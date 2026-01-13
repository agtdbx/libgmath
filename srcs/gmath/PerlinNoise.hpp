#ifndef PERLIN_NOISE_HPP
# define PERLIN_NOISE_HPP

# include <gmath/Vec2.hpp>
# include <gmath/linear.hpp>
# include <gmath/random.hpp>

# include <vector>
# include <stdexcept>

namespace gm {
	# define DEFAULT_PERLIN_SHAPE gm::Vec2i(16, 16)

	template <typename T>
	struct	Noise
	{
		gm::Vec2i					shape;
		std::vector<gm::Vec2<T>>	noise;

		Noise<T>	&operator=(const Noise<T> &obj)
		{
			if (this == &obj)
				return (*this);

			this->shape = obj.shape;
			this->noise = obj.noise;

			return (*this);
		}
	};

	//**** STATIC FUNCTIONS DEFINE *************************************************

	template <typename T>
	static void		generateNoise(Noise<T> &noise, unsigned int seed);
	template <typename T>
	static T	getNoiseValue(const Noise<T> &noise, T x, T y);
	template <typename T>
	static T	fade(T value);

	//**** CLASS DEFINE ********************************************************

	/**
	 * @brief PerlinNoise class.
	 *
	 * @tparam T Return type of perlin noise value.
	 *
	 * The class is design to create 2D seeded fractal perlin noise.
	 */
	template <typename T>
	class PerlinNoise
	{
	public:
		//**** PUBLIC ATTRIBUTS ********************************************************
		//**** INITIALISION ************************************************************
		//---- Constructors ------------------------------------------------------------

		/**
		 * @brief Default contructor of PerlinNoise class.
		 *
		 * @return The default PerlinNoise.
		 */
		PerlinNoise(void)
		{
			this->seed = 42;
			this->octaves = 1;
			this->persistence = static_cast<T>(0.0);
			this->generateNoises(DEFAULT_PERLIN_SHAPE);
		}

		/**
		 * @brief Copy constructor of PerlinNoise class.
		 *
		 * @param obj The PerlinNoise to copy.
		 *
		 * @return The PerlinNoise copied from parameter.
		 */
		PerlinNoise(const PerlinNoise &obj)
		{
			this->seed = obj.seed;
			this->octaves = obj.octaves;
			this->persistence = obj.persistence;
			this->noises = obj.noises;
		}

		/**
		 * @brief Constructor of PerlinNoise class.
		 *
		 * @param seed The seed of perlin noise.
		 * @param shape The shape of perlin noise.
		 *
		 * @return The PerlinNoise created from parameter.
		 */
		PerlinNoise(unsigned int seed, const gm::Vec2i &shape)
		{
			this->seed = seed;
			this->octaves = 1;
			this->persistence = static_cast<T>(0.0);
			this->generateNoises(shape);
		}

		/**
		 * @brief Constructor of PerlinNoise class.
		 *
		 * @param seed The seed of perlin noise.
		 * @param shape The shape of perlin noise.
		 * @param octaves The number of sub perlin noise (for more details). Must be higher than 0.
		 * @param persistence The influence of sub perlin noise on previous noise. Must be between 0 and 1.
		 *
		 * @exception Throw an runtime_error if octaves is 0 or if persistence isn't in range [0, 1].
		 * @return The PerlinNoise created from parameter.
		 */
		PerlinNoise(
			unsigned int seed,
			const gm::Vec2i &shape,
			unsigned int octaves,
			T persistence)
		{
			this->seed = seed;
			this->octaves = octaves;
			this->persistence = persistence;

			if (this->octaves == 0)
				throw std::runtime_error("Octave can't be 0");
			if (persistence < static_cast<T>(0.0) || persistence > static_cast<T>(1.0))
				throw std::runtime_error("Persistence must be between 0.0 and 1.0");

			this->generateNoises(shape);
		}

		//---- Destructor --------------------------------------------------------------

		/**
		 * @brief Destructor of PerlinNoise class.
		 */
		~PerlinNoise()
		{
		}

		//**** ACCESSORS ***************************************************************
		//---- Getters -----------------------------------------------------------------

		/**
		 * @brief Getter for seed.
		 *
		 * @return The seed of the perlin noise.
		 */
		unsigned int	getSeed(void) const noexcept
		{
			return (this->seed);
		}

