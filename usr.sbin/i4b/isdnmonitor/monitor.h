begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1998,1999 Martin Husemann. All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b daemon - network monitor protocol definition  *	------------------------------------------------  *  *	$Id: monitor.h,v 1.16 1999/12/13 21:25:26 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:52:18 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MONITOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MONITOR_H_
end_define

begin_define
define|#
directive|define
name|DEF_MONPORT
value|451
end_define

begin_comment
comment|/* default monitor TCP port     */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|u_int8_t
value|ubit8
end_define

begin_define
define|#
directive|define
name|u_int32_t
value|ubit32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|u_int8_t
value|BYTE
end_define

begin_define
define|#
directive|define
name|u_int32_t
value|DWORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The monitor client connects to the isdnd daemon process via a tcp/ip  * connection from a remote machine or via a local (unix domain) socket.  * The daemon accepts multiple connections and verifies access rights.  * On connection establishment the daemon sends initial data telling  * the client the current configuration: number and type of available  * controllers, current connections, channel and interface states  * and the clients access privileges. The client sends an event mask  * telling the daemon which events it is interested in. If the client  * has appropriate rights he may send commands to the daemon.  *  * All multi-byte values are in network byte order!  */
end_comment

begin_comment
comment|/* All data packets transfered are declared as arrays of u_int8_t */
end_comment

begin_comment
comment|/* max stringlength used in this protocol */
end_comment

begin_define
define|#
directive|define
name|I4B_MAX_MON_STRING
value|256
end_define

begin_comment
comment|/* max command size from client to server */
end_comment

begin_define
define|#
directive|define
name|I4B_MAX_MON_CLIENT_CMD
value|16
end_define

begin_comment
comment|/* Version of the monitor protocol described here */
end_comment

begin_define
define|#
directive|define
name|MPROT_VERSION
value|0
end_define

begin_comment
comment|/* major version no */
end_comment

begin_define
define|#
directive|define
name|MPROT_REL
value|5
end_define

begin_comment
comment|/* release no */
end_comment

begin_comment
comment|/*  * Client access rights  */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_COMMAND_FULL
value|1
end_define

begin_comment
comment|/* may send any command */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_COMMAND_RESTRICTED
value|2
end_define

begin_comment
comment|/* may send 'harmless' commands */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_EVNT_CHANSTATE
value|16
end_define

begin_comment
comment|/* may watch b-channel states */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_EVNT_CALLIN
value|32
end_define

begin_comment
comment|/* may watch incoming calls */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_EVNT_CALLOUT
value|64
end_define

begin_comment
comment|/* may watch outgoing calls */
end_comment

begin_define
define|#
directive|define
name|I4B_CA_EVNT_I4B
value|128
end_define

begin_comment
comment|/* may watch isdnd actions */
end_comment

begin_comment
comment|/*  * General layout of a command packet. All commands have this common  * prefix. It is prepared by the macro I4B_PREP_CMD (s.b.)  */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CMD
value|0
end_define

begin_comment
comment|/* 2 byte: command code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CMD_LEN
value|2
end_define

begin_comment
comment|/* 2 byte: packet length */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CMD_HDR
value|4
end_define

begin_comment
comment|/* size of header */
end_comment

begin_comment
comment|/*  * Currently events look the same as commands. We do not make  * any guarantee this will remain the same, so a different set  * of macros is used when describing events. Events are prepared  * by I4B_PREP_EVNT (s.b.)  */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_EVNT
value|0
end_define

begin_comment
comment|/* 2 byte: event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_EVNT_LEN
value|2
end_define

begin_comment
comment|/* 2 byte: packet length */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_EVNT_HDR
value|4
end_define

begin_comment
comment|/* size of header */
end_comment

begin_comment
comment|/* Initial data send by daemon after connection is established */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_SIZE
value|I4B_MON_EVNT_HDR+12
end_define

begin_define
define|#
directive|define
name|I4B_MON_IDATA_CODE
value|0
end_define

begin_comment
comment|/* event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_VERSMAJOR
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 2 byte: isdnd major version */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_VERSMINOR
value|I4B_MON_EVNT_HDR+2
end_define

begin_comment
comment|/* 2 byte: isdnd minor version */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_NUMCTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 2 byte: number of controllers */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_NUMENTR
value|I4B_MON_EVNT_HDR+6
end_define

