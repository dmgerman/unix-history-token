begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|PHASE_DEAD
value|0
end_define

begin_comment
comment|/* Link is dead */
end_comment

begin_define
define|#
directive|define
name|PHASE_ESTABLISH
value|1
end_define

begin_comment
comment|/* Establishing link */
end_comment

begin_define
define|#
directive|define
name|PHASE_AUTHENTICATE
value|2
end_define

begin_comment
comment|/* Being authenticated */
end_comment

begin_define
define|#
directive|define
name|PHASE_NETWORK
value|3
end_define

begin_comment
comment|/* We're alive ! */
end_comment

begin_define
define|#
directive|define
name|PHASE_TERMINATE
value|4
end_define

begin_comment
comment|/* Terminating link */
end_comment

begin_comment
comment|/* cfg.opt bit settings */
end_comment

begin_define
define|#
directive|define
name|OPT_FILTERDECAP
value|0x0001
end_define

begin_define
define|#
directive|define
name|OPT_IDCHECK
value|0x0002
end_define

begin_define
define|#
directive|define
name|OPT_IFACEALIAS
value|0x0004
end_define

begin_define
define|#
directive|define
name|OPT_KEEPSESSION
value|0x0008
end_define

begin_define
define|#
directive|define
name|OPT_LOOPBACK
value|0x0010
end_define

begin_define
define|#
directive|define
name|OPT_PASSWDAUTH
value|0x0020
end_define

begin_define
define|#
directive|define
name|OPT_PROXY
value|0x0040
end_define

begin_define
define|#
directive|define
name|OPT_PROXYALL
value|0x0080
end_define

begin_define
define|#
directive|define
name|OPT_SROUTES
value|0x0100
end_define

begin_define
define|#
directive|define
name|OPT_TCPMSSFIXUP
value|0x0200
end_define

begin_define
define|#
directive|define
name|OPT_THROUGHPUT
value|0x0400
end_define

begin_define
define|#
directive|define
name|OPT_UTMP
value|0x0800
end_define

begin_define
define|#
directive|define
name|MAX_ENDDISC_CLASS
value|5
end_define

begin_define
define|#
directive|define
name|Enabled
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|((b)->cfg.opt& (o))
end_define

begin_comment
comment|/* AutoAdjust() values */
end_comment

begin_define
define|#
directive|define
name|AUTO_UP
value|1
end_define

begin_define
define|#
directive|define
name|AUTO_DOWN
value|2
end_define

