begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)tip.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * tip - terminal interface program  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|HAVE_TERMIOS
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* for TIOCHPCL */
end_comment

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_comment
comment|/* for FIONREAD */
end_comment

begin_include
include|#
directive|include
file|<sys/termios.h>
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

begin_include
include|#
directive|include
file|<signal.h>
end_include

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
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Remote host attributes  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UNIX device(s) to open */
end_comment

begin_decl_stmt
name|char
modifier|*
name|EL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* chars marking an EOL */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial connection message */
end_comment

begin_decl_stmt
name|char
modifier|*
name|IE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EOT to expect on input */
end_comment

begin_decl_stmt
name|char
modifier|*
name|OE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EOT to send to complete FT */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* call unit if making a phone call */
end_comment

begin_decl_stmt
name|char
modifier|*
name|AT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* acu type */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* phone number(s) */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* disconnect string */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parity to be generated */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* phone number file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote file name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|HO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* login script */
end_comment

begin_decl_stmt
name|char
modifier|*
name|LO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logout script */
end_comment

begin_decl_stmt
name|long
name|BR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line speed for conversation */
end_comment

begin_decl_stmt
name|long
name|FS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frame size for transfers */
end_comment

begin_decl_stmt
name|char
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this host is dialed up */
end_comment

begin_decl_stmt
name|char
name|HW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this device is hardwired, see hunt.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* escape character */
end_comment

begin_decl_stmt
name|char
modifier|*
name|EX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exceptions */
end_comment

begin_decl_stmt
name|char
modifier|*
name|FO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force (literal next) char*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|RC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* raise character */
end_comment

begin_decl_stmt
name|char
modifier|*
name|RE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* script record file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|PR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote prompt */
end_comment

begin_decl_stmt
name|long
name|DL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line delay for file transfers to remote */
end_comment

begin_decl_stmt
name|long
name|CL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* char delay for file transfers to remote */
end_comment

begin_decl_stmt
name|long
name|ET
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* echocheck timeout */
end_comment

begin_decl_stmt
name|char
name|HD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this host is half duplex - do local echo */
end_comment

begin_comment
comment|/*  * String value table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|v_name
decl_stmt|;
comment|/* whose name is it */
name|char
name|v_type
decl_stmt|;
comment|/* for interpreting set's */
name|char
name|v_access
decl_stmt|;
comment|/* protection of touchy ones */
name|char
modifier|*
name|v_abrev
decl_stmt|;
comment|/* possible abreviation */
name|char
modifier|*
name|v_value
decl_stmt|;
comment|/* casted to a union later */
block|}
name|value_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|STRING
value|01
end_define

begin_comment
comment|/* string valued */
end_comment

begin_define
define|#
directive|define
name|BOOL
value|02
end_define

begin_comment
comment|/* true-false value */
end_comment

begin_define
define|#
directive|define
name|NUMBER
value|04
end_define

begin_comment
comment|/* numeric value */
end_comment

begin_define
define|#
directive|define
name|CHAR
value|010
end_define

begin_comment
comment|/* character value */
end_comment

begin_define
define|#
directive|define
name|WRITE
value|01
end_define

begin_comment
comment|/* write access to variable */
end_comment

begin_define
define|#
directive|define
name|READ
value|02
end_define

begin_comment
comment|/* read access */
end_comment

begin_define
define|#
directive|define
name|CHANGED
value|01
end_define

begin_comment
comment|/* low bit is used to show modification */
end_comment

begin_define
define|#
directive|define
name|PUBLIC
value|1
end_define

begin_comment
comment|/* public access rights */
end_comment

begin_define
define|#
directive|define
name|PRIVATE
value|03
end_define

begin_comment
comment|/* private to definer */
end_comment

begin_define
define|#
directive|define
name|ROOT
value|05
end_define

begin_comment
comment|/* root defined */
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
name|ENVIRON
value|020
end_define

begin_comment
comment|/* initialize out of the environment */
end_comment

begin_define
define|#
directive|define
name|IREMOTE
value|040
end_define

begin_comment
comment|/* initialize out of remote structure */
end_comment

begin_define
define|#
directive|define
name|INIT
value|0100
end_define

begin_comment
comment|/* static data space used for initialization */
end_comment

begin_define
define|#
directive|define
name|TMASK
value|017
end_define

begin_comment
comment|/*  * Definition of ACU line description  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|acu_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|acu_dialer
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|acu_disconnect
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|acu_abort
function_decl|)
parameter_list|()
function_decl|;
block|}
name|acu_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|equal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

begin_comment
comment|/* A nice function to string compare */
end_comment

