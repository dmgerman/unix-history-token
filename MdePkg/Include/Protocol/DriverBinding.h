begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI DriverBinding Protocol is defined in UEFI specification.      This protocol is produced by every driver that follows the UEFI Driver Model,    and it is the central component that allows drivers and controllers to be managed.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_DRIVER_BINDING_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_DRIVER_BINDING_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The global ID for the ControllerHandle Driver Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DRIVER_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x18a031ab, 0xb443, 0x4d1a, {0xa5, 0xc0, 0xc, 0x9, 0x26, 0x1e, 0x9f, 0x71 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DRIVER_BINDING_PROTOCOL
name|EFI_DRIVER_BINDING_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Tests to see if this driver supports a given controller. If a child device is provided,    it further tests to see if this driver supports creating a handle for the specified child device.    This function checks to see if the driver specified by This supports the device specified by    ControllerHandle. Drivers will typically use the device path attached to    ControllerHandle and/or the services from the bus I/O abstraction attached to    ControllerHandle to determine if the driver supports ControllerHandle. This function    may be called many times during platform initialization. In order to reduce boot times, the tests    performed by this function must be very small, and take as little time as possible to execute. This    function must not change the state of any hardware devices, and this function must be aware that the    device specified by ControllerHandle may already be managed by the same driver or a    different driver. This function must match its calls to AllocatePages() with FreePages(),    AllocatePool() with FreePool(), and OpenProtocol() with CloseProtocol().     Because ControllerHandle may have been previously started by the same driver, if a protocol is    already in the opened state, then it must not be closed with CloseProtocol(). This is required    to guarantee the state of ControllerHandle is not modified by this function.    @param[in]  This                 A pointer to the EFI_DRIVER_BINDING_PROTOCOL instance.   @param[in]  ControllerHandle     The handle of the controller to test. This handle                                     must support a protocol interface that supplies                                     an I/O abstraction to the driver.   @param[in]  RemainingDevicePath  A pointer to the remaining portion of a device path.  This                                     parameter is ignored by device drivers, and is optional for bus                                     drivers. For bus drivers, if this parameter is not NULL, then                                     the bus driver must determine if the bus controller specified                                     by ControllerHandle and the child controller specified                                     by RemainingDevicePath are both supported by this                                     bus driver.    @retval EFI_SUCCESS              The device specified by ControllerHandle and                                    RemainingDevicePath is supported by the driver specified by This.   @retval EFI_ALREADY_STARTED      The device specified by ControllerHandle and                                    RemainingDevicePath is already being managed by the driver                                    specified by This.   @retval EFI_ACCESS_DENIED        The device specified by ControllerHandle and                                    RemainingDevicePath is already being managed by a different                                    driver or an application that requires exclusive access.                                    Currently not implemented.   @retval EFI_UNSUPPORTED          The device specified by ControllerHandle and                                    RemainingDevicePath is not supported by the driver specified by This. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_BINDING_SUPPORTED
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|RemainingDevicePath
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Starts a device controller or a bus controller.    The Start() function is designed to be invoked from the EFI boot service ConnectController().   As a result, much of the error checking on the parameters to Start() has been moved into this    common boot service. It is legal to call Start() from other locations,    but the following calling restrictions must be followed, or the system behavior will not be deterministic.   1. ControllerHandle must be a valid EFI_HANDLE.   2. If RemainingDevicePath is not NULL, then it must be a pointer to a naturally aligned      EFI_DEVICE_PATH_PROTOCOL.   3. Prior to calling Start(), the Supported() function for the driver specified by This must      have been called with the same calling parameters, and Supported() must have returned EFI_SUCCESS.      @param[in]  This                 A pointer to the EFI_DRIVER_BINDING_PROTOCOL instance.   @param[in]  ControllerHandle     The handle of the controller to start. This handle                                     must support a protocol interface that supplies                                     an I/O abstraction to the driver.   @param[in]  RemainingDevicePath  A pointer to the remaining portion of a device path.  This                                     parameter is ignored by device drivers, and is optional for bus                                     drivers. For a bus driver, if this parameter is NULL, then handles                                     for all the children of Controller are created by this driver.                                      If this parameter is not NULL and the first Device Path Node is                                     not the End of Device Path Node, then only the handle for the                                     child device specified by the first Device Path Node of                                     RemainingDevicePath is created by this driver.                                    If the first Device Path Node of RemainingDevicePath is                                     the End of Device Path Node, no child handle is created by this                                    driver.    @retval EFI_SUCCESS              The device was started.   @retval EFI_DEVICE_ERROR         The device could not be started due to a device error.Currently not implemented.   @retval EFI_OUT_OF_RESOURCES     The request could not be completed due to a lack of resources.   @retval Others                   The driver failded to start the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_BINDING_START
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|RemainingDevicePath
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Stops a device controller or a bus controller.      The Stop() function is designed to be invoked from the EFI boot service DisconnectController().    As a result, much of the error checking on the parameters to Stop() has been moved    into this common boot service. It is legal to call Stop() from other locations,    but the following calling restrictions must be followed, or the system behavior will not be deterministic.   1. ControllerHandle must be a valid EFI_HANDLE that was used on a previous call to this      same driver's Start() function.   2. The first NumberOfChildren handles of ChildHandleBuffer must all be a valid      EFI_HANDLE. In addition, all of these handles must have been created in this driver's      Start() function, and the Start() function must have called OpenProtocol() on      ControllerHandle with an Attribute of EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER.      @param[in]  This              A pointer to the EFI_DRIVER_BINDING_PROTOCOL instance.   @param[in]  ControllerHandle  A handle to the device being stopped. The handle must                                  support a bus specific I/O protocol for the driver                                  to use to stop the device.   @param[in]  NumberOfChildren  The number of child device handles in ChildHandleBuffer.   @param[in]  ChildHandleBuffer An array of child handles to be freed. May be NULL                                  if NumberOfChildren is 0.    @retval EFI_SUCCESS           The device was stopped.   @retval EFI_DEVICE_ERROR      The device could not be stopped due to a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DRIVER_BINDING_STOP
function_decl|)
parameter_list|(
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|UINTN
name|NumberOfChildren
parameter_list|,
name|IN
name|EFI_HANDLE
modifier|*
name|ChildHandleBuffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the services required to determine if a driver supports a given controller.
end_comment

begin_comment
comment|/// If a controller is supported, then it also provides routines to start and stop the controller.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DRIVER_BINDING_PROTOCOL
block|{
name|EFI_DRIVER_BINDING_SUPPORTED
name|Supported
decl_stmt|;
name|EFI_DRIVER_BINDING_START
name|Start
decl_stmt|;
name|EFI_DRIVER_BINDING_STOP
name|Stop
decl_stmt|;
comment|///
comment|/// The version number of the UEFI driver that produced the
comment|/// EFI_DRIVER_BINDING_PROTOCOL. This field is used by
comment|/// the EFI boot service ConnectController() to determine
comment|/// the order that driver's Supported() service will be used when
comment|/// a controller needs to be started. EFI Driver Binding Protocol
comment|/// instances with higher Version values will be used before ones
comment|/// with lower Version values. The Version values of 0x0-
comment|/// 0x0f and 0xfffffff0-0xffffffff are reserved for
comment|/// platform/OEM specific drivers. The Version values of 0x10-
comment|/// 0xffffffef are reserved for IHV-developed drivers.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// The image handle of the UEFI driver that produced this instance
comment|/// of the EFI_DRIVER_BINDING_PROTOCOL.
comment|///
name|EFI_HANDLE
name|ImageHandle
decl_stmt|;
comment|///
comment|/// The handle on which this instance of the
comment|/// EFI_DRIVER_BINDING_PROTOCOL is installed. In most
comment|/// cases, this is the same handle as ImageHandle. However, for
comment|/// UEFI drivers that produce more than one instance of the
comment|/// EFI_DRIVER_BINDING_PROTOCOL, this value may not be
comment|/// the same as ImageHandle.
comment|///
name|EFI_HANDLE
name|DriverBindingHandle
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDriverBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

