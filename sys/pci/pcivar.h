begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_COMPAT
end_ifndef

begin_define
define|#
directive|define
name|PCI_COMPAT
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|u_int64_t
name|pci_addr_t
typedef|;
end_typedef

begin_comment
comment|/* u_int64_t for system with 64bit addresses */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_int32_t
name|pci_addr_t
typedef|;
end_typedef

begin_comment
comment|/* u_int64_t for system with 64bit addresses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|void
modifier|*
name|hdrspec
decl_stmt|;
comment|/* pointer to header type specific data */
name|u_int16_t
name|subvendor
decl_stmt|;
comment|/* card vendor ID */
name|u_int16_t
name|subdevice
decl_stmt|;
comment|/* card device ID, assigned by card vendor */
name|u_int16_t
name|vendor
decl_stmt|;
comment|/* chip vendor ID */
name|u_int16_t
name|device
decl_stmt|;
comment|/* chip device ID, assigned by chip vendor */
name|u_int16_t
name|cmdreg
decl_stmt|;
comment|/* disable/enable chip and PCI options */
name|u_int16_t
name|statreg
decl_stmt|;
comment|/* supported PCI features and error state */
name|u_int8_t
name|baseclass
decl_stmt|;
comment|/* chip PCI class */
name|u_int8_t
name|subclass
decl_stmt|;
comment|/* chip PCI subclass */
name|u_int8_t
name|progif
decl_stmt|;
comment|/* chip PCI programming interface */
name|u_int8_t
name|revid
decl_stmt|;
comment|/* chip revision ID */
name|u_int8_t
name|hdrtype
decl_stmt|;
comment|/* chip config header type */
name|u_int8_t
name|cachelnsz
decl_stmt|;
comment|/* cache line size in 4byte units */
name|u_int8_t
name|intpin
decl_stmt|;
comment|/* PCI interrupt pin */
name|u_int8_t
name|intline
decl_stmt|;
comment|/* interrupt line (IRQ for PC arch) */
name|u_int8_t
name|mingnt
decl_stmt|;
comment|/* min. useful bus grant time in 250ns units */
name|u_int8_t
name|maxlat
decl_stmt|;
comment|/* max. tolerated bus grant latency in 250ns */
name|u_int8_t
name|lattimer
decl_stmt|;
comment|/* latency timer in units of 30ns bus cycles */
name|u_int8_t
name|mfdev
decl_stmt|;
comment|/* multi-function device (from hdrtype reg) */
name|u_int8_t
name|nummaps
decl_stmt|;
comment|/* actual number of PCI maps used */
name|u_int8_t
name|hose
decl_stmt|;
comment|/* hose which bus is attached to */
name|u_int8_t
name|bus
decl_stmt|;
comment|/* config space bus address */
name|u_int8_t
name|slot
decl_stmt|;
comment|/* config space slot address */
name|u_int8_t
name|func
decl_stmt|;
comment|/* config space function number */
name|u_int8_t
name|secondarybus
decl_stmt|;
comment|/* bus on secondary side of bridge, if any */
name|u_int8_t
name|subordinatebus
decl_stmt|;
comment|/* topmost bus number behind bridge, if any */
name|u_int16_t
name|pp_cap
decl_stmt|;
comment|/* PCI power management capabilities */
name|u_int8_t
name|pp_status
decl_stmt|;
comment|/* config space address of PCI power status reg */
name|u_int8_t
name|pp_pmcsr
decl_stmt|;
comment|/* config space address of PMCSR reg */
name|u_int8_t
name|pp_data
decl_stmt|;
comment|/* config space address of PCI power data reg */
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
name|u_int32_t
name|membase
decl_stmt|;
comment|/* base address of memory window */
name|u_int32_t
name|memlimit
decl_stmt|;
comment|/* topmost address of memory window */
name|u_int32_t
name|iobase
decl_stmt|;
comment|/* base address of port window */
name|u_int32_t
name|iolimit
decl_stmt|;
comment|/* topmost address of port window */
name|u_int16_t
name|secstat
decl_stmt|;
comment|/* secondary bus status register */
name|u_int16_t
name|bridgectl
decl_stmt|;
comment|/* bridge control register */
name|u_int8_t
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
name|u_int32_t
name|membase0
decl_stmt|;
comment|/* base address of memory window */
name|u_int32_t
name|memlimit0
decl_stmt|;
comment|/* topmost address of memory window */
name|u_int32_t
name|membase1
decl_stmt|;
comment|/* base address of memory window */
name|u_int32_t
name|memlimit1
decl_stmt|;
comment|/* topmost address of memory window */
name|u_int32_t
name|iobase0
decl_stmt|;
comment|/* base address of port window */
name|u_int32_t
name|iolimit0
decl_stmt|;
comment|/* topmost address of port window */
name|u_int32_t
name|iobase1
decl_stmt|;
comment|/* base address of port window */
name|u_int32_t
name|iolimit1
decl_stmt|;
comment|/* topmost address of port window */
name|u_int32_t
name|pccardif
decl_stmt|;
comment|/* PC Card 16bit IF legacy more base addr. */
name|u_int16_t
name|secstat
decl_stmt|;
comment|/* secondary bus status register */
name|u_int16_t
name|bridgectl
decl_stmt|;
comment|/* bridge control register */
name|u_int8_t
name|seclat
decl_stmt|;
comment|/* CardBus latency timer */
block|}
name|pcih2cfgregs
typedef|;
end_typedef

