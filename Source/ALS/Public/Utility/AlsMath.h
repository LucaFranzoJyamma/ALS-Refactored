#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AlsMath.generated.h"

USTRUCT(BlueprintType)
struct ALS_API FAlsSpringFloatState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	float Velocity{ForceInit};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	float PreviousTarget{ForceInit};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	bool bStateValid{false};

	void Reset();
};

inline void FAlsSpringFloatState::Reset()
{
	Velocity = 0.f;
	PreviousTarget = 0.f;
	bStateValid = false;
}

USTRUCT(BlueprintType)
struct ALS_API FAlsSpringVectorState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FVector Velocity{ForceInit};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FVector PreviousTarget{ForceInit};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	bool bStateValid{false};

	void Reset();
};

inline void FAlsSpringVectorState::Reset()
{
	Velocity = FVector::ZeroVector;
	PreviousTarget = FVector::ZeroVector;
	bStateValid = false;
}

UCLASS()
class ALS_API UAlsMath : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static constexpr auto CounterClockwiseRotationAngleThreshold{5.0f};

public:
	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Value"))
	static float Clamp01(float Value);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Value"))
	static float LerpClamped(float From, float To, float Alpha);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Angle"))
	static float LerpAngle(float From, float To, float Alpha);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (AutoCreateRefTerm = "From, To", ReturnDisplayName = "Rotator"))
	static FRotator LerpRotator(const FRotator& From, const FRotator& To, float Alpha);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Interpolation Ammount"))
	static float Damp(float DeltaTime, float Smoothing);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Interpolation Ammount"))
	static float ExponentialDecay(float DeltaTime, float Lambda);

	template <typename ValueType>
	static ValueType Damp(const ValueType& Current, const ValueType& Target, float DeltaTime, float Smoothing);

	template <typename ValueType>
	static ValueType ExponentialDecay(const ValueType& Current, const ValueType& Target, float DeltaTime, float Lambda);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Angle"))
	static float DampAngle(float Current, float Target, float DeltaTime, float Smoothing);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Angle"))
	static float ExponentialDecayAngle(float Current, float Target, float DeltaTime, float Lambda);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (AutoCreateRefTerm = "Current, Target", ReturnDisplayName = "Rotator"))
	static FRotator DampRotator(const FRotator& Current, const FRotator& Target, float DeltaTime, float Smoothing);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (AutoCreateRefTerm = "Current, Target", ReturnDisplayName = "Rotator"))
	static FRotator ExponentialDecayRotator(const FRotator& Current, const FRotator& Target, float DeltaTime, float Lambda);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Angle"))
	static float InterpolateAngleConstant(float Current, float Target, float DeltaTime, float InterpolationSpeed);

	template <typename ValueType, typename StateType>
	static ValueType SpringDamp(const ValueType& Current, const ValueType& Target, StateType& SpringState,
	                            float DeltaTime, float Frequency, float DampingRatio, float TargetVelocityAmount = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "ALS|Als Math", Meta = (ReturnDisplayName = "Value"))
	static float SpringDampFloat(float Current, float Target, UPARAM(ref) FAlsSpringFloatState& SpringState,
	                             float DeltaTime, float Frequency, float DampingRatio, float TargetVelocityAmount = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "ALS|Als Math", Meta = (AutoCreateRefTerm = "Current, Target", ReturnDisplayName = "Vector"))
	static FVector SpringDampVector(const FVector& Current, const FVector& Target, UPARAM(ref) FAlsSpringVectorState& SpringState,
	                                float DeltaTime, float Frequency, float DampingRatio, float TargetVelocityAmount = 1.0f);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (AutoCreateRefTerm = "Vector", ReturnDisplayName = "Vector"))
	static FVector ClampMagnitude01(const FVector& Vector);

	static FVector3f ClampMagnitude01(const FVector3f& Vector);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", DisplayName = "Clamp Magnitude 01 2D",
		Meta = (AutoCreateRefTerm = "Vector", ReturnDisplayName = "Vector"))
	static FVector2D ClampMagnitude012D(const FVector2D& Vector);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (ReturnDisplayName = "Direction"))
	static FVector2D RadianToDirection(float Radian);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (ReturnDisplayName = "Direction"))
	static FVector RadianToDirectionXY(float Radian);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (ReturnDisplayName = "Direction"))
	static FVector2D AngleToDirection(float Angle);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (ReturnDisplayName = "Direction"))
	static FVector AngleToDirectionXY(float Angle);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (AutoCreateRefTerm = "Direction", ReturnDisplayName = "Angle"))
	static double DirectionToAngle(const FVector2D& Direction);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (AutoCreateRefTerm = "Direction", ReturnDisplayName = "Angle"))
	static double DirectionToAngleXY(const FVector& Direction);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (AutoCreateRefTerm = "Vector", ReturnDisplayName = "Vector"))
	static FVector PerpendicularClockwiseXY(const FVector& Vector);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", Meta = (AutoCreateRefTerm = "Vector", ReturnDisplayName = "Vector"))
	static FVector PerpendicularCounterClockwiseXY(const FVector& Vector);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector", DisplayName = "Angle Between (Skip Normalization)",
		Meta = (AutoCreateRefTerm = "From, To", ReturnDisplayName = "Angle"))
	static double AngleBetweenSkipNormalization(const FVector& From, const FVector& To);

	UFUNCTION(BlueprintPure, Category = "ALS|Als Math|Vector",
		DisplayName = "Slerp (Skip Normalization)", Meta = (AutoCreateRefTerm = "From, To", ReturnDisplayName = "Direction"))
	static FVector SlerpSkipNormalization(const FVector& From, const FVector& To, float Alpha);

	UFUNCTION(BlueprintCallable, Category = "ALS|Als Math|Input", Meta = (ReturnDisplayName = "Direction"))
	static EAlsMovementDirection CalculateMovementDirection(float Angle, float ForwardHalfAngle, float AngleThreshold);
};