begin_struct_decl
struct_decl|struct
name|sockaddr_un
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|datalink
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|link
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|server
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iface
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bundle
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
comment|/* really all our datalinks */
name|int
name|unit
decl_stmt|;
comment|/* The device/interface unit number */
struct|struct
block|{
name|char
name|Name
index|[
literal|20
index|]
decl_stmt|;
comment|/* The /dev/XXXX name */
name|int
name|fd
decl_stmt|;
comment|/* The /dev/XXXX descriptor */
name|unsigned
name|header
range|:
literal|1
decl_stmt|;
comment|/* Family header sent& received ? */
block|}
name|dev
struct|;
name|u_long
name|bandwidth
decl_stmt|;
comment|/* struct tuninfo speed */
name|struct
name|iface
modifier|*
name|iface
decl_stmt|;
comment|/* Interface information */
name|int
name|routing_seq
decl_stmt|;
comment|/* The current routing sequence number */
name|u_int
name|phase
decl_stmt|;
comment|/* Curent phase */
struct|struct
block|{
name|int
name|all
decl_stmt|;
comment|/* Union of all physical::type's */
name|int
name|open
decl_stmt|;
comment|/* Union of all open physical::type's */
block|}
name|phys_type
struct|;
name|unsigned
name|CleaningUp
range|:
literal|1
decl_stmt|;
comment|/* Going to exit.... */
name|unsigned
name|NatEnabled
range|:
literal|1
decl_stmt|;
comment|/* Are we using libalias ? */
name|struct
name|fsm_parent
name|fsm
decl_stmt|;
comment|/* Our callback functions */
name|struct
name|datalink
modifier|*
name|links
decl_stmt|;
comment|/* Our data links */
name|time_t
name|upat
decl_stmt|;
comment|/* When the link came up */
struct|struct
block|{
struct|struct
block|{
name|int
name|timeout
decl_stmt|;
comment|/* NCP Idle timeout value */
name|int
name|min_timeout
decl_stmt|;
comment|/* Don't idle out before this */
block|}
name|idle
struct|;
struct|struct
block|{
name|char
name|name
index|[
name|AUTHLEN
index|]
decl_stmt|;
comment|/* PAP/CHAP system name */
name|char
name|key
index|[
name|AUTHLEN
index|]
decl_stmt|;
comment|/* PAP/CHAP key */
block|}
name|auth
struct|;
name|unsigned
name|opt
decl_stmt|;
comment|/* Uses OPT_ bits from above */
name|char
name|label
index|[
literal|50
index|]
decl_stmt|;
comment|/* last thing `load'ed */
name|u_short
name|ifqueue
decl_stmt|;
comment|/* Interface queue size */
struct|struct
block|{
name|int
name|timeout
decl_stmt|;
comment|/* How long to leave the output queue choked */
block|}
name|choked
struct|;
block|}
name|cfg
struct|;
struct|struct
block|{
name|struct
name|ipcp
name|ipcp
decl_stmt|;
comment|/* Our IPCP FSM */
name|struct
name|mp
name|mp
decl_stmt|;
comment|/* Our MP */
block|}
name|ncp
struct|;
struct|struct
block|{
name|struct
name|filter
name|in
decl_stmt|;
comment|/* incoming packet filter */
name|struct
name|filter
name|out
decl_stmt|;
comment|/* outgoing packet filter */
name|struct
name|filter
name|dial
decl_stmt|;
comment|/* dial-out packet filter */
name|struct
name|filter
name|alive
decl_stmt|;
comment|/* keep-alive packet filter */
block|}
name|filter
struct|;
struct|struct
block|{
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* timeout after cfg.idle_timeout */
name|time_t
name|done
decl_stmt|;
block|}
name|idle
struct|;
struct|struct
block|{
name|int
name|fd
decl_stmt|;
comment|/* write status here */
block|}
name|notify
struct|;
struct|struct
block|{
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* choked output queue timer */
block|}
name|choked
struct|;
ifndef|#
directive|ifndef
name|NORADIUS
name|struct
name|radius
name|radius
decl_stmt|;
comment|/* Info retrieved from radius server */
name|struct
name|radacct
name|radacct
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2bundle
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == BUNDLE_DESCRIPTOR ? (struct bundle *)(d) : NULL)
end_define

begin_function_decl
specifier|extern
name|struct
name|bundle
modifier|*
name|bundle_Create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_Destroy
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|bundle_PhaseName
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bundle_Phase
parameter_list|(
name|b
parameter_list|)
value|((b)->phase)
end_define

begin_function_decl
specifier|extern
name|void
name|bundle_NewPhase
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_LinksRemoved
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_LinkIsUp
parameter_list|(
specifier|const
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_Close
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_Down
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_Open
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_LinkClosed
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_ShowLinks
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_ShowStatus
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_StartIdleTimer
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|unsigned
name|secs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_SetIdleTimer
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_StopIdleTimer
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_IsDead
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|datalink
modifier|*
name|bundle2datalink
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_RegisterDescriptor
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|fdescriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_UnRegisterDescriptor
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|fdescriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_SetTtyCommandMode
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_DatalinkClone
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_DatalinkRemove
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_CleanDatalinks
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_SetLabel
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|bundle_GetLabel
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_SendDatalink
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_un
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_LinkSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_ReceiveDatalink
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_SetMode
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_RenameDatalink
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|datalink
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_setsid
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_LockTun
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_HighestState
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_Exception
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_AdjustFilters
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_AdjustDNS
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|in_addr
type|[
function_decl|2]
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|bundle_CalculateBandwidth
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_AutoAdjust
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bundle_WantAutoloadTimer
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_ChangedPID
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bundle_Notify
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|char
parameter_list|)
function_decl|;
end_function_decl

end_unit

