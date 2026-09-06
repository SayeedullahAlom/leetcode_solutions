# Write your MySQL query statement below
select s1.id,if(s1.id%2=0,s3.student,coalesce(s2.student,s1.student)) as student
from Seat s1
left join Seat s2
on s1.id+1=s2.id
left join Seat s3
on s1.id-1=s3.id;
