-- Discover all information about the crime
SELECT
   *
FROM
   crime_scene_reports
WHERE
   day = 28
   AND month = 7
   AND street = 'Humphrey Street';
-- Search for data in the interviews
SELECT
   *
FROM
   interviews
WHERE
   month = 7
   AND day = 28;
-- Search exit activities in bakery in the day in space of 10 minutes
SELECT
   *
FROM
   bakery_security_logs
WHERE
   day = 28
   AND month = 7
   AND hour = 10
   AND minute > 15
   AND minute <= 25
   AND activity = 'exit';
-- Find the name of person that entered in bakey and the cars license plate of him
SELECT
   *
FROM
   people
   JOIN
      bakery_security_logs
      ON people.license_plate = bakery_security_logs.license_plate
WHERE
   people.license_plate IN
   (
      SELECT
         license_plate
      FROM
         bakery_security_logs
      WHERE
         day = 28
         AND month = 7
         AND hour = 10
         AND hour = 10
         AND minute > 15
         AND minute <= 25
         AND activity = 'exit'
   )
;
-- Find people that went on ATM on Leggett Street in the day
SELECT
   *
FROM
   atm_transactions
WHERE
   day = 28
   AND month = 7
   AND atm_location = 'Leggett Street';
-- Find peoples full bank account that went on atm and in the bakery in the specific hour
SELECT
   *
FROM
   atm_transactions AS t
   JOIN
      bank_accounts AS a
      ON t.account_number = a.account_number
WHERE
   a.person_id IN
   (
      SELECT
         id
      FROM
         people
      WHERE
         license_plate IN
         (
            SELECT
               license_plate
            FROM
               bakery_security_logs
            WHERE
               day = 28
               AND month = 7
               AND hour = 10
               AND hour = 10
               AND minute > 15
               AND minute <= 25
               AND activity = 'exit'
         )
   )
   AND t.atm_location = 'Leggett Street'
   AND t.transaction_type = 'withdraw'
   AND t.day = 28;
-- Find the name of suspects in the atm
SELECT
   *
FROM
   people
WHERE
   id IN
   (
      SELECT
         person_id
      FROM
         bank_accounts AS a
         JOIN
            atm_transactions AS t
            ON a.account_number = t.account_number
      WHERE
         a.person_id IN
         (
            SELECT
               id
            FROM
               people
            WHERE
               license_plate IN
               (
                  SELECT
                     license_plate
                  FROM
                     bakery_security_logs
                  WHERE
                     day = 28
                     AND month = 7
                     AND hour = 10
                     AND hour = 10
                     AND minute > 15
                     AND minute <= 25
                     AND activity = 'exit'
               )
         )
         AND t.atm_location = 'Leggett Street'
         AND t.transaction_type = 'withdraw'
         AND t.day = 28
   )
;
-- Find phonecalls that these people doed ( who is on the phone ) and find the name of the one that purchase the
-- flight ticket and for where
SELECT
   *
FROM
   phone_calls AS c
   JOIN
      people AS p
      ON c.caller = p.phone_number
WHERE
   c.caller IN
   (
      SELECT
         phone_number
      FROM
         people
      WHERE
         id IN
         (
            SELECT
               person_id
            FROM
               bank_accounts AS a
               JOIN
                  atm_transactions AS t
                  ON a.account_number = t.account_number
            WHERE
               a.person_id IN
               (
                  SELECT
                     id
                  FROM
                     people
                  WHERE
                     license_plate IN
                     (
                        SELECT
                           license_plate
                        FROM
                           bakery_security_logs
                        WHERE
                           day = 28
                           AND month = 7
                           AND hour = 10
                           AND hour = 10
                           AND minute > 15
                           AND minute <= 25
                           AND activity = 'exit'
                     )
               )
               AND t.atm_location = 'Leggett Street'
               AND t.transaction_type = 'withdraw'
               AND t.day = 28
         )
   )
   AND c.day = 28
   AND c.month = 7;
-- Find the information about the receivers
SELECT
   *
FROM
   people
   JOIN
      phone_calls AS calls
      ON people.phone_number = calls.receiver
