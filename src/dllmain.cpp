#include "dllmain.hpp"
#include <amethyst/runtime/ModContext.hpp>
#include <amethyst/runtime/events/InputEvents.hpp>
#include <amethyst/Log.hpp>
#include <minecraft/src-client/common/client/input/Keymapping.hpp>
#include <vector>

void RegisterInputs(RegisterInputsEvent& event)
{
    AmethystContext& context{ Amethyst::GetContext() };

    std::vector<Keymapping>& keymappings1{ context.mOptions->mKeyboardRemappings.at(0)->mKeymappings };
    for (int i{ 0 }; i != keymappings1.size(); ++i)
    {
        Keymapping& current{ keymappings1.at(i) };
        if (current.mAction == "key.sprint")
        {
            Log::Info("[{}] key.sprint found at index {}", MOD_NAME, i);
            current.mKeys = { 87 };
            current.mAllowRemap = false;
        }
    }

    std::vector<Keymapping>& keymappings2{ context.mOptions->mKeyboardRemappings.at(1)->mKeymappings };
    for (int i{ 0 }; i != keymappings2.size(); ++i)
    {
        Keymapping& current{ keymappings2.at(i) };
        if (current.mAction == "key.sprint")
        {
            Log::Info("[{}] key.sprint found at index {}", MOD_NAME, i);
            current.mKeys = { 87 };
            current.mAllowRemap = false;
        }
    }
    Log::Info("");
}

ModFunction void Initialize(AmethystContext& ctx)
{
    Amethyst::InitializeAmethystMod(ctx);

    Amethyst::GetEventBus().AddListener<RegisterInputsEvent>(&RegisterInputs);

    Log::Info("[{}] Mod successfully initialized!", MOD_NAME);
}
