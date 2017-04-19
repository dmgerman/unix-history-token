begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BCM_OSAL_ECORE_PACKAGE
end_ifndef

begin_define
define|#
directive|define
name|__BCM_OSAL_ECORE_PACKAGE
end_define

begin_include
include|#
directive|include
file|"qlnx_os.h"
end_include

begin_include
include|#
directive|include
file|"ecore_status.h"
end_include

begin_include
include|#
directive|include
file|<sys/bitstring.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100090
end_if

begin_include
include|#
directive|include
file|<compat/linuxkpi/common/include/linux/bitops.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ofed/include/linux/bitops.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * prototypes of freebsd specific functions required by ecore  */
end_comment

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_pci_bus_get_bar_size
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint8_t
name|bar_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_pci_read_config_byte
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint8_t
modifier|*
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_pci_read_config_word
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint16_t
modifier|*
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_pci_read_config_dword
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint32_t
modifier|*
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_pci_write_config_byte
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint8_t
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_pci_write_config_word
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint16_t
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_pci_write_config_dword
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|uint32_t
name|pci_reg
parameter_list|,
name|uint32_t
name|reg_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qlnx_pci_find_capability
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|int
name|cap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_direct_reg_rd32
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|uint32_t
modifier|*
name|reg_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_direct_reg_wr32
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|void
modifier|*
name|reg_addr
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|qlnx_reg_rd32
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_reg_wr32
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_reg_wr16
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_dbell_wr32
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|qlnx_dma_alloc_coherent
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|bus_addr_t
modifier|*
name|phys
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_dma_free_coherent
parameter_list|(
name|void
modifier|*
name|ecore_dev
parameter_list|,
name|void
modifier|*
name|v_addr
parameter_list|,
name|bus_addr_t
name|phys
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_link_update
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_barrier
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|qlnx_zalloc
parameter_list|(
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_get_protocol_stats
parameter_list|(
name|void
modifier|*
name|cdev
parameter_list|,
name|int
name|proto_type
parameter_list|,
name|void
modifier|*
name|proto_stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_sp_isr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ECORE_PACKAGE
end_ifdef

begin_comment
comment|/* Memory Types */
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
name|s16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|s32
value|uint32_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|QLNX_RDMA
end_ifndef

begin_typedef
typedef|typedef
name|uint16_t
name|__le16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__be16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|roundup_pow_of_two
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1UL
operator|<<
name|flsl
argument_list|(
name|x
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|is_power_of_2
parameter_list|(
name|unsigned
name|long
name|n
parameter_list|)
block|{
return|return
operator|(
name|n
operator|==
name|roundup_pow_of_two
argument_list|(
name|n
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|rounddown_pow_of_two
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
literal|1UL
operator|<<
operator|(
name|flsl
argument_list|(
name|x
argument_list|)
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|((type)(val1)> (type)(val2) ? (type)(val1) : (val2))
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|((type)(val1)< (type)(val2) ? (type)(val1) : (val2))
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof(arr[0]))
end_define

begin_define
define|#
directive|define
name|nothing
value|do {} while(0)
end_define

begin_define
define|#
directive|define
name|BUILD_BUG_ON
parameter_list|(
name|cond
parameter_list|)
value|nothing
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef QLNX_RDMA */
end_comment

begin_define
define|#
directive|define
name|OSAL_CPU_TO_BE64
parameter_list|(
name|val
parameter_list|)
value|htobe64(val)
end_define

begin_define
define|#
directive|define
name|OSAL_BE64_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|be64toh(val)
end_define

begin_define
define|#
directive|define
name|OSAL_CPU_TO_BE32
parameter_list|(
name|val
parameter_list|)
value|htobe32(val)
end_define

begin_define
define|#
directive|define
name|OSAL_BE32_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|be32toh(val)
end_define

begin_define
define|#
directive|define
name|OSAL_CPU_TO_LE32
parameter_list|(
name|val
parameter_list|)
value|htole32(val)
end_define

begin_define
define|#
directive|define
name|OSAL_LE32_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|le32toh(val)
end_define

begin_define
define|#
directive|define
name|OSAL_CPU_TO_BE16
parameter_list|(
name|val
parameter_list|)
value|htobe16(val)
end_define

begin_define
define|#
directive|define
name|OSAL_BE16_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|be16toh(val)
end_define

begin_define
define|#
directive|define
name|OSAL_CPU_TO_LE16
parameter_list|(
name|val
parameter_list|)
value|htole16(val)
end_define

begin_define
define|#
directive|define
name|OSAL_LE16_TO_CPU
parameter_list|(
name|val
parameter_list|)
value|le16toh(val)
end_define

begin_function
specifier|static
name|__inline
name|uint32_t
name|qlnx_get_cache_line_size
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|CACHE_LINE_SIZE
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|OSAL_CACHE_LINE_SIZE
value|qlnx_get_cache_line_size()
end_define

begin_define
define|#
directive|define
name|OSAL_BE32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|dma_addr_t
value|bus_addr_t
end_define

begin_define
define|#
directive|define
name|osal_size_t
value|size_t
end_define

begin_typedef
typedef|typedef
name|struct
name|mtx
name|osal_spinlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mtx
name|osal_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|osal_dpc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osal_list_entry_t
block|{
name|struct
name|_osal_list_entry_t
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
name|osal_list_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osal_list_t
block|{
name|osal_list_entry_t
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|unsigned
name|long
name|cnt
decl_stmt|;
block|}
name|osal_list_t
typedef|;
end_typedef

begin_comment
comment|/* OSAL functions */
end_comment

begin_define
define|#
directive|define
name|OSAL_UDELAY
parameter_list|(
name|time
parameter_list|)
value|DELAY(time)
end_define

begin_define
define|#
directive|define
name|OSAL_MSLEEP
parameter_list|(
name|time
parameter_list|)
value|qlnx_mdelay(__func__, time)
end_define

begin_define
define|#
directive|define
name|OSAL_ALLOC
parameter_list|(
name|dev
parameter_list|,
name|GFP
parameter_list|,
name|size
parameter_list|)
value|qlnx_zalloc(size)
end_define

begin_define
define|#
directive|define
name|OSAL_ZALLOC
parameter_list|(
name|dev
parameter_list|,
name|GFP
parameter_list|,
name|size
parameter_list|)
value|qlnx_zalloc(size)
end_define

begin_define
define|#
directive|define
name|OSAL_VALLOC
parameter_list|(
name|dev
parameter_list|,
name|size
parameter_list|)
value|qlnx_zalloc(size)
end_define

begin_define
define|#
directive|define
name|OSAL_VZALLOC
parameter_list|(
name|dev
parameter_list|,
name|size
parameter_list|)
value|qlnx_zalloc(size)
end_define

begin_define
define|#
directive|define
name|OSAL_FREE
parameter_list|(
name|dev
parameter_list|,
name|memory
parameter_list|)
value|free(memory, M_QLNXBUF)
end_define

begin_define
define|#
directive|define
name|OSAL_VFREE
parameter_list|(
name|dev
parameter_list|,
name|memory
parameter_list|)
value|free(memory, M_QLNXBUF)
end_define

begin_define
define|#
directive|define
name|OSAL_MEM_ZERO
parameter_list|(
name|mem
parameter_list|,
name|size
parameter_list|)
value|bzero(mem, size)
end_define

begin_define
define|#
directive|define
name|OSAL_MEMCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|memcpy(dst, src, size)
end_define

begin_define
define|#
directive|define
name|OSAL_DMA_ALLOC_COHERENT
parameter_list|(
name|dev
parameter_list|,
name|phys
parameter_list|,
name|size
parameter_list|)
define|\
value|qlnx_dma_alloc_coherent(dev, phys, size)
end_define

begin_define
define|#
directive|define
name|OSAL_DMA_FREE_COHERENT
parameter_list|(
name|dev
parameter_list|,
name|virt
parameter_list|,
name|phys
parameter_list|,
name|size
parameter_list|)
define|\
value|qlnx_dma_free_coherent(dev, virt, phys, size)
end_define

begin_define
define|#
directive|define
name|OSAL_VF_CQE_COMPLETION
parameter_list|(
name|_dev_p
parameter_list|,
name|_cqe
parameter_list|,
name|_protocol
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|REG_WR
parameter_list|(
name|hwfn
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
value|qlnx_reg_wr32(hwfn, addr, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|hwfn
parameter_list|,
name|addr
parameter_list|,
name|val
parameter_list|)
value|qlnx_reg_wr16(hwfn, addr, val)
end_define

begin_define
define|#
directive|define
name|DIRECT_REG_WR
parameter_list|(
name|p_hwfn
parameter_list|,
name|addr
parameter_list|,
name|value
parameter_list|)
value|qlnx_direct_reg_wr32(p_hwfn, addr, value)
end_define

begin_define
define|#
directive|define
name|DIRECT_REG_RD
parameter_list|(
name|p_hwfn
parameter_list|,
name|addr
parameter_list|)
value|qlnx_direct_reg_rd32(p_hwfn, addr)
end_define

begin_define
define|#
directive|define
name|REG_RD
parameter_list|(
name|hwfn
parameter_list|,
name|addr
parameter_list|)
value|qlnx_reg_rd32(hwfn, addr)
end_define

begin_define
define|#
directive|define
name|DOORBELL
parameter_list|(
name|hwfn
parameter_list|,
name|addr
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_dbell_wr32(hwfn, addr, value)
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_LOCK_ALLOC
parameter_list|(
name|p_hwfn
parameter_list|,
name|mutex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_LOCK_DEALLOC
parameter_list|(
name|mutex
parameter_list|)
value|mtx_destroy(mutex)
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_LOCK_INIT
parameter_list|(
name|lock
parameter_list|)
value|{\ 		mtx_init(lock, __func__, MTX_NETWORK_LOCK, MTX_SPIN); \ 	}
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_UNLOCK
parameter_list|(
name|lock
parameter_list|)
value|{\ 		mtx_unlock(lock); \ 	}
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_LOCK
parameter_list|(
name|lock
parameter_list|)
value|{\ 		mtx_lock(lock); \ 	}
end_define

begin_define
define|#
directive|define
name|OSAL_MUTEX_ALLOC
parameter_list|(
name|p_hwfn
parameter_list|,
name|mutex
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSAL_MUTEX_DEALLOC
parameter_list|(
name|mutex
parameter_list|)
value|mtx_destroy(mutex)
end_define

begin_define
define|#
directive|define
name|OSAL_MUTEX_INIT
parameter_list|(
name|lock
parameter_list|)
value|{\ 		mtx_init(lock, __func__, MTX_NETWORK_LOCK, MTX_DEF);\ 	}
end_define

begin_define
define|#
directive|define
name|OSAL_MUTEX_ACQUIRE
parameter_list|(
name|lock
parameter_list|)
value|mtx_lock(lock)
end_define

begin_define
define|#
directive|define
name|OSAL_MUTEX_RELEASE
parameter_list|(
name|lock
parameter_list|)
value|mtx_unlock(lock)
end_define

begin_define
define|#
directive|define
name|OSAL_DPC_ALLOC
parameter_list|(
name|hwfn
parameter_list|)
value|malloc(PAGE_SIZE, M_QLNXBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|OSAL_DPC_INIT
parameter_list|(
name|dpc
parameter_list|,
name|hwfn
parameter_list|)
value|nothing
end_define

begin_define
define|#
directive|define
name|OSAL_SCHEDULE_RECOVERY_HANDLER
parameter_list|(
name|x
parameter_list|)
value|nothing
end_define

begin_define
define|#
directive|define
name|OSAL_HW_ERROR_OCCURRED
parameter_list|(
name|hwfn
parameter_list|,
name|err_type
parameter_list|)
value|nothing
end_define

begin_define
define|#
directive|define
name|OSAL_DPC_SYNC
parameter_list|(
name|hwfn
parameter_list|)
value|nothing
end_define

begin_function
specifier|static
specifier|inline
name|void
name|OSAL_DCBX_AEN
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|,
name|u32
name|mib_type
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|OSAL_NVM_IS_ACCESS_ENABLED
parameter_list|(
name|void
modifier|*
name|p_hwfn
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_define
define|#
directive|define
name|OSAL_LIST_INIT
parameter_list|(
name|list
parameter_list|)
define|\
value|do {                       \         (list)->head = NULL;  \         (list)->tail = NULL;  \         (list)->cnt  = 0;     \     } while (0)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_INSERT_ENTRY_AFTER
parameter_list|(
name|entry
parameter_list|,
name|entry_prev
parameter_list|,
name|list
parameter_list|)
define|\
value|do {						\ 	(entry)->prev = (entry_prev);		\ 	(entry)->next = (entry_prev)->next;	\ 	(entry)->next->prev = (entry);		\ 	(entry_prev)->next = (entry);		\ 	(list)->cnt++;				\ } while (0);
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_SPLICE_TAIL_INIT
parameter_list|(
name|new_list
parameter_list|,
name|list
parameter_list|)
define|\
value|do {							\ 	((new_list)->tail)->next = ((list)->head);	\ 	((list)->head)->prev = ((new_list)->tail);	\ 	(list)->head = (new_list)->head;		\ 	(list)->cnt = (list)->cnt + (new_list)->cnt;	\ 	OSAL_LIST_INIT(new_list);			\ } while (0);
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_PUSH_HEAD
parameter_list|(
name|entry
parameter_list|,
name|list
parameter_list|)
define|\
value|do {                                                \         (entry)->prev = (osal_list_entry_t *)0;        \         (entry)->next = (list)->head;                  \         if ((list)->tail == (osal_list_entry_t *)0) { \             (list)->tail = (entry);                    \         } else {                                        \             (list)->head->prev = (entry);              \         }                                               \         (list)->head = (entry);                        \         (list)->cnt++;                                 \     } while (0)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_PUSH_TAIL
parameter_list|(
name|entry
parameter_list|,
name|list
parameter_list|)
define|\
value|do {                                         \         (entry)->next = (osal_list_entry_t *)0; \         (entry)->prev = (list)->tail;           \         if ((list)->tail) {                     \             (list)->tail->next = (entry);       \         } else {                                 \             (list)->head = (entry);             \         }                                        \         (list)->tail = (entry);                 \         (list)->cnt++;                          \     } while (0)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_FIRST_ENTRY
parameter_list|(
name|list
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(type *)((list)->head)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_REMOVE_ENTRY
parameter_list|(
name|entry
parameter_list|,
name|list
parameter_list|)
define|\
value|do {                                                           \         if ((list)->head == (entry)) {                            \             if ((list)->head) {                                   \                 (list)->head = (list)->head->next;               \                 if ((list)->head) {                               \                     (list)->head->prev = (osal_list_entry_t *)0; \                 } else {                                           \                     (list)->tail = (osal_list_entry_t *)0;       \                 }                                                  \                 (list)->cnt--;                                    \             }                                                      \         } else if ((list)->tail == (entry)) {                     \             if ((list)->tail) {                                   \                 (list)->tail = (list)->tail->prev;               \                 if ((list)->tail) {                               \                     (list)->tail->next = (osal_list_entry_t *)0; \                 } else {                                           \                     (list)->head = (osal_list_entry_t *)0;       \                 }                                                  \                 (list)->cnt--;                                    \             }                                                      \         } else {                                                   \             (entry)->prev->next = (entry)->next;                   \             (entry)->next->prev = (entry)->prev;                   \             (list)->cnt--;                                        \         }                                                          \     } while (0)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_IS_EMPTY
parameter_list|(
name|list
parameter_list|)
define|\
value|((list)->cnt == 0)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_NEXT
parameter_list|(
name|entry
parameter_list|,
name|field
parameter_list|,
name|type
parameter_list|)
define|\
value|(type *)((&((entry)->field))->next)
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_FOR_EACH_ENTRY
parameter_list|(
name|entry
parameter_list|,
name|list
parameter_list|,
name|field
parameter_list|,
name|type
parameter_list|)
define|\
value|for (entry = OSAL_LIST_FIRST_ENTRY(list, type, field); \ 		entry;                                              \ 		entry = OSAL_LIST_NEXT(entry, field, type))
end_define

begin_define
define|#
directive|define
name|OSAL_LIST_FOR_EACH_ENTRY_SAFE
parameter_list|(
name|entry
parameter_list|,
name|tmp_entry
parameter_list|,
name|list
parameter_list|,
name|field
parameter_list|,
name|type
parameter_list|)
define|\
value|for (entry = OSAL_LIST_FIRST_ENTRY(list, type, field),        \           tmp_entry = (entry) ? OSAL_LIST_NEXT(entry, field, type) : NULL;    \           entry != NULL;                                             \           entry = (type *)tmp_entry,                                         \           tmp_entry = (entry) ? OSAL_LIST_NEXT(entry, field, type) : NULL)
end_define

begin_define
define|#
directive|define
name|OSAL_BAR_SIZE
parameter_list|(
name|dev
parameter_list|,
name|bar_id
parameter_list|)
value|qlnx_pci_bus_get_bar_size(dev, bar_id)
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_READ_CONFIG_BYTE
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_read_config_byte(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_READ_CONFIG_WORD
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_read_config_word(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_READ_CONFIG_DWORD
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_read_config_dword(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_WRITE_CONFIG_BYTE
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_write_config_byte(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_WRITE_CONFIG_WORD
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_write_config_word(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_WRITE_CONFIG_DWORD
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|qlnx_pci_write_config_dword(dev, reg, value);
end_define

begin_define
define|#
directive|define
name|OSAL_PCI_FIND_CAPABILITY
parameter_list|(
name|dev
parameter_list|,
name|cap
parameter_list|)
value|qlnx_pci_find_capability(dev, cap);
end_define

begin_define
define|#
directive|define
name|OSAL_MMIOWB
parameter_list|(
name|dev
parameter_list|)
value|qlnx_barrier(dev)
end_define

begin_define
define|#
directive|define
name|OSAL_BARRIER
parameter_list|(
name|dev
parameter_list|)
value|qlnx_barrier(dev)
end_define

begin_define
define|#
directive|define
name|OSAL_SMP_MB
parameter_list|(
name|dev
parameter_list|)
value|mb()
end_define

begin_define
define|#
directive|define
name|OSAL_SMP_RMB
parameter_list|(
name|dev
parameter_list|)
value|rmb()
end_define

begin_define
define|#
directive|define
name|OSAL_SMP_WMB
parameter_list|(
name|dev
parameter_list|)
value|wmb()
end_define

begin_define
define|#
directive|define
name|OSAL_RMB
parameter_list|(
name|dev
parameter_list|)
value|rmb()
end_define

begin_define
define|#
directive|define
name|OSAL_WMB
parameter_list|(
name|dev
parameter_list|)
value|wmb()
end_define

begin_define
define|#
directive|define
name|OSAL_DMA_SYNC
parameter_list|(
name|dev
parameter_list|,
name|addr
parameter_list|,
name|length
parameter_list|,
name|is_post
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSAL_FIND_FIRST_BIT
value|find_first_bit
end_define

begin_define
define|#
directive|define
name|OSAL_SET_BIT
parameter_list|(
name|bit
parameter_list|,
name|bitmap
parameter_list|)
value|bit_set((bitstr_t *)bitmap, bit)
end_define

begin_define
define|#
directive|define
name|OSAL_CLEAR_BIT
parameter_list|(
name|bit
parameter_list|,
name|bitmap
parameter_list|)
value|bit_clear((bitstr_t *)bitmap, bit)
end_define

begin_define
define|#
directive|define
name|OSAL_TEST_BIT
parameter_list|(
name|bit
parameter_list|,
name|bitmap
parameter_list|)
value|bit_test((bitstr_t *)bitmap, bit)
end_define

begin_define
define|#
directive|define
name|OSAL_FIND_FIRST_ZERO_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|length
parameter_list|)
define|\
value|find_first_zero_bit(bitmap, length)
end_define

begin_define
define|#
directive|define
name|OSAL_LINK_UPDATE
parameter_list|(
name|hwfn
parameter_list|)
value|qlnx_link_update(hwfn)
end_define

begin_define
define|#
directive|define
name|OSAL_VF_FLR_UPDATE
parameter_list|(
name|hwfn
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QLNX_DIV_ROUND_UP
parameter_list|(
name|n
parameter_list|,
name|d
parameter_list|)
value|(((n) + (d) - 1) / (d))
end_define

begin_define
define|#
directive|define
name|QLNX_ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x) + ((y) - 1)) / (y)) * (y))
end_define

begin_define
define|#
directive|define
name|OSAL_NUM_ACTIVE_CPU
parameter_list|()
value|mp_ncpus
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DIV_ROUND_UP
end_ifndef

begin_define
define|#
directive|define
name|DIV_ROUND_UP
parameter_list|(
name|size
parameter_list|,
name|to_what
parameter_list|)
value|QLNX_DIV_ROUND_UP((size), (to_what))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|value
parameter_list|,
name|to_what
parameter_list|)
value|QLNX_ROUNDUP((value), (to_what))
end_define

begin_define
define|#
directive|define
name|OSAL_ROUNDUP_POW_OF_TWO
parameter_list|(
name|val
parameter_list|)
value|roundup_pow_of_two((val))
end_define

begin_function
specifier|static
name|__inline
name|uint32_t
name|qlnx_log2
parameter_list|(
name|uint32_t
name|x
parameter_list|)
block|{
name|uint32_t
name|log
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|x
operator|>>=
literal|1
condition|)
name|log
operator|++
expr_stmt|;
return|return
operator|(
name|log
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|OSAL_LOG2
parameter_list|(
name|val
parameter_list|)
value|qlnx_log2(val)
end_define

begin_define
define|#
directive|define
name|OFFSETOF
parameter_list|(
name|str
parameter_list|,
name|field
parameter_list|)
value|offsetof(str, field)
end_define

begin_define
define|#
directive|define
name|PRINT
value|device_printf
end_define

begin_define
define|#
directive|define
name|PRINT_ERR
value|device_printf
end_define

begin_define
define|#
directive|define
name|OSAL_ASSERT
parameter_list|(
name|is_assert
parameter_list|)
value|nothing
end_define

begin_define
define|#
directive|define
name|OSAL_BEFORE_PF_START
parameter_list|(
name|cdev
parameter_list|,
name|my_id
parameter_list|)
value|{};
end_define

begin_define
define|#
directive|define
name|OSAL_AFTER_PF_STOP
parameter_list|(
name|cdev
parameter_list|,
name|my_id
parameter_list|)
value|{};
end_define

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_define
define|#
directive|define
name|OSAL_INLINE
value|__inline
end_define

begin_define
define|#
directive|define
name|OSAL_UNLIKELY
end_define

begin_define
define|#
directive|define
name|OSAL_NULL
value|NULL
end_define

begin_define
define|#
directive|define
name|OSAL_MAX_T
parameter_list|(
name|type
parameter_list|,
name|__max1
parameter_list|,
name|__max2
parameter_list|)
value|max_t(type, __max1, __max2)
end_define

begin_define
define|#
directive|define
name|OSAL_MIN_T
parameter_list|(
name|type
parameter_list|,
name|__max1
parameter_list|,
name|__max2
parameter_list|)
value|min_t(type, __max1, __max2)
end_define

begin_define
define|#
directive|define
name|__iomem
end_define

begin_define
define|#
directive|define
name|OSAL_IOMEM
end_define

begin_define
define|#
directive|define
name|int_ptr_t
value|void *
end_define

begin_define
define|#
directive|define
name|osal_int_ptr_t
value|void *
end_define

begin_define
define|#
directive|define
name|OSAL_BUILD_BUG_ON
parameter_list|(
name|cond
parameter_list|)
value|nothing
end_define

begin_define
define|#
directive|define
name|REG_ADDR
parameter_list|(
name|hwfn
parameter_list|,
name|offset
parameter_list|)
value|(void *)((u8 *)(hwfn->regview) + (offset))
end_define

begin_define
define|#
directive|define
name|OSAL_REG_ADDR
parameter_list|(
name|hwfn
parameter_list|,
name|offset
parameter_list|)
value|(void *)((u8 *)(hwfn->regview) + (offset))
end_define

begin_define
define|#
directive|define
name|OSAL_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|OSAL_STRCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|strcpy(dst, src)
end_define

begin_define
define|#
directive|define
name|OSAL_STRNCPY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|bytes
parameter_list|)
value|strncpy(dst, src, bytes)
end_define

begin_define
define|#
directive|define
name|OSAL_STRLEN
parameter_list|(
name|src
parameter_list|)
value|strlen(src)
end_define

begin_define
define|#
directive|define
name|OSAL_SPRINTF
value|sprintf
end_define

begin_define
define|#
directive|define
name|OSAL_SNPRINTF
value|snprintf
end_define

begin_define
define|#
directive|define
name|OSAL_MEMSET
value|memset
end_define

begin_define
define|#
directive|define
name|OSAL_ARRAY_SIZE
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof(arr[0]))
end_define

begin_define
define|#
directive|define
name|osal_uintptr_t
value|u64
end_define

begin_define
define|#
directive|define
name|OSAL_SLOWPATH_IRQ_REQ
parameter_list|(
name|p_hwfn
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|OSAL_GET_PROTOCOL_STATS
parameter_list|(
name|p_hwfn
parameter_list|,
name|type
parameter_list|,
name|stats
parameter_list|)
define|\
value|qlnx_get_protocol_stats(p_hwfn, type, stats);
end_define

begin_define
define|#
directive|define
name|OSAL_POLL_MODE_DPC
parameter_list|(
name|hwfn
parameter_list|)
value|{if (cold) qlnx_sp_isr(hwfn);}
end_define

begin_define
define|#
directive|define
name|OSAL_WARN
parameter_list|(
name|cond
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (cond) printf("%s: WARNING: " fmt, __func__, ## args);
end_define

begin_define
define|#
directive|define
name|OSAL_BITMAP_WEIGHT
parameter_list|(
name|bitmap
parameter_list|,
name|nbits
parameter_list|)
value|bitmap_weight(bitmap, nbits)
end_define

begin_define
define|#
directive|define
name|OSAL_GET_RDMA_SB_ID
parameter_list|(
name|p_hwfn
parameter_list|,
name|cnq_id
parameter_list|)
value|ecore_rdma_get_sb_id(p_hwfn, cnq_id)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|qlnx_test_and_change_bit
parameter_list|(
name|long
name|bit
parameter_list|,
specifier|volatile
name|unsigned
name|long
modifier|*
name|var
parameter_list|)
block|{
name|long
name|val
decl_stmt|;
name|var
operator|+=
name|BIT_WORD
argument_list|(
name|bit
argument_list|)
expr_stmt|;
name|bit
operator|%=
name|BITS_PER_LONG
expr_stmt|;
name|bit
operator|=
operator|(
literal|1UL
operator|<<
name|bit
operator|)
expr_stmt|;
name|val
operator|=
operator|*
name|var
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|1100000
if|if
condition|(
name|val
operator|&
name|bit
condition|)
return|return
operator|(
name|test_and_clear_bit
argument_list|(
name|bit
argument_list|,
name|var
argument_list|)
operator|)
return|;
return|return
operator|(
name|test_and_set_bit
argument_list|(
name|bit
argument_list|,
name|var
argument_list|)
operator|)
return|;
else|#
directive|else
if|if
condition|(
name|val
operator|&
name|bit
condition|)
return|return
operator|(
name|test_and_clear_bit
argument_list|(
name|bit
argument_list|,
operator|(
name|long
operator|*
operator|)
name|var
argument_list|)
operator|)
return|;
return|return
operator|(
name|test_and_set_bit
argument_list|(
name|bit
argument_list|,
operator|(
name|long
operator|*
operator|)
name|var
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|1100000
end_if

begin_function
specifier|static
specifier|inline
name|unsigned
name|bitmap_weight
parameter_list|(
name|unsigned
name|long
modifier|*
name|bitmap
parameter_list|,
name|unsigned
name|nbits
parameter_list|)
block|{
name|unsigned
name|bit
decl_stmt|;
name|unsigned
name|retval
init|=
literal|0
decl_stmt|;
name|for_each_set_bit
argument_list|(
argument|bit
argument_list|,
argument|bitmap
argument_list|,
argument|nbits
argument_list|)
name|retval
operator|++
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OSAL_TEST_AND_FLIP_BIT
value|qlnx_test_and_change_bit
end_define

begin_define
define|#
directive|define
name|OSAL_TEST_AND_CLEAR_BIT
value|test_and_clear_bit
end_define

begin_define
define|#
directive|define
name|OSAL_MEMCMP
value|memcmp
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_LOCK_IRQSAVE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{y=0; mtx_lock(x);}
end_define

begin_define
define|#
directive|define
name|OSAL_SPIN_UNLOCK_IRQSAVE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{y= 0; mtx_unlock(x);}
end_define

begin_function
specifier|static
specifier|inline
name|u32
name|OSAL_CRC32
parameter_list|(
name|u32
name|crc
parameter_list|,
name|u8
modifier|*
name|ptr
parameter_list|,
name|u32
name|length
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
while|while
condition|(
name|length
operator|--
condition|)
block|{
name|crc
operator|^=
operator|*
name|ptr
operator|++
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
name|crc
operator|=
operator|(
name|crc
operator|>>
literal|1
operator|)
operator|^
operator|(
operator|(
name|crc
operator|&
literal|1
operator|)
condition|?
literal|0xedb88320
else|:
literal|0
operator|)
expr_stmt|;
block|}
return|return
name|crc
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|OSAL_CRC8_POPULATE
parameter_list|(
name|u8
modifier|*
name|cdu_crc8_table
parameter_list|,
name|u8
name|polynomial
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|u8
name|OSAL_CRC8
parameter_list|(
name|u8
modifier|*
name|cdu_crc8_table
parameter_list|,
name|u8
modifier|*
name|data_to_crc
parameter_list|,
name|int
name|data_to_crc_len
parameter_list|,
name|u8
name|init_value
parameter_list|)
block|{
return|return
name|ECORE_NOTIMPL
return|;
block|}
end_function

begin_define
define|#
directive|define
name|OSAL_HW_INFO_CHANGE
parameter_list|(
name|p_hwfn
parameter_list|,
name|offset
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSAL_MFW_TLV_REQ
parameter_list|(
name|p_hwfn
parameter_list|)
end_define

begin_define
define|#
directive|define
name|OSAL_VF_FILL_ACQUIRE_RESC_REQ
parameter_list|(
name|p_hwfn
parameter_list|,
name|req
parameter_list|,
name|vf_sw_info
parameter_list|)
value|{};
end_define

begin_define
define|#
directive|define
name|OSAL_VF_UPDATE_ACQUIRE_RESC_RESP
parameter_list|(
name|p_hwfn
parameter_list|,
name|res
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef ECORE_PACKAGE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef __BCM_OSAL_ECORE_PACKAGE */
end_comment

end_unit

