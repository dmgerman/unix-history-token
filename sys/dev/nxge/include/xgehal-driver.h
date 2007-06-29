begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xgehal-driver.h  *  *  Description:  HAL driver object functionality  *  *  Created:      14 May 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_HAL_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_HAL_DRIVER_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-os-pal.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-list.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-queue.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-types.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-config.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-event.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/* maximum number of events consumed in a syncle poll() cycle */
end_comment

begin_define
define|#
directive|define
name|XGE_HAL_DRIVER_QUEUE_CONSUME_MAX
value|5
end_define

begin_comment
comment|/**  * function xge_uld_sched_timer_cb_f - Per-device periodic timer  * callback.  * @devh: HAL device handle.  * @userdata: Per-device user data (a.k.a. context) specified via  * xge_hal_device_initialize().  *  * Periodic or one-shot timer callback. If specified (that is, not NULL)  * HAL invokes this callback periodically. The call is performed in the  * interrupt context, or more exactly, in the context of HAL's ISR  * xge_hal_device_continue_irq().  *  * See also: xge_hal_device_initialize{}  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_sched_timer_cb_f
function_decl|)
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_link_up_f - Link-Up callback provided by upper-layer  * driver.  * @userdata: Opaque context set by the ULD via  * xge_hal_device_private_set()  * (typically - at HAL device iinitialization time).  *  * Link-up notification callback provided by the ULD.  * This is one of the per-driver callbacks, see xge_hal_uld_cbs_t{}.  *  * See also: xge_hal_uld_cbs_t{}, xge_uld_link_down_f{},  * xge_hal_driver_initialize(), xge_hal_device_private_set().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_link_up_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_link_down_f - Link-Down callback provided by  * upper-layer driver.  * @userdata: Opaque context set by the ULD via  * xge_hal_device_private_set()  * (typically - at HAL device iinitialization time).  *  * Link-Down notification callback provided by the upper-layer driver.  * This is one of the per-driver callbacks, see xge_hal_uld_cbs_t{}.  *  * See also: xge_hal_uld_cbs_t{}, xge_uld_link_up_f{},  * xge_hal_driver_initialize(), xge_hal_device_private_set().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_link_down_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|userdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_crit_err_f - Critical Error notification callback.  * @userdata: Opaque context set by the ULD via  * xge_hal_device_private_set()  * (typically - at HAL device iinitialization time).  * @type: Enumerated hw error, e.g.: double ECC.  * @serr_data: Xframe status.  * @ext_data: Extended data. The contents depends on the @type.  *  * Link-Down notification callback provided by the upper-layer driver.  * This is one of the per-driver callbacks, see xge_hal_uld_cbs_t{}.  *  * See also: xge_hal_uld_cbs_t{}, xge_hal_event_e{},  * xge_hal_device_private_set(), xge_hal_driver_initialize().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_crit_err_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|userdata
parameter_list|,
name|xge_hal_event_e
name|type
parameter_list|,
name|u64
name|ext_data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_event_queued_f - Event-enqueued notification  * callback.  * @devh: HAL device handle.  * @event_type: HAL- or ULD-defined event type. Note that HAL  *              events are enumerated by xge_hal_event_e{}.  *  * "Event-was-enqueued" notification callback provided by the upper-layer  * driver. The callback is invoked (if defined, i.e., not NULL in the  * xge_hal_uld_cbs_t{} structure) each time immediately after an event  * is enqueued.  *  * See also: xge_hal_uld_cbs_t{}, xge_hal_device_private_set(),  * xge_hal_driver_initialize().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_event_queued_f
function_decl|)
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|,
name|int
name|event_type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_event_f - ULD event callback.  * @item: ULD-defined event, item of the xge_queue_t.  *  * ULD event callback.  * Upper-layer driver can use HAL queue to serialize certain slow-path  * events. HAL periodically polls the queue as part of the  * xge_hal_device_poll() processing. When/if HAL discovers in the queue  * an unkown event type it simply invokes the event callback  * (which must be non-NULL and supplied by the ULD in this case).  *  * See also: xge_hal_uld_cbs_t{}, xge_hal_device_poll(), xge_queue_t{},  * xge_hal_driver_initialize(), xge_queue_item_t{}.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_event_f
function_decl|)
parameter_list|(
name|xge_queue_item_t
modifier|*
name|item
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_before_device_poll_f - ULD "before-poll" callback.  * @devh: HAL device handle.  *  * HAL invokes the callback from inside its xge_hal_device_poll()  * implementation %prior to accessing the @devh device. This allows ULD to  * perform per-device locking and/or context mapping, if required..  * The interface is currently used by AIX driver only.  * To avoid using/implementing the callback set the corresponding field  * in the xge_hal_uld_cbs_t{} structure to NULL.  *  * Returns: 0 on success, non-zero on failure.  *  * See also: xge_hal_driver_initialize(), xge_hal_uld_cbs_t{},  * xge_hal_device_poll().  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xge_uld_before_device_poll_f
function_decl|)
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_after_device_poll_f - ULD "after-poll" callback.  * @devh: HAL device handle.  *  * Unless NULL is specified,  * HAL invokes the callback from inside its xge_hal_device_poll()  * implementation immediately %after it has completed polling the @devh  * device. This allows ULD to undo the affects of  * xge_uld_before_device_poll_f{}.  * The interface is currently used by AIX driver only.  *  * See also: xge_hal_driver_initialize(), xge_hal_uld_cbs_t{},  * xge_hal_device_poll().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_after_device_poll_f
function_decl|)
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * function xge_uld_xpak_alarm_log_f - ULD "XPAK alarm log" callback.  * @devh: HAL device handle.  * @type: TODO  *  * Unless NULL is specified,  * HAL invokes the callback from inside __hal_chk_xpak_counter()  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_uld_xpak_alarm_log_f
function_decl|)
parameter_list|(
name|xge_hal_device_h
name|devh
parameter_list|,
name|xge_hal_xpak_alarm_type_e
name|type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * struct xge_hal_uld_cbs_t - Upper-layer driver "slow-path" callbacks.  * @link_up: See xge_uld_link_up_f{}.  * @link_down: See xge_uld_link_down_f{}.  * @crit_err: See xge_uld_crit_err_f{}.  * @event: See xge_uld_event_f{}.  * @event_queued: See xge_uld_event_queued_f{}.  * @before_device_poll: See xge_uld_before_device_poll_f{}.  * @after_device_poll: See xge_uld_after_device_poll_f{}.  * @sched_timer: See xge_uld_sched_timer_cb_f{}.  * @xpak_alarm_log: TODO  *  * Upper layer driver slow-path (per-driver) callbacks.  * Implemented by ULD and provided to HAL via  * xge_hal_driver_initialize().  * Note that these callbacks are not mandatory: HAL will not invoke  * a callback if NULL is specified.  *  * Note that in addition to those, there are curently 2 per-channel callbacks  * (completion and abort) specified at channel open time  * via xge_hal_channel_open().  *  * See also: xge_hal_driver_initialize().  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_hal_uld_cbs_t
block|{
name|xge_uld_link_up_f
name|link_up
decl_stmt|;
name|xge_uld_link_down_f
name|link_down
decl_stmt|;
name|xge_uld_crit_err_f
name|crit_err
decl_stmt|;
name|xge_uld_event_f
name|event
decl_stmt|;
name|xge_uld_event_queued_f
name|event_queued
decl_stmt|;
name|xge_uld_before_device_poll_f
name|before_device_poll
decl_stmt|;
name|xge_uld_after_device_poll_f
name|after_device_poll
decl_stmt|;
name|xge_uld_sched_timer_cb_f
name|sched_timer
decl_stmt|;
name|xge_uld_xpak_alarm_log_f
name|xpak_alarm_log
decl_stmt|;
block|}
name|xge_hal_uld_cbs_t
typedef|;
end_typedef

begin_comment
comment|/**  * struct xge_hal_driver_t - Represents HAL object.  * @config: HAL configuration.  * @devices: List of all PCI-enumerated Xframe devices in the system.  * A single xge_hal_driver_t instance contains zero or more  * Xframe devices.  * @devices_lock: Lock to protect %devices when inserting/removing.  * @is_initialized: True if HAL is initialized; false otherwise.  * @uld_callbacks: Upper-layer driver callbacks. See xge_hal_uld_cbs_t{}.  * @debug_module_mask: 32bit mask that defines which components of the  * driver are to be traced. The trace-able components are:  *	XGE_COMPONENT_HAL_CONFIG		0x1  *	XGE_COMPONENT_HAL_FIFO			0x2  *	XGE_COMPONENT_HAL_RING			0x4  *	XGE_COMPONENT_HAL_CHANNEL		0x8  *	XGE_COMPONENT_HAL_DEVICE		0x10  *	XGE_COMPONENT_HAL_MM			0x20  *	XGE_COMPONENT_HAL_QUEUE			0x40  *	XGE_COMPONENT_HAL_STATS			0x100  *	XGE_COMPONENT_OSDEP			0x1000  *	XGE_COMPONENT_LL			0x2000  *	XGE_COMPONENT_TOE			0x4000  *	XGE_COMPONENT_RDMA			0x8000  *	XGE_COMPONENT_ALL			0xffffffff  * The @debug_module_mask allows to switch off and on tracing at runtime.  * In addition, the traces for the same trace-able components can be  * compiled out, based on the same mask provided via Makefile.  * @debug_level: See xge_debug_level_e{}.  *  * HAL (driver) object. There is a single instance of this structure per HAL.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_hal_driver_t
block|{
name|xge_hal_driver_config_t
name|config
decl_stmt|;
name|int
name|is_initialized
decl_stmt|;
name|xge_hal_uld_cbs_t
name|uld_callbacks
decl_stmt|;
name|u32
name|debug_module_mask
decl_stmt|;
name|int
name|debug_level
decl_stmt|;
block|}
name|xge_hal_driver_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|xge_hal_driver_t
modifier|*
name|g_xge_hal_driver
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|xge_hal_driver_is_initialized
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g_xge_hal_driver
operator|->
name|is_initialized
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|xge_hal_driver_debug_module_mask
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g_xge_hal_driver
operator|->
name|debug_module_mask
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_hal_driver_debug_module_mask_set
parameter_list|(
name|u32
name|new_mask
parameter_list|)
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|XGE_DEBUG_TRACE_MASK
argument_list|)
operator|&&
name|XGE_DEBUG_TRACE_MASK
operator|>
literal|0
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|XGE_DEBUG_ERR_MASK
argument_list|)
operator|&&
name|XGE_DEBUG_ERR_MASK
operator|>
literal|0
operator|)
name|g_xge_hal_driver
operator|->
name|debug_module_mask
operator|=
name|new_mask
expr_stmt|;
name|g_module_mask
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|g_xge_hal_driver
operator|->
name|debug_module_mask
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|xge_hal_driver_debug_level
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|g_xge_hal_driver
operator|->
name|debug_level
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|xge_hal_driver_debug_level_set
parameter_list|(
name|int
name|new_level
parameter_list|)
block|{
if|#
directive|if
operator|(
name|defined
argument_list|(
name|XGE_DEBUG_TRACE_MASK
argument_list|)
operator|&&
name|XGE_DEBUG_TRACE_MASK
operator|>
literal|0
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|XGE_DEBUG_ERR_MASK
argument_list|)
operator|&&
name|XGE_DEBUG_ERR_MASK
operator|>
literal|0
operator|)
name|g_xge_hal_driver
operator|->
name|debug_level
operator|=
name|new_level
expr_stmt|;
name|g_level
operator|=
operator|&
name|g_xge_hal_driver
operator|->
name|debug_level
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function_decl
name|xge_hal_status_e
name|xge_hal_driver_initialize
parameter_list|(
name|xge_hal_driver_config_t
modifier|*
name|config
parameter_list|,
name|xge_hal_uld_cbs_t
modifier|*
name|uld_callbacks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_hal_driver_terminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_TRACE_INTO_CIRCULAR_ARR
end_ifdef

begin_function_decl
name|void
name|xge_hal_driver_tracebuf_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_hal_status_e
name|xge_hal_driver_tracebuf_read
parameter_list|(
name|int
name|bufsize
parameter_list|,
name|char
modifier|*
name|retbuf
parameter_list|,
name|int
modifier|*
name|retsize
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_hal_driver_tracebuf_dump
parameter_list|()
end_define

begin_define
define|#
directive|define
name|xge_hal_driver_tracebuf_read
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(0);
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
comment|/* XGE_HAL_DRIVER_H */
end_comment

end_unit

