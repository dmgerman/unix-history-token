begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The PCI configuration Library Services that carry out PCI configuration and enable   the PCI operations to be replayed during an S3 resume. This library class   maps directly on top of the PciLib class.     Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__S3_PCI_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__S3_PCI_LIB_H__
end_define

begin_comment
comment|/**   Macro that converts PCI Bus, PCI Device, PCI Function and PCI Register to an   address that can be passed to the S3 PCI Library functions.    @param  Bus       The PCI Bus number. Range 0..255.   @param  Device    The PCI Device number. Range 0..31.   @param  Function  The PCI Function number. Range 0..7.   @param  Register  The PCI Register number. Range 0..255 for PCI. Range 0..4095                     for PCI Express.    @return The encoded PCI address.  **/
end_comment

begin_define
define|#
directive|define
name|S3_PCI_LIB_ADDRESS
parameter_list|(
name|Bus
parameter_list|,
name|Device
parameter_list|,
name|Function
parameter_list|,
name|Register
parameter_list|)
define|\
value|(((Register)& 0xfff) | (((Function)& 0x07)<< 12) | (((Device)& 0x1f)<< 15) | (((Bus)& 0xff)<< 20))
end_define

begin_comment
comment|/**     Reads and returns the 8-bit PCI configuration register specified by Address,    and saves the value in the S3 script to be replayed on S3 resume.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.    @return   The value read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciRead8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes an 8-bit PCI configuration register, and saves the value in the S3   script to be replayed on S3 resume.    Writes the 8-bit PCI configuration register specified by Address with the   value specified by Value. Value is returned. This function must guarantee   that all PCI read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] Value     The value to write.    @return   The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciWrite8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of an 8-bit PCI configuration register with   an 8-bit value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 8-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized.    If Address> 0x0FFFFFFF, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] OrData    The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciOr8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of an 8-bit PCI configuration register with an 8-bit   value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 8-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().    @param[in]  Address   The address that encodes the PCI Bus, Device, Function and                         Register.   @param[in]  AndData   The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciAnd8
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT8
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of an 8-bit PCI configuration register with an 8-bit   value, followed a  bitwise OR with another 8-bit value, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and   the value specified by OrData, and writes the result to the 8-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] AndData   The value to AND with the PCI configuration register.   @param[in] OrData    The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciAndThenOr8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field of a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Reads the bit field in an 8-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If Address> 0x0FFFFFFF, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in] Address    The PCI configuration register to read.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..7.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..7.    @return   The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciBitFieldRead8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Writes a bit field to a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   8-bit register is returned.    If Address> 0x0FFFFFFF, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..7.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..7.   @param[in] Value      New value of the bit field.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciBitFieldWrite8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in an 8-bit PCI configuration, performs a bitwise OR, and   writes the result back to the bit field in the 8-bit port, and saves the value   in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 8-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized. Extra left bits in OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..7.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..7.   @param[in] OrData     The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciBitFieldOr8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in an 8-bit PCI configuration register, performs a bitwise   AND, and writes the result back to the bit field in the 8-bit register and   saves the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 8-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized. Extra left bits in AndData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..7.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..7.   @param[in] AndData    The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciBitFieldAnd8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in an 8-bit Address, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   8-bit port, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 8-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 8-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If StartBit is greater than 7, then ASSERT().   If EndBit is greater than 7, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..7.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..7.   @param[in] AndData    The value to AND with the PCI configuration register.   @param[in] OrData     The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|S3PciBitFieldAndThenOr8
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a 16-bit PCI configuration register, and saves the value in the S3   script to be replayed on S3 resume.    Reads and returns the 16-bit PCI configuration register specified by Address.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.    @return   The read value from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciRead16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 16-bit PCI configuration register, and saves the value in the S3   script to be replayed on S3 resume.    Writes the 16-bit PCI configuration register specified by Address with the   value specified by Value. Value is returned. This function must guarantee   that all PCI read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] Value     The value to write.    @return   The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciWrite16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of a 16-bit PCI configuration register with   a 16-bit value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 16-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] OrData    The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciOr16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 16-bit PCI configuration register with a 16-bit   value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 16-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] AndData   The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciAnd16
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT16
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 16-bit PCI configuration register with a 16-bit   value, followed a  bitwise OR with another 16-bit value, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and   the value specified by OrData, and writes the result to the 16-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] AndData   The value to AND with the PCI configuration register.   @param[in] OrData    The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciAndThenOr16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field of a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Reads the bit field in a 16-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().    @param[in] Address    The PCI configuration register to read.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..15.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..15.    @return   The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciBitFieldRead16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Writes a bit field to a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   16-bit register is returned.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..15.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..15.   @param[in] Value      New value of the bit field.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciBitFieldWrite16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 16-bit PCI configuration, performs a bitwise OR, and   writes the result back to the bit field in the 16-bit port, and saves the value   in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 16-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized. Extra left bits in OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..15.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..15.   @param[in] OrData     The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciBitFieldOr16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 16-bit PCI configuration register, performs a bitwise   AND, and writes the result back to the bit field in the 16-bit register and   saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 16-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized. Extra left bits in AndData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..15.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..15.   @param[in] AndData    The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciBitFieldAnd16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 16-bit Address, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   16-bit port, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 16-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 16-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 16-bit boundary, then ASSERT().   If StartBit is greater than 15, then ASSERT().   If EndBit is greater than 15, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..15.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..15.   @param[in] AndData    The value to AND with the PCI configuration register.   @param[in] OrData     The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|S3PciBitFieldAndThenOr16
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a 32-bit PCI configuration register, and saves the value in the S3   script to be replayed on S3 resume.    Reads and returns the 32-bit PCI configuration register specified by Address.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.    @return   The read value from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciRead32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Writes a 32-bit PCI configuration register, and saves the value in the S3   script to be replayed on S3 resume.    Writes the 32-bit PCI configuration register specified by Address with the   value specified by Value. Value is returned. This function must guarantee   that all PCI read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] Value     The value to write.    @return   The value written to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciWrite32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise OR of a 32-bit PCI configuration register with   a 32-bit value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 32-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] OrData    The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciOr32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|OrData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 32-bit PCI configuration register with a 32-bit   value, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 32-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] AndData   The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciAnd32
parameter_list|(
name|IN
name|UINTN
name|Address
parameter_list|,
name|IN
name|UINT32
name|AndData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Performs a bitwise AND of a 32-bit PCI configuration register with a 32-bit   value, followed a  bitwise OR with another 32-bit value, and saves   the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData,   performs a bitwise OR between the result of the AND operation and   the value specified by OrData, and writes the result to the 32-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().    @param[in] Address   The address that encodes the PCI Bus, Device, Function and                        Register.   @param[in] AndData   The value to AND with the PCI configuration register.   @param[in] OrData    The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciAndThenOr32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field of a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Reads the bit field in a 32-bit PCI configuration register. The bit field is   specified by the StartBit and the EndBit. The value of the bit field is   returned.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().     @param[in] Address    The PCI configuration register to read.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..31.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..31.    @return   The value of the bit field read from the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciBitFieldRead32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Writes a bit field to a PCI configuration register, and saves the value in   the S3 script to be replayed on S3 resume.    Writes Value to the bit field of the PCI configuration register. The bit   field is specified by the StartBit and the EndBit. All other bits in the   destination PCI configuration register are preserved. The new value of the   32-bit register is returned.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If Value is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..31.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..31.   @param[in] Value      New value of the bit field.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciBitFieldWrite32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 32-bit PCI configuration, performs a bitwise OR, and   writes the result back to the bit field in the 32-bit port, and saves the value   in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise OR between the read result and the value specified by   OrData, and writes the result to the 32-bit PCI configuration register   specified by Address. The value written to the PCI configuration register is   returned. This function must guarantee that all PCI read and write operations   are serialized. Extra left bits in OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..31.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..31.   @param[in] OrData     The value to OR with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciBitFieldOr32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 32-bit PCI configuration register, performs a bitwise   AND, and writes the result back to the bit field in the 32-bit register and   saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise AND between the read result and the value specified by AndData, and   writes the result to the 32-bit PCI configuration register specified by   Address. The value written to the PCI configuration register is returned.   This function must guarantee that all PCI read and write operations are   serialized. Extra left bits in AndData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..31.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..31.   @param[in] AndData    The value to AND with the PCI configuration register.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciBitFieldAnd32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a bit field in a 32-bit Address, performs a bitwise AND followed by a   bitwise OR, and writes the result back to the bit field in the   32-bit port, and saves the value in the S3 script to be replayed on S3 resume.    Reads the 32-bit PCI configuration register specified by Address, performs a   bitwise AND followed by a bitwise OR between the read result and   the value specified by AndData, and writes the result to the 32-bit PCI   configuration register specified by Address. The value written to the PCI   configuration register is returned. This function must guarantee that all PCI   read and write operations are serialized. Extra left bits in both AndData and   OrData are stripped.    If Address> 0x0FFFFFFF, then ASSERT().   If Address is not aligned on a 32-bit boundary, then ASSERT().   If StartBit is greater than 31, then ASSERT().   If EndBit is greater than 31, then ASSERT().   If EndBit is less than StartBit, then ASSERT().   If AndData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().   If OrData is larger than the bitmask value range specified by StartBit and EndBit, then ASSERT().    @param[in] Address    The PCI configuration register to write.   @param[in] StartBit   The ordinal of the least significant bit in the bit field.                         Range 0..31.   @param[in] EndBit     The ordinal of the most significant bit in the bit field.                         Range 0..31.   @param[in] AndData    The value to AND with the PCI configuration register.   @param[in] OrData     The value to OR with the result of the AND operation.    @return   The value written back to the PCI configuration register.  **/
end_comment

