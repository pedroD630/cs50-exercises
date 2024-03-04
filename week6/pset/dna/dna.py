import csv
import sys


def main(argv):
    data = []

    if len(argv) != 3:
        print("Correct usage: [dna.py] [csv database] [sequences]")

    with open(argv[1], 'r', newline='') as database:
        reader = csv.reader(database)

        header = []
        header = next(reader)

        for row in reader:
            data.append(row)

    with open(argv[2], 'r', newline="") as file:
        sequence = ''.join(file.readlines())

    subsequences = []
    for i in header[1:]:
        subsequences.append(i)

    sub_count = []
    for subs in subsequences:
        length = longest_match(sequence, subs)
        sub_count.append(length)

    # TODO: Check database for matching profiles
    for person in data:
        matches = True
        name = person[0]
        for count, sub in zip(person[1:], sub_count):
            count_num = int(count)
            count_sub = int(sub)

            if matches == False:
                break
            if count_num != count_sub:
                matches = False
        if matches == True:
            print(name)
            break
    if matches == False:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main(sys.argv)
