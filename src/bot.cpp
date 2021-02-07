#include "bot.h"

#include <nlohmann/json.hpp>
#include <sc2api/sc2_data.h>
#include <sc2api/sc2_interfaces.h>
#include <sc2api/sc2_typeenums.h>

#include <cstdlib>
#include <iostream>

using json = nlohmann::json;

void Bot::OnGameStart()
{
    json stableids;

    const sc2::UnitTypes& types = Observation()->GetUnitTypeData();

    for (const auto& i : types)
    {
        if (i.unit_type_id == 0)
        {
            json invalid = json::object();
            invalid["id"] = 0;
            invalid["name"] = "NotAUnit";

            stableids["Units"].push_back(invalid);
            continue;
        }

        if (i.name.empty())
            continue;

        json item = json::object();
        item["id"] = static_cast<int>(i.unit_type_id);
        item["name"] = i.name;

        stableids["Units"].push_back(item);
    }

    const sc2::Abilities& abilities = Observation()->GetAbilityData();

    for (const auto& i : abilities)
    {
        if (i.link_name.empty() && i.button_name.empty())
            continue;

        json item = json::object();
        item["id"] = static_cast<int>(i.ability_id);
        item["name"] = i.link_name;

        if (i.button_name.empty())
            item["buttonname"] = "";
        else
            item["buttonname"] = i.button_name;

        // NOTE (alkurbatov): Should have been named "Morph Baneling", not "Train Baneling".
        //                    Discard wrong friendlyname.
        if (!i.friendly_name.empty() && i.friendly_name != "Train Baneling")
            item["friendlyname"] = i.friendly_name;

        item["index"] = i.link_index;

        if (i.remaps_to_ability_id)
            item["remapid"] = i.remaps_to_ability_id;

        stableids["Abilities"].push_back(item);
    }

    const sc2::Upgrades& upgrades = Observation()->GetUpgradeData();
    for (const auto& i : upgrades)
    {
        if (i.upgrade_id == 0)
        {
            json item = json::object();
            item["id"] = i.upgrade_id;
            item["name"] = "Null";

            stableids["Upgrades"].push_back(item);
            continue;
        }

        if (i.name.empty())
            continue;

        json item = json::object();
        item["id"] = i.upgrade_id;
        item["name"] = i.name;

        stableids["Upgrades"].push_back(item);
    }

    const sc2::Buffs& buffs = Observation()->GetBuffData();
    for (const auto& i : buffs)
    {
        if (i.buff_id == 0)
        {
            json item = json::object();
            item["id"] = i.buff_id;
            item["name"] = "Null";

            stableids["Buffs"].push_back(item);
            continue;
        }

        if (i.name.empty())
            continue;

        json item = json::object();
        item["id"] = i.buff_id;
        item["name"] = i.name;

        stableids["Buffs"].push_back(item);
    }

    const sc2::Effects& effects = Observation()->GetEffectData();
    for (const auto& i : effects)
    {
        if (i.effect_id == 0)
        {
            json item = json::object();
            item["id"] = i.effect_id;
            item["name"] = "Null";

            stableids["Effects"].push_back(item);
            continue;
        }

        if (i.name.empty())
            continue;

        json item = json::object();
        item["id"] = i.effect_id;
        item["name"] = i.name;
        item["friendlyname"] = i.friendly_name;

        stableids["Effects"].push_back(item);
    }

    std::cout << stableids.dump(4) << std::endl;
}

void Bot::OnStep()
{
    std::exit(0);
}
