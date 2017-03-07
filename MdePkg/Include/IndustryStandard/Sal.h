begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Main SAL API's defined in Intel Itanium Processor Family System Abstraction   Layer Specification Revision 3.2 (December 2003)  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAL_API_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAL_API_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// SAL return status type
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|INTN
name|EFI_SAL_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call completed without error.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_SUCCESS
value|((EFI_SAL_STATUS) 0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call completed without error, but some information was lost due to overflow.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_OVERFLOW
value|((EFI_SAL_STATUS) 1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call completed without error; effect a warm boot of the system to complete the update.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_WARM_BOOT_NEEDED
value|((EFI_SAL_STATUS) 2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// More information is available for retrieval.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MORE_RECORDS
value|((EFI_SAL_STATUS) 3)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Not implemented.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_NOT_IMPLEMENTED
value|((EFI_SAL_STATUS) - 1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Invalid Argument.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_INVALID_ARGUMENT
value|((EFI_SAL_STATUS) - 2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Call completed without error.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_ERROR
value|((EFI_SAL_STATUS) - 3)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Virtual address not registered.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_VIRTUAL_ADDRESS_ERROR
value|((EFI_SAL_STATUS) - 4)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// No information available.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_NO_INFORMATION
value|((EFI_SAL_STATUS) - 5)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Scratch buffer required.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_NOT_ENOUGH_SCRATCH
value|((EFI_SAL_STATUS) - 9)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return registers from SAL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// SAL return status value in r8.
comment|///
name|EFI_SAL_STATUS
name|Status
decl_stmt|;
comment|///
comment|/// SAL returned value in r9.
comment|///
name|UINTN
name|r9
decl_stmt|;
comment|///
comment|/// SAL returned value in r10.
comment|///
name|UINTN
name|r10
decl_stmt|;
comment|///
comment|/// SAL returned value in r11.
comment|///
name|UINTN
name|r11
decl_stmt|;
block|}
name|SAL_RETURN_REGS
typedef|;
end_typedef

begin_comment
comment|/**   Prototype of SAL procedures.    @param  FunctionId         Functional identifier.                              The upper 32 bits are ignored and only the lower 32 bits                              are used. The following functional identifiers are defined:                              0x01XXXXXX - Architected SAL functional group.                              0x02XXXXXX to 0x03XXXXXX - OEM SAL functional group. Each OEM is                              allowed to use the entire range in the 0x02XXXXXX to 0x03XXXXXX range.                              0x04XXXXXX to 0xFFFFFFFF - Reserved.   @param  Arg1               The first parameter of the architected/OEM specific SAL functions.   @param  Arg2               The second parameter of the architected/OEM specific SAL functions.   @param  Arg3               The third parameter passed to the ESAL function based.   @param  Arg4               The fourth parameter passed to the ESAL function based.   @param  Arg5               The fifth parameter passed to the ESAL function based.   @param  Arg6               The sixth parameter passed to the ESAL function.   @param  Arg7               The seventh parameter passed to the ESAL function based.    @return r8                 Return status: positive number indicates successful,                              negative number indicates failure.           r9                 Other return parameter in r9.           r10                Other return parameter in r10.           r11                Other return parameter in r11.  **/
end_comment

begin_typedef
typedef|typedef
name|SAL_RETURN_REGS
function_decl|(
name|EFIAPI
modifier|*
name|SAL_PROC
function_decl|)
parameter_list|(
name|IN
name|UINT64
name|FunctionId
parameter_list|,
name|IN
name|UINT64
name|Arg1
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|,
name|IN
name|UINT64
name|Arg5
parameter_list|,
name|IN
name|UINT64
name|Arg6
parameter_list|,
name|IN
name|UINT64
name|Arg7
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// SAL Procedure FunctionId definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register software code locations with SAL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_SET_VECTORS
value|0x01000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return Machine State information obtained by SAL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_GET_STATE_INFO
value|0x01000001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Obtain size of Machine State information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_GET_STATE_INFO_SIZE
value|0x01000002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clear Machine State information.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_CLEAR_STATE_INFO
value|0x01000003
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Cause the processor to go into a spin loop within SAL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MC_RENDEZ
value|0x01000004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register the machine check interface layer with SAL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_PARAMS
value|0x01000005
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Register the physical addresses of locations needed by SAL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_REGISTER_PHYSICAL_ADDR
value|0x01000006
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flush the instruction or data caches.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_CACHE_FLUSH
value|0x01000008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initialize the instruction and data caches.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_CACHE_INIT
value|0x01000009
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Read from the PCI configuration space.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_PCI_CONFIG_READ
value|0x01000010
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Write to the PCI configuration space.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_PCI_CONFIG_WRITE
value|0x01000011
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Return the base frequency of the platform.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FREQ_BASE
value|0x01000012
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns information on the physical processor mapping within the platform.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_PHYSICAL_ID_INFO
value|0x01000013
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Update the contents of firmware blocks.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL
value|0x01000020
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FUNCTION_ID_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|EFI_SAL_MAX_SAL_FUNCTION_ID
value|0x00000021
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SAL Procedure parameter definitions
end_comment

begin_comment
comment|// Not much point in using typedefs or enums because all params
end_comment

begin_comment
comment|// are UINT64 and the entry point is common
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_SET_VECTORS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Vector type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_SET_MCA_VECTOR
value|0x0
end_define

begin_define
define|#
directive|define
name|EFI_SAL_SET_INIT_VECTOR
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_SET_BOOT_RENDEZ_VECTOR
value|0x2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format of a length_cs_n argument.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Length
range|:
literal|32
decl_stmt|;
name|UINT64
name|ChecksumValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|Reserved1
range|:
literal|7
decl_stmt|;
name|UINT64
name|ByteChecksum
range|:
literal|8
decl_stmt|;
name|UINT64
name|Reserved2
range|:
literal|16
decl_stmt|;
block|}
name|SAL_SET_VECTORS_CS_N
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_GET_STATE_INFO, EFI_SAL_GET_STATE_INFO_SIZE, and EFI_SAL_CLEAR_STATE_INFO
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Type of information
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MCA_STATE_INFO
value|0x0
end_define

begin_define
define|#
directive|define
name|EFI_SAL_INIT_STATE_INFO
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_CMC_STATE_INFO
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_SAL_CP_STATE_INFO
value|0x3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_MC_SET_PARAMS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unsigned 64-bit integer value for the parameter type of the machine check interface
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_RENDEZ_PARAM
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_WAKEUP_PARAM
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_CPE_PARAM
value|0x3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Unsigned 64-bit integer value indicating whether interrupt vector or
end_comment

begin_comment
comment|// memory address is specified
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_INTR_PARAM
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_MC_SET_MEM_PARAM
value|0x2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_REGISTER_PAL_PHYSICAL_ADDR
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The encoded value of the entity whose physical address is registered
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_REGISTER_PAL_ADDR
value|0x0
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_CACHE_FLUSH
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unsigned 64-bit integer denoting type of cache flush operation
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FLUSH_I_CACHE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FLUSH_D_CACHE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FLUSH_BOTH_CACHE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FLUSH_MAKE_COHERENT
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_PCI_CONFIG_READ and EFI_SAL_PCI_CONFIG_WRITE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PCI config size
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_PCI_CONFIG_ONE_BYTE
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_PCI_CONFIG_TWO_BYTES
value|0x2
end_define

begin_define
define|#
directive|define
name|EFI_SAL_PCI_CONFIG_FOUR_BYTES
value|0x4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The type of PCI configuration address
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_PCI_COMPATIBLE_ADDRESS
value|0x0
end_define

begin_define
define|#
directive|define
name|EFI_SAL_PCI_EXTENDED_REGISTER_ADDRESS
value|0x1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format of PCI Compatible Address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Register
range|:
literal|8
decl_stmt|;
name|UINT64
name|Function
range|:
literal|3
decl_stmt|;
name|UINT64
name|Device
range|:
literal|5
decl_stmt|;
name|UINT64
name|Bus
range|:
literal|8
decl_stmt|;
name|UINT64
name|Segment
range|:
literal|8
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|32
decl_stmt|;
block|}
name|SAL_PCI_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The format of Extended Register Address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Register
range|:
literal|8
decl_stmt|;
name|UINT64
name|ExtendedRegister
range|:
literal|4
decl_stmt|;
name|UINT64
name|Function
range|:
literal|3
decl_stmt|;
name|UINT64
name|Device
range|:
literal|5
decl_stmt|;
name|UINT64
name|Bus
range|:
literal|8
decl_stmt|;
name|UINT64
name|Segment
range|:
literal|16
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|20
decl_stmt|;
block|}
name|SAL_PCI_EXTENDED_REGISTER_ADDRESS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter of EFI_SAL_FREQ_BASE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Unsigned 64-bit integer specifying the type of clock source
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_CPU_INPUT_FREQ_BASE
value|0x0
end_define

begin_define
define|#
directive|define
name|EFI_SAL_PLATFORM_IT_FREQ_BASE
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_PLATFORM_RTC_FREQ_BASE
value|0x2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Parameter and return value of EFI_SAL_UPDATE_PAL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Return parameter provides additional information on the
end_comment

begin_comment
comment|// failure when the status field contains a value of -3,
end_comment

begin_comment
comment|// returned in r9.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_BAD_PAL_VERSION
value|((UINT64) -1)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_AUTH_FAIL
value|((UINT64) -2)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_BAD_TYPE
value|((UINT64) -3)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_READONLY
value|((UINT64) -4)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_WRITE_FAIL
value|((UINT64) -10)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_ERASE_FAIL
value|((UINT64) -11)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_READ_FAIL
value|((UINT64) -12)
end_define

begin_define
define|#
directive|define
name|EFI_SAL_UPDATE_PAL_CANT_FIT
value|((UINT64) -13)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 64-byte header of update data block.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Size
decl_stmt|;
name|UINT32
name|MmddyyyyDate
decl_stmt|;
name|UINT16
name|Version
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
name|UINT64
name|FwVendorId
decl_stmt|;
name|UINT8
name|Reserved2
index|[
literal|40
index|]
decl_stmt|;
block|}
name|SAL_UPDATE_PAL_DATA_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Data structure pointed by the parameter param_buf.
end_comment

begin_comment
comment|/// It is a 16-byte aligned data structure in memory with a length of 32 bytes
end_comment

begin_comment
comment|/// that describes the new firmware. This information is organized in the form
end_comment

begin_comment
comment|/// of a linked list with each element describing one firmware component.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SAL_UPDATE_PAL_INFO_BLOCK
block|{
name|struct
name|_SAL_UPDATE_PAL_INFO_BLOCK
modifier|*
name|Next
decl_stmt|;
name|struct
name|SAL_UPDATE_PAL_DATA_BLOCK
modifier|*
name|DataBlock
decl_stmt|;
name|UINT8
name|StoreChecksum
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|15
index|]
decl_stmt|;
block|}
name|SAL_UPDATE_PAL_INFO_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SAL System Table Definitions.
end_comment