begin_function_decl
name|UINT32
name|EFIAPI
name|S3PciBitFieldAndThenOr32
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Reads a range of PCI configuration registers into a caller supplied buffer,   and saves the value in the S3 script to be replayed on S3 resume.    Reads the range of PCI configuration registers specified by StartAddress and   Size into the buffer specified by Buffer. This function only allows the PCI   configuration registers from a single PCI function to be read. Size is   returned. When possible 32-bit PCI configuration read cycles are used to read   from StartAdress to StartAddress + Size. Due to alignment restrictions, 8-bit   and 16-bit PCI configuration read cycles may be used at the beginning and the   end of the range.    If StartAddress> 0x0FFFFFFF, then ASSERT().   If ((StartAddress& 0xFFF) + Size)> 0x1000, then ASSERT().   If Size> 0 and Buffer is NULL, then ASSERT().    @param[in]  StartAddress   Starting address that encodes the PCI Bus, Device,                              Function and Register.   @param[in]  Size           Size in bytes of the transfer.   @param[out] Buffer         The pointer to a buffer receiving the data read.    @return   Size.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3PciReadBuffer
parameter_list|(
name|IN
name|UINTN
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
comment|/**   Copies the data in a caller supplied buffer to a specified range of PCI   configuration space, and saves the value in the S3 script to be replayed on S3   resume.    Writes the range of PCI configuration registers specified by StartAddress and   Size from the buffer specified by Buffer. This function only allows the PCI   configuration registers from a single PCI function to be written. Size is   returned. When possible 32-bit PCI configuration write cycles are used to   write from StartAdress to StartAddress + Size. Due to alignment restrictions,   8-bit and 16-bit PCI configuration write cycles may be used at the beginning   and the end of the range.    If StartAddress> 0x0FFFFFFF, then ASSERT().   If ((StartAddress& 0xFFF) + Size)> 0x1000, then ASSERT().   If Size> 0 and Buffer is NULL, then ASSERT().    @param[in] StartAddress   Starting address that encodes the PCI Bus, Device,                             Function and Register.   @param[in] Size           Size in bytes of the transfer.   @param[in] Buffer         The pointer to a buffer containing the data to write.    @return   Size.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3PciWriteBuffer
parameter_list|(
name|IN
name|UINTN
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

