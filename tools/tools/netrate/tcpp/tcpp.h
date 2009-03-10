begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008-2009 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TCPP_H
end_ifndef

begin_define
define|#
directive|define
name|TCPP_H
end_define

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|localipbase
decl_stmt|,
name|remoteip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cflag
decl_stmt|,
name|lflag
decl_stmt|,
name|mflag
decl_stmt|,
name|pflag
decl_stmt|,
name|sflag
decl_stmt|,
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Cflag
decl_stmt|,
name|Iflag
decl_stmt|,
name|Mflag
decl_stmt|,
name|Tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|bflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|rflag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TCPP_MAGIC
value|0x84e812f7
end_define

begin_struct
struct|struct
name|tcpp_header
block|{
name|u_int32_t
name|th_magic
decl_stmt|;
name|u_int64_t
name|th_len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|void
name|tcpp_client
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpp_header_encode
parameter_list|(
name|struct
name|tcpp_header
modifier|*
name|thp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpp_header_decode
parameter_list|(
name|struct
name|tcpp_header
modifier|*
name|thp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcpp_server
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SYSCTLNAME_CPUS
value|"kern.smp.cpus"
end_define

begin_define
define|#
directive|define
name|SYSCTLNAME_CPTIME
value|"kern.cp_time"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCPP_H */
end_comment

end_unit

