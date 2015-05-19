/*
Some of this code began its life as a part of GTA V SCRIPT HOOK SDK.
http://dev-c.com
(C) Alexander Blade 2015

It is now part of the Enhanced Native Trainer project.
https://github.com/gtav-ent/GTAV-EnhancedNativeTrainer
(C) Rob Pridham and fellow contributors 2015
*/

#include "vehicles.h"
#include "menu_functions.h"
#include "config_io.h"

extern int whichpart = 0;
extern int whichtype = 0;

//Parts
const std::vector<std::string> MENU_PAINT_WHAT{ "Primary Color", "Secondary Color", "Pearl Topcoat" }; //"Wheels"


//Paint Names
const std::vector<std::string> MENU_PAINT_TYPE{ "Metallic", "Normal", "Pearlescent", "Matte", "Metal", "Chrome" }; //"Wheel Colors"

const std::vector<std::string> CAPTIONS_NORMAL{ "Black", "Carbon Black", "Graphite Black", "Anthracite Black", "Black Steel", "Dark Steel", "Silver", "Bluish Silver", "Rolled Steel", "Shadow Silver", "Stone Silver", "Midnight Silver", "Cast Iron Silver", "Red", "Torino Red", "Formula Red", "Lava Red", "Blaze Red", "Grace Red", "Garnet Red", "Sunset Red", "Cabernet Red", "Wine Red", "Candy Red", "Hot Pink", "Pfister Pink", "Salmon Pink", "Sunrise Orange", "Orange", "Bright Orange", "Gold", "Bronze", "Yellow", "Race Yellow", "Dew Yellow", "Dark Green", "Racing Green", "Sea Green", "Olive Green", "Bright Green", "Gasoline Green", "Lime Green", "Midnight Blue", "Galaxy Blue", "Dark Blue", "Saxon Blue", "Blue", "Mariner Blue", "Harbor Blue", "Diamond Blue", "Surf Blue", "Nautical Blue", "Racing Blue", "Ultra Blue", "Light Blue", "Chocolate Brown", "Bison Brown", "Creek Brown", "Feltzer Brown", "Maple Brown", "Beechwood Brown", "Sienna Brown", "Saddle Brown", "Moss Brown", "Woodbeech Brown", "Straw Brown", "Sandy Brown", "Bleached Brown", "Schafter Purple", "Spinnaker Purple", "Midnight Purple", "Bright Purple", "Cream", "Ice White", "Frost White" };

const std::vector<std::string> CAPTIONS_METALLIC{ "Black", "Carbon Black", "Graphite Black", "Anthracite Black", "Black Steel", "Dark Steel", "Silver", "Bluish Silver", "Rolled Steel", "Shadow Silver", "Stone Silver", "Midnight Silver", "Cast Iron Silver", "Red", "Torino Red", "Formula Red", "Lava Red", "Blaze Red", "Grace Red", "Garnet Red", "Sunset Red", "Cabernet Red", "Wine Red", "Candy Red", "Hot Pink", "Pfister Pink", "Salmon Pink", "Sunrise Orange", "Orange", "Bright Orange", "Gold", "Bronze", "Yellow", "Race Yellow", "Dew Yellow", "Dark Green", "Racing Green", "Sea Green", "Olive Green", "Bright Green", "Gasoline Green", "Lime Green", "Midnight Blue", "Galaxy Blue", "Dark Blue", "Saxon Blue", "Blue", "Mariner Blue", "Harbor Blue", "Diamond Blue", "Surf Blue", "Nautical Blue", "Racing Blue", "Ultra Blue", "Light Blue", "Chocolate Brown", "Bison Brown", "Creek Brown", "Feltzer Brown", "Maple Brown", "Beechwood Brown", "Sienna Brown", "Saddle Brown", "Moss Brown", "Woodbeech Brown", "Straw Brown", "Sandy Brown", "Bleached Brown", "Schafter Purple", "Spinnaker Purple", "Midnight Purple", "Bright Purple", "Cream", "Ice White", "Frost White" };

const std::vector<std::string> CAPTIONS_PEARL{ "Black", "Carbon Black", "Graphite Black", "Anthracite Black", "Black Steel", "Dark Steel", "Silver", "Bluish Silver", "Rolled Steel", "Shadow Silver", "Stone Silver", "Midnight Silver", "Cast Iron Silver", "Red", "Torino Red", "Formula Red", "Lava Red", "Blaze Red", "Grace Red", "Garnet Red", "Sunset Red", "Cabernet Red", "Wine Red", "Candy Red", "Hot Pink", "Pfister Pink", "Salmon Pink", "Sunrise Orange", "Orange", "Bright Orange", "Gold", "Bronze", "Yellow", "Race Yellow", "Dew Yellow", "Dark Green", "Racing Green", "Sea Green", "Olive Green", "Bright Green", "Gasoline Green", "Lime Green", "Midnight Blue", "Galaxy Blue", "Dark Blue", "Saxon Blue", "Blue", "Mariner Blue", "Harbor Blue", "Diamond Blue", "Surf Blue", "Nautical Blue", "Racing Blue", "Ultra Blue", "Light Blue", "Chocolate Brown", "Bison Brown", "Creek Brown", "Feltzer Brown", "Maple Brown", "Beechwood Brown", "Sienna Brown", "Saddle Brown", "Moss Brown", "Woodbeech Brown", "Straw Brown", "Sandy Brown", "Bleached Brown", "Schafter Purple", "Spinnaker Purple", "Midnight Purple", "Bright Purple", "Cream", "Ice White", "Frost White" };

