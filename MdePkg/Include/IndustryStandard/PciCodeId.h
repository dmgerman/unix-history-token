begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file lists the PCI class codes only defined in PCI code and ID assignment specification   revision 1.3.    Copyright (c) 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_CODE_ID_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_CODE_ID_H__
end_define

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
name|PCI_IF_MASS_STORAGE_SCSI_VENDOR_SPECIFIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SCSI_DEVICE_PQI
value|0x11
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SCSI_CONTROLLER_PQI
value|0x12
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SCSI_DEVICE_CONTROLLER_PQI
value|0x13
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SCSI_DEVICE_NVM_EXPRESS
value|0x21
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SATA_SERIAL_BUS
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_SAS
value|0x07
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SAS
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SAS_SERIAL_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_MASS_STORAGE_SOLID_STATE
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SOLID_STATE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SOLID_STATE_NVMHCI
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SOLID_STATE_ENTERPRISE_NVMHCI
value|0x02
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_NETWORK, Base Class 02h.
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
name|PCI_CLASS_NETWORK_INFINIBAND
value|0x07
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_MEDIA, Base Class 04h.
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
name|PCI_CLASS_MEDIA_MIXED_MODE
value|0x03
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_BRIDGE, Base Class 06h.
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
name|PCI_CLASS_BRIDGE_ADVANCED_SWITCHING_TO_PCI
value|0x0B
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_ADVANCED_SWITCHING_TO_PCI_CUSTOM
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_ADVANCED_SWITCHING_TO_PCI_ASI_SIG
value|0x01
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_SYSTEM_PERIPHERAL, Base Class 08h.
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
name|PCI_IF_HPET
value|0x03
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SD_HOST_CONTROLLER
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_IOMMU
value|0x06
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_PROCESSOR, Base Class 0Bh.
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
name|PCI_SUBCLASS_PROC_OTHER
value|0x80
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_SERIAL, Base Class 0Ch.
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
name|PCI_IF_XHCI
value|0x30
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_OTHER
value|0x80
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_SATELLITE, Base Class 0Fh.
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
name|PCI_SUBCLASS_SATELLITE_OTHER
value|0x80
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_PROCESSING_ACCELERATOR, Base Class 12h.
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
name|PCI_CLASS_PROCESSING_ACCELERATOR
value|0x12
end_define

begin_comment
comment|///@}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

