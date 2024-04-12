#ifndef APP_PASSWORDFILEREADER_PASSWORDFILEREADER
#define APP_PASSWORDFILEREADER_PASSWORDFILEREADER

#include <string>
#include <vector>

class PasswordFileReader
{
public:
    /**
     * @brief Constructs a PasswordFileReader object.
     */
    PasswordFileReader();

    /**
     * @brief Destroys the PasswordFileReader object.
     */
    ~PasswordFileReader();

    /**
     * @brief Generates a random password.
     */
    void drawPassword();

    /**
     * @brief Returns the current password.
     * @return The current password as a string.
     */
    std::string getPassword() const { return _password; }

    /**
     * @brief Returns the vector of passwords.
     * @return The vector of passwords.
     */
    std::vector<int> getPasswords() const { return _passwords; }

    /**
     * @brief Calculates the number of lines in the file.
     */
    void calculateNumberOfLinesInFile();

    /**
     * @brief Picks a random line from the file and retrieves the password.
     */
    void randomLineAndGetPassword();

    /**
     * @brief Checks if the given password exists in the vector of passwords.
     * @param password The password to check.
     * @return True if the password exists, false otherwise.
     */
    bool checkForPassword(int password);

    /**
     * @brief Retrieves the password from the file based on the drawn line number.
     * @param drawnLine The line number from which to retrieve the password.
     */
    void getPasswordFromFile(int drawnLine);

private:
    int              _fileLines = 0;
    std::string      _password  = "";
    std::vector<int> _passwords = {};  // Int type because line number = password
};


#endif /* APP_PASSWORDFILEREADER_PASSWORDFILEREADER */