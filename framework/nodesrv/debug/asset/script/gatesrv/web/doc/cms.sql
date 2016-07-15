
create table if not exists cms_menu
(
    id 	        int not null comment '',
    parentid    int not null comment '',
    bin         blob comment '',
    url         varchar(30) comment '菜单地址',
    name        varchar(32) comment '名字',
    primary key(id)
)ENGINE = MYISAM;

