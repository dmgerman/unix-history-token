begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares EFI PCI Hot Plug Init Protocol.      This protocol provides the necessary functionality to initialize the Hot Plug    Controllers (HPCs) and the buses that they control. This protocol also provides    information regarding resource padding.      @par Note:      This protocol is required only on platforms that support one or more PCI Hot     Plug* slots or CardBus sockets.      The EFI_PCI_HOT_PLUG_INIT_PROTOCOL provides a mechanism for the PCI bus enumerator   to properly initialize the HPCs and CardBus sockets that require initialization.    The HPC initialization takes place before the PCI enumeration process is complete.    There cannot be more than one instance of this protocol in a system. This protocol    is installed on its own separate handle.        Because the system may include multiple HPCs, one instance of this protocol    should represent all of them. The protocol functions use the device path of    the HPC to identify the HPC. When the PCI bus enumerator finds a root HPC, it    will call EFI_PCI_HOT_PLUG_INIT_PROTOCOL.InitializeRootHpc(). If InitializeRootHpc()   is unable to initialize a root HPC, the PCI enumerator will ignore that root HPC    and continue the enumeration process. If the HPC is not initialized, the devices    that it controls may not be initialized, and no resource padding will be provided.    From the standpoint of the PCI bus enumerator, HPCs are divided into the following    two classes:      - Root HPC:         These HPCs must be initialized by calling InitializeRootHpc() during the          enumeration process. These HPCs will also require resource padding. The          platform code must have a priori knowledge of these devices and must know          how to initialize them. There may not be any way to access their PCI          configuration space before the PCI enumerator programs all the upstream         bridges and thus enables the path to these devices. The PCI bus enumerator          is responsible for determining the PCI bus address of the HPC before it          calls InitializeRootHpc().     - Nonroot HPC:         These HPCs will not need explicit initialization during enumeration process.          These HPCs will require resource padding. The platform code does not have          to have a priori knowledge of these devices.    Copyright (c) 2007 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_PCI_HOT_PLUG_INIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_PCI_HOT_PLUG_INIT_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_PCI_HOT_PLUG_INIT_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_HOT_PLUG_INIT_PROTOCOL_GUID
define|\
value|{ \     0xaa0e8bc1, 0xdabc, 0x46b0, {0xa8, 0x44, 0x37, 0xb8, 0x16, 0x9b, 0x2b, 0xea } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_PCI_HOT_PLUG_INIT_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PCI_HOT_PLUG_INIT_PROTOCOL
name|EFI_PCI_HOT_PLUG_INIT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes the current state of an HPC
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|EFI_HPC_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The HPC initialization function was called and the HPC completed
end_comment

begin_comment
comment|/// initialization, but it was not enabled for some reason. The HPC may be
end_comment

begin_comment
comment|/// disabled in hardware, or it may be disabled due to user preferences,
end_comment

begin_comment
comment|/// hardware failure, or other reasons. No resource padding is required.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_HPC_STATE_INITIALIZED
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The HPC initialization function was called, the HPC completed
end_comment

begin_comment
comment|/// initialization, and it was enabled. Resource padding is required.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_HPC_STATE_ENABLED
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Location definition for PCI Hot Plug Controller
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|///
comment|/// The device path to the root HPC. An HPC cannot control its parent buses.
comment|/// The PCI bus driver requires this information so that it can pass the
comment|/// correct HpcPciAddress to the InitializeRootHpc() and GetResourcePadding()
comment|/// functions.
comment|///
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|HpcDevicePath
decl_stmt|;
comment|///
comment|/// The device path to the Hot Plug Bus (HPB) that is controlled by the root
comment|/// HPC. The PCI bus driver uses this information to check if a particular PCI
comment|/// bus has hot-plug slots.  The device path of a PCI bus is the same as the
comment|/// device path of its parent. For Standard(PCI) Hot Plug Controllers (SHPCs)
comment|/// and PCI Express*, HpbDevicePath is the same as HpcDevicePath.
comment|///
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|HpbDevicePath
decl_stmt|;
block|}
name|EFI_HPC_LOCATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes how resource padding should be applied
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Apply the padding at a PCI bus level. In other words, the resources
comment|/// that are allocated to the bus containing hot-plug slots are padded by
comment|/// the specified amount. If the hot-plug bus is behind a PCI-to-PCI
comment|/// bridge, the PCI-to-PCI bridge apertures will indicate the padding
comment|///
name|EfiPaddingPciBus
block|,
comment|///
comment|/// Apply the padding at a PCI root bridge level. If a PCI root bridge
comment|/// includes more than one hot-plug bus, the resource padding requests
comment|/// for these buses are added together and the resources that are
comment|/// allocated to the root bridge are padded by the specified amount. This
comment|/// strategy may reduce the total amount of padding, but requires
comment|/// reprogramming of PCI-to-PCI bridges in a hot-add event. If the hotplug
comment|/// bus is behind a PCI-to-PCI bridge, the PCI-to-PCI bridge
comment|/// apertures do not indicate the padding for that bus.
comment|///
name|EfiPaddingPciRootBridge
block|}
name|EFI_HPC_PADDING_ATTRIBUTES
typedef|;
end_typedef

