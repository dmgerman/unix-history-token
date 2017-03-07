begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID for system configuration table entry that points to the table   in case an entity in DXE wishes to update/change the vector table contents.     Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID defined in PI 1.2.1 spec. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_VECTOR_HANDOFF_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_VECTOR_HANDOFF_TABLE_H__
end_define

begin_include
include|#
directive|include
file|<Ppi/VectorHandoffInfo.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// System configuration table entry that points to the table
end_comment

begin_comment
comment|// in case an entity in DXE wishes to update/change the vector
end_comment

begin_comment
comment|// table contents.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_VECTOR_HANDOF_TABLE_GUID
define|\
value|{ 0x996ec11c, 0x5397, 0x4e73, { 0xb5, 0x8f, 0x82, 0x7e, 0x52, 0x90, 0x6d, 0xef }}
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVectorHandoffTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

