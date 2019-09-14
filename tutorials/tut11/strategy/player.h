#ifndef ___PLAYER___H__
#define ___PLAYER___H__

class Player{
 public:
	virtual int guess() = 0;
	virtual ~Player() = default;
	Player(int min, int max);
	virtual void update(int cmp);
 protected:
	int min, max;
};

class Human: public Player{
 public:
	int guess() override;
	Human(int min, int max);
};

class Easy: public Player{
 public:
	int guess() override;
	Easy(int min, int max);
};

class Hard: public Player{
 public:
	int guess() override;
	Hard(int min, int max);
	void update(int cmp) override;
 private:
  int max_possible, min_possible;
	int prevGuess;
};

#endif
