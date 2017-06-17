begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HW_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HW_H__
end_define

begin_include
include|#
directive|include
file|"ecore.h"
end_include

begin_include
include|#
directive|include
file|"ecore_dev_api.h"
end_include

begin_comment
comment|/* Forward decleration */
end_comment

begin_struct_decl
struct_decl|struct
name|ecore_ptt
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|reserved_ptts
block|{
name|RESERVED_PTT_EDIAG
block|,
name|RESERVED_PTT_USER_SPACE
block|,
name|RESERVED_PTT_MAIN
block|,
name|RESERVED_PTT_DPC
block|,
name|RESERVED_PTT_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* @@@TMP - in earlier versions of the emulation, the HW lock started from 1  * instead of 0, this should be fixed in later HW versions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MISC_REG_DRIVER_CONTROL_0
end_ifndef

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_0
value|MISC_REG_DRIVER_CONTROL_1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MISC_REG_DRIVER_CONTROL_0_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MISC_REG_DRIVER_CONTROL_0_SIZE
value|MISC_REG_DRIVER_CONTROL_1_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|_dmae_cmd_dst_mask
block|{
name|DMAE_CMD_DST_MASK_NONE
init|=
literal|0
block|,
name|DMAE_CMD_DST_MASK_PCIE
init|=
literal|1
block|,
name|DMAE_CMD_DST_MASK_GRC
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
name|_dmae_cmd_src_mask
block|{
name|DMAE_CMD_SRC_MASK_PCIE
init|=
literal|0
block|,
name|DMAE_CMD_SRC_MASK_GRC
init|=
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|_dmae_cmd_crc_mask
block|{
name|DMAE_CMD_COMP_CRC_EN_MASK_NONE
init|=
literal|0
block|,
name|DMAE_CMD_COMP_CRC_EN_MASK_SET
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* definitions for DMA constants */
end_comment

begin_define
define|#
directive|define
name|DMAE_GO_VALUE
value|0x1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|DMAE_COMPLETION_VAL
value|0xAED10000
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY
value|0x3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMAE_COMPLETION_VAL
value|0xD1AE
end_define

begin_define
define|#
directive|define
name|DMAE_CMD_ENDIANITY
value|0x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DMAE_CMD_SIZE
value|14
end_define

begin_comment
comment|/* size of DMAE command structure to fill.. DMAE_CMD_SIZE-5 */
end_comment

begin_define
define|#
directive|define
name|DMAE_CMD_SIZE_TO_FILL
value|(DMAE_CMD_SIZE - 5)
end_define

begin_comment
comment|/* Minimum wait for dmae opertaion to complete 2 milliseconds */
end_comment

begin_define
define|#
directive|define
name|DMAE_MIN_WAIT_TIME
value|0x2
end_define

begin_define
define|#
directive|define
name|DMAE_MAX_CLIENTS
value|32
end_define

begin_comment
comment|/** * @brief ecore_gtt_init - Initialize GTT windows * * @param p_hwfn * @param p_ptt */
end_comment

begin_function_decl
name|void
name|ecore_gtt_init
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_invalidate - Forces all ptt entries to be re-configured  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_ptt_invalidate
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_pool_alloc - Allocate and initialize PTT pool  *  * @param p_hwfn  *  * @return _ecore_status_t - success (0), negative - error.  */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_ptt_pool_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_pool_free -  *  * @param p_hwfn  */
end_comment

begin_function_decl
name|void
name|ecore_ptt_pool_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_get_hw_addr - Get PTT's GRC/HW address  *  * @param p_ptt  *  * @return u32  */
end_comment

begin_function_decl
name|u32
name|ecore_ptt_get_hw_addr
parameter_list|(
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_get_bar_addr - Get PPT's external BAR address  *  * @param p_hwfn  * @param p_ptt  *  * @return u32  */
end_comment

begin_function_decl
name|u32
name|ecore_ptt_get_bar_addr
parameter_list|(
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_ptt_set_win - Set PTT Window's GRC BAR address  *  * @param p_hwfn  * @param new_hw_addr  * @param p_ptt  */
end_comment

begin_function_decl
name|void
name|ecore_ptt_set_win
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|new_hw_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_get_reserved_ptt - Get a specific reserved PTT  *  * @param p_hwfn  * @param ptt_idx  *  * @return struct ecore_ptt *  */
end_comment

begin_function_decl
name|struct
name|ecore_ptt
modifier|*
name|ecore_get_reserved_ptt
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|reserved_ptts
name|ptt_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_wr - Write value to BAR using the given ptt  *  * @param p_hwfn  * @param p_ptt  * @param val  * @param hw_addr  */
end_comment

begin_function_decl
name|void
name|ecore_wr
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|hw_addr
parameter_list|,
name|u32
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_rd - Read value from BAR using the given ptt  *  * @param p_hwfn  * @param p_ptt  * @param val  * @param hw_addr  */
end_comment

begin_function_decl
name|u32
name|ecore_rd
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|hw_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_memcpy_from - copy n bytes from BAR using the given  *        ptt  *  * @param p_hwfn  * @param p_ptt  * @param dest  * @param hw_addr  * @param n  */
end_comment

begin_function_decl
name|void
name|ecore_memcpy_from
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|u32
name|hw_addr
parameter_list|,
name|osal_size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_memcpy_to - copy n bytes to BAR using the given  *        ptt  *  * @param p_hwfn  * @param p_ptt  * @param hw_addr  * @param src  * @param n  */
end_comment

begin_function_decl
name|void
name|ecore_memcpy_to
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u32
name|hw_addr
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|osal_size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_fid_pretend - pretend to another function when  *        accessing the ptt window. There is no way to unpretend  *        a function. The only way to cancel a pretend is to  *        pretend back to the original function.  *  * @param p_hwfn  * @param p_ptt  * @param fid - fid field of pxp_pretend structure. Can contain  *            either pf / vf, port/path fields are don't care.  */
end_comment

begin_function_decl
name|void
name|ecore_fid_pretend
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u16
name|fid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_port_pretend - pretend to another port when  *        accessing the ptt window  *  * @param p_hwfn  * @param p_ptt  * @param port_id - the port to pretend to  */
end_comment

begin_function_decl
name|void
name|ecore_port_pretend
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|,
name|u8
name|port_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_port_unpretend - cancel any previously set port  *        pretend  *  * @param p_hwfn  * @param p_ptt  */
end_comment

begin_function_decl
name|void
name|ecore_port_unpretend
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|struct
name|ecore_ptt
modifier|*
name|p_ptt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief ecore_vfid_to_concrete - build a concrete FID for a  *        given VF ID  *  * @param p_hwfn  * @param p_ptt  * @param vfid  */
end_comment

begin_function_decl
name|u32
name|ecore_vfid_to_concrete
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|u8
name|vfid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_dmae_info_alloc - Init the dmae_info structure * which is part of p_hwfn. * @param p_hwfn */
end_comment

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_dmae_info_alloc
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** * @brief ecore_dmae_info_free - Free the dmae_info structure * which is part of p_hwfn * * @param p_hwfn */
end_comment

begin_function_decl
name|void
name|ecore_dmae_info_free
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|_ecore_status_t
name|ecore_init_fw_data
parameter_list|(
name|struct
name|ecore_dev
modifier|*
name|p_dev
parameter_list|,
specifier|const
name|u8
modifier|*
name|fw_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_hw_err_notify
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|p_hwfn
parameter_list|,
name|enum
name|ecore_hw_err_type
name|err_type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HW_H__ */
end_comment

end_unit

