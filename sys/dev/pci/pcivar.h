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
name|PCI_BUSMAX
value|255
end_define

begin_comment
comment|/* highest supported bus number */
end_comment

begin_define
define|#
directive|define
name|PCI_SLOTMAX
value|31
end_define

begin_comment
comment|/* highest supported slot number */
end_comment

begin_define
define|#
directive|define
name|PCI_FUNCMAX
value|7
end_define

begin_comment
comment|/* highest supported function number */
end_comment

begin_define
define|#
directive|define
name|PCI_REGMAX
value|255
end_define

begin_comment
comment|/* highest supported config register addr. */
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

begin_comment
comment|/* pci_addr_t covers this system's PCI bus address space: 32 or 64 bit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_A64
end_ifdef

begin_typedef
typedef|typedef
name|uint64_t
name|pci_addr_t
typedef|;
end_typedef

begin_comment
comment|/* uint64_t for system with 64bit addresses */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint32_t
name|pci_addr_t
typedef|;
end_typedef

begin_comment
comment|/* uint64_t for system with 64bit addresses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* config space address of PCI power status reg */
name|uint8_t
name|pp_pmcsr
decl_stmt|;
comment|/* config space address of PMCSR reg */
name|uint8_t
name|pp_data
decl_stmt|;
comment|/* config space address of PCI power data reg */
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
name|msi_msgnum
decl_stmt|;
comment|/* Number of messages */
name|uint16_t
name|msi_data
decl_stmt|;
comment|/* Location of MSI data word */
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
name|uint32_t
name|bar
index|[
name|PCI_MAXMAPS_0
index|]
decl_stmt|;
comment|/* BARs */
name|uint32_t
name|bios
decl_stmt|;
comment|/* BIOS mapping */
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
comment|/* pci power management */
name|struct
name|pcicfg_msi
name|msi
decl_stmt|;
comment|/* pci msi */
block|}
name|pcicfgregs
typedef|;
end_typedef

begin_comment
comment|/* additional type 1 device config header information (PCI to PCI bridge) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_A64
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCI_PPBMEMBASE
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((l)<<16)& ~0xfffff)
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
value|(((l)<<16) | 0xfffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_A64 */
end_comment

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

begin_comment
comment|/*  * Define pci-specific resource flags for accessing memory via dense  * or bwx memory spaces. These flags are ignored on i386.  */
end_comment

begin_define
define|#
directive|define
name|PCI_RF_DENSE
value|0x10000
end_define

begin_define
define|#
directive|define
name|PCI_RF_BWX
value|0x20000
end_define

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
block|, }
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
comment|/*  * PCI power states are as defined by ACPI:  *  * D0	State in which device is on and running.  It is receiving full  *	power from the system and delivering full functionality to the user.  * D1	Class-specific low-power state in which device context may or may not  *	be lost.  Buses in D1 cannot do anything to the bus that would force  *	devices on that bus to loose context.  * D2	Class-specific low-power state in which device context may or may  *	not be lost.  Attains greater power savings than D1.  Buses in D2  *	can cause devices on that bus to loose some context.  Devices in D2  *	must be prepared for the bus to be in D2 or higher.  * D3	State in which the device is off and not running.  Device context is  *	lost.  Power can be removed from the device.  */
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
name|pci_find_device
parameter_list|(
name|uint16_t
parameter_list|,
name|uint16_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCIVAR_H_ */
end_comment

end_unit

