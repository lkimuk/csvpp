#include "csv.hpp"

#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <fmt/ranges.h>


int main() {
    // 加载数据集
//     auto chip = csvpp::read_csv("../data/chip_dataset.csv", "CPU");
//     if (chip) {
//         std::ranges::for_each(chip.value(), [](const csvpp::result_type::value_type& cpu) {
//             fmt::print("{}\n", cpu);
//         });
//     }
    csvpp::read_csv("../data/chip_dataset.csv", [](auto&& tokens) {
        fmt::print("{}\n", tokens);
    });
}
