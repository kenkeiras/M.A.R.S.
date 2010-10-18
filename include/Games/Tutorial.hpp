/* Tutorial.hpp

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

# ifndef TUTORIAL_HPP_INCLUDED
# define TUTORIAL_HPP_INCLUDED

# include "Games/Game.hpp"

class Home;
class Player;

class Tutorial: public Game {
    public:
        Tutorial();

        void update();
        void draw() const;
        void restart();

    private:
        int state_;
        int savedState_;
        Home* evilHome_;
        Player* evilPlayer1_;
        Player* evilPlayer2_;
        float timer_, deadTimer_;
        bool dead_, life_, fuel_, name_;
};

# endif // TUTORIAL_HPP_INCLUDED
