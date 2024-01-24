#include "bot.h"

#include <sc2utils/sc2_arg_parser.h>
#include <sc2api/sc2_coordinator.h>

int main(int argc, char* argv[])
{
    sc2::ArgParser arg_parser(argv[0]);

    arg_parser.AddOptions({
            {"-p", "--GamePort", "Port of client to connect to", true},
            {"-m", "--Map", "Name or path to game map", true},
        });

    arg_parser.Parse(argc, argv);

    std::string GamePort;
    arg_parser.Get("GamePort", GamePort);

    std::string Map;
    arg_parser.Get("Map", Map);
 
    Bot bot;

    sc2::Coordinator coordinator;
    coordinator.SetParticipants(
        {
            CreateParticipant(sc2::Race::Random, &bot),
            CreateComputer(
                sc2::Race::Random,
                sc2::Difficulty::VeryEasy,
                sc2::AIBuild::Macro,
                "VeryEasy"
                )
        });

    coordinator.Connect(std::stoi(GamePort));
    coordinator.SetRawAffectsSelection(true);

    coordinator.StartGame(Map);

    while (coordinator.Update())
    {
    }

    return 0;
}
