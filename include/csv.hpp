#ifndef CSVPP_CSV_HPP_
#define CSVPP_CSV_HPP_

#include <fstream> // ifstream
#include <optional> // optional
#include <ranges> // views::split, views::transform
#include <string_view> // string_view
#include <vector> // vector


namespace csvpp
{

using result_type = std::vector<std::vector<std::string>>;

auto read_csv(std::string_view file, std::string_view type = "", std::string_view delimiter = ",")
    -> std::optional<result_type>
{
    std::ifstream data_file(file.data());
    if (!data_file.is_open())
    {
        return {};
    }

    std::string line;
    std::getline(data_file, line); // skip the title
    result_type result;
    while (std::getline(data_file, line))
    {
        auto tokens = line
                    | std::views::split(delimiter)
                    | std::views::transform([](auto&& token) {
                        return std::string_view(&*token.begin(), std::ranges::distance(token));
                    });

        auto it = std::ranges::begin(tokens);
        std::ranges::advance(it, 2);
        if (type.empty() || *it == type)
        {
            // save all records or filtered records.
            result.push_back(result_type::value_type(tokens.begin(), tokens.end()));
        }
    }

    return result;
}


} // namespace csvpp

#endif // CSVPP_CSV_HPP_
