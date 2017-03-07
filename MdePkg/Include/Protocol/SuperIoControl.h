begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The Super I/O Control Protocol is installed by the Super I/O driver. It provides   the low-level services for SIO devices that enable them to be used in the UEFI   driver model.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This protocol is from PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SUPER_IO_CONTROL_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SUPER_IO_CONTROL_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIO_CONTROL_PROTOCOL_GUID
define|\
value|{ \     0xb91978df, 0x9fc1, 0x427d, { 0xbb, 0x5, 0x4c, 0x82, 0x84, 0x55, 0xca, 0x27 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIO_CONTROL_PROTOCOL
name|EFI_SIO_CONTROL_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIO_CONTROL_PROTOCOL
modifier|*
name|PEFI_SIO_CONTROL_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Enable an ISA-style device.    This function enables a logical ISA device and, if necessary, configures it   to default settings, including memory, I/O, DMA and IRQ resources.    @param This A pointer to this instance of the EFI_SIO_CONTROL_PROTOCOL.    @retval EFI_SUCCESS          The device is enabled successfully.   @retval EFI_OUT_OF_RESOURCES The device could not be enabled because there                                were insufficient resources either for the device                                 itself or for the records needed to track the device.   @retval EFI_ALREADY_STARTED  The device is already enabled.   @retval EFI_UNSUPPORTED      The device cannot be enabled. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIO_CONTROL_ENABLE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SIO_CONTROL_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disable a logical ISA device.    This function disables a logical ISA device so that it no longer consumes   system resources, such as memory, I/O, DMA and IRQ resources. Enough information   must be available so that subsequent Enable() calls would properly reconfigure   the device.    @param This A pointer to this instance of the EFI_SIO_CONTROL_PROTOCOL.    @retval EFI_SUCCESS          The device is disabled successfully.   @retval EFI_OUT_OF_RESOURCES The device could not be disabled because there                                were insufficient resources either for the device                                 itself or for the records needed to track the device.   @retval EFI_ALREADY_STARTED  The device is already disabled.   @retval EFI_UNSUPPORTED      The device cannot be disabled. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIO_CONTROL_DISABLE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SIO_CONTROL_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_SIO_CONTROL_PROTOCOL
block|{
comment|///
comment|/// The version of this protocol.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// Enable a device.
comment|///
name|EFI_SIO_CONTROL_ENABLE
name|EnableDevice
decl_stmt|;
comment|///
comment|/// Disable a device.
comment|///
name|EFI_SIO_CONTROL_DISABLE
name|DisableDevice
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSioControlProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __EFI_SUPER_IO_CONTROL_PROTOCOL_H__
end_comment

end_unit

