begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * fsm.h - {Link, IP} Control Protocol Finite State Machine definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Packet header = Code, id, length.  */
end_comment

begin_define
define|#
directive|define
name|HEADERLEN
value|(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))
end_define

begin_comment
comment|/*  *  CP (LCP, PPP_IPCP, etc.) codes.  */
end_comment

begin_define
define|#
directive|define
name|CONFREQ
value|1
end_define

begin_comment
comment|/* Configuration Request */
end_comment

begin_define
define|#
directive|define
name|CONFACK
value|2
end_define

begin_comment
comment|/* Configuration Ack */
end_comment

begin_define
define|#
directive|define
name|CONFNAK
value|3
end_define

begin_comment
comment|/* Configuration Nak */
end_comment

begin_define
define|#
directive|define
name|CONFREJ
value|4
end_define

begin_comment
comment|/* Configuration Reject */
end_comment

begin_define
define|#
directive|define
name|TERMREQ
value|5
end_define

begin_comment
comment|/* Termination Request */
end_comment

begin_define
define|#
directive|define
name|TERMACK
value|6
end_define

begin_comment
comment|/* Termination Ack */
end_comment

begin_define
define|#
directive|define
name|CODEREJ
value|7
end_define

begin_comment
comment|/* Code Reject */
end_comment

