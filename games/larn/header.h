begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	header.h		Larn is copyrighted 1986 by Noah Morgan. */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<termcap.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|MAXLEVEL
value|11
end_define

begin_comment
comment|/*	max # levels in the dungeon			*/
end_comment

begin_define
define|#
directive|define
name|MAXVLEVEL
value|3
end_define

begin_comment
comment|/*	max # of levels in the temple of the luran	*/
end_comment

begin_define
define|#
directive|define
name|MAXX
value|67
end_define

begin_define
define|#
directive|define
name|MAXY
value|17
end_define

begin_define
define|#
directive|define
name|SCORESIZE
value|10
end_define

begin_comment
comment|/*	this is the number of people on a scoreboard max */
end_comment

begin_define
define|#
directive|define
name|MAXPLEVEL
value|100
end_define

begin_comment
comment|/*	maximum player level allowed		*/
end_comment

begin_define
define|#
directive|define
name|MAXMONST
value|56
end_define

begin_comment
comment|/*	maximum # monsters in the dungeon	*/
end_comment

begin_define
define|#
directive|define
name|SPNUM
value|38
end_define

begin_comment
comment|/*	maximum number of spells in existance	*/
end_comment

begin_define
define|#
directive|define
name|MAXSCROLL
value|28
end_define

begin_comment
comment|/*	maximum number of scrolls that are possible	*/
end_comment

begin_define
define|#
directive|define
name|MAXPOTION
value|35
end_define

begin_comment
comment|/*	maximum number of potions that are possible	*/
end_comment

begin_define
define|#
directive|define
name|TIMELIMIT
value|30000
end_define

begin_comment
comment|/*	the maximum number of moves before the game is called */
end_comment

begin_define
define|#
directive|define
name|TAXRATE
value|1/20
end_define

begin_comment
comment|/*	the tax rate for the LRS */
end_comment

begin_define
define|#
directive|define
name|MAXOBJ
value|93
end_define

begin_comment
comment|/* the maximum number of objects   n< MAXOBJ */
end_comment

begin_comment
comment|/*	this is the structure definition of the monster data	*/
end_comment

begin_struct
struct|struct
name|monst
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|level
decl_stmt|;
name|short
name|armorclass
decl_stmt|;
name|char
name|damage
decl_stmt|;
name|char
name|attack
decl_stmt|;
name|char
name|defense
decl_stmt|;
name|char
name|genocided
decl_stmt|;
name|char
name|intelligence
decl_stmt|;
comment|/* monsters intelligence -- used to choose movement */
name|short
name|gold
decl_stmt|;
name|short
name|hitpoints
decl_stmt|;
name|unsigned
name|long
name|experience
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*	this is the structure definition for the items in the dnd store */
end_comment

