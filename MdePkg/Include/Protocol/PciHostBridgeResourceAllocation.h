begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares PCI Host Bridge Resource Allocation Protocol which    provides the basic interfaces to abstract a PCI host bridge resource allocation.    This protocol is mandatory if the system includes PCI devices.    Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards.    **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This file must be included because EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
end_comment

begin_comment
comment|// uses EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<Protocol/PciRootBridgeIo.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GUID
define|\
value|{ \     0xCF8034BE, 0x6768, 0x4d8b, {0xB7,0x39,0x7C,0xCE,0x68,0x3A,0x9F,0xBE } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/// If this bit is set, then the PCI Root Bridge does not
end_comment

begin_comment
comment|/// support separate windows for Non-prefetchable and Prefetchable
end_comment

begin_comment
comment|/// memory. A PCI bus driver needs to include requests for Prefetchable
end_comment

begin_comment
comment|/// memory in the Non-prefetchable memory pool.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_HOST_BRIDGE_COMBINE_MEM_PMEM
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this bit is set, then the PCI Root Bridge supports
end_comment

begin_comment
comment|/// 64 bit memory windows.  If this bit is not set,
end_comment

begin_comment
comment|/// the PCI bus driver needs to include requests for 64 bit
end_comment

begin_comment
comment|/// memory address in the corresponding 32 bit memory pool.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_HOST_BRIDGE_MEM64_DECODE
value|2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A UINT64 value that contains the status of a PCI resource requested
end_comment

begin_comment
comment|/// in the Configuration parameter returned by GetProposedResources()
end_comment

begin_comment
comment|/// The legal values are EFI_RESOURCE_SATISFIED and EFI_RESOURCE_NOT_SATISFIED
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_RESOURCE_ALLOCATION_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The request of this resource type could be fulfilled.  Used in the
end_comment

begin_comment
comment|/// Configuration parameter returned by GetProposedResources() to identify
end_comment

begin_comment
comment|/// a PCI resources request that can be satisfied.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_SATISFIED
value|0x0000000000000000ULL
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The request of this resource type could not be fulfilled for its
end_comment

begin_comment
comment|/// absence in the host bridge resource pool.  Used in the Configuration parameter
end_comment

begin_comment
comment|/// returned by GetProposedResources() to identify a PCI resources request that
end_comment

begin_comment
comment|/// can not be satisfied.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESOURCE_NOT_SATISFIED
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This  enum is used to specify the phase of the PCI enumaeration process.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Reset the host bridge PCI apertures and internal data structures.
comment|/// PCI enumerator should issue this notification before starting fresh
comment|/// enumeration process. Enumeration cannot be restarted after sending
comment|/// any other notification such as EfiPciHostBridgeBeginBusAllocation.
comment|///
name|EfiPciHostBridgeBeginEnumeration
block|,
comment|///
comment|/// The bus allocation phase is about to begin. No specific action
comment|/// is required here. This notification can be used to perform any
comment|/// chipset specific programming.
comment|///
name|EfiPciHostBridgeBeginBusAllocation
block|,
comment|///
comment|/// The bus allocation and bus programming phase is complete. No specific
comment|/// action is required here. This notification can be used to perform any
comment|/// chipset specific programming.
comment|///
name|EfiPciHostBridgeEndBusAllocation
block|,
comment|///
comment|/// The resource allocation phase is about to begin.No specific action is
comment|/// required here. This notification can be used to perform any chipset specific programming.
comment|///
name|EfiPciHostBridgeBeginResourceAllocation
block|,
comment|///
comment|/// Allocate resources per previously submitted requests for all the PCI Root
comment|/// Bridges. These resource settings are returned on the next call to
comment|/// GetProposedResources().
comment|///
name|EfiPciHostBridgeAllocateResources
block|,
comment|///
comment|/// Program the Host Bridge hardware to decode previously allocated resources
comment|/// (proposed resources) for all the PCI Root Bridges.
comment|///
name|EfiPciHostBridgeSetResources
block|,
comment|///
comment|/// De-allocate previously allocated resources previously for all the PCI
comment|/// Root Bridges and reset the I/O and memory apertures to initial state.
comment|///
name|EfiPciHostBridgeFreeResources
block|,
comment|///
comment|/// The resource allocation phase is completed.  No specific action is required
comment|/// here. This notification can be used to perform any chipset specific programming.
comment|///
name|EfiPciHostBridgeEndResourceAllocation
block|,
comment|///
comment|/// The Host Bridge Enumeration is completed. No specific action is required here.
comment|/// This notification can be used to perform any chipset specific programming.
comment|///
name|EfiPciHostBridgeEndEnumeration
block|,
name|EfiMaxPciHostBridgeEnumerationPhase
block|}
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definitions of 2 notification points.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// This notification is only applicable to PCI-PCI bridges and
comment|/// indicates that the PCI enumerator is about to begin enumerating
comment|/// the bus behind the PCI-PCI Bridge. This notification is sent after
comment|/// the primary bus number, the secondary bus number and the subordinate
comment|/// bus number registers in the PCI-PCI Bridge are programmed to valid
comment|/// (not necessary final) values
comment|///
name|EfiPciBeforeChildBusEnumeration
block|,
comment|///
comment|/// This notification is sent before the PCI enumerator probes BAR registers
comment|/// for every valid PCI function.
comment|///
name|EfiPciBeforeResourceCollection
block|}
name|EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE
typedef|;
end_typedef

