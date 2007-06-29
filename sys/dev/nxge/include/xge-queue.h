begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xge-queue.h  *  *  Description:  serialized event queue  *  *  Created:      7 June 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_QUEUE_H
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-os-pal.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-defs.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xge-list.h>
end_include

begin_include
include|#
directive|include
file|<dev/nxge/include/xgehal-event.h>
end_include

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_define
define|#
directive|define
name|XGE_QUEUE_BUF_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|XGE_DEFAULT_EVENT_MAX_DATA_SIZE
value|16
end_define

begin_comment
comment|/**  * enum xge_queue_status_e - Enumerates return codes of the xge_queue  * manipulation APIs.  * @XGE_QUEUE_IS_FULL: Queue is full, need to grow.  * @XGE_QUEUE_IS_EMPTY: Queue is empty.  * @XGE_QUEUE_OUT_OF_MEMORY: Out of memory.  * @XGE_QUEUE_NOT_ENOUGH_SPACE: Exceeded specified event size,  * see xge_queue_consume().  * @XGE_QUEUE_OK: Neither one of the codes listed above.  *  * Enumerates return codes of xge_queue_consume()  * and xge_queue_produce() APIs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|xge_queue_status_e
block|{
name|XGE_QUEUE_OK
init|=
literal|0
block|,
name|XGE_QUEUE_IS_FULL
init|=
literal|1
block|,
name|XGE_QUEUE_IS_EMPTY
init|=
literal|2
block|,
name|XGE_QUEUE_OUT_OF_MEMORY
init|=
literal|3
block|,
name|XGE_QUEUE_NOT_ENOUGH_SPACE
init|=
literal|4
block|}
name|xge_queue_status_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|xge_queue_h
typedef|;
end_typedef

begin_comment
comment|/**  * struct xge_queue_item_t - Queue item.  * @item: List item. Note that the queue is "built" on top of  *        the bi-directional linked list.  * @event_type: Event type. Includes (but is not restricted to)  * one of the xge_hal_event_e{} enumerated types.  * @data_size: Size of the enqueued user data. Note that xge_queue_t  * items are allowed to have variable sizes.  * @is_critical: For critical events, e.g. ECC.  * @context: Opaque (void*) "context", for instance event producer object.  *  * Item of the xge_queue_t{}. The queue is protected  * in terms of multi-threaded concurrent access.  * See also: xge_queue_t{}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_queue_item_t
block|{
name|xge_list_t
name|item
decl_stmt|;
name|xge_hal_event_e
name|event_type
decl_stmt|;
name|int
name|data_size
decl_stmt|;
name|int
name|is_critical
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|xge_queue_item_t
typedef|;
end_typedef

begin_comment
comment|/**  * function xge_queued_f - Item-enqueued callback.  * @data: Per-queue context independent of the event. E.g., device handle.  * @event_type: HAL or ULD-defined event type. Note that HAL own  *        events are enumerated by xge_hal_event_e{}.  *  * Per-queue optional callback. If not NULL, called by HAL each  * time an event gets added to the queue.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xge_queued_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|int
name|event_type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * struct xge_queue_t - Protected dynamic queue of variable-size items.  * @start_ptr: Points to the start of the queue.  * @end_ptr: Points to the end of the queue.  * @head_ptr: Points to the head of the queue. It gets changed during queue  *            produce/consume operations.  * @tail_ptr: Points to the tail of the queue. It gets changed during queue  *            produce/consume operations.  * @lock: Lock for queue operations(syncronization purpose).  * @pages_initial:Number of pages to be initially allocated at the time  *		  of queue creation.  * @pages_max: Max number of pages that can be allocated in the queue.  * @pages_current: Number of pages currently allocated  * @list_head: Points to the list of queue elements that are produced, but yet  *             to be consumed.  * @signal_callback: (TODO)  * @pdev: PCI device handle  * @irqh: PCI device IRQ handle.  * @queued_func: Optional callback function to be called each time a new  * item is added to the queue.  * @queued_data: Arguments to the callback function.  * @has_critical_event: Non-zero, if the queue contains a critical event,  * see xge_hal_event_e{}.  * Protected dynamically growing queue. The queue is used to support multiple  * producer/consumer type scenarios. The queue is a strict FIFO: first come  * first served.  * Queue users may "produce" (see xge_queue_produce()) and "consume"  * (see xge_queue_consume()) items (a.k.a. events) variable sizes.  * See also: xge_queue_item_t{}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_queue_t
block|{
name|void
modifier|*
name|start_ptr
decl_stmt|;
name|void
modifier|*
name|end_ptr
decl_stmt|;
name|void
modifier|*
name|head_ptr
decl_stmt|;
name|void
modifier|*
name|tail_ptr
decl_stmt|;
name|spinlock_t
name|lock
decl_stmt|;
name|unsigned
name|int
name|pages_initial
decl_stmt|;
name|unsigned
name|int
name|pages_max
decl_stmt|;
name|unsigned
name|int
name|pages_current
decl_stmt|;
name|xge_list_t
name|list_head
decl_stmt|;
name|pci_dev_h
name|pdev
decl_stmt|;
name|pci_irq_h
name|irqh
decl_stmt|;
name|xge_queued_f
name|queued_func
decl_stmt|;
name|void
modifier|*
name|queued_data
decl_stmt|;
name|int
name|has_critical_event
decl_stmt|;
block|}
name|xge_queue_t
typedef|;
end_typedef

begin_comment
comment|/* ========================== PUBLIC API ================================= */
end_comment

begin_function_decl
name|xge_queue_h
name|xge_queue_create
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_irq_h
name|irqh
parameter_list|,
name|int
name|pages_initial
parameter_list|,
name|int
name|pages_max
parameter_list|,
name|xge_queued_f
name|queued_func
parameter_list|,
name|void
modifier|*
name|queued_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_queue_destroy
parameter_list|(
name|xge_queue_h
name|queueh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xge_queue_item_data
parameter_list|(
name|xge_queue_item_t
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xge_queue_status_e
name|xge_queue_produce
parameter_list|(
name|xge_queue_h
name|queueh
parameter_list|,
name|int
name|event_type
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|int
name|is_critical
parameter_list|,
specifier|const
name|int
name|data_size
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|xge_queue_status_e
name|xge_queue_produce_context
parameter_list|(
name|xge_queue_h
name|queueh
parameter_list|,
name|int
name|event_type
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
return|return
name|xge_queue_produce
argument_list|(
name|queueh
argument_list|,
name|event_type
argument_list|,
name|context
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|xge_queue_status_e
name|xge_queue_consume
parameter_list|(
name|xge_queue_h
name|queueh
parameter_list|,
name|int
name|data_max_size
parameter_list|,
name|xge_queue_item_t
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xge_queue_flush
parameter_list|(
name|xge_queue_h
name|queueh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ========================== PRIVATE API ================================= */
end_comment

begin_function_decl
name|xge_queue_status_e
name|__io_queue_grow
parameter_list|(
name|xge_queue_h
name|qh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__queue_get_reset_critical
parameter_list|(
name|xge_queue_h
name|qh
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_QUEUE_H */
end_comment

end_unit

