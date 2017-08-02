begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * BSD LICENSE  *  * Copyright (c) 2015-2017 Amazon.com, Inc. or its affiliates.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * * Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in  * the documentation and/or other materials provided with the  * distribution.  * * Neither the name of copyright holder nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENA_PLAT_H_
end_ifndef

begin_define
define|#
directive|define
name|ENA_PLAT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/in_cksum.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
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
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
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
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip6.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<dev/led/led.h>
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

begin_decl_stmt
specifier|extern
name|struct
name|ena_bus_space
name|ebs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Levels */
end_comment

begin_define
define|#
directive|define
name|ENA_ALERT
value|(1<< 0)
end_define

begin_comment
comment|/* Alerts are providing more error info.     */
end_comment

begin_define
define|#
directive|define
name|ENA_WARNING
value|(1<< 1)
end_define

begin_comment
comment|/* Driver output is more error sensitive.    */
end_comment

begin_define
define|#
directive|define
name|ENA_INFO
value|(1<< 2)
end_define

begin_comment
comment|/* Provides additional driver info. 	      */
end_comment

begin_define
define|#
directive|define
name|ENA_DBG
value|(1<< 3)
end_define

begin_comment
comment|/* Driver output for debugging.	      */
end_comment

begin_comment
comment|/* Detailed info that will be printed with ENA_INFO or ENA_DEBUG flag. 	      */
end_comment

begin_define
define|#
directive|define
name|ENA_TXPTH
value|(1<< 4)
end_define

begin_comment
comment|/* Allows TX path tracing. 		      */
end_comment

begin_define
define|#
directive|define
name|ENA_RXPTH
value|(1<< 5)
end_define

begin_comment
comment|/* Allows RX path tracing.		      */
end_comment

begin_define
define|#
directive|define
name|ENA_RSC
value|(1<< 6)
end_define

begin_comment
comment|/* Goes with TXPTH or RXPTH, free/alloc res. */
end_comment

begin_define
define|#
directive|define
name|ENA_IOQ
value|(1<< 7)
end_define

begin_comment
comment|/* Detailed info about IO queues. 	      */
end_comment

begin_define
define|#
directive|define
name|ENA_ADMQ
value|(1<< 8)
end_define

begin_comment
comment|/* Detailed info about admin queue. 	      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENA_DEBUG_LEVEL
end_ifndef

begin_define
define|#
directive|define
name|ENA_DEBUG_LEVEL
value|(ENA_ALERT | ENA_WARNING)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENA_TRACE
end_ifdef

begin_define
define|#
directive|define
name|ena_trace_raw
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {							\ 		if (((level)& ENA_DEBUG_LEVEL) != (level))	\ 			break;					\ 		printf(fmt, ##args);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ena_trace
parameter_list|(
name|level
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|ena_trace_raw(level, "%s() [TID:%d]: "			\ 	    fmt " \n", __func__, curthread->td_tid, ##args)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ENA_TRACE */
end_comment

begin_define
define|#
directive|define
name|ena_trace_raw
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ena_trace
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENA_TRACE */
end_comment

