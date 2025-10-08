#include <optional>

template <typename T>
class Optional {
public:
    bool has_value()const;

    // version of value for non-const lvalues
    constexpr T& value()&
    {
        if (has_value()) {
            return this->m_value;
        }
        throw std::bad_optional_access();
    }

    // version of value for const lvalues
    constexpr T const& value() const&
    {
        if (has_value()) {
            return this->m_value;
        }
        throw std::bad_optional_access();
    }

    // version of value for non-const rvalues
    constexpr T&& value()&&
    {
        if (has_value()) {
            return std::move(this->m_value);
        }
        throw std::bad_optional_access();
    }

    
    constexpr T const&& value() const&&
    {
        if (has_value()) {
            return std::move(this->m_value);
        }
        throw std::bad_optional_access();
    }
    // ...
};