inline float UAlsMath::Clamp01(const float Value)
{
	return Value <= 0.0f
		       ? 0.0f
		       : Value >= 1.0f
		       ? 1.0f
		       : Value;
}

inline float UAlsMath::LerpClamped(const float From, const float To, const float Alpha)
{
	return From + (To - From) * Clamp01(Alpha);
}

inline float UAlsMath::LerpAngle(const float From, const float To, const float Alpha)
{
	auto Delta{FRotator3f::NormalizeAxis(To - From)};

	if (Delta > 180.0f - CounterClockwiseRotationAngleThreshold)
	{
		Delta -= 360.0f;
	}

	return FRotator3f::NormalizeAxis(From + Delta * Alpha);
}

inline FRotator UAlsMath::LerpRotator(const FRotator& From, const FRotator& To, const float Alpha)
{
	auto Result{To - From};
	Result.Normalize();

	if (Result.Pitch > 180.0f - CounterClockwiseRotationAngleThreshold)
	{
		Result.Pitch -= 360.0f;
	}

	if (Result.Yaw > 180.0f - CounterClockwiseRotationAngleThreshold)
	{
		Result.Yaw -= 360.0f;
	}

	if (Result.Roll > 180.0f - CounterClockwiseRotationAngleThreshold)
	{
		Result.Roll -= 360.0f;
	}

	Result *= Alpha;
	Result += From;
	Result.Normalize();

	return Result;
}

inline float UAlsMath::Damp(const float DeltaTime, const float Smoothing)
{
	// https://www.rorydriscoll.com/2016/03/07/frame-rate-independent-damping-using-lerp/

	return 1.0f - FMath::Pow(Smoothing, DeltaTime);
}

inline float UAlsMath::ExponentialDecay(const float DeltaTime, const float Lambda)
{
	// https://www.rorydriscoll.com/2016/03/07/frame-rate-independent-damping-using-lerp/

	return 1.0f - FMath::InvExpApprox(Lambda * DeltaTime);
}

template <typename ValueType>
ValueType UAlsMath::Damp(const ValueType& Current, const ValueType& Target, const float DeltaTime, const float Smoothing)
{
	return Smoothing > 0.0f
		       ? FMath::Lerp(Current, Target, Damp(DeltaTime, Smoothing))
		       : Target;
}

template <typename ValueType>
ValueType UAlsMath::ExponentialDecay(const ValueType& Current, const ValueType& Target, const float DeltaTime, const float Lambda)
{
	return Lambda > 0.0f
		       ? FMath::Lerp(Current, Target, ExponentialDecay(DeltaTime, Lambda))
		       : Target;
}

template <>
inline FRotator UAlsMath::Damp(const FRotator& Current, const FRotator& Target, const float DeltaTime, const float Smoothing)
{
	return Smoothing > 0.0f
		       ? LerpRotator(Current, Target, Damp(DeltaTime, Smoothing))
		       : Target;
}

template <>
inline FRotator UAlsMath::ExponentialDecay(const FRotator& Current, const FRotator& Target, const float DeltaTime, const float Lambda)
{
	return Lambda > 0.0f
		       ? LerpRotator(Current, Target, ExponentialDecay(DeltaTime, Lambda))
		       : Target;
}

inline float UAlsMath::DampAngle(const float Current, const float Target, const float DeltaTime, const float Smoothing)
{
	return Smoothing > 0.0f
		       ? LerpAngle(Current, Target, Damp(DeltaTime, Smoothing))
		       : Target;
}

inline float UAlsMath::ExponentialDecayAngle(const float Current, const float Target, const float DeltaTime, const float Lambda)
{
	return Lambda > 0.0f
		       ? LerpAngle(Current, Target, ExponentialDecay(DeltaTime, Lambda))
		       : Target;
}

