begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *       Copyright (c) 1997 by Simon Shapiro  *       All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_empty
empty|#ident "$Id: dpt_pci.h,v 1.3 1997/10/02 04:25:30 ShimonR Exp $"
end_empty

begin_define
define|#
directive|define
name|DPT_VENDOR_ID
value|0x00001044
end_define

begin_define
define|#
directive|define
name|DPT_DEVICE_ID
value|0x0000a400
end_define

begin_comment
comment|/* The following are taken, shamelessly from Linux include/linux/pci.h */
end_comment

begin_comment
comment|/*  * Under PCI, each device has 256 bytes of configuration address space,  * of which the first 64 bytes are standardized as follows:  */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_ID
value|0x00
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVICE_ID
value|0x02
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND
value|0x04
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_IO
value|0x1
end_define

begin_comment
comment|/* Enable response in I/O space */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_MEMORY
value|0x2
end_define

begin_comment
comment|/* Enable response in Memory space */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_MASTER
value|0x4
end_define

begin_comment
comment|/* Enable bus mastering */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_SPECIAL
value|0x8
end_define

begin_comment
comment|/* Enable response to special cycles */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_INVALIDATE
value|0x10
end_define

begin_comment
comment|/* Use memory write and invalidate */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_VGA_PALETTE
value|0x20
end_define

begin_comment
comment|/* Enable palette snooping */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_PARITY
value|0x40
end_define

begin_comment
comment|/* Enable parity checking */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_WAIT
value|0x80
end_define

begin_comment
comment|/* Enable address/data stepping */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_SERR
value|0x100
end_define

begin_comment
comment|/* Enable SERR */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_FAST_BACK
value|0x200
end_define

begin_comment
comment|/* Enable back-to-back writes */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS
value|0x06
end_define

begin_comment
comment|/* 16 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_66MHZ
value|0x20
end_define

begin_comment
comment|/* Support 66 Mhz PCI 2.1 bus */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_UDF
value|0x40
end_define

begin_comment
comment|/* Support User Definable Features */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_FAST_BACK
value|0x80
end_define

begin_comment
comment|/* Accept fast-back to back */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_PARITY
value|0x100
end_define

begin_comment
comment|/* Detected parity error */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_STATUS_DEVSEL_MASK
end_ifndef

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_MASK
value|0x600
end_define

begin_comment
comment|/* DEVSEL timing */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_FAST
value|0x000
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_MEDIUM
value|0x200
end_define

begin_define
define|#
directive|define
name|PCI_STATUS_DEVSEL_SLOW
value|0x400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_STATUS_SIG_TARGET_ABORT
value|0x800
end_define

begin_comment
comment|/* Set on target abort */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_REC_TARGET_ABORT
value|0x1000
end_define

begin_comment
comment|/* Master ack of " */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_REC_MASTER_ABORT
value|0x2000
end_define

begin_comment
comment|/* Set on master abort */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_SIG_SYSTEM_ERROR
value|0x4000
end_define

begin_comment
comment|/* Set when we drive SERR */
end_comment

begin_define
define|#
directive|define
name|PCI_STATUS_DETECTED_PARITY
value|0x8000
end_define

begin_comment
comment|/* Set on parity error */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_REVISION
value|0x08
end_define

begin_comment
comment|/* High 24 bits are class, low 8 					 * revision */
end_comment

begin_define
define|#
directive|define
name|PCI_REVISION_ID
value|0x08
end_define

begin_comment
comment|/* Revision ID */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_PROG
value|0x09
end_define

begin_comment
comment|/* Reg. Level Programming Interface */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_DEVICE
value|0x0a
end_define

begin_comment
comment|/* Device class */
end_comment

begin_define
define|#
directive|define
name|PCI_CACHE_LINE_SIZE
value|0x0c
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_LATENCY_TIMER
value|0x0d
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_HEADER_TYPE
value|0x0e
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BIST
value|0x0f
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BIST_CODE_MASK
value|0x0f
end_define

begin_comment
comment|/* Return result */
end_comment

begin_define
define|#
directive|define
name|PCI_BIST_START
value|0x40
end_define

begin_comment
comment|/* 1 to start BIST, 2 secs or less */
end_comment

begin_define
define|#
directive|define
name|PCI_BIST_CAPABLE
value|0x80
end_define

begin_comment
comment|/* 1 if BIST capable */
end_comment

