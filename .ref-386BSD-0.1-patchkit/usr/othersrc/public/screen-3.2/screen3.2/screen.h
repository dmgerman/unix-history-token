begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1991  *      Juergen Weigert (jnweiger@immd4.informatik.uni-erlangen.de)  *      Michael Schroeder (mlschroe@immd4.informatik.uni-erlangen.de)  * Copyright (c) 1987 Oliver Laumann  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 1, or (at your option)  * any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program (see the file COPYING); if not, write to the  * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  *  * Noteworthy contributors to screen's design and implementation:  *	Wayne Davison (davison@borland.com)  *	Patrick Wolfe (pat@kai.com, kailand!pat)  *	Bart Schaefer (schaefer@cse.ogi.edu)  *	Nathan Glasser (nathan@brokaw.lcs.mit.edu)  *	Larry W. Virden (lwv27%cas.BITNET@CUNYVM.CUNY.Edu)  *	Howard Chu (hyc@hanauma.jpl.nasa.gov)  *	Tim MacKenzie (tym@dibbler.cs.monash.edu.au)  *	Markku Jarvinen (mta@{cc,cs,ee}.tut.fi)  *	Marc Boucher (marc@CAM.ORG)  *  ****************************************************************  * $Id: screen.h,v 1.2 92/02/03 02:28:13 jnweiger Exp $ FAU  */
end_comment

begin_comment
comment|/* screen.h now includes enough to satisfy its own references.  * only config.h is still needed.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ENAMETOOLONG
end_ifdef

begin_undef
undef|#
directive|undef
name|ENAMETOOLONG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENOTEMPTY
end_ifdef

begin_undef
undef|#
directive|undef
name|ENOTEMPTY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|getpgrp
value|__getpgrp
end_define

begin_define
define|#
directive|define
name|exit
value|__exit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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
name|sun
end_ifdef

begin_undef
undef|#
directive|undef
name|getpgrp
end_undef

begin_undef
undef|#
directive|undef
name|exit
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_include
include|#
directive|include
file|<bsdtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|sequent
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|strlen
value|___strlen___
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_undef
undef|#
directive|undef
name|strlen
end_undef

begin_function_decl
specifier|extern
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|TIOCGWINSZ
argument_list|)
operator|||
name|defined
argument_list|(
name|TIOCSWINSZ
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUIDROOT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|LOCKPTY
end_ifdef

begin_undef
undef|#
directive|undef
name|LOCKPTY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UTMPOK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|USRLIMIT
end_ifdef

begin_undef
undef|#
directive|undef
name|USRLIMIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOGINDEFAULT
end_ifndef

begin_define
define|#
directive|define
name|LOGINDEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOADAV_3DOUBLES
argument_list|)
operator|||
name|defined
argument_list|(
name|LOADAV_3LONGS
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|LOADAV_4LONGS
argument_list|)
operator|||
name|defined
argument_list|(
name|LOADAV_NEXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOADAV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FSCALE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|FSCALE
value|256
end_define

begin_comment
comment|/* MIPS doesn't, and... */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_define
define|#
directive|define
name|FSCALE
value|1024.0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSCALE
value|1000.0
end_define

begin_comment
comment|/* Sequent doesn't define FSCALE...grrrr */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|F_OK
end_ifndef

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_OK
end_ifndef

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|R_OK
end_ifndef

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATH
end_ifndef

begin_define
define|#
directive|define
name|MAXPATH
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_T_DEFINED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SIGVOID
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|sig_t
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* nice compilers: */
end_comment

begin_typedef
typedef|typedef
name|void
name|sig_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|sig_t
typedef|;
end_typedef

