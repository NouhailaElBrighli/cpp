#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq(), TimeVec(0.0), TimeDeq(0.0)
{

}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->vec = obj.vec;
		this->deq = obj.deq;
		this->TimeDeq = obj.TimeDeq;
		this->TimeVec = obj.TimeVec;
	}
	return(*this);
}

PmergeMe::PmergeMe(const PmergeMe &obj) : vec(obj.vec), deq(obj.deq), TimeVec(obj.TimeVec) ,TimeDeq(obj.TimeDeq)
{

}

/**************************************************************************/

void	PmergeMe::PushNumber(int num)
{
	this->vec.push_back(num);
	this->deq.push_back(num);
}

void	PmergeMe::PrintVector()
{
	std::vector<int> ::iterator itr;

	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void	PmergeMe::PrintDeque()
{
	std::deque<int> ::iterator itr;

	for (itr = deq.begin(); itr != deq.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

void	PmergeMe::Merge(size_t left, size_t right, size_t mid)
{
	std::vector<int> left_vec;
	std::vector<int> right_vec;

	size_t i = left;
	size_t k = left;
	size_t l = 0;
	size_t r = 0;


	while (i <= mid)
		left_vec.push_back(this->vec[i++]);
	while (i <= right)
		right_vec.push_back(this->vec[i++]);// (mid + 1)++


	while (r < right_vec.size() && l < left_vec.size())
	{
		if (left_vec[l] < right_vec[r])
			this->vec[k++] = left_vec[l++];
		else
			this->vec[k++] = right_vec[r++];
	}

	while (r < right_vec.size())
		this->vec[k++] = right_vec[r++];
	while (l < left_vec.size())
		this->vec[k++] = left_vec[l++];
}

void	PmergeMe::MergeDeque(size_t left, size_t right, size_t mid)
{
	std::deque<int> left_deq;
	std::deque<int> right_deq;
	size_t i = left;
	size_t k = left;
	size_t r = 0;
	size_t l = 0;

	while (i <= mid)
		left_deq.push_back(deq[i++]);
	while (i <= right)
		right_deq.push_back(deq[i++]);
	
	while (r < right_deq.size() && l < left_deq.size())
	{
		if (left_deq[l] < right_deq[r])
			this->deq[k++] = left_deq[l++];
		else
			this->deq[k++] = right_deq[r++];
	}

	while (r < right_deq.size())
		this->deq[k++] = right_deq[r++];
	while (l < left_deq.size())
		this->deq[k++] = left_deq[l++];
}

double	PmergeMe::GetTimeVec()
{
	return(TimeVec);
}

double	PmergeMe::GetTimeDeq()
{
	return(TimeDeq);
}

void	PmergeMe::MergeInsertion(size_t left, size_t right, int type)
{
	if (right - left + 1 <= 250)
		Insertion(type);
	if (right > left)
	{
		int mid =  (left + right) / 2;
		MergeInsertion(left, mid, type);
		MergeInsertion(mid + 1, right, type);
		if (type == VECTOR)
			this->Merge(left, right, mid);
		else
			this->MergeDeque(left, right , mid);
	}
}

int		PmergeMe::GetSize()
{
	return(this->vec.size());
}

void	PmergeMe::Insertion(int type)
{
	int size = GetSize();
	int j;
	if (type == VECTOR)
	{
		for (int i = 1; i < size; i++)
		{
			j = i;
			while (j > 0)
			{
				if (vec[j] < vec[j - 1])
					std::swap(vec[j], vec[j - 1]);
				j--;
			}
		}
	}
	else
	{
		for(int i = 1; i < size; i++)
		{
			j = i;
			while (j > 0)
			{
				if (deq[j] < deq[j - 1])
					std::swap(deq[j], deq[j - 1]);
				j--;
			}			
		}
	}
}

void	PmergeMe::Sort()
{
	std::cout << "Before: ";
	PrintVector();
	clock_t start_deq = clock();
	MergeInsertion(0, GetSize() - 1, DEQUE);
	clock_t end_deq = clock();
	clock_t start_vec= clock();
	MergeInsertion(0, GetSize() - 1, VECTOR);
	clock_t end_vec= clock();
	std::cout << "After: ";
	PrintVector();
	TimeVec = (static_cast<double>(end_vec - start_vec) / static_cast<double> (CLOCKS_PER_SEC)) * 1000000.0;
	TimeDeq = (static_cast<double>(end_deq - start_deq) / static_cast<double> (CLOCKS_PER_SEC)) * 1000000.0;
}
