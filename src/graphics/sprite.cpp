#include "sprite.h"

Sprite::Sprite(int m_width, int m_height) {
  width = m_width;
  height = m_height;
  sprite = new bool*[width];
  for (int w = 0; w < width; w++) {
    sprite[w] = new bool[height];
    for (int h = 0; h < height; h++) {
      sprite[w][h] = false;
    }  
  }
}

Sprite::~Sprite() {
  for (int w = 0; w < width; w++) {
    delete[] sprite[w];
  }
  delete[] sprite;
}

void Sprite::SetPixel(int x, int y, bool solid) {
  sprite[x][y] = solid;
}

int Sprite::GetHeight() {
  return height;
}


int Sprite::GetWidth() {
  return width;

}

void Sprite::Draw(DaisyPatch patch, int x, int y) {
  for (int w = 0; w < width; w++) {
    for (int h = 0; h < height; h++) {
      patch.display.DrawPixel(x+w, y+h, sprite[w][h]);
    }
  }
}

void Sprite::DrawTile(DaisyPatch patch,
		      int x1,
		      int y1,
		      int x2,
		      int y2) {
  int x_min = std::min(x1, x2);
  int x_max = std::max(x1, x2);
  int y_min = std::min(y1, y2);
  int y_max = std::max(y1, y2);
  for (int w = x_min; w < x_max; w++) {
    for (int h = y_min; h < y_max; h++) {
      patch.display.DrawPixel(w, h, sprite[(w-x_min) % width]
			      [(h-y_min) % height]);
    }
  }
}

bool** Sprite::GetSprite() {
  return sprite;
}

void Sprite::SetBlank() {
  for (int w = 0; w < width; w++) {
    for (int h = 0; h < height; h++) {
      sprite[w][h] = false;
    }  
  }
}