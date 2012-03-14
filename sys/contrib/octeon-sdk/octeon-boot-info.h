begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2011  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to Octeon boot structure  *  *<hr>$Revision:  $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_BOOT_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_BOOT_INFO_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-asm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx-asm.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_comment
comment|/*  * This structure is access by bootloader, Linux kernel and the Linux  * user space utility "bootoct".   * In the bootloader, this structure is accessed by assembly code in start.S,  * so any changes to content or size must be reflected there as well.   * This is placed at a fixed address in DRAM, so that cores can access it  * when they come out of reset.  It is used to setup the minimal bootloader  * runtime environment (stack, but no heap, global data ptr) that is needed  * by the non-boot cores to setup the environment for the applications.  * The boot_info_addr is the address of a boot_info_block_t structure  * which contains more core-specific information.  *  * The Linux kernel and the Linux bootoct utility access this structure for  * implementing CPU hotplug functionality and booting of idle cores with SE  * apps respectively.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* First stage address - in ram instead of flash */
name|uint64_t
name|code_addr
decl_stmt|;
comment|/* Setup code for application, NOT application entry point */
name|uint32_t
name|app_start_func_addr
decl_stmt|;
comment|/* k0 is used for global data - needs to be passed to other cores */
name|uint32_t
name|k0_val
decl_stmt|;
comment|/* Address of boot info block structure */
name|uint64_t
name|boot_info_addr
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* flags */
name|uint32_t
name|pad
decl_stmt|;
block|}
name|boot_init_vector_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ASM_GBL_DATA_H
argument_list|)
end_if

begin_comment
comment|/* defined above */
end_comment

begin_comment
comment|/*  * Definition of a data structure to mimic the old u-boot gd_t data structure.  */
end_comment

begin_undef
undef|#
directive|undef
name|GD_TMP_STR_SIZE
end_undef

begin_define
define|#
directive|define
name|GD_TMP_STR_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LINUX_APP_GLOBAL_DATA_MAGIC
value|0x221eb111476f410full
end_define

begin_define
define|#
directive|define
name|LINUX_APP_GLOBAL_DATA_VERSION
value|2
end_define