begin_comment
comment|/* 2 byte: number of controllers */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDATA_CLACCESS
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: client rights */
end_comment

begin_comment
comment|/* followed by this for every controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_SIZE
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+8
end_define

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_CODE
value|1
end_define

begin_comment
comment|/* event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_NAME
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* string: name of controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_BUSID
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+0
end_define

begin_comment
comment|/* 2 byte: isdn bus id (reservered) */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_FLAGS
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+2
end_define

begin_comment
comment|/* 4 byte: controller flags (not yet defined) */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICTRL_NCHAN
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+6
end_define

begin_comment
comment|/* 2 byte: number of b channels on this controller */
end_comment

begin_comment
comment|/* followed by this for every entry */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDEV_SIZE
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+2
end_define

begin_define
define|#
directive|define
name|I4B_MON_IDEV_CODE
value|2
end_define

begin_comment
comment|/* event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDEV_NAME
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* string: name of device */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_IDEV_STATE
value|I4B_MON_EVNT_HDR+I4B_MAX_MON_STRING+0
end_define

begin_comment
comment|/* 2 byte: state of device */
end_comment

begin_comment
comment|/*  * The client sets it's protocol version and event mask (usually once after  * connection establishement)  */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CCMD_SETMASK
value|0x7e
end_define

begin_comment
comment|/* command code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICLIENT_SIZE
value|I4B_MON_CMD_HDR+8
end_define

begin_define
define|#
directive|define
name|I4B_MON_ICLIENT_VERMAJOR
value|I4B_MON_CMD_HDR+0
end_define

begin_comment
comment|/* 2 byte: protocol major version (always 0 for now) */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICLIENT_VERMINOR
value|I4B_MON_CMD_HDR+2
end_define

begin_comment
comment|/* 2 byte: protocol minor version (always 0 for now) */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ICLIENT_EVENTS
value|I4B_MON_CMD_HDR+4
end_define

begin_comment
comment|/* 4 byte: client event mask */
end_comment

begin_comment
comment|/* The client requests a list of monitor rights */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DUMPRIGHTS_CODE
value|1
end_define

begin_define
define|#
directive|define
name|I4B_MON_DUMPRIGHTS_SIZE
value|I4B_MON_CMD_HDR
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_comment
comment|/*  * in response to a I4B_MON_DUMPRIGHTS_CODE command, the daemon sends  * this event:  */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DRINI_CODE
value|2
end_define

begin_comment
comment|/* event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DRINI_SIZE
value|I4B_MON_EVNT_HDR+2
end_define

begin_comment
comment|/* size of packet */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DRINI_COUNT
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 2 byte: number of records */
end_comment

begin_comment
comment|/* followed by this for each record anounced above */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DR_CODE
value|3
end_define

begin_define
define|#
directive|define
name|I4B_MON_DR_SIZE
value|I4B_MON_EVNT_HDR+13
end_define

begin_define
define|#
directive|define
name|I4B_MON_DR_RIGHTS
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: rights mask */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DR_NET
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: network address */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DR_MASK
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: network mask */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DR_LOCAL
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 1 byte: non-zero if local socket */
end_comment

begin_comment
comment|/* The client requests a list of monitor connections */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DUMPMCONS_CODE
value|2
end_define

begin_define
define|#
directive|define
name|I4B_MON_DUMPMCONS_SIZE
value|I4B_MON_CMD_HDR
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_comment
comment|/*  * in response to a I4B_MON_DUMPMCONS_CODE command, the daemon sends  * this event:  */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DCINI_CODE
value|4
end_define

begin_comment
comment|/* event code */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DCINI_SIZE
value|I4B_MON_EVNT_HDR+2
end_define

begin_comment
comment|/* size of packet */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DCINI_COUNT
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 2 byte: number of records */
end_comment

begin_comment
comment|/* followed by this for each record anounced above */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DC_CODE
value|5
end_define

begin_define
define|#
directive|define
name|I4B_MON_DC_SIZE
value|I4B_MON_EVNT_HDR+8
end_define

begin_define
define|#
directive|define
name|I4B_MON_DC_RIGHTS
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: rights mask */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DC_WHO
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: network address */
end_comment

begin_comment
comment|/* The client requests a config file rescan */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CFGREREAD_CODE
value|3
end_define

begin_define
define|#
directive|define
name|I4B_MON_CFGREREAD_SIZE
value|I4B_MON_CMD_HDR
end_define

