#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

enum {
	VECTOR,
	DEQUE,
};


class PmergeMe
{
	private :
		std::vector<int>	vec;
		std::deque<int>		deq;
		double			TimeVec;
		double			TimeDeq;
	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		void	PushNumber(int num);
		void	PrintVector();
		void	MergeInsertion(size_t left, size_t right, int type);
		int		GetSize();
		double	GetTimeVec();
		double	GetTimeDeq();
		void	Merge(size_t left, size_t right, size_t mid);
		void	MergeDeque(size_t left, size_t right, size_t mid);
		void	Insertion(int type);
		void	PrintDeque();
		void	Sort();
};
