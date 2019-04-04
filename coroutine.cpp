#include <boost/coroutine/all.hpp>
#include <iostream>

using namespace boost::coroutines;

void coro(coroutine<void>::push_type &yield)
{
	std::cout << "[coro]: Helloooooooooo" << std::endl;
	/* Suspend here, wait for resume. */
	yield();
	std::cout << "[coro]: Just awesome, this coroutine " << std::endl;
}

int main()
{
	coroutine<void>::pull_type resume{coro};
	/* coro is called once, and returns here. */

	std::cout << "[main]: ....... " << std::endl; //flush here

	/* Now resume the coro. */
	resume();

	std::cout << "[main]: here at NETWAYS! :)" << std::endl;
}
