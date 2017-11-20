begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright(c) 2002-2011 Exar Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification are permitted provided the following conditions are met:  *  *    1. Redistributions of source code must retain the above copyright notice,  *       this list of conditions and the following disclaimer.  *  *    2. Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *  *    3. Neither the name of the Exar Corporation nor the names of its  *       contributors may be used to endorse or promote products derived from  *       this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_DEBUG_H
end_define

begin_decl_stmt
name|__EXTERN_BEGIN_DECLS
comment|/*  * __FUNCTION__ is, together with __PRETTY_FUNCTION__ or something similar,  * a gcc extension. we'll have to #if defined around that, and provide some  * meaningful replacement for those, so to make some gcc versions happier  */
ifndef|#
directive|ifndef
name|__func__
if|#
directive|if
name|defined
argument_list|(
name|__FUNCTION__
argument_list|)
define|#
directive|define
name|__func__
value|__FUNCTION__
else|#
directive|else
define|#
directive|define
name|__func__
value|" "
endif|#
directive|endif
endif|#
directive|endif
define|#
directive|define
name|NULL_HLDEV
value|NULL
define|#
directive|define
name|NULL_VPID
value|0xFFFFFFFF
define|#
directive|define
name|VXGE_DEBUG_MODULE_MASK_DEF
value|0xFFFFFFFF
define|#
directive|define
name|VXGE_DEBUG_LEVEL_DEF
value|VXGE_TRACE
specifier|extern
name|u32
name|g_debug_level
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VXGE_DEBUG_MODULE_MASK
end_ifndef

begin_define
define|#
directive|define
name|VXGE_DEBUG_MODULE_MASK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * enum vxge_debug_level_e  * @VXGE_NONE: debug disabled  * @VXGE_ERR: all errors going to be logged out  * @VXGE_INFO: all errors plus all kind of info tracing print outs  *		going to be logged out. noisy.  * @VXGE_TRACE: all errors, all info plus all function entry and exit  *		and parameters. Very noisy  *  * This enumeration going to be used to switch between different  * debug levels during runtime if DEBUG macro defined during  * compilation. If DEBUG macro not defined than code will be  * compiled out.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vxge_debug_level_e
block|{
name|VXGE_NONE
init|=
literal|0x0
block|,
name|VXGE_ERR
init|=
literal|0x1
block|,
name|VXGE_INFO
init|=
literal|0x2
block|,
name|VXGE_TRACE
init|=
literal|0x4
block|, }
name|vxge_debug_level_e
typedef|;
end_typedef

begin_comment
comment|/*  * @VXGE_COMPONENT_HAL_DEVICE: do debug for vxge core device module  * @VXGE_COMPONENT_HAL_DEVICE_IRQ: do debug for vxge core device module in ISR  * @VXGE_COMPONENT_HAL_VAPTH: do debug for vxge core virtual path module  * @VXGE_COMPONENT_HAL_VAPTH_ISR: do debug for vxge core virtual path module in  *		ISR  * @VXGE_COMPONENT_HAL_CONFIG: do debug for vxge core config module  * @VXGE_COMPONENT_HAL_MM: do debug for vxge core memory module  * @VXGE_COMPONENT_HAL_POOL: do debug for vxge core memory pool module  * @VXGE_COMPONENT_HAL_QUEUE: do debug for vxge core queue module  * @VXGE_COMPONENT_HAL_BITMAP: do debug for vxge core BITMAP module  * @VXGE_COMPONENT_HAL_CHANNEL: do debug for vxge core channel module  * @VXGE_COMPONENT_HAL_FIFO: do debug for vxge core fifo module  * @VXGE_COMPONENT_HAL_RING: do debug for vxge core ring module  * @VXGE_COMPONENT_HAL_DMQ: do debug for vxge core DMQ module  * @VXGE_COMPONENT_HAL_UMQ: do debug for vxge core UMQ module  * @VXGE_COMPONENT_HAL_SQ: do debug for vxge core SQ module  * @VXGE_COMPONENT_HAL_SRQ: do debug for vxge core SRQ module  * @VXGE_COMPONENT_HAL_CQRQ: do debug for vxge core CRQ module  * @VXGE_COMPONENT_HAL_NCE: do debug for vxge core NCE module  * @VXGE_COMPONENT_HAL_STAG: do debug for vxge core STAG module  * @VXGE_COMPONENT_HAL_TCP: do debug for vxge core TCP module  * @VXGE_COMPONENT_HAL_LRO: do debug for vxge core LRO module  * @VXGE_COMPONENT_HAL_SPDM: do debug for vxge core SPDM module  * @VXGE_COMPONENT_HAL_SESSION: do debug for vxge core SESSION module  * @VXGE_COMPONENT_HAL_STATS: do debug for vxge core statistics module  * @VXGE_COMPONENT_HAL_MRPCIM: do debug for vxge KMA core mrpcim module  * @VXGE_COMPONENT_HAL_SRPCIM: do debug for vxge KMA core srpcim module  * @VXGE_COMPONENT_OSDEP: do debug for vxge KMA os dependent parts  * @VXGE_COMPONENT_LL: do debug for vxge link layer module  * @VXGE_COMPONENT_ULD: do debug for vxge upper layer driver  * @VXGE_COMPONENT_ALL: activate debug for all modules with no exceptions  *  * This enumeration going to be used to distinguish modules  * or libraries during compilation and runtime.  Makefile must declare  * VXGE_DEBUG_MODULE_MASK macro and set it to proper value.  */
end_comment

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_DEVICE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_DEVICE_IRQ
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_VPATH
value|0x00000004
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_VPATH_IRQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_CONFIG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_MM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_POOL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_QUEUE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_BITMAP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_CHANNEL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_FIFO
value|0x00000400
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_RING
value|0x00000800
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_DMQ
value|0x00001000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_UMQ
value|0x00002000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SQ
value|0x00004000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SRQ
value|0x00008000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_CQRQ
value|0x00010000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_NCE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_STAG
value|0x00040000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_TCP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_LRO
value|0x00100000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SPDM
value|0x00200000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SESSION
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_STATS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_MRPCIM
value|0x01000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_MRPCIM_IRQ
value|0x02000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SRPCIM
value|0x04000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_SRPCIM_IRQ
value|0x08000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_HAL_DRIVER
value|0x10000000
end_define

begin_comment
comment|/* space for CORE_XXX */
end_comment

begin_define
define|#
directive|define
name|VXGE_COMPONENT_OSDEP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_LL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_ULD
value|0x80000000
end_define

begin_define
define|#
directive|define
name|VXGE_COMPONENT_ALL
value|0xffffffff
end_define

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_DEBUG_H */
end_comment

end_unit

