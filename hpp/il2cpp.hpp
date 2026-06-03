/* OAAU - IL2CPP SDK
 * Generated: 2026-06-03 13:53:41
 * Build ID: 21934483 */

#pragma once
#include <cstdint>

struct Il2CppObject { void* klass; void* monitor; };
struct Il2CppString : Il2CppObject { int32_t length; wchar_t chars[1]; };
struct Il2CppArray  : Il2CppObject { void* bounds; uintptr_t max_length; };
struct Il2CppList   : Il2CppObject { Il2CppArray* _items; int32_t _size; };

struct Vector2  { float x, y; };
struct Vector3  { float x, y, z; };
struct Vector4  { float x, y, z, w; };
struct Matrix4x4 { float m[4][4]; };
struct Quaternion { float x, y, z, w; };
struct Color { float r, g, b, a; };

namespace SDK {
    inline uintptr_t GameAssembly = 0;
    template<typename T> inline T Read(uintptr_t a) { return *(T*)a; }
    template<typename T> inline void Write(uintptr_t a, T v) { *(T*)a = v; }
}
