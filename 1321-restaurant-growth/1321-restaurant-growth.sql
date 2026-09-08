# Write your MySQL query statement below
select distinct c1.visited_on,sum(c2.amount) as amount,round(sum(c2.amount)/7,2) as average_amount
from Customer c1
left join Customer c2
ON c2.visited_on BETWEEN DATE_SUB(c1.visited_on, INTERVAL 6 DAY) AND c1.visited_on
group by c1.visited_on,c1.customer_id
having count(distinct c2.visited_on)=7
order by c1.visited_on asc;

