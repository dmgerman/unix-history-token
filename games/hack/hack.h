begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/* hack.h - version 1.0.3 */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_define
define|#
directive|define
name|Null
parameter_list|(
name|type
parameter_list|)
value|((struct type *) 0)
end_define

begin_include
include|#
directive|include
file|"def.objclass.h"
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|xchar
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|coord
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"def.monst.h"
end_include

begin_comment
comment|/* uses coord */
end_comment

begin_include
include|#
directive|include
file|"def.gold.h"
end_include

begin_include
include|#
directive|include
file|"def.trap.h"
end_include

begin_include
include|#
directive|include
file|"def.obj.h"
end_include

begin_include
include|#
directive|include
file|"def.flag.h"
end_include

begin_define
define|#
directive|define
name|plur
parameter_list|(
name|x
parameter_list|)
value|(((x) == 1) ? "" : "s")
end_define

begin_define
define|#
directive|define
name|BUFSZ
value|256
end_define

begin_comment
comment|/* for getlin buffers */
end_comment

begin_define
define|#
directive|define
name|PL_NSIZ
value|32
end_define

begin_comment
comment|/* name of player, ghost, shopkeeper */
end_comment

begin_include
include|#
directive|include
file|"def.rm.h"
end_include

begin_include
include|#
directive|include
file|"def.permonst.h"
end_include

begin_function_decl
specifier|extern
name|long
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|xchar
name|xdnstair
decl_stmt|,
name|ydnstair
decl_stmt|,
name|xupstair
decl_stmt|,
name|yupstair
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stairs up and down. */
end_comment

begin_decl_stmt
specifier|extern
name|xchar
name|dlevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|newstring
parameter_list|(
name|x
parameter_list|)
value|(char *) alloc((unsigned)(x))
end_define

begin_include
include|#
directive|include
file|"hack.onames.h"
end_include

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_decl_stmt
specifier|extern
name|struct
name|obj
modifier|*
name|invent
decl_stmt|,
modifier|*
name|uwep
decl_stmt|,
modifier|*
name|uarm
decl_stmt|,
modifier|*
name|uarm2
decl_stmt|,
modifier|*
name|uarmh
decl_stmt|,
modifier|*
name|uarms
decl_stmt|,
modifier|*
name|uarmg
decl_stmt|,
modifier|*
name|uleft
decl_stmt|,
modifier|*
name|uright
decl_stmt|,
modifier|*
name|fcobj
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|obj
modifier|*
name|uchain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined iff PUNISHED */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|obj
modifier|*
name|uball
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined if PUNISHED */
end_comment

