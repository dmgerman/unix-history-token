begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* curses.h */
end_comment

begin_comment
comment|/* Author:  *	Steve Kirkendall  *	14407 SW Teal Blvd. #C  *	Beaverton, OR 97005  *	kirkenda@cs.pdx.edu  */
end_comment

begin_comment
comment|/* This is the header file for a small, fast, fake curses package */
end_comment

begin_comment
comment|/* termcap stuff */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgoto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tputs
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_comment
comment|/* BIOS interface used instead of termcap for MS-DOS */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vmode
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|v_up
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_cb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_cs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_ce
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_cl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_cd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_al
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_dl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_sr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|v_move
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* faddch() is a function.  a pointer to it is passed to tputs() */
end_comment

begin_function_decl
specifier|extern
name|int
name|faddch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* data types */
end_comment

begin_define
define|#
directive|define
name|WINDOW
value|char
end_define

begin_comment
comment|/* CONSTANTS& SYMBOLS */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|A_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|A_STANDOUT
value|1
end_define

begin_define
define|#
directive|define
name|A_BOLD
value|2
end_define

begin_define
define|#
directive|define
name|A_UNDERLINE
value|3
end_define

begin_define
define|#
directive|define
name|A_ALTCHARSET
value|4
end_define

begin_define
define|#
directive|define
name|A_POPUP
value|5
end_define

begin_define
define|#
directive|define
name|A_VISIBLE
value|6
end_define

begin_define
define|#
directive|define
name|KBSIZ
value|4096
end_define

begin_comment
comment|/* figure out how many function keys we need to allow. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FKEY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NO_SHIFT_FKEY
end_ifdef

begin_define
define|#
directive|define
name|NFKEYS
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CTRL_FKEY
end_ifdef

begin_define
define|#
directive|define
name|NFKEYS
value|20
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NO_ALT_FKEY
end_ifdef

begin_define
define|#
directive|define
name|NFKEYS
value|30
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFKEYS
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|FKEY
index|[
name|NFKEYS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :k0=:...:k9=: codes sent by function keys */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* extern variables, defined in curses.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|termtype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of terminal entry */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty speed, eg B2400 */
end_comment

begin_if
if|#
directive|if
name|OSK
end_if

