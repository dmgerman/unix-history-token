begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Adams.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Hacks to support "-a|c|n" flags on the command line which enable VJ  * header compresion and disable ICMP.  * If this is good all rights go to B& L Jolitz, otherwise send your  * comments to Reagan (/dev/null).  *  * nerd@percival.rain.com (Michael Galassi) 92.09.03  *  * Hacked to change from sgtty to POSIX termio style serial line control  * and added flag to enable cts/rts style flow control.  *  * blymn@awadi.com.au (Brett Lymn) 93.04.04  *  * Put slattach in it's own process group so it can't be killed  * accidentally. Close the connection on SIGHUP and SIGINT. Write a  * syslog entry upon opening and closing the connection.  Rich Murphey  * and Brad Huntting.  *  * Add '-r command' option: runs 'command' upon recieving SIGHUP  * resulting from loss of carrier.  Log any errors after forking.  * Rich 8/13/93  *  * This version of slattach includes many changes by David Greenman, Brian  * Smith, Chris Bradley, and me (Michael Galassi).  None of them are  * represented as functional anywhere outside of RAINet though they do work  * for us.  Documentation is limited to the usage message for now.  If you  * make improovments please pass them back.  *  * Added '-u UCMD' which runs 'UCMD<old><new>' whenever the slip  * unit number changes where<old> and<new> are the old and new unit  * numbers, respectively.  Also added the '-z' option which forces  * invocation of the redial command (-r CMD) upon startup regardless  * of whether the com driver claims (sometimes mistakenly) that  * carrier is present. Also added '-e ECMD' which runs ECMD before  * exiting.  *  * marc@escargot.rain.com (Marc Frajola) 93/09/10  *  * Minor fixes to allow passive SLIP links to work (connections with  * modem control that do not have an associated dial command). Added  * code to re-check for carrier after dial command has been executed.  * Added SIGTERM handler to properly handle normal kill signals. Fixed  * bug in logic that caused message about no -u command to be logged  * even when -u was specified and the sl number changes. Tried to get  * rid of redundant syslog()'s to minimize console log output. Improved  * logging of improper command line options or number of command  * arguments. Removed spurious newline characters from syslog() calls.  *  * gjung@gjbsd.franken.de  *  * sighup_handler changed to set CLOCAL before running redial_cmd.  * added flag exiting, so exit_handler is not run twice.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/*static char sccsid[] = "from: @(#)slattach.c	4.6 (Berkeley) 6/1/90";*/
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_slvar.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEFAULT_BAUD
value|9600
end_define

begin_function_decl
name|void
name|sighup_handler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SIGHUP handler */
end_comment

begin_function_decl
name|void
name|sigint_handler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SIGINT handler */
end_comment

begin_function_decl
name|void
name|sigterm_handler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SIGTERM handler */
end_comment

