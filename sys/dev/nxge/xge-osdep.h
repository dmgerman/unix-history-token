begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_OSDEP_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_OSDEP_H
end_define

begin_comment
comment|/**  * Includes and defines  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pci_private.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_define
define|#
directive|define
name|XGE_OS_PLATFORM_64BIT
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|XGE_OS_HOST_BIG_ENDIAN
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_elif

begin_define
define|#
directive|define
name|XGE_OS_HOST_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XGE_HAL_USE_5B_MODE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_TRACE_ASSERT
end_ifdef

begin_undef
undef|#
directive|undef
name|XGE_TRACE_ASSERT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OS_NETSTACK_BUF
value|struct mbuf *
end_define

begin_define
define|#
directive|define
name|XGE_LL_IP_FAST_CSUM
parameter_list|(
name|hdr
parameter_list|,
name|len
parameter_list|)
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__DECONST
end_ifndef

begin_define
define|#
directive|define
name|__DECONST
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintrptr_t)(const void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|xge_os_ntohs
value|ntohs
end_define

begin_define
define|#
directive|define
name|xge_os_ntohl
value|ntohl
end_define

begin_define
define|#
directive|define
name|xge_os_htons
value|htons
end_define

begin_define
define|#
directive|define
name|xge_os_htonl
value|htonl
end_define

begin_typedef
typedef|typedef
struct|struct
name|xge_bus_resource_t
block|{
name|bus_space_tag_t
name|bus_tag
decl_stmt|;
comment|/* DMA Tag                      */
name|bus_space_handle_t
name|bus_handle
decl_stmt|;
comment|/* Bus handle                   */
name|struct
name|resource
modifier|*
name|bar_start_addr
decl_stmt|;
comment|/* BAR start address            */
block|}
name|xge_bus_resource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_dma_alloc_t
block|{
name|bus_addr_t
name|dma_phyaddr
decl_stmt|;
comment|/* Physical Address             */
name|caddr_t
name|dma_viraddr
decl_stmt|;
comment|/* Virtual Address              */
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
comment|/* DMA Tag                      */
name|bus_dmamap_t
name|dma_map
decl_stmt|;
comment|/* DMA Map                      */
name|bus_dma_segment_t
name|dma_segment
decl_stmt|;
comment|/* DMA Segment                  */
name|bus_size_t
name|dma_size
decl_stmt|;
comment|/* Size                         */
name|int
name|dma_nseg
decl_stmt|;
comment|/* Maximum scatter-gather segs. */
block|}
name|xge_dma_alloc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_dma_mbuf_t
block|{
name|bus_addr_t
name|dma_phyaddr
decl_stmt|;
comment|/* Physical Address             */
name|bus_dmamap_t
name|dma_map
decl_stmt|;
comment|/* DMA Map                      */
block|}
name|xge_dma_mbuf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xge_pci_info
block|{
name|device_t
name|device
decl_stmt|;
comment|/* Device                       */
name|struct
name|resource
modifier|*
name|regmap0
decl_stmt|;
comment|/* Resource for BAR0            */
name|struct
name|resource
modifier|*
name|regmap1
decl_stmt|;
comment|/* Resource for BAR1            */
name|void
modifier|*
name|bar0resource
decl_stmt|;
comment|/* BAR0 tag and handle          */
name|void
modifier|*
name|bar1resource
decl_stmt|;
comment|/* BAR1 tag and handle          */
block|}
name|xge_pci_info_t
typedef|;
end_typedef

begin_comment
comment|/**  * Fixed size primitive types  */
end_comment

begin_define
define|#
directive|define
name|u8
value|uint8_t
end_define

begin_define
define|#
directive|define
name|u16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|u32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|u64
value|uint64_t
end_define

begin_define
define|#
directive|define
name|ulong_t
value|unsigned long
end_define

begin_define
define|#
directive|define
name|uint
value|unsigned int
end_define

begin_define
define|#
directive|define
name|ptrdiff_t
value|ptrdiff_t
end_define

