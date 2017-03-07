begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID for MdePkg PCD Token Space     Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MDEPKG_TOKEN_SPACE_GUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_MDEPKG_TOKEN_SPACE_GUID_H_
end_define

begin_define
define|#
directive|define
name|MDEPKG_TOKEN_SPACE_GUID
define|\
value|{ \     0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMdePkgTokenSpaceGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

