begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*                    * Principal Author: Matthew Jacob  * Copyright (c) 1999, 2001 by Traakan Software  * All rights reserved.  *                * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:               * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.    * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Additional Copyright (c) 2001 by Parag Patel  * under same licence for MII PHY code.  */
end_comment

begin_comment
comment|/*  * Softc definitions for the Intel Gigabit Ethernet driver.  *  * Guidance and inspiration from David Greenman's  * if_fxp driver gratefully acknowledged here.  */
end_comment

begin_comment
comment|/*  * Platform specific defines and inline functions go here.  * Look further below for more generic structures.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIOCSIFMEDIA
argument_list|)
end_if

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_if
if|#
directive|if
name|NBPFILTER
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/bpfdesc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NS
end_ifdef

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_include
include|#
directive|include
file|<netns/ns_if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<net/if_ether.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INET
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/if_inarp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<dev/pci/pcidevs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/if_wxreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_struct
struct|struct
name|wxmdvar
block|{
name|struct
name|device
name|dev
decl_stmt|;
comment|/* generic device structures */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|ethercom
name|ethercom
decl_stmt|;
comment|/* ethernet common part */
name|pci_chipset_tag_t
name|pci_pc
decl_stmt|;
name|pcitag_t
name|pci_tag
decl_stmt|;
name|u_int8_t
name|enaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* our mac address */
name|u_int32_t
name|cmdw
decl_stmt|;
name|bus_space_tag_t
name|st
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|ifmedia
name|ifm
decl_stmt|;
name|struct
name|wx_softc
modifier|*
name|next
decl_stmt|;
name|int
name|spl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|wx_dev
value|w.dev
end_define

begin_define
define|#
directive|define
name|wx_enaddr
value|w.enaddr
end_define

begin_define
define|#
directive|define
name|wx_cmdw
value|w.cmdw
end_define

begin_define
define|#
directive|define
name|wx_media
value|w.ifm
end_define

begin_define
define|#
directive|define
name|wx_next
value|w.next
end_define

begin_define
define|#
directive|define
name|wx_if
value|w.ethercom.ec_if
end_define

begin_define
define|#
directive|define
name|wx_name
value|w.dev.dv_xname
end_define

begin_define
define|#
directive|define
name|IOCTL_CMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|WXMALLOC
parameter_list|(
name|len
parameter_list|)
value|malloc(len, M_DEVBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|WXFREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|SOFTC_IFP
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_softc
end_define

begin_define
define|#
directive|define
name|WX_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_bpf
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|VTIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|f
parameter_list|,
name|arg
parameter_list|,
name|sc
parameter_list|)
value|untimeout(f, arg)
end_define

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_define
define|#
directive|define
name|WX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|_sc->w.spl = splimp()
end_define

begin_define
define|#
directive|define
name|WX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|splx(_sc->w.spl)
end_define

begin_define
define|#
directive|define
name|WX_ILOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WX_IUNLK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WX_SOFTC_FROM_MII_ARG
parameter_list|(
name|x
parameter_list|)
value|(wx_softc_t *) x
end_define

begin_define
define|#
directive|define
name|vm_offset_t
value|vaddr_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IFM_1000_SX
end_ifndef

begin_define
define|#
directive|define
name|IFM_1000_SX
value|IFM_1000_FX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_CSR
value|_read_csr
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
value|_write_csr
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_comment
comment|/*  * Enable for FreeBSD 5.0 SMP code  */
end_comment

begin_comment
comment|/* #define	SMPNG		1 */
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
file|<net/if.h>
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

