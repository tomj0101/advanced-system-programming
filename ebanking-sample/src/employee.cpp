#include"employee.hpp"
Employee :: Employee()
{

}
Employee :: Employee( int empId)
{

    env = Environment::createEnvironment();
    conn = env->createConnection("e838243","Er.anshu04","ILPChnUnix");
    string sQlstmt;
    stmt = conn->createStatement();
    sQlstmt = "select * from employeedetails where emp_id=:1";
    stmt->setSQL(sQlstmt);
    stmt->setInt(1,empId);
    rs = stmt->executeQuery();
    rs->next();
    employeeId = rs->getInt(1);
    employeeFirstName = rs->getString(2);
    employeeLastName = rs->getString(3);
    dateOfJoining = rs->getString(4);

    address = rs->getString(5);
    workingBankId = rs->getInt(6);
    designation = rs->getString(7);
    rank = rs->getInt(8);

    reportingHeadId = rs->getInt(9);
    salary == rs->getInt(10);

    password = rs->getString(11);
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);

    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);
}
Employee::~Employee()
{
}
