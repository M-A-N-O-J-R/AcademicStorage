

--R.MANOJ 195002071 IT-B 3rd SEM UIT1311--


--create database DBMS;
--use DBMS;

create table EMPLOYEE(e_id integer primary key,name varchar(30),email varchar(40),age integer,city varchar(30));

insert into EMPLOYEE values(101,'ASHWIN','ASH@SSN.IN','DELHI');
insert into EMPLOYEE values(102,'DHONI','MSD@SSN.IN','CHENNAI');
insert into EMPLOYEE values(103,'VIRAT','VIRAT@SSN.IN','BANGALORE');
insert into EMPLOYEE values(104,'WATSON','WATTY@SSN.IN','CHENNAI');
insert into EMPLOYEE values(105,'WARNER','DW@SSN.IN','HYDERABAD');
insert into EMPLOYEE values(106,'RAHUL','KLLASIC@ssn.in','AMRITSAR');

select * from EMPLOYEE;


update EMPLOYEE 
set e_id= 107 where name='RAHUL';

update EMPLOYEE 
set e_id= 108 where name='WARNER' and city = 'HYDERABAD';


select * from EMPLOYEE;

delete from EMPLOYEE where name='RAHUL';
delete from EMPLOYEE where name='WARNER';

select * from EMPLOYEE;


