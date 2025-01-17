#pragma once
#include "../Value.h"
#include "TargetValue.h"
#include "NearestUnitsValue.h"

namespace ai
{
    class AttackersValue : public ObjectGuidListCalculatedValue
	{
	public:
        AttackersValue(PlayerbotAI* ai) : ObjectGuidListCalculatedValue(ai, "attackers") {}
        list<ObjectGuid> Calculate();

	private:
        void AddAttackersOf(Group* group, set<Unit*>& targets);
        void AddAttackersOf(Player* player, set<Unit*>& targets);
		void RemoveNonThreating(set<Unit*>& targets);

    public:
        static bool HasIgnoreCCRti(Unit* attacker, Player* player);
        static bool HasBreakableCC(Unit* attacker, Player* player);
        static bool HasUnBreakableCC(Unit* attacker, Player* player);
        static bool IsPossibleTarget(Unit* attacker, Player *player, float range = sPlayerbotAIConfig.sightDistance, bool ignoreCC = false);
        static bool IsValidTarget(Unit* attacker, Player* player, bool ignoreCC = false);
    };

    class PossibleAddsValue : public BoolCalculatedValue
    {
    public:
        PossibleAddsValue(PlayerbotAI* const ai, string name = "possible adds") : BoolCalculatedValue(ai, name) {}
        virtual bool Calculate();
    };
}
