begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Security Policy protocol as defined in PI Specification VOLUME 2 DXE    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_POLICY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_POLICY_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Security policy protocol GUID definition
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SECURITY_POLICY_PROTOCOL_GUID
define|\
value|{0x78E4D245, 0xCD4D, 0x4a05, {0xA2, 0xBA, 0x47, 0x43, 0xE8, 0x6C, 0xFC, 0xAB} }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSecurityPolicyProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

