begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2008 Daniel Braniss<danny@cs.huji.ac.il>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  | $Id: iscontrol.h,v 2.3 2007/04/27 08:36:49 danny Exp danny $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {if (level<= vflag) printf("%s: " fmt "\n", __func__ , ##args);} while(0)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
value|do {if (level<= vflag) printf("%s: called\n", __func__);} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|debug_called
parameter_list|(
name|level
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// DEBUG
end_comment

begin_define
define|#
directive|define
name|xdebug
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: " fmt "\n", __func__ , ##args)
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1<<(n))
end_define

begin_define
define|#
directive|define
name|MAXREDIRECTS
value|2
end_define

begin_typedef
typedef|typedef
name|int
name|auth_t
parameter_list|(
name|void
modifier|*
name|sess
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|address
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|pgt
decl_stmt|;
block|}
name|target_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isess
block|{
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|SESS_CONNECTED
value|BIT(0)
define|#
directive|define
name|SESS_DISCONNECT
value|BIT(1)
define|#
directive|define
name|SESS_LOGGEDIN
value|BIT(2)
define|#
directive|define
name|SESS_RECONNECT
value|BIT(3)
define|#
directive|define
name|SESS_REDIRECT
value|BIT(4)
define|#
directive|define
name|SESS_NEGODONE
value|BIT(10)
comment|// XXX: kludge
define|#
directive|define
name|SESS_FULLFEATURE
value|BIT(29)
define|#
directive|define
name|SESS_INITIALLOGIN1
value|BIT(30)
define|#
directive|define
name|SESS_INITIALLOGIN
value|BIT(31)
name|isc_opt_t
modifier|*
name|op
decl_stmt|;
comment|// operational values
name|target_t
name|target
decl_stmt|;
comment|// the Original target address
name|int
name|fd
decl_stmt|;
comment|// the session fd
name|int
name|soc
decl_stmt|;
comment|// the socket
name|iscsi_cam_t
name|cam
decl_stmt|;
name|struct
name|cam_device
modifier|*
name|camdev
decl_stmt|;
name|time_t
name|open_time
decl_stmt|;
name|int
name|redirect_cnt
decl_stmt|;
name|time_t
name|redirect_time
decl_stmt|;
name|int
name|reconnect_cnt
decl_stmt|;
name|int
name|reconnect_cnt1
decl_stmt|;
name|time_t
name|reconnect_time
decl_stmt|;
name|char
name|isid
index|[
literal|6
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|csg
decl_stmt|;
comment|// current stage
name|int
name|nsg
decl_stmt|;
comment|// next stage
comment|// Phases/Stages
define|#
directive|define
name|SN_PHASE
value|0
comment|// Security Negotiation
define|#
directive|define
name|LON_PHASE
value|1
comment|// Login Operational Negotiation
define|#
directive|define
name|FF_PHASE
value|3
comment|// FuLL-Feature
name|uint
name|tsih
decl_stmt|;
name|sn_t
name|sn
decl_stmt|;
block|}
name|isess_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|token
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
name|token_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|NONE
init|=
literal|0
block|,
name|KRB5
block|,
name|SPKM1
block|,
name|SPKM2
block|,
name|SRP
block|,
name|CHAP
block|}
name|authm_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|token_t
name|AuthMethods
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|token_t
name|DigestMethods
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|SET
block|,
name|GET
block|}
name|oper_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|U_PR
block|,
comment|// private
name|U_IO
block|,
comment|// Initialize Only -- during login
name|U_LO
block|,
comment|// Leading Only -- when TSIH is zero
name|U_FFPO
block|,
comment|// Full Feature Phase Only
name|U_ALL
comment|// in any phase
block|}
name|usage_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|S_PR
block|,
name|S_CO
block|,
comment|// Connect only
name|S_SW
comment|// Session Wide
block|}
name|scope_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|keyfun_t
parameter_list|(
name|isess_t
modifier|*
parameter_list|,
name|oper_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|usage_t
name|usage
decl_stmt|;
name|scope_t
name|scope
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|tokenID
decl_stmt|;
block|}
name|textkey_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|handler_t
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|,
name|pdu_t
modifier|*
name|pp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|authenticateLogin
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsm
parameter_list|(
name|isc_opt_t
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sendPDU
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|,
name|pdu_t
modifier|*
name|pp
parameter_list|,
name|handler_t
modifier|*
name|hdlr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|addText
parameter_list|(
name|pdu_t
modifier|*
name|pp
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freePDU
parameter_list|(
name|pdu_t
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xmitpdu
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|,
name|pdu_t
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|recvpdu
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|,
name|pdu_t
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lookup
parameter_list|(
name|token_t
modifier|*
name|tbl
parameter_list|,
name|char
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|iscsidev
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|parseArgs
parameter_list|(
name|int
name|nargs
parameter_list|,
name|char
modifier|*
modifier|*
name|args
parameter_list|,
name|isc_opt_t
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parseConfig
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|char
modifier|*
name|key
parameter_list|,
name|isc_opt_t
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|chapDigest
parameter_list|(
name|char
modifier|*
name|ap
parameter_list|,
name|char
name|id
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|char
modifier|*
name|chapSecret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|genChapChallenge
parameter_list|(
name|char
modifier|*
name|encoding
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str2bin
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|rsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bin2str
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
name|unsigned
name|char
modifier|*
name|md
parameter_list|,
name|int
name|blen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|negotiateOPV
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setOptions
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|loginPhase
parameter_list|(
name|isess_t
modifier|*
name|sess
parameter_list|)
function_decl|;
end_function_decl

end_unit

