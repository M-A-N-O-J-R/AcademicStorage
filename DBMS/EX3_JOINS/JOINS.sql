
--R.MANOJ 195002071 IT-B 3rd SEM UIT1311--
--create database DBMS;
--use DBMS;

create table DEPT (deptid varchar(5),dname varchar(20),est_year integer);
create table EMPLOYEE(regno integer,name varchar(20),dname varchar(20),city varchar(10));
select * from DEPT
select * from EMPLOYEE

insert into DEPT values ('A','IT',2001);
insert into DEPT values ('B','ENG',2002);
insert into DEPT values ('C','MECH',2005);
insert into DEPT values ('D','CSE',2003);
insert into DEPT values ('E','CIVIL',2007);
insert into DEPT values ('F','CHEM',2009);
insert into DEPT values ('G','EEE',2011);


insert into EMPLOYEE values (1,'KESHAV','IT','CHN');
insert into EMPLOYEE values (2,'MAHENDRA','ENG','NCR');
insert into EMPLOYEE values (3,'RAJAT','IT','KER');
insert into EMPLOYEE values (4,'KIRAN','IT','CHN');
insert into EMPLOYEE values (5,'SUDESHI','IT','BAN');
insert into EMPLOYEE values (6,'RAJEEV','ENG','CHN');
insert into EMPLOYEE values (5,'RAM','CSE','KER');
insert into EMPLOYEE values (6,'AKASH','CIVIL','BAN');
insert into EMPLOYEE values (7,'NEHA','MATHS','KER');
insert into EMPLOYEE values (8,'VISHNU','MATHS','CHN');


--DELETE FROM DEPT
--DELETE FROM EMPLOYEE

drop table DEPT
drop table EMPLOYEE

select e.regno ,e.name,e.city,d.deptid ,d.dname,d.est_year  from DEPT d inner join EMPLOYEE e on d.dname=e.dname;


select e.regno ,e.name,e.city,d.deptid ,d.dname,d.est_year  from EMPLOYEE e inner join  DEPT d on d.dname=e.dname;


select e.regno ,e.name,e.city,d.deptid ,d.dname,d.est_year  from DEPT d left join EMPLOYEE e on d.dname=e.dname;


select e.regno ,e.name,e.city,d.deptid ,d.dname,d.est_year  from DEPT d right join EMPLOYEE e on d.dname=e.dname;


select *  from DEPT d cross join EMPLOYEE e ;
select *  from EMPLOYEE e cross join DEPT d  ;

select a.regno ,a.name , a.city ,a.dname from EMPLOYEE a , EMPLOYEE e where a.dname=e.dname;