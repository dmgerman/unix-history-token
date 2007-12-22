begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<dev/rr232x/rr232x_config.h>
end_include

begin_comment
comment|/*  * $Id: osm.h,v 1.5 2005/08/18 05:17:43 gmm Exp $  * Copyright (C) 2005 HighPoint Technologies, Inc. All rights reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HPT_OSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_HPT_OSM_H_
end_define

begin_define
define|#
directive|define
name|VERMAGIC_OSM
value|5
end_define

begin_define
define|#
directive|define
name|os_max_queue_comm
value|32
end_define

begin_define
define|#
directive|define
name|os_max_sg_descriptors
value|18
end_define

begin_define
define|#
directive|define
name|DMAPOOL_PAGE_SIZE
value|0x1000
end_define

begin_comment
comment|/* PAGE_SIZE (i386/x86_64) */
end_comment

begin_define
define|#
directive|define
name|os_max_cache_size
value|0x800000
end_define

begin_comment
comment|/* 8MB */
end_comment

begin_define
define|#
directive|define
name|os_max_cache_pages
value|(os_max_cache_size/DMAPOOL_PAGE_SIZE)
end_define

begin_comment
comment|/* data types */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|HPT_UINT
typedef|,
name|HPT_U32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|HPT_UPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|HPT_U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|HPT_U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|HPT_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|HPT_U64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CPU_TO_LE64
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|CPU_TO_LE32
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|CPU_TO_LE16
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|LE32_TO_CPU
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|LE16_TO_CPU
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|LE64_TO_CPU
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|FAR
end_define

begin_define
define|#
directive|define
name|EXTERN_C
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|HPT_PTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HPT_U64
name|HPT_LBA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HPT_U32
name|HPT_RAW_LBA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_LBA_VALUE
value|0xffffffffffffffffull
end_define

begin_define
define|#
directive|define
name|MAX_RAW_LBA_VALUE
value|0xfffffffful
end_define

begin_define
define|#
directive|define
name|RAW_LBA
parameter_list|(
name|x
parameter_list|)
value|((HPT_U32)(x))
end_define

begin_define
define|#
directive|define
name|LO_LBA
parameter_list|(
name|x
parameter_list|)
value|((HPT_U32)(x))
end_define

begin_define
define|#
directive|define
name|HI_LBA
parameter_list|(
name|x
parameter_list|)
value|(sizeof(HPT_LBA)>4? (HPT_U32)((x)>>32) : 0)
end_define

begin_define
define|#
directive|define
name|LBA_FORMAT_STR
value|"0x%llX"
end_define

begin_typedef
typedef|typedef
name|HPT_U64
name|BUS_ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LO_BUSADDR
parameter_list|(
name|x
parameter_list|)
value|((HPT_U32)(x))
end_define

begin_define
define|#
directive|define
name|HI_BUSADDR
parameter_list|(
name|x
parameter_list|)
value|(sizeof(BUS_ADDRESS)>4? (x)>>32 : 0)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|HPT_BOOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HPT_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|HPT_FALSE
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|_TIME_RECORD
block|{
name|HPT_U32
name|seconds
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|HPT_U32
name|minutes
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|HPT_U32
name|month
range|:
literal|4
decl_stmt|;
comment|/* 1 - 12 */
name|HPT_U32
name|hours
range|:
literal|6
decl_stmt|;
comment|/* 0 - 59 */
name|HPT_U32
name|day
range|:
literal|5
decl_stmt|;
comment|/* 1 - 31 */
name|HPT_U32
name|year
range|:
literal|5
decl_stmt|;
comment|/* 0=2000, 31=2031 */
block|}
name|TIME_RECORD
typedef|;
end_typedef

begin_comment
comment|/* hardware access */
end_comment