begin_typedef
typedef|typedef
name|bus_addr_t
name|dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mtx
name|spinlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xge_pci_info_t
modifier|*
name|pci_dev_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xge_bus_resource_t
modifier|*
name|pci_reg_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xge_dma_alloc_t
name|pci_dma_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xge_dma_alloc_t
name|pci_dma_acc_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|resource
modifier|*
name|pci_irq_h
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|xge_pci_info_t
modifier|*
name|pci_cfg_h
typedef|;
end_typedef

begin_comment
comment|/**  * "libc" functionality  */
end_comment

begin_define
define|#
directive|define
name|xge_os_memzero
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|)
value|bzero(addr, size)
end_define

begin_define
define|#
directive|define
name|xge_os_memcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|bcopy(src, dst, size)
end_define

begin_define
define|#
directive|define
name|xge_os_memcmp
value|memcmp
end_define

begin_define
define|#
directive|define
name|xge_os_strcpy
value|strcpy
end_define

begin_define
define|#
directive|define
name|xge_os_strlen
value|strlen
end_define

begin_define
define|#
directive|define
name|xge_os_snprintf
value|snprintf
end_define

begin_define
define|#
directive|define
name|xge_os_sprintf
value|sprintf
end_define

begin_define
define|#
directive|define
name|xge_os_printf
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|{                                                \ 	printf(fmt);                                                           \ 	printf("\n");                                                          \ }
end_define

begin_define
define|#
directive|define
name|xge_os_vaprintf
parameter_list|(
name|fmt
parameter_list|)
value|{                                                 \ 	sprintf(fmt, fmt, "\n");                                               \ 	va_list va;                                                            \ 	va_start(va, fmt);                                                     \ 	vprintf(fmt, va);                                                      \ 	va_end(va);                                                            \ }
end_define

begin_define
define|#
directive|define
name|xge_os_vasprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
parameter_list|)
value|{                                           \ 	va_list va;                                                            \ 	va_start(va, fmt);                                                     \ 	(void) vaprintf(buf, fmt, va);                                         \ 	va_end(va);                                                            \ }
end_define

begin_define
define|#
directive|define
name|xge_os_timestamp
parameter_list|(
name|buf
parameter_list|)
value|{                                                \ 	struct timeval current_time;                                           \ 	gettimeofday(&current_time, 0);                                        \ 	sprintf(buf, "%08li.%08li: ", current_time.tv_sec,                     \ 	    current_time.tv_usec);                                             \ }
end_define

begin_define
define|#
directive|define
name|xge_os_println
value|xge_os_printf
end_define

begin_comment
comment|/**  * Synchronization Primitives  */
end_comment

begin_comment
comment|/* Initialize the spin lock */
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
value|{                                   \ 	if(mtx_initialized(lockp) == 0) {                                      \ 	    mtx_init((lockp), "xge", NULL, MTX_DEF);                           \ 	}                                                                      \ }
end_define

begin_comment
comment|/* Initialize the spin lock (IRQ version) */
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
value|{                               \ 	if(mtx_initialized(lockp) == 0) {                                      \ 	    mtx_init((lockp), "xge", NULL, MTX_DEF);                           \ 	}                                                                      \ }
end_define

begin_comment
comment|/* Destroy the lock */
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
value|{                                \ 	if(mtx_initialized(lockp) != 0) {                                      \ 	    mtx_destroy(lockp);                                                \ 	}                                                                      \ }
end_define

begin_comment
comment|/* Destroy the lock (IRQ version) */
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
value|{                            \ 	if(mtx_initialized(lockp) != 0) {                                      \ 	    mtx_destroy(lockp);                                                \ 	}                                                                      \ }
end_define

begin_comment
comment|/* Acquire the lock */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_lock
parameter_list|(
name|lockp
parameter_list|)
value|{                                              \ 	if(mtx_owned(lockp) == 0) mtx_lock(lockp);                             \ }
end_define

begin_comment
comment|/* Release the lock */
end_comment

begin_define
define|#
directive|define
name|xge_os_spin_unlock
parameter_list|(
name|lockp
parameter_list|)
value|{                                            \ 	mtx_unlock(lockp);                                                     \ }
end_define

