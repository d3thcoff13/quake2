#include "g_local.h"

void CheckPerks(edict_t *ent)
{
	if (ent->client->resp.perk < 1)
	{       
		gi.centerprintf(ent, "Please choose your perk:\n\nG - Master Crafter\nM - Secret Ingreident\nN - Scavenger\n");
	}
}

void Cmd_Perks_f(edict_t *ent, char *cmd)
{

	if (ent->client->resp.perk > 0)
	{

		gi.sound(ent, CHAN_VOICE, gi.soundindex("items/damage2.wav"), 1, ATTN_NORM, 0);
		return;

	}
	
	gi.cprintf(ent, PRINT_HIGH, "Got: %s\n", cmd);

	if (Q_stricmp(cmd, "Master Crafter") == 0)
	{
		ent->client->resp.perk = 1;
		gi.centerprintf(ent, "Selected Master Crafter.\n");
	}
	else if (Q_stricmp(cmd, "Secret Ingredient") == 0)
	{
		ent->client->resp.perk = 2;
		gi.centerprintf(ent, "Selected Secret Ingredient.\n");
	}
	else if (Q_stricmp(cmd, "Scavenger") == 0)
	{
		ent->client->resp.perk = 3;
		gi.centerprintf(ent, "Selected Scavenger.\n");
	}
	else
	{
		ent->client->resp.perk = 0;
		gi.centerprintf(ent, "Invalid selection!\n");
	}

	gi.sound(ent, CHAN_VOICE, gi.soundindex("player/male/jump1.wav"), 1, ATTN_NORM, 0);
}