const std::vector<std::string> CAPTIONS_MATTE{ "Black", "Gray", "Light Gray", "Ice White", "Blue", "Dark Blue", "Midnight Blue", "Midnight Purple", "Schafter Purple", "Red", "Dark Red", "Orange", "Yellow", "Lime Green", "Green", "Forest Green", "Foliage Green", "Olive Drab", "Dark Earth", "Desert Tan" };

const std::vector<std::string> CAPTIONS_METAL{ "Brushed Steel", "Brushed Black Steel", "Brushed Aluminum", "Pure Gold", "Brushed Gold" };

const std::vector<std::string> CAPTIONS_CHROME{ "Chrome" };

//const std::vector<std::string> CAPTIONS_WHEELS{ "Alloy", "Black", "Carbon Black", "Anthracite Black", "Black Steel", "Stone Silver", "Frost White", "Red", "Blaze Red", "Garnet Red", "Candy Red", "Sunset Red", "Salmon Pink", "Hot Pink", "Sunrise Orange", "Orange", "Bright Orange", "Gold", "Straw Brown", "Dark Copper", "Dark Ivory", "Dark Brown", "Bronze", "Dark Earth", "Desert Tan", "Yellow", "Race Yellow", "Yellow Bird", "Lime Green", "Pea Green", "Green", "Dark Green", "Olive Green", "Midnight Blue", "Royal Blue", "Baby Blue", "Bright Blue", "Flourescent Blue", "Slate Blue", "Schafter Purple", "Midnight Purple" };


//Paint Values
const std::vector<std::string> VALUES_NORMAL{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74" };

const std::vector<std::string> VALUES_METALLIC{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74" };

const std::vector<std::string> VALUES_PEARL{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74" };

const std::vector<std::string> VALUES_MATTE{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19" };

const std::vector<std::string> VALUES_METAL{ "0", "1", "2", "3", "4" };

const std::vector<std::string> VALUES_CHROME{ "0" };

//const std::vector<std::string> VALUES_WHEELS{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40" };


const std::vector<std::string> VOV_PAINT_CAPTIONS[] = { CAPTIONS_METALLIC, CAPTIONS_NORMAL, CAPTIONS_PEARL, CAPTIONS_MATTE, CAPTIONS_METAL, CAPTIONS_CHROME }; //CAPTIONS_WHEELS
const std::vector<std::string> VOV_PAINT_VALUES[] = { VALUES_METALLIC, VALUES_NORMAL, VALUES_PEARL, VALUES_MATTE, VALUES_METAL, VALUES_CHROME }; //VALUES_WHEELS



bool onconfirm_paint_menu(MenuItem<int> choice)
{
	::whichpart = choice.value;
	process_paint_menu_type();
	return false;
}

bool process_paint_menu()
{
	std::vector<MenuItem<int>*> menuItems;
	for (int i = 0; i < MENU_PAINT_WHAT.size(); i++)
	{
		MenuItem<int> *item = new MenuItem<int>();
		item->caption = MENU_PAINT_WHAT[i];
		item->value = i;
		item->isLeaf = false;
		menuItems.push_back(item);
	}

	return draw_generic_menu<int>(menuItems, 0, "Choose which part to paint", onconfirm_paint_menu, NULL, NULL);
}

bool onconfirm_paint_menu_type(MenuItem<int> choice)
{
	std::string category = choice.caption;

	std::vector<MenuItem<std::string>*> menuItems;
	for (int i = 0; i < VOV_PAINT_VALUES[choice.value].size(); i++)
	{
		MenuItem<std::string> *item = new MenuItem<std::string>();
		item->caption = VOV_PAINT_CAPTIONS[choice.value][i];
		item->value = VOV_PAINT_VALUES[choice.value][i];
		menuItems.push_back(item);
	}
	::whichtype = choice.value;
	return draw_generic_menu<std::string>(menuItems, 0, category, onconfirm_color_menu_selection, onhighlight_color_menu_selection, NULL);
}

bool process_paint_menu_type()
{
	std::vector<MenuItem<int>*> menuItems;
	for (int i = 0; i < MENU_PAINT_TYPE.size(); i++)
	{
		MenuItem<int> *item = new MenuItem<int>();
		item->caption = MENU_PAINT_TYPE[i];
		item->value = i;
		item->isLeaf = false;
		menuItems.push_back(item);
	}

	return draw_generic_menu<int>(menuItems, 0, "Choose Paint Type", onconfirm_paint_menu_type, NULL, NULL);
}

void onhighlight_color_menu_selection(MenuItem<std::string> choice)
{
	onconfirm_color_menu_selection(choice);
}

bool onconfirm_color_menu_selection(MenuItem<std::string> choice)
{
	int whichpaint = std::stoi(choice.value);
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (bPlayerExists)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

			if (::whichpart == 0) //Primary Color
			{
				VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, ::whichtype, whichpaint, 0);
			}
			else if (::whichpart == 1) //Secondary Color
			{
				VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, ::whichtype, whichpaint);
			}
			else if (::whichpart == 2) //Pearl Topcoat
			{
				Any paint1, paint2, paint3;
				VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &paint1, &paint2, &paint3);

				if (paint1 == 2) //Check if pearlescent is set as primary paint type
				{
					VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, paint1, paint2, whichpaint); //apply topcoat
				}
				else
				{
					set_status_text("Set a Pearlescent Basecoat first");
				}
			}
			//else if (::whichpart == 3) //Wheels
			//{
			//	Any paint1, paint2;
			//	VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &paint1, &paint2);
			//	VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, paint1, whichpaint); //pearl topcoat followed by wheel color
			//}

		}
		else
		{
			set_status_text("Player isn't in a vehicle");
		}
	}
	return false;
}