begin_comment
comment|/* Acquire the lock (IRQ version) */
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
value|{                                   \ 	flags = MTX_QUIET;                                                     \ 	if(mtx_owned(lockp) == 0) mtx_lock_flags(lockp, flags);                \ }
end_define

begin_comment
comment|/* Release the lock (IRQ version) */
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
value|{                                 \ 	flags = MTX_QUIET;                                                     \ 	mtx_unlock_flags(lockp, flags);                                        \ }
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|800053
end_if

begin_comment
comment|/* Write memory barrier */
end_comment

begin_define
define|#
directive|define
name|xge_os_wmb
parameter_list|()
value|wmb()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xge_os_wmb
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Delay (in micro seconds) */
end_comment

begin_define
define|#
directive|define
name|xge_os_udelay
parameter_list|(
name|us
parameter_list|)
value|DELAY(us)
end_define

begin_comment
comment|/* Delay (in milli seconds) */
end_comment

begin_define
define|#
directive|define
name|xge_os_mdelay
parameter_list|(
name|ms
parameter_list|)
value|DELAY(ms * 1000)
end_define

begin_comment
comment|/* Compare and exchange */
end_comment

begin_comment
comment|//#define xge_os_cmpxchg(targetp, cmd, newval)
end_comment

begin_comment
comment|/**  * Misc primitives  */
end_comment

begin_define
define|#
directive|define
name|xge_os_unlikely
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|xge_os_prefetch
parameter_list|(
name|x
parameter_list|)
value|(x=x)
end_define

begin_define
define|#
directive|define
name|xge_os_prefetchw
parameter_list|(
name|x
parameter_list|)
value|(x=x)
end_define

begin_define
define|#
directive|define
name|xge_os_bug
parameter_list|(
name|fmt
modifier|...
parameter_list|)
value|printf(fmt)
end_define

begin_define
define|#
directive|define
name|xge_os_htohs
value|ntohs
end_define

begin_define
define|#
directive|define
name|xge_os_ntohl
value|ntohl
end_define

begin_define
define|#
directive|define
name|xge_os_htons
value|htons
end_define

begin_define
define|#
directive|define
name|xge_os_htonl
value|htonl
end_define

begin_comment
comment|/**  * Compiler Stuffs  */
end_comment

begin_define
define|#
directive|define
name|__xge_os_attr_cacheline_aligned
end_define

begin_define
define|#
directive|define
name|__xge_os_cacheline_size
value|32
end_define

begin_comment
comment|/**  * Memory Primitives  */
end_comment

begin_define
define|#
directive|define
name|XGE_OS_INVALID_DMA_ADDR
value|((dma_addr_t)0)
end_define

