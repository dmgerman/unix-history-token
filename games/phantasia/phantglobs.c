begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * phantglobs.c - globals for Phantasia  */
end_comment

begin_include
include|#
directive|include
file|"include.h"
end_include

begin_decl_stmt
name|double
name|Circle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which circle player is in			*/
end_comment

begin_decl_stmt
name|double
name|Shield
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force field thrown up in monster battle	*/
end_comment

begin_decl_stmt
name|bool
name|Beyond
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is beyond point of no return	*/
end_comment

begin_decl_stmt
name|bool
name|Marsh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is in dead marshes		*/
end_comment

begin_decl_stmt
name|bool
name|Throne
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is on throne			*/
end_comment

begin_decl_stmt
name|bool
name|Changed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if important player stats have changed	*/
end_comment

begin_decl_stmt
name|bool
name|Wizard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is the 'wizard' of the game	*/
end_comment

begin_decl_stmt
name|bool
name|Timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if short timeout waiting for input	*/
end_comment

begin_decl_stmt
name|bool
name|Windows
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we are set up for curses stuff	*/
end_comment

begin_decl_stmt
name|bool
name|Luckout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we have tried to luck out in fight	*/
end_comment

begin_decl_stmt
name|bool
name|Foestrikes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if foe gets a chance to hit in battleplayer()	*/
end_comment

begin_decl_stmt
name|bool
name|Echo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if echo input to terminal		*/
end_comment

begin_decl_stmt
name|int
name|Users
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of users currently playing		*/
end_comment

begin_decl_stmt
name|int
name|Whichmonster
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which monster we are fighting		*/
end_comment

begin_decl_stmt
name|int
name|Lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line on screen counter for fight routines	*/
end_comment

begin_decl_stmt
name|jmp_buf
name|Fightenv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to jump into fight routine		*/
end_comment

begin_decl_stmt
name|jmp_buf
name|Timeoenv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used for timing out waiting for input	*/
end_comment

begin_decl_stmt
name|long
name|Fileloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location in file of player statistics	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|Login
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to login of player			*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|Enemyname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer name of monster/player we are battling*/
end_comment

begin_decl_stmt
name|struct
name|player
name|Player
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for player				*/
end_comment

begin_decl_stmt
name|struct
name|player
name|Other
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for another player			*/
end_comment

begin_decl_stmt
name|struct
name|monster
name|Curmonster
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for current monster			*/
end_comment

begin_decl_stmt
name|struct
name|energyvoid
name|Enrgyvoid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* energy void buffer			*/
end_comment

begin_decl_stmt
name|struct
name|charstats
modifier|*
name|Statptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into Stattable[]			*/
end_comment

begin_comment
comment|/* lookup table for character type dependent statistics */
end_comment