begin_comment
comment|/*  * Base addresses specify locations in memory or I/O space.  * Decoded size can be determined by writing a value of  * 0xffffffff to the register, and reading it back.  Only  * 1 bits are decoded.  */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_0
value|0x10
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_1
value|0x14
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_2
value|0x18
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_3
value|0x1c
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_4
value|0x20
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_5
value|0x24
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_SPACE
value|0x01
end_define

begin_comment
comment|/* 0 = memory, 1 = I/O */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_SPACE_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_SPACE_MEMORY
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_TYPE_MASK
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_TYPE_32
value|0x00
end_define

begin_comment
comment|/* 32 bit address */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_TYPE_1M
value|0x02
end_define

begin_comment
comment|/* Below 1M */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_TYPE_64
value|0x04
end_define

begin_comment
comment|/* 64 bit address */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_PREFETCH
value|0x08
end_define

begin_comment
comment|/* prefetchable? */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_MEM_MASK
value|(~0x0f)
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESS_IO_MASK
value|(~0x03)
end_define

begin_comment
comment|/* bit 1 is reserved if address_space = 1 */
end_comment

begin_define
define|#
directive|define
name|PCI_CARDBUS_CIS
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_SUBSYSTEM_ID
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCI_SUBSYSTEM_VENDOR_ID
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCI_ROM_ADDRESS
value|0x30
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_ROM_ADDRESS_ENABLE
value|0x01
end_define

begin_comment
comment|/* Write 1 to enable ROM, bits 31..11 					 * are address, 10..2 are reserved */
end_comment

begin_comment
comment|/* 0x34-0x3b are reserved */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERRUPT_LINE
value|0x3c
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_INTERRUPT_PIN
value|0x3d
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_MIN_GNT
value|0x3e
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_MAX_LAT
value|0x3f
end_define

begin_comment
comment|/* 8 bits */
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_NOT_DEFINED
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NOT_DEFINED_VGA
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_STORAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_SCSI
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_IDE
value|0x0101
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_FLOPPY
value|0x0102
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_IPI
value|0x0103
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_RAID
value|0x0104
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_STORAGE_OTHER
value|0x0180
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_NETWORK
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_ETHERNET
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_TOKEN_RING
value|0x0201
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_FDDI
value|0x0202
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_ATM
value|0x0203
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_OTHER
value|0x0280
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_DISPLAY
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_VGA
value|0x0300
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_XGA
value|0x0301
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_OTHER
value|0x0380
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_MULTIMEDIA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MULTIMEDIA_VIDEO
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MULTIMEDIA_AUDIO
value|0x0401
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MULTIMEDIA_OTHER
value|0x0480
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_MEMORY
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_RAM
value|0x0500
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_FLASH
value|0x0501
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_OTHER
value|0x0580
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_BRIDGE
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_HOST
value|0x0600
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_ISA
value|0x0601
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_EISA
value|0x0602
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_MC
value|0x0603
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_PCI
value|0x0604
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_PCMCIA
value|0x0605
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_NUBUS
value|0x0606
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_CARDBUS
value|0x0607
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_OTHER
value|0x0680
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_COMMUNICATION
value|0x07
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_COMMUNICATION_SERIAL
value|0x0700
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_COMMUNICATION_PARALLEL
value|0x0701
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_COMMUNICATION_OTHER
value|0x0780
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_SYSTEM
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_PIC
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_DMA
value|0x0801
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_TIMER
value|0x0802
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_RTC
value|0x0803
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_OTHER
value|0x0880
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_INPUT
value|0x09
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INPUT_KEYBOARD
value|0x0900
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INPUT_PEN
value|0x0901
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INPUT_MOUSE
value|0x0902
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INPUT_OTHER
value|0x0980
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_DOCKING
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DOCKING_GENERIC
value|0x0a00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DOCKING_OTHER
value|0x0a01
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_PROCESSOR
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_386
value|0x0b00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_486
value|0x0b01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_PENTIUM
value|0x0b02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_ALPHA
value|0x0b10
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_POWERPC
value|0x0b20
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR_CO
value|0x0b40
end_define

begin_define
define|#
directive|define
name|PCI_BASE_CLASS_SERIAL
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_FIREWIRE
value|0x0c00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_ACCESS
value|0x0c01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_SSA
value|0x0c02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_USB
value|0x0c03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_FIBER
value|0x0c04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_OTHERS
value|0xff
end_define

end_unit

