begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for HSTI 1.0 specification, defined at    Microsoft Hardware Security Testability Specification.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HSTI_H__
end_ifndef

begin_define
define|#
directive|define
name|__HSTI_H__
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_define
define|#
directive|define
name|ADAPTER_INFO_PLATFORM_SECURITY_GUID
define|\
value|{0x6be272c7, 0x1320, 0x4ccd, { 0x90, 0x17, 0xd4, 0x61, 0x2c, 0x01, 0x2b, 0x25 }}
end_define

begin_define
define|#
directive|define
name|PLATFORM_SECURITY_VERSION_VNEXTCS
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PLATFORM_SECURITY_ROLE_PLATFORM_REFERENCE
value|0x00000001
end_define

begin_comment
comment|// IHV
end_comment

begin_define
define|#
directive|define
name|PLATFORM_SECURITY_ROLE_PLATFORM_IBV
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PLATFORM_SECURITY_ROLE_IMPLEMENTOR_OEM
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PLATFORM_SECURITY_ROLE_IMPLEMENTOR_ODM
value|0x00000004
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|//  Return PLATFORM_SECURITY_VERSION_VNEXTCS
comment|//
name|UINT32
name|Version
decl_stmt|;
comment|//
comment|// The role of the publisher of this interface.  Reference platform designers
comment|// such as IHVs and IBVs are expected to return PLATFORM_SECURITY_ROLE_PLATFORM_REFERENCE
comment|// and PLATFORM_SECURITY_ROLE_PLATFORM_IBV respectively.
comment|// If the test modules from the designers are unable to fully verify all
comment|// security features, then the platform implementers, OEMs and ODMs, will
comment|// need to publish this interface with a role of Implementer.
comment|//
name|UINT32
name|Role
decl_stmt|;
comment|//
comment|// Human readable vendor, model,& version of this implementation.
comment|//
name|CHAR16
name|ImplementationID
index|[
literal|256
index|]
decl_stmt|;
comment|//
comment|// The size in bytes of the SecurityFeaturesRequired and SecurityFeaturesEnabled arrays.
comment|// The arrays must be the same size.
comment|//
name|UINT32
name|SecurityFeaturesSize
decl_stmt|;
comment|//
comment|// IHV-defined bitfield corresponding to all security features which must be
comment|// implemented to meet the security requirements defined by PLATFORM_SECURITY_VERSION Version.
comment|//
comment|//UINT8   SecurityFeaturesRequired[];     //Ignored for non-IHV
comment|//
comment|// Publisher-defined bitfield corresponding to all security features which
comment|// have implemented programmatic tests in this module.
comment|//
comment|//UINT8   SecurityFeaturesImplemented[];
comment|//
comment|// Publisher-defined bitfield corresponding to all security features which
comment|// have been verified implemented by this implementation.
comment|//
comment|//UINT8   SecurityFeaturesVerified[];
comment|//
comment|// A Null-terminated string, one failure per line (CR/LF terminated), with a
comment|// unique identifier that the OEM/ODM can use to locate the documentation
comment|// which will describe the steps to remediate the failure - a URL to the
comment|// documentation is recommended.
comment|//
comment|//CHAR16	ErrorString[];
block|}
name|ADAPTER_INFO_PLATFORM_SECURITY
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gAdapterInfoPlatformSecurityGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