begin_comment
comment|/*  * Each FSM is described by a fsm_callbacks and a fsm structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fsm_callbacks
block|{
name|void
function_decl|(
modifier|*
name|resetci
function_decl|)
parameter_list|()
function_decl|;
comment|/* Reset our Configuration Information */
name|int
function_decl|(
modifier|*
name|cilen
function_decl|)
parameter_list|()
function_decl|;
comment|/* Length of our Configuration Information */
name|void
function_decl|(
modifier|*
name|addci
function_decl|)
parameter_list|()
function_decl|;
comment|/* Add our Configuration Information */
name|int
function_decl|(
modifier|*
name|ackci
function_decl|)
parameter_list|()
function_decl|;
comment|/* ACK our Configuration Information */
name|int
function_decl|(
modifier|*
name|nakci
function_decl|)
parameter_list|()
function_decl|;
comment|/* NAK our Configuration Information */
name|int
function_decl|(
modifier|*
name|rejci
function_decl|)
parameter_list|()
function_decl|;
comment|/* Reject our Configuration Information */
name|int
function_decl|(
modifier|*
name|reqci
function_decl|)
parameter_list|()
function_decl|;
comment|/* Request peer's Configuration Information */
name|void
function_decl|(
modifier|*
name|up
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when fsm reaches OPENED state */
name|void
function_decl|(
modifier|*
name|down
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when fsm leaves OPENED state */
name|void
function_decl|(
modifier|*
name|starting
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when we want the lower layer */
name|void
function_decl|(
modifier|*
name|finished
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when we don't want the lower layer */
name|void
function_decl|(
modifier|*
name|protreject
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when Protocol-Reject received */
name|void
function_decl|(
modifier|*
name|retransmit
function_decl|)
parameter_list|()
function_decl|;
comment|/* Retransmission is necessary */
name|int
function_decl|(
modifier|*
name|extcode
function_decl|)
parameter_list|()
function_decl|;
comment|/* Called when unknown code received */
name|char
modifier|*
name|proto_name
decl_stmt|;
comment|/* String name for protocol (for messages) */
block|}
name|fsm_callbacks
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fsm
block|{
name|int
name|unit
decl_stmt|;
comment|/* Interface unit number */
name|int
name|protocol
decl_stmt|;
comment|/* Data Link Layer Protocol field value */
name|int
name|state
decl_stmt|;
comment|/* State */
name|int
name|flags
decl_stmt|;
comment|/* Contains option bits */
name|u_char
name|id
decl_stmt|;
comment|/* Current id */
name|u_char
name|reqid
decl_stmt|;
comment|/* Current request id */
name|u_char
name|seen_ack
decl_stmt|;
comment|/* Have received valid Ack/Nak/Rej to Req */
name|int
name|timeouttime
decl_stmt|;
comment|/* Timeout time in milliseconds */
name|int
name|maxconfreqtransmits
decl_stmt|;
comment|/* Maximum Configure-Request transmissions */
name|int
name|retransmits
decl_stmt|;
comment|/* Number of retransmissions left */
name|int
name|maxtermtransmits
decl_stmt|;
comment|/* Maximum Terminate-Request transmissions */
name|int
name|nakloops
decl_stmt|;
comment|/* Number of nak loops since last ack */
name|int
name|maxnakloops
decl_stmt|;
comment|/* Maximum number of nak loops tolerated */
name|fsm_callbacks
modifier|*
name|callbacks
decl_stmt|;
comment|/* Callback routines */
block|}
name|fsm
typedef|;
end_typedef

begin_comment
comment|/*  * Link states.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL
value|0
end_define

begin_comment
comment|/* Down, hasn't been opened */
end_comment

begin_define
define|#
directive|define
name|STARTING
value|1
end_define

begin_comment
comment|/* Down, been opened */
end_comment

begin_define
define|#
directive|define
name|CLOSED
value|2
end_define

begin_comment
comment|/* Up, hasn't been opened */
end_comment

begin_define
define|#
directive|define
name|STOPPED
value|3
end_define

begin_comment
comment|/* Open, waiting for down event */
end_comment

begin_define
define|#
directive|define
name|CLOSING
value|4
end_define

begin_comment
comment|/* Terminating the connection, not open */
end_comment

begin_define
define|#
directive|define
name|STOPPING
value|5
end_define

begin_comment
comment|/* Terminating, but open */
end_comment

begin_define
define|#
directive|define
name|REQSENT
value|6
end_define

begin_comment
comment|/* We've sent a Config Request */
end_comment

begin_define
define|#
directive|define
name|ACKRCVD
value|7
end_define

begin_comment
comment|/* We've received a Config Ack */
end_comment

begin_define
define|#
directive|define
name|ACKSENT
value|8
end_define

begin_comment
comment|/* We've sent a Config Ack */
end_comment

begin_define
define|#
directive|define
name|OPENED
value|9
end_define

begin_comment
comment|/* Connection available */
end_comment

begin_comment
comment|/*  * Flags - indicate options controlling FSM operation  */
end_comment

begin_define
define|#
directive|define
name|OPT_PASSIVE
value|1
end_define

begin_comment
comment|/* Don't die if we don't get a response */
end_comment

begin_define
define|#
directive|define
name|OPT_RESTART
value|2
end_define

begin_comment
comment|/* Treat 2nd OPEN as DOWN, UP */
end_comment

begin_define
define|#
directive|define
name|OPT_SILENT
value|4
end_define

begin_comment
comment|/* Wait for peer to speak first */
end_comment

begin_comment
comment|/*  * Timeouts.  */
end_comment

begin_define
define|#
directive|define
name|DEFTIMEOUT
value|3
end_define

begin_comment
comment|/* Timeout time in seconds */
end_comment

begin_define
define|#
directive|define
name|DEFMAXTERMREQS
value|2
end_define

begin_comment
comment|/* Maximum Terminate-Request transmissions */
end_comment

begin_define
define|#
directive|define
name|DEFMAXCONFREQS
value|10
end_define

begin_comment
comment|/* Maximum Configure-Request transmissions */
end_comment

begin_define
define|#
directive|define
name|DEFMAXNAKLOOPS
value|5
end_define

begin_comment
comment|/* Maximum number of nak loops */
end_comment

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_decl_stmt
name|void
name|fsm_init
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_lowerup
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_lowerdown
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_open
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_close
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_input
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_protreject
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fsm_sdata
name|__P
argument_list|(
operator|(
name|fsm
operator|*
operator|,
name|int
operator|,
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
comment|/*  * Variables  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|peer_mru
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* currently negotiated peer MRU (per unit) */
end_comment

end_unit

