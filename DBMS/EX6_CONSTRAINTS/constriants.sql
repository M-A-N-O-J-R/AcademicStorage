
--R.MANOJ 195002071 IT-B 3rd SEM UIT1311--
create database d1
use d1;
create table people(id int,name varchar(20),country varchar(80)  DEFAULT 'india',age int check(age>= 18));
insert into  people values (1,'a','india',18);
insert into  people values (3,'c','india',28);
insert into  people values (2,'w','pakistan',98);
insert into  people values (10,'k','afghanisthan',87);
insert into  people values (30,'b','canada',35);
insert into  people values (7,'m','canada',43);

select * from people;
create index i1 on people(id);
select * from people order by country desc,name desc;
select top 3*from people;
select  count(name),country from people group by country;
select count(name),country from people  where age>='30' group by country having count(country)>1 order by country desc;
select count(country),name from people group by name having count(name)>0;
select *into newtable from people;
select * from newtable;
--select country,name into neww  from people where country ='canada'or country='india';
select * from neww;
select * from people where not country ='india';
select count(name) from people;
select * from people where country in ('india','canada');
select country from people where exists (select name from people where country='canada' and age>=50);
select country,name from people where country like '%an';
select country,name from people where country like '_a%';
select min(age) from people;
select max(age) from people;
select avg(age) from people;
select sum(age)from people;
truncate table person;

