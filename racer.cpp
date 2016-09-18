#include "racer.h"

Racer::~Racer(){
	WaitFor();
}

void Racer::WaitFor(){
	if(work_horse.joinable()){
		work_horse.join();
	}
}

string Racer::CopyProgress(){
	progress_mutex.lock();
	string result(progress.begin(),progress.end());
	progress_mutex.unlock();
}

void Racer::Run(){
	while(!go){}
	
	
}