begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)ww.h	3.16 83/09/15	  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_define
define|#
directive|define
name|NWW
value|30
end_define

begin_struct
struct|struct
name|ww_dim
block|{
name|int
name|nr
decl_stmt|;
comment|/* number of rows */
name|int
name|nc
decl_stmt|;
comment|/* number of columns */
name|int
name|t
decl_stmt|,
name|b
decl_stmt|;
comment|/* top, bottom */
name|int
name|l
decl_stmt|,
name|r
decl_stmt|;
comment|/* left, right */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ww_pos
block|{
name|int
name|r
decl_stmt|;
comment|/* row */
name|int
name|c
decl_stmt|;
comment|/* column */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ww
block|{
name|struct
name|ww
modifier|*
name|ww_forw
decl_stmt|;
comment|/* doubly linked list, for overlapping info */
name|struct
name|ww
modifier|*
name|ww_back
decl_stmt|;
name|char
name|ww_state
decl_stmt|;
comment|/* state of window creation */
name|char
name|ww_wstate
decl_stmt|;
comment|/* state for printing charcters */
name|char
name|ww_modes
decl_stmt|;
comment|/* current printing modes */
name|char
name|ww_insert
range|:
literal|1
decl_stmt|;
comment|/* insert mode, for printing */
name|char
name|ww_mapnl
range|:
literal|1
decl_stmt|;
comment|/* map \n to \r\n */
name|char
name|ww_haspty
range|:
literal|1
decl_stmt|;
comment|/* has pty */
name|char
name|ww_hascursor
range|:
literal|1
decl_stmt|;
comment|/* has fake cursor */
name|char
name|ww_hasframe
range|:
literal|1
decl_stmt|;
comment|/* frame it */
name|char
name|ww_index
decl_stmt|;
comment|/* the index, for wwindex[] */
name|char
name|ww_order
decl_stmt|;
comment|/* the overlapping order */
comment|/* sizes and positions */
name|struct
name|ww_dim
name|ww_w
decl_stmt|;
comment|/* window size and pos */
name|struct
name|ww_dim
name|ww_b
decl_stmt|;
comment|/* buffer size and pos */
name|struct
name|ww_dim
name|ww_i
decl_stmt|;
comment|/* the part inside the screen */
name|struct
name|ww_pos
name|ww_cur
decl_stmt|;
comment|/* the cursor position, relative to ww_w */
comment|/* arrays */
name|char
modifier|*
modifier|*
name|ww_win
decl_stmt|;
comment|/* the window */
name|union
name|ww_char
modifier|*
modifier|*
name|ww_buf
decl_stmt|;
comment|/* the buffer */
name|char
modifier|*
modifier|*
name|ww_cov
decl_stmt|;
comment|/* the covered-by array */
name|char
modifier|*
modifier|*
name|ww_fmap
decl_stmt|;
comment|/* map for frame and box windows */
name|short
modifier|*
name|ww_nvis
decl_stmt|;
comment|/* how many ww_buf chars are visible per row */
comment|/* things for the window process */
name|int
name|ww_pty
decl_stmt|;
comment|/* file descriptor of pty */
name|int
name|ww_tty
decl_stmt|;
comment|/* . . . tty */
name|int
name|ww_pid
decl_stmt|;
comment|/* pid of process, if WWS_HASPROC true */
name|char
name|ww_ttyname
index|[
literal|11
index|]
decl_stmt|;
comment|/* "/dev/ttyp?" */
comment|/* things for the user, they really don't belong here */
name|char
name|ww_center
range|:
literal|1
decl_stmt|;
comment|/* center the label */
name|int
name|ww_id
decl_stmt|;
comment|/* the user window id */
name|char
modifier|*
name|ww_label
decl_stmt|;
comment|/* the user supplied label */
name|struct
name|ww_pos
name|ww_altpos
decl_stmt|;
comment|/* alternate position */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ww_tty
block|{
name|struct
name|sgttyb
name|ww_sgttyb
decl_stmt|;
name|struct
name|tchars
name|ww_tchars
decl_stmt|;
name|struct
name|ltchars
name|ww_ltchars
decl_stmt|;
name|int
name|ww_lmode
decl_stmt|;
name|int
name|ww_ldisc
decl_stmt|;
name|int
name|ww_pgrp
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ww_char
block|{
name|short
name|c_w
decl_stmt|;
comment|/* as a word */
struct|struct
block|{
name|char
name|C_c
decl_stmt|;
comment|/* the character part */
name|char
name|C_m
decl_stmt|;
comment|/* the mode part */
block|}
name|c_un
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|c_c
value|c_un.C_c
end_define

begin_define
define|#
directive|define
name|c_m
value|c_un.C_m
end_define

begin_comment
comment|/* parts of ww_char */
end_comment

begin_define
define|#
directive|define
name|WWC_CMASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|WWC_MMASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|WWC_MSHIFT
value|8
end_define

begin_comment
comment|/* c_m bits */
end_comment

begin_define
define|#
directive|define
name|WWM_REV
value|0x01
end_define

begin_comment
comment|/* reverse video */
end_comment

begin_define
define|#
directive|define
name|WWM_BLK
value|0x02
end_define

begin_comment
comment|/* blinking */
end_comment

begin_define
define|#
directive|define
name|WWM_UL
value|0x04
end_define

begin_comment
comment|/* underlined */
end_comment

begin_define
define|#
directive|define
name|WWM_GLS
value|0x10
end_define

begin_comment
comment|/* window only, glass, i.e. transparent */
end_comment

begin_define
define|#
directive|define
name|WWM_COV
value|0x20
end_define

begin_comment
comment|/* window only, covered */
end_comment

begin_comment
comment|/* ww_state values */
end_comment

begin_define
define|#
directive|define
name|WWS_INITIAL
value|0
end_define

begin_comment
comment|/* just opened */
end_comment

begin_define
define|#
directive|define
name|WWS_HASPROC
value|1
end_define

begin_comment
comment|/* forked, in parent */
end_comment

begin_define
define|#
directive|define
name|WWS_INCHILD
value|2
end_define

begin_comment
comment|/* forked, in child */
end_comment

begin_define
define|#
directive|define
name|WWS_DEAD
value|3
end_define

begin_comment
comment|/* child died */
end_comment

begin_comment
comment|/* flags for ww_fmap */
end_comment

begin_define
define|#
directive|define
name|WWF_U
value|0x01
end_define

begin_define
define|#
directive|define
name|WWF_R
value|0x02
end_define

begin_define
define|#
directive|define
name|WWF_D
value|0x04
end_define

begin_define
define|#
directive|define
name|WWF_L
value|0x08
end_define

begin_define
define|#
directive|define
name|WWF_MASK
value|(WWF_U|WWF_R|WWF_D|WWF_L)
end_define

begin_define
define|#
directive|define
name|WWF_LABEL
value|0x40
end_define

begin_define
define|#
directive|define
name|WWF_TOP
value|0x80
end_define

begin_comment
comment|/* flags to wwopen() */
end_comment

begin_define
define|#
directive|define
name|WWO_PTY
value|0x01
end_define

begin_comment
comment|/* want pty */
end_comment

begin_define
define|#
directive|define
name|WWO_REVERSE
value|0x02
end_define

begin_comment
comment|/* make it all reverse video */
end_comment

begin_define
define|#
directive|define
name|WWO_GLASS
value|0x04
end_define

begin_comment
comment|/* make it all glass */
end_comment

begin_define
define|#
directive|define
name|WWO_FRAME
value|0x08
end_define

begin_comment
comment|/* this is a frame window */
end_comment

begin_comment
comment|/* special ww_index value */
end_comment

begin_define
define|#
directive|define
name|WWX_NOBODY
value|NWW
end_define

begin_define
define|#
directive|define
name|WWE_NOERR
value|0
end_define

begin_define
define|#
directive|define
name|WWE_SYS
value|1
end_define

begin_comment
comment|/* system error */
end_comment

begin_define
define|#
directive|define
name|WWE_NOMEM
value|2
end_define

begin_comment
comment|/* out of memory */
end_comment

begin_define
define|#
directive|define
name|WWE_TOOMANY
value|3
end_define

begin_comment
comment|/* too many windows */
end_comment

begin_define
define|#
directive|define
name|WWE_NOPTY
value|4
end_define

begin_comment
comment|/* no more ptys */
end_comment

begin_define
define|#
directive|define
name|WWE_SIZE
value|5
end_define

begin_comment
comment|/* bad window size */
end_comment

begin_define
define|#
directive|define
name|WWE_BADTERM
value|6
end_define

begin_comment
comment|/* bad terminal type */
end_comment

begin_define
define|#
directive|define
name|WWE_CANTDO
value|7
end_define

begin_comment
comment|/* dumb terminal */
end_comment

begin_decl_stmt
name|struct
name|ww
name|wwhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|wwindex
index|[
name|NWW
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last location is for wwnobody */
end_comment

begin_decl_stmt
name|struct
name|ww
name|wwnobody
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww_tty
name|wwoldtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the old (saved) terminal settings */
end_comment

begin_decl_stmt
name|struct
name|ww_tty
name|wwnewtty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the new (current) terminal settings */
end_comment

begin_decl_stmt
name|struct
name|ww_tty
name|wwwintty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the terminal settings for windows */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the terminal name */
end_comment

begin_decl_stmt
name|char
name|wwtermcap
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place for the termcap */
end_comment

begin_decl_stmt
name|char
name|wwkeys
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* termcap fields for the function keys */
end_comment

begin_decl_stmt
name|int
name|wwnrow
decl_stmt|,
name|wwncol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the screen size */
end_comment

begin_decl_stmt
name|char
name|wwavailmodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actually supported modes */
end_comment

begin_decl_stmt
name|char
name|wwcursormodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the modes for the fake cursor */
end_comment

begin_decl_stmt
name|char
name|wwwrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal has auto wrap around */
end_comment

begin_decl_stmt
name|int
name|wwdtablesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* result of getdtablesize() call */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|wwsmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the screen map */
end_comment

begin_decl_stmt
name|union
name|ww_char
modifier|*
modifier|*
name|wwos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the old (current) screen */
end_comment

begin_decl_stmt
name|union
name|ww_char
modifier|*
modifier|*
name|wwns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the new (desired) screen */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwtouched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wwns changed flags */
end_comment

begin_decl_stmt
name|int
name|wwbaudmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maps stty() baud rate code into number */
end_comment

begin_decl_stmt
name|int
name|wwbaud
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wwbaudmap[wwoldtty.ww_sgttyb.sg_ospeed] */
end_comment

begin_decl_stmt
name|int
name|wwcursorrow
decl_stmt|,
name|wwcursorcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where we want the cursor to be */
end_comment

begin_decl_stmt
name|int
name|wwerrno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error number */
end_comment

begin_comment
comment|/* statistics */
end_comment

begin_decl_stmt
name|int
name|wwnwrite
decl_stmt|,
name|wwnwritec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnupdate
decl_stmt|,
name|wwntouched
decl_stmt|,
name|wwnmiss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quicky macros */
end_comment

begin_define
define|#
directive|define
name|wwsetcursor
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|(wwcursorrow = (r), wwcursorcol = (c))
end_define

begin_define
define|#
directive|define
name|wwcurtowin
parameter_list|(
name|w
parameter_list|)
value|wwsetcursor((w)->ww_cur.r, (w)->ww_cur.c)
end_define

begin_define
define|#
directive|define
name|wwbell
parameter_list|()
value|putchar(CTRL(g))
end_define

begin_define
define|#
directive|define
name|wwunbox
parameter_list|(
name|w
parameter_list|)
value|wwunframe(w)
end_define

begin_define
define|#
directive|define
name|wwclreol
parameter_list|(
name|w
parameter_list|,
name|r
parameter_list|,
name|c
parameter_list|)
value|wwclreol1((w), (r), (c), 0)
end_define

begin_define
define|#
directive|define
name|wwredrawwin
parameter_list|(
name|w
parameter_list|)
value|wwredrawwin1((w), (w)->ww_i.t, (w)->ww_i.b, 0)
end_define

begin_comment
comment|/* the window virtual terminal */
end_comment

begin_define
define|#
directive|define
name|WWT_TERM
value|"TERM=window"
end_define

begin_define
define|#
directive|define
name|WWT_TERMCAP
value|"WW|window|window package:\ 	:cr=^M:nl=^J:bl=^G:\ 	:al=\\EL:am:le=^H:bs:cd=\\EJ:ce=\\EK:cl=\\EE:cm=\\EY%+ %+ :\ 	:da:db:dc=\\EN:dl=\\EM:do=\\EB:ei=\\EO:ho=\\EH:im=\\E@:mi:\ 	:nd=\\EC:ta=^I:pt:up=\\EA:"
end_define

begin_define
define|#
directive|define
name|WWT_REV
value|"se=\\Eq:so=\\Ep:"
end_define

begin_define
define|#
directive|define
name|WWT_UL
value|"ue=\\Es:us=\\Er:"
end_define

begin_comment
comment|/* our functions */
end_comment

begin_function_decl
name|struct
name|ww
modifier|*
name|wwopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|wwfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wwchild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wwsuspend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|unctrl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|wwalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|wwerror
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* c library functions */
end_comment

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_undef
undef|#
directive|undef
name|MAX
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (y) : (x))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)> (y) ? (x) : (y))
end_define

begin_undef
undef|#
directive|undef
name|CTRL
end_undef

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'&0x1f)
end_define

begin_define
define|#
directive|define
name|DEL
value|0x7f
end_define

begin_define
define|#
directive|define
name|ISCTRL
parameter_list|(
name|c
parameter_list|)
value|((c)< ' ' || (c)>= DEL)
end_define

end_unit

