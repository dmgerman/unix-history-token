begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pppd.h - PPP daemon global declarations.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPPD_H__
end_ifndef

begin_define
define|#
directive|define
name|__PPPD_H__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* for FILE */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for MAXPATHLEN and BSD4_4, if defined */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for u_int32_t, if defined */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* for struct timeval */
end_comment

begin_include
include|#
directive|include
file|<net/ppp_defs.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_define
define|#
directive|define
name|__V
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_define
define|#
directive|define
name|__V
parameter_list|(
name|x
parameter_list|)
value|(va_alist) va_dcl
end_define

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
name|INET6
end_ifdef

begin_include
include|#
directive|include
file|"eui64.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Limits.  */
end_comment

begin_define
define|#
directive|define
name|NUM_PPP
value|1
end_define

begin_comment
comment|/* One PPP interface supported (per process) */
end_comment

begin_define
define|#
directive|define
name|MAXWORDLEN
value|1024
end_define

begin_comment
comment|/* max length of word in file (incl null) */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|1
end_define

begin_comment
comment|/* max # args to a command */
end_comment

begin_define
define|#
directive|define
name|MAXNAMELEN
value|256
end_define

begin_comment
comment|/* max length of hostname or name for auth */
end_comment

begin_define
define|#
directive|define
name|MAXSECRETLEN
value|256
end_define

begin_comment
comment|/* max length of password or secret */
end_comment

begin_comment
comment|/*  * Global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hungup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Physical layer has disconnected */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ifunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface unit number */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ifname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ttyfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Serial device file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our hostname */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|outpacket_buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer for outgoing packets */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|phase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current state of link - see values below */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|baud_rate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current link speed in bits/sec */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of this program */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|redirect_stderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Connector's stderr should go to file */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|peer_authname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Authenticated name of peer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|privileged
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We were run by real-uid root */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|need_holdoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Need holdoff period after link terminates */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|script_env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Environment variables for scripts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|detached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have detached from controlling tty */
end_comment

begin_comment
comment|/*  * Variables set by command-line options.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|kdebugflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell kernel to print debug messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|default_device
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Using /dev/tty or equivalent */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|devnam
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|crtscts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use hardware flow control */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|modem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use modem control lines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inspeed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input/Output speed requested */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|netmask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IP netmask to set on interface */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lockflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create lock file to lock the serial dev */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nodetach
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't detach from controlling tty */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|connector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Script to establish physical link */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|disconnector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Script to disestablish physical link */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|welcomer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Script to welcome client after connection */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_con_attempts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of times to try dialing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxconnect
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum connect time (seconds) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|user
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our name for authenticating ourselves */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|passwd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Password for PAP */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|auth_required
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Peer is required to authenticate */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|proxyarp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up proxy ARP entry for peer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|persist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reopen link after it goes down */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|uselogin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use /etc/passwd for checking PAP */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lcp_echo_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interval between LCP echo-requests */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lcp_echo_fails
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tolerance to unanswered echo-requests */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|our_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our name for authentication purposes */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|remote_name
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Peer's name for authentication */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|explicit_remote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote_name specified with remotename opt */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usehostname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use hostname for our_name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|disable_defaultip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't use hostname for default IP adrs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|demand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do dial-on-demand */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ipparam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Extra parameter for ip up/down scripts */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cryptpap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Others' PAP passwords are encrypted */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|idle_time_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shut down link if idle for this long */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|holdoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dead time before restarting */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refuse_pap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't wanna auth. ourselves with PAP */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refuse_chap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't wanna auth. ourselves with CHAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPP_FILTER
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|bpf_program
name|pass_filter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Filter for pkts to pass */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bpf_program
name|active_filter
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Filter for link-active pkts */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSLANMAN
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ms_lanman
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if use LanMan password instead of NT */
end_comment

begin_comment
comment|/* Has meaning only with MS-CHAP challenges */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Values for phase.  */
end_comment

begin_define
define|#
directive|define
name|PHASE_DEAD
value|0
end_define

begin_define
define|#
directive|define
name|PHASE_INITIALIZE
value|1
end_define

