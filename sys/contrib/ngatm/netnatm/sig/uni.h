begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/sig/uni.h,v 1.5 2004/07/08 08:22:24 brandt Exp $  *  * Public UNI interface  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SIG_UNI_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SIG_UNI_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/sig/unidef.h>
end_include

begin_struct_decl
struct_decl|struct
name|uni
struct_decl|;
end_struct_decl

begin_comment
comment|/* functions to be supplied by the user */
end_comment

begin_struct
struct|struct
name|uni_funcs
block|{
comment|/* output to the upper layer */
name|void
function_decl|(
modifier|*
name|uni_output
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|uni_sig
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* output to the SAAL */
name|void
function_decl|(
modifier|*
name|saal_output
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|saal_sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* verbosity */
name|void
function_decl|(
modifier|*
name|verbose
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|uni_verb
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
block|)
struct|;
end_struct

begin_comment
comment|/* function to 'print' status */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|status
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* start a timer */
end_comment

begin_function_decl
name|void
modifier|*
function_decl|(
modifier|*
name|start_timer
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stop a timer */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|stop_timer
function_decl|)
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/* create a UNI instance */
end_comment

begin_function_decl
name|struct
name|uni
modifier|*
name|uni_create
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_funcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy a UNI instance, free all resources */
end_comment

begin_function_decl
name|void
name|uni_destroy
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* generate a status report */
end_comment

begin_function_decl
name|void
name|uni_status
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get current instance configuration */
end_comment

begin_function_decl
name|void
name|uni_get_config
parameter_list|(
specifier|const
name|struct
name|uni
modifier|*
parameter_list|,
name|struct
name|uni_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set new instance configuration */
end_comment

begin_function_decl
name|void
name|uni_set_config
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_config
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* input from the SAAL to the instance */
end_comment

begin_function_decl
name|void
name|uni_saal_input
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|saal_sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* input from the upper layer to the instance */
end_comment

begin_function_decl
name|void
name|uni_uni_input
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|uni_sig
parameter_list|,
name|uint32_t
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* do work on pending signals */
end_comment

begin_function_decl
name|void
name|uni_work
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set debuging level */
end_comment

begin_function_decl
name|void
name|uni_set_debug
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|uni_verb
parameter_list|,
name|u_int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|uni_get_debug
parameter_list|(
specifier|const
name|struct
name|uni
modifier|*
parameter_list|,
name|enum
name|uni_verb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reset a UNI instance */
end_comment

begin_function_decl
name|void
name|uni_reset
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* states */
end_comment

begin_function_decl
name|u_int
name|uni_getcustate
parameter_list|(
specifier|const
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return a reference to the coding/decoding context */
end_comment

begin_function_decl
name|struct
name|unicx
modifier|*
name|uni_context
parameter_list|(
name|struct
name|uni
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