begin_decl_stmt
name|struct
name|obj
modifier|*
name|o_at
argument_list|()
decl_stmt|,
modifier|*
name|getobj
argument_list|()
decl_stmt|,
modifier|*
name|sobj_at
argument_list|()
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|prop
block|{
define|#
directive|define
name|TIMEOUT
value|007777
comment|/* mask */
define|#
directive|define
name|LEFT_RING
value|W_RINGL
comment|/* 010000L */
define|#
directive|define
name|RIGHT_RING
value|W_RINGR
comment|/* 020000L */
define|#
directive|define
name|INTRINSIC
value|040000L
define|#
directive|define
name|LEFT_SIDE
value|LEFT_RING
define|#
directive|define
name|RIGHT_SIDE
value|RIGHT_RING
define|#
directive|define
name|BOTH_SIDES
value|(LEFT_SIDE | RIGHT_SIDE)
name|long
name|p_flgs
decl_stmt|;
name|int
function_decl|(
modifier|*
name|p_tofn
function_decl|)
parameter_list|()
function_decl|;
comment|/* called after timeout */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|you
block|{
name|xchar
name|ux
decl_stmt|,
name|uy
decl_stmt|;
name|schar
name|dx
decl_stmt|,
name|dy
decl_stmt|,
name|dz
decl_stmt|;
comment|/* direction of move (or zap or ... ) */
ifdef|#
directive|ifdef
name|QUEST
name|schar
name|di
decl_stmt|;
comment|/* direction of FF */
name|xchar
name|ux0
decl_stmt|,
name|uy0
decl_stmt|;
comment|/* initial position FF */
endif|#
directive|endif
endif|QUEST
name|xchar
name|udisx
decl_stmt|,
name|udisy
decl_stmt|;
comment|/* last display pos */
name|char
name|usym
decl_stmt|;
comment|/* usually '@' */
name|schar
name|uluck
decl_stmt|;
define|#
directive|define
name|LUCKMAX
value|10
comment|/* on moonlit nights 11 */
define|#
directive|define
name|LUCKMIN
value|(-10)
name|int
name|last_str_turn
range|:
literal|3
decl_stmt|;
comment|/* 0: none, 1: half turn, 2: full turn */
comment|/* +: turn right, -: turn left */
name|unsigned
name|udispl
range|:
literal|1
decl_stmt|;
comment|/* @ on display */
name|unsigned
name|ulevel
range|:
literal|4
decl_stmt|;
comment|/* 1 - 14 */
ifdef|#
directive|ifdef
name|QUEST
name|unsigned
name|uhorizon
range|:
literal|7
decl_stmt|;
endif|#
directive|endif
endif|QUEST
name|unsigned
name|utrap
range|:
literal|3
decl_stmt|;
comment|/* trap timeout */
name|unsigned
name|utraptype
range|:
literal|1
decl_stmt|;
comment|/* defined if utrap nonzero */
define|#
directive|define
name|TT_BEARTRAP
value|0
define|#
directive|define
name|TT_PIT
value|1
name|unsigned
name|uinshop
range|:
literal|6
decl_stmt|;
comment|/* used only in shk.c - (roomno+1) of shop */
comment|/* perhaps these #define's should also be generated by makedefs */
define|#
directive|define
name|TELEPAT
value|LAST_RING
comment|/* not a ring */
define|#
directive|define
name|Telepat
value|u.uprops[TELEPAT].p_flgs
define|#
directive|define
name|FAST
value|(LAST_RING+1)
comment|/* not a ring */
define|#
directive|define
name|Fast
value|u.uprops[FAST].p_flgs
define|#
directive|define
name|CONFUSION
value|(LAST_RING+2)
comment|/* not a ring */
define|#
directive|define
name|Confusion
value|u.uprops[CONFUSION].p_flgs
define|#
directive|define
name|INVIS
value|(LAST_RING+3)
comment|/* not a ring */
define|#
directive|define
name|Invis
value|u.uprops[INVIS].p_flgs
define|#
directive|define
name|Invisible
value|(Invis&& !See_invisible)
define|#
directive|define
name|GLIB
value|(LAST_RING+4)
comment|/* not a ring */
define|#
directive|define
name|Glib
value|u.uprops[GLIB].p_flgs
define|#
directive|define
name|PUNISHED
value|(LAST_RING+5)
comment|/* not a ring */
define|#
directive|define
name|Punished
value|u.uprops[PUNISHED].p_flgs
define|#
directive|define
name|SICK
value|(LAST_RING+6)
comment|/* not a ring */
define|#
directive|define
name|Sick
value|u.uprops[SICK].p_flgs
define|#
directive|define
name|BLIND
value|(LAST_RING+7)
comment|/* not a ring */
define|#
directive|define
name|Blind
value|u.uprops[BLIND].p_flgs
define|#
directive|define
name|WOUNDED_LEGS
value|(LAST_RING+8)
comment|/* not a ring */
define|#
directive|define
name|Wounded_legs
value|u.uprops[WOUNDED_LEGS].p_flgs
define|#
directive|define
name|STONED
value|(LAST_RING+9)
comment|/* not a ring */
define|#
directive|define
name|Stoned
value|u.uprops[STONED].p_flgs
define|#
directive|define
name|PROP
parameter_list|(
name|x
parameter_list|)
value|(x-RIN_ADORNMENT)
comment|/* convert ring to index in uprops */
name|unsigned
name|umconf
range|:
literal|1
decl_stmt|;
name|char
modifier|*
name|usick_cause
decl_stmt|;
name|struct
name|prop
name|uprops
index|[
name|LAST_RING
operator|+
literal|10
index|]
decl_stmt|;
name|unsigned
name|uswallow
range|:
literal|1
decl_stmt|;
comment|/* set if swallowed by a monster */
name|unsigned
name|uswldtim
range|:
literal|4
decl_stmt|;
comment|/* time you have been swallowed */
name|unsigned
name|uhs
range|:
literal|3
decl_stmt|;
comment|/* hunger state - see hack.eat.c */
name|schar
name|ustr
decl_stmt|,
name|ustrmax
decl_stmt|;
name|schar
name|udaminc
decl_stmt|;
name|schar
name|uac
decl_stmt|;
name|int
name|uhp
decl_stmt|,
name|uhpmax
decl_stmt|;
name|long
name|int
name|ugold
decl_stmt|,
name|ugold0
decl_stmt|,
name|uexp
decl_stmt|,
name|urexp
decl_stmt|;
name|int
name|uhunger
decl_stmt|;
comment|/* refd only in eat.c and shk.c */
name|int
name|uinvault
decl_stmt|;
name|struct
name|monst
modifier|*
name|ustuck
decl_stmt|;
name|int
name|nr_killed
index|[
name|CMNUM
operator|+
literal|2
index|]
decl_stmt|;
comment|/* used for experience bookkeeping */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|you
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|traps
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|monnam
argument_list|()
decl_stmt|,
modifier|*
name|Monnam
argument_list|()
decl_stmt|,
modifier|*
name|amonnam
argument_list|()
decl_stmt|,
modifier|*
name|Amonnam
argument_list|()
decl_stmt|,
modifier|*
name|doname
argument_list|()
decl_stmt|,
modifier|*
name|aobjnam
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
name|readchar
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|vowels
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xchar
name|curx
decl_stmt|,
name|cury
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cursor location on screen */
end_comment

begin_decl_stmt
specifier|extern
name|coord
name|bhitpos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place where thrown weapon falls to the ground */
end_comment

begin_decl_stmt
specifier|extern
name|xchar
name|seehx
decl_stmt|,
name|seelx
decl_stmt|,
name|seehy
decl_stmt|,
name|seely
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where to see*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|save_cm
decl_stmt|,
modifier|*
name|killer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xchar
name|dlevel
decl_stmt|,
name|maxdlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dungeon level */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|moves
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|multi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|lock
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DIST
parameter_list|(
name|x1
parameter_list|,
name|y1
parameter_list|,
name|x2
parameter_list|,
name|y2
parameter_list|)
value|(((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)))
end_define

begin_define
define|#
directive|define
name|PL_CSIZ
value|20
end_define

begin_comment
comment|/* sizeof pl_character */
end_comment

begin_define
define|#
directive|define
name|MAX_CARR_CAP
value|120
end_define

begin_comment
comment|/* so that boulders can be heavier */
end_comment

begin_define
define|#
directive|define
name|MAXLEVEL
value|40
end_define

begin_define
define|#
directive|define
name|FAR
value|(COLNO+2)
end_define

begin_comment
comment|/* position outside screen */
end_comment

end_unit

