begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b remote monitor - private header  *	-----------------------------------  *  *	$Id: monprivate.h,v 1.10 1999/12/13 21:25:26 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:52:25 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	definitions in i4b_ioctl.h, do something for other systems  *---------------------------------------------------------------------------*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FOREIGN
value|1
end_define

begin_comment
comment|/* we are running on a "foreign" OS */
end_comment

begin_define
define|#
directive|define
name|I4B_TIME_FORMAT
value|"%d.%m.%Y %H:%M:%S"
end_define

begin_define
define|#
directive|define
name|VERSION
value|0
end_define

begin_define
define|#
directive|define
name|REL
value|0
end_define

begin_define
define|#
directive|define
name|STEP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	some general definitions  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|GOOD
value|0
end_define

begin_comment
comment|/* general "good" or "ok" return*/
end_comment

begin_define
define|#
directive|define
name|ERROR
value|(-1)
end_define

begin_comment
comment|/* general error return		*/
end_comment

begin_define
define|#
directive|define
name|WARNING
value|(-2)
end_define

begin_comment
comment|/* warning return		*/
end_comment

begin_define
define|#
directive|define
name|INVALID
value|(-1)
end_define

begin_comment
comment|/* an invalid integer		*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state definitions  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|ST_INIT
value|0
end_define

begin_comment
comment|/* initial data */
end_comment

begin_define
define|#
directive|define
name|ST_ICTRL
value|1
end_define

begin_comment
comment|/* initial controller list */
end_comment

begin_define
define|#
directive|define
name|ST_IDEV
value|2
end_define

begin_comment
comment|/* initial entry devicename list */
end_comment

begin_define
define|#
directive|define
name|ST_ANYEV
value|3
end_define

begin_comment
comment|/* any event */
end_comment

begin_define
define|#
directive|define
name|ST_RIGHT
value|4
end_define

begin_comment
comment|/* one record in a list of monitor rights */
end_comment

begin_define
define|#
directive|define
name|ST_CONNS
value|5
end_define

begin_comment
comment|/* monitor connections */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	curses fullscreen display definitions  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* window dimensions */
end_comment

begin_define
define|#
directive|define
name|UPPER_B
value|2
end_define

begin_comment
comment|/* upper window start  */
end_comment

begin_comment
comment|/* horizontal positions for upper window */
end_comment

begin_define
define|#
directive|define
name|H_CNTL
value|0
end_define

begin_comment
comment|/* controller		*/
end_comment

begin_define
define|#
directive|define
name|H_TEI
value|2
end_define

begin_comment
comment|/* TEI			*/
end_comment

begin_define
define|#
directive|define
name|H_CHAN
value|(H_TEI+4)
end_define

begin_comment
comment|/* channel		*/
end_comment

begin_define
define|#
directive|define
name|H_TELN
value|(H_CHAN+2)
end_define

begin_comment
comment|/* telephone number	*/
end_comment

begin_define
define|#
directive|define
name|H_IFN
value|(H_TELN+23)
end_define

begin_comment
comment|/* interfacename	*/
end_comment

begin_define
define|#
directive|define
name|H_IO
value|(H_IFN+7)
end_define

begin_comment
comment|/* incoming or outgoing */
end_comment

begin_define
define|#
directive|define
name|H_OUT
value|(H_IO+4)
end_define

begin_comment
comment|/* # of bytes out	*/
end_comment

begin_define
define|#
directive|define
name|H_OUTBPS
value|(H_OUT+11)
end_define

begin_comment
comment|/* bytes per second out	*/
end_comment

begin_define
define|#
directive|define
name|H_IN
value|(H_OUTBPS+5)
end_define

begin_comment
comment|/* # of bytes in	*/
end_comment

begin_define
define|#
directive|define
name|H_INBPS
value|(H_IN+11)
end_define

begin_comment
comment|/* bytes per second in	*/
end_comment

begin_define
define|#
directive|define
name|H_UNITS
value|(H_INBPS+6)
end_define

begin_comment
comment|/* # of charging units	*/
end_comment

begin_comment
comment|/* fullscreen mode menu window */
end_comment

begin_define
define|#
directive|define
name|WMENU_LEN
value|35
end_define

begin_comment
comment|/* width of menu window */
end_comment

begin_define
define|#
directive|define
name|WMENU_TITLE
value|"Command"
end_define

begin_comment
comment|/* title string */
end_comment

begin_define
define|#
directive|define
name|WMENU_POSLN
value|10
end_define

begin_comment
comment|/* menu position, line */
end_comment

begin_define
define|#
directive|define
name|WMENU_POSCO
value|5
end_define

begin_comment
comment|/* menu position, col */
end_comment

begin_define
define|#
directive|define
name|WMITEMS
value|4
end_define

begin_comment
comment|/* no of menu items */
end_comment

begin_define
define|#
directive|define
name|WMENU_HGT
value|(WMITEMS + 4)
end_define

begin_comment
comment|/* menu window height */
end_comment

begin_define
define|#
directive|define
name|WREFRESH
value|0
end_define

begin_define
define|#
directive|define
name|WHANGUP
value|1
end_define

begin_define
define|#
directive|define
name|WREREAD
value|2
end_define

begin_define
define|#
directive|define
name|WQUIT
value|3
end_define

begin_define
define|#
directive|define
name|WMTIMEOUT
value|5
end_define

begin_comment
comment|/* timeout in seconds */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	misc  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CHPOS
parameter_list|(
name|uctlr
parameter_list|,
name|uchan
parameter_list|)
value|(((uctlr)*2) + (uchan))
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	remote state  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|MAX_CTRL
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|remstate
block|{
name|int
name|ch1state
decl_stmt|;
name|int
name|ch2state
decl_stmt|;
block|}
name|remstate_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	global variables  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
name|remstate_t
name|remstate
index|[
name|MAX_CTRL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nctrl
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of controllers available */
end_comment

begin_decl_stmt
name|int
name|curses_ready
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curses initialized */
end_comment

begin_decl_stmt
name|int
name|do_bell
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nentries
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fullscreen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug_noscreen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_decl_stmt
name|WINDOW
modifier|*
name|upper_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curses upper window pointer */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|mid_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curses mid window pointer */
end_comment

begin_decl_stmt
name|WINDOW
modifier|*
name|lower_w
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* curses lower window pointer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|devbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sockpath
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hostname
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|portno
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MAIN */
end_comment

begin_decl_stmt
name|remstate_t
name|remstate
index|[
name|MAX_CTRL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nctrl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curses_ready
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_bell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nentries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fullscreen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug_noscreen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|upper_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|mid_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|lower_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|devbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sockpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|hostname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|portno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|do_exit
parameter_list|(
name|int
name|exitval
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
name|display_charge
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|charge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_ccharge
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|units
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_connect
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|dir
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|remtel
parameter_list|,
name|char
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_acct
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|obyte
parameter_list|,
name|int
name|obps
parameter_list|,
name|int
name|ibyte
parameter_list|,
name|int
name|ibps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_disconnect
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_updown
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|updown
parameter_list|,
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_l12stat
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|layer
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_tei
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|tei
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

begin_function_decl
specifier|extern
name|void
name|hangup
parameter_list|(
name|int
name|ctrl
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

end_unit

