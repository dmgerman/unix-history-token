begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * phantdefs.h - important constants for Phantasia  */
end_comment

begin_comment
comment|/* ring constants */
end_comment

begin_define
define|#
directive|define
name|R_NONE
value|0
end_define

begin_comment
comment|/* no ring */
end_comment

begin_define
define|#
directive|define
name|R_NAZREG
value|1
end_define

begin_comment
comment|/* regular Nazgul ring (expires) */
end_comment

begin_define
define|#
directive|define
name|R_DLREG
value|2
end_define

begin_comment
comment|/* regular Dark Lord ring (does not expire) */
end_comment

begin_define
define|#
directive|define
name|R_BAD
value|3
end_define

begin_comment
comment|/* bad ring */
end_comment

begin_define
define|#
directive|define
name|R_SPOILED
value|4
end_define

begin_comment
comment|/* ring which has gone bad */
end_comment

begin_comment
comment|/* status constants */
end_comment

begin_define
define|#
directive|define
name|S_NOTUSED
value|0
end_define

begin_comment
comment|/* record not in use */
end_comment

begin_define
define|#
directive|define
name|S_OFF
value|1
end_define

begin_comment
comment|/* not playing */
end_comment

begin_define
define|#
directive|define
name|S_PLAYING
value|2
end_define

begin_comment
comment|/* playing - nothing else */
end_comment

begin_define
define|#
directive|define
name|S_CLOAKED
value|3
end_define

begin_comment
comment|/* playing - cloaked */
end_comment

begin_define
define|#
directive|define
name|S_INBATTLE
value|4
end_define

begin_comment
comment|/* playing - in battle */
end_comment

begin_define
define|#
directive|define
name|S_MONSTER
value|5
end_define

begin_comment
comment|/* playing - fighting monster */
end_comment

begin_define
define|#
directive|define
name|S_TRADING
value|6
end_define

begin_comment
comment|/* playing - at a trading post */
end_comment

begin_define
define|#
directive|define
name|S_HUNGUP
value|7
end_define

begin_comment
comment|/* error occured with character */
end_comment

begin_comment
comment|/* tampered constants */
end_comment

begin_define
define|#
directive|define
name|T_OFF
value|0
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|T_NRGVOID
value|1
end_define

begin_comment
comment|/* hit an energy void */
end_comment

begin_define
define|#
directive|define
name|T_GRAIL
value|2
end_define

begin_comment
comment|/* landed on the holy grail */
end_comment

begin_define
define|#
directive|define
name|T_TRANSPORT
value|3
end_define

begin_comment
comment|/* transported by king */
end_comment

begin_define
define|#
directive|define
name|T_BESTOW
value|4
end_define

begin_comment
comment|/* gold bestowed by king */
end_comment

begin_define
define|#
directive|define
name|T_CURSED
value|5
end_define

begin_comment
comment|/* cursed by king */
end_comment

begin_define
define|#
directive|define
name|T_MONSTER
value|6
end_define

begin_comment
comment|/* monster lobbed by valar */
end_comment

begin_define
define|#
directive|define
name|T_BLESSED
value|7
end_define

begin_comment
comment|/* blessed by valar */
end_comment

begin_define
define|#
directive|define
name|T_RELOCATE
value|8
end_define

begin_comment
comment|/* moved by valar */
end_comment

begin_define
define|#
directive|define
name|T_HEAL
value|9
end_define

begin_comment
comment|/* healed by valar */
end_comment

begin_define
define|#
directive|define
name|T_VAPORIZED
value|10
end_define

begin_comment
comment|/* vaporized by wizard */
end_comment

begin_define
define|#
directive|define
name|T_EXVALAR
value|11
end_define

begin_comment
comment|/* no longer valar */
end_comment

begin_comment
comment|/* inter-terminal battle status constants */
end_comment

begin_define
define|#
directive|define
name|I_OFF
value|0
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|I_RAN
value|1
end_define

begin_comment
comment|/* ran away */
end_comment

begin_define
define|#
directive|define
name|I_STUCK
value|2
end_define

begin_comment
comment|/* tried to run unsuccessfully */
end_comment

begin_define
define|#
directive|define
name|I_BLEWIT
value|3
end_define

begin_comment
comment|/* tried to luckout unsuccessfully */
end_comment

begin_define
define|#
directive|define
name|I_KILLED
value|4
end_define

