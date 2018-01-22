#pragma once

// Let's define map size
constexpr unsigned int mapWidth{ 2000 }, mapHeight{ 2000 };

// Let's define mWindow and camera size.
constexpr unsigned int windowWidth{ 800 }, windowHeight{ 600 };
constexpr unsigned int cameraWidth{ 800 }, cameraHeight{ 600 };

// Let's define start size and velocity circle
constexpr float sizeCircle{ 10.f }, maxSpeedCircle{ 100 };
constexpr int playerVelocity{ static_cast<int>(maxSpeedCircle) };

// Let's define group declaration for class members
using Group = std::size_t;
constexpr std::size_t maxGroups{ 32 };
using GroupBitset = std::bitset<maxGroups>;

// Lets define componets declaration
constexpr std::size_t maxComponents{ 32 };
using ComponentBitset = std::bitset<maxComponents>;

// Enum has three states. Any represents no movement.
namespace CWay
{
	enum class Horizontally : int
	{
		Any = 0,
		Left = -playerVelocity,
		Right = playerVelocity,
	};

	enum class Vertically : int
	{
		Any = 0,
		Up = -playerVelocity,
		Down = playerVelocity,
	};
};

// All group characters in the game
enum AgarioGroup : std::size_t
{
	GCircleEnemy,
	GCirclePlayer
};