begin_decl_stmt
specifier|extern
name|char
name|PC_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pad char */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Backspace char string */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pad char */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|stdscr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into kbuf[] */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
name|kbuf
index|[
name|KBSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a very large output buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :li#: number of rows */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|COLS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :co#: number of columns */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|AM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :am:  boolean: auto margins? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :pt:  boolean: physical tabs? */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|VB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :vb=: visible bell */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :up=: move cursor up */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :so=: standout start */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :se=: standout end */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|US
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :us=: underline start */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ue=: underline end */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|MD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :md=: bold start */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ME
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :me=: bold end */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :as=: alternate (italic) start */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ae=: alternate (italic) end */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VISIBLE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|MV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :mv=: "visible" selection start */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cm=: cursor movement */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ce=: clear to end of line */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cd=: clear to end of screen */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :al=: add a line */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :dl=: delete a line */
end_comment

begin_if
if|#
directive|if
name|OSK
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SR_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :sr=: scroll reverse */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :sr=: scroll reverse */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ks=: init string for cursor */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ke=: restore string for cursor */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ku=: sequence sent by up key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :kd=: sequence sent by down key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :kl=: sequence sent by left key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :kr=: sequence sent by right key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :PU=: key sequence sent by PgUp key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :PD=: key sequence sent by PgDn key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|HM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :HM=: key sequence sent by Home key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|EN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :EN=: key sequence sent by End key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :kI=: key sequence sent by Insert key */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|IM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :im=: insert mode start */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|IC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ic=: insert following char */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|EI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ei=: insert mode end */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :dc=: delete a character */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :ti=: terminal init */
end_comment

begin_comment
comment|/* GB */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|TE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :te=: terminal exit */
end_comment

begin_comment
comment|/* GB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CURSORSHAPE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cQ=: normal cursor */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cX=: cursor used for EX command/entry */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cV=: cursor used for VI command mode */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cI=: cursor used for VI input mode */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* :cR=: cursor used for VI replace mode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|aend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end an attribute -- either UE or ME */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ERASEKEY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* taken from the ioctl structure */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_COLOR
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|SOcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|SEcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|UScolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|UEcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|MDcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|MEcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|AScolor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|AEcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NO_POPUP
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|POPUPcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_VISIBLE
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|VISIBLEcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|normalcolor
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* undef NO_COLOR */
end_comment

begin_comment
comment|/* Msdos-versions may use bios; others always termcap.  * Will emit some 'code has no effect' warnings in unix.  */
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_decl_stmt
specifier|extern
name|char
name|o_pcbios
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* BAH! */
end_comment

begin_define
define|#
directive|define
name|CHECKBIOS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*o_pcbios ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|VOIDBIOS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{if (*o_pcbios) {x;} else {y;}}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECKBIOS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(y)
end_define

begin_define
define|#
directive|define
name|VOIDBIOS
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{y;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_COLOR
end_ifndef

begin_define
define|#
directive|define
name|setcolor
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
value|CHECKBIOS(bioscolor(m,a), ansicolor(m,a))
end_define

begin_define
define|#
directive|define
name|fixcolor
parameter_list|()
value|VOIDBIOS(;, tputs(normalcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|quitcolor
parameter_list|()
value|CHECKBIOS(biosquit(), ansiquit())
end_define

begin_define
define|#
directive|define
name|do_SO
parameter_list|()
value|VOIDBIOS((vmode=A_STANDOUT), tputs(SOcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_SE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(SEcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_US
parameter_list|()
value|VOIDBIOS((vmode=A_UNDERLINE), tputs(UScolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_UE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(UEcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_MD
parameter_list|()
value|VOIDBIOS((vmode=A_BOLD), tputs(MDcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_ME
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(MEcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_AS
parameter_list|()
value|VOIDBIOS((vmode=A_ALTCHARSET), tputs(AScolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_AE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(AEcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_POPUP
parameter_list|()
value|VOIDBIOS((vmode=A_POPUP), tputs(POPUPcolor, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_VISIBLE
parameter_list|()
value|VOIDBIOS((vmode=A_VISIBLE), tputs(VISIBLEcolor, 1, faddch))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_SO
parameter_list|()
value|VOIDBIOS((vmode=A_STANDOUT), tputs(SO, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_SE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(SE, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_US
parameter_list|()
value|VOIDBIOS((vmode=A_UNDERLINE), tputs(US, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_UE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(UE, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_MD
parameter_list|()
value|VOIDBIOS((vmode=A_BOLD), tputs(MD, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_ME
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(ME, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_AS
parameter_list|()
value|VOIDBIOS((vmode=A_ALTCHARSET), tputs(AS, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_AE
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(AE, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_POPUP
parameter_list|()
value|VOIDBIOS((vmode=A_POPUP), tputs(SO, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_VISIBLE
parameter_list|()
value|VOIDBIOS((vmode=A_VISIBLE), tputs(MV, 1, faddch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|do_VB
parameter_list|()
value|VOIDBIOS(;, tputs(VB, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_UP
parameter_list|()
value|VOIDBIOS(v_up(), tputs(UP, 1, faddch))
end_define

begin_undef
undef|#
directive|undef
name|do_CM
end_undef

begin_comment
comment|/* move */
end_comment

begin_define
define|#
directive|define
name|do_CE
parameter_list|()
value|VOIDBIOS(v_ce(), tputs(CE, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_CD
parameter_list|()
value|VOIDBIOS(v_cd(), tputs(CD, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_AL
parameter_list|()
value|VOIDBIOS(v_al(), tputs(AL, LINES, faddch))
end_define

begin_define
define|#
directive|define
name|do_DL
parameter_list|()
value|VOIDBIOS(v_dl(), tputs(DL, LINES, faddch))
end_define

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|do_SR
parameter_list|()
value|VOIDBIOS(v_sr(), tputs(SR_, 1, faddch))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_SR
parameter_list|()
value|VOIDBIOS(v_sr(), tputs(SR, 1, faddch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|do_KS
parameter_list|()
value|VOIDBIOS(1, tputs(KS, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_KE
parameter_list|()
value|VOIDBIOS(1, tputs(KE, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_IM
parameter_list|()
value|VOIDBIOS(;, tputs(IM, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_IC
parameter_list|()
value|VOIDBIOS(;, tputs(IC, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_EI
parameter_list|()
value|VOIDBIOS(;, tputs(EI, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_DC
parameter_list|()
value|VOIDBIOS(;, tputs(DC, COLS, faddch))
end_define

begin_define
define|#
directive|define
name|do_TI
parameter_list|()
value|VOIDBIOS(;, (void)ttywrite(TI, (unsigned)strlen(TI)))
end_define

begin_define
define|#
directive|define
name|do_TE
parameter_list|()
value|VOIDBIOS(;, (void)ttywrite(TE, (unsigned)strlen(TE)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CURSORSHAPE
end_ifndef

begin_define
define|#
directive|define
name|do_CQ
parameter_list|()
value|VOIDBIOS(v_cs(), tputs(CQ, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_CX
parameter_list|()
value|VOIDBIOS(v_cs(), tputs(CX, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_CV
parameter_list|()
value|VOIDBIOS(v_cs(), tputs(CV, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_CI
parameter_list|()
value|VOIDBIOS(v_cb(), tputs(CI, 1, faddch))
end_define

begin_define
define|#
directive|define
name|do_CR
parameter_list|()
value|VOIDBIOS(v_cb(), tputs(CR, 1, faddch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_COLOR
end_ifndef

begin_define
define|#
directive|define
name|do_aend
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), endcolor())
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|do_aend
parameter_list|()
value|VOIDBIOS((vmode=A_NORMAL), tputs(aend, 1, faddch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|has_AM
value|CHECKBIOS(1, AM)
end_define

begin_define
define|#
directive|define
name|has_PT
value|CHECKBIOS(0, PT)
end_define

begin_define
define|#
directive|define
name|has_VB
value|CHECKBIOS((char *)0, VB)
end_define

begin_define
define|#
directive|define
name|has_UP
value|CHECKBIOS((char *)1, UP)
end_define

begin_define
define|#
directive|define
name|has_SO
value|CHECKBIOS((char)1, (*SO))
end_define

begin_define
define|#
directive|define
name|has_SE
value|CHECKBIOS((char)1, (*SE))
end_define

begin_define
define|#
directive|define
name|has_US
value|CHECKBIOS((char)1, (*US))
end_define

begin_define
define|#
directive|define
name|has_UE
value|CHECKBIOS((char)1, (*UE))
end_define

begin_define
define|#
directive|define
name|has_MD
value|CHECKBIOS((char)1, (*MD))
end_define

begin_define
define|#
directive|define
name|has_ME
value|CHECKBIOS((char)1, (*ME))
end_define

begin_define
define|#
directive|define
name|has_AS
value|CHECKBIOS((char)1, (*AS))
end_define

begin_define
define|#
directive|define
name|has_AE
value|CHECKBIOS((char)1, (*AE))
end_define

begin_undef
undef|#
directive|undef
name|has_CM
end_undef

begin_comment
comment|/* cursor move: don't need */
end_comment

begin_define
define|#
directive|define
name|has_CB
value|CHECKBIOS(1, 0)
end_define

begin_define
define|#
directive|define
name|has_CS
value|CHECKBIOS(1, 0)
end_define

begin_define
define|#
directive|define
name|has_CE
value|CHECKBIOS((char *)1, CE)
end_define

begin_define
define|#
directive|define
name|has_CD
value|CHECKBIOS((char *)1, CD)
end_define

begin_define
define|#
directive|define
name|has_AL
value|CHECKBIOS((char *)1, AL)
end_define

begin_define
define|#
directive|define
name|has_DL
value|CHECKBIOS((char *)1, DL)
end_define

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|has_SR
value|CHECKBIOS((char *)1, SR_)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|has_SR
value|CHECKBIOS((char *)1, SR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|has_KS
value|CHECKBIOS((char)1, (*KS))
end_define

begin_define
define|#
directive|define
name|has_KE
value|CHECKBIOS((char)1, (*KE))
end_define

begin_define
define|#
directive|define
name|has_KU
value|KU
end_define

begin_define
define|#
directive|define
name|has_KD
value|KD
end_define

begin_define
define|#
directive|define
name|has_KL
value|KL
end_define

begin_define
define|#
directive|define
name|has_KR
value|KR
end_define

begin_define
define|#
directive|define
name|has_HM
value|HM
end_define

begin_define
define|#
directive|define
name|has_EN
value|EN
end_define

begin_define
define|#
directive|define
name|has_PU
value|PU
end_define

begin_define
define|#
directive|define
name|has_PD
value|PD
end_define

begin_define
define|#
directive|define
name|has_KI
value|KI
end_define

begin_define
define|#
directive|define
name|has_IM
value|CHECKBIOS((char)0, (*IM))
end_define

begin_define
define|#
directive|define
name|has_IC
value|CHECKBIOS((char)0, (*IC))
end_define

begin_define
define|#
directive|define
name|has_EI
value|CHECKBIOS((char)0, (*EI))
end_define

begin_define
define|#
directive|define
name|has_DC
value|CHECKBIOS((char *)0, DC)
end_define

begin_define
define|#
directive|define
name|has_TI
value|CHECKBIOS((char)0, (*TI))
end_define

begin_define
define|#
directive|define
name|has_TE
value|CHECKBIOS((char)0, (*TE))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_CURSORSHAPE
end_ifndef

begin_define
define|#
directive|define
name|has_CQ
value|CHECKBIOS((char *)1, CQ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (pseudo)-Curses-functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|_addCR
value|VOIDBIOS(;, (stdscr[-1] == '\n' ? qaddch('\r') : (stdscr[-1] = '\n')))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|_addCR
value|VOIDBIOS(;, (stdscr[-1] == '\n' ? qaddch('\l') : (stdscr[-1] = stdscr[-1])))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_addCR
value|VOIDBIOS(;, (stdscr[-1] == '\n' ? qaddch('\r') : 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AZTEC_C
end_ifdef

begin_define
define|#
directive|define
name|qaddch
parameter_list|(
name|ch
parameter_list|)
value|CHECKBIOS(v_put(ch), (*stdscr = (ch), *stdscr++))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|qaddch
parameter_list|(
name|ch
parameter_list|)
value|CHECKBIOS(v_put(ch), (*stdscr++ = (ch)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|addch
parameter_list|(
name|ch
parameter_list|)
value|if (qaddch(ch) == '\n') qaddch('\l'); else
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|addch
parameter_list|(
name|ch
parameter_list|)
value|if (qaddch(ch) == '\n') qaddch('\r'); else
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|initscr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|endwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|suspend_curses
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resume_curses
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|attrset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qaddstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wrefresh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|wqrefresh
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|addstr
parameter_list|(
name|str
parameter_list|)
value|{qaddstr(str); _addCR;}
end_define

begin_define
define|#
directive|define
name|move
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|VOIDBIOS(v_move(x,y), tputs(tgoto(CM, x, y), 1, faddch))
end_define

begin_define
define|#
directive|define
name|mvaddch
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|,
name|ch
parameter_list|)
value|{move(y,x); addch(ch);}
end_define

begin_define
define|#
directive|define
name|refresh
parameter_list|()
value|VOIDBIOS(;, wrefresh())
end_define

begin_define
define|#
directive|define
name|standout
parameter_list|()
value|do_SO()
end_define

begin_define
define|#
directive|define
name|standend
parameter_list|()
value|do_SE()
end_define

begin_define
define|#
directive|define
name|clrtoeol
parameter_list|()
value|do_CE()
end_define

begin_define
define|#
directive|define
name|clrtobot
parameter_list|()
value|do_CD()
end_define

begin_define
define|#
directive|define
name|insertln
parameter_list|()
value|do_AL()
end_define

begin_define
define|#
directive|define
name|deleteln
parameter_list|()
value|do_DL()
end_define

begin_define
define|#
directive|define
name|delch
parameter_list|()
value|do_DC()
end_define

begin_define
define|#
directive|define
name|scrollok
parameter_list|(
name|w
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|raw
parameter_list|()
end_define

begin_define
define|#
directive|define
name|echo
parameter_list|()
end_define

begin_define
define|#
directive|define
name|cbreak
parameter_list|()
end_define

begin_define
define|#
directive|define
name|noraw
parameter_list|()
end_define

begin_define
define|#
directive|define
name|noecho
parameter_list|()
end_define

begin_define
define|#
directive|define
name|nocbreak
parameter_list|()
end_define

end_unit

