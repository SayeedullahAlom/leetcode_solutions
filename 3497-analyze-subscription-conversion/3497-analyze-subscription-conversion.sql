SELECT 
    user_id,
    ROUND(AVG(IF(activity_type = 'free_trial', activity_duration, NULL)), 2) AS trial_avg_duration,
    ROUND(AVG(IF(activity_type = 'paid', activity_duration, NULL)), 2) AS paid_avg_duration
FROM UserActivity
GROUP BY user_id
HAVING 
    COUNT(CASE WHEN activity_type = 'free_trial' THEN 1 END) > 0
    AND COUNT(CASE WHEN activity_type = 'paid' THEN 1 END) > 0
ORDER BY user_id;