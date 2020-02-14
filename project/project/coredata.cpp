#include "coredata.hpp"

ofstream items;
string secret = "PBG892FXX982ABC*";

void coredata::LoadItem(int clothingType, string name, int itemID, int breakhits, int actionType)
{
	//item defs are the same but you can easily add them with other items.dat vars
	items.open("CoreData.txt", ofstream::app);

	if (name.find("Ancestral") != -1 || name == "Ancient Shards")
	{
		items << to_string(itemID) + "|" + name + "|999|NoSeed, Dropless, Untradable|Artifact|C334EA|C7833B|0|3600|None" << endl;
	}

	else if (name == "Fist")
	{
		items << "18|Fist|999|Untradable|Fist|F01F3E|ED0AB6|4|3600|None" << endl;
	}

	else if (name == "Wrench")
	{
		items << "32|Wrench|999|Untradable|Wrench|37BA86|B05704|4|3600|None" << endl;
	}
	else {
		if (breakhits == 0)
		{
			if (clothingType == 0)
			{
				items << to_string(itemID) + "|" + name + "|8|NoSeed|Clothing|2F2F2F|191919|0|752|Hat" << endl;
			}
			else if (clothingType == 1)
			{
				items << to_string(itemID) + "|" + name + "|55|NoSeed|Clothing|050505|1D1D1D|0|168025|Shirt" << endl;
			}
			else if (clothingType == 2)
			{
				items << to_string(itemID) + "|" + name + "|51|NoSeed|Clothing|E8E8E8|5A5A5A|0|134181|Pants" << endl;
			}
			else if (clothingType == 3)
			{
				items << to_string(itemID) + "|" + name + "|11|NoSeed|Clothing|FF2727|FFE32B|0|1661|Feet" << endl;
			}
			else if (clothingType == 4)
			{
				items << to_string(itemID) + "|" + name + "|15|NoSeed|Clothing|F7F7F7|FFFFFF|0|3825|Face" << endl;
			}
			else if (clothingType == 5)
			{
				items << to_string(itemID) + "|" + name + "|10|NoSeed|Clothing|565656|FFFEE9|0|1300|Hand" << endl;
			}
			else if (clothingType == 6)
			{
				items << to_string(itemID) + "|" + name + "|999|NoSeed, Dropless, Untradable|Clothing|38B9E0|9FE6FB|0|3600|Back" << endl;
			}
			else if (clothingType == 7)
			{
				items << to_string(itemID) + "|" + name + "|74|NoSeed|Clothing|FFC34B|ED71FF|0|407444|Hair" << endl;
			}
			else if (clothingType == 8)
			{
				items << to_string(itemID) + "|" + name + "|999|NoSeed, Dropless|Clothing|FFFE0F|EAAA00|0|3600|Chest" << endl;
			}
			else {
				cout << "[BUILDER] FAILED TO LOAD ITEM WITH ID: " << to_string(itemID) << endl;
			}
		}
		else {
			if (name != "Fist" && name != "Wrench")
			{
				if (clothingType > -1 && breakhits == 120)
				{
					items << to_string(itemID) + "|" + name + "|1|NoSeed, Mod|Seed|000000|000000|20|0|None" << endl;
				}
				else if (clothingType == 0)
				{
					items << to_string(itemID) + "|" + name + "|1|0|Foreground_Block|603913|A67C52|" + to_string(breakhits / 6) + "|31|None" << endl;
				}
				else {
					cout << "[BUILDER] FAILED TO LOAD ITEM WITH ID: " + to_string(itemID) << endl;
				}
			}
		}
	}
	items.close();
}

