from cs50 import get_string


def calcGrade(letters, words, sentences):
    l = (letters / words) * 100
    s = (sentences / words) * 100

    grade = 0.0588 * l - 0.296 * s - 15.8

    grade = round(grade)
    return grade


def main():
    text = get_string("Text: ")

    letters = 0
    words = 0
    sentences = 0

    for i in range(len(text)):
        if (text[i].isalpha()):
            letters += 1
        elif (text[i] == " " and i > 0):
            words += 1
        elif (text[i] == "!" or text[i] == "." or text[i] == "?"):
            sentences += 1

    grade = calcGrade(letters, words + 1, sentences)

    if (grade >= 16):
        print("Grade 16+")
    elif (grade < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


main()