begin_comment
comment|/**  * xge_os_malloc  * Allocate non DMA-able memory.  * @pdev: Device context.  * @size: Size to allocate.  *  * Allocate @size bytes of memory. This allocation can sleep, and therefore,  * and therefore it requires process context. In other words, xge_os_malloc()  * cannot be called from the interrupt context. Use xge_os_free() to free the  * allocated block.  *  * Returns: Pointer to allocated memory, NULL - on failure.  *  * See also: xge_os_free().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xge_os_malloc
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|void
modifier|*
name|vaddr
init|=
name|malloc
argument_list|(
operator|(
name|size
operator|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
decl_stmt|;
if|if
condition|(
name|vaddr
operator|!=
name|NULL
condition|)
block|{
name|XGE_OS_MEMORY_CHECK_MALLOC
argument_list|(
name|vaddr
argument_list|,
name|size
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
name|xge_os_memzero
argument_list|(
name|vaddr
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|vaddr
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_free  * Free non DMA-able memory.  * @pdev: Device context.  * @vaddr: Address of the allocated memory block.  * @size: Some OS's require to provide size on free  *  * Free the memory area obtained via xge_os_malloc(). This call may also sleep,  * and therefore it cannot be used inside interrupt.  *  * See also: xge_os_malloc().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_free
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|XGE_OS_MEMORY_CHECK_FREE
argument_list|(
name|vaddr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|__DECONST
argument_list|(
name|void
operator|*
argument_list|,
name|vaddr
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xge_dmamap_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
name|nseg
parameter_list|,
name|int
name|error
parameter_list|)
block|{
if|if
condition|(
name|error
condition|)
return|return;
operator|*
operator|(
name|bus_addr_t
operator|*
operator|)
name|arg
operator|=
name|segs
operator|->
name|ds_addr
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_malloc  * Allocate DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @size: Size (in bytes) to allocate.  * @dma_flags: XGE_OS_DMA_CACHELINE_ALIGNED, XGE_OS_DMA_STREAMING,  * XGE_OS_DMA_CONSISTENT (Note that the last two flags are mutually exclusive.)  * @p_dmah: Handle used to map the memory onto the corresponding device memory  * space. See xge_os_dma_map(). The handle is an out-parameter returned by the  * function.  * @p_dma_acch: One more DMA handle used subsequently to free the DMA object  * (via xge_os_dma_free()).  *  * Allocate DMA-able contiguous memory block of the specified @size. This memory  * can be subsequently freed using xge_os_dma_free().  * Note: can be used inside interrupt context.  *  * Returns: Pointer to allocated memory(DMA-able), NULL on failure.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|xge_os_dma_malloc
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|int
name|dma_flags
parameter_list|,
name|pci_dma_h
modifier|*
name|p_dmah
parameter_list|,
name|pci_dma_acc_h
modifier|*
name|p_dma_acch
parameter_list|)
block|{
name|int
name|retValue
init|=
name|bus_dma_tag_create
argument_list|(
name|bus_get_dma_tag
argument_list|(
name|pdev
operator|->
name|device
argument_list|)
argument_list|,
comment|/* Parent                          */
name|PAGE_SIZE
argument_list|,
comment|/* Alignment no specific alignment */
literal|0
argument_list|,
comment|/* Bounds                          */
name|BUS_SPACE_MAXADDR
argument_list|,
comment|/* Low Address                     */
name|BUS_SPACE_MAXADDR
argument_list|,
comment|/* High Address                    */
name|NULL
argument_list|,
comment|/* Filter                          */
name|NULL
argument_list|,
comment|/* Filter arg                      */
name|size
argument_list|,
comment|/* Max Size                        */
literal|1
argument_list|,
comment|/* n segments                      */
name|size
argument_list|,
comment|/* max segment size                */
name|BUS_DMA_ALLOCNOW
argument_list|,
comment|/* Flags                           */
name|NULL
argument_list|,
comment|/* lockfunction                    */
name|NULL
argument_list|,
comment|/* lock arg                        */
operator|&
name|p_dmah
operator|->
name|dma_tag
argument_list|)
decl_stmt|;
comment|/* DMA tag                         */
if|if
condition|(
name|retValue
operator|!=
literal|0
condition|)
block|{
name|xge_os_printf
argument_list|(
literal|"bus_dma_tag_create failed\n"
argument_list|)
goto|goto
name|fail_1
goto|;
block|}
name|p_dmah
operator|->
name|dma_size
operator|=
name|size
expr_stmt|;
name|retValue
operator|=
name|bus_dmamem_alloc
argument_list|(
name|p_dmah
operator|->
name|dma_tag
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|p_dmah
operator|->
name|dma_viraddr
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|,
operator|&
name|p_dmah
operator|->
name|dma_map
argument_list|)
expr_stmt|;
if|if
condition|(
name|retValue
operator|!=
literal|0
condition|)
block|{
name|xge_os_printf
argument_list|(
literal|"bus_dmamem_alloc failed\n"
argument_list|)
goto|goto
name|fail_2
goto|;
block|}
name|XGE_OS_MEMORY_CHECK_MALLOC
argument_list|(
name|p_dmah
operator|->
name|dma_viraddr
argument_list|,
name|p_dmah
operator|->
name|dma_size
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_dmah
operator|->
name|dma_viraddr
operator|)
return|;
name|fail_2
label|:
name|bus_dma_tag_destroy
argument_list|(
name|p_dmah
operator|->
name|dma_tag
argument_list|)
expr_stmt|;
name|fail_1
label|:
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_free  * Free previously allocated DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @vaddr: Virtual address of the DMA-able memory.  * @p_dma_acch: DMA handle used to free the resource.  * @p_dmah: DMA handle used for mapping. See xge_os_dma_malloc().  *  * Free DMA-able memory originally allocated by xge_os_dma_malloc().  * Note: can be used inside interrupt.  * See also: xge_os_dma_malloc().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_free
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|,
name|int
name|size
parameter_list|,
name|pci_dma_acc_h
modifier|*
name|p_dma_acch
parameter_list|,
name|pci_dma_h
modifier|*
name|p_dmah
parameter_list|)
block|{
name|XGE_OS_MEMORY_CHECK_FREE
argument_list|(
name|p_dmah
operator|->
name|dma_viraddr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|bus_dmamem_free
argument_list|(
name|p_dmah
operator|->
name|dma_tag
argument_list|,
name|p_dmah
operator|->
name|dma_viraddr
argument_list|,
name|p_dmah
operator|->
name|dma_map
argument_list|)
expr_stmt|;
name|bus_dma_tag_destroy
argument_list|(
name|p_dmah
operator|->
name|dma_tag
argument_list|)
expr_stmt|;
name|p_dmah
operator|->
name|dma_tag
operator|=
name|NULL
expr_stmt|;
name|p_dmah
operator|->
name|dma_viraddr
operator|=
name|NULL
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/**  * IO/PCI/DMA Primitives  */
end_comment

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_TODEVICE
value|0
end_define

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_FROMDEVICE
value|1
end_define

begin_define
define|#
directive|define
name|XGE_OS_DMA_DIR_BIDIRECTIONAL
value|2
end_define

begin_comment
comment|/**  * xge_os_pci_read8  * Read one byte from device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform PIO and/or  * config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of the result.  *  * Read byte value from the specified @regh PCI configuration space at the  * specified offset = @where.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_read8
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(val) = pci_read_config(pdev->device, where, 1))
end_define

begin_comment
comment|/**  * xge_os_pci_write8  * Write one byte into device PCI configuration.  * @pdev: Device context. Some OSs require device context to perform PIO and/or  * config space IO.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write byte value into the specified PCI configuration space  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_write8
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|pci_write_config(pdev->device, where, val, 1)
end_define

begin_comment
comment|/**  * xge_os_pci_read16  * Read 16bit word from device PCI configuration.  * @pdev: Device context.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of the 16bit result.  *  * Read 16bit value from the specified PCI configuration space at the  * specified offset.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_read16
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(val) = pci_read_config(pdev->device, where, 2))
end_define

begin_comment
comment|/**  * xge_os_pci_write16  * Write 16bit word into device PCI configuration.  * @pdev: Device context.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write 16bit value into the specified @offset in PCI configuration space.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_write16
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|pci_write_config(pdev->device, where, val, 2)
end_define

begin_comment
comment|/**  * xge_os_pci_read32  * Read 32bit word from device PCI configuration.  * @pdev: Device context.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Address of 32bit result.  *  * Read 32bit value from the specified PCI configuration space at the  * specified offset.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_read32
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(val) = pci_read_config(pdev->device, where, 4))
end_define

begin_comment
comment|/**  * xge_os_pci_write32  * Write 32bit word into device PCI configuration.  * @pdev: Device context.  * @cfgh: PCI configuration space handle.  * @where: Offset in the PCI configuration space.  * @val: Value to write.  *  * Write 32bit value into the specified @offset in PCI configuration space.  * Returns: 0 - success, non-zero - failure.  */
end_comment

begin_define
define|#
directive|define
name|xge_os_pci_write32
parameter_list|(
name|pdev
parameter_list|,
name|cfgh
parameter_list|,
name|where
parameter_list|,
name|val
parameter_list|)
define|\
value|pci_write_config(pdev->device, where, val, 4)
end_define

begin_comment
comment|/**  * xge_os_pio_mem_read8  * Read 1 byte from device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 1 byte value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u8
name|xge_os_pio_mem_read8
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
return|return
name|bus_space_read_1
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write8  * Write 1 byte into device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write byte value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write8
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|u8
name|val
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
name|bus_space_write_1
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read16  * Read 16bit from device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 16bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u16
name|xge_os_pio_mem_read16
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
return|return
name|bus_space_read_2
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write16  * Write 16bit into device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 16bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write16
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|u16
name|val
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
name|bus_space_write_2
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read32  * Read 32bit from device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 32bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u32
name|xge_os_pio_mem_read32
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
return|return
name|bus_space_read_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write32  * Write 32bit into device memory space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 32bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write32
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|u32
name|val
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
name|bus_space_write_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_read64  * Read 64bit from device memory mapped space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @addr: Address in device memory space.  *  * Returns: 64bit value read from the specified (mapped) memory space address.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u64
name|xge_os_pio_mem_read64
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|u64
name|value1
decl_stmt|,
name|value2
decl_stmt|;
name|bus_space_tag_t
name|tag
init|=
call|(
name|bus_space_tag_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_tag
argument_list|)
decl_stmt|;
name|bus_space_handle_t
name|handle
init|=
call|(
name|bus_space_handle_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
name|regh
operator|)
operator|->
name|bus_handle
argument_list|)
decl_stmt|;
name|caddr_t
name|addrss
init|=
call|(
name|caddr_t
call|)
argument_list|(
operator|(
operator|(
name|xge_bus_resource_t
operator|*
operator|)
operator|(
name|regh
operator|)
operator|)
operator|->
name|bar_start_addr
argument_list|)
decl_stmt|;
name|value1
operator|=
name|bus_space_read_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|+
literal|4
operator|-
name|addrss
argument_list|)
expr_stmt|;
name|value1
operator|<<=
literal|32
expr_stmt|;
name|value2
operator|=
name|bus_space_read_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|-
name|addrss
argument_list|)
expr_stmt|;
name|value1
operator||=
name|value2
expr_stmt|;
return|return
name|value1
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_pio_mem_write64  * Write 32bit into device memory space.  * @pdev: Device context.  * @regh: PCI configuration space handle.  * @val: Value to write.  * @addr: Address in device memory space.  *  * Write 64bit value into the specified (mapped) device memory space.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_pio_mem_write64
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_reg_h
name|regh
parameter_list|,
name|u64
name|val
parameter_list|,
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|u32
name|vall
init|=
name|val
operator|&
literal|0xffffffff
decl_stmt|;
name|xge_os_pio_mem_write32
argument_list|(
name|pdev
argument_list|,
name|regh
argument_list|,
name|vall
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|xge_os_pio_mem_write32
argument_list|(
name|pdev
argument_list|,
name|regh
argument_list|,
name|val
operator|>>
literal|32
argument_list|,
operator|(
call|(
name|caddr_t
call|)
argument_list|(
name|addr
argument_list|)
operator|+
literal|4
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * FIXME: document  */
end_comment

begin_define
define|#
directive|define
name|xge_os_flush_bridge
value|xge_os_pio_mem_read64
end_define

begin_comment
comment|/**  * xge_os_dma_map  * Map DMA-able memory block to, or from, or to-and-from device.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @vaddr: Virtual address of the DMA-able memory.  * @size: Size (in bytes) to be mapped.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  * @dma_flags: XGE_OS_DMA_CACHELINE_ALIGNED, XGE_OS_DMA_STREAMING,  * XGE_OS_DMA_CONSISTENT (Note that the last two flags are mutually exclusive).  *  * Map a single memory block.  *  * Returns: DMA address of the memory block, XGE_OS_INVALID_DMA_ADDR on failure.  *  * See also: xge_os_dma_malloc(), xge_os_dma_unmap(), xge_os_dma_sync().  */
end_comment

begin_function
specifier|static
specifier|inline
name|dma_addr_t
name|xge_os_dma_map
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_dma_h
name|dmah
parameter_list|,
name|void
modifier|*
name|vaddr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|dir
parameter_list|,
name|int
name|dma_flags
parameter_list|)
block|{
name|int
name|retValue
init|=
name|bus_dmamap_load
argument_list|(
name|dmah
operator|.
name|dma_tag
argument_list|,
name|dmah
operator|.
name|dma_map
argument_list|,
name|dmah
operator|.
name|dma_viraddr
argument_list|,
name|dmah
operator|.
name|dma_size
argument_list|,
name|xge_dmamap_cb
argument_list|,
operator|&
name|dmah
operator|.
name|dma_phyaddr
argument_list|,
name|BUS_DMA_NOWAIT
argument_list|)
decl_stmt|;
if|if
condition|(
name|retValue
operator|!=
literal|0
condition|)
block|{
name|xge_os_printf
argument_list|(
literal|"bus_dmamap_load_ failed\n"
argument_list|)
return|return
name|XGE_OS_INVALID_DMA_ADDR
return|;
block|}
name|dmah
operator|.
name|dma_size
operator|=
name|size
expr_stmt|;
return|return
name|dmah
operator|.
name|dma_phyaddr
return|;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_unmap - Unmap DMA-able memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @dma_addr: DMA address of the block. Obtained via xge_os_dma_map().  * @size: Size (in bytes) to be unmapped.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  *  * Unmap a single DMA-able memory block that was previously mapped using  * xge_os_dma_map().  * See also: xge_os_dma_malloc(), xge_os_dma_map().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_unmap
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_dma_h
name|dmah
parameter_list|,
name|dma_addr_t
name|dma_addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|dir
parameter_list|)
block|{
name|bus_dmamap_unload
argument_list|(
name|dmah
operator|.
name|dma_tag
argument_list|,
name|dmah
operator|.
name|dma_map
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/**  * xge_os_dma_sync - Synchronize mapped memory.  * @pdev: Device context. Used to allocate/pin/map/unmap DMA-able memory.  * @dmah: DMA handle used to map the memory block. Obtained via  * xge_os_dma_malloc().  * @dma_addr: DMA address of the block. Obtained via xge_os_dma_map().  * @dma_offset: Offset from start of the blocke. Used by Solaris only.  * @length: Size of the block.  * @dir: Direction of this operation (XGE_OS_DMA_DIR_TODEVICE, etc.)  *  * Make physical and CPU memory consistent for a single streaming mode DMA  * translation. This API compiles to NOP on cache-coherent platforms. On  * non cache-coherent platforms, depending on the direction of the "sync"  * operation, this API will effectively either invalidate CPU cache (that might  * contain old data), or flush CPU cache to update physical memory.  * See also: xge_os_dma_malloc(), xge_os_dma_map(),  * xge_os_dma_unmap().  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|xge_os_dma_sync
parameter_list|(
name|pci_dev_h
name|pdev
parameter_list|,
name|pci_dma_h
name|dmah
parameter_list|,
name|dma_addr_t
name|dma_addr
parameter_list|,
name|u64
name|dma_offset
parameter_list|,
name|size_t
name|length
parameter_list|,
name|int
name|dir
parameter_list|)
block|{
name|bus_dmasync_op_t
name|syncop
decl_stmt|;
switch|switch
condition|(
name|dir
condition|)
block|{
case|case
name|XGE_OS_DMA_DIR_TODEVICE
case|:
name|syncop
operator|=
name|BUS_DMASYNC_PREWRITE
operator||
name|BUS_DMASYNC_POSTWRITE
expr_stmt|;
break|break;
case|case
name|XGE_OS_DMA_DIR_FROMDEVICE
case|:
name|syncop
operator|=
name|BUS_DMASYNC_PREREAD
operator||
name|BUS_DMASYNC_POSTREAD
expr_stmt|;
break|break;
default|default:
name|syncop
operator|=
name|BUS_DMASYNC_PREWRITE
operator||
name|BUS_DMASYNC_PREWRITE
expr_stmt|;
break|break;
block|}
name|bus_dmamap_sync
argument_list|(
name|dmah
operator|.
name|dma_tag
argument_list|,
name|dmah
operator|.
name|dma_map
argument_list|,
name|syncop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_OSDEP_H */
end_comment

end_unit