WHERE
   calls.receiver IN
   (
      SELECT
         receiver
      FROM
         phone_calls AS c
         JOIN
            people AS p
            ON c.caller = p.phone_number
      WHERE
         c.caller IN
         (
            SELECT
               phone_number
            FROM
               people
            WHERE
               id IN
               (
                  SELECT
                     person_id
                  FROM
                     bank_accounts AS a
                     JOIN
                        atm_transactions AS t
                        ON a.account_number = t.account_number
                  WHERE
                     a.person_id IN
                     (
                        SELECT
                           id
                        FROM
                           people
                        WHERE
                           license_plate IN
                           (
                              SELECT
                                 license_plate
                              FROM
                                 bakery_security_logs
                              WHERE
                                 day = 28
                                 AND month = 7
                                 AND hour = 10
                                 AND hour = 10
                                 AND minute > 15
                                 AND minute <= 25
                                 AND activity = 'exit'
                           )
                     )
                     AND t.atm_location = 'Leggett Street'
                     AND t.transaction_type = 'withdraw'
                     AND t.day = 28
               )
         )
         AND c.day = 28
         AND c.month = 7
   )
   AND calls.day = 28
   AND calls.month = 7;
-- Join names, passport, phone_number from callers  and receivers
SELECT
   people.name,
   people.phone_number,
   people.passport_number,
   calls.caller,
   calls.receiver
FROM
   people
   JOIN
      phone_calls AS calls
      ON people.phone_number = calls.receiver
      OR people.phone_number = calls.caller
WHERE
   calls.receiver IN
   (
      SELECT
         receiver
      FROM
         phone_calls AS c
         JOIN
            people AS p
            ON c.caller = p.phone_number
      WHERE
         c.caller IN
         (
            SELECT
               phone_number
            FROM
               people
            WHERE
               id IN
               (
                  SELECT
                     person_id
                  FROM
                     bank_accounts AS a
                     JOIN
                        atm_transactions AS t
                        ON a.account_number = t.account_number
                  WHERE
                     a.person_id IN
                     (
                        SELECT
                           id
                        FROM
                           people
                        WHERE
                           license_plate IN
                           (
                              SELECT
                                 license_plate
                              FROM
                                 bakery_security_logs
                              WHERE
                                 day = 28
                                 AND month = 7
                                 AND hour = 10
                                 AND minute > 15
                                 AND minute <= 25
                                 AND activity = 'exit'
                           )
                     )
                     AND t.atm_location = 'Leggett Street'
                     AND t.transaction_type = 'withdraw'
                     AND t.day = 28
               )
         )
         AND c.day = 28
         AND c.month = 7
   )
   AND calls.caller IN
   (
      SELECT
         phone_number
      FROM
         people
      WHERE
         id IN
         (
            SELECT
               person_id
            FROM
               bank_accounts AS a
               JOIN
                  atm_transactions AS t
                  ON a.account_number = t.account_number
            WHERE
               a.person_id IN
               (
                  SELECT
                     id
                  FROM
                     people
                  WHERE
                     license_plate IN
                     (
                        SELECT
                           license_plate
                        FROM
                           bakery_security_logs
                        WHERE
                           day = 28
                           AND month = 7
                           AND hour = 10
                           AND minute > 15
                           AND minute <= 25
                           AND activity = 'exit'
                     )
               )
               AND t.atm_location = 'Leggett Street'
               AND t.transaction_type = 'withdraw'
               AND t.day = 28
         )
   )
   AND people.passport_number IS NOT NULL
   AND calls.day = 28
   AND calls.month = 7;
-- Find the complete flight information for the people who are in the call list and travel one day after the robbery
SELECT
   p.name,
   p.passport_number,
   p.phone_number,
   f.origin_airport_id,
   f.destination_airport_id,
   f.day,
   f.hour,
   f.minute
FROM
   people AS p
   JOIN
      passengers AS pa
      ON p.passport_number = pa.passport_number
   JOIN
      flights AS f
      ON pa.flight_id = f.id
