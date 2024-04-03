class ElapsedTime
{
private:
    std::chrono::steady_clock::time_point start_time;
public:
    ElapsedTime()
    {
        start_time = std::chrono::steady_clock::now();
    }

    void Reset()
    {
        start_time = std::chrono::steady_clock::now();
    }

    long long Microseconds() const
    {
        auto end_time = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }

    long long Milliseconds() const
    {
        return Microseconds() / 1000.0;
    }

    double Seconds() const
    {
        return Milliseconds() / 1000.0;
    }

    double Minutes() const
    {
        return Seconds() / 60.0;
    }

    double Hours() const
    {
        return Minutes() / 60.0;
    }
};