begin_comment
comment|/* (* sig_t) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_T_DEFINED */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
name|defined
argument_list|(
name|ISC
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__386BSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|SIGPROTOARG
value|(int)
end_define

begin_define
define|#
directive|define
name|SIGDEFARG
value|int sigsig
end_define

begin_define
define|#
directive|define
name|SIGARG
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGPROTOARG
value|(void)
end_define

begin_define
define|#
directive|define
name|SIGDEFARG
end_define

begin_define
define|#
directive|define
name|SIGARG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|POSIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|apollo
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|sysV68
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PID_T_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PID_T_DEFINED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_XENIX
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UTMPOK
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_if

begin_define
define|#
directive|define
name|GETUTENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GETUTENT
end_ifdef

begin_typedef
typedef|typedef
name|char
modifier|*
name|slot_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|slot_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sequent
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_comment
comment|/* jw. */
end_comment

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|poi
parameter_list|,
name|len
parameter_list|)
value|memset(poi,0,len)
end_define

begin_define
define|#
directive|define
name|killpg
parameter_list|(
name|pgrp
parameter_list|,
name|sig
parameter_list|)
value|kill( -(pgrp), sig)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|ISC
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|O_NDELAY
end_ifndef

begin_define
define|#
directive|define
name|O_NDELAY
value|O_NONBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* here comes my own Free: jw. */
end_comment

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|a
parameter_list|)
value|{if ((a) == 0) abort(); else free((void *)(a)); (a)=0;}
end_define

begin_define
define|#
directive|define
name|Ctrl
parameter_list|(
name|c
parameter_list|)
value|((c)&037)
end_define

begin_comment
comment|/* modes for markroutine   */
end_comment

begin_define
define|#
directive|define
name|PLAIN
value|0
end_define

begin_define
define|#
directive|define
name|TRICKY
value|1
end_define

begin_define
define|#
directive|define
name|CRAZY
value|2
end_define

begin_comment
comment|/* should rather be TAXY or MAHEM though... */
end_comment

begin_comment
comment|/*typedef long off_t; */
end_comment

begin_comment
comment|/* Someone might need this */
end_comment

