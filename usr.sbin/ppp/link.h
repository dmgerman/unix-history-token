begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  $Id: link.h,v 1.3 1998/05/23 17:05:27 brian Exp $  *  */
end_comment

begin_define
define|#
directive|define
name|PHYSICAL_LINK
value|1
end_define

begin_define
define|#
directive|define
name|MP_LINK
value|2
end_define

begin_define
define|#
directive|define
name|LINK_QUEUES
value|(PRI_MAX + 1)
end_define

begin_define
define|#
directive|define
name|NPROTOSTAT
value|13
end_define

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|prompt
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|link
block|{
name|int
name|type
decl_stmt|;
comment|/* _LINK type */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Points to datalink::name */
name|int
name|len
decl_stmt|;
comment|/* full size of parent struct */
name|struct
name|pppThroughput
name|throughput
decl_stmt|;
comment|/* Link throughput statistics */
name|struct
name|mqueue
name|Queue
index|[
name|LINK_QUEUES
index|]
decl_stmt|;
comment|/* Our output queue of mbufs */
name|u_long
name|proto_in
index|[
name|NPROTOSTAT
index|]
decl_stmt|;
comment|/* outgoing protocol stats */
name|u_long
name|proto_out
index|[
name|NPROTOSTAT
index|]
decl_stmt|;
comment|/* incoming protocol stats */
name|struct
name|lcp
name|lcp
decl_stmt|;
comment|/* Our line control FSM */
name|struct
name|ccp
name|ccp
decl_stmt|;
comment|/* Our compression FSM */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|link_AddInOctets
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_AddOutOctets
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_SequenceQueue
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_DeleteQueue
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|link_QueueLen
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|link_QueueBytes
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|link_Dequeue
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_Write
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|int
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
name|link_StartOutput
parameter_list|(
name|struct
name|link
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
name|link_Output
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PROTO_IN
value|1
end_define

begin_comment
comment|/* third arg to link_ProtocolRecord */
end_comment

begin_define
define|#
directive|define
name|PROTO_OUT
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|link_ProtocolRecord
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_ReportProtocolStatus
parameter_list|(
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|prompt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

