begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2009 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This is the virtual network stack memory allocator, which provides support  * for virtualized global variables via a special linker set, set_vnet.  When  * "options VIMAGE" isn't defined, virtualized global variables are compiled  * as normal globals.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_VNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_VNET_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_VNET
argument_list|)
end_if

begin_define
define|#
directive|define
name|VNET_SETNAME
value|"set_vnet"
end_define

begin_define
define|#
directive|define
name|VNET_SYMPREFIX
value|"vnet_entry_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/*  * SYSINIT/SYSUNINIT variants that provide per-vnet constructors and  * destructors.  */
end_comment

begin_struct
struct|struct
name|vnet_sysinit
block|{
name|enum
name|sysinit_sub_id
name|subsystem
decl_stmt|;
name|enum
name|sysinit_elem_order
name|order
decl_stmt|;
name|sysinit_cfunc_t
name|func
decl_stmt|;
specifier|const
name|void
modifier|*
name|arg
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|vnet_sysinit
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VNET_SYSINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct vnet_sysinit ident ## _vnet_init = {		\ 		subsystem,						\ 		order,							\ 		(sysinit_cfunc_t)(sysinit_nfunc_t)func,			\ 		(arg)							\ 	};								\ 	SYSINIT(vnet_init_ ## ident, subsystem, order,			\ 	    vnet_register_sysinit,&ident ## _vnet_init);		\ 	SYSUNINIT(vnet_init_ ## ident, subsystem, order,		\ 	    vnet_deregister_sysinit,&ident ## _vnet_init)
end_define

begin_define
define|#
directive|define
name|VNET_SYSUNINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct vnet_sysinit ident ## _vnet_uninit = {		\ 		subsystem,						\ 		order,							\ 		(sysinit_cfunc_t)(sysinit_nfunc_t)func,			\ 		(arg)							\ 	};								\ 	SYSINIT(vnet_uninit_ ## ident, subsystem, order,		\ 	    vnet_register_sysuninit,&ident ## _vnet_uninit);		\ 	SYSUNINIT(vnet_uninit_ ## ident, subsystem, order,		\ 	    vnet_deregister_sysuninit,&ident ## _vnet_uninit)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_asm
asm|__asm__(".section " VNET_SETNAME ", \"aw\", %progbits");
end_asm

begin_else
else|#
directive|else
end_else

begin_asm
asm|__asm__(".section " VNET_SETNAME ", \"aw\", @progbits");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|__asm__(".previous");
end_asm

begin_define
define|#
directive|define
name|VNET_NAME
parameter_list|(
name|n
parameter_list|)
value|vnet_entry_##n
end_define

begin_define
define|#
directive|define
name|VNET_DECLARE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|extern t VNET_NAME(n)
end_define

begin_define
define|#
directive|define
name|VNET_DEFINE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|t VNET_NAME(n) __section(VNET_SETNAME) __used
end_define

begin_define
define|#
directive|define
name|_VNET_PTR
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|(__typeof(VNET_NAME(n))*)		\ 				    ((b) + (uintptr_t)&VNET_NAME(n))
end_define

begin_define
define|#
directive|define
name|_VNET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|(*_VNET_PTR(b, n))
end_define

begin_comment
comment|/*  * Virtualized global variable accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|VNET_VNET_PTR
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|_VNET_PTR((vnet)->vnet_data_base, n)
end_define

begin_define
define|#
directive|define
name|VNET_VNET
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(*VNET_VNET_PTR((vnet), n))
end_define

begin_define
define|#
directive|define
name|VNET_PTR
parameter_list|(
name|n
parameter_list|)
value|VNET_VNET_PTR(curvnet, n)
end_define

begin_define
define|#
directive|define
name|VNET
parameter_list|(
name|n
parameter_list|)
value|VNET_VNET(curvnet, n)
end_define

begin_comment
comment|/*  * Sysctl variants for vnet-virtualized global variables.  Include  *<sys/sysctl.h> to expose these definitions.  *  * Note: SYSCTL_PROC() handler functions will need to resolve pointer  * arguments themselves, if required.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_OID
end_ifdef

begin_function_decl
name|int
name|vnet_sysctl_handle_int
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vnet_sysctl_handle_opaque
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vnet_sysctl_handle_string
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vnet_sysctl_handle_uint
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SYSCTL_VNET_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_INT|CTLFLAG_MPSAFE|(access), \ 	    ptr, val, vnet_sysctl_handle_int, "I", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,	\
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, access, ptr, arg, handler, fmt,	\ 	    descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_STRING|(access), arg,	\ 	    len, vnet_sysctl_handle_string, "A", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_OPAQUE|(access), ptr,	\ 	    sizeof(struct type), vnet_sysctl_handle_opaque, "S," #type,	\ 	    descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_UINT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name, CTLTYPE_UINT|CTLFLAG_MPSAFE|(access), \ 	    ptr, val, vnet_sysctl_handle_uint, "IU", descr)
end_define

begin_define
define|#
directive|define
name|VNET_SYSCTL_ARG
parameter_list|(
name|req
parameter_list|,
name|arg1
parameter_list|)
value|do {					\ 	if (arg1 != NULL)						\ 		arg1 = (void *)(TD_TO_VNET((req)->td)->vnet_data_base +	\ 		    (uintptr_t)(arg1));					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_OID */
end_comment

begin_comment
comment|/*  * Interfaces from the kernel linker.  */
end_comment

begin_function_decl
name|void
modifier|*
name|vnet_data_alloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_data_copy
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_data_free
parameter_list|(
name|void
modifier|*
name|start_arg
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interfaces for vnet setup/teardown.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vnet
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|vnet_data_init
parameter_list|(
name|struct
name|vnet
modifier|*
name|vnet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_data_destroy
parameter_list|(
name|struct
name|vnet
modifier|*
name|vnet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_sysinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_sysuninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interfaces for managing per-vnet constructors and destructors.  */
end_comment

begin_function_decl
name|void
name|vnet_register_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_register_sysuninit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_deregister_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_deregister_sysuninit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_comment
comment|/*  * Versions of the VNET macros that compile to normal global variables and  * standard sysctl definitions.  */
end_comment

begin_define
define|#
directive|define
name|VNET_NAME
parameter_list|(
name|n
parameter_list|)
value|n
end_define

begin_define
define|#
directive|define
name|VNET_DECLARE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|extern t n
end_define

begin_define
define|#
directive|define
name|VNET_DEFINE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|t n
end_define

begin_define
define|#
directive|define
name|_VNET_PTR
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|&VNET_NAME(n)
end_define

begin_define
define|#
directive|define
name|VNET_SYSINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|SYSINIT(ident, subsystem, order, func, arg)
end_define

begin_define
define|#
directive|define
name|VNET_SYSUNINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|SYSUNINIT(ident, subsystem, order, func, arg)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_OID
end_ifdef

begin_define
define|#
directive|define
name|SYSCTL_VNET_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_INT(parent, nbr, name, access, ptr, val, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,	\
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(parent, nbr, name, access, ptr, arg, handler, fmt,	\ 	    descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_STRING(parent, nbr, name, access, arg, len, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_STRUCT(parent, nbr, name, access, ptr, type, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_UINT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_UINT(parent, nbr, name, access, ptr, val, descr)
end_define

begin_define
define|#
directive|define
name|VNET_SYSCTL_ARG
parameter_list|(
name|req
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_OID */
end_comment

begin_comment
comment|/*  * Virtualized global variable accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|VNET_VNET_PTR
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(&(n))
end_define

begin_define
define|#
directive|define
name|VNET_VNET
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|VNET_PTR
parameter_list|(
name|n
parameter_list|)
value|(&(n))
end_define

begin_define
define|#
directive|define
name|VNET
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIMAGE */
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
comment|/* !_NET_VNET_H_ */
end_comment

end_unit

