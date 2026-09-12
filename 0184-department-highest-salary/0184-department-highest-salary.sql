# Write your MySQL query statement below
with highestSalary as (
    select id,name,salary,departmentId,
    rank() over(partition by departmentId order by salary  desc) as rnk
    from Employee
)
select d.name as Department, hs.name as Employee, hs.salary as Salary
from highestSalary hs
join Department d
on hs.departmentId=d.id
where rnk=1;