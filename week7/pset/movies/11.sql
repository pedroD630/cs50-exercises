SELECT DISTINCT m.title
FROM movies m
JOIN ratings ON m.id = ratings.movie_id
WHERE m.id IN (SELECT DISTINCT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
ORDER BY ratings.rating DESC;
