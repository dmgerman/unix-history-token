begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)main.c	1.2	%G%  *  * Main program for the SUN Gremlin picture editor.  *  * Many of the routines in SUN Gremlin are direct descendants of  * their counterparts in the original Gremlin written for the AED  * by Barry Roitblat.  *  * Mark Opperman (opcode@monet.BERKELEY)  *  */
end_comment

begin_include
include|#
directive|include
file|<suntool/tool_hs.h>
end_include

begin_include
include|#
directive|include
file|<suntool/fullscreen.h>
end_include

begin_include
include|#
directive|include
file|<suntool/menu.h>
end_include

begin_include
include|#
directive|include
file|<suntool/wmgr.h>
end_include

begin_include
include|#
directive|include
file|<sunwindow/cms.h>
end_include

begin_include
include|#
directive|include
file|<sunwindow/win_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sun/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"gremlin.h"
end_include

begin_include
include|#
directive|include
file|"icondata.h"
end_include

begin_define
define|#
directive|define
name|RETAIN
value|TRUE
end_define

begin_comment
comment|/* use retained subwindow for pix_sw */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|maybefaster
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|_image
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_bytesperline
decl_stmt|,
name|_maxx
decl_stmt|,
name|_maxy
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* database imports */
end_comment

begin_function_decl
specifier|extern
name|ELT
modifier|*
name|DBRead
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|POINT
modifier|*
name|PTMakePoint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|POpen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* imports from startup.c */
end_comment

begin_extern
extern|extern STERROR;
end_extern

