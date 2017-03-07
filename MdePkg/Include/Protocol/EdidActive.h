begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EDID Active Protocol from the UEFI 2.0 specification.    Placed on the video output device child handle that is actively displaying output.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EDID_ACTIVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EDID_ACTIVE_H__
end_define

begin_define
define|#
directive|define
name|EFI_EDID_ACTIVE_PROTOCOL_GUID
define|\
value|{ \     0xbd8c1056, 0x9f36, 0x44ec, {0x92, 0xa8, 0xa6, 0x33, 0x7f, 0x81, 0x79, 0x86 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol contains the EDID information for an active video output device. This is either the
end_comment

begin_comment
comment|/// EDID information retrieved from the EFI_EDID_OVERRIDE_PROTOCOL if an override is
end_comment

begin_comment
comment|/// available, or an identical copy of the EDID information from the
end_comment

begin_comment
comment|/// EFI_EDID_DISCOVERED_PROTOCOL if no overrides are available.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The size, in bytes, of the Edid buffer. 0 if no EDID information
comment|/// is available from the video output device. Otherwise, it must be a
comment|/// minimum of 128 bytes.
comment|///
name|UINT32
name|SizeOfEdid
decl_stmt|;
comment|///
comment|/// A pointer to a read-only array of bytes that contains the EDID
comment|/// information for an active video output device. This pointer is
comment|/// NULL if no EDID information is available for the video output
comment|/// device. The minimum size of a valid Edid buffer is 128 bytes.
comment|/// EDID information is defined in the E-EDID EEPROM
comment|/// specification published by VESA (www.vesa.org).
comment|///
name|UINT8
modifier|*
name|Edid
decl_stmt|;
block|}
name|EFI_EDID_ACTIVE_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEdidActiveProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