begin_comment
comment|/**   Returns a list of root Hot Plug Controllers (HPCs) that require initialization   during the boot process.    This procedure returns a list of root HPCs. The PCI bus driver must initialize    these controllers during the boot process. The PCI bus driver may or may not be    able to detect these HPCs. If the platform includes a PCI-to-CardBus bridge, it    can be included in this list if it requires initialization.  The HpcList must be    self consistent. An HPC cannot control any of its parent buses. Only one HPC can    control a PCI bus. Because this list includes only root HPCs, no HPC in the list    can be a child of another HPC. This policy must be enforced by the    EFI_PCI_HOT_PLUG_INIT_PROTOCOL.   The PCI bus driver may not check for such    invalid conditions.  The callee allocates the buffer HpcList    @param[in]  This       Pointer to the EFI_PCI_HOT_PLUG_INIT_PROTOCOL instance.   @param[out] HpcCount   The number of root HPCs that were returned.   @param[out] HpcList    The list of root HPCs. HpcCount defines the number of                          elements in this list.    @retval EFI_SUCCESS             HpcList was returned.   @retval EFI_OUT_OF_RESOURCES    HpcList was not returned due to insufficient                                    resources.   @retval EFI_INVALID_PARAMETER   HpcCount is NULL or HpcList is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_ROOT_HPC_LIST
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOT_PLUG_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|HpcCount
parameter_list|,
name|OUT
name|EFI_HPC_LOCATION
modifier|*
modifier|*
name|HpcList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Initializes one root Hot Plug Controller (HPC). This process may causes   initialization of its subordinate buses.      This function initializes the specified HPC. At the end of initialization,    the hot-plug slots or sockets (controlled by this HPC) are powered and are    connected to the bus. All the necessary registers in the HPC are set up. For    a Standard (PCI) Hot Plug Controller (SHPC), the registers that must be set    up are defined in the PCI Standard Hot Plug Controller and Subsystem    Specification.      @param[in]  This            Pointer to the EFI_PCI_HOT_PLUG_INIT_PROTOCOL instance.   @param[in]  HpcDevicePath   The device path to the HPC that is being initialized.   @param[in]  HpcPciAddress   The address of the HPC function on the PCI bus.   @param[in]  Event           The event that should be signaled when the HPC                                initialization is complete.  Set to NULL if the                                caller wants to wait until the entire initialization                                process is complete.   @param[out] HpcState        The state of the HPC hardware. The state is                                EFI_HPC_STATE_INITIALIZED or EFI_HPC_STATE_ENABLED.    @retval EFI_SUCCESS             If Event is NULL, the specific HPC was successfully                                   initialized. If Event is not NULL, Event will be                                    signaled at a later time when initialization is complete.   @retval EFI_UNSUPPORTED         This instance of EFI_PCI_HOT_PLUG_INIT_PROTOCOL                                   does not support the specified HPC.   @retval EFI_OUT_OF_RESOURCES    Initialization failed due to insufficient                                   resources.   @retval EFI_INVALID_PARAMETER   HpcState is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INITIALIZE_ROOT_HPC
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOT_PLUG_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|HpcDevicePath
parameter_list|,
name|IN
name|UINT64
name|HpcPciAddress
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_HPC_STATE
modifier|*
name|HpcState
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the resource padding that is required by the PCI bus that is controlled   by the specified Hot Plug Controller (HPC).    This function returns the resource padding that is required by the PCI bus that   is controlled by the specified HPC. This member function is called for all the    root HPCs and nonroot HPCs that are detected by the PCI bus enumerator. This    function will be called before PCI resource allocation is completed. This function    must be called after all the root HPCs, with the possible exception of a    PCI-to-CardBus bridge, have completed initialization.    @param[in]  This            Pointer to the EFI_PCI_HOT_PLUG_INIT_PROTOCOL instance.   @param[in]  HpcDevicePath   The device path to the HPC.   @param[in]  HpcPciAddress   The address of the HPC function on the PCI bus.   @param[in]  HpcState        The state of the HPC hardware.   @param[out] Padding         The amount of resource padding that is required by the                               PCI bus under the control of the specified HPC.   @param[out] Attributes      Describes how padding is accounted for. The padding                               is returned in the form of ACPI 2.0 resource descriptors.    @retval EFI_SUCCESS             The resource padding was successfully returned.   @retval EFI_UNSUPPORTED         This instance of the EFI_PCI_HOT_PLUG_INIT_PROTOCOL                                   does not support the specified HPC.   @retval EFI_NOT_READY           This function was called before HPC initialization                                   is complete.   @retval EFI_INVALID_PARAMETER   HpcState or Padding or Attributes is NULL.   @retval EFI_OUT_OF_RESOURCES    ACPI 2.0 resource descriptors for Padding                                   cannot be allocated due to insufficient resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_HOT_PLUG_PADDING
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_HOT_PLUG_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|HpcDevicePath
parameter_list|,
name|IN
name|UINT64
name|HpcPciAddress
parameter_list|,
name|OUT
name|EFI_HPC_STATE
modifier|*
name|HpcState
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Padding
parameter_list|,
name|OUT
name|EFI_HPC_PADDING_ATTRIBUTES
modifier|*
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the necessary functionality to initialize the
end_comment

begin_comment
comment|/// Hot Plug Controllers (HPCs) and the buses that they control. This protocol
end_comment

begin_comment
comment|/// also provides information regarding resource padding.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PCI_HOT_PLUG_INIT_PROTOCOL
block|{
comment|///
comment|/// Returns a list of root HPCs and the buses that they control.
comment|///
name|EFI_GET_ROOT_HPC_LIST
name|GetRootHpcList
decl_stmt|;
comment|///
comment|/// Initializes the specified root HPC.
comment|///
name|EFI_INITIALIZE_ROOT_HPC
name|InitializeRootHpc
decl_stmt|;
comment|///
comment|/// Returns the resource padding that is required by the HPC.
comment|///
name|EFI_GET_HOT_PLUG_PADDING
name|GetResourcePadding
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciHotPlugInitProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

