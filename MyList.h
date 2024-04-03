#pragma once

template <typename ValueType>
class MyList
{
public:
    int Count;
    MyList() = default;
    MyList(const std::initializer_list<ValueType>& initList) : list_(initList) {}

    ValueType& operator[](const ValueType& key)
    {
        auto& value = list_[key];
        Count = list_.size();
        return value;
    }
    auto begin() const
    {
        return list_.begin();
    }

    auto end() const
    {
        return list_.end();
    }

    ValueType* data()
    {
        return list_.data();
    }
    void Resize(size_t size)
    {
        list_.resize(size);
    }
    void Add(const ValueType& value)
    {
        list_.push_back(value);
        Count = list_.size();
    }

    bool Contains(const ValueType& value) const
    {
        return std::find(list_.begin(), list_.end(), value) != list_.end();
    }

    bool Remove(const ValueType& value)
    {
        auto it = std::find(list_.begin(), list_.end(), value);
        if (it != list_.end())
        {
            list_.erase(it);
            Count = list_.size();
            return true;
        }
        return false;
    }

private:
    std::vector<ValueType> list_;
};
