#ifndef JOB_SYSTEM_COMPILEJOB_H
#define JOB_SYSTEM_COMPILEJOB_H

#include "job.h"
#include <string>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

class CompileJob : public Job
{
public:
    CompileJob(unsigned long jobChannels, int jobType, std::string cmd)
        : Job(jobChannels, jobType), command(cmd){};

    ~CompileJob(){};

    std::string output;
    int returnCode;

    void Execute();
    void parseFile();
    void JobCompleteCallback();

    void generateJson(std::string &);

private:
    json outputJson;
    std::string command;
    std::string projectName;
};

#endif // JOB_SYSTEM_COMPILEJOB_H