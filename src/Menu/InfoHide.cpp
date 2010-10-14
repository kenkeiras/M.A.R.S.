/* InfoHide.cpp

Copyright (c) 2010 by Felix Lauer und Simon Schneegans

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

# include "Menu/InfoHide.hpp"

# include "Interface/UiWindow.hpp"
# include "Interface/Button.hpp"
# include "Interface/Checkbox.hpp"
# include "Menu/menus.hpp"
# include "Interface/TextBox.hpp"
# include "Interface/Line.hpp"
# include "System/settings.hpp"
# include "Media/text.hpp"
# include "Locales/locales.hpp"

UiWindow* InfoHide::instance_(NULL);
bool InfoHide::kOk_(false);
TextBox* InfoHide::infoBox_(NULL);

UiWindow* InfoHide::get() {
    if (instance_ == NULL) {
        instance_ = new InfoHide(320, 200);
        instance_->addWidget(new Button(locales::getLocale(locales::Close), &kOk_, Vector2f(240,170), 70, 20));
        instance_->addWidget(new Label(locales::getLocale(locales::HideMenu), TEXT_ALIGN_LEFT, Vector2f(10,10), 20.f));
        instance_->addWidget(new Label(locales::getLocale(locales::Info), TEXT_ALIGN_RIGHT, Vector2f(310,18), 12.f));
        instance_->addWidget(new Line(Vector2f(10, 35), Vector2f(310, 35)));
        infoBox_ = new TextBox(locales::getLocale(locales::Ok), Vector2f(10, 80), 300, 300);
        instance_->addWidget(infoBox_);
        instance_->addWidget(new Checkbox(locales::getLocale(locales::ShowAgainButton), &settings::C_showInfoHide, Vector2f(10,170), 170));
    }
    return instance_;
}

void InfoHide::checkWidgets() {
    if (kOk_) {
        kOk_ = false;
        menus::hideWindow();
        menus::hideMenu();
    }
}

void InfoHide::onShow() {
    infoBox_->setText(locales::getLocale(locales::HideMenuText));
}
