begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to access PCI Configuration Space on a platform with multiple PCI segments.      The PCI Segment Library function provide services to read, write, and modify the PCI configuration   registers on PCI root bridges on any supported PCI segment.  These library services take a single    address parameter that encodes the PCI Segment, PCI Bus, PCI Device, PCI Function, and PCI Register.     The layout of this address parameter is as follows:                PCI Register: Bits 0..11             PCI Function  Bits 12..14             PCI Device  Bits 15..19             PCI Bus Bits 20..27             Reserved  Bits 28..31.  Must be 0.             PCI Segment Bits 32..47             Reserved  Bits 48..63.  Must be 0.                | Reserved (MBZ) | Segment | Reserved (MBZ) |     Bus     | Device | Function | Register |   63             48  47    32  31           28 27         20 19    15 14      12 11         0    These functions perform PCI configuration cycles using the default PCI configuration access    method.  This may use I/O ports 0xCF8 and 0xCFC to perform PCI configuration accesses, or it    may use MMIO registers relative to the PcdPciExpressBaseAddress, or it may use some alternate    access method.  Modules will typically use the PCI Segment Library for its PCI configuration    accesses when PCI Segments other than Segment #0 must be accessed.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_SEGMENT_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_SEGMENT_LIB__
end_define

begin_comment
comment|/**   Macro that converts PCI Segment, PCI Bus, PCI Device, PCI Function,   and PCI Register to an address that can be passed to the PCI Segment Library functions.    Computes an address that is compatible with the PCI Segment Library functions.   The unused upper bits of Segment, Bus, Device, Function,   and Register are stripped prior to the generation of the address.    @param  Segment   PCI Segment number.  Range 0..65535.   @param  Bus       PCI Bus number.  Range 0..255.   @param  Device    PCI Device number.  Range 0..31.   @param  Function  PCI Function number.  Range 0..7.   @param  Register  PCI Register number.  Range 0..255 for PCI.  Range 0..4095 for PCI Express.    @return The address that is compatible with the PCI Segment Library functions.  **/
end_comment

begin_define
define|#
directive|define
name|PCI_SEGMENT_LIB_ADDRESS
parameter_list|(
name|Segment
parameter_list|,
name|Bus
parameter_list|,
name|Device
parameter_list|,
name|Function
parameter_list|,
name|Register
parameter_list|)
define|\
value|((Segment != 0) ? \     ( ((Register)& 0xfff)                 | \       (((Function)& 0x07)<< 12)          | \       (((Device)& 0x1f)<< 15)            | \       (((Bus)& 0xff)<< 20)               | \       (LShiftU64 ((Segment)& 0xffff, 32))   \     ) :                                      \     ( ((Register)& 0xfff)                 | \       (((Function)& 0x07)<< 12)          | \       (((Device)& 0x1f)<< 15)            | \       (((Bus)& 0xff)<< 20)                 \     )                                        \   )
end_define

