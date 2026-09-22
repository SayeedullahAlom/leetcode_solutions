WITH RankedReviews AS (
    SELECT 
        employee_id,
        rating,
      
        LEAD(rating, 1) OVER (
            PARTITION BY employee_id 
            ORDER BY review_date DESC
        ) AS prev_rating,
     
        LEAD(rating, 2) OVER (
            PARTITION BY employee_id 
            ORDER BY review_date DESC
        ) AS prev_prev_rating,
 
        ROW_NUMBER() OVER (
            PARTITION BY employee_id 
            ORDER BY review_date DESC
        ) AS rn
    FROM performance_reviews
)
SELECT 
    e.employee_id,
    e.name,
    (r.rating - r.prev_prev_rating) AS improvement_score
FROM RankedReviews r
JOIN employees e ON r.employee_id = e.employee_id
WHERE r.rn = 1 
  AND r.prev_prev_rating IS NOT NULL  
  AND r.rating > r.prev_rating      
  AND r.prev_rating > r.prev_prev_rating 
ORDER BY improvement_score DESC, e.name ASC;