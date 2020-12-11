//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

namespace SmartGrid::Types
{
	namespace Parameters
	{
		constexpr int V_MIN = 10;
		constexpr int V_MAX = 120;
		constexpr int S_MIN = 0;
		constexpr int S_MAX = 100000;

		struct GridParameters
		{
			int Step{};
			int Length{};

			int Vmin{};
			int Vmax{};
			int VStep{};
		};

		struct GridPoint
		{
			int X;
			int Y;
        };
	}
}
//---------------------------------------------------------------------------
#endif
