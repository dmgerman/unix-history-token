begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM End Of Dxe protocol introduced in the PI 1.2.1 specification.    According to PI 1.4a specification, this protocol indicates end of the   execution phase when all of the components are under the authority of   the platform manufacturer.   This protocol is a mandatory protocol published by SMM Foundation code.   This protocol is an SMM counterpart of the End of DXE Event.   This protocol prorogates End of DXE notification into SMM environment.   This protocol is installed prior to installation of the SMM Ready to Lock Protocol.    Copyright (c) 2012 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_END_OF_DXE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_END_OF_DXE_H_
end_define

begin_define
define|#
directive|define
name|EFI_SMM_END_OF_DXE_PROTOCOL_GUID
define|\
value|{ \     0x24e70042, 0xd5c5, 0x4260, { 0x8c, 0x39, 0xa, 0xd3, 0xaa, 0x32, 0xe9, 0x3d } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmEndOfDxeProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

