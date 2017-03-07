begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares EFI IDE Controller Init Protocol      The EFI_IDE_CONTROLLER_INIT_PROTOCOL provides the chipset-specific information   to the driver entity. This protocol is mandatory for IDE controllers if the   IDE devices behind the controller are to be enumerated by a driver entity.      There can only be one instance of EFI_IDE_CONTROLLER_INIT_PROTOCOL for each IDE   controller in a system. It is installed on the handle that corresponds to the   IDE controller. A driver entity that wishes to manage an IDE bus and possibly   IDE devices in a system will have to retrieve the EFI_IDE_CONTROLLER_INIT_PROTOCOL   instance that is associated with the controller to be managed.      A device handle for an IDE controller must contain an EFI_DEVICE_PATH_PROTOCOL.  Copyright (c) 2007 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2    Volume 5: Standards.    **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_IDE_CONTROLLER_INIT_PROTOCOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_IDE_CONTROLLER_INIT_PROTOCOL_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Atapi.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_IDE_CONTROLLER_INIT_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL_GUID
define|\
value|{ \     0xa1e37052, 0x80d9, 0x4e65, {0xa3, 0x17, 0x3e, 0x9a, 0x55, 0xc4, 0x3e, 0xc9 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_IDE_CONTROLLER_INIT_PROTOCOL.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_IDE_CONTROLLER_INIT_PROTOCOL
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The phase of the IDE Controller enumeration.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The driver entity is about to begin enumerating the devices
comment|/// behind the specified channel. This notification can be used to
comment|/// perform any chipset-specific programming.
comment|///
name|EfiIdeBeforeChannelEnumeration
block|,
comment|///
comment|/// The driver entity has completed enumerating the devices
comment|/// behind the specified channel. This notification can be used to
comment|/// perform any chipset-specific programming.
comment|///
name|EfiIdeAfterChannelEnumeration
block|,
comment|///
comment|/// The driver entity is about to reset the devices behind the
comment|/// specified channel. This notification can be used to perform any
comment|/// chipset-specific programming.
comment|///
name|EfiIdeBeforeChannelReset
block|,
comment|///
comment|/// The driver entity has completed resetting the devices behind
comment|/// the specified channel. This notification can be used to perform
comment|/// any chipset-specific programming.
comment|///
name|EfiIdeAfterChannelReset
block|,
comment|///
comment|/// The driver entity is about to detect the presence of devices
comment|/// behind the specified channel. This notification can be used to
comment|/// set up the bus signals to default levels or for implementing
comment|/// predelays.
comment|///
name|EfiIdeBusBeforeDevicePresenceDetection
block|,
comment|///
comment|/// The driver entity is done with detecting the presence of
comment|/// devices behind the specified channel. This notification can be
comment|/// used to perform any chipset-specific programming.
comment|///
name|EfiIdeBusAfterDevicePresenceDetection
block|,
comment|///
comment|/// The IDE bus is requesting the IDE controller driver to
comment|/// reprogram the IDE controller hardware and thereby reset all
comment|/// the mode and timing settings to default settings.
comment|///
name|EfiIdeResetMode
block|,
name|EfiIdeBusPhaseMaximum
block|}
name|EFI_IDE_CONTROLLER_ENUM_PHASE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended mode describes the SATA physical protocol.
end_comment

begin_comment
comment|/// SATA physical layers can operate at different speeds.
end_comment

begin_comment
comment|/// These speeds are defined below. Various PATA protocols
end_comment

begin_comment
comment|/// and associated modes are not applicable to SATA devices.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiAtaSataTransferProtocol
block|}
name|EFI_ATA_EXT_TRANSFER_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Automatically detects the optimum SATA speed.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SATA_AUTO_SPEED
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates a first-generation (Gen1) SATA speed.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SATA_GEN1_SPEED
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Indicates a second-generation (Gen2) SATA speed.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SATA_GEN2_SPEED
value|2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ATA_MODE structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|Valid
decl_stmt|;
comment|///< TRUE if Mode is valid.
name|UINT32
name|Mode
decl_stmt|;
comment|///< The actual ATA mode. This field is not a bit map.
block|}
name|EFI_ATA_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ATA_EXTENDED_MODE structure
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// An enumeration defining various transfer protocols other than the protocols
comment|/// that exist at the time this specification was developed (i.e., PIO, single
comment|/// word DMA, multiword DMA, and UDMA). Each transfer protocol is associated
comment|/// with a mode. The various transfer protocols are defined by the ATA/ATAPI
comment|/// specification. This enumeration makes the interface extensible because we
comment|/// can support new transport protocols beyond UDMA. Type EFI_ATA_EXT_TRANSFER_PROTOCOL
comment|/// is defined below.
comment|///
name|EFI_ATA_EXT_TRANSFER_PROTOCOL
name|TransferProtocol
decl_stmt|;
comment|///
comment|/// The mode for operating the transfer protocol that is identified by TransferProtocol.
comment|///
name|UINT32
name|Mode
decl_stmt|;
block|}
name|EFI_ATA_EXTENDED_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ATA_COLLECTIVE_MODE structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// This field specifies the PIO mode. PIO modes are defined in the ATA/ATAPI
comment|/// specification. The ATA/ATAPI specification defines the enumeration.  In
comment|/// other words, a value of 1 in this field means PIO mode 1. The actual meaning
comment|/// of PIO mode 1 is governed by the ATA/ATAPI specification. Type EFI_ATA_MODE
comment|/// is defined below.
comment|///
name|EFI_ATA_MODE
name|PioMode
decl_stmt|;
comment|///
comment|/// This field specifies the single word DMA mode. Single word DMA modes are defined
comment|/// in the ATA/ATAPI specification, versions 1 and 2. Single word DMA support was
comment|/// obsoleted in the ATA/ATAPI specification, version 3. Therefore, most devices and
comment|/// controllers will not support this transfer mode. The ATA/ATAPI specification defines
comment|/// the enumeration. In other words, a value of 1 in this field means single word DMA
comment|/// mode 1. The actual meaning of single word DMA mode 1 is governed by the ATA/
comment|/// ATAPI specification.
comment|///
name|EFI_ATA_MODE
name|SingleWordDmaMode
decl_stmt|;
comment|///
comment|/// This field specifies the multiword DMA mode. Various multiword DMA modes are
comment|/// defined in the ATA/ATAPI specification. A value of 1 in this field means multiword
comment|/// DMA mode 1. The actual meaning of multiword DMA mode 1 is governed by the
comment|/// ATA/ATAPI specification.
comment|///
name|EFI_ATA_MODE
name|MultiWordDmaMode
decl_stmt|;
comment|///
comment|/// This field specifies the ultra DMA (UDMA) mode. UDMA modes are defined in the
comment|/// ATA/ATAPI specification. A value of 1 in this field means UDMA mode 1. The
comment|/// actual meaning of UDMA mode 1 is governed by the ATA/ATAPI specification.
comment|///
name|EFI_ATA_MODE
name|UdmaMode
decl_stmt|;
comment|///
comment|/// The number of extended-mode bitmap entries. Extended modes describe transfer
comment|/// protocols beyond PIO, single word DMA, multiword DMA, and UDMA. This field
comment|/// can be zero and provides extensibility.
comment|///
name|UINT32
name|ExtModeCount
decl_stmt|;
comment|///
comment|/// ExtModeCount number of entries. Each entry represents a transfer protocol other
comment|/// than the ones defined above (i.e., PIO, single word DMA, multiword DMA, and
comment|/// UDMA). This field is defined for extensibility. At this time, only one extended
comment|/// transfer protocol is defined to cover SATA transfers. Type
comment|/// EFI_ATA_EXTENDED_MODE is defined below.
comment|///
name|EFI_ATA_EXTENDED_MODE
name|ExtMode
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_ATA_COLLECTIVE_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_ATA_IDENTIFY_DATA& EFI_ATAPI_IDENTIFY_DATA structure
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The definition of these two structures is not part of the protocol
end_comment

