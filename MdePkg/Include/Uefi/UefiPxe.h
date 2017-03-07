begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This header file contains all of the PXE type definitions,   structure prototypes, global variables and constants that   are needed for porting PXE to EFI.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   32/64-bit PXE specification:   alpha-4, 99-Dec-17.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_PXE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_PXE_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_define
define|#
directive|define
name|PXE_BUSTYPE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|( \       (((PXE_UINT32) (d)& 0xFF)<< 24) | (((PXE_UINT32) (c)& 0xFF)<< 16) | (((PXE_UINT32) (b)& 0xFF)<< 8) | \         ((PXE_UINT32) (a)& 0xFF) \     )
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI ROM ID and devive ID signature.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_BUSTYPE_PXE
value|PXE_BUSTYPE ('!', 'P', 'X', 'E')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// BUS ROM ID signatures.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_BUSTYPE_PCI
value|PXE_BUSTYPE ('P', 'C', 'I', 'R')
end_define

begin_define
define|#
directive|define
name|PXE_BUSTYPE_PC_CARD
value|PXE_BUSTYPE ('P', 'C', 'C', 'R')
end_define

begin_define
define|#
directive|define
name|PXE_BUSTYPE_USB
value|PXE_BUSTYPE ('U', 'S', 'B', 'R')
end_define

begin_define
define|#
directive|define
name|PXE_BUSTYPE_1394
value|PXE_BUSTYPE ('1', '3', '9', '4')
end_define

begin_define
define|#
directive|define
name|PXE_SWAP_UINT16
parameter_list|(
name|n
parameter_list|)
value|((((PXE_UINT16) (n)& 0x00FF)<< 8) | (((PXE_UINT16) (n)& 0xFF00)>> 8))
end_define

begin_define
define|#
directive|define
name|PXE_SWAP_UINT32
parameter_list|(
name|n
parameter_list|)
define|\
value|((((PXE_UINT32)(n)& 0x000000FF)<< 24) | \    (((PXE_UINT32)(n)& 0x0000FF00)<< 8)  | \    (((PXE_UINT32)(n)& 0x00FF0000)>> 8)  | \    (((PXE_UINT32)(n)& 0xFF000000)>> 24))
end_define

begin_define
define|#
directive|define
name|PXE_SWAP_UINT64
parameter_list|(
name|n
parameter_list|)
define|\
value|((((PXE_UINT64)(n)& 0x00000000000000FFULL)<< 56) | \    (((PXE_UINT64)(n)& 0x000000000000FF00ULL)<< 40) | \    (((PXE_UINT64)(n)& 0x0000000000FF0000ULL)<< 24) | \    (((PXE_UINT64)(n)& 0x00000000FF000000ULL)<< 8)  | \    (((PXE_UINT64)(n)& 0x000000FF00000000ULL)>> 8)  | \    (((PXE_UINT64)(n)& 0x0000FF0000000000ULL)>> 24) | \    (((PXE_UINT64)(n)& 0x00FF000000000000ULL)>> 40) | \    (((PXE_UINT64)(n)& 0xFF00000000000000ULL)>> 56))
end_define

begin_define
define|#
directive|define
name|PXE_CPBSIZE_NOT_USED
value|0
end_define

begin_comment
comment|///< zero
end_comment

begin_define
define|#
directive|define
name|PXE_DBSIZE_NOT_USED
value|0
end_define

begin_comment
comment|///< zero
end_comment

begin_define
define|#
directive|define
name|PXE_CPBADDR_NOT_USED
value|(PXE_UINT64) 0
end_define

begin_comment
comment|///< zero
end_comment

begin_define
define|#
directive|define
name|PXE_DBADDR_NOT_USED
value|(PXE_UINT64) 0
end_define

begin_comment
comment|///< zero
end_comment

begin_define
define|#
directive|define
name|PXE_CONST
value|CONST
end_define

begin_define
define|#
directive|define
name|PXE_VOLATILE
value|volatile
end_define

begin_typedef
typedef|typedef
name|VOID
name|PXE_VOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|PXE_UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|PXE_UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|PXE_UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINTN
name|PXE_UINTN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Typedef unsigned long PXE_UINT64.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|PXE_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PXE_UINT8
name|PXE_BOOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_FALSE
value|0
end_define

begin_comment
comment|///< zero
end_comment

begin_define
define|#
directive|define
name|PXE_TRUE
value|(!PXE_FALSE)
end_define

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_OPCODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return UNDI operational state.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_GET_STATE
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Change UNDI operational state from Stopped to Started.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_START
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Change UNDI operational state from Started to Stopped.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_STOP
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get UNDI initialization information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_GET_INIT_INFO
value|0x0003
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get NIC configuration information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_GET_CONFIG_INFO
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Changed UNDI operational state from Started to Initialized.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_INITIALIZE
value|0x0005
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Re-initialize the NIC H/W.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_RESET
value|0x0006
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Change the UNDI operational state from Initialized to Started.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_SHUTDOWN
value|0x0007
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read& change state of external interrupt enables.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_INTERRUPT_ENABLES
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read& change state of packet receive filters.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_RECEIVE_FILTERS
value|0x0009
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read& change station MAC address.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_STATION_ADDRESS
value|0x000A
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read traffic statistics.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_STATISTICS
value|0x000B
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Convert multicast IP address to multicast MAC address.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_MCAST_IP_TO_MAC
value|0x000C
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read or change non-volatile storage on the NIC.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_NVDATA
value|0x000D
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Get& clear interrupt status.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_GET_STATUS
value|0x000E
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Fill media header in packet for transmit.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_FILL_HEADER
value|0x000F
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit packet(s).
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_TRANSMIT
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Receive packet.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_RECEIVE
value|0x0011
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Last valid PXE UNDI OpCode number.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPCODE_LAST_VALID
value|0x0011
end_define

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_OPFLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_OPFLAGS_NOT_USED
value|0x0000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// //////////////////////////////////////
end_comment

begin_comment
comment|// UNDI Get State
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No OpFlags
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// UNDI Start
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No OpFlags
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// UNDI Stop
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No OpFlags
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// UNDI Get Init Info
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No Opflags
end_comment

begin_comment
comment|////////////////////////////////////////
end_comment

begin_comment
comment|// UNDI Get Config Info
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No Opflags
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Initialize
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INITIALIZE_CABLE_DETECT_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INITIALIZE_DETECT_CABLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INITIALIZE_DO_NOT_DETECT_CABLE
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Reset
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RESET_DISABLE_INTERRUPTS
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RESET_DISABLE_FILTERS
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Shutdown.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No OpFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Interrupt Enables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Select whether to enable or disable external interrupt signals.
end_comment

begin_comment
comment|/// Setting both enable and disable will return PXE_STATCODE_INVALID_OPFLAGS.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_OPMASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_DISABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_READ
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable receive interrupts.  An external interrupt will be generated
end_comment

begin_comment
comment|/// after a complete non-error packet has been received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_RECEIVE
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable transmit interrupts.  An external interrupt will be generated
end_comment

begin_comment
comment|/// after a complete non-error packet has been transmitted.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_TRANSMIT
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable command interrupts.  An external interrupt will be generated
end_comment

begin_comment
comment|/// when command execution stops.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_COMMAND
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generate software interrupt.  Setting this bit generates an external
end_comment

begin_comment
comment|/// interrupt, if it is supported by the hardware.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_INTERRUPT_SOFTWARE
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Receive Filters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Select whether to enable or disable receive filters.
end_comment

begin_comment
comment|/// Setting both enable and disable will return PXE_STATCODE_INVALID_OPCODE.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_OPMASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_DISABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_READ
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// To reset the contents of the multicast MAC address filter list,
end_comment

