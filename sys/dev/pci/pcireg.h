begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * PCIM_xxx: mask to locate subfield in register  * PCIR_xxx: config register offset  * PCIC_xxx: device class  * PCIS_xxx: device subclass  * PCIP_xxx: device programming interface  * PCIV_xxx: PCI vendor ID (only required to fixup ancient devices)  * PCID_xxx: device ID  * PCIY_xxx: capability identification number  */
end_comment

begin_comment
comment|/* some PCI bus constants */
end_comment

begin_define
define|#
directive|define
name|PCI_BUSMAX
value|255
end_define

begin_define
define|#
directive|define
name|PCI_SLOTMAX
value|31
end_define

begin_define
define|#
directive|define
name|PCI_FUNCMAX
value|7
end_define

begin_define
define|#
directive|define
name|PCI_REGMAX
value|255
end_define

begin_define
define|#
directive|define
name|PCI_MAXHDRTYPE
value|2
end_define

begin_comment
comment|/* PCI config header registers for all devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_DEVVENDOR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIR_VENDOR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIR_DEVICE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIR_COMMAND
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_PORTEN
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_MEMEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_BUSMASTEREN
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_SPECIALEN
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_MWRICEN
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_PERRESPEN
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_SERRESPEN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_CMD_BACKTOBACK
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIR_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_CAPPRESENT
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_66CAPABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_BACKTOBACK
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_PERRREPORT
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_FAST
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_MEDIMUM
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_SLOW
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SEL_MASK
value|0x0600
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_STABORT
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_RTABORT
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_RMABORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_SERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_STATUS_PERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIR_REVID
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIR_PROGIF
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIR_SUBCLASS
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCIR_CLASS
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCIR_CACHELNSZ
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCIR_LATTIMER
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCIR_HDRTYPE
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE
value|0x7f
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_BRIDGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIM_HDRTYPE_CARDBUS
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIM_MFDEV
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIR_BIST
value|0x0f
end_define

begin_comment
comment|/* Capability Identification Numbers */
end_comment

begin_define
define|#
directive|define
name|PCIY_PMG
value|0x01
end_define

begin_comment
comment|/* PCI Power Management */
end_comment

begin_define
define|#
directive|define
name|PCIY_AGP
value|0x02
end_define

begin_comment
comment|/* AGP */
end_comment

begin_define
define|#
directive|define
name|PCIY_VPD
value|0x03
end_define

begin_comment
comment|/* Vital Product Data */
end_comment

begin_define
define|#
directive|define
name|PCIY_SLOTID
value|0x04
end_define

begin_comment
comment|/* Slot Identification */
end_comment

begin_define
define|#
directive|define
name|PCIY_MSI
value|0x05
end_define

begin_comment
comment|/* Message Signaled Interrupts */
end_comment

begin_define
define|#
directive|define
name|PCIY_CHSWP
value|0x06
end_define

begin_comment
comment|/* CompactPCI Hot Swap */
end_comment

begin_define
define|#
directive|define
name|PCIY_PCIX
value|0x07
end_define

begin_comment
comment|/* PCI-X */
end_comment

begin_define
define|#
directive|define
name|PCIY_HT
value|0x08
end_define

begin_comment
comment|/* HyperTransport */
end_comment

begin_define
define|#
directive|define
name|PCIY_VENDOR
value|0x09
end_define

begin_comment
comment|/* Vendor Unique */
end_comment

begin_define
define|#
directive|define
name|PCIY_DEBUG
value|0x0a
end_define

begin_comment
comment|/* Debug port */
end_comment

begin_define
define|#
directive|define
name|PCIY_CRES
value|0x0b
end_define

begin_comment
comment|/* CompactPCI central resource control */
end_comment

begin_define
define|#
directive|define
name|PCIY_HOTPLUG
value|0x0c
end_define

begin_comment
comment|/* PCI Hot-Plug */
end_comment

begin_define
define|#
directive|define
name|PCIY_AGP8X
value|0x0e
end_define

begin_comment
comment|/* AGP 8x */
end_comment

begin_define
define|#
directive|define
name|PCIY_SECDEV
value|0x0f
end_define

begin_comment
comment|/* Secure Device */
end_comment

begin_define
define|#
directive|define
name|PCIY_EXPRESS
value|0x10
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|PCIY_MSIX
value|0x11
end_define

begin_comment
comment|/* MSI-X */
end_comment

