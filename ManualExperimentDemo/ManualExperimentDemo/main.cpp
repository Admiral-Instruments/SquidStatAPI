#include "AppThread.h"

int main(int argc, char *argv[])
{
    // We are running a manual experiment on a single thread.
	std::thread app(Dowork);
	app.join();
	return 0;
}




