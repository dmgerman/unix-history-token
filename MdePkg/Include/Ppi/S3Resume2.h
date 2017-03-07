begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI produces functions to interpret and execute the PI boot script table.      This PPI is published by a PEIM and provides for the restoration of the platform's   configuration when resuming from the ACPI S3 power state. The ability to execute    the boot script may depend on the availability of other PPIs. For example, if    the boot script includes an SMBus command, this PEIM looks for the relevant PPI    that is able to execute that command.        Copyright (c) 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is defined in UEFI Platform Initialization Specification 1.2 Volume 5:    Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_S3_RESUME_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_S3_RESUME_PPI_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for EFI_PEI_S3_RESUME2_PPI
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_S3_RESUME2_PPI_GUID
define|\
value|{ \     0x6D582DBC, 0xDB85, 0x4514, {0x8F, 0xCC, 0x5A, 0xDF, 0x62, 0x27, 0xB1, 0x47 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward declaration for EFI_PEI_S3_RESUME_PPI
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_S3_RESUME2_PPI
name|EFI_PEI_S3_RESUME2_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Restores the platform to its preboot configuration for an S3 resume and   jumps to the OS waking vector.    This function will restore the platform to its pre-boot configuration that was    pre-stored in the boot script table and transfer control to OS waking vector.   Upon invocation, this function is responsible for locating the following    information before jumping to OS waking vector:     - ACPI tables     - boot script table     - any other information that it needs        The S3RestoreConfig() function then executes the pre-stored boot script table    and transitions the platform to the pre-boot state. The boot script is recorded    during regular boot using the EFI_S3_SAVE_STATE_PROTOCOL.Write() and   EFI_S3_SMM_SAVE_STATE_PROTOCOL.Write() functions.  Finally, this function    transfers control to the OS waking vector. If the OS supports only a real-mode    waking vector, this function will switch from flat mode to real mode before    jumping to the waking vector.  If all platform pre-boot configurations are    successfully restored and all other necessary information is ready, this    function will never return and instead will directly jump to the OS waking    vector. If this function returns, it indicates that the attempt to resume    from the ACPI S3 sleep state failed.        @param[in] This   Pointer to this instance of the PEI_S3_RESUME_PPI    @retval EFI_ABORTED     Execution of the S3 resume boot script table failed.   @retval EFI_NOT_FOUND   Some necessary information that is used for the S3                            resume boot path could not be located.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_S3_RESUME_PPI_RESTORE_CONFIG2
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_S3_RESUME2_PPI
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   EFI_PEI_S3_RESUME2_PPI accomplishes the firmware S3 resume boot   path and transfers control to OS. **/
end_comment

begin_struct
struct|struct
name|_EFI_PEI_S3_RESUME2_PPI
block|{
comment|///
comment|/// Restores the platform to its preboot configuration for an S3 resume and
comment|/// jumps to the OS waking vector.
comment|///
name|EFI_PEI_S3_RESUME_PPI_RESTORE_CONFIG2
name|S3RestoreConfig2
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiS3Resume2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

