begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Driver Health Protocol definitions.    When installed, the Driver Health Protocol produces a collection of services that allow   the health status for a controller to be retrieved. If a controller is not in a usable   state, status messages may be reported to the user, repair operations can be invoked,   and the user may be asked to make software and/or hardware configuration changes.      The Driver Health Protocol is optionally produced by a driver that follows the    EFI Driver Model.  If an EFI Driver needs to report health status to the platform,    provide warning or error messages to the user, perform length repair operations,    or request the user to make hardware or software configuration changes, then the    Driver Health Protocol must be produced.     A controller that is managed by driver that follows the EFI Driver Model and    produces the Driver Health Protocol must report the current health of the    controllers that the driver is currently managing.  The controller can initially    be healthy, failed, require repair, or require configuration.  If a controller    requires configuration, and the user make configuration changes, the controller    may then need to be reconnected or the system may need to be rebooted for the    configuration changes to take affect.     Copyright (c) 2009 - 2013, Intel Corporation. All rights reserved.<BR>   Copyright (c) 2014, Hewlett-Packard Development Company, L.P.<BR>     This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This Protocol is defined in UEFI Specification 2.3d   **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DRIVER_HEALTH_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DRIVER_HEALTH_H__
end_define

begin_define
define|#
directive|define
name|EFI_DRIVER_HEALTH_PROTOCOL_GUID
define|\
value|{ \     0x2a534210, 0x9280, 0x41d8, { 0xae, 0x79, 0xca, 0xda, 0x1, 0xa2, 0xb1, 0x27 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DRIVER_HEALTH_PROTOCOL
name|EFI_DRIVER_HEALTH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DRIVER_HEALTH_HEALTH_STATUS
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiDriverHealthStatusHealthy
block|,
name|EfiDriverHealthStatusRepairRequired
block|,
name|EfiDriverHealthStatusConfigurationRequired
block|,
name|EfiDriverHealthStatusFailed
block|,
name|EfiDriverHealthStatusReconnectRequired
block|,
name|EfiDriverHealthStatusRebootRequired
block|}
name|EFI_DRIVER_HEALTH_STATUS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DRIVER_HEALTH_HII_MESSAGE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HII_HANDLE
name|HiiHandle
decl_stmt|;
name|EFI_STRING_ID
name|StringId
decl_stmt|;
comment|///
comment|/// 64-bit numeric value of the warning/error specified by this message.
comment|///   A value of 0x0000000000000000 is used to indicate that MessageCode is not specified.
comment|///   The values  0x0000000000000001 to 0x0fffffffffffffff are reserved for allocation by the UEFI Specification.
comment|///   The values  0x1000000000000000 to 0x1fffffffffffffff are reserved for IHV-developed drivers.
comment|///   The values 0x8000000000000000 to 0x8fffffffffffffff is reserved for platform/OEM drivers.
comment|///   All other values are reserved and should not be used.
comment|///
name|UINT64
name|MessageCode
decl_stmt|;
block|}
name|EFI_DRIVER_HEALTH_HII_MESSAGE
typedef|;
end_typedef