begin_comment
comment|/* no parameters */
end_comment

begin_comment
comment|/* The client requests to hangup a connection */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_HANGUP_CODE
value|4
end_define

begin_define
define|#
directive|define
name|I4B_MON_HANGUP_SIZE
value|I4B_MON_CMD_HDR+8
end_define

begin_define
define|#
directive|define
name|I4B_MON_HANGUP_CTRL
value|I4B_MON_CMD_HDR+0
end_define

begin_comment
comment|/* controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_HANGUP_CHANNEL
value|I4B_MON_CMD_HDR+4
end_define

begin_comment
comment|/* channel */
end_comment

begin_comment
comment|/* The daemon sends a logfile event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_CODE
value|6
end_define

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_SIZE
value|I4B_MON_EVNT_HDR+8+2*I4B_MAX_MON_STRING
end_define

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: timestamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_PRIO
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: syslog priority */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_WHAT
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* followed by 2 strings: 'what' and 'message' */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_LOGEVNT_MSG
value|I4B_MON_EVNT_HDR+8+I4B_MAX_MON_STRING
end_define

begin_comment
comment|/* The daemon sends a charge event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CHRG_CODE
value|7
end_define

begin_define
define|#
directive|define
name|I4B_MON_CHRG_SIZE
value|I4B_MON_EVNT_HDR+20
end_define

begin_define
define|#
directive|define
name|I4B_MON_CHRG_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: timestamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CHRG_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: channel charged */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CHRG_CHANNEL
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: channel charged */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CHRG_UNITS
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 4 byte: new charge value */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CHRG_ESTIMATED
value|I4B_MON_EVNT_HDR+16
end_define

begin_comment
comment|/* 4 byte: 0 = charge by network, 1 = calculated estimate */
end_comment

begin_comment
comment|/* The daemon sends a connect event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_CODE
value|8
end_define

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_SIZE
value|I4B_MON_EVNT_HDR+16+4*I4B_MAX_MON_STRING
end_define

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_DIR
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: direction (0 = incoming, 1 = outgoing) */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_CTRL
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: channel connected */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_CHANNEL
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 4 byte: channel connected */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_CFGNAME
value|I4B_MON_EVNT_HDR+16
end_define

begin_comment
comment|/* name of config entry */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_DEVNAME
value|I4B_MON_EVNT_HDR+16+I4B_MAX_MON_STRING
end_define

begin_comment
comment|/* name of device used for connection */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_REMPHONE
value|I4B_MON_EVNT_HDR+16+2*I4B_MAX_MON_STRING
end_define

begin_comment
comment|/* remote phone no. */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_CONNECT_LOCPHONE
value|I4B_MON_EVNT_HDR+16+3*I4B_MAX_MON_STRING
end_define

begin_comment
comment|/* local phone no. */
end_comment

begin_comment
comment|/* The daemon sends a disconnect event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DISCONNECT_CODE
value|9
end_define

begin_define
define|#
directive|define
name|I4B_MON_DISCONNECT_SIZE
value|I4B_MON_EVNT_HDR+12
end_define

begin_define
define|#
directive|define
name|I4B_MON_DISCONNECT_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DISCONNECT_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: channel disconnected */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_DISCONNECT_CHANNEL
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: channel disconnected */
end_comment

begin_comment
comment|/* The daemon sends an up/down event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_CODE
value|10
end_define

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_SIZE
value|I4B_MON_EVNT_HDR+16
end_define

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: channel disconnected */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_CHANNEL
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: channel disconnected */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_UPDOWN_ISUP
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 4 byte: interface is up */
end_comment

begin_comment
comment|/* The daemon sends a L1/L2 status change event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_CODE
value|11
end_define

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_SIZE
value|I4B_MON_EVNT_HDR+16
end_define

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_LAYER
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: layer */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_L12STAT_STATE
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 4 byte: state */
end_comment

begin_comment
comment|/* The daemon sends a TEI change event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_TEI_CODE
value|12
end_define

begin_define
define|#
directive|define
name|I4B_MON_TEI_SIZE
value|I4B_MON_EVNT_HDR+12
end_define

begin_define
define|#
directive|define
name|I4B_MON_TEI_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_TEI_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_TEI_TEI
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: tei */
end_comment

begin_comment
comment|/* The daemon sends an accounting message event */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_CODE
value|13
end_define

