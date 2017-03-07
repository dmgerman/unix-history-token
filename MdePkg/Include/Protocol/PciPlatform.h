begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares PlatfromOpRom protocols that provide the interface between    the PCI bus driver/PCI Host Bridge Resource Allocation driver and a platform-specific    driver to describe the unique features of a platform.    This protocol is optional.    Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_PLATFORM_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_PLATFORM_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file must be included because the EFI_PCI_PLATFORM_PROTOCOL uses
end_comment

begin_comment
comment|/// EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE.
end_comment

begin_comment
comment|///
end_comment

begin_include
include|#
directive|include
file|<Protocol/PciHostBridgeResourceAllocation.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_PCI_PLATFORM_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_PLATFORM_PROTOCOL_GUID
define|\
value|{ \     0x7d75280, 0x27d4, 0x4d69, {0x90, 0xd0, 0x56, 0x43, 0xe2, 0x38, 0xb3, 0x41} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_PCI_PLATFORM_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PCI_PLATFORM_PROTOCOL
name|EFI_PCI_PLATFORM_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PCI_PLATFORM_POLICY that is a bitmask with the following legal combinations:
end_comment

begin_comment
comment|///   - EFI_RESERVE_NONE_IO_ALIAS:<BR>
end_comment

begin_comment
comment|///       Does not set aside either ISA or VGA I/O resources during PCI
end_comment

begin_comment
comment|///       enumeration. By using this selection, the platform indicates that it does
end_comment

begin_comment
comment|///       not want to support a PCI device that requires ISA or legacy VGA
end_comment

begin_comment
comment|///       resources. If a PCI device driver asks for these resources, the request
end_comment

begin_comment
comment|///       will be turned down.
end_comment

begin_comment
comment|///   - EFI_RESERVE_ISA_IO_ALIAS | EFI_RESERVE_VGA_IO_ALIAS:<BR>
end_comment

begin_comment
comment|///       Sets aside the ISA I/O range and all the aliases during PCI
end_comment

begin_comment
comment|///       enumeration. VGA I/O ranges and aliases are included in ISA alias
end_comment

begin_comment
comment|///       ranges. In this scheme, seventy-five percent of the I/O space remains unused.
end_comment

begin_comment
comment|///       By using this selection, the platform indicates that it wants to support
end_comment

begin_comment
comment|///       PCI devices that require the following, at the cost of wasted I/O space:
end_comment

begin_comment
comment|///       ISA range and its aliases
end_comment

begin_comment
comment|///       Legacy VGA range and its aliases
end_comment

begin_comment
comment|///       The PCI bus driver will not allocate I/O addresses out of the ISA I/O
end_comment

begin_comment
comment|///       range and its aliases. The following are the ISA I/O ranges:
end_comment

begin_comment
comment|///         - n100..n3FF
end_comment

begin_comment
comment|///         - n500..n7FF
end_comment

begin_comment
comment|///         - n900..nBFF
end_comment

begin_comment
comment|///         - nD00..nFFF
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///       In this case, the PCI bus driver will ask the PCI host bridge driver for
end_comment

begin_comment
comment|///       larger I/O ranges. The PCI host bridge driver is not aware of the ISA
end_comment

begin_comment
comment|///       aliasing policy and merely attempts to allocate the requested ranges.
end_comment

begin_comment
comment|///       The first device that requests the legacy VGA range will get all the
end_comment

begin_comment
comment|///       legacy VGA range plus its aliased addresses forwarded to it. The first
end_comment

begin_comment
comment|///       device that requests the legacy ISA range will get all the legacy ISA
end_comment

begin_comment
comment|///       range, plus its aliased addresses, forwarded to it.
end_comment

begin_comment
comment|///   - EFI_RESERVE_ISA_IO_NO_ALIAS | EFI_RESERVE_VGA_IO_ALIAS:<BR>
end_comment

begin_comment
comment|///       Sets aside the ISA I/O range (0x100 - 0x3FF) during PCI enumeration
end_comment

begin_comment
comment|///       and the aliases of the VGA I/O ranges. By using this selection, the
end_comment

begin_comment
comment|///       platform indicates that it will support VGA devices that require VGA
end_comment

begin_comment
comment|///       ranges, including those that require VGA aliases. The platform further
end_comment

begin_comment
comment|///       wants to support non-VGA devices that ask for the ISA range (0x100 -
end_comment

begin_comment
comment|///       3FF), but not if it also asks for the ISA aliases. The PCI bus driver will
end_comment

begin_comment
comment|///       not allocate I/O addresses out of the legacy ISA I/O range (0x100 -
end_comment

begin_comment
comment|///       0x3FF) range or the aliases of the VGA I/O range. If a PCI device
end_comment

begin_comment
comment|///       driver asks for the ISA I/O ranges, including aliases, the request will be
end_comment

begin_comment
comment|///       turned down. The first device that requests the legacy VGA range will
end_comment

begin_comment
comment|///       get all the legacy VGA range plus its aliased addresses forwarded to
end_comment

begin_comment
comment|///       it. When the legacy VGA device asks for legacy VGA ranges and its
end_comment

begin_comment
comment|///       aliases, all the upstream PCI-to-PCI bridges must be set up to perform
end_comment

begin_comment
comment|///       10-bit decode on legacy VGA ranges. To prevent two bridges from
end_comment

begin_comment
comment|///       positively decoding the same address, all PCI-to-PCI bridges that are
end_comment

begin_comment
comment|///       peers to this bridge will have to be set up to not decode ISA aliased
end_comment

begin_comment
comment|///       ranges. In that case, all the devices behind the peer bridges can
end_comment

begin_comment
comment|///       occupy only I/O addresses that are not ISA aliases. This is a limitation
end_comment

begin_comment
comment|///       of PCI-to-PCI bridges and is described in the white paper PCI-to-PCI
end_comment

begin_comment
comment|///       Bridges and Card Bus Controllers on Windows 2000, Windows XP,
end_comment

begin_comment
comment|///       and Windows Server 2003. The PCI enumeration process must be
end_comment

begin_comment
comment|///       cognizant of this restriction.
end_comment

begin_comment
comment|///   - EFI_RESERVE_ISA_IO_NO_ALIAS | EFI_RESERVE_VGA_IO_NO_ALIAS:<BR>
end_comment

begin_comment
comment|///       Sets aside the ISA I/O range (0x100 - 0x3FF) during PCI enumeration.
end_comment

begin_comment
comment|///       VGA I/O ranges are included in the ISA range. By using this selection,
end_comment

begin_comment
comment|///       the platform indicates that it wants to support PCI devices that require
end_comment

begin_comment
comment|///       the ISA range and legacy VGA range, but it does not want to support
end_comment

begin_comment
comment|///       devices that require ISA alias ranges or VGA alias ranges. The PCI
end_comment

begin_comment
comment|///       bus driver will not allocate I/O addresses out of the legacy ISA I/O
end_comment

begin_comment
comment|///       range (0x100-0x3FF). If a PCI device driver asks for the ISA I/O
end_comment

begin_comment
comment|///       ranges, including aliases, the request will be turned down. By using
end_comment

begin_comment
comment|///       this selection, the platform indicates that it will support VGA devices
end_comment

begin_comment
comment|///       that require VGA ranges, but it will not support VGA devices that
end_comment

begin_comment
comment|///       require VGA aliases. To truly support 16-bit VGA decode, all the PCIto-
end_comment

begin_comment
comment|///       PCI bridges that are upstream to a VGA device, as well as
end_comment

begin_comment
comment|///       upstream to the parent PCI root bridge, must support 16-bit VGA I/O
end_comment

begin_comment
comment|///       decode. See the PCI-to-PCI Bridge Architecture Specification for
end_comment

begin_comment
comment|///       information regarding the 16-bit VGA decode support. This
end_comment

begin_comment
comment|///       requirement must hold true for every VGA device in the system. If any
end_comment

begin_comment
comment|///       of these bridges does not support 16-bit VGA decode, it will positively
end_comment

begin_comment
comment|///       decode all the aliases of the VGA I/O ranges and this selection must
end_comment

begin_comment
comment|///       be treated like EFI_RESERVE_ISA_IO_NO_ALIAS |
end_comment

begin_comment
comment|///       EFI_RESERVE_VGA_IO_ALIAS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_PCI_PLATFORM_POLICY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Does not set aside either ISA or VGA I/O resources during PCI
end_comment

begin_comment
comment|/// enumeration.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVE_NONE_IO_ALIAS
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets aside ISA I/O range and all aliases:
end_comment

begin_comment
comment|///   - n100..n3FF
end_comment

begin_comment
comment|///   - n500..n7FF
end_comment

begin_comment
comment|///   - n900..nBFF
end_comment

begin_comment
comment|///   - nD00..nFFF.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVE_ISA_IO_ALIAS
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets aside ISA I/O range 0x100-0x3FF.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVE_ISA_IO_NO_ALIAS
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets aside VGA I/O ranges and all aliases.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVE_VGA_IO_ALIAS
value|0x0004
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets aside VGA I/O ranges
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_RESERVE_VGA_IO_NO_ALIAS
value|0x0008
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PCI_EXECUTION_PHASE is used to call a platform protocol and execute
end_comment

begin_comment
comment|/// platform-specific code.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The phase that indicates the entry point to the PCI Bus Notify phase. This
comment|/// platform hook is called before the PCI bus driver calls the
comment|/// EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL driver.
comment|///
name|BeforePciHostBridge
init|=
literal|0
block|,
comment|///
comment|/// The phase that indicates the entry point to the PCI Bus Notify phase. This
comment|/// platform hook is called before the PCI bus driver calls the
comment|/// EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL driver.
comment|///
name|ChipsetEntry
init|=
literal|0
block|,
comment|///
comment|/// The phase that indicates the exit point to the Chipset Notify phase before
comment|/// returning to the PCI Bus Driver Notify phase. This platform hook is called after
comment|/// the PCI bus driver calls the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
comment|/// driver.
comment|///
name|AfterPciHostBridge
init|=
literal|1
block|,
comment|///
comment|/// The phase that indicates the exit point to the Chipset Notify phase before
comment|/// returning to the PCI Bus Driver Notify phase. This platform hook is called after
comment|/// the PCI bus driver calls the EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PROTOCOL
comment|/// driver.
comment|///
name|ChipsetExit
init|=
literal|1
block|,
name|MaximumChipsetPhase
block|}
name|EFI_PCI_EXECUTION_PHASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_PCI_EXECUTION_PHASE
name|EFI_PCI_CHIPSET_EXECUTION_PHASE
typedef|;
end_typedef