begin_comment
comment|/**   Register a PCI device so PCI configuration registers may be accessed after    SetVirtualAddressMap().      If any reserved bits in Address are set, then ASSERT().    @param  Address Address that encodes the PCI Bus, Device, Function and                   Register.      @retval RETURN_SUCCESS           The PCI device was registered for runtime access.   @retval RETURN_UNSUPPORTED       An attempt was made to call this function                                     after ExitBootServices().   @retval RETURN_UNSUPPORTED       The resources required to access the PCI device                                    at runtime could not be mapped.   @retval RETURN_OUT_OF_RESOURCES  There are not enough resources available to                                    complete the registration.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|PciSegmentRegisterForRuntimeAccess
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads an 8-bit PCI configuration register.    Reads and returns the 8-bit PCI configuration register specified by Address.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().      @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.    @return The 8-bit PCI configuration register specified by Address.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentRead8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit PCI configuration register.    Writes the 8-bit PCI configuration register specified by Address with the value specified by Value.   Value is returned.  This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().    @param  Address     Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  Value       The value to write.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentWrite8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of an 8-bit PCI configuration register with an 8-bit value.    Reads the 8-bit PCI configuration register specified by Address,   performs a bitwise OR between the read result and the value specified by OrData,   and writes the result to the 8-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentOr8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of an 8-bit PCI configuration register with an 8-bit value.    Reads the 8-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   and writes the result to the 8-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.   If any reserved bits in Address are set, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData   The value to AND with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentAnd8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of an 8-bit PCI configuration register with an 8-bit value,   followed a  bitwise OR with another 8-bit value.      Reads the 8-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and the value specified by OrData,   and writes the result to the 8-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData    The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentAndThenOr8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a PCI configuration register.    Reads the bit field in an 8-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   PCI configuration register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.    @return The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentBitFieldRead8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a PCI configuration register.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   8-bit register is returned.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  Value     New value of the bit field.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentBitFieldWrite8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit PCI configuration, performs a bitwise OR, and   writes the result back to the bit field in the 8-bit port.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 8-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized. Extra left bits in OrData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentBitFieldOr8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit PCI configuration register, performs a bitwise   AND, and writes the result back to the bit field in the 8-bit register.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 8-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized. Extra left bits in AndData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentBitFieldAnd8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in an 8-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   8-bit port.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 8-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..7.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..7.   @param  AndData   The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|PciSegmentBitFieldAndThenOr8
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 16-bit PCI configuration register.    Reads and returns the 16-bit PCI configuration register specified by Address.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().      @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.    @return The 16-bit PCI configuration register specified by Address.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentRead16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit PCI configuration register.    Writes the 16-bit PCI configuration register specified by Address with the value specified by Value.   Value is returned.  This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address     Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  Value       The value to write.    @return The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentWrite16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of a 16-bit PCI configuration register with   a 16-bit value.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 16-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized.    If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address Address that encodes the PCI Segment, Bus, Device, Function and                   Register.   @param  OrData  The value to OR with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentOr16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 16-bit PCI configuration register with a 16-bit value.    Reads the 16-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   and writes the result to the 16-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().      @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData   The value to AND with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentAnd16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 16-bit PCI configuration register with a 16-bit value,   followed a  bitwise OR with another 16-bit value.      Reads the 16-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and the value specified by OrData,   and writes the result to the 16-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData    The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentAndThenOr16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a PCI configuration register.    Reads the bit field in a 16-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   PCI configuration register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.    @return The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentBitFieldRead16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a PCI configuration register.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   16-bit register is returned.    If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  Value     New value of the bit field.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentBitFieldWrite16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads the 16-bit PCI configuration register specified by Address,   performs a bitwise OR between the read result and the value specified by OrData,   and writes the result to the 16-bit PCI configuration register specified by Address.     If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentBitFieldOr16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit PCI configuration, performs a bitwise OR,   and writes the result back to the bit field in the 16-bit port.    Reads the 16-bit PCI configuration register specified by Address,   performs a bitwise OR between the read result and the value specified by OrData,   and writes the result to the 16-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.   Extra left bits in OrData are stripped.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     The ordinal of the least significant bit in a byte is bit 0.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     The ordinal of the most significant bit in a byte is bit 7.   @param  AndData   The value to AND with the read value from the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentBitFieldAnd16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 16-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   16-bit port.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 16-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..15.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..15.   @param  AndData   The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|PciSegmentBitFieldAndThenOr16
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a 32-bit PCI configuration register.    Reads and returns the 32-bit PCI configuration register specified by Address.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.    @return The 32-bit PCI configuration register specified by Address.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentRead32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit PCI configuration register.    Writes the 32-bit PCI configuration register specified by Address with the value specified by Value.   Value is returned.  This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address     Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  Value       The value to write.    @return The parameter of Value.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentWrite32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of a 32-bit PCI configuration register with a 32-bit value.    Reads the 32-bit PCI configuration register specified by Address,   performs a bitwise OR between the read result and the value specified by OrData,   and writes the result to the 32-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentOr32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 32-bit PCI configuration register with a 32-bit value.    Reads the 32-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   and writes the result to the 32-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData   The value to AND with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentAnd32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 32-bit PCI configuration register with a 32-bit value,   followed a  bitwise OR with another 32-bit value.      Reads the 32-bit PCI configuration register specified by Address,   performs a bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and the value specified by OrData,   and writes the result to the 32-bit PCI configuration register specified by Address.   The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are serialized.      If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param  Address   Address that encodes the PCI Segment, Bus, Device, Function, and Register.   @param  AndData   The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentAndThenOr32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field of a PCI configuration register.    Reads the bit field in a 32-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param  Address   PCI configuration register to read.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.    @return The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentBitFieldRead32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a bit field to a PCI configuration register.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   32-bit register is returned.    If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  Value     New value of the bit field.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentBitFieldWrite32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit PCI configuration, performs a bitwise OR, and   writes the result back to the bit field in the 32-bit port.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 32-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized. Extra left bits in OrData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  OrData    The value to OR with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentBitFieldOr32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit PCI configuration register, performs a bitwise   AND, and writes the result back to the bit field in the 32-bit register.       Reads the 32-bit PCI configuration register specified by Address, performs a bitwise   AND between the read result and the value specified by AndData, and writes the result   to the 32-bit PCI configuration register specified by Address. The value written to   the PCI configuration register is returned.  This function must guarantee that all PCI   read and write operations are serialized.  Extra left bits in AndData are stripped.   If any reserved bits in Address are set, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the PCI configuration register.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentBitFieldAnd32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a bit field in a 32-bit port, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   32-bit port.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 32-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If any reserved bits in Address are set, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param  Address   PCI configuration register to write.   @param  StartBit  The ordinal of the least significant bit in the bit field.                     Range 0..31.   @param  EndBit    The ordinal of the most significant bit in the bit field.                     Range 0..31.   @param  AndData   The value to AND with the PCI configuration register.   @param  OrData    The value to OR with the result of the AND operation.    @return The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|PciSegmentBitFieldAndThenOr32
parameter_list|(
name|IN
name|UINT64
name|Address
parameter_list|,
name|IN
name|UINTN
name|StartBit
parameter_list|,
name|IN
name|UINTN
name|EndBit
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads a range of PCI configuration registers into a caller supplied buffer.    Reads the range of PCI configuration registers specified by StartAddress and   Size into the buffer specified by Buffer. This function only allows the PCI   configuration registers from a single PCI function to be read. Size is   returned. When possible 32-bit PCI configuration read cycles are used to read   from StartAdress to StartAddress + Size. Due to alignment restrictions, 8-bit   and 16-bit PCI configuration read cycles may be used at the beginning and the   end of the range.    If any reserved bits in StartAddress are set, then ASSERT().   If ((StartAddress& 0xFFF) + Size)> 0x1000, then ASSERT().   If Size> 0 and Buffer is NULL, then ASSERT().    @param  StartAddress  Starting address that encodes the PCI Segment, Bus, Device,                         Function and Register.   @param  Size          Size in bytes of the transfer.   @param  Buffer        Pointer to a buffer receiving the data read.    @return Size  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|PciSegmentReadBuffer
parameter_list|(
name|IN
name|UINT64
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Copies the data in a caller supplied buffer to a specified range of PCI   configuration space.    Writes the range of PCI configuration registers specified by StartAddress and   Size from the buffer specified by Buffer. This function only allows the PCI   configuration registers from a single PCI function to be written. Size is   returned. When possible 32-bit PCI configuration write cycles are used to   write from StartAdress to StartAddress + Size. Due to alignment restrictions,   8-bit and 16-bit PCI configuration write cycles may be used at the beginning   and the end of the range.    If any reserved bits in StartAddress are set, then ASSERT().   If ((StartAddress& 0xFFF) + Size)> 0x1000, then ASSERT().   If Size> 0 and Buffer is NULL, then ASSERT().    @param  StartAddress  Starting address that encodes the PCI Segment, Bus, Device,                         Function and Register.   @param  Size          Size in bytes of the transfer.   @param  Buffer        Pointer to a buffer containing the data to write.    @return The parameter of Size.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|PciSegmentWriteBuffer
parameter_list|(
name|IN
name|UINT64
name|StartAddress
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

