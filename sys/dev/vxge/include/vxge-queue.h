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
name|VXGE_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|VXGE_QUEUE_H
end_define

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_define
define|#
directive|define
name|VXGE_QUEUE_BUF_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|VXGE_DEFAULT_EVENT_MAX_DATA_SIZE
value|16
end_define

begin_comment
comment|/*  * enum vxge_queue_status_e - Enumerates return codes of the vxge_queue  * manipulation APIs.  * @VXGE_QUEUE_IS_FULL: Queue is full, need to grow.  * @VXGE_QUEUE_IS_EMPTY: Queue is empty.  * @VXGE_QUEUE_OUT_OF_MEMORY: Out of memory.  * @VXGE_QUEUE_NOT_ENOUGH_SPACE: Exceeded specified event size,  * see vxge_queue_consume().  * @VXGE_QUEUE_OK: Neither one of the codes listed above.  *  * Enumerates return codes of vxge_queue_consume()  * and vxge_queue_produce() APIs.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vxge_queue_status_e
block|{
name|VXGE_QUEUE_OK
init|=
literal|0
block|,
name|VXGE_QUEUE_IS_FULL
init|=
literal|1
block|,
name|VXGE_QUEUE_IS_EMPTY
init|=
literal|2
block|,
name|VXGE_QUEUE_OUT_OF_MEMORY
init|=
literal|3
block|,
name|VXGE_QUEUE_NOT_ENOUGH_SPACE
init|=
literal|4
block|}
name|vxge_queue_status_e
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|vxge_queue_h
typedef|;
end_typedef

begin_comment
comment|/*  * struct vxge_queue_item_t - Queue item.  * @item: List item. Note that the queue is "built" on top of  *	the bi-directional linked list.  * @event_type: Event type. Includes (but is not restricted to)  * one of the vxge_hal_event_e {} enumerated types.  * @data_size: Size of the enqueued user data. Note that vxge_queue_t  * items are allowed to have variable sizes.  * @is_critical: For critical events, e.g. ECC.  * @context: Opaque (void *) "context", for instance event producer object.  *  * Item of the vxge_queue_t {}. The queue is protected  * in terms of multi-threaded concurrent access.  * See also: vxge_queue_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_queue_item_t
block|{
name|vxge_list_t
name|item
decl_stmt|;
name|vxge_hal_event_e
name|event_type
decl_stmt|;
name|u32
name|data_size
decl_stmt|;
name|u32
name|is_critical
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
block|}
name|vxge_queue_item_t
typedef|;
end_typedef

begin_comment
comment|/*  * function vxge_queued_f - Item-enqueued callback.  * @data: Per-queue context independent of the event. E.g., device handle.  * @event_type: HAL or ULD-defined event type. Note that HAL own  *	events are enumerated by vxge_hal_event_e {}.  *  * Per-queue optional callback. If not NULL, called by HAL each  * time an event gets added to the queue.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vxge_queued_f
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|u32
name|event_type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * struct vxge_queue_t - Protected dynamic queue of variable-size items.  * @start_ptr: Points to the start of the queue.  * @end_ptr: Points to the end of the queue.  * @head_ptr: Points to the head of the queue. It gets changed during queue  *	   produce/consume operations.  * @tail_ptr: Points to the tail of the queue. It gets changed during queue  *	   produce/consume operations.  * @lock: Lock for queue operations(synchronization purpose).  * @pages_initial:Number of pages to be initially allocated at the time  *		 of queue creation.  * @pages_max: Max number of pages that can be allocated in the queue.  * @pages_current: Number of pages currently allocated  * @list_head: Points to the list of queue elements that are produced, but yet  *		to be consumed.  * @hldev: HAL device handle  * @pdev: PCI device handle  * @irqh: PCI device IRQ handle.  * @queued_func: Optional callback function to be called each time a new  * item is added to the queue.  * @queued_data: Arguments to the callback function.  * @has_critical_event: Non-zero, if the queue contains a critical event,  * see vxge_hal_event_e {}.  * Protected dynamically growing queue. The queue is used to support multiple  * producer/consumer type scenarios. The queue is a strict FIFO: first come  * first served.  * Queue users may "produce" (see vxge_queue_produce()) and "consume"  * (see vxge_queue_consume()) items (a.k.a. events) variable sizes.  * See also: vxge_queue_item_t {}.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vxge_queue_t
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
name|u32
name|pages_initial
decl_stmt|;
name|u32
name|pages_max
decl_stmt|;
name|u32
name|pages_current
decl_stmt|;
name|vxge_list_t
name|list_head
decl_stmt|;
name|vxge_hal_device_h
name|hldev
decl_stmt|;
name|pci_dev_h
name|pdev
decl_stmt|;
name|pci_irq_h
name|irqh
decl_stmt|;
name|vxge_queued_f
name|queued_func
decl_stmt|;
name|void
modifier|*
name|queued_data
decl_stmt|;
name|u32
name|has_critical_event
decl_stmt|;
block|}
name|vxge_queue_t
typedef|;
end_typedef

begin_comment
comment|/* ========================== PUBLIC API ================================= */
end_comment

begin_comment
comment|/*  * vxge_queue_create - Create protected first-in-first-out queue.  * @devh: HAL device handle.  * @pages_initial: Number of pages to be initially allocated at the  * time of queue creation.  * @pages_max: Max number of pages that can be allocated in the queue.  * @queued_func: Optional callback function to be called each time a new item is  * added to the queue.  * @queued_data: Argument to the callback function.  *  * Create protected (fifo) queue.  *  * Returns: Pointer to vxge_queue_t structure,  * NULL - on failure.  *  * See also: vxge_queue_item_t {}, vxge_queue_destroy().  */
end_comment

