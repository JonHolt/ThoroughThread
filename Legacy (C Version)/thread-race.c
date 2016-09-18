#include <pthread.h>
#include <stdio.h>

//Parameters
struct thread_data
{
    char *name;
    int start_pos;
};

void* race(void* params)
{
    struct thread_data* horse;
    horse = (struct thread_data*) params;
    int reps;
    if(horse->start_pos == 1){
	reps = 100000000000;
    } else if(horse->start_pos == 2){
	reps = 99999999999;
    } else if (horse->start_pos == 3){
	reps = 99999999998;
    } else if (horse->start_pos == 4){
	reps = 99999999997;
    } else {
	return NULL;
    }

    int i;
    for(i = 0; i < reps; i++){
	int g = i * i + 6;
	if(i == reps/4){
	    int len;
            char message[50];
	    strcpy(message, horse->name);
	    strcat(message, " is 25% done!\n");
	    len = strlen(message);
	    write(1,message,len);
	} else if(i == reps/2){
	    int len;
            char message[50];
	    strcpy(message, horse->name);
	    strcat(message, " is 50% done!\n");
	    len = strlen(message);
	    write(1,message,len);
	} else if(i == 3* (reps/4)){
	    int len;
            char message[50];
	    strcpy(message, horse->name);
	    strcat(message, " is 75% done!\n");
	    len = strlen(message);
	    write(1,message,len);
	}
    }
    int len;
    char message[50];
    strcpy(message, horse->name);
    strcat(message, " has finished!\n");
    len = strlen(message);
    write(1,message,len);
    return 0;
}

int main(int argc, const char* argv[])
{
    char* horse1;
    char* horse2;
    char* horse3;
    char* horse4;

    if(argc == 5){
	horse1 = argv[1];
	horse2 = argv[2];
	horse3 = argv[3];
	horse4 = argv[4];
    } else {
    	horse1 = "First Pass";
	    horse2 = "Hoof Hearted";
	    horse3 = "Objective-C Biscuit";
	    horse4 = "C++ Biscuit";
    }

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    pthread_t thread4;

    struct thread_data args1;
    args1.name = horse1;
    args1.start_pos = 1;
    struct thread_data args2;
    args2.name = horse2;
    args2.start_pos = 2;
    struct thread_data args3;
    args3.name = horse3;
    args3.start_pos = 3;
    struct thread_data args4;
    args4.name = horse4;
    args4.start_pos = 4;

    pthread_create(&thread1, NULL, &race, &args1);
    pthread_create(&thread2, NULL, &race, &args2);
    pthread_create(&thread3, NULL, &race, &args3);
    pthread_create(&thread4, NULL, &race, &args4);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
}