inline FRotator UAlsMath::DampRotator(const FRotator& Current, const FRotator& Target, const float DeltaTime, const float Smoothing)
{
	return Damp(Current, Target, DeltaTime, Smoothing);
}

inline FRotator UAlsMath::ExponentialDecayRotator(const FRotator& Current, const FRotator& Target,
                                                  const float DeltaTime, const float Lambda)
{
	return ExponentialDecay(Current, Target, DeltaTime, Lambda);
}

inline float UAlsMath::InterpolateAngleConstant(const float Current, const float Target,
                                                const float DeltaTime, const float InterpolationSpeed)
{
	if (InterpolationSpeed <= 0.0f || Current == Target)
	{
		return Target;
	}

	auto Delta{FRotator3f::NormalizeAxis(Target - Current)};

	if (Delta > 180.0f - CounterClockwiseRotationAngleThreshold)
	{
		Delta -= 360.0f;
	}

	const auto Alpha{InterpolationSpeed * DeltaTime};

	return FRotator3f::NormalizeAxis(Current + FMath::Clamp(Delta, -Alpha, Alpha));
}

template <typename ValueType, typename StateType>
ValueType UAlsMath::SpringDamp(const ValueType& Current, const ValueType& Target, StateType& SpringState, const float DeltaTime,
                               const float Frequency, const float DampingRatio, const float TargetVelocityAmount)
{
	if (DeltaTime <= UE_SMALL_NUMBER)
	{
		return Current;
	}

	if (!SpringState.bStateValid)
	{
		SpringState.Velocity = ValueType{0.0f};
		SpringState.PreviousTarget = Target;
		SpringState.bStateValid = true;

		return Target;
	}

	ValueType Result{Current};
	FMath::SpringDamper(Result, SpringState.Velocity, Target,
	                    (Target - SpringState.PreviousTarget) * (Clamp01(TargetVelocityAmount) / DeltaTime),
	                    DeltaTime, Frequency, DampingRatio);

	SpringState.PreviousTarget = Target;

	return Result;
}

inline FVector UAlsMath::ClampMagnitude01(const FVector& Vector)
{
	const auto MagnitudeSquared{Vector.SizeSquared()};

	if (MagnitudeSquared <= 1.0f)
	{
		return Vector;
	}

	const auto Scale{FMath::InvSqrt(MagnitudeSquared)};

	return {Vector.X * Scale, Vector.Y * Scale, Vector.Z * Scale};
}

inline FVector3f UAlsMath::ClampMagnitude01(const FVector3f& Vector)
{
	const auto MagnitudeSquared{Vector.SizeSquared()};

	if (MagnitudeSquared <= 1.0f)
	{
		return Vector;
	}

	const auto Scale{FMath::InvSqrt(MagnitudeSquared)};

	return {Vector.X * Scale, Vector.Y * Scale, Vector.Z * Scale};
}

inline FVector2D UAlsMath::ClampMagnitude012D(const FVector2D& Vector)
{
	const auto MagnitudeSquared{Vector.SizeSquared()};

	if (MagnitudeSquared <= 1.0f)
	{
		return Vector;
	}

	const auto Scale{FMath::InvSqrt(MagnitudeSquared)};

	return {Vector.X * Scale, Vector.Y * Scale};
}

inline FVector2D UAlsMath::RadianToDirection(const float Radian)
{
	float Sin, Cos;
	FMath::SinCos(&Sin, &Cos, Radian);

	return {Cos, Sin};
}

inline FVector UAlsMath::RadianToDirectionXY(const float Radian)
{
	float Sin, Cos;
	FMath::SinCos(&Sin, &Cos, Radian);

	return {Cos, Sin, 0.0f};
}

inline FVector2D UAlsMath::AngleToDirection(const float Angle)
{
	return RadianToDirection(FMath::DegreesToRadians(Angle));
}

inline FVector UAlsMath::AngleToDirectionXY(const float Angle)
{
	return RadianToDirectionXY(FMath::DegreesToRadians(Angle));
}

inline double UAlsMath::DirectionToAngle(const FVector2D& Direction)
{
	return FMath::RadiansToDegrees(FMath::Atan2(Direction.Y, Direction.X));
}

inline double UAlsMath::DirectionToAngleXY(const FVector& Direction)
{
	return FMath::RadiansToDegrees(FMath::Atan2(Direction.Y, Direction.X));
}

inline FVector UAlsMath::PerpendicularClockwiseXY(const FVector& Vector)
{
	return {Vector.Y, -Vector.X, Vector.Z};
}

inline FVector UAlsMath::PerpendicularCounterClockwiseXY(const FVector& Vector)
{
	return {-Vector.Y, Vector.X, Vector.Z};
}

inline double UAlsMath::AngleBetweenSkipNormalization(const FVector& From, const FVector& To)
{
	return FMath::RadiansToDegrees(FMath::Acos(From | To));
}