begin_comment
comment|///
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The ASCII string representation of "SST_" that confirms the presence of the table.
comment|///
name|UINT32
name|Signature
decl_stmt|;
comment|///
comment|/// The length of the entire table in bytes, starting from offset zero and including the
comment|/// header and all entries indicated by the EntryCount field.
comment|///
name|UINT32
name|Length
decl_stmt|;
comment|///
comment|/// The revision number of the Itanium Processor Family System Abstraction Layer
comment|/// Specification supported by the SAL implementation, in binary coded decimal (BCD) format.
comment|///
name|UINT16
name|SalRevision
decl_stmt|;
comment|///
comment|/// The number of entries in the variable portion of the table.
comment|///
name|UINT16
name|EntryCount
decl_stmt|;
comment|///
comment|/// A modulo checksum of the entire table and the entries following this table.
comment|///
name|UINT8
name|CheckSum
decl_stmt|;
comment|///
comment|/// Unused, must be zero.
comment|///
name|UINT8
name|Reserved
index|[
literal|7
index|]
decl_stmt|;
comment|///
comment|/// Version Number of the SAL_A firmware implementation in BCD format.
comment|///
name|UINT16
name|SalAVersion
decl_stmt|;
comment|///
comment|/// Version Number of the SAL_B firmware implementation in BCD format.
comment|///
name|UINT16
name|SalBVersion
decl_stmt|;
comment|///
comment|/// An ASCII identification string which uniquely identifies the manufacturer
comment|/// of the system hardware.
comment|///
name|UINT8
name|OemId
index|[
literal|32
index|]
decl_stmt|;
comment|///
comment|/// An ASCII identification string which uniquely identifies a family of
comment|/// compatible products from the manufacturer.
comment|///
name|UINT8
name|ProductId
index|[
literal|32
index|]
decl_stmt|;
comment|///
comment|/// Unused, must be zero.
comment|///
name|UINT8
name|Reserved2
index|[
literal|8
index|]
decl_stmt|;
block|}
name|SAL_SYSTEM_TABLE_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SAL_ST_HEADER_SIGNATURE
value|"SST_"
end_define

