#include "compilejob.h"
#include <iostream>
#include <string>
#include <array>

void CompileJob::Execute()
{
    std::array<char, 128> buffer;
    std::string command = "MinGW32-make -s -C C:\\Users\\giova_pwwkjqa\\OneDrive\\Escritorio\\SMU\\lab-1-multithreading-giovabos11\\Code project1"; // This should be "make -s -C Code project1"

    // Redirect cerr to cout
    command.append(" 2>&1");

    // Open pile and run command
#ifdef __linux__
    FILE *pipe = popen(command.c_str(), "r");
#elif _WIN32
    FILE *pipe = _popen(command.c_str(), "r");
#else
    FILE *pipe = popen(command.c_str(), "r");
#endif

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
#ifdef __linux__
    this->returnCode = pclose(pipe);
#elif _WIN32
    this->returnCode = _pclose(pipe);
#else
    this->returnCode = pclose(pipe);
#endif

    std::cout << "Job " << this->GetUniqueID() << " Has Been Executed" << std::endl;
}

void CompileJob::JobCompleteCallback()
{
    std::cout << "Compile Job " << this->GetUniqueID() << " Return Code" << this->returnCode << std::endl;
    std::cout << "Compile Job " << this->GetUniqueID() << " Output: \n"
              << this->output << std::endl;
}