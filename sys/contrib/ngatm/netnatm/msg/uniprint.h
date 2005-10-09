begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/msg/uniprint.h,v 1.4 2004/07/08 08:22:08 brandt Exp $  *  * Print utility functions. These are only needed if you want to hook to  * the format of the uni printing routines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_MSG_UNIPRINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_MSG_UNIPRINT_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/msg/uni_config.h>
end_include

begin_comment
comment|/*  * This structure is used to define value->string mappings.  * It must be terminated by a { NULL, 0 } entry.  */
end_comment

begin_struct
struct|struct
name|uni_print_tbl
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|u_int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|uni_print_tbl
parameter_list|(
specifier|const
name|char
modifier|*
name|_entry
parameter_list|,
name|u_int
name|_val
parameter_list|,
specifier|const
name|struct
name|uni_print_tbl
modifier|*
name|_tbl
parameter_list|,
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialize printing. This must be called at the start from each external  * callable printing function. */
end_comment

begin_function_decl
name|void
name|uni_print_init
parameter_list|(
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_bufsiz
parameter_list|,
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* End the current (semantical) line. This takes care of indendation and  * actually print the newline in the appropriate modes. */
end_comment

begin_function_decl
name|void
name|uni_print_eol
parameter_list|(
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Push or pop a prefix. This takes care of indendation. */
end_comment

begin_function_decl
name|void
name|uni_print_push_prefix
parameter_list|(
specifier|const
name|char
modifier|*
name|_prefix
parameter_list|,
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_print_pop_prefix
parameter_list|(
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a flag taking care of the right prefixing */
end_comment

begin_function_decl
name|void
name|uni_print_flag
parameter_list|(
specifier|const
name|char
modifier|*
name|_flag
parameter_list|,
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print an entry taking care of the right prefixing */
end_comment

begin_function_decl
name|void
name|uni_print_entry
parameter_list|(
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|,
specifier|const
name|char
modifier|*
name|_entry
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Generic printf */
end_comment

begin_function_decl
name|void
name|uni_printf
parameter_list|(
name|struct
name|unicx
modifier|*
name|_cx
parameter_list|,
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