begin_comment
comment|/**   The notification from the PCI bus enumerator to the platform that it is   about to enter a certain phase during the enumeration process.    The PlatformNotify() function can be used to notify the platform driver so that   it can perform platform-specific actions. No specific actions are required.   Eight notification points are defined at this time. More synchronization points   may be added as required in the future. The PCI bus driver calls the platform driver   twice for every Phase-once before the PCI Host Bridge Resource Allocation Protocol   driver is notified, and once after the PCI Host Bridge Resource Allocation Protocol   driver has been notified.   This member function may not perform any error checking on the input parameters. It   also does not return any error codes. If this member function detects any error condition,   it needs to handle those errors on its own because there is no way to surface any   errors to the caller.    @param[in] This           The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.   @param[in] HostBridge     The handle of the host bridge controller.   @param[in] Phase          The phase of the PCI bus enumeration.   @param[in] ExecPhase      Defines the execution phase of the PCI chipset driver.    @retval EFI_SUCCESS   The function completed successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_PLATFORM_PHASE_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_PLATFORM_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|HostBridge
parameter_list|,
name|IN
name|EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE
name|Phase
parameter_list|,
name|IN
name|EFI_PCI_EXECUTION_PHASE
name|ExecPhase
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The notification from the PCI bus enumerator to the platform for each PCI   controller at several predefined points during PCI controller initialization.    The PlatformPrepController() function can be used to notify the platform driver so that   it can perform platform-specific actions. No specific actions are required.   Several notification points are defined at this time. More synchronization points may be   added as required in the future. The PCI bus driver calls the platform driver twice for   every PCI controller-once before the PCI Host Bridge Resource Allocation Protocol driver   is notified, and once after the PCI Host Bridge Resource Allocation Protocol driver has   been notified.   This member function may not perform any error checking on the input parameters. It also   does not return any error codes. If this member function detects any error condition, it   needs to handle those errors on its own because there is no way to surface any errors to   the caller.    @param[in] This           The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.   @param[in] HostBridge     The associated PCI host bridge handle.   @param[in] RootBridge     The associated PCI root bridge handle.   @param[in] PciAddress     The address of the PCI device on the PCI bus.   @param[in] Phase          The phase of the PCI controller enumeration.   @param[in] ExecPhase      Defines the execution phase of the PCI chipset driver.    @retval EFI_SUCCESS   The function completed successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_PLATFORM_PREPROCESS_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_PCI_PLATFORM_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|HostBridge
parameter_list|,
name|IN
name|EFI_HANDLE
name|RootBridge
parameter_list|,
name|IN
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS
name|PciAddress
parameter_list|,
name|IN
name|EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE
name|Phase
parameter_list|,
name|IN
name|EFI_PCI_EXECUTION_PHASE
name|ExecPhase
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the platform policy regarding enumeration.    The GetPlatformPolicy() function retrieves the platform policy regarding PCI   enumeration. The PCI bus driver and the PCI Host Bridge Resource Allocation Protocol   driver can call this member function to retrieve the policy.    @param[in]  This        The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.   @param[out] PciPolicy   The platform policy with respect to VGA and ISA aliasing.    @retval EFI_SUCCESS             The function completed successfully.   @retval EFI_INVALID_PARAMETER   PciPolicy is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_PLATFORM_GET_PLATFORM_POLICY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PCI_PLATFORM_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_PCI_PLATFORM_POLICY
modifier|*
name|PciPolicy
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the PCI device's option ROM from a platform-specific location.    The GetPciRom() function gets the PCI device's option ROM from a platform-specific location.   The option ROM will be loaded into memory. This member function is used to return an image   that is packaged as a PCI 2.2 option ROM. The image may contain both legacy and EFI option   ROMs. See the UEFI 2.0 Specification for details. This member function can be used to return   option ROM images for embedded controllers. Option ROMs for embedded controllers are typically   stored in platform-specific storage, and this member function can retrieve it from that storage   and return it to the PCI bus driver. The PCI bus driver will call this member function before   scanning the ROM that is attached to any controller, which allows a platform to specify a ROM   image that is different from the ROM image on a PCI card.    @param[in]  This        The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.   @param[in]  PciHandle   The handle of the PCI device.   @param[out] RomImage    If the call succeeds, the pointer to the pointer to the option ROM image.                           Otherwise, this field is undefined. The memory for RomImage is allocated                           by EFI_PCI_PLATFORM_PROTOCOL.GetPciRom() using the EFI Boot Service AllocatePool().                           It is the caller's responsibility to free the memory using the EFI Boot Service                           FreePool(), when the caller is done with the option ROM.   @param[out] RomSize     If the call succeeds, a pointer to the size of the option ROM size. Otherwise,                           this field is undefined.    @retval EFI_SUCCESS            The option ROM was available for this device and loaded into memory.   @retval EFI_NOT_FOUND          No option ROM was available for this device.   @retval EFI_OUT_OF_RESOURCES   No memory was available to load the option ROM.   @retval EFI_DEVICE_ERROR       An error occurred in obtaining the option ROM.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PCI_PLATFORM_GET_PCI_ROM
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PCI_PLATFORM_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|PciHandle
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|RomImage
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|RomSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the interface between the PCI bus driver/PCI Host
end_comment

begin_comment
comment|/// Bridge Resource Allocation driver and a platform-specific driver to describe
end_comment

begin_comment
comment|/// the unique features of a platform.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PCI_PLATFORM_PROTOCOL
block|{
comment|///
comment|/// The notification from the PCI bus enumerator to the platform that it is about to
comment|/// enter a certain phase during the enumeration process.
comment|///
name|EFI_PCI_PLATFORM_PHASE_NOTIFY
name|PlatformNotify
decl_stmt|;
comment|///
comment|/// The notification from the PCI bus enumerator to the platform for each PCI
comment|/// controller at several predefined points during PCI controller initialization.
comment|///
name|EFI_PCI_PLATFORM_PREPROCESS_CONTROLLER
name|PlatformPrepController
decl_stmt|;
comment|///
comment|/// Retrieves the platform policy regarding enumeration.
comment|///
name|EFI_PCI_PLATFORM_GET_PLATFORM_POLICY
name|GetPlatformPolicy
decl_stmt|;
comment|///
comment|/// Gets the PCI device's option ROM from a platform-specific location.
comment|///
name|EFI_PCI_PLATFORM_GET_PCI_ROM
name|GetPciRom
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciPlatformProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

