begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UUID_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Length of a node address (an IEEE 802 address). */
end_comment

begin_define
define|#
directive|define
name|_UUID_NODE_LEN
value|6
end_define

begin_comment
comment|/*  * See also:  *      http://www.opengroup.org/dce/info/draft-leach-uuids-guids-01.txt  *      http://www.opengroup.org/onlinepubs/009629399/apdxa.htm  *  * A DCE 1.1 compatible source representation of UUIDs.  */
end_comment

begin_struct
struct|struct
name|uuid
block|{
name|uint32_t
name|time_low
decl_stmt|;
name|uint16_t
name|time_mid
decl_stmt|;
name|uint16_t
name|time_hi_and_version
decl_stmt|;
name|uint8_t
name|clock_seq_hi_and_reserved
decl_stmt|;
name|uint8_t
name|clock_seq_low
decl_stmt|;
name|uint8_t
name|node
index|[
name|_UUID_NODE_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|UUID_NODE_LEN
value|_UUID_NODE_LEN
end_define

begin_struct_decl
struct_decl|struct
name|sbuf
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|uuid
modifier|*
name|kern_uuidgen
parameter_list|(
name|struct
name|uuid
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_ether_add
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuid_ether_del
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snprintf_uuid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf_uuid
parameter_list|(
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbuf_printf_uuid
parameter_list|(
name|struct
name|sbuf
modifier|*
parameter_list|,
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_uuid
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uuidcmp
parameter_list|(
specifier|const
name|struct
name|uuid
modifier|*
parameter_list|,
specifier|const
name|struct
name|uuid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|be_uuid_dec
parameter_list|(
name|void
specifier|const
modifier|*
name|buf
parameter_list|,
name|struct
name|uuid
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|be_uuid_enc
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|struct
name|uuid
specifier|const
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|le_uuid_dec
parameter_list|(
name|void
specifier|const
modifier|*
name|buf
parameter_list|,
name|struct
name|uuid
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|le_uuid_enc
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|struct
name|uuid
specifier|const
modifier|*
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* XXX namespace pollution? */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uuid
name|uuid_t
typedef|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|uuidgen
parameter_list|(
name|struct
name|uuid
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_UUID_H_ */
end_comment

end_unit

