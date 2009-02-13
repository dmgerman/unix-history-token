begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_DEBUG_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-os-pal.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*  * __FUNCTION__ is, together with __PRETTY_FUNCTION__ or something similar,  * a gcc extension. we'll have to #ifdef around that, and provide some  * meaningful replacement for those, so to make some gcc versions happier  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__func__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__FUNCTION__
end_ifdef

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_DEBUG_FP
end_ifdef

begin_define
define|#
directive|define
name|XGE_DEBUG_FP_DEVICE
value|0x1
end_define

begin_define
define|#
directive|define
name|XGE_DEBUG_FP_CHANNEL
value|0x2
end_define

begin_define
define|#
directive|define
name|XGE_DEBUG_FP_FIFO
value|0x4
end_define

begin_define
define|#
directive|define
name|XGE_DEBUG_FP_RING
value|0x8
end_define

begin_define
define|#
directive|define
name|XGE_DEBUG_FP_ALL
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * enum xge_debug_level_e  * @XGE_NONE: debug disabled  * @XGE_ERR: all errors going to be logged out  * @XGE_TRACE: all errors plus all kind of verbose tracing print outs  *                 going to be logged out. Very noisy.  *  * This enumeration going to be used to switch between different  * debug levels during runtime if DEBUG macro defined during  * compilation. If DEBUG macro not defined than code will be  * compiled out.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xge_debug_level_e
block|{
name|XGE_NONE
init|=
literal|0
block|,
name|XGE_TRACE
init|=
literal|1
block|,
name|XGE_ERR
init|=
literal|2
block|, }
name|xge_debug_level_e
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XGE_DEBUG_MODULE_MASK_DEF
value|0x30000030
end_define

