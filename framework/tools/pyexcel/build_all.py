# -*- coding:utf-8 -*-
import os
import os.path
import xlrd
import codecs
import sys


for root, dirs, files in os.walk('excel'):
    for f in files:
        if f[0] == '~':
            continue
        ext = os.path.splitext(f)[1]
        if ext != '.xls' and ext != '.xlsx':
            continue
        filename = os.path.join(root, f)
        print u'处理文件 %s' % filename
        os.system(u'python build_lua.py %s' % filename)

os.system(u'python build_script.py')        
