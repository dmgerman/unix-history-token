begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID used for MemoryOverwriteRequestControl UEFI variable defined in    TCG Platform Reset Attack Mitigation Specification 1.00.   See http://trustedcomputinggroup.org for the latest specification    The purpose of the MemoryOverwriteRequestControl UEFI variable is to give users (e.g., OS, loader) the ability to    indicate to the platform that secrets are present in memory and that the platform firmware must clear memory upon    a restart. The OS loader should not create the variable. Rather, the  firmware is required to create it.     Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEMORY_OVERWRITE_CONTROL_DATA_GUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEMORY_OVERWRITE_CONTROL_DATA_GUID_H_
end_define

begin_define
define|#
directive|define
name|MEMORY_ONLY_RESET_CONTROL_GUID
define|\
value|{ \     0xe20939be, 0x32d4, 0x41be, {0xa1, 0x50, 0x89, 0x7f, 0x85, 0xd4, 0x98, 0x29} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|///  Variable name is "MemoryOverwriteRequestControl" and it is a 1 byte unsigned value.
end_comment

begin_comment
comment|///  The attributes should be:
end_comment

begin_comment
comment|///  EFI_VARIABLE_NON_VOLATILE |
end_comment

begin_comment
comment|///  EFI_VARIABLE_BOOTSERVICE_ACCESS |
end_comment

begin_comment
comment|///  EFI_VARIABLE_RUNTIME_ACCESS
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MEMORY_OVERWRITE_REQUEST_VARIABLE_NAME
value|L"MemoryOverwriteRequestControl"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 0 = Firmware MUST clear the MOR bi
end_comment

begin_comment
comment|/// 1 = Firmware MUST set the MOR bit
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MOR_CLEAR_MEMORY_BIT_MASK
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// 0 = Firmware MAY autodetect a clean shutdown of the Static RTM OS.
end_comment

begin_comment
comment|/// 1 = Firmware MUST NOT autodetect a clean shutdown of the Static RTM OS.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MOR_DISABLEAUTODETECT_BIT_MASK
value|0x10
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// MOR field bit offset
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MOR_CLEAR_MEMORY_BIT_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|MOR_DISABLEAUTODETECT_BIT_OFFSET
value|4
end_define

begin_comment
comment|/**   Return the ClearMemory bit value 0 or 1.    @param mor   1 byte value that contains ClearMemory and DisableAutoDetect bit.    @return ClearMemory bit value **/
end_comment

begin_define
define|#
directive|define
name|MOR_CLEAR_MEMORY_VALUE
parameter_list|(
name|mor
parameter_list|)
value|(((UINT8)(mor)& MOR_CLEAR_MEMORY_BIT_MASK)>> MOR_CLEAR_MEMORY_BIT_OFFSET)
end_define

begin_comment
comment|/**   Return the DisableAutoDetect bit value 0 or 1.    @param mor   1 byte value that contains ClearMemory and DisableAutoDetect bit.    @return DisableAutoDetect bit value **/
end_comment

begin_define
define|#
directive|define
name|MOR_DISABLE_AUTO_DETECT_VALUE
parameter_list|(
name|mor
parameter_list|)
value|(((UINT8)(mor)& MOR_DISABLEAUTODETECT_BIT_MASK)>> MOR_DISABLEAUTODETECT_BIT_OFFSET)
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMemoryOverwriteControlDataGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

