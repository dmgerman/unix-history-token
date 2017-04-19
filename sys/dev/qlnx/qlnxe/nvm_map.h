begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/****************************************************************************  * Name:        nvm_map.h  *  * Description: Everest NVRAM map  *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NVM_MAP_H
end_ifndef

begin_define
define|#
directive|define
name|NVM_MAP_H
end_define

begin_define
define|#
directive|define
name|CRC_MAGIC_VALUE
value|0xDEBB20E3
end_define

begin_define
define|#
directive|define
name|CRC32_POLYNOMIAL
value|0xEDB88320
end_define

begin_define
define|#
directive|define
name|NVM_CRC_SIZE
value|(sizeof(u32))
end_define

begin_enum
enum|enum
name|nvm_sw_arbitrator
block|{
name|NVM_SW_ARB_HOST
block|,
name|NVM_SW_ARB_MCP
block|,
name|NVM_SW_ARB_UART
block|,
name|NVM_SW_ARB_RESERVED
block|}
enum|;
end_enum

begin_comment
comment|/****************************************************************************  * Boot Strap Region                                                        *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|legacy_bootstrap_region
block|{
name|u32
name|magic_value
decl_stmt|;
comment|/* a pattern not likely to occur randomly */
define|#
directive|define
name|NVM_MAGIC_VALUE
value|0x669955aa
name|u32
name|sram_start_addr
decl_stmt|;
comment|/* where to locate LIM code (byte addr) */
name|u32
name|code_len
decl_stmt|;
comment|/* boot code length (in dwords) */
name|u32
name|code_start_addr
decl_stmt|;
comment|/* location of code on media (media byte addr) */
name|u32
name|crc
decl_stmt|;
comment|/* 32-bit CRC */
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Directories Region                                                       *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|nvm_code_entry
block|{
name|u32
name|image_type
decl_stmt|;
comment|/* Image type */
name|u32
name|nvm_start_addr
decl_stmt|;
comment|/* NVM address of the image */
name|u32
name|len
decl_stmt|;
comment|/* Include CRC */
name|u32
name|sram_start_addr
decl_stmt|;
comment|/* Where to load the image on the scratchpad */
name|u32
name|sram_run_addr
decl_stmt|;
comment|/* Relevant in case of MIM only */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|nvm_image_type
block|{
name|NVM_TYPE_TIM1
init|=
literal|0x01
block|,
name|NVM_TYPE_TIM2
init|=
literal|0x02
block|,
name|NVM_TYPE_MIM1
init|=
literal|0x03
block|,
name|NVM_TYPE_MIM2
init|=
literal|0x04
block|,
name|NVM_TYPE_MBA
init|=
literal|0x05
block|,
name|NVM_TYPE_MODULES_PN
init|=
literal|0x06
block|,
name|NVM_TYPE_VPD
init|=
literal|0x07
block|,
name|NVM_TYPE_MFW_TRACE1
init|=
literal|0x08
block|,
name|NVM_TYPE_MFW_TRACE2
init|=
literal|0x09
block|,
name|NVM_TYPE_NVM_CFG1
init|=
literal|0x0a
block|,
name|NVM_TYPE_L2B
init|=
literal|0x0b
block|,
name|NVM_TYPE_DIR1
init|=
literal|0x0c
block|,
name|NVM_TYPE_EAGLE_FW1
init|=
literal|0x0d
block|,
name|NVM_TYPE_FALCON_FW1
init|=
literal|0x0e
block|,
name|NVM_TYPE_PCIE_FW1
init|=
literal|0x0f
block|,
name|NVM_TYPE_HW_SET
init|=
literal|0x10
block|,
name|NVM_TYPE_LIM
init|=
literal|0x11
block|,
name|NVM_TYPE_AVS_FW1
init|=
literal|0x12
block|,
name|NVM_TYPE_DIR2
init|=
literal|0x13
block|,
name|NVM_TYPE_CCM
init|=
literal|0x14
block|,
name|NVM_TYPE_EAGLE_FW2
init|=
literal|0x15
block|,
name|NVM_TYPE_FALCON_FW2
init|=
literal|0x16
block|,
name|NVM_TYPE_PCIE_FW2
init|=
literal|0x17
block|,
name|NVM_TYPE_AVS_FW2
init|=
literal|0x18
block|,
name|NVM_TYPE_INIT_HW
init|=
literal|0x19
block|,
name|NVM_TYPE_DEFAULT_CFG
init|=
literal|0x1a
block|,
name|NVM_TYPE_MDUMP
init|=
literal|0x1b
block|,
name|NVM_TYPE_NVM_META
init|=
literal|0x1c
block|,
name|NVM_TYPE_ISCSI_CFG
init|=
literal|0x1d
block|,
name|NVM_TYPE_FCOE_CFG
init|=
literal|0x1f
block|,
name|NVM_TYPE_ETH_PHY_FW1
init|=
literal|0x20
block|,
name|NVM_TYPE_ETH_PHY_FW2
init|=
literal|0x21
block|,
name|NVM_TYPE_BDN
init|=
literal|0x22
block|,
name|NVM_TYPE_8485X_PHY_FW
init|=
literal|0x23
block|,
name|NVM_TYPE_PUB_KEY
init|=
literal|0x24
block|,
name|NVM_TYPE_RECOVERY
init|=
literal|0x25
block|,
name|NVM_TYPE_MAX
block|, }
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_IMAGE_TABLE
end_ifdef

begin_struct
struct|struct
name|image_map
block|{
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|char
name|option
index|[
literal|32
index|]
decl_stmt|;
name|u32
name|image_type
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|image_map
name|g_image_table
index|[]
init|=
block|{
block|{
literal|"TIM1"
block|,
literal|"-tim1"
block|,
name|NVM_TYPE_TIM1
block|}
block|,
block|{
literal|"TIM2"
block|,
literal|"-tim2"
block|,
name|NVM_TYPE_TIM2
block|}
block|,
block|{
literal|"MIM1"
block|,
literal|"-mim1"
block|,
name|NVM_TYPE_MIM1
block|}
block|,
block|{
literal|"MIM2"
block|,
literal|"-mim2"
block|,
name|NVM_TYPE_MIM2
block|}
block|,
block|{
literal|"MBA"
block|,
literal|"-mba"
block|,
name|NVM_TYPE_MBA
block|}
block|,
block|{
literal|"OPT_MODULES"
block|,
literal|"-optm"
block|,
name|NVM_TYPE_MODULES_PN
block|}
block|,
block|{
literal|"VPD"
block|,
literal|"-vpd"
block|,
name|NVM_TYPE_VPD
block|}
block|,
block|{
literal|"MFW_TRACE1"
block|,
literal|"-mfwt1"
block|,
name|NVM_TYPE_MFW_TRACE1
block|}
block|,
block|{
literal|"MFW_TRACE2"
block|,
literal|"-mfwt2"
block|,
name|NVM_TYPE_MFW_TRACE2
block|}
block|,
block|{
literal|"NVM_CFG1"
block|,
literal|"-cfg"
block|,
name|NVM_TYPE_NVM_CFG1
block|}
block|,
block|{
literal|"L2B"
block|,
literal|"-l2b"
block|,
name|NVM_TYPE_L2B
block|}
block|,
block|{
literal|"DIR1"
block|,
literal|"-dir1"
block|,
name|NVM_TYPE_DIR1
block|}
block|,
block|{
literal|"EAGLE_FW1"
block|,
literal|"-eagle1"
block|,
name|NVM_TYPE_EAGLE_FW1
block|}
block|,
block|{
literal|"FALCON_FW1"
block|,
literal|"-falcon1"
block|,
name|NVM_TYPE_FALCON_FW1
block|}
block|,
block|{
literal|"PCIE_FW1"
block|,
literal|"-pcie1"
block|,
name|NVM_TYPE_PCIE_FW1
block|}
block|,
block|{
literal|"HW_SET"
block|,
literal|"-hw_set"
block|,
name|NVM_TYPE_HW_SET
block|}
block|,
block|{
literal|"LIM"
block|,
literal|"-lim"
block|,
name|NVM_TYPE_LIM
block|}
block|,
block|{
literal|"AVS_FW1"
block|,
literal|"-avs1"
block|,
name|NVM_TYPE_AVS_FW1
block|}
block|,
block|{
literal|"DIR2"
block|,
literal|"-dir2"
block|,
name|NVM_TYPE_DIR2
block|}
block|,
block|{
literal|"CCM"
block|,
literal|"-ccm"
block|,
name|NVM_TYPE_CCM
block|}
block|,
block|{
literal|"EAGLE_FW2"
block|,
literal|"-eagle2"
block|,
name|NVM_TYPE_EAGLE_FW2
block|}
block|,
block|{
literal|"FALCON_FW2"
block|,
literal|"-falcon2"
block|,
name|NVM_TYPE_FALCON_FW2
block|}
block|,
block|{
literal|"PCIE_FW2"
block|,
literal|"-pcie2"
block|,
name|NVM_TYPE_PCIE_FW2
block|}
block|,
block|{
literal|"AVS_FW2"
block|,
literal|"-avs2"
block|,
name|NVM_TYPE_AVS_FW2
block|}
block|,
block|{
literal|"INIT_HW"
block|,
literal|"-init_hw"
block|,
name|NVM_TYPE_INIT_HW
block|}
block|,
block|{
literal|"DEFAULT_CFG"
block|,
literal|"-def_cfg"
block|,
name|NVM_TYPE_DEFAULT_CFG
block|}
block|,
block|{
literal|"CRASH_DUMP"
block|,
literal|"-mdump"
block|,
name|NVM_TYPE_MDUMP
block|}
block|,
block|{
literal|"META"
block|,
literal|"-meta"
block|,
name|NVM_TYPE_NVM_META
block|}
block|,
block|{
literal|"ISCSI_CFG"
block|,
literal|"-iscsi_cfg"
block|,
name|NVM_TYPE_ISCSI_CFG
block|}
block|,
block|{
literal|"FCOE_CFG"
block|,
literal|"-fcoe_cfg"
block|,
name|NVM_TYPE_FCOE_CFG
block|}
block|,
block|{
literal|"ETH_PHY_FW1"
block|,
literal|"-ethphy1"
block|,
name|NVM_TYPE_ETH_PHY_FW1
block|}
block|,
block|{
literal|"ETH_PHY_FW2"
block|,
literal|"-ethphy2"
block|,
name|NVM_TYPE_ETH_PHY_FW2
block|}
block|,
block|{
literal|"BDN"
block|,
literal|"-bdn"
block|,
name|NVM_TYPE_BDN
block|}
block|,
block|{
literal|"PK"
block|,
literal|"-pk"
block|,
name|NVM_TYPE_PUB_KEY
block|}
block|,
block|{
literal|"RECOVERY"
block|,
literal|"-recovery"
block|,
name|NVM_TYPE_RECOVERY
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IMAGE_TABLE_SIZE
value|(sizeof(g_image_table) / sizeof(struct image_map))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef DEFINE_IMAGE_TABLE */
end_comment

begin_define
define|#
directive|define
name|MAX_NVM_DIR_ENTRIES
value|150
end_define

begin_comment
comment|/* Note: The has given 150 possible entries since anyway each file captures at least one page. */
end_comment

begin_struct
struct|struct
name|nvm_dir
block|{
name|s32
name|seq
decl_stmt|;
comment|/* This dword is used to indicate whether this dir is valid, and whether it is more updated than the other dir */
define|#
directive|define
name|NVM_DIR_NEXT_MFW_MASK
value|0x00000001
define|#
directive|define
name|NVM_DIR_SEQ_MASK
value|0xfffffffe
define|#
directive|define
name|NVM_DIR_NEXT_MFW
parameter_list|(
name|seq
parameter_list|)
value|((seq)& NVM_DIR_NEXT_MFW_MASK)
define|#
directive|define
name|NVM_DIR_UPDATE_SEQ
parameter_list|(
name|_seq
parameter_list|,
name|swap_mfw
parameter_list|)
define|\
value|do { \ 		_seq = (((_seq + 2)& NVM_DIR_SEQ_MASK) | (NVM_DIR_NEXT_MFW(_seq ^ swap_mfw))); \ 	} while (0)
define|#
directive|define
name|IS_DIR_SEQ_VALID
parameter_list|(
name|seq
parameter_list|)
value|((seq& NVM_DIR_SEQ_MASK) != NVM_DIR_SEQ_MASK)
name|u32
name|num_images
decl_stmt|;
name|u32
name|rsrv
decl_stmt|;
name|struct
name|nvm_code_entry
name|code
index|[
literal|1
index|]
decl_stmt|;
comment|/* Up to MAX_NVM_DIR_ENTRIES */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NVM_DIR_SIZE
parameter_list|(
name|_num_images
parameter_list|)
value|(sizeof(struct nvm_dir) + (_num_images - 1) * sizeof(struct nvm_code_entry) + NVM_CRC_SIZE)
end_define

begin_struct
struct|struct
name|nvm_vpd_image
block|{
name|u32
name|format_revision
decl_stmt|;
define|#
directive|define
name|VPD_IMAGE_VERSION
value|1
comment|/* This array length depends on the number of VPD fields */
name|u8
name|vpd_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * NVRAM FULL MAP                                                           *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DIR_ID_1
value|(0)
end_define

begin_define
define|#
directive|define
name|DIR_ID_2
value|(1)
end_define

begin_define
define|#
directive|define
name|MAX_DIR_IDS
value|(2)
end_define

begin_define
define|#
directive|define
name|MFW_BUNDLE_1
value|(0)
end_define

begin_define
define|#
directive|define
name|MFW_BUNDLE_2
value|(1)
end_define

begin_define
define|#
directive|define
name|MAX_MFW_BUNDLES
value|(2)
end_define

begin_define
define|#
directive|define
name|FLASH_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|NVM_DIR_MAX_SIZE
value|(FLASH_PAGE_SIZE)
end_define

begin_comment
comment|/* 4Kb */
end_comment

begin_define
define|#
directive|define
name|ASIC_MIM_MAX_SIZE
value|(300*FLASH_PAGE_SIZE)
end_define

begin_comment
comment|/* 1.2Mb */
end_comment

begin_define
define|#
directive|define
name|FPGA_MIM_MAX_SIZE
value|(62*FLASH_PAGE_SIZE)
end_define

begin_comment
comment|/* 250Kb */
end_comment

begin_comment
comment|/* Each image must start on its own page. Bootstrap and LIM are bound together, so they can share the same page.  * The LIM itself should be very small, so limit it to 8Kb, but in order to open a new page, we decrement the bootstrap size out of it.  */
end_comment

begin_define
define|#
directive|define
name|LIM_MAX_SIZE
value|((2*FLASH_PAGE_SIZE) - sizeof(struct legacy_bootstrap_region) - NVM_RSV_SIZE)
end_define

begin_define
define|#
directive|define
name|LIM_OFFSET
value|(NVM_OFFSET(lim_image))
end_define

begin_define
define|#
directive|define
name|NVM_RSV_SIZE
value|(44)
end_define

begin_define
define|#
directive|define
name|MIM_MAX_SIZE
parameter_list|(
name|is_asic
parameter_list|)
value|((is_asic) ? ASIC_MIM_MAX_SIZE : FPGA_MIM_MAX_SIZE )
end_define

begin_define
define|#
directive|define
name|MIM_OFFSET
parameter_list|(
name|idx
parameter_list|,
name|is_asic
parameter_list|)
value|(NVM_OFFSET(dir[MAX_MFW_BUNDLES]) + ((idx == NVM_TYPE_MIM2) ? MIM_MAX_SIZE(is_asic) : 0))
end_define

begin_define
define|#
directive|define
name|NVM_FIXED_AREA_SIZE
parameter_list|(
name|is_asic
parameter_list|)
value|(sizeof(struct nvm_image) + MIM_MAX_SIZE(is_asic)*2)
end_define

begin_union
union|union
name|nvm_dir_union
block|{
name|struct
name|nvm_dir
name|dir
decl_stmt|;
name|u8
name|page
index|[
name|FLASH_PAGE_SIZE
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*                        Address  *  +-------------------+ 0x000000  *  |    Bootstrap:     |  *  | magic_number      |  *  | sram_start_addr   |  *  | code_len  	|  *  | code_start_addr   |  *  | crc               |  *  +-------------------+ 0x000014  *  | rsrv              |  *  +-------------------+ 0x000040  *  | LIM               |  *  +-------------------+ 0x002000  *  | Dir1              |  *  +-------------------+ 0x003000  *  | Dir2              |  *  +-------------------+ 0x004000  *  | MIM1              |  *  +-------------------+ 0x130000  *  | MIM2              |  *  +-------------------+ 0x25C000  *  | Rest Images:      |  *  | TIM1/2    	|  *  | MFW_TRACE1/2      |  *  | Eagle/Falcon FW   |  *  | PCIE/AVS FW       |  *  | MBA/CCM/L2B       |  *  | VPD       	|  *  | optic_modules     |  *  |  ...              |  *  +-------------------+ 0x400000 */
end_comment

begin_struct
struct|struct
name|nvm_image
block|{
comment|/*********** !!!  FIXED SECTIONS  !!! DO NOT MODIFY !!! **********************/
comment|/* NVM Offset  (size) */
name|struct
name|legacy_bootstrap_region
name|bootstrap
decl_stmt|;
comment|/* 0x000000 (0x000014) */
name|u8
name|rsrv
index|[
name|NVM_RSV_SIZE
index|]
decl_stmt|;
comment|/* 0x000014 (0x00002c) */
name|u8
name|lim_image
index|[
name|LIM_MAX_SIZE
index|]
decl_stmt|;
comment|/* 0x000040 (0x001fc0) */
name|union
name|nvm_dir_union
name|dir
index|[
name|MAX_MFW_BUNDLES
index|]
decl_stmt|;
comment|/* 0x002000 (0x001000)x2 */
comment|/* MIM1_IMAGE        	                   0x004000 (0x12c000) */
comment|/* MIM2_IMAGE                              0x130000 (0x12c000) */
comment|/*********** !!!  FIXED SECTIONS  !!! DO NOT MODIFY !!! **********************/
block|}
struct|;
end_struct

begin_comment
comment|/* 0x134 */
end_comment

begin_define
define|#
directive|define
name|NVM_OFFSET
parameter_list|(
name|f
parameter_list|)
value|((u32_t)((int_ptr_t)(&(((struct nvm_image*)0)->f))))
end_define

begin_struct
struct|struct
name|hw_set_info
block|{
name|u32
name|reg_type
decl_stmt|;
define|#
directive|define
name|GRC_REG_TYPE
value|1
define|#
directive|define
name|PHY_REG_TYPE
value|2
define|#
directive|define
name|PCI_REG_TYPE
value|4
name|u32
name|bank_num
decl_stmt|;
name|u32
name|pf_num
decl_stmt|;
name|u32
name|operation
decl_stmt|;
define|#
directive|define
name|READ_OP
value|1
define|#
directive|define
name|WRITE_OP
value|2
define|#
directive|define
name|RMW_SET_OP
value|3
define|#
directive|define
name|RMW_CLR_OP
value|4
name|u32
name|reg_addr
decl_stmt|;
name|u32
name|reg_data
decl_stmt|;
name|u32
name|reset_type
decl_stmt|;
define|#
directive|define
name|POR_RESET_TYPE
value|(1<< 0)
define|#
directive|define
name|HARD_RESET_TYPE
value|(1<< 1)
define|#
directive|define
name|CORE_RESET_TYPE
value|(1<< 2)
define|#
directive|define
name|MCP_RESET_TYPE
value|(1<< 3)
define|#
directive|define
name|PERSET_ASSERT
value|(1<< 4)
define|#
directive|define
name|PERSET_DEASSERT
value|(1<< 5)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hw_set_image
block|{
name|u32
name|format_version
decl_stmt|;
define|#
directive|define
name|HW_SET_IMAGE_VERSION
value|1
name|u32
name|no_hw_sets
decl_stmt|;
comment|/* This array length depends on the no_hw_sets */
name|struct
name|hw_set_info
name|hw_sets
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//NVM_MAP_H
end_comment

end_unit

