# -*- coding:utf-8 -*-
import os
import os.path
import xlrd
import codecs
import sys

#外链接的表格
ref_sheet_list = {}
current_filename = ''
opening_files = {}

def split(str, sep):
    list = str.split(sep)
    for i in xrange(0, len(list)):
        list[i] = int(list[i])
    return list

def tolua(conf, table):
    filename = conf['filename']
    result = u'--文件由脚本生成，请不要手动编辑\n' 
    result += conf['header']
    result += '\n'
    #如果是list,就一个个转
    if type(table) != type([]):
        result += table2str(table, 1, conf.has_key('noquote'))
    else:
        for i in xrange(0, len(table)):
            result += table2str(table[i], 1, conf.has_key('noquote'))
            if i < len(table) - 1:
                result += ',\n'

    result += '\n'
    result += conf['tail']
    if not os.path.exists(os.path.dirname(filename)):
        print(filename)
        os.makedirs(os.path.dirname(filename))
    if not opening_files.has_key(filename):
        f = codecs.open(filename, 'w', 'utf-8')
        opening_files[filename] = f
    f = opening_files[filename]
    f.write(result)
    if len(opening_files) > 100:
        f.close()

def list2table(list):
    table = {}
    for i in xrange(0, len(list)):
        table[i + 1] = list[i]
    return table

def table2str(table, deep = 1, noquote = None):
    result = ''
    if noquote and deep == 1:
        pass
    else:
        result += '{\n'
   
    #为了处理策划要求的按顺序。。。。。。
    #判断是否数组
    isarray = True
    for i in xrange(1, len(table) + 1):
        if not table.has_key(i) and not table.has_key(str(i)):
            isarray = False;
            break

    if not isarray:
        for k, v in table.items():
            if type(k) == type(u'') and k.find('__') >= 0:
                continue
            for i in xrange(0, deep):
                result += '\t'
            try:
                k =  int(k)
            except:
                pass
            if isarray:
                result += '' 
            elif type(k) == type(0):
                result += '[' + str(k) + '] = ' 
            elif type(k) == type('') or type(k) == type(u''):
                #result += '[\'' + k + '\']'
                result += k  + ' = '

            if type(v) == type(()) and v[0] == 'int':
                result += str(v[1])  
            elif type(v) == type(()) and v[0] == 'bool' and v[1] == False:
                result += 'false'
            elif type(v) == type(()) and v[0] == 'bool' and v[1] == True:
                result += 'true'
            elif type(v) == type(()) and v[0] == 'float':
                result += str(v[1])
            elif type(v) == type(()) and v[0] == 'string':
                result += '\'' + v[1] + '\''
            elif type(v) == type(()) and v[0] == 'value':
                result += v[1]
            elif type(v) == type({}):
                result += table2str(v, deep + 1)
            elif type(v) == type([]):
                result += table2str(list2table(v), deep + 1)

            result += ','
            if type(v) == type(()) and len(v) >= 3:
                result += '--' + v[2]
            result += '\n'
    else:
        for k in xrange(1, len(table) + 1):
            if type(k) == type(u'') and k.find('__') >= 0:
                continue
            v = table[k]
            for i in xrange(0, deep):
                result += '\t'
            try:
                k =  int(k)
            except:
                pass
            if isarray:
                result += '' 
            elif type(k) == type(0):
                result += '[' + str(k) + '] = ' 
            elif type(k) == type('') or type(k) == type(u''):
                #result += '[\'' + k + '\']'
                result += k  + ' = '

            if type(v) == type(()) and v[0] == 'int':
                result += str(v[1])  
            elif type(v) == type(()) and v[0] == 'bool' and v[1] == False:
                result += 'false'
            elif type(v) == type(()) and v[0] == 'bool' and v[1] == True:
                result += 'true'
            elif type(v) == type(()) and v[0] == 'float':
                result += str(v[1])
            elif type(v) == type(()) and v[0] == 'string':
                result += '\'' + v[1] + '\''
            elif type(v) == type(()) and v[0] == 'value':
                result += v[1]
            elif type(v) == type({}):
                result += table2str(v, deep + 1)
            elif type(v) == type([]):
                result += table2str(list2table(v), deep + 1)

            result += ','
            if type(v) == type(()) and len(v) >= 3:
                result += '--' + v[2]
            result += '\n'


    for i in xrange(0, deep - 1):
        result += '\t'
    if noquote and deep == 1:
        pass
    else:
        result += '}'
    return result

def setval(obj, key, value):
    index = key.find('.')
    if index == -1:
        try:
            key = int(key)
        except:
            pass
        obj[key] = value
    else:
        key1 = key[0:index]
        key2 = key[index + 1:]
        try:
            key1 = int(key1)
        except:
            pass
        if not obj.has_key(key1):
            obj[key1] = {}
        setval(obj[key1], key2, value)

