begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	isdntel - isdn4bsd telephone answering support  *      ==============================================  *  *	$Id: defs.h,v 1.10 1999/12/13 21:25:26 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:53:50 1999]  *  *----------------------------------------------------------------------------*/
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
file|<stdarg.h>
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
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|SPOOLDIR
value|"/var/isdn"
end_define

begin_define
define|#
directive|define
name|PLAYCMD
value|"cat %s | g711conv -a>/dev/audio"
end_define

begin_comment
comment|/* reread timeout in seconds */
end_comment

begin_define
define|#
directive|define
name|REREADTIMEOUT
value|60
end_define

begin_comment
comment|/* window dimensions */
end_comment

begin_define
define|#
directive|define
name|START_O
value|3
end_define

begin_comment
comment|/* main window start  */
end_comment

begin_define
define|#
directive|define
name|DAT_POS
value|0
end_define

begin_define
define|#
directive|define
name|TIM_POS
value|(DAT_POS+10)
end_define

begin_define
define|#
directive|define
name|DST_POS
value|(TIM_POS+8)
end_define

begin_define
define|#
directive|define
name|SRC_POS
value|(DST_POS+17)
end_define

begin_define
define|#
directive|define
name|ALI_POS
value|(SRC_POS+17)
end_define

begin_define
define|#
directive|define
name|SEC_POS
value|(ALI_POS+21)
end_define

begin_define
define|#
directive|define
name|LAST_POS
value|(SEC_POS+5)
end_define

begin_comment
comment|/* fullscreen mode menu window */
end_comment

begin_define
define|#
directive|define
name|WMITEMS
value|5
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

begin_struct
struct|struct
name|onefile
block|{
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* filename */
name|char
modifier|*
name|date
decl_stmt|;
name|char
modifier|*
name|time
decl_stmt|;
name|char
modifier|*
name|srcnumber
decl_stmt|;
name|char
modifier|*
name|dstnumber
decl_stmt|;
name|char
modifier|*
name|seconds
decl_stmt|;
name|char
modifier|*
name|alias
decl_stmt|;
name|int
name|len
decl_stmt|;
name|struct
name|onefile
modifier|*
name|next
decl_stmt|;
comment|/* ptr to next entry */
name|struct
name|onefile
modifier|*
name|prev
decl_stmt|;
comment|/* prt to previous entry */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

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
name|struct
name|onefile
modifier|*
name|cur_file
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the CURRENT filename */
end_comment

begin_decl_stmt
name|struct
name|onefile
modifier|*
name|first
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* init dir-list head-ptr */
end_comment

begin_decl_stmt
name|struct
name|onefile
modifier|*
name|last
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* init dir-list tail-ptr */
end_comment

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
name|int
name|nofiles
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cur_pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|spooldir
init|=
name|SPOOLDIR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|playstring
init|=
name|PLAYCMD
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|curses_ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|onefile
modifier|*
name|cur_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|onefile
modifier|*
name|first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|onefile
modifier|*
name|last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|main_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nofiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cur_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|spooldir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|playstring
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|init_alias
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_files
parameter_list|(
name|int
name|inipos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_screen
parameter_list|(
name|void
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
name|fill_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_alias
parameter_list|(
name|char
modifier|*
name|number
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
name|error
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
name|play
parameter_list|(
name|struct
name|onefile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete
parameter_list|(
name|struct
name|onefile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EOF */
end_comment

end_unit