begin_define
define|#
directive|define
name|PHASE_DORMANT
value|2
end_define

begin_define
define|#
directive|define
name|PHASE_ESTABLISH
value|3
end_define

begin_define
define|#
directive|define
name|PHASE_AUTHENTICATE
value|4
end_define

begin_define
define|#
directive|define
name|PHASE_CALLBACK
value|5
end_define

begin_define
define|#
directive|define
name|PHASE_NETWORK
value|6
end_define

begin_define
define|#
directive|define
name|PHASE_TERMINATE
value|7
end_define

begin_define
define|#
directive|define
name|PHASE_HOLDOFF
value|8
end_define

begin_comment
comment|/*  * The following struct gives the addresses of procedures to call  * for a particular protocol.  */
end_comment

begin_struct
struct|struct
name|protent
block|{
name|u_short
name|protocol
decl_stmt|;
comment|/* PPP protocol number */
comment|/* Initialization procedure */
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Process a received packet */
name|void
function_decl|(
modifier|*
name|input
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|u_char
modifier|*
name|pkt
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* Process a received protocol-reject */
name|void
function_decl|(
modifier|*
name|protrej
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Lower layer has come up */
name|void
function_decl|(
modifier|*
name|lowerup
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Lower layer has gone down */
name|void
function_decl|(
modifier|*
name|lowerdown
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Open the protocol */
name|void
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Close the protocol */
name|void
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
comment|/* Print a packet in readable form */
name|int
function_decl|(
modifier|*
name|printpkt
function_decl|)
parameter_list|(
name|u_char
modifier|*
name|pkt
parameter_list|,
name|int
name|len
parameter_list|,
name|void
function_decl|(
modifier|*
name|printer
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
comment|/* Process a received data packet */
name|void
function_decl|(
modifier|*
name|datainput
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|u_char
modifier|*
name|pkt
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
name|int
name|enabled_flag
decl_stmt|;
comment|/* 0 iff protocol is disabled */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Text name of protocol */
comment|/* Check requested options, assign defaults */
name|void
function_decl|(
modifier|*
name|check_options
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Configure interface for demand-dial */
name|int
function_decl|(
modifier|*
name|demand_conf
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
comment|/* Say whether to bring up link for this pkt */
name|int
function_decl|(
modifier|*
name|active_pkt
function_decl|)
parameter_list|(
name|u_char
modifier|*
name|pkt
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Table of pointers to supported protocols */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|protent
modifier|*
name|protocols
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_comment
comment|/* Procedures exported from main.c. */
end_comment

begin_function_decl
name|void
name|detach
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Detach from controlling tty */
end_comment

begin_function_decl
name|void
name|die
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cleanup and exit */
end_comment

begin_function_decl
name|void
name|quit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* like die(1) */
end_comment

begin_function_decl
name|void
name|novm
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Say we ran out of memory, and die */
end_comment

begin_function_decl
name|void
name|timeout
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call func(arg) after t seconds */
end_comment

begin_function_decl
name|void
name|untimeout
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cancel call to func(arg) */
end_comment

begin_function_decl
name|int
name|run_program
parameter_list|(
name|char
modifier|*
name|prog
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|,
name|int
name|must_exist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Run program prog with args in child */
end_comment

begin_function_decl
name|void
name|demuxprotrej
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Demultiplex a Protocol-Reject */
end_comment

begin_function_decl
name|void
name|format_packet
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Format a packet in human-readable form */
end_comment

begin_function_decl
name|void
name|log_packet
parameter_list|(
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Format a packet and log it with syslog */
end_comment

begin_function_decl
name|void
name|print_string
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Format a string for output */
end_comment

begin_function_decl
name|int
name|fmtmsg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sprintf++ */
end_comment

begin_function_decl
name|int
name|vfmtmsg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vsprintf++ */
end_comment

begin_function_decl
name|void
name|script_setenv
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set script env var */
end_comment

begin_function_decl
name|void
name|script_unsetenv
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* unset script env var */
end_comment

begin_comment
comment|/* Procedures exported from auth.c */
end_comment

begin_function_decl
name|void
name|link_required
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we are starting to use the link */
end_comment

begin_function_decl
name|void
name|link_terminated
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we are finished with the link */
end_comment

begin_function_decl
name|void
name|link_down
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the LCP layer has left the Opened state */
end_comment

begin_function_decl
name|void
name|link_established
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the link is up; authenticate now */
end_comment

begin_function_decl
name|void
name|np_up
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a network protocol has come up */
end_comment

begin_function_decl
name|void
name|np_down
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a network protocol has gone down */
end_comment

begin_function_decl
name|void
name|np_finished
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a network protocol no longer needs link */
end_comment

begin_function_decl
name|void
name|auth_peer_fail
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* peer failed to authenticate itself */
end_comment

begin_function_decl
name|void
name|auth_peer_success
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* peer successfully authenticated itself */
end_comment

begin_function_decl
name|void
name|auth_withpeer_fail
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we failed to authenticate ourselves */
end_comment

begin_function_decl
name|void
name|auth_withpeer_success
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* we successfully authenticated ourselves */
end_comment

begin_function_decl
name|void
name|auth_check_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check authentication options supplied */
end_comment

begin_function_decl
name|void
name|auth_reset
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check what secrets we have */
end_comment

begin_function_decl
name|int
name|check_passwd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check peer-supplied username/password */
end_comment

begin_function_decl
name|int
name|get_secret
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get "secret" for chap */
end_comment

begin_function_decl
name|int
name|auth_ip_addr
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check if IP address is authorized */
end_comment

begin_function_decl
name|int
name|bad_ip_adrs
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check if IP address is unreasonable */
end_comment

begin_function_decl
name|void
name|check_access
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check permissions on secrets file */
end_comment

begin_comment
comment|/* Procedures exported from demand.c */
end_comment

begin_function_decl
name|void
name|demand_conf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* config interface(s) for demand-dial */
end_comment

begin_function_decl
name|void
name|demand_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set all NPs to queue up packets */
end_comment

begin_function_decl
name|void
name|demand_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set all NPs to pass packets */
end_comment

begin_function_decl
name|void
name|demand_discard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set all NPs to discard packets */
end_comment

begin_function_decl
name|void
name|demand_rexmit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* retransmit saved frames for an NP */
end_comment

begin_function_decl
name|int
name|loop_chars
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process chars from loopback */
end_comment

begin_function_decl
name|int
name|loop_frame
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process frame from loopback */
end_comment

begin_comment
comment|/* Procedures exported from sys-*.c */
end_comment

begin_function_decl
name|void
name|sys_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Do system-dependent initialization */
end_comment

begin_function_decl
name|void
name|sys_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Restore system state before exiting */
end_comment

begin_function_decl
name|void
name|sys_check_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check options specified */
end_comment

begin_function_decl
name|void
name|sys_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clean up in a child before execing */
end_comment

begin_function_decl
name|int
name|ppp_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Test whether ppp kernel support exists */
end_comment

begin_function_decl
name|void
name|open_ppp_loopback
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open loopback for demand-dialling */
end_comment

begin_function_decl
name|void
name|establish_ppp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Turn serial port into a ppp interface */
end_comment

begin_function_decl
name|void
name|restore_loop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transfer ppp unit back to loopback */
end_comment

begin_function_decl
name|void
name|disestablish_ppp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Restore port to normal operation */
end_comment

begin_function_decl
name|void
name|clean_check
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if line was 8-bit clean */
end_comment

begin_function_decl
name|void
name|set_up_tty
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set up port's speed, parameters, etc. */
end_comment

begin_function_decl
name|void
name|restore_tty
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Restore port's original parameters */
end_comment

begin_function_decl
name|void
name|setdtr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Raise or lower port's DTR line */
end_comment

begin_function_decl
name|void
name|output
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a PPP packet */
end_comment

begin_function_decl
name|void
name|wait_input
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wait for input, with timeout */
end_comment

begin_function_decl
name|void
name|wait_loop_output
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wait for pkt from loopback, with timeout */
end_comment

begin_function_decl
name|void
name|wait_time
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wait for given length of time */
end_comment

begin_function_decl
name|int
name|read_packet
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read PPP packet */
end_comment

begin_function_decl
name|int
name|get_loop_output
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read pkts from loopback */
end_comment

begin_function_decl
name|void
name|ppp_send_config
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure i/f transmit parameters */
end_comment

begin_function_decl
name|void
name|ppp_set_xaccm
parameter_list|(
name|int
parameter_list|,
name|ext_accm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set extended transmit ACCM */
end_comment

begin_function_decl
name|void
name|ppp_recv_config
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure i/f receive parameters */
end_comment

begin_function_decl
name|int
name|ccp_test
parameter_list|(
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Test support for compression scheme */
end_comment

begin_function_decl
name|void
name|ccp_flags_set
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set kernel CCP state */
end_comment

begin_function_decl
name|int
name|ccp_fatal_error
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Test for fatal decomp error in kernel */
end_comment

begin_function_decl
name|int
name|get_idle_time
parameter_list|(
name|int
parameter_list|,
name|struct
name|ppp_idle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find out how long link has been idle */
end_comment

begin_function_decl
name|int
name|sifvjcomp
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure VJ TCP header compression */
end_comment

begin_function_decl
name|int
name|sifup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure i/f up (for IP) */
end_comment

begin_function_decl
name|int
name|sifnpmode
parameter_list|(
name|int
name|u
parameter_list|,
name|int
name|proto
parameter_list|,
name|enum
name|NPmode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set mode for handling packets for proto */
end_comment

begin_function_decl
name|int
name|sifdown
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure i/f down (for IP) */
end_comment

begin_function_decl
name|int
name|sifaddr
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure IP addresses for i/f */
end_comment

begin_function_decl
name|int
name|cifaddr
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset i/f IP addresses */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
name|int
name|sif6addr
parameter_list|(
name|int
parameter_list|,
name|eui64_t
parameter_list|,
name|eui64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Configure IPv6 addresses for i/f */
end_comment

begin_function_decl
name|int
name|cif6addr
parameter_list|(
name|int
parameter_list|,
name|eui64_t
parameter_list|,
name|eui64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove an IPv6 address from i/f */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|sifdefaultroute
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create default route through i/f */
end_comment

begin_function_decl
name|int
name|cifdefaultroute
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete default route through i/f */
end_comment

begin_function_decl
name|int
name|sifproxyarp
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add proxy ARP entry for peer */
end_comment

begin_function_decl
name|int
name|cifproxyarp
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete proxy ARP entry for peer */
end_comment

begin_function_decl
name|u_int32_t
name|GetMask
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get appropriate netmask for address */
end_comment

begin_function_decl
name|int
name|lock
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create lock file for device */
end_comment

begin_function_decl
name|void
name|unlock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete previously-created lock file */
end_comment

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Detach us from terminal session */
end_comment

begin_function_decl
name|void
name|logwtmp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write entry to wtmp file */
end_comment

begin_function_decl
name|int
name|get_host_seed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get host-dependent random number seed */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPP_FILTER
end_ifdef

begin_function_decl
name|int
name|set_filters
parameter_list|(
name|struct
name|bpf_program
modifier|*
name|pass
parameter_list|,
name|struct
name|bpf_program
modifier|*
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set filter programs in kernel */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Procedures exported from options.c */
end_comment

begin_function_decl
name|int
name|parse_args
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

begin_comment
comment|/* Parse options from arguments given */
end_comment

begin_function_decl
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a usage message */
end_comment

begin_function_decl
name|int
name|options_from_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|must_exist
parameter_list|,
name|int
name|check_prot
parameter_list|,
name|int
name|privileged
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse options from an options file */
end_comment

begin_function_decl
name|int
name|options_from_user
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse options from user's .ppprc */
end_comment

begin_function_decl
name|int
name|options_for_tty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse options from /etc/ppp/options.tty */
end_comment

begin_function_decl
name|void
name|scan_args
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

begin_comment
comment|/* Look for tty name in command-line args */
end_comment

begin_function_decl
name|int
name|getword
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|char
modifier|*
name|word
parameter_list|,
name|int
modifier|*
name|newlinep
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a word from a file */
end_comment

begin_function_decl
name|void
name|option_error
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
comment|/* Print an error message about an option */
end_comment

begin_function_decl
name|int
name|setipaddr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set IP addresses */
end_comment

begin_comment
comment|/*  * This structure is used to store information about certain  * options, such as where the option value came from (/etc/ppp/options,  * command line, etc.) and whether it came from a privileged source.  */
end_comment

begin_struct
struct|struct
name|option_info
block|{
name|int
name|priv
decl_stmt|;
comment|/* was value set by sysadmin? */
name|char
modifier|*
name|source
decl_stmt|;
comment|/* where option came from */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|option_info
name|auth_req_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option_info
name|connector_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option_info
name|disconnector_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option_info
name|welcomer_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|option_info
name|devnam_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Inline versions of get/put char/short/long.  * Pointer is advanced; we assume that both arguments  * are lvalues and will already be in registers.  * cp MUST be u_char *.  */
end_comment

begin_define
define|#
directive|define
name|GETCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(c) = *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) (c); \ }
end_define

begin_define
define|#
directive|define
name|GETSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(s) = *(cp)++<< 8; \ 	(s) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) ((s)>> 8); \ 	*(cp)++ = (u_char) (s); \ }
end_define

begin_define
define|#
directive|define
name|GETLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(l) = *(cp)++<< 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (u_char) ((l)>> 24); \ 	*(cp)++ = (u_char) ((l)>> 16); \ 	*(cp)++ = (u_char) ((l)>> 8); \ 	*(cp)++ = (u_char) (l); \ }
end_define

begin_define
define|#
directive|define
name|INCPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) += (n))
end_define

begin_define
define|#
directive|define
name|DECPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) -= (n))
end_define

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*  * System dependent definitions for user-level 4.3BSD UNIX implementation.  */
end_comment

begin_define
define|#
directive|define
name|DEMUXPROTREJ
parameter_list|(
name|u
parameter_list|,
name|p
parameter_list|)
value|demuxprotrej(u, p)
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|timeout((r), (f), (t))
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|untimeout((r), (f))
end_define

begin_define
define|#
directive|define
name|BCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|memcpy(d, s, l)
end_define

begin_define
define|#
directive|define
name|BZERO
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|memset(s, 0, n)
end_define

begin_define
define|#
directive|define
name|EXIT
parameter_list|(
name|u
parameter_list|)
value|quit()
end_define

begin_define
define|#
directive|define
name|PRINTMSG
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|{ m[l] = '\0'; syslog(LOG_INFO, "Remote message: %s", m); }
end_define

begin_comment
comment|/*  * MAKEHEADER - Add Header fields to a packet.  */
end_comment

begin_define
define|#
directive|define
name|MAKEHEADER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|{ \     PUTCHAR(PPP_ALLSTATIONS, p); \     PUTCHAR(PPP_UI, p); \     PUTSHORT(t, p); }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGALL
end_ifdef

begin_define
define|#
directive|define
name|DEBUGMAIN
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGFSM
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGLCP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGIPCP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGUPAP
value|1
end_define

begin_define
define|#
directive|define
name|DEBUGCHAP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_PPP
end_ifndef

begin_comment
comment|/* we use LOG_LOCAL2 for syslog by default */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUGMAIN
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGFSM
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGSYS
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGLCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGIPCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGUPAP
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGCHAP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_LOCAL2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_DAEMON
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
comment|/* LOG_PPP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGMAIN
end_ifdef

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGSYS
end_ifdef

begin_define
define|#
directive|define
name|SYSDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGFSM
end_ifdef

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGLCP
end_ifdef

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGIPCP
end_ifdef

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGIPV6CP
end_ifdef

begin_define
define|#
directive|define
name|IPV6CPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPV6CPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGUPAP
end_ifdef

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGCHAP
end_ifdef

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGIPXCP
end_ifdef

begin_define
define|#
directive|define
name|IPXCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPXCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun) || defined(SYSV) || defined(POSIX_SOURCE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYPE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b)? (a): (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b)? (a): (b))
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
comment|/* __PPP_H__ */
end_comment

end_unit