begin_define
define|#
directive|define
name|EFI_SAL_REVISION
value|0x0320
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SAL System Types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_ST_ENTRY_POINT
value|0
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_MEMORY_DESCRIPTOR
value|1
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_PLATFORM_FEATURES
value|2
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_TR_USAGE
value|3
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_PTC
value|4
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_AP_WAKEUP
value|5
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// SAL System Type Sizes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_ST_ENTRY_POINT_SIZE
value|48
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_MEMORY_DESCRIPTOR_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_PLATFORM_FEATURES_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_TR_USAGE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_PTC_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_AP_WAKEUP_SIZE
value|16
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Entrypoint Descriptor Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Type here should be 0.
name|UINT8
name|Reserved
index|[
literal|7
index|]
decl_stmt|;
name|UINT64
name|PalProcEntry
decl_stmt|;
name|UINT64
name|SalProcEntry
decl_stmt|;
name|UINT64
name|SalGlobalDataPointer
decl_stmt|;
name|UINT64
name|Reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SAL_ST_ENTRY_POINT_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Platform Features Descriptor Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Type here should be 2.
name|UINT8
name|PlatformFeatures
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
name|SAL_ST_PLATFORM_FEATURES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of Platform Feature List
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SAL_PLAT_FEAT_BUS_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|SAL_PLAT_FEAT_PLAT_IPI_HINT
value|0x02
end_define