begin_comment
comment|/// set this OpFlag:
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_RESET_MCAST_LIST
value|0x2000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable unicast packet receiving.  Packets sent to the current station
end_comment

begin_comment
comment|/// MAC address will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_UNICAST
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable broadcast packet receiving.  Packets sent to the broadcast
end_comment

begin_comment
comment|/// MAC address will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_BROADCAST
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable filtered multicast packet receiving.  Packets sent to any
end_comment

begin_comment
comment|/// of the multicast MAC addresses in the multicast MAC address filter
end_comment

begin_comment
comment|/// list will be received.  If the filter list is empty, no multicast
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_FILTERED_MULTICAST
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable promiscuous packet receiving.  All packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_PROMISCUOUS
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enable promiscuous multicast packet receiving.  All multicast
end_comment

begin_comment
comment|/// packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_RECEIVE_FILTER_ALL_MULTICAST
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Station Address.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_STATION_ADDRESS_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_STATION_ADDRESS_WRITE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_STATION_ADDRESS_RESET
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Statistics.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_STATISTICS_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_STATISTICS_RESET
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI MCast IP to MAC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Identify the type of IP address in the CPB.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_MCAST_IP_TO_MAC_OPMASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_MCAST_IPV4_TO_MAC
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_MCAST_IPV6_TO_MAC
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI NvData.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Select the type of non-volatile data operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_NVDATA_OPMASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_NVDATA_READ
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_NVDATA_WRITE
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Get Status.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return current interrupt status.  This will also clear any interrupts
end_comment

begin_comment
comment|/// that are currently set.  This can be used in a polling routine.  The
end_comment

begin_comment
comment|/// interrupt flags are still set and cleared even when the interrupts
end_comment

begin_comment
comment|/// are disabled.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_GET_INTERRUPT_STATUS
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return list of transmitted buffers for recycling.  Transmit buffers
end_comment

begin_comment
comment|/// must not be changed or unallocated until they have recycled.  After
end_comment

begin_comment
comment|/// issuing a transmit command, wait for a transmit complete interrupt.
end_comment

begin_comment
comment|/// When a transmit complete interrupt is received, read the transmitted
end_comment

begin_comment
comment|/// buffers.  Do not plan on getting one buffer per interrupt.  Some
end_comment

begin_comment
comment|/// NICs and UNDIs may transmit multiple buffers per interrupt.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_GET_TRANSMITTED_BUFFERS
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return current media status.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_GET_MEDIA_STATUS
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Fill Header.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_FILL_HEADER_OPMASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_FILL_HEADER_FRAGMENTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_FILL_HEADER_WHOLE
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Transmit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// S/W UNDI only.  Return after the packet has been transmitted.  A
end_comment

begin_comment
comment|/// transmit complete interrupt will still be generated and the transmit
end_comment

begin_comment
comment|/// buffer will have to be recycled.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_OPFLAGS_SWUNDI_TRANSMIT_OPMASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_TRANSMIT_BLOCK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_TRANSMIT_DONT_BLOCK
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_TRANSMIT_OPMASK
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_TRANSMIT_FRAGMENTED
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXE_OPFLAGS_TRANSMIT_WHOLE
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Receive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No OpFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PXE STATFLAGS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_STATFLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_STATFLAGS_INITIALIZE
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common StatFlags that can be returned by all commands.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The COMMAND_COMPLETE and COMMAND_FAILED status flags must be
end_comment

begin_comment
comment|/// implemented by all UNDIs.  COMMAND_QUEUED is only needed by UNDIs
end_comment

begin_comment
comment|/// that support command queuing.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_STATUS_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_COMMAND_COMPLETE
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_COMMAND_FAILED
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_COMMAND_QUEUED
value|0x4000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Get State.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATE_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATE_INITIALIZED
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATE_STARTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATE_STOPPED
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Start.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Get Init Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_CABLE_DETECT_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_CABLE_DETECT_NOT_SUPPORTED
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_CABLE_DETECT_SUPPORTED
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_MEDIA_MASK
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_MEDIA_NOT_SUPPORTED
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_MEDIA_SUPPORTED
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Initialize.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_INITIALIZED_NO_MEDIA
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Reset.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RESET_NO_MEDIA
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Shutdown.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Interrupt Enables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, receive interrupts are enabled.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_INTERRUPT_RECEIVE
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, transmit interrupts are enabled.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_INTERRUPT_TRANSMIT
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, command interrupts are enabled.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_INTERRUPT_COMMAND
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Receive Filters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, unicast packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RECEIVE_FILTER_UNICAST
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, broadcast packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RECEIVE_FILTER_BROADCAST
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, multicast packets that match up with the multicast address
end_comment

begin_comment
comment|/// filter list will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RECEIVE_FILTER_FILTERED_MULTICAST
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, all packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RECEIVE_FILTER_PROMISCUOUS
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, all multicast packets will be received.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_RECEIVE_FILTER_ALL_MULTICAST
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Station Address.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Statistics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//// UNDI MCast IP to MAC.
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|//// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI NvData.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Get Status.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use to determine if an interrupt has occurred.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_INTERRUPT_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_INTERRUPTS
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, at least one receive interrupt occurred.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_RECEIVE
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, at least one transmit interrupt occurred.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_TRANSMIT
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, at least one command interrupt occurred.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_COMMAND
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, at least one software interrupt occurred.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_SOFTWARE
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This flag is set if the transmitted buffer queue is empty.  This flag
end_comment

begin_comment
comment|/// will be set if all transmitted buffer addresses get written into the DB.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_TXBUF_QUEUE_EMPTY
value|0x0010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This flag is set if no transmitted buffer addresses were written
end_comment

begin_comment
comment|/// into the DB.  (This could be because DBsize was too small.)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_TXBUFS_WRITTEN
value|0x0020
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This flag is set if there is no media detected.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATFLAGS_GET_STATUS_NO_MEDIA
value|0x0040
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Fill Header.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Transmit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI Receive
end_comment

begin_comment
comment|///.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// No additional StatFlags.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_STATCODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_STATCODE_INITIALIZE
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Common StatCodes returned by all UNDI commands, UNDI protocol functions
end_comment

begin_comment
comment|/// and BC protocol functions.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATCODE_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_INVALID_CDB
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_INVALID_CPB
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_BUSY
value|0x0003
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_QUEUE_FULL
value|0x0004
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_ALREADY_STARTED
value|0x0005
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NOT_STARTED
value|0x0006
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NOT_SHUTDOWN
value|0x0007
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_ALREADY_INITIALIZED
value|0x0008
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NOT_INITIALIZED
value|0x0009
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_DEVICE_FAILURE
value|0x000A
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NVDATA_FAILURE
value|0x000B
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_UNSUPPORTED
value|0x000C
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_BUFFER_FULL
value|0x000D
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_INVALID_PARAMETER
value|0x000E
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_INVALID_UNDI
value|0x000F
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_IPV4_NOT_SUPPORTED
value|0x0010
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_IPV6_NOT_SUPPORTED
value|0x0011
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NOT_ENOUGH_MEMORY
value|0x0012
end_define

begin_define
define|#
directive|define
name|PXE_STATCODE_NO_DATA
value|0x0013
end_define

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_IFNUM
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This interface number must be passed to the S/W UNDI Start command.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_IFNUM_START
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This interface number is returned by the S/W UNDI Get State and
end_comment

begin_comment
comment|/// Start commands if information in the CDB, CPB or DB is invalid.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_IFNUM_INVALID
value|0x0000
end_define

begin_typedef
typedef|typedef
name|PXE_UINT16
name|PXE_CONTROL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Setting this flag directs the UNDI to queue this command for later
end_comment