		/**
		 * @brief Getter for octaves.
		 *
		 * @return The octaves of the perlin noise.
		 */
		unsigned int	getOctaves(void) const noexcept
		{
			return (this->octaves);
		}

		/**
		 * @brief Getter for persistence.
		 *
		 * @return The persistence of the perlin noise.
		 */
		T	getPersistence(void) const noexcept
		{
			return (this->persistence);
		}

		/**
		 * @brief Getter for shape.
		 *
		 * @return The shape of the perlin noise.
		 */
		gm::Vec2i	getShape(void) const noexcept
		{
			return (this->noises[0].shape);
		}

		//---- Setters -----------------------------------------------------------------
		//---- Operators ---------------------------------------------------------------

		/**
		 * @brief Copy operator of PerlinNoise class.
		 *
		 * @param obj The PerlinNoise to copy.
		 *
		 * @return The PerlinNoise copied from parameter.
		 */
		PerlinNoise	&operator=(const PerlinNoise &obj)
		{
			if (this == &obj)
				return (*this);

			this->seed = obj.seed;
			this->octaves = obj.octaves;
			this->persistence = obj.persistence;
			this->noises = obj.noises;

			return (*this);
		}

		//**** PUBLIC METHODS **********************************************************
		/**
		 * @brief Method to get noise at give coordinates.
		 *
		 * @param x The x coordinates.
		 * @param y The y coordinates.
		 *
		 * @return The noise a coordinates (x, y). Result is between -1 and 1.
		 */
		T	getNoise(T x, T y) const noexcept
		{
			if (this->octaves == 1 || this->persistence == static_cast<T>(0))
				return (getNoiseValue(this->noises[0], x, y));

			T	total = static_cast<T>(0.0);
			T	frequency = static_cast<T>(1.0);
			T	amplitude = static_cast<T>(1.0);
			T	maxValue = static_cast<T>(0.0);
			T	amplitudeMin = static_cast<T>(0.00001);
			T	frequencyMultiplier = static_cast<T>(2);

			for (unsigned int i = 0; i < this->octaves; i++)
			{
				total += getNoiseValue(this->noises[i], x * frequency, y * frequency) * amplitude;

				maxValue += amplitude;

				amplitude *= this->persistence;
				if (amplitude <= amplitudeMin)
					break;
				frequency *= frequencyMultiplier;
			}

			if (maxValue == static_cast<T>(0))
				return (static_cast<T>(0));
			return (total / maxValue);
		}

		/**
		 * @brief Method to get noise normalize at give coordinates.
		 *
		 * @param x The x coordinates.
		 * @param y The y coordinates.
		 *
		 * @return The normalize noise a coordinates (x, y). Result is between 0 and 1.
		 */
		T	getNoiseNormalize(T x, T y) const noexcept
		{
			T	noise = this->getNoise(x, y);

			return ((noise + static_cast<T>(1.0)) * static_cast<T>(0.5));
		}

		//**** STATIC METHODS **********************************************************

	private:
		//**** PRIVATE ATTRIBUTS *******************************************************
		unsigned int			seed, octaves;
		T						persistence;
		std::vector<Noise<T> >	noises;

		//**** PRIVATE METHODS *********************************************************
		/**
		 * @brief Generate noises.
		 *
		 * @param firstShape Shape of the first noise.
		 */
		void	generateNoises(const gm::Vec2i &firstShape)
		{
			unsigned int	seed = this->seed;
			gm::Vec2i		shape = firstShape;

			this->noises.resize(this->octaves);
			for (unsigned int i = 0; i < this->octaves; i++)
			{
				// Create noise
				this->noises[i].shape = shape;
				generateNoise(this->noises[i], seed);

				// Create seed and shape for next noise
				if (i + 1 < this->octaves)
				{
					gm::initRandom(seed);
					seed = gm::uRand();
					shape *= 2;
				}
			}
		}
	};

	//**** FUNCTIONS ***************************************************************
	//**** STATIC FUNCTIONS ********************************************************

