begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pppd.h - PPP daemon global declarations.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: pppd.h,v 1.10 1997/10/10 06:02:57 peter Exp $  */
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
argument_list|(
argument|*init
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Process a received packet */
name|void
argument_list|(
argument|*input
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_char
operator|*
name|pkt
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
comment|/* Process a received protocol-reject */
name|void
argument_list|(
argument|*protrej
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Lower layer has come up */
name|void
argument_list|(
argument|*lowerup
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Lower layer has gone down */
name|void
argument_list|(
argument|*lowerdown
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Open the protocol */
name|void
argument_list|(
argument|*open
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Close the protocol */
name|void
argument_list|(
argument|*close
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|char
operator|*
name|reason
operator|)
argument_list|)
expr_stmt|;
comment|/* Print a packet in readable form */
name|int
argument_list|(
argument|*printpkt
argument_list|)
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|pkt
operator|,
name|int
name|len
operator|,
name|void
argument_list|(
argument|*printer
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
expr_stmt|;
comment|/* Process a received data packet */
name|void
argument_list|(
argument|*datainput
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_char
operator|*
name|pkt
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
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
argument_list|(
argument|*check_options
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Configure interface for demand-dial */
name|int
argument_list|(
argument|*demand_conf
argument_list|)
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|)
argument_list|)
expr_stmt|;
comment|/* Say whether to bring up link for this pkt */
name|int
argument_list|(
argument|*active_pkt
argument_list|)
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|pkt
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
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

begin_decl_stmt
name|void
name|die
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cleanup and exit */
end_comment

begin_decl_stmt
name|void
name|quit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* like die(1) */
end_comment

begin_decl_stmt
name|void
name|novm
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Say we ran out of memory, and die */
end_comment

begin_decl_stmt
name|void
name|timeout
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|arg
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call func(arg) after t seconds */
end_comment

begin_decl_stmt
name|void
name|untimeout
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cancel call to func(arg) */
end_comment

begin_decl_stmt
name|int
name|run_program
name|__P
argument_list|(
operator|(
name|char
operator|*
name|prog
operator|,
name|char
operator|*
operator|*
name|args
operator|,
name|int
name|must_exist
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run program prog with args in child */
end_comment

begin_decl_stmt
name|void
name|demuxprotrej
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Demultiplex a Protocol-Reject */
end_comment

begin_decl_stmt
name|void
name|format_packet
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|char
operator|*
argument_list|,
operator|...
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Format a packet in human-readable form */
end_comment

begin_decl_stmt
name|void
name|log_packet
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
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

begin_comment
comment|/* Format a packet and log it with syslog */
end_comment

begin_decl_stmt
name|void
name|print_string
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|char
operator|*
argument_list|,
operator|...
argument_list|)
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Format a string for output */
end_comment

begin_decl_stmt
name|int
name|fmtmsg
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sprintf++ */
end_comment

begin_decl_stmt
name|int
name|vfmtmsg
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vsprintf++ */
end_comment

begin_comment
comment|/* Procedures exported from auth.c */
end_comment

begin_decl_stmt
name|void
name|link_required
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are starting to use the link */
end_comment

begin_decl_stmt
name|void
name|link_terminated
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are finished with the link */
end_comment

begin_decl_stmt
name|void
name|link_down
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the LCP layer has left the Opened state */
end_comment

begin_decl_stmt
name|void
name|link_established
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the link is up; authenticate now */
end_comment

begin_decl_stmt
name|void
name|np_up
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a network protocol has come up */
end_comment

begin_decl_stmt
name|void
name|np_down
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a network protocol has gone down */
end_comment

begin_decl_stmt
name|void
name|np_finished
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a network protocol no longer needs link */
end_comment

begin_decl_stmt
name|void
name|auth_peer_fail
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* peer failed to authenticate itself */
end_comment

begin_decl_stmt
name|void
name|auth_peer_success
name|__P
argument_list|(
operator|(
name|int
operator|,
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

begin_comment
comment|/* peer successfully authenticated itself */
end_comment

begin_decl_stmt
name|void
name|auth_withpeer_fail
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we failed to authenticate ourselves */
end_comment

begin_decl_stmt
name|void
name|auth_withpeer_success
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we successfully authenticated ourselves */
end_comment

begin_decl_stmt
name|void
name|auth_check_options
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check authentication options supplied */
end_comment

begin_decl_stmt
name|void
name|auth_reset
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check what secrets we have */
end_comment

begin_decl_stmt
name|int
name|check_passwd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check peer-supplied username/password */
end_comment

begin_decl_stmt
name|int
name|get_secret
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get "secret" for chap */
end_comment

begin_decl_stmt
name|int
name|auth_ip_addr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check if IP address is authorized */
end_comment

begin_decl_stmt
name|int
name|bad_ip_adrs
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check if IP address is unreasonable */
end_comment

begin_decl_stmt
name|void
name|check_access
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* check permissions on secrets file */
end_comment

begin_comment
comment|/* Procedures exported from demand.c */
end_comment

begin_decl_stmt
name|void
name|demand_conf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* config interface(s) for demand-dial */
end_comment

begin_decl_stmt
name|void
name|demand_block
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set all NPs to queue up packets */
end_comment

begin_decl_stmt
name|void
name|demand_unblock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set all NPs to pass packets */
end_comment

begin_decl_stmt
name|void
name|demand_discard
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set all NPs to discard packets */
end_comment

begin_decl_stmt
name|void
name|demand_rexmit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* retransmit saved frames for an NP */
end_comment

begin_decl_stmt
name|int
name|loop_chars
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process chars from loopback */
end_comment

begin_decl_stmt
name|int
name|loop_frame
name|__P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process frame from loopback */
end_comment

begin_comment
comment|/* Procedures exported from sys-*.c */
end_comment

begin_decl_stmt
name|void
name|sys_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do system-dependent initialization */
end_comment

begin_decl_stmt
name|void
name|sys_cleanup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore system state before exiting */
end_comment

begin_decl_stmt
name|void
name|sys_check_options
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check options specified */
end_comment

begin_decl_stmt
name|void
name|sys_close
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clean up in a child before execing */
end_comment

begin_decl_stmt
name|int
name|ppp_available
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test whether ppp kernel support exists */
end_comment

begin_decl_stmt
name|void
name|open_ppp_loopback
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open loopback for demand-dialling */
end_comment

begin_decl_stmt
name|void
name|establish_ppp
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn serial port into a ppp interface */
end_comment

begin_decl_stmt
name|void
name|restore_loop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transfer ppp unit back to loopback */
end_comment

begin_decl_stmt
name|void
name|disestablish_ppp
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore port to normal operation */
end_comment

begin_decl_stmt
name|void
name|clean_check
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check if line was 8-bit clean */
end_comment

begin_decl_stmt
name|void
name|set_up_tty
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set up port's speed, parameters, etc. */
end_comment

begin_decl_stmt
name|void
name|restore_tty
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Restore port's original parameters */
end_comment

begin_decl_stmt
name|void
name|setdtr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Raise or lower port's DTR line */
end_comment

begin_decl_stmt
name|void
name|output
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a PPP packet */
end_comment

begin_decl_stmt
name|void
name|wait_input
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wait for input, with timeout */
end_comment

begin_decl_stmt
name|void
name|wait_loop_output
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wait for pkt from loopback, with timeout */
end_comment

begin_decl_stmt
name|void
name|wait_time
name|__P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wait for given length of time */
end_comment

begin_decl_stmt
name|int
name|read_packet
name|__P
argument_list|(
operator|(
name|u_char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read PPP packet */
end_comment

begin_decl_stmt
name|int
name|get_loop_output
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read pkts from loopback */
end_comment

begin_decl_stmt
name|void
name|ppp_send_config
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|u_int32_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure i/f transmit parameters */
end_comment

begin_decl_stmt
name|void
name|ppp_set_xaccm
name|__P
argument_list|(
operator|(
name|int
operator|,
name|ext_accm
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set extended transmit ACCM */
end_comment

begin_decl_stmt
name|void
name|ppp_recv_config
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|u_int32_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure i/f receive parameters */
end_comment

begin_decl_stmt
name|int
name|ccp_test
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test support for compression scheme */
end_comment

begin_decl_stmt
name|void
name|ccp_flags_set
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set kernel CCP state */
end_comment

begin_decl_stmt
name|int
name|ccp_fatal_error
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Test for fatal decomp error in kernel */
end_comment

begin_decl_stmt
name|int
name|get_idle_time
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|ppp_idle
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find out how long link has been idle */
end_comment

begin_decl_stmt
name|int
name|sifvjcomp
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure VJ TCP header compression */
end_comment

begin_decl_stmt
name|int
name|sifup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure i/f up (for IP) */
end_comment

begin_decl_stmt
name|int
name|sifnpmode
name|__P
argument_list|(
operator|(
name|int
name|u
operator|,
name|int
name|proto
operator|,
expr|enum
name|NPmode
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set mode for handling packets for proto */
end_comment

begin_decl_stmt
name|int
name|sifdown
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure i/f down (for IP) */
end_comment

begin_decl_stmt
name|int
name|sifaddr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Configure IP addresses for i/f */
end_comment

begin_decl_stmt
name|int
name|cifaddr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset i/f IP addresses */
end_comment

begin_decl_stmt
name|int
name|sifdefaultroute
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create default route through i/f */
end_comment

begin_decl_stmt
name|int
name|cifdefaultroute
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete default route through i/f */
end_comment

begin_decl_stmt
name|int
name|sifproxyarp
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add proxy ARP entry for peer */
end_comment

begin_decl_stmt
name|int
name|cifproxyarp
name|__P
argument_list|(
operator|(
name|int
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete proxy ARP entry for peer */
end_comment

begin_decl_stmt
name|u_int32_t
name|GetMask
name|__P
argument_list|(
operator|(
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get appropriate netmask for address */
end_comment

begin_decl_stmt
name|int
name|lock
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create lock file for device */
end_comment

begin_decl_stmt
name|void
name|unlock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Delete previously-created lock file */
end_comment

begin_decl_stmt
name|int
name|daemon
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Detach us from terminal session */
end_comment

begin_decl_stmt
name|void
name|logwtmp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write entry to wtmp file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PPP_FILTER
end_ifdef

begin_decl_stmt
name|int
name|set_filters
name|__P
argument_list|(
operator|(
expr|struct
name|bpf_program
operator|*
name|pass
operator|,
expr|struct
name|bpf_program
operator|*
name|active
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|parse_args
name|__P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse options from arguments given */
end_comment

begin_decl_stmt
name|void
name|usage
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a usage message */
end_comment

begin_decl_stmt
name|int
name|options_from_file
name|__P
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|int
name|must_exist
operator|,
name|int
name|check_prot
operator|,
name|int
name|privileged
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse options from an options file */
end_comment

begin_decl_stmt
name|int
name|options_from_user
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse options from user's .ppprc */
end_comment

begin_decl_stmt
name|int
name|options_for_tty
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parse options from /etc/ppp/options.tty */
end_comment

begin_decl_stmt
name|void
name|scan_args
name|__P
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look for tty name in command-line args */
end_comment

begin_decl_stmt
name|int
name|getword
name|__P
argument_list|(
operator|(
name|FILE
operator|*
name|f
operator|,
name|char
operator|*
name|word
operator|,
name|int
operator|*
name|newlinep
operator|,
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read a word from a file */
end_comment

begin_decl_stmt
name|void
name|option_error
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print an error message about an option */
end_comment

begin_decl_stmt
name|int
name|setipaddr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

