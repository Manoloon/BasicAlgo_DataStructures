#pragma once
/*
implementacion de Bimap
Un bimap mantiene una relación uno a uno entre dos tipos L y R, 
permitiendo búsquedas eficientes en ambos sentidos.
Complejidad promedio O(1)
*/
#include <unordered_map>
#include <optional>
#include <stdexcept>
#include <iostream>

template<typename L, typename R>
class bimap
{
    public:
        void insert(const L& left, const R& right)
        {
            if (left_to_right.contains(left))
            {
                throw std::logic_error("Duplicate left key in bimap");
            }
            if (right_to_left.contains(right))
            {
                throw std::logic_error("Duplicate right key in bimap");
            }
            left_to_right[left] = right;
            right_to_left[right] = left;
        }

        bool erase_left(const L& left)
        {
            auto it = left_to_right.find(left);
            if ( it == left_to_right.end())
            {
                return false;
            }
            right_to_left.erase(it->second);
            left_to_right.erase(it);
            return true;
        }

        bool erase_right(const R& right)
        {
            auto it = right_to_left.find(right);
            if (it == right_to_left.end())
            {
                return false;
            }
            left_to_right.erase(it->second);
            right_to_left.erase(it);
            return true;
        }
        [[nodiscard]]
        std::optional<R> get_right(const L& left) const 
        {
            auto it = left_to_right.find(left);
            if (it == left_to_right.end())
            {
                return std::nullopt;
            }
            return it->second;
        }
        [[nodiscard]]
        std::optional<L> get_left(const R& right) const 
        {
            auto it = right_to_left.find(right);
            if (it == right_to_left.end())
            {
                return std::nullopt;
            }
            return it->second;
        }
        [[nodiscard]]
        bool contains_left(const L& left) const { return left_to_right.contains(left);}
        [[nodiscard]]
        bool contains_right(const R& right) const {return right_to_left.contains(right);}

        void clear()
        {
            left_to_right.clear();
            right_to_left.clear();
        }
        [[nodiscard]]
        std::size_t size() const { return left_to_right.size();}
        [[nodiscard]]
        bool is_empty() const { return left_to_right.empty();}
    private:
    std::unordered_map<L,R> left_to_right;
    std::unordered_map<R,L> right_to_left;
};

void Example()
{
        bimap<int, std::string> ids;

    ids.insert(1, "Player");
    ids.insert(2, "Enemy");

    if (auto r = ids.get_right(1)) {
        std::cout << *r << '\n';  // Player
    }

    if (auto l = ids.get_left("Enemy")) {
        std::cout << *l << '\n';  // 2
    }

    ids.erase_left(1);
}