/* main.cpp

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

# include "System/window.hpp"
# include "Games/games.hpp"

void mainLoop() {
    while (window::isOpen()) {
        window::update();
        games::update();
        games::draw();
        window::display();
    }
}

int main() {
    window::open();
    games::start(games::gMenu);
    mainLoop();

    return 0;
}