begin_function_decl
name|void
name|exit_handler
parameter_list|(
name|int
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* run exit_cmd iff specified upon exit. */
end_comment

begin_function_decl
name|void
name|setup_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* configure slip line */
end_comment

begin_function_decl
name|void
name|attach_line
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* switch to slip line discipline */
end_comment

begin_decl_stmt
name|int
name|fd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dev
init|=
operator|(
name|char
operator|*
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slipdisc
init|=
name|SLIPDISC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ttydisc
init|=
name|TTYDISC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flow_control
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-zero to enable hardware flow control. */
end_comment

begin_decl_stmt
name|int
name|modem_control
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-zero iff we watch carrier. */
end_comment

begin_decl_stmt
name|int
name|comstate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TIOCMGET current state of serial driver */
end_comment

begin_decl_stmt
name|int
name|redial_on_startup
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* iff non-zero execute redial_cmd on startup */
end_comment

begin_decl_stmt
name|int
name|speed
init|=
name|DEFAULT_BAUD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slflags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compression flags */
end_comment

begin_decl_stmt
name|int
name|unit
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* slip device unit number */
end_comment

begin_decl_stmt
name|int
name|foreground
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exiting
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allready running exit_handler */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|termios
name|tty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|devname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|redial_cmd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command to exec upon shutdown. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|config_cmd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command to exec if slip unit changes. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|exit_cmd
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command to exec before exiting. */
end_comment

begin_decl_stmt
name|char
name|string
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|usage_str
index|[]
init|=
literal|"\ usage: %s [-acfhlnz] [-e command] [-r command] [-s speed] [-u command] device\n\   -a      -- autoenable VJ compression\n\   -c      -- enable VJ compression\n\   -e ECMD -- run ECMD before exiting\n\   -f      -- run in foreground (don't detach from controlling tty)\n\   -h      -- turn on cts/rts style flow control\n\   -l      -- disable modem control (CLOCAL) and ignore carrier detect\n\   -n      -- throw out ICMP packets\n\   -r RCMD -- run RCMD upon loss of carrier\n\   -s #    -- set baud rate (default 9600)\n\   -u UCMD -- run 'UCMD<old sl#><new sl#>' before switch to slip discipline\n\   -z      -- run RCMD upon startup irrespective of carrier\n"
decl_stmt|;
end_decl_stmt

begin_function
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
block|{
name|int
name|option
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
specifier|extern
name|int
name|optind
decl_stmt|;
while|while
condition|(
operator|(
name|option
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"ace:fhlnr:s:u:z"
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
switch|switch
condition|(
name|option
condition|)
block|{
case|case
literal|'a'
case|:
name|slflags
operator||=
name|SC_AUTOCOMP
expr_stmt|;
name|slflags
operator|&=
operator|~
name|SC_COMPRESS
expr_stmt|;
break|break;
case|case
literal|'c'
case|:
name|slflags
operator||=
name|SC_COMPRESS
expr_stmt|;
name|slflags
operator|&=
operator|~
name|SC_AUTOCOMP
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
name|exit_cmd
operator|=
operator|(
name|char
operator|*
operator|)
name|strdup
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|foreground
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
name|flow_control
operator||=
name|CRTSCTS
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|modem_control
operator||=
name|CLOCAL
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
name|slflags
operator||=
name|SC_NOICMP
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|redial_cmd
operator|=
operator|(
name|char
operator|*
operator|)
name|strdup
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|speed
operator|=
name|atoi
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
name|config_cmd
operator|=
operator|(
name|char
operator|*
operator|)
name|strdup
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'z'
case|:
name|redial_on_startup
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Invalid option -- '%c'\n"
argument_list|,
name|option
argument_list|)
expr_stmt|;
case|case
literal|'?'
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|usage_str
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|optind
operator|==
name|argc
operator|-
literal|1
condition|)
name|dev
operator|=
name|argv
index|[
name|optind
index|]
expr_stmt|;
if|if
condition|(
name|optind
operator|<
operator|(
name|argc
operator|-
literal|1
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Too many args, first='%s'\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|,
name|argv
index|[
name|optind
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|optind
operator|>
operator|(
name|argc
operator|-
literal|1
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Not enough args\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dev
operator|==
operator|(
name|char
operator|*
operator|)
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|usage_str
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|strncmp
argument_list|(
name|_PATH_DEV
argument_list|,
name|dev
argument_list|,
sizeof|sizeof
argument_list|(
name|_PATH_DEV
argument_list|)
operator|-
literal|1
argument_list|)
condition|)
block|{
name|strcpy
argument_list|(
name|devname
argument_list|,
name|_PATH_DEV
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|devname
argument_list|,
literal|"/"
argument_list|)
expr_stmt|;
name|strncat
argument_list|(
name|devname
argument_list|,
name|dev
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|dev
operator|=
name|devname
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|foreground
condition|)
name|daemon
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* fork, setsid, chdir /, and close std*. */
comment|/* Note: daemon() closes stderr, so log errors from here on. */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"slattach[%d]"
argument_list|,
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
name|name
argument_list|,
name|LOG_CONS
argument_list|,
name|LOG_DAEMON
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|dev
argument_list|,
name|O_RDWR
operator||
name|O_NONBLOCK
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"open(%s): %m"
argument_list|,
name|dev
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* acquire the serial line as a controling terminal. */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSCTTY
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"ioctl(TIOCSCTTY) failed: %s: %m"
argument_list|)
expr_stmt|;
comment|/* Make us the foreground process group associated with the 	   slip line which is our controlling terminal. */
if|if
condition|(
name|tcsetpgrp
argument_list|(
name|fd
argument_list|,
name|getpid
argument_list|()
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"tcsetpgrp failed: %s: %m"
argument_list|)
expr_stmt|;
comment|/* upon INT log a timestamp and exit.  */
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|sigint_handler
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"cannot install SIGINT handler: %s: %m"
argument_list|)
expr_stmt|;
comment|/* upon TERM log a timestamp and exit.  */
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|sigterm_handler
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"cannot install SIGTERM handler: %s: %m"
argument_list|)
expr_stmt|;
comment|/* upon HUP redial and reconnect.  */
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|sighup_handler
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"cannot install SIGHUP handler: %s: %m"
argument_list|)
expr_stmt|;
name|setup_line
argument_list|()
expr_stmt|;
if|if
condition|(
name|redial_on_startup
condition|)
name|sighup_handler
argument_list|()
expr_stmt|;
else|else
name|attach_line
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|modem_control
operator|&
name|CLOCAL
operator|)
condition|)
block|{
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|comstate
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|comstate
operator|&
name|TIOCM_CD
operator|)
condition|)
block|{
comment|/* check for carrier */
comment|/* force a redial if no carrier */
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGHUP
argument_list|)
expr_stmt|;
block|}
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
name|sigset_t
name|mask
init|=
literal|0
decl_stmt|;
name|sigsuspend
argument_list|(
operator|&
name|mask
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|setup_line
parameter_list|()
block|{
name|tty
operator|.
name|c_lflag
operator|=
name|tty
operator|.
name|c_iflag
operator|=
name|tty
operator|.
name|c_oflag
operator|=
literal|0
expr_stmt|;
name|tty
operator|.
name|c_cflag
operator|=
name|CREAD
operator||
name|CS8
operator||
name|flow_control
operator||
name|modem_control
expr_stmt|;
name|tty
operator|.
name|c_ispeed
operator|=
name|tty
operator|.
name|c_ospeed
operator|=
name|speed
expr_stmt|;
comment|/* set the line speed and flow control */
if|if
condition|(
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"tcsetattr(TCSAFLUSH): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* set data terminal ready */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSDTR
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ioctl(TIOCSDTR): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Switch to slip line discipline. */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|slipdisc
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ioctl(TIOCSETD): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Assert any compression or no-icmp flags. */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|SLIOCSFLAGS
argument_list|,
operator|&
name|slflags
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ioctl(SLIOCSFLAGS): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* switch to slip line discipline and configure the network. */
end_comment

begin_function
name|void
name|attach_line
parameter_list|()
block|{
name|int
name|new_unit
decl_stmt|;
comment|/* find out what unit number we were assigned */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|SLIOCGUNIT
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|new_unit
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ioctl(SLIOCGUNIT): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* don't compare unit numbers if this is the first time to attach. */
if|if
condition|(
name|unit
operator|<
literal|0
condition|)
name|unit
operator|=
name|new_unit
expr_stmt|;
comment|/* iff the unit number changes either invoke config_cmd or punt. */
if|if
condition|(
name|config_cmd
condition|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|s
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|strlen
argument_list|(
name|config_cmd
argument_list|)
operator|+
literal|32
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|s
argument_list|,
literal|"%s %d %d"
argument_list|,
name|config_cmd
argument_list|,
name|unit
argument_list|,
name|new_unit
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Configuring %s (sl%d):"
argument_list|,
name|dev
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"  '%s'"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|unit
operator|=
name|new_unit
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|new_unit
operator|!=
name|unit
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"slip unit changed from sl%d to sl%d, but no -u CMD was specified!"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"sl%d connected to %s at %d baud"
argument_list|,
name|unit
argument_list|,
name|dev
argument_list|,
name|speed
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Signal handler for SIGHUP when carrier is dropped. */
end_comment

begin_function
name|void
name|sighup_handler
parameter_list|()
block|{
if|if
condition|(
name|exiting
condition|)
return|return;
name|again
label|:
comment|/* reset discipline */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSETD
argument_list|,
operator|&
name|ttydisc
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"ioctl(TIOCSETD): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* invoke a shell for redial_cmd or punt. */
if|if
condition|(
name|redial_cmd
condition|)
block|{
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"SIGHUP on %s (sl%d); running %s"
argument_list|,
name|dev
argument_list|,
name|unit
argument_list|,
name|redial_cmd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|modem_control
operator|&
name|CLOCAL
operator|)
condition|)
block|{
name|tty
operator|.
name|c_cflag
operator||=
name|CLOCAL
expr_stmt|;
if|if
condition|(
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"tcsetattr(TCSAFLUSH): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|system
argument_list|(
name|redial_cmd
argument_list|)
expr_stmt|;
comment|/* Now check again for carrier (dial command is done): */
if|if
condition|(
operator|!
operator|(
name|modem_control
operator|&
name|CLOCAL
operator|)
condition|)
block|{
name|tty
operator|.
name|c_cflag
operator|&=
operator|~
name|CLOCAL
expr_stmt|;
if|if
condition|(
name|tcsetattr
argument_list|(
name|fd
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|tty
argument_list|)
operator|<
literal|0
condition|)
block|{
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"tcsetattr(TCSAFLUSH): %m"
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|comstate
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|comstate
operator|&
name|TIOCM_CD
operator|)
condition|)
block|{
comment|/* check for carrier */
comment|/* force a redial if no carrier */
goto|goto
name|again
goto|;
block|}
block|}
block|}
else|else
block|{
comment|/* 		 * No redial command. 		 * 		 * If modem control, just wait for carrier before 		 * falling through to setup_line() and attach_line(). 		 * If no modem control, just fall through immediately. 		 */
if|if
condition|(
operator|!
operator|(
name|modem_control
operator|&
name|CLOCAL
operator|)
condition|)
block|{
name|int
name|carrier
init|=
literal|0
decl_stmt|;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Waiting for carrier on %s (sl%d)"
argument_list|,
name|dev
argument_list|,
name|unit
argument_list|)
expr_stmt|;
comment|/* Now wait for carrier before attaching line: */
while|while
condition|(
operator|!
name|carrier
condition|)
block|{
comment|/* 			 * Don't burn the CPU checking for carrier; 			 * carrier must be polled since there is no 			 * way to have a signal sent when carrier 			 * goes high (SIGHUP can only be sent when 			 * carrier is dropped); so add space between 			 * checks for carrier: 			 */
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|/* Check for carrier present on tty port: */
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCMGET
argument_list|,
operator|&
name|comstate
argument_list|)
expr_stmt|;
if|if
condition|(
name|comstate
operator|&
name|TIOCM_CD
condition|)
block|{
name|carrier
operator|=
literal|1
expr_stmt|;
block|}
block|}
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Carrier now present on %s (sl%d)"
argument_list|,
name|dev
argument_list|,
name|unit
argument_list|)
expr_stmt|;
block|}
block|}
name|setup_line
argument_list|()
expr_stmt|;
name|attach_line
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Signal handler for SIGINT.  We just log and exit. */
end_comment

begin_function
name|void
name|sigint_handler
parameter_list|()
block|{
if|if
condition|(
name|exiting
condition|)
return|return;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"sl%d on %s caught SIGINT, exiting."
argument_list|,
name|unit
argument_list|,
name|dev
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Signal handler for SIGTERM.  We just log and exit. */
end_comment

begin_function
name|void
name|sigterm_handler
parameter_list|()
block|{
if|if
condition|(
name|exiting
condition|)
return|return;
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"SIGTERM on %s (sl%d); exiting"
argument_list|,
name|dev
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|exit_handler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Run config_cmd if specified before exiting. */
end_comment

begin_function
name|void
name|exit_handler
parameter_list|(
name|int
name|ret
parameter_list|)
block|{
if|if
condition|(
name|exiting
condition|)
return|return;
name|exiting
operator|=
literal|1
expr_stmt|;
comment|/* 	 * First close the slip line in case exit_cmd wants it (like to hang 	 * up a modem or something). 	 */
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|/* invoke a shell for exit_cmd. */
if|if
condition|(
name|exit_cmd
condition|)
block|{
name|syslog
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"exiting after running %s"
argument_list|,
name|exit_cmd
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|exit_cmd
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
name|ret
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* local variables: */
end_comment

begin_comment
comment|/* c-indent-level: 8 */
end_comment

begin_comment
comment|/* c-argdecl-indent: 0 */
end_comment

begin_comment
comment|/* c-label-offset: -8 */
end_comment

begin_comment
comment|/* c-continued-statement-offset: 8 */
end_comment

begin_comment
comment|/* c-brace-offset: 0 */
end_comment

begin_comment
comment|/* comment-column: 32 */
end_comment

begin_comment
comment|/* end: */
end_comment

end_unit

