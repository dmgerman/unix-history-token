begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Neel Natu<neel@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LPC_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lpc_write_dsdt_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|lpc_dsdt
block|{
name|lpc_write_dsdt_t
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LPC_DSDT
parameter_list|(
name|handler
parameter_list|)
define|\
value|static struct lpc_dsdt __CONCAT(__lpc_dsdt, __LINE__) = {	\ 		(handler),						\ 	};								\ 	DATA_SET(lpc_dsdt_set, __CONCAT(__lpc_dsdt, __LINE__))
end_define

begin_enum
enum|enum
name|lpc_sysres_type
block|{
name|LPC_SYSRES_IO
block|,
name|LPC_SYSRES_MEM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|lpc_sysres
block|{
name|enum
name|lpc_sysres_type
name|type
decl_stmt|;
name|uint32_t
name|base
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LPC_SYSRES
parameter_list|(
name|type
parameter_list|,
name|base
parameter_list|,
name|length
parameter_list|)
define|\
value|static struct lpc_sysres __CONCAT(__lpc_sysres, __LINE__) = {	\ 		(type),							\ 		(base),							\ 		(length)						\ 	};								\ 	DATA_SET(lpc_sysres_set, __CONCAT(__lpc_sysres, __LINE__))
end_define

begin_define
define|#
directive|define
name|SYSRES_IO
parameter_list|(
name|base
parameter_list|,
name|length
parameter_list|)
value|LPC_SYSRES(LPC_SYSRES_IO, base, length)
end_define

begin_define
define|#
directive|define
name|SYSRES_MEM
parameter_list|(
name|base
parameter_list|,
name|length
parameter_list|)
value|LPC_SYSRES(LPC_SYSRES_MEM, base, length)
end_define

begin_function_decl
name|int
name|lpc_device_parse
parameter_list|(
specifier|const
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lpc_pirq_name
parameter_list|(
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lpc_pirq_routed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