void coredata::items_dat()
{
	bool items = experimental::filesystem::exists("items.dat");
	if (items)
	{
		ifstream file("items.dat", ios::binary | ios::ate);
		int size = file.tellg();
		char* data = new char[size];
		file.seekg(0, ios::beg);

		if (file.read((char*)(data), size))
		{
			cout << "[BUILDER] Making CoreData.txt" << endl;
		}
		int itemCount;
		int memPos = 0;
		int16_t itemsdatVersion = 0;
		memcpy(&itemsdatVersion, data + memPos, 2);
		memPos += 2;
		memcpy(&itemCount, data + memPos, 4);
		memPos += 4;
		cout << "[BUILDER] Itemcount: " << itemCount - 1 << "\n";
		for (int i = 0; i < itemCount; i++) {
			int itemID = 0;
			char editableType = 0;
			char itemCategory = 0;
			char actionType = 0;
			char hitSoundType = 0;
			string name = "";
			string texture = "";
			int textureHash = 0;
			char itemKind = 0;
			int val1;
			char textureX = 0;
			char textureY = 0;
			char spreadType = 0;
			char isStripeyWallpaper = 0;
			char collisionType = 0;
			unsigned char breakHits = 0;
			int dropChance = 0;
			char clothingType = 0;
			int16_t rarity = 0;
			unsigned char maxAmount = 0;
			string extraFile = "";
			int extraFileHash = 0;
			int audioVolume = 0;
			string petName = "";
			string petPrefix = "";
			string petSuffix = "";
			string petAbility = "";
			char seedBase = 0;
			char seedOverlay = 0;
			char treeBase = 0;
			char treeLeaves = 0;
			int seedColor = 0;
			int seedOverlayColor = 0;
			int growTime = 0;
			short val2;
			short isRayman = 0;
			string extraOptions = "";
			string texture2 = "";
			string extraOptions2 = "";
			string punchOptions = "";
			{
				memcpy(&itemID, data + memPos, 4);
				memPos += 4;
			}
			{
				editableType = data[memPos];
				memPos += 1;
			}
			{
				itemCategory = data[memPos];
				memPos += 1;
			}
			{
				actionType = data[memPos];
				memPos += 1;
			}
			{
				hitSoundType = data[memPos];
				memPos += 1;
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					name += data[memPos] ^ (secret[(j + itemID) % secret.length()]);
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					texture += data[memPos];
					memPos++;
				}
			}
			memcpy(&textureHash, data + memPos, 4);
			memPos += 4;
			itemKind = memPos[data];
			memPos += 1;
			memcpy(&val1, data + memPos, 4);
			memPos += 4;
			textureX = data[memPos];
			memPos += 1;
			textureY = data[memPos];
			memPos += 1;
			spreadType = data[memPos];
			memPos += 1;
			isStripeyWallpaper = data[memPos];
			memPos += 1;
			collisionType = data[memPos];
			memPos += 1;
			breakHits = data[memPos];
			memPos += 1;
			memcpy(&dropChance, data + memPos, 4);
			memPos += 4;
			clothingType = data[memPos];
			memPos += 1;
			memcpy(&rarity, data + memPos, 2);
			memPos += 2;
			maxAmount = data[memPos];
			memPos += 1;
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					extraFile += data[memPos];
					memPos++;
				}
			}
			memcpy(&extraFileHash, data + memPos, 4);
			memPos += 4;
			memcpy(&audioVolume, data + memPos, 4);
			memPos += 4;
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					petName += data[memPos];
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					petPrefix += data[memPos];
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					petSuffix += data[memPos];
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					petAbility += data[memPos];
					memPos++;
				}
			}
			{
				seedBase = data[memPos];
				memPos += 1;
			}
			{
				seedOverlay = data[memPos];
				memPos += 1;
			}
			{
				treeBase = data[memPos];
				memPos += 1;
			}
			{
				treeLeaves = data[memPos];
				memPos += 1;
			}
			{
				memcpy(&seedColor, data + memPos, 4);
				memPos += 4;
			}
			{
				memcpy(&seedOverlayColor, data + memPos, 4);
				memPos += 4;
			}
			memPos += 4;
			{
				memcpy(&growTime, data + memPos, 4);
				memPos += 4;
			}
			memcpy(&val2, data + memPos, 2);
			memPos += 2;
			memcpy(&isRayman, data + memPos, 2);
			memPos += 2;
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					extraOptions += data[memPos];
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					texture2 += data[memPos];
					memPos++;
				}
			}
			{
				int16_t strLen = *(int16_t*)& data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					extraOptions2 += data[memPos];
					memPos++;
				}
			}
			memPos += 80;
			if (itemsdatVersion >= 11) {
				{
					int16_t strLen = *(int16_t*)& data[memPos];
					memPos += 2;
					for (int j = 0; j < strLen; j++) {
						punchOptions += data[memPos];
						memPos++;
					}
				}
			}
			LoadItem(clothingType, name, itemID, breakHits, actionType);
		}
		cout << "[BUILDER] FINISHED!" << endl;
	}
	else {
	    cout << "[BUILDER] NO ITEMS.DAT FILE FOUND" << endl;
	}
}
