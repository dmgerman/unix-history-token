begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b daemon - main header file  *	-----------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sat May 13 13:18:48 2006]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISDND_H_
end_ifndef

begin_define
define|#
directive|define
name|_ISDND_H_
end_define

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
file|<strings.h>
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
file|<time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_CURSES
end_ifdef

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
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

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* TAILQ_ macros */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_RTPRIO
end_ifdef

begin_include
include|#
directive|include
file|<sys/rtprio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if_sppp.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_cause.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* compile time configuration	*/
end_comment

begin_include
include|#
directive|include
file|"pathnames.h"
end_include

begin_comment
comment|/* location of files		*/
end_comment

begin_include
include|#
directive|include
file|"alias.h"
end_include

begin_comment
comment|/* alias file processing	*/
end_comment

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
comment|/*---------------------------------------------------------------------------*  *	misc  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|RTPRIO_NOTUSED
value|(-1)
end_define

begin_comment
comment|/* rtprio is not used for isdnd	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	debug flag bits  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DL_MSG
value|0x0001
end_define

begin_comment
comment|/* general debug messages		*/
end_comment

begin_define
define|#
directive|define
name|DL_RATES
value|0x0002
end_define

begin_comment
comment|/* messages related to rates		*/
end_comment

begin_define
define|#
directive|define
name|DL_TIME
value|0x0004
end_define

begin_comment
comment|/* messages related to timing		*/
end_comment

begin_define
define|#
directive|define
name|DL_STATE
value|0x0008
end_define

begin_comment
comment|/* messages related to states changes	*/
end_comment

begin_define
define|#
directive|define
name|DL_RCVRY
value|0x0010
end_define

begin_comment
comment|/* messages related to dial recovery	*/
end_comment

begin_define
define|#
directive|define
name|DL_DIAL
value|0x0020
end_define

begin_comment
comment|/* messages related to dial recovery	*/
end_comment

begin_define
define|#
directive|define
name|DL_PROC
value|0x0040
end_define

begin_comment
comment|/* messages related to process handling	*/
end_comment

begin_define
define|#
directive|define
name|DL_DRVR
value|0x0080
end_define

begin_comment
comment|/* messages related to kernel i4b msg i/o*/
end_comment

begin_define
define|#
directive|define
name|DL_CNST
value|0x0100
end_define

begin_comment
comment|/* messages related to controller state	*/
end_comment

begin_define
define|#
directive|define
name|DL_RCCF
value|0x0200
end_define

begin_comment
comment|/* messages related to isdnd.rc at boot	*/
end_comment

begin_define
define|#
directive|define
name|DL_BDGT
value|0x0400
end_define

begin_comment
comment|/* messages related to budgets		*/
end_comment

begin_define
define|#
directive|define
name|DL_VALID
value|0x0800
end_define

begin_comment
comment|/* messages related to valid keyword	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBGL
parameter_list|(
name|cond
parameter_list|,
name|dolog
parameter_list|)
value|if(cond& debug_flags) dolog
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBGL
parameter_list|(
name|cond
parameter_list|,
name|dolog
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|6
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
name|WSHOW
value|3
end_define

begin_define
define|#
directive|define
name|WBUDGET
value|4
end_define

begin_define
define|#
directive|define
name|WQUIT
value|5
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
comment|/*---------------------------------------------------------------------------*  *	charging rates  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NDAYS
value|7
end_define

begin_comment
comment|/* number of days in a week		*/
end_comment

begin_define
define|#
directive|define
name|NRATES
value|4
end_define

begin_comment
comment|/* number of rate structures supported 	*/
end_comment

begin_comment
comment|/* struct for rates - each day has one or more */
end_comment

