begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for PCI 2.2 standard.    This file includes the definitions in the following specifications,     PCI Local Bus Specification, 2.2     PCI-to-PCI Bridge Architecture Specification, Revision 1.2     PC Card Standard, 8.0     PCI Power Management Interface Specifiction, Revision 1.2    Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2014 - 2015, Hewlett-Packard Development Company, L.P.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI22_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI22_H_
end_define

begin_define
define|#
directive|define
name|PCI_MAX_BUS
value|255
end_define

begin_define
define|#
directive|define
name|PCI_MAX_DEVICE
value|31
end_define

begin_define
define|#
directive|define
name|PCI_MAX_FUNC
value|7
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common header region in PCI Configuration Space
end_comment

begin_comment
comment|/// Section 6.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|Command
decl_stmt|;
name|UINT16
name|Status
decl_stmt|;
name|UINT8
name|RevisionID
decl_stmt|;
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|CacheLineSize
decl_stmt|;
name|UINT8
name|LatencyTimer
decl_stmt|;
name|UINT8
name|HeaderType
decl_stmt|;
name|UINT8
name|BIST
decl_stmt|;
block|}
name|PCI_DEVICE_INDEPENDENT_REGION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Device header region in PCI Configuration Space
end_comment

begin_comment
comment|/// Section 6.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Bar
index|[
literal|6
index|]
decl_stmt|;
name|UINT32
name|CISPtr
decl_stmt|;
name|UINT16
name|SubsystemVendorID
decl_stmt|;
name|UINT16
name|SubsystemID
decl_stmt|;
name|UINT32
name|ExpansionRomBar
decl_stmt|;
name|UINT8
name|CapabilityPtr
decl_stmt|;
name|UINT8
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT8
name|InterruptLine
decl_stmt|;
name|UINT8
name|InterruptPin
decl_stmt|;
name|UINT8
name|MinGnt
decl_stmt|;
name|UINT8
name|MaxLat
decl_stmt|;
block|}
name|PCI_DEVICE_HEADER_TYPE_REGION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Device Configuration Space
end_comment

begin_comment
comment|/// Section 6.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|PCI_DEVICE_INDEPENDENT_REGION
name|Hdr
decl_stmt|;
name|PCI_DEVICE_HEADER_TYPE_REGION
name|Device
decl_stmt|;
block|}
name|PCI_TYPE00
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI-PCI Bridge header region in PCI Configuration Space
end_comment

begin_comment
comment|/// Section 3.2, PCI-PCI Bridge Architecture, Version 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Bar
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|PrimaryBus
decl_stmt|;
name|UINT8
name|SecondaryBus
decl_stmt|;
name|UINT8
name|SubordinateBus
decl_stmt|;
name|UINT8
name|SecondaryLatencyTimer
decl_stmt|;
name|UINT8
name|IoBase
decl_stmt|;
name|UINT8
name|IoLimit
decl_stmt|;
name|UINT16
name|SecondaryStatus
decl_stmt|;
name|UINT16
name|MemoryBase
decl_stmt|;
name|UINT16
name|MemoryLimit
decl_stmt|;
name|UINT16
name|PrefetchableMemoryBase
decl_stmt|;
name|UINT16
name|PrefetchableMemoryLimit
decl_stmt|;
name|UINT32
name|PrefetchableBaseUpper32
decl_stmt|;
name|UINT32
name|PrefetchableLimitUpper32
decl_stmt|;
name|UINT16
name|IoBaseUpper16
decl_stmt|;
name|UINT16
name|IoLimitUpper16
decl_stmt|;
name|UINT8
name|CapabilityPtr
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|ExpansionRomBAR
decl_stmt|;
name|UINT8
name|InterruptLine
decl_stmt|;
name|UINT8
name|InterruptPin
decl_stmt|;
name|UINT16
name|BridgeControl
decl_stmt|;
block|}
name|PCI_BRIDGE_CONTROL_REGISTER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI-to-PCI Bridge Configuration Space
end_comment

begin_comment
comment|/// Section 3.2, PCI-PCI Bridge Architecture, Version 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|PCI_DEVICE_INDEPENDENT_REGION
name|Hdr
decl_stmt|;
name|PCI_BRIDGE_CONTROL_REGISTER
name|Bridge
decl_stmt|;
block|}
name|PCI_TYPE01
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|PCI_TYPE00
name|Device
decl_stmt|;
name|PCI_TYPE01
name|Bridge
decl_stmt|;
block|}
name|PCI_TYPE_GENERIC
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// CardBus Conroller Configuration Space,
end_comment

