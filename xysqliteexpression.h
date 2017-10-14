#ifndef XYSQLITEEXPRESSION
#define XYSQLITEEXPRESSION

#include <QString>

const QString createStudentTable = "CREATE TABLE Student( \
        ID INTEGER PRIMARY KEY AUTOINCREMENT, \
        Number     INTEGER  NOT NULL, \
        Name       CHAR(50) NOT NULL, \
        Sex        CHAR(10) NOT NULL, \
        Unit       CHAR(50) NOT NULL£¬ \
        IDCard     CHAR(50) NOT NULL£¬ \
        Phonenumber CHAR(20) NOT NULL );";

const QString createCourseTable = "CREATE TABLE Course( \
        ID INTEGER PRIMARY KEY AUTOINCREMENT, \
        Theme    CHAR(50) NOT NULL, \
        Teacher  CHAR(50) NOT NULL, \
        DateTime CHAR(50) NOT NULL, \
        Place    CHAR(50) NOT NULL£¬ \
        DurationTime INTEGER  NOT NULL£¬ \
        Students     INTEGER  NOT NULL,\
        Status       CHAR(50) NOT NULL );";

const QString createServeTable = "CREATE TABLE Serve( \
        ID INTEGER PRIMARY KEY AUTOINCREMENT, \
        Theme        CHAR(50) NOT NULL, \
        DutyOfficer  CHAR(50) NOT NULL, \
        DateTime     CHAR(50) NOT NULL, \
        Place        CHAR(50) NOT NULL£¬ \
        DurationTime INTEGER  NOT NULL£¬ \
        Students     INTEGER  NOT NULL,\
        Status       CHAR(50) NOT NULL );";

const QString DropStudentTable = "DROP TABLE Student";
const QString DropCourseTable = "DROP TABLE Course";
const QString DropServeTable = "DROP TABLE Serve";

const QString InsertStudent = "INSERT INTO Student (Number, Name, Sex, Unit, IDCard, Phonenumber)\
                              VALUES (:Number, :Name, :Sex, :Unit, :IDCard, :Phonenumber)";
const QString InsertCourse = "INSERT INTO Course (Theme, Teacher, DateTime, Place, DurationTime, Students, Status)\
                             VALUES (:Theme, :Teacher, :DateTime, :Place, :DurationTime, :Students, :Status)";
const QString InsertServe = "INSERT INTO Serve (Theme, DutyOfficer, DateTime, Place, DurationTime, Students, Status)\
                            VALUES (:Theme, :DutyOfficer, :DateTime, :Place, :DurationTime, :Students, :Status)";

const QString SearchStudent = "SELECT * FROM Student limit %1, %2";
const QString SearchCourse = "SELECT * FROM Course limit %1, %2";
const QString SearchServe = "SELECT * FROM Serve limit %1, %2";
#endif // XYSQLITEEXPRESSION