begin_comment
comment|/// definition because the ATA/ATAPI Specification controls the definition
end_comment

begin_comment
comment|/// of all the fields. The ATA/ATAPI Specification can obsolete old fields
end_comment

begin_comment
comment|/// or redefine existing fields.
end_comment

begin_typedef
typedef|typedef
name|ATA_IDENTIFY_DATA
name|EFI_ATA_IDENTIFY_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ATAPI_IDENTIFY_DATA
name|EFI_ATAPI_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This flag indicates whether the IDENTIFY data is a response from an ATA device
end_comment

begin_comment
comment|/// (EFI_ATA_IDENTIFY_DATA) or response from an ATAPI device
end_comment

begin_comment
comment|/// (EFI_ATAPI_IDENTIFY_DATA).  According to the ATA/ATAPI specification,
end_comment

begin_comment
comment|/// EFI_IDENTIFY_DATA is for an ATA device if bit 15 of the Config field is zero.
end_comment

begin_comment
comment|/// The Config field is common to both EFI_ATA_IDENTIFY_DATA and
end_comment

begin_comment
comment|/// EFI_ATAPI_IDENTIFY_DATA.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ATAPI_DEVICE_IDENTIFY_DATA
value|0x8000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IDENTIFY_DATA structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// The data that is returned by an ATA device upon successful completion
comment|/// of the ATA IDENTIFY_DEVICE command.
comment|///
name|EFI_ATA_IDENTIFY_DATA
name|AtaData
decl_stmt|;
comment|///
comment|/// The data that is returned by an ATAPI device upon successful completion
comment|/// of the ATA IDENTIFY_PACKET_DEVICE command.
comment|///
name|EFI_ATAPI_IDENTIFY_DATA
name|AtapiData
decl_stmt|;
block|}
name|EFI_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Returns the information about the specified IDE channel.      This function can be used to obtain information about a particular IDE channel.   The driver entity uses this information during the enumeration process.       If Enabled is set to FALSE, the driver entity will not scan the channel. Note    that it will not prevent an operating system driver from scanning the channel.      For most of today's controllers, MaxDevices will either be 1 or 2. For SATA    controllers, this value will always be 1. SATA configurations can contain SATA    port multipliers. SATA port multipliers behave like SATA bridges and can support   up to 16 devices on the other side. If a SATA port out of the IDE controller    is connected to a port multiplier, MaxDevices will be set to the number of SATA    devices that the port multiplier supports. Because today's port multipliers    support up to fifteen SATA devices, this number can be as large as fifteen. The IDE     bus driver is required to scan for the presence of port multipliers behind an SATA    controller and enumerate up to MaxDevices number of devices behind the port    multiplier.          In this context, the devices behind a port multiplier constitute a channel.        @param[in]  This         The pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in]  Channel      Zero-based channel number.   @param[out] Enabled      TRUE if this channel is enabled.  Disabled channels                             are not scanned to see if any devices are present.   @param[out] MaxDevices   The maximum number of IDE devices that the bus driver                            can expect on this channel.  For the ATA/ATAPI                             specification, version 6, this number will either be                             one or two. For Serial ATA (SATA) configurations with a                             port multiplier, this number can be as large as fifteen.    @retval EFI_SUCCESS             Information was returned without any errors.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_GET_CHANNEL_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|Enabled
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|MaxDevices
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The notifications from the driver entity that it is about to enter a certain   phase of the IDE channel enumeration process.      This function can be used to notify the IDE controller driver to perform    specific actions, including any chipset-specific initialization, so that the    chipset is ready to enter the next phase. Seven notification points are defined    at this time.       More synchronization points may be added as required in the future.      @param[in] This      The pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in] Phase     The phase during enumeration.   @param[in] Channel   Zero-based channel number.    @retval EFI_SUCCESS             The notification was accepted without any errors.   @retval EFI_UNSUPPORTED         Phase is not supported.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).   @retval EFI_NOT_READY           This phase cannot be entered at this time; for                                    example, an attempt was made to enter a Phase                                    without having entered one or more previous                                    Phase.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_NOTIFY_PHASE
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_IDE_CONTROLLER_ENUM_PHASE
name|Phase
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Submits the device information to the IDE controller driver.    This function is used by the driver entity to pass detailed information about    a particular device to the IDE controller driver. The driver entity obtains    this information by issuing an ATA or ATAPI IDENTIFY_DEVICE command. IdentifyData   is the pointer to the response data buffer. The IdentifyData buffer is owned    by the driver entity, and the IDE controller driver must make a local copy    of the entire buffer or parts of the buffer as needed. The original IdentifyData    buffer pointer may not be valid when        - EFI_IDE_CONTROLLER_INIT_PROTOCOL.CalculateMode() or     - EFI_IDE_CONTROLLER_INIT_PROTOCOL.DisqualifyMode() is called at a later point.        The IDE controller driver may consult various fields of EFI_IDENTIFY_DATA to    compute the optimum mode for the device. These fields are not limited to the    timing information. For example, an implementation of the IDE controller driver    may examine the vendor and type/mode field to match known bad drives.        The driver entity may submit drive information in any order, as long as it    submits information for all the devices belonging to the enumeration group    before EFI_IDE_CONTROLLER_INIT_PROTOCOL.CalculateMode() is called for any device   in that enumeration group. If a device is absent, EFI_IDE_CONTROLLER_INIT_PROTOCOL.SubmitData()   should be called with IdentifyData set to NULL.  The IDE controller driver may    not have any other mechanism to know whether a device is present or not. Therefore,    setting IdentifyData to NULL does not constitute an error condition.    EFI_IDE_CONTROLLER_INIT_PROTOCOL.SubmitData() can be called only once for a    given (Channel, Device) pair.          @param[in] This           A pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in] Channel        Zero-based channel number.   @param[in] Device         Zero-based device number on the Channel.   @param[in] IdentifyData   The device's response to the ATA IDENTIFY_DEVICE command.    @retval EFI_SUCCESS             The information was accepted without any errors.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).   @retval EFI_INVALID_PARAMETER   Device is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_SUBMIT_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|,
name|IN
name|UINT8
name|Device
parameter_list|,
name|IN
name|EFI_IDENTIFY_DATA
modifier|*
name|IdentifyData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disqualifies specific modes for an IDE device.    This function allows the driver entity or other drivers (such as platform    drivers) to reject certain timing modes and request the IDE controller driver   to recalculate modes. This function allows the driver entity and the IDE    controller driver to negotiate the timings on a per-device basis. This function    is useful in the case of drives that lie about their capabilities. An example    is when the IDE device fails to accept the timing modes that are calculated    by the IDE controller driver based on the response to the Identify Drive command.    If the driver entity does not want to limit the ATA timing modes and leave that    decision to the IDE controller driver, it can either not call this function for    the given device or call this function and set the Valid flag to FALSE for all    modes that are listed in EFI_ATA_COLLECTIVE_MODE.      The driver entity may disqualify modes for a device in any order and any number    of times.      This function can be called multiple times to invalidate multiple modes of the    same type (e.g., Programmed Input/Output [PIO] modes 3 and 4). See the ATA/ATAPI    specification for more information on PIO modes.        For Serial ATA (SATA) controllers, this member function can be used to disqualify   a higher transfer rate mode on a given channel. For example, a platform driver   may inform the IDE controller driver to not use second-generation (Gen2) speeds    for a certain SATA drive.      @param[in] This       The pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in] Channel    The zero-based channel number.   @param[in] Device     The zero-based device number on the Channel.   @param[in] BadModes   The modes that the device does not support and that                         should be disqualified.    @retval EFI_SUCCESS             The modes were accepted without any errors.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).   @retval EFI_INVALID_PARAMETER   Device is invalid.   @retval EFI_INVALID_PARAMETER   IdentifyData is NULL.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_DISQUALIFY_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|,
name|IN
name|UINT8
name|Device
parameter_list|,
name|IN
name|EFI_ATA_COLLECTIVE_MODE
modifier|*
name|BadModes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the information about the optimum modes for the specified IDE device.    This function is used by the driver entity to obtain the optimum ATA modes for   a specific device.  The IDE controller driver takes into account the following    while calculating the mode:     - The IdentifyData inputs to EFI_IDE_CONTROLLER_INIT_PROTOCOL.SubmitData()     - The BadModes inputs to EFI_IDE_CONTROLLER_INIT_PROTOCOL.DisqualifyMode()    The driver entity is required to call EFI_IDE_CONTROLLER_INIT_PROTOCOL.SubmitData()    for all the devices that belong to an enumeration group before calling    EFI_IDE_CONTROLLER_INIT_PROTOCOL.CalculateMode() for any device in the same group.        The IDE controller driver will use controller- and possibly platform-specific    algorithms to arrive at SupportedModes.  The IDE controller may base its    decision on user preferences and other considerations as well. This function    may be called multiple times because the driver entity may renegotiate the mode    with the IDE controller driver using EFI_IDE_CONTROLLER_INIT_PROTOCOL.DisqualifyMode().        The driver entity may collect timing information for various devices in any    order. The driver entity is responsible for making sure that all the dependencies   are satisfied. For example, the SupportedModes information for device A that    was previously returned may become stale after a call to    EFI_IDE_CONTROLLER_INIT_PROTOCOL.DisqualifyMode() for device B.      The buffer SupportedModes is allocated by the callee because the caller does    not necessarily know the size of the buffer. The type EFI_ATA_COLLECTIVE_MODE    is defined in a way that allows for future extensibility and can be of variable    length. This memory pool should be deallocated by the caller when it is no    longer necessary.        The IDE controller driver for a Serial ATA (SATA) controller can use this    member function to force a lower speed (first-generation [Gen1] speeds on a    second-generation [Gen2]-capable hardware).  The IDE controller driver can    also allow the driver entity to stay with the speed that has been negotiated    by the physical layer.      @param[in]  This             The pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in]  Channel          A zero-based channel number.   @param[in]  Device           A zero-based device number on the Channel.   @param[out] SupportedModes   The optimum modes for the device.    @retval EFI_SUCCESS             SupportedModes was returned.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).   @retval EFI_INVALID_PARAMETER   Device is invalid.    @retval EFI_INVALID_PARAMETER   SupportedModes is NULL.   @retval EFI_NOT_READY           Modes cannot be calculated due to a lack of                                    data.  This error may happen if                                    EFI_IDE_CONTROLLER_INIT_PROTOCOL.SubmitData()                                    and EFI_IDE_CONTROLLER_INIT_PROTOCOL.DisqualifyData()                                    were not called for at least one drive in the                                    same enumeration group.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_CALCULATE_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|,
name|IN
name|UINT8
name|Device
parameter_list|,
name|OUT
name|EFI_ATA_COLLECTIVE_MODE
modifier|*
modifier|*
name|SupportedModes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Commands the IDE controller driver to program the IDE controller hardware   so that the specified device can operate at the specified mode.    This function is used by the driver entity to instruct the IDE controller    driver to program the IDE controller hardware to the specified modes. This    function can be called only once for a particular device. For a Serial ATA    (SATA) Advanced Host Controller Interface (AHCI) controller, no controller-   specific programming may be required.    @param[in] This      Pointer to the EFI_IDE_CONTROLLER_INIT_PROTOCOL instance.   @param[in] Channel   Zero-based channel number.   @param[in] Device    Zero-based device number on the Channel.   @param[in] Modes     The modes to set.    @retval EFI_SUCCESS             The command was accepted without any errors.   @retval EFI_INVALID_PARAMETER   Channel is invalid (Channel>= ChannelCount).   @retval EFI_INVALID_PARAMETER   Device is invalid.   @retval EFI_NOT_READY           Modes cannot be set at this time due to lack of data.   @retval EFI_DEVICE_ERROR        Modes cannot be set due to hardware failure.                                   The driver entity should not use this device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IDE_CONTROLLER_SET_TIMING
function_decl|)
parameter_list|(
name|IN
name|EFI_IDE_CONTROLLER_INIT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|Channel
parameter_list|,
name|IN
name|UINT8
name|Device
parameter_list|,
name|IN
name|EFI_ATA_COLLECTIVE_MODE
modifier|*
name|Modes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides the basic interfaces to abstract an IDE controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_IDE_CONTROLLER_INIT_PROTOCOL
block|{
comment|///
comment|/// Returns the information about a specific channel.
comment|///
name|EFI_IDE_CONTROLLER_GET_CHANNEL_INFO
name|GetChannelInfo
decl_stmt|;
comment|///
comment|/// The notification that the driver entity is about to enter the
comment|/// specified phase during the enumeration process.
comment|///
name|EFI_IDE_CONTROLLER_NOTIFY_PHASE
name|NotifyPhase
decl_stmt|;
comment|///
comment|/// Submits the Drive Identify data that was returned by the device.
comment|///
name|EFI_IDE_CONTROLLER_SUBMIT_DATA
name|SubmitData
decl_stmt|;
comment|///
comment|/// Submits information about modes that should be disqualified.  The specified
comment|/// IDE device does not support these modes and these modes should not be
comment|/// returned by EFI_IDE_CONTROLLER_INIT_PROTOCOL.CalculateMode()
comment|///
name|EFI_IDE_CONTROLLER_DISQUALIFY_MODE
name|DisqualifyMode
decl_stmt|;
comment|///
comment|/// Calculates and returns the optimum mode for a particular IDE device.
comment|///
name|EFI_IDE_CONTROLLER_CALCULATE_MODE
name|CalculateMode
decl_stmt|;
comment|///
comment|/// Programs the IDE controller hardware to the default timing or per the modes
comment|/// that were returned by the last call to EFI_IDE_CONTROLLER_INIT_PROTOCOL.CalculateMode().
comment|///
name|EFI_IDE_CONTROLLER_SET_TIMING
name|SetTiming
decl_stmt|;
comment|///
comment|/// Set to TRUE if the enumeration group includes all the channels that are
comment|/// produced by this controller. Set to FALSE if an enumeration group consists of
comment|/// only one channel.
comment|///
name|BOOLEAN
name|EnumAll
decl_stmt|;
comment|///
comment|/// The number of channels that are produced by this controller. Parallel ATA
comment|/// (PATA) controllers can support up to two channels. Advanced Host Controller
comment|/// Interface (AHCI) Serial ATA (SATA) controllers can support up to 32 channels,
comment|/// each of which can have up to one device. In the presence of a multiplier,
comment|/// each channel can have fifteen devices.
comment|///
name|UINT8
name|ChannelCount
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIdeControllerInitProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

