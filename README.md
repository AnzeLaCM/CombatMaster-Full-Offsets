<div align="center">
  <img src="https://i.imgur.com/XJaCHng.jpeg" alt="Combat Master Offsets">
  
  # 🎯 Combat Master Full Offsets
  
  **Complete IL2CPP offsets for Combat Master — Updated automatically**
  
  ![License](https://img.shields.io/badge/license-MIT-blue)
  ![Visitors](https://visitor-badge.laobi.icu/badge?page_id=AnzeLaCM.CombatMaster-Full-Offsets)
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
| **Direct (Flat)** | [`hpp/Direct.hpp`](hpp/Direct.hpp) — All offsets as flat `constexpr uintptr_t` constants |

---

## 🗺️ Offsets Map — Full Structure

All offset files are organized into **14 logical namespaces** inside `namespace CombatMaster`:

```
CombatMaster
├── Player                    # PlayerRoot, PlayerHealth, Movement, Arming, CameraController
│   ├── PlayerRoot            # Health, Armor, Position, TeamId, IsVisible, ...
│   ├── PlayerHealth          # CurrentHp, MaxHp, Armor, IsDead, IsDowned, ...
│   └── PlayerMovement        # Velocity, IsGrounded, IsInAir, Gravity, ...
│
├── Weapons                   # WeaponBase, ShootWeapon, MeleeWeapon, Throwing, Attachments
│   ├── WeaponBase            # Damage, FireRate, Ammo, ReloadTime, ...
│   ├── ShootWeapon           # BulletSpread, RecoilPattern, MuzzlePosition, ...
│   └── Attachment            # ScopeZoom, RecoilMult, DamageMult, ...
│
├── WorldLoot                 # Loot, WeaponBoxes, JumpPads, ZipLines, Bombs, Actors
│
├── GameModes                 # TDM, BR, SND, CTF, DM, Domination, Arena, Tutorial
│
├── Vehicles                  # Helicopter, Bike, ATV, Truck, VehicleManager, VehicleSeat
│
├── AI                        # Seeker, RichPath, NavMesh, BotMovement, Pathfinding
│
├── Networking                # Photon Bolt, BoltEntity, NetworkId, UDP, Commands
│
├── Physics                   # Rigidbody, Colliders, RaycastHit, Hitboxes, Joints
│
├── Input                     # InputSystem, InputControllers, Touch, Gamepad, Keyboard
│
├── GameData                  # WeaponInfo, MatchInfo, LootTables, Enums, Config
│
├── ClientProfile             # PlayerProfile, Store, Stats, PlayFab, Steam, Achievements
│
├── UnityCore                 # Transform, GameObject, Camera, Animator, Renderer, Material
│
├── Bones                     # HumanBodyBones, WeaponBones, HitboxBones, CM bone offsets
│   ├── HumanBodyBones        # Hips=0, LeftUpperLeg=1, ..., Head=11, ..., LastBone=54
│   ├── WeaponBones           # Root=0, Muzzle=1, Sight=3, Scope=4, Grip=6, ...
│   ├── HitboxBones           # Head=0, Neck=1, Chest=2, Spine=3, ...
│   ├── CM_PlayerBoneOffsets  # HeadHitbox=0x58, HitboxBody=0x90, Health=0xB8, ...
│   └── CM_MobViewBoneOffsets # HeadTransform=0x40, NeckTransform=0x48, ...
│
└── Other                     # Uncategorized classes
```

---

## 🧱 Offset Structure

All offset files follow the same structure, organized by namespace and class:

```
CombatMaster
  └── Section
       └── Class
            ├── FieldName  = offset
            └── MethodName = RVA
```

### C++ Example
```cpp
namespace CombatMaster {
    struct PlayerRoot {
        constexpr uintptr_t Health         = 0xB8;
        constexpr uintptr_t Armor          = 0xC0;
        constexpr uintptr_t TeamId         = 0xE0;
        constexpr uintptr_t IsVisible      = 0x10A;
        // ---- Methods ----
        constexpr uintptr_t TakeDamage     = 0x1A3F720;
        constexpr uintptr_t Heal           = 0x1A40B50;
    };
}
```

### C# Example
```csharp
namespace CombatMaster {
    public static class PlayerRoot {
        public const ulong Health          = 0xB8;
        public const ulong Armor           = 0xC0;
        public const ulong TeamId          = 0xE0;
        public const ulong IsVisible       = 0x10A;
        // ---- Methods ----
        public const ulong TakeDamage      = 0x1A3F720;
        public const ulong Heal            = 0x1A40B50;
    }
}
```

### JSON Example
```json
{
  "name": "CombatMaster.Player.PlayerRoot",
  "fields": {
    "Health": "0xB8",
    "Armor": "0xC0"
  },
  "methods": {
    "TakeDamage": "0x1A3F720"
  }
}
```

---

## 💻 How To Use Offsets

All offsets are **relative to `Project.dll`** (Unity's il2cpp game assembly).

To use an offset value, simply add it to the game's base address:

```cpp
uintptr_t game = (uintptr_t)GetModuleHandleA("Project.dll");
int health = *(int*)(game + Player_PlayerRoot_playerHealth); // read player health
```

### Reading Static Fields (e.g., find your player)

Classes with static data include a `_StaticData` constant pointing to the class's static storage. Use it like this:

```cpp
uintptr_t game = (uintptr_t)GetModuleHandleA("Project.dll");

// Get the static data block for PlayerRoot
uintptr_t playerRootStatic = game + Player_PlayerRoot_StaticData;

// Read static fields from that block (these are pointers to runtime objects)
uintptr_t myPlayer = *(uintptr_t*)(playerRootStatic + Player_PlayerRoot_MyPlayer);

// Now read field offsets from the player object
int health = *(int*)(myPlayer + Player_PlayerRoot_get_Health);
```

### Simple ESP (No GUI) — Full Example

```cpp
#include "Direct.hpp"
#include <windows.h>
#include <vector>

struct Vec3 { float x, y, z; };

// Helper to read memory
template<typename T> T Read(uintptr_t addr) { return *(T*)addr; }

int main() {
    uintptr_t game = (uintptr_t)GetModuleHandleA("Project.dll");

    // 1. Get the PlayerRoot static data block (contains all player instances)
    uintptr_t staticData  = game + Player_PlayerRoot_StaticData;
    uintptr_t localPlayer = Read<uintptr_t>(staticData + Player_PlayerRoot_MyPlayer);

    // 2. Read local player info
    Vec3  pos    = Read<Vec3>(localPlayer + Player_PlayerRoot_get_Transform); // position
    int   health = Read<int>(localPlayer + Player_PlayerRoot_get_Health);
    int   teamId = Read<int>(localPlayer + Player_PlayerRoot_TeamId);

    // 3. Iterate all players via static list
    uintptr_t playerList = Read<uintptr_t>(staticData + Player_PlayerRoot_AllPlayers);
    auto* list = (uintptr_t*)playerList;

    for (int i = 0; i < 10; i++) {
        uintptr_t player = list[i];
        if (!player || player == localPlayer) continue;

        int   hp     = Read<int>(player + Player_PlayerRoot_get_Health);
        Vec3  ppos   = Read<Vec3>(player + Player_PlayerRoot_get_Transform);
        int   team   = Read<int>(player + Player_PlayerRoot_TeamId);
        bool  alive  = Read<bool>(player + Player_PlayerRoot_IsAlive);

        // ESP drawing here (your own overlay / console / etc.)
        // printf("Player %d: HP=%d Team=%d Alive=%d\n", i, hp, team, alive);
    }

    // 4. Call a method by its RVA
    typedef void (*TakeDamage_t)(uintptr_t, float);
    auto TakeDamage = (TakeDamage_t)(game + Player_PlayerRoot_TakeDamage);
    TakeDamage(localPlayer, 10.0f);

    return 0;
}
```

> **Note:** Replace `Player_PlayerRoot_StaticData` with the actual class you need.  
> The `Direct.hpp` file contains every offset as a flat `constexpr uintptr_t` constant.  
> Just `#include "Direct.hpp"` and start reading — no nested namespaces required.

---

## 🦴 Bones Reference

### HumanBodyBones (Unity Standard — 54 bones)
| Index | Bone | Purpose |
|-------|------|---------|
| 0 | Hips | Root of skeleton |
| 1 | LeftUpperLeg | Left thigh |
| 2 | RightUpperLeg | Right thigh |
| 7 | Spine | Lower spine |
| 8 | Chest | Chest/ribcage |
| 10 | Neck | Neck |
| 11 | Head | Head/skull |
| 14 | LeftUpperArm | Left shoulder to elbow |
| 15 | RightUpperArm | Right shoulder to elbow |
| 18 | LeftHand | Left hand |
| 19 | RightHand | Right hand |

### WeaponBones (21 bones)
| Index | Bone | Description |
|-------|------|-------------|
| 0 | Root | Weapon root/pivot |
| 1 | Muzzle | Bullet spawn point |
| 3 | Sight | Iron sight / optic |
| 4 | Scope | Scope attachment |
| 5 | Magazine | Magazine attach |
| 6 | Grip | Foregrip |
| 7 | Stock | Stock attachment |
| 14 | Camera | ADS aim point |
| 15 | LeftHand | Left hand IK |
| 16 | RightHand | Right hand IK |

### HitboxBones (Combat Master — 14 bones)
| Index | Bone | Purpose |
|-------|------|---------|
| 0 | Head | Head hitbox |
| 1 | Neck | Neck hitbox |
| 2 | Chest | Torso hitbox |
| 3 | Spine | Spine hitbox |
| 4 | LeftKnee | Left leg |
| 5 | RightKnee | Right leg |
| 12 | Pelvis | Pelvis hitbox |

---

## 📜 Metadata

Each dump includes a `DumpLog.txt` with:

```
Combat Master IL2CPP Dump
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
  <sub>Combat Master Full Offsets — Keeping the community updated, always.</sub>
</div>
