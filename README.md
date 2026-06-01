<div align="center">
  <img src="https://i.imgur.com/XJaCHng.jpeg" alt="Combat Master Offsets">
  
  # 🎯 Combat Master Full Offsets
  
  **Complete IL2CPP offsets for Combat Master — Updated automatically**
  
  ![License](https://img.shields.io/badge/license-MIT-blue)
  ![Platform](https://img.shields.io/badge/platform-Windows_64bit-blueviolet)
  ![Language](https://img.shields.io/badge/language-C%2B%2B-00599C)
  ![Game](https://img.shields.io/badge/game-Combat_Master-orange)
  
  ---
  
  ### ✅ **100% Free — Always**
  
  If you'd like to support the project, feel free to reach out on [Discord](https://discord.com/users/1383191871089672292).
  
  ---
  
</div>

## 📁 Available Formats

| Format | File |
|--------|------|
| **C Header** | [`HeaderFile/Offsets.h`](HeaderFile/Offsets.h) |
| **C++ Header** | [`hpp/Offsets.hpp`](hpp/Offsets.hpp) |
| **C#** | [`cs/Offsets.cs`](cs/Offsets.cs) |
| **JSON** | [`json/Offsets.json`](json/Offsets.json) |
| **Plain Text** | [`txt/Offsets.txt`](txt/Offsets.txt) |

## 🧱 Offset Structure

All offset files follow the same structure, organized by class:

```
- ImageName
  - ClassName
    - FieldName = offset
    - MethodName = RVA
```

### C++ Example
```cpp
namespace OAAU {
    struct Player {
        constexpr uintptr_t Health         = 0x28;
        constexpr uintptr_t Armor          = 0x30;
        constexpr uintptr_t Position       = 0x50;
        constexpr uintptr_t TakeDamage     = 0x1A3F720;
        constexpr uintptr_t Heal           = 0x1A40B50;
    };
}
```

### C# Example
```csharp
namespace OAAU {
    public static class Player {
        public const ulong Health          = 0x28;
        public const ulong Armor           = 0x30;
        public const ulong Position        = 0x50;
        public const ulong TakeDamage      = 0x1A3F720;
        public const ulong Heal            = 0x1A40B50;
    }
}
```

### JSON Example
```json
{
  "name": "Player",
  "fields": {
    "Health": "0x28",
    "Armor": "0x30"
  },
  "methods": {
    "TakeDamage": "0x1A3F720"
  }
}
```

## 📜 Metadata

Each dump includes a `dump_info.txt` with:

```
OAAU IL2CPP Dump
Game: Combat Master
Dump Time: xxxx-xx-xx xx:xx:xx
Build ID: xxxxxxxx
```

## 🔄 Auto-Update

This repository is automatically updated whenever a new game version is detected.  
The offsets are extracted directly from the running game and pushed in real time.

## 🆓 Free

This project is **completely free**.  
No paywalls, no subscriptions, no hidden charges.

If you'd like to say thanks, you can find me on [Discord](https://discord.com/users/1383191871089672292).

---

<div align="center">
  <sub>Combat Master Full Offsets — Keeping the community updated, always.<3 </sub>
</div>
