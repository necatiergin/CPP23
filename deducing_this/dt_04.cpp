#include <optional>

template <typename T>
class Optional {
public:
    bool has_value()const;
    //...
    template <typename Self>
    constexpr decltype(auto) value(this Self&& self)
    {
        if (has_value())
            return std::forward<Self>(self).m_value;

        throw std::bad_optional_access();
    }

private:
    T m_value;
};
