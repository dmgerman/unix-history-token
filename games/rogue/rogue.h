begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Timoth C. Stoehr.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)rogue.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * rogue.h  *  * This source herein may be modified and/or distributed by anybody who  * so desires, with the following restrictions:  *    1.)  This notice shall not be removed.  *    2.)  Credit shall not be taken for the creation of this source.  *    3.)  This code is not to be traded, sold, or used for personal  *         gain or profit.  */
end_comment

begin_define
define|#
directive|define
name|boolean
value|char
end_define

begin_define
define|#
directive|define
name|NOTHING
value|((unsigned short)     0)
end_define

begin_define
define|#
directive|define
name|OBJECT
value|((unsigned short)    01)
end_define

begin_define
define|#
directive|define
name|MONSTER
value|((unsigned short)    02)
end_define

begin_define
define|#
directive|define
name|STAIRS
value|((unsigned short)    04)
end_define

begin_define
define|#
directive|define
name|HORWALL
value|((unsigned short)   010)
end_define

begin_define
define|#
directive|define
name|VERTWALL
value|((unsigned short)   020)
end_define

begin_define
define|#
directive|define
name|DOOR
value|((unsigned short)   040)
end_define

begin_define
define|#
directive|define
name|FLOOR
value|((unsigned short)  0100)
end_define

begin_define
define|#
directive|define
name|TUNNEL
value|((unsigned short)  0200)
end_define

begin_define
define|#
directive|define
name|TRAP
value|((unsigned short)  0400)
end_define

begin_define
define|#
directive|define
name|HIDDEN
value|((unsigned short) 01000)
end_define

begin_define
define|#
directive|define
name|ARMOR
value|((unsigned short)   01)
end_define

begin_define
define|#
directive|define
name|WEAPON
value|((unsigned short)   02)
end_define

begin_define
define|#
directive|define
name|SCROL
value|((unsigned short)   04)
end_define

begin_define
define|#
directive|define
name|POTION
value|((unsigned short)  010)
end_define

begin_define
define|#
directive|define
name|GOLD
value|((unsigned short)  020)
end_define

begin_define
define|#
directive|define
name|FOOD
value|((unsigned short)  040)
end_define

begin_define
define|#
directive|define
name|WAND
value|((unsigned short) 0100)
end_define

begin_define
define|#
directive|define
name|RING
value|((unsigned short) 0200)
end_define

begin_define
define|#
directive|define
name|AMULET
value|((unsigned short) 0400)
end_define

begin_define
define|#
directive|define
name|ALL_OBJECTS
value|((unsigned short) 0777)
end_define

begin_define
define|#
directive|define
name|LEATHER
value|0
end_define

begin_define
define|#
directive|define
name|RINGMAIL
value|1
end_define

begin_define
define|#
directive|define
name|SCALE
value|2
end_define

begin_define
define|#
directive|define
name|CHAIN
value|3
end_define

begin_define
define|#
directive|define
name|BANDED
value|4
end_define

begin_define
define|#
directive|define
name|SPLINT
value|5
end_define

begin_define
define|#
directive|define
name|PLATE
value|6
end_define

begin_define
define|#
directive|define
name|ARMORS
value|7
end_define

begin_define
define|#
directive|define
name|BOW
value|0
end_define

begin_define
define|#
directive|define
name|DART
value|1
end_define

begin_define
define|#
directive|define
name|ARROW
value|2
end_define

begin_define
define|#
directive|define
name|DAGGER
value|3
end_define

begin_define
define|#
directive|define
name|SHURIKEN
value|4
end_define

begin_define
define|#
directive|define
name|MACE
value|5
end_define

begin_define
define|#
directive|define
name|LONG_SWORD
value|6
end_define

begin_define
define|#
directive|define
name|TWO_HANDED_SWORD
value|7
end_define

begin_define
define|#
directive|define
name|WEAPONS
value|8
end_define

begin_define
define|#
directive|define
name|MAX_PACK_COUNT
value|24
end_define

