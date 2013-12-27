begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_BOOTLOADER__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_BOOTLOADER__
end_define

begin_comment
comment|/**  * @file  *  * Bootloader definitions that are shared with other programs  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_comment
comment|/* The bootloader_header_t structure defines the header that is present ** at the start of binary u-boot images.  This header is used to locate the bootloader ** image in NAND, and also to allow verification of images for normal NOR booting. ** This structure is placed at the beginning of a bootloader binary image, and remains ** in the executable code. */
end_comment

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_MAGIC
value|0x424f4f54
end_define

begin_comment
comment|/* "BOOT" in ASCII */
end_comment

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_COMMENT_LEN
value|64
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_VERSION_LEN
value|64
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_MAX_SIZE
value|0x200
end_define

begin_comment
comment|/* limited by the space to the next exception handler */
end_comment

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_CURRENT_MAJOR_REV
value|1
end_define

begin_define
define|#
directive|define
name|BOOTLOADER_HEADER_CURRENT_MINOR_REV
value|2
end_define

begin_comment
comment|/* Revision history * 1.1  Initial released revision. (SDK 1.9) * 1.2  TLB based relocatable image (SDK 2.0) * * */
end_comment

begin_comment
comment|/* offsets to struct bootloader_header fields for assembly use */
end_comment

begin_define
define|#
directive|define
name|GOT_ADDRESS_OFFSET
value|48
end_define

begin_define
define|#
directive|define
name|LOOKUP_STEP
value|(64*1024)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|bootloader_header
block|{
name|uint32_t
name|jump_instr
decl_stmt|;
comment|/* Jump to executable code following the                             ** header.  This allows this header to                             ** be (and remain) part of the executable image)                             */
name|uint32_t
name|nop_instr
decl_stmt|;
comment|/* Must be 0x0 */
name|uint32_t
name|magic
decl_stmt|;
comment|/* Magic number to identify header */
name|uint32_t
name|hcrc
decl_stmt|;
comment|/* CRC of all of header excluding this field */
name|uint16_t
name|hlen
decl_stmt|;
comment|/* Length of header in bytes */
name|uint16_t
name|maj_rev
decl_stmt|;
comment|/* Major revision */
name|uint16_t
name|min_rev
decl_stmt|;
comment|/* Minor revision */
name|uint16_t
name|board_type
decl_stmt|;
comment|/* Board type that the image is for */
name|uint32_t
name|dlen
decl_stmt|;
comment|/* Length of data (immediately following header) in bytes */
name|uint32_t
name|dcrc
decl_stmt|;
comment|/* CRC of data */
name|uint64_t
name|address
decl_stmt|;
comment|/* Mips virtual address */
name|uint32_t
name|flags
decl_stmt|;
name|uint16_t
name|image_type
decl_stmt|;
comment|/* Defined in bootloader_image_t enum */
name|uint16_t
name|resv0
decl_stmt|;
comment|/* pad */
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
name|uint32_t
name|reserved4
decl_stmt|;
name|char
name|comment_string
index|[
name|BOOTLOADER_HEADER_COMMENT_LEN
index|]
decl_stmt|;
comment|/* Optional, for descriptive purposes */
name|char
name|version_string
index|[
name|BOOTLOADER_HEADER_VERSION_LEN
index|]
decl_stmt|;
comment|/* Optional, for descriptive purposes */
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|bootloader_header_t
typedef|;
end_typedef

begin_comment
comment|/* Defines for flag field */
end_comment

begin_define
define|#
directive|define
name|BL_HEADER_FLAG_FAILSAFE
value|(1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|BL_HEADER_IMAGE_UNKNOWN
init|=
literal|0x0
block|,
name|BL_HEADER_IMAGE_STAGE2
block|,
comment|/* Binary bootloader stage2 image (NAND boot) */
name|BL_HEADER_IMAGE_STAGE3
block|,
comment|/* Binary bootloader stage3 image (NAND boot)*/
name|BL_HEADER_IMAGE_NOR
block|,
comment|/* Binary bootloader for NOR boot */
name|BL_HEADER_IMAGE_PCIBOOT
block|,
comment|/* Binary bootloader for PCI boot */
name|BL_HEADER_IMAGE_UBOOT_ENV
block|,
comment|/* Environment for u-boot */
name|BL_HEADER_IMAGE_MAX
block|,
comment|/* Range for customer private use.  Will not be used by Cavium Inc. */
name|BL_HEADER_IMAGE_CUST_RESERVED_MIN
init|=
literal|0x1000
block|,
name|BL_HEADER_IMAGE_CUST_RESERVED_MAX
init|=
literal|0x1fff
block|}
name|bootloader_image_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_comment
comment|/* Maximum address searched for NAND boot images and environments.  This is used ** by stage1 and stage2. */
end_comment

begin_define
define|#
directive|define
name|MAX_NAND_SEARCH_ADDR
value|0x400000
end_define

begin_comment
comment|/* Maximum address to look for start of normal bootloader */
end_comment

begin_define
define|#
directive|define
name|MAX_NOR_SEARCH_ADDR
value|0x200000
end_define

begin_comment
comment|/* Defines for RAM based environment set by the host or the previous bootloader ** in a chain boot configuration. */
end_comment

begin_define
define|#
directive|define
name|U_BOOT_RAM_ENV_ADDR
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|U_BOOT_RAM_ENV_SIZE
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|U_BOOT_RAM_ENV_CRC_SIZE
value|(0x4)
end_define

begin_define
define|#
directive|define
name|U_BOOT_RAM_ENV_ADDR_2
value|(U_BOOT_RAM_ENV_ADDR + U_BOOT_RAM_ENV_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_BOOTLOADER__ */
end_comment

end_unit

