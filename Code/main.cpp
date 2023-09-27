#include <iostream>
#include <string>

#include "jobsystem.h"
#include "compilejob.h"

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    JobSystem *js = JobSystem::CreateOrGet();

    cout << "Creating Worker Threads" << endl;

    js->CreateWorkerThread("Thread1", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread2", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread3", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread4", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread5", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread6", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread7", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread8", 0xFFFFFFFF);
    js->CreateWorkerThread("Thread9", 0xFFFFFFFF);

    cout << "Create Jobs" << endl;

    std::vector<Job *> jobs;

    CompileJob *cjb = new CompileJob(0xFFFFFFFF, 1);
    jobs.push_back(cjb);

    cout << "Queuing Jobs" << endl;

    vector<Job *>::iterator it = jobs.begin();

    for (; it != jobs.end(); it++)
    {
        js->QueueJob(*it);
    }

    int running = 1;

    while (running)
    {
        string command;
        cout << "Enter stop, destroy, finish, or status: " << endl;
        cin >> command;

        if (command == "stop")
        {
            running = 0;
        }
        else if (command == "destroy")
        {
            cout << "Destroying Job System" << endl;
            js->FinishCompletedJobs();
            js->Destroy();
            running = 0;
        }
        else if (command == "finish")
        {
            std::cout << "Finishing Jobs" << js->totalJobs << std::endl;
            js->FinishCompletedJobs();
        }
        else if (command == "finishjob")
        {
            std::cout << "Finishing Job 0" << std::endl;
            js->FinishJob(0);
        }
        else if (command == "status")
        {
            std::cout << "Job Status" << std::endl;
            for (int i = 0; i < jobs.size(); i++)
            {
                std::cout << "Job " << i << " Status: " << (int)js->GetJobStatus(i) << std::endl;
            }
        }
        else
        {
            cout << "Invalid Command" << endl;
        }
    }

    return 0;
}