begin_define
define|#
directive|define
name|PROTECT_ARMOR
value|0
end_define

begin_define
define|#
directive|define
name|HOLD_MONSTER
value|1
end_define

begin_define
define|#
directive|define
name|ENCH_WEAPON
value|2
end_define

begin_define
define|#
directive|define
name|ENCH_ARMOR
value|3
end_define

begin_define
define|#
directive|define
name|IDENTIFY
value|4
end_define

begin_define
define|#
directive|define
name|TELEPORT
value|5
end_define

begin_define
define|#
directive|define
name|SLEEP
value|6
end_define

begin_define
define|#
directive|define
name|SCARE_MONSTER
value|7
end_define

begin_define
define|#
directive|define
name|REMOVE_CURSE
value|8
end_define

begin_define
define|#
directive|define
name|CREATE_MONSTER
value|9
end_define

begin_define
define|#
directive|define
name|AGGRAVATE_MONSTER
value|10
end_define

begin_define
define|#
directive|define
name|MAGIC_MAPPING
value|11
end_define

begin_define
define|#
directive|define
name|CON_MON
value|12
end_define

begin_define
define|#
directive|define
name|SCROLS
value|13
end_define

begin_define
define|#
directive|define
name|INCREASE_STRENGTH
value|0
end_define

begin_define
define|#
directive|define
name|RESTORE_STRENGTH
value|1
end_define

begin_define
define|#
directive|define
name|HEALING
value|2
end_define

begin_define
define|#
directive|define
name|EXTRA_HEALING
value|3
end_define

begin_define
define|#
directive|define
name|POISON
value|4
end_define

begin_define
define|#
directive|define
name|RAISE_LEVEL
value|5
end_define

begin_define
define|#
directive|define
name|BLINDNESS
value|6
end_define

begin_define
define|#
directive|define
name|HALLUCINATION
value|7
end_define

begin_define
define|#
directive|define
name|DETECT_MONSTER
value|8
end_define

begin_define
define|#
directive|define
name|DETECT_OBJECTS
value|9
end_define

begin_define
define|#
directive|define
name|CONFUSION
value|10
end_define

begin_define
define|#
directive|define
name|LEVITATION
value|11
end_define

begin_define
define|#
directive|define
name|HASTE_SELF
value|12
end_define

begin_define
define|#
directive|define
name|SEE_INVISIBLE
value|13
end_define

begin_define
define|#
directive|define
name|POTIONS
value|14
end_define

begin_define
define|#
directive|define
name|TELE_AWAY
value|0
end_define

begin_define
define|#
directive|define
name|SLOW_MONSTER
value|1
end_define

begin_define
define|#
directive|define
name|INVISIBILITY
value|2
end_define

begin_define
define|#
directive|define
name|POLYMORPH
value|3
end_define

begin_define
define|#
directive|define
name|HASTE_MONSTER
value|4
end_define

begin_define
define|#
directive|define
name|MAGIC_MISSILE
value|5
end_define

begin_define
define|#
directive|define
name|CANCELLATION
value|6
end_define

begin_define
define|#
directive|define
name|DO_NOTHING
value|7
end_define

begin_define
define|#
directive|define
name|DRAIN_LIFE
value|8
end_define

begin_define
define|#
directive|define
name|COLD
value|9
end_define

begin_define
define|#
directive|define
name|FIRE
value|10
end_define

begin_define
define|#
directive|define
name|WANDS
value|11
end_define

begin_define
define|#
directive|define
name|STEALTH
value|0
end_define

begin_define
define|#
directive|define
name|R_TELEPORT
value|1
end_define

begin_define
define|#
directive|define
name|REGENERATION
value|2
end_define

begin_define
define|#
directive|define
name|SLOW_DIGEST
value|3
end_define

begin_define
define|#
directive|define
name|ADD_STRENGTH
value|4
end_define

begin_define
define|#
directive|define
name|SUSTAIN_STRENGTH
value|5
end_define