begin_define
define|#
directive|define
name|SAL_PLAT_FEAT_PROC_IPI_HINT
value|0x04
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Translation Register Descriptor Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Type here should be 3.
name|UINT8
name|TRType
decl_stmt|;
name|UINT8
name|TRNumber
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
name|UINT64
name|VirtualAddress
decl_stmt|;
name|UINT64
name|EncodedPageSize
decl_stmt|;
name|UINT64
name|Reserved1
decl_stmt|;
block|}
name|SAL_ST_TR_DECRIPTOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Type of Translation Register
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_ST_TR_USAGE_INSTRUCTION
value|00
end_define

begin_define
define|#
directive|define
name|EFI_SAL_ST_TR_USAGE_DATA
value|01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Coherence Domain Information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|NumberOfProcessors
decl_stmt|;
name|UINT64
name|LocalIDRegister
decl_stmt|;
block|}
name|SAL_COHERENCE_DOMAIN_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Purge Translation Cache Coherence Domain Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Type here should be 4.
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
name|UINT32
name|NumberOfDomains
decl_stmt|;
name|SAL_COHERENCE_DOMAIN_INFO
modifier|*
name|DomainInformation
decl_stmt|;
block|}
name|SAL_ST_CACHE_COHERENCE_DECRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Application Processor Wake-Up Descriptor Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Type here should be 5.
name|UINT8
name|WakeUpType
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|ExternalInterruptVector
decl_stmt|;
block|}
name|SAL_ST_AP_WAKEUP_DECRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of Firmware Interface Table (FIT) Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Address
decl_stmt|;
name|UINT8
name|Size
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|Type
range|:
literal|7
decl_stmt|;
name|UINT8
name|CheckSumValid
range|:
literal|1
decl_stmt|;
name|UINT8
name|CheckSum
decl_stmt|;
block|}
name|EFI_SAL_FIT_ENTRY
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// FIT Types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_FIT_HEADER_TYPE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PAL_B_TYPE
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Type from 0x02 to 0x0D is reserved.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PROCESSOR_SPECIFIC_PAL_A_TYPE
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PAL_A_TYPE
value|0x0F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// OEM-defined type range is from 0x10 to 0x7E.
end_comment