begin_define
define|#
directive|define
name|I4B_MON_ACCT_SIZE
value|I4B_MON_EVNT_HDR+28
end_define

begin_define
define|#
directive|define
name|I4B_MON_ACCT_TSTAMP
value|I4B_MON_EVNT_HDR+0
end_define

begin_comment
comment|/* 4 byte: time stamp */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_CTRL
value|I4B_MON_EVNT_HDR+4
end_define

begin_comment
comment|/* 4 byte: controller */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_CHAN
value|I4B_MON_EVNT_HDR+8
end_define

begin_comment
comment|/* 4 byte: channel */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_OBYTES
value|I4B_MON_EVNT_HDR+12
end_define

begin_comment
comment|/* 4 byte: outbytes */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_OBPS
value|I4B_MON_EVNT_HDR+16
end_define

begin_comment
comment|/* 4 byte: outbps */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_IBYTES
value|I4B_MON_EVNT_HDR+20
end_define

begin_comment
comment|/* 4 byte: inbytes */
end_comment

begin_define
define|#
directive|define
name|I4B_MON_ACCT_IBPS
value|I4B_MON_EVNT_HDR+24
end_define

begin_comment
comment|/* 4 byte: inbps */
end_comment

begin_comment
comment|/* macros for setup/decoding of protocol packets */
end_comment

begin_comment
comment|/* clear a record */
end_comment

begin_define
define|#
directive|define
name|I4B_CLEAR
parameter_list|(
name|r
parameter_list|)
value|memset(&(r), 0, sizeof(r));
end_define

begin_comment
comment|/* prepare a record as event or command */
end_comment

begin_define
define|#
directive|define
name|I4B_PREP_EVNT
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|{			\ 	I4B_CLEAR(r);					\ 	I4B_PUT_2B(r, I4B_MON_EVNT, e);			\ 	I4B_PUT_2B(r, I4B_MON_EVNT_LEN, sizeof(r));	\ }
end_define

begin_define
define|#
directive|define
name|I4B_PREP_CMD
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|{			\ 	I4B_CLEAR(r);					\ 	I4B_PUT_2B(r, I4B_MON_CMD, c);			\ 	I4B_PUT_2B(r, I4B_MON_CMD_LEN, sizeof(r));	\ }
end_define

begin_comment
comment|/* put 1, 2 or 4 bytes in network byte order into a record at offset off */
end_comment

begin_define
define|#
directive|define
name|I4B_PUT_1B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
value|{ ((u_int8_t*)(r))[off] = (val)& 0x00ff; }
end_define

begin_define
define|#
directive|define
name|I4B_PUT_2B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
value|{ I4B_PUT_1B(r, off, val>> 8); I4B_PUT_1B(r, off+1, val); }
end_define

begin_define
define|#
directive|define
name|I4B_PUT_4B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
value|{ I4B_PUT_1B(r, off, val>> 24); I4B_PUT_1B(r, off+1, val>> 16); I4B_PUT_1B(r, off+2, val>> 8); I4B_PUT_1B(r, off+3, val); }
end_define

begin_comment
comment|/* get 1, 2 or 4 bytes in network byte order from a record at offset off */
end_comment

begin_define
define|#
directive|define
name|I4B_GET_1B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|)
value|(((u_int8_t*)(r))[off])
end_define

begin_define
define|#
directive|define
name|I4B_GET_2B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|)
value|((((u_int8_t*)(r))[off])<< 8) | (((u_int8_t*)(r))[off+1])
end_define

begin_define
define|#
directive|define
name|I4B_GET_4B
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|)
value|((((u_int8_t*)(r))[off])<< 24) | ((((u_int8_t*)(r))[off+1])<< 16) | ((((u_int8_t*)(r))[off+2])<< 8) | (((u_int8_t*)(r))[off+3])
end_define

begin_comment
comment|/*  * put a string into record r at offset off, make sure it's not to long  * and proper terminate it  */
end_comment

begin_define
define|#
directive|define
name|I4B_PUT_STR
parameter_list|(
name|r
parameter_list|,
name|off
parameter_list|,
name|str
parameter_list|)
value|{		\ 	strncpy((r)+(off), (str), I4B_MAX_MON_STRING);	\ 	(r)[(off)+I4B_MAX_MON_STRING-1] = (u_int8_t)0;     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MONITOR_H_ */
end_comment

end_unit

