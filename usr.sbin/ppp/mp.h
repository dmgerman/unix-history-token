begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
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

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|datalink
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ENDDISC_NULL
value|0
end_define

begin_define
define|#
directive|define
name|ENDDISC_LOCAL
value|1
end_define

begin_define
define|#
directive|define
name|ENDDISC_IP
value|2
end_define

begin_define
define|#
directive|define
name|ENDDISC_MAC
value|3
end_define

begin_define
define|#
directive|define
name|ENDDISC_MAGIC
value|4
end_define

begin_define
define|#
directive|define
name|ENDDISC_PSN
value|5
end_define

begin_define
define|#
directive|define
name|MP_LINKSENT
value|0
end_define

begin_comment
comment|/* We attached the link to another ppp */
end_comment

begin_define
define|#
directive|define
name|MP_UP
value|1
end_define

begin_comment
comment|/* We've started MP */
end_comment

begin_define
define|#
directive|define
name|MP_ADDED
value|2
end_define

begin_comment
comment|/* We've added the link to our MP */
end_comment

begin_define
define|#
directive|define
name|MP_FAILED
value|3
end_define

begin_comment
comment|/* No go */
end_comment

begin_define
define|#
directive|define
name|MPSERVER_CONNECTED
value|0
end_define

begin_define
define|#
directive|define
name|MPSERVER_LISTENING
value|1
end_define

begin_define
define|#
directive|define
name|MPSERVER_FAILED
value|2
end_define

begin_struct
struct|struct
name|enddisc
block|{
name|u_char
name|class
decl_stmt|;
name|char
name|address
index|[
literal|50
index|]
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|peerid
block|{
name|struct
name|enddisc
name|enddisc
decl_stmt|;
comment|/* Peers endpoint discriminator */
name|char
name|authname
index|[
name|AUTHLEN
index|]
decl_stmt|;
comment|/* Peers name (authenticated) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpserver
block|{
name|struct
name|fdescriptor
name|desc
decl_stmt|;
name|int
name|fd
decl_stmt|;
comment|/* listen()ing or connect()ing here */
name|struct
name|sockaddr_un
name|socket
decl_stmt|;
comment|/* On this socket */
struct|struct
block|{
name|struct
name|datalink
modifier|*
name|dl
decl_stmt|;
comment|/* Send this datalink */
block|}
name|send
struct|;
comment|/* (in UpdateSet()) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mp
block|{
name|struct
name|link
name|link
decl_stmt|;
name|unsigned
name|active
range|:
literal|1
decl_stmt|;
name|unsigned
name|peer_is12bit
range|:
literal|1
decl_stmt|;
comment|/* 12/24bit seq nos */
name|unsigned
name|local_is12bit
range|:
literal|1
decl_stmt|;
name|u_short
name|peer_mrru
decl_stmt|;
name|u_short
name|local_mrru
decl_stmt|;
name|struct
name|peerid
name|peer
decl_stmt|;
comment|/* Who are we talking to */
name|struct
name|mpserver
name|server
decl_stmt|;
comment|/* Our ``sharing'' socket */
struct|struct
block|{
name|u_int32_t
name|seq
decl_stmt|;
comment|/* next outgoing seq */
name|int
name|link
decl_stmt|;
comment|/* Next link to send on */
block|}
name|out
struct|;
struct|struct
block|{
name|u_int32_t
name|min_in
decl_stmt|;
comment|/* minimum received incoming seq */
name|u_int32_t
name|next_in
decl_stmt|;
comment|/* next incoming seq to process */
block|}
name|seq
struct|;
struct|struct
block|{
name|u_short
name|mrru
decl_stmt|;
comment|/* Max Reconstructed Receive Unit */
name|unsigned
name|shortseq
range|:
literal|2
decl_stmt|;
comment|/* I want short Sequence Numbers */
name|unsigned
name|negenddisc
range|:
literal|2
decl_stmt|;
comment|/* I want an endpoint discriminator */
name|struct
name|enddisc
name|enddisc
decl_stmt|;
comment|/* endpoint discriminator */
struct|struct
block|{
name|int
name|min
decl_stmt|;
comment|/* Lowest percent of bundle->bandwidth */
name|int
name|max
decl_stmt|;
comment|/* Highest percent of bundle->bandwidth out */
name|int
name|period
decl_stmt|;
comment|/* link->throughput sample period */
block|}
name|autoload
struct|;
block|}
name|cfg
struct|;
name|struct
name|mbuf
modifier|*
name|inbufs
decl_stmt|;
comment|/* Received fragments */
name|struct
name|fsm_parent
name|fsmp
decl_stmt|;
comment|/* Our callback functions */
name|struct
name|bundle
modifier|*
name|bundle
decl_stmt|;
comment|/* Parent */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mp_link
block|{
name|u_int32_t
name|seq
decl_stmt|;
comment|/* 12 or 24 bit incoming seq */
name|unsigned
name|bandwidth
decl_stmt|;
comment|/* Our link bandwidth (or zero) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mp_header
block|{
name|unsigned
name|begin
range|:
literal|1
decl_stmt|;
name|unsigned
name|end
range|:
literal|1
decl_stmt|;
name|u_int32_t
name|seq
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2mpserver
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == MPSERVER_DESCRIPTOR ? (struct mpserver *)(d) : NULL)
end_define

begin_define
define|#
directive|define
name|mpserver_IsOpen
parameter_list|(
name|s
parameter_list|)
value|((s)->fd != -1)
end_define

begin_function_decl
specifier|extern
name|void
name|peerid_Init
parameter_list|(
name|struct
name|peerid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|peerid_Equal
parameter_list|(
specifier|const
name|struct
name|peerid
modifier|*
parameter_list|,
specifier|const
name|struct
name|peerid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpserver_Init
parameter_list|(
name|struct
name|mpserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mpserver_Open
parameter_list|(
name|struct
name|mpserver
modifier|*
parameter_list|,
name|struct
name|peerid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mpserver_Close
parameter_list|(
name|struct
name|mpserver
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_Init
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|,
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_linkInit
parameter_list|(
name|struct
name|mp_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_Up
parameter_list|(
name|struct
name|mp
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
name|mp_Down
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mp_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mp_FillQueues
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
name|mp_SetDatalinkBandwidth
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
name|mp_ShowStatus
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
name|mp_Enddisc
parameter_list|(
name|u_char
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
name|int
name|mp_SetEnddisc
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
name|mp_LinkLost
parameter_list|(
name|struct
name|mp
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
name|mp_DeleteQueue
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_RestartAutoloadTimer
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_CheckAutoloadTimer
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mp_StopAutoloadTimer
parameter_list|(
name|struct
name|mp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

