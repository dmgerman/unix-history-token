begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2015 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* This header contains only those definitions that are global  * and non algorithm-specific for the entropy processor  */
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
value|static int								\ random_check_uint_##name(SYSCTL_HANDLER_ARGS)				\ {									\ 	if (oidp->oid_arg1 != NULL) {					\ 		if (*(u_int *)(oidp->oid_arg1)<= (min))		\ 			*(u_int *)(oidp->oid_arg1) = (min);		\ 		else if (*(u_int *)(oidp->oid_arg1)> (max))		\ 			*(u_int *)(oidp->oid_arg1) = (max);		\ 	}								\ 	return (sysctl_handle_int(oidp, oidp->oid_arg1, oidp->oid_arg2,	\ 		req));							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_DECL */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ENTROPY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct_decl
struct_decl|struct
name|harvest_event
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|random_alg_init_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_alg_deinit_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_alg_pre_read_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_alg_read_t
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|bool
name|random_alg_seeded_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_alg_reseed_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|random_alg_eventprocessor_t
parameter_list|(
name|struct
name|harvest_event
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|random_source_read_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Random Algorithm is a processor of randomness for the kernel  * and for userland.  */
end_comment

begin_struct
struct|struct
name|random_algorithm
block|{
specifier|const
name|char
modifier|*
name|ra_ident
decl_stmt|;
name|u_int
name|ra_poolcount
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ra_init_alg
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ra_deinit_alg
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|random_alg_pre_read_t
modifier|*
name|ra_pre_read
decl_stmt|;
name|random_alg_read_t
modifier|*
name|ra_read
decl_stmt|;
name|random_alg_seeded_t
modifier|*
name|ra_seeded
decl_stmt|;
name|random_alg_eventprocessor_t
modifier|*
name|ra_event_processor
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|random_algorithm
name|random_alg_context
decl_stmt|,
modifier|*
name|p_random_alg_context
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Random Source is a source of entropy that can provide  * specified or approximate amount of entropy immediately  * upon request.  */
end_comment

begin_struct
struct|struct
name|random_source
block|{
specifier|const
name|char
modifier|*
name|rs_ident
decl_stmt|;
name|enum
name|random_entropy_source
name|rs_source
decl_stmt|;
name|random_source_read_t
modifier|*
name|rs_read
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|random_sources
block|{
name|LIST_ENTRY
argument_list|(
argument|random_sources
argument_list|)
name|rrs_entries
expr_stmt|;
name|struct
name|random_source
modifier|*
name|rrs_source
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|sources_head
argument_list|,
name|random_sources
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sources_head
name|source_list
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|random_source_register
parameter_list|(
name|struct
name|random_source
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_source_deregister
parameter_list|(
name|struct
name|random_source
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RANDOM_LOADABLE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|randomdev_config_lock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RANDOM_CONFIG_INIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|sx_init(&randomdev_config_lock, "configuration change lock")
end_define

begin_define
define|#
directive|define
name|RANDOM_CONFIG_X_LOCK
parameter_list|(
name|x
parameter_list|)
value|sx_xlock(&randomdev_config_lock)
end_define

begin_define
define|#
directive|define
name|RANDOM_CONFIG_X_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|sx_xunlock(&randomdev_config_lock)
end_define

begin_define
define|#
directive|define
name|RANDOM_CONFIG_S_LOCK
parameter_list|(
name|x
parameter_list|)
value|sx_slock(&randomdev_config_lock)
end_define

begin_define
define|#
directive|define
name|RANDOM_CONFIG_S_UNLOCK
parameter_list|(
name|x
parameter_list|)
value|sx_sunlock(&randomdev_config_lock)
end_define

begin_define
define|#
directive|define
name|RANDOM_CONFIG_DEINIT_LOCK
parameter_list|(
name|x
parameter_list|)
value|sx_destroy(&randomdev_config_lock)
end_define

begin_function_decl
name|void
name|random_infra_init
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|uio
modifier|*
parameter_list|,
name|bool
parameter_list|)
parameter_list|,
name|u_int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|random_infra_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function_decl
name|void
name|randomdev_unblock
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
comment|/* SYS_DEV_RANDOM_RANDOMDEV_H_INCLUDED */
end_comment

end_unit