begin_comment
comment|/* killed foe */
end_comment

begin_comment
comment|/* constants for altering coordinates */
end_comment

begin_define
define|#
directive|define
name|A_SPECIFIC
value|0
end_define

begin_comment
comment|/* coordinates specified */
end_comment

begin_define
define|#
directive|define
name|A_FORCED
value|1
end_define

begin_comment
comment|/* coordinates specified, ignore Beyond */
end_comment

begin_define
define|#
directive|define
name|A_NEAR
value|2
end_define

begin_comment
comment|/* coordinates not specified, move near */
end_comment

begin_define
define|#
directive|define
name|A_FAR
value|3
end_define

begin_comment
comment|/* coordinates not specified, move far */
end_comment

begin_comment
comment|/* constants for character types */
end_comment

begin_define
define|#
directive|define
name|C_MAGIC
value|0
end_define

begin_comment
comment|/* magic user */
end_comment

begin_define
define|#
directive|define
name|C_FIGHTER
value|1
end_define

begin_comment
comment|/* fighter */
end_comment

begin_define
define|#
directive|define
name|C_ELF
value|2
end_define

begin_comment
comment|/* elf */
end_comment

begin_define
define|#
directive|define
name|C_DWARF
value|3
end_define

begin_comment
comment|/* dwarf */
end_comment

begin_define
define|#
directive|define
name|C_HALFLING
value|4
end_define

begin_comment
comment|/* halfling */
end_comment

begin_define
define|#
directive|define
name|C_EXPER
value|5
end_define

begin_comment
comment|/* experimento */
end_comment

begin_define
define|#
directive|define
name|C_SUPER
value|6
end_define

begin_comment
comment|/* super being */
end_comment

begin_comment
comment|/* constants for special character types */
end_comment

begin_define
define|#
directive|define
name|SC_NONE
value|0
end_define

begin_comment
comment|/* not a special character */
end_comment

begin_define
define|#
directive|define
name|SC_KING
value|1
end_define

begin_comment
comment|/* king */
end_comment

begin_define
define|#
directive|define
name|SC_COUNCIL
value|2
end_define

begin_comment
comment|/* council of the wise */
end_comment

begin_define
define|#
directive|define
name|SC_VALAR
value|3
end_define

begin_comment
comment|/* valar */
end_comment

begin_define
define|#
directive|define
name|SC_EXVALAR
value|4
end_define

begin_comment
comment|/* ex-valar */
end_comment

begin_comment
comment|/* special monster constants */
end_comment

begin_define
define|#
directive|define
name|SM_NONE
value|0
end_define

begin_comment
comment|/* nothing special */
end_comment

begin_define
define|#
directive|define
name|SM_UNICORN
value|1
end_define

begin_comment
comment|/* unicorn */
end_comment

begin_define
define|#
directive|define
name|SM_MODNAR
value|2
end_define

begin_comment
comment|/* Modnar */
end_comment

begin_define
define|#
directive|define
name|SM_MIMIC
value|3
end_define

begin_comment
comment|/* mimic */
end_comment

begin_define
define|#
directive|define
name|SM_DARKLORD
value|4
end_define

begin_comment
comment|/* Dark Lord */
end_comment

begin_define
define|#
directive|define
name|SM_LEANAN
value|5
end_define

begin_comment
comment|/* Leanan-Sidhe */
end_comment

begin_define
define|#
directive|define
name|SM_SARUMAN
value|6
end_define

begin_comment
comment|/* Saruman */
end_comment

begin_define
define|#
directive|define
name|SM_THAUMATURG
value|7
end_define

begin_comment
comment|/* thaumaturgist */
end_comment

begin_define
define|#
directive|define
name|SM_BALROG
value|8
end_define

begin_comment
comment|/* balrog */
end_comment

begin_define
define|#
directive|define
name|SM_VORTEX
value|9
end_define

begin_comment
comment|/* vortex */
end_comment

begin_define
define|#
directive|define
name|SM_NAZGUL
value|10
end_define

begin_comment
comment|/* nazgul */
end_comment

begin_define
define|#
directive|define
name|SM_TIAMAT
value|11
end_define

begin_comment
comment|/* Tiamat */
end_comment

begin_define
define|#
directive|define
name|SM_KOBOLD
value|12
end_define

begin_comment
comment|/* kobold */
end_comment