begin_comment
comment|/// execution if the UNDI is busy and it supports command queuing.
end_comment

begin_comment
comment|/// If queuing is not supported, a PXE_STATCODE_INVALID_CONTROL error
end_comment

begin_comment
comment|/// is returned.  If the queue is full, a PXE_STATCODE_CDB_QUEUE_FULL
end_comment

begin_comment
comment|/// error is returned.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_CONTROL_QUEUE_IF_BUSY
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// These two bit values are used to determine if there are more UNDI
end_comment

begin_comment
comment|/// CDB structures following this one.  If the link bit is set, there
end_comment

begin_comment
comment|/// must be a CDB structure following this one.  Execution will start
end_comment

begin_comment
comment|/// on the next CDB structure as soon as this one completes successfully.
end_comment

begin_comment
comment|/// If an error is generated by this command, execution will stop.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_CONTROL_LINK
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXE_CONTROL_LAST_CDB_IN_LIST
value|0x0000
end_define

begin_typedef
typedef|typedef
name|PXE_UINT8
name|PXE_FRAME_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_UNICAST
value|0x01
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_BROADCAST
value|0x02
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_FILTERED_MULTICAST
value|0x03
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_PROMISCUOUS
value|0x04
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_PROMISCUOUS_MULTICAST
value|0x05
end_define

begin_define
define|#
directive|define
name|PXE_FRAME_TYPE_MULTICAST
value|PXE_FRAME_TYPE_FILTERED_MULTICAST
end_define

