begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995, 1996 Matt Thomas<matt@3am-software.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * DEC PDQ FDDI Controller; PDQ O/S dependent definitions  *  * Written by Matt Thomas  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PDQ_OS_H
end_ifndef

begin_define
define|#
directive|define
name|_PDQ_OS_H
end_define

begin_define
define|#
directive|define
name|PDQ_OS_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* seconds */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_pdq_t
name|pdq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_csrs_t
name|pdq_csrs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_pci_csrs_t
name|pdq_pci_csrs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_pdq_lanaddr_t
name|pdq_lanaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|pdq_uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|pdq_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|pdq_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_boolean_t
name|pdq_boolean_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_type_t
name|pdq_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|_pdq_state_t
name|pdq_state_t
typedef|;
end_typedef

begin_enum
enum|enum
name|_pdq_type_t
block|{
name|PDQ_DEFPA
block|,
comment|/* PCI-bus */
name|PDQ_DEFEA
block|,
comment|/* EISA-bus */
name|PDQ_DEFTA
block|,
comment|/* TurboChannel */
name|PDQ_DEFAA
block|,
comment|/* FutureBus+ */
name|PDQ_DEFQA
comment|/* Q-bus */
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQTEST
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pdq_os_test.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

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
file|<sys/lock.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|M_MCAST
end_ifndef

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_CAST */
end_comment

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_define
define|#
directive|define
name|PDQ_USE_MBUFS
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX
value|"%s: "
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX_ARGS
value|pdq->pdq_os_name
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX
value|"%s%d: "
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX_ARGS
value|pdq->pdq_os_name, pdq->pdq_unit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|BSD
operator|>=
literal|199506
end_if

begin_define
define|#
directive|define
name|PDQ_OS_PAGESIZE
value|PAGE_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_OS_PAGESIZE
value|NBPG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PDQ_OS_USEC_DELAY
parameter_list|(
name|n
parameter_list|)
value|DELAY(n)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMZERO
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|bzero((caddr_t)(p), (n))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_VA_TO_PA
parameter_list|(
name|pdq
parameter_list|,
name|p
parameter_list|)
value|(vtophys((vm_offset_t)p) | (pdq->pdq_type == PDQ_DEFTA ? 0 : 0x40000000))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PDQ_OS_VA_TO_PA
parameter_list|(
name|pdq
parameter_list|,
name|p
parameter_list|)
value|(vtophys((vm_offset_t)p) | (pdq->pdq_type == PDQ_DEFTA ? 0 : alpha_XXX_dmamap_or))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_OS_VA_TO_PA
parameter_list|(
name|pdq
parameter_list|,
name|p
parameter_list|)
value|vtophys(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC
parameter_list|(
name|n
parameter_list|)
value|malloc(n, M_DEVBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|free((void *) p, M_DEVBUF)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
parameter_list|(
name|n
parameter_list|)
value|vm_page_alloc_contig(n, 0, 0xffffffff, PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE_CONTIG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|kmem_free(kernel_map, (vm_offset_t) p, n)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
parameter_list|(
name|n
parameter_list|)
value|kmem_alloc(kernel_map, round_page(n))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE_CONTIG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|kmem_free(kernel_map, (vm_offset_t) p, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_typedef
typedef|typedef
name|void
name|ifnet_ret_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|ioctl_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDQ_BUS_EISA
block|,
name|PDQ_BUS_PCI
block|}
name|pdq_bus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|pdq_bus_ioport_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|pdq_uint32_t
modifier|*
name|pdq_bus_memaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pdq_bus_memaddr_t
name|pdq_bus_memoffset_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199506
end_if

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|PDQ_BPF_MTAP
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
value|bpf_mtap(&(sc)->sc_if, m)
end_define

begin_define
define|#
directive|define
name|PDQ_BPFATTACH
parameter_list|(
name|sc
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|)
value|bpfattach(&(sc)->sc_if, t, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<machine/inline.h>
end_include

begin_typedef
typedef|typedef
name|int
name|ifnet_ret_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ioctl_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDQ_BUS_EISA
block|,
name|PDQ_BUS_PCI
block|}
name|pdq_bus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|pdq_bus_ioport_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|volatile
name|pdq_uint32_t
modifier|*
name|pdq_bus_memaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pdq_bus_memaddr_t
name|pdq_bus_memoffset_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_define
define|#
directive|define
name|PDQ_OS_PTR_FMT
value|"%p"
end_define

begin_typedef
typedef|typedef
name|void
name|ifnet_ret_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|ioctl_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_chipset_tag_t
name|pdq_bus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_io_handle_t
name|pdq_bus_ioport_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQ_IOMAPPED
argument_list|)
end_if

begin_typedef
typedef|typedef
name|bus_io_handle_t
name|pdq_bus_memaddr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|bus_mem_handle_t
name|pdq_bus_memaddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|pdq_uint32_t
name|pdq_bus_memoffset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDQ_OS_IOMEM
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|bus_io_read_4  (t, base, offset)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|bus_io_write_4 (t, base, offset, data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_8
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|bus_io_read_1  (t, base, offset)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_8
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|bus_io_write_1 (t, base, offset, data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMRD_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|bus_mem_read_4(t, base, offset)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMWR_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|bus_mem_write_4(t, base, offset, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_OFFSET
parameter_list|(
name|base
parameter_list|,
name|offset
parameter_list|)
value|(0 + (offset)*sizeof(pdq_uint32_t))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PDQ_IOMAPPED
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_CSR_WRITE
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|,
name|data
parameter_list|)
value|PDQ_OS_IOWR_32((csr)->csr_bus, (csr)->csr_base, (csr)->name, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_READ
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|)
value|PDQ_OS_IORD_32((csr)->csr_bus, (csr)->csr_base, (csr)->name)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PDQ_CSR_WRITE
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|,
name|data
parameter_list|)
value|PDQ_OS_MEMWR_32((csr)->csr_bus, (csr)->csr_base, (csr)->name, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_READ
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|)
value|PDQ_OS_MEMRD_32((csr)->csr_bus, (csr)->csr_base, (csr)->name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PDQ_BPF_MTAP
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_BPF_MTAP
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
value|bpf_mtap((sc)->sc_bpf, m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PDQ_BPFATTACH
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_BPFATTACH
parameter_list|(
name|sc
parameter_list|,
name|t
parameter_list|,
name|s
parameter_list|)
value|bpfattach(&(sc)->sc_bpf,&(sc)->sc_if, t, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PDQ_OS_PTR_FMT
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_PTR_FMT
value|"0x%x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PDQ_OS_IOMEM
argument_list|)
end_if

begin_define
define|#
directive|define
name|PDQ_OS_IORD_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|inl((base) + (offset))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|outl((base) + (offset), data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_8
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|inb((base) + (offset))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_8
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|outb((base) + (offset), data)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMRD_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|)
value|readl((base) + (offset))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMWR_32
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|offset
parameter_list|,
name|data
parameter_list|)
value|writel((base) + (offset), data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PDQ_CSR_OFFSET
end_ifndef

begin_define
define|#
directive|define
name|PDQ_CSR_OFFSET
parameter_list|(
name|base
parameter_list|,
name|offset
parameter_list|)
value|(0 + (base) + (offset))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PDQ_CSR_WRITE
end_ifndef

begin_define
define|#
directive|define
name|PDQ_CSR_WRITE
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|,
name|data
parameter_list|)
value|PDQ_OS_MEMWR_32((csr)->csr_bus, (csr)->name, 0, data)
end_define

begin_define
define|#
directive|define
name|PDQ_CSR_READ
parameter_list|(
name|csr
parameter_list|,
name|name
parameter_list|)
value|PDQ_OS_MEMRD_32((csr)->csr_bus, (csr)->name, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PDQ_HWSUPPORT
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|__bsdi__
argument_list|)
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* base device */
name|struct
name|isadev
name|sc_id
decl_stmt|;
comment|/* ISA device */
name|struct
name|intrhand
name|sc_ih
decl_stmt|;
comment|/* interrupt vectoring */
name|struct
name|atshutdown
name|sc_ats
decl_stmt|;
comment|/* shutdown routine */
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* base device */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt vectoring */
name|void
modifier|*
name|sc_ats
decl_stmt|;
comment|/* shutdown hook */
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|struct
name|kern_devconf
modifier|*
name|sc_kdc
decl_stmt|;
comment|/* freebsd cruft */
endif|#
directive|endif
name|struct
name|arpcom
name|sc_ac
decl_stmt|;
define|#
directive|define
name|sc_if
value|sc_ac.ac_if
name|pdq_t
modifier|*
name|sc_pdq
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
name|pdq_bus_ioport_t
name|sc_iobase
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PDQ_IOMAPPED
define|#
directive|define
name|sc_membase
value|sc_iobase
else|#
directive|else
name|pdq_bus_memaddr_t
name|sc_membase
decl_stmt|;
endif|#
directive|endif
name|pdq_bus_t
name|sc_bc
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|_BSDI_VERSION
operator|>=
literal|199401
define|#
directive|define
name|sc_bpf
value|sc_if.if_bpf
else|#
directive|else
name|caddr_t
name|sc_bpf
decl_stmt|;
endif|#
directive|endif
block|}
name|pdq_softc_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|pdq_ifreset
parameter_list|(
name|pdq_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_ifinit
parameter_list|(
name|pdq_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_ifwatchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ifnet_ret_t
name|pdq_ifstart
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pdq_ifioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|ioctl_cmd_t
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_ifattach
parameter_list|(
name|pdq_softc_t
modifier|*
name|sc
parameter_list|,
name|ifnet_ret_t
function_decl|(
modifier|*
name|ifwatchdog
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !PDQ_HWSUPPORT */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DLPI_PDQ
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_include
include|#
directive|include
file|<sys/ddi.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_define
define|#
directive|define
name|PDQ_USE_STREAMS
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX
value|"%s board %d "
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PREFIX_ARGS
value|pdq->pdq_os_name, pdq->pdq_unit
end_define

begin_define
define|#
directive|define
name|PDQ_OS_PAGESIZE
value|PAGESIZE
end_define

begin_define
define|#
directive|define
name|PDQ_OS_USEC_DELAY
parameter_list|(
name|n
parameter_list|)
value|drv_usecwait(n)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMZERO
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|bzero((caddr_t)(p), (n))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_VA_TO_PA
parameter_list|(
name|pdq
parameter_list|,
name|p
parameter_list|)
value|vtop((caddr_t)p, NULL)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC
parameter_list|(
name|n
parameter_list|)
value|kmem_zalloc(n, KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|kmem_free((caddr_t) p, n)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMALLOC_CONTIG
parameter_list|(
name|n
parameter_list|)
value|kmem_zalloc_physreq(n, decfddiphysreq_db, KM_NOSLEEP)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_MEMFREE_CONTIG
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|PDQ_OS_MEMFREE(p, n)
end_define

begin_decl_stmt
specifier|extern
name|physreq_t
modifier|*
name|decfddiphysreq_db
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|physreq_t
modifier|*
name|decfddiphysreq_mblk
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ALLOC
parameter_list|(
name|b
parameter_list|)
value|((void) (((b) = allocb_physreq(PDQ_OS_DATABUF_SIZE, BPRI_MED, decfddiphysreq_mblk))&& ((b)->b_wptr = (b)->b_rptr + PDQ_OS_DATABUF_SIZE)))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IORD_8
parameter_list|(
name|port
parameter_list|)
value|inb(port)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_IOWR_8
parameter_list|(
name|port
parameter_list|,
name|data
parameter_list|)
value|outb(port, data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDQ_USE_MBUFS
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_SIZE
value|(MCLBYTES)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_FREE
parameter_list|(
name|b
parameter_list|)
value|(m_freem(b))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT
parameter_list|(
name|b
parameter_list|)
value|((b)->m_next)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->m_next = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT
parameter_list|(
name|b
parameter_list|)
value|((b)->m_nextpkt)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->m_nextpkt = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN
parameter_list|(
name|b
parameter_list|)
value|((b)->m_len)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_len = (n))
end_define

begin_comment
comment|/* #define	PDQ_OS_DATABUF_LEN_ADJ(b, n)		((b)->m_len += (n)) */
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_PTR
parameter_list|(
name|b
parameter_list|)
value|(mtod((b), pdq_uint8_t *))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ADJ
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->m_data += (n), (b)->m_len -= (n))
end_define

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|PDQ_OS_DATABUF_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ALLOC
parameter_list|(
name|b
parameter_list|)
value|do { \     PDQ_OS_DATABUF_T *x_m0; \     MGETHDR(x_m0, M_DONTWAIT, MT_DATA); \     if (x_m0 != NULL) { \ 	MCLGET(x_m0, M_DONTWAIT);	\ 	if ((x_m0->m_flags& M_EXT) == 0) { \ 	    m_free(x_m0); \ 	    (b) = NULL; \ 	} else { \ 	    (b) = x_m0; \ 	    x_m0->m_len = PDQ_OS_DATABUF_SIZE; \ 	} \     } else { \ 	(b) = NULL; \     } \ } while (0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_RESET
parameter_list|(
name|b
parameter_list|)
value|((b)->m_data = (b)->m_ext.ext_buf, (b)->m_len = MCLBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_USE_MBUFS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PDQ_USE_STREAMS
end_ifdef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_SIZE
value|(2048)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_FREE
parameter_list|(
name|b
parameter_list|)
value|(freemsg(b))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT
parameter_list|(
name|b
parameter_list|)
value|((b)->b_cont)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->b_cont = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT
parameter_list|(
name|b
parameter_list|)
value|((b)->b_next)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_NEXTPKT_SET
parameter_list|(
name|b
parameter_list|,
name|b1
parameter_list|)
value|((b)->b_next = (b1))
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN
parameter_list|(
name|b
parameter_list|)
value|((b)->b_wptr - (b)->b_rptr)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_LEN_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->b_wptr = (b)->b_rptr + (n))
end_define

begin_comment
comment|/*#define	PDQ_OS_DATABUF_LEN_ADJ(b, n)		((b)->b_wptr += (n))*/
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_PTR
parameter_list|(
name|b
parameter_list|)
value|((pdq_uint8_t *) (b)->b_rptr)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ADJ
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|((b)->b_rptr += (n))
end_define

begin_typedef
typedef|typedef
name|mblk_t
name|PDQ_OS_DATABUF_T
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|PDQ_OS_DATABUF_ALLOC
end_ifndef

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ALLOC
parameter_list|(
name|b
parameter_list|)
value|((void) (((b) = allocb(PDQ_OS_DATABUF_SIZE, BPRI_MED))&& ((b)->b_wptr = (b)->b_rptr + PDQ_OS_DATABUF_SIZE)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_OS_DATABUF_ALLOC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PDQ_USE_STREAMS */
end_comment

begin_define
define|#
directive|define
name|PDQ_OS_TX_TRANSMIT
value|5
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_ENQUEUE
parameter_list|(
name|q
parameter_list|,
name|b
parameter_list|)
value|do { \     PDQ_OS_DATABUF_NEXTPKT_SET(b, NULL); \     if ((q)->q_tail == NULL) \ 	(q)->q_head = (b); \     else \ 	PDQ_OS_DATABUF_NEXTPKT_SET(((PDQ_OS_DATABUF_T *)(q)->q_tail), b); \     (q)->q_tail = (b); \ } while (0)
end_define

begin_define
define|#
directive|define
name|PDQ_OS_DATABUF_DEQUEUE
parameter_list|(
name|q
parameter_list|,
name|b
parameter_list|)
value|do { \     if (((b) = (PDQ_OS_DATABUF_T *) (q)->q_head) != NULL) { \ 	if (((q)->q_head = PDQ_OS_DATABUF_NEXTPKT(b)) == NULL) \ 	    (q)->q_tail = NULL; \ 	PDQ_OS_DATABUF_NEXTPKT_SET(b, NULL); \     } \ } while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|pdq_os_addr_fill
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|pdq_lanaddr_t
modifier|*
name|addrs
parameter_list|,
name|size_t
name|numaddrs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_os_receive_pdu
parameter_list|(
name|pdq_t
modifier|*
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
name|pdu
parameter_list|,
name|size_t
name|pdulen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_os_restart_transmitter
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_os_transmit_done
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
name|pdu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_boolean_t
name|pdq_queue_transmit_data
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|,
name|PDQ_OS_DATABUF_T
modifier|*
name|pdu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_flush_transmitter
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_run
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_state_t
name|pdq_stop
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdq_hwreset
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pdq_interrupt
parameter_list|(
name|pdq_t
modifier|*
name|pdq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pdq_t
modifier|*
name|pdq_initialize
parameter_list|(
name|pdq_bus_t
name|bus
parameter_list|,
name|pdq_bus_memaddr_t
name|csr_va
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|,
name|pdq_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PDQ_OS_H */
end_comment

end_unit

