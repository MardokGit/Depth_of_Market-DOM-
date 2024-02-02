#include <Windows.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct offer
{
	double price;
	int count;
};

class DOM
{
public:
	vector<offer> bid;
	vector<offer> ask;

	void ins_bid(offer of)
	{
		bid.push_back(of);
	}
	void ins_ask(offer of)
	{
		ask.push_back(of);
	}

	vector<offer> sort_vec(vector<offer> vec)
	{
		vector<offer> new_vec;
		while (!empty(vec))
		{
			int index_erase = 0;
			double max = 0;
			offer max_of;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].price > max)
				{
					max = vec[i].price;
					max_of = vec[i];
					index_erase = i;
				}
			}
			new_vec.push_back(max_of);
			vec.erase(vec.begin() + index_erase);
		}
		return new_vec;
	}

	void Output()
	{
		printf("bid\t|price\t|ask\n");

		for (int i = 0; i < 10; i++)
			printf("\t|%.2f\t|%u\n", ask[i].price, ask[i].count);

		for (int i = bid.size() - 1; i > bid.size() - 11; i--)
			printf("%u\t|%.2f\t\n", bid[i].count, bid[i].price);

		printf("\n\n\n\n");
	}
};

offer rand_offer()
{
	double price = (rand() % 10) + ((double)rand() / 100);
	int count = rand() % 1000;
	return { price,count };
}

int main()
{
	milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	unsigned __int64 count_ms = ms.count();
	srand(count_ms);

	DOM dom;
	offer of;
	vector<offer> vec_vec;

	while (true)
	{
		dom.ask.push_back(rand_offer());
		dom.bid.push_back(rand_offer());

		if(dom.ask.size() > 10 && dom.bid.size() > 10)
		{
			dom.ask = dom.sort_vec(dom.ask);
			dom.bid = dom.sort_vec(dom.bid);
			dom.Output();
		}
	}

	return 0;
}