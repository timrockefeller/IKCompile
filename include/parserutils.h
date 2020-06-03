#pragma once
#include <map>
#include <unordered_map>
#include <unordered_set>
namespace IKC {
using Grim = std::unordered_map<int, std::vector<std::vector<int>>>;
using Usi = std::unordered_set<int>;
using Miu = std::map<int, Usi>;
using Mim = std::map<int, std::unordered_map<int, int>>;

}  // namespace IKC