def select(sheet):
    table = {}
    conf_row = sheet.row_values(0)
    conf = {}
    conf['filename'] = len(conf_row) > 0 and conf_row[0] or ''
    conf['header'] = len(conf_row) > 2 and conf_row[2] or ''
    conf['tail'] = len(conf_row) > 3 and conf_row[3] or ''
    if len(conf_row) > 4 and conf_row[4] == 'noquote':
        conf['noquote'] = True
    type_row = sheet.row_values(1)    
    header_row = sheet.row_values(2)
    comment_row = sheet.row_values(3)

    #嵌套的深度
    nest_cols = 0
    for i in xrange(0, len(type_row)):
        value_type = type_row[i]
        if header_row[i] != '' and value_type[0] == '*':
            nest_cols = nest_cols + 1

    for i in xrange(4, sheet.nrows):
        row = sheet.row_values(i)
        obj = {}
        for k in xrange(0, len(row)):
            if header_row[k] == '':
                continue
            #转换数据类型
            value = row[k]
            value_type = type_row[k][0] == '*' and type_row[k][1:] or type_row[k]
            if value == '' and header_row[k] != '_value':
                continue
            if value_type  == 'int':
                value = int(value)
                setval(obj, header_row[k], ('int', value, comment_row[k]))
            elif value_type == 'float':
                value = float(value)
                setval(obj, header_row[k], ('float', value, comment_row[k]))
            elif (value_type == 'bool' or value_type == 'boolean'):
                #print(header_row[k], value, type(0))
                bValue = True
                if type(value) == type(0) and value == 0:
                    bValue = False
                elif (type(value) == type(u'') or type(value) == type(''))and value.lower() == 'false':
                    bValue = False
                setval(obj, header_row[k], ('bool', bValue, comment_row[k]))
            elif value_type == 'string':
                value = unicode(value)
                setval(obj, header_row[k], ('string', value, comment_row[k]))
            elif value_type == 'value':
                value = ''.join(unicode(value).split('\n'))
                setval(obj, header_row[k], ('value', unicode(value), comment_row[k]))
            elif value_type == 'ref':
                #处理外链的
                pats = header_row[k].split(':')
                if not ref_sheet_list.has_key(header_row[k]):
                    file_name = pats[0]
                    if file_name == '' or os.path.basename(file_name) == os.path.basename(current_filename):
                        file_name = current_filename
                    ref_sheet = open_sheet(current_filename, pats[1])
                    ref_conf, ref_table = select(ref_sheet)
                    ref_sheet_list[header_row[k]] = (ref_conf, ref_table)
                    #print(ref_conf, ref_table)
                ref_conf, ref_table = ref_sheet_list[header_row[k]]
                #将外部表的数据拷贝过来
                ref_row = ref_table[int(value)]
                for k, v in ref_row.items():
                    obj[k] = v
            elif value_type == 'xls':
                pats = value.split(':')
                #print(pats)
                filename = (len(pats) == 1) and current_filename or pats[0]
                sheetname = (len(pats) == 1) and pats[0] or pats[1]
                ref_sheet = open_sheet(filename, sheetname)
                ref_conf, ref_table = select(ref_sheet)
                setval(obj, header_row[k], ref_table)


        #一行的数据处理结束

        #处理特殊的列    
        index = len(table) + 1
        #特殊的_file
        if obj.has_key('_file'):
            #每行一个文件
            conf['file_per_row'] = True
        if obj.has_key('_key'):
            index = obj['_key'][1]
            del obj['_key']
        #特殊的_value
        if obj.has_key('_value'):
            obj = obj['_value']
        table[index] = obj

    #如果有嵌套，就在这里转化一下
    if nest_cols <= 0:
        return conf, table

    newtable = {}
    for k, row in table.items():
        #先根据深度算出前缀
        prefix = ''
        for i in xrange(0, len(header_row)):
            if header_row[i] != '' and type_row[i][0] == '*':
                prefix = prefix + str(row[header_row[i]][1]) + '.'
        newk = prefix[-1] == '.' and prefix[:-1] or prefix
        setval(newtable, newk, row)
    #print(newtable)
    return conf, newtable

def open_sheet(filename, sheet_name):
    file = xlrd.open_workbook(filename)
    return file.sheet_by_name(sheet_name)
    
if len(sys.argv) < 2:
    print('usage:')
    print('python build_lua.py xxx.xlsx')
else:                
    current_filename = sys.argv[1]
    file = xlrd.open_workbook(current_filename)
    sheets = file.sheets()
    for i in xrange(0, len(sheets)):
        sheet = sheets[i]
        if sheet.nrows <= 0 or sheet.ncols <= 0 or sheet.cell_value(0, 0) == '':
            continue
        conf, table = select(sheet)
        if not conf.has_key('file_per_row'):
            tolua(conf, table)
        else:
            filetable = {}
            for k, obj in table.items():
                filename = obj['_file'][1]
                del obj['_file']
                if not filetable.has_key(filename):
                    filetable[filename]= []
                filetable[filename].append(obj)
            for filename, obj in filetable.items():
                conf['filename'] = filename
                tolua(conf, obj)


