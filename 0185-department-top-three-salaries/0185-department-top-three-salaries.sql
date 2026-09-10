# Write your MySQL query statement below
select d.name as  Department ,x.name as Employee, x.salary as Salary
from (
    select e.*,
    dense_rank() over(partition by departmentID order by salary desc) as rnk
    from Employee e 
) as x
join Department as d
on x.departmentID=d.id
where x.rnk<=3;

