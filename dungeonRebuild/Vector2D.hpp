//
//  Vector2D.hpp
//  dungeonCrawler
//
//  Created by Pavel Bibichenko on 15/03/2019.
//  Copyright © 2019 Pavel Bibichenko. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <cmath>

class Vector2D {
public:
    float x;
    float y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D& add(const Vector2D& vec);
    Vector2D& subtract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);
    Vector2D& normalize();
    
    friend Vector2D& operator+(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator-(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator*(Vector2D& vec1, const Vector2D& vec2);
    friend Vector2D& operator/(Vector2D& vec1, const Vector2D& vec2);
    
    bool operator==(const Vector2D& vec);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    
    Vector2D& operator*(const float& i);
    Vector2D& zero();
};

#endif /* Vector2D_hpp */
