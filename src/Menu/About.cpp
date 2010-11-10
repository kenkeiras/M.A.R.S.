/* About.cpp

Copyright (c) 2010 by Felix Lauer and Simon Schneegans

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

# include "Menu/About.hpp"

# include "Interface/UiWindow.hpp"
# include "Interface/Button.hpp"
# include "Menu/menus.hpp"
# include "Interface/TextBox.hpp"
# include "Interface/TabList.hpp"
# include "System/generateName.hpp"
# include "Media/text.hpp"
# include "Locales/locales.hpp"

UiWindow* About::instance_(NULL);
bool About::kClose_(false);
sf::String About::marsName_("");

UiWindow* About::get() {
    if (instance_ == NULL) {
        instance_ = new About(420, 310);
        instance_->addWidget(new Button(locales::getLocale(locales::Close), &kClose_, Vector2f(340,280), 70, 20));
        instance_->addWidget(new Label(new sf::String("M.A.R.S."), TEXT_ALIGN_LEFT, Vector2f(10,10), 20.f));
        instance_->addWidget(new Label(&marsName_, TEXT_ALIGN_RIGHT, Vector2f(410,18), 12.f));

        TabList* tabs = new TabList(Vector2f(10, 50), 400, 250);

        Tab* about = new Tab(locales::getLocale(locales::About), 90);
        Tab* license = new Tab(locales::getLocale(locales::License), 90);
        Tab* credits = new Tab(locales::getLocale(locales::About), 90);

        about->addWidget(new TextBox(locales::getLocale(locales::AboutText), Vector2f(10, 30), 380, 230));
        license->addWidget(new TextBox(locales::getLocale(locales::LicenseText), Vector2f(10, 30), 380, 230));
        credits->addWidget(new TextBox(locales::getLocale(locales::AboutText), Vector2f(10, 30), 380, 230));

        tabs->addTab(about);
        tabs->addTab(license);
        tabs->addTab(credits);

        instance_->addWidget(tabs);
    }
    return instance_;
}

void About::checkWidgets() {
    if (kClose_) {
        kClose_ = false;
        menus::hideWindow();
    }
}

void About::onShow() {
    marsName_ = "A " + generateName::game();
}





