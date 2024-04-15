def main() -> None:
    try:
        with open("app/passwordFileReader/passwords.txt", "r") as file:
            lines = file.readlines()

        cleaned_lines = [line.strip() for line in lines]

        with open("app/passwordFileReader/passwords.txt", "w") as file:
            file.write("\n".join(cleaned_lines))
    except IOError as e:
        print("File open error:", e)


if __name__ == "__main__":
    print("Removing blank spaces from passwords.txt")
    main()
