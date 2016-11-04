

using namespace std;

const int MAX_ITEMS = 10;

class StackType
{
public:
	StackType();
	bool isEmpty()const;
	bool isFull() const;
	void Push(char c);
	void Pop();
	char Top();

private:
	int top;
	char item[MAX_ITEMS];
};