begin_comment
comment|/// Section 4.5.1, PC Card Standard. 8.0
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|CardBusSocketReg
decl_stmt|;
comment|///< Cardus Socket/ExCA Base
name|UINT8
name|Cap_Ptr
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|SecondaryStatus
decl_stmt|;
comment|///< Secondary Status
name|UINT8
name|PciBusNumber
decl_stmt|;
comment|///< PCI Bus Number
name|UINT8
name|CardBusBusNumber
decl_stmt|;
comment|///< CardBus Bus Number
name|UINT8
name|SubordinateBusNumber
decl_stmt|;
comment|///< Subordinate Bus Number
name|UINT8
name|CardBusLatencyTimer
decl_stmt|;
comment|///< CardBus Latency Timer
name|UINT32
name|MemoryBase0
decl_stmt|;
comment|///< Memory Base Register 0
name|UINT32
name|MemoryLimit0
decl_stmt|;
comment|///< Memory Limit Register 0
name|UINT32
name|MemoryBase1
decl_stmt|;
name|UINT32
name|MemoryLimit1
decl_stmt|;
name|UINT32
name|IoBase0
decl_stmt|;
name|UINT32
name|IoLimit0
decl_stmt|;
comment|///< I/O Base Register 0
name|UINT32
name|IoBase1
decl_stmt|;
comment|///< I/O Limit Register 0
name|UINT32
name|IoLimit1
decl_stmt|;
name|UINT8
name|InterruptLine
decl_stmt|;
comment|///< Interrupt Line
name|UINT8
name|InterruptPin
decl_stmt|;
comment|///< Interrupt Pin
name|UINT16
name|BridgeControl
decl_stmt|;
comment|///< Bridge Control
block|}
name|PCI_CARDBUS_CONTROL_REGISTER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions of PCI class bytes and manipulation macros.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_OLD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_OLD_OTHER
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_OLD_VGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_SCSI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_IDE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_FLOPPY
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_IPI
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_RAID
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_ETHERNET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_TOKENRING
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_FDDI
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_ATM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_ISDN
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_VGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_VGA_VGA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_VGA_8514
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_XGA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_3D
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DISPLAY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEDIA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEDIA_VIDEO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEDIA_AUDIO
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEDIA_TELEPHONE
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEDIA_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_CONTROLLER
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_RAM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_FLASH
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MEMORY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_HOST
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_ISA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_EISA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_MCA
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_P2P
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_P2P
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_P2P_SUBTRACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_PCMCIA
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_NUBUS
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_CARDBUS
value|0x07
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_RACEWAY
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_ISA_PDECODE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SCC
value|0x07
end_define

begin_comment
comment|///< Simple communications controllers
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SERIAL
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_GENERIC_XT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_16450
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_16550
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_IF_16650
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_16750
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_IF_16850
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_IF_16950
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PARALLEL
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_PARALLEL_PORT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_BI_DIR_PARALLEL_PORT
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_ECP_PARALLEL_PORT
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_IF_1284_CONTROLLER
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_1284_DEVICE
value|0xFE
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MULTIPORT_SERIAL
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MODEM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_GENERIC_MODEM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_16450_MODEM
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_16550_MODEM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_IF_16650_MODEM
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_16750_MODEM
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SCC_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SYSTEM_PERIPHERAL
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_8259_PIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_ISA_PIC
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_EISA_PIC
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_IF_APIC_CONTROLLER
value|0x10
end_define

begin_comment
comment|///< I/O APIC interrupt controller , 32 bye none-prefectable memory.
end_comment

begin_define
define|#
directive|define
name|PCI_IF_APIC_CONTROLLER2
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_8237_DMA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_ISA_DMA
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_EISA_DMA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_TIMER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_IF_8254_TIMER
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_ISA_TIMER
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_EISA_TIMER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_RTC
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_GENERIC_RTC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_ISA_RTC
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PNP_CONTROLLER
value|0x04
end_define

begin_comment
comment|///< HotPlug Controller
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PERIPHERAL_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INPUT_DEVICE
value|0x09
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_KEYBOARD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PEN
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MOUSE_CONTROLLER
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SCAN_CONTROLLER
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_GAMEPORT
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_IF_GAMEPORT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_GAMEPORT1
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_INPUT_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DOCKING_STATION
value|0x0A
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DOCKING_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DOCKING_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_PROCESSOR
value|0x0B
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_386
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_486
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_PENTIUM
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_ALPHA
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_POWERPC
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_MIPS
value|0x30
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_PROC_CO_PORC
value|0x40
end_define

