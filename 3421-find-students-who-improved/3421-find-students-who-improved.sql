# Write your MySQL query statement below
select s1.student_id,s1.subject,s1.score as first_score , s2.score as latest_score
from Scores s1
join Scores s2
on s1.student_id=s2.student_id and s1.subject=s2.subject and s1.exam_date<s2.exam_date and s1.score<s2.score
where (s1.exam_date,s2.exam_date) in (
    select min(exam_date),max(exam_date)
    from Scores
    group by student_id,subject
)
order by s1.student_id,s1.subject;

