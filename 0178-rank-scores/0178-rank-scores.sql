# Write your MySQL query statement below
with rnk as (
    select score,
    dense_rank() over(order by score desc) as 'rank'
    from Scores
)
select *
from rnk;