begin_function_decl
name|vxge_queue_h
name|vxge_queue_create
parameter_list|(
name|vxge_hal_device_h
name|devh
parameter_list|,
name|u32
name|pages_initial
parameter_list|,
name|u32
name|pages_max
parameter_list|,
name|vxge_queued_f
name|queued_func
parameter_list|,
name|void
modifier|*
name|queued_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_destroy - Destroy vxge_queue_t object.  * @queueh: Queue handle.  *  * Destroy the specified vxge_queue_t object.  *  * See also: vxge_queue_item_t {}, vxge_queue_create().  */
end_comment

begin_function_decl
name|void
name|vxge_queue_destroy
parameter_list|(
name|vxge_queue_h
name|queueh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_item_data - Get item's data.  * @item: Queue item.  *  * Returns:  item data(variable size). Note that vxge_queue_t  * contains items comprized of a fixed vxge_queue_item_t "header"  * and a variable size data. This function returns the variable  * user-defined portion of the queue item.  */
end_comment

begin_function_decl
name|void
modifier|*
name|vxge_queue_item_data
parameter_list|(
name|vxge_queue_item_t
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_produce - Enqueue an item (see vxge_queue_item_t {})  *			 into the specified queue.  * @queueh: Queue handle.  * @event_type: Event type. One of the enumerated event types  *		 that both consumer and producer "understand".  *		 For an example, please refer to vxge_hal_event_e.  * @context: Opaque (void *) "context", for instance event producer object.  * @is_critical: For critical event, e.g. ECC.  * @data_size: Size of the @data.  * @data: User data of variable @data_size that is _copied_ into  *	the new queue item (see vxge_queue_item_t {}). Upon return  *	from the call the @data memory can be re-used or released.  *  * Enqueue a new item.  *  * Returns: VXGE_QUEUE_OK - success.  * VXGE_QUEUE_IS_FULL - Queue is full.  * VXGE_QUEUE_OUT_OF_MEMORY - Memory allocation failed.  *  * See also: vxge_queue_item_t {}, vxge_queue_consume().  */
end_comment

begin_function_decl
name|vxge_queue_status_e
name|vxge_queue_produce
parameter_list|(
name|vxge_queue_h
name|queueh
parameter_list|,
name|u32
name|event_type
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
name|u32
name|is_critical
parameter_list|,
specifier|const
name|u32
name|data_size
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_produce_context - Enqueue context.  * @queueh: Queue handle.  * @event_type: Event type. One of the enumerated event types  *		 that both consumer and producer "understand".  *		 For an example, please refer to vxge_hal_event_e.  * @context: Opaque (void *) "context", for instance event producer object.  *  * Enqueue Context.  *  * Returns: VXGE_QUEUE_OK - success.  * VXGE_QUEUE_IS_EMPTY - Queue is empty.  * VXGE_QUEUE_NOT_ENOUGH_SPACE - Requested item size(@data_max_size)  * is too small to accommodate an item from the queue.  *  * See also: vxge_queue_item_t {}, vxge_queue_produce().  */
end_comment

begin_function
specifier|static
specifier|inline
name|vxge_queue_status_e
comment|/* LINTED */
name|vxge_queue_produce_context
parameter_list|(
name|vxge_queue_h
name|queueh
parameter_list|,
name|u32
name|event_type
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
block|{
return|return
operator|(
name|vxge_queue_produce
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
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * vxge_queue_consume - Dequeue an item from the specified queue.  * @queueh: Queue handle.  * @data_max_size: Maximum expected size of the item.  * @item: Memory area into which the item is _copied_ upon return  *	from the function.  *  * Dequeue an item from the queue. The caller is required to provide  * enough space for the item.  *  * Returns: VXGE_QUEUE_OK - success.  * VXGE_QUEUE_IS_EMPTY - Queue is empty.  * VXGE_QUEUE_NOT_ENOUGH_SPACE - Requested item size(@data_max_size)  * is too small to accommodate an item from the queue.  *  * See also: vxge_queue_item_t {}, vxge_queue_produce().  */
end_comment

begin_function_decl
name|vxge_queue_status_e
name|vxge_queue_consume
parameter_list|(
name|vxge_queue_h
name|queueh
parameter_list|,
name|u32
name|data_max_size
parameter_list|,
name|vxge_queue_item_t
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_flush - Flush, or empty, the queue.  * @queueh: Queue handle.  *  * Flush the queue, i.e. make it empty by consuming all events  * without invoking the event processing logic (callbacks, etc.)  */
end_comment

begin_function_decl
name|void
name|vxge_queue_flush
parameter_list|(
name|vxge_queue_h
name|queueh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_io_queue_grow - Dynamically increases the size of the queue.  * @queueh: Queue handle.  *  * This function is called in the case of no slot avaialble in the queue  * to accommodate the newly received event.  * Note that queue cannot grow beyond the max size specified for the  * queue.  *  * Returns VXGE_QUEUE_OK: On success.  * VXGE_QUEUE_OUT_OF_MEMORY : No memory is available.  */
end_comment

begin_function_decl
name|vxge_queue_status_e
name|vxge_io_queue_grow
parameter_list|(
name|vxge_queue_h
name|qh
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * vxge_queue_get_reset_critical - Check for critical events in the queue,  * @queueh: Queue handle.  *  * Check for critical event(s) in the queue, and reset the  * "has-critical-event" flag upon return.  * Returns: 1 - if the queue contains atleast one critical event.  * 0 - If there are no critical events in the queue.  */
end_comment

begin_function_decl
name|u32
name|vxge_queue_get_reset_critical
parameter_list|(
name|vxge_queue_h
name|queueh
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
comment|/* VXGE_QUEUE_H */
end_comment

end_unit

