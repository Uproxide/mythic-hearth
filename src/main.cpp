#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelCell.hpp>

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool randomAssBoolWhyAreYouHere) {
		if (!LevelInfoLayer::init(level, randomAssBoolWhyAreYouHere)) {
			return false;
		}

		if (level->m_levelID == 101746243) {
			m_difficultySprite->updateFeatureState((GJFeatureState)(4));
		}

		return true;
	}

	void levelUpdateFinished(GJGameLevel* level, UpdateResponse response) {
		LevelInfoLayer::levelUpdateFinished(level, response);

		if (level->m_levelID == 101746243) {
			m_difficultySprite->updateFeatureState((GJFeatureState)(4));
		}
	}

	void levelDownloadFinished(GJGameLevel* level) {
		LevelInfoLayer::levelDownloadFinished(level);

		if (level->m_levelID == 101746243) {
			m_difficultySprite->updateFeatureState((GJFeatureState)(4));
		}
	}
};

class $modify(LevelCell) {
	void loadFromLevel(GJGameLevel* level) {
		LevelCell::loadFromLevel(level);
		
		auto difficultyNode = m_mainLayer->getChildByID("difficulty-container");

		if (difficultyNode) {
			GJDifficultySprite* difficultySpr = static_cast<GJDifficultySprite*>(difficultyNode->getChildByID("difficulty-sprite"));

			if (level->m_levelID == 101746243) {
				difficultySpr->updateFeatureState((GJFeatureState)(4));
			}
		}
	}	
};
