begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|DATALINK_CLOSED
value|(0)
end_define

begin_define
define|#
directive|define
name|DATALINK_OPENING
value|(1)
end_define

begin_define
define|#
directive|define
name|DATALINK_HANGUP
value|(2)
end_define

begin_define
define|#
directive|define
name|DATALINK_DIAL
value|(3)
end_define

begin_define
define|#
directive|define
name|DATALINK_CARRIER
value|(4)
end_define

begin_define
define|#
directive|define
name|DATALINK_LOGOUT
value|(5)
end_define

begin_define
define|#
directive|define
name|DATALINK_LOGIN
value|(6)
end_define

begin_define
define|#
directive|define
name|DATALINK_READY
value|(7)
end_define

begin_define
define|#
directive|define
name|DATALINK_LCP
value|(8)
end_define

begin_define
define|#
directive|define
name|DATALINK_AUTH
value|(9)
end_define

begin_define
define|#
directive|define
name|DATALINK_CBCP
value|(10)
end_define

begin_define
define|#
directive|define
name|DATALINK_OPEN
value|(11)
end_define

begin_define
define|#
directive|define
name|DATALINK_MAXNAME
value|(20)
end_define

begin_comment
comment|/* Maximum datalink::name length */
end_comment

begin_comment
comment|/* How to close the link */
end_comment

begin_define
define|#
directive|define
name|CLOSE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|CLOSE_STAYDOWN
value|1
end_define

begin_define
define|#
directive|define
name|CLOSE_LCP
value|2
end_define

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|datalink
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
comment|/* We play either a physical or a chat */
name|int
name|state
decl_stmt|;
comment|/* Our DATALINK_* state */
name|struct
name|physical
modifier|*
name|physical
decl_stmt|;
comment|/* Our link */
name|struct
name|chat
name|chat
decl_stmt|;
comment|/* For bringing the link up& down */
name|unsigned
name|stayonline
range|:
literal|1
decl_stmt|;
comment|/* stay online when LCP is closed ? */
struct|struct
block|{
name|unsigned
name|run
range|:
literal|1
decl_stmt|;
comment|/* run scripts ? */
name|unsigned
name|packetmode
range|:
literal|1
decl_stmt|;
comment|/* Go into packet mode after login ? */
block|}
name|script
struct|;
struct|struct
block|{
struct|struct
block|{
name|char
name|dial
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
name|char
name|login
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
name|char
name|logout
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
name|char
name|hangup
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
block|}
name|script
struct|;
comment|/* various chat scripts */
struct|struct
block|{
name|char
name|list
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
comment|/* Telephone Numbers */
block|}
name|phone
struct|;
struct|struct
block|{
name|int
name|max
decl_stmt|;
comment|/* initially try again this number of times */
name|int
name|next_timeout
decl_stmt|;
comment|/* Redial next timeout value */
name|int
name|inc
decl_stmt|;
comment|/* Increment timeout by `inc' each time read */
name|int
name|maxinc
decl_stmt|;
comment|/* Maximum number of increments */
name|int
name|timeout
decl_stmt|;
comment|/* Redial timeout value (end of phone list) */
block|}
name|dial
struct|;
struct|struct
block|{
name|int
name|max
decl_stmt|;
comment|/* initially try again this number of times */
name|int
name|timeout
decl_stmt|;
comment|/* Timeout before reconnect on carrier loss */
block|}
name|reconnect
struct|;
name|struct
name|callback
name|callback
decl_stmt|;
comment|/* Direction depends on physical type */
name|struct
name|cbcpcfg
name|cbcp
decl_stmt|;
comment|/* Direction depends on phys type& callback */
block|}
name|cfg
struct|;
comment|/* All our config data is in here */
struct|struct
block|{
name|char
name|list
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
comment|/* copy of cfg.list for strsep() */
name|char
modifier|*
name|next
decl_stmt|;
comment|/* Next phone from the list */
name|char
modifier|*
name|alt
decl_stmt|;
comment|/* Alternate (after fail) phone from the list */
specifier|const
name|char
modifier|*
name|chosen
decl_stmt|;
comment|/* Chosen phone number after DIAL */
block|}
name|phone
struct|;
name|struct
name|cbcp
name|cbcp
decl_stmt|;
struct|struct
block|{
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* For timing between close& open */
name|int
name|tries
decl_stmt|;
comment|/* currently try again this number of times */
name|int
name|incs
decl_stmt|;
comment|/* # times our timeout has been incremented */
block|}
name|dial
struct|;
name|unsigned
name|reconnect_tries
decl_stmt|;
comment|/* currently try again this number of times */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Our name */
name|struct
name|peerid
name|peer
decl_stmt|;
comment|/* Peer identification */
name|struct
name|fsm_parent
name|fsmp
decl_stmt|;
comment|/* Our callback functions */
specifier|const
name|struct
name|fsm_parent
modifier|*
name|parent
decl_stmt|;
comment|/* Our parent */
name|struct
name|authinfo
name|pap
decl_stmt|;
comment|/* Authentication using pap */
name|struct
name|chap
name|chap
decl_stmt|;
comment|/* Authentication using chap */
name|struct
name|mp_link
name|mp
decl_stmt|;
comment|/* multilink data */
name|struct
name|bundle
modifier|*
name|bundle
decl_stmt|;
comment|/* for the moment */
name|struct
name|datalink
modifier|*
name|next
decl_stmt|;
comment|/* Next in the list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2datalink
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == DATALINK_DESCRIPTOR ? (struct datalink *)(d) : NULL)
end_define

begin_function_decl
specifier|extern
name|struct
name|datalink
modifier|*
name|datalink_Create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
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
name|struct
name|datalink
modifier|*
name|datalink_Clone
parameter_list|(
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
name|struct
name|datalink
modifier|*
name|iov2datalink
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|datalink2iov
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|,
name|struct
name|iovec
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|datalink
modifier|*
name|datalink_Destroy
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_GotAuthname
parameter_list|(
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
name|datalink_Up
parameter_list|(
name|struct
name|datalink
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
name|datalink_Close
parameter_list|(
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
name|void
name|datalink_Down
parameter_list|(
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
name|void
name|datalink_StayDown
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_DontHangup
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_AuthOk
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_AuthNotOk
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_NCPUp
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_CBCPComplete
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_CBCPFailed
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|datalink_Show
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
name|datalink_SetRedial
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
name|datalink_SetReconnect
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
specifier|const
name|char
modifier|*
name|datalink_State
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|datalink_Rename
parameter_list|(
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
name|char
modifier|*
name|datalink_NextName
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|datalink_RemoveFromSet
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|datalink_SetMode
parameter_list|(
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
name|datalink_GetDialTimeout
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|datalink_ChoosePhoneNumber
parameter_list|(
name|struct
name|datalink
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