begin_struct
struct|struct
name|rates
block|{
name|int
name|start_time
decl_stmt|;
comment|/* hour and min at which this rate starts, e.g. 12:20 12*60+20*/
name|int
name|end_time
decl_stmt|;
comment|/* hour and min at which this rate ends, e.g. 19:10 19*60+10*/
name|int
name|rate
decl_stmt|;
comment|/* how long can I telephone at this price, seconds */
name|struct
name|rates
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  * the internal identifiers for isdnd log levels. CAUTION: this has to stay  * in sync with the loglevel to text and sysloglevel table in log.c !!  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|logids
block|{
name|LL_ERR
block|,
comment|/* error conditions - everything which caused an error	*/
name|LL_WRN
block|,
comment|/* warning conditions - nonfatal abnormal conditions	*/
name|LL_DMN
block|,
comment|/* normal but significant condition - status of daemon	*/
name|LL_CHD
block|,
comment|/* informational - everything regarding call handling	*/
name|LL_DBG
block|,
comment|/* debug messages - everything which helps debugging	*/
name|LL_MER
block|,
comment|/* monitor error messages - not sent to remote          */
name|LL_PKT
comment|/* packet logging - log the first few packets		*/
block|}
enum|;
end_enum

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state machine events  *---------------------------------------------------------------------------*/
end_comment

begin_enum
enum|enum
name|events
block|{
comment|/* incoming messages */
name|EV_MCI
block|,
comment|/* MSG_CONNECT_IND */
name|EV_MCAI
block|,
comment|/* MSG_CONNECT_ACTIVE_IND */
name|EV_MDI
block|,
comment|/* MSG_DISCONNECT_IND */
name|EV_MDO
block|,
comment|/* MSG_DIALOUT */
comment|/* local requests */
name|EV_TIMO
block|,
comment|/* timer expired */
name|EV_DRQ
block|,
comment|/* disconnect request */
name|EV_CBRQ
block|,
comment|/* callback request */
name|EV_ALRT
block|,
comment|/* alerting request */
comment|/* illegal */
name|EV_ILL
comment|/* illegal event */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_EVENTS
value|(EV_ILL+1)
end_define

begin_comment
comment|/* no of possible events */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes the numbers to try to dial out  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|number
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* number	*/
name|char
name|subaddr
index|[
name|SUBADDR_MAX
index|]
decl_stmt|;
comment|/* subaddr	*/
block|}
name|number_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes the numbers to try to dial out  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|number
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* remote number to dial	*/
name|char
name|subaddr
index|[
name|SUBADDR_MAX
index|]
decl_stmt|;
comment|/* remote subaddr	*/
name|int
name|flag
decl_stmt|;
comment|/* usage flag			*/
define|#
directive|define
name|RNF_IDLE
value|0
define|#
directive|define
name|RNF_SUCC
value|1
comment|/* last dial was ok */
block|}
name|remote_number_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes numbers allowed to dial in  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|number
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* calling party number		*/
name|char
name|subaddr
index|[
name|SUBADDR_MAX
index|]
decl_stmt|;
comment|/* calling party subaddr	*/
block|}
name|incoming_number_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this structure describes a prematurely aborted called-back dialout  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call handle */
name|int
name|controller
decl_stmt|;
comment|/* the controller used to dial out */
name|int
name|channel
decl_stmt|;
comment|/* the channel assigned to the outgoing call */
comment|/* XXX - timeout handling and error recovery? */
block|}
name|phantom_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes one complete configuration entry  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cfg_entry
block|{
comment|/* ====== filled in at startup configuration, then static ===========*/
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* id for this entry */
name|int
name|isdncontroller
decl_stmt|;
comment|/* controller to use 0 ... n */
name|int
name|isdnchannel
decl_stmt|;
comment|/* channel to use */
name|int
name|isdntxdelin
decl_stmt|;
comment|/* tx delay, incoming connections */
name|int
name|isdntxdelout
decl_stmt|;
comment|/* tx delay, outgoing connections */
name|int
name|usrdevicename
decl_stmt|;
comment|/* userland device to use */
name|int
name|usrdeviceunit
decl_stmt|;
comment|/* userland unit to use */
name|int
name|remote_numbers_count
decl_stmt|;
comment|/* number of remote numbers	*/
name|int
name|remote_subaddr_count
decl_stmt|;
comment|/* number of remote subaddr	*/
define|#
directive|define
name|MAXRNUMBERS
value|8
comment|/* max remote numbers		*/
name|remote_number_t
name|remote_numbers
index|[
name|MAXRNUMBERS
index|]
decl_stmt|;
comment|/* remote numbers to dial */
name|int
name|remote_numbers_handling
decl_stmt|;
comment|/* how to handle the remote dialing */
define|#
directive|define
name|RNH_NEXT
value|0
comment|/* use next number after last successfull   */
define|#
directive|define
name|RNH_LAST
value|1
comment|/* use last successfull for next call	    */
define|#
directive|define
name|RNH_FIRST
value|2
comment|/* always use first number for next call    */
name|number_t
name|local_phone_dialout
decl_stmt|;
comment|/* our number to tell remote*/
name|number_t
name|local_phone_incoming
decl_stmt|;
comment|/* answer calls for this local number */
define|#
directive|define
name|MAX_INCOMING
value|8
name|int
name|incoming_numbers_count
decl_stmt|;
comment|/* number of incoming allowed numbers */
name|int
name|incoming_subaddr_count
decl_stmt|;
comment|/* number of incoming allowed subaddr */
name|incoming_number_t
name|remote_phone_incoming
index|[
name|MAX_INCOMING
index|]
decl_stmt|;
comment|/* answer calls from this remote machine */
name|int
name|dialin_reaction
decl_stmt|;
comment|/* what to do with incoming calls */
define|#
directive|define
name|REACT_ACCEPT
value|0
define|#
directive|define
name|REACT_REJECT
value|1
define|#
directive|define
name|REACT_IGNORE
value|2
define|#
directive|define
name|REACT_ANSWER
value|3
define|#
directive|define
name|REACT_CALLBACK
value|4
name|int
name|b1protocol
decl_stmt|;
comment|/* hdlc / raw */
name|int
name|bcap
decl_stmt|;
comment|/* special bearer capability (DoV) */
name|int
name|idle_time_in
decl_stmt|;
comment|/* max idle time incoming calls */
name|int
name|idle_time_out
decl_stmt|;
comment|/* max idle time outgoing calls */
name|int
name|shorthold_algorithm
decl_stmt|;
comment|/* shorthold algorithm		*/
name|int
name|unitlength
decl_stmt|;
comment|/* length of a charging unit	*/
define|#
directive|define
name|UNITLENGTH_DEFAULT
value|60
comment|/* last resort unit length	*/
name|int
name|earlyhangup
decl_stmt|;
comment|/* time in seconds to hangup 	*/
comment|/* before the next expected	*/
comment|/* charging unit		*/
define|#
directive|define
name|EARLYHANGUP_DEFAULT
value|5
name|int
name|ratetype
decl_stmt|;
comment|/* type of rate	*/
define|#
directive|define
name|NO_RATE
value|(NRATES+1)
define|#
directive|define
name|INVALID_RATE
value|(-1)
name|int
name|unitlengthsrc
decl_stmt|;
comment|/* where we get the unit length from	*/
define|#
directive|define
name|ULSRC_NONE
value|0
comment|/* nowhere specified		*/
define|#
directive|define
name|ULSRC_CMDL
value|1
comment|/* specified on commandline	*/
define|#
directive|define
name|ULSRC_CMDLMIN
value|5
comment|/* minimum value from cmdl	*/
define|#
directive|define
name|ULSRC_CMDLMAX
value|3600
comment|/* minimum value from cmdl	*/
define|#
directive|define
name|ULSRC_CONF
value|2
comment|/* get it from config file	*/
define|#
directive|define
name|ULSRC_RATE
value|3
comment|/* get it dynamic from ratesfile*/
define|#
directive|define
name|ULSRC_DYN
value|4
comment|/* dynamic calculated from AOCD */
name|char
modifier|*
name|answerprog
decl_stmt|;
comment|/* program to use for answering */
name|char
modifier|*
name|connectprog
decl_stmt|;
comment|/* program run after negotiation finished */
name|char
modifier|*
name|disconnectprog
decl_stmt|;
comment|/* program run after shutdown is complete */
name|int
name|callbackwait
decl_stmt|;
comment|/* time to wait before calling back */
define|#
directive|define
name|CALLBACKWAIT_MIN
value|1
name|int
name|calledbackwait
decl_stmt|;
comment|/* time to wait for remote callback */
define|#
directive|define
name|CALLEDBACKWAIT_MIN
value|2
name|int
name|dialretries
decl_stmt|;
comment|/* no. of dial tries		*/
define|#
directive|define
name|DIALRETRIES_DEF
value|1
name|int
name|recoverytime
decl_stmt|;
comment|/* time between 2 dial tries	*/
define|#
directive|define
name|RECOVERYTIME_MIN
value|1
name|int
name|dialrandincr
decl_stmt|;
comment|/* use random dial time incr	*/
name|int
name|usedown
decl_stmt|;
comment|/* set interface down yes/no	*/
name|int
name|downtries
decl_stmt|;
comment|/* retries before i/f is set down */
define|#
directive|define
name|DOWN_TRIES_MIN
value|2
define|#
directive|define
name|DOWN_TRIES_MAX
value|20
name|int
name|downtime
decl_stmt|;
comment|/* time i/f is down		*/
define|#
directive|define
name|DOWN_TIME_MIN
value|10
comment|/* 10 seconds */
define|#
directive|define
name|DOWN_TIME_MAX
value|3600
comment|/* 1 hour */
name|int
name|dialouttype
decl_stmt|;
comment|/* type of outgoing connection	*/
define|#
directive|define
name|DIALOUT_NORMAL
value|0
comment|/* normal dialout behaviour	*/
define|#
directive|define
name|DIALOUT_CALLEDBACK
value|1
comment|/* remote is expected to callback */
name|int
name|alert
decl_stmt|;
comment|/* alert time in sec if nonzero	*/
define|#
directive|define
name|MINALERT
value|5
comment|/* 5 secs min			*/
define|#
directive|define
name|MAXALERT
value|(3*60)
comment|/* 3 minutes max		*/
name|int
name|inout
decl_stmt|;
comment|/* in/out, in-only or out-only	*/
define|#
directive|define
name|DIR_INOUT
value|0
define|#
directive|define
name|DIR_INONLY
value|1
define|#
directive|define
name|DIR_OUTONLY
value|2
name|int
name|usesubaddr
decl_stmt|;
comment|/* use subaddresses		*/
name|int
name|budget_callbackperiod
decl_stmt|;
comment|/* length of a budget period (s)*/
name|int
name|budget_callbackncalls
decl_stmt|;
comment|/* call budget for a period	*/
name|char
modifier|*
name|budget_callbacks_file
decl_stmt|;
comment|/* filename to store callback stats */
name|char
name|budget_callbacksfile_rotate
decl_stmt|;
name|int
name|budget_calloutperiod
decl_stmt|;
comment|/* length of a budget period (s)*/
name|int
name|budget_calloutncalls
decl_stmt|;
comment|/* call budget for a period	*/
name|char
modifier|*
name|budget_callouts_file
decl_stmt|;
comment|/* filename to store callout stats */
name|char
name|budget_calloutsfile_rotate
decl_stmt|;
name|int
name|ppp_expect_auth
decl_stmt|;
name|int
name|ppp_send_auth
decl_stmt|;
define|#
directive|define
name|AUTH_UNDEF
value|0
define|#
directive|define
name|AUTH_NONE
value|1
define|#
directive|define
name|AUTH_PAP
value|2
define|#
directive|define
name|AUTH_CHAP
value|3
name|int
name|ppp_auth_flags
decl_stmt|;
define|#
directive|define
name|AUTH_RECHALLENGE
value|0x01
define|#
directive|define
name|AUTH_REQUIRED
value|0x02
name|char
name|ppp_expect_name
index|[
name|AUTHNAMELEN
index|]
decl_stmt|;
comment|/* PPP PAP/CHAP login name */
name|char
name|ppp_send_name
index|[
name|AUTHNAMELEN
index|]
decl_stmt|;
name|char
name|ppp_expect_password
index|[
name|AUTHKEYLEN
index|]
decl_stmt|;
name|char
name|ppp_send_password
index|[
name|AUTHKEYLEN
index|]
decl_stmt|;
name|int
name|day
decl_stmt|;
comment|/* days valid */
define|#
directive|define
name|SU
value|0x01
define|#
directive|define
name|MO
value|0x02
define|#
directive|define
name|TU
value|0x04
define|#
directive|define
name|WE
value|0x08
define|#
directive|define
name|TH
value|0x10
define|#
directive|define
name|FR
value|0x20
define|#
directive|define
name|SA
value|0x40
define|#
directive|define
name|HD
value|0x80
comment|/* holiday */
name|int
name|fromhr
decl_stmt|;
comment|/* time valid */
name|int
name|frommin
decl_stmt|;
name|int
name|tohr
decl_stmt|;
name|int
name|tomin
decl_stmt|;
name|time_t
name|maxconnecttime
decl_stmt|;
comment|/* maximum connection time */
comment|/*===========================================================================*/
comment|/*============ filled in after start, then dynamic ==========================*/
comment|/*===========================================================================*/
name|int
name|cdid
decl_stmt|;
comment|/* cdid for call		*/
define|#
directive|define
name|CDID_RESERVED
value|(-1)
name|int
name|isdncontrollerused
decl_stmt|;
comment|/* the one we are using		*/
name|int
name|isdnchannelused
decl_stmt|;
comment|/* the one we are using		*/
name|int
name|fs_position
decl_stmt|;
comment|/* fullscreen position		*/
name|int
name|state
decl_stmt|;
comment|/* state of connection 		*/
define|#
directive|define
name|ST_IDLE
value|0
comment|/* connection is idle / disconnected  */
comment|/* normal dial out to remote */
define|#
directive|define
name|ST_DIAL
value|1
comment|/* dialing                            */
define|#
directive|define
name|ST_DIALRTMRCHD
value|2
comment|/* wait for dial retry time reached   */
define|#
directive|define
name|ST_DIALRETRY
value|3
comment|/* last/first dialing failed, retry   */
comment|/* PCB: passive callback, i'm being called back */
define|#
directive|define
name|ST_PCB_DIAL
value|4
comment|/* dialing, trigger a callback        */
define|#
directive|define
name|ST_PCB_DIALFAIL
value|5
comment|/* dialing failed triggering a callbk */
define|#
directive|define
name|ST_PCB_WAITCALL
value|6
comment|/* waiting for callback from remote   */
comment|/* ACB: active callback, i'm calling back */
define|#
directive|define
name|ST_ACB_WAITDISC
value|7
comment|/* got call, wait for disconnect      */
define|#
directive|define
name|ST_ACB_WAITDIAL
value|8
comment|/* wait until allowed to callback     */
define|#
directive|define
name|ST_ACB_DIAL
value|9
comment|/* callback to remote                 */
define|#
directive|define
name|ST_ACB_DIALFAIL
value|10
comment|/* callback to remote failed          */
comment|/* normal non-dialling states */
define|#
directive|define
name|ST_ACCEPTED
value|11
comment|/* remote accepted                    */
define|#
directive|define
name|ST_CONNECTED
value|12
comment|/* connected with remote              */
define|#
directive|define
name|ST_WAITDISCI
value|13
comment|/* tx disc req, wait for disc ind     */
define|#
directive|define
name|ST_DOWN
value|14
comment|/* interface is down                  */
define|#
directive|define
name|ST_ALERT
value|15
comment|/* interface is waiting for alert time*/
comment|/* illegal and pseudo states */
define|#
directive|define
name|ST_ILL
value|16
comment|/* illegal state 		      */
define|#
directive|define
name|ST_SUSE
value|17
comment|/* subroutine sets new state	      */
define|#
directive|define
name|N_STATES
value|(ST_ILL+1)
comment|/* max number of states               */
name|cause_t
name|disc_cause
decl_stmt|;
comment|/* cause from disconnect */
name|int
name|local_disconnect
decl_stmt|;
comment|/* flag, who disconnected */
define|#
directive|define
name|DISCON_LOC
value|0
define|#
directive|define
name|DISCON_REM
value|1
name|int
name|timerval
decl_stmt|;
comment|/* value for timer, 0 if inactive */
name|int
name|timerremain
decl_stmt|;
comment|/* remaining time	*/
name|int
name|hangup
decl_stmt|;
comment|/* flag, hangup connection asap */
name|number_t
name|real_phone_incoming
decl_stmt|;
comment|/* real remote telno in case of wildcard */
name|int
name|last_remote_number
decl_stmt|;
comment|/* index of last used dialout number*/
name|number_t
name|remote_phone_dialout
decl_stmt|;
comment|/* used remote number to dial */
name|int
name|direction
decl_stmt|;
comment|/* incoming or outgoing */
define|#
directive|define
name|DIR_IN
value|0
define|#
directive|define
name|DIR_OUT
value|1
name|int
name|charge
decl_stmt|;
comment|/* charge in units */
name|int
name|last_charge
decl_stmt|;
comment|/* last charge in units */
name|int
name|inbytes
decl_stmt|;
comment|/* # of bytes from remote */
name|int
name|iinbytes
decl_stmt|;
comment|/* # of bytes from remote on the line */
name|int
name|inbps
decl_stmt|;
comment|/* bytes/sec from remote */
name|int
name|outbytes
decl_stmt|;
comment|/* # of bytes to remote */
name|int
name|ioutbytes
decl_stmt|;
comment|/* # of bytes to remote on the line */
name|int
name|outbps
decl_stmt|;
comment|/* bytes/sec to remote */
name|time_t
name|connect_time
decl_stmt|;
comment|/* time connection was established */
name|time_t
name|aoc_last
decl_stmt|;
comment|/* last AOCD timestamp		*/
name|time_t
name|aoc_now
decl_stmt|;
comment|/* current AOCD timestamp	*/
name|time_t
name|aoc_diff
decl_stmt|;
comment|/* current unit length		*/
name|time_t
name|aoc_lastdiff
decl_stmt|;
comment|/* last charge unit length	*/
name|int
name|aoc_valid
decl_stmt|;
comment|/* flag: time diff is valid	*/
define|#
directive|define
name|AOC_INVALID
value|0
comment|/* aoc_diff is NOT valid	*/
define|#
directive|define
name|AOC_VALID
value|1
comment|/* aoc_diff is valid		*/
name|time_t
name|last_dial_time
decl_stmt|;
comment|/* time of last dialing		*/
name|time_t
name|last_release_time
decl_stmt|;
comment|/* time of last hangup		*/
name|int
name|dial_count
decl_stmt|;
comment|/* number of dialout tries	*/
name|int
name|randomtime
decl_stmt|;
comment|/* random() part of recoverytime*/
define|#
directive|define
name|RANDOM_MASK
value|0x04
comment|/* bits used from randomtime	*/
name|int
name|down_retry_count
decl_stmt|;
comment|/* retry cycle count for usedown*/
name|time_t
name|went_down_time
decl_stmt|;
comment|/* time i/f went down		*/
name|phantom_t
name|saved_call
decl_stmt|;
comment|/* outgoing call state if called 					   back too early */
name|int
name|alert_time
decl_stmt|;
comment|/* count down of alert time	*/
name|char
name|display
index|[
name|DISPLAY_MAX
index|]
decl_stmt|;
name|time_t
name|budget_callbackperiod_time
decl_stmt|;
comment|/* end of current period	*/
name|int
name|budget_callbackncalls_cnt
decl_stmt|;
comment|/* amount of calls left	*/
name|int
name|budget_callback_req
decl_stmt|;
comment|/* requests			*/
name|int
name|budget_callback_done
decl_stmt|;
comment|/* call done			*/
name|int
name|budget_callback_rej
decl_stmt|;
comment|/* call refused			*/
name|time_t
name|budget_calloutperiod_time
decl_stmt|;
comment|/* end of current period	*/
name|int
name|budget_calloutncalls_cnt
decl_stmt|;
comment|/* amount of calls left	*/
name|int
name|budget_callout_req
decl_stmt|;
comment|/* requests			*/
name|int
name|budget_callout_done
decl_stmt|;
comment|/* call done			*/
name|int
name|budget_callout_rej
decl_stmt|;
comment|/* call refused			*/
name|int
name|budget_calltype
decl_stmt|;
comment|/* type of call			*/
define|#
directive|define
name|BUDGET_TYPE_CBACK
value|1
define|#
directive|define
name|BUDGET_TYPE_COUT
value|2
name|char
name|keypad
index|[
name|KEYPAD_MAX
index|]
decl_stmt|;
comment|/* keypad string		*/
block|}
name|cfg_entry_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes state of controller with MAX_BCHAN b channels  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isdn_ctrl_state
block|{
name|int
name|ctrl_type
decl_stmt|;
comment|/* type: active/passive 	*/
name|int
name|card_type
decl_stmt|;
comment|/* manufacturer (CARD_XXXX) 	*/
name|int
name|protocol
decl_stmt|;
comment|/* ISDN D-channel protocol 	*/
name|char
modifier|*
name|firmware
decl_stmt|;
comment|/* loadable fimrware file name 	*/
name|int
name|state
decl_stmt|;
comment|/* controller state		*/
define|#
directive|define
name|CTRL_DOWN
value|0
comment|/* controller inoparable	*/
define|#
directive|define
name|CTRL_UP
value|1
comment|/* controller may be used	*/
define|#
directive|define
name|MAX_BCHAN
value|30
name|int
name|stateb
index|[
name|MAX_BCHAN
index|]
decl_stmt|;
comment|/* b channel state */
define|#
directive|define
name|CHAN_IDLE
value|0
comment|/* channel is free for usage	*/
define|#
directive|define
name|CHAN_RUN
value|1
comment|/* channel is occupied		*/
name|int
name|nbch
decl_stmt|;
comment|/* number of b channels */
name|int
name|freechans
decl_stmt|;
comment|/* number of unused channels	*/
name|int
name|tei
decl_stmt|;
comment|/* tei or -1 if invalid		*/
name|int
name|l1stat
decl_stmt|;
comment|/* layer 1 state		*/
name|int
name|l2stat
decl_stmt|;
comment|/* layer 2 state		*/
block|}
name|isdn_ctrl_state_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this struct describes a logging regular expression  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|rarr
block|{
name|int
name|re_flg
decl_stmt|;
comment|/* valid entry flag */
name|char
modifier|*
name|re_expr
decl_stmt|;
comment|/* plain text expression */
name|regex_t
name|re
decl_stmt|;
comment|/* compiled expression */
name|char
modifier|*
name|re_prog
decl_stmt|;
comment|/* the program to be executed */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|I4B_EXTERNAL_MONITOR
end_ifdef

begin_comment
comment|/* for each rights entry we keep one of this structures around: */
end_comment

begin_struct
struct|struct
name|monitor_rights
block|{
name|TAILQ_ENTRY
argument_list|(
argument|monitor_rights
argument_list|)
name|list
expr_stmt|;
comment|/* a list of this structures */
name|char
name|name
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
comment|/* net/host spec or filename */
name|int
name|rights
decl_stmt|;
comment|/* bitmask of allowed acces rights */
name|u_int32_t
name|net
decl_stmt|;
comment|/* net/host address (host byte order!) */
name|u_int32_t
name|mask
decl_stmt|;
comment|/* bitmask 1 = network, 0 = host (host byte order!) */
name|int
name|local
decl_stmt|;
comment|/* zero if remote access via tcp/ip */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	global variables, storage allocation  *---------------------------------------------------------------------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
name|int
name|isdnfd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file handle, /dev/i4b */
end_comment

begin_decl_stmt
name|char
name|mailto
index|[
name|MAXPATHLEN
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* panic mail address */
end_comment

begin_decl_stmt
name|char
name|mailer
index|[
name|MAXPATHLEN
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* panic mail address */
end_comment

begin_decl_stmt
name|char
modifier|*
name|configfile
init|=
name|CONFIG_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration filename */
end_comment

begin_decl_stmt
name|int
name|config_error_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error counter */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|do_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug mode flag	*/
end_comment

begin_decl_stmt
name|int
name|debug_flags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug options	*/
end_comment

begin_decl_stmt
name|int
name|debug_noscreen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* not on fullscreen	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|do_bell
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bell on connect/disconnect */
end_comment

begin_decl_stmt
name|int
name|do_fork
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* run as daemon/foreground */
end_comment

begin_decl_stmt
name|int
name|do_ttytype
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* got new terminal type */
end_comment

begin_decl_stmt
name|char
modifier|*
name|ttype
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* termcap entry name string */
end_comment

begin_decl_stmt
name|int
name|do_rdev
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* redirect output	*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|rdev
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new device string */
end_comment

begin_decl_stmt
name|int
name|do_print
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* config file printout */
end_comment

begin_decl_stmt
name|int
name|got_unitlen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, got length of a unit */
end_comment

begin_decl_stmt
name|time_t
name|unit_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of a unit */
end_comment

begin_decl_stmt
name|cfg_entry_t
name|cfg_entry_tab
index|[
name|CFG_ENTRY_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration table */
end_comment

begin_decl_stmt
name|isdn_ctrl_state_t
name|isdn_ctrl_tab
index|[
name|ISDN_CTRL_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controller states table */
end_comment

begin_decl_stmt
name|int
name|ncontroller
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of controllers available */
end_comment

begin_decl_stmt
name|int
name|nentries
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of entries in config tab */
end_comment

begin_decl_stmt
name|int
name|uselogfile
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, use a logfile */
end_comment

begin_decl_stmt
name|char
name|logfile
index|[
name|MAXPATHLEN
index|]
init|=
name|LOG_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log filename */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|logfp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log file pointer */
end_comment

begin_decl_stmt
name|int
name|logfacility
init|=
name|LOG_LOCAL0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the syslog facility used */
end_comment

begin_decl_stmt
name|int
name|nregex
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of reg expr */
end_comment

begin_decl_stmt
name|struct
name|rarr
name|rarr
index|[
name|MAX_RE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regexpr& progs table */
end_comment

begin_decl_stmt
name|char
name|ratesfile
index|[
name|MAXPATHLEN
index|]
init|=
name|RATES_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rates filename */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rate_error
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* errorcase: error string */
end_comment

begin_decl_stmt
name|int
name|got_rate
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, ratesfile found */
end_comment

begin_decl_stmt
name|struct
name|rates
modifier|*
name|rates
index|[
name|NRATES
index|]
index|[
name|NDAYS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the rates structure */
end_comment

begin_decl_stmt
name|int
name|useacctfile
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, write accounting */
end_comment

begin_decl_stmt
name|char
name|acctfile
index|[
name|MAXPATHLEN
index|]
init|=
name|ACCT_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accounting  filename */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|acctfp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accounting file pointer */
end_comment

begin_decl_stmt
name|int
name|acct_all
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* account all connections */
end_comment

begin_decl_stmt
name|int
name|aliasing
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* enable alias processing */
end_comment

begin_decl_stmt
name|char
name|aliasfile
index|[
name|MAXPATHLEN
index|]
init|=
name|ALIASFILE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alias file location */
end_comment

begin_decl_stmt
name|int
name|do_fullscreen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fullscreen log	*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_CURSES
end_ifdef

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
name|int
name|rt_prio
init|=
name|RTPRIO_NOTUSED
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* realtime priority */
end_comment

begin_comment
comment|/* monitor via network */
end_comment

begin_decl_stmt
name|int
name|do_monitor
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inhibit_monitor
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|I4B_EXTERNAL_MONITOR
end_ifdef

begin_decl_stmt
name|int
name|monitorport
init|=
name|DEF_MONPORT
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|monitorport
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|accepted
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isdntime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, log time from exchange	*/
end_comment

begin_decl_stmt
name|int
name|extcallattr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag, display extended caller attributes */
end_comment

begin_decl_stmt
name|char
name|tinainitprog
index|[
name|MAXPATHLEN
index|]
init|=
name|TINA_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|rotatesuffix
index|[
name|MAXPATHLEN
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|starttime
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|holidayfile
index|[
name|MAXPATHLEN
index|]
init|=
name|HOLIDAY_FILE_DEF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holiday filename */
end_comment

begin_decl_stmt
name|int
name|addprefix
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prefixnational
index|[
name|TELNO_MAX
index|]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prefixinternational
index|[
name|TELNO_MAX
index|]
init|=
literal|""
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
name|int
name|isdnfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mailto
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|mailer
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|configfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|config_error_flag
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|do_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|debug_noscreen
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|do_bell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_fork
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_ttytype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ttype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_rdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|got_unitlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|unit_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cfg_entry_t
name|cfg_entry_tab
index|[
name|CFG_ENTRY_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration table */
end_comment

begin_decl_stmt
name|isdn_ctrl_state_t
name|isdn_ctrl_tab
index|[
name|ISDN_CTRL_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* controller states table */
end_comment

begin_decl_stmt
name|int
name|ncontroller
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nentries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uselogfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|logfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|logfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logfacility
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nregex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rarr
name|rarr
index|[
name|MAX_RE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ratesfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rate_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|got_rate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rates
modifier|*
name|rates
index|[
name|NRATES
index|]
index|[
name|NDAYS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|useacctfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|acctfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|acctfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|acct_all
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aliasing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|aliasfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_fullscreen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curses_ready
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_CURSES
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|rt_prio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_monitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|inhibit_monitor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|monitorport
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|accepted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isdntime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|extcallattr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tinainitprog
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|rotatesuffix
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|starttime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|holidayfile
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|addprefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prefixnational
index|[
name|TELNO_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prefixinternational
index|[
name|TELNO_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAIN */
end_comment

begin_function_decl
name|int
name|add_number_prefix
parameter_list|(
name|char
modifier|*
name|number
parameter_list|,
name|int
name|type_of_number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bdrivername
parameter_list|(
name|int
name|drivertype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfg_setval
parameter_list|(
name|int
name|keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_and_kill
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_pid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_allactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configure
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|reread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|daemonize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialresponse
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|dstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_acct
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_bell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_ccharge
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|units
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_chans
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_charge
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_connect
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display_disconnect
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|display_updown
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|updown
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_exit
parameter_list|(
name|int
name|exitval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_menu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exec_answer
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exec_connect_prog
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
specifier|const
name|char
modifier|*
name|prog
parameter_list|,
name|int
name|link_down
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|exec_prog
parameter_list|(
name|char
modifier|*
name|prog
parameter_list|,
name|char
modifier|*
modifier|*
name|arglist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|find_by_device_for_dialout
parameter_list|(
name|int
name|drivertype
parameter_list|,
name|int
name|driverunit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|find_by_device_for_dialoutnumber
parameter_list|(
name|msg_dialoutnumber_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|find_by_device_for_keypad
parameter_list|(
name|int
name|drivertype
parameter_list|,
name|int
name|driverunit
parameter_list|,
name|int
name|cmdlen
parameter_list|,
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|find_matching_entry_incoming
parameter_list|(
name|msg_connect_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|find_active_entry_by_driver
parameter_list|(
name|int
name|drivertype
parameter_list|,
name|int
name|driverunit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getlogdatetime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_cdid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|get_cep_by_cc
parameter_list|(
name|int
name|ctrlr
parameter_list|,
name|int
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|get_cep_by_driver
parameter_list|(
name|int
name|drivertype
parameter_list|,
name|int
name|driverunit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cfg_entry_t
modifier|*
name|get_cep_by_cdid
parameter_list|(
name|int
name|cdid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_current_rate
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|logit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|handle_charge
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|handle_recovery
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|handle_scrprs
parameter_list|(
name|int
name|cdid
parameter_list|,
name|int
name|scr
parameter_list|,
name|int
name|prs
parameter_list|,
name|char
modifier|*
name|caller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_up
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_down
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_controller
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_controller_protocol
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_screen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|llog
parameter_list|(
name|int
name|what
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|msg_accounting
parameter_list|(
name|msg_accounting_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_alert_ind
parameter_list|(
name|msg_alert_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_charging_ind
parameter_list|(
name|msg_charging_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_connect_active_ind
parameter_list|(
name|msg_connect_active_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_connect_ind
parameter_list|(
name|msg_connect_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_pdeact_ind
parameter_list|(
name|msg_pdeact_ind_t
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_negcomplete_ind
parameter_list|(
name|msg_negcomplete_ind_t
modifier|*
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_ifstatechg_ind
parameter_list|(
name|msg_ifstatechg_ind_t
modifier|*
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_drvrdisc_req
parameter_list|(
name|msg_drvrdisc_req_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_dialout
parameter_list|(
name|msg_dialout_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_dialoutnumber
parameter_list|(
name|msg_dialoutnumber_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_disconnect_ind
parameter_list|(
name|msg_disconnect_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_idle_timeout_ind
parameter_list|(
name|msg_idle_timeout_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_l12stat_ind
parameter_list|(
name|msg_l12stat_ind_t
modifier|*
name|ml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_teiasg_ind
parameter_list|(
name|msg_teiasg_ind_t
modifier|*
name|mt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_proceeding_ind
parameter_list|(
name|msg_proceeding_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_packet_ind
parameter_list|(
name|msg_packet_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msg_keypad
parameter_list|(
name|msg_keypad_ind_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|name_of_controller
parameter_list|(
name|int
name|ctrl_type
parameter_list|,
name|int
name|card_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|next_state
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|print_i4b_cause
parameter_list|(
name|cause_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|printstate
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readrates
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ret_channel_state
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reopenfiles
parameter_list|(
name|int
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rereadconfig
parameter_list|(
name|int
name|dummy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|select_first_dialno
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|select_next_dialno
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|select_this_dialno
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendm_alert_req
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendm_connect_req
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendm_connect_resp
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|cdid
parameter_list|,
name|int
name|response
parameter_list|,
name|cause_t
name|cause
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendm_disconnect_req
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|cause_t
name|cause
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_channel_busy
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_channel_idle
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup_dialout
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigchild_handler
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_timer
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stop_timer
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unitlen_chkupd
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_pid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error_exit
parameter_list|(
name|int
name|exitval
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* montior server module */
end_comment

begin_function_decl
name|void
name|monitor_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_exit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_clear_rights
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_fixup_rights
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|monitor_start_rights
parameter_list|(
specifier|const
name|char
modifier|*
name|clientspec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_add_rights
parameter_list|(
name|int
name|rights
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* possible return codes from monitor_start_rights: */
end_comment

begin_define
define|#
directive|define
name|I4BMAR_OK
value|0
end_define

begin_comment
comment|/* rights added successfully */
end_comment

begin_define
define|#
directive|define
name|I4BMAR_LENGTH
value|1
end_define

begin_comment
comment|/* local socket name to long */
end_comment

begin_define
define|#
directive|define
name|I4BMAR_DUP
value|2
end_define

begin_comment
comment|/* entry already exists */
end_comment

begin_define
define|#
directive|define
name|I4BMAR_CIDR
value|3
end_define

begin_comment
comment|/* cidr netmask is invalid */
end_comment

begin_define
define|#
directive|define
name|I4BMAR_NOIP
value|4
end_define

begin_comment
comment|/* host/net could not be resolved */
end_comment

begin_function_decl
name|int
name|monitor_create_local_socket
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_NOTCPIP_MONITOR
end_ifndef

begin_function_decl
name|int
name|monitor_create_remote_socket
parameter_list|(
name|int
name|portno
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|monitor_prepselect
parameter_list|(
name|fd_set
modifier|*
name|selset
parameter_list|,
name|int
modifier|*
name|max_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_handle_input
parameter_list|(
name|fd_set
modifier|*
name|selset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_handle_connect
parameter_list|(
name|int
name|sockfd
parameter_list|,
name|int
name|is_local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_charge
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|units
parameter_list|,
name|int
name|estimated
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_connect
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_disconnect
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_updown
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|,
name|int
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_log
parameter_list|(
name|int
name|prio
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|monitor_evnt_l12stat
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
name|void
name|monitor_evnt_tei
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
name|void
name|monitor_evnt_acct
parameter_list|(
name|cfg_entry_t
modifier|*
name|cep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* controller.c */
end_comment

begin_function_decl
name|void
name|init_active_controller
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_controller_state
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_controller_state
parameter_list|(
name|int
name|controller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|decr_free_channels
parameter_list|(
name|int
name|controller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|incr_free_channels
parameter_list|(
name|int
name|controller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_free_channels
parameter_list|(
name|int
name|controller
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_channel_busy
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_channel_idle
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ret_channel_state
parameter_list|(
name|int
name|controller
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* alias.c */
end_comment

begin_function_decl
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
name|void
name|free_aliases
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|upd_callstat_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|rotateflag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* holiday.c */
end_comment

begin_function_decl
name|void
name|init_holidays
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_holidays
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isholiday
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISDND_H_ */
end_comment

end_unit

