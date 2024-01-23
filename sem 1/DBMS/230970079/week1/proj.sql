create table proj(dno varchar(3) not null constraint DNO_FK_DEPT_Cons references dept(dno),
prj_no varchar(5) constraint P_LikePRJNO_Cons check(prj_no like 'P%'),
prj_name varchar(10),
prj_credit number(2) constraint PRJ_CREDIT_RANGE_Cons check(prj_credit >= 1 and prj_credit <= 10),
strt_date date,
end_date date, constraint ENDDATE_GRT_STRT_Cons check(end_date > strt_date));