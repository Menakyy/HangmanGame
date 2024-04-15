#include "CppUTest/TestHarness.h"
#include "app/passwordFileReader/PasswordFileReader.h"

#include <string>

TEST_GROUP(PasswordFileReaderTestsGroup)
{
    PasswordFileReader* passwordFileReader = nullptr;

    void setup()
    {
        /*
        INFO
        The file passwords.txt contains 5 passwords
        */
        passwordFileReader = new PasswordFileReader("tests/utils/passwords.txt");
    }

    void teardown()
    {
        delete passwordFileReader;
    }
};


TEST(PasswordFileReaderTestsGroup, InitTest)
{
    CHECK_EQUAL("", passwordFileReader->getPassword());
    CHECK_EQUAL(0, passwordFileReader->getPasswords().size());
    CHECK_EQUAL(5, passwordFileReader->getFileLines());
    CHECK_EQUAL(PasswordFileReader::FileStatus::FILE_OK, passwordFileReader->getFileStatus());
}

TEST(PasswordFileReaderTestsGroup, DrawPasswordTest)
{
    CHECK_EQUAL(PasswordFileReader::FileStatus::FILE_OK, passwordFileReader->getFileStatus());
    CHECK_EQUAL(5, passwordFileReader->getFileLines());
    passwordFileReader->randomLineAndGetPassword();
    CHECK_EQUAL(1, passwordFileReader->getPasswords().size());
    CHECK_FALSE(passwordFileReader->isMaxPasswords());
}

TEST(PasswordFileReaderTestsGroup, MultipleDrawPasswordTest)
{
    CHECK_EQUAL(PasswordFileReader::FileStatus::FILE_OK, passwordFileReader->getFileStatus());
    CHECK_EQUAL(5, passwordFileReader->getFileLines());
    for (size_t i = i; i <= passwordFileReader->getFileLines(); i++)
    {
        passwordFileReader->randomLineAndGetPassword();
        CHECK_EQUAL(i, passwordFileReader->getPasswords().size());
    }
    CHECK_EQUAL(passwordFileReader->getFileLines(), passwordFileReader->getPasswords().size());
    CHECK_TRUE(passwordFileReader->isMaxPasswords());
}