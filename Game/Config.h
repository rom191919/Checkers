#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../Models/Project_path.h"

class Config //отвечает за обработку настроек
{
  public:
    Config()
    {
        reload();
    }

    void reload()
    {
        std::ifstream fin("settings.json"); //загрузка настроек из файла
        fin >> config;
        fin.close();
    }

    auto operator()(const string &setting_dir, const string &setting_name) const //оператор круглые скобки позволяет получать нужную настроку из setting_dir и setting_name
    {
        return config[setting_dir][setting_name];
    }

  private:
    json config; //загружает и сохраняет
};