begin_struct
struct|struct
name|linux_app_global_data
block|{
name|bd_t
modifier|*
name|bd
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|unsigned
name|long
name|baudrate
decl_stmt|;
name|unsigned
name|long
name|have_console
decl_stmt|;
comment|/* serial_init() was called */
name|uint64_t
name|ram_size
decl_stmt|;
comment|/* RAM size */
name|uint64_t
name|reloc_off
decl_stmt|;
comment|/* Relocation Offset */
name|unsigned
name|long
name|env_addr
decl_stmt|;
comment|/* Address  of Environment struct */
name|unsigned
name|long
name|env_valid
decl_stmt|;
comment|/* Checksum of Environment valid? */
name|unsigned
name|long
name|cpu_clock_mhz
decl_stmt|;
comment|/* CPU clock speed in MHz */
name|unsigned
name|long
name|ddr_clock_mhz
decl_stmt|;
comment|/* DDR clock (not data rate!) in MHz */
name|unsigned
name|long
name|ddr_ref_hertz
decl_stmt|;
comment|/* DDR Ref clock Hertz */
name|int
name|mcu_rev_maj
decl_stmt|;
name|int
name|mcu_rev_min
decl_stmt|;
name|int
name|console_uart
decl_stmt|;
comment|/* EEPROM data structures as read from EEPROM or populated by other      * means on boards without an EEPROM      */
name|octeon_eeprom_board_desc_t
name|board_desc
decl_stmt|;
name|octeon_eeprom_clock_desc_t
name|clock_desc
decl_stmt|;
name|octeon_eeprom_mac_addr_t
name|mac_desc
decl_stmt|;
name|void
modifier|*
modifier|*
name|jt
decl_stmt|;
comment|/* jump table, not used */
name|char
modifier|*
name|err_msg
decl_stmt|;
comment|/* pointer to error message to save 					 * until console is up.  Not used. 					 */
union|union
block|{
struct|struct
block|{
comment|/* Keep under 32 bytes! */
name|uint64_t
name|magic
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|fdt_addr
decl_stmt|;
block|}
struct|;
name|char
name|tmp_str
index|[
name|GD_TMP_STR_SIZE
index|]
decl_stmt|;
block|}
union|;
name|unsigned
name|long
name|uboot_flash_address
decl_stmt|;
comment|/* Address of normal bootloader 						 * in flash 						 */
name|unsigned
name|long
name|uboot_flash_size
decl_stmt|;
comment|/* Size of normal bootloader */
name|uint64_t
name|dfm_ram_size
decl_stmt|;
comment|/* DFM RAM size */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|linux_app_global_data
name|linux_app_global_data_t
typedef|;
end_typedef

begin_comment
comment|/* Flags for linux_app_global_data */
end_comment

begin_define
define|#
directive|define
name|LA_GD_FLG_RELOC
value|0x0001
end_define

begin_comment
comment|/* Code was relocated to RAM	 */
end_comment

begin_define
define|#
directive|define
name|LA_GD_FLG_DEVINIT
value|0x0002
end_define

begin_comment
comment|/* Devices have been initialized */
end_comment

begin_define
define|#
directive|define
name|LA_GD_FLG_SILENT
value|0x0004
end_define

begin_comment
comment|/* Silent mode			 */
end_comment

begin_define
define|#
directive|define
name|LA_GD_FLG_CLOCK_DESC_MISSING
value|0x0008
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_BOARD_DESC_MISSING
value|0x0010
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR_VERBOSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR0_CLK_INITIALIZED
value|0x0040
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR1_CLK_INITIALIZED
value|0x0080
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR2_CLK_INITIALIZED
value|0x0100
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR3_CLK_INITIALIZED
value|0x0200
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_FAILSAFE_MODE
value|0x0400
end_define

begin_comment
comment|/* Use failsafe mode */
end_comment

begin_define
define|#
directive|define
name|LA_GD_FLG_DDR_TRACE_INIT
value|0x0800
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DFM_CLK_INITIALIZED
value|0x1000
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DFM_VERBOSE
value|0x2000
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_DFM_TRACE_INIT
value|0x4000
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_MEMORY_PRESERVED
value|0x8000
end_define

begin_define
define|#
directive|define
name|LA_GD_FLG_RAM_RESIDENT
value|0x10000
end_define

begin_comment
comment|/* RAM boot detected */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASM_GBL_DATA_H */
end_comment

begin_comment
comment|/*  * Definition of a data structure setup by the bootloader to enable Linux to  * launch SE apps on idle cores.  */
end_comment

begin_struct
struct|struct
name|linux_app_boot_info
block|{
name|uint32_t
name|labi_signature
decl_stmt|;
name|uint32_t
name|start_core0_addr
decl_stmt|;
name|uint32_t
name|avail_coremask
decl_stmt|;
name|uint32_t
name|pci_console_active
decl_stmt|;
name|uint32_t
name|icache_prefetch_disable
decl_stmt|;
name|uint64_t
name|InitTLBStart_addr
decl_stmt|;
name|uint32_t
name|start_app_addr
decl_stmt|;
name|uint32_t
name|cur_exception_base
decl_stmt|;
name|uint32_t
name|no_mark_private_data
decl_stmt|;
name|uint32_t
name|compact_flash_common_base_addr
decl_stmt|;
name|uint32_t
name|compact_flash_attribute_base_addr
decl_stmt|;
name|uint32_t
name|led_display_base_addr
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__ASM_GBL_DATA_H
argument_list|)
comment|/* defined above */
name|linux_app_global_data_t
name|gd
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|linux_app_boot_info
name|linux_app_boot_info_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not to copy a lot of bootloader's structures    here is only offset of requested member */
end_comment

begin_define
define|#
directive|define
name|AVAIL_COREMASK_OFFSET_IN_LINUX_APP_BOOT_BLOCK
value|0x765c
end_define

begin_comment
comment|/* hardcoded in bootloader */
end_comment

begin_define
define|#
directive|define
name|LABI_ADDR_IN_BOOTLOADER
value|0x700
end_define

begin_define
define|#
directive|define
name|LINUX_APP_BOOT_BLOCK_NAME
value|"linux-app-boot"
end_define

begin_define
define|#
directive|define
name|LABI_SIGNATURE
value|0xAABBCC01
end_define

begin_comment
comment|/*  from uboot-headers/octeon_mem_map.h */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|CVMX_BUILD_FOR_TOOLCHAIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXCEPTION_BASE_INCR
value|(4 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Increment size for exception base addresses (4k minimum) */
end_comment

begin_define
define|#
directive|define
name|EXCEPTION_BASE_BASE
value|0
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_PRIV_DATA_BASE
value|(EXCEPTION_BASE_BASE + 0x800)
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_BOOT_VECTOR
value|(BOOTLOADER_PRIV_DATA_BASE)
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_DEBUG_TRAMPOLINE
value|(BOOTLOADER_BOOT_VECTOR + BOOT_VECTOR_SIZE)
end_define

begin_comment
comment|/* WORD */
end_comment

begin_define
define|#
directive|define
name|BOOTLOADER_DEBUG_TRAMPOLINE_CORE
value|(BOOTLOADER_DEBUG_TRAMPOLINE + 4)
end_define

begin_comment
comment|/* WORD */
end_comment

begin_define
define|#
directive|define
name|OCTEON_EXCEPTION_VECTOR_BLOCK_SIZE
value|(CVMX_MAX_CORES*EXCEPTION_BASE_INCR)
end_define

begin_comment
comment|/* 32 4k blocks */
end_comment

begin_define
define|#
directive|define
name|BOOTLOADER_DEBUG_REG_SAVE_BASE
value|(EXCEPTION_BASE_BASE + OCTEON_EXCEPTION_VECTOR_BLOCK_SIZE)
end_define

begin_define
define|#
directive|define
name|BOOT_VECTOR_NUM_WORDS
value|(8)
end_define

begin_define
define|#
directive|define
name|BOOT_VECTOR_SIZE
value|((CVMX_MAX_CORES*4)*BOOT_VECTOR_NUM_WORDS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OCTEON_BOOT_INFO_H__ */
end_comment

end_unit

