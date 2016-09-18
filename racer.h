#ifndef RACER
#define RACER

#include <thread>
#include <vector>
#include <mutex>
#include <string>
using std::thread;
using std::vector;
using std::mutex;
using std::string;

class Racer{
private:
	static bool go;
	vector<char> progress;
	mutex progress_mutex;
	thread* work_horse;
	
	void Run();
	
public:
	static void Start(){go = true;};
	~Racer();
	void WaitFor();
	string CopyProgress();	
};

bool Racer::go = false;

#endif