begin_comment
comment|/* config registers for header type 0 devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_BARS
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIR_BAR
parameter_list|(
name|x
parameter_list|)
value|(PCIR_BARS + (x) * 4)
end_define

begin_define
define|#
directive|define
name|PCIR_CARDBUSCIS
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIR_SUBVEND_0
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIR_SUBDEV_0
value|0x2e
end_define

begin_define
define|#
directive|define
name|PCIR_BIOS
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIM_BIOS_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIR_CAP_PTR
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIR_INTLINE
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCIR_INTPIN
value|0x3d
end_define

begin_define
define|#
directive|define
name|PCIR_MINGNT
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIR_MAXLAT
value|0x3f
end_define

begin_comment
comment|/* config registers for header type 1 (PCI-to-PCI bridge) devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_SECSTAT_1
value|0x1e
end_define

begin_define
define|#
directive|define
name|PCIR_PRIBUS_1
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIR_SECBUS_1
value|0x19
end_define

begin_define
define|#
directive|define
name|PCIR_SUBBUS_1
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCIR_SECLAT_1
value|0x1b
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASEL_1
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMITL_1
value|0x1d
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASEH_1
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMITH_1
value|0x32
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_16
value|0x0
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_32
value|0x1
end_define

begin_define
define|#
directive|define
name|PCIM_BRIO_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE_1
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT_1
value|0x22
end_define

begin_define
define|#
directive|define
name|PCIR_PMBASEL_1
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIR_PMLIMITL_1
value|0x26
end_define

begin_define
define|#
directive|define
name|PCIR_PMBASEH_1
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIR_PMLIMITH_1
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIR_BRIDGECTL_1
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIR_SUBVEND_1
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIR_SUBDEV_1
value|0x36
end_define

begin_comment
comment|/* config registers for header type 2 (CardBus) devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_SECSTAT_2
value|0x16
end_define

begin_define
define|#
directive|define
name|PCIR_PRIBUS_2
value|0x18
end_define

begin_define
define|#
directive|define
name|PCIR_SECBUS_2
value|0x19
end_define

begin_define
define|#
directive|define
name|PCIR_SUBBUS_2
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCIR_SECLAT_2
value|0x1b
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE0_2
value|0x1c
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT0_2
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIR_MEMBASE1_2
value|0x24
end_define

begin_define
define|#
directive|define
name|PCIR_MEMLIMIT1_2
value|0x28
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASE0_2
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMIT0_2
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIR_IOBASE1_2
value|0x34
end_define

begin_define
define|#
directive|define
name|PCIR_IOLIMIT1_2
value|0x38
end_define

begin_define
define|#
directive|define
name|PCIR_BRIDGECTL_2
value|0x3e
end_define

begin_define
define|#
directive|define
name|PCIR_SUBVEND_2
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIR_SUBDEV_2
value|0x42
end_define

begin_define
define|#
directive|define
name|PCIR_PCCARDIF_2
value|0x44
end_define

begin_comment
comment|/* PCI device class, subclass and programming interface definitions */
end_comment

begin_define
define|#
directive|define
name|PCIC_OLD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_OLD_NONVGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_OLD_VGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIC_STORAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_SCSI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_IDE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MODEPRIM
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_PROGINDPRIM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MODESEC
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_PROGINDSEC
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIP_STORAGE_IDE_MASTERDEV
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_FLOPPY
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_IPI
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_RAID
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_STORAGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_NETWORK
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ETHERNET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_TOKENRING
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_FDDI
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ATM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_ISDN
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_NETWORK_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DISPLAY
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_VGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_XGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_3D
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_DISPLAY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_MULTIMEDIA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_VIDEO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_AUDIO
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_TELE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_MEMORY
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_RAM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_FLASH
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_MEMORY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_BRIDGE
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_HOST
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_ISA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_EISA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_MCA
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_PCI
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_PCMCIA
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_NUBUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_CARDBUS
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_RACEWAY
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIS_BRIDGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_SIMPLECOMM
value|0x07
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_UART
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SIMPLECOMM_UART_16550A
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_PAR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_MULSER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_MODEM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_SIMPLECOMM_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_BASEPERIPH
value|0x08
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_PIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_TIMER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_RTC
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_PCIHOT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_BASEPERIPH_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_INPUTDEV
value|0x09
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_KEYBOARD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_DIGITIZER
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_MOUSE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_SCANNER
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_GAMEPORT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_INPUTDEV_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DOCKING
value|0x0a
end_define

begin_define
define|#
directive|define
name|PCIS_DOCKING_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DOCKING_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_PROCESSOR
value|0x0b
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_386
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_486
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_PENTIUM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_ALPHA
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_POWERPC
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_MIPS
value|0x30
end_define

begin_define
define|#
directive|define
name|PCIS_PROCESSOR_COPROC
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIC_SERIALBUS
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_FW
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_ACCESS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_SSA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_USB
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_UHCI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_OHCI
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIP_SERIALBUS_USB_EHCI
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_FC
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIS_SERIALBUS_SMBUS
value|0x05
end_define

begin_define
define|#
directive|define
name|PCIC_WIRELESS
value|0x0d
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_IRDA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_IR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_RF
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_WIRELESS_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_INTELLIIO
value|0x0e
end_define

begin_define
define|#
directive|define
name|PCIS_INTELLIIO_I2O
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIC_SATCOM
value|0x0f
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_TV
value|0x01
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_AUDIO
value|0x02
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_VOICE
value|0x03
end_define

