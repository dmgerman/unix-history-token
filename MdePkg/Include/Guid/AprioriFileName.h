begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The GUID PEI_APRIORI_FILE_NAME_GUID definition is the file   name of the PEI a priori file that is stored in a firmware   volume.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_APRIORI_FILE_NAME_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_APRIORI_FILE_NAME_H__
end_define

begin_define
define|#
directive|define
name|PEI_APRIORI_FILE_NAME_GUID
define|\
value|{ 0x1b45cc0a, 0x156a, 0x428a, { 0x62, 0XAF, 0x49, 0x86, 0x4d, 0xa0, 0xe6, 0xe6 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|///  This file must be of type EFI_FV_FILETYPE_FREEFORM and must
end_comment

begin_comment
comment|///  contain a single section of type EFI_SECTION_RAW. For details on
end_comment

begin_comment
comment|///  firmware volumes, firmware file types, and firmware file section
end_comment

begin_comment
comment|///  types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// An array of zero or more EFI_GUID type entries that match the file names of PEIM
comment|/// modules in the same Firmware Volume. The maximum number of entries.
comment|///
name|EFI_GUID
name|FileNamesWithinVolume
index|[
literal|1
index|]
decl_stmt|;
block|}
name|PEI_APRIORI_FILE_CONTENTS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gPeiAprioriFileNameGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

