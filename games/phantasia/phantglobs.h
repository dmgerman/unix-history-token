begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * phantglobs.h - global declarations for Phantasia  */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|Circle
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which circle player is in			*/
end_comment

begin_decl_stmt
specifier|extern
name|double
name|Shield
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force field thrown up in monster battle	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Beyond
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is beyond point of no return	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Marsh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is in dead marshes		*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Throne
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is on throne			*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Changed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if important player stats have changed	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Wizard
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if player is the 'wizard' of the game	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Timeout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if short timeout waiting for input	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Windows
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we are set up for curses stuff	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Luckout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if we have tried to luck out in fight	*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Foestrikes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if foe gets a chance to hit in battleplayer()*/
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Echo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if echo input to terminal		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Users
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of users currently playing		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Whichmonster
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which monster we are fighting		*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line on screen counter for fight routines	*/
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|Fightenv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to jump into fight routine		*/
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|Timeoenv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used for timing out waiting for input	*/
end_comment

begin_decl_stmt
specifier|extern
name|long
name|Fileloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location in file of player statistics	*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Login
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to login of current player		*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Enemyname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer name of monster/player we are battling*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|player
name|Player
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for player				*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|player
name|Other
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for another player			*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|monster
name|Curmonster
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stats for current monster			*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|energyvoid
name|Enrgyvoid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* energy void buffer			*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|charstats
name|Stattable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used for rolling and changing player stats*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|charstats
modifier|*
name|Statptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into Stattable[]			*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|menuitem
name|Menu
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* menu of items for purchase			*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Playersfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open player file			*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Monstfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open monster file			*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Messagefp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open message file			*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|Energyvoidfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to open energy void file		*/
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Databuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a place to read data into			*/
end_comment

begin_comment
comment|/* some canned strings for messages */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Illcmd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Illmove
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Illspell
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Nomana
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Somebetter
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Nobetter
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* library functions and system calls */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpass
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* functions which we need to know about */
end_comment

begin_function_decl
specifier|extern
name|int
name|interrupt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ill_sig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|catchalarm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|recallplayer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|findname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|allocrecord
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|rollnewplayer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|allocvoid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|drandom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|distance
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|infloat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|explevel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|descrlocation
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|descrtype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|descrstatus
parameter_list|()
function_decl|;
end_function_decl

end_unit