WHERE
   p.passport_number IN
   (
      SELECT
         people.passport_number
      FROM
         people
         JOIN
            phone_calls AS calls
            ON people.phone_number = calls.receiver
            OR people.phone_number = calls.caller
      WHERE
         calls.receiver IN
         (
            SELECT
               receiver
            FROM
               phone_calls AS c
               JOIN
                  people AS p
                  ON c.caller = p.phone_number
            WHERE
               c.caller IN
               (
                  SELECT
                     phone_number
                  FROM
                     people
                  WHERE
                     id IN
                     (
                        SELECT
                           person_id
                        FROM
                           bank_accounts AS a
                           JOIN
                              atm_transactions AS t
                              ON a.account_number = t.account_number
                        WHERE
                           a.person_id IN
                           (
                              SELECT
                                 id
                              FROM
                                 people
                              WHERE
                                 license_plate IN
                                 (
                                    SELECT
                                       license_plate
                                    FROM
                                       bakery_security_logs
                                    WHERE
                                       day = 28
                                       AND month = 7
                                       AND hour = 10
                                       AND minute > 15
                                       AND minute <= 25
                                       AND activity = 'exit'
                                 )
                           )
                           AND t.atm_location = 'Leggett Street'
                           AND t.transaction_type = 'withdraw'
                           AND t.day = 28
                     )
               )
               AND c.day = 28
               AND c.month = 7
         )
         AND calls.caller IN
         (
            SELECT
               phone_number
            FROM
               people
            WHERE
               id IN
               (
                  SELECT
                     person_id
                  FROM
                     bank_accounts AS a
                     JOIN
                        atm_transactions AS t
                        ON a.account_number = t.account_number
                  WHERE
                     a.person_id IN
                     (
                        SELECT
                           id
                        FROM
                           people
                        WHERE
                           license_plate IN
                           (
                              SELECT
                                 license_plate
                              FROM
                                 bakery_security_logs
                              WHERE
                                 day = 28
                                 AND month = 7
                                 AND hour = 10
                                 AND minute > 15
                                 AND minute <= 25
                                 AND activity = 'exit'
                           )
                     )
                     AND t.atm_location = 'Leggett Street'
                     AND t.transaction_type = 'withdraw'
                     AND t.day = 28
               )
         )
         AND calls.day = 28
         AND calls.month = 7
   )
   AND f.day = 29
   AND p.passport_number IS NOT NULL;
-- Discover data of the airport 8 including name, hour of the flights and destination ( we need find the first flight of the day 29 )
SELECT
   *
FROM
   flights AS f
   JOIN
      airports AS a
      ON f.origin_airport_id = a.id
WHERE
   a.id IN
   (
      SELECT
         f.origin_airport_id
      FROM
         people AS p
         JOIN
            passengers AS pa
            ON p.passport_number = pa.passport_number
         JOIN
            flights AS f
            ON pa.flight_id = f.id
      WHERE
         p.passport_number IN
         (
            SELECT
               people.passport_number
            FROM
               people
               JOIN
                  phone_calls AS calls
                  ON people.phone_number = calls.receiver
                  OR people.phone_number = calls.caller
            WHERE
               calls.receiver IN
               (
                  SELECT
                     receiver
                  FROM
                     phone_calls AS c
                     JOIN
                        people AS p
                        ON c.caller = p.phone_number
                  WHERE
                     c.caller IN
                     (
                        SELECT
                           phone_number
                        FROM
                           people
                        WHERE
                           id IN
                           (
                              SELECT
                                 person_id
                              FROM
                                 bank_accounts AS a
                                 JOIN
                                    atm_transactions AS t
                                    ON a.account_number = t.account_number
                              WHERE
                                 a.person_id IN
                                 (
                                    SELECT
                                       id
                                    FROM
                                       people
                                    WHERE
                                       license_plate IN
                                       (
                                          SELECT
                                             license_plate
                                          FROM
                                             bakery_security_logs
                                          WHERE
                                             day = 28
                                             AND month = 7
                                             AND hour = 10
                                             AND minute > 15
                                             AND minute <= 25
                                             AND activity = 'exit'
                                       )
                                 )
                                 AND t.atm_location = 'Leggett Street'
                                 AND t.transaction_type = 'withdraw'
                                 AND t.day = 28
                           )
                     )
                     AND c.day = 28
                     AND c.month = 7
               )
               AND calls.caller IN
               (
                  SELECT
                     phone_number
                  FROM
                     people
                  WHERE
                     id IN
                     (
                        SELECT
                           person_id
                        FROM
                           bank_accounts AS a
                           JOIN
                              atm_transactions AS t
                              ON a.account_number = t.account_number
                        WHERE
                           a.person_id IN
                           (
                              SELECT
                                 id
                              FROM
                                 people
                              WHERE
                                 license_plate IN
                                 (
                                    SELECT
                                       license_plate
                                    FROM
                                       bakery_security_logs
                                    WHERE
                                       day = 28
                                       AND month = 7
                                       AND hour = 10
                                       AND minute > 15
                                       AND minute <= 25
                                       AND activity = 'exit'
                                 )
                           )
                           AND t.atm_location = 'Leggett Street'
                           AND t.transaction_type = 'withdraw'
                           AND t.day = 28
                     )
               )
               AND calls.day = 28
               AND calls.month = 7
         )
         AND f.day = 29
         AND p.passport_number IS NOT NULL
   )
   AND f.day = 29