begin_comment
comment|// Here we defined the PEI_CORE type as 0x10
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PEI_CORE_TYPE
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_SAL_FIT_UNUSED_TYPE
value|0x7F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// FIT Entry
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_ENTRY_PTR
value|(0x100000000 - 32)
end_define

begin_comment
comment|// 4GB - 24
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PALA_ENTRY
value|(0x100000000 - 48)
end_define

begin_comment
comment|// 4GB - 32
end_comment

begin_define
define|#
directive|define
name|EFI_SAL_FIT_PALB_TYPE
value|01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Following definitions are for Error Record Structure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of TimeStamp field in Record Header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Seconds
decl_stmt|;
name|UINT8
name|Minutes
decl_stmt|;
name|UINT8
name|Hours
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Year
decl_stmt|;
name|UINT8
name|Century
decl_stmt|;
block|}
name|SAL_TIME_STAMP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Record Header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|RecordId
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|ErrorSeverity
decl_stmt|;
name|UINT8
name|ValidationBits
decl_stmt|;
name|UINT32
name|RecordLength
decl_stmt|;
name|SAL_TIME_STAMP
name|TimeStamp
decl_stmt|;
name|UINT8
name|OemPlatformId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|SAL_RECORD_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Section Header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|GUID
name|Guid
decl_stmt|;
name|UINT16
name|Revision
decl_stmt|;
name|UINT8
name|ErrorRecoveryInfo
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|SectionLength
decl_stmt|;
block|}
name|SAL_SEC_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Processor Machine Check Errors.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_PROCESSOR_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf1, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for valid bits of MOD_ERROR_INFO
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CHECK_INFO_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|REQUESTOR_ID_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|RESPONDER_ID_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|TARGER_ID_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|PRECISE_IP_VALID_BIT_MASK
value|0x10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of MOD_ERROR_INFO_STRUCT.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|InfoValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|ReqValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|RespValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|TargetValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|IpValid
range|:
literal|1
decl_stmt|;
name|UINT64
name|Reserved
range|:
literal|59
decl_stmt|;
name|UINT64
name|Info
decl_stmt|;
name|UINT64
name|Req
decl_stmt|;
name|UINT64
name|Resp
decl_stmt|;
name|UINT64
name|Target
decl_stmt|;
name|UINT64
name|Ip
decl_stmt|;
block|}
name|MOD_ERROR_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of CPUID_INFO_STRUCT.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CpuidInfo
index|[
literal|40
index|]
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|CPUID_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|FrLow
decl_stmt|;
name|UINT64
name|FrHigh
decl_stmt|;
block|}
name|FR_STRUCT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for PSI_STATIC_STRUCT.ValidFieldBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MIN_STATE_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|BR_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|CR_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|AR_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|RR_VALID_BIT_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|FR_VALID_BIT_MASK
value|0x20
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of PSI_STATIC_STRUCT.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|ValidFieldBits
decl_stmt|;
name|UINT8
name|MinStateInfo
index|[
literal|1024
index|]
decl_stmt|;
name|UINT64
name|Br
index|[
literal|8
index|]
decl_stmt|;
name|UINT64
name|Cr
index|[
literal|128
index|]
decl_stmt|;
name|UINT64
name|Ar
index|[
literal|128
index|]
decl_stmt|;
name|UINT64
name|Rr
index|[
literal|8
index|]
decl_stmt|;
name|FR_STRUCT
name|Fr
index|[
literal|128
index|]
decl_stmt|;
block|}
name|PSI_STATIC_STRUCT
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_PROCESSOR_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PROC_ERROR_MAP_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|PROC_STATE_PARAMETER_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|PROC_CR_LID_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|PROC_STATIC_STRUCT_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|CPU_INFO_VALID_BIT_MASK
value|0x1000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Processor Machine Check Error Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT64
name|ProcErrorMap
decl_stmt|;
name|UINT64
name|ProcStateParameter
decl_stmt|;
name|UINT64
name|ProcCrLid
decl_stmt|;
name|MOD_ERROR_INFO
name|CacheError
index|[
literal|15
index|]
decl_stmt|;
name|MOD_ERROR_INFO
name|TlbError
index|[
literal|15
index|]
decl_stmt|;
name|MOD_ERROR_INFO
name|BusError
index|[
literal|15
index|]
decl_stmt|;
name|MOD_ERROR_INFO
name|RegFileCheck
index|[
literal|15
index|]
decl_stmt|;
name|MOD_ERROR_INFO
name|MsCheck
index|[
literal|15
index|]
decl_stmt|;
name|CPUID_INFO
name|CpuInfo
decl_stmt|;
name|PSI_STATIC_STRUCT
name|PsiValidData
decl_stmt|;
block|}
name|SAL_PROCESSOR_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Platform Memory Device Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_MEMORY_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf2, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_MEMORY_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MEMORY_ERROR_STATUS_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|MEMORY_PHYSICAL_ADDRESS_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|MEMORY_ADDR_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|MEMORY_NODE_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|MEMORY_CARD_VALID_BIT_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|MEMORY_MODULE_VALID_BIT_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|MEMORY_BANK_VALID_BIT_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|MEMORY_DEVICE_VALID_BIT_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|MEMORY_ROW_VALID_BIT_MASK
value|0x100
end_define

