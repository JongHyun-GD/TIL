#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T* ptr, unsigned int size, void (*f)(T))
{
	for (unsigned int i=0; i<size; ++i)
	{
		f(*ptr++);
	}
}

#endif
