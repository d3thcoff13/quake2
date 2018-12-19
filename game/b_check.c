#include "g_local.h"


void CheckItem(edict_t *ent, gitem_t *item)
{


	char *sp_weapon[29][2] =
	{
		{ "weapon_machinegun", "cluster_parts" },
		{ "weapon_supershotgun", "proximity_parts" },
		{ "weapon_grenadelauncher", "pulse_parts" },
		{ "weapon_rocketlauncher", "fastball_parts" },
		{ "weapon_railgun", "poison_parts" },
		{ "weapon_hyperblaster", "impulse_parts" },
		{ "weapon_shotgun", "fastball_parts" },
		{ "weapon_chaingun", "pulse_parts" },
		{"weapon_bfg", "nuke_parts"},
		{ "ammo_shells", "cluster_parts" },
		{ "ammo_bullets", "proximity_parts" },
		{ "ammo_cells", "pulse_parts" },
		{ "ammo_rockets", "fastball_parts" },
		{ "ammo_slugs", "poison_parts" },
		{ "item_quad", "item_double" },
		{ "item_invulnerability", "item_half_dmg" },
		{ "item_silencer", "item_double" },
		{ "item_breather", "item_double" },
		{ "item_enviro", "item_rapid_fire" },
		{ "item_ancient_head", "item_half_dmg" },
		{ "item_adrenaline", "item_half_dmg" },
		{ "item_bandolier", "item_rapid_fire" },
		{ "item_pack", "item_rapid_fire" },
		{ "item_armor_body", "item_half_dmg" },
		{ "item_armor_combat", "item_half_dmg" },
		{ "item_armor_jacket", "item_half_dmg" },
		{ "item_armor_shard", "item_half_dmg" },
		{ "item_power_screen", "item_half_dmg" },
		{ "item_power_shield", "item_half_dmg" }
	};

	int i;

	for (i = 0; i < 29; i++)
	{
		
		if (!sp_weapon[i][0])
			continue;
		
		if (Q_stricmp(ent->classname, sp_weapon[i][0]) == 0)
		{
			
			ent->classname = item->classname = sp_weapon[i][1];
			SpawnItem(ent, item);
			

			return;
		}
	}
}