begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/saal/sscfu.h,v 1.4 2004/07/08 08:22:15 brandt Exp $  *  * Public include file for UNI SSCF  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_SAAL_SSCFU_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_SAAL_SSCFU_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/saal/sscopdef.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/saal/sscfudef.h>
end_include

begin_comment
comment|/*  * Define how a buffer looks like.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|SSCFU_MBUF_T
value|mbuf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSCFU_MBUF_T
value|uni_msg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|SSCFU_MBUF_T
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sscfu
struct_decl|;
end_struct_decl

begin_comment
comment|/* functions to be supplied by the SSCOP user */
end_comment

begin_struct
struct|struct
name|sscfu_funcs
block|{
comment|/* upper (SAAL) interface output */
name|void
function_decl|(
modifier|*
name|send_upper
function_decl|)
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|saal_sig
parameter_list|,
name|struct
name|SSCFU_MBUF_T
modifier|*
parameter_list|)
function_decl|;
comment|/* lower (SSCOP) interface output */
name|void
function_decl|(
modifier|*
name|send_lower
function_decl|)
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|sscop_aasig
parameter_list|,
name|struct
name|SSCFU_MBUF_T
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* function to move the SSCOP window */
name|void
function_decl|(
modifier|*
name|window
function_decl|)
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* debugging function */
name|void
function_decl|(
modifier|*
name|verbose
function_decl|)
parameter_list|(
name|struct
name|sscfu
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
function_decl|3
operator|,
function_decl|4
block|)
struct|;
end_struct

begin_comment
unit|};
comment|/* Function defined by the SSCF-UNI code */
end_comment

begin_comment
comment|/* allocate and initialize a new SSCF instance */
end_comment

begin_function_decl
name|struct
name|sscfu
modifier|*
name|sscfu_create
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|sscfu_funcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy an SSCF instance and free all resources */
end_comment

begin_function_decl
name|void
name|sscfu_destroy
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reset the SSCF to the released state */
end_comment

begin_function_decl
name|void
name|sscfu_reset
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lower input interface (SSCOP signals) */
end_comment

begin_function_decl
name|void
name|sscfu_input
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|enum
name|sscop_aasig
parameter_list|,
name|struct
name|SSCFU_MBUF_T
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* upper input interface (SAAL) */
end_comment

begin_function_decl
name|int
name|sscfu_saalsig
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|enum
name|saal_sig
parameter_list|,
name|struct
name|SSCFU_MBUF_T
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* retrieve the current state */
end_comment

begin_function_decl
name|enum
name|sscfu_state
name|sscfu_getstate
parameter_list|(
specifier|const
name|struct
name|sscfu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* char'ify signals and states */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|sscfu_signame
parameter_list|(
name|enum
name|saal_sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|sscfu_statename
parameter_list|(
name|enum
name|sscfu_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* retrieve the default set of parameters for SSCOP */
end_comment

begin_function_decl
name|u_int
name|sscfu_getdefparam
parameter_list|(
name|struct
name|sscop_param
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get/set debugging flags */
end_comment

begin_function_decl
name|void
name|sscfu_setdebug
parameter_list|(
name|struct
name|sscfu
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|sscfu_getdebug
parameter_list|(
specifier|const
name|struct
name|sscfu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

