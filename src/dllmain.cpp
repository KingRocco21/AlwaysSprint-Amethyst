#include "dllmain.hpp"
#include <amethyst/runtime/ModContext.hpp>
#include <amethyst/runtime/events/InputEvents.hpp>
#include <amethyst/Log.hpp>

void RegisterInputs(RegisterInputsEvent& event)
{
    auto& keymappings{ Amethyst::GetContext().mOptions->mKeyboardRemappings };

    // "key.sprint" is at index 17 for regular controls.
    keymappings.at(0)->mKeymappings.at(17).mAllowRemap = false;
    keymappings.at(0)->mKeymappings.at(17).mKeys = { 87 }; // 87 = W

    // "key.sprint" is at index 34 for full keyboard controls.
    keymappings.at(1)->mKeymappings.at(34).mAllowRemap = false;
    keymappings.at(1)->mKeymappings.at(34).mKeys = { 87 }; // 87 = W
}

ModFunction void Initialize(AmethystContext& ctx) 
{
    Amethyst::InitializeAmethystMod(ctx);

    Amethyst::GetEventBus().AddListener<RegisterInputsEvent>(&RegisterInputs);

    Log::Info("[AlwaysSprint] Mod successfully initialized!");
}
