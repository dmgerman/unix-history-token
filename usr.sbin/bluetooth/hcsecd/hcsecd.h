begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hcsecd.h  *  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: hcsecd.h,v 1.3 2003/09/08 18:54:21 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HCSECD_H_
end_ifndef

begin_define
define|#
directive|define
name|_HCSECD_H_
value|1
end_define

begin_define
define|#
directive|define
name|HCSECD_BUFFER_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|HCSECD_IDENT
value|"hcsecd"
end_define

begin_define
define|#
directive|define
name|HCSECD_PIDFILE
value|"/var/run/" HCSECD_IDENT ".pid"
end_define

begin_define
define|#
directive|define
name|HCSECD_KEYSFILE
value|"/var/db/"  HCSECD_IDENT ".keys"
end_define

begin_struct
struct|struct
name|link_key
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote device BDADDR */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* remote device name */
name|uint8_t
modifier|*
name|key
decl_stmt|;
comment|/* link key (or NULL if no key) */
name|char
modifier|*
name|pin
decl_stmt|;
comment|/* pin (or NULL if no pin) */
name|LIST_ENTRY
argument_list|(
argument|link_key
argument_list|)
name|next
expr_stmt|;
comment|/* link to the next */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|link_key
name|link_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|link_key
modifier|*
name|link_key_p
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|config_file
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__config_debug__
end_if

begin_function_decl
name|void
name|dump_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|read_config_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clean_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|link_key_p
name|get_key
parameter_list|(
name|bdaddr_p
name|bdaddr
parameter_list|,
name|int
name|exact_match
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_keys_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dump_keys_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _HCSECD_H_ */
end_comment

end_unit

