begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI Platform to Driver Configuration Protocol is defined in UEFI specification.      This is a protocol that is optionally produced by the platform and optionally consumed    by a UEFI Driver in its Start() function. This protocol allows the driver to receive    configuration information as part of being started.    Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PLATFORM_TO_DRIVER_CONFIGUARTION_H__
end_ifndef

begin_define
define|#
directive|define
name|__PLATFORM_TO_DRIVER_CONFIGUARTION_H__
end_define

begin_define
define|#
directive|define
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL_GUID
define|\
value|{ 0x642cd590, 0x8059, 0x4c0a, { 0xa9, 0x58, 0xc5, 0xec, 0x7, 0xd2, 0x3c, 0x4b } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The UEFI driver must call Query early in the Start() function   before any time consuming operations are performed. If   ChildHandle is NULL the driver is requesting information from   the platform about the ControllerHandle that is being started.   Information returned from Query may lead to the drivers Start()   function failing.   If the UEFI driver is a bus driver and producing a ChildHandle,   the driver must call Query after the child handle has been created   and an EFI_DEVICE_PATH_PROTOCOL has been placed on that handle,   but before any time consuming operation is performed. If information   return by Query may lead the driver to decide to not create the   ChildHandle. The driver must then cleanup and remove the ChildHandle   from the system.   The UEFI driver repeatedly calls Query, processes the information   returned by the platform, and calls Response passing in the   arguments returned from Query. The Instance value passed into   Response must be the same value passed into the corresponding   call to Query. The UEFI driver must continuously call Query and   Response until EFI_NOT_FOUND is returned by Query.   If the UEFI driver does not recognize the ParameterTypeGuid, it   calls Response with a ConfigurationAction of   EfiPlatformConfigurationActionUnsupportedGuid. The UEFI driver   must then continue calling Query and Response until EFI_NOT_FOUND   is returned by Query. This gives the platform an opportunity to   pass additional configuration settings using a different   ParameterTypeGuid that may be supported by the driver.   An Instance value of zero means return the first ParameterBlock   in the set of unprocessed parameter blocks. The driver should   increment the Instance value by one for each successive call to Query.    @param This                 A pointer to the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL instance.      @param ControllerHandle     The handle the platform will return                               configuration information about.      @param ChildHandle          The handle of the child controller to                               return information on. This is an optional                               parameter that may be NULL. It will be                               NULL for device drivers and for bus                               drivers that attempt to get options for                               the bus controller. It will not be NULL                               for a bus driver that attempts to get                               options for one of its child controllers.         @param Instance             Pointer to the Instance value. Zero means                               return the first query data. The caller should                               increment this value by one each time to retrieve                               successive data.    @param ParameterTypeGuid    An EFI_GUID that defines the contents                               of ParameterBlock. UEFI drivers must                               use the ParameterTypeGuid to determine                               how to parse the ParameterBlock. The caller                               should not attempt to free ParameterTypeGuid.    @param ParameterBlock       The platform returns a pointer to the                               ParameterBlock structure which                               contains details about the                               configuration parameters specific to                               the ParameterTypeGuid. This structure                               is defined based on the protocol and                               may be different for different                               protocols. UEFI driver decodes this                               structure and its contents based on                               ParameterTypeGuid. ParameterBlock is                               allocated by the platform and the                               platform is responsible for freeing                               the ParameterBlock after Result is                               called.    @param ParameterBlockSize   The platform returns the size of                               the ParameterBlock in bytes.     @retval EFI_SUCCESS           The platform return parameter                                 information for ControllerHandle.    @retval EFI_NOT_FOUND         No more unread Instance exists.    @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.    @retval EFI_INVALID_PARAMETER Instance is NULL.    @retval EFI_DEVICE_ERROR      A device error occurred while                                 attempting to return parameter block                                 information for the controller                                 specified by ControllerHandle and                                 ChildHandle.    @retval EFI_OUT_RESOURCES     There are not enough resources                                 available to set the configuration                                 options for the controller specified                                 by ControllerHandle and ChildHandle.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_QUERY
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|UINTN
modifier|*
name|Instance
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
modifier|*
name|ParameterTypeGuid
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|ParameterBlock
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ParameterBlockSize
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|///  The controller specified by ControllerHandle is still
comment|///  in a usable state, and its configuration has been updated
comment|///  via parsing the ParameterBlock. If required by the
comment|///  parameter block, and the module supports an NVRAM store,
comment|///  the configuration information from PB was successfully
comment|///  saved to the NVRAM. No actions are required before
comment|///  this controller can be used again with the updated
comment|///  configuration settings.
comment|///
name|EfiPlatformConfigurationActionNone
init|=
literal|0
block|,
comment|///
comment|///  The driver has detected that the controller specified
comment|///  by ControllerHandle is not in a usable state and
comment|///  needs to be stopped. The calling agent can use the
comment|///  DisconnectControservice to perform this operation, and
comment|///  it should be performed as soon as possible.
comment|///
name|EfiPlatformConfigurationActionStopController
init|=
literal|1
block|,
comment|///
comment|///  This controller specified by ControllerHandle needs to
comment|///  be stopped and restarted before it can be used again.
comment|///  The calling agent can use the DisconnectController()
comment|///  and ConnectController() services to perform this
comment|///  operation. The restart operation can be delayed until
comment|///  all of the configuration options have been set.
comment|///
name|EfiPlatformConfigurationActionRestartController
init|=
literal|2
block|,
comment|///
comment|///  A configuration change has been made that requires the
comment|///  platform to be restarted before the controller
comment|///  specified by ControllerHandle can be used again. The
comment|///  calling agent can use the ResetSystem() services to
comment|///  perform this operation. The restart operation can be
comment|///  delayed until all of the configuration options have
comment|///  been set.
comment|///
name|EfiPlatformConfigurationActionRestartPlatform
init|=
literal|3
block|,
comment|///
comment|///  The controller specified by ControllerHandle is still
comment|///  in a usable state; its configuration has been updated
comment|///  via parsing the ParameterBlock. The driver tried to
comment|///  update the driver's private NVRAM store with
comment|///  information from ParameterBlock and failed. No actions
comment|///  are required before this controller can be used again
comment|///  with the updated configuration settings, but these
comment|///  configuration settings are not guaranteed to persist
comment|///  after ControllerHandle is stopped.
comment|///
name|EfiPlatformConfigurationActionNvramFailed
init|=
literal|4
block|,
comment|///
comment|/// The controller specified by ControllerHandle is still
comment|/// in a usable state; its configuration has not been updated
comment|/// via parsing the ParameterBlock. The driver did not support
comment|/// the ParameterBlock format identified by ParameterTypeGuid.
comment|/// No actions are required before this controller can be used
comment|/// again. On additional Query calls from this ControllerHandle,
comment|/// the platform should stop returning a ParameterBlock
comment|/// qualified by this same ParameterTypeGuid. If no other
comment|/// ParameterTypeGuid is supported by the platform, Query
comment|/// should return EFI_NOT_FOUND.
comment|///
name|EfiPlatformConfigurationActionUnsupportedGuid
init|=
literal|5
block|,
name|EfiPlatformConfigurationActionMaximum
block|}
name|EFI_PLATFORM_CONFIGURATION_ACTION
typedef|;
end_typedef

