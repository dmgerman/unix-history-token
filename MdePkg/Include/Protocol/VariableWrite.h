begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Variable Write Architectural Protocol as defined in PI Specification VOLUME 2 DXE    This provides the services required to set nonvolatile environment variables.    This protocol must be produced by a runtime DXE driver and may be consumed only    by the DXE Foundation.    The DXE driver that produces this protocol must be a runtime driver. This driver    may update the SetVariable() field of the UEFI Runtime Services Table.      After the UEFI Runtime Services Table has been initialized, the driver must    install the EFI_VARIABLE_WRITE_ARCH_PROTOCOL_GUID on a new handle with a NULL    interface pointer. The installation of this protocol informs the DXE Foundation    that the write services for nonvolatile environment variables are now available    and that the DXE Foundation must update the 32-bit CRC of the UEFI Runtime Services    Table. The full complement of environment variable services are not available    until both this protocol and EFI_VARIABLE_ARCH_PROTOCOL are installed. DXE drivers    that require read-only access or read/write access to volatile environment variables   must have the EFI_VARIABLE_WRITE_ARCH_PROTOCOL in their dependency expressions.   DXE drivers that require write access to nonvolatile environment variables must    have this architectural protocol in their dependency expressions.        Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_VARIABLE_WRITE_ARCH_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_VARIABLE_WRITE_ARCH_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Variable Write Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_WRITE_ARCH_PROTOCOL_GUID
define|\
value|{ 0x6441f818, 0x6362, 0x4e44, {0xb5, 0x70, 0x7d, 0xba, 0x31, 0xdd, 0x24, 0x53 } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiVariableWriteArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