begin_define
define|#
directive|define
name|DEXTERITY
value|6
end_define

begin_define
define|#
directive|define
name|ADORNMENT
value|7
end_define

begin_define
define|#
directive|define
name|R_SEE_INVISIBLE
value|8
end_define

begin_define
define|#
directive|define
name|MAINTAIN_ARMOR
value|9
end_define

begin_define
define|#
directive|define
name|SEARCHING
value|10
end_define

begin_define
define|#
directive|define
name|RINGS
value|11
end_define

begin_define
define|#
directive|define
name|RATION
value|0
end_define

begin_define
define|#
directive|define
name|FRUIT
value|1
end_define

begin_define
define|#
directive|define
name|NOT_USED
value|((unsigned short)   0)
end_define

begin_define
define|#
directive|define
name|BEING_WIELDED
value|((unsigned short)  01)
end_define

begin_define
define|#
directive|define
name|BEING_WORN
value|((unsigned short)  02)
end_define

begin_define
define|#
directive|define
name|ON_LEFT_HAND
value|((unsigned short)  04)
end_define

begin_define
define|#
directive|define
name|ON_RIGHT_HAND
value|((unsigned short) 010)
end_define

begin_define
define|#
directive|define
name|ON_EITHER_HAND
value|((unsigned short) 014)
end_define

begin_define
define|#
directive|define
name|BEING_USED
value|((unsigned short) 017)
end_define

begin_define
define|#
directive|define
name|NO_TRAP
value|-1
end_define

begin_define
define|#
directive|define
name|TRAP_DOOR
value|0
end_define

begin_define
define|#
directive|define
name|BEAR_TRAP
value|1
end_define

begin_define
define|#
directive|define
name|TELE_TRAP
value|2
end_define

begin_define
define|#
directive|define
name|DART_TRAP
value|3
end_define

begin_define
define|#
directive|define
name|SLEEPING_GAS_TRAP
value|4
end_define

begin_define
define|#
directive|define
name|RUST_TRAP
value|5
end_define

begin_define
define|#
directive|define
name|TRAPS
value|6
end_define

begin_define
define|#
directive|define
name|STEALTH_FACTOR
value|3
end_define

begin_define
define|#
directive|define
name|R_TELE_PERCENT
value|8
end_define

begin_define
define|#
directive|define
name|UNIDENTIFIED
value|((unsigned short) 00)
end_define

begin_comment
comment|/* MUST BE ZERO! */
end_comment

begin_define
define|#
directive|define
name|IDENTIFIED
value|((unsigned short) 01)
end_define

begin_define
define|#
directive|define
name|CALLED
value|((unsigned short) 02)
end_define

begin_define
define|#
directive|define
name|DROWS
value|24
end_define

begin_define
define|#
directive|define
name|DCOLS
value|80
end_define

begin_define
define|#
directive|define
name|NMESSAGES
value|5
end_define

begin_define
define|#
directive|define
name|MAX_TITLE_LENGTH
value|30
end_define

begin_define
define|#
directive|define
name|MAXSYLLABLES
value|40
end_define

begin_define
define|#
directive|define
name|MAX_METAL
value|14
end_define

begin_define
define|#
directive|define
name|WAND_MATERIALS
value|30
end_define

begin_define
define|#
directive|define
name|GEMS
value|14
end_define

begin_define
define|#
directive|define
name|GOLD_PERCENT
value|46
end_define

begin_define
define|#
directive|define
name|MAX_OPT_LEN
value|40
end_define

