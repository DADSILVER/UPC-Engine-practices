#pragma once
#include <cmath>

#define PI 3.14159265

template <class T>
class Vec3
{
private:
	T m_x;
	T m_y;
	T m_z;

	

public:
	Vec3() : m_x(0), m_y(0), m_z(0) {};
	Vec3(T x, T y, T z) : m_x(x), m_y(y), m_z(z) {};
	Vec3(const Vec3& v) : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z) {};
	inline Vec3 operator + (const Vec3& v) { return Vec3(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z); }
	inline T GetX() { return m_x; }
	inline T GetY() { return m_y; }
	inline T GetZ() { return m_z; }
	Vec3 Normalize();
	inline T DistanceTo(Vec3 v) {	return sqrt(pow(m_x - v.GetX(), 2) + pow(m_y - v.GetY(), 2) + pow(m_z - v.GetZ(), 2));	}
	inline T DotProduct(Vec3 v) {	return m_x * v.GetX() + m_y * v.GetY() + m_z * v.GetZ();	}
	inline Vec3 CrossProduct(const Vec3& v) {	return Vec3(m_y * v.m_z - m_z * v.m_y, m_z * v.m_x - m_x * v.m_z, m_x * v.m_y - m_y * v.m_x);	}
	inline T mag() { return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }
	T AngleBetween(Vec3 v) {	return acos(DotProduct(v) / (mag() * v.mag())) * 180.0 / PI;	}
};



template <class T> Vec3<T> Vec3<T>::Normalize() {
	float length = sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
	return Vec3(m_x = m_x / length, m_y = m_y / length, m_z = m_z / length);
}