begin_typedef
typedef|typedef
name|PXE_UINT32
name|PXE_IPV4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PXE_UINT32
name|PXE_IPV6
index|[
literal|4
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_MAC_LENGTH
value|32
end_define

begin_typedef
typedef|typedef
name|PXE_UINT8
name|PXE_MAC_ADDR
index|[
name|PXE_MAC_LENGTH
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PXE_UINT8
name|PXE_IFTYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|PXE_MEDIA_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This information is from the ARP section of RFC 1700.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     1 Ethernet (10Mb)                                    [JBP]
end_comment

begin_comment
comment|///     2 Experimental Ethernet (3Mb)                        [JBP]
end_comment

begin_comment
comment|///     3 Amateur Radio AX.25                                [PXK]
end_comment

begin_comment
comment|///     4 Proteon ProNET Token Ring                          [JBP]
end_comment

begin_comment
comment|///     5 Chaos                                              [GXP]
end_comment

begin_comment
comment|///     6 IEEE 802 Networks                                  [JBP]
end_comment

begin_comment
comment|///     7 ARCNET                                             [JBP]
end_comment

begin_comment
comment|///     8 Hyperchannel                                       [JBP]
end_comment

begin_comment
comment|///     9 Lanstar                                             [TU]
end_comment

begin_comment
comment|///    10 Autonet Short Address                             [MXB1]
end_comment

begin_comment
comment|///    11 LocalTalk                                         [JKR1]
end_comment

begin_comment
comment|///    12 LocalNet (IBM* PCNet or SYTEK* LocalNET)           [JXM]
end_comment

begin_comment
comment|///    13 Ultra link                                        [RXD2]
end_comment

begin_comment
comment|///    14 SMDS                                              [GXC1]
end_comment

begin_comment
comment|///    15 Frame Relay                                        [AGM]
end_comment

begin_comment
comment|///    16 Asynchronous Transmission Mode (ATM)              [JXB2]
end_comment

begin_comment
comment|///    17 HDLC                                               [JBP]
end_comment

begin_comment
comment|///    18 Fibre Channel                            [Yakov Rekhter]
end_comment

begin_comment
comment|///    19 Asynchronous Transmission Mode (ATM)      [Mark Laubach]
end_comment

begin_comment
comment|///    20 Serial Line                                        [JBP]
end_comment

begin_comment
comment|///    21 Asynchronous Transmission Mode (ATM)              [MXB1]
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// * Other names and brands may be claimed as the property of others.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_IFTYPE_ETHERNET
value|0x01
end_define

begin_define
define|#
directive|define
name|PXE_IFTYPE_TOKENRING
value|0x04
end_define

begin_define
define|#
directive|define
name|PXE_IFTYPE_FIBRE_CHANNEL
value|0x12
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_hw_undi
block|{
name|PXE_UINT32
name|Signature
decl_stmt|;
comment|///< PXE_ROMID_SIGNATURE.
name|PXE_UINT8
name|Len
decl_stmt|;
comment|///< sizeof(PXE_HW_UNDI).
name|PXE_UINT8
name|Fudge
decl_stmt|;
comment|///< makes 8-bit cksum equal zero.
name|PXE_UINT8
name|Rev
decl_stmt|;
comment|///< PXE_ROMID_REV.
name|PXE_UINT8
name|IFcnt
decl_stmt|;
comment|///< physical connector count lower byte.
name|PXE_UINT8
name|MajorVer
decl_stmt|;
comment|///< PXE_ROMID_MAJORVER.
name|PXE_UINT8
name|MinorVer
decl_stmt|;
comment|///< PXE_ROMID_MINORVER.
name|PXE_UINT8
name|IFcntExt
decl_stmt|;
comment|///< physical connector count upper byte.
name|PXE_UINT8
name|reserved
decl_stmt|;
comment|///< zero, not used.
name|PXE_UINT32
name|Implementation
decl_stmt|;
comment|///< implementation flags.
comment|///< reserved             ///< vendor use.
comment|///< UINT32 Status;       ///< status port.
comment|///< UINT32 Command;      ///< command port.
comment|///< UINT64 CDBaddr;      ///< CDB address port.
comment|///<
block|}
name|PXE_HW_UNDI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Status port bit definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI operation state.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWSTAT_STATE_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_BUSY
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_INITIALIZED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_STARTED
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_STOPPED
value|0x00000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, last command failed.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWSTAT_COMMAND_FAILED
value|0x20000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, identifies enabled receive filters.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWSTAT_PROMISCUOUS_MULTICAST_RX_ENABLED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_PROMISCUOUS_RX_ENABLED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_BROADCAST_RX_ENABLED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_MULTICAST_RX_ENABLED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_UNICAST_RX_ENABLED
value|0x00000100
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, identifies enabled external interrupts.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWSTAT_SOFTWARE_INT_ENABLED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_TX_COMPLETE_INT_ENABLED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_PACKET_RX_INT_ENABLED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_CMD_COMPLETE_INT_ENABLED
value|0x00000010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, identifies pending interrupts.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWSTAT_SOFTWARE_INT_PENDING
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_TX_COMPLETE_INT_PENDING
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_PACKET_RX_INT_PENDING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PXE_HWSTAT_CMD_COMPLETE_INT_PENDING
value|0x00000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Command port definitions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If set, CDB identified in CDBaddr port is given to UNDI.
end_comment

begin_comment
comment|/// If not set, other bits in this word will be processed.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWCMD_ISSUE_COMMAND
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_INTS_AND_FILTS
value|0x00000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use these to enable/disable receive filters.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWCMD_PROMISCUOUS_MULTICAST_RX_ENABLE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_PROMISCUOUS_RX_ENABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_BROADCAST_RX_ENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_MULTICAST_RX_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_UNICAST_RX_ENABLE
value|0x00000100
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use these to enable/disable external interrupts.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWCMD_SOFTWARE_INT_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_TX_COMPLETE_INT_ENABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_PACKET_RX_INT_ENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_CMD_COMPLETE_INT_ENABLE
value|0x00000010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use these to clear pending external interrupts.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_HWCMD_CLEAR_SOFTWARE_INT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_CLEAR_TX_COMPLETE_INT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_CLEAR_PACKET_RX_INT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PXE_HWCMD_CLEAR_CMD_COMPLETE_INT
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_sw_undi
block|{
name|PXE_UINT32
name|Signature
decl_stmt|;
comment|///< PXE_ROMID_SIGNATURE.
name|PXE_UINT8
name|Len
decl_stmt|;
comment|///< sizeof(PXE_SW_UNDI).
name|PXE_UINT8
name|Fudge
decl_stmt|;
comment|///< makes 8-bit cksum zero.
name|PXE_UINT8
name|Rev
decl_stmt|;
comment|///< PXE_ROMID_REV.
name|PXE_UINT8
name|IFcnt
decl_stmt|;
comment|///< physical connector count lower byte.
name|PXE_UINT8
name|MajorVer
decl_stmt|;
comment|///< PXE_ROMID_MAJORVER.
name|PXE_UINT8
name|MinorVer
decl_stmt|;
comment|///< PXE_ROMID_MINORVER.
name|PXE_UINT8
name|IFcntExt
decl_stmt|;
comment|///< physical connector count upper byte.
name|PXE_UINT8
name|reserved1
decl_stmt|;
comment|///< zero, not used.
name|PXE_UINT32
name|Implementation
decl_stmt|;
comment|///< Implementation flags.
name|PXE_UINT64
name|EntryPoint
decl_stmt|;
comment|///< API entry point.
name|PXE_UINT8
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|///< zero, not used.
name|PXE_UINT8
name|BusCnt
decl_stmt|;
comment|///< number of bustypes supported.
name|PXE_UINT32
name|BusType
index|[
literal|1
index|]
decl_stmt|;
comment|///< list of supported bustypes.
block|}
name|PXE_SW_UNDI
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|u_pxe_undi
block|{
name|PXE_HW_UNDI
name|hw
decl_stmt|;
name|PXE_SW_UNDI
name|sw
decl_stmt|;
block|}
name|PXE_UNDI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signature of !PXE structure.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_ROMID_SIGNATURE
value|PXE_BUSTYPE ('!', 'P', 'X', 'E')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// !PXE structure format revision
end_comment

begin_comment
comment|///.
end_comment

begin_define
define|#
directive|define
name|PXE_ROMID_REV
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UNDI command interface revision.  These are the values that get sent
end_comment

begin_comment
comment|/// in option 94 (Client Network Interface Identifier) in the DHCP Discover
end_comment

begin_comment
comment|/// and PXE Boot Server Request packets.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_ROMID_MAJORVER
value|0x03
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_MINORVER
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implementation flags.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_HW_UNDI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_SW_VIRT_ADDR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_64BIT_DEVICE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_FRAG_SUPPORTED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_CMD_LINK_SUPPORTED
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_CMD_QUEUE_SUPPORTED
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_MULTI_FRAME_SUPPORTED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_NVDATA_SUPPORT_MASK
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_NVDATA_BULK_WRITABLE
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_NVDATA_SPARSE_WRITABLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_NVDATA_READ_ONLY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_NVDATA_NOT_AVAILABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_STATISTICS_SUPPORTED
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_STATION_ADDR_SETTABLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_PROMISCUOUS_MULTICAST_RX_SUPPORTED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_PROMISCUOUS_RX_SUPPORTED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_BROADCAST_RX_SUPPORTED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_FILTERED_MULTICAST_RX_SUPPORTED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_SOFTWARE_INT_SUPPORTED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_TX_COMPLETE_INT_SUPPORTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_PACKET_RX_INT_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PXE_ROMID_IMP_CMD_COMPLETE_INT_SUPPORTED
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cdb
block|{
name|PXE_OPCODE
name|OpCode
decl_stmt|;
name|PXE_OPFLAGS
name|OpFlags
decl_stmt|;
name|PXE_UINT16
name|CPBsize
decl_stmt|;
name|PXE_UINT16
name|DBsize
decl_stmt|;
name|PXE_UINT64
name|CPBaddr
decl_stmt|;
name|PXE_UINT64
name|DBaddr
decl_stmt|;
name|PXE_STATCODE
name|StatCode
decl_stmt|;
name|PXE_STATFLAGS
name|StatFlags
decl_stmt|;
name|PXE_UINT16
name|IFnum
decl_stmt|;
name|PXE_CONTROL
name|Control
decl_stmt|;
block|}
name|PXE_CDB
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|u_pxe_ip_addr
block|{
name|PXE_IPV6
name|IPv6
decl_stmt|;
name|PXE_IPV4
name|IPv4
decl_stmt|;
block|}
name|PXE_IP_ADDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|pxe_device
block|{
comment|///
comment|/// PCI and PC Card NICs are both identified using bus, device
comment|/// and function numbers.  For PC Card, this may require PC
comment|/// Card services to be loaded in the BIOS or preboot
comment|/// environment.
comment|///
struct|struct
block|{
comment|///
comment|/// See S/W UNDI ROMID structure definition for PCI and
comment|/// PCC BusType definitions.
comment|///
name|PXE_UINT32
name|BusType
decl_stmt|;
comment|///
comment|/// Bus, device& function numbers that locate this device.
comment|///
name|PXE_UINT16
name|Bus
decl_stmt|;
name|PXE_UINT8
name|Device
decl_stmt|;
name|PXE_UINT8
name|Function
decl_stmt|;
block|}
name|PCI
struct|,
name|PCC
struct|;
block|}
name|PXE_DEVICE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// cpb and db definitions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_PCI_CONFIG_LEN
value|64
end_define

begin_comment
comment|///< # of dwords.
end_comment

begin_define
define|#
directive|define
name|MAX_EEPROM_LEN
value|128
end_define

begin_comment
comment|///< # of dwords.
end_comment

begin_define
define|#
directive|define
name|MAX_XMIT_BUFFERS
value|32
end_define

begin_comment
comment|///< recycling Q length for xmit_done.
end_comment

begin_define
define|#
directive|define
name|MAX_MCAST_ADDRESS_CNT
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_start_30
block|{
comment|///
comment|/// PXE_VOID Delay(UINTN microseconds);
comment|///
comment|/// UNDI will never request a delay smaller than 10 microseconds
comment|/// and will always request delays in increments of 10 microseconds.
comment|/// The Delay() CallBack routine must delay between n and n + 10
comment|/// microseconds before returning control to the UNDI.
comment|///
comment|/// This field cannot be set to zero.
comment|///
name|UINT64
name|Delay
decl_stmt|;
comment|///
comment|/// PXE_VOID Block(UINT32 enable);
comment|///
comment|/// UNDI may need to block multi-threaded/multi-processor access to
comment|/// critical code sections when programming or accessing the network
comment|/// device.  To this end, a blocking service is needed by the UNDI.
comment|/// When UNDI needs a block, it will call Block() passing a non-zero
comment|/// value.  When UNDI no longer needs a block, it will call Block()
comment|/// with a zero value.  When called, if the Block() is already enabled,
comment|/// do not return control to the UNDI until the previous Block() is
comment|/// disabled.
comment|///
comment|/// This field cannot be set to zero.
comment|///
name|UINT64
name|Block
decl_stmt|;
comment|///
comment|/// PXE_VOID Virt2Phys(UINT64 virtual, UINT64 physical_ptr);
comment|///
comment|/// UNDI will pass the virtual address of a buffer and the virtual
comment|/// address of a 64-bit physical buffer.  Convert the virtual address
comment|/// to a physical address and write the result to the physical address
comment|/// buffer.  If virtual and physical addresses are the same, just
comment|/// copy the virtual address to the physical address buffer.
comment|///
comment|/// This field can be set to zero if virtual and physical addresses
comment|/// are equal.
comment|///
name|UINT64
name|Virt2Phys
decl_stmt|;
comment|///
comment|/// PXE_VOID Mem_IO(UINT8 read_write, UINT8 len, UINT64 port,
comment|///              UINT64 buf_addr);
comment|///
comment|/// UNDI will read or write the device io space using this call back
comment|/// function. It passes the number of bytes as the len parameter and it
comment|/// will be either 1,2,4 or 8.
comment|///
comment|/// This field can not be set to zero.
comment|///
name|UINT64
name|Mem_IO
decl_stmt|;
block|}
name|PXE_CPB_START_30
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_start_31
block|{
comment|///
comment|/// PXE_VOID Delay(UINT64 UnqId, UINTN microseconds);
comment|///
comment|/// UNDI will never request a delay smaller than 10 microseconds
comment|/// and will always request delays in increments of 10 microseconds.
comment|/// The Delay() CallBack routine must delay between n and n + 10
comment|/// microseconds before returning control to the UNDI.
comment|///
comment|/// This field cannot be set to zero.
comment|///
name|UINT64
name|Delay
decl_stmt|;
comment|///
comment|/// PXE_VOID Block(UINT64 unq_id, UINT32 enable);
comment|///
comment|/// UNDI may need to block multi-threaded/multi-processor access to
comment|/// critical code sections when programming or accessing the network
comment|/// device.  To this end, a blocking service is needed by the UNDI.
comment|/// When UNDI needs a block, it will call Block() passing a non-zero
comment|/// value.  When UNDI no longer needs a block, it will call Block()
comment|/// with a zero value.  When called, if the Block() is already enabled,
comment|/// do not return control to the UNDI until the previous Block() is
comment|/// disabled.
comment|///
comment|/// This field cannot be set to zero.
comment|///
name|UINT64
name|Block
decl_stmt|;
comment|///
comment|/// PXE_VOID Virt2Phys(UINT64 UnqId, UINT64 virtual, UINT64 physical_ptr);
comment|///
comment|/// UNDI will pass the virtual address of a buffer and the virtual
comment|/// address of a 64-bit physical buffer.  Convert the virtual address
comment|/// to a physical address and write the result to the physical address
comment|/// buffer.  If virtual and physical addresses are the same, just
comment|/// copy the virtual address to the physical address buffer.
comment|///
comment|/// This field can be set to zero if virtual and physical addresses
comment|/// are equal.
comment|///
name|UINT64
name|Virt2Phys
decl_stmt|;
comment|///
comment|/// PXE_VOID Mem_IO(UINT64 UnqId, UINT8 read_write, UINT8 len, UINT64 port,
comment|///              UINT64 buf_addr);
comment|///
comment|/// UNDI will read or write the device io space using this call back
comment|/// function. It passes the number of bytes as the len parameter and it
comment|/// will be either 1,2,4 or 8.
comment|///
comment|/// This field can not be set to zero.
comment|///
name|UINT64
name|Mem_IO
decl_stmt|;
comment|///
comment|/// PXE_VOID Map_Mem(UINT64 unq_id, UINT64 virtual_addr, UINT32 size,
comment|///                 UINT32 Direction, UINT64 mapped_addr);
comment|///
comment|/// UNDI will pass the virtual address of a buffer, direction of the data
comment|/// flow from/to the mapped buffer (the constants are defined below)
comment|/// and a place holder (pointer) for the mapped address.
comment|/// This call will Map the given address to a physical DMA address and write
comment|/// the result to the mapped_addr pointer.  If there is no need to
comment|/// map the given address to a lower address (i.e. the given address is
comment|/// associated with a physical address that is already compatible to be
comment|/// used with the DMA, it converts the given virtual address to it's
comment|/// physical address and write that in the mapped address pointer.
comment|///
comment|/// This field can be set to zero if there is no mapping service available.
comment|///
name|UINT64
name|Map_Mem
decl_stmt|;
comment|///
comment|/// PXE_VOID UnMap_Mem(UINT64 unq_id, UINT64 virtual_addr, UINT32 size,
comment|///            UINT32 Direction, UINT64 mapped_addr);
comment|///
comment|/// UNDI will pass the virtual and mapped addresses of a buffer.
comment|/// This call will un map the given address.
comment|///
comment|/// This field can be set to zero if there is no unmapping service available.
comment|///
name|UINT64
name|UnMap_Mem
decl_stmt|;
comment|///
comment|/// PXE_VOID Sync_Mem(UINT64 unq_id, UINT64 virtual,
comment|///            UINT32 size, UINT32 Direction, UINT64 mapped_addr);
comment|///
comment|/// UNDI will pass the virtual and mapped addresses of a buffer.
comment|/// This call will synchronize the contents of both the virtual and mapped.
comment|/// buffers for the given Direction.
comment|///
comment|/// This field can be set to zero if there is no service available.
comment|///
name|UINT64
name|Sync_Mem
decl_stmt|;
comment|///
comment|/// protocol driver can provide anything for this Unique_ID, UNDI remembers
comment|/// that as just a 64bit value associated to the interface specified by
comment|/// the ifnum and gives it back as a parameter to all the call-back routines
comment|/// when calling for that interface!
comment|///
name|UINT64
name|Unique_ID
decl_stmt|;
block|}
name|PXE_CPB_START_31
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TO_AND_FROM_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|FROM_DEVICE
value|1
end_define

begin_define
define|#
directive|define
name|TO_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|PXE_DELAY_MILLISECOND
value|1000
end_define

begin_define
define|#
directive|define
name|PXE_DELAY_SECOND
value|1000000
end_define

begin_define
define|#
directive|define
name|PXE_IO_READ
value|0
end_define

begin_define
define|#
directive|define
name|PXE_IO_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|PXE_MEM_READ
value|2
end_define

begin_define
define|#
directive|define
name|PXE_MEM_WRITE
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_get_init_info
block|{
comment|///
comment|/// Minimum length of locked memory buffer that must be given to
comment|/// the Initialize command. Giving UNDI more memory will generally
comment|/// give better performance.
comment|///
comment|/// If MemoryRequired is zero, the UNDI does not need and will not
comment|/// use system memory to receive and transmit packets.
comment|///
name|PXE_UINT32
name|MemoryRequired
decl_stmt|;
comment|///
comment|/// Maximum frame data length for Tx/Rx excluding the media header.
comment|///
name|PXE_UINT32
name|FrameDataLen
decl_stmt|;
comment|///
comment|/// Supported link speeds are in units of mega bits.  Common ethernet
comment|/// values are 10, 100 and 1000.  Unused LinkSpeeds[] entries are zero
comment|/// filled.
comment|///
name|PXE_UINT32
name|LinkSpeeds
index|[
literal|4
index|]
decl_stmt|;
comment|///
comment|/// Number of non-volatile storage items.
comment|///
name|PXE_UINT32
name|NvCount
decl_stmt|;
comment|///
comment|/// Width of non-volatile storage item in bytes.  0, 1, 2 or 4
comment|///
name|PXE_UINT16
name|NvWidth
decl_stmt|;
comment|///
comment|/// Media header length.  This is the typical media header length for
comment|/// this UNDI.  This information is needed when allocating receive
comment|/// and transmit buffers.
comment|///
name|PXE_UINT16
name|MediaHeaderLen
decl_stmt|;
comment|///
comment|/// Number of bytes in the NIC hardware (MAC) address.
comment|///
name|PXE_UINT16
name|HWaddrLen
decl_stmt|;
comment|///
comment|/// Maximum number of multicast MAC addresses in the multicast
comment|/// MAC address filter list.
comment|///
name|PXE_UINT16
name|MCastFilterCnt
decl_stmt|;
comment|///
comment|/// Default number and size of transmit and receive buffers that will
comment|/// be allocated by the UNDI.  If MemoryRequired is non-zero, this
comment|/// allocation will come out of the memory buffer given to the Initialize
comment|/// command.  If MemoryRequired is zero, this allocation will come out of
comment|/// memory on the NIC.
comment|///
name|PXE_UINT16
name|TxBufCnt
decl_stmt|;
name|PXE_UINT16
name|TxBufSize
decl_stmt|;
name|PXE_UINT16
name|RxBufCnt
decl_stmt|;
name|PXE_UINT16
name|RxBufSize
decl_stmt|;
comment|///
comment|/// Hardware interface types defined in the Assigned Numbers RFC
comment|/// and used in DHCP and ARP packets.
comment|/// See the PXE_IFTYPE typedef and PXE_IFTYPE_xxx macros.
comment|///
name|PXE_UINT8
name|IFtype
decl_stmt|;
comment|///
comment|/// Supported duplex.  See PXE_DUPLEX_xxxxx #defines below.
comment|///
name|PXE_UINT8
name|SupportedDuplexModes
decl_stmt|;
comment|///
comment|/// Supported loopback options.  See PXE_LOOPBACK_xxxxx #defines below.
comment|///
name|PXE_UINT8
name|SupportedLoopBackModes
decl_stmt|;
block|}
name|PXE_DB_GET_INIT_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_MAX_TXRX_UNIT_ETHER
value|1500
end_define

begin_define
define|#
directive|define
name|PXE_HWADDR_LEN_ETHER
value|0x0006
end_define

begin_define
define|#
directive|define
name|PXE_MAC_HEADER_LEN_ETHER
value|0x000E
end_define

begin_define
define|#
directive|define
name|PXE_DUPLEX_ENABLE_FULL_SUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|PXE_DUPLEX_FORCE_FULL_SUPPORTED
value|2
end_define

begin_define
define|#
directive|define
name|PXE_LOOPBACK_INTERNAL_SUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|PXE_LOOPBACK_EXTERNAL_SUPPORTED
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_pci_config_info
block|{
comment|///
comment|/// This is the flag field for the PXE_DB_GET_CONFIG_INFO union.
comment|/// For PCI bus devices, this field is set to PXE_BUSTYPE_PCI.
comment|///
name|UINT32
name|BusType
decl_stmt|;
comment|///
comment|/// This identifies the PCI network device that this UNDI interface.
comment|/// is bound to.
comment|///
name|UINT16
name|Bus
decl_stmt|;
name|UINT8
name|Device
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
comment|///
comment|/// This is a copy of the PCI configuration space for this
comment|/// network device.
comment|///
union|union
block|{
name|UINT8
name|Byte
index|[
literal|256
index|]
decl_stmt|;
name|UINT16
name|Word
index|[
literal|128
index|]
decl_stmt|;
name|UINT32
name|Dword
index|[
literal|64
index|]
decl_stmt|;
block|}
name|Config
union|;
block|}
name|PXE_PCI_CONFIG_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_pcc_config_info
block|{
comment|///
comment|/// This is the flag field for the PXE_DB_GET_CONFIG_INFO union.
comment|/// For PCC bus devices, this field is set to PXE_BUSTYPE_PCC.
comment|///
name|PXE_UINT32
name|BusType
decl_stmt|;
comment|///
comment|/// This identifies the PCC network device that this UNDI interface
comment|/// is bound to.
comment|///
name|PXE_UINT16
name|Bus
decl_stmt|;
name|PXE_UINT8
name|Device
decl_stmt|;
name|PXE_UINT8
name|Function
decl_stmt|;
comment|///
comment|/// This is a copy of the PCC configuration space for this
comment|/// network device.
comment|///
union|union
block|{
name|PXE_UINT8
name|Byte
index|[
literal|256
index|]
decl_stmt|;
name|PXE_UINT16
name|Word
index|[
literal|128
index|]
decl_stmt|;
name|PXE_UINT32
name|Dword
index|[
literal|64
index|]
decl_stmt|;
block|}
name|Config
union|;
block|}
name|PXE_PCC_CONFIG_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|u_pxe_db_get_config_info
block|{
name|PXE_PCI_CONFIG_INFO
name|pci
decl_stmt|;
name|PXE_PCC_CONFIG_INFO
name|pcc
decl_stmt|;
block|}
name|PXE_DB_GET_CONFIG_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_initialize
block|{
comment|///
comment|/// Address of first (lowest) byte of the memory buffer.  This buffer must
comment|/// be in contiguous physical memory and cannot be swapped out.  The UNDI
comment|/// will be using this for transmit and receive buffering.
comment|///
name|PXE_UINT64
name|MemoryAddr
decl_stmt|;
comment|///
comment|/// MemoryLength must be greater than or equal to MemoryRequired
comment|/// returned by the Get Init Info command.
comment|///
name|PXE_UINT32
name|MemoryLength
decl_stmt|;
comment|///
comment|/// Desired link speed in Mbit/sec.  Common ethernet values are 10, 100
comment|/// and 1000.  Setting a value of zero will auto-detect and/or use the
comment|/// default link speed (operation depends on UNDI/NIC functionality).
comment|///
name|PXE_UINT32
name|LinkSpeed
decl_stmt|;
comment|///
comment|/// Suggested number and size of receive and transmit buffers to
comment|/// allocate.  If MemoryAddr and MemoryLength are non-zero, this
comment|/// allocation comes out of the supplied memory buffer.  If MemoryAddr
comment|/// and MemoryLength are zero, this allocation comes out of memory
comment|/// on the NIC.
comment|///
comment|/// If these fields are set to zero, the UNDI will allocate buffer
comment|/// counts and sizes as it sees fit.
comment|///
name|PXE_UINT16
name|TxBufCnt
decl_stmt|;
name|PXE_UINT16
name|TxBufSize
decl_stmt|;
name|PXE_UINT16
name|RxBufCnt
decl_stmt|;
name|PXE_UINT16
name|RxBufSize
decl_stmt|;
comment|///
comment|/// The following configuration parameters are optional and must be zero
comment|/// to use the default values.
comment|///
name|PXE_UINT8
name|DuplexMode
decl_stmt|;
name|PXE_UINT8
name|LoopBackMode
decl_stmt|;
block|}
name|PXE_CPB_INITIALIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_DUPLEX_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|PXE_FORCE_FULL_DUPLEX
value|0x01
end_define

begin_define
define|#
directive|define
name|PXE_ENABLE_FULL_DUPLEX
value|0x02
end_define

begin_define
define|#
directive|define
name|PXE_FORCE_HALF_DUPLEX
value|0x04
end_define

begin_define
define|#
directive|define
name|PXE_DISABLE_FULL_DUPLEX
value|0x08
end_define

begin_define
define|#
directive|define
name|LOOPBACK_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|LOOPBACK_INTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|LOOPBACK_EXTERNAL
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_initialize
block|{
comment|///
comment|/// Actual amount of memory used from the supplied memory buffer.  This
comment|/// may be less that the amount of memory suppllied and may be zero if
comment|/// the UNDI and network device do not use external memory buffers.
comment|///
comment|/// Memory used by the UNDI and network device is allocated from the
comment|/// lowest memory buffer address.
comment|///
name|PXE_UINT32
name|MemoryUsed
decl_stmt|;
comment|///
comment|/// Actual number and size of receive and transmit buffers that were
comment|/// allocated.
comment|///
name|PXE_UINT16
name|TxBufCnt
decl_stmt|;
name|PXE_UINT16
name|TxBufSize
decl_stmt|;
name|PXE_UINT16
name|RxBufCnt
decl_stmt|;
name|PXE_UINT16
name|RxBufSize
decl_stmt|;
block|}
name|PXE_DB_INITIALIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_receive_filters
block|{
comment|///
comment|/// List of multicast MAC addresses.  This list, if present, will
comment|/// replace the existing multicast MAC address filter list.
comment|///
name|PXE_MAC_ADDR
name|MCastList
index|[
name|MAX_MCAST_ADDRESS_CNT
index|]
decl_stmt|;
block|}
name|PXE_CPB_RECEIVE_FILTERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_receive_filters
block|{
comment|///
comment|/// Filtered multicast MAC address list.
comment|///
name|PXE_MAC_ADDR
name|MCastList
index|[
name|MAX_MCAST_ADDRESS_CNT
index|]
decl_stmt|;
block|}
name|PXE_DB_RECEIVE_FILTERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_station_address
block|{
comment|///
comment|/// If supplied and supported, the current station MAC address
comment|/// will be changed.
comment|///
name|PXE_MAC_ADDR
name|StationAddr
decl_stmt|;
block|}
name|PXE_CPB_STATION_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_dpb_station_address
block|{
comment|///
comment|/// Current station MAC address.
comment|///
name|PXE_MAC_ADDR
name|StationAddr
decl_stmt|;
comment|///
comment|/// Station broadcast MAC address.
comment|///
name|PXE_MAC_ADDR
name|BroadcastAddr
decl_stmt|;
comment|///
comment|/// Permanent station MAC address.
comment|///
name|PXE_MAC_ADDR
name|PermanentAddr
decl_stmt|;
block|}
name|PXE_DB_STATION_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_statistics
block|{
comment|///
comment|/// Bit field identifying what statistic data is collected by the
comment|/// UNDI/NIC.
comment|/// If bit 0x00 is set, Data[0x00] is collected.
comment|/// If bit 0x01 is set, Data[0x01] is collected.
comment|/// If bit 0x20 is set, Data[0x20] is collected.
comment|/// If bit 0x21 is set, Data[0x21] is collected.
comment|/// Etc.
comment|///
name|PXE_UINT64
name|Supported
decl_stmt|;
comment|///
comment|/// Statistic data.
comment|///
name|PXE_UINT64
name|Data
index|[
literal|64
index|]
decl_stmt|;
block|}
name|PXE_DB_STATISTICS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Total number of frames received.  Includes frames with errors and
end_comment

begin_comment
comment|/// dropped frames.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_TOTAL_FRAMES
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of valid frames received and copied into receive buffers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_GOOD_FRAMES
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames below the minimum length for the media.
end_comment

begin_comment
comment|/// This would be<64 for ethernet.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_UNDERSIZE_FRAMES
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames longer than the maxminum length for the
end_comment

begin_comment
comment|/// media.  This would be>1500 for ethernet.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_OVERSIZE_FRAMES
value|0x03
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Valid frames that were dropped because receive buffers were full.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_DROPPED_FRAMES
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of valid unicast frames received and not dropped.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_UNICAST_FRAMES
value|0x05
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of valid broadcast frames received and not dropped.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_BROADCAST_FRAMES
value|0x06
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of valid mutlicast frames received and not dropped.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_MULTICAST_FRAMES
value|0x07
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames w/ CRC or alignment errors.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_CRC_ERROR_FRAMES
value|0x08
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Total number of bytes received.  Includes frames with errors
end_comment

begin_comment
comment|/// and dropped frames.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_TOTAL_BYTES
value|0x09
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Transmit statistics.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_TOTAL_FRAMES
value|0x0A
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_GOOD_FRAMES
value|0x0B
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_UNDERSIZE_FRAMES
value|0x0C
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_OVERSIZE_FRAMES
value|0x0D
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_DROPPED_FRAMES
value|0x0E
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_UNICAST_FRAMES
value|0x0F
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_BROADCAST_FRAMES
value|0x10
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_MULTICAST_FRAMES
value|0x11
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_CRC_ERROR_FRAMES
value|0x12
end_define

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_TOTAL_BYTES
value|0x13
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of collisions detection on this subnet.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_COLLISIONS
value|0x14
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames destined for unsupported protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_UNSUPPORTED_PROTOCOL
value|0x15
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of valid frames received that were duplicated.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_DUPLICATED_FRAMES
value|0x16
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of encrypted frames received that failed to decrypt.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_RX_DECRYPT_ERROR_FRAMES
value|0x17
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames that failed to transmit after exceeding the retry limit.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_ERROR_FRAMES
value|0x18
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Number of frames transmitted successfully after more than one attempt.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PXE_STATISTICS_TX_RETRY_FRAMES
value|0x19
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_mcast_ip_to_mac
block|{
comment|///
comment|/// Multicast IP address to be converted to multicast MAC address.
comment|///
name|PXE_IP_ADDR
name|IP
decl_stmt|;
block|}
name|PXE_CPB_MCAST_IP_TO_MAC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_mcast_ip_to_mac
block|{
comment|///
comment|/// Multicast MAC address.
comment|///
name|PXE_MAC_ADDR
name|MAC
decl_stmt|;
block|}
name|PXE_DB_MCAST_IP_TO_MAC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_nvdata_sparse
block|{
comment|///
comment|/// NvData item list.  Only items in this list will be updated.
comment|///
struct|struct
block|{
comment|///
comment|///  Non-volatile storage address to be changed.
comment|///
name|PXE_UINT32
name|Addr
decl_stmt|;
comment|///
comment|/// Data item to write into above storage address.
comment|///
union|union
block|{
name|PXE_UINT8
name|Byte
decl_stmt|;
name|PXE_UINT16
name|Word
decl_stmt|;
name|PXE_UINT32
name|Dword
decl_stmt|;
block|}
name|Data
union|;
block|}
name|Item
index|[
name|MAX_EEPROM_LEN
index|]
struct|;
block|}
name|PXE_CPB_NVDATA_SPARSE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// When using bulk update, the size of the CPB structure must be
end_comment

begin_comment
comment|/// the same size as the non-volatile NIC storage.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
name|u_pxe_cpb_nvdata_bulk
block|{
comment|///
comment|/// Array of byte-wide data items.
comment|///
name|PXE_UINT8
name|Byte
index|[
name|MAX_EEPROM_LEN
operator|<<
literal|2
index|]
decl_stmt|;
comment|///
comment|/// Array of word-wide data items.
comment|///
name|PXE_UINT16
name|Word
index|[
name|MAX_EEPROM_LEN
operator|<<
literal|1
index|]
decl_stmt|;
comment|///
comment|/// Array of dword-wide data items.
comment|///
name|PXE_UINT32
name|Dword
index|[
name|MAX_EEPROM_LEN
index|]
decl_stmt|;
block|}
name|PXE_CPB_NVDATA_BULK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_nvdata
block|{
comment|///
comment|/// Arrays of data items from non-volatile storage.
comment|///
union|union
block|{
comment|///
comment|/// Array of byte-wide data items.
comment|///
name|PXE_UINT8
name|Byte
index|[
name|MAX_EEPROM_LEN
operator|<<
literal|2
index|]
decl_stmt|;
comment|///
comment|/// Array of word-wide data items.
comment|///
name|PXE_UINT16
name|Word
index|[
name|MAX_EEPROM_LEN
operator|<<
literal|1
index|]
decl_stmt|;
comment|///
comment|/// Array of dword-wide data items.
comment|///
name|PXE_UINT32
name|Dword
index|[
name|MAX_EEPROM_LEN
index|]
decl_stmt|;
block|}
name|Data
union|;
block|}
name|PXE_DB_NVDATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_get_status
block|{
comment|///
comment|/// Length of next receive frame (header + data).  If this is zero,
comment|/// there is no next receive frame available.
comment|///
name|PXE_UINT32
name|RxFrameLen
decl_stmt|;
comment|///
comment|/// Reserved, set to zero.
comment|///
name|PXE_UINT32
name|reserved
decl_stmt|;
comment|///
comment|///  Addresses of transmitted buffers that need to be recycled.
comment|///
name|PXE_UINT64
name|TxBuffer
index|[
name|MAX_XMIT_BUFFERS
index|]
decl_stmt|;
block|}
name|PXE_DB_GET_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_fill_header
block|{
comment|///
comment|/// Source and destination MAC addresses.  These will be copied into
comment|/// the media header without doing byte swapping.
comment|///
name|PXE_MAC_ADDR
name|SrcAddr
decl_stmt|;
name|PXE_MAC_ADDR
name|DestAddr
decl_stmt|;
comment|///
comment|/// Address of first byte of media header.  The first byte of packet data
comment|/// follows the last byte of the media header.
comment|///
name|PXE_UINT64
name|MediaHeader
decl_stmt|;
comment|///
comment|/// Length of packet data in bytes (not including the media header).
comment|///
name|PXE_UINT32
name|PacketLen
decl_stmt|;
comment|///
comment|/// Protocol type.  This will be copied into the media header without
comment|/// doing byte swapping.  Protocol type numbers can be obtained from
comment|/// the Assigned Numbers RFC 1700.
comment|///
name|PXE_UINT16
name|Protocol
decl_stmt|;
comment|///
comment|/// Length of the media header in bytes.
comment|///
name|PXE_UINT16
name|MediaHeaderLen
decl_stmt|;
block|}
name|PXE_CPB_FILL_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PXE_PROTOCOL_ETHERNET_IP
value|0x0800
end_define

begin_define
define|#
directive|define
name|PXE_PROTOCOL_ETHERNET_ARP
value|0x0806
end_define

begin_define
define|#
directive|define
name|MAX_XMIT_FRAGMENTS
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_fill_header_fragmented
block|{
comment|///
comment|/// Source and destination MAC addresses.  These will be copied into
comment|/// the media header without doing byte swapping.
comment|///
name|PXE_MAC_ADDR
name|SrcAddr
decl_stmt|;
name|PXE_MAC_ADDR
name|DestAddr
decl_stmt|;
comment|///
comment|/// Length of packet data in bytes (not including the media header).
comment|///
name|PXE_UINT32
name|PacketLen
decl_stmt|;
comment|///
comment|/// Protocol type.  This will be copied into the media header without
comment|/// doing byte swapping.  Protocol type numbers can be obtained from
comment|/// the Assigned Numbers RFC 1700.
comment|///
name|PXE_MEDIA_PROTOCOL
name|Protocol
decl_stmt|;
comment|///
comment|/// Length of the media header in bytes.
comment|///
name|PXE_UINT16
name|MediaHeaderLen
decl_stmt|;
comment|///
comment|/// Number of packet fragment descriptors.
comment|///
name|PXE_UINT16
name|FragCnt
decl_stmt|;
comment|///
comment|/// Reserved, must be set to zero.
comment|///
name|PXE_UINT16
name|reserved
decl_stmt|;
comment|///
comment|/// Array of packet fragment descriptors.  The first byte of the media
comment|/// header is the first byte of the first fragment.
comment|///
struct|struct
block|{
comment|///
comment|/// Address of this packet fragment.
comment|///
name|PXE_UINT64
name|FragAddr
decl_stmt|;
comment|///
comment|/// Length of this packet fragment.
comment|///
name|PXE_UINT32
name|FragLen
decl_stmt|;
comment|///
comment|/// Reserved, must be set to zero.
comment|///
name|PXE_UINT32
name|reserved
decl_stmt|;
block|}
name|FragDesc
index|[
name|MAX_XMIT_FRAGMENTS
index|]
struct|;
block|}
name|PXE_CPB_FILL_HEADER_FRAGMENTED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_transmit
block|{
comment|///
comment|/// Address of first byte of frame buffer.  This is also the first byte
comment|/// of the media header.
comment|///
name|PXE_UINT64
name|FrameAddr
decl_stmt|;
comment|///
comment|/// Length of the data portion of the frame buffer in bytes.  Do not
comment|/// include the length of the media header.
comment|///
name|PXE_UINT32
name|DataLen
decl_stmt|;
comment|///
comment|/// Length of the media header in bytes.
comment|///
name|PXE_UINT16
name|MediaheaderLen
decl_stmt|;
comment|///
comment|/// Reserved, must be zero.
comment|///
name|PXE_UINT16
name|reserved
decl_stmt|;
block|}
name|PXE_CPB_TRANSMIT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_transmit_fragments
block|{
comment|///
comment|/// Length of packet data in bytes (not including the media header).
comment|///
name|PXE_UINT32
name|FrameLen
decl_stmt|;
comment|///
comment|/// Length of the media header in bytes.
comment|///
name|PXE_UINT16
name|MediaheaderLen
decl_stmt|;
comment|///
comment|/// Number of packet fragment descriptors.
comment|///
name|PXE_UINT16
name|FragCnt
decl_stmt|;
comment|///
comment|/// Array of frame fragment descriptors.  The first byte of the first
comment|/// fragment is also the first byte of the media header.
comment|///
struct|struct
block|{
comment|///
comment|/// Address of this frame fragment.
comment|///
name|PXE_UINT64
name|FragAddr
decl_stmt|;
comment|///
comment|/// Length of this frame fragment.
comment|///
name|PXE_UINT32
name|FragLen
decl_stmt|;
comment|///
comment|/// Reserved, must be set to zero.
comment|///
name|PXE_UINT32
name|reserved
decl_stmt|;
block|}
name|FragDesc
index|[
name|MAX_XMIT_FRAGMENTS
index|]
struct|;
block|}
name|PXE_CPB_TRANSMIT_FRAGMENTS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_cpb_receive
block|{
comment|///
comment|/// Address of first byte of receive buffer.  This is also the first byte
comment|/// of the frame header.
comment|///
name|PXE_UINT64
name|BufferAddr
decl_stmt|;
comment|///
comment|/// Length of receive buffer.  This must be large enough to hold the
comment|/// received frame (media header + data).  If the length of smaller than
comment|/// the received frame, data will be lost.
comment|///
name|PXE_UINT32
name|BufferLen
decl_stmt|;
comment|///
comment|/// Reserved, must be set to zero.
comment|///
name|PXE_UINT32
name|reserved
decl_stmt|;
block|}
name|PXE_CPB_RECEIVE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|s_pxe_db_receive
block|{
comment|///
comment|/// Source and destination MAC addresses from media header.
comment|///
name|PXE_MAC_ADDR
name|SrcAddr
decl_stmt|;
name|PXE_MAC_ADDR
name|DestAddr
decl_stmt|;
comment|///
comment|/// Length of received frame.  May be larger than receive buffer size.
comment|/// The receive buffer will not be overwritten.  This is how to tell
comment|/// if data was lost because the receive buffer was too small.
comment|///
name|PXE_UINT32
name|FrameLen
decl_stmt|;
comment|///
comment|/// Protocol type from media header.
comment|///
name|PXE_MEDIA_PROTOCOL
name|Protocol
decl_stmt|;
comment|///
comment|/// Length of media header in received frame.
comment|///
name|PXE_UINT16
name|MediaHeaderLen
decl_stmt|;
comment|///
comment|/// Type of receive frame.
comment|///
name|PXE_FRAME_TYPE
name|Type
decl_stmt|;
comment|///
comment|/// Reserved, must be zero.
comment|///
name|PXE_UINT8
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
name|PXE_DB_RECEIVE
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

