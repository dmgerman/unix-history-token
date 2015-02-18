begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2013 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_DEV_RANDOM_RANDOMDEV_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SYS_DEV_RANDOM_RANDOMDEV_H_INCLUDED
end_define

begin_comment
comment|/* This header contains only those definitions that are global  * and non algorithm-specific for the entropy processor  */
end_comment

begin_typedef
typedef|typedef
name|void
name|random_init_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_deinit_func_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|randomdev_init_harvester
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|random_entropy_source
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_init_reader
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_deinit_harvester
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|randomdev_deinit_reader
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stub/fake routines for when no entropy processor is loaded */
end_comment

begin_function_decl
specifier|extern
name|void
name|dummy_random_read_phony
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* kern.random sysctls */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_comment
comment|/* from sysctl.h */
end_comment

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_kern_random
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If this was C++, the macro below would be a template */
end_comment

begin_define
define|#
directive|define
name|RANDOM_CHECK_UINT
parameter_list|(
name|name
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|static int								\ random_check_uint_##name(SYSCTL_HANDLER_ARGS)				\ {									\ 	if (oidp->oid_arg1 != NULL) {					\ 		 if (*(u_int *)(oidp->oid_arg1)<= (min))		\ 			*(u_int *)(oidp->oid_arg1) = (min);		\ 		 else if (*(u_int *)(oidp->oid_arg1)> (max))		\ 			*(u_int *)(oidp->oid_arg1) = (max);		\ 	}								\         return (sysctl_handle_int(oidp, oidp->oid_arg1, oidp->oid_arg2,	\ 		req));							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_DECL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

