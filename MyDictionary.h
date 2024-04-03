#pragma once

template <typename KeyType, typename ValueType>
class MyDictionary
{
public:
    int Count;
    MyDictionary() = default;
    MyDictionary(const std::initializer_list<std::pair<KeyType, ValueType>>& initList) : dictionary_(initList) {}

    ValueType& operator[](const KeyType& key)
    {
        auto& value = dictionary_[key];
        Count = dictionary_.size();
        return value;
    }
    auto begin() const
    {
        return dictionary_.begin();
    }

    auto end() const
    {
        return dictionary_.end();
    }
    void Add(const KeyType& key, const ValueType& value)
    {
        dictionary_[key] = value;
        Count = dictionary_.size();
    }

    bool ContainsKey(const KeyType& key) const
    {
        return dictionary_.find(key) != dictionary_.end();
    }

    bool TryGetValue(const KeyType& key, ValueType& value) const
    {
        auto it = dictionary_.find(key);
        if (it != dictionary_.end())
        {
            value = it->second;
            Count = dictionary_.size();
            return true;
        }
        return false;
    }

    bool TryRemove(const KeyType& key)
    {
        auto it = dictionary_.find(key);
        if (it != dictionary_.end())
        {
            dictionary_.erase(it);
            Count = dictionary_.size();
            return true;
        }
        return false;
    }

    void Clear()
    {
        Count = 0;
        dictionary_.clear();
    }

private:
    std::map<KeyType, ValueType> dictionary_;
};