begin_define
define|#
directive|define
name|PCIS_SATCOM_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCIC_CRYPTO
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_NETCOMP
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_ENTERTAIN
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIS_CRYPTO_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_DASP
value|0x11
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_DPIO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCIS_DASP_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIC_OTHER
value|0xff
end_define

begin_comment
comment|/* Bridge Control Values. */
end_comment

begin_define
define|#
directive|define
name|PCIB_BCR_PERR_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SERR_ENABLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_ISA_ENABLE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_VGA_ENABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_MASTER_ABORT_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SECBUS_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SECBUS_BACKTOBACK
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_PRI_DISCARD_TIMEOUT
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_SEC_DISCARD_TIMEOUT
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_DISCARD_TIMER_STATUS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIB_BCR_DISCARD_TIMER_SERREN
value|0x0800
end_define

begin_comment
comment|/* PCI power manangement */
end_comment

begin_define
define|#
directive|define
name|PCIR_POWER_CAP
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_SPEC
value|0x0007
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_PMEREQCLK
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_PMEREQPWR
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_DEVSPECINIT
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_DYNCLOCK
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_SECCLOCK
value|0x00c0
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_CLOCKMASK
value|0x00c0
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_REQFULLCLOCK
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D1SUPP
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D2SUPP
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D0PME
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D1PME
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_PCAP_D2PME
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_STATUS
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_REPENABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_PMEENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0POWER
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1POWER
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2POWER
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3POWER
value|0x0600
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D0HEAT
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D1HEAT
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D2HEAT
value|0x1200
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_D3HEAT
value|0x1400
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATAUNKN
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV10
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV100
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIV1000
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_DATADIVMASK
value|0x6000
end_define

begin_define
define|#
directive|define
name|PCIM_PSTAT_PME
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_PMCSR
value|0x6
end_define

begin_define
define|#
directive|define
name|PCIM_PMCSR_DCLOCK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIM_PMCSR_B2SUPP
value|0x20
end_define

begin_define
define|#
directive|define
name|PCIM_BMCSR_B3SUPP
value|0x40
end_define

begin_define
define|#
directive|define
name|PCIM_BMCSR_BPCE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCIR_POWER_DATA
value|0x7
end_define

begin_comment
comment|/* PCI Message Signalled Interrupts (MSI) */
end_comment

begin_define
define|#
directive|define
name|PCIR_MSI_CTRL
value|0x2
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_VECTOR
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_64BIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_2
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_4
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_8
value|0x0030
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_16
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MME_32
value|0x0050
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_MASK
value|0x000E
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_1
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_4
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_8
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_16
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MMC_32
value|0x000A
end_define

begin_define
define|#
directive|define
name|PCIM_MSICTRL_MSI_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_ADDR
value|0x4
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_ADDR_HIGH
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_DATA
value|0x8
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_DATA_64BIT
value|0xc
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCIR_MSI_PENDING
value|0x14
end_define

begin_comment
comment|/* PCI-X definitions */
end_comment

begin_define
define|#
directive|define
name|PCIXR_COMMAND
value|0x96
end_define

begin_define
define|#
directive|define
name|PCIXR_DEVADDR
value|0x98
end_define

begin_define
define|#
directive|define
name|PCIXM_DEVADDR_FNUM
value|0x0003
end_define

begin_comment
comment|/* Function Number */
end_comment

begin_define
define|#
directive|define
name|PCIXM_DEVADDR_DNUM
value|0x00F8
end_define

begin_comment
comment|/* Device Number */
end_comment

begin_define
define|#
directive|define
name|PCIXM_DEVADDR_BNUM
value|0xFF00
end_define

begin_comment
comment|/* Bus Number */
end_comment

begin_define
define|#
directive|define
name|PCIXR_STATUS
value|0x9A
end_define

begin_define
define|#
directive|define
name|PCIXM_STATUS_64BIT
value|0x0001
end_define

begin_comment
comment|/* Active 64bit connection to device. */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_133CAP
value|0x0002
end_define

begin_comment
comment|/* Device is 133MHz capable */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_SCDISC
value|0x0004
end_define

begin_comment
comment|/* Split Completion Discarded */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_UNEXPSC
value|0x0008
end_define

begin_comment
comment|/* Unexpected Split Completion */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_CMPLEXDEV
value|0x0010
end_define

begin_comment
comment|/* Device Complexity (set == bridge) */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAXMRDBC
value|0x0060
end_define

begin_comment
comment|/* Maximum Burst Read Count */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAXSPLITS
value|0x0380
end_define

begin_comment
comment|/* Maximum Split Transactions */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_MAXCRDS
value|0x1C00
end_define

begin_comment
comment|/* Maximum Cumulative Read Size */
end_comment

begin_define
define|#
directive|define
name|PCIXM_STATUS_RCVDSCEM
value|0x2000
end_define

begin_comment
comment|/* Received a Split Comp w/Error msg */
end_comment

end_unit

