begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: tip.h,v 1.11 2001/09/09 19:30:49 millert Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: tip.h,v 1.7 1997/04/20 00:02:46 mellon Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)tip.h	8.1 (Berkeley) 6/6/93  */
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
file|<termios.h>
end_include

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

begin_include
include|#
directive|include
file|<limits.h>
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
name|short
name|DU
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this host is dialed up */
end_comment

begin_decl_stmt
name|short
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
name|short
name|HD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this host is half duplex - do local echo */
end_comment

begin_decl_stmt
name|short
name|DC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this host is directly connected. */
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
specifier|const
name|char
modifier|*
name|acu_name
decl_stmt|;
name|int
argument_list|(
argument|*acu_dialer
argument_list|)
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
expr_stmt|;
name|void
argument_list|(
argument|*acu_disconnect
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*acu_abort
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
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
value|((long)(v))
end_define

begin_define
define|#
directive|define
name|boolean
parameter_list|(
name|v
parameter_list|)
value|((short)(long)(v))
end_define

begin_define
define|#
directive|define
name|character
parameter_list|(
name|v
parameter_list|)
value|((char)(long)(v))
end_define

begin_define
define|#
directive|define
name|address
parameter_list|(
name|v
parameter_list|)
value|((long *)(v))
end_define

begin_define
define|#
directive|define
name|setnumber
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|do { (v) = (char *)(long)(n); } while (0)
end_define

begin_define
define|#
directive|define
name|setboolean
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|do { (v) = (char *)(long)(n); } while (0)
end_define

begin_define
define|#
directive|define
name|setcharacter
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|do { (v) = (char *)(long)(n); } while (0)
end_define

begin_define
define|#
directive|define
name|setaddress
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|do { (v) = (char *)(n); } while (0)
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
specifier|const
name|char
modifier|*
name|e_help
decl_stmt|;
comment|/* help string */
name|int
argument_list|(
argument|*e_func
argument_list|)
name|__P
argument_list|(
operator|(
name|char
operator|)
argument_list|)
expr_stmt|;
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
name|int
name|noesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no escape `~' char */
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

begin_ifndef
ifndef|#
directive|ifndef
name|ACULOG
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definition of indices into variable table so  *  value(DEFINE) turns into a static address.  */
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
name|PHONES
value|12
end_define

begin_define
define|#
directive|define
name|PROMPT
value|13
end_define

begin_define
define|#
directive|define
name|RAISE
value|14
end_define

begin_define
define|#
directive|define
name|RAISECHAR
value|15
end_define

begin_define
define|#
directive|define
name|RECORD
value|16
end_define

begin_define
define|#
directive|define
name|REMOTE
value|17
end_define

begin_define
define|#
directive|define
name|SCRIPT
value|18
end_define

begin_define
define|#
directive|define
name|TABEXPAND
value|19
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|20
end_define

begin_define
define|#
directive|define
name|SHELL
value|21
end_define

begin_define
define|#
directive|define
name|HOME
value|22
end_define

begin_define
define|#
directive|define
name|ECHOCHECK
value|23
end_define

begin_define
define|#
directive|define
name|DISCONNECT
value|24
end_define

begin_define
define|#
directive|define
name|TAND
value|25
end_define

begin_define
define|#
directive|define
name|LDELAY
value|26
end_define

begin_define
define|#
directive|define
name|CDELAY
value|27
end_define

begin_define
define|#
directive|define
name|ETIMEOUT
value|28
end_define

begin_define
define|#
directive|define
name|RAWFTP
value|29
end_define

begin_define
define|#
directive|define
name|HALFDUPLEX
value|30
end_define

begin_define
define|#
directive|define
name|LECHO
value|31
end_define

begin_define
define|#
directive|define
name|PARITY
value|32
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

begin_decl_stmt
name|struct
name|termios
name|term
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current mode of terminal */
end_comment

begin_decl_stmt
name|struct
name|termios
name|defterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial mode of terminal */
end_comment

begin_decl_stmt
name|struct
name|termios
name|defchars
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current mode with initial chars */
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
name|noesc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no `~' escape char */
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
name|int
name|bits8
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terminal is is 8-bit mode */
end_comment

begin_define
define|#
directive|define
name|STRIP_PAR
value|(bits8 ? 0377 : 0177)
end_define

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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* program name */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ctrl
name|__P
argument_list|(
operator|(
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vinterp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|connect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|any
name|__P
argument_list|(
operator|(
name|int
name|cc
operator|,
name|char
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|anyof
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s1
operator|,
name|char
operator|*
name|s2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|char
operator|*
name|a
index|[]
operator|,
name|int
name|num
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|escape
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prompt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|char
operator|*
name|p
operator|,
name|size_t
name|sz
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|size
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|speed
name|__P
argument_list|(
operator|(
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_lock
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_unlock
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vstring
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|char
operator|*
name|v
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|hunt
name|__P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cumain
name|__P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|disconnect
name|__P
argument_list|(
operator|(
name|char
operator|*
name|reason
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|execute
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logent
name|__P
argument_list|(
operator|(
name|char
operator|*
name|group
operator|,
specifier|const
name|char
operator|*
name|num
operator|,
specifier|const
name|char
operator|*
name|acu
operator|,
specifier|const
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|prtime
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|time_t
name|a
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|parwrite
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|raw
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|send
name|__P
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setparity
name|__P
argument_list|(
operator|(
name|char
operator|*
name|defparity
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|tandem
name|__P
argument_list|(
operator|(
name|char
operator|*
name|option
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tipabort
name|__P
argument_list|(
operator|(
name|char
operator|*
name|msg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tipin
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|transfer
name|__P
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|int
name|fd
operator|,
name|char
operator|*
name|eofchars
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|transmit
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|fd
operator|,
name|char
operator|*
name|eofchars
operator|,
name|char
operator|*
name|command
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ttysetup
name|__P
argument_list|(
operator|(
name|int
name|_speed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|user_uid
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
name|void
name|vlex
name|__P
argument_list|(
operator|(
name|char
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|biz31f_dialer
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
name|void
name|biz31f_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|biz31f_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ven_dialer
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
name|void
name|ven_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ven_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hay_dialer
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
name|void
name|hay_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hay_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cour_dialer
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
name|void
name|cour_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cour_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|t3000_dialer
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
name|void
name|t3000_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|t3000_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|v831_dialer
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
name|void
name|v831_disconnect
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|v831_abort
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

