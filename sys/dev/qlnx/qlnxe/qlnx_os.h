begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * File: qlnx_os.h  * Author : David C Somayajulu, Cavium, Inc., San Jose, CA 95131.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLNX_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLNX_OS_H_
end_define

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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/_inttypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|1000000
end_if

begin_error
error|#
directive|error
error|FreeBSD Version not supported - use version>= 1000000
end_error

begin_endif
endif|#
directive|endif
end_endif

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
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
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
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_function
specifier|static
name|__inline
name|int
name|qlnx_ms_to_hz
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
name|int
name|qlnx_hz
decl_stmt|;
name|struct
name|timeval
name|t
decl_stmt|;
name|t
operator|.
name|tv_sec
operator|=
name|ms
operator|/
literal|1000
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|=
operator|(
name|ms
operator|%
literal|1000
operator|)
operator|*
literal|1000
expr_stmt|;
name|qlnx_hz
operator|=
name|tvtohz
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
if|if
condition|(
name|qlnx_hz
operator|<
literal|0
condition|)
name|qlnx_hz
operator|=
literal|0x7fffffff
expr_stmt|;
if|if
condition|(
operator|!
name|qlnx_hz
condition|)
name|qlnx_hz
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|qlnx_hz
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|qlnx_sec_to_hz
parameter_list|(
name|int
name|sec
parameter_list|)
block|{
name|struct
name|timeval
name|t
decl_stmt|;
name|t
operator|.
name|tv_sec
operator|=
name|sec
expr_stmt|;
name|t
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|tvtohz
argument_list|(
operator|&
name|t
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_QLNXBUF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|qlnx_mdelay
parameter_list|(
name|fn
parameter_list|,
name|msecs
parameter_list|)
define|\
value|{\ 		if (cold) \ 			DELAY((msecs * 1000)); \ 		else  \ 			pause(fn, qlnx_ms_to_hz(msecs)); \ 	}
end_define

begin_comment
comment|/*  * Locks  */
end_comment

begin_define
define|#
directive|define
name|QLNX_LOCK
parameter_list|(
name|ha
parameter_list|)
value|mtx_lock(&ha->hw_lock)
end_define

begin_define
define|#
directive|define
name|QLNX_UNLOCK
parameter_list|(
name|ha
parameter_list|)
value|mtx_unlock(&ha->hw_lock)
end_define

begin_define
define|#
directive|define
name|QLNX_TX_LOCK
parameter_list|(
name|ha
parameter_list|)
value|mtx_lock(&ha->tx_lock);
end_define

begin_define
define|#
directive|define
name|QLNX_TX_UNLOCK
parameter_list|(
name|ha
parameter_list|)
value|mtx_unlock(&ha->tx_lock);
end_define

begin_comment
comment|/*  * structure encapsulating a DMA buffer  */
end_comment

begin_struct
struct|struct
name|qlnx_dma
block|{
name|bus_size_t
name|alignment
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|void
modifier|*
name|dma_b
decl_stmt|;
name|bus_addr_t
name|dma_addr
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_dma
name|qlnx_dma_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLNX_OS_H_ */
end_comment

end_unit

