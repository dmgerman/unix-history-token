begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)ww.h	3.1 83/08/11	  */
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

begin_include
include|#
directive|include
file|"tt.h"
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
name|int
name|ww_insert
range|:
literal|1
decl_stmt|;
comment|/* insert mode, for printing */
name|int
name|ww_mapnl
range|:
literal|1
decl_stmt|;
comment|/* map \n to \r\n */
name|int
name|ww_haspty
range|:
literal|1
decl_stmt|;
comment|/* has pty */
name|char
name|ww_index
decl_stmt|;
comment|/* the index, for wwindex[] */
name|char
name|ww_order
decl_stmt|;
comment|/* the overlapping order */
name|struct
name|ww_dim
name|ww_w
decl_stmt|;
comment|/* window dimemsions */
name|short
name|ww_nline
decl_stmt|;
comment|/* size of the buffer */
name|short
name|ww_scroll
decl_stmt|;
comment|/* where the window is relative to the buffer */
name|struct
name|ww_pos
name|ww_cur
decl_stmt|;
comment|/* the cursor position, relative to ww_w */
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
name|short
modifier|*
name|ww_nvis
decl_stmt|;
comment|/* how many ww_buf chars are visible per row */
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
comment|/* /dev/ttyp? */
comment|/* below are things for the user */
name|char
name|ww_hasframe
range|:
literal|1
decl_stmt|;
comment|/* frame it */
name|char
name|ww_center
range|:
literal|1
decl_stmt|;
comment|/* center the label */
name|int
name|ww_id
decl_stmt|;
comment|/* the user id */
name|char
modifier|*
name|ww_label
decl_stmt|;
comment|/* the user supplied label */
block|}
struct|;
end_struct

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

begin_decl_stmt
name|struct
name|ww
name|wwnobody
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WWX_NOBODY
value|NWW
end_define

begin_decl_stmt
name|struct
name|ww_tty
name|wwoldtty
decl_stmt|,
name|wwnewtty
decl_stmt|,
name|wwwintty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|wwterm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|wwtermcap
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|wwkeys
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

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
name|int
name|wwcursorrow
decl_stmt|,
name|wwcursorcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the terminal cursor position */
end_comment

begin_decl_stmt
name|int
name|wwdtablesize
decl_stmt|;
end_decl_stmt

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
name|wwns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|ww_char
modifier|*
modifier|*
name|wwos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwbaud
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwbaudmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics */
end_comment

begin_decl_stmt
name|int
name|wwnwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnwritec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|wwcurrow
parameter_list|(
name|w
parameter_list|)
value|((w)->ww_cur.r + (w)->ww_w.t)
end_define

begin_define
define|#
directive|define
name|wwcurcol
parameter_list|(
name|w
parameter_list|)
value|((w)->ww_cur.c + (w)->ww_w.l)
end_define

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
value|wwsetcursor(wwcurrow(w), wwcurcol(w))
end_define

begin_define
define|#
directive|define
name|wwbell
parameter_list|()
value|putchar(CTRL(g))
end_define

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

