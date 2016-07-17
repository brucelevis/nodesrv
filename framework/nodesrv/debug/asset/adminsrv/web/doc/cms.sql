
create table if not exists cms_menu
(
    id 	        int not null comment '',
    url         varchar(32) comment '菜单地址',
    name        varchar(32) comment '名字',
    parentname  varchar(32) comment '父节点',
    primary key(id)
)ENGINE = MYISAM;

