begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_CLONE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_CLONE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|if_clone
struct_decl|;
end_struct_decl

begin_comment
comment|/* Methods. */
end_comment

begin_typedef
typedef|typedef
name|int
name|ifc_match_t
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ifc_create_t
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ifc_destroy_t
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ifcs_create_t
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ifcs_destroy_t
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Interface cloner (de)allocating functions. */
end_comment

begin_function_decl
name|struct
name|if_clone
modifier|*
name|if_clone_advanced
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|ifc_match_t
parameter_list|,
name|ifc_create_t
parameter_list|,
name|ifc_destroy_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|if_clone
modifier|*
name|if_clone_simple
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|ifcs_create_t
parameter_list|,
name|ifcs_destroy_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_clone_detach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unit (de)allocating fucntions. */
end_comment

begin_function_decl
name|int
name|ifc_name2unit
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_alloc_unit
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifc_free_unit
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_EVENTHANDLER_H_
end_ifdef

begin_comment
comment|/* Interface clone event. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|if_clone_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|if_clone_event
argument_list|,
name|if_clone_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The below interfaces used only by net/if.c. */
end_comment

begin_function_decl
name|void
name|if_clone_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_if_clone_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_destroy
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_list
parameter_list|(
name|struct
name|if_clonereq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The below interface used only by epair(4). */
end_comment

begin_function_decl
name|int
name|if_clone_destroyif
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_NET_IF_CLONE_H_ */
end_comment

end_unit

