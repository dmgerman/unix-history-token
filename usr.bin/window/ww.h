begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ww.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_TTY
end_ifdef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|NWW
value|30
end_define

begin_comment
comment|/* maximum number of windows */
end_comment

begin_comment
comment|/* a rectangle */
end_comment

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

begin_comment
comment|/* a coordinate */
end_comment

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

begin_comment
comment|/* the window structure */
end_comment

begin_struct
struct|struct
name|ww
block|{
comment|/* general flags and states */
name|char
name|ww_state
decl_stmt|;
comment|/* state of window */
name|char
name|ww_oflags
decl_stmt|;
comment|/* wwopen flags */
comment|/* information for overlap */
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
name|ww_index
decl_stmt|;
comment|/* the window index, for wwindex[] */
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
name|ww_fmap
decl_stmt|;
comment|/* map for frame and box windows */
name|short
modifier|*
name|ww_nvis
decl_stmt|;
comment|/* how many ww_buf chars are visible per row */
comment|/* information for wwwrite() and company */
name|char
name|ww_wstate
decl_stmt|;
comment|/* state for outputting characters */
name|char
name|ww_modes
decl_stmt|;
comment|/* current display modes */
name|char
name|ww_insert
decl_stmt|;
comment|/* insert mode */
name|char
name|ww_mapnl
decl_stmt|;
comment|/* map \n to \r\n */
name|char
name|ww_noupdate
decl_stmt|;
comment|/* don't do updates in wwwrite() */
name|char
name|ww_unctrl
decl_stmt|;
comment|/* expand control characters */
name|char
name|ww_nointr
decl_stmt|;
comment|/* wwwrite() not interruptable */
name|char
name|ww_hascursor
decl_stmt|;
comment|/* has fake cursor */
comment|/* things for the window process and io */
name|char
name|ww_ispty
decl_stmt|;
comment|/* ww_pty is really a pty, not socket pair */
name|char
name|ww_stopped
decl_stmt|;
comment|/* output stopped */
name|int
name|ww_pty
decl_stmt|;
comment|/* file descriptor of pty or socket pair */
name|int
name|ww_socket
decl_stmt|;
comment|/* other end of socket pair */
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
name|char
modifier|*
name|ww_ob
decl_stmt|;
comment|/* output buffer */
name|char
modifier|*
name|ww_obe
decl_stmt|;
comment|/* end of ww_ob */
name|char
modifier|*
name|ww_obp
decl_stmt|;
comment|/* current read position in ww_ob */
name|char
modifier|*
name|ww_obq
decl_stmt|;
comment|/* current write position in ww_ob */
comment|/* things for the user, they really don't belong here */
name|char
name|ww_id
decl_stmt|;
comment|/* the user window id */
name|char
name|ww_center
decl_stmt|;
comment|/* center the label */
name|char
name|ww_hasframe
decl_stmt|;
comment|/* frame it */
name|char
name|ww_keepopen
decl_stmt|;
comment|/* keep it open after the process dies */
name|char
modifier|*
name|ww_label
decl_stmt|;
comment|/* the user supplied label */
name|struct
name|ww_dim
name|ww_alt
decl_stmt|;
comment|/* alternate position and size */
block|}
struct|;
end_struct

begin_comment
comment|/* state of a tty */
end_comment

begin_struct
struct|struct
name|ww_tty
block|{
ifdef|#
directive|ifdef
name|OLD_TTY
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
else|#
directive|else
name|struct
name|termios
name|ww_termios
decl_stmt|;
endif|#
directive|endif
name|int
name|ww_fflags
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
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|||
name|BYTE_ORDER
operator|==
name|PDP_ENDIAN
name|char
name|C_c
decl_stmt|;
comment|/* the character part */
name|char
name|C_m
decl_stmt|;
comment|/* the mode part */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|char
name|C_m
decl_stmt|;
comment|/* the mode part */
name|char
name|C_c
decl_stmt|;
comment|/* the character part */
endif|#
directive|endif
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
comment|/* for display update */
end_comment

begin_struct
struct|struct
name|ww_update
block|{
name|int
name|best_gain
decl_stmt|;
name|int
name|best_col
decl_stmt|;
name|int
name|gain
decl_stmt|;
block|}
struct|;
end_struct

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
name|WWM_GRP
value|0x08
end_define

begin_comment
comment|/* graphics */
end_comment

begin_define
define|#
directive|define
name|WWM_DIM
value|0x10
end_define

begin_comment
comment|/* half intensity */
end_comment

begin_define
define|#
directive|define
name|WWM_USR
value|0x20
end_define

begin_comment
comment|/* user specified mode */
end_comment

begin_define
define|#
directive|define
name|WWM_GLS
value|0x40
end_define

begin_comment
comment|/* window only, glass, i.e., transparent */
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
comment|/* has process on pty */
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
name|WWO_SOCKET
value|0x02
end_define

begin_comment
comment|/* want socket pair */
end_comment

begin_define
define|#
directive|define
name|WWO_REVERSE
value|0x04
end_define

begin_comment
comment|/* make it all reverse video */
end_comment

begin_define
define|#
directive|define
name|WWO_GLASS
value|0x08
end_define

begin_comment
comment|/* make it all glass */
end_comment

begin_define
define|#
directive|define
name|WWO_FRAME
value|0x10
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

begin_comment
comment|/* error codes */
end_comment

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

begin_comment
comment|/* wwtouched[] bits, there used to be more than one */
end_comment

begin_define
define|#
directive|define
name|WWU_TOUCHED
value|0x01
end_define

begin_comment
comment|/* touched */
end_comment

begin_comment
comment|/* the window structures */
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

begin_comment
comment|/* tty things */
end_comment

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

begin_comment
comment|/* generally useful variables */
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
name|union
name|ww_char
modifier|*
modifier|*
name|wwcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the checkpointed screen */
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
name|struct
name|ww_update
modifier|*
name|wwupd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for display update */
end_comment

begin_decl_stmt
name|int
name|wwospeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output baud rate, copied from wwoldtty */
end_comment

begin_decl_stmt
name|int
name|wwbaud
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wwospeed converted into actual number */
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
name|wwnflush
decl_stmt|,
name|wwnwr
decl_stmt|,
name|wwnwre
decl_stmt|,
name|wwnwrz
decl_stmt|,
name|wwnwrc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnwwr
decl_stmt|,
name|wwnwwra
decl_stmt|,
name|wwnwwrc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwntokdef
decl_stmt|,
name|wwntokuse
decl_stmt|,
name|wwntokbad
decl_stmt|,
name|wwntoksave
decl_stmt|,
name|wwntokc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnupdate
decl_stmt|,
name|wwnupdline
decl_stmt|,
name|wwnupdmiss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnupdscan
decl_stmt|,
name|wwnupdclreol
decl_stmt|,
name|wwnupdclreos
decl_stmt|,
name|wwnupdclreosmiss
decl_stmt|,
name|wwnupdclreosline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnread
decl_stmt|,
name|wwnreade
decl_stmt|,
name|wwnreadz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnreadc
decl_stmt|,
name|wwnreadack
decl_stmt|,
name|wwnreadnack
decl_stmt|,
name|wwnreadstat
decl_stmt|,
name|wwnreadec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnwread
decl_stmt|,
name|wwnwreade
decl_stmt|,
name|wwnwreadz
decl_stmt|,
name|wwnwreadd
decl_stmt|,
name|wwnwreadc
decl_stmt|,
name|wwnwreadp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wwnselect
decl_stmt|,
name|wwnselecte
decl_stmt|,
name|wwnselectz
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

begin_define
define|#
directive|define
name|wwupdate
parameter_list|()
value|wwupdate1(0, wwnrow);
end_define

begin_comment
comment|/* things for handling input */
end_comment

begin_function_decl
name|void
name|wwrint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* interrupt handler */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|wwcurwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* window to copy input into */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwib
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input (keyboard) buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwibe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wwib + sizeof buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwibp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current read position in buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|wwibq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current write position in buffer */
end_comment

begin_define
define|#
directive|define
name|wwmaskc
parameter_list|(
name|c
parameter_list|)
value|((c)& 0xff)
end_define

begin_define
define|#
directive|define
name|wwgetc
parameter_list|()
value|(wwibp< wwibq ? wwmaskc(*wwibp++) : -1)
end_define

begin_define
define|#
directive|define
name|wwpeekc
parameter_list|()
value|(wwibp< wwibq ? wwmaskc(*wwibp) : -1)
end_define

begin_define
define|#
directive|define
name|wwungetc
parameter_list|(
name|c
parameter_list|)
value|(wwibp> wwib ? *--wwibp = (c) : -1)
end_define

begin_comment
comment|/* things for short circuiting wwiomux() */
end_comment

begin_decl_stmt
name|char
name|wwintr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupting */
end_comment

begin_decl_stmt
name|char
name|wwsetjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* want a longjmp() from wwrint() and wwchild() */
end_comment

begin_decl_stmt
name|jmp_buf
name|wwjmpbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* jmpbuf for above */
end_comment

begin_define
define|#
directive|define
name|wwinterrupt
parameter_list|()
value|wwintr
end_define

begin_define
define|#
directive|define
name|wwsetintr
parameter_list|()
value|do { wwintr = 1; if (wwsetjmp) longjmp(wwjmpbuf, 1); } \ 			while (0)
end_define

begin_define
define|#
directive|define
name|wwclrintr
parameter_list|()
value|(wwintr = 0)
end_define

begin_comment
comment|/* checkpointing */
end_comment

begin_decl_stmt
name|int
name|wwdocheckpoint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window virtual terminal */
end_comment

begin_define
define|#
directive|define
name|WWT_TERM
value|"window-v2"
end_define

begin_define
define|#
directive|define
name|WWT_TERMCAP
value|"WW|window-v2|window program version 2:\ 	:am:bs:da:db:ms:pt:cr=^M:nl=^J:bl=^G:ta=^I:\ 	:cm=\\EY%+ %+ :le=^H:nd=\\EC:up=\\EA:do=\\EB:ho=\\EH:\ 	:cd=\\EJ:ce=\\EK:cl=\\EE:me=\\Er^?:"
end_define

begin_define
define|#
directive|define
name|WWT_REV
value|"se=\\ErA:so=\\EsA:mr=\\EsA:"
end_define

begin_define
define|#
directive|define
name|WWT_BLK
value|"BE=\\ErB:BS=\\EsB:mb=\\EsB:"
end_define

begin_define
define|#
directive|define
name|WWT_UL
value|"ue=\\ErD:us=\\EsD:"
end_define

begin_define
define|#
directive|define
name|WWT_GRP
value|"ae=\\ErH:as=\\EsH:"
end_define

begin_define
define|#
directive|define
name|WWT_DIM
value|"HE=\\ErP:HS=\\EsP:mh=\\EsP:"
end_define

begin_define
define|#
directive|define
name|WWT_USR
value|"XE=\\Er`:XS=\\Es`:"
end_define

begin_define
define|#
directive|define
name|WWT_ALDL
value|"al=\\EL:dl=\\EM:"
end_define

begin_define
define|#
directive|define
name|WWT_IMEI
value|"im=\\E@:ei=\\EO:ic=:mi:"
end_define

begin_comment
comment|/* XXX, ic for emacs bug */
end_comment

begin_define
define|#
directive|define
name|WWT_IC
value|"ic=\\EP:"
end_define

begin_define
define|#
directive|define
name|WWT_DC
value|"dc=\\EN:"
end_define

begin_decl_stmt
name|char
name|wwwintermcap
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal-specific but window-independent 				   part of the window termcap */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TERMINFO
end_ifdef

begin_comment
comment|/* where to put the temporary terminfo directory */
end_comment

begin_decl_stmt
name|char
name|wwterminfopath
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|wwchild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wwalarm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wwquit
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

end_unit