begin_comment
comment|/**   The UEFI driver repeatedly calls Query, processes the   information returned by the platform, and calls Response passing   in the arguments returned from Query. The UEFI driver must   continuously call Query until EFI_NOT_FOUND is returned. For   every call to Query that returns EFI_SUCCESS a corrisponding   call to Response is required passing in the same   ContollerHandle, ChildHandle, Instance, ParameterTypeGuid,   ParameterBlock, and ParameterBlockSize. The UEFI driver may   update values in ParameterBlock based on rules defined by   ParameterTypeGuid. The platform is responsible for freeing   ParameterBlock and the UEFI driver must not try to free it.    @param This                A pointer to the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL instance.    @param ControllerHandle    The handle the driver is returning                              configuration information about.    @param ChildHandle         The handle of the child controller to                              return information on. This is an optional                              parameter that may be NULL. It will be                              NULL for device drivers, and for bus                              drivers that attempt to get options for                              the bus controller. It will not be NULL                              for a bus driver that attempts to get                              options for one of its child controllers.                              Instance Instance data returned from                              Query().    @param Instance            Instance data passed to Query().    @param ParameterTypeGuid   ParameterTypeGuid returned from Query.    @param ParameterBlock      ParameterBlock returned from Query.    @param ParameterBlockSize  The ParameterBlock size returned from Query.    @param ConfigurationAction The driver tells the platform what                              action is required for ParameterBlock to                              take effect.         @retval EFI_SUCCESS           The platform return parameter information                                 for ControllerHandle.      @retval EFI_NOT_FOUND         Instance was not found.      @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.     @retval EFI_INVALID_PARAMETER Instance is zero.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_RESPONSE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|UINTN
modifier|*
name|Instance
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ParameterTypeGuid
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|ParameterBlock
parameter_list|,
name|IN
name|CONST
name|UINTN
name|ParameterBlockSize
parameter_list|,
name|IN
name|CONST
name|EFI_PLATFORM_CONFIGURATION_ACTION
name|ConfigurationAction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL is used by the
end_comment

begin_comment
comment|/// UEFI driver to query the platform for configuration information.
end_comment

begin_comment
comment|/// The UEFI driver calls Query() multiple times to get
end_comment

begin_comment
comment|/// configuration information from the platform. For every call to
end_comment

begin_comment
comment|/// Query() there must be a matching call to Response() so the
end_comment

begin_comment
comment|/// UEFI driver can inform the platform how it used the
end_comment

begin_comment
comment|/// information passed in from Query(). It's legal for a UEFI
end_comment

begin_comment
comment|/// driver to use Response() to inform the platform it does not
end_comment

begin_comment
comment|/// understand the data returned via Query() and thus no action was
end_comment

begin_comment
comment|/// taken.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL
block|{
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_QUERY
name|Query
decl_stmt|;
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_RESPONSE
name|Response
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EFI_PLATFORM_TO_DRIVER_CONFIGURATION_CLP_GUID
define|\
value|{0x345ecc0e, 0xcb6, 0x4b75, { 0xbb, 0x57, 0x1b, 0x12, 0x9c, 0x47, 0x33,0x3e } }
end_define

begin_comment
comment|/**       ParameterTypeGuid provides the support for parameters   communicated through the DMTF SM CLP Specification 1.0 Final   Standard to be used to configure the UEFI driver. In this   section the producer of the   EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL is platform   firmware and the consumer is the UEFI driver. Note: if future   versions of the DMTF SM CLP Specification require changes to the   parameter block definition, a newer ParameterTypeGuid will be   used. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CHAR8
modifier|*
name|CLPCommand
decl_stmt|;
comment|///<  A pointer to the null-terminated UTF-8 string that specifies the DMTF SM CLP command
comment|///<  line that the driver is required to parse and process when this function is called.
comment|///<  See the DMTF SM CLP Specification 1.0 Final Standard for details on the
comment|///<  format and syntax of the CLP command line string. CLPCommand buffer
comment|///<  is allocated by the producer of the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOOL.
name|UINT32
name|CLPCommandLength
decl_stmt|;
comment|///< The length of the CLP Command in bytes.
name|CHAR8
modifier|*
name|CLPReturnString
decl_stmt|;
comment|///<  A pointer to the null-terminated UTF-8 string that indicates the CLP return status
comment|///<  that the driver is required to provide to the calling agent.
comment|///<  The calling agent may parse and/ or pass
comment|///<  this for processing and user feedback. The SM CLP Command Response string
comment|///<  buffer is filled in by the UEFI driver in the "keyword=value" format
comment|///<  described in the SM CLP Specification, unless otherwise requested via the SM
comment|///<  CLP Coutput option in the Command Line string buffer. UEFI driver's support
comment|///<  for this default "keyword=value" output format is required if the UEFI
comment|///<  driver supports this protocol, while support for other SM CLP output
comment|///<  formats is optional (the UEFI Driver should return an EFI_UNSUPPORTED if
comment|///<  the SM CLP Coutput option requested by the caller is not supported by the
comment|///<  UEFI Driver). CLPReturnString buffer is allocated by the consumer of the
comment|///<  EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOC OL and undefined prior to the call to
comment|///<  Response().
name|UINT32
name|CLPReturnStringLength
decl_stmt|;
comment|///< The length of the CLP return status string in bytes.
name|UINT8
name|CLPCmdStatus
decl_stmt|;
comment|///<  SM CLP Command Status (see DMTF SM CLP Specification 1.0 Final Standard -
comment|///<  Table 4) CLPErrorValue SM CLP Processing Error Value (see DMTF SM
comment|///<  CLP Specification 1.0 Final Standard - Table 6). This field is filled in by
comment|///<  the consumer of the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOC
comment|///<  OL and undefined prior to the call to Response().
name|UINT8
name|CLPErrorValue
decl_stmt|;
comment|///<  SM CLP Processing Error Value (see DMTF SM CLP Specification 1.0 Final Standard - Table 6).
comment|///<  This field is filled in by the consumer of the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL and undefined prior to the call to Response().
name|UINT16
name|CLPMsgCode
decl_stmt|;
comment|///<  Bit 15: OEM Message Code Flag 0 = Message Code is an SM CLP Probable
comment|///<  Cause Value. (see SM CLP Specification Table 11) 1 = Message Code is OEM
comment|///<  Specific Bits 14-0: Message Code This field is filled in by the consumer of
comment|///<  the EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOC OL and undefined prior to the call to
comment|///<  Response().
block|}
name|EFI_CONFIGURE_CLP_PARAMETER_BLK
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPlatformToDriverConfigurationClpGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPlatformToDriverConfigurationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