begin_comment
comment|///< Co-Processor
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_FIREWIRE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_1394
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_1394_OPEN_HCI
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_ACCESS_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_SSA
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_USB
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_IF_UHCI
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_OHCI
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_IF_USB_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_IF_USB_DEVICE
value|0xFE
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_FIBRECHANNEL
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_SMB
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_WIRELESS
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_IRDA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_IR
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_RF
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_WIRELESS_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_INTELLIGENT_IO
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SATELLITE
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_TV
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_AUDIO
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_VOICE
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DATA
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_SECURITY_CONTROLLER
value|0x10
end_define

begin_comment
comment|///< Encryption and decryption controller
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_NET_COMPUT
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_ENTERTAINMENT
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SECURITY_OTHER
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_DPIO
value|0x11
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DPIO
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_DPIO_OTHER
value|0x80
end_define

begin_comment
comment|/**     Macro that checks whether the Base Class code of device matched.    @param  _p      Specified device.   @param  c       Base Class code needs matching.    @retval TRUE    Base Class code matches the specified device.   @retval FALSE   Base Class code doesn't match the specified device.           **/
end_comment

begin_define
define|#
directive|define
name|IS_CLASS1
parameter_list|(
name|_p
parameter_list|,
name|c
parameter_list|)
value|((_p)->Hdr.ClassCode[2] == (c))
end_define

begin_comment
comment|/**     Macro that checks whether the Base Class code and Sub-Class code of device matched.    @param  _p      Specified device.   @param  c       Base Class code needs matching.   @param  s       Sub-Class code needs matching.    @retval TRUE    Base Class code and Sub-Class code match the specified device.   @retval FALSE   Base Class code and Sub-Class code don't match the specified device.           **/
end_comment

