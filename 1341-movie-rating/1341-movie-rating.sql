# Write your MySQL query statement below
(
    select u.name as results
    from MovieRating m
    left join Users u
    on m.user_id=u.user_id
    group by m.user_id,u.name
    order by count(m.movie_id) desc, u.name asc
    limit 1
)

union all

(
    select m1.title as results
    from MovieRating mr
    left join Movies m1
    on mr.movie_id=m1.movie_id
    where mr.created_at>='2020-02-01' and mr.created_at<='2020-02-29'
    group by mr.movie_id,m1.title
    order by avg(mr.rating) desc, m1.title asc
    limit 1
);
