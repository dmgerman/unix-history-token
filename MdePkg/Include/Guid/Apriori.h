begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID used as an FV filename for A Priori file. The A Priori file contains a   list of FV filenames that the DXE dispatcher will schedule reguardless of   the dependency grammar.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__APRIORI_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__APRIORI_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_APRIORI_GUID
define|\
value|{ \     0xfc510ee7, 0xffdc, 0x11d4, {0xbd, 0x41, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gAprioriGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

