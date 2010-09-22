/* NewGameMenu.cpp

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>. */

# include "Menu/NewGameMenu.hpp"

# include "Interface/UiWindow.hpp"
# include "Interface/Button.hpp"
# include "Interface/Tab.hpp"
# include "Interface/TabList.hpp"
# include "Interface/RadioGroup.hpp"
# include "Interface/RadioButton.hpp"
# include "Interface/Slider.hpp"
# include "Interface/Checkbox.hpp"
# include "Interface/Line.hpp"
# include "Games/games.hpp"
# include "System/window.hpp"
# include "System/settings.hpp"
# include "Menu/menus.hpp"
# include "Menu/InfoSB.hpp"
# include "Menu/InfoDM.hpp"
# include "Menu/InfoTDM.hpp"
# include "Menu/InfoCK.hpp"

UiWindow* NewGameMenu::instance_(NULL);
bool NewGameMenu::kStartSB_(false);
bool NewGameMenu::kStartDM_(false);
bool NewGameMenu::kStartTDM_(false);
bool NewGameMenu::kStartCK_(false);
bool NewGameMenu::kInfoSB_(false);
bool NewGameMenu::kInfoDM_(false);
bool NewGameMenu::kInfoTDM_(false);
bool NewGameMenu::kInfoCK_(false);
bool NewGameMenu::kCancel_(false);
bool NewGameMenu::playerI_(false);
bool NewGameMenu::playerII_(false);

UiWindow* NewGameMenu::get() {
    if (instance_ == NULL) {
        instance_ = new NewGameMenu(480, 295);
        instance_->addWidget(new Button("Cancel", &kCancel_, Vector2f(315,260), 70, 20));

        instance_->addWidget(new Label("Start local Game", TEXT_ALIGN_LEFT, Vector2f(10,10), 20.f));

        TabList* tabList        = new TabList(Vector2f(10,55), 460, 220);
        Tab* tabSpaceBall       = new Tab("SpaceBall", 70);
        Tab* tabDeathMatch      = new Tab("DeathMatch", 80);
        Tab* tabTeamDeathMatch  = new Tab("Team-DeatMatch", 110);
        Tab* tabCannonKeep      = new Tab("CannonKeep", 80);

        tabSpaceBall->addWidget(new Label("Left Team:", TEXT_ALIGN_LEFT, Vector2f(10, 40)));
        tabSpaceBall->addWidget(new Label("Right Team:", TEXT_ALIGN_LEFT, Vector2f(240, 40)));
        tabSpaceBall->addWidget(new Slider("Bots Left", &settings::C_botsLeft, 0, 20, Vector2f(10,100), 210, 100, true));
        tabSpaceBall->addWidget(new Slider("Bots Right", &settings::C_botsRight, 0, 20, Vector2f(240,100), 210, 100, true));
        RadioGroup* player1Group = new RadioGroup();
            player1Group->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamL, Vector2f(10,70), 80));
            player1Group->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamR, Vector2f(240,70), 80));
            tabSpaceBall->addWidget(player1Group);
        RadioGroup* player2Group = new RadioGroup();
            player2Group->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamL, Vector2f(93,70), 80));
            player2Group->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamR, Vector2f(323,70), 80));
            tabSpaceBall->addWidget(player2Group);
        tabSpaceBall->addWidget(new Slider("Pointlimit", &settings::C_pointLimit, 1, 20, Vector2f(10,150), 440, 100, true));
        tabSpaceBall->addWidget(new Button("Start", &kStartSB_, Vector2f(385,195), 70, 20));
        tabSpaceBall->addWidget(new Button("Info", &kInfoSB_, Vector2f(10,195), 70, 20));

        tabDeathMatch->addWidget(new Slider("Bots", &settings::C_botsDeath, 0, 150, Vector2f(10,110), 440, 100, true));
        tabDeathMatch->addWidget(new Checkbox("Player I", &playerI_, Vector2f(10,60), 100));
        tabDeathMatch->addWidget(new Checkbox("Player II", &playerII_, Vector2f(240,60), 100));
        tabDeathMatch->addWidget(new Slider("Fraglimit", &settings::C_fragLimit, 1, 50, Vector2f(10,150), 440, 100, true));
        tabDeathMatch->addWidget(new Button("Start", &kStartDM_, Vector2f(385, 195), 70, 20));
        tabDeathMatch->addWidget(new Button("Info", &kInfoDM_, Vector2f(10,195), 70, 20));

        tabTeamDeathMatch->addWidget(new Label("Left Team:", TEXT_ALIGN_LEFT, Vector2f(10, 40)));
        tabTeamDeathMatch->addWidget(new Label("Right Team:", TEXT_ALIGN_LEFT, Vector2f(240, 40)));
        tabTeamDeathMatch->addWidget(new Slider("Bots Left", &settings::C_botsLeft, 0, 20, Vector2f(10,100), 210, 100, true));
        tabTeamDeathMatch->addWidget(new Slider("Bots Right", &settings::C_botsRight, 0, 20, Vector2f(240,100), 210, 100, true));
        RadioGroup* player1Group2 = new RadioGroup();
            player1Group2->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamL, Vector2f(10,70), 80));
            player1Group2->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamR, Vector2f(240,70), 80));
            tabTeamDeathMatch->addWidget(player1Group2);
        RadioGroup* player2Group2 = new RadioGroup();
            player2Group2->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamL, Vector2f(93,70), 80));
            player2Group2->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamR, Vector2f(323,70), 80));
            tabTeamDeathMatch->addWidget(player2Group2);
        tabTeamDeathMatch->addWidget(new Slider("Fraglimit", &settings::C_fragLimit, 1, 50, Vector2f(10,150), 440, 100, true));
        tabTeamDeathMatch->addWidget(new Button("Start", &kStartTDM_, Vector2f(385, 195), 70, 20));
        tabTeamDeathMatch->addWidget(new Button("Info", &kInfoTDM_, Vector2f(10,195), 70, 20));

        tabCannonKeep->addWidget(new Label("Left Team:", TEXT_ALIGN_LEFT, Vector2f(10, 40)));
        tabCannonKeep->addWidget(new Label("Right Team:", TEXT_ALIGN_LEFT, Vector2f(240, 40)));
        tabCannonKeep->addWidget(new Slider("Bots Left", &settings::C_botsLeft, 0, 20, Vector2f(10,100), 210, 100, true));
        tabCannonKeep->addWidget(new Slider("Bots Right", &settings::C_botsRight, 0, 20, Vector2f(240,100), 210, 100, true));
        RadioGroup* player1Group3 = new RadioGroup();
            player1Group3->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamL, Vector2f(10,70), 80));
            player1Group3->addRadioButton(new RadioButton("Player I", &settings::C_playerIteamR, Vector2f(240,70), 80));
            tabCannonKeep->addWidget(player1Group3);
        RadioGroup* player2Group3 = new RadioGroup();
            player2Group3->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamL, Vector2f(93,70), 80));
            player2Group3->addRadioButton(new RadioButton("Player II", &settings::C_playerIIteamR, Vector2f(323,70), 80));
            tabCannonKeep->addWidget(player2Group3);
        tabCannonKeep->addWidget(new Slider("Pointlimit", &settings::C_pointLimit, 1, 20, Vector2f(10,150), 440, 100, true));
        tabCannonKeep->addWidget(new Button("Start", &kStartCK_, Vector2f(385, 195), 70, 20));
        tabCannonKeep->addWidget(new Button("Info", &kInfoCK_, Vector2f(10,195), 70, 20));

        tabList->addTab(tabSpaceBall);
        tabList->addTab(tabDeathMatch);
        tabList->addTab(tabTeamDeathMatch);
        tabList->addTab(tabCannonKeep);

        instance_->addWidget(tabList);
    }
    return instance_;
}

