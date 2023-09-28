#include "compilejob.h"
#include <iostream>
#include <string>
#include <array>

void CompileJob::Execute()
{
    std::array<char, 128> buffer;
    std::string command = "make project_1";

    // Redirect cerr to cout
    command.append(" 2>&1");

    // Open pile and run command
    FILE *pipe = _popen(command.c_str(), "r");

    if (!pipe)
    {
        std::cout << "popen Failed: Failed to open pipe" << std::endl;
        return;
    }

    // Read until the end of the process
    while (fgets(buffer.data(), 128, pipe) != NULL)
    {
        this->output.append(buffer.data());
    }

    // Close pipe and get the return code
    this->returnCode = _pclose(pipe);

    std::cout << "Job " << this->GetUniqueID() << " Has Been Executed" << std::endl;
}

void CompileJob::JobCompleteCallback()
{
    std::cout << "Compile Job " << this->GetUniqueID() << " Return Code" << this->returnCode << std::endl;
    std::cout << "Compile Job " << this->GetUniqueID() << " Output: \n"
              << this->output << std::endl;
}