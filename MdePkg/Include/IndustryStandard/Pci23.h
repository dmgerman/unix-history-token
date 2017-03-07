begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Support for PCI 2.3 standard.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI23_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI23_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Pci22.h>
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
name|PCI_CLASS_MASS_STORAGE_ATA
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_SINGLE_DMA
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_IF_MASS_STORAGE_CHAINED_DMA
value|0x30
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
name|PCI_CLASS_NETWORK_WORLDFIP
value|0x05
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_NETWORK_PICMG_MULTI_COMPUTING
value|0x06
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
name|PCI_CLASS_BRIDGE_SEMI_TRANSPARENT_P2P
value|0x09
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_SEMI_TRANSPARENT_P2P_PRIMARY
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_IF_BRIDGE_SEMI_TRANSPARENT_P2P_SECONDARY
value|0x80
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_BRIDGE_INFINIBAND_TO_PCI
value|0x0A
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_SCC, Base Class 07h.
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
name|PCI_SUBCLASS_GPIB
value|0x04
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_SMART_CARD
value|0x05
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
name|PCI_IF_EHCI
value|0x20
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_IB
value|0x06
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_IPMI
value|0x07
end_define

begin_define
define|#
directive|define
name|PCI_IF_IPMI_SMIC
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_IF_IPMI_KCS
value|0x01
end_define

begin_comment
comment|///< Keyboard Controller Style
end_comment

begin_define
define|#
directive|define
name|PCI_IF_IPMI_BT
value|0x02
end_define

begin_comment
comment|///< Block Transfer
end_comment

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_SERCOS
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_CLASS_SERIAL_CANBUS
value|0x09
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
name|PCI_SUBCLASS_BLUETOOTH
value|0x11
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_BROADBAND
value|0x12
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI_CLASS_DPIO, Base Class 11h.
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
name|PCI_SUBCLASS_PERFORMANCE_COUNTERS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_COMMUNICATION_SYNCHRONIZATION
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_SUBCLASS_MANAGEMENT_CARD
value|0x20
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// defined in PCI Express Spec.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PCI_EXP_MAX_CONFIG_OFFSET
value|0x1000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI Capability List IDs and records.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_CAPABILITY_ID_PCIX
value|0x07
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
comment|/// PCI-X Capabilities List,
end_comment

begin_comment
comment|/// Section 7.2, PCI-X Addendum to the PCI Local Bus Specification, Revision 1.0b.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT16
name|CommandReg
decl_stmt|;
name|UINT32
name|StatusReg
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_PCIX
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// PCI-X Bridge Capabilities List,
end_comment

begin_comment
comment|/// Section 8.6.2, PCI-X Addendum to the PCI Local Bus Specification, Revision 1.0b.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PCI_CAPABILITY_HDR
name|Hdr
decl_stmt|;
name|UINT16
name|SecStatusReg
decl_stmt|;
name|UINT32
name|StatusReg
decl_stmt|;
name|UINT32
name|SplitTransCtrlRegUp
decl_stmt|;
name|UINT32
name|SplitTransCtrlRegDn
decl_stmt|;
block|}
name|EFI_PCI_CAPABILITY_PCIX_BRDG
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|PCI_CODE_TYPE_EFI_IMAGE
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