begin_define
define|#
directive|define
name|IS_CLASS2
parameter_list|(
name|_p
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|(IS_CLASS1 (_p, c)&& ((_p)->Hdr.ClassCode[1] == (s)))
end_define

begin_comment
comment|/**     Macro that checks whether the Base Class code, Sub-Class code and Interface code of device matched.    @param  _p      Specified device.   @param  c       Base Class code needs matching.   @param  s       Sub-Class code needs matching.   @param  p       Interface code needs matching.    @retval TRUE    Base Class code, Sub-Class code and Interface code match the specified device.   @retval FALSE   Base Class code, Sub-Class code and Interface code don't match the specified device.           **/
end_comment

begin_define
define|#
directive|define
name|IS_CLASS3
parameter_list|(
name|_p
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|,
name|p
parameter_list|)
value|(IS_CLASS2 (_p, c, s)&& ((_p)->Hdr.ClassCode[0] == (p)))
end_define

begin_comment
comment|/**     Macro that checks whether device is a display controller.    @param  _p      Specified device.    @retval TRUE    Device is a display controller.   @retval FALSE   Device is not a display controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_DISPLAY
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS1 (_p, PCI_CLASS_DISPLAY)
end_define

begin_comment
comment|/**     Macro that checks whether device is a VGA-compatible controller.    @param  _p      Specified device.    @retval TRUE    Device is a VGA-compatible controller.   @retval FALSE   Device is not a VGA-compatible controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_VGA
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS3 (_p, PCI_CLASS_DISPLAY, PCI_CLASS_DISPLAY_VGA, PCI_IF_VGA_VGA)
end_define

begin_comment
comment|/**     Macro that checks whether device is an 8514-compatible controller.    @param  _p      Specified device.    @retval TRUE    Device is an 8514-compatible controller.   @retval FALSE   Device is not an 8514-compatible controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_8514
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS3 (_p, PCI_CLASS_DISPLAY, PCI_CLASS_DISPLAY_VGA, PCI_IF_VGA_8514)
end_define

begin_comment
comment|/**     Macro that checks whether device is built before the Class Code field was defined.    @param  _p      Specified device.    @retval TRUE    Device is an old device.   @retval FALSE   Device is not an old device.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_OLD
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS1 (_p, PCI_CLASS_OLD)
end_define

begin_comment
comment|/**     Macro that checks whether device is a VGA-compatible device built before the Class Code field was defined.    @param  _p      Specified device.    @retval TRUE    Device is an old VGA-compatible device.   @retval FALSE   Device is not an old VGA-compatible device.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_OLD_VGA
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_OLD, PCI_CLASS_OLD_VGA)
end_define

begin_comment
comment|/**     Macro that checks whether device is an IDE controller.    @param  _p      Specified device.    @retval TRUE    Device is an IDE controller.   @retval FALSE   Device is not an IDE controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_IDE
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_MASS_STORAGE, PCI_CLASS_MASS_STORAGE_IDE)
end_define

begin_comment
comment|/**     Macro that checks whether device is a SCSI bus controller.    @param  _p      Specified device.    @retval TRUE    Device is a SCSI bus controller.   @retval FALSE   Device is not a SCSI bus controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_SCSI
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_MASS_STORAGE, PCI_CLASS_MASS_STORAGE_SCSI)
end_define

begin_comment
comment|/**     Macro that checks whether device is a RAID controller.    @param  _p      Specified device.    @retval TRUE    Device is a RAID controller.   @retval FALSE   Device is not a RAID controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_RAID
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_MASS_STORAGE, PCI_CLASS_MASS_STORAGE_RAID)
end_define

begin_comment
comment|/**     Macro that checks whether device is an ISA bridge.    @param  _p      Specified device.    @retval TRUE    Device is an ISA bridge.   @retval FALSE   Device is not an ISA bridge.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_LPC
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_BRIDGE, PCI_CLASS_BRIDGE_ISA)
end_define

begin_comment
comment|/**     Macro that checks whether device is a PCI-to-PCI bridge.    @param  _p      Specified device.    @retval TRUE    Device is a PCI-to-PCI bridge.   @retval FALSE   Device is not a PCI-to-PCI bridge.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_P2P
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS3 (_p, PCI_CLASS_BRIDGE, PCI_CLASS_BRIDGE_P2P, PCI_IF_BRIDGE_P2P)
end_define

begin_comment
comment|/**     Macro that checks whether device is a Subtractive Decode PCI-to-PCI bridge.    @param  _p      Specified device.    @retval TRUE    Device is a Subtractive Decode PCI-to-PCI bridge.   @retval FALSE   Device is not a Subtractive Decode PCI-to-PCI bridge.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_P2P_SUB
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS3 (_p, PCI_CLASS_BRIDGE, PCI_CLASS_BRIDGE_P2P, PCI_IF_BRIDGE_P2P_SUBTRACTIVE)
end_define

begin_comment
comment|/**     Macro that checks whether device is a 16550-compatible serial controller.    @param  _p      Specified device.    @retval TRUE    Device is a 16550-compatible serial controller.   @retval FALSE   Device is not a 16550-compatible serial controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_16550_SERIAL
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS3 (_p, PCI_CLASS_SCC, PCI_SUBCLASS_SERIAL, PCI_IF_16550)
end_define

begin_comment
comment|/**     Macro that checks whether device is a Universal Serial Bus controller.    @param  _p      Specified device.    @retval TRUE    Device is a Universal Serial Bus controller.   @retval FALSE   Device is not a Universal Serial Bus controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_USB
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_SERIAL, PCI_CLASS_SERIAL_USB)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// the definition of Header Type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HEADER_TYPE_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|HEADER_TYPE_PCI_TO_PCI_BRIDGE
value|0x01
end_define

begin_define
define|#
directive|define
name|HEADER_TYPE_CARDBUS_BRIDGE
value|0x02
end_define

begin_define
define|#
directive|define
name|HEADER_TYPE_MULTI_FUNCTION
value|0x80
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Mask of Header type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|HEADER_LAYOUT_CODE
value|0x7f
end_define

begin_comment
comment|/**     Macro that checks whether device is a PCI-PCI bridge.    @param  _p      Specified device.    @retval TRUE    Device is a PCI-PCI bridge.   @retval FALSE   Device is not a PCI-PCI bridge.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_BRIDGE
parameter_list|(
name|_p
parameter_list|)
value|(((_p)->Hdr.HeaderType& HEADER_LAYOUT_CODE) == (HEADER_TYPE_PCI_TO_PCI_BRIDGE))
end_define

begin_comment
comment|/**     Macro that checks whether device is a CardBus bridge.    @param  _p      Specified device.    @retval TRUE    Device is a CardBus bridge.   @retval FALSE   Device is not a CardBus bridge.  **/
end_comment

begin_define
define|#
directive|define
name|IS_CARDBUS_BRIDGE
parameter_list|(
name|_p
parameter_list|)
value|(((_p)->Hdr.HeaderType& HEADER_LAYOUT_CODE) == (HEADER_TYPE_CARDBUS_BRIDGE))
end_define

begin_comment
comment|/**     Macro that checks whether device is a multiple functions device.    @param  _p      Specified device.    @retval TRUE    Device is a multiple functions device.   @retval FALSE   Device is not a multiple functions device.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_MULTI_FUNC
parameter_list|(
name|_p
parameter_list|)
value|((_p)->Hdr.HeaderType& HEADER_TYPE_MULTI_FUNCTION)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Rom Base Address in Bridge, defined in PCI-to-PCI Bridge Architecure Specification,
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PCI_BRIDGE_ROMBAR
value|0x38
end_define

begin_define
define|#
directive|define
name|PCI_MAX_BAR
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCI_MAX_CONFIG_OFFSET
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_OFFSET
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_COMMAND_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_PRIMARY_STATUS_OFFSET
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_REVISION_ID_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_CLASSCODE_OFFSET
value|0x09
end_define

begin_define
define|#
directive|define
name|PCI_CACHELINE_SIZE_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|PCI_LATENCY_TIMER_OFFSET
value|0x0D
end_define

begin_define
define|#
directive|define
name|PCI_HEADER_TYPE_OFFSET
value|0x0E
end_define

begin_define
define|#
directive|define
name|PCI_BIST_OFFSET
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCI_BASE_ADDRESSREG_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_CARDBUS_CIS_OFFSET
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_SVID_OFFSET
value|0x2C
end_define

begin_comment
comment|///< SubSystem Vendor id
end_comment

begin_define
define|#
directive|define
name|PCI_SUBSYSTEM_VENDOR_ID_OFFSET
value|0x2C
end_define

begin_define
define|#
directive|define
name|PCI_SID_OFFSET
value|0x2E
end_define

begin_comment
comment|///< SubSystem ID
end_comment

begin_define
define|#
directive|define
name|PCI_SUBSYSTEM_ID_OFFSET
value|0x2E
end_define

begin_define
define|#
directive|define
name|PCI_EXPANSION_ROM_BASE
value|0x30
end_define

begin_define
define|#
directive|define
name|PCI_CAPBILITY_POINTER_OFFSET
value|0x34
end_define

begin_define
define|#
directive|define
name|PCI_INT_LINE_OFFSET
value|0x3C
end_define

begin_comment
comment|///< Interrupt Line Register
end_comment

begin_define
define|#
directive|define
name|PCI_INT_PIN_OFFSET
value|0x3D
end_define

begin_comment
comment|///< Interrupt Pin Register
end_comment

begin_define
define|#
directive|define
name|PCI_MAXGNT_OFFSET
value|0x3E
end_define

begin_comment
comment|///< Max Grant Register
end_comment

begin_define
define|#
directive|define
name|PCI_MAXLAT_OFFSET
value|0x3F
end_define

begin_comment
comment|///< Max Latency Register
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// defined in PCI-to-PCI Bridge Architecture Specification
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PCI_BRIDGE_PRIMARY_BUS_REGISTER_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|PCI_BRIDGE_SECONDARY_BUS_REGISTER_OFFSET
value|0x19
end_define

begin_define
define|#
directive|define
name|PCI_BRIDGE_SUBORDINATE_BUS_REGISTER_OFFSET
value|0x1a
end_define

begin_define
define|#
directive|define
name|PCI_BRIDGE_SECONDARY_LATENCY_TIMER_OFFSET
value|0x1b
end_define

begin_define
define|#
directive|define
name|PCI_BRIDGE_STATUS_REGISTER_OFFSET
value|0x1E
end_define

begin_define
define|#
directive|define
name|PCI_BRIDGE_CONTROL_REGISTER_OFFSET
value|0x3E
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interrupt Line "Unknown" or "No connection" value defined for x86 based system
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PCI_INT_LINE_UNKNOWN
value|0xFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Access Data Format
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT32
name|Reg
range|:
literal|8
decl_stmt|;
name|UINT32
name|Func
range|:
literal|3
decl_stmt|;
name|UINT32
name|Dev
range|:
literal|5
decl_stmt|;
name|UINT32
name|Bus
range|:
literal|8
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|7
decl_stmt|;
name|UINT32
name|Enable
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT32
name|Uint32
decl_stmt|;
block|}
name|PCI_CONFIG_ACCESS_CF8
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_IO_SPACE
value|BIT0
end_define

begin_comment
comment|///< 0x0001
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_MEMORY_SPACE
value|BIT1
end_define

begin_comment
comment|///< 0x0002
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_BUS_MASTER
value|BIT2
end_define

begin_comment
comment|///< 0x0004
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_SPECIAL_CYCLE
value|BIT3
end_define

begin_comment
comment|///< 0x0008
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_MEMORY_WRITE_AND_INVALIDATE
value|BIT4
end_define

begin_comment
comment|///< 0x0010
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_VGA_PALETTE_SNOOP
value|BIT5
end_define

begin_comment
comment|///< 0x0020
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_PARITY_ERROR_RESPOND
value|BIT6
end_define

begin_comment
comment|///< 0x0040
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_STEPPING_CONTROL
value|BIT7
end_define

begin_comment
comment|///< 0x0080
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_SERR
value|BIT8
end_define

begin_comment
comment|///< 0x0100
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_COMMAND_FAST_BACK_TO_BACK
value|BIT9
end_define

begin_comment
comment|///< 0x0200
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// defined in PCI-to-PCI Bridge Architecture Specification
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_PARITY_ERROR_RESPONSE
value|BIT0
end_define

begin_comment
comment|///< 0x0001
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_SERR
value|BIT1
end_define

begin_comment
comment|///< 0x0002
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_ISA
value|BIT2
end_define

begin_comment
comment|///< 0x0004
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_VGA
value|BIT3
end_define

begin_comment
comment|///< 0x0008
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_VGA_16
value|BIT4
end_define

begin_comment
comment|///< 0x0010
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_MASTER_ABORT
value|BIT5
end_define

begin_comment
comment|///< 0x0020
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_RESET_SECONDARY_BUS
value|BIT6
end_define

begin_comment
comment|///< 0x0040
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_FAST_BACK_TO_BACK
value|BIT7
end_define

begin_comment
comment|///< 0x0080
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_PRIMARY_DISCARD_TIMER
value|BIT8
end_define

begin_comment
comment|///< 0x0100
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_SECONDARY_DISCARD_TIMER
value|BIT9
end_define

begin_comment
comment|///< 0x0200
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_TIMER_STATUS
value|BIT10
end_define

begin_comment
comment|///< 0x0400
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_DISCARD_TIMER_SERR
value|BIT11
end_define

begin_comment
comment|///< 0x0800
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Following are the PCI-CARDBUS bridge control bit, defined in PC Card Standard
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_IREQINT_ENABLE
value|BIT7
end_define

begin_comment
comment|///< 0x0080
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_RANGE0_MEMORY_TYPE
value|BIT8
end_define

begin_comment
comment|///< 0x0100
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_RANGE1_MEMORY_TYPE
value|BIT9
end_define

begin_comment
comment|///< 0x0200
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_BRIDGE_CONTROL_WRITE_POSTING_ENABLE
value|BIT10
end_define

begin_comment
comment|///< 0x0400
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Following are the PCI status control bit
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_STATUS_CAPABILITY
value|BIT4
end_define

begin_comment
comment|///< 0x0010
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_STATUS_66MZ_CAPABLE
value|BIT5
end_define

begin_comment
comment|///< 0x0020
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_FAST_BACK_TO_BACK_CAPABLE
value|BIT7
end_define

begin_comment
comment|///< 0x0080
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_MASTER_DATA_PARITY_ERROR
value|BIT8
end_define

begin_comment
comment|///< 0x0100
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// defined in PC Card Standard
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_CARDBUS_BRIDGE_CAPABILITY_PTR
value|0x14
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// PCI Capability List IDs and records
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_PMI
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_AGP
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_VPD
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_SLOTID
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_MSI
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_HOTPLUG
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_SHPC
value|0x0C
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Capabilities List Header
end_comment

begin_comment
comment|/// Section 6.7, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CapabilityID
decl_stmt|;
name|UINT8
name|NextItemPtr
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_HDR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PMC - Power Management Capabilities
end_comment

begin_comment
comment|/// Section 3.2.3, PCI Power Management Interface Specifiction, Revision 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|Version
range|:
literal|3
decl_stmt|;
name|UINT16
name|PmeClock
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|1
decl_stmt|;
name|UINT16
name|DeviceSpecificInitialization
range|:
literal|1
decl_stmt|;
name|UINT16
name|AuxCurrent
range|:
literal|3
decl_stmt|;
name|UINT16
name|D1Support
range|:
literal|1
decl_stmt|;
name|UINT16
name|D2Support
range|:
literal|1
decl_stmt|;
name|UINT16
name|PmeSupport
range|:
literal|5
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT16
name|Data
decl_stmt|;
block|}
name|EFI_PCI_PMC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_PCI_PMC_D3_COLD_MASK
value|(BIT15)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PMCSR - Power Management Control/Status
end_comment

begin_comment
comment|/// Section 3.2.4, PCI Power Management Interface Specifiction, Revision 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT16
name|PowerState
range|:
literal|2
decl_stmt|;
name|UINT16
name|ReservedForPciExpress
range|:
literal|1
decl_stmt|;
name|UINT16
name|NoSoftReset
range|:
literal|1
decl_stmt|;
name|UINT16
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT16
name|PmeEnable
range|:
literal|1
decl_stmt|;
name|UINT16
name|DataSelect
range|:
literal|4
decl_stmt|;
name|UINT16
name|DataScale
range|:
literal|2
decl_stmt|;
name|UINT16
name|PmeStatus
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT16
name|Data
decl_stmt|;
block|}
name|EFI_PCI_PMCSR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PCI_POWER_STATE_D0
value|0
end_define

begin_define
define|#
directive|define
name|PCI_POWER_STATE_D1
value|1
end_define

begin_define
define|#
directive|define
name|PCI_POWER_STATE_D2
value|2
end_define

begin_define
define|#
directive|define
name|PCI_POWER_STATE_D3_HOT
value|3
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PMCSR_BSE - PMCSR PCI-to-PCI Bridge Support Extensions
end_comment

begin_comment
comment|/// Section 3.2.5, PCI Power Management Interface Specifiction, Revision 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
name|UINT8
name|B2B3
range|:
literal|1
decl_stmt|;
name|UINT8
name|BusPowerClockControl
range|:
literal|1
decl_stmt|;
block|}
name|Bits
struct|;
name|UINT8
name|Uint8
decl_stmt|;
block|}
name|EFI_PCI_PMCSR_BSE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Power Management Register Block Definition
end_comment

begin_comment
comment|/// Section 3.2, PCI Power Management Interface Specifiction, Revision 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|EFI_PCI_PMC
name|PMC
decl_stmt|;
name|EFI_PCI_PMCSR
name|PMCSR
decl_stmt|;
name|EFI_PCI_PMCSR_BSE
name|BridgeExtention
decl_stmt|;
name|UINT8
name|Data
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_PMI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A.G.P Capability
end_comment

begin_comment
comment|/// Section 6.1.4, Accelerated Graphics Port Interface Specification, Revision 1.0
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT8
name|Rev
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|Status
decl_stmt|;
name|UINT32
name|Command
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_AGP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// VPD Capability Structure
end_comment

begin_comment
comment|/// Appendix I, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT16
name|AddrReg
decl_stmt|;
name|UINT32
name|DataReg
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_VPD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Slot Numbering Capabilities Register
end_comment

begin_comment
comment|/// Section 3.2.6, PCI-to-PCI Bridge Architeture Specification, Revision 1.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT8
name|ExpnsSlotReg
decl_stmt|;
name|UINT8
name|ChassisNo
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_SLOTID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Message Capability Structure for 32-bit Message Address
end_comment

begin_comment
comment|/// Section 6.8.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT16
name|MsgCtrlReg
decl_stmt|;
name|UINT32
name|MsgAddrReg
decl_stmt|;
name|UINT16
name|MsgDataReg
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_MSI32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Message Capability Structure for 64-bit Message Address
end_comment

begin_comment
comment|/// Section 6.8.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT16
name|MsgCtrlReg
decl_stmt|;
name|UINT32
name|MsgAddrRegLsdw
decl_stmt|;
name|UINT32
name|MsgAddrRegMsdw
decl_stmt|;
name|UINT16
name|MsgDataReg
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_MSI64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Capability EFI_PCI_CAPABILITY_ID_HOTPLUG,
end_comment

begin_comment
comment|/// CompactPCI Hot Swap Specification PICMG 2.1, R1.0
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
comment|///
comment|/// not finished - fields need to go here
comment|///
block|}
name|EFI_PCI_CAPABILITY_HOTPLUG
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Below macros (till PCI_BAR_NOCHANGE) were used by EfiIncompatiblePciDeviceSupport Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|///
end_comment

begin_comment
comment|/// [ATTENTION] These macros are deprecated because they don't match Spec or not defined in Spec.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DEVICE_ID_NOCARE
value|0xFFFF
end_define

begin_comment
comment|///< Deprecated. Value doesn't match Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_OLD_ALIGN
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_comment
comment|///< Deprecated. Value isn't defined in Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_EVEN_ALIGN
value|0xFFFFFFFFFFFFFFFEULL
end_define

begin_comment
comment|///< Deprecated. Value isn't defined in Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_SQUAD_ALIGN
value|0xFFFFFFFFFFFFFFFDULL
end_define

begin_comment
comment|///< Deprecated. Value isn't defined in Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_DQUAD_ALIGN
value|0xFFFFFFFFFFFFFFFCULL
end_define

begin_comment
comment|///< Deprecated. Value isn't defined in Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_ALL
value|0xFF
end_define

begin_comment
comment|///< Deprecated. Value doesn't match Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_ACPI_UNUSED
value|0
end_define

begin_comment
comment|///< Deprecated. Macro name is too general.
end_comment

begin_define
define|#
directive|define
name|PCI_BAR_NOCHANGE
value|0
end_define

begin_comment
comment|///< Deprecated. Macro name is too general.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PCI_BAR_IDX0
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IDX1
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IDX2
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IDX3
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IDX4
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_BAR_IDX5
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI PCI Option ROM definitions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ROOT_BRIDGE_LIST
value|'eprb'
end_define

begin_define
define|#
directive|define
name|EFI_PCI_EXPANSION_ROM_HEADER_EFISIGNATURE
value|0x0EF1
end_define

begin_comment
comment|///< defined in UEFI Spec.
end_comment

begin_define
define|#
directive|define
name|PCI_EXPANSION_ROM_HEADER_SIGNATURE
value|0xaa55
end_define

begin_define
define|#
directive|define
name|PCI_DATA_STRUCTURE_SIGNATURE
value|SIGNATURE_32 ('P', 'C', 'I', 'R')
end_define

begin_define
define|#
directive|define
name|PCI_CODE_TYPE_PCAT_IMAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_PCI_EXPANSION_ROM_HEADER_COMPRESSED
value|0x0001
end_define

begin_comment
comment|///< defined in UEFI spec.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard PCI Expansion ROM Header
end_comment

begin_comment
comment|/// Section 13.4.2, Unified Extensible Firmware Interface Specification, Version 2.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Signature
decl_stmt|;
comment|///< 0xaa55
name|UINT8
name|Reserved
index|[
literal|0x16
index|]
decl_stmt|;
name|UINT16
name|PcirOffset
decl_stmt|;
block|}
name|PCI_EXPANSION_ROM_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Legacy ROM Header Extensions
end_comment

begin_comment
comment|/// Section 6.3.3.1, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Signature
decl_stmt|;
comment|///< 0xaa55
name|UINT8
name|Size512
decl_stmt|;
name|UINT8
name|InitEntryPoint
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|0x12
index|]
decl_stmt|;
name|UINT16
name|PcirOffset
decl_stmt|;
block|}
name|EFI_LEGACY_EXPANSION_ROM_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Data Structure Format
end_comment

begin_comment
comment|/// Section 6.3.1.2, PCI Local Bus Specification, 2.2
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
comment|///< "PCIR"
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|Reserved0
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT16
name|ImageLength
decl_stmt|;
name|UINT16
name|CodeRevision
decl_stmt|;
name|UINT8
name|CodeType
decl_stmt|;
name|UINT8
name|Indicator
decl_stmt|;
name|UINT16
name|Reserved1
decl_stmt|;
block|}
name|PCI_DATA_STRUCTURE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI PCI Expansion ROM Header
end_comment

begin_comment
comment|/// Section 13.4.2, Unified Extensible Firmware Interface Specification, Version 2.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Signature
decl_stmt|;
comment|///< 0xaa55
name|UINT16
name|InitializationSize
decl_stmt|;
name|UINT32
name|EfiSignature
decl_stmt|;
comment|///< 0x0EF1
name|UINT16
name|EfiSubsystem
decl_stmt|;
name|UINT16
name|EfiMachineType
decl_stmt|;
name|UINT16
name|CompressionType
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|8
index|]
decl_stmt|;
name|UINT16
name|EfiImageHeaderOffset
decl_stmt|;
name|UINT16
name|PcirOffset
decl_stmt|;
block|}
name|EFI_PCI_EXPANSION_ROM_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
modifier|*
name|Raw
decl_stmt|;
name|PCI_EXPANSION_ROM_HEADER
modifier|*
name|Generic
decl_stmt|;
name|EFI_PCI_EXPANSION_ROM_HEADER
modifier|*
name|Efi
decl_stmt|;
name|EFI_LEGACY_EXPANSION_ROM_HEADER
modifier|*
name|PcAt
decl_stmt|;
block|}
name|EFI_PCI_ROM_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