begin_comment
comment|/* PCI bus attach definitions (there could be multiple PCI bus *trees* ... */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pciattach
block|{
name|int
name|unit
decl_stmt|;
name|int
name|pcibushigh
decl_stmt|;
name|struct
name|pciattach
modifier|*
name|next
decl_stmt|;
block|}
name|pciattach
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|u_int32_t
name|pci_numdevs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* externally visible functions */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|pci_ata_match
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pci_usb_match
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pci_vga_match
parameter_list|(
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* low level PCI config register functions provided by pcibus.c */
end_comment

begin_function_decl
name|int
name|pci_cfgread
parameter_list|(
name|pcicfgregs
modifier|*
name|cfg
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_cfgwrite
parameter_list|(
name|pcicfgregs
modifier|*
name|cfg
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|data
parameter_list|,
name|int
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_function_decl
name|vm_offset_t
name|pci_cvt_to_dense
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|pci_cvt_to_bwx
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __alpha__ */
end_comment

begin_comment
comment|/* low level devlist operations for the 2.2 compatibility code in pci.c */
end_comment

begin_function_decl
name|pcicfgregs
modifier|*
name|pci_devlist_get_parent
parameter_list|(
name|pcicfgregs
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

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
name|PCI_IVAR_SECONDARYBUS
block|,
name|PCI_IVAR_SUBORDINATEBUS
block|,
name|PCI_IVAR_HOSE
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
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									\
value|static __inline T pci_get_ ## A(device_t dev)				\ {									\ 	uintptr_t v;							\ 	BUS_READ_IVAR(device_get_parent(dev), dev, PCI_IVAR_ ## B,&v);	\ 	return (T) v;							\ }									\ 									\ static __inline void pci_set_ ## A(device_t dev, T t)			\ {									\ 	u_long v = (u_long) t;						\ 	BUS_WRITE_IVAR(device_get_parent(dev), dev, PCI_IVAR_ ## B, v);	\ }
end_define

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subvendor
argument_list|,
argument|SUBVENDOR
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subdevice
argument_list|,
argument|SUBDEVICE
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|vendor
argument_list|,
argument|VENDOR
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|device
argument_list|,
argument|DEVICE
argument_list|,
argument|u_int16_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|devid
argument_list|,
argument|DEVID
argument_list|,
argument|u_int32_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|class
argument_list|,
argument|CLASS
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subclass
argument_list|,
argument|SUBCLASS
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|progif
argument_list|,
argument|PROGIF
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|revid
argument_list|,
argument|REVID
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|intpin
argument_list|,
argument|INTPIN
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|irq
argument_list|,
argument|IRQ
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|bus
argument_list|,
argument|BUS
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|slot
argument_list|,
argument|SLOT
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|function
argument_list|,
argument|FUNCTION
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|secondarybus
argument_list|,
argument|SECONDARYBUS
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|subordinatebus
argument_list|,
argument|SUBORDINATEBUS
argument_list|,
argument|u_int8_t
argument_list|)
end_macro

begin_macro
name|PCI_ACCESSOR
argument_list|(
argument|hose
argument_list|,
argument|HOSE
argument_list|,
argument|u_int32_t
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|u_int32_t
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
name|u_int32_t
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
comment|/*  * Convenience functions.  *  * These should be used in preference to manually manipulating  * configuration space.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|pci_enable_busmaster
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|PCI_ENABLE_BUSMASTER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pci_disable_busmaster
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|PCI_DISABLE_BUSMASTER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pci_enable_io
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|space
parameter_list|)
block|{
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
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pci_disable_io
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|space
parameter_list|)
block|{
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
expr_stmt|;
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
name|PCIB_IVAR_HOSE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|PCIB_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									 \
value|static __inline T pcib_get_ ## A(device_t dev)				 \ {									 \ 	uintptr_t v;							 \ 	BUS_READ_IVAR(device_get_parent(dev), dev, PCIB_IVAR_ ## B,&v); \ 	return (T) v;							 \ }									 \ 									 \ static __inline void pcib_set_ ## A(device_t dev, T t)			 \ {									 \ 	u_long v = (u_long) t;						 \ 	BUS_WRITE_IVAR(device_get_parent(dev), dev, PCIB_IVAR_ ## B, v); \ }
end_define

begin_macro
name|PCIB_ACCESSOR
argument_list|(
argument|hose
argument_list|,
argument|HOSE
argument_list|,
argument|u_int32_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for compatibility to FreeBSD-2.2 version of PCI code */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_COMPAT
end_ifdef

begin_typedef
typedef|typedef
name|pcicfgregs
modifier|*
name|pcici_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|pcidi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pci_inthand_t
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|pci_max_burst_len
value|(3)
end_define

begin_comment
comment|/* just copied from old PCI code for now ... */
end_comment

begin_struct
struct|struct
name|pci_device
block|{
name|char
modifier|*
name|pd_name
decl_stmt|;
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|pd_probe
function_decl|)
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pd_attach
function_decl|)
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
name|u_long
modifier|*
name|pd_count
decl_stmt|;
name|int
function_decl|(
modifier|*
name|pd_shutdown
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_typedef
typedef|typedef
name|u_short
name|pci_port_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_int
name|pci_port_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_long
name|pci_conf_read
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_conf_write
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|,
name|u_long
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_map_port
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|,
name|pci_port_t
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_map_mem
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|reg
parameter_list|,
name|vm_offset_t
modifier|*
name|va
parameter_list|,
name|vm_offset_t
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_map_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pci_inthand_t
modifier|*
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|intrmask_t
modifier|*
name|maskptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_map_int_right
parameter_list|(
name|pcici_t
name|cfg
parameter_list|,
name|pci_inthand_t
modifier|*
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|intrmask_t
modifier|*
name|maskptr
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_unmap_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcici_t
name|pci_get_parent_from_tag
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pci_get_bus_from_tag
parameter_list|(
name|pcici_t
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|module
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|compat_pci_handler
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|COMPAT_PCI_DRIVER
parameter_list|(
name|name
parameter_list|,
name|pcidata
parameter_list|)
define|\
value|static moduledata_t name##_mod = {					\ 	#name,								\ 	compat_pci_handler,						\&pcidata							\ };									\ DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_ANY)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_COMPAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCIVAR_H_ */
end_comment

end_unit

