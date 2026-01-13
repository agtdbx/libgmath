# libgmath

A lightweight, C++ math library for game development and graphics programming.

## Overview

**libgmath** is a modern, template-based C++ mathematics library designed for game engines, graphics applications, and computational geometry. Inspired by GLM (OpenGL Mathematics), it provides a complete set of vector, matrix, and utility functions with a clean, intuitive API.</br>
The libgmath can replace the GLM in OpenGL/Vulkan projects.

### Key Features

- ✅ **Template-based** - Full support for `float`, `double`, and custom numeric types
- ✅ **GLM-like API** - Familiar syntax for developers experienced with GLM
- ✅ **Zero dependencies** - Fully self-contained, no external libraries required
- ✅ **Game-ready** - Optimized for real-time applications
- ✅ **Modern C++** - Clean C++17 codebase with best practices

---

## Table of Contents

- [Installation](#installation)
- [Quick Start](#quick-start)
- [API Reference](#api-reference)
  - [Vector Types](#vector-types)
  - [Matrix Types](#matrix-types)
  - [Utility Functions](#utility-functions)
  - [Perlin Noise](#perlin-noise)
- [Usage Examples](#usage-examples)
- [Building](#building)
- [License](#license)

---

## Installation

### Meson subproject

You can add it into you meson.build
```meson
dependencies : [
    dependency('libgmath', static: true),
]
```

And creating the file subprojects/libgmath.wrap
```meson
[wrap-git]
url = https://github.com/agtdbx/libgmath.git
revision = HEAD
depth = 1
```

---

## Quick Start

```cpp
#include <gmath.hpp>

int main(void)
{
	// Create vectors
	gm::Vec3f position(1.0f, 2.0f, 3.0f);
	gm::Vec3f velocity(0.5f, 0.0f, -0.2f);

	// Vector operations
	gm::Vec3f newPosition = position + velocity;
	float distance = gm::length(position);
	gm::Vec3f normalized = gm::normalize(velocity);

	// Create a 4x4 identity matrix
	gm::Mat4f transform(1);

	// Perlin noise generation
	gm::PerlinNoisef noise(42, gm::Vec2i(256, 256), 4, 0.5f);
	float value = noise.getNoise(10.5f, 20.3f);

	return (0);
}
```

---

## API Reference

### Vector Types

libgmath provides 2D, 3D, and 4D vector types for both `float` and `double` precision:

#### Available Types

```cpp
// 2D Vectors
gm::Vec2<T>     // Generic 2D vector
gm::Vec2f       // float version
gm::Vec2d       // double version
gm::Vec2i       // int version
gm::Vec2u       // unsigned int version

// 3D Vectors
gm::Vec3<T>     // Generic 3D vector
gm::Vec3f       // float version
gm::Vec3d       // double version
gm::Vec3i       // int version
gm::Vec3u       // unsigned int version

// 4D Vectors
gm::Vec4<T>     // Generic 4D vector
gm::Vec4f       // float version
gm::Vec4d       // double version
gm::Vec4i       // int version
gm::Vec4u       // unsigned int version
```

#### Vector Operations

```cpp
// Construction
gm::Vec3f v1(1.0f, 2.0f, 3.0f);
gm::Vec3f v2(v1);  // Copy constructor

// Arithmetic operations
gm::Vec3f sum = v1 + v2;
gm::Vec3f diff = v1 - v2;
gm::Vec3f scaled = v1 * 2.0f;
gm::Vec3f divided = v1 / 2.0f;

// Comparison
bool equal = (v1 == v2);
bool notEqual = (v1 != v2);

// Access
float x = v1.x;  // or v1[0]
float y = v1.y;  // or v1[1]
float z = v1.z;  // or v1[2]
```

---

### Matrix Types

Full support for 2x2, 3x3, and 4x4 matrices:

#### Available Types

```cpp
// 2x2 Matrices
gm::Mat2<T>   // Generic 2x2 matrix
gm::Mat2f     // float version
gm::Mat2d     // double version
gm::Mat2i     // int version
gm::Mat2u     // unsigned int version

// 3x3 Matrices
gm::Mat3<T>   // Generic 3x3 matrix
gm::Mat3f     // float version
gm::Mat3d     // double version
gm::Mat3i     // int version
gm::Mat3u     // unsigned int version

// 4x4 Matrices
gm::Mat4<T>   // Generic 4x4 matrix
gm::Mat4f     // float version
gm::Mat4d     // double version
gm::Mat4i     // int version
gm::Mat4u     // unsigned int version
```

#### Matrix Operations

```cpp
// Identity matrix
gm::Mat4f identity(1);

// Matrix arithmetic
gm::Mat4f result = mat1 + mat2;
gm::Mat4f product = mat1 * mat2;

// Matrix-vector multiplication
gm::Vec4f transformed = matrix * vector;

// Transpose and inverse (if available)
gm::Mat4f transposed = gm::transpose(matrix);
```

---

### Utility Functions

#### Math Functions

```cpp
namespace gm {
	// Vector operations
	template<typename T>
	T norm(const Vec3<T> &v);           // Vector magnitude

	template<typename T>
	T norm2(const Vec3<T> &v);           // Vector magnitude squarred

	template<typename T>
	Vec3<T> normalize(const Vec3<T> &v);  // Normalized vector

	template<typename T>
	T dot(const Vec3<T> &a, const Vec3<T> &b);  // Dot product

	template<typename T>
	Vec3<T> cross(const Vec3<T> &a, const Vec3<T> &b);  // Cross product

	template<typename T>
	T hash(const Vec3<T> &vec);  // Hashing

	// Interpolation
	template<typename T>
	T lerp(T a, T b, float/double t);  // Linear interpolation

	// Random number generation
	void initRandom(unsigned int seed);  // Initialize RNG
	int iRand(int min, int max);         // Random integer
	unsigned int uRand();                // Random unsigned int
	float fRand();                       // Random float [0, 1]
	double dRand(2.1, 42.0);             // Random double [2.1, 42.0]
}
```

---

### Perlin Noise

Generate seamless, tileable 2D Perlin noise for procedural content generation.

#### Types

```cpp
gm::PerlinNoise<T>   // Generic Perlin noise
gm::PerlinNoisef     // float version
gm::PerlinNoised     // double version
```

#### Constructors

```cpp
// Default constructor (seed=42, shape=16x16, octaves=1)
gm::PerlinNoisef noise1;

// Custom seed and shape
gm::PerlinNoisef noise2(12345, gm::Vec2i(512, 512));

// Fractal Brownian Motion (FBM) with octaves
gm::PerlinNoisef noise3(
	42,                      // Seed
	gm::Vec2i(256, 256),    // Grid shape
	6,                       // Number of octaves
	0.5f                     // Persistence (amplitude decay)
);
```

#### Methods

```cpp
// Get noise value at coordinates [-1, 1]
float value = noise.getNoise(x, y);

// Get normalized noise value [0, 1]
float normalized = noise.getNoiseNormalize(x, y);

// Accessors
unsigned int seed = noise.getSeed();
unsigned int octaves = noise.getOctaves();
float persistence = noise.getPersistence();
gm::Vec2i shape = noise.getShape();
```

#### Example: Terrain Generation

```cpp
#include <gmath.hpp>

// Create fractal noise with 5 octaves
gm::PerlinNoisef terrain(
	42,                      // Seed for reproducibility
	gm::Vec2i(256, 256),    // 256x256 grid
	5,                       // 5 octaves for detail
	0.5f                     // Standard persistence
);

// Generate heightmap
for (int y = 0; y < 256; y++) {
	for (int x = 0; x < 256; x++) {
		// Scale coordinates for smoother noise
		float nx = x / 32.0f;
		float ny = y / 32.0f;

		// Get height value [0, 1]
		float height = terrain.getNoiseNormalize(nx, ny);

		// Use height for terrain generation
		// ...
	}
}
```

---

## Usage Examples

### Example 1: 3D Camera System

```cpp
#include <gmath.hpp>

class Camera {
public:
	gm::Vec3f position;
	gm::Vec3f forward;
	gm::Vec3f up;

	Camera() :
		position(0.0f, 0.0f, 5.0f),
		forward(0.0f, 0.0f, -1.0f),
		up(0.0f, 1.0f, 0.0f) {}

	void moveForward(float distance) {
		position += gm::normalize(forward) * distance;
	}

	gm::Vec3f getRight() const {
		return gm::normalize(gm::cross(forward, up));
	}
};
```

### Example 2: Particle System

```cpp
#include <gmath.hpp>
#include <vector>

struct Particle {
	gm::Vec3f position;
	gm::Vec3f velocity;
	float lifetime;
};

void updateParticles(std::vector<Particle>& particles, float deltaTime) {
	for (auto& p : particles) {
		p.position += p.velocity * deltaTime;
		p.lifetime -= deltaTime;

		// Apply gravity
		p.velocity += gm::Vec3f(0.0f, -9.81f, 0.0f) * deltaTime;
	}
}
```

### Example 3: Procedural Texture Generation

```cpp
#include <gmath.hpp>

void generateCloudTexture(unsigned char* texture, int width, int height) {
	gm::PerlinNoisef noise(12345, gm::Vec2i(256, 256), 4, 0.5f);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			float value = noise.getNoiseNormalize(
				x / 64.0f,
				y / 64.0f
			);

			// Convert to grayscale [0, 255]
			texture[y * width + x] = static_cast<unsigned char>(value * 255);
		}
	}
}
```

### Example 4: Physics Calculations

```cpp
#include <gmath.hpp>

struct RigidBody {
	gm::Vec3f position;
	gm::Vec3f velocity;
	float mass;

	void applyForce(const gm::Vec3f& force, float deltaTime) {
		// F = ma -> a = F/m
		gm::Vec3f acceleration = force / mass;
		velocity += acceleration * deltaTime;
		position += velocity * deltaTime;
	}

	float kineticEnergy() const {
		// KE = 0.5 * m * v²
		float speed = gm::length(velocity);
		return 0.5f * mass * speed * speed;
	}
};
```

---

## Building

The librairy use meson for build system.
You can use the makefile that wrap meson.

```bash
make # compile library. libgmath.so will be in ./build/libgmath.so

make run # Run basics tests on the lib.
```

### Compiler Requirements

- **C++17** or later

---

## Performance Notes

- **Zero-overhead abstraction**: Template-based design incurs no runtime cost
- **Inlining**: Most functions are candidates for compiler inlining
- **Type safety**: Compile-time type checking prevents errors
- **Cache-friendly**: Contiguous memory layout for vectors and matrices

---

## License

This project is free to used, just credit the repo.

---

## Author
**agtdbx**
- GitHub: [@agtdbx](https://github.com/agtdbx)

---

## Acknowledgments

- Inspired by [GLM](https://github.com/g-truc/glm) (OpenGL Mathematics)
- Perlin noise implementation based on Ken Perlin's improved noise
- Built for game developers, by a game developer

---

## See Also

- [GLM Documentation](https://glm.g-truc.net/)
- [LearnOpenGL - Mathematics](https://learnopengl.com/Getting-started/Transformations)
- [Perlin Noise](https://en.wikipedia.org/wiki/Perlin_noise)

---

**Happy coding!** 🚀
