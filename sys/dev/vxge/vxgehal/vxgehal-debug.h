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
name|VXGE_HAL_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_HAL_DEBUG_H
end_define

begin_function
name|__EXTERN_BEGIN_DECLS
define|#
directive|define
name|D_ERR_MASK
value|((__hal_device_t *)hldev)->d_err_mask
define|#
directive|define
name|D_INFO_MASK
value|((__hal_device_t *)hldev)->d_info_mask
define|#
directive|define
name|D_TRACE_MASK
value|((__hal_device_t *)hldev)->d_trace_mask
if|#
directive|if
name|defined
argument_list|(
name|VXGE_TRACE_INTO_CIRCULAR_ARR
argument_list|)
define|#
directive|define
name|vxge_hal_debug_printf
value|vxge_os_vasprintf
else|#
directive|else
define|#
directive|define
name|vxge_hal_debug_printf
value|vxge_os_vaprintf
endif|#
directive|endif
ifndef|#
directive|ifndef
name|VXGE_DEBUG_INLINE_FUNCTIONS
define|#
directive|define
name|vxge_hal_debug_noop
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
specifier|static
specifier|inline
name|void
name|vxge_hal_debug_noop
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{  }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_DRIVER
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_driver
define|\
value|if (g_debug_level& VXGE_ERR) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_driver
define|\
value|if (g_debug_level& VXGE_INFO) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_driver
define|\
value|if (g_debug_level& VXGE_TRACE) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_driver
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_driver
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_driver
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_DEVICE
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_device
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_DEVICE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_device
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_DEVICE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_device
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_DEVICE) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_device
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_device
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_device
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_DEVICE_IRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_device_irq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_DEVICE_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_device_irq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_DEVICE_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_device_irq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_DEVICE_IRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_device_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_device_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_device_irq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_VPATH
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_vpath
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_VPATH) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_vpath
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_VPATH) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_vpath
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_VPATH) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_vpath
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_vpath
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_vpath
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_VPATH_IRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_vpath_irq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_VPATH_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_vpath_irq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_VPATH_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_vpath_irq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_VPATH_IRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_vpath_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_vpath_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_vpath_irq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_CONFIG
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_config
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_CONFIG) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_config
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_CONFIG) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_config
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_CONFIG) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_config
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_config
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_config
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_MM
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_mm
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_MM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mm
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_MM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mm
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_MM) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_mm
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mm
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mm
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_POOL
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_pool
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_POOL) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_pool
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_POOL) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_pool
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_POOL) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_pool
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_pool
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_pool
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_QUEUE
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_queue
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_QUEUE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_queue
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_QUEUE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_queue
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_QUEUE) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_queue
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_queue
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_queue
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_BITMAP
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_bitmap
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_BITMAP) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_bitmap
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_BITMAP) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_bitmap
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_BITMAP) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_bitmap
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_bitmap
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_bitmap
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_CHANNEL
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_channel
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_CHANNEL) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_channel
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_CHANNEL) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_channel
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_CHANNEL) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_channel
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_channel
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_channel
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_FIFO
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_fifo
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_FIFO) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_fifo
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_FIFO) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_fifo
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_FIFO) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_fifo
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_fifo
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_fifo
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_RING
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_ring
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_RING) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_ring
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_RING) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_ring
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_RING) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_ring
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_ring
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_ring
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_DMQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_dmq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_DMQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_dmq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_DMQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_dmq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_DMQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_dmq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_dmq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_dmq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_UMQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_umq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_UMQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_umq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_UMQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_umq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_UMQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_umq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_umq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_umq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_sq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_sq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_sq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_sq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_sq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_sq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_srq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_srq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_CQRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_cqrq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_CQRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_cqrq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_CQRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_cqrq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_CQRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_cqrq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_cqrq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_cqrq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_NCE
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_nce
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_NCE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_nce
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_NCE) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_nce
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_NCE) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_nce
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_nce
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_nce
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_STAG
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_stag
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_STAG) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_stag
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_STAG) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_stag
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_STAG) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_stag
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_stag
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_stag
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_TCP
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_tcp
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_TCP) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_tcp
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_TCP) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_tcp
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_TCP) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_tcp
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_tcp
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_tcp
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_LRO
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_lro
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_LRO) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_lro
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_LRO) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_lro
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_LRO) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_lro
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_lro
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_lro
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SPDM
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_spdm
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SPDM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_spdm
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SPDM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_spdm
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SPDM) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_spdm
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_spdm
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_spdm
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SESSION
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_session
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SESSION) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_session
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SESSION) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_session
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SESSION) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_session
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_session
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_session
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_STATS
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_stats
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_STATS) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_stats
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_STATS) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_stats
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_STATS) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_stats
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_stats
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_stats
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_MRPCIM
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_mrpcim
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_MRPCIM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mrpcim
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_MRPCIM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mrpcim
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_MRPCIM) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_mrpcim
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mrpcim
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mrpcim
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_MRPCIM_IRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_mrpcim_irq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_MRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mrpcim_irq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_MRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mrpcim_irq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_MRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_mrpcim_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_mrpcim_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_mrpcim_irq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SRPCIM
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_srpcim
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SRPCIM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srpcim
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SRPCIM) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srpcim
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SRPCIM) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_srpcim
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srpcim
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srpcim
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|VXGE_COMPONENT_HAL_SRPCIM_IRQ
operator|&
name|VXGE_DEBUG_MODULE_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|vxge_hal_err_log_srpcim_irq
define|\
value|if (D_ERR_MASK& VXGE_COMPONENT_HAL_SRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srpcim_irq
define|\
value|if (D_INFO_MASK& VXGE_COMPONENT_HAL_SRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srpcim_irq
define|\
value|if (D_TRACE_MASK& VXGE_COMPONENT_HAL_SRPCIM_IRQ) vxge_hal_debug_printf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vxge_hal_err_log_srpcim_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_info_log_srpcim_irq
value|vxge_hal_debug_noop
end_define

begin_define
define|#
directive|define
name|vxge_hal_trace_log_srpcim_irq
value|vxge_hal_debug_noop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXGE_HAL_DEBUG_H */
end_comment

end_unit

