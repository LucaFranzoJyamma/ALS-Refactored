#include "Utility/AlsGameplayTags.h"

namespace AlsViewModeTags
{
	UE_DEFINE_GAMEPLAY_TAG(FirstPerson, FName{TEXTVIEW("Als.ViewMode.FirstPerson")})
	UE_DEFINE_GAMEPLAY_TAG(ThirdPerson, FName{TEXTVIEW("Als.ViewMode.ThirdPerson")})
}

namespace AlsLocomotionModeTags
{
	UE_DEFINE_GAMEPLAY_TAG(Grounded, FName{TEXTVIEW("Als.LocomotionMode.Grounded")})
	UE_DEFINE_GAMEPLAY_TAG(InAir, FName{TEXTVIEW("Als.LocomotionMode.InAir")})
}

namespace AlsRotationModeTags
{
	UE_DEFINE_GAMEPLAY_TAG(VelocityDirection, FName{TEXTVIEW("Als.RotationMode.VelocityDirection")})
	UE_DEFINE_GAMEPLAY_TAG(ViewDirection, FName{TEXTVIEW("Als.RotationMode.ViewDirection")})
	UE_DEFINE_GAMEPLAY_TAG(Aiming, FName{TEXTVIEW("Als.RotationMode.Aiming")})
}

namespace AlsStanceTags
{
	UE_DEFINE_GAMEPLAY_TAG(Standing, FName{TEXTVIEW("Als.Stance.Standing")})
	UE_DEFINE_GAMEPLAY_TAG(Crouching, FName{TEXTVIEW("Als.Stance.Crouching")})
}

namespace AlsGaitTags
{
	UE_DEFINE_GAMEPLAY_TAG(Walking, FName{TEXTVIEW("Als.Gait.Walking")})
	UE_DEFINE_GAMEPLAY_TAG(Running, FName{TEXTVIEW("Als.Gait.Running")})
	UE_DEFINE_GAMEPLAY_TAG(Sprinting, FName{TEXTVIEW("Als.Gait.Sprinting")})
}

namespace AlsOverlayModeTags
{
	UE_DEFINE_GAMEPLAY_TAG(Default, TEXT("Als.OverlayMode.Default"))
	// UE_DEFINE_GAMEPLAY_TAG(Masculine, TEXT("Als.OverlayMode.Masculine"))
	// UE_DEFINE_GAMEPLAY_TAG(Feminine, TEXT("Als.OverlayMode.Feminine"))
	// UE_DEFINE_GAMEPLAY_TAG(Injured, TEXT("Als.OverlayMode.Injured"))
	// UE_DEFINE_GAMEPLAY_TAG(HandsTied, TEXT("Als.OverlayMode.HandsTied"))
	// UE_DEFINE_GAMEPLAY_TAG(M4, TEXT("Als.OverlayMode.M4"))
	// UE_DEFINE_GAMEPLAY_TAG(PistolOneHanded, TEXT("Als.OverlayMode.PistolOneHanded"))
	// UE_DEFINE_GAMEPLAY_TAG(PistolTwoHanded, TEXT("Als.OverlayMode.PistolTwoHanded"))
	// UE_DEFINE_GAMEPLAY_TAG(Bow, TEXT("Als.OverlayMode.Bow"))
	// UE_DEFINE_GAMEPLAY_TAG(Torch, TEXT("Als.OverlayMode.Torch"))
	// UE_DEFINE_GAMEPLAY_TAG(Binoculars, TEXT("Als.OverlayMode.Binoculars"))
	// UE_DEFINE_GAMEPLAY_TAG(Box, TEXT("Als.OverlayMode.Box"))
	// UE_DEFINE_GAMEPLAY_TAG(Barrel, TEXT("Als.OverlayMode.Barrel"))
}

namespace AlsLocomotionActionTags
{
	UE_DEFINE_GAMEPLAY_TAG(Mantling, FName{TEXTVIEW("Als.LocomotionAction.Mantling")})
	UE_DEFINE_GAMEPLAY_TAG(Ragdolling, FName{TEXTVIEW("Als.LocomotionAction.Ragdolling")})
	UE_DEFINE_GAMEPLAY_TAG(GettingUp, FName{TEXTVIEW("Als.LocomotionAction.GettingUp")})
	UE_DEFINE_GAMEPLAY_TAG(Rolling, FName{TEXTVIEW("Als.LocomotionAction.Rolling")})
}

namespace AlsGroundedEntryModeTags
{
	UE_DEFINE_GAMEPLAY_TAG(FromRoll, FName{TEXTVIEW("Als.GroundedEntryMode.FromRoll")})
}
