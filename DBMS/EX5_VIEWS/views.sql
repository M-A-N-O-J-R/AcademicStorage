--R.MANOJ 195002071 IT-B 3rd SEM UIT1311--

create database students;
use students;
create table ssnstud(regno int NOT NULL,name varchar(20) NOT NULL,dept varchar(20));
create table ssndept(deptid int,dname varchar(20) NOT NULL);
execute sp_help ssnstud;
execute sp_help ssnclg;
insert into ssnstud values(1,'student A','IT');
insert into ssnstud values(2,'student B','CSE');
insert into ssnstud values(3,'student C','IT');
insert into ssnstud values(4,'student D','IT');
insert into ssnstud values(5,'student E','CSE');
insert into ssnstud values(6,'student F','CSE');
select * from ssnstud;
insert into ssndept values(1,'IT');
insert into ssndept values(2,'ENG');
insert into ssndept values(3,'CSE');
insert into ssndept values(4,'MECH');
insert into ssndept values(5,'CIVIL');
insert into ssndept values(6,'EEE');
select * from ssndept;
drop table ssnstud;
drop table ssndept;

create view itidept as
select regno,name from ssnstud where dept='IT';

select * from itidept;

drop view itidept

insert into itidept values(8,'studentq');

update  itidept
set name='student m' where regno=4;

delete from itidept where regno=3;

drop view itidept;

create view i1 as
select s.regno,s.name from ssnstud s right join ssndept d on s.dept=d.dname;
select * from i1;

insert into i1 values(66,'student Aa');

update i1 set regno=78 where name='student F ';
delete from i1 where name='student F';
drop view i1;