begin_define
define|#
directive|define
name|MEMORY_COLUMN_VALID_BIT_MASK
value|0x200
end_define

begin_define
define|#
directive|define
name|MEMORY_BIT_POSITION_VALID_BIT_MASK
value|0x400
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_REQUESTOR_ID_VALID_BIT_MASK
value|0x800
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_RESPONDER_ID_VALID_BIT_MASK
value|0x1000
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_TARGET_VALID_BIT_MASK
value|0x2000
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_BUS_SPECIFIC_DATA_VALID_BIT_MASK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_OEM_ID_VALID_BIT_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|MEMORY_PLATFORM_OEM_DATA_STRUCT_VALID_BIT_MASK
value|0x10000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform Memory Device Error Info Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT64
name|MemErrorStatus
decl_stmt|;
name|UINT64
name|MemPhysicalAddress
decl_stmt|;
name|UINT64
name|MemPhysicalAddressMask
decl_stmt|;
name|UINT16
name|MemNode
decl_stmt|;
name|UINT16
name|MemCard
decl_stmt|;
name|UINT16
name|MemModule
decl_stmt|;
name|UINT16
name|MemBank
decl_stmt|;
name|UINT16
name|MemDevice
decl_stmt|;
name|UINT16
name|MemRow
decl_stmt|;
name|UINT16
name|MemColumn
decl_stmt|;
name|UINT16
name|MemBitPosition
decl_stmt|;
name|UINT64
name|ModRequestorId
decl_stmt|;
name|UINT64
name|ModResponderId
decl_stmt|;
name|UINT64
name|ModTargetId
decl_stmt|;
name|UINT64
name|BusSpecificData
decl_stmt|;
name|UINT8
name|MemPlatformOemId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|SAL_MEMORY_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Platform PCI Bus Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_PCI_BUS_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf4, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_PCI_BUS_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PCI_BUS_ERROR_STATUS_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|PCI_BUS_ERROR_TYPE_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|PCI_BUS_ID_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|PCI_BUS_ADDRESS_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|PCI_BUS_DATA_VALID_BIT_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_BUS_CMD_VALID_BIT_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_BUS_REQUESTOR_ID_VALID_BIT_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_BUS_RESPONDER_ID_VALID_BIT_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_BUS_TARGET_VALID_BIT_MASK
value|0x100
end_define

