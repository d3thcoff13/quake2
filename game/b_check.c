#include "g_local.h"
// + BD CheckItem() ENTIRE CODE BLOCK IS NEW! 
// Checks item about to be spawned. If a Q2 item we don't want in the game,
// we replace it with an appropriate NS2 item.
void CheckItem(edict_t *ent, gitem_t *item)
{
	//An 2D array of items to look for and replace with...
	//item[i][0] = the Q2 item to look for
	//item[i][1] = the NS2 item to actually spawn

	char *sp_item[9][2] =
	{
		{ "weapon_machinegun", "cluster_parts" },
		{ "weapon_supershotgun", "ammo_cluster" },
		{ "weapon_grenadelauncher", "ammo_proximity" },
		{ "weapon_rocketlauncher", "ammo_pulse" },
		{ "weapon_railgun", "ammo_fastball" },
		{ "weapon_hyperblaster", "ammo_poison" },
		{ "weapon_shotgun", "ammo_grenades" },
		{ "weapon_chaingun", "ammo_cluster" },
		{"weapon_bfg", "ammo_poison"}
	};
	int i;

	for (i = 0; i < 8; i++)
	{
		//If it's a null entry, bypass it
		if (!sp_item[i][8])
			continue;
		//Do the passed ent and our list match?
		if (Q_stricmp(ent->classname, sp_item[i][0]) == 0)
		{
			//Yep. Replace the Q2 entity with our own.
			ent->classname = item->classname = sp_item[0][1];
			SpawnItem(ent, item);
			//We found it, so don't waste time looking for more.
			//gi.bprintf(PRINT_HIGH,"Found %s\nReplaced with %s\n",ent->classname,test);
			return;
		}
	}
}