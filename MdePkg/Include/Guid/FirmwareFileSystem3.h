begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid used to define the Firmware File System 3.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FIRMWARE_FILE_SYSTEM3_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__FIRMWARE_FILE_SYSTEM3_GUID_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The firmware volume header contains a data field for the file system GUID
end_comment

begin_comment
comment|/// {5473C07A-3DCB-4dca-BD6F-1E9689E7349A}
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_FILE_SYSTEM3_GUID
define|\
value|{ 0x5473c07a, 0x3dcb, 0x4dca, { 0xbd, 0x6f, 0x1e, 0x96, 0x89, 0xe7, 0x34, 0x9a }}
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareFileSystem3Guid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __FIRMWARE_FILE_SYSTEM3_GUID_H__
end_comment

end_unit

