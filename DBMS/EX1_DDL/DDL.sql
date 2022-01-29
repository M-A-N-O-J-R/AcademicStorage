
--R.MANOJ 195002071 IT-B 3rd SEM UIT1311--


create database DBMS;
use DBMS;

create table STUDENT(stud_id int primary key,name varchar(20),city varchar(20),college_name varchar(30));
create table EMPLOYEE(e_id int primary key,name varchar(30),email varchar(40),city varchar(30));
insert into EMPLOYEE values(101,'KARTHIK','KARTHIK@SSN.IN','CHENNAI')
insert into EMPLOYEE values(102,'MANI','MANI@SSN.IN','MUMBAI');
select * from EMPLOYEE;


alter table EMPLOYEE drop column city;
alter table STUDENT add  age integer;
alter table STUDENT 
alter column city varchar(25)

sp_help EMPLOYEE;

drop table STUDENT;


TRUNCATE  table EMPLOYEE;








