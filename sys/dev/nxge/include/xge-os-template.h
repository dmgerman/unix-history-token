begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xge-os-template.h  *  *  Description:  Template for creating platform-dependent "glue" code.  *  *  Created:      6 May 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_OS_TEMPLATE_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_OS_TEMPLATE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TEMPLATE
end_ifndef

begin_error
error|#
directive|error
literal|"should not be compiled for platforms other than TEMPLATE..."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------------- includes and defines ------------------------- */
end_comment

begin_comment
comment|/*  * Note:  *  *     - on some operating systems like Linux& FreeBSD, there is a macro  *       by using which it is possible to determine endiennes automatically  */
end_comment

begin_define
define|#
directive|define
name|XGE_OS_HOST_BIG_ENDIAN
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|XGE_OS_HOST_PAGE_SIZE
value|TEMPLATE
end_define

begin_comment
comment|/* ---------------------- fixed size primitive types -----------------------*/
end_comment

begin_comment
comment|/*  * Note:  *  *	- u## - means ## bits unsigned int/long  *      - all names must be preserved since HAL using them.  *      - ulong_t is platform specific, i.e. for 64bit - 64bit size, for  *        32bit - 32bit size  */
end_comment

begin_define
define|#
directive|define
name|TEMPLATE
value|u8
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|u16
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|u32
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|u64
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|ulong_t
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|ptrdiff_t
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|dma_addr_t
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|spinlock_t
end_define

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_dev_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_reg_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_dma_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_irq_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_cfg_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TEMPLATE
name|pci_dma_acc_h
typedef|;
end_typedef

begin_comment
comment|/* -------------------------- "libc" functionality -------------------------*/
end_comment

begin_comment
comment|/*  * Note:  *  *	- "libc" functionality maps one-to-one to be posix-like  */
end_comment

begin_comment
comment|/* Note: use typedef: xge_os_memzero(void* mem, int size); */
end_comment

begin_define
define|#
directive|define
name|xge_os_memzero
value|TEMPLATE
end_define

begin_comment
comment|/* Note: the 1st argument MUST be destination, like in:  * void *memcpy(void *dest, const void *src, size_t n);  */
end_comment

begin_define
define|#
directive|define
name|xge_os_memcpy
value|TEMPLATE
end_define

begin_comment
comment|/* Note: should accept format (the 1st argument) and a variable  * number of arguments thereafter.. */
end_comment

begin_define
define|#
directive|define
name|xge_os_printf
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_vasprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
modifier|...
parameter_list|)
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_sprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_timestamp
parameter_list|(
name|buf
parameter_list|)
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_println
value|TEMPLATE
end_define

begin_comment
comment|/* -------------------- synchronization primitives -------------------------*/
end_comment

begin_comment
comment|/*  * Note:  *  *	- use spin_lock in interrupts or in threads when there is no races  *	  with interrupt  *	- use spin_lock_irqsave in threads if there is a race with interrupt  *	- use spin_lock_irqsave for nested locks  */
end_comment

begin_comment
comment|/*  * Initialize the spin lock.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock_init
parameter_list|(
name|lockp
parameter_list|,
name|ctxh
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Initialize the spin lock (IRQ version).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock_init_irq
parameter_list|(
name|lockp
parameter_list|,
name|ctxh
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Destroy the lock.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock_destroy
parameter_list|(
name|lockp
parameter_list|,
name|ctxh
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Destroy the lock (IRQ version).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock_destroy_irq
parameter_list|(
name|lockp
parameter_list|,
name|ctxh
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Acquire the lock.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock
parameter_list|(
name|lockp
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Release the lock.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_unlock
parameter_list|(
name|lockp
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Acquire the lock(IRQ version).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock_irq
parameter_list|(
name|lockp
parameter_list|,
name|flags
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Release the lock(IRQ version).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_unlock_irq
parameter_list|(
name|lockp
parameter_list|,
name|flags
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Write memory barrier.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_wmb
parameter_list|()
value|TEMPLATE
end_define

begin_comment
comment|/*  * Delay (in micro seconds).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_udelay
parameter_list|(
name|us
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Delay (in milli seconds).  */
end_comment

