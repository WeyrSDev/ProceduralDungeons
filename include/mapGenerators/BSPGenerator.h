#include "dataStructures.h"

#include <vector>

namespace ProceduralDungeons
{
	class BSPGenerator
	{
	public:
		BSPGenerator();
		BSPGenerator(int width, int height);

		Map GenerateMap();

		void SetMinRoomSize(int newMinRoomSize) { _minRoomSize = newMinRoomSize; }
		void SetPasaggesSize(int newPassagesSize) { _passagesSize = newPassagesSize; }
	private:

		Map _map; // 0 = empty, 1 = wall
		int _width;
		int _height;
		int _minRoomSize;
		int _passagesSize;
		int _nRooms;

		bool IsOutOfBounds(int x, int y) const;

		std::vector<BSPRoom> GeneratePartition(int minX, int maxX, int minY, int maxY);
		BSPRoom CreateRoom(int startX, int finalX, int startY, int finalY);
		void ConnectRooms(std::vector<BSPRoom>* roomsA, std::vector<BSPRoom>* roomsB);
		void CreatePassage(BSPRoom roomA, BSPRoom roomB);
		void DrawPassage(int startX, int finalX, int startY, int finalY);

	}; // class BSPGenerator

} // namespace ProceduralDungeons