begin_comment
comment|/*  * variable manipulation stuff --  *   if we defined the value entry in value_t, then we couldn't  *   initialize it in vars.c, so we cast it as needed to keep lint  *   happy.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|zz_number
decl_stmt|;
name|short
name|zz_boolean
index|[
literal|2
index|]
decl_stmt|;
name|char
name|zz_character
index|[
literal|4
index|]
decl_stmt|;
name|int
modifier|*
name|zz_address
decl_stmt|;
block|}
name|zzhack
typedef|;
end_typedef

begin_define
define|#
directive|define
name|value
parameter_list|(
name|v
parameter_list|)
value|vtable[v].v_value
end_define

begin_define
define|#
directive|define
name|number
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_number)
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|boolean
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_boolean[0])
end_define

begin_define
define|#
directive|define
name|character
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_character[0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|boolean
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_boolean[1])
end_define

begin_define
define|#
directive|define
name|character
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_character[3])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|address
parameter_list|(
name|v
parameter_list|)
value|((((zzhack *)(&(v))))->zz_address)
end_define

begin_comment
comment|/*  * Escape command table definitions --  *   lookup in this table is performed when ``escapec'' is recognized  *   at the begining of a line (as defined by the eolmarks variable). */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|e_char
decl_stmt|;
comment|/* char to match on */
name|char
name|e_flags
decl_stmt|;
comment|/* experimental, priviledged */
name|char
modifier|*
name|e_help
decl_stmt|;
comment|/* help string */
name|int
function_decl|(
modifier|*
name|e_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* command */
block|}
name|esctable_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NORM
value|00
end_define

begin_comment
comment|/* normal protection, execute anyone */
end_comment

begin_define
define|#
directive|define
name|EXP
value|01
end_define

begin_comment
comment|/* experimental, mark it with a `*' on help */
end_comment

begin_define
define|#
directive|define
name|PRIV
value|02
end_define

begin_comment
comment|/* priviledged, root execute only */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verbose during reading of .tiprc file */
end_comment

begin_decl_stmt
specifier|extern
name|value_t
name|vtable
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* variable table */
end_comment

begin_if
if|#
directive|if
operator|!
name|ACULOG
end_if

begin_define
define|#
directive|define
name|logent
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|loginit
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|logent
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definition of indices into variable table so  *  value(DEFINE) turns into a static address.  */
end_comment

begin_comment
comment|/* 'a,.!awk '{ printf("\%s \%s \%d\n", $1, $2, NR - 1); }' */
end_comment

begin_define
define|#
directive|define
name|BEAUTIFY
value|0
end_define

begin_define
define|#
directive|define
name|BAUDRATE
value|1
end_define

begin_define
define|#
directive|define
name|DIALTIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|EOFREAD
value|3
end_define

begin_define
define|#
directive|define
name|EOFWRITE
value|4
end_define

begin_define
define|#
directive|define
name|EOL
value|5
end_define

begin_define
define|#
directive|define
name|ESCAPE
value|6
end_define

begin_define
define|#
directive|define
name|EXCEPTIONS
value|7
end_define

begin_define
define|#
directive|define
name|FORCE
value|8
end_define

begin_define
define|#
directive|define
name|FRAMESIZE
value|9
end_define

begin_define
define|#
directive|define
name|HOST
value|10
end_define

begin_define
define|#
directive|define
name|LOG
value|11
end_define

begin_define
define|#
directive|define
name|LOGIN
value|12
end_define

begin_define
define|#
directive|define
name|LOGOUT
value|13
end_define

begin_define
define|#
directive|define
name|PHONES
value|14
end_define

begin_define
define|#
directive|define
name|PROMPT
value|15
end_define

begin_define
define|#
directive|define
name|RAISE
value|16
end_define

begin_define
define|#
directive|define
name|RAISECHAR
value|17
end_define

begin_define
define|#
directive|define
name|RECORD
value|18
end_define

begin_define
define|#
directive|define
name|REMOTE
value|19
end_define

begin_define
define|#
directive|define
name|SCRIPT
value|20
end_define

begin_define
define|#
directive|define
name|TABEXPAND
value|21
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|22
end_define

begin_define
define|#
directive|define
name|SHELL
value|23
end_define

begin_define
define|#
directive|define
name|HOME
value|24
end_define

begin_define
define|#
directive|define
name|ECHOCHECK
value|25
end_define