begin_define
define|#
directive|define
name|PCI_BUS_OEM_ID_VALID_BIT_MASK
value|0x200
end_define

begin_define
define|#
directive|define
name|PCI_BUS_OEM_DATA_STRUCT_VALID_BIT_MASK
value|0x400
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Designated PCI Bus identifier.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BusNumber
decl_stmt|;
name|UINT8
name|SegmentNumber
decl_stmt|;
block|}
name|PCI_BUS_ID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform PCI Bus Error Info Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT64
name|PciBusErrorStatus
decl_stmt|;
name|UINT16
name|PciBusErrorType
decl_stmt|;
name|PCI_BUS_ID
name|PciBusId
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
name|UINT64
name|PciBusAddress
decl_stmt|;
name|UINT64
name|PciBusData
decl_stmt|;
name|UINT64
name|PciBusCommand
decl_stmt|;
name|UINT64
name|PciBusRequestorId
decl_stmt|;
name|UINT64
name|PciBusResponderId
decl_stmt|;
name|UINT64
name|PciBusTargetId
decl_stmt|;
name|UINT8
name|PciBusOemId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|SAL_PCI_BUS_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Platform PCI Component Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_PCI_COMP_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf6, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_PCI_COMPONENT_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PCI_COMP_ERROR_STATUS_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|PCI_COMP_INFO_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|PCI_COMP_MEM_NUM_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|PCI_COMP_IO_NUM_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|PCI_COMP_REG_DATA_PAIR_VALID_BIT_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_COMP_OEM_DATA_STRUCT_VALID_BIT_MASK
value|0x20
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Format of PCI Component Information to identify the device.
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
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT8
name|FunctionNumber
decl_stmt|;
name|UINT8
name|DeviceNumber
decl_stmt|;
name|UINT8
name|BusNumber
decl_stmt|;
name|UINT8
name|SegmentNumber
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
name|PCI_COMP_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform PCI Component Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT64
name|PciComponentErrorStatus
decl_stmt|;
name|PCI_COMP_INFO
name|PciComponentInfo
decl_stmt|;
name|UINT32
name|PciComponentMemNum
decl_stmt|;
name|UINT32
name|PciComponentIoNum
decl_stmt|;
name|UINT8
name|PciBusOemId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|SAL_PCI_COMPONENT_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Platform SEL Device Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_SEL_DEVICE_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf3, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_SEL_DEVICE_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SEL_RECORD_ID_VALID_BIT_MASK
value|0x1;
end_define

begin_define
define|#
directive|define
name|SEL_RECORD_TYPE_VALID_BIT_MASK
value|0x2;
end_define

begin_define
define|#
directive|define
name|SEL_GENERATOR_ID_VALID_BIT_MASK
value|0x4;
end_define

begin_define
define|#
directive|define
name|SEL_EVM_REV_VALID_BIT_MASK
value|0x8;
end_define

begin_define
define|#
directive|define
name|SEL_SENSOR_TYPE_VALID_BIT_MASK
value|0x10;
end_define

begin_define
define|#
directive|define
name|SEL_SENSOR_NUM_VALID_BIT_MASK
value|0x20;
end_define

begin_define
define|#
directive|define
name|SEL_EVENT_DIR_TYPE_VALID_BIT_MASK
value|0x40;
end_define

begin_define
define|#
directive|define
name|SEL_EVENT_DATA1_VALID_BIT_MASK
value|0x80;
end_define

begin_define
define|#
directive|define
name|SEL_EVENT_DATA2_VALID_BIT_MASK
value|0x100;
end_define

