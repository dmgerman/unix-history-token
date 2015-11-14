begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCIVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* some PCI bus constants */
end_comment

begin_define
define|#
directive|define
name|PCI_MAXMAPS_0
value|6
end_define

begin_comment
comment|/* max. no. of memory/port maps */
end_comment

begin_define
define|#
directive|define
name|PCI_MAXMAPS_1
value|2
end_define

begin_comment
comment|/* max. no. of maps for PCI to PCI bridge */
end_comment

begin_define
define|#
directive|define
name|PCI_MAXMAPS_2
value|1
end_define

begin_comment
comment|/* max. no. of maps for CardBus bridge */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|pci_addr_t
typedef|;
end_typedef

begin_comment
comment|/* Interesting values for PCI power management */
end_comment

begin_struct
struct|struct
name|pcicfg_pp
block|{
name|uint16_t
name|pp_cap
decl_stmt|;
comment|/* PCI power management capabilities */
name|uint8_t
name|pp_status
decl_stmt|;
comment|/* conf. space addr. of PM control/status reg */
name|uint8_t
name|pp_bse
decl_stmt|;
comment|/* conf. space addr. of PM BSE reg */
name|uint8_t
name|pp_data
decl_stmt|;
comment|/* conf. space addr. of PM data reg */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_map
block|{
name|pci_addr_t
name|pm_value
decl_stmt|;
comment|/* Raw BAR value */
name|pci_addr_t
name|pm_size
decl_stmt|;
name|uint8_t
name|pm_reg
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|pci_map
argument_list|)
name|pm_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vpd_readonly
block|{
name|char
name|keyword
index|[
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vpd_write
block|{
name|char
name|keyword
index|[
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcicfg_vpd
block|{
name|uint8_t
name|vpd_reg
decl_stmt|;
comment|/* base register, + 2 for addr, + 4 data */
name|char
name|vpd_cached
decl_stmt|;
name|char
modifier|*
name|vpd_ident
decl_stmt|;
comment|/* string identifier */
name|int
name|vpd_rocnt
decl_stmt|;
name|struct
name|vpd_readonly
modifier|*
name|vpd_ros
decl_stmt|;
name|int
name|vpd_wcnt
decl_stmt|;
name|struct
name|vpd_write
modifier|*
name|vpd_w
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interesting values for PCI MSI */
end_comment

begin_struct
struct|struct
name|pcicfg_msi
block|{
name|uint16_t
name|msi_ctrl
decl_stmt|;
comment|/* Message Control */
name|uint8_t
name|msi_location
decl_stmt|;
comment|/* Offset of MSI capability registers. */
name|uint8_t
name|msi_msgnum
decl_stmt|;
comment|/* Number of messages */
name|int
name|msi_alloc
decl_stmt|;
comment|/* Number of allocated messages. */
name|uint64_t
name|msi_addr
decl_stmt|;
comment|/* Contents of address register. */
name|uint16_t
name|msi_data
decl_stmt|;
comment|/* Contents of data register. */
name|u_int
name|msi_handlers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interesting values for PCI MSI-X */
end_comment

begin_struct
struct|struct
name|msix_vector
block|{
name|uint64_t
name|mv_address
decl_stmt|;
comment|/* Contents of address register. */
name|uint32_t
name|mv_data
decl_stmt|;
comment|/* Contents of data register. */
name|int
name|mv_irq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msix_table_entry
block|{
name|u_int
name|mte_vector
decl_stmt|;
comment|/* 1-based index into msix_vectors array. */
name|u_int
name|mte_handlers
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcicfg_msix
block|{
name|uint16_t
name|msix_ctrl
decl_stmt|;
comment|/* Message Control */
name|uint16_t
name|msix_msgnum
decl_stmt|;
comment|/* Number of messages */
name|uint8_t
name|msix_location
decl_stmt|;
comment|/* Offset of MSI-X capability registers. */
name|uint8_t
name|msix_table_bar
decl_stmt|;
comment|/* BAR containing vector table. */
name|uint8_t
name|msix_pba_bar
decl_stmt|;
comment|/* BAR containing PBA. */
name|uint32_t
name|msix_table_offset
decl_stmt|;
name|uint32_t
name|msix_pba_offset
decl_stmt|;
name|int
name|msix_alloc
decl_stmt|;
comment|/* Number of allocated vectors. */
name|int
name|msix_table_len
decl_stmt|;
comment|/* Length of virtual table. */
name|struct
name|msix_table_entry
modifier|*
name|msix_table
decl_stmt|;
comment|/* Virtual table. */
name|struct
name|msix_vector
modifier|*
name|msix_vectors
decl_stmt|;
comment|/* Array of allocated vectors. */
name|struct
name|resource
modifier|*
name|msix_table_res
decl_stmt|;
comment|/* Resource containing vector table. */
name|struct
name|resource
modifier|*
name|msix_pba_res
decl_stmt|;
comment|/* Resource containing PBA. */
block|}
struct|;
end_struct

begin_comment
comment|/* Interesting values for HyperTransport */
end_comment

begin_struct
struct|struct
name|pcicfg_ht
block|{
name|uint8_t
name|ht_slave
decl_stmt|;
comment|/* Non-zero if device is an HT slave. */
name|uint8_t
name|ht_msimap
decl_stmt|;
comment|/* Offset of MSI mapping cap registers. */
name|uint16_t
name|ht_msictrl
decl_stmt|;
comment|/* MSI mapping control */
name|uint64_t
name|ht_msiaddr
decl_stmt|;
comment|/* MSI mapping base address */
block|}
struct|;
end_struct

begin_comment
comment|/* Interesting values for PCI-express */
end_comment

begin_struct
struct|struct
name|pcicfg_pcie
block|{
name|uint8_t
name|pcie_location
decl_stmt|;
comment|/* Offset of PCI-e capability registers. */
name|uint8_t
name|pcie_type
decl_stmt|;
comment|/* Device type. */
block|}
struct|;
end_struct

begin_comment
comment|/* config header information common to all header types */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pcicfg
block|{
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
comment|/* device which owns this */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|pci_map
argument_list|)
name|maps
expr_stmt|;
comment|/* BARs */
name|uint16_t
name|subvendor
decl_stmt|;
comment|/* card vendor ID */
name|uint16_t
name|subdevice
decl_stmt|;
comment|/* card device ID, assigned by card vendor */
name|uint16_t
name|vendor
decl_stmt|;
comment|/* chip vendor ID */
name|uint16_t
name|device
decl_stmt|;
comment|/* chip device ID, assigned by chip vendor */
name|uint16_t
name|cmdreg
decl_stmt|;
comment|/* disable/enable chip and PCI options */
name|uint16_t
name|statreg
decl_stmt|;
comment|/* supported PCI features and error state */
name|uint8_t
name|baseclass
decl_stmt|;
comment|/* chip PCI class */
name|uint8_t
name|subclass
decl_stmt|;
comment|/* chip PCI subclass */
name|uint8_t
name|progif
decl_stmt|;
comment|/* chip PCI programming interface */
name|uint8_t
name|revid
decl_stmt|;
comment|/* chip revision ID */
name|uint8_t
name|hdrtype
decl_stmt|;
comment|/* chip config header type */
name|uint8_t
name|cachelnsz
decl_stmt|;
comment|/* cache line size in 4byte units */
name|uint8_t
name|intpin
decl_stmt|;
comment|/* PCI interrupt pin */
name|uint8_t
name|intline
decl_stmt|;
comment|/* interrupt line (IRQ for PC arch) */
name|uint8_t
name|mingnt
decl_stmt|;
comment|/* min. useful bus grant time in 250ns units */
name|uint8_t
name|maxlat
decl_stmt|;
comment|/* max. tolerated bus grant latency in 250ns */
name|uint8_t
name|lattimer
decl_stmt|;
comment|/* latency timer in units of 30ns bus cycles */
name|uint8_t
name|mfdev
decl_stmt|;
comment|/* multi-function device (from hdrtype reg) */
name|uint8_t
name|nummaps
decl_stmt|;
comment|/* actual number of PCI maps used */
name|uint32_t
name|domain
decl_stmt|;
comment|/* PCI domain */
name|uint8_t
name|bus
decl_stmt|;
comment|/* config space bus address */
name|uint8_t
name|slot
decl_stmt|;
comment|/* config space slot address */
name|uint8_t
name|func
decl_stmt|;
comment|/* config space function number */
name|struct
name|pcicfg_pp
name|pp
decl_stmt|;
comment|/* Power management */
name|struct
name|pcicfg_vpd
name|vpd
decl_stmt|;
comment|/* Vital product data */
name|struct
name|pcicfg_msi
name|msi
decl_stmt|;
comment|/* PCI MSI */
name|struct
name|pcicfg_msix
name|msix
decl_stmt|;
comment|/* PCI MSI-X */
name|struct
name|pcicfg_ht
name|ht
decl_stmt|;
comment|/* HyperTransport */
name|struct
name|pcicfg_pcie
name|pcie
decl_stmt|;
comment|/* PCI Express */
block|}
name|pcicfgregs
typedef|;
end_typedef

begin_comment
comment|/* additional type 1 device config header information (PCI to PCI bridge) */
end_comment

begin_define
define|#
directive|define
name|PCI_PPBMEMBASE
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|((((pci_addr_t)(h)<< 32) + ((l)<<16))& ~0xfffff)
end_define

begin_define
define|#
directive|define
name|PCI_PPBMEMLIMIT
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|((((pci_addr_t)(h)<< 32) + ((l)<<16)) | 0xfffff)
end_define

begin_define
define|#
directive|define
name|PCI_PPBIOBASE
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|((((h)<<16) + ((l)<<8))& ~0xfff)
end_define

begin_define
define|#
directive|define
name|PCI_PPBIOLIMIT
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|((((h)<<16) + ((l)<<8)) | 0xfff)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|pci_addr_t
name|pmembase
decl_stmt|;
comment|/* base address of prefetchable memory */
name|pci_addr_t
name|pmemlimit
decl_stmt|;
comment|/* topmost address of prefetchable memory */
name|uint32_t
name|membase
decl_stmt|;
comment|/* base address of memory window */
name|uint32_t
name|memlimit
decl_stmt|;
comment|/* topmost address of memory window */
name|uint32_t
name|iobase
decl_stmt|;
comment|/* base address of port window */
name|uint32_t
name|iolimit
decl_stmt|;
comment|/* topmost address of port window */
name|uint16_t
name|secstat
decl_stmt|;
comment|/* secondary bus status register */
name|uint16_t
name|bridgectl
decl_stmt|;
comment|/* bridge control register */
name|uint8_t
name|seclat
decl_stmt|;
comment|/* CardBus latency timer */
block|}
name|pcih1cfgregs
typedef|;
end_typedef

begin_comment
comment|/* additional type 2 device config header information (CardBus bridge) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|membase0
decl_stmt|;
comment|/* base address of memory window */
name|uint32_t
name|memlimit0
decl_stmt|;
comment|/* topmost address of memory window */
name|uint32_t
name|membase1
decl_stmt|;
comment|/* base address of memory window */
name|uint32_t
name|memlimit1
decl_stmt|;
comment|/* topmost address of memory window */
name|uint32_t
name|iobase0
decl_stmt|;
comment|/* base address of port window */
name|uint32_t
name|iolimit0
decl_stmt|;
comment|/* topmost address of port window */
name|uint32_t
name|iobase1
decl_stmt|;
comment|/* base address of port window */
name|uint32_t
name|iolimit1
decl_stmt|;
comment|/* topmost address of port window */
name|uint32_t
name|pccardif
decl_stmt|;
comment|/* PC Card 16bit IF legacy more base addr. */
name|uint16_t
name|secstat
decl_stmt|;
comment|/* secondary bus status register */
name|uint16_t
name|bridgectl
decl_stmt|;
comment|/* bridge control register */
name|uint8_t
name|seclat
decl_stmt|;
comment|/* CardBus latency timer */
block|}
name|pcih2cfgregs
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|uint32_t
name|pci_numdevs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only if the prerequisites are present */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SYS_BUS_H_
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SYS_PCIIO_H_
argument_list|)
end_if

begin_struct
struct|struct
name|pci_devinfo
block|{
name|STAILQ_ENTRY
argument_list|(
argument|pci_devinfo
argument_list|)
name|pci_links
expr_stmt|;
name|struct
name|resource_list
name|resources
decl_stmt|;
name|pcicfgregs
name|cfg
decl_stmt|;
name|struct
name|pci_conf
name|conf
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_BUS_H_
end_ifdef

begin_include
include|#
directive|include
file|"pci_if.h"
end_include

begin_enum
enum|enum
name|pci_device_ivars
block|{
name|PCI_IVAR_SUBVENDOR
block|,
name|PCI_IVAR_SUBDEVICE
block|,
name|PCI_IVAR_VENDOR
block|,
name|PCI_IVAR_DEVICE
block|,
name|PCI_IVAR_DEVID
block|,
name|PCI_IVAR_CLASS
block|,
name|PCI_IVAR_SUBCLASS
block|,
name|PCI_IVAR_PROGIF
block|,
name|PCI_IVAR_REVID
block|,
name|PCI_IVAR_INTPIN
block|,
name|PCI_IVAR_IRQ
block|,
name|PCI_IVAR_DOMAIN
block|,
name|PCI_IVAR_BUS
block|,
name|PCI_IVAR_SLOT
block|,
name|PCI_IVAR_FUNCTION
block|,
name|PCI_IVAR_ETHADDR
block|,
name|PCI_IVAR_CMDREG
block|,
name|PCI_IVAR_CACHELNSZ
block|,
name|PCI_IVAR_MINGNT
block|,
name|PCI_IVAR_MAXLAT
block|,
name|PCI_IVAR_LATTIMER
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for pci devices  */
end_comment

begin_define
define|#
directive|define
name|PCI_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(pci, var, PCI, ivar, type)
end_define

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subvendor
argument_list|,
argument|SUBVENDOR
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subdevice
argument_list|,
argument|SUBDEVICE
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|vendor
argument_list|,
argument|VENDOR
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|device
argument_list|,
argument|DEVICE
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|devid
argument_list|,
argument|DEVID
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|class
argument_list|,
argument|CLASS
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subclass
argument_list|,
argument|SUBCLASS
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|progif
argument_list|,
argument|PROGIF
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|revid
argument_list|,
argument|REVID
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|intpin
argument_list|,
argument|INTPIN
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|irq
argument_list|,
argument|IRQ
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|domain
argument_list|,
argument|DOMAIN
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|bus
argument_list|,
argument|BUS
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|slot
argument_list|,
argument|SLOT
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|function
argument_list|,
argument|FUNCTION
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|ether
argument_list|,
argument|ETHADDR
argument_list|,
argument|uint8_t *
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|cmdreg
argument_list|,
argument|CMDREG
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|cachelnsz
argument_list|,
argument|CACHELNSZ
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|mingnt
argument_list|,
argument|MINGNT
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|maxlat
argument_list|,
argument|MAXLAT
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|lattimer
argument_list|,
argument|LATTIMER
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|PCI_ACCESSOR
end_undef

begin_comment
comment|/*  * Operations on configuration space.  */
end_comment

begin_function
specifier|static
name|__inline
name|uint32_t
name|pci_read_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
block|{
return|return
name|PCI_READ_CONFIG
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|reg
argument_list|,
name|width
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pci_write_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|int
name|width
parameter_list|)
block|{
name|PCI_WRITE_CONFIG
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|reg
argument_list|,
name|val
argument_list|,
name|width
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Ivars for pci bridges.  */
end_comment

begin_comment
comment|/*typedef enum pci_device_ivars pcib_device_ivars;*/
end_comment

begin_enum
enum|enum
name|pcib_device_ivars
block|{
name|PCIB_IVAR_DOMAIN
block|,
name|PCIB_IVAR_BUS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PCIB_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(pcib, var, PCIB, ivar, type)
end_define

begin_macro
name|PCIB_ACCESSOR
argument_list|(
argument|domain
argument_list|,
argument|DOMAIN
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCIB_ACCESSOR
argument_list|(
argument|bus
argument_list|,
argument|BUS
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|PCIB_ACCESSOR
end_undef

begin_comment
comment|/*  * PCI interrupt validation.  Invalid interrupt values such as 0 or 128  * on i386 or other platforms should be mapped out in the MD pcireadconf  * code and not here, since the only MI invalid IRQ is 255.  */
end_comment

begin_define
define|#
directive|define
name|PCI_INVALID_IRQ
value|255
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_VALID
parameter_list|(
name|x
parameter_list|)
value|((x) != PCI_INVALID_IRQ)
end_define

begin_comment
comment|/*  * Convenience functions.  *  * These should be used in preference to manually manipulating  * configuration space.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|pci_enable_busmaster
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|PCI_ENABLE_BUSMASTER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_disable_busmaster
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|PCI_DISABLE_BUSMASTER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_enable_io
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|space
parameter_list|)
block|{
return|return
operator|(
name|PCI_ENABLE_IO
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|space
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_disable_io
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|space
parameter_list|)
block|{
return|return
operator|(
name|PCI_DISABLE_IO
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|space
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_get_vpd_ident
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|identptr
parameter_list|)
block|{
return|return
operator|(
name|PCI_GET_VPD_IDENT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|identptr
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_get_vpd_readonly
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|kw
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|identptr
parameter_list|)
block|{
return|return
operator|(
name|PCI_GET_VPD_READONLY
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|kw
argument_list|,
name|identptr
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Check if the address range falls within the VGA defined address range(s)  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|pci_is_vga_ioport_range
parameter_list|(
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|start
operator|>=
literal|0x3b0
operator|&&
name|end
operator|<=
literal|0x3bb
operator|)
operator|||
operator|(
name|start
operator|>=
literal|0x3c0
operator|&&
name|end
operator|<=
literal|0x3df
operator|)
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_is_vga_memory_range
parameter_list|(
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|)
block|{
return|return
operator|(
operator|(
name|start
operator|>=
literal|0xa0000
operator|&&
name|end
operator|<=
literal|0xbffff
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * PCI power states are as defined by ACPI:  *  * D0	State in which device is on and running.  It is receiving full  *	power from the system and delivering full functionality to the user.  * D1	Class-specific low-power state in which device context may or may not  *	be lost.  Buses in D1 cannot do anything to the bus that would force  *	devices on that bus to lose context.  * D2	Class-specific low-power state in which device context may or may  *	not be lost.  Attains greater power savings than D1.  Buses in D2  *	can cause devices on that bus to lose some context.  Devices in D2  *	must be prepared for the bus to be in D2 or higher.  * D3	State in which the device is off and not running.  Device context is  *	lost.  Power can be removed from the device.  */
end_comment

begin_define
define|#
directive|define
name|PCI_POWERSTATE_D0
value|0
end_define

begin_define
define|#
directive|define
name|PCI_POWERSTATE_D1
value|1
end_define

begin_define
define|#
directive|define
name|PCI_POWERSTATE_D2
value|2
end_define

begin_define
define|#
directive|define
name|PCI_POWERSTATE_D3
value|3
end_define

begin_define
define|#
directive|define
name|PCI_POWERSTATE_UNKNOWN
value|-1
end_define

begin_function
specifier|static
name|__inline
name|int
name|pci_set_powerstate
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|state
parameter_list|)
block|{
return|return
name|PCI_SET_POWERSTATE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|state
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_get_powerstate
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
name|PCI_GET_POWERSTATE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_find_cap
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|capability
parameter_list|,
name|int
modifier|*
name|capreg
parameter_list|)
block|{
return|return
operator|(
name|PCI_FIND_EXTCAP
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|capability
argument_list|,
name|capreg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_find_extcap
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|capability
parameter_list|,
name|int
modifier|*
name|capreg
parameter_list|)
block|{
return|return
operator|(
name|PCI_FIND_EXTCAP
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|capability
argument_list|,
name|capreg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_alloc_msi
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|count
parameter_list|)
block|{
return|return
operator|(
name|PCI_ALLOC_MSI
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|count
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_alloc_msix
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|count
parameter_list|)
block|{
return|return
operator|(
name|PCI_ALLOC_MSIX
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|count
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_remap_msix
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|count
parameter_list|,
specifier|const
name|u_int
modifier|*
name|vectors
parameter_list|)
block|{
return|return
operator|(
name|PCI_REMAP_MSIX
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|count
argument_list|,
name|vectors
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_release_msi
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|PCI_RELEASE_MSI
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_msi_count
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|PCI_MSI_COUNT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|pci_msix_count
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|PCI_MSIX_COUNT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|device_t
name|pci_find_bsf
parameter_list|(
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|pci_find_dbsf
parameter_list|(
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|pci_find_device
parameter_list|(
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|pci_find_class
parameter_list|(
name|uint8_t
name|class
parameter_list|,
name|uint8_t
name|subclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Can be used by drivers to manage the MSI-X table. */
end_comment

begin_function_decl
name|int
name|pci_pending_msix
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_msi_device_blacklisted
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_msix_device_blacklisted
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_ht_map_msi
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint64_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|pci_find_pcie_root_port
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_get_max_read_req
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_restore_state
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_save_state
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_set_max_read_req
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pcie_read_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcie_write_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|pcie_adjust_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
name|value
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_BUS_H_ */
end_comment

begin_comment
comment|/*  * cdev switch for control device, initialised in generic PCI code  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|pcicdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * List of all PCI devices, generation count for the list.  */
end_comment

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|devlist
argument_list|,
name|pci_devinfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devlist
name|pci_devq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|pci_generation
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|pci_map
modifier|*
name|pci_find_bar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_bar_enabled
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|pci_map
modifier|*
name|pm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcicfg_vpd
modifier|*
name|pci_fetch_vpd_list
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VGA_PCI_BIOS_SHADOW_ADDR
value|0xC0000
end_define

begin_define
define|#
directive|define
name|VGA_PCI_BIOS_SHADOW_SIZE
value|131072
end_define

begin_function_decl
name|int
name|vga_pci_is_boot_display
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vga_pci_map_bios
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vga_pci_unmap_bios
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|bios
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCIVAR_H_ */
end_comment

end_unit

