create table dept(dno varchar(3) constraint DNO_UNQ_Cons Unique constraint D_LikeDNO_Cons check(dno like 'D%'),
dname varchar(10) constraint DNAME_UNQ_Cons unique,
location varchar(9) constraint VALID_LOC_Cons check(location in('BNG', 'MNG', 'MUM', 'HYD', 'CHN')));