begin_define
define|#
directive|define
name|SEL_EVENT_DATA3_VALID_BIT_MASK
value|0x200;
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform SEL Device Error Info Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT16
name|SelRecordId
decl_stmt|;
name|UINT8
name|SelRecordType
decl_stmt|;
name|UINT32
name|TimeStamp
decl_stmt|;
name|UINT16
name|GeneratorId
decl_stmt|;
name|UINT8
name|EvmRevision
decl_stmt|;
name|UINT8
name|SensorType
decl_stmt|;
name|UINT8
name|SensorNum
decl_stmt|;
name|UINT8
name|EventDirType
decl_stmt|;
name|UINT8
name|Data1
decl_stmt|;
name|UINT8
name|Data2
decl_stmt|;
name|UINT8
name|Data3
decl_stmt|;
block|}
name|SAL_SEL_DEVICE_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Platform SMBIOS Device Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_SMBIOS_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf5, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_SMBIOS_DEVICE_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SMBIOS_EVENT_TYPE_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|SMBIOS_LENGTH_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|SMBIOS_TIME_STAMP_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|SMBIOS_DATA_VALID_BIT_MASK
value|0x8
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform SMBIOS Device Error Info Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT8
name|SmbiosEventType
decl_stmt|;
name|UINT8
name|SmbiosLength
decl_stmt|;
name|UINT8
name|SmbiosBcdTimeStamp
index|[
literal|6
index|]
decl_stmt|;
block|}
name|SAL_SMBIOS_DEVICE_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GUID of Platform Specific Error Info.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SAL_PLATFORM_ERROR_RECORD_INFO
define|\
value|{ \     0xe429faf7, 0x3cb7, 0x11d4, {0xbc, 0xa7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit masks for SAL_PLATFORM_SPECIFIC_ERROR_RECORD.ValidationBits
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PLATFORM_ERROR_STATUS_VALID_BIT_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|PLATFORM_REQUESTOR_ID_VALID_BIT_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|PLATFORM_RESPONDER_ID_VALID_BIT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|PLATFORM_TARGET_VALID_BIT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|PLATFORM_SPECIFIC_DATA_VALID_BIT_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PLATFORM_OEM_ID_VALID_BIT_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|PLATFORM_OEM_DATA_STRUCT_VALID_BIT_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|PLATFORM_OEM_DEVICE_PATH_VALID_BIT_MASK
value|0x80
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of Platform Specific Error Info Record.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SAL_SEC_HEADER
name|SectionHeader
decl_stmt|;
name|UINT64
name|ValidationBits
decl_stmt|;
name|UINT64
name|PlatformErrorStatus
decl_stmt|;
name|UINT64
name|PlatformRequestorId
decl_stmt|;
name|UINT64
name|PlatformResponderId
decl_stmt|;
name|UINT64
name|PlatformTargetId
decl_stmt|;
name|UINT64
name|PlatformBusSpecificData
decl_stmt|;
name|UINT8
name|OemComponentId
index|[
literal|16
index|]
decl_stmt|;
block|}
name|SAL_PLATFORM_SPECIFIC_ERROR_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Union of all the possible SAL Error Record Types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|SAL_RECORD_HEADER
modifier|*
name|RecordHeader
decl_stmt|;
name|SAL_PROCESSOR_ERROR_RECORD
modifier|*
name|SalProcessorRecord
decl_stmt|;
name|SAL_PCI_BUS_ERROR_RECORD
modifier|*
name|SalPciBusRecord
decl_stmt|;
name|SAL_PCI_COMPONENT_ERROR_RECORD
modifier|*
name|SalPciComponentRecord
decl_stmt|;
name|SAL_SEL_DEVICE_ERROR_RECORD
modifier|*
name|ImpiRecord
decl_stmt|;
name|SAL_SMBIOS_DEVICE_ERROR_RECORD
modifier|*
name|SmbiosRecord
decl_stmt|;
name|SAL_PLATFORM_SPECIFIC_ERROR_RECORD
modifier|*
name|PlatformRecord
decl_stmt|;
name|SAL_MEMORY_ERROR_RECORD
modifier|*
name|MemoryRecord
decl_stmt|;
name|UINT8
modifier|*
name|Raw
decl_stmt|;
block|}
name|SAL_ERROR_RECORDS_POINTERS
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

