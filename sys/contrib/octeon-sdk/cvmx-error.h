begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Networks nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the Octeon extended error status.  *  *<hr>$Revision: 44252 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_ERROR_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_ERROR_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * There are generally many error status bits associated with a  * single logical group. The enumeration below is used to  * communicate high level groups to the error infastructure so  * error status bits can be enable or disabled in large groups.  */
typedef|typedef
enum|enum
block|{
name|CVMX_ERROR_GROUP_INTERNAL
block|,
comment|/* All internal blocks that can always be enabled */
name|CVMX_ERROR_GROUP_ETHERNET
block|,
comment|/* All errors related to network traffic that should be enabled when a port is up. Indexed by IPD number */
name|CVMX_ERROR_GROUP_MGMT_PORT
block|,
comment|/* All errors related to the management ethernet ports that should be enabled when a port is up. Indexed by port number (0-1) */
name|CVMX_ERROR_GROUP_PCI
block|,
comment|/* All errors related to PCI/PCIe when the bus is up. Index by port number (0-1) */
name|CVMX_ERROR_GROUP_SRIO
block|,
comment|/* All errors related to SRIO when the bus is up. Index by port number (0-1) */
name|CVMX_ERROR_GROUP_USB
block|,
comment|/* All errors related to USB when the port is enabled. Index by port number (0-1) */
name|CVMX_ERROR_GROUP_LMC
block|,
comment|/* All errors related to LMC when the controller is enabled. Index by controller number (0-1) */
block|}
name|cvmx_error_group_t
typedef|;
comment|/**  * When registering for interest in an error status register, the  * type of the register needs to be known by cvmx-error. Most  * registers are either IO64 or IO32, but some blocks contain  * registers that can't be directly accessed. A good example of  * would be PCIe extended error state stored in config space.  */
typedef|typedef
enum|enum
block|{
name|__CVMX_ERROR_REGISTER_NONE
block|,
comment|/* Used internally */
name|CVMX_ERROR_REGISTER_IO64
block|,
comment|/* Status and enable registers are Octeon 64bit CSRs */
name|CVMX_ERROR_REGISTER_IO32
block|,
comment|/* Status and enable registers are Octeon 32bit CSRs */
name|CVMX_ERROR_REGISTER_PCICONFIG
block|,
comment|/* Status and enable registers are in PCI config space */
name|CVMX_ERROR_REGISTER_SRIOMAINT
block|,
comment|/* Status and enable registers are in SRIO maintenance space */
block|}
name|cvmx_error_register_t
typedef|;
comment|/**  * Flags representing special handling for some error registers.  * These flags are passed to cvmx_error_initialize() to control  * the handling of bits where the same flags were passed to the  * added cvmx_error_info_t.  */
typedef|typedef
enum|enum
block|{
name|CVMX_ERROR_FLAGS_ECC_SINGLE_BIT
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* This is a ECC single bit error. Normally these can be ignored */
name|CVMX_ERROR_FLAGS_CORRECTABLE
init|=
literal|1
operator|<<
literal|1
block|,
comment|/* Some blocks have errors that can be silently corrected. This flags reports these */
name|CVMX_ERROR_FLAGS_DISABLED
init|=
literal|1
operator|<<
literal|2
block|,
comment|/* Flag used to signal a register should not be enable as part of the groups */
block|}
name|cvmx_error_flags_t
typedef|;
struct_decl|struct
name|cvmx_error_info
struct_decl|;
comment|/**  * Error handling functions must have the following prototype.  */
typedef|typedef
name|int
function_decl|(
modifier|*
name|cvmx_error_func_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|cvmx_error_info
modifier|*
name|info
parameter_list|)
function_decl|;
comment|/**  * This structure is passed to all error handling functions.  */
typedef|typedef
struct|struct
name|cvmx_error_info
block|{
name|cvmx_error_register_t
name|reg_type
decl_stmt|;
comment|/* Type of registers used for the error */
name|uint64_t
name|status_addr
decl_stmt|;
comment|/* The address of the status register */
name|uint64_t
name|status_mask
decl_stmt|;
comment|/* Mask to apply to status register to detect asserted error */
name|uint64_t
name|enable_addr
decl_stmt|;
comment|/* The address of the enable register */
name|uint64_t
name|enable_mask
decl_stmt|;
comment|/* Mask to apply to enable register to allow error detection */
name|cvmx_error_flags_t
name|flags
decl_stmt|;
comment|/* Flags indicating special handling of this error */
name|cvmx_error_group_t
name|group
decl_stmt|;
comment|/* Group to associate this error register with */
name|int
name|group_index
decl_stmt|;
comment|/* Group index to associate this error register with */
name|cvmx_error_func_t
name|func
decl_stmt|;
comment|/* Function to call when the error is detected */
name|uint64_t
name|user_info
decl_stmt|;
comment|/* User supplied information for the error handler */
struct|struct
block|{
name|cvmx_error_register_t
name|reg_type
decl_stmt|;
comment|/* Type of parent's register */
name|uint64_t
name|status_addr
decl_stmt|;
comment|/* The address of the parent's register */
name|uint64_t
name|status_mask
decl_stmt|;
comment|/* Mask to apply to parent's register */
block|}
name|parent
struct|;
block|}
name|cvmx_error_info_t
typedef|;
comment|/**  * Initalize the error status system. This should be called once  * before any other functions are called. This function adds default  * handlers for most all error events but does not enable them. Later  * calls to cvmx_error_enable() are needed.  *  * @param flags  Optional flags.  *  * @return Zero on success, negative on failure.  */
name|int
name|cvmx_error_initialize
parameter_list|(
name|cvmx_error_flags_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Poll the error status registers and call the appropriate error  * handlers. This should be called in the RSL interrupt handler  * for your application or operating system.  *  * @return Number of error handlers called. Zero means this call  *         found no errors and was spurious.  */
name|int
name|cvmx_error_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Register to be called when an error status bit is set. Most users  * will not need to call this function as cvmx_error_initialize()  * registers default handlers for most error conditions. This function  * is normally used to add more handlers without changing the existing  * handlers.  *  * @param new_info Information about the handler for a error register. The  *                 structure passed is copied and can be destroyed after the  *                 call. All members of the structure must be populated, even the  *                 parent information.  *  * @return Zero on success, negative on failure.  */
name|int
name|cvmx_error_add
parameter_list|(
specifier|const
name|cvmx_error_info_t
modifier|*
name|new_info
parameter_list|)
function_decl|;
comment|/**  * Remove all handlers for a status register and mask. Normally  * this function should not be called. Instead a new handler should be  * installed to replace the existing handler. In the even that all  * reporting of a error bit should be removed, then use this  * function.  *  * @param reg_type Type of the status register to remove  * @param status_addr  *                 Status register to remove.  * @param status_mask  *                 All handlers for this status register with this mask will be  *                 removed.  * @param old_info If not NULL, this is filled with information about the handler  *                 that was removed.  *  * @return Zero on success, negative on failure (not found).  */
name|int
name|cvmx_error_remove
parameter_list|(
name|cvmx_error_register_t
name|reg_type
parameter_list|,
name|uint64_t
name|status_addr
parameter_list|,
name|uint64_t
name|status_mask
parameter_list|,
name|cvmx_error_info_t
modifier|*
name|old_info
parameter_list|)
function_decl|;
comment|/**  * Change the function and user_info for an existing error status  * register. This function should be used to replace the default  * handler with an application specific version as needed.  *  * @param reg_type Type of the status register to change  * @param status_addr  *                 Status register to change.  * @param status_mask  *                 All handlers for this status register with this mask will be  *                 changed.  * @param new_func New function to use to handle the error status  * @param new_user_info  *                 New user info parameter for the function  * @param old_func If not NULL, the old function is returned. Useful for restoring  *                 the old handler.  * @param old_user_info  *                 If not NULL, the old user info parameter.  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_error_change_handler
parameter_list|(
name|cvmx_error_register_t
name|reg_type
parameter_list|,
name|uint64_t
name|status_addr
parameter_list|,
name|uint64_t
name|status_mask
parameter_list|,
name|cvmx_error_func_t
name|new_func
parameter_list|,
name|uint64_t
name|new_user_info
parameter_list|,
name|cvmx_error_func_t
modifier|*
name|old_func
parameter_list|,
name|uint64_t
modifier|*
name|old_user_info
parameter_list|)
function_decl|;
comment|/**  * Enable all error registers for a logical group. This should be  * called whenever a logical group is brought online.  *  * @param group  Logical group to enable  * @param group_index  *               Index for the group as defined in the cvmx_error_group_t  *               comments.  *  * @return Zero on success, negative on failure.  */
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_UBOOT
name|int
name|cvmx_error_enable_group
parameter_list|(
name|cvmx_error_group_t
name|group
parameter_list|,
name|int
name|group_index
parameter_list|)
function_decl|;
else|#
directive|else
comment|/* Rather than conditionalize the calls throughout the executive to not enable     interrupts in Uboot, simply make the enable function do nothing */
specifier|static
specifier|inline
name|int
name|cvmx_error_enable_group
parameter_list|(
name|cvmx_error_group_t
name|group
parameter_list|,
name|int
name|group_index
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/**  * Disable all error registers for a logical group. This should be  * called whenever a logical group is brought offline. Many blocks  * will report spurious errors when offline unless this function  * is called.  *  * @param group  Logical group to disable  * @param group_index  *               Index for the group as defined in the cvmx_error_group_t  *               comments.  *  * @return Zero on success, negative on failure.  */
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_UBOOT
name|int
name|cvmx_error_disable_group
parameter_list|(
name|cvmx_error_group_t
name|group
parameter_list|,
name|int
name|group_index
parameter_list|)
function_decl|;
else|#
directive|else
comment|/* Rather than conditionalize the calls throughout the executive to not disable     interrupts in Uboot, simply make the enable function do nothing */
specifier|static
specifier|inline
name|int
name|cvmx_error_disable_group
parameter_list|(
name|cvmx_error_group_t
name|group
parameter_list|,
name|int
name|group_index
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/**  * Enable all handlers for a specific status register mask.  *  * @param reg_type Type of the status register  * @param status_addr  *                 Status register address  * @param status_mask  *                 All handlers for this status register with this mask will be  *                 enabled.  *  * @return Zero on success, negative on failure.  */
name|int
name|cvmx_error_enable
parameter_list|(
name|cvmx_error_register_t
name|reg_type
parameter_list|,
name|uint64_t
name|status_addr
parameter_list|,
name|uint64_t
name|status_mask
parameter_list|)
function_decl|;
comment|/**  * Disable all handlers for a specific status register and mask.  *  * @param reg_type Type of the status register  * @param status_addr  *                 Status register address  * @param status_mask  *                 All handlers for this status register with this mask will be  *                 disabled.  *  * @return Zero on success, negative on failure.  */
name|int
name|cvmx_error_disable
parameter_list|(
name|cvmx_error_register_t
name|reg_type
parameter_list|,
name|uint64_t
name|status_addr
parameter_list|,
name|uint64_t
name|status_mask
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * Function for processing non leaf error status registers. This function  * calls all handlers for this passed register and all children linked  * to it.  *  * @param info   Error register to check  *  * @return Number of error status bits found or zero if no bits were set.  */
name|int
name|__cvmx_error_decode
parameter_list|(
specifier|const
name|cvmx_error_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
comment|/**  * @INTERNAL  * This error bit handler simply prints a message and clears the status bit  *  * @param info   Error register to check  *  * @return  */
name|int
name|__cvmx_error_display
parameter_list|(
specifier|const
name|cvmx_error_info_t
modifier|*
name|info
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