ORDER BY
   f.hour ASC;
--> Bruce take's the first flight
-- Find the name of the destination airport of Bruce
SELECT
   *
FROM
   airports
WHERE
   id = 4;
-- Find the receivers that called for less than one minute and talks with bruce
SELECT
   *
FROM
   people
   JOIN
      phone_calls AS calls
      ON people.phone_number = calls.receiver
WHERE
   calls.receiver IN
   (
      SELECT
         receiver
      FROM
         phone_calls AS c
         JOIN
            people AS p
            ON c.caller = p.phone_number
      WHERE
         c.caller IN
         (
            SELECT
               phone_number
            FROM
               people
            WHERE
               id IN
               (
                  SELECT
                     p.id
                  FROM
                     people AS p
                     JOIN
                        passengers AS pa
                        ON p.passport_number = pa.passport_number
                     JOIN
                        flights AS f
                        ON pa.flight_id = f.id
                  WHERE
                     p.passport_number IN
                     (
                        SELECT
                           people.passport_number
                        FROM
                           people
                           JOIN
                              phone_calls AS calls
                              ON people.phone_number = calls.receiver
                              OR people.phone_number = calls.caller
                        WHERE
                           calls.receiver IN
                           (
                              SELECT
                                 receiver
                              FROM
                                 phone_calls AS c
                                 JOIN
                                    people AS p
                                    ON c.caller = p.phone_number
                              WHERE
                                 c.caller IN
                                 (
                                    SELECT
                                       phone_number
                                    FROM
                                       people
                                    WHERE
                                       id IN
                                       (
                                          SELECT
                                             person_id
                                          FROM
                                             bank_accounts AS a
                                             JOIN
                                                atm_transactions AS t
                                                ON a.account_number = t.account_number
                                          WHERE
                                             a.person_id IN
                                             (
                                                SELECT
                                                   id
                                                FROM
                                                   people
                                                WHERE
                                                   license_plate IN
                                                   (
                                                      SELECT
                                                         license_plate
                                                      FROM
                                                         bakery_security_logs
                                                      WHERE
                                                         day = 28
                                                         AND month = 7
                                                         AND hour = 10
                                                         AND minute > 15
                                                         AND minute <= 25
                                                         AND activity = 'exit'
                                                   )
                                             )
                                             AND t.atm_location = 'Leggett Street'
                                             AND t.transaction_type = 'withdraw'
                                             AND t.day = 28
                                       )
                                 )
                                 AND c.day = 28
                                 AND c.month = 7
                           )
                           AND calls.caller IN
                           (
                              SELECT
                                 phone_number
                              FROM
                                 people
                              WHERE
                                 id IN
                                 (
                                    SELECT
                                       person_id
                                    FROM
                                       bank_accounts AS a
                                       JOIN
                                          atm_transactions AS t
                                          ON a.account_number = t.account_number
                                    WHERE
                                       a.person_id IN
                                       (
                                          SELECT
                                             id
                                          FROM
                                             people
                                          WHERE
                                             license_plate IN
                                             (
                                                SELECT
                                                   license_plate
                                                FROM
                                                   bakery_security_logs
                                                WHERE
                                                   day = 28
                                                   AND month = 7
                                                   AND hour = 10
                                                   AND minute > 15
                                                   AND minute <= 25
                                                   AND activity = 'exit'
                                             )
                                       )
                                       AND t.atm_location = 'Leggett Street'
                                       AND t.transaction_type = 'withdraw'
                                       AND t.day = 28
                                 )
                           )
                           AND calls.day = 28
                           AND calls.month = 7
                     )
                     AND f.day = 29
                     AND p.passport_number IS NOT NULL
               )
         )
         AND c.day = 28
         AND c.month = 7
   )
   AND calls.day = 28
   AND calls.month = 7
   AND calls.duration <= 60;
--> Robin is the one who talks with bruce