begin_define
define|#
directive|define
name|ena_trc_dbg
parameter_list|(
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|ena_trace(ENA_DBG, format, ##arg)
end_define

begin_define
define|#
directive|define
name|ena_trc_info
parameter_list|(
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|ena_trace(ENA_INFO, format, ##arg)
end_define

begin_define
define|#
directive|define
name|ena_trc_warn
parameter_list|(
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|ena_trace(ENA_WARNING, format, ##arg)
end_define

begin_define
define|#
directive|define
name|ena_trc_err
parameter_list|(
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|ena_trace(ENA_ALERT, format, ##arg)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__predict_false(x)
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__predict_true(x)
end_define

begin_define
define|#
directive|define
name|__iomem
end_define

begin_define
define|#
directive|define
name|____cacheline_aligned
value|__aligned(CACHE_LINE_SIZE)
end_define

begin_define
define|#
directive|define
name|MAX_ERRNO
value|4095
end_define

begin_define
define|#
directive|define
name|IS_ERR_VALUE
parameter_list|(
name|x
parameter_list|)
value|unlikely((x)<= (unsigned long)MAX_ERRNO)
end_define

begin_define
define|#
directive|define
name|ENA_ASSERT
parameter_list|(
name|cond
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (unlikely(!(cond))) {				\ 			ena_trc_err(					\ 				"Assert failed on %s:%s:%d:" format,	\ 				__FILE__, __func__, __LINE__, ##arg);	\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_WARN
parameter_list|(
name|cond
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (unlikely((cond))) {					\ 			ena_trc_warn(format, ##arg);			\ 		}							\ 	} while (0)
end_define

begin_function
specifier|static
specifier|inline
name|long
name|IS_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|IS_ERR_VALUE
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|ptr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ERR_PTR
parameter_list|(
name|long
name|error
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|error
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|PTR_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
name|long
operator|)
name|ptr
return|;
block|}
end_function

begin_define
define|#
directive|define
name|GENMASK
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((1U<< ((h) - (l) + 1)) - 1)<< (l))
end_define

begin_define
define|#
directive|define
name|GENMASK_ULL
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((~0ULL)<< (l))& (~0ULL>> (64 - 1 - (h))))
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|ENA_ABORT
parameter_list|()
value|BUG()
end_define

begin_define
define|#
directive|define
name|BUG
parameter_list|()
value|panic("ENA BUG")
end_define

begin_define
define|#
directive|define
name|SZ_256
value|(256)
end_define

begin_define
define|#
directive|define
name|SZ_4K
value|(4096)
end_define

begin_define
define|#
directive|define
name|ENA_COM_OK
value|0
end_define

begin_define
define|#
directive|define
name|ENA_COM_FAULT
value|EFAULT
end_define

begin_define
define|#
directive|define
name|ENA_COM_INVAL
value|EINVAL
end_define

begin_define
define|#
directive|define
name|ENA_COM_NO_MEM
value|ENOMEM
end_define

begin_define
define|#
directive|define
name|ENA_COM_NO_SPACE
value|ENOSPC
end_define

begin_define
define|#
directive|define
name|ENA_COM_TRY_AGAIN
value|-1
end_define

begin_define
define|#
directive|define
name|ENA_COM_NO_DEVICE
value|ENODEV
end_define

begin_define
define|#
directive|define
name|ENA_COM_PERMISSION
value|EPERM
end_define

begin_define
define|#
directive|define
name|ENA_COM_TIMER_EXPIRED
value|ETIMEDOUT
end_define

begin_define
define|#
directive|define
name|ENA_MSLEEP
parameter_list|(
name|x
parameter_list|)
value|pause_sbt("ena", SBT_1MS * (x), SBT_1MS, 0)
end_define

begin_define
define|#
directive|define
name|ENA_UDELAY
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|ENA_GET_SYSTEM_TIMEOUT
parameter_list|(
name|timeout_us
parameter_list|)
define|\
value|((long)cputick2usec(cpu_ticks()) + (timeout_us))
end_define

begin_define
define|#
directive|define
name|ENA_TIME_EXPIRE
parameter_list|(
name|timeout
parameter_list|)
value|((timeout)< (long)cputick2usec(cpu_ticks()))
end_define

begin_define
define|#
directive|define
name|ENA_MIGHT_SLEEP
parameter_list|()
end_define

begin_define
define|#
directive|define
name|min_t
parameter_list|(
name|type
parameter_list|,
name|_x
parameter_list|,
name|_y
parameter_list|)
value|((type)(_x)< (type)(_y) ? (type)(_x) : (type)(_y))
end_define

begin_define
define|#
directive|define
name|max_t
parameter_list|(
name|type
parameter_list|,
name|_x
parameter_list|,
name|_y
parameter_list|)
value|((type)(_x)> (type)(_y) ? (type)(_x) : (type)(_y))
end_define

begin_define
define|#
directive|define
name|ENA_MIN32
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MIN(x, y)
end_define

begin_define
define|#
directive|define
name|ENA_MIN16
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MIN(x, y)
end_define

begin_define
define|#
directive|define
name|ENA_MIN8
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MIN(x, y)
end_define

begin_define
define|#
directive|define
name|ENA_MAX32
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MAX(x, y)
end_define

begin_define
define|#
directive|define
name|ENA_MAX16
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MAX(x, y)
end_define

begin_define
define|#
directive|define
name|ENA_MAX8
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|MAX(x, y)
end_define

begin_comment
comment|/* Spinlock related methods */
end_comment

begin_define
define|#
directive|define
name|ena_spinlock_t
value|struct mtx
end_define

begin_define
define|#
directive|define
name|ENA_SPINLOCK_INIT
parameter_list|(
name|spinlock
parameter_list|)
define|\
value|mtx_init(&(spinlock), "ena_spin", NULL, MTX_SPIN)
end_define

begin_define
define|#
directive|define
name|ENA_SPINLOCK_DESTROY
parameter_list|(
name|spinlock
parameter_list|)
define|\
value|do {							\ 		if (mtx_initialized(&(spinlock)))		\ 		    mtx_destroy(&(spinlock));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_SPINLOCK_LOCK
parameter_list|(
name|spinlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {							\ 		(void)(flags);					\ 		mtx_lock_spin(&(spinlock));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_SPINLOCK_UNLOCK
parameter_list|(
name|spinlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {							\ 		(void)(flags);					\ 		mtx_unlock_spin(&(spinlock));			\ 	} while (0)
end_define

begin_comment
comment|/* Wait queue related methods */
end_comment

begin_define
define|#
directive|define
name|ena_wait_event_t
value|struct { struct cv wq; struct mtx mtx; }
end_define

begin_define
define|#
directive|define
name|ENA_WAIT_EVENT_INIT
parameter_list|(
name|waitqueue
parameter_list|)
define|\
value|do {								\ 		cv_init(&((waitqueue).wq), "cv");			\ 		mtx_init(&((waitqueue).mtx), "wq", NULL, MTX_DEF);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_WAIT_EVENT_DESTROY
parameter_list|(
name|waitqueue
parameter_list|)
define|\
value|do {								\ 		cv_destroy(&((waitqueue).wq));				\ 		mtx_destroy(&((waitqueue).mtx));			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_WAIT_EVENT_CLEAR
parameter_list|(
name|waitqueue
parameter_list|)
define|\
value|cv_init(&((waitqueue).wq), (waitqueue).wq.cv_description)
end_define

begin_define
define|#
directive|define
name|ENA_WAIT_EVENT_WAIT
parameter_list|(
name|waitqueue
parameter_list|,
name|timeout_us
parameter_list|)
define|\
value|do {								\ 		mtx_lock(&((waitqueue).mtx));				\ 		cv_timedwait(&((waitqueue).wq),&((waitqueue).mtx),	\ 		    timeout_us * hz / 1000 / 1000 );			\ 		mtx_unlock(&((waitqueue).mtx));				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_WAIT_EVENT_SIGNAL
parameter_list|(
name|waitqueue
parameter_list|)
value|cv_broadcast(&((waitqueue).wq))
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|bus_addr_t
name|paddr
decl_stmt|;
name|caddr_t
name|vaddr
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_dma_segment_t
name|seg
decl_stmt|;
name|int
name|nseg
decl_stmt|;
block|}
name|ena_mem_handle_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ena_bus
block|{
name|bus_space_handle_t
name|reg_bar_h
decl_stmt|;
name|bus_space_tag_t
name|reg_bar_t
decl_stmt|;
name|bus_space_handle_t
name|mem_bar_h
decl_stmt|;
name|bus_space_tag_t
name|mem_bar_t
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint32_t
name|ena_atomic32_t
typedef|;
end_typedef

begin_function_decl
name|void
name|ena_dmamap_callback
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
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ena_dma_alloc
parameter_list|(
name|device_t
name|dmadev
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|ena_mem_handle_t
modifier|*
name|dma
parameter_list|,
name|int
name|mapflags
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ENA_MEM_ALLOC
parameter_list|(
name|dmadev
parameter_list|,
name|size
parameter_list|)
value|malloc(size, M_DEVBUF, M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|ENA_MEM_ALLOC_NODE
parameter_list|(
name|dmadev
parameter_list|,
name|size
parameter_list|,
name|virt
parameter_list|,
name|node
parameter_list|,
name|dev_node
parameter_list|)
value|(virt = NULL)
end_define

begin_define
define|#
directive|define
name|ENA_MEM_FREE
parameter_list|(
name|dmadev
parameter_list|,
name|ptr
parameter_list|)
value|free(ptr, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|ENA_MEM_ALLOC_COHERENT_NODE
parameter_list|(
name|dmadev
parameter_list|,
name|size
parameter_list|,
name|virt
parameter_list|,
name|phys
parameter_list|,
name|handle
parameter_list|,
name|node
parameter_list|, \
name|dev_node
parameter_list|)
define|\
value|do {								\ 		((virt) = NULL);					\ 		(void)(dev_node);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_MEM_ALLOC_COHERENT
parameter_list|(
name|dmadev
parameter_list|,
name|size
parameter_list|,
name|virt
parameter_list|,
name|phys
parameter_list|,
name|dma
parameter_list|)
define|\
value|do {								\ 		ena_dma_alloc((dmadev), (size),&(dma), 0);		\ 		(virt) = (void *)(dma).vaddr;				\ 		(phys) = (dma).paddr;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENA_MEM_FREE_COHERENT
parameter_list|(
name|dmadev
parameter_list|,
name|size
parameter_list|,
name|virt
parameter_list|,
name|phys
parameter_list|,
name|dma
parameter_list|)
define|\
value|do {								\ 		(void)size;						\ 		bus_dmamap_unload((dma).tag, (dma).map);		\ 		bus_dmamem_free((dma).tag, (virt), (dma).map);		\ 		bus_dma_tag_destroy((dma).tag);				\ 		(dma).tag = NULL;					\ 		(virt) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/* Register R/W methods */
end_comment

begin_define
define|#
directive|define
name|ENA_REG_WRITE32
parameter_list|(
name|bus
parameter_list|,
name|value
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_write_4(						\ 			  ((struct ena_bus*)bus)->reg_bar_t,		\ 			  ((struct ena_bus*)bus)->reg_bar_h,		\ 			  (bus_size_t)(offset), (value))
end_define

begin_define
define|#
directive|define
name|ENA_REG_READ32
parameter_list|(
name|bus
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(						\ 			 ((struct ena_bus*)bus)->reg_bar_t,		\ 			 ((struct ena_bus*)bus)->reg_bar_h,		\ 			 (bus_size_t)(offset))
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)((unsigned long)(b) - (unsigned long)(a))< 0)
end_define

begin_define
define|#
directive|define
name|VLAN_HLEN
value|sizeof(struct ether_vlan_header)
end_define

begin_define
define|#
directive|define
name|CSUM_OFFLOAD
value|(CSUM_IP|CSUM_TCP|CSUM_UDP)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|prefetch
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DMA buffers access */
end_comment

begin_define
define|#
directive|define
name|dma_unmap_addr
parameter_list|(
name|p
parameter_list|,
name|name
parameter_list|)
value|((p)->dma->name)
end_define

begin_define
define|#
directive|define
name|dma_unmap_addr_set
parameter_list|(
name|p
parameter_list|,
name|name
parameter_list|,
name|v
parameter_list|)
value|(((p)->dma->name) = (v))
end_define

begin_define
define|#
directive|define
name|dma_unmap_len
parameter_list|(
name|p
parameter_list|,
name|name
parameter_list|)
value|((p)->name)
end_define

begin_define
define|#
directive|define
name|dma_unmap_len_set
parameter_list|(
name|p
parameter_list|,
name|name
parameter_list|,
name|v
parameter_list|)
value|(((p)->name) = (v))
end_define

begin_define
define|#
directive|define
name|memcpy_toio
value|memcpy
end_define

begin_define
define|#
directive|define
name|ATOMIC32_INC
parameter_list|(
name|I32_PTR
parameter_list|)
value|atomic_add_int(I32_PTR, 1)
end_define

begin_define
define|#
directive|define
name|ATOMIC32_DEC
parameter_list|(
name|I32_PTR
parameter_list|)
value|atomic_add_int(I32_PTR, -1)
end_define

begin_define
define|#
directive|define
name|ATOMIC32_READ
parameter_list|(
name|I32_PTR
parameter_list|)
value|atomic_load_acq_int(I32_PTR)
end_define

begin_define
define|#
directive|define
name|ATOMIC32_SET
parameter_list|(
name|I32_PTR
parameter_list|,
name|VAL
parameter_list|)
value|atomic_store_rel_int(I32_PTR, VAL)
end_define

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__asm__ __volatile__("": : :"memory")
end_define

begin_define
define|#
directive|define
name|ACCESS_ONCE
parameter_list|(
name|x
parameter_list|)
value|(*(volatile __typeof(x) *)&(x))
end_define

begin_define
define|#
directive|define
name|READ_ONCE
parameter_list|(
name|x
parameter_list|)
value|({			\ 			__typeof(x) __var;	\ 			barrier();		\ 			__var = ACCESS_ONCE(x);	\ 			barrier();		\ 			__var;			\ 		})
end_define

begin_include
include|#
directive|include
file|"ena_common_defs.h"
end_include

begin_include
include|#
directive|include
file|"ena_admin_defs.h"
end_include

begin_include
include|#
directive|include
file|"ena_eth_io_defs.h"
end_include

begin_include
include|#
directive|include
file|"ena_regs_defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENA_PLAT_H_ */
end_comment

end_unit

