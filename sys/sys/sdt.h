begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2006-2008 John Birrell<jb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Statically Defined Tracing (SDT) definitions.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SDT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SDT_H
end_define

begin_comment
comment|/* Stub these for the time being. */
end_comment

begin_define
define|#
directive|define
name|DTRACE_PROBE
parameter_list|(
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE1
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE2
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE3
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|,
name|type3
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DTRACE_PROBE4
parameter_list|(
name|name
parameter_list|,
name|type1
parameter_list|,
name|arg1
parameter_list|,
name|type2
parameter_list|,
name|arg2
parameter_list|,
name|type3
parameter_list|,
name|arg3
parameter_list|,
name|type4
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* The promise of things to come. Worlds to explore. People to meet. Things to do. */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|KDTRACE_HOOKS
end_ifndef

begin_define
define|#
directive|define
name|SDT_PROVIDER_DEFINE
parameter_list|(
name|prov
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROVIDER_DECLARE
parameter_list|(
name|prov
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DECLARE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_ARGTYPE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|num
parameter_list|,
name|type
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE1
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE2
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE3
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE4
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE5
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This type definition must match that of dtrace_probe. It is defined this  * way to avoid having to rely on CDDL code.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sdt_probe_func_t
function_decl|)
parameter_list|(
name|u_int32_t
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The hook for the probe function. See kern_sdt.c which defaults this to  * it's own stub. The 'sdt' provider will set it to dtrace_probe when it  * loads.  */
end_comment

begin_decl_stmt
specifier|extern
name|sdt_probe_func_t
name|sdt_probe_func
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|SDT_UNINIT
init|=
literal|1
block|,
name|SDT_INIT
block|, }
name|sdt_state_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|sdt_probe
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sdt_provider
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sdt_argtype
block|{
name|int
name|ndx
decl_stmt|;
comment|/* Argument index. */
specifier|const
name|char
modifier|*
name|type
decl_stmt|;
comment|/* Argument type string. */
name|TAILQ_ENTRY
argument_list|(
argument|sdt_argtype
argument_list|)
name|argtype_entry
expr_stmt|;
comment|/* Argument type list entry. */
name|struct
name|sdt_probe
modifier|*
name|probe
decl_stmt|;
comment|/* Ptr to the probe structure. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdt_probe
block|{
name|int
name|version
decl_stmt|;
comment|/* Set to sizeof(struct sdt_ref). */
name|sdt_state_t
name|state
decl_stmt|;
name|struct
name|sdt_provider
modifier|*
name|prov
decl_stmt|;
comment|/* Ptr to the provider structure. */
name|TAILQ_ENTRY
argument_list|(
argument|sdt_probe
argument_list|)
name|probe_entry
expr_stmt|;
comment|/* SDT probe list entry. */
name|TAILQ_HEAD
argument_list|(
argument|argtype_list_head
argument_list|,
argument|sdt_argtype
argument_list|)
name|argtype_list
expr_stmt|;
specifier|const
name|char
modifier|*
name|mod
decl_stmt|;
specifier|const
name|char
modifier|*
name|func
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|id_t
name|id
decl_stmt|;
comment|/* DTrace probe ID. */
name|int
name|n_args
decl_stmt|;
comment|/* Number of arguments. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdt_provider
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Provider name. */
name|TAILQ_ENTRY
argument_list|(
argument|sdt_provider
argument_list|)
name|prov_entry
expr_stmt|;
comment|/* SDT provider list entry. */
name|TAILQ_HEAD
argument_list|(
argument|probe_list_head
argument_list|,
argument|sdt_probe
argument_list|)
name|probe_list
expr_stmt|;
name|uintptr_t
name|id
decl_stmt|;
comment|/* DTrace provider ID. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDT_PROVIDER_DEFINE
parameter_list|(
name|prov
parameter_list|)
define|\
value|struct sdt_provider sdt_provider_##prov[1] = {				\ 		{ #prov, { NULL, NULL }, { NULL, NULL } }			\ 	};									\ 	SYSINIT(sdt_provider_##prov##_init, SI_SUB_KDTRACE, 			\ 	    SI_ORDER_SECOND, sdt_provider_register, 				\ 	    sdt_provider_##prov );						\ 	SYSUNINIT(sdt_provider_##prov##_uninit, SI_SUB_KDTRACE,			\ 	    SI_ORDER_SECOND, sdt_provider_deregister, 				\ 	    sdt_provider_##prov )
end_define

begin_define
define|#
directive|define
name|SDT_PROVIDER_DECLARE
parameter_list|(
name|prov
parameter_list|)
define|\
value|extern struct sdt_provider sdt_provider_##prov[1]
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
define|\
value|struct sdt_probe sdt_##prov##_##mod##_##func##_##name[1] = {		\ 		{ sizeof(struct sdt_probe), 0, sdt_provider_##prov,		\ 		    { NULL, NULL }, { NULL, NULL }, #mod, #func, #name, 0, 0 }	\ 	};									\ 	SYSINIT(sdt_##prov##_##mod##_##func##_##name##_init, SI_SUB_KDTRACE, 	\ 	    SI_ORDER_SECOND + 1, sdt_probe_register, 				\ 	    sdt_##prov##_##mod##_##func##_##name );				\ 	SYSUNINIT(sdt_##prov##_##mod##_##func##_##name##_uninit, 		\ 	    SI_SUB_KDTRACE, SI_ORDER_SECOND + 1, sdt_probe_deregister, 		\ 	    sdt_##prov##_##mod##_##func##_##name )
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DECLARE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
define|\
value|extern struct sdt_probe sdt_##prov##_##mod##_##func##_##name[1]
end_define

begin_define
define|#
directive|define
name|SDT_PROBE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|if (sdt_##prov##_##mod##_##func##_##name->id)				\ 		(*sdt_probe_func)(sdt_##prov##_##mod##_##func##_##name->id,	\ 		    (uintptr_t) arg0, (uintptr_t) arg1, (uintptr_t) arg2,	\ 		    (uintptr_t) arg3, (uintptr_t) arg4)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_ARGTYPE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|num
parameter_list|,
name|type
parameter_list|)
define|\
value|struct sdt_argtype sdt_##prov##_##mod##_##func##_##name##num[1]		\ 	    = { { num, type, { NULL, NULL },					\ 	    sdt_##prov##_##mod##_##func##_##name }				\ 	};									\ 	SYSINIT(sdt_##prov##_##mod##_##func##_##name##num##_init,		\ 	    SI_SUB_KDTRACE, SI_ORDER_SECOND + 2, sdt_argtype_register, 		\ 	    sdt_##prov##_##mod##_##func##_##name##num );			\ 	SYSUNINIT(sdt_##prov##_##mod##_##func##_##name##num##_uninit, 		\ 	    SI_SUB_KDTRACE, SI_ORDER_SECOND + 2, sdt_argtype_deregister,	\ 	    sdt_##prov##_##mod##_##func##_##name##num )
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE1
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|)
define|\
value|SDT_PROBE_DEFINE(prov, mod, func, name);			\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 0, arg0)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE2
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE_DEFINE(prov, mod, func, name);			\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 0, arg0);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 1, arg1)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE3
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|SDT_PROBE_DEFINE(prov, mod, func, name);			\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 0, arg0);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 1, arg1);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 2, arg2)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE4
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|SDT_PROBE_DEFINE(prov, mod, func, name);			\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 0, arg0);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 1, arg1);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 2, arg2);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 3, arg3)
end_define

begin_define
define|#
directive|define
name|SDT_PROBE_DEFINE5
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|SDT_PROBE_DEFINE(prov, mod, func, name);			\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 0, arg0);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 1, arg1);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 2, arg2);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 3, arg3);		\ 	SDT_PROBE_ARGTYPE(prov, mod, func, name, 4, arg4)
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sdt_argtype_listall_func_t
function_decl|)
parameter_list|(
name|struct
name|sdt_argtype
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sdt_probe_listall_func_t
function_decl|)
parameter_list|(
name|struct
name|sdt_probe
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|sdt_provider_listall_func_t
function_decl|)
parameter_list|(
name|struct
name|sdt_provider
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|sdt_argtype_deregister
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_argtype_register
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_probe_deregister
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_probe_register
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_provider_deregister
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_provider_register
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdt_probe_stub
parameter_list|(
name|u_int32_t
parameter_list|,
name|uintptr_t
name|arg0
parameter_list|,
name|uintptr_t
name|arg1
parameter_list|,
name|uintptr_t
name|arg2
parameter_list|,
name|uintptr_t
name|arg3
parameter_list|,
name|uintptr_t
name|arg4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdt_argtype_listall
parameter_list|(
name|struct
name|sdt_probe
modifier|*
parameter_list|,
name|sdt_argtype_listall_func_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdt_probe_listall
parameter_list|(
name|struct
name|sdt_provider
modifier|*
parameter_list|,
name|sdt_probe_listall_func_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sdt_provider_listall
parameter_list|(
name|sdt_provider_listall_func_t
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
comment|/* KDTRACE_HOOKS */
end_comment

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
comment|/* _SYS_SDT_H */
end_comment

end_unit

