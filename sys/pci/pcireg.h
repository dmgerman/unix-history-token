begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * PCIM_xxx: mask to locate subfield in register  * PCIR_xxx: config register offset  * PCIC_xxx: device class  * PCIS_xxx: device subclass  * PCIP_xxx: device programming interface  * PCIV_xxx: PCI vendor ID (only required to fixup ancient devices)  * PCID_xxx: device ID  */
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
name|PCIR_HEADERTYPE
value|0x0e
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
comment|/* config registers for header type 0 devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_MAPS
value|0x10
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
comment|/* config registers for header type 1 devices */
end_comment

begin_define
define|#
directive|define
name|PCIR_SECSTAT_1
value|0
end_define

begin_comment
comment|/**/
end_comment

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
value|0
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PCIR_IOLIMITH_1
value|0
end_define

begin_comment
comment|/**/
end_comment

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
value|0
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PCIR_PMLIMITH_1
value|0
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|PCIR_BRIDGECTL_1
value|0
end_define

begin_comment
comment|/**/
end_comment

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
comment|/* config registers for header type 2 devices */
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
name|PCIC_OTHER
value|0xff
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
comment|/* some PCI vendor definitions (only used to identify ancient devices !!! */
end_comment

begin_define
define|#
directive|define
name|PCIV_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|PCID_INTEL_SATURN
value|0x0483
end_define

begin_define
define|#
directive|define
name|PCID_INTEL_ORION
value|0x84c4
end_define

begin_comment
comment|/* for compatibility to FreeBSD-2.2 version of PCI code */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCI_COMPAT
end_ifdef

begin_define
define|#
directive|define
name|PCI_ID_REG
value|0x00
end_define

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

begin_define
define|#
directive|define
name|PCI_REVISION_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PREHISTORIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PREHISTORIC_VGA
value|0x00010000
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
name|PCI_CLASS_DISPLAY
value|0x03000000
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DISPLAY_VGA
value|0x00000000
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
name|PCI_MAP_IO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PCI_INTERRUPT_REG
value|0x3c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCI_COMPAT */
end_comment

end_unit