begin_enum
enum|enum
name|state_t
block|{
name|LIT
block|,
comment|/* Literal input */
name|ESC
block|,
comment|/* Start of escape sequence */
name|ASTR
block|,
comment|/* Start of control string */
name|STRESC
block|,
comment|/* ESC seen in control string */
name|CSI
block|,
comment|/* Reading arguments in "CSI Pn ; Pn ; ... ; XXX" */
name|PRIN
block|,
comment|/* Printer mode */
name|PRINESC
block|,
comment|/* ESC seen in printer mode */
name|PRINCSI
block|,
comment|/* CSI seen in printer mode */
name|PRIN4
comment|/* CSI 4 seen in printer mode */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|string_t
block|{
name|NONE
block|,
name|DCS
block|,
comment|/* Device control string */
name|OSC
block|,
comment|/* Operating system command */
name|APC
block|,
comment|/* Application program command */
name|PM
block|,
comment|/* Privacy message */
name|AKA
comment|/* a.k.a. for current screen */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MAXSTR
value|256
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|64
end_define

begin_define
define|#
directive|define
name|MSGWAIT
value|5
end_define

begin_define
define|#
directive|define
name|MSGMINWAIT
value|1
end_define

begin_comment
comment|/*   * 4<= IOSIZE<=1000  * you may try to vary this value. Use low values if your (VMS) system  * tends to choke when pasting. Use high values if you want to test  * how many characters your pty's can buffer.  */
end_comment

begin_define
define|#
directive|define
name|IOSIZE
value|80
end_define

begin_comment
comment|/*  * if a nasty user really wants to try a history of 2000 lines on all 10  * windows, he will allocate 5 MegaBytes of memory, which is quite enough.  */
end_comment

begin_define
define|#
directive|define
name|MAXHISTHEIGHT
value|3000
end_define

begin_define
define|#
directive|define
name|DEFAULTHISTHEIGHT
value|100
end_define

begin_struct
struct|struct
name|win
block|{
name|int
name|wpid
decl_stmt|;
comment|/* process, that is connected to the other end of ptyfd */
name|int
name|ptyfd
decl_stmt|;
comment|/* usually the master side of our pty pair */
name|int
name|ttyflag
decl_stmt|;
comment|/* 1 if ptyfd is connected to a user specified tty. */
name|int
name|aflag
decl_stmt|;
name|char
name|outbuf
index|[
name|IOSIZE
index|]
decl_stmt|;
name|int
name|outlen
decl_stmt|;
name|int
name|autoaka
decl_stmt|,
name|akapos
decl_stmt|;
name|char
name|cmd
index|[
name|MAXSTR
index|]
decl_stmt|;
name|char
name|tty
index|[
name|MAXSTR
index|]
decl_stmt|;
name|int
name|args
index|[
name|MAXARGS
index|]
decl_stmt|;
name|int
name|NumArgs
decl_stmt|;
name|slot_t
name|slot
decl_stmt|;
name|char
modifier|*
modifier|*
name|image
decl_stmt|;
name|char
modifier|*
modifier|*
name|attr
decl_stmt|;
name|char
modifier|*
modifier|*
name|font
decl_stmt|;
name|int
name|LocalCharset
decl_stmt|;
name|int
name|charsets
index|[
literal|4
index|]
decl_stmt|;
name|int
name|ss
decl_stmt|;
name|int
name|active
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|char
name|LocalAttr
decl_stmt|;
name|int
name|saved
decl_stmt|;
name|int
name|Saved_x
decl_stmt|,
name|Saved_y
decl_stmt|;
name|char
name|SavedLocalAttr
decl_stmt|;
name|int
name|SavedLocalCharset
decl_stmt|;
name|int
name|SavedCharsets
index|[
literal|4
index|]
decl_stmt|;
name|int
name|top
decl_stmt|,
name|bot
decl_stmt|;
name|int
name|wrap
decl_stmt|;
name|int
name|origin
decl_stmt|;
name|int
name|insert
decl_stmt|;
name|int
name|keypad
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width AND height, as we have now resized wins. jw.*/
name|int
name|histheight
decl_stmt|;
comment|/* all histbases are malloced with width * histheight */
name|int
name|histidx
decl_stmt|;
comment|/* 0=< histidx< histheight; where we insert lines */
name|char
modifier|*
modifier|*
name|ihist
decl_stmt|;
comment|/* the history buffer  image */
name|char
modifier|*
modifier|*
name|ahist
decl_stmt|;
comment|/* attributes */
name|char
modifier|*
modifier|*
name|fhist
decl_stmt|;
comment|/* fonts */
name|enum
name|state_t
name|state
decl_stmt|;
name|enum
name|string_t
name|StringType
decl_stmt|;
name|char
name|string
index|[
name|MAXSTR
index|]
decl_stmt|;
name|char
modifier|*
name|stringp
decl_stmt|;
name|char
modifier|*
name|tabs
decl_stmt|;
name|int
name|vbwait
decl_stmt|;
name|int
name|bell
decl_stmt|;
name|int
name|flow
decl_stmt|;
name|int
name|WinLink
decl_stmt|;
name|FILE
modifier|*
name|logfp
decl_stmt|;
name|int
name|monitor
decl_stmt|;
name|int
name|cursor_invisible
decl_stmt|;
name|int
name|norefresh
decl_stmt|;
comment|/* we dont redisplay when switching to that win */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for flow  *   000  -(-)  *   001  +(-)  *   010  -(+)  *   011  +(+)  *   100  -(a)  *   111  +(a)  */
end_comment

begin_define
define|#
directive|define
name|FLOW_NOW
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FLOW_AUTO
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FLOW_AUTOFLAG
value|(1<<2)
end_define

begin_comment
comment|/*  * Parameters for the Detach() routine  */
end_comment

begin_define
define|#
directive|define
name|D_DETACH
value|0
end_define

begin_define
define|#
directive|define
name|D_STOP
value|1
end_define

begin_define
define|#
directive|define
name|D_REMOTE
value|2
end_define

begin_define
define|#
directive|define
name|D_POWER
value|3
end_define

begin_define
define|#
directive|define
name|D_REMOTE_POWER
value|4
end_define

begin_define
define|#
directive|define
name|D_LOCK
value|5
end_define

begin_comment
comment|/*  * Here are the messages the attacher sends to the backend  */
end_comment

begin_define
define|#
directive|define
name|MSG_CREATE
value|0
end_define

begin_define
define|#
directive|define
name|MSG_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|MSG_ATTACH
value|2
end_define

begin_define
define|#
directive|define
name|MSG_CONT
value|3
end_define

begin_define
define|#
directive|define
name|MSG_DETACH
value|4
end_define

begin_define
define|#
directive|define
name|MSG_POW_DETACH
value|5
end_define

begin_define
define|#
directive|define
name|MSG_WINCH
value|6
end_define

begin_define
define|#
directive|define
name|MSG_HANGUP
value|7
end_define

begin_struct
struct|struct
name|msg
block|{
name|int
name|type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|int
name|lflag
decl_stmt|;
name|int
name|aflag
decl_stmt|;
name|int
name|flowflag
decl_stmt|;
name|int
name|hheight
decl_stmt|;
comment|/* size of scrollback buffer */
name|int
name|nargs
decl_stmt|;
name|char
name|line
index|[
name|MAXPATH
index|]
decl_stmt|;
name|char
name|dir
index|[
name|MAXPATH
index|]
decl_stmt|;
name|char
name|screenterm
index|[
literal|20
index|]
decl_stmt|;
comment|/* is screen really "screen" ? */
block|}
name|create
struct|;
struct|struct
block|{
name|int
name|apid
decl_stmt|;
name|int
name|adaptflag
decl_stmt|;
comment|/* do we wish to adapt window size? */
name|int
name|lines
decl_stmt|,
name|columns
decl_stmt|;
name|char
name|tty
index|[
name|MAXPATH
index|]
decl_stmt|;
name|char
name|password
index|[
literal|20
index|]
decl_stmt|;
name|char
name|envterm
index|[
name|MAXPATH
index|]
decl_stmt|;
block|}
name|attach
struct|;
struct|struct
block|{
name|char
name|password
index|[
literal|20
index|]
decl_stmt|;
name|int
name|dpid
decl_stmt|;
name|char
name|tty
index|[
name|MAXPATH
index|]
decl_stmt|;
block|}
name|detach
struct|;
name|char
name|message
index|[
name|MAXPATH
operator|*
literal|2
index|]
decl_stmt|;
block|}
name|m
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * And the signals the attacher receives from the backend  */
end_comment

begin_define
define|#
directive|define
name|SIG_BYE
value|SIGHUP
end_define

begin_define
define|#
directive|define
name|SIG_POWER_BYE
value|SIGUSR1
end_define

begin_define
define|#
directive|define
name|SIG_LOCK
value|SIGUSR2
end_define

begin_define
define|#
directive|define
name|SIG_STOP
value|SIGTSTP
end_define

begin_define
define|#
directive|define
name|SIG_PW_OK
value|SIGUSR1
end_define

begin_define
define|#
directive|define
name|SIG_PW_FAIL
value|SIG_BYE
end_define

begin_struct
struct|struct
name|mode
block|{
ifdef|#
directive|ifdef
name|POSIX
name|struct
name|termios
name|tio
decl_stmt|;
ifdef|#
directive|ifdef
name|hpux
name|struct
name|ltchars
name|m_ltchars
decl_stmt|;
endif|#
directive|endif
else|#
directive|else
ifdef|#
directive|ifdef
name|TERMIO
name|struct
name|termio
name|tio
decl_stmt|;
else|#
directive|else
name|struct
name|sgttyb
name|m_ttyb
decl_stmt|;
name|struct
name|tchars
name|m_tchars
decl_stmt|;
name|struct
name|ltchars
name|m_ltchars
decl_stmt|;
name|int
name|m_ldisc
decl_stmt|;
name|int
name|m_lmode
decl_stmt|;
endif|#
directive|endif
comment|/* TERMIO */
endif|#
directive|endif
comment|/* POSIX */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BELL
value|7
end_define

begin_define
define|#
directive|define
name|VBELLWAIT
value|1
end_define

begin_comment
comment|/* No. of seconds a vbell will be displayed */
end_comment

begin_define
define|#
directive|define
name|BELL_OFF
value|0
end_define

begin_comment
comment|/* No bell has occurred in the window */
end_comment

begin_define
define|#
directive|define
name|BELL_ON
value|1
end_define

begin_comment
comment|/* A bell has occurred, but user not yet notified */
end_comment

begin_define
define|#
directive|define
name|BELL_DONE
value|2
end_define

begin_comment
comment|/* A bell has occured, user has been notified */
end_comment

begin_define
define|#
directive|define
name|BELL_VISUAL
value|3
end_define

begin_comment
comment|/* A bell has occured in fore win, notify him visually */
end_comment

begin_define
define|#
directive|define
name|MON_OFF
value|0
end_define

begin_comment
comment|/* Monitoring is off in the window */
end_comment

begin_define
define|#
directive|define
name|MON_ON
value|1
end_define

begin_comment
comment|/* No activity has occurred in the window */
end_comment

begin_define
define|#
directive|define
name|MON_FOUND
value|2
end_define

begin_comment
comment|/* Activity has occured, but user not yet notified */
end_comment

begin_define
define|#
directive|define
name|MON_DONE
value|3
end_define

begin_comment
comment|/* Activity has occured, user has been notified */
end_comment

begin_define
define|#
directive|define
name|DUMP_TERMCAP
value|0
end_define

begin_comment
comment|/* WriteFile() options */
end_comment

begin_define
define|#
directive|define
name|DUMP_HARDCOPY
value|1
end_define

begin_define
define|#
directive|define
name|DUMP_EXCHANGE
value|2
end_define

begin_undef
undef|#
directive|undef
name|MAXWIN20
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXWIN20
end_ifdef

begin_define
define|#
directive|define
name|MAXWIN
value|20
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXWIN
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the key definitions are used in screen.c and help.c */
end_comment

begin_comment
comment|/* keep this list synchronus with the names given in fileio.c */
end_comment

begin_enum
enum|enum
name|keytype
block|{
name|KEY_IGNORE
block|,
comment|/* Keep these first 2 at the start */
name|KEY_SCREEN
block|,
name|KEY_0
block|,
name|KEY_1
block|,
name|KEY_2
block|,
name|KEY_3
block|,
name|KEY_4
block|,
name|KEY_5
block|,
name|KEY_6
block|,
name|KEY_7
block|,
name|KEY_8
block|,
name|KEY_9
block|,
ifdef|#
directive|ifdef
name|MAXWIN20
name|KEY_10
block|,
name|KEY_11
block|,
name|KEY_12
block|,
name|KEY_13
block|,
name|KEY_14
block|,
name|KEY_15
block|,
name|KEY_16
block|,
name|KEY_17
block|,
name|KEY_18
block|,
name|KEY_19
block|,
endif|#
directive|endif
name|KEY_AKA
block|,
name|KEY_CLEAR
block|,
name|KEY_COLON
block|,
name|KEY_COPY
block|,
name|KEY_DETACH
block|,
name|KEY_FLOW
block|,
name|KEY_HARDCOPY
block|,
name|KEY_HELP
block|,
name|KEY_HISTNEXT
block|,
name|KEY_HISTORY
block|,
name|KEY_INFO
block|,
name|KEY_KILL
block|,
name|KEY_LASTMSG
block|,
name|KEY_LICENSE
block|,
name|KEY_LOCK
block|,
name|KEY_LOGTOGGLE
block|,
name|KEY_LOGIN
block|,
name|KEY_MONITOR
block|,
name|KEY_NEXT
block|,
name|KEY_OTHER
block|,
name|KEY_PASTE
block|,
name|KEY_POW_DETACH
block|,
name|KEY_PREV
block|,
name|KEY_QUIT
block|,
name|KEY_READ_BUFFER
block|,
name|KEY_REDISPLAY
block|,
name|KEY_REMOVE_BUFFERS
block|,
name|KEY_RESET
block|,
name|KEY_SET
block|,
name|KEY_SHELL
block|,
name|KEY_SUSPEND
block|,
name|KEY_TERMCAP
block|,
name|KEY_TIME
block|,
name|KEY_VBELL
block|,
name|KEY_VERSION
block|,
name|KEY_WIDTH
block|,
name|KEY_WINDOWS
block|,
name|KEY_WRAP
block|,
name|KEY_WRITE_BUFFER
block|,
name|KEY_XOFF
block|,
name|KEY_XON
block|,
name|KEY_EXTEND
block|,
name|KEY_X_WINDOWS
block|,
name|KEY_BONUSWINDOW
block|,
name|KEY_CREATE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|key
block|{
name|enum
name|keytype
name|type
decl_stmt|;
name|char
modifier|*
modifier|*
name|args
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NETHACK
end_ifdef

begin_define
define|#
directive|define
name|Msg_nomem
value|Msg(0, "You feel stupid.")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Msg_nomem
value|Msg(0, "Out of memory.")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
value|{fprintf(dfp,x);fflush(dfp);}
end_define

begin_define
define|#
directive|define
name|debug1
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|{fprintf(dfp,x,a);fflush(dfp);}
end_define

begin_define
define|#
directive|define
name|debug2
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|{fprintf(dfp,x,a,b);fflush(dfp);}
end_define

begin_define
define|#
directive|define
name|debug3
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{fprintf(dfp,x,a,b,c);fflush(dfp);}
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|dfp
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
value|{}
end_define

begin_define
define|#
directive|define
name|debug1
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|{}
end_define

begin_define
define|#
directive|define
name|debug2
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|{}
end_define

begin_define
define|#
directive|define
name|debug3
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|a
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|ruid
parameter_list|,
name|euid
parameter_list|)
value|setresuid(ruid, euid, -1)
end_define

begin_define
define|#
directive|define
name|setregid
parameter_list|(
name|rgid
parameter_list|,
name|egid
parameter_list|)
value|setresgid(rgid, egid, -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UTMPOK
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_include
include|#
directive|include
file|<utmpx.h>
end_include

begin_define
define|#
directive|define
name|UTMPFILE
value|UTMPX_FILE
end_define

begin_define
define|#
directive|define
name|utmp
value|utmpx
end_define

begin_define
define|#
directive|define
name|getutent
value|getutxent
end_define

begin_define
define|#
directive|define
name|getutid
value|getutxid
end_define

begin_define
define|#
directive|define
name|getutline
value|getutxline
end_define

begin_define
define|#
directive|define
name|pututline
value|pututxline
end_define

begin_define
define|#
directive|define
name|setutent
value|setutxent
end_define

begin_define
define|#
directive|define
name|endutent
value|endutxent
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SVR4 */
end_comment

begin_include
include|#
directive|include
file|<utmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UTMPFILE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|UTMP_FILE
end_ifdef

begin_define
define|#
directive|define
name|UTMPFILE
value|UTMP_FILE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSDI
end_ifdef

begin_define
define|#
directive|define
name|UTMPFILE
value|"/var/run/utmp"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UTMPFILE
value|"/etc/utmp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSDI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|RENO
argument_list|)
operator|||
name|defined
argument_list|(
name|xelos
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__386BSD__
end_ifndef

begin_define
define|#
directive|define
name|BSDWAIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

