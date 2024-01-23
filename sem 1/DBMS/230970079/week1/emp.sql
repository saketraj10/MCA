create table emp(empno number(4) primary key,
ename varchar(10),
job varchar(9) constraint JOB_CHK_Cons check(job in('CLRK', 'MGR', 'A.MGR', 'GM', 'CEO')),
mgrid number(4) constraint MGR_FK_EMPNO_Cons REFERENCES emp,
date_birth date,
sal number(7,2) constraint SAL_20KMore_Cons check(sal>20000),
comm number(7,2) default 1000,
deptno varchar(3) constraint DEPTNO_FK_DEPT_Cons REFERENCES dept(dno) on delete cascade,
date_join date, constraint DB_Less_DBJOIN_Cons check(date_birth < date_join));