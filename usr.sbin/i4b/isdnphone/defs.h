begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	isdnphone - header file  *      =======================  *  *	$Id: defs.h,v 1.6 1999/12/13 21:25:26 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:52:46 1999]  *  *----------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/soundcard.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_tel_ioctl.h>
end_include

begin_comment
comment|/* device file prefixes */
end_comment

begin_define
define|#
directive|define
name|I4BTELDEVICE
value|"/dev/i4btel"
end_define

begin_define
define|#
directive|define
name|I4BTELDDEVICE
value|"/dev/i4bteld"
end_define

begin_define
define|#
directive|define
name|AUDIODEVICE
value|"/dev/audio"
end_define

begin_define
define|#
directive|define
name|GOOD
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|(-1)
end_define

begin_define
define|#
directive|define
name|WARNING
value|(-2)
end_define

begin_comment
comment|/* main window dimensions */
end_comment

begin_define
define|#
directive|define
name|MW_ROW
value|5
end_define

begin_define
define|#
directive|define
name|MW_COL
value|8
end_define

begin_define
define|#
directive|define
name|MW_WIDTH
value|60
end_define

begin_define
define|#
directive|define
name|MW_HEIGHT
value|8
end_define

begin_define
define|#
directive|define
name|DB_ROW
value|15
end_define

begin_define
define|#
directive|define
name|DB_COL
value|1
end_define

begin_define
define|#
directive|define
name|DB_WID
value|79
end_define

begin_define
define|#
directive|define
name|DB_HGT
value|9
end_define

begin_define
define|#
directive|define
name|MW_STATEY
value|2
end_define

begin_define
define|#
directive|define
name|MW_STATEX
value|1
end_define

begin_define
define|#
directive|define
name|MW_STX
value|10
end_define

begin_define
define|#
directive|define
name|MW_NUMY
value|4
end_define

begin_define
define|#
directive|define
name|MW_NUMX
value|1
end_define

begin_define
define|#
directive|define
name|MW_NUX
value|10
end_define

begin_define
define|#
directive|define
name|MW_MSGY
value|6
end_define

begin_define
define|#
directive|define
name|MW_MSGX
value|1
end_define

begin_define
define|#
directive|define
name|MW_MSX
value|10
end_define

begin_comment
comment|/* fullscreen mode menu window */
end_comment

begin_define
define|#
directive|define
name|WMITEMS
value|4
end_define

begin_comment
comment|/* no of items */
end_comment

begin_define
define|#
directive|define
name|WMENU_LEN
value|18
end_define

begin_comment
comment|/* window width */
end_comment

begin_define
define|#
directive|define
name|WMENU_HGT
value|(WMITEMS+4)
end_define

begin_comment
comment|/* window height */
end_comment

begin_define
define|#
directive|define
name|WMENU_TITLE
value|"Command"
end_define

begin_define
define|#
directive|define
name|WMENU_POSLN
value|8
end_define

begin_comment
comment|/* window position: lines */
end_comment

begin_define
define|#
directive|define
name|WMENU_POSCO
value|20
end_define

begin_comment
comment|/* window position: columns */
end_comment

begin_define
define|#
directive|define
name|CR
value|0x0d
end_define

begin_define
define|#
directive|define
name|LF
value|0x0a
end_define

begin_define
define|#
directive|define
name|TAB
value|0x09
end_define

begin_define
define|#
directive|define
name|CNTRL_D
value|0x04
end_define

begin_define
define|#
directive|define
name|CNTRL_L
value|0x0c
end_define

begin_define
define|#
directive|define
name|ST_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|ST_DIALING
value|1
end_define

begin_define
define|#
directive|define
name|ST_ACTIVE
value|2
end_define

begin_define
define|#
directive|define
name|ST_MAX
value|2
end_define

begin_define
define|#
directive|define
name|AUDIORATE
value|8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
name|WINDOW
modifier|*
name|main_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curses main window pointer */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|dbg_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curses_ready
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, curses display is initialized */
end_comment

begin_decl_stmt
name|int
name|state
init|=
name|ST_IDLE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|states
index|[]
init|=
block|{
literal|"IDLE"
block|,
literal|"DIALING"
block|,
literal|"ACTIVE"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dialerfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|audiofd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|telfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|numberbuffer
index|[
name|TELNO_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|play_fmt
init|=
name|AFMT_MU_LAW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rec_fmt
init|=
name|AFMT_MU_LAW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opt_unit
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opt_d
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|main_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|dbg_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curses_ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|states
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dialerfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|audiofd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|telfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|numberbuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|play_fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rec_fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opt_unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|opt_d
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|audio_hdlr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tel_hdlr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_mainw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_audio
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_menu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_quit
parameter_list|(
name|int
name|exitval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|message
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_dial
parameter_list|(
name|char
modifier|*
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_hangup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|audiowrite
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|telwrite
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|newstate
parameter_list|(
name|int
name|newstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_dial
parameter_list|(
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dial_hdlr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_tel
parameter_list|(
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EOF */
end_comment

end_unit

