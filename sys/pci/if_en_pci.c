begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_en_pci.c,v 1.1 1996/06/22 02:00:31 chuck Exp $	*/
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *	Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  *  * i f _ e n _ p c i . c    *  * author: Chuck Cranor<chuck@ccrc.wustl.edu>  * started: spring, 1996.  *  * FreeBSD PCI glue for the eni155p card.  * thanks to Matt Thomas for figuring out FreeBSD vs NetBSD vs etc.. diffs.  */
end_comment

begin_include
include|#
directive|include
file|"en.h"
end_include

begin_include
include|#
directive|include
file|"pci.h"
end_include

begin_if
if|#
directive|if
operator|(
name|NEN
operator|>
literal|0
operator|)
operator|&&
operator|(
name|NPCI
operator|>
literal|0
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SHUTDOWN_PRE_SYNC
end_ifndef

begin_comment
comment|/*  * device shutdown mechanism has been changed since 2.2-ALPHA.  * if SHUTDOWN_PRE_SYNC is defined in "sys/systm.h", use new one.  * otherwise, use old one.  *	new: 2.2-ALPHA, 2.2-BETA, 2.2-GAMME, 2.2-RELEASE, 3.0  *	old: 2.1.5, 2.1.6, 2.2-SNAP  *			-- kjc  */
end_comment

begin_include
include|#
directive|include
file|<sys/devconf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

begin_include
include|#
directive|include
file|<net/if.h>
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
file|<dev/en/midwayreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/en/midwayvar.h>
end_include

begin_comment
comment|/*  * prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|en_pci_attach
name|__P
argument_list|(
operator|(
name|pcici_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|en_pci_probe
name|__P
argument_list|(
operator|(
name|pcici_t
operator|,
name|pcidi_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SHUTDOWN_PRE_SYNC
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|en_pci_shutdown
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|int
name|en_pci_shutdown
name|__P
argument_list|(
operator|(
expr|struct
name|kern_devconf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * local structures  */
end_comment

begin_struct
struct|struct
name|en_pci_softc
block|{
comment|/* bus independent stuff */
name|struct
name|en_softc
name|esc
decl_stmt|;
comment|/* includes "device" structure */
comment|/* PCI bus glue */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt handle */
name|pci_chipset_tag_t
name|en_pc
decl_stmt|;
comment|/* for PCI calls */
block|}
struct|;
end_struct

begin_comment
comment|/*  * pointers to softcs (we alloc)  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|en_pci_softc
modifier|*
name|enpcis
index|[
name|NEN
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cfdriver
name|en_cd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * autoconfig structures  */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|en_pci_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device
name|endevice
init|=
block|{
literal|"en"
block|,
name|en_pci_probe
block|,
name|en_pci_attach
block|,
operator|&
name|en_pci_count
block|,
ifdef|#
directive|ifdef
name|SHUTDOWN_PRE_SYNC
name|NULL
block|,
else|#
directive|else
name|en_pci_shutdown
block|,
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DATA_SET
argument_list|(
name|pcidevice_set
argument_list|,
name|endevice
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * local defines (PCI specific stuff)  */
end_comment

begin_comment
comment|/*   * address of config base memory address register in PCI config space  * (this is card specific)  */
end_comment

begin_define
define|#
directive|define
name|PCI_CBMA
value|0x10
end_define

begin_comment
comment|/*  * tonga (pci bridge).   ENI cards only!  */
end_comment

begin_define
define|#
directive|define
name|EN_TONGA
value|0x60
end_define

begin_comment
comment|/* PCI config addr of tonga reg */
end_comment

begin_define
define|#
directive|define
name|TONGA_SWAP_DMA
value|0x80
end_define

begin_comment
comment|/* endian swap control */
end_comment

begin_define
define|#
directive|define
name|TONGA_SWAP_BYTE
value|0x40
end_define

begin_define
define|#
directive|define
name|TONGA_SWAP_WORD
value|0x20
end_define

begin_comment
comment|/*  * adaptec pci bridge.   ADP cards only!  */
end_comment

begin_define
define|#
directive|define
name|ADP_PCIREG
value|0x050040
end_define

begin_comment
comment|/* PCI control register */
end_comment

begin_define
define|#
directive|define
name|ADP_PCIREG_RESET
value|0x1
end_define

begin_comment
comment|/* reset card */
end_comment

begin_define
define|#
directive|define
name|ADP_PCIREG_IENABLE
value|0x2
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ADP_PCIREG_SWAP_WORD
value|0x4
end_define

begin_comment
comment|/* swap byte on slave access */
end_comment

begin_define
define|#
directive|define
name|ADP_PCIREG_SWAP_DMA
value|0x8
end_define

begin_comment
comment|/* swap byte on DMA */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_EFFICIENTNETS
value|0x111a
end_define

begin_comment
comment|/* Efficent Networks */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_EFFICIENTNETS_ENI155PF
value|0x0000
end_define

begin_comment
comment|/* ENI-155P ATM */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_EFFICIENTNETS_ENI155PA
value|0x0002
end_define

begin_comment
comment|/* ENI-155P ATM */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_ADP
value|0x9004
end_define

begin_comment
comment|/* adaptec */
end_comment

begin_define
define|#
directive|define
name|PCI_PRODUCT_ADP_AIC5900
value|0x5900
end_define

begin_define
define|#
directive|define
name|PCI_PRODUCT_ADP_AIC5905
value|0x5905
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|PCI_CHIPID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIDWAY_ENIONLY
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|void
name|adp_busreset
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * bus specific reset function [ADP only!]  */
end_comment

begin_function
specifier|static
name|void
name|adp_busreset
parameter_list|(
name|v
parameter_list|)
name|void
modifier|*
name|v
decl_stmt|;
block|{
name|struct
name|en_softc
modifier|*
name|sc
init|=
operator|(
expr|struct
name|en_softc
operator|*
operator|)
name|v
decl_stmt|;
name|u_int32_t
name|dummy
decl_stmt|;
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|en_memt
argument_list|,
name|sc
operator|->
name|en_base
argument_list|,
name|ADP_PCIREG
argument_list|,
name|ADP_PCIREG_RESET
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* let it reset */
name|dummy
operator|=
name|bus_space_read_4
argument_list|(
name|sc
operator|->
name|en_memt
argument_list|,
name|sc
operator|->
name|en_base
argument_list|,
name|ADP_PCIREG
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|en_memt
argument_list|,
name|sc
operator|->
name|en_base
argument_list|,
name|ADP_PCIREG
argument_list|,
operator|(
name|ADP_PCIREG_SWAP_WORD
operator||
name|ADP_PCIREG_SWAP_DMA
operator||
name|ADP_PCIREG_IENABLE
operator|)
argument_list|)
expr_stmt|;
name|dummy
operator|=
name|bus_space_read_4
argument_list|(
name|sc
operator|->
name|en_memt
argument_list|,
name|sc
operator|->
name|en_base
argument_list|,
name|ADP_PCIREG
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dummy
operator|&
operator|(
name|ADP_PCIREG_SWAP_WORD
operator||
name|ADP_PCIREG_SWAP_DMA
operator|)
operator|)
operator|!=
operator|(
name|ADP_PCIREG_SWAP_WORD
operator||
name|ADP_PCIREG_SWAP_DMA
operator|)
condition|)
name|printf
argument_list|(
literal|"adp_busreset: Adaptec ATM did NOT reset!\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*  * autoconfig stuff  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|en_pci_probe
parameter_list|(
name|config_id
parameter_list|,
name|device_id
parameter_list|)
name|pcici_t
name|config_id
decl_stmt|;
name|pcidi_t
name|device_id
decl_stmt|;
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIDWAY_ADPONLY
argument_list|)
if|if
condition|(
name|PCI_VENDOR
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_VENDOR_EFFICIENTNETS
operator|&&
operator|(
name|PCI_CHIPID
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_PRODUCT_EFFICIENTNETS_ENI155PF
operator|||
name|PCI_CHIPID
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_PRODUCT_EFFICIENTNETS_ENI155PA
operator|)
condition|)
return|return
literal|"Efficient Networks ENI-155p"
return|;
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIDWAY_ENIONLY
argument_list|)
if|if
condition|(
name|PCI_VENDOR
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_VENDOR_ADP
operator|&&
operator|(
name|PCI_CHIPID
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_PRODUCT_ADP_AIC5900
operator|||
name|PCI_CHIPID
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_PRODUCT_ADP_AIC5905
operator|)
condition|)
return|return
literal|"Adaptec 155 ATM"
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|en_pci_attach
parameter_list|(
name|config_id
parameter_list|,
name|unit
parameter_list|)
name|pcici_t
name|config_id
decl_stmt|;
name|int
name|unit
decl_stmt|;
block|{
name|struct
name|en_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|en_pci_softc
modifier|*
name|scp
decl_stmt|;
name|pcidi_t
name|device_id
decl_stmt|;
name|int
name|retval
decl_stmt|;
name|vm_offset_t
name|pa
decl_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NEN
condition|)
block|{
name|printf
argument_list|(
literal|"en%d: not configured; kernel is built for only %d device%s.\n"
argument_list|,
name|unit
argument_list|,
name|NEN
argument_list|,
name|NEN
operator|==
literal|1
condition|?
literal|""
else|:
literal|"s"
argument_list|)
expr_stmt|;
return|return;
block|}
name|scp
operator|=
operator|(
expr|struct
name|en_pci_softc
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|scp
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|scp
operator|==
name|NULL
condition|)
return|return;
name|bzero
argument_list|(
name|scp
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|scp
argument_list|)
argument_list|)
expr_stmt|;
comment|/* zero */
name|sc
operator|=
operator|&
name|scp
operator|->
name|esc
expr_stmt|;
name|retval
operator|=
name|pci_map_mem
argument_list|(
name|config_id
argument_list|,
name|PCI_CBMA
argument_list|,
operator|(
name|vm_offset_t
operator|*
operator|)
operator|&
name|sc
operator|->
name|en_base
argument_list|,
operator|&
name|pa
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|retval
condition|)
block|{
name|free
argument_list|(
operator|(
name|caddr_t
operator|)
name|scp
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
return|return;
block|}
name|enpcis
index|[
name|unit
index|]
operator|=
name|scp
expr_stmt|;
comment|/* lock it in */
name|en_cd
operator|.
name|cd_devs
index|[
name|unit
index|]
operator|=
name|sc
expr_stmt|;
comment|/* fake a cfdriver structure */
name|en_cd
operator|.
name|cd_ndevs
operator|=
name|NEN
expr_stmt|;
name|sprintf
argument_list|(
name|sc
operator|->
name|sc_dev
operator|.
name|dv_xname
argument_list|,
literal|"en%d"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|sc
operator|->
name|enif
operator|.
name|if_unit
operator|=
name|unit
expr_stmt|;
name|sc
operator|->
name|enif
operator|.
name|if_name
operator|=
literal|"en"
expr_stmt|;
comment|/*    * figure out if we are an adaptec card or not.    * XXX: why do we have to re-read PC_ID_REG when en_pci_probe already    * had that info?    */
name|device_id
operator|=
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|PCI_ID_REG
argument_list|)
expr_stmt|;
name|sc
operator|->
name|is_adaptec
operator|=
operator|(
name|PCI_VENDOR
argument_list|(
name|device_id
argument_list|)
operator|==
name|PCI_VENDOR_ADP
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|SHUTDOWN_PRE_SYNC
comment|/*    * Add shutdown hook so that DMA is disabled prior to reboot. Not    * doing so could allow DMA to corrupt kernel memory during the    * reboot before the driver initializes.    */
name|at_shutdown
argument_list|(
name|en_pci_shutdown
argument_list|,
name|scp
argument_list|,
name|SHUTDOWN_POST_SYNC
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|pci_map_int
argument_list|(
name|config_id
argument_list|,
name|en_intr
argument_list|,
operator|(
name|void
operator|*
operator|)
name|sc
argument_list|,
operator|&
name|net_imask
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s: couldn't establish interrupt\n"
argument_list|,
name|sc
operator|->
name|sc_dev
operator|.
name|dv_xname
argument_list|)
expr_stmt|;
return|return;
block|}
name|sc
operator|->
name|ipl
operator|=
literal|1
expr_stmt|;
comment|/* XXX */
comment|/*    * set up pci bridge    */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIDWAY_ENIONLY
argument_list|)
if|if
condition|(
name|sc
operator|->
name|is_adaptec
condition|)
block|{
name|sc
operator|->
name|en_busreset
operator|=
name|adp_busreset
expr_stmt|;
name|adp_busreset
argument_list|(
name|sc
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIDWAY_ADPONLY
argument_list|)
if|if
condition|(
operator|!
name|sc
operator|->
name|is_adaptec
condition|)
block|{
name|sc
operator|->
name|en_busreset
operator|=
name|NULL
expr_stmt|;
name|pci_conf_write
argument_list|(
name|config_id
argument_list|,
name|EN_TONGA
argument_list|,
operator|(
name|TONGA_SWAP_DMA
operator||
name|TONGA_SWAP_WORD
operator|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*    * done PCI specific stuff    */
name|en_attach
argument_list|(
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SHUTDOWN_PRE_SYNC
end_ifdef

begin_function
specifier|static
name|void
name|en_pci_shutdown
parameter_list|(
name|int
name|howto
parameter_list|,
name|void
modifier|*
name|sc
parameter_list|)
block|{
name|struct
name|en_pci_softc
modifier|*
name|psc
init|=
operator|(
expr|struct
name|en_pci_softc
operator|*
operator|)
name|sc
decl_stmt|;
name|en_reset
argument_list|(
operator|&
name|psc
operator|->
name|esc
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SHUTDOWN_PRE_SYNC */
end_comment

begin_function
specifier|static
name|int
name|en_pci_shutdown
parameter_list|(
name|kdc
parameter_list|,
name|force
parameter_list|)
name|struct
name|kern_devconf
modifier|*
name|kdc
decl_stmt|;
name|int
name|force
decl_stmt|;
block|{
if|if
condition|(
name|kdc
operator|->
name|kdc_unit
operator|<
name|NEN
condition|)
block|{
name|struct
name|en_pci_softc
modifier|*
name|psc
init|=
name|enpcis
index|[
name|kdc
operator|->
name|kdc_unit
index|]
decl_stmt|;
if|if
condition|(
name|psc
condition|)
comment|/* can it be null? */
name|en_reset
argument_list|(
operator|&
name|psc
operator|->
name|esc
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
block|}
name|dev_detach
argument_list|(
name|kdc
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SHUTDOWN_PRE_SYNC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEN> 0&& NPCI> 0 */
end_comment

end_unit

