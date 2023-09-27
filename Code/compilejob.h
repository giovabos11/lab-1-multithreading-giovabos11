#ifndef JOB_SYSTEM_COMPILEJOB_H
#define JOB_SYSTEM_COMPILEJOB_H

#include "job.h"
#include <string>

class CompileJob : public Job
{
public:
    CompileJob(unsigned long jobChannels, int jobType)
        : Job(jobChannels, jobType){};

    ~CompileJob(){};

    std::string output;
    int returnCode;

    void Execute();
    void JobCompleteCallback();
};

#endif // JOB_SYSTEM_COMPILEJOB_H