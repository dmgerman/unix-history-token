begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010,2013 Lawrence Stewart<lstewart@freebsd.org>  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Lawrence Stewart while studying at the Centre  * for Advanced Internet Architectures, Swinburne University of Technology, made  * possible in part by grants from the FreeBSD Foundation and Cisco University  * Research Program Fund at Community Foundation Silicon Valley.  *  * Portions of this software were developed at the Centre for Advanced  * Internet Architectures, Swinburne University of Technology, Melbourne,  * Australia by Lawrence Stewart under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * A KPI modelled on the pfil framework for instantiating helper hook points  * within the kernel for use by Khelp modules. Originally released as part of  * the NewTCP research project at Swinburne University of Technology's Centre  * for Advanced Internet Architectures, Melbourne, Australia, which was made  * possible in part by a grant from the Cisco University Research Program Fund  * at Community Foundation Silicon Valley. More details are available at:  *   http://caia.swin.edu.au/urp/newtcp/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_HHOOK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_HHOOK_H_
end_define

begin_comment
comment|/* XXXLAS: Is there a way around this? */
end_comment

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rmlock.h>
end_include

begin_comment
comment|/* hhook_head flags. */
end_comment

begin_define
define|#
directive|define
name|HHH_ISINVNET
value|0x00000001
end_define

begin_comment
comment|/* Is the hook point in a vnet? */
end_comment

begin_comment
comment|/* Flags common to  all register functions. */
end_comment

begin_define
define|#
directive|define
name|HHOOK_WAITOK
value|0x00000001
end_define

begin_comment
comment|/* Sleeping allowed. */
end_comment

begin_define
define|#
directive|define
name|HHOOK_NOWAIT
value|0x00000002
end_define

begin_comment
comment|/* Sleeping disallowed. */
end_comment

begin_comment
comment|/* Flags only relevant to hhook_head_register() and hhook_head_is_virtual(). */
end_comment

begin_define
define|#
directive|define
name|HHOOK_HEADISINVNET
value|0x00000100
end_define

begin_comment
comment|/* Public proxy for HHH_ISINVNET. */
end_comment

begin_comment
comment|/* Helper hook types. */
end_comment

begin_define
define|#
directive|define
name|HHOOK_TYPE_TCP
value|1
end_define

begin_define
define|#
directive|define
name|HHOOK_TYPE_SOCKET
value|2
end_define

begin_struct_decl
struct_decl|struct
name|helper
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osd
struct_decl|;
end_struct_decl

begin_comment
comment|/* Signature for helper hook functions. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hhook_func_t
function_decl|)
parameter_list|(
name|int32_t
name|hhook_type
parameter_list|,
name|int32_t
name|hhook_id
parameter_list|,
name|void
modifier|*
name|udata
parameter_list|,
name|void
modifier|*
name|ctx_data
parameter_list|,
name|void
modifier|*
name|hdata
parameter_list|,
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Information required to add/remove a helper hook function to/from a helper  * hook point.  */
end_comment

begin_struct
struct|struct
name|hookinfo
block|{
name|hhook_func_t
name|hook_func
decl_stmt|;
name|struct
name|helper
modifier|*
name|hook_helper
decl_stmt|;
name|void
modifier|*
name|hook_udata
decl_stmt|;
name|int32_t
name|hook_id
decl_stmt|;
name|int32_t
name|hook_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ideally this would be private but we need access to the hhh_nhooks member  * variable in order to make the HHOOKS_RUN_IF() macro low impact.  */
end_comment

begin_struct
struct|struct
name|hhook_head
block|{
name|STAILQ_HEAD
argument_list|(
argument|hhook_list
argument_list|,
argument|hhook
argument_list|)
name|hhh_hooks
expr_stmt|;
name|struct
name|rmlock
name|hhh_lock
decl_stmt|;
name|uintptr_t
name|hhh_vid
decl_stmt|;
name|int32_t
name|hhh_id
decl_stmt|;
name|int32_t
name|hhh_nhooks
decl_stmt|;
name|int32_t
name|hhh_type
decl_stmt|;
name|uint32_t
name|hhh_flags
decl_stmt|;
specifier|volatile
name|uint32_t
name|hhh_refcount
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|hhook_head
argument_list|)
name|hhh_next
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|hhook_head
argument_list|)
name|hhh_vnext
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Public KPI functions. */
end_comment

begin_function_decl
name|void
name|hhook_run_hooks
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|,
name|void
modifier|*
name|ctx_data
parameter_list|,
name|struct
name|osd
modifier|*
name|hosd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_add_hook
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|,
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_add_hook_lookup
parameter_list|(
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_remove_hook
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|,
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_remove_hook_lookup
parameter_list|(
name|struct
name|hookinfo
modifier|*
name|hki
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_head_register
parameter_list|(
name|int32_t
name|hhook_type
parameter_list|,
name|int32_t
name|hhook_id
parameter_list|,
name|struct
name|hhook_head
modifier|*
modifier|*
name|hhh
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_head_deregister
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hhook_head_deregister_lookup
parameter_list|(
name|int32_t
name|hhook_type
parameter_list|,
name|int32_t
name|hhook_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hhook_head
modifier|*
name|hhook_head_get
parameter_list|(
name|int32_t
name|hhook_type
parameter_list|,
name|int32_t
name|hhook_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hhook_head_release
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hhook_head_is_virtualised
parameter_list|(
name|struct
name|hhook_head
modifier|*
name|hhh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hhook_head_is_virtualised_lookup
parameter_list|(
name|int32_t
name|hook_type
parameter_list|,
name|int32_t
name|hook_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A wrapper around hhook_run_hooks() that only calls the function if at least  * one helper hook function is registered for the specified helper hook point.  */
end_comment

begin_define
define|#
directive|define
name|HHOOKS_RUN_IF
parameter_list|(
name|hhh
parameter_list|,
name|ctx_data
parameter_list|,
name|hosd
parameter_list|)
value|do {				\ 	if (hhh != NULL&& hhh->hhh_nhooks> 0)				\ 		hhook_run_hooks(hhh, ctx_data, hosd);			\ } while (0)
end_define

begin_comment
comment|/*  * WARNING: This macro should only be used in code paths that execute  * infrequently, otherwise the refcounting overhead would be excessive.  *  * A similar wrapper to HHOOKS_RUN_IF() for situations where the caller prefers  * not to lookup and store the appropriate hhook_head pointer themselves.  */
end_comment

begin_define
define|#
directive|define
name|HHOOKS_RUN_LOOKUP_IF
parameter_list|(
name|hhook_type
parameter_list|,
name|hhook_id
parameter_list|,
name|ctx_data
parameter_list|,
name|hosd
parameter_list|)
value|do {	\ 	struct hhook_head *_hhh;					\ 									\ 	_hhh = hhook_head_get(hhook_type, hhook_id);			\ 	if (_hhh != NULL) {						\ 		if (_hhh->hhh_nhooks> 0)				\ 			hhook_run_hooks(_hhh, ctx_data, hosd);		\ 		hhook_head_release(_hhh);				\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_HHOOK_H_ */
end_comment

end_unit