begin_define
define|#
directive|define
name|XGE_DEBUG_LEVEL_DEF
value|XGE_ERR
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XGE_DEBUG_TRACE_MASK
argument_list|)
operator|||
name|defined
argument_list|(
name|XGE_DEBUG_ERR_MASK
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|long
modifier|*
name|g_module_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|g_level
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_DEBUG_TRACE_MASK
end_ifndef

begin_define
define|#
directive|define
name|XGE_DEBUG_TRACE_MASK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_DEBUG_ERR_MASK
end_ifndef

begin_define
define|#
directive|define
name|XGE_DEBUG_ERR_MASK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * @XGE_COMPONENT_HAL_CONFIG: do debug for xge core config module  * @XGE_COMPONENT_HAL_FIFO: do debug for xge core fifo module  * @XGE_COMPONENT_HAL_RING: do debug for xge core ring module  * @XGE_COMPONENT_HAL_CHANNEL: do debug for xge core channel module  * @XGE_COMPONENT_HAL_DEVICE: do debug for xge core device module  * @XGE_COMPONENT_HAL_DMQ: do debug for xge core DMQ module  * @XGE_COMPONENT_HAL_UMQ: do debug for xge core UMQ module  * @XGE_COMPONENT_HAL_SQ: do debug for xge core SQ module  * @XGE_COMPONENT_HAL_SRQ: do debug for xge core SRQ module  * @XGE_COMPONENT_HAL_CQRQ: do debug for xge core CRQ module  * @XGE_COMPONENT_HAL_POOL: do debug for xge core memory pool module  * @XGE_COMPONENT_HAL_BITMAP: do debug for xge core BITMAP module  * @XGE_COMPONENT_CORE: do debug for xge KMA core module  * @XGE_COMPONENT_OSDEP: do debug for xge KMA os dependent parts  * @XGE_COMPONENT_LL: do debug for xge link layer module  * @XGE_COMPONENT_ALL: activate debug for all modules with no exceptions  *  * This enumeration going to be used to distinguish modules  * or libraries during compilation and runtime.  Makefile must declare  * XGE_DEBUG_MODULE_MASK macro and set it to proper value.  */
end_comment

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_CONFIG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_FIFO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_RING
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_CHANNEL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_DEVICE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_MM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_QUEUE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_INTERRUPT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_HAL_STATS
value|0x00000100
end_define

begin_comment
comment|/* space for CORE_XXX */
end_comment

begin_define
define|#
directive|define
name|XGE_COMPONENT_OSDEP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_LL
value|0x20000000
end_define

begin_define
define|#
directive|define
name|XGE_COMPONENT_ALL
value|0xffffffff
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_DEBUG_MODULE_MASK
end_ifndef

begin_error
error|#
directive|error
literal|"XGE_DEBUG_MODULE_MASK macro must be defined for DEBUG mode..."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_TRACE_INTO_CIRCULAR_ARR
end_ifdef

begin_define
define|#
directive|define
name|xge_trace_aux
parameter_list|(
name|fmt
parameter_list|)
value|xge_os_vatrace(g_xge_os_tracebuf, fmt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_trace_aux
parameter_list|(
name|fmt
parameter_list|)
value|xge_os_vaprintf(fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * xge_debug  * @level: level of debug verbosity.  * @fmt: printf like format string  *  * Provides logging facilities. Can be customized on per-module  * basis or/and with debug levels. Input parameters, except  * module and level, are the same as posix printf. This function  * may be compiled out if DEBUG macro was never defined.  * See also: xge_debug_level_e{}.  */
end_comment

begin_define
define|#
directive|define
name|xge_debug
parameter_list|(
name|module
parameter_list|,
name|level
parameter_list|,
name|fmt
parameter_list|)
value|{ \ if (((level>= XGE_TRACE&& ((module& XGE_DEBUG_TRACE_MASK) == module)) || \ 	(level>= XGE_ERR&& ((module& XGE_DEBUG_ERR_MASK) == module)))&& \ 	level>= *g_level&& module& *(unsigned int *)g_module_mask) { \ 	            xge_trace_aux(fmt); \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_TRACE_INTO_CIRCULAR_ARR
end_ifdef

begin_define
define|#
directive|define
name|xge_trace_aux
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|xge_os_trace(g_xge_os_tracebuf, fmt)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_trace_aux
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|xge_os_printf(fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|xge_debug
parameter_list|(
name|module
parameter_list|,
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
value|{ \ if (((level>= XGE_TRACE&& ((module& XGE_DEBUG_TRACE_MASK) == module)) || \ 	(level>= XGE_ERR&& ((module& XGE_DEBUG_ERR_MASK) == module)))&& \ 	level>= *g_level&& module& *(unsigned int *)g_module_mask) { \ 	            xge_trace_aux(fmt); \ 	} \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_STATS
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_stats
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_STATS
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_stats
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_STATS, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_stats
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_stats
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Interrupt Related */
end_comment

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_INTERRUPT
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_interrupt
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_INTERRUPT
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_interrupt
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_INTERRUPT, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_interrupt
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_interrupt
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_QUEUE
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_queue
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_QUEUE
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_queue
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_QUEUE, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_queue
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_queue
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_MM
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_mm
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_MM
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_mm
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_MM, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_mm
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_mm
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_CONFIG
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_config
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_CONFIG
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_config
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_CONFIG, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_config
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_config
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_FIFO
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_fifo
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_FIFO
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_fifo
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_FIFO, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_fifo
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_fifo
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_RING
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ring
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_RING
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_ring
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_RING, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ring
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_ring
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_CHANNEL
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_channel
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_CHANNEL
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_channel
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_CHANNEL, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_channel
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_channel
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_HAL_DEVICE
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_device
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_HAL_DEVICE
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_device
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_HAL_DEVICE, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_device
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_device
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_OSDEP
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_osdep
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_OSDEP
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_osdep
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_OSDEP, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_osdep
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_osdep
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|XGE_COMPONENT_LL
operator|&
name|XGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ll
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|u32
name|module
init|=
name|XGE_COMPONENT_LL
decl_stmt|;
name|xge_debug
argument_list|(
name|module
argument_list|,
name|level
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_ll
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|xge_debug(XGE_COMPONENT_LL, level, fmt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ll
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_define
define|#
directive|define
name|xge_debug_ll
parameter_list|(
name|level
parameter_list|,
name|fmt
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_interrupt
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_stats
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_queue
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_mm
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_config
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_fifo
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ring
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_channel
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_device
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_hal
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_osdep
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_debug_ll
parameter_list|(
name|xge_debug_level_e
name|level
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of XGE_DEBUG_*_MASK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_DEBUG_ASSERT
end_ifdef

begin_comment
comment|/**  * xge_assert  * @test: C-condition to check  * @fmt: printf like format string  *  * This function implements traditional assert. By default assertions  * are enabled. It can be disabled by defining XGE_DEBUG_ASSERT macro in  * compilation  * time.  */
end_comment

begin_define
define|#
directive|define
name|xge_assert
parameter_list|(
name|test
parameter_list|)
value|{ \ 	    if (!(test)) xge_os_bug("bad cond: "#test" at %s:%d\n", \ 	__FILE__, __LINE__); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_assert
parameter_list|(
name|test
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of XGE_DEBUG_ASSERT */
end_comment

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_DEBUG_H */
end_comment

end_unit

