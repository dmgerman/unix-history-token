begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: pcireg.h,v 2.2 94/10/11 19:01:08 wolf Oct11 $ ** **  Declarations for pci bus drivers. ** **  386bsd / FreeBSD ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_REG_H__
end_define

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	main pci initialization function. **	called at boot time from autoconf.c ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|void
name|pci_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*----------------------------------------------------------------- ** **	The pci configuration id describes a pci device on the bus. **	It is constructed from: bus, device& function numbers. ** **----------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_long
name|cfg1
decl_stmt|;
struct|struct
block|{
name|u_char
name|enable
decl_stmt|;
name|u_char
name|forward
decl_stmt|;
name|u_short
name|port
decl_stmt|;
block|}
name|cfg2
struct|;
block|}
name|pcici_t
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------------- ** **	Each pci device has an unique device id. **	It is used to find a matching driver. ** **----------------------------------------------------------------- */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|pcidi_t
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	The pci driver structure. ** **	probe:	Checks if the driver can support a device **		with this type. The tag may be used to get **		more info with pci_read_conf(). See below. **		It returns a string with the devices name, **		or a NULL pointer, if the driver cannot **		support this device. ** **	attach:	Allocate a control structure and prepare **		it. This function may use the pci mapping **		functions. See below. **		(configuration id) or type. ** **	count:	A pointer to a unit counter. **		It's used by the pci configurator to **		allocate unit numbers. ** **----------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|pci_driver
block|{
name|char
modifier|*
function_decl|(
modifier|*
name|probe
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
name|attach
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
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	Per device structure. ** **	An array of this structure should be created by the **	config utility and live in "ioconf.c". ** **	At the moment it's created by hand and lives in **	pci_config.c ** **	pd_driver: **		a pointer to the driver structure. ** **	pd_name: **		the name of the devices which are supported **		by this driver for kernel messages. ** **	pd_flags: **		for further study. ** **----------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|pci_device
block|{
name|struct
name|pci_driver
modifier|*
name|pd_driver
decl_stmt|;
specifier|const
name|char
modifier|*
name|pd_name
decl_stmt|;
name|int
name|pd_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------------------------------------------------- ** **	This table should be generated in file "ioconf.c" **	by the config program. **	It is used at boot time by the configuration function **	pci_configure() ** **----------------------------------------------------------------- */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pci_device
name|pci_devtab
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to physical and virtual memory. ** **	The va and pa addresses are "in/out" parameters. **	If they are 0 on entry, the function assigns an address. ** **	Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the physical address. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_map_mem
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|entry
parameter_list|,
name|u_long
modifier|*
name|va
parameter_list|,
name|u_long
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci device to an io port area. ** **	*pa is an "in/out" parameter. **	If it's 0 on entry, the function assigns an port number.. ** **	Entry selects the register in the pci configuration **	space, which supplies the size of the region, and **	receives the port number. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_map_port
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|u_long
name|entry
parameter_list|,
name|u_short
modifier|*
name|pa
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	Map a pci interrupt to an isa irq line, **	and enable the interrupt. ** **	func is the interrupt handler, arg is the argument **	to this function. ** **	The maskptr argument should be&bio_imask, **&net_imask etc. or NULL. ** **	If there is any error, a message is written, and **	the function returns with zero. **	Else it returns with a value different to zero. ** **	A word of caution for FreeBSD 2.0: ** **	We use the register_intr() function. ** **	The interrupt line of the selected device is included **	into the supplied mask: after the corresponding splXXX **	this drivers interrupts are blocked. ** **	But in the interrupt handlers startup code ONLY **	the interrupt of the driver is blocked, and NOT **	all interrupts of the spl group. ** **	It may be required to additional block the group **	interrupts by splXXX() inside the interrupt handler. ** **	In pre 2.0 kernels we emulate the register_intr **	function. The emulating function blocks all interrupts **	of the group in the interrupt handler prefix code. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_map_int
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
modifier|*
name|maskptr
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------- ** **	The following functions are provided by the pci bios. **	They are used only by the pci configuration. ** **	pci_conf_mode(): **		Probes for a pci system. **		Returns 1 or 2 for pci configuration mechanism. **		Returns 0 if no pci system. ** **	pcitag(): **		Gets a handle for accessing the pci configuration **		space. **		This handle is given to the mapping functions (see **		above) or to the read/write functions. ** **	pci_conf_read(): **		Read a long word from the pci configuration space. **		Requires a tag (from pcitag) and the register **		number (should be a long word alligned one). ** **	pci_conf_write(): **		Writes a long word to the pci configuration space. **		Requires a tag (from pcitag), the register number **		(should be a long word alligned one), and a value. ** **----------------------------------------------------------------- */
end_comment

begin_function_decl
name|int
name|pci_conf_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pcici_t
name|pcitag
parameter_list|(
name|unsigned
name|char
name|bus
parameter_list|,
name|unsigned
name|char
name|device
parameter_list|,
name|unsigned
name|char
name|func
parameter_list|)
function_decl|;
end_function_decl

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

begin_escape
end_escape

begin_comment
comment|/*------------------------------------------------------------------ ** **	Names for PCI configuration space registers. ** **	Copyright (c) 1994 Charles Hannum.  All rights reserved. ** **------------------------------------------------------------------ */
end_comment

begin_comment
comment|/*  * Device identification register; contains a vendor ID and a device ID.  * We have little need to distinguish the two parts.  */
end_comment

begin_define
define|#
directive|define
name|PCI_ID_REG
value|0x00
end_define

begin_comment
comment|/*  * Command and status register.  */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_STATUS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_IO_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_MEM_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_MASTER_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_SPECIAL_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_INVALIDATE_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_PALETTE_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_PARITY_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_STEPPING_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_SERR_ENABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_BACKTOBACK_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_BACKTOBACK_OKAY
value|0x00800000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_PARITY_ERROR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_FAST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_MEDIUM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_SLOW
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_MASK
value|0x06000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_TARGET_TARGET_ABORT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_MASTER_TARGET_ABORT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_MASTER_ABORT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_SPECIAL_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_PARITY_DETECT
value|0x80000000
end_define

begin_comment
comment|/*  * Class register; defines basic type of device.  */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASK
value|0x00ff0000
end_define

begin_comment
comment|/* base classes */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_PREHISTORIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY
value|0x03000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MULTIMEDIA
value|0x04000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY
value|0x05000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE
value|0x06000000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_UNDEFINED
value|0xff000000
end_define

begin_comment
comment|/* 0x00 prehistoric subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PREHISTORIC_MISC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PREHISTORIC_VGA
value|0x00010000
end_define

begin_comment
comment|/* 0x01 mass storage subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASS_STORAGE_SCSI
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASS_STORAGE_IDE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASS_STORAGE_FLOPPY
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASS_STORAGE_IPI
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MASS_STORAGE_MISC
value|0x00800000
end_define

begin_comment
comment|/* 0x02 network subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_NETWORK_ETHERNET
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_NETWORK_TOKENRING
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_NETWORK_FDDI
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_NETWORK_MISC
value|0x00800000
end_define

begin_comment
comment|/* 0x03 display subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DISPLAY_VGA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DISPLAY_XGA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DISPLAY_MISC
value|0x00800000
end_define

begin_comment
comment|/* 0x04 multimedia subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MULTIMEDIA_VIDEO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MULTIMEDIA_AUDIO
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MULTIMEDIA_MISC
value|0x00800000
end_define

begin_comment
comment|/* 0x05 memory subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MEMORY_RAM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MEMORY_FLASH
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MEMORY_MISC
value|0x00800000
end_define

begin_comment
comment|/* 0x06 bridge subclasses */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_HOST
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_ISA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_EISA
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_MC
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_PCI
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_PCMCIA
value|0x00050000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BRIDGE_MISC
value|0x00800000
end_define

begin_comment
comment|/*  * Mapping registers  */
end_comment

begin_define
define|#
directive|define
name|PCI_MAP_REG_START
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_MAP_REG_END
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_MAP_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_32BIT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_32BIT_1M
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_64BIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_TYPE_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_CACHABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PCI_MAP_MEMORY_ADDRESS_MASK
value|0xfffffff0
end_define

begin_comment
comment|/*  * Interrupt configuration register  */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERRUPT_REG
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|((((x)& PCI_INTERRUPT_PIN_MASK)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_A
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_B
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_C
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN_D
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|((((x)& PCI_INTERRUPT_LINE_MASK)>> 0)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE_INSERT
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(((x)& ~PCI_INTERRUPT_LINE_MASK) | ((v)<< 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PCI_REG_H__ */
end_comment

end_unit