begin_decl_stmt
name|struct
name|charstats
name|Stattable
index|[
literal|7
index|]
init|=
block|{
comment|/* MAGIC USER */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|15.0
block|,
literal|200.0
block|,
literal|18.0
block|,
literal|175.0
block|,
literal|10
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|30
block|,
literal|6
block|,
literal|0.0
block|,
literal|10
block|,
literal|6
block|,
literal|2.0
block|,
literal|50
block|,
literal|51
block|,
literal|75.0
block|,
literal|30
block|,
literal|16
block|,
literal|20.0
block|,
literal|60
block|,
literal|26
block|,
literal|6.0
block|,
literal|5
block|,
literal|5
block|,
literal|2.75
block|,
comment|/* FIGHTER */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|10.0
block|,
literal|110.0
block|,
literal|15.0
block|,
literal|220.0
block|,
literal|20
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|30
block|,
literal|6
block|,
literal|0.0
block|,
literal|40
block|,
literal|16
block|,
literal|3.0
block|,
literal|30
block|,
literal|21
block|,
literal|40.0
block|,
literal|45
block|,
literal|26
block|,
literal|30.0
block|,
literal|25
block|,
literal|21
block|,
literal|3.0
block|,
literal|3
block|,
literal|4
block|,
literal|1.5
block|,
comment|/* ELF */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|12.0
block|,
literal|150.0
block|,
literal|17.0
block|,
literal|190.0
block|,
literal|13
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|32
block|,
literal|7
block|,
literal|0.0
block|,
literal|35
block|,
literal|11
block|,
literal|2.5
block|,
literal|45
block|,
literal|46
block|,
literal|65.0
block|,
literal|30
block|,
literal|21
block|,
literal|25.0
block|,
literal|40
block|,
literal|26
block|,
literal|4.0
block|,
literal|4
block|,
literal|4
block|,
literal|2.0
block|,
comment|/* DWARF */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|7.0
block|,
literal|80.0
block|,
literal|13.0
block|,
literal|255.0
block|,
literal|25
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|25
block|,
literal|6
block|,
literal|0.0
block|,
literal|50
block|,
literal|21
block|,
literal|5.0
block|,
literal|25
block|,
literal|21
block|,
literal|30.0
block|,
literal|60
block|,
literal|41
block|,
literal|35.0
block|,
literal|20
block|,
literal|21
block|,
literal|2.5
block|,
literal|2
block|,
literal|4
block|,
literal|1.0
block|,
comment|/* HALFLING */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|11.0
block|,
literal|80.0
block|,
literal|10.0
block|,
literal|125.0
block|,
literal|40
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|34
block|,
literal|0
block|,
literal|0.0
block|,
literal|20
block|,
literal|6
block|,
literal|2.0
block|,
literal|25
block|,
literal|21
block|,
literal|30.0
block|,
literal|55
block|,
literal|36
block|,
literal|30.0
block|,
literal|40
block|,
literal|36
block|,
literal|4.5
block|,
literal|1
block|,
literal|4
block|,
literal|1.0
block|,
comment|/* EXPERIMENTO */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|9.0
block|,
literal|90.0
block|,
literal|16.0
block|,
literal|160.0
block|,
literal|20
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|27
block|,
literal|0
block|,
literal|0.0
block|,
literal|25
block|,
literal|0
block|,
literal|0.0
block|,
literal|100
block|,
literal|0
block|,
literal|0.0
block|,
literal|35
block|,
literal|0
block|,
literal|0.0
block|,
literal|25
block|,
literal|0
block|,
literal|0.0
block|,
literal|2
block|,
literal|0
block|,
literal|0.0
block|,
comment|/* SUPER */
comment|/* max brains, max mana, weakness, gold tote, ring duration */
literal|15.0
block|,
literal|200.0
block|,
literal|10.0
block|,
literal|225.0
block|,
literal|40
block|,
comment|/* quickness strength     mana         energy       brains       magic lvl */
literal|38
block|,
literal|0
block|,
literal|0.0
block|,
literal|65
block|,
literal|0
block|,
literal|5.0
block|,
literal|100
block|,
literal|0
block|,
literal|75.0
block|,
literal|80
block|,
literal|0
block|,
literal|35.0
block|,
literal|85
block|,
literal|0
block|,
literal|6.0
block|,
literal|9
block|,
literal|0
block|,
literal|2.75
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* menu of items for purchase */
end_comment

begin_decl_stmt
name|struct
name|menuitem
name|Menu
index|[]
init|=
block|{
literal|"Mana"
block|,
literal|1
block|,
literal|"Shield"
block|,
literal|5
block|,
literal|"Book"
block|,
literal|200
block|,
literal|"Sword"
block|,
literal|500
block|,
literal|"Charm"
block|,
literal|1000
block|,
literal|"Quicksilver"
block|,
literal|2500
block|,
literal|"Blessing"
block|,
literal|1000
block|,     }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|Playersfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open player file			*/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Monstfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open monster file			*/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Messagefp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open message file			*/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Energyvoidfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open energy void file		*/
end_comment

begin_decl_stmt
name|char
name|Databuf
index|[
name|SZ_DATABUF
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a place to read data into		*/
end_comment

begin_comment
comment|/* some canned strings for messages */
end_comment

begin_decl_stmt
name|char
name|Illcmd
index|[]
init|=
literal|"Illegal command.\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Illmove
index|[]
init|=
literal|"Too far.\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Illspell
index|[]
init|=
literal|"Illegal spell.\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Nomana
index|[]
init|=
literal|"Not enought mana for that spell.\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Somebetter
index|[]
init|=
literal|"But you already have something better.\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Nobetter
index|[]
init|=
literal|"That's no better than what you already have.\n"
decl_stmt|;
end_decl_stmt

end_unit

