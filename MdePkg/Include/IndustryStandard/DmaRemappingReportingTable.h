begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   DMA Remapping Reporting (DMAR) ACPI table definition from Intel(R)   Virtualization Technology for Directed I/O (VT-D) Architecture Specification.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:     - Intel(R) Virtualization Technology for Directed I/O (VT-D) Architecture       Specification v2.4, Dated June 2016.       http://www.intel.com/content/dam/www/public/us/en/documents/product-specifications/vt-directed-io-spec.pdf    @par Glossary:     - HPET - High Precision Event Timer     - NUMA - Non-uniform Memory Access **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DMA_REMAPPING_REPORTING_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DMA_REMAPPING_REPORTING_TABLE_H_
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
comment|/// DMA-Remapping Reporting Structure definitions from section 8.1
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_REVISION
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_FLAGS_INTR_REMAP
value|BIT0
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_FLAGS_X2APIC_OPT_OUT
value|BIT1
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remapping Structure Types definitions from section 8.2
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_TYPE_DRHD
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_TYPE_RMRR
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_TYPE_ATSR
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_TYPE_RHSA
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_TYPE_ANDD
value|0x04
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMA-Remapping Hardware Unit definitions from section 8.3
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_DRHD_FLAGS_INCLUDE_PCI_ALL
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// DMA-Remapping Device Scope Entry Structure definitions from section 8.3.1
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DEVICE_SCOPE_ENTRY_TYPE_PCI_ENDPOINT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DEVICE_SCOPE_ENTRY_TYPE_PCI_BRIDGE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DEVICE_SCOPE_ENTRY_TYPE_IOAPIC
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DEVICE_SCOPE_ENTRY_TYPE_MSI_CAPABLE_HPET
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_ACPI_DEVICE_SCOPE_ENTRY_TYPE_ACPI_NAMESPACE_DEVICE
value|0x05
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Root Port ATS Capability Reporting Structure definitions from section 8.5
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_DMAR_ATSR_FLAGS_ALL_PORTS
value|BIT0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition for DMA Remapping Structure Header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Type
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition for DMA-Remapping PCI Path
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Device
decl_stmt|;
name|UINT8
name|Function
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_PCI_PATH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Scope Structure is defined in section 8.3.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
name|UINT8
name|EnumerationId
decl_stmt|;
name|UINT8
name|StartBusNumber
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_DEVICE_SCOPE_STRUCTURE_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   DMA-remapping hardware unit definition (DRHD) structure is defined in   section 8.3. This uniquely represents a remapping hardware unit present   in the platform. There must be at least one instance of this structure   for each PCI segment in the platform. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
name|Header
decl_stmt|;
comment|/**     - Bit[0]: INCLUDE_PCI_ALL               - If Set, this remapping hardware unit has under its scope all                 PCI compatible devices in the specified Segment, except devices                 reported under the scope of other remapping hardware units for                 the same Segment.               - If Clear, this remapping hardware unit has under its scope only                 devices in the specified Segment that are explicitly identified                 through the DeviceScope field.     - Bits[7:1] Reserved.   **/
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
comment|///
comment|/// The PCI Segment associated with this unit.
comment|///
name|UINT16
name|SegmentNumber
decl_stmt|;
comment|///
comment|/// Base address of remapping hardware register-set for this unit.
comment|///
name|UINT64
name|RegisterBaseAddress
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_DRHD_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   Reserved Memory Region Reporting Structure (RMRR) is described in section 8.4   Reserved memory ranges that may be DMA targets may be reported through the   RMRR structures, along with the devices that requires access to the specified   reserved memory region. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
comment|///
comment|/// PCI Segment Number associated with devices identified through
comment|/// the Device Scope field.
comment|///
name|UINT16
name|SegmentNumber
decl_stmt|;
comment|///
comment|/// Base address of 4KB-aligned reserved memory region
comment|///
name|UINT64
name|ReservedMemoryRegionBaseAddress
decl_stmt|;
comment|/**     Last address of the reserved memory region. Value in this field must be     greater than the value in Reserved Memory Region Base Address field.     The reserved memory region size (Limit - Base + 1) must be an integer     multiple of 4KB.   **/
name|UINT64
name|ReservedMemoryRegionLimitAddress
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_RMRR_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   Root Port ATS Capability Reporting (ATSR) structure is defined in section 8.5.   This structure is applicable only for platforms supporting Device-TLBs as   reported through the Extended Capability Register. For each PCI Segment in   the platform that supports Device-TLBs, BIOS provides an ATSR structure. The   ATSR structures identifies PCI-Express Root-Ports supporting Address   Translation Services (ATS) transactions. Software must enable ATS on endpoint   devices behind a Root Port only if the Root Port is reported as supporting   ATS transactions. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
name|Header
decl_stmt|;
comment|/**     - Bit[0]: ALL_PORTS:               - If Set, indicates all PCI Express Root Ports in the specified                 PCI Segment supports ATS transactions.               - If Clear, indicates ATS transactions are supported only on                 Root Ports identified through the Device Scope field.     - Bits[7:1] Reserved.   **/
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
comment|///
comment|/// The PCI Segment associated with this ATSR structure
comment|///
name|UINT16
name|SegmentNumber
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_ATSR_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   Remapping Hardware Static Affinity (RHSA) is an optional structure defined   in section 8.6. This is intended to be used only on NUMA platforms with   Remapping hardware units and memory spanned across multiple nodes.   When used, there must be a RHSA structure for each Remapping hardware unit   reported through DRHD structure. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
comment|///
comment|/// Register Base Address of this Remap hardware unit reported in the
comment|/// corresponding DRHD structure.
comment|///
name|UINT64
name|RegisterBaseAddress
decl_stmt|;
comment|///
comment|/// Proximity Domain to which the Remap hardware unit identified by the
comment|/// Register Base Address field belongs.
comment|///
name|UINT32
name|ProximityDomain
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_RHSA_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   An ACPI Name-space Device Declaration (ANDD) structure is defined in section   8.7 and uniquely represents an ACPI name-space enumerated device capable of   issuing DMA requests in the platform. ANDD structures are used in conjunction   with Device-Scope entries of type ACPI_NAMESPACE_DEVICE. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DMAR_STRUCTURE_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/**     Each ACPI device enumerated through an ANDD structure must have a unique     value for this field. To report an ACPI device with ACPI Device Number     value of X, under the scope of a DRHD unit, a Device-Scope entry of type     ACPI_NAMESPACE_DEVICE is used with value of X in the Enumeration ID field.     The Start Bus Number and Path fields in the Device-Scope together     provides the 16-bit source-id allocated by platform for the ACPI device.   **/
name|UINT8
name|AcpiDeviceNumber
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_ANDD_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   DMA Remapping Reporting Structure Header as defined in section 8.1   This header will be followed by list of Remapping Structures listed below     - DMA Remapping Hardware Unit Definition (DRHD)     - Reserved Memory Region Reporting (RMRR)     - Root Port ATS Capability Reporting (ATSR)     - Remapping Hardware Static Affinity (RHSA)     - ACPI Name-space Device Declaration (ANDD)   These structure types must by reported in numerical order.   i.e., All remapping structures of type 0 (DRHD) enumerated before remapping   structures of type 1 (RMRR), and so forth. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_DESCRIPTION_HEADER
name|Header
decl_stmt|;
comment|/**     This field indicates the maximum DMA physical addressability supported by     this platform. The system address map reported by the BIOS indicates what     portions of this addresses are populated. The Host Address Width (HAW) of     the platform is computed as (N+1), where N is the value reported in this     field.     For example, for a platform supporting 40 bits of physical addressability,     the value of 100111b is reported in this field.   **/
name|UINT8
name|HostAddressWidth
decl_stmt|;
comment|/**     - Bit[0]:   INTR_REMAP - If Clear, the platform does not support interrupt                 remapping. If Set, the platform supports interrupt remapping.     - Bit[1]:   X2APIC_OPT_OUT - For firmware compatibility reasons, platform                 firmware may Set this field to request system software to opt                 out of enabling Extended xAPIC (X2APIC) mode. This field is                 valid only when the INTR_REMAP field (bit 0) is Set.     - Bits[7:2] Reserved.   **/
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|EFI_ACPI_DMAR_HEADER
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

