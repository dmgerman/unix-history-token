begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_BSD_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_BSD_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
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
file|<sys/sockio.h>
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
file|<net/if_gif.h>
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
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/firmware.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_CAVIUM
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_CAVIUM
value|0x177D
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|nr
parameter_list|)
value|(1UL<< (nr))
end_define

begin_define
define|#
directive|define
name|lio_check_timeout
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((b) - (a))< 0)
end_define

begin_define
define|#
directive|define
name|lio_ms_to_ticks
parameter_list|(
name|x
parameter_list|)
define|\
value|((hz> 1000) ? ((x) * (hz/1000)) : ((x) / (1000/hz)))
end_define

begin_define
define|#
directive|define
name|lio_mdelay
parameter_list|(
name|x
parameter_list|)
value|do {				\ 	if (cold)					\ 		DELAY(1000 * (x));			\ 	else						\ 		pause("Wait", lio_ms_to_ticks(x));	\ } while(0)
end_define

begin_define
define|#
directive|define
name|lio_sleep_timeout
parameter_list|(
name|timeout
parameter_list|)
value|lio_mdelay((timeout))
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|__be32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__be64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|lio_dev_info
parameter_list|(
name|oct
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(oct->device, "Info: " format, ##args)
end_define

begin_define
define|#
directive|define
name|lio_dev_warn
parameter_list|(
name|oct
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(oct->device, "Warn: " format, ##args)
end_define

begin_define
define|#
directive|define
name|lio_dev_err
parameter_list|(
name|oct
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(oct->device, "Error: " format, ##args)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIO_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|lio_dev_dbg
parameter_list|(
name|oct
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|device_printf(oct->device, "Debug: " format, ##args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lio_dev_dbg
parameter_list|(
name|oct
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|{do { } while (0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|lio_stailq_node
block|{
name|STAILQ_ENTRY
argument_list|(
argument|lio_stailq_node
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|lio_stailq_head
argument_list|,
name|lio_stailq_node
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|struct
name|lio_stailq_node
modifier|*
name|lio_delete_first_node
parameter_list|(
name|struct
name|lio_stailq_head
modifier|*
name|root
parameter_list|)
block|{
name|struct
name|lio_stailq_node
modifier|*
name|node
decl_stmt|;
if|if
condition|(
name|STAILQ_EMPTY
argument_list|(
name|root
argument_list|)
condition|)
name|node
operator|=
name|NULL
expr_stmt|;
else|else
name|node
operator|=
name|STAILQ_FIRST
argument_list|(
name|root
argument_list|)
expr_stmt|;
if|if
condition|(
name|node
operator|!=
name|NULL
condition|)
name|STAILQ_REMOVE_HEAD
argument_list|(
name|root
argument_list|,
name|entries
argument_list|)
expr_stmt|;
return|return
operator|(
name|node
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_BSD_H__ */
end_comment

end_unit

