begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2002  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  * Copyright (c) 2003-2004  *	Hartmut Brandt.  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATMCONFIG_DEVICE_H_
end_ifndef

begin_define
define|#
directive|define
name|ATMCONFIG_DEVICE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/*  * ATM interface table  */
end_comment

begin_struct
struct|struct
name|atmif
block|{
name|TAILQ_ENTRY
argument_list|(
argument|atmif
argument_list|)
name|link
expr_stmt|;
name|uint64_t
name|found
decl_stmt|;
name|int32_t
name|index
decl_stmt|;
name|char
modifier|*
name|ifname
decl_stmt|;
name|size_t
name|ifnamelen
decl_stmt|;
name|uint32_t
name|pcr
decl_stmt|;
name|int32_t
name|media
decl_stmt|;
name|uint32_t
name|vpi_bits
decl_stmt|;
name|uint32_t
name|vci_bits
decl_stmt|;
name|uint32_t
name|max_vpcs
decl_stmt|;
name|uint32_t
name|max_vccs
decl_stmt|;
name|u_char
modifier|*
name|esi
decl_stmt|;
name|size_t
name|esilen
decl_stmt|;
name|int32_t
name|carrier
decl_stmt|;
name|int32_t
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|atmif_list
argument_list|,
name|atmif
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* list of all ATM interfaces */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|atmif_list
name|atmif_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fetch this table */
end_comment

begin_function_decl
name|void
name|atmif_fetchtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find an ATM interface by name */
end_comment

begin_function_decl
name|struct
name|atmif
modifier|*
name|atmif_find_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* find an ATM interface by index */
end_comment

begin_function_decl
name|struct
name|atmif
modifier|*
name|atmif_find
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

