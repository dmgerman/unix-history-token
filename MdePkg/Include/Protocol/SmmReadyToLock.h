begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM Ready To Lock protocol introduced in the PI 1.2 specification.    According to PI 1.4a specification, this SMM protocol indicates that   SMM resources and services that should not be used by the third party   code are about to be locked.   This protocol is a mandatory protocol published by the SMM Foundation   code when the system is preparing to lock certain resources and interfaces   in anticipation of the invocation of 3rd party extensible modules.   This protocol is an SMM counterpart of the DXE SMM Ready to Lock Protocol.   This protocol prorogates resource locking notification into SMM environment.   This protocol is installed after installation of the SMM End of DXE Protocol.    Copyright (c) 2009 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_READY_TO_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_READY_TO_LOCK_H_
end_define

begin_define
define|#
directive|define
name|EFI_SMM_READY_TO_LOCK_PROTOCOL_GUID
define|\
value|{ \     0x47b7fa8c, 0xf4bd, 0x4af6, { 0x82, 0x00, 0x33, 0x30, 0x86, 0xf0, 0xd2, 0xc8 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmReadyToLockProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

