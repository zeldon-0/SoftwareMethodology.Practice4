class Transport
{
public:
	virtual int GetSpeed(int distance, int time)
	{
		if (time == 0)
			return 0;
		return distance / time;
	}
};


class Car : public Transport
{
};

class Plane : public Transport
{
public: 
	Plane(int takeOffTime, int landingTime) : m_takeOffTime(takeOffTime), m_landingTime(landingTime) 
	{}

	int GetSpeed(int distance, int time) const override
	{
		if (time == 0)
			return 0;

		auto travelTime = time - getTakeOffTime() - getLandingTime();
		return distance / travelTime;
	}
	
	int getTakeOffTime() {
		return m_takeOffTime;
	}

	int getLandingTime() {
		return m_takeOffTime;
	}

private:
	int m_takeOffTime;
	int m_landingTime;
};

class Submarine : public Transport
{
public:
	Submarine(int diveTime, int ascentTime) : m_diveTime(diveTime), m_ascentTime(ascentTime)
	{}

	int GetSpeed(int distance, int time) const override
	{
		if (time == 0)
			return 0;

		auto travelTime = time - getDiveTime() - getAscentTime();
		return distance / travelTime;
	}

	int getDiveTime() {
		return m_diveTime;
	}

	int getAscentTime() {
		return m_ascentTime;
	}

private:
	int m_diveTime;
	int m_ascentTime;
};