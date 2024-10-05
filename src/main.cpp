#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);
		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		// Test to see if std::source_location compiles for all platforms in github actions
		// Not checking if it works properly
		std::source_location source = std::source_location::current();
		FLAlertLayer::create("Geode", fmt::format(
			"File: {}\nFunction: {}\nLine: {}\nColumn: {}",
			source.file_name(),
			source.function_name(),
			source.line(),
			source.column()
		), "OK")->show();
	}
};