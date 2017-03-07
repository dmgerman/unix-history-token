begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Access2 Protocol as defined in the PI 1.2 specification.    This protocol is used to control the visibility of the SMRAM on the platform.   It abstracts the location and characteristics of SMRAM.  The expectation is   that the north bridge or memory controller would publish this protocol.    The principal functionality found in the memory controller includes the following:    - Exposing the SMRAM to all non-SMM agents, or the "open" state   - Shrouding the SMRAM to all but the SMM agents, or the "closed" state   - Preserving the system integrity, or "locking" the SMRAM, such that the settings cannot be      perturbed by either boot service or runtime agents     Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_ACCESS2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_ACCESS2_H_
end_define

begin_define
define|#
directive|define
name|EFI_SMM_ACCESS2_PROTOCOL_GUID
define|\
value|{ \      0xc2702b74, 0x800c, 0x4131, {0x87, 0x46, 0x8f, 0xb5, 0xb8, 0x9c, 0xe4, 0xac } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_ACCESS2_PROTOCOL
name|EFI_SMM_ACCESS2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Opens the SMRAM area to be accessible by a boot-service driver.    This function "opens" SMRAM so that it is visible while not inside of SMM. The function should    return EFI_UNSUPPORTED if the hardware does not support hiding of SMRAM. The function    should return EFI_DEVICE_ERROR if the SMRAM configuration is locked.    @param[in] This           The EFI_SMM_ACCESS2_PROTOCOL instance.    @retval EFI_SUCCESS       The operation was successful.   @retval EFI_UNSUPPORTED   The system does not support opening and closing of SMRAM.   @retval EFI_DEVICE_ERROR  SMRAM cannot be opened, perhaps because it is locked. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_OPEN2
function_decl|)
parameter_list|(
name|IN
name|EFI_SMM_ACCESS2_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Inhibits access to the SMRAM.    This function "closes" SMRAM so that it is not visible while outside of SMM. The function should    return EFI_UNSUPPORTED if the hardware does not support hiding of SMRAM.    @param[in] This           The EFI_SMM_ACCESS2_PROTOCOL instance.    @retval EFI_SUCCESS       The operation was successful.   @retval EFI_UNSUPPORTED   The system does not support opening and closing of SMRAM.   @retval EFI_DEVICE_ERROR  SMRAM cannot be closed. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_CLOSE2
function_decl|)
parameter_list|(
name|IN
name|EFI_SMM_ACCESS2_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Inhibits access to the SMRAM.    This function prohibits access to the SMRAM region.  This function is usually implemented such    that it is a write-once operation.     @param[in] This          The EFI_SMM_ACCESS2_PROTOCOL instance.    @retval EFI_SUCCESS      The device was successfully locked.   @retval EFI_UNSUPPORTED  The system does not support locking of SMRAM. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_LOCK2
function_decl|)
parameter_list|(
name|IN
name|EFI_SMM_ACCESS2_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queries the memory controller for the possible regions that will support SMRAM.    @param[in]     This           The EFI_SMM_ACCESS2_PROTOCOL instance.   @param[in,out] SmramMapSize   A pointer to the size, in bytes, of the SmramMemoryMap buffer.   @param[in,out] SmramMap       A pointer to the buffer in which firmware places the current memory map.    @retval EFI_SUCCESS           The chipset supported the given resource.   @retval EFI_BUFFER_TOO_SMALL  The SmramMap parameter was too small.  The current buffer size                                  needed to hold the memory map is returned in SmramMapSize. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_CAPABILITIES2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_ACCESS2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|SmramMapSize
parameter_list|,
name|IN
name|OUT
name|EFI_SMRAM_DESCRIPTOR
modifier|*
name|SmramMap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  EFI SMM Access2 Protocol is used to control the visibility of the SMRAM on the platform.
end_comment

begin_comment
comment|///  It abstracts the location and characteristics of SMRAM.  The expectation is
end_comment

begin_comment
comment|///  that the north bridge or memory controller would publish this protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_ACCESS2_PROTOCOL
block|{
name|EFI_SMM_OPEN2
name|Open
decl_stmt|;
name|EFI_SMM_CLOSE2
name|Close
decl_stmt|;
name|EFI_SMM_LOCK2
name|Lock
decl_stmt|;
name|EFI_SMM_CAPABILITIES2
name|GetCapabilities
decl_stmt|;
comment|///
comment|/// Indicates the current state of the SMRAM. Set to TRUE if SMRAM is locked.
comment|///
name|BOOLEAN
name|LockState
decl_stmt|;
comment|///
comment|/// Indicates the current state of the SMRAM. Set to TRUE if SMRAM is open.
comment|///
name|BOOLEAN
name|OpenState
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmAccess2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