begin_struct
struct|struct
name|id
block|{
name|short
name|value
decl_stmt|;
name|char
modifier|*
name|title
decl_stmt|;
name|char
modifier|*
name|real
decl_stmt|;
name|unsigned
name|short
name|id_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The following #defines provide more meaningful names for some of the  * struct object fields that are used for monsters.  This, since each monster  * and object (scrolls, potions, etc) are represented by a struct object.  * Ideally, this should be handled by some kind of union structure.  */
end_comment

begin_define
define|#
directive|define
name|m_damage
value|damage
end_define

begin_define
define|#
directive|define
name|hp_to_kill
value|quantity
end_define

begin_define
define|#
directive|define
name|m_char
value|ichar
end_define

begin_define
define|#
directive|define
name|first_level
value|is_protected
end_define

begin_define
define|#
directive|define
name|last_level
value|is_cursed
end_define

begin_define
define|#
directive|define
name|m_hit_chance
value|class
end_define

begin_define
define|#
directive|define
name|stationary_damage
value|identified
end_define

begin_define
define|#
directive|define
name|drop_percent
value|which_kind
end_define

begin_define
define|#
directive|define
name|trail_char
value|d_enchant
end_define

begin_define
define|#
directive|define
name|slowed_toggle
value|quiver
end_define

begin_define
define|#
directive|define
name|moves_confused
value|hit_enchant
end_define

begin_define
define|#
directive|define
name|nap_length
value|picked_up
end_define

begin_define
define|#
directive|define
name|disguise
value|what_is
end_define

begin_define
define|#
directive|define
name|next_monster
value|next_object
end_define

begin_struct
struct|struct
name|obj
block|{
comment|/* comment is monster meaning */
name|unsigned
name|long
name|m_flags
decl_stmt|;
comment|/* monster flags */
name|char
modifier|*
name|damage
decl_stmt|;
comment|/* damage it does */
name|short
name|quantity
decl_stmt|;
comment|/* hit points to kill */
name|short
name|ichar
decl_stmt|;
comment|/* 'A' is for aquatar */
name|short
name|kill_exp
decl_stmt|;
comment|/* exp for killing it */
name|short
name|is_protected
decl_stmt|;
comment|/* level starts */
name|short
name|is_cursed
decl_stmt|;
comment|/* level ends */
name|short
name|class
decl_stmt|;
comment|/* chance of hitting you */
name|short
name|identified
decl_stmt|;
comment|/* 'F' damage, 1,2,3... */
name|unsigned
name|short
name|which_kind
decl_stmt|;
comment|/* item carry/drop % */
name|short
name|o_row
decl_stmt|,
name|o_col
decl_stmt|,
name|o
decl_stmt|;
comment|/* o is how many times stuck at o_row, o_col */
name|short
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* current row, col */
name|short
name|d_enchant
decl_stmt|;
comment|/* room char when detect_monster */
name|short
name|quiver
decl_stmt|;
comment|/* monster slowed toggle */
name|short
name|trow
decl_stmt|,
name|tcol
decl_stmt|;
comment|/* target row, col */
name|short
name|hit_enchant
decl_stmt|;
comment|/* how many moves is confused */
name|unsigned
name|short
name|what_is
decl_stmt|;
comment|/* imitator's charactor (?!%: */
name|short
name|picked_up
decl_stmt|;
comment|/* sleep from wand of sleep */
name|unsigned
name|short
name|in_use_flags
decl_stmt|;
name|struct
name|obj
modifier|*
name|next_object
decl_stmt|;
comment|/* next monster */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|obj
name|object
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INIT_AW
value|(object*)0,(object*)0
end_define

begin_define
define|#
directive|define
name|INIT_RINGS
value|(object*)0,(object*)0
end_define

begin_define
define|#
directive|define
name|INIT_HP
value|12,12
end_define

begin_define
define|#
directive|define
name|INIT_STR
value|16,16
end_define

begin_define
define|#
directive|define
name|INIT_EXP
value|1,0
end_define

begin_define
define|#
directive|define
name|INIT_PACK
value|{0}
end_define

begin_define
define|#
directive|define
name|INIT_GOLD
value|0
end_define

begin_define
define|#
directive|define
name|INIT_CHAR
value|'@'
end_define

begin_define
define|#
directive|define
name|INIT_MOVES
value|1250
end_define

begin_struct
struct|struct
name|fightr
block|{
name|object
modifier|*
name|armor
decl_stmt|;
name|object
modifier|*
name|weapon
decl_stmt|;
name|object
modifier|*
name|left_ring
decl_stmt|,
modifier|*
name|right_ring
decl_stmt|;
name|short
name|hp_current
decl_stmt|;
name|short
name|hp_max
decl_stmt|;
name|short
name|str_current
decl_stmt|;
name|short
name|str_max
decl_stmt|;
name|object
name|pack
decl_stmt|;
name|long
name|gold
decl_stmt|;
name|short
name|exp
decl_stmt|;
name|long
name|exp_points
decl_stmt|;
name|short
name|row
decl_stmt|,
name|col
decl_stmt|;
name|short
name|fchar
decl_stmt|;
name|short
name|moves_left
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fightr
name|fighter
typedef|;
end_typedef

begin_struct
struct|struct
name|dr
block|{
name|short
name|oth_room
decl_stmt|;
name|short
name|oth_row
decl_stmt|,
name|oth_col
decl_stmt|;
name|short
name|door_row
decl_stmt|,
name|door_col
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|dr
name|door
typedef|;
end_typedef

begin_struct
struct|struct
name|rm
block|{
name|short
name|bottom_row
decl_stmt|,
name|right_col
decl_stmt|,
name|left_col
decl_stmt|,
name|top_row
decl_stmt|;
name|door
name|doors
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|is_room
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rm
name|room
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXROOMS
value|9
end_define

begin_define
define|#
directive|define
name|BIG_ROOM
value|10
end_define

begin_define
define|#
directive|define
name|NO_ROOM
value|-1
end_define

begin_define
define|#
directive|define
name|PASSAGE
value|-3
end_define

begin_comment
comment|/* cur_room value */
end_comment

begin_define
define|#
directive|define
name|AMULET_LEVEL
value|26
end_define

begin_define
define|#
directive|define
name|R_NOTHING
value|((unsigned short) 01)
end_define

begin_define
define|#
directive|define
name|R_ROOM
value|((unsigned short) 02)
end_define

begin_define
define|#
directive|define
name|R_MAZE
value|((unsigned short) 04)
end_define

begin_define
define|#
directive|define
name|R_DEADEND
value|((unsigned short) 010)
end_define

begin_define
define|#
directive|define
name|R_CROSS
value|((unsigned short) 020)
end_define

begin_define
define|#
directive|define
name|MAX_EXP_LEVEL
value|21
end_define

begin_define
define|#
directive|define
name|MAX_EXP
value|10000001L
end_define

begin_define
define|#
directive|define
name|MAX_GOLD
value|999999
end_define

begin_define
define|#
directive|define
name|MAX_ARMOR
value|99
end_define

begin_define
define|#
directive|define
name|MAX_HP
value|999
end_define

begin_define
define|#
directive|define
name|MAX_STRENGTH
value|99
end_define

begin_define
define|#
directive|define
name|LAST_DUNGEON
value|99
end_define

begin_define
define|#
directive|define
name|STAT_LEVEL
value|01
end_define

begin_define
define|#
directive|define
name|STAT_GOLD
value|02
end_define

begin_define
define|#
directive|define
name|STAT_HP
value|04
end_define

begin_define
define|#
directive|define
name|STAT_STRENGTH
value|010
end_define

begin_define
define|#
directive|define
name|STAT_ARMOR
value|020
end_define

begin_define
define|#
directive|define
name|STAT_EXP
value|040
end_define

begin_define
define|#
directive|define
name|STAT_HUNGER
value|0100
end_define

begin_define
define|#
directive|define
name|STAT_LABEL
value|0200
end_define

begin_define
define|#
directive|define
name|STAT_ALL
value|0377
end_define

begin_define
define|#
directive|define
name|PARTY_TIME
value|10
end_define

begin_comment
comment|/* one party somewhere in each 10 level span */
end_comment

begin_define
define|#
directive|define
name|MAX_TRAPS
value|10
end_define

begin_comment
comment|/* maximum traps per level */
end_comment

begin_define
define|#
directive|define
name|HIDE_PERCENT
value|12
end_define

begin_struct
struct|struct
name|tr
block|{
name|short
name|trap_type
decl_stmt|;
name|short
name|trap_row
decl_stmt|,
name|trap_col
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tr
name|trap
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|fighter
name|rogue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|room
name|rooms
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|trap
name|traps
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|dungeon
index|[
name|DROWS
index|]
index|[
name|DCOLS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|object
name|level_objects
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_scrolls
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_potions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_wands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_rings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_weapons
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|id
name|id_armors
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|object
name|mon_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|object
name|level_monsters
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MONSTERS
value|26
end_define

begin_define
define|#
directive|define
name|HASTED
value|01L
end_define

begin_define
define|#
directive|define
name|SLOWED
value|02L
end_define

begin_define
define|#
directive|define
name|INVISIBLE
value|04L
end_define

begin_define
define|#
directive|define
name|ASLEEP
value|010L
end_define

begin_define
define|#
directive|define
name|WAKENS
value|020L
end_define

begin_define
define|#
directive|define
name|WANDERS
value|040L
end_define

begin_define
define|#
directive|define
name|FLIES
value|0100L
end_define

begin_define
define|#
directive|define
name|FLITS
value|0200L
end_define

begin_define
define|#
directive|define
name|CAN_FLIT
value|0400L
end_define

begin_comment
comment|/* can, but usually doesn't, flit */
end_comment

begin_define
define|#
directive|define
name|CONFUSED
value|01000L
end_define

begin_define
define|#
directive|define
name|RUSTS
value|02000L
end_define

begin_define
define|#
directive|define
name|HOLDS
value|04000L
end_define

begin_define
define|#
directive|define
name|FREEZES
value|010000L
end_define

begin_define
define|#
directive|define
name|STEALS_GOLD
value|020000L
end_define

begin_define
define|#
directive|define
name|STEALS_ITEM
value|040000L
end_define

begin_define
define|#
directive|define
name|STINGS
value|0100000L
end_define

begin_define
define|#
directive|define
name|DRAINS_LIFE
value|0200000L
end_define

begin_define
define|#
directive|define
name|DROPS_LEVEL
value|0400000L
end_define

begin_define
define|#
directive|define
name|SEEKS_GOLD
value|01000000L
end_define

begin_define
define|#
directive|define
name|FREEZING_ROGUE
value|02000000L
end_define

begin_define
define|#
directive|define
name|RUST_VANISHED
value|04000000L
end_define

begin_define
define|#
directive|define
name|CONFUSES
value|010000000L
end_define

begin_define
define|#
directive|define
name|IMITATES
value|020000000L
end_define

begin_define
define|#
directive|define
name|FLAMES
value|040000000L
end_define

begin_define
define|#
directive|define
name|STATIONARY
value|0100000000L
end_define

begin_comment
comment|/* damage will be 1,2,3,... */
end_comment

begin_define
define|#
directive|define
name|NAPPING
value|0200000000L
end_define

begin_comment
comment|/* can't wake up for a while */
end_comment

begin_define
define|#
directive|define
name|ALREADY_MOVED
value|0400000000L
end_define

begin_define
define|#
directive|define
name|SPECIAL_HIT
value|(RUSTS|HOLDS|FREEZES|STEALS_GOLD|STEALS_ITEM|STINGS|DRAINS_LIFE|DROPS_LEVEL)
end_define

begin_define
define|#
directive|define
name|WAKE_PERCENT
value|45
end_define

begin_define
define|#
directive|define
name|FLIT_PERCENT
value|40
end_define

begin_define
define|#
directive|define
name|PARTY_WAKE_PERCENT
value|75
end_define

begin_define
define|#
directive|define
name|HYPOTHERMIA
value|1
end_define

begin_define
define|#
directive|define
name|STARVATION
value|2
end_define

begin_define
define|#
directive|define
name|POISON_DART
value|3
end_define

begin_define
define|#
directive|define
name|QUIT
value|4
end_define

begin_define
define|#
directive|define
name|WIN
value|5
end_define

begin_define
define|#
directive|define
name|KFIRE
value|6
end_define

begin_define
define|#
directive|define
name|UPWARD
value|0
end_define

begin_define
define|#
directive|define
name|UPRIGHT
value|1
end_define

begin_define
define|#
directive|define
name|RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|DOWNRIGHT
value|3
end_define

begin_define
define|#
directive|define
name|DOWN
value|4
end_define

begin_define
define|#
directive|define
name|DOWNLEFT
value|5
end_define

begin_define
define|#
directive|define
name|LEFT
value|6
end_define

begin_define
define|#
directive|define
name|UPLEFT
value|7
end_define

begin_define
define|#
directive|define
name|DIRS
value|8
end_define

begin_define
define|#
directive|define
name|ROW1
value|7
end_define

begin_define
define|#
directive|define
name|ROW2
value|15
end_define

begin_define
define|#
directive|define
name|COL1
value|26
end_define

begin_define
define|#
directive|define
name|COL2
value|52
end_define

begin_define
define|#
directive|define
name|MOVED
value|0
end_define

begin_define
define|#
directive|define
name|MOVE_FAILED
value|-1
end_define

begin_define
define|#
directive|define
name|STOPPED_ON_SOMETHING
value|-2
end_define

begin_define
define|#
directive|define
name|CANCEL
value|'\033'
end_define

begin_define
define|#
directive|define
name|LIST
value|'*'
end_define

begin_define
define|#
directive|define
name|HUNGRY
value|300
end_define

begin_define
define|#
directive|define
name|WEAK
value|150
end_define

begin_define
define|#
directive|define
name|FAINT
value|20
end_define

begin_define
define|#
directive|define
name|STARVE
value|0
end_define

begin_define
define|#
directive|define
name|MIN_ROW
value|1
end_define

begin_comment
comment|/* external routine declarations.  */
end_comment

begin_function_decl
name|char
modifier|*
name|mon_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_ench_color
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|name_of
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|md_gln
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|md_getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|md_malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|is_direction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|mon_sees
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|mask_pack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|mask_room
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|is_digit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|check_hunger
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|reg_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|md_df
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|has_been_touched
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|add_to_pack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|alloc_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|get_letter_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|gr_monster
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|get_thrown_at_monster
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|get_zapped_monster
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|check_duplicate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|gr_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|object_at
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|object
modifier|*
name|pick_up
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|id
modifier|*
name|get_id_table
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|gr_what_is
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rrandom
value|random
end_define

begin_define
define|#
directive|define
name|srrandom
parameter_list|(
name|x
parameter_list|)
value|srandomdev()
end_define

begin_function_decl
name|long
name|lget_number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|xxx
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|byebye
argument_list|()
decl_stmt|,
name|onintr
argument_list|()
decl_stmt|,
name|error_save
argument_list|()
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|rogue_time
block|{
name|short
name|year
decl_stmt|;
comment|/*>= 1987 */
name|short
name|month
decl_stmt|;
comment|/* 1 - 12 */
name|short
name|day
decl_stmt|;
comment|/* 1 - 31 */
name|short
name|hour
decl_stmt|;
comment|/* 0 - 23 */
name|short
name|minute
decl_stmt|;
comment|/* 0 - 59 */
name|short
name|second
decl_stmt|;
comment|/* 0 - 59 */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CURSES
end_ifdef

begin_struct
struct|struct
name|_win_st
block|{
name|short
name|_cury
decl_stmt|,
name|_curx
decl_stmt|;
name|short
name|_maxy
decl_stmt|,
name|_maxx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_win_st
name|WINDOW
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|,
name|COLS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|curscr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CL
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|md_gdtcf
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

