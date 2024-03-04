SELECT title, year
FROM movies
JOIN ratings ON ratings.movie_id = (
    SELECT id FROM movies WHERE year = 2010
)
WHERE movies.year = 2010
ORDER BY ratings.rating DESC, movies.title ASC;
