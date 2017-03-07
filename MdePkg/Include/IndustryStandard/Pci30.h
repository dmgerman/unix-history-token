begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for PCI 3.0 standard.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI30_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI30_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Pci23.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_MASS_STORAGE, Base Class 01h.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_SATADPA
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SATA
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_AHCI
value|0x01
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_WIRELESS, Base Class 0Dh.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|PCI_SUBCLASS_ETHERNET_80211A
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_ETHERNET_80211B
value|0x21
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|/**   Macro that checks whether device is a SATA controller.    @param  _p      Specified device.    @retval TRUE    Device is a SATA controller.   @retval FALSE   Device is not a SATA controller.  **/
end_comment

begin_define
define|#
directive|define
name|IS_PCI_SATADPA
parameter_list|(
name|_p
parameter_list|)
value|IS_CLASS2 (_p, PCI_CLASS_MASS_STORAGE, PCI_CLASS_MASS_STORAGE_SATADPA)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Capability List IDs and records
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_PCIEXP
value|0x10
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Data Structure Format
end_comment

begin_comment
comment|/// Section 5.1.2, PCI Firmware Specification, Revision 3.0
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Signature
decl_stmt|;
comment|///< "PCIR"
name|UINT16
name|VendorId
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|DeviceListOffset
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Revision
decl_stmt|;
name|UINT8
name|ClassCode
index|[
literal|3
index|]
decl_stmt|;
name|UINT16
name|ImageLength
decl_stmt|;
name|UINT16
name|CodeRevision
decl_stmt|;
name|UINT8
name|CodeType
decl_stmt|;
name|UINT8
name|Indicator
decl_stmt|;
name|UINT16
name|MaxRuntimeImageLength
decl_stmt|;
name|UINT16
name|ConfigUtilityCodeHeaderOffset
decl_stmt|;
name|UINT16
name|DMTFCLPEntryPointOffset
decl_stmt|;
block|}
name|PCI_3_0_DATA_STRUCTURE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

