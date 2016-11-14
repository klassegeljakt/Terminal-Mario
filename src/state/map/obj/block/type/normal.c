/******************************************************************************
*     File Name           :     normal.c                                      *
*     Created By          :     Klas Segeljakt                                *
*     Creation Date       :     [2016-11-10 12:48]                            *
*     Last Modified       :     [2016-11-13 21:40]                            *
*     Description         :     Normal block (unbreakable).                   *
******************************************************************************/
#include "../block.h"
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map);
/*****************************************************************************/
int new_normal_block(int y, int x, int ch, map_t *map) {
    map->block[y][x].ctop = cblock;
    map->block[y][x].cside = cblock;
    map->block[y][x].cbot = cbot;
    map->block[y][x].has_collision = 1;
    map->block[y][x].ch = ch;
    return 0;
}
/*****************************************************************************/
static int cbot(unit_t *player, block_t *self, map_t *map) {
    player->pos.x = player->pre.x;
    player->pos.y = player->pre.y;
    player->vel.y = 0;
    return 0;
}