begin_define
define|#
directive|define
name|xge_os_mdelay
parameter_list|(
name|ms
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/*  * Compare and exchange.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_cmpxchg
parameter_list|(
name|targetp
parameter_list|,
name|cmp
parameter_list|,
name|newval
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/* ------------------------- misc primitives -------------------------------*/
end_comment

begin_define
define|#
directive|define
name|xge_os_prefetch
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_prefetchw
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|xge_os_bug
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|TEMPLATE
end_define

begin_comment
comment|/* -------------------------- compiler stuffs ------------------------------*/
end_comment

begin_define
define|#
directive|define
name|__xge_os_attr_cacheline_aligned
value|TEMPLATE
end_define

begin_comment
comment|/* ---------------------- memory primitives --------------------------------*/
end_comment

begin_comment
comment|/**  * xge_os_malloc - Allocate non DMA-able memory.  * @pdev: Device context. Some OSs require device context to perform  *        operations on memory.  * @size: Size to allocate.  *  * Allocate @size bytes of memory. This allocation can sleep, and  * therefore, and therefore it requires process context. In other words,  * xge_os_malloc() cannot be called from the interrupt context.  * Use xge_os_free() to free the allocated block.  *  * Returns: Pointer to allocated memory, NULL - on failure.  *  * See also: xge_os_free().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xge_os_malloc
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_free - Free non DMA-able memory.  * @pdev: Device context. Some OSs require device context to perform  *        operations on memory.  * @vaddr: Address of the allocated memory block.  * @size: Some OS's require to provide size on free  *  * Free the memory area obtained via xge_os_malloc().  * This call may also sleep, and therefore it cannot be used inside  * interrupt.  *  * See also: xge_os_malloc().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_free
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|,
name|IN
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_vaddr - Get Virtual address for the given physical address.  * @pdev: Device context. Some OSs require device context to perform  *        operations on memory.  * @vaddr: Physical Address of the memory block.  * @size: Some OS's require to provide size  *  * Get the virtual address for physical address.  * This call may also sleep, and therefore it cannot be used inside  * interrupt.  *  * See also: xge_os_malloc().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_vaddr
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|,
name|IN
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_malloc  -  Allocate DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @size: Size (in bytes) to allocate.  * @dma_flags: XGE_OS_DMA_CACHELINE_ALIGNED,  *             XGE_OS_DMA_STREAMING,  *             XGE_OS_DMA_CONSISTENT  *	 Note that the last two flags are mutually exclusive.  * @p_dmah: Handle used to map the memory onto the corresponding device memory  *          space. See xge_os_dma_map(). The handle is an out-parameter  *          returned by the function.  * @p_dma_acch: One more DMA handle used subsequently to free the  *              DMA object (via xge_os_dma_free()).  *              Note that this and the previous handle have  *              physical meaning for Solaris; on Windows and Linux the  *              corresponding value will be simply a pointer to PCI device.  *              The value is returned by this function.  *  * Allocate DMA-able contiguous memory block of the specified @size.  * This memory can be subsequently freed using xge_os_dma_free().  * Note: can be used inside interrupt context.  *  * Returns: Pointer to allocated memory(DMA-able), NULL on failure.  *  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xge_os_dma_malloc
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|unsigned
name|long
name|size
parameter_list|,
name|IN
name|int
name|dma_flags
parameter_list|,
name|OUT
name|pci_dma_h
modifier|*
name|p_dmah
parameter_list|,
name|OUT
name|pci_dma_acc_h
modifier|*
name|p_dma_acch
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_free - Free previously allocated DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @vaddr: Virtual address of the DMA-able memory.  * @p_dma_acch: DMA handle used to free the resource.  * @p_dmah: DMA handle used for mapping. See xge_os_dma_malloc().  *  * Free DMA-able memory originally allocated by xge_os_dma_malloc().  * Note: can be used inside interrupt.  * See also: xge_os_dma_malloc().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_free
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|,
name|IN
name|pci_dma_acc_h
modifier|*
name|p_dma_acch
parameter_list|,
name|IN
name|pci_dma_h
modifier|*
name|p_dmah
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ----------------------- io/pci/dma primitives ---------------------------*/
end_comment

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_TODEVICE
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_FROMDEVICE
value|TEMPLATE
end_define

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_BIDIRECTIONAL
value|TEMPLATE
end_define

begin_comment
comment|/**  * xge_os_pci_read8 - Read one byte from device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of the result.  *  * Read byte value from the specified @regh PCI configuration space at the  * specified offset = @where.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_read8
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u8
modifier|*
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pci_write8 - Write one byte into device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write byte value into the specified PCI configuration space  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_write8
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u8
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pci_read16 - Read 16bit word from device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of the 16bit result.  *  * Read 16bit value from the specified PCI configuration space at the  * specified offset.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_read16
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u16
modifier|*
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pci_write16 - Write 16bit word into device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write 16bit value into the specified @offset in PCI  * configuration space.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_write16
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u16
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pci_read32 - Read 32bit word from device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of 32bit result.  *  * Read 32bit value from the specified PCI configuration space at the  * specified offset.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_read32
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u32
modifier|*
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pci_write32 - Write 32bit word into device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write 32bit value into the specified @offset in PCI  * configuration space.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|xge_os_pci_write32
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_cfg_h
name|cfgh
parameter_list|,
name|IN
name|int
name|where
parameter_list|,
name|IN
name|u32
name|val
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read8 - Read 1 byte from device memory mapped space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO..  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 1 byte value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u8
name|xge_os_pio_mem_read8
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write64 - Write 1 byte into device memory mapped  * space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO and/or config space IO..  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write byte value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write8
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|u8
name|val
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read16 - Read 16bit from device memory mapped space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 16bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u16
name|xge_os_pio_mem_read16
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write16 - Write 16bit into device memory mapped space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 16bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write16
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|u16
name|val
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read32 - Read 32bit from device memory mapped space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 32bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u32
name|xge_os_pio_mem_read32
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write32 - Write 32bit into device memory space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 32bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write32
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|u32
name|val
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read64 - Read 64bit from device memory mapped space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 64bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u64
name|xge_os_pio_mem_read64
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write64 - Write 64bit into device memory space.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 64bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write64
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|u64
name|val
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_flush_bridge - Flush the bridge.  * @pdev: Device context. Some OSs require device context to perform  *        PIO.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Flush the bridge.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_flush_bridge
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_reg_h
name|regh
parameter_list|,
name|IN
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_map - Map DMA-able memory block to, or from, or  * to-and-from device.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @vaddr: Virtual address of the DMA-able memory.  * @size: Size (in bytes) to be mapped.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  * @dma_flags: XGE_OS_DMA_CACHELINE_ALIGNED,  *             XGE_OS_DMA_STREAMING,  *             XGE_OS_DMA_CONSISTENT  *	 Note that the last two flags are mutually exclusive.  *  * Map a single memory block.  *  * Returns: DMA address of the memory block,  * XGE_OS_INVALID_DMA_ADDR on failure.  *  * See also: xge_os_dma_malloc(), xge_os_dma_unmap(),  * xge_os_dma_sync().  */
end_comment

begin_function
specifier|static
specifier|inline
name|dma_addr_t
name|xge_os_dma_map
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_dma_h
name|dmah
parameter_list|,
name|IN
name|void
modifier|*
name|vaddr
parameter_list|,
name|IN
name|size_t
name|size
parameter_list|,
name|IN
name|int
name|dir
parameter_list|,
name|IN
name|int
name|dma_flags
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_unmap - Unmap DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @dma_addr: DMA address of the block. Obtained via xge_os_dma_map().  * @size: Size (in bytes) to be unmapped.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  *  * Unmap a single DMA-able memory block that was previously mapped  * using xge_os_dma_map().  * See also: xge_os_dma_malloc(), xge_os_dma_map().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_unmap
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_dma_h
name|dmah
parameter_list|,
name|IN
name|dma_addr_t
name|dma_addr
parameter_list|,
name|IN
name|size_t
name|size
parameter_list|,
name|IN
name|int
name|dir
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_sync - Synchronize mapped memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @dma_addr: DMA address of the block. Obtained via xge_os_dma_map().  * @dma_offset: Offset from start of the blocke. Used by Solaris only.  * @length: Size of the block.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  *  * Make physical and CPU memory consistent for a single  * streaming mode DMA translation.  * This API compiles to NOP on cache-coherent platforms.  * On non cache-coherent platforms, depending on the direction  * of the "sync" operation, this API will effectively  * either invalidate CPU cache (that might contain old data),  * or  flush CPU cache to update physical memory.  * See also: xge_os_dma_malloc(), xge_os_dma_map(),  * xge_os_dma_unmap().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_sync
parameter_list|(
name|IN
name|pci_dev_h
name|pdev
parameter_list|,
name|IN
name|pci_dma_h
name|dmah
parameter_list|,
name|IN
name|dma_addr_t
name|dma_addr
parameter_list|,
name|IN
name|u64
name|dma_offset
parameter_list|,
name|IN
name|size_t
name|length
parameter_list|,
name|IN
name|int
name|dir
parameter_list|)
block|{
name|TEMPLATE
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_OS_TEMPLATE_H */
end_comment

end_unit