begin_define
define|#
directive|define
name|DISCONNECT
value|26
end_define

begin_define
define|#
directive|define
name|TAND
value|27
end_define

begin_define
define|#
directive|define
name|LDELAY
value|28
end_define

begin_define
define|#
directive|define
name|CDELAY
value|29
end_define

begin_define
define|#
directive|define
name|ETIMEOUT
value|30
end_define

begin_define
define|#
directive|define
name|RAWFTP
value|31
end_define

begin_define
define|#
directive|define
name|HALFDUPLEX
value|32
end_define

begin_define
define|#
directive|define
name|LECHO
value|33
end_define

begin_define
define|#
directive|define
name|PARITY
value|34
end_define

begin_define
define|#
directive|define
name|NOVAL
value|((value_t *)NULL)
end_define

begin_define
define|#
directive|define
name|NOACU
value|((acu_t *)NULL)
end_define

begin_define
define|#
directive|define
name|NOSTR
value|((char *)NULL)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOFILE
end_ifdef

begin_undef
undef|#
directive|undef
name|NOFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NOFILE
value|((FILE *)NULL)
end_define

begin_define
define|#
directive|define
name|NOPWD
value|((struct passwd *)0)
end_define

begin_if
if|#
directive|if
name|HAVE_TERMIOS
end_if

begin_decl_stmt
name|struct
name|termios
name|otermios
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|termios
name|ctermios
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_TERMIOS */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|arg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current mode of local terminal */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|defarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial mode of local terminal */
end_comment

begin_decl_stmt
name|struct
name|tchars
name|tchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current state of terminal */
end_comment

begin_decl_stmt
name|struct
name|tchars
name|defchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial state of terminal */
end_comment

begin_decl_stmt
name|struct
name|ltchars
name|ltchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current local characters of terminal */
end_comment

begin_decl_stmt
name|struct
name|ltchars
name|deflchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial local characters of terminal */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TERMIOS */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|fscript
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FILE for scripting */
end_comment

begin_decl_stmt
name|int
name|fildes
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file transfer synchronization channel */
end_comment

begin_decl_stmt
name|int
name|repdes
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read process sychronization channel */
end_comment

begin_decl_stmt
name|int
name|FD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open file descriptor to remote host */
end_comment

begin_decl_stmt
name|int
name|AC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* open file descriptor to dialer (v831 only) */
end_comment

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print .tiprc initialization sequence */
end_comment

begin_decl_stmt
name|int
name|sfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for ~< operation */
end_comment

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of tipout */
end_comment

begin_decl_stmt
name|uid_t
name|uid
decl_stmt|,
name|euid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real and effective user id's */
end_comment

begin_decl_stmt
name|gid_t
name|gid
decl_stmt|,
name|egid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* real and effective group id's */
end_comment

begin_decl_stmt
name|int
name|stop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stop transfer session flag */
end_comment

begin_decl_stmt
name|int
name|quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* same; but on other end */
end_comment

begin_decl_stmt
name|int
name|intflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recognized interrupt */
end_comment

begin_decl_stmt
name|int
name|stoprompt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for interrupting a prompt session */
end_comment

begin_decl_stmt
name|int
name|timedout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ~> transfer timedout */
end_comment

begin_decl_stmt
name|int
name|cumode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* simulating the "cu" program */
end_comment

begin_decl_stmt
name|char
name|fname
index|[
name|PATH_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name buffer for ~< */
end_comment

begin_decl_stmt
name|char
name|copyname
index|[
name|PATH_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name buffer for ~> */
end_comment

begin_decl_stmt
name|char
name|ccc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* synchronization character */
end_comment

begin_decl_stmt
name|char
name|ch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for tipout */
end_comment

begin_decl_stmt
name|char
modifier|*
name|uucplock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of lock file for uucp's */
end_comment

begin_decl_stmt
name|int
name|odisc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial tty line discipline */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|disc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current tty discpline */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctrl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|vinterp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|connect
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|size
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|any
name|__P
argument_list|(
operator|(
name|char
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setscript
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tipout
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|loginit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hunt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vstring
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setparity
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|vlex
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|daemon_uid
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|disconnect
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|shell_uid
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|unraw
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|xpwrite
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|prompt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|consh
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tipabort
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TL_VERBOSE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TL_SIGNAL_TIPOUT
value|0x00000002
end_define

begin_function_decl
name|int
name|tiplink
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|raw
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end of tip.h */
end_comment

end_unit