begin_extern
extern|extern STgremlinrc(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from menu.c */
end_comment

begin_extern
extern|extern MNDisplayMenu(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern MNInitMenu(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* graphics imports */
end_comment

begin_extern
extern|extern GRBlankGrid(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRCurrentSet(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRCurrentSetOn(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRDisplayGrid(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern GRFontInit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from undodb.c */
end_comment

begin_extern
extern|extern UNForget(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|UNELT
modifier|*
name|unlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UNELT
modifier|*
name|unback
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* imports from long.c */
end_comment

begin_extern
extern|extern SHOWPOINTS;
end_extern

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Editfile
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern CP(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern LGQuit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern nop(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from short.c */
end_comment

begin_extern
extern|extern SHCommand(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern SHUpdate(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from C */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sprintf
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

begin_comment
comment|/* imports from strings.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|GLibrary
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declaration of Globals */
end_comment

begin_decl_stmt
name|ELT
name|arhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ELT
modifier|*
name|cset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ELT
modifier|*
name|MEN
index|[
name|NUSER
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ELT
modifier|*
name|PICTURE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|POINT
modifier|*
name|BACKPOINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|POINT
name|MENPOINT
index|[
name|NUSER
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|POINT
modifier|*
name|POINTLIST
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Artmode
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Adjustment
init|=
name|NOADJ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Alignment
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CBRUSH
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CFONT
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CJUST
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CSIZE
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CSTIPPLE
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GravityOn
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Gridon
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Gridsize
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Orientation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SEQ
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|CHANGED
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SEARCH
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SymbolicLines
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|newfileformat
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1=sungremlinfile, 0=gremlinfile */
end_comment

begin_decl_stmt
name|int
name|TOOLINSTALLED
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|lastcommand
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* last command's routine pointer */
end_comment

begin_decl_stmt
name|int
name|lasttext
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if last command uses text */
end_comment

begin_decl_stmt
name|float
name|PX
decl_stmt|,
name|PY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user point coordinate */
end_comment

begin_decl_stmt
name|float
name|Lastx
decl_stmt|,
name|Lasty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last user point coordinate */
end_comment

begin_decl_stmt
name|long
name|timeon_ms
init|=
literal|580
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current set flash on period */
end_comment

begin_decl_stmt
name|long
name|timeon_s
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|timeoff_ms
init|=
literal|180
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current set flash off period */
end_comment

begin_decl_stmt
name|long
name|timeoff_s
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|FLASH_READY
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if time to flash current set */
end_comment

begin_decl_stmt
name|int
name|CsetOn
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if current set displayed */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|itimerval
name|itime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for ALARM signals */
end_comment

begin_expr_stmt
specifier|static
name|alrm_sighandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|SUN_XORIGIN
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* top left corner in gremlin coords */
end_comment

begin_decl_stmt
name|int
name|SUN_YORIGIN
init|=
literal|511
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|SccsId
index|[]
init|=
literal|"@(#)main.c	1.2   (Berkeley)      %G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* imports from menu.c */
end_comment

begin_extern
extern|extern menu_left(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern menu_middle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern menu_right(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern menu_winexit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern mouse_move(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from pix.c */
end_comment

begin_extern
extern|extern pix_left(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern pix_middle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern pix_right(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern pix_winexit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* imports from suntext.c */
end_comment

begin_extern
extern|extern text_left(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_middle(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_right(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_winexit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_putvalue(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern text_output(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern TxInit(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern TxPutMsg(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|cursor
name|kbd_cursor
init|=
block|{
literal|4
block|,
literal|8
block|,
name|PIX_SRC
operator|^
name|PIX_DST
block|,
operator|&
name|kbdcursor_pr
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cursor
name|main_cursor
init|=
block|{
literal|0
block|,
literal|0
block|,
name|PIX_SRC
operator|^
name|PIX_DST
block|,
operator|&
name|uparrow_pr
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cursor
name|menu_cursor
init|=
block|{
literal|3
block|,
literal|3
block|,
name|PIX_SRC
operator|^
name|PIX_DST
block|,
operator|&
name|diamond_pr
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|icon
name|gremlin_icon
init|=
block|{
name|TOOL_ICONWIDTH
block|,
name|TOOL_ICONHEIGHT
block|,
name|NULL
block|,
block|{
literal|0
block|,
literal|0
block|,
name|TOOL_ICONWIDTH
block|,
name|TOOL_ICONHEIGHT
block|}
block|,
operator|&
name|gremlin_icon_pr
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tool window stuff */
end_comment

begin_define
define|#
directive|define
name|DEV_FB
value|"/dev/fb"
end_define

begin_decl_stmt
name|struct
name|tool
modifier|*
name|tool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rect
name|tool_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tool_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rootfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|namestripe
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|tool_selected
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|init_tool
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|sigwinched
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* for handling tool manager menu */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|menu
modifier|*
name|wmgr_toolmenu
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|menuitem
modifier|*
name|menu_display
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* text subwindow */
end_comment

begin_decl_stmt
name|struct
name|toolsw
modifier|*
name|text_sw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixwin
modifier|*
name|text_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rect
name|text_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|text_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixfont
modifier|*
name|text_pf
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|init_text
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|text_selected
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|text_sighandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* menu subwindow */
end_comment

begin_decl_stmt
name|struct
name|toolsw
modifier|*
name|menu_sw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixwin
modifier|*
name|menu_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rect
name|menu_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|menu_fd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|init_menu
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|menu_selected
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|menu_sighandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pix subwindow */
end_comment

begin_decl_stmt
name|struct
name|toolsw
modifier|*
name|pix_sw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixwin
modifier|*
name|pix_pw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rect
name|pix_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pix_fd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|init_pix
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|pix_selected
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|pix_sighandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|pixrect
modifier|*
name|cset_pr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixrect
modifier|*
name|scratch_pr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pixrect
modifier|*
name|retained_pr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This routine prints an error message in the text subwindow.  */
end_comment

begin_macro
name|error
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|TxPutMsg
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|char
modifier|*
name|arg
decl_stmt|,
modifier|*
name|file
decl_stmt|,
modifier|*
name|gremlinrc
decl_stmt|,
modifier|*
name|usage
decl_stmt|;
name|file
operator|=
literal|""
expr_stmt|;
name|gremlinrc
operator|=
literal|""
expr_stmt|;
name|usage
operator|=
literal|"usage: gremlin [-o] [-s<.gremlinrc>] [file]\n"
expr_stmt|;
while|while
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
block|{
name|arg
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
operator|*
name|arg
operator|!=
literal|'-'
condition|)
name|file
operator|=
name|arg
expr_stmt|;
else|else
block|{
switch|switch
condition|(
operator|*
operator|++
name|arg
condition|)
block|{
case|case
literal|'s'
case|:
if|if
condition|(
operator|*
operator|++
name|arg
operator|==
literal|'\0'
condition|)
if|if
condition|(
operator|--
name|argc
operator|>
literal|0
condition|)
name|arg
operator|=
operator|*
operator|++
name|argv
expr_stmt|;
if|if
condition|(
name|argc
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|usage
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|gremlinrc
operator|=
name|arg
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|newfileformat
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|usage
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|strcpy
argument_list|(
name|namestripe
argument_list|,
name|version
argument_list|)
expr_stmt|;
name|tool
operator|=
name|tool_create
argument_list|(
name|namestripe
argument_list|,
name|TOOL_NAMESTRIPE
argument_list|,
operator|(
expr|struct
name|rect
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|gremlin_icon
comment|/*(struct icon *) NULL*/
argument_list|)
expr_stmt|;
if|if
condition|(
name|tool
operator|==
operator|(
expr|struct
name|tool
operator|*
operator|)
name|NULL
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|text_sw
operator|=
name|tool_createsubwindow
argument_list|(
name|tool
argument_list|,
literal|"text_sw"
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|,
name|TEXTSW_HEIGHT
argument_list|)
expr_stmt|;
name|menu_sw
operator|=
name|tool_createsubwindow
argument_list|(
name|tool
argument_list|,
literal|"menu_sw"
argument_list|,
name|MENUSW_WIDTH
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|)
expr_stmt|;
name|pix_sw
operator|=
name|tool_createsubwindow
argument_list|(
name|tool
argument_list|,
literal|"pix_sw"
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|,
name|TOOL_SWEXTENDTOEDGE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|text_sw
operator|==
operator|(
expr|struct
name|toolsw
operator|*
operator|)
name|NULL
operator|)
operator|||
operator|(
name|menu_sw
operator|==
operator|(
expr|struct
name|toolsw
operator|*
operator|)
name|NULL
operator|)
operator|||
operator|(
name|pix_sw
operator|==
operator|(
expr|struct
name|toolsw
operator|*
operator|)
name|NULL
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"error creating subwindows\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|init_tool
argument_list|()
expr_stmt|;
name|init_text
argument_list|()
expr_stmt|;
name|init_menu
argument_list|()
expr_stmt|;
name|init_pix
argument_list|()
expr_stmt|;
comment|/* set up gremlin variables */
name|main_init
argument_list|(
name|file
argument_list|,
name|gremlinrc
argument_list|)
expr_stmt|;
comment|/* install tool in tree of windows */
name|signal
argument_list|(
name|SIGWINCH
argument_list|,
name|sigwinched
argument_list|)
expr_stmt|;
name|tool_install
argument_list|(
name|tool
argument_list|)
expr_stmt|;
name|TOOLINSTALLED
operator|=
literal|1
expr_stmt|;
comment|/* if current set flash off period non-zero, set up SIGALRM */
if|if
condition|(
operator|(
name|timeoff_ms
operator|!=
literal|0l
operator|)
operator|||
operator|(
name|timeoff_s
operator|!=
literal|0l
operator|)
condition|)
block|{
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|alrm_sighandler
argument_list|)
expr_stmt|;
name|itime
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|timeon_s
expr_stmt|;
name|itime
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|timeon_ms
operator|*
literal|1000
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itime
argument_list|,
operator|(
expr|struct
name|itimerval
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
block|}
comment|/* handle input */
name|tool_select
argument_list|(
name|tool
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* cleanup */
name|tool_destroy
argument_list|(
name|tool
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set input mask for the tool border.  */
end_comment

begin_expr_stmt
specifier|static
name|set_tool_input
argument_list|()
block|{     struct
name|inputmask
name|im
block|;
name|input_imnull
argument_list|(
operator|&
name|im
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_LEFT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_MIDDLE
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_RIGHT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_STILL
argument_list|)
block|;
name|win_setinputmask
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|im
argument_list|,
name|NULL
argument_list|,
name|WIN_NULLLINK
argument_list|)
block|; }
specifier|static
name|init_tool
argument_list|()
block|{
name|tool_fd
operator|=
name|tool
operator|->
name|tl_windowfd
block|;
name|tool
operator|->
name|tl_io
operator|.
name|tio_selected
operator|=
name|tool_selected
block|;
name|set_tool_input
argument_list|()
block|;
if|if
condition|(
operator|(
name|rootfd
operator|=
name|open
argument_list|(
literal|"/dev/win0"
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"can't open root window\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|fix_tool_size
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  * Set the size of the entire gremlin window.  */
end_comment

begin_expr_stmt
unit|fix_tool_size
operator|(
operator|)
block|{     struct
name|rect
name|icon_rect
block|;
if|if
condition|(
name|wmgr_iswindowopen
argument_list|(
name|tool_fd
argument_list|)
condition|)
name|win_getrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|tool_size
argument_list|)
expr_stmt|;
else|else
name|win_getsavedrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|tool_size
argument_list|)
expr_stmt|;
name|tool_size
operator|.
name|r_width
operator|=
literal|2
operator|*
name|tool_borderwidth
argument_list|(
name|tool
argument_list|)
operator|+
name|tool_subwindowspacing
argument_list|(
name|tool
argument_list|)
operator|+
name|MENUSW_WIDTH
operator|+
name|PIXSW_WIDTH
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tool_size
operator|.
name|r_height
operator|=
name|tool_stripeheight
argument_list|(
name|tool
argument_list|)
operator|+
name|tool_borderwidth
argument_list|(
name|tool
argument_list|)
operator|+
name|tool_subwindowspacing
argument_list|(
name|tool
argument_list|)
operator|+
literal|2
operator|+
comment|/* don't know why */
name|TEXTSW_HEIGHT
operator|+
name|PIXSW_HEIGHT
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* don't allow window to open in lower left corner */
end_comment

begin_if
if|if
condition|(
name|tool_size
operator|.
name|r_left
operator|<
literal|100
condition|)
name|tool_size
operator|.
name|r_left
operator|=
literal|100
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|rect_bottom
argument_list|(
operator|&
name|tool_size
argument_list|)
operator|>=
literal|700
condition|)
name|tool_size
operator|.
name|r_top
operator|-=
name|rect_bottom
argument_list|(
operator|&
name|tool_size
argument_list|)
operator|-
literal|699
expr_stmt|;
end_if

begin_comment
comment|/* land icon near upper left corner */
end_comment

begin_expr_stmt
name|icon_rect
operator|.
name|r_left
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|icon_rect
operator|.
name|r_top
operator|=
literal|64
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|icon_rect
operator|.
name|r_width
operator|=
literal|64
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|icon_rect
operator|.
name|r_height
operator|=
literal|64
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|wmgr_iswindowopen
argument_list|(
name|tool_fd
argument_list|)
condition|)
block|{
name|win_setrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|tool_size
argument_list|)
expr_stmt|;
name|win_setsavedrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|icon_rect
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|win_setrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|icon_rect
argument_list|)
expr_stmt|;
name|win_setsavedrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|tool_size
argument_list|)
expr_stmt|;
block|}
end_if

begin_macro
unit|}   static
name|init_text
argument_list|()
end_macro

begin_block
block|{
name|struct
name|inputmask
name|im
decl_stmt|;
name|text_fd
operator|=
name|text_sw
operator|->
name|ts_windowfd
expr_stmt|;
name|text_pw
operator|=
name|pw_open
argument_list|(
name|text_fd
argument_list|)
expr_stmt|;
name|text_sw
operator|->
name|ts_io
operator|.
name|tio_handlesigwinch
operator|=
name|text_sighandler
expr_stmt|;
name|text_sw
operator|->
name|ts_io
operator|.
name|tio_selected
operator|=
name|text_selected
expr_stmt|;
name|win_setcursor
argument_list|(
name|text_fd
argument_list|,
operator|&
name|kbd_cursor
argument_list|)
expr_stmt|;
name|input_imnull
argument_list|(
operator|&
name|im
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_LEFT
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_MIDDLE
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_RIGHT
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_STILL
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_WINEXIT
argument_list|)
expr_stmt|;
name|im
operator|.
name|im_flags
operator||=
name|IM_ASCII
expr_stmt|;
name|win_setinputmask
argument_list|(
name|text_fd
argument_list|,
operator|&
name|im
argument_list|,
name|NULL
argument_list|,
name|WIN_NULLLINK
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|init_menu
argument_list|()
block|{     struct
name|inputmask
name|im
block|;
name|menu_fd
operator|=
name|menu_sw
operator|->
name|ts_windowfd
block|;
name|menu_pw
operator|=
name|pw_open
argument_list|(
name|menu_fd
argument_list|)
block|;
name|menu_sw
operator|->
name|ts_io
operator|.
name|tio_handlesigwinch
operator|=
name|menu_sighandler
block|;
name|menu_sw
operator|->
name|ts_io
operator|.
name|tio_selected
operator|=
name|menu_selected
block|;
name|win_setcursor
argument_list|(
name|menu_fd
argument_list|,
operator|&
name|menu_cursor
argument_list|)
block|;
name|input_imnull
argument_list|(
operator|&
name|im
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_LEFT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_MIDDLE
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_RIGHT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_MOVE
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_WINEXIT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_STILL
argument_list|)
block|;
name|im
operator|.
name|im_flags
operator||=
name|IM_ASCII
block|;
name|win_setinputmask
argument_list|(
name|menu_fd
argument_list|,
operator|&
name|im
argument_list|,
name|NULL
argument_list|,
name|WIN_NULLLINK
argument_list|)
block|; }
specifier|static
name|init_pix
argument_list|()
block|{     struct
name|inputmask
name|im
block|;     struct
name|fbtype
name|fb
block|;     struct
name|mpr_data
operator|*
name|md
block|;
name|int
name|height
block|,
name|width
block|;
name|int
name|fd
block|;
name|pix_fd
operator|=
name|pix_sw
operator|->
name|ts_windowfd
block|;
name|pix_pw
operator|=
name|pw_open
argument_list|(
name|pix_fd
argument_list|)
block|;
name|pix_sw
operator|->
name|ts_io
operator|.
name|tio_handlesigwinch
operator|=
name|pix_sighandler
block|;
name|pix_sw
operator|->
name|ts_io
operator|.
name|tio_selected
operator|=
name|pix_selected
block|;
name|win_setcursor
argument_list|(
name|pix_fd
argument_list|,
operator|&
name|main_cursor
argument_list|)
block|;
name|input_imnull
argument_list|(
operator|&
name|im
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_LEFT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_MIDDLE
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_RIGHT
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_STILL
argument_list|)
block|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|LOC_WINEXIT
argument_list|)
block|;
name|im
operator|.
name|im_flags
operator||=
name|IM_ASCII
block|;
name|win_setinputmask
argument_list|(
name|pix_fd
argument_list|,
operator|&
name|im
argument_list|,
name|NULL
argument_list|,
name|WIN_NULLLINK
argument_list|)
block|;
comment|/* determine screen physical dimensions */
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|DEV_FB
argument_list|,
literal|1
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* must be open for writing */
name|printf
argument_list|(
literal|"init_pix: can't open %s\n"
argument_list|,
name|DEV_FB
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/* get frame buffer characteristics */
end_comment

begin_if
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|FBIOGTYPE
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|fb
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"init_pix: ioctl (FBIOGTYPE)\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* determine maximum physical size of picture subwindow */
end_comment

begin_expr_stmt
name|height
operator|=
name|fb
operator|.
name|fb_height
operator|-
name|TEXTSW_HEIGHT
operator|-
name|tool_stripeheight
argument_list|(
name|tool
argument_list|)
operator|-
name|tool_borderwidth
argument_list|(
name|tool
argument_list|)
operator|-
name|tool_subwindowspacing
argument_list|(
name|tool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|width
operator|=
name|fb
operator|.
name|fb_width
operator|-
name|MENUSW_WIDTH
operator|-
name|tool_subwindowspacing
argument_list|(
name|tool
argument_list|)
operator|-
name|tool_borderwidth
argument_list|(
name|tool
argument_list|)
operator|*
literal|2
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* create pixrect for retaining image of current set */
end_comment

begin_expr_stmt
name|cset_pr
operator|=
name|mem_create
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|cset_pr
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"can't create cset_pr\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* create pixrect to do all element drawing in memory (faster) */
end_comment

begin_expr_stmt
name|scratch_pr
operator|=
name|mem_create
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|scratch_pr
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"can't create scratch_pr\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|RETAIN
end_ifdef

begin_comment
comment|/* create retained pixrect for picture subwindow */
end_comment

begin_expr_stmt
name|retained_pr
operator|=
name|mem_create
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|retained_pr
operator|==
operator|(
expr|struct
name|pixrect
operator|*
operator|)
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"can't create retained_pr\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* add retained pixrect to the pix subwindow pixwin */
end_comment

begin_expr_stmt
name|pix_pw
operator|->
name|pw_prretained
operator|=
name|retained_pr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*       * The pix subwindow width and height MUST be initialized before      * any drawing can take place when using a retained pixrect.      * The display routine DISScreenAdd() uses these dimensions to      * minimize the area of the mem_pixrect (scratch_pr) which must      * be cleared prior to drawing an element and is called via      * SHUpdate() at the end of main_init().      */
end_comment

begin_expr_stmt
name|pix_size
operator|.
name|r_width
operator|=
name|PIXSW_WIDTH
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|pix_size
operator|.
name|r_height
operator|=
name|PIXSW_HEIGHT
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|maybefaster
end_ifdef

begin_expr_stmt
name|md
operator|=
operator|(
expr|struct
name|mpr_data
operator|*
operator|)
name|scratch_pr
operator|->
name|pr_data
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_image
operator|=
operator|(
name|char
operator|*
operator|)
name|md
operator|->
name|md_image
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_bytesperline
operator|=
name|md
operator|->
name|md_linebytes
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_maxx
operator|=
name|_bytesperline
operator|<<
literal|3
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_maxy
operator|=
name|scratch_pr
operator|->
name|pr_size
operator|.
name|y
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/*   * This routine catches the normal tool manager quit menuitem  * and handles it slightly differently if no write has occurred  * since the last change to the picture.  * WARNING: this routine depends upon menu_display() returning  * mi->mi_data = 2 for the QUIT menuitem and  * mi->mi_data = 1 for the REDISPLAY menuitem.  */
end_comment

begin_macro
unit|static
name|tool_selected
argument_list|(
argument|nullsw
argument_list|,
argument|ibits
argument_list|,
argument|obits
argument_list|,
argument|ebits
argument_list|,
argument|timer
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
modifier|*
name|nullsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ibits
decl_stmt|,
modifier|*
name|obits
decl_stmt|,
modifier|*
name|ebits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
modifier|*
modifier|*
name|timer
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|inputevent
name|ie
decl_stmt|;
name|struct
name|inputmask
name|im
decl_stmt|;
name|struct
name|menuitem
modifier|*
name|mi
decl_stmt|;
if|if
condition|(
name|input_readevent
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|ie
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"error: tool_selected()\n"
argument_list|)
expr_stmt|;
return|return;
block|}
switch|switch
condition|(
name|ie
operator|.
name|ie_code
condition|)
block|{
case|case
name|LOC_STILL
case|:
comment|/*	    GRCurrentSetOn();			*/
break|break;
case|case
name|MS_LEFT
case|:
if|if
condition|(
name|wmgr_iswindowopen
argument_list|(
name|tool_fd
argument_list|)
condition|)
name|wmgr_top
argument_list|(
name|tool_fd
argument_list|,
name|rootfd
argument_list|)
expr_stmt|;
else|else
name|wmgr_open
argument_list|(
name|tool_fd
argument_list|,
name|rootfd
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_MIDDLE
case|:
name|wmgr_changerect
argument_list|(
name|tool_fd
argument_list|,
name|tool_fd
argument_list|,
operator|&
name|ie
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_RIGHT
case|:
comment|/* force mouse button input only for pop-up menu */
name|input_imnull
argument_list|(
operator|&
name|im
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_LEFT
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_MIDDLE
argument_list|)
expr_stmt|;
name|win_setinputcodebit
argument_list|(
operator|&
name|im
argument_list|,
name|MS_RIGHT
argument_list|)
expr_stmt|;
name|win_setinputmask
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|im
argument_list|,
name|NULL
argument_list|,
name|WIN_NULLLINK
argument_list|)
expr_stmt|;
name|wmgr_setupmenu
argument_list|(
name|tool_fd
argument_list|)
expr_stmt|;
name|mi
operator|=
name|menu_display
argument_list|(
operator|&
name|wmgr_toolmenu
argument_list|,
operator|&
name|ie
argument_list|,
name|tool_fd
argument_list|)
expr_stmt|;
if|if
condition|(
name|mi
operator|==
operator|(
expr|struct
name|menuitem
operator|*
operator|)
name|NULL
condition|)
break|break;
if|if
condition|(
operator|(
operator|(
name|int
operator|)
name|mi
operator|->
name|mi_data
operator|==
literal|1
operator|)
comment|/* REDISPLAY !! */
operator|&&
name|wmgr_iswindowopen
argument_list|(
name|tool_fd
argument_list|)
condition|)
name|SHUpdate
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|int
operator|)
name|mi
operator|->
name|mi_data
operator|==
literal|2
condition|)
comment|/* QUIT !! */
name|LGQuit
argument_list|()
expr_stmt|;
else|else
name|wmgr_handletoolmenuitem
argument_list|(
name|wmgr_toolmenu
argument_list|,
name|mi
argument_list|,
name|tool_fd
argument_list|,
name|rootfd
argument_list|)
expr_stmt|;
name|set_tool_input
argument_list|()
expr_stmt|;
comment|/* reset tool input */
break|break;
block|}
operator|*
name|ibits
operator|=
operator|*
name|obits
operator|=
operator|*
name|ebits
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|text_selected
argument_list|(
argument|nullsw
argument_list|,
argument|ibits
argument_list|,
argument|obits
argument_list|,
argument|ebits
argument_list|,
argument|timer
argument_list|)
name|caddr_t
operator|*
name|nullsw
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|ibits
decl_stmt|,
modifier|*
name|obits
decl_stmt|,
modifier|*
name|ebits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
modifier|*
modifier|*
name|timer
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|inputevent
name|ie
decl_stmt|;
if|if
condition|(
name|input_readevent
argument_list|(
name|text_fd
argument_list|,
operator|&
name|ie
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"error: text_selected()\n"
argument_list|)
expr_stmt|;
return|return;
block|}
switch|switch
condition|(
name|ie
operator|.
name|ie_code
condition|)
block|{
case|case
name|LOC_STILL
case|:
name|check_cset
argument_list|()
expr_stmt|;
break|break;
case|case
name|MS_LEFT
case|:
name|text_left
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_MIDDLE
case|:
name|text_middle
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_RIGHT
case|:
name|text_right
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOC_WINEXIT
case|:
name|text_winexit
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|(
name|ie
operator|.
name|ie_code
operator|<=
name|ASCII_LAST
operator|)
operator|&&
operator|(
name|ie
operator|.
name|ie_code
operator|>=
name|ASCII_FIRST
operator|)
condition|)
name|text_output
argument_list|(
name|ie
operator|.
name|ie_code
argument_list|)
expr_stmt|;
break|break;
block|}
operator|*
name|ibits
operator|=
operator|*
name|obits
operator|=
operator|*
name|ebits
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|menu_selected
argument_list|(
argument|nullsw
argument_list|,
argument|ibits
argument_list|,
argument|obits
argument_list|,
argument|ebits
argument_list|,
argument|timer
argument_list|)
name|caddr_t
operator|*
name|nullsw
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|ibits
decl_stmt|,
modifier|*
name|obits
decl_stmt|,
modifier|*
name|ebits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
modifier|*
modifier|*
name|timer
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|inputevent
name|ie
decl_stmt|;
name|char
name|shcmd
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|input_readevent
argument_list|(
name|menu_fd
argument_list|,
operator|&
name|ie
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"error: menu_selected()\n"
argument_list|)
expr_stmt|;
return|return;
block|}
switch|switch
condition|(
name|ie
operator|.
name|ie_code
condition|)
block|{
case|case
name|LOC_MOVE
case|:
name|mouse_move
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOC_STILL
case|:
name|check_cset
argument_list|()
expr_stmt|;
break|break;
case|case
name|MS_LEFT
case|:
name|menu_left
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_MIDDLE
case|:
name|menu_middle
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_RIGHT
case|:
name|menu_right
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOC_WINEXIT
case|:
name|menu_winexit
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|(
name|ie
operator|.
name|ie_code
operator|<=
name|ASCII_LAST
operator|)
operator|&&
operator|(
name|ie
operator|.
name|ie_code
operator|>=
name|ASCII_FIRST
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|shcmd
index|[
literal|0
index|]
operator|=
name|ie
operator|.
name|ie_code
operator|)
operator|!=
literal|'.'
condition|)
name|lasttext
operator|=
name|FALSE
expr_stmt|;
name|shcmd
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|SHCommand
argument_list|(
name|shcmd
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
operator|*
name|ibits
operator|=
operator|*
name|obits
operator|=
operator|*
name|ebits
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|pix_selected
argument_list|(
argument|nullsw
argument_list|,
argument|ibits
argument_list|,
argument|obits
argument_list|,
argument|ebits
argument_list|,
argument|timer
argument_list|)
name|caddr_t
operator|*
name|nullsw
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
modifier|*
name|ibits
decl_stmt|,
modifier|*
name|obits
decl_stmt|,
modifier|*
name|ebits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
modifier|*
modifier|*
name|timer
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|inputevent
name|ie
decl_stmt|;
name|char
name|shcmd
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|input_readevent
argument_list|(
name|pix_fd
argument_list|,
operator|&
name|ie
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"error: pix_selected()\n"
argument_list|)
expr_stmt|;
return|return;
block|}
switch|switch
condition|(
name|ie
operator|.
name|ie_code
condition|)
block|{
case|case
name|LOC_STILL
case|:
name|check_cset
argument_list|()
expr_stmt|;
break|break;
case|case
name|MS_LEFT
case|:
name|pix_left
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_MIDDLE
case|:
name|pix_middle
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|MS_RIGHT
case|:
name|pix_right
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
case|case
name|LOC_WINEXIT
case|:
name|pix_winexit
argument_list|(
operator|&
name|ie
argument_list|)
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|(
name|ie
operator|.
name|ie_code
operator|<=
name|ASCII_LAST
operator|)
operator|&&
operator|(
name|ie
operator|.
name|ie_code
operator|>=
name|ASCII_FIRST
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|shcmd
index|[
literal|0
index|]
operator|=
name|ie
operator|.
name|ie_code
operator|)
operator|!=
literal|'.'
condition|)
name|lasttext
operator|=
name|FALSE
expr_stmt|;
name|shcmd
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
name|SHCommand
argument_list|(
name|shcmd
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
operator|*
name|ibits
operator|=
operator|*
name|obits
operator|=
operator|*
name|ebits
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|sigwinched
argument_list|()
block|{
name|tool_sigwinch
argument_list|(
name|tool
argument_list|)
block|;
name|win_getrect
argument_list|(
name|tool_fd
argument_list|,
operator|&
name|tool_size
argument_list|)
block|;
comment|/*     printf("tool: left %d, top %d, width %d, height %d\n", tool_size.r_left, 	tool_size.r_top, tool_size.r_width, tool_size.r_height);     */
block|}
specifier|static
name|text_sighandler
argument_list|()
block|{
name|pw_damaged
argument_list|(
name|text_pw
argument_list|)
block|;
name|win_getrect
argument_list|(
name|text_fd
argument_list|,
operator|&
name|text_size
argument_list|)
block|;
name|pw_writebackground
argument_list|(
name|text_pw
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1024
argument_list|,
literal|1024
argument_list|,
name|PIX_SRC
argument_list|)
block|;
name|text_putvalue
argument_list|()
block|;
name|pw_donedamaged
argument_list|(
name|text_pw
argument_list|)
block|; }
specifier|static
name|menu_sighandler
argument_list|()
block|{
name|pw_damaged
argument_list|(
name|menu_pw
argument_list|)
block|;
name|win_getrect
argument_list|(
name|menu_fd
argument_list|,
operator|&
name|menu_size
argument_list|)
block|;
name|pw_writebackground
argument_list|(
name|menu_pw
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1024
argument_list|,
literal|1024
argument_list|,
name|PIX_SRC
argument_list|)
block|;
name|MNDisplayMenu
argument_list|()
block|;
comment|/*     printf("menu: left %d, top %d, width %d, height %d\n", menu_size.r_left, 	menu_size.r_top, menu_size.r_width, menu_size.r_height);     */
name|pw_donedamaged
argument_list|(
name|menu_pw
argument_list|)
block|; }
specifier|static
name|pix_sighandler
argument_list|()
block|{
name|GRCurrentSetOn
argument_list|()
block|;
comment|/* make current set on */
name|pw_damaged
argument_list|(
name|pix_pw
argument_list|)
block|;
if|if
condition|(
name|STERROR
condition|)
block|{
comment|/* check for startup error reading .gremlinrc */
name|TxPutMsg
argument_list|(
literal|"error in .gremlinrc"
argument_list|)
expr_stmt|;
name|STERROR
operator|=
literal|0
expr_stmt|;
block|}
name|win_getrect
argument_list|(
name|pix_fd
argument_list|,
operator|&
name|pix_size
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RETAIN
end_ifdef

begin_expr_stmt
name|pw_repairretained
argument_list|(
name|pix_pw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|SHUpdate
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|pw_donedamaged
argument_list|(
name|pix_pw
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  *  One time only start-up initialization.  */
end_comment

begin_expr_stmt
unit|main_init
operator|(
name|file
operator|,
name|gremlinrc
operator|)
name|char
operator|*
name|file
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|gremlinrc
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|POINT
modifier|*
name|pos
decl_stmt|;
name|int
name|i
decl_stmt|,
name|fd
decl_stmt|;
name|char
modifier|*
name|prealname
decl_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* ignore interrupts */
name|TxInit
argument_list|()
expr_stmt|;
comment|/* text subwindow init */
name|MNInitMenu
argument_list|()
expr_stmt|;
comment|/* menu subwindow init */
name|PSetPath
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
comment|/* file search path */
name|Editfile
operator|=
name|malloc
argument_list|(
literal|128
argument_list|)
expr_stmt|;
comment|/* current picture name */
name|POINTLIST
operator|=
name|PTInit
argument_list|()
expr_stmt|;
comment|/* drawing points */
name|BACKPOINT
operator|=
name|PTInit
argument_list|()
expr_stmt|;
comment|/* backup point list */
name|PICTURE
operator|=
name|DBInit
argument_list|()
expr_stmt|;
comment|/* picture database */
name|cset
operator|=
name|DBInit
argument_list|()
expr_stmt|;
comment|/* current set */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
operator|++
name|i
control|)
comment|/* set buffers */
name|MEN
index|[
name|i
index|]
operator|=
name|DBInit
argument_list|()
expr_stmt|;
name|unlist
operator|=
name|unback
operator|=
name|NULL
expr_stmt|;
comment|/* undo pointers */
name|make_arrowhead
argument_list|()
expr_stmt|;
comment|/* for> command */
name|lastcommand
operator|=
name|nop
expr_stmt|;
comment|/* no last command yet */
name|STgremlinrc
argument_list|(
name|gremlinrc
argument_list|)
expr_stmt|;
comment|/* .gremlinrc processing */
name|GRFontInit
argument_list|()
expr_stmt|;
comment|/* must be called after CSIZE& CFONT set */
name|strcpy
argument_list|(
name|Editfile
argument_list|,
name|file
argument_list|)
expr_stmt|;
comment|/* find edit file */
if|if
condition|(
operator|*
name|file
operator|!=
literal|'\0'
condition|)
block|{
name|fp
operator|=
name|POpen
argument_list|(
name|Editfile
argument_list|,
operator|&
name|prealname
argument_list|,
name|SEARCH
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
operator|==
name|NULL
condition|)
block|{
name|strcat
argument_list|(
name|namestripe
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"creating new file"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|namestripe
argument_list|,
name|prealname
argument_list|)
expr_stmt|;
name|PICTURE
operator|=
name|DBRead
argument_list|(
name|Editfile
argument_list|,
operator|&
name|Orientation
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|prealname
argument_list|,
name|O_WRONLY
operator||
name|O_APPEND
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|strcat
argument_list|(
name|namestripe
argument_list|,
literal|" (read only)"
argument_list|)
expr_stmt|;
else|else
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|strcat
argument_list|(
name|namestripe
argument_list|,
literal|"new file"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|RETAIN
comment|/*       * Update pix subwindow now so that the retained pixrect is set before      * the first SIGWINCH.      */
name|SHUpdate
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_comment
comment|/* end main_init */
end_comment

begin_comment
comment|/*  *  Make arrowhead element for later drawing.  */
end_comment

begin_macro
name|make_arrowhead
argument_list|()
end_macro

begin_block
block|{
name|POINT
modifier|*
name|pos
decl_stmt|;
name|pos
operator|=
name|PTInit
argument_list|()
expr_stmt|;
comment|/* initialize arrowhead template */
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
operator|-
literal|5.51
argument_list|,
literal|3.51
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
operator|-
literal|3.51
argument_list|,
literal|0.0
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
operator|-
literal|5.51
argument_list|,
operator|-
literal|3.51
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|PTMakePoint
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|,
operator|&
name|pos
argument_list|)
expr_stmt|;
name|arhead
operator|.
name|type
operator|=
name|VECTOR
expr_stmt|;
name|arhead
operator|.
name|ptlist
operator|=
name|pos
expr_stmt|;
name|arhead
operator|.
name|brushf
operator|=
literal|0
expr_stmt|;
comment|/* brush filled in when used */
name|arhead
operator|.
name|size
operator|=
literal|0
expr_stmt|;
name|arhead
operator|.
name|textpt
operator|=
name|malloc
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|*
operator|(
name|arhead
operator|.
name|textpt
operator|)
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Nothing has happened for a while, so check to see if its time  * to flash the current set.  If so, set the SIGALRM timer for the  * appropriate period.  */
end_comment

begin_macro
name|check_cset
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|FLASH_READY
comment|/*&& wmgr_iswindowopen(tool_fd) */
condition|)
block|{
name|GRCurrentSet
argument_list|()
expr_stmt|;
comment|/* XOR current set */
if|if
condition|(
name|CsetOn
condition|)
block|{
comment|/* set off period */
name|itime
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|timeon_s
expr_stmt|;
name|itime
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|timeon_ms
operator|*
literal|1000
expr_stmt|;
block|}
else|else
block|{
comment|/* set on period */
name|itime
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|timeoff_s
expr_stmt|;
name|itime
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|itime
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|timeoff_ms
operator|*
literal|1000
expr_stmt|;
block|}
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|itime
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|FLASH_READY
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * This routine handles the timer signals indicating that it is time  * to flash the current set.  Since the screen may not be in a consistent  * state, we simply set the FLASH_READY flag and return.  When a LOC_STILL  * input event arrives later, this flag will be checked and the current  * set flashed then.  */
end_comment

begin_expr_stmt
specifier|static
name|alrm_sighandler
argument_list|()
block|{
name|FLASH_READY
operator|=
literal|1
block|; }
end_expr_stmt

end_unit