begin_struct
struct|struct
name|_itm
block|{
name|short
name|price
decl_stmt|;
name|char
modifier|*
modifier|*
name|mem
decl_stmt|;
name|char
name|obj
decl_stmt|;
name|char
name|arg
decl_stmt|;
name|char
name|qty
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*	this is the structure that holds the entire dungeon specifications	*/
end_comment

begin_struct
struct|struct
name|cel
block|{
name|short
name|hitp
decl_stmt|;
comment|/*	monster's hit points	*/
name|char
name|mitem
decl_stmt|;
comment|/*	the monster ID			*/
name|char
name|item
decl_stmt|;
comment|/*	the object's ID			*/
name|short
name|iarg
decl_stmt|;
comment|/*	the object's argument	*/
name|char
name|know
decl_stmt|;
comment|/*	have we been here before*/
block|}
struct|;
end_struct

begin_comment
comment|/* this is the structure for maintaining& moving the spheres of annihilation */
end_comment

begin_struct
struct|struct
name|sphere
block|{
name|struct
name|sphere
modifier|*
name|p
decl_stmt|;
comment|/* pointer to next structure */
name|char
name|x
decl_stmt|,
name|y
decl_stmt|,
name|lev
decl_stmt|;
comment|/* location of the sphere */
name|char
name|dir
decl_stmt|;
comment|/* direction sphere is going in */
name|char
name|lifetime
decl_stmt|;
comment|/* duration of the sphere */
block|}
struct|;
end_struct

begin_comment
comment|/*	defines for the character attribute array	c[]	*/
end_comment

begin_define
define|#
directive|define
name|STRENGTH
value|0
end_define

begin_comment
comment|/* characters physical strength not due to objects */
end_comment

begin_define
define|#
directive|define
name|INTELLIGENCE
value|1
end_define

begin_define
define|#
directive|define
name|WISDOM
value|2
end_define

begin_define
define|#
directive|define
name|CONSTITUTION
value|3
end_define

begin_define
define|#
directive|define
name|DEXTERITY
value|4
end_define

begin_define
define|#
directive|define
name|CHARISMA
value|5
end_define

begin_define
define|#
directive|define
name|HPMAX
value|6
end_define

begin_define
define|#
directive|define
name|HP
value|7
end_define

begin_define
define|#
directive|define
name|GOLD
value|8
end_define

begin_define
define|#
directive|define
name|EXPERIENCE
value|9
end_define

begin_define
define|#
directive|define
name|LEVEL
value|10
end_define

begin_define
define|#
directive|define
name|REGEN
value|11
end_define

begin_define
define|#
directive|define
name|WCLASS
value|12
end_define

begin_define
define|#
directive|define
name|AC
value|13
end_define

begin_define
define|#
directive|define
name|BANKACCOUNT
value|14
end_define

begin_define
define|#
directive|define
name|SPELLMAX
value|15
end_define

begin_define
define|#
directive|define
name|SPELLS
value|16
end_define

begin_define
define|#
directive|define
name|ENERGY
value|17
end_define

begin_define
define|#
directive|define
name|ECOUNTER
value|18
end_define

begin_define
define|#
directive|define
name|MOREDEFENSES
value|19
end_define

begin_define
define|#
directive|define
name|WEAR
value|20
end_define

begin_define
define|#
directive|define
name|PROTECTIONTIME
value|21
end_define

begin_define
define|#
directive|define
name|WIELD
value|22
end_define

begin_define
define|#
directive|define
name|AMULET
value|23
end_define

begin_define
define|#
directive|define
name|REGENCOUNTER
value|24
end_define

begin_define
define|#
directive|define
name|MOREDAM
value|25
end_define

begin_define
define|#
directive|define
name|DEXCOUNT
value|26
end_define

begin_define
define|#
directive|define
name|STRCOUNT
value|27
end_define

begin_define
define|#
directive|define
name|BLINDCOUNT
value|28
end_define

begin_define
define|#
directive|define
name|CAVELEVEL
value|29
end_define

begin_define
define|#
directive|define
name|CONFUSE
value|30
end_define

begin_define
define|#
directive|define
name|ALTPRO
value|31
end_define

begin_define
define|#
directive|define
name|HERO
value|32
end_define

begin_define
define|#
directive|define
name|CHARMCOUNT
value|33
end_define

begin_define
define|#
directive|define
name|INVISIBILITY
value|34
end_define

begin_define
define|#
directive|define
name|CANCELLATION
value|35
end_define

begin_define
define|#
directive|define
name|HASTESELF
value|36
end_define

begin_define
define|#
directive|define
name|EYEOFLARN
value|37
end_define

begin_define
define|#
directive|define
name|AGGRAVATE
value|38
end_define

begin_define
define|#
directive|define
name|GLOBE
value|39
end_define

begin_define
define|#
directive|define
name|TELEFLAG
value|40
end_define

begin_define
define|#
directive|define
name|SLAYING
value|41
end_define

begin_define
define|#
directive|define
name|NEGATESPIRIT
value|42
end_define

begin_define
define|#
directive|define
name|SCAREMONST
value|43
end_define

begin_define
define|#
directive|define
name|AWARENESS
value|44
end_define

begin_define
define|#
directive|define
name|HOLDMONST
value|45
end_define

begin_define
define|#
directive|define
name|TIMESTOP
value|46
end_define

begin_define
define|#
directive|define
name|HASTEMONST
value|47
end_define

begin_define
define|#
directive|define
name|CUBEofUNDEAD
value|48
end_define

begin_define
define|#
directive|define
name|GIANTSTR
value|49
end_define

begin_define
define|#
directive|define
name|FIRERESISTANCE
value|50
end_define

begin_define
define|#
directive|define
name|BESSMANN
value|51
end_define

begin_define
define|#
directive|define
name|NOTHEFT
value|52
end_define

begin_define
define|#
directive|define
name|HARDGAME
value|53
end_define

begin_define
define|#
directive|define
name|CPUTIME
value|54
end_define

begin_define
define|#
directive|define
name|BYTESIN
value|55
end_define

begin_define
define|#
directive|define
name|BYTESOUT
value|56
end_define

begin_define
define|#
directive|define
name|MOVESMADE
value|57
end_define

begin_define
define|#
directive|define
name|MONSTKILLED
value|58
end_define

begin_define
define|#
directive|define
name|SPELLSCAST
value|59
end_define

begin_define
define|#
directive|define
name|LANCEDEATH
value|60
end_define

begin_define
define|#
directive|define
name|SPIRITPRO
value|61
end_define

begin_define
define|#
directive|define
name|UNDEADPRO
value|62
end_define

begin_define
define|#
directive|define
name|SHIELD
value|63
end_define

begin_define
define|#
directive|define
name|STEALTH
value|64
end_define

begin_define
define|#
directive|define
name|ITCHING
value|65
end_define

begin_define
define|#
directive|define
name|LAUGHING
value|66
end_define

begin_define
define|#
directive|define
name|DRAINSTRENGTH
value|67
end_define

begin_define
define|#
directive|define
name|CLUMSINESS
value|68
end_define

begin_define
define|#
directive|define
name|INFEEBLEMENT
value|69
end_define

begin_define
define|#
directive|define
name|HALFDAM
value|70
end_define

begin_define
define|#
directive|define
name|SEEINVISIBLE
value|71
end_define

begin_define
define|#
directive|define
name|FILLROOM
value|72
end_define

begin_define
define|#
directive|define
name|RANDOMWALK
value|73
end_define

begin_define
define|#
directive|define
name|SPHCAST
value|74
end_define

begin_comment
comment|/* nz if an active sphere of annihilation */
end_comment

begin_define
define|#
directive|define
name|WTW
value|75
end_define

begin_comment
comment|/* walk through walls */
end_comment

begin_define
define|#
directive|define
name|STREXTRA
value|76
end_define

begin_comment
comment|/* character strength due to objects or enchantments */
end_comment

begin_define
define|#
directive|define
name|TMP
value|77
end_define

begin_comment
comment|/* misc scratch space */
end_comment

begin_define
define|#
directive|define
name|LIFEPROT
value|78
end_define

begin_comment
comment|/* life protection counter */
end_comment

begin_comment
comment|/*	defines for the objects in the game		*/
end_comment

begin_define
define|#
directive|define
name|OALTAR
value|1
end_define

begin_define
define|#
directive|define
name|OTHRONE
value|2
end_define

begin_define
define|#
directive|define
name|OORB
value|3
end_define

begin_define
define|#
directive|define
name|OPIT
value|4
end_define

begin_define
define|#
directive|define
name|OSTAIRSUP
value|5
end_define

begin_define
define|#
directive|define
name|OELEVATORUP
value|6
end_define

begin_define
define|#
directive|define
name|OFOUNTAIN
value|7
end_define

begin_define
define|#
directive|define
name|OSTATUE
value|8
end_define

begin_define
define|#
directive|define
name|OTELEPORTER
value|9
end_define

begin_define
define|#
directive|define
name|OSCHOOL
value|10
end_define

begin_define
define|#
directive|define
name|OMIRROR
value|11
end_define

begin_define
define|#
directive|define
name|ODNDSTORE
value|12
end_define

begin_define
define|#
directive|define
name|OSTAIRSDOWN
value|13
end_define

begin_define
define|#
directive|define
name|OELEVATORDOWN
value|14
end_define

begin_define
define|#
directive|define
name|OBANK2
value|15
end_define

begin_define
define|#
directive|define
name|OBANK
value|16
end_define

begin_define
define|#
directive|define
name|ODEADFOUNTAIN
value|17
end_define

begin_define
define|#
directive|define
name|OMAXGOLD
value|70
end_define

begin_define
define|#
directive|define
name|OGOLDPILE
value|18
end_define

begin_define
define|#
directive|define
name|OOPENDOOR
value|19
end_define

begin_define
define|#
directive|define
name|OCLOSEDDOOR
value|20
end_define

begin_define
define|#
directive|define
name|OWALL
value|21
end_define

begin_define
define|#
directive|define
name|OTRAPARROW
value|66
end_define

begin_define
define|#
directive|define
name|OTRAPARROWIV
value|67
end_define

begin_define
define|#
directive|define
name|OLARNEYE
value|22
end_define

begin_define
define|#
directive|define
name|OPLATE
value|23
end_define

begin_define
define|#
directive|define
name|OCHAIN
value|24
end_define

begin_define
define|#
directive|define
name|OLEATHER
value|25
end_define

begin_define
define|#
directive|define
name|ORING
value|60
end_define

begin_define
define|#
directive|define
name|OSTUDLEATHER
value|61
end_define

begin_define
define|#
directive|define
name|OSPLINT
value|62
end_define

begin_define
define|#
directive|define
name|OPLATEARMOR
value|63
end_define

begin_define
define|#
directive|define
name|OSSPLATE
value|64
end_define

begin_define
define|#
directive|define
name|OSHIELD
value|68
end_define

begin_define
define|#
directive|define
name|OELVENCHAIN
value|92
end_define

begin_define
define|#
directive|define
name|OSWORDofSLASHING
value|26
end_define

begin_define
define|#
directive|define
name|OHAMMER
value|27
end_define

begin_define
define|#
directive|define
name|OSWORD
value|28
end_define

begin_define
define|#
directive|define
name|O2SWORD
value|29
end_define

begin_define
define|#
directive|define
name|OSPEAR
value|30
end_define

begin_define
define|#
directive|define
name|ODAGGER
value|31
end_define

begin_define
define|#
directive|define
name|OBATTLEAXE
value|57
end_define

begin_define
define|#
directive|define
name|OLONGSWORD
value|58
end_define

begin_define
define|#
directive|define
name|OFLAIL
value|59
end_define

begin_define
define|#
directive|define
name|OLANCE
value|65
end_define

begin_define
define|#
directive|define
name|OVORPAL
value|90
end_define

begin_define
define|#
directive|define
name|OSLAYER
value|91
end_define

begin_define
define|#
directive|define
name|ORINGOFEXTRA
value|32
end_define

begin_define
define|#
directive|define
name|OREGENRING
value|33
end_define

begin_define
define|#
directive|define
name|OPROTRING
value|34
end_define

begin_define
define|#
directive|define
name|OENERGYRING
value|35
end_define

begin_define
define|#
directive|define
name|ODEXRING
value|36
end_define

begin_define
define|#
directive|define
name|OSTRRING
value|37
end_define

begin_define
define|#
directive|define
name|OCLEVERRING
value|38
end_define

begin_define
define|#
directive|define
name|ODAMRING
value|39
end_define

begin_define
define|#
directive|define
name|OBELT
value|40
end_define

begin_define
define|#
directive|define
name|OSCROLL
value|41
end_define

begin_define
define|#
directive|define
name|OPOTION
value|42
end_define

begin_define
define|#
directive|define
name|OBOOK
value|43
end_define

begin_define
define|#
directive|define
name|OCHEST
value|44
end_define

begin_define
define|#
directive|define
name|OAMULET
value|45
end_define

begin_define
define|#
directive|define
name|OORBOFDRAGON
value|46
end_define

begin_define
define|#
directive|define
name|OSPIRITSCARAB
value|47
end_define

begin_define
define|#
directive|define
name|OCUBEofUNDEAD
value|48
end_define

begin_define
define|#
directive|define
name|ONOTHEFT
value|49
end_define

begin_define
define|#
directive|define
name|ODIAMOND
value|50
end_define

begin_define
define|#
directive|define
name|ORUBY
value|51
end_define

begin_define
define|#
directive|define
name|OEMERALD
value|52
end_define

begin_define
define|#
directive|define
name|OSAPPHIRE
value|53
end_define

begin_define
define|#
directive|define
name|OENTRANCE
value|54
end_define

begin_define
define|#
directive|define
name|OVOLDOWN
value|55
end_define

begin_define
define|#
directive|define
name|OVOLUP
value|56
end_define

begin_define
define|#
directive|define
name|OHOME
value|69
end_define

begin_define
define|#
directive|define
name|OKGOLD
value|71
end_define

begin_define
define|#
directive|define
name|ODGOLD
value|72
end_define

begin_define
define|#
directive|define
name|OIVDARTRAP
value|73
end_define

begin_define
define|#
directive|define
name|ODARTRAP
value|74
end_define

begin_define
define|#
directive|define
name|OTRAPDOOR
value|75
end_define

begin_define
define|#
directive|define
name|OIVTRAPDOOR
value|76
end_define

begin_define
define|#
directive|define
name|OTRADEPOST
value|77
end_define

begin_define
define|#
directive|define
name|OIVTELETRAP
value|78
end_define

begin_define
define|#
directive|define
name|ODEADTHRONE
value|79
end_define

begin_define
define|#
directive|define
name|OANNIHILATION
value|80
end_define

begin_comment
comment|/* sphere of annihilation */
end_comment

begin_define
define|#
directive|define
name|OTHRONE2
value|81
end_define

begin_define
define|#
directive|define
name|OLRS
value|82
end_define

begin_comment
comment|/* Larn Revenue Service */
end_comment

begin_define
define|#
directive|define
name|OCOOKIE
value|83
end_define

begin_define
define|#
directive|define
name|OURN
value|84
end_define

begin_define
define|#
directive|define
name|OBRASSLAMP
value|85
end_define

begin_define
define|#
directive|define
name|OHANDofFEAR
value|86
end_define

begin_comment
comment|/* hand of fear */
end_comment

begin_define
define|#
directive|define
name|OSPHTAILSMAN
value|87
end_define

begin_comment
comment|/* tailsman of the sphere */
end_comment

begin_define
define|#
directive|define
name|OWWAND
value|88
end_define

begin_comment
comment|/* wand of wonder */
end_comment

begin_define
define|#
directive|define
name|OPSTAFF
value|89
end_define

begin_comment
comment|/* staff of power */
end_comment

begin_comment
comment|/* used up to 92 */
end_comment

begin_comment
comment|/*	defines for the monsters as objects		*/
end_comment

begin_define
define|#
directive|define
name|BAT
value|1
end_define

begin_define
define|#
directive|define
name|GNOME
value|2
end_define

begin_define
define|#
directive|define
name|HOBGOBLIN
value|3
end_define

begin_define
define|#
directive|define
name|JACKAL
value|4
end_define

begin_define
define|#
directive|define
name|KOBOLD
value|5
end_define

begin_define
define|#
directive|define
name|ORC
value|6
end_define

begin_define
define|#
directive|define
name|SNAKE
value|7
end_define

begin_define
define|#
directive|define
name|CENTIPEDE
value|8
end_define

begin_define
define|#
directive|define
name|JACULI
value|9
end_define

begin_define
define|#
directive|define
name|TROGLODYTE
value|10
end_define

begin_define
define|#
directive|define
name|ANT
value|11
end_define

begin_define
define|#
directive|define
name|EYE
value|12
end_define

begin_define
define|#
directive|define
name|LEPRECHAUN
value|13
end_define

begin_define
define|#
directive|define
name|NYMPH
value|14
end_define

begin_define
define|#
directive|define
name|QUASIT
value|15
end_define

begin_define
define|#
directive|define
name|RUSTMONSTER
value|16
end_define

begin_define
define|#
directive|define
name|ZOMBIE
value|17
end_define

begin_define
define|#
directive|define
name|ASSASSINBUG
value|18
end_define

begin_define
define|#
directive|define
name|BUGBEAR
value|19
end_define

begin_define
define|#
directive|define
name|HELLHOUND
value|20
end_define

begin_define
define|#
directive|define
name|ICELIZARD
value|21
end_define

begin_define
define|#
directive|define
name|CENTAUR
value|22
end_define

begin_define
define|#
directive|define
name|TROLL
value|23
end_define

begin_define
define|#
directive|define
name|YETI
value|24
end_define

begin_define
define|#
directive|define
name|WHITEDRAGON
value|25
end_define

begin_define
define|#
directive|define
name|ELF
value|26
end_define

begin_define
define|#
directive|define
name|CUBE
value|27
end_define

begin_define
define|#
directive|define
name|METAMORPH
value|28
end_define

begin_define
define|#
directive|define
name|VORTEX
value|29
end_define

begin_define
define|#
directive|define
name|ZILLER
value|30
end_define

begin_define
define|#
directive|define
name|VIOLETFUNGI
value|31
end_define

begin_define
define|#
directive|define
name|WRAITH
value|32
end_define

begin_define
define|#
directive|define
name|FORVALAKA
value|33
end_define

begin_define
define|#
directive|define
name|LAMANOBE
value|34
end_define

begin_define
define|#
directive|define
name|OSEQUIP
value|35
end_define

begin_define
define|#
directive|define
name|ROTHE
value|36
end_define

begin_define
define|#
directive|define
name|XORN
value|37
end_define

begin_define
define|#
directive|define
name|VAMPIRE
value|38
end_define

begin_define
define|#
directive|define
name|INVISIBLESTALKER
value|39
end_define

begin_define
define|#
directive|define
name|POLTERGEIST
value|40
end_define

begin_define
define|#
directive|define
name|DISENCHANTRESS
value|41
end_define

begin_define
define|#
directive|define
name|SHAMBLINGMOUND
value|42
end_define

begin_define
define|#
directive|define
name|YELLOWMOLD
value|43
end_define

begin_define
define|#
directive|define
name|UMBERHULK
value|44
end_define

begin_define
define|#
directive|define
name|GNOMEKING
value|45
end_define

begin_define
define|#
directive|define
name|MIMIC
value|46
end_define

begin_define
define|#
directive|define
name|WATERLORD
value|47
end_define

begin_define
define|#
directive|define
name|BRONZEDRAGON
value|48
end_define

begin_define
define|#
directive|define
name|GREENDRAGON
value|49
end_define

begin_define
define|#
directive|define
name|PURPLEWORM
value|50
end_define

begin_define
define|#
directive|define
name|XVART
value|51
end_define

begin_define
define|#
directive|define
name|SPIRITNAGA
value|52
end_define

begin_define
define|#
directive|define
name|SILVERDRAGON
value|53
end_define

begin_define
define|#
directive|define
name|PLATINUMDRAGON
value|54
end_define

begin_define
define|#
directive|define
name|GREENURCHIN
value|55
end_define

begin_define
define|#
directive|define
name|REDDRAGON
value|56
end_define

begin_define
define|#
directive|define
name|DEMONLORD
value|57
end_define

begin_define
define|#
directive|define
name|DEMONPRINCE
value|64
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|BUFBIG
value|4096
end_define

begin_comment
comment|/* size of the output buffer */
end_comment

begin_define
define|#
directive|define
name|MAXIBUF
value|4096
end_define

begin_comment
comment|/* size of the input buffer */
end_comment

begin_define
define|#
directive|define
name|LOGNAMESIZE
value|40
end_define

begin_comment
comment|/* max size of the players name */
end_comment

begin_define
define|#
directive|define
name|PSNAMESIZE
value|40
end_define

begin_comment
comment|/* max size of the process name */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODEFS
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|VERSION
decl_stmt|,
name|SUBVERSION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|aborted
index|[]
decl_stmt|,
name|alpha
index|[]
decl_stmt|,
name|beenhere
index|[]
decl_stmt|,
name|boldon
decl_stmt|,
name|cheat
decl_stmt|,
name|ckpfile
index|[]
decl_stmt|,
name|ckpflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|class
index|[]
decl_stmt|,
name|course
index|[]
decl_stmt|,
name|diagfile
index|[]
decl_stmt|,
name|fortfile
index|[]
decl_stmt|,
name|helpfile
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|inbuffer
decl_stmt|,
name|is_alpha
index|[]
decl_stmt|,
name|is_digit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|item
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|iven
index|[]
decl_stmt|,
name|know
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|larnlevels
index|[]
decl_stmt|,
name|lastmonst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|level
decl_stmt|,
modifier|*
name|levelname
index|[]
decl_stmt|,
name|logfile
index|[]
decl_stmt|,
name|loginname
index|[]
decl_stmt|,
name|logname
index|[]
decl_stmt|,
modifier|*
name|lpbuf
decl_stmt|,
modifier|*
name|lpend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lpnt
decl_stmt|,
name|moved
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|mitem
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|monstlevel
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|monstnamelist
index|[]
decl_stmt|,
name|nch
index|[]
decl_stmt|,
name|ndgg
index|[]
decl_stmt|,
name|nlpts
index|[]
decl_stmt|,
name|nomove
decl_stmt|,
name|nosignal
decl_stmt|,
name|nowelcome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|nplt
index|[]
decl_stmt|,
name|nsw
index|[]
decl_stmt|,
modifier|*
name|objectname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|objnamelist
index|[]
decl_stmt|,
name|optsfile
index|[]
decl_stmt|,
modifier|*
name|potionname
index|[]
decl_stmt|,
name|playerids
index|[]
decl_stmt|,
name|potprob
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|predostuff
decl_stmt|,
name|psname
index|[]
decl_stmt|,
name|restorflag
decl_stmt|,
name|savefilename
index|[]
decl_stmt|,
name|scorefile
index|[]
decl_stmt|,
name|scprob
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|screen
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
modifier|*
name|scrollname
index|[]
decl_stmt|,
name|sex
decl_stmt|,
modifier|*
name|spelcode
index|[]
decl_stmt|,
modifier|*
name|speldescript
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|spelknow
index|[]
decl_stmt|,
modifier|*
name|spelname
index|[]
decl_stmt|,
modifier|*
name|spelmes
index|[]
decl_stmt|,
name|spelweird
index|[
name|MAXMONST
operator|+
literal|8
index|]
index|[
name|SPNUM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|splev
index|[]
decl_stmt|,
name|stealth
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|to_lower
index|[]
decl_stmt|,
name|to_upper
index|[]
decl_stmt|,
name|wizard
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|diroffx
index|[]
decl_stmt|,
name|diroffy
index|[]
decl_stmt|,
name|hitflag
decl_stmt|,
name|hit2flag
decl_stmt|,
name|hit3flag
decl_stmt|,
name|hitp
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|iarg
index|[
name|MAXX
index|]
index|[
name|MAXY
index|]
decl_stmt|,
name|ivenarg
index|[]
decl_stmt|,
name|lasthx
decl_stmt|,
name|lasthy
decl_stmt|,
name|lastnum
decl_stmt|,
name|lastpx
decl_stmt|,
name|lastpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|nobeep
decl_stmt|,
name|oldx
decl_stmt|,
name|oldy
decl_stmt|,
name|playerx
decl_stmt|,
name|playery
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dayplay
decl_stmt|,
name|enable_scroll
decl_stmt|,
name|srcount
decl_stmt|,
name|yrepcount
decl_stmt|,
name|userid
decl_stmt|,
name|wisid
decl_stmt|,
name|lfd
decl_stmt|,
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|initialtime
decl_stmt|,
name|outstanding_taxes
decl_stmt|,
name|skill
index|[]
decl_stmt|,
name|gtime
decl_stmt|,
name|c
index|[]
decl_stmt|,
name|cbak
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cel
modifier|*
name|cell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|monst
name|monster
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sphere
modifier|*
name|spheres
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_itm
name|itm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fortune
argument_list|()
decl_stmt|,
modifier|*
name|lgetw
argument_list|()
decl_stmt|,
modifier|*
name|lgetl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|tmcapcnv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|paytaxes
argument_list|()
decl_stmt|,
name|lgetc
argument_list|()
decl_stmt|,
name|lrint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|unsigned
name|long
name|readnum
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* macro to create scroll #'s with probability of occurrence */
end_comment

begin_define
define|#
directive|define
name|newscroll
parameter_list|()
value|(scprob[rund(81)])
end_define

begin_comment
comment|/* macro to return a potion # created with probability of occurrence */
end_comment

begin_define
define|#
directive|define
name|newpotion
parameter_list|()
value|(potprob[rund(41)])
end_define

begin_comment
comment|/* macro to return the + points on created leather armor */
end_comment

begin_define
define|#
directive|define
name|newleather
parameter_list|()
value|(nlpts[rund(c[HARDGAME]?13:15)])
end_define

begin_comment
comment|/* macro to return the + points on chain armor */
end_comment

begin_define
define|#
directive|define
name|newchain
parameter_list|()
value|(nch[rund(10)])
end_define

begin_comment
comment|/* macro to return + points on plate armor */
end_comment

begin_define
define|#
directive|define
name|newplate
parameter_list|()
value|(nplt[rund(c[HARDGAME]?4:12)])
end_define

begin_comment
comment|/* macro to return + points on new daggers */
end_comment

begin_define
define|#
directive|define
name|newdagger
parameter_list|()
value|(ndgg[rund(13)])
end_define

begin_comment
comment|/* macro to return + points on new swords */
end_comment

begin_define
define|#
directive|define
name|newsword
parameter_list|()
value|(nsw[rund(c[HARDGAME]?6:13)])
end_define

begin_comment
comment|/* macro to destroy object at present location */
end_comment

begin_define
define|#
directive|define
name|forget
parameter_list|()
value|(item[playerx][playery]=know[playerx][playery]=0)
end_define

begin_comment
comment|/* macro to wipe out a monster at a location */
end_comment

begin_define
define|#
directive|define
name|disappear
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(mitem[x][y]=know[x][y]=0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VT100
end_ifdef

begin_comment
comment|/* macro to turn on bold display for the terminal */
end_comment

begin_define
define|#
directive|define
name|setbold
parameter_list|()
value|(lprcat(boldon?"\33[1m":"\33[7m"))
end_define

begin_comment
comment|/* macro to turn off bold display for the terminal */
end_comment

begin_define
define|#
directive|define
name|resetbold
parameter_list|()
value|(lprcat("\33[m"))
end_define

begin_comment
comment|/* macro to setup the scrolling region for the terminal */
end_comment

begin_define
define|#
directive|define
name|setscroll
parameter_list|()
value|(lprcat("\33[20;24r"))
end_define

begin_comment
comment|/* macro to clear the scrolling region for the terminal */
end_comment

begin_define
define|#
directive|define
name|resetscroll
parameter_list|()
value|(lprcat("\33[;24r"))
end_define

begin_comment
comment|/* macro to clear the screen and home the cursor */
end_comment

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|(lprcat("\33[2J\33[f"), cbak[SPELLS]= -50)
end_define

begin_define
define|#
directive|define
name|cltoeoln
parameter_list|()
value|lprcat("\33[K")
end_define

begin_else
else|#
directive|else
else|VT100
end_else

begin_comment
comment|/* defines below are for use in the termcap mode only */
end_comment

begin_define
define|#
directive|define
name|ST_START
value|1
end_define

begin_define
define|#
directive|define
name|ST_END
value|2
end_define

begin_define
define|#
directive|define
name|BOLD
value|3
end_define

begin_define
define|#
directive|define
name|END_BOLD
value|4
end_define

begin_define
define|#
directive|define
name|CLEAR
value|5
end_define

begin_define
define|#
directive|define
name|CL_LINE
value|6
end_define

begin_define
define|#
directive|define
name|CL_DOWN
value|14
end_define

begin_define
define|#
directive|define
name|CURSOR
value|15
end_define

begin_comment
comment|/* macro to turn on bold display for the terminal */
end_comment

begin_define
define|#
directive|define
name|setbold
parameter_list|()
value|(*lpnt++ = ST_START)
end_define

begin_comment
comment|/* macro to turn off bold display for the terminal */
end_comment

begin_define
define|#
directive|define
name|resetbold
parameter_list|()
value|(*lpnt++ = ST_END)
end_define

begin_comment
comment|/* macro to setup the scrolling region for the terminal */
end_comment

begin_define
define|#
directive|define
name|setscroll
parameter_list|()
value|enable_scroll=1
end_define

begin_comment
comment|/* macro to clear the scrolling region for the terminal */
end_comment

begin_define
define|#
directive|define
name|resetscroll
parameter_list|()
value|enable_scroll=0
end_define

begin_comment
comment|/* macro to clear the screen and home the cursor */
end_comment

begin_define
define|#
directive|define
name|clear
parameter_list|()
value|(*lpnt++ =CLEAR, cbak[SPELLS]= -50)
end_define

begin_comment
comment|/* macro to clear to end of line */
end_comment

begin_define
define|#
directive|define
name|cltoeoln
parameter_list|()
value|(*lpnt++ = CL_LINE)
end_define

begin_endif
endif|#
directive|endif
endif|VT100
end_endif

begin_comment
comment|/* macro to output one byte to the output buffer */
end_comment

begin_define
define|#
directive|define
name|lprc
parameter_list|(
name|ch
parameter_list|)
value|((lpnt>=lpend)?(*lpnt++ =(ch), lflush()):(*lpnt++ =(ch)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MACRORND
end_ifdef

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|randx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* macro to seed the random number generator */
end_comment

begin_define
define|#
directive|define
name|srand
parameter_list|(
name|x
parameter_list|)
value|(randx=x)
end_define

begin_comment
comment|/* macros to generate random numbers   1<=rnd(N)<=N   0<=rund(N)<=N-1 */
end_comment

begin_define
define|#
directive|define
name|rnd
parameter_list|(
name|x
parameter_list|)
value|((((randx=randx*1103515245+12345)>>7)%(x))+1)
end_define

begin_define
define|#
directive|define
name|rund
parameter_list|(
name|x
parameter_list|)
value|((((randx=randx*1103515245+12345)>>7)%(x))  )
end_define

begin_endif
endif|#
directive|endif
endif|MACRORND
end_endif

begin_comment
comment|/* macros for miscellaneous data conversion */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)>(y))?(y):(x))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)>(y))?(x):(y))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|x
parameter_list|)
value|(is_alpha[x])
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|x
parameter_list|)
value|(is_digit[x])
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|x
parameter_list|)
value|(to_lower[x])
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|x
parameter_list|)
value|(to_upper[x])
end_define

begin_define
define|#
directive|define
name|lcc
parameter_list|(
name|x
parameter_list|)
value|(to_lower[x])
end_define

begin_define
define|#
directive|define
name|ucc
parameter_list|(
name|x
parameter_list|)
value|(to_upper[x])
end_define

begin_endif
endif|#
directive|endif
endif|NODEFS
end_endif

end_unit