begin_comment
comment|/**   Reports the progress of a repair operation    @param[in]  Value             A value between 0 and Limit that identifies the current                                  progress of the repair operation.      @param[in]  Limit             The maximum value of Value for the current repair operation.                                 For example, a driver that wants to specify progress in                                  percent would use a Limit value of 100. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_HEALTH_REPAIR_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|Value
parameter_list|,
name|IN
name|UINTN
name|Limit
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the health status of a controller in the platform.  This function can also    optionally return warning messages, error messages, and a set of HII Forms that may    be repair a controller that is not proper configured.       @param[in] This             A pointer to the EFI_DRIVER_HEALTH_PROTOCOL instance.    @param[in] ControllerHandle The handle of the controller to retrieve the health status                                on.  This is an optional parameter that may be NULL.  If                                this parameter is NULL, then the value of ChildHandle is                                ignored, and the combined health status of all the devices                                that the driver is managing is returned.    @param[in] ChildHandle      The handle of the child controller to retrieve the health                                status on.  This is an optional parameter that may be NULL.                                 This parameter is ignored of ControllerHandle is NULL.  It                                will be NULL for device drivers.  It will also be NULL for                                bus drivers when an attempt is made to collect the health                                status of the bus controller.  If will not be NULL when an                                attempt is made to collect the health status for a child                                controller produced by the driver.    @param[out] HealthStatus    A pointer to the health status that is returned by this                                function.  This is an optional parameter that may be NULL.                                 This parameter is ignored of ControllerHandle is NULL.                                 The health status for the controller specified by                                ControllerHandle and ChildHandle is returned.     @param[out] MessageList     A pointer to an array of warning or error messages associated                                with the controller specified by ControllerHandle and                                ChildHandle.  This is an optional parameter that may be NULL.                                 MessageList is allocated by this function with the EFI Boot                                Service AllocatePool(), and it is the caller's responsibility                                to free MessageList with the EFI Boot Service FreePool().                                 Each message is specified by tuple of an EFI_HII_HANDLE and                                an EFI_STRING_ID.  The array of messages is terminated by tuple                                containing a EFI_HII_HANDLE with a value of NULL.  The                                EFI_HII_STRING_PROTOCOL.GetString() function can be used to                                retrieve the warning or error message as a Null-terminated                                string in a specific language.  Messages may be                                returned for any of the HealthStatus values except                                EfiDriverHealthStatusReconnectRequired and                                EfiDriverHealthStatusRebootRequired.    @param[out] FormHiiHandle   A pointer to the HII handle containing the HII form used when                                configuration is required. The HII handle is associated with                                the controller specified by ControllerHandle and ChildHandle.                               If this is NULL, then no HII form is available. An HII handle                               will only be returned with a HealthStatus value of                                EfiDriverHealthStatusConfigurationRequired.    @retval EFI_SUCCESS           ControllerHandle is NULL, and all the controllers                                  managed by this driver specified by This have a health                                  status of EfiDriverHealthStatusHealthy with no warning                                  messages to be returned.  The ChildHandle, HealthStatus,                                  MessageList, and FormList parameters are ignored.    @retval EFI_DEVICE_ERROR      ControllerHandle is NULL, and one or more of the                                  controllers managed by this driver specified by This                                  do not have a health status of EfiDriverHealthStatusHealthy.                                   The ChildHandle, HealthStatus, MessageList, and                                  FormList parameters are ignored.    @retval EFI_DEVICE_ERROR      ControllerHandle is NULL, and one or more of the                                  controllers managed by this driver specified by This                                  have one or more warning and/or error messages.                                   The ChildHandle, HealthStatus, MessageList, and                                  FormList parameters are ignored.    @retval EFI_SUCCESS           ControllerHandle is not NULL and the health status                                  of the controller specified by ControllerHandle and                                  ChildHandle was returned in HealthStatus.  A list                                  of warning and error messages may be optionally                                  returned in MessageList, and a list of HII Forms                                  may be optionally returned in FormList.    @retval EFI_UNSUPPORTED       ControllerHandle is not NULL, and the controller                                  specified by ControllerHandle and ChildHandle is not                                  currently being managed by the driver specified by This.    @retval EFI_INVALID_PARAMETER HealthStatus is NULL.    @retval EFI_OUT_OF_RESOURCES  MessageList is not NULL, and there are not enough                                  resource available to allocate memory for MessageList.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_HEALTH_GET_HEALTH_STATUS
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_HEALTH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_DRIVER_HEALTH_STATUS
modifier|*
name|HealthStatus
parameter_list|,
name|OUT
name|EFI_DRIVER_HEALTH_HII_MESSAGE
modifier|*
modifier|*
name|MessageList
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_HII_HANDLE
modifier|*
name|FormHiiHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Performs a repair operation on a controller in the platform.  This function can    optionally report repair progress information back to the platform.       @param[in] This              A pointer to the EFI_DRIVER_HEALTH_PROTOCOL instance.   @param[in] ControllerHandle  The handle of the controller to repair.   @param[in] ChildHandle       The handle of the child controller to repair.  This is                                 an optional parameter that may be NULL.  It will be NULL                                 for device drivers.  It will also be NULL for bus                                 drivers when an attempt is made to repair a bus controller.                                If will not be NULL when an attempt is made to repair a                                 child controller produced by the driver.   @param[in] RepairNotify      A notification function that may be used by a driver to                                 report the progress of the repair operation.  This is                                 an optional parameter that may be NULL.       @retval EFI_SUCCESS           An attempt to repair the controller specified by                                  ControllerHandle and ChildHandle was performed.                                   The result of the repair operation can bet                                  determined by calling GetHealthStatus().   @retval EFI_UNSUPPORTED       The driver specified by This is not currently                                  managing the controller specified by ControllerHandle                                  and ChildHandle.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to perform the                                  repair operation.  */
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_HEALTH_REPAIR
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_HEALTH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_DRIVER_HEALTH_REPAIR_NOTIFY
name|RepairNotify
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// When installed, the Driver Health Protocol produces a collection of services
end_comment

begin_comment
comment|/// that allow the health status for a controller to be retrieved.  If a controller
end_comment

begin_comment
comment|/// is not in a usable state, status messages may be reported to the user, repair
end_comment

begin_comment
comment|/// operations can be invoked, and the user may be asked to make software and/or
end_comment

begin_comment
comment|/// hardware configuration changes.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DRIVER_HEALTH_PROTOCOL
block|{
name|EFI_DRIVER_HEALTH_GET_HEALTH_STATUS
name|GetHealthStatus
decl_stmt|;
name|EFI_DRIVER_HEALTH_REPAIR
name|Repair
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDriverHealthProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

