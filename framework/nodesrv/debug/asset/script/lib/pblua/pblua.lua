module('Pblua', package.seeall)

function import_dir(dir)
    Pblua.mappath('', dir)
    local files = File.listdir(dir)
    for _, file in pairs(files) do
        if file.type == File.TYPE_FILE and string.find(file.name, '.proto$') then
            Log.info(string.format('load proto(%s)', file.name))
            Pblua.import(file.name)
        end
    end
end