begin_ifdef
ifdef|#
directive|ifdef
name|NS
end_ifdef

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_include
include|#
directive|include
file|<netns/ns_if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
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
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/if_wxreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_define
define|#
directive|define
name|NBPFILTER
value|1
end_define

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_include
include|#
directive|include
file|"opt_bdg.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE
end_ifdef

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/bridge.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|wxmdvar
block|{
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* backpointer to device */
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* per-interface network data */
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
comment|/* resource descriptor for registers */
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* resource descriptor for interrupt */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|u_int16_t
name|cmdw
decl_stmt|;
name|struct
name|callout_handle
name|sch
decl_stmt|;
comment|/* handle for timeouts */
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
name|bus_space_tag_t
name|st
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|ifmedia
name|ifm
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|wx_softc
modifier|*
name|next
decl_stmt|;
ifdef|#
directive|ifdef
name|SMPNG
name|struct
name|mtx
name|wxmtx
decl_stmt|;
else|#
directive|else
name|int
name|spl
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|wx_dev
value|w.dev
end_define

begin_define
define|#
directive|define
name|wx_enaddr
value|w.arpcom.ac_enaddr
end_define

begin_define
define|#
directive|define
name|wx_cmdw
value|w.cmdw
end_define

begin_define
define|#
directive|define
name|wx_media
value|w.ifm
end_define

begin_define
define|#
directive|define
name|wx_next
value|w.next
end_define

begin_define
define|#
directive|define
name|wx_if
value|w.arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|wx_name
value|w.name
end_define

begin_define
define|#
directive|define
name|wx_mtx
value|w.wxmtx
end_define

begin_define
define|#
directive|define
name|IOCTL_CMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|WXMALLOC
parameter_list|(
name|len
parameter_list|)
value|malloc(len, M_DEVBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|WXFREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|SOFTC_IFP
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_softc
end_define

begin_define
define|#
directive|define
name|WX_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|ifp
end_define

begin_define
define|#
directive|define
name|VTIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|(void) timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|(sc)->w.sch = timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|f
parameter_list|,
name|arg
parameter_list|,
name|sc
parameter_list|)
value|untimeout(f, arg, (sc)->w.sch)
end_define

begin_define
define|#
directive|define
name|INLINE
value|__inline
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMPNG
end_ifdef

begin_define
define|#
directive|define
name|WX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_enter(&(_sc)->wx_mtx, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|WX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_exit(&(_sc)->wx_mtx, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|WX_ILOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_enter(&(_sc)->wx_mtx, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|WX_IUNLK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_exit(&(_sc)->wx_mtx, MTX_DEF)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|_sc->w.spl = splimp()
end_define

begin_define
define|#
directive|define
name|WX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|splx(_sc->w.spl)
end_define

begin_define
define|#
directive|define
name|WX_ILOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WX_IUNLK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WX_SOFTC_FROM_MII_ARG
parameter_list|(
name|x
parameter_list|)
value|device_get_softc(x)
end_define

begin_define
define|#
directive|define
name|READ_CSR
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->w.st, (sc)->w.sh, (reg))
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->w.st, (sc)->w.sh, (reg), (val))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
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
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NS
end_ifdef

begin_include
include|#
directive|include
file|<netns/ns.h>
end_include

begin_include
include|#
directive|include
file|<netns/ns_if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bpfilter.h"
end_include

begin_if
if|#
directive|if
name|NBPFILTER
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/bpfdesc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

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
file|<dev/pci/pcidevs.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/if_wxreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_struct
struct|struct
name|wxmdvar
block|{
name|struct
name|device
name|dev
decl_stmt|;
comment|/* generic device structures */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* ethernet common part */
name|pci_chipset_tag_t
name|pci_pc
decl_stmt|;
name|pcitag_t
name|pci_tag
decl_stmt|;
name|u_int32_t
name|cmdw
decl_stmt|;
name|bus_space_tag_t
name|st
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|sh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|ifmedia
name|ifm
decl_stmt|;
name|struct
name|wx_softc
modifier|*
name|next
decl_stmt|;
name|int
name|locked
decl_stmt|;
name|int
name|spl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|wx_dev
value|w.dev
end_define

begin_define
define|#
directive|define
name|wx_enaddr
value|w.arpcom.ac_enaddr
end_define

begin_define
define|#
directive|define
name|wx_cmdw
value|w.cmdw
end_define

begin_define
define|#
directive|define
name|wx_media
value|w.ifm
end_define

begin_define
define|#
directive|define
name|wx_next
value|w.next
end_define

begin_define
define|#
directive|define
name|wx_if
value|w.arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|wx_name
value|w.dev.dv_xname
end_define

begin_define
define|#
directive|define
name|IOCTL_CMD_TYPE
value|u_long
end_define

begin_define
define|#
directive|define
name|WXMALLOC
parameter_list|(
name|len
parameter_list|)
value|malloc(len, M_DEVBUF, M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|WXFREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|SOFTC_IFP
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_softc
end_define

begin_define
define|#
directive|define
name|WX_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_bpf
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|VTIMEOUT
parameter_list|(
name|sc
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|time
parameter_list|)
value|timeout(func, arg, time)
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|f
parameter_list|,
name|arg
parameter_list|,
name|sc
parameter_list|)
value|untimeout(f, arg)
end_define

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_define
define|#
directive|define
name|WX_LOCK
parameter_list|(
name|wx
parameter_list|)
value|if (wx->w.locked++ == 0) wx->w.spl = splimp()
end_define

begin_define
define|#
directive|define
name|WX_UNLOCK
parameter_list|(
name|wx
parameter_list|)
value|if (wx->w.locked) {				\ 				if (--wx->w.locked == 0)		\ 					splx(wx->w.spl);		\ 			}
end_define

begin_define
define|#
directive|define
name|WX_ILOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WX_IUNLK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WX_SOFTC_FROM_MII_ARG
parameter_list|(
name|x
parameter_list|)
value|(wx_softc_t *) x
end_define

begin_define
define|#
directive|define
name|vm_offset_t
value|vaddr_t
end_define

begin_define
define|#
directive|define
name|READ_CSR
value|_read_csr
end_define

begin_define
define|#
directive|define
name|WRITE_CSR
value|_write_csr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Transmit soft descriptor, used to manage packets as they come in.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rxpkt
block|{
name|struct
name|mbuf
modifier|*
name|dptr
decl_stmt|;
comment|/* pointer to receive frame */
name|u_int32_t
name|dma_addr
decl_stmt|;
comment|/* dma address */
block|}
name|rxpkt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit soft descriptor, used to manage packets as they are transmitted.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|txpkt
block|{
name|struct
name|txpkt
modifier|*
name|next
decl_stmt|;
comment|/* next in a chain */
name|struct
name|mbuf
modifier|*
name|dptr
decl_stmt|;
comment|/* pointer to mbuf being sent */
name|u_int32_t
name|sidx
decl_stmt|;
comment|/* start index */
name|u_int32_t
name|eidx
decl_stmt|;
comment|/* end index */
block|}
name|txpkt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|wx_softc
block|{
comment|/* 	 * OS dependent storage... must be first... 	 */
name|struct
name|wxmdvar
name|w
decl_stmt|;
comment|/* 	 * misc goodies 	 */
name|u_int32_t
label|:
literal|24
operator|,
name|wx_no_flow
operator|:
literal|1
operator|,
name|wx_ilos
operator|:
literal|1
operator|,
name|wx_no_ilos
operator|:
literal|1
operator|,
name|wx_verbose
operator|:
literal|1
operator|,
name|wx_debug
operator|:
literal|1
operator|,
name|ane_failed
operator|:
literal|1
operator|,
name|linkup
operator|:
literal|1
operator|,
name|all_mcasts
operator|:
literal|1
expr_stmt|;
name|u_int32_t
name|wx_idnrev
decl_stmt|;
comment|/* chip revision&& PCI ID */
name|u_int16_t
name|wx_cfg1
decl_stmt|;
name|u_int16_t
name|wx_txint_delay
decl_stmt|;
name|u_int32_t
name|wx_ienable
decl_stmt|;
comment|/* current ienable to use */
name|u_int32_t
name|wx_dcr
decl_stmt|;
comment|/* dcr used */
name|u_int32_t
name|wx_icr
decl_stmt|;
comment|/* last icr */
name|mii_data_t
modifier|*
name|wx_mii
decl_stmt|;
comment|/* non-NULL if we have a PHY */
comment|/* 	 * Statistics, soft&& hard 	 */
name|u_int32_t
name|wx_intr
decl_stmt|;
name|u_int32_t
name|wx_linkintr
decl_stmt|;
name|u_int32_t
name|wx_rxintr
decl_stmt|;
name|u_int32_t
name|wx_xmitgc
decl_stmt|;
name|u_int32_t
name|wx_xmitpullup
decl_stmt|;
name|u_int32_t
name|wx_xmitcluster
decl_stmt|;
name|u_int32_t
name|wx_xmitputback
decl_stmt|;
name|u_int32_t
name|wx_xmitwanted
decl_stmt|;
name|u_int32_t
name|wx_xmitblocked
decl_stmt|;
name|u_int32_t
name|wx_xmitblocked1
decl_stmt|;
name|u_int32_t
name|wx_xmitrunt
decl_stmt|;
name|u_int32_t
name|wx_rxnobuf
decl_stmt|;
comment|/* 	 * Soft copies of multicast addresses. We're only 	 * using (right now) the rest of the receive address 	 * registers- not the hashed multicast table. 	 */
name|u_int8_t
name|wx_mcaddr
index|[
name|WX_RAL_TAB_SIZE
operator|-
literal|1
index|]
index|[
literal|6
index|]
decl_stmt|;
name|u_int8_t
name|wx_nmca
decl_stmt|;
comment|/* # active multicast addrs */
comment|/*  	 * Receive Management 	 * We have software and shared memory rings in a buddy store format. 	 */
name|wxrd_t
modifier|*
name|rdescriptors
decl_stmt|;
comment|/* receive descriptor ring */
name|rxpkt_t
modifier|*
name|rbase
decl_stmt|;
comment|/* base of soft rdesc list */
name|u_int16_t
name|rnxt
decl_stmt|;
comment|/* next descriptor to check */
name|u_int16_t
name|_pad
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rpending
decl_stmt|;
comment|/* pending partial packet */
comment|/*  	 * Transmit Management 	 * We have software and shared memory rings in a buddy store format. 	 */
name|txpkt_t
modifier|*
name|tbase
decl_stmt|;
comment|/* base of soft soft management */
name|txpkt_t
modifier|*
name|tbsyf
decl_stmt|,
modifier|*
name|tbsyl
decl_stmt|;
comment|/* linked busy list */
name|wxtd_t
modifier|*
name|tdescriptors
decl_stmt|;
comment|/* transmit descriptor ring */
name|u_int16_t
name|tnxtfree
decl_stmt|;
comment|/* next free index (circular) */
name|u_int16_t
name|tactive
decl_stmt|;
comment|/* # active */
block|}
name|wx_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * We offset the the receive frame header by two bytes so that the actual  * payload is 32 bit aligned. On platforms that require strict structure  * alignment, this means that the ethernet frame header may have to be shifted  * to align it at interrupt time, but because it's such a small amount  * (fourteen bytes) and processors have gotten pretty fast, that's okay.  * It may even turn out on some platforms that this doesn't have to happen.  */
end_comment

begin_define
define|#
directive|define
name|WX_RX_OFFSET_VALUE
value|2
end_define

begin_comment
comment|/*  * Tunable Parameters.  *  * Descriptor lengths must be in multiples of 8.  */
end_comment

begin_define
define|#
directive|define
name|WX_MAX_TDESC
value|256
end_define

begin_comment
comment|/* number of transmit descriptors */
end_comment

begin_define
define|#
directive|define
name|T_NXT_IDX
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& (WX_MAX_TDESC - 1))
end_define

begin_define
define|#
directive|define
name|T_PREV_IDX
parameter_list|(
name|x
parameter_list|)
value|((x - 1)& (WX_MAX_TDESC - 1))
end_define

begin_define
define|#
directive|define
name|WX_MAX_RDESC
value|64
end_define

begin_comment
comment|/* number of receive descriptors */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PADDED_CELL
end_ifdef

begin_define
define|#
directive|define
name|RXINCR
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RXINCR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|R_NXT_IDX
parameter_list|(
name|x
parameter_list|)
value|((x + RXINCR)& (WX_MAX_RDESC - 1))
end_define

begin_define
define|#
directive|define
name|R_PREV_IDX
parameter_list|(
name|x
parameter_list|)
value|((x - RXINCR)& (WX_MAX_RDESC - 1))
end_define

begin_comment
comment|/*  * Link Up timeout, in milliseconds.  */
end_comment

begin_define
define|#
directive|define
name|WX_LINK_UP_TIMEOUT
value|500
end_define

end_unit