begin_define
define|#
directive|define
name|SM_SHELOB
value|13
end_define

begin_comment
comment|/* Shelob */
end_comment

begin_define
define|#
directive|define
name|SM_FAERIES
value|14
end_define

begin_comment
comment|/* assorted faeries */
end_comment

begin_define
define|#
directive|define
name|SM_LAMPREY
value|15
end_define

begin_comment
comment|/* lamprey */
end_comment

begin_define
define|#
directive|define
name|SM_SHRIEKER
value|16
end_define

begin_comment
comment|/* shrieker */
end_comment

begin_define
define|#
directive|define
name|SM_BONNACON
value|17
end_define

begin_comment
comment|/* bonnacon */
end_comment

begin_define
define|#
directive|define
name|SM_SMEAGOL
value|18
end_define

begin_comment
comment|/* Smeagol */
end_comment

begin_define
define|#
directive|define
name|SM_SUCCUBUS
value|19
end_define

begin_comment
comment|/* succubus */
end_comment

begin_define
define|#
directive|define
name|SM_CERBERUS
value|20
end_define

begin_comment
comment|/* Cerberus */
end_comment

begin_define
define|#
directive|define
name|SM_UNGOLIANT
value|21
end_define

begin_comment
comment|/* Ungoliant */
end_comment

begin_define
define|#
directive|define
name|SM_JABBERWOCK
value|22
end_define

begin_comment
comment|/* jabberwock */
end_comment

begin_define
define|#
directive|define
name|SM_MORGOTH
value|23
end_define

begin_comment
comment|/* Morgoth */
end_comment

begin_define
define|#
directive|define
name|SM_TROLL
value|24
end_define

begin_comment
comment|/* troll */
end_comment

begin_define
define|#
directive|define
name|SM_WRAITH
value|25
end_define

begin_comment
comment|/* wraith */
end_comment

begin_comment
comment|/* constants for spells */
end_comment

begin_define
define|#
directive|define
name|ML_ALLORNOTHING
value|0.0
end_define

begin_comment
comment|/* magic level for 'all or nothing' */
end_comment

begin_define
define|#
directive|define
name|MM_ALLORNOTHING
value|1.0
end_define

begin_comment
comment|/* mana used for 'all or nothing' */
end_comment

begin_define
define|#
directive|define
name|ML_MAGICBOLT
value|5.0
end_define

begin_comment
comment|/* magic level for 'magic bolt' */
end_comment

begin_define
define|#
directive|define
name|ML_FORCEFIELD
value|15.0
end_define

begin_comment
comment|/* magic level for 'force field' */
end_comment

begin_define
define|#
directive|define
name|MM_FORCEFIELD
value|30.0
end_define

begin_comment
comment|/* mana used for 'force field' */
end_comment

begin_define
define|#
directive|define
name|ML_XFORM
value|25.0
end_define

begin_comment
comment|/* magic level for 'transform' */
end_comment

begin_define
define|#
directive|define
name|MM_XFORM
value|50.0
end_define

begin_comment
comment|/* mana used for 'transform' */
end_comment

begin_define
define|#
directive|define
name|ML_INCRMIGHT
value|35.0
end_define

begin_comment
comment|/* magic level for 'increase might' */
end_comment

begin_define
define|#
directive|define
name|MM_INCRMIGHT
value|75.0
end_define

begin_comment
comment|/* mana used for 'increase might' */
end_comment

begin_define
define|#
directive|define
name|ML_INVISIBLE
value|45.0
end_define

begin_comment
comment|/* magic level for 'invisibility' */
end_comment

begin_define
define|#
directive|define
name|MM_INVISIBLE
value|90.0
end_define

begin_comment
comment|/* mana used for 'invisibility' */
end_comment

begin_define
define|#
directive|define
name|ML_XPORT
value|60.0
end_define

begin_comment
comment|/* magic level for 'transport' */
end_comment

begin_define
define|#
directive|define
name|MM_XPORT
value|125.0
end_define

begin_comment
comment|/* mana used for 'transport' */
end_comment

begin_define
define|#
directive|define
name|ML_PARALYZE
value|75.0
end_define

begin_comment
comment|/* magic level for 'paralyze' */
end_comment

begin_define
define|#
directive|define
name|MM_PARALYZE
value|150.0
end_define

begin_comment
comment|/* mana used for 'paralyze' */
end_comment

