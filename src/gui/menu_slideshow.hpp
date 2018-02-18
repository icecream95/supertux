//  SuperTux
//  Copyright (C) 2018 christ2go <christian@hagemeier.ch>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_GUI_MENU_SLIDESHOW_HPP
#define HEADER_SUPERTUX_GUI_MENU_SLIDESHOW_HPP

#include <SDL.h>
#include <list>
#include <memory>
#include <algorithm>
#include "gui/menu_item.hpp"
#include "video/surface.hpp"

class Slideshow : public MenuItem {
private:
  Slideshow(const Slideshow &);
  Slideshow &operator=(const Slideshow &);
  int m_time;
  std::vector<SurfacePtr> m_images;
  std::vector<std::string> m_text;
  int maxH = 0;
  int maxW = 0;

public:
  Slideshow(std::vector<SurfacePtr> &images, std::vector<std::string> &texts,
            int time)
      : MenuItem(""),
      m_time(time),
      m_images(images),
      m_text(texts)
       {
    for (auto &ptr : images) {
      maxH = std::max(maxH, ptr->get_height());
      maxW = std::max(maxW, ptr->get_width());
    }
  }

  virtual bool skippable() const { return true; }

  virtual int get_width() const { return maxW + 100; };

  virtual bool changes_width() const { return true; }

  virtual int get_height() const { return maxH + 30; }

  virtual void process_action(const MenuAction &action) {}
  ~Slideshow() {}
  void draw(DrawingContext &context, const Vector & pos, int menu_width, bool active);
};

#endif

/* EOF */