begin_comment
comment|/**   These are the notifications from the PCI bus driver that it is about to enter a certain phase of the PCI    enumeration process.    @param[in] This    The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                       instance.   @param[in] Phase   The phase during enumeration.    @retval EFI_SUCCESS             The notification was accepted without any errors.   @retval EFI_INVALID_PARAMETER   The Phase is invalid.   @retval EFI_NOT_READY           This phase cannot be entered at this time. For example, this error                                    is valid for a Phase of EfiPciHostBridgeAllocateResources if                                    SubmitResources() has not been called for one or more                                    PCI root bridges before this call.   @retval EFI_DEVICE_ERROR        Programming failed due to a hardware error. This error is valid for                                    a Phase of EfiPciHostBridgeSetResources.   @retval EFI_OUT_OF_RESOURCES    The request could not be completed due to a lack of resources.                                    This error is valid for a Phase of EfiPciHostBridgeAllocateResources                                   if the previously submitted resource requests cannot be fulfilled or were only                                    partially fulfilled  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_NOTIFY_PHASE
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE
name|Phase
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the device handle of the next PCI root bridge that is associated with this host bridge.    @param[in]     This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                      instance.   @param[in,out] RootBridgeHandle   Returns the device handle of the next PCI root bridge. On input, it holds the                                      RootBridgeHandle that was returned by the most recent call to                                      GetNextRootBridge(). If RootBridgeHandle is NULL on input, the handle                                      for the first PCI root bridge is returned.    @retval EFI_SUCCESS             The requested attribute information was returned.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not an EFI_HANDLE that was returned                                    on a previous call to GetNextRootBridge().   @retval EFI_NOT_FOUND           There are no more PCI root bridge device handles.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_NEXT_ROOT_BRIDGE
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|RootBridgeHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the allocation attributes of a PCI root bridge.    @param[in]  This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                   instance.   @param[in]  RootBridgeHandle   The device handle of the PCI root bridge in which the caller is interested.   @param[out] Attribute          The pointer to attributes of the PCI root bridge.    @retval EFI_SUCCESS             The requested attribute information was returned.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_INVALID_PARAMETER   Attributes is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets up the specified PCI root bridge for the bus enumeration process.    @param[in]  This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                   instance.   @param[in]  RootBridgeHandle   The PCI root bridge to be set up.   @param[out] Configuration      The pointer to the pointer to the PCI bus resource descriptor.    @retval EFI_SUCCESS             The PCI root bridge was set up and the bus range was returned in                                    Configuration.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_DEVICE_ERROR        Programming failed due to a hardware error.   @retval EFI_OUT_OF_RESOURCES    The request could not be completed due to a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_START_BUS_ENUMERATION
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Configuration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Programs the PCI root bridge hardware so that it decodes the specified PCI bus range.    @param[in] This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                 instance.     @param[in] RootBridgeHandle   The PCI root bridge whose bus range is to be programmed.   @param[in] Configuration      The pointer to the PCI bus resource descriptor.    @retval EFI_SUCCESS             The bus range for the PCI root bridge was programmed.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_INVALID_PARAMETER   Configuration is NULL   @retval EFI_INVALID_PARAMETER   Configuration does not point to a valid ACPI (2.0& 3.0)                                    resource descriptor.   @retval EFI_INVALID_PARAMETER   Configuration does not include a valid ACPI 2.0 bus resource                                   descriptor.   @retval EFI_INVALID_PARAMETER   Configuration includes valid ACPI (2.0& 3.0) resource                                    descriptors other than bus descriptors.   @retval EFI_INVALID_PARAMETER   Configuration contains one or more invalid ACPI resource                                    descriptors.   @retval EFI_INVALID_PARAMETER   "Address Range Minimum" is invalid for this root bridge.   @retval EFI_INVALID_PARAMETER   "Address Range Length" is invalid for this root bridge.   @retval EFI_DEVICE_ERROR        Programming failed due to a hardware error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_SET_BUS_NUMBERS
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|IN
name|VOID
modifier|*
name|Configuration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Submits the I/O and memory resource requirements for the specified PCI root bridge.    @param[in] This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                  instance.   @param[in] RootBridgeHandle   The PCI root bridge whose I/O and memory resource requirements are being                                  submitted.   @param[in] Configuration      The pointer to the PCI I/O and PCI memory resource descriptor.    @retval EFI_SUCCESS             The I/O and memory resource requests for a PCI root bridge were                                    accepted.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_INVALID_PARAMETER   Configuration is NULL.   @retval EFI_INVALID_PARAMETER   Configuration does not point to a valid ACPI (2.0& 3.0)                                    resource descriptor.   @retval EFI_INVALID_PARAMETER   Configuration includes requests for one or more resource                                    types that are not supported by this PCI root bridge. This error will                                    happen if the caller did not combine resources according to                                    Attributes that were returned by GetAllocAttributes().   @retval EFI_INVALID_PARAMETER   "Address Range Maximum" is invalid.   @retval EFI_INVALID_PARAMETER   "Address Range Length" is invalid for this PCI root bridge.   @retval EFI_INVALID_PARAMETER   "Address Space Granularity" is invalid for this PCI root bridge.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_SUBMIT_RESOURCES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|IN
name|VOID
modifier|*
name|Configuration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the proposed resource settings for the specified PCI root bridge.    @param[in]  This               The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL                                   instance.   @param[in]  RootBridgeHandle   The PCI root bridge handle.   @param[out] Configuration      The pointer to the pointer to the PCI I/O and memory resource descriptor.    @retval EFI_SUCCESS             The requested parameters were returned.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_DEVICE_ERROR        Programming failed due to a hardware error.   @retval EFI_OUT_OF_RESOURCES    The request could not be completed due to a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_PROPOSED_RESOURCES
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Configuration
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Provides the hooks from the PCI bus driver to every PCI controller (device/function) at various    stages of the PCI enumeration process that allow the host bridge driver to preinitialize individual    PCI controllers before enumeration.    @param[in]  This                  The pointer to the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL instance.   @param[in]  RootBridgeHandle      The associated PCI root bridge handle.   @param[in]  PciAddress            The address of the PCI device on the PCI bus.   @param[in]  Phase                 The phase of the PCI device enumeration.    @retval EFI_SUCCESS             The requested parameters were returned.   @retval EFI_INVALID_PARAMETER   RootBridgeHandle is not a valid root bridge handle.   @retval EFI_INVALID_PARAMETER   Phase is not a valid phase that is defined in                                    EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE.   @retval EFI_DEVICE_ERROR        Programming failed due to a hardware error. The PCI enumerator                                    should not enumerate this device, including its child devices if it is                                    a PCI-to-PCI bridge.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_PREPROCESS_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridgeHandle
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS
name|PciAddress
parameter_list|,
name|IN
name|EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE
name|Phase
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the basic interfaces to abstract a PCI host bridge resource allocation.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
block|{
comment|///
comment|/// The notification from the PCI bus enumerator that it is about to enter
comment|/// a certain phase during the enumeration process.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_NOTIFY_PHASE
name|NotifyPhase
decl_stmt|;
comment|///
comment|/// Retrieves the device handle for the next PCI root bridge that is produced by the
comment|/// host bridge to which this instance of the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL is attached.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_NEXT_ROOT_BRIDGE
name|GetNextRootBridge
decl_stmt|;
comment|///
comment|/// Retrieves the allocation-related attributes of a PCI root bridge.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_ATTRIBUTES
name|GetAllocAttributes
decl_stmt|;
comment|///
comment|/// Sets up a PCI root bridge for bus enumeration.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_START_BUS_ENUMERATION
name|StartBusEnumeration
decl_stmt|;
comment|///
comment|/// Sets up the PCI root bridge so that it decodes a specific range of bus numbers.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_SET_BUS_NUMBERS
name|SetBusNumbers
decl_stmt|;
comment|///
comment|/// Submits the resource requirements for the specified PCI root bridge.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_SUBMIT_RESOURCES
name|SubmitResources
decl_stmt|;
comment|///
comment|/// Returns the proposed resource assignment for the specified PCI root bridges.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_GET_PROPOSED_RESOURCES
name|GetProposedResources
decl_stmt|;
comment|///
comment|/// Provides hooks from the PCI bus driver to every PCI controller
comment|/// (device/function) at various stages of the PCI enumeration process that
comment|/// allow the host bridge driver to preinitialize individual PCI controllers
comment|/// before enumeration.
comment|///
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL_PREPROCESS_CONTROLLER
name|PreprocessController
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciHostBridgeResourceAllocationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