begin_define
define|#
directive|define
name|MM_SPECIFY
value|1000.0
end_define

begin_comment
comment|/* mana used for 'specify' */
end_comment

begin_define
define|#
directive|define
name|ML_CLOAK
value|20.0
end_define

begin_comment
comment|/* magic level for 'cloak' */
end_comment

begin_define
define|#
directive|define
name|MEL_CLOAK
value|7.0
end_define

begin_comment
comment|/* experience level for 'cloak' */
end_comment

begin_define
define|#
directive|define
name|MM_CLOAK
value|35.0
end_define

begin_comment
comment|/* mana used for 'cloak' */
end_comment

begin_define
define|#
directive|define
name|ML_TELEPORT
value|40.0
end_define

begin_comment
comment|/* magic level for 'teleport' */
end_comment

begin_define
define|#
directive|define
name|MEL_TELEPORT
value|12.0
end_define

begin_comment
comment|/* experience level for 'teleport' */
end_comment

begin_define
define|#
directive|define
name|MM_INTERVENE
value|1000.0
end_define

begin_comment
comment|/* mana used to 'intervene' */
end_comment

begin_comment
comment|/* some miscellaneous constants */
end_comment

begin_define
define|#
directive|define
name|SZ_DATABUF
value|100
end_define

begin_comment
comment|/* size of input buffer */
end_comment

begin_define
define|#
directive|define
name|SZ_PLAYERSTRUCT
value|sizeof(struct player)
end_define

begin_comment
comment|/* size of player structure */
end_comment

begin_define
define|#
directive|define
name|SZ_VOIDSTRUCT
value|sizeof(struct energyvoid)
end_define

begin_comment
comment|/* size of energy void struct */
end_comment

begin_define
define|#
directive|define
name|SZ_SCORESTRUCT
value|sizeof(struct scoreboard)
end_define

begin_comment
comment|/* size of score board entry */
end_comment

begin_define
define|#
directive|define
name|SZ_MONSTERSTRUCT
value|sizeof(struct monster)
end_define

begin_comment
comment|/* size of monster structure */
end_comment

begin_define
define|#
directive|define
name|SZ_NAME
value|21
end_define

begin_comment
comment|/* size of player name (incl. trailing nul) */
end_comment

begin_define
define|#
directive|define
name|SZ_PASSWORD
value|9
end_define

begin_comment
comment|/* size of password (incl. trailing nul) */
end_comment

begin_define
define|#
directive|define
name|SZ_LOGIN
value|9
end_define

begin_comment
comment|/* size of login (incl. trailing nul) */
end_comment

begin_define
define|#
directive|define
name|N_DAYSOLD
value|21
end_define

begin_comment
comment|/* number of days old for purge */
end_comment

begin_define
define|#
directive|define
name|N_AGE
value|500
end_define

begin_comment
comment|/* age to degenerate ratio */
end_comment

begin_define
define|#
directive|define
name|N_GEMVALUE
value|(1000.0)
end_define

begin_comment
comment|/* number of gold pieces to gem ratio */
end_comment

begin_define
define|#
directive|define
name|N_TAXAMOUNT
value|(7.0)
end_define

begin_comment
comment|/* tax percent */
end_comment

begin_define
define|#
directive|define
name|D_BEYOND
value|(1.1e6)
end_define

begin_comment
comment|/* distance to beyond point of no return */
end_comment

begin_define
define|#
directive|define
name|D_EXPER
value|(2000.0)
end_define

begin_comment
comment|/* distance experimentos are allowed */
end_comment

begin_define
define|#
directive|define
name|CH_MARKDELETE
value|'\001'
end_define

begin_comment
comment|/* used to alter name of deleted players */
end_comment

begin_define
define|#
directive|define
name|CH_KILL
value|'\030'
end_define

begin_comment
comment|/* kill character (ctrl-X) */
end_comment

begin_define
define|#
directive|define
name|CH_ERASE
value|'\010'
end_define

begin_comment
comment|/* erase character (ctrl-H) */
end_comment

begin_define
define|#
directive|define
name|CH_NEWLINE
value|'\n'
end_define

begin_comment
comment|/* newline */
end_comment

begin_define
define|#
directive|define
name|CH_REDRAW
value|'\014'
end_define

begin_comment
comment|/* redraw screen character (ctrl-L) */
end_comment

end_unit

