#pragma once

namespace PlayerAV
{
	class ActorValueDamage
	{

	public:
		static ActorValueDamage* GetSingleton()
		{
			static ActorValueDamage damageValues;
			return &damageValues;
		}

		static float GetActorValueMax(RE::PlayerCharacter* player, RE::ActorValue value)
		{
			return GetActorValueMod(player, 1, value) + GetActorValuePerm(player, value);
		}

		float GetAVDamage(RE::ActorValue av);

		void SetAVDamage(RE::ActorValue av, float damage);

		float GetAVAccumulator(RE::ActorValue av);

		void SetAVAccumulator(RE::ActorValue av, float damage);

		bool SerializeSave(SKSE::SerializationInterface* a_intfc);
		bool SerializeSave(SKSE::SerializationInterface* a_intfc, uint32_t a_type, uint32_t a_version);
		bool DeserializeLoad(SKSE::SerializationInterface* a_intfc);

	private:

		static float GetActorValueMod(RE::PlayerCharacter* player, int32_t integer, RE::ActorValue value)
		{
			using func_t = decltype(&GetActorValueMod);

			REL::Relocation<func_t> func{ REL::ID(37524) };

			return func(player, integer, value);
		}

		static float GetActorValuePerm(RE::ActorValueOwner* owner, RE::ActorValue value)
		{
			using func_t = decltype(&GetActorValuePerm);

			REL::Relocation<func_t> func{ REL::ID(37518) };

			return func(owner, value);
		}

		ActorValueDamage()
		{
			_healthDamage = 0.0f;
			_staminaDamage = 0.0f;
			_magickaDamage = 0.0f;
			_healthAccumulator = 0.0f;
			_staminaAccumulator = 0.0f;
			_magickaAccumulator = 0.0f;
		}

		float _healthDamage;
		float _staminaDamage;
		float _magickaDamage;

		float _healthAccumulator;
		float _staminaAccumulator;
		float _magickaAccumulator;
	};
}
