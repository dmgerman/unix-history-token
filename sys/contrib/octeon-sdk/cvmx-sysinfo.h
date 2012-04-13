begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This module provides system/board information obtained by the bootloader.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_SYSINFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_SYSINFO_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|"cvmx-app-init.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
define|#
directive|define
name|OCTEON_SERIAL_LEN
value|20
comment|/**  * Structure describing application specific information.  * __cvmx_app_init() populates this from the cvmx boot descriptor.  * This structure is private to simple executive applications, so no  * versioning is required.  *  * This structure must be provided with some fields set in order to  * use simple executive functions in other applications (Linux kernel,  * u-boot, etc.)  The cvmx_sysinfo_minimal_initialize() function is  * provided to set the required values in these cases.  *  */
struct|struct
name|cvmx_sysinfo
block|{
comment|/* System wide variables */
name|uint64_t
name|system_dram_size
decl_stmt|;
comment|/**< installed DRAM in system, in bytes */
name|uint64_t
name|phy_mem_desc_addr
decl_stmt|;
comment|/**< Address of the memory descriptor block */
comment|/* Application image specific variables */
name|uint64_t
name|stack_top
decl_stmt|;
comment|/**< stack top address (virtual) */
name|uint64_t
name|heap_base
decl_stmt|;
comment|/**< heap base address (virtual) */
name|uint32_t
name|stack_size
decl_stmt|;
comment|/**< stack size in bytes */
name|uint32_t
name|heap_size
decl_stmt|;
comment|/**< heap size in bytes */
name|uint32_t
name|core_mask
decl_stmt|;
comment|/**< coremask defining cores running application */
name|uint32_t
name|init_core
decl_stmt|;
comment|/**< Deprecated, use cvmx_coremask_first_core() to select init core */
name|uint64_t
name|exception_base_addr
decl_stmt|;
comment|/**< exception base address, as set by bootloader */
name|uint32_t
name|cpu_clock_hz
decl_stmt|;
comment|/**< cpu clock speed in hz */
name|uint32_t
name|dram_data_rate_hz
decl_stmt|;
comment|/**< dram data rate in hz (data rate = 2 * clock rate */
name|uint16_t
name|board_type
decl_stmt|;
name|uint8_t
name|board_rev_major
decl_stmt|;
name|uint8_t
name|board_rev_minor
decl_stmt|;
name|uint8_t
name|mac_addr_base
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|mac_addr_count
decl_stmt|;
name|char
name|board_serial_number
index|[
name|OCTEON_SERIAL_LEN
index|]
decl_stmt|;
comment|/* 	 * Several boards support compact flash on the Octeon boot 	 * bus.  The CF memory spaces may be mapped to different 	 * addresses on different boards.  These values will be 0 if 	 * CF is not present.  Note that these addresses are physical 	 * addresses, and it is up to the application to use the 	 * proper addressing mode (XKPHYS, KSEG0, etc.) 	 */
name|uint64_t
name|compact_flash_common_base_addr
decl_stmt|;
name|uint64_t
name|compact_flash_attribute_base_addr
decl_stmt|;
comment|/* 	 * Base address of the LED display (as on EBT3000 board) This 	 * will be 0 if LED display not present.  Note that this 	 * address is a physical address, and it is up to the 	 * application to use the proper addressing mode (XKPHYS, 	 * KSEG0, etc.) 	 */
name|uint64_t
name|led_display_base_addr
decl_stmt|;
name|uint32_t
name|dfa_ref_clock_hz
decl_stmt|;
comment|/**< DFA reference clock in hz (if applicable)*/
name|uint32_t
name|bootloader_config_flags
decl_stmt|;
comment|/**< configuration flags from bootloader */
name|uint8_t
name|console_uart_num
decl_stmt|;
comment|/**< Uart number used for console */
name|uint64_t
name|fdt_addr
decl_stmt|;
comment|/** pointer to device tree */
block|}
struct|;
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_KERNEL
typedef|typedef
name|struct
name|cvmx_sysinfo
name|cvmx_sysinfo_t
typedef|;
endif|#
directive|endif
comment|/**  * This function returns the system/board information as obtained  * by the bootloader.  *  *  * @return  Pointer to the boot information structure  *  */
specifier|extern
name|struct
name|cvmx_sysinfo
modifier|*
name|cvmx_sysinfo_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * This function adds the current cpu to sysinfo coremask  *   */
name|void
name|cvmx_sysinfo_add_self_to_core_mask
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * This function removes the current cpu to sysinfo coremask  *   */
name|void
name|cvmx_sysinfo_remove_self_from_core_mask
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_KERNEL
comment|/**  * This function is used in non-simple executive environments (such as Linux kernel, u-boot, etc.)  * to configure the minimal fields that are required to use  * simple executive files directly.  *  * Locking (if required) must be handled outside of this  * function  *  * @param phy_mem_desc_addr  *                   Address of the global physical memory descriptor (bootmem  *                   descriptor)  * @param board_type Octeon board type enumeration  *  * @param board_rev_major  *                   Board major revision  * @param board_rev_minor  *                   Board minor revision  * @param cpu_clock_hz  *                   CPU clock freqency in hertz  *  * @return 0: Failure  *         1: success  */
specifier|extern
name|int
name|cvmx_sysinfo_minimal_initialize
parameter_list|(
name|uint64_t
name|phy_mem_desc_addr
parameter_list|,
name|uint16_t
name|board_type
parameter_list|,
name|uint8_t
name|board_rev_major
parameter_list|,
name|uint8_t
name|board_rev_minor
parameter_list|,
name|uint32_t
name|cpu_clock_hz
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_USER
comment|/**  * Initialize the sysinfo structure when running on  * Octeon under Linux userspace  */
specifier|extern
name|void
name|cvmx_sysinfo_linux_userspace_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
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

begin_comment
comment|/* __CVMX_SYSINFO_H__ */
end_comment

end_unit

