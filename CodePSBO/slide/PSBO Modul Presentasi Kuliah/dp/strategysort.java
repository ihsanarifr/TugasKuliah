interface StrategySort
{
	Array sort(Array data);
}

class StrategyBubbleSort implements StrategySort
{
	Array sort(Array data)
	{
		/* buble sort */

		return data;
	}
}

class StrategyQuickSort implements StrategySort
{
	Array sort(Array data)
	{
		/* buble sort */

		return data;
	}
}

class SortContext
{
	StrategySort strategy;
	Array data;

	SortContext(Array d)
	{
		this.data = d;
	}

	void setData(Array d)
	{
		this.data = d;
	}

	void setStrategy(StrategySort s)
	{
		this.strategy = s;
	}

	
	void doSort()
	{
		data = strategy.sort(data);
	}
}


class MainExample
{
	public static void main()
	{
		SortContext s;
		s = new SortContext(data);
		s.setStrategy(new StrategyQuickSort());
		/* .......... -->> data */ 
		
		
		s.doSort();

		s.setData(data2);
		s.doSort();

		s.setData(data3);
		s.doSort();

	}
}