begin_function_decl
name|HPT_U8
name|os_inb
parameter_list|(
name|void
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_U16
name|os_inw
parameter_list|(
name|void
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_U32
name|os_inl
parameter_list|(
name|void
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_outb
parameter_list|(
name|void
modifier|*
name|port
parameter_list|,
name|HPT_U8
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_outw
parameter_list|(
name|void
modifier|*
name|port
parameter_list|,
name|HPT_U16
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_outl
parameter_list|(
name|void
modifier|*
name|port
parameter_list|,
name|HPT_U32
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_insw
parameter_list|(
name|void
modifier|*
name|port
parameter_list|,
name|HPT_U16
modifier|*
name|buffer
parameter_list|,
name|HPT_U32
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_outsw
parameter_list|(
name|void
modifier|*
name|port
parameter_list|,
name|HPT_U16
modifier|*
name|buffer
parameter_list|,
name|HPT_U32
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|HPT_U32
name|__dummy_reg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to avoid the compiler warning */
end_comment

begin_define
define|#
directive|define
name|os_readb
parameter_list|(
name|addr
parameter_list|)
value|(*(HPT_U8 *)&__dummy_reg = *(volatile HPT_U8 *)(addr))
end_define

begin_define
define|#
directive|define
name|os_readw
parameter_list|(
name|addr
parameter_list|)
value|(*(HPT_U16 *)&__dummy_reg = *(volatile HPT_U16 *)(addr))
end_define

begin_define
define|#
directive|define
name|os_readl
parameter_list|(
name|addr
parameter_list|)
value|(*(HPT_U32 *)&__dummy_reg = *(volatile HPT_U32 *)(addr))
end_define

begin_define
define|#
directive|define
name|os_writeb
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
value|*(volatile HPT_U8 *)(addr) = (HPT_U8)(val)
end_define

begin_define
define|#
directive|define
name|os_writew
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
value|*(volatile HPT_U16 *)(addr) = (HPT_U16)(val)
end_define

begin_define
define|#
directive|define
name|os_writel
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
value|*(volatile HPT_U32 *)(addr) = (HPT_U32)(val)
end_define

begin_comment
comment|/* PCI configuration space for specified device*/
end_comment

begin_function_decl
name|HPT_U8
name|os_pci_readb
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_U16
name|os_pci_readw
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_U32
name|os_pci_readl
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_pci_writeb
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|,
name|HPT_U8
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_pci_writew
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|,
name|HPT_U16
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_pci_writel
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U8
name|offset
parameter_list|,
name|HPT_U32
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsolute interface */
end_comment

begin_define
define|#
directive|define
name|MAX_PCI_BUS_NUMBER
value|0xff
end_define

begin_define
define|#
directive|define
name|MAX_PCI_DEVICE_NUMBER
value|32
end_define

begin_define
define|#
directive|define
name|MAX_PCI_FUNC_NUMBER
value|8
end_define

begin_define
define|#
directive|define
name|pcicfg_read_dword
parameter_list|(
name|bus
parameter_list|,
name|dev
parameter_list|,
name|fn
parameter_list|,
name|reg
parameter_list|)
value|0xffff
end_define

begin_function_decl
name|void
modifier|*
name|os_map_pci_bar
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|int
name|index
parameter_list|,
name|HPT_U32
name|offset
parameter_list|,
name|HPT_U32
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_unmap_pci_bar
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|void
modifier|*
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|os_kmap_sgptr
parameter_list|(
name|psg
parameter_list|)
value|(psg->addr._logical)
end_define

begin_define
define|#
directive|define
name|os_kunmap_sgptr
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|os_set_sgptr
parameter_list|(
name|psg
parameter_list|,
name|ptr
parameter_list|)
value|(psg)->addr._logical = (ptr)
end_define

begin_comment
comment|/* timer */
end_comment

begin_function_decl
name|void
modifier|*
name|os_add_timer
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U32
name|microseconds
parameter_list|,
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_del_timer
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_request_timer
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|HPT_U32
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_TIME
name|os_query_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* task */
end_comment

begin_define
define|#
directive|define
name|OS_SUPPORT_TASK
end_define

begin_typedef
typedef|typedef
struct|struct
name|_OSM_TASK
block|{
name|struct
name|_OSM_TASK
modifier|*
name|next
decl_stmt|;
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|vbus
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|OSM_TASK
typedef|;
end_typedef

begin_function_decl
name|void
name|os_schedule_task
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|OSM_TASK
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* misc */
end_comment

begin_function_decl
name|HPT_U32
name|os_get_stamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|os_stallexec
parameter_list|(
name|HPT_U32
name|microseconds
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LIBKERN_H_
end_ifndef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|__builtin_memcpy((dst), (src), (size))
end_define

begin_define
define|#
directive|define
name|memcmp
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
value|__builtin_memcmp((dst), (src), (size))
end_define

begin_define
define|#
directive|define
name|strcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|__builtin_strcpy((dst), (src))
end_define

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|int
name|c
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
operator|(
name|char
operator|*
operator|)
name|dst
init|;
name|size
condition|;
name|size
operator|--
operator|,
name|p
operator|++
control|)
operator|*
name|p
operator|=
name|c
expr_stmt|;
return|return
name|dst
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
name|farMemoryCopy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|memcpy((char *)(a), (char *)(b), (HPT_U32)c)
end_define

begin_define
define|#
directive|define
name|os_register_device
parameter_list|(
name|osext
parameter_list|,
name|target_id
parameter_list|)
end_define

begin_define
define|#
directive|define
name|os_unregister_device
parameter_list|(
name|osext
parameter_list|,
name|target_id
parameter_list|)
end_define

begin_function_decl
name|int
name|os_query_remove_device
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|int
name|target_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|os_revalidate_device
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|,
name|int
name|target_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HPT_U8
name|os_get_vbus_seq
parameter_list|(
name|void
modifier|*
name|osext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* debug support */
end_comment

begin_function_decl
name|int
name|os_printk
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|DBG
end_if

begin_decl_stmt
specifier|extern
name|int
name|hpt_dbg_level
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KdPrint
parameter_list|(
name|x
parameter_list|)
value|do { if (hpt_dbg_level) os_printk x; } while (0)
end_define

begin_function_decl
name|void
name|__os_dbgbreak
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|os_dbgbreak
parameter_list|()
value|__os_dbgbreak(__FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|HPT_ASSERT
parameter_list|(
name|x
parameter_list|)
value|do { if (!(x)) os_dbgbreak(); } while (0)
end_define

begin_function_decl
name|void
name|os_check_stack
parameter_list|(
specifier|const
name|char
modifier|*
name|location
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HPT_CHECK_STACK
parameter_list|(
name|size
parameter_list|)
value|os_check_stack(__FUNCTION__, (size))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KdPrint
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HPT_ASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HPT_CHECK_STACK
parameter_list|(
name|size
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OsPrint
parameter_list|(
name|x
parameter_list|)
value|do { os_printk x; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

