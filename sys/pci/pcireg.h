begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** ** $FreeBSD$ ** **  Names for PCI configuration space registers. ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
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
value|"pl2 95/03/21"
end_define

begin_comment
comment|/* ** Device identification register; contains a vendor ID and a device ID. ** We have little need to distinguish the two parts. */
end_comment

begin_define
define|#
directive|define
name|PCI_ID_REG
value|0x00
end_define

begin_comment
comment|/* ** Command and status register. */
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
comment|/* ** Class register; defines basic type of device. */
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
comment|/* ** Header registers */
end_comment

begin_define
define|#
directive|define
name|PCI_HEADER_MISC
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCI_HEADER_MULTIFUNCTION
value|0x00800000
end_define

begin_comment
comment|/* ** Mapping registers */
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

begin_define
define|#
directive|define
name|PCI_MAP_IO_ADDRESS_MASK
value|0xfffffffc
end_define

begin_comment
comment|/* ** PCI-PCI bridge mapping registers */
end_comment

begin_define
define|#
directive|define
name|PCI_PCI_BRIDGE_BUS_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|PCI_PCI_BRIDGE_IO_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCI_PCI_BRIDGE_MEM_REG
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_PCI_BRIDGE_PMEM_REG
value|0x24
end_define

begin_define
define|#
directive|define
name|PCI_SUBID_REG0
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCI_SUBID_REG1
value|0x34
end_define

begin_define
define|#
directive|define
name|PCI_SUBID_REG2
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_SUBORDINATE_BUS_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|PCI_SECONDARY_BUS_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|PCI_PRIMARY_BUS_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|PCI_SUBORDINATE_BUS_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_SECONDARY_BUS_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_PRIMARY_BUS_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)      )& 0xff)
end_define

begin_define
define|#
directive|define
name|PCI_PRIMARY_BUS_INSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)& ~PCI_PRIMARY_BUS_MASK) | ((y)<<  0))
end_define

begin_define
define|#
directive|define
name|PCI_SECONDARY_BUS_INSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)& ~PCI_SECONDARY_BUS_MASK) | ((y)<<  8))
end_define

begin_define
define|#
directive|define
name|PCI_SUBORDINATE_BUS_INSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)& ~PCI_SUBORDINATE_BUS_MASK) | ((y)<< 16))
end_define

begin_define
define|#
directive|define
name|PCI_PPB_IOBASE_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 8)& 0xF000)
end_define

begin_define
define|#
directive|define
name|PCI_PPB_IOLIMIT_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 0)& 0xF000 | 0x0FFF)
end_define

begin_define
define|#
directive|define
name|PCI_PPB_MEMBASE_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 16)& 0xFFF00000)
end_define

begin_define
define|#
directive|define
name|PCI_PPB_MEMLIMIT_EXTRACT
parameter_list|(
name|x
parameter_list|)
value|(((x)<<  0)& 0xFFF00000 | 0x000FFFFF)
end_define

begin_comment
comment|/* ** Interrupt configuration register */
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