void NewGameMenu::checkWidgets() {
    if (kStartSB_) {
        kStartSB_ = false;
        menus::hideWindow();
        menus::hideWindow();
        settings::save();
        games::end();
        games::start(games::gSpaceBall);
    }
    if (kStartTDM_) {
        kStartTDM_ = false;
        menus::hideWindow();
        menus::hideWindow();
        settings::save();
        games::end();
        games::start(games::gTeamDeathMatch);
    }
    if (kStartDM_) {
        kStartDM_ = false;
        menus::hideWindow();
        menus::hideWindow();
        games::end();
        settings::C_playerIteamR = false;
        settings::C_playerIteamL = false;
        settings::C_playerIIteamR = false;
        settings::C_playerIIteamL = false;

        if (playerI_)  settings::C_playerIteamL  = true;
        if (playerII_) settings::C_playerIIteamL = true;

        settings::save();

        games::start(games::gDeathMatch);
    }
    if (kStartCK_) {
        kStartCK_ = false;
        menus::hideWindow();
        menus::hideWindow();
        settings::save();
        games::end();
        games::start(games::gCannonKeep);
    }
    if (kInfoSB_) {
        kInfoSB_ = false;
        menus::showWindow(InfoSB::get());
    }
    if (kInfoDM_) {
        kInfoDM_ = false;
        menus::showWindow(InfoDM::get());
    }
    if (kInfoTDM_) {
        kInfoTDM_ = false;
        menus::showWindow(InfoTDM::get());
    }
    if (kInfoCK_) {
        kInfoCK_ = false;
        menus::showWindow(InfoCK::get());
    }
    else if (kCancel_) {
        kCancel_ = false;
        menus::hideWindow();
    }
}

void NewGameMenu::onShow() {
    if (settings::C_playerIteamL | settings::C_playerIteamR)
        playerI_ = true;
    if (settings::C_playerIIteamL | settings::C_playerIIteamR)
        playerII_ = true;
}



