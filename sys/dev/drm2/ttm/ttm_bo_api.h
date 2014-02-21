begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright (c) 2006-2009 VMware, Inc., Palo Alto, CA., USA  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * Authors: Thomas Hellstrom<thellstrom-at-vmware-dot-com>  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTM_BO_API_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTM_BO_API_H_
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_struct_decl
struct_decl|struct
name|ttm_bo_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|drm_mm_node
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct ttm_placement  *  * @fpfn:		first valid page frame number to put the object  * @lpfn:		last valid page frame number to put the object  * @num_placement:	number of preferred placements  * @placement:		preferred placements  * @num_busy_placement:	number of preferred placements when need to evict buffer  * @busy_placement:	preferred placements when need to evict buffer  *  * Structure indicating the placement you request for an object.  */
end_comment

begin_struct
struct|struct
name|ttm_placement
block|{
name|unsigned
name|fpfn
decl_stmt|;
name|unsigned
name|lpfn
decl_stmt|;
name|unsigned
name|num_placement
decl_stmt|;
specifier|const
name|uint32_t
modifier|*
name|placement
decl_stmt|;
name|unsigned
name|num_busy_placement
decl_stmt|;
specifier|const
name|uint32_t
modifier|*
name|busy_placement
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct ttm_bus_placement  *  * @addr:		mapped virtual address  * @base:		bus base address  * @is_iomem:		is this io memory ?  * @size:		size in byte  * @offset:		offset from the base address  * @io_reserved_vm:     The VM system has a refcount in @io_reserved_count  * @io_reserved_count:  Refcounting the numbers of callers to ttm_mem_io_reserve  *  * Structure indicating the bus placement of an object.  */
end_comment

begin_struct
struct|struct
name|ttm_bus_placement
block|{
name|void
modifier|*
name|addr
decl_stmt|;
name|unsigned
name|long
name|base
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|unsigned
name|long
name|offset
decl_stmt|;
name|bool
name|is_iomem
decl_stmt|;
name|bool
name|io_reserved_vm
decl_stmt|;
name|uint64_t
name|io_reserved_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct ttm_mem_reg  *  * @mm_node: Memory manager node.  * @size: Requested size of memory region.  * @num_pages: Actual size of memory region in pages.  * @page_alignment: Page alignment.  * @placement: Placement flags.  * @bus: Placement on io bus accessible to the CPU  *  * Structure indicating the placement and space resources used by a  * buffer object.  */
end_comment

begin_struct
struct|struct
name|ttm_mem_reg
block|{
name|void
modifier|*
name|mm_node
decl_stmt|;
name|unsigned
name|long
name|start
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|unsigned
name|long
name|num_pages
decl_stmt|;
name|uint32_t
name|page_alignment
decl_stmt|;
name|uint32_t
name|mem_type
decl_stmt|;
name|uint32_t
name|placement
decl_stmt|;
name|struct
name|ttm_bus_placement
name|bus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * enum ttm_bo_type  *  * @ttm_bo_type_device:	These are 'normal' buffers that can  * be mmapped by user space. Each of these bos occupy a slot in the  * device address space, that can be used for normal vm operations.  *  * @ttm_bo_type_kernel: These buffers are like ttm_bo_type_device buffers,  * but they cannot be accessed from user-space. For kernel-only use.  *  * @ttm_bo_type_sg: Buffer made from dmabuf sg table shared with another  * driver.  */
end_comment

begin_enum
enum|enum
name|ttm_bo_type
block|{
name|ttm_bo_type_device
block|,
name|ttm_bo_type_kernel
block|,
name|ttm_bo_type_sg
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ttm_tt
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * struct ttm_buffer_object  *  * @bdev: Pointer to the buffer object device structure.  * @type: The bo type.  * @destroy: Destruction function. If NULL, kfree is used.  * @num_pages: Actual number of pages.  * @addr_space_offset: Address space offset.  * @acc_size: Accounted size for this object.  * @kref: Reference count of this buffer object. When this refcount reaches  * zero, the object is put on the delayed delete list.  * @list_kref: List reference count of this buffer object. This member is  * used to avoid destruction while the buffer object is still on a list.  * Lru lists may keep one refcount, the delayed delete list, and kref != 0  * keeps one refcount. When this refcount reaches zero,  * the object is destroyed.  * @event_queue: Queue for processes waiting on buffer object status change.  * @mem: structure describing current placement.  * @persistent_swap_storage: Usually the swap storage is deleted for buffers  * pinned in physical memory. If this behaviour is not desired, this member  * holds a pointer to a persistent shmem object.  * @ttm: TTM structure holding system pages.  * @evicted: Whether the object was evicted without user-space knowing.  * @cpu_writes: For synchronization. Number of cpu writers.  * @lru: List head for the lru list.  * @ddestroy: List head for the delayed destroy list.  * @swap: List head for swap LRU list.  * @val_seq: Sequence of the validation holding the @reserved lock.  * Used to avoid starvation when many processes compete to validate the  * buffer. This member is protected by the bo_device::lru_lock.  * @seq_valid: The value of @val_seq is valid. This value is protected by  * the bo_device::lru_lock.  * @reserved: Deadlock-free lock used for synchronization state transitions.  * @sync_obj: Pointer to a synchronization object.  * @priv_flags: Flags describing buffer object internal state.  * @vm_rb: Rb node for the vm rb tree.  * @vm_node: Address space manager node.  * @offset: The current GPU offset, which can have different meanings  * depending on the memory type. For SYSTEM type memory, it should be 0.  * @cur_placement: Hint of current placement.  *  * Base class for TTM buffer object, that deals with data placement and CPU  * mappings. GPU mappings are really up to the driver, but for simpler GPUs  * the driver can usually use the placement offset @offset directly as the  * GPU virtual address. For drivers implementing multiple  * GPU memory manager contexts, the driver should manage the address space  * in these contexts separately and use these objects to get the correct  * placement and caching for these GPU maps. This makes it possible to use  * these objects for even quite elaborate memory management schemes.  * The destroy member, the API visibility of this object makes it possible  * to derive driver specific types.  */
end_comment

begin_struct
struct|struct
name|ttm_buffer_object
block|{
comment|/** 	 * Members constant at init. 	 */
name|struct
name|ttm_bo_global
modifier|*
name|glob
decl_stmt|;
name|struct
name|ttm_bo_device
modifier|*
name|bdev
decl_stmt|;
name|enum
name|ttm_bo_type
name|type
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|long
name|num_pages
decl_stmt|;
name|uint64_t
name|addr_space_offset
decl_stmt|;
name|size_t
name|acc_size
decl_stmt|;
comment|/** 	* Members not needing protection. 	*/
name|u_int
name|kref
decl_stmt|;
name|u_int
name|list_kref
decl_stmt|;
comment|/* wait_queue_head_t event_queue; */
comment|/** 	 * Members protected by the bo::reserved lock. 	 */
name|struct
name|ttm_mem_reg
name|mem
decl_stmt|;
name|struct
name|vm_object
modifier|*
name|persistent_swap_storage
decl_stmt|;
name|struct
name|ttm_tt
modifier|*
name|ttm
decl_stmt|;
name|bool
name|evicted
decl_stmt|;
comment|/** 	 * Members protected by the bo::reserved lock only when written to. 	 */
name|atomic_t
name|cpu_writers
decl_stmt|;
comment|/** 	 * Members protected by the bdev::lru_lock. 	 */
name|struct
name|list_head
name|lru
decl_stmt|;
name|struct
name|list_head
name|ddestroy
decl_stmt|;
name|struct
name|list_head
name|swap
decl_stmt|;
name|struct
name|list_head
name|io_reserve_lru
decl_stmt|;
name|uint32_t
name|val_seq
decl_stmt|;
name|bool
name|seq_valid
decl_stmt|;
comment|/** 	 * Members protected by the bdev::lru_lock 	 * only when written to. 	 */
name|atomic_t
name|reserved
decl_stmt|;
comment|/** 	 * Members protected by struct buffer_object_device::fence_lock 	 * In addition, setting sync_obj to anything else 	 * than NULL requires bo::reserved to be held. This allows for 	 * checking NULL while reserved but not holding the mentioned lock. 	 */
name|void
modifier|*
name|sync_obj
decl_stmt|;
name|unsigned
name|long
name|priv_flags
decl_stmt|;
comment|/** 	 * Members protected by the bdev::vm_lock 	 */
name|RB_ENTRY
argument_list|(
argument|ttm_buffer_object
argument_list|)
name|vm_rb
expr_stmt|;
name|struct
name|drm_mm_node
modifier|*
name|vm_node
decl_stmt|;
comment|/** 	 * Special members that are protected by the reserve lock 	 * and the bo::lock when written to. Can be read with 	 * either of these locks held. 	 */
name|unsigned
name|long
name|offset
decl_stmt|;
name|uint32_t
name|cur_placement
decl_stmt|;
name|struct
name|sg_table
modifier|*
name|sg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct ttm_bo_kmap_obj  *  * @virtual: The current kernel virtual address.  * @page: The page when kmap'ing a single page.  * @bo_kmap_type: Type of bo_kmap.  *  * Object describing a kernel mapping. Since a TTM bo may be located  * in various memory types with various caching policies, the  * mapping can either be an ioremap, a vmap, a kmap or part of a  * premapped region.  */
end_comment

begin_define
define|#
directive|define
name|TTM_BO_MAP_IOMEM_MASK
value|0x80
end_define

begin_struct
struct|struct
name|ttm_bo_kmap_obj
block|{
name|void
modifier|*
name|virtual
decl_stmt|;
name|struct
name|vm_page
modifier|*
name|page
decl_stmt|;
name|struct
name|sf_buf
modifier|*
name|sf
decl_stmt|;
name|int
name|num_pages
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
enum|enum
block|{
name|ttm_bo_map_iomap
init|=
literal|1
operator||
name|TTM_BO_MAP_IOMEM_MASK
block|,
name|ttm_bo_map_vmap
init|=
literal|2
block|,
name|ttm_bo_map_kmap
init|=
literal|3
block|,
name|ttm_bo_map_premapped
init|=
literal|4
operator||
name|TTM_BO_MAP_IOMEM_MASK
block|, 	}
name|bo_kmap_type
enum|;
name|struct
name|ttm_buffer_object
modifier|*
name|bo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * ttm_bo_reference - reference a struct ttm_buffer_object  *  * @bo: The buffer object.  *  * Returns a refcounted pointer to a buffer object.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|ttm_buffer_object
modifier|*
name|ttm_bo_reference
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
block|{
name|refcount_acquire
argument_list|(
operator|&
name|bo
operator|->
name|kref
argument_list|)
expr_stmt|;
return|return
name|bo
return|;
block|}
end_function

begin_comment
comment|/**  * ttm_bo_wait - wait for buffer idle.  *  * @bo:  The buffer object.  * @interruptible:  Use interruptible wait.  * @no_wait:  Return immediately if buffer is busy.  *  * This function must be called with the bo::mutex held, and makes  * sure any previous rendering to the buffer is completed.  * Note: It might be necessary to block validations before the  * wait by reserving the buffer.  * Returns -EBUSY if no_wait is true and the buffer is busy.  * Returns -ERESTARTSYS if interrupted by a signal.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_wait
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|bool
name|lazy
parameter_list|,
name|bool
name|interruptible
parameter_list|,
name|bool
name|no_wait
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_validate  *  * @bo: The buffer object.  * @placement: Proposed placement for the buffer object.  * @interruptible: Sleep interruptible if sleeping.  * @no_wait_gpu: Return immediately if the GPU is busy.  *  * Changes placement and caching policy of the buffer object  * according proposed placement.  * Returns  * -EINVAL on invalid proposed placement.  * -ENOMEM on out-of-memory condition.  * -EBUSY if no_wait is true and buffer busy.  * -ERESTARTSYS if interrupted by a signal.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_validate
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|struct
name|ttm_placement
modifier|*
name|placement
parameter_list|,
name|bool
name|interruptible
parameter_list|,
name|bool
name|no_wait_gpu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_unref  *  * @bo: The buffer object.  *  * Unreference and clear a pointer to a buffer object.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_unref
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_list_ref_sub  *  * @bo: The buffer object.  * @count: The number of references with which to decrease @bo::list_kref;  * @never_free: The refcount should not reach zero with this operation.  *  * Release @count lru list references to this buffer object.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_list_ref_sub
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|int
name|count
parameter_list|,
name|bool
name|never_free
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_add_to_lru  *  * @bo: The buffer object.  *  * Add this bo to the relevant mem type lru and, if it's backed by  * system pages (ttms) to the swap list.  * This function must be called with struct ttm_bo_global::lru_lock held, and  * is typically called immediately prior to unreserving a bo.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_add_to_lru
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_del_from_lru  *  * @bo: The buffer object.  *  * Remove this bo from all lru lists used to lookup and reserve an object.  * This function must be called with struct ttm_bo_global::lru_lock held,  * and is usually called just immediately after the bo has been reserved to  * avoid recursive reservation from lru lists.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_del_from_lru
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_lock_delayed_workqueue  *  * Prevent the delayed workqueue from running.  * Returns  * True if the workqueue was queued at the time  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_lock_delayed_workqueue
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_unlock_delayed_workqueue  *  * Allows the delayed workqueue to run.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_unlock_delayed_workqueue
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|int
name|resched
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_synccpu_write_grab  *  * @bo: The buffer object:  * @no_wait: Return immediately if buffer is busy.  *  * Synchronizes a buffer object for CPU RW access. This means  * command submission that affects the buffer will return -EBUSY  * until ttm_bo_synccpu_write_release is called.  *  * Returns  * -EBUSY if the buffer is busy and no_wait is true.  * -ERESTARTSYS if interrupted by a signal.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_synccpu_write_grab
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|bool
name|no_wait
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_synccpu_write_release:  *  * @bo : The buffer object.  *  * Releases a synccpu lock.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_synccpu_write_release
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_acc_size  *  * @bdev: Pointer to a ttm_bo_device struct.  * @bo_size: size of the buffer object in byte.  * @struct_size: size of the structure holding buffer object datas  *  * Returns size to account for a buffer object  */
end_comment

begin_function_decl
name|size_t
name|ttm_bo_acc_size
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|long
name|bo_size
parameter_list|,
name|unsigned
name|struct_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ttm_bo_dma_acc_size
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|long
name|bo_size
parameter_list|,
name|unsigned
name|struct_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_init  *  * @bdev: Pointer to a ttm_bo_device struct.  * @bo: Pointer to a ttm_buffer_object to be initialized.  * @size: Requested size of buffer object.  * @type: Requested type of buffer object.  * @flags: Initial placement flags.  * @page_alignment: Data alignment in pages.  * @interruptible: If needing to sleep to wait for GPU resources,  * sleep interruptible.  * @persistent_swap_storage: Usually the swap storage is deleted for buffers  * pinned in physical memory. If this behaviour is not desired, this member  * holds a pointer to a persistent shmem object. Typically, this would  * point to the shmem object backing a GEM object if TTM is used to back a  * GEM user interface.  * @acc_size: Accounted size for this object.  * @destroy: Destroy function. Use NULL for kfree().  *  * This function initializes a pre-allocated struct ttm_buffer_object.  * As this object may be part of a larger structure, this function,  * together with the @destroy function,  * enables driver-specific objects derived from a ttm_buffer_object.  * On successful return, the object kref and list_kref are set to 1.  * If a failure occurs, the function will call the @destroy function, or  * kfree() if @destroy is NULL. Thus, after a failure, dereferencing @bo is  * illegal and will likely cause memory corruption.  *  * Returns  * -ENOMEM: Out of memory.  * -EINVAL: Invalid placement flags.  * -ERESTARTSYS: Interrupted by signal while sleeping waiting for resources.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_init
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|enum
name|ttm_bo_type
name|type
parameter_list|,
name|struct
name|ttm_placement
modifier|*
name|placement
parameter_list|,
name|uint32_t
name|page_alignment
parameter_list|,
name|bool
name|interrubtible
parameter_list|,
name|struct
name|vm_object
modifier|*
name|persistent_swap_storage
parameter_list|,
name|size_t
name|acc_size
parameter_list|,
name|struct
name|sg_table
modifier|*
name|sg
parameter_list|,
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_synccpu_object_init  *  * @bdev: Pointer to a ttm_bo_device struct.  * @bo: Pointer to a ttm_buffer_object to be initialized.  * @size: Requested size of buffer object.  * @type: Requested type of buffer object.  * @flags: Initial placement flags.  * @page_alignment: Data alignment in pages.  * @interruptible: If needing to sleep while waiting for GPU resources,  * sleep interruptible.  * @persistent_swap_storage: Usually the swap storage is deleted for buffers  * pinned in physical memory. If this behaviour is not desired, this member  * holds a pointer to a persistent shmem object. Typically, this would  * point to the shmem object backing a GEM object if TTM is used to back a  * GEM user interface.  * @p_bo: On successful completion *p_bo points to the created object.  *  * This function allocates a ttm_buffer_object, and then calls ttm_bo_init  * on that object. The destroy function is set to kfree().  * Returns  * -ENOMEM: Out of memory.  * -EINVAL: Invalid placement flags.  * -ERESTARTSYS: Interrupted by signal while waiting for resources.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_create
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|enum
name|ttm_bo_type
name|type
parameter_list|,
name|struct
name|ttm_placement
modifier|*
name|placement
parameter_list|,
name|uint32_t
name|page_alignment
parameter_list|,
name|bool
name|interruptible
parameter_list|,
name|struct
name|vm_object
modifier|*
name|persistent_swap_storage
parameter_list|,
name|struct
name|ttm_buffer_object
modifier|*
modifier|*
name|p_bo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_check_placement  *  * @bo:		the buffer object.  * @placement:	placements  *  * Performs minimal validity checking on an intended change of  * placement flags.  * Returns  * -EINVAL: Intended change is invalid or not allowed.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_check_placement
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|struct
name|ttm_placement
modifier|*
name|placement
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_init_mm  *  * @bdev: Pointer to a ttm_bo_device struct.  * @mem_type: The memory type.  * @p_size: size managed area in pages.  *  * Initialize a manager for a given memory type.  * Note: if part of driver firstopen, it must be protected from a  * potentially racing lastclose.  * Returns:  * -EINVAL: invalid size or memory type.  * -ENOMEM: Not enough memory.  * May also return driver-specified errors.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_init_mm
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|type
parameter_list|,
name|unsigned
name|long
name|p_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_clean_mm  *  * @bdev: Pointer to a ttm_bo_device struct.  * @mem_type: The memory type.  *  * Take down a manager for a given memory type after first walking  * the LRU list to evict any buffers left alive.  *  * Normally, this function is part of lastclose() or unload(), and at that  * point there shouldn't be any buffers left created by user-space, since  * there should've been removed by the file descriptor release() method.  * However, before this function is run, make sure to signal all sync objects,  * and verify that the delayed delete queue is empty. The driver must also  * make sure that there are no NO_EVICT buffers present in this memory type  * when the call is made.  *  * If this function is part of a VT switch, the caller must make sure that  * there are no appications currently validating buffers before this  * function is called. The caller can do that by first taking the  * struct ttm_bo_device::ttm_lock in write mode.  *  * Returns:  * -EINVAL: invalid or uninitialized memory type.  * -EBUSY: There are still buffers left in this memory type.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_clean_mm
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|mem_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_evict_mm  *  * @bdev: Pointer to a ttm_bo_device struct.  * @mem_type: The memory type.  *  * Evicts all buffers on the lru list of the memory type.  * This is normally part of a VT switch or an  * out-of-memory-space-due-to-fragmentation handler.  * The caller must make sure that there are no other processes  * currently validating buffers, and can do that by taking the  * struct ttm_bo_device::ttm_lock in write mode.  *  * Returns:  * -EINVAL: Invalid or uninitialized memory type.  * -ERESTARTSYS: The call was interrupted by a signal while waiting to  * evict a buffer.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_evict_mm
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|unsigned
name|mem_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_kmap_obj_virtual  *  * @map: A struct ttm_bo_kmap_obj returned from ttm_bo_kmap.  * @is_iomem: Pointer to an integer that on return indicates 1 if the  * virtual map is io memory, 0 if normal memory.  *  * Returns the virtual address of a buffer object area mapped by ttm_bo_kmap.  * If *is_iomem is 1 on return, the virtual address points to an io memory area,  * that should strictly be accessed by the iowriteXX() and similar functions.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ttm_kmap_obj_virtual
parameter_list|(
name|struct
name|ttm_bo_kmap_obj
modifier|*
name|map
parameter_list|,
name|bool
modifier|*
name|is_iomem
parameter_list|)
block|{
operator|*
name|is_iomem
operator|=
operator|!
operator|!
operator|(
name|map
operator|->
name|bo_kmap_type
operator|&
name|TTM_BO_MAP_IOMEM_MASK
operator|)
expr_stmt|;
return|return
name|map
operator|->
name|virtual
return|;
block|}
end_function

begin_comment
comment|/**  * ttm_bo_kmap  *  * @bo: The buffer object.  * @start_page: The first page to map.  * @num_pages: Number of pages to map.  * @map: pointer to a struct ttm_bo_kmap_obj representing the map.  *  * Sets up a kernel virtual mapping, using ioremap, vmap or kmap to the  * data in the buffer object. The ttm_kmap_obj_virtual function can then be  * used to obtain a virtual address to the data.  *  * Returns  * -ENOMEM: Out of memory.  * -EINVAL: Invalid range.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_bo_kmap
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|,
name|unsigned
name|long
name|start_page
parameter_list|,
name|unsigned
name|long
name|num_pages
parameter_list|,
name|struct
name|ttm_bo_kmap_obj
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_kunmap  *  * @map: Object describing the map to unmap.  *  * Unmaps a kernel map set up by ttm_bo_kmap.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_bo_kunmap
parameter_list|(
name|struct
name|ttm_bo_kmap_obj
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_fbdev_mmap - mmap fbdev memory backed by a ttm buffer object.  *  * @vma:       vma as input from the fbdev mmap method.  * @bo:        The bo backing the address space. The address space will  * have the same size as the bo, and start at offset 0.  *  * This function is intended to be called by the fbdev mmap method  * if the fbdev address space is to be backed by a bo.  */
end_comment

begin_comment
comment|/* XXXKIB extern int ttm_fbdev_mmap(struct vm_area_struct *vma, 			  struct ttm_buffer_object *bo); */
end_comment

begin_comment
comment|/**  * ttm_bo_mmap - mmap out of the ttm device address space.  *  * @filp:      filp as input from the mmap method.  * @vma:       vma as input from the mmap method.  * @bdev:      Pointer to the ttm_bo_device with the address space manager.  *  * This function is intended to be called by the device mmap method.  * if the device address space is to be backed by the bo manager.  */
end_comment

begin_comment
comment|/* XXXKIB extern int ttm_bo_mmap(struct file *filp, struct vm_area_struct *vma, 		       struct ttm_bo_device *bdev); */
end_comment

begin_comment
comment|/**  * ttm_bo_io  *  * @bdev:      Pointer to the struct ttm_bo_device.  * @filp:      Pointer to the struct file attempting to read / write.  * @wbuf:      User-space pointer to address of buffer to write. NULL on read.  * @rbuf:      User-space pointer to address of buffer to read into.  * Null on write.  * @count:     Number of bytes to read / write.  * @f_pos:     Pointer to current file position.  * @write:     1 for read, 0 for write.  *  * This function implements read / write into ttm buffer objects, and is  * intended to  * be called from the fops::read and fops::write method.  * Returns:  * See man (2) write, man(2) read. In particular,  * the function may return -ERESTARTSYS if  * interrupted by a signal.  */
end_comment

begin_function_decl
specifier|extern
name|ssize_t
name|ttm_bo_io
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|struct
name|file
modifier|*
name|filp
parameter_list|,
specifier|const
name|char
modifier|*
name|wbuf
parameter_list|,
name|char
modifier|*
name|rbuf
parameter_list|,
name|size_t
name|count
parameter_list|,
name|off_t
modifier|*
name|f_pos
parameter_list|,
name|bool
name|write
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttm_bo_swapout_all
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_bo_is_reserved - return an indication if a ttm buffer object is reserved  *  * @bo:     The buffer object to check.  *  * This function returns an indication if a bo is reserved or not, and should  * only be used to print an error when it is not from incorrect api usage, since  * there's no guarantee that it is the caller that is holding the reservation.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ttm_bo_is_reserved
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
block|{
return|return
name|atomic_read
argument_list|(
operator|&
name|bo
operator|->
name|reserved
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

