/* OAAU - IL2CPP SDK
 * Generated: 2026-05-28 02:23:58
 * Build ID: 21934483 */

namespace OAAU.SDK
{
    public class Il2CppObject { public System.IntPtr klass; public System.IntPtr monitor; }
    public class Il2CppString : Il2CppObject { public int length; public char[] chars; }
    public class Il2CppArray  : Il2CppObject { public System.IntPtr bounds; public ulong max_length; }
    public class Il2CppList   : Il2CppObject { public Il2CppArray _items; public int _size; }

    public struct Vector2  { public float x, y; }
    public struct Vector3  { public float x, y, z; }
    public struct Vector4  { public float x, y, z, w; }
    public struct Matrix4x4 { public float[,] m; }
    public struct Quaternion { public float x, y, z, w; }
    public struct Color { public float r, g, b, a; }
}