	template <typename T>
	static void	generateNoise(Noise<T> &noise, unsigned int seed)
	{
		int size = noise.shape.x * noise.shape.y;

		gm::initRandom(seed);

		noise.noise.resize(size);
		for (int i = 0; i < size; i++)
		{
			int	nb = gm::iRand(0, 3);

			if (nb == 0)
				noise.noise[i] = gm::Vec2<T>(static_cast<T>( 1.0),static_cast<T>( 1.0));
			else if (nb == 1)
				noise.noise[i] = gm::Vec2<T>(static_cast<T>(-1.0),static_cast<T>( 1.0));
			else if (nb == 2)
				noise.noise[i] = gm::Vec2<T>(static_cast<T>(-1.0),static_cast<T>(-1.0));
			else
				noise.noise[i] = gm::Vec2<T>(static_cast<T>( 1.0),static_cast<T>(-1.0));
		}
	}


	template <typename T>
	static T	getNoiseValue(const Noise<T> &noise, T x, T y)
	{
		// Put x in noise coordinates
		if (x >= noise.shape.x)
			x -= ((int)x / noise.shape.x) * noise.shape.x;
		else if (x < static_cast<T>(0))
		{
			x -= ((int)x / noise.shape.x) * noise.shape.x;
			x = noise.shape.x + x;
			if (x >= noise.shape.x)
				x -= noise.shape.x;
		}

		// Put y in noise coordinates
		if (y >= noise.shape.y)
			y -= ((int)y / noise.shape.y) * noise.shape.y;
		else if (y < static_cast<T>(0))
		{
			y -= ((int)y / noise.shape.y) * noise.shape.y;
			y = noise.shape.y + y;
			if (y >= noise.shape.y)
				y -= noise.shape.y;
		}

		// Get coordinates of point in noise.
		gm::Vec2<T>	pos(x, y);
		int	xi = (int)x;
		int	yi = (int)y;
		T	xf = x - (int)x;
		T	yf = y - (int)y;

		// Compute u and v for interpolations
		T	u = fade(xf);
		T	v = fade(yf);

		// Left up corner
		int	xLU = xi;
		int	yLU = yi;
		const gm::Vec2<T>	&noiseLU = noise.noise[xLU + yLU * noise.shape.x];
		const gm::Vec2<T>	vecLU = (pos - gm::Vec2<T>(xi, yi));
		T	valueLU = gm::dot(noiseLU, vecLU);

		// Left down corner
		int	xLD = xi;
		int	yLD = (yi + 1) % noise.shape.y;
		const gm::Vec2<T>	&noiseLD = noise.noise[xLD + yLD * noise.shape.x];
		const gm::Vec2<T>	vecLD = (pos - gm::Vec2<T>(xi, yi + 1));
		T	valueLD = gm::dot(noiseLD, vecLD);

		// Right down corner
		int	xRD = (xi + 1) % noise.shape.x;
		int	yRD = (yi + 1) % noise.shape.y;
		const gm::Vec2<T>	&noiseRD = noise.noise[xRD + yRD * noise.shape.x];
		const gm::Vec2<T>	vecRD = (pos - gm::Vec2<T>(xi + 1, yi + 1));
		T	valueRD = gm::dot(noiseRD, vecRD);

		// Right up corner
		int	xRU = (xi + 1) % noise.shape.x;
		int	yRU = yi;
		const gm::Vec2<T>	&noiseRU = noise.noise[xRU + yRU * noise.shape.x];
		const gm::Vec2<T>	vecRU = (pos - gm::Vec2<T>(xi + 1, yi));
		T	valueRU = gm::dot(noiseRU, vecRU);

		// Interpolate x axis
		T	valueU = gm::lerp(valueLU, valueRU, u);
		T	valueD = gm::lerp(valueLD, valueRD, u);

		// Interpolate y axis
		T	value = gm::lerp(valueU, valueD, v);

		return (value);
	}

	template <typename T>
	static T	fade(T value)
	{
		return (value * value * value * (value * (value * static_cast<T>(6) - static_cast<T>(15))
											+ static_cast<T>(10)));
	}

	//**** USINGS **************************************************************

	/**
	 * @brief PerlinNoise float class.
	 *
	 * The class is design to create 2D seeded fractal perlin noise.
	 */
	using PerlinNoisef = PerlinNoise<float>;
	/**
	 * @brief PerlinNoise double class.
	 *
	 * The class is design to create 2D seeded fractal perlin noise.
	 */
	using PerlinNoised = PerlinNoise<double>;
}

#endif
