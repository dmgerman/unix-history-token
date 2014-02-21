begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_MDIO_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_MDIO_H__
end_define

begin_comment
comment|/** * @file_name mdio.h * @author Netlogic Microsystems * @brief Access functions for XLP MDIO  */
end_comment

begin_define
define|#
directive|define
name|INT_MDIO_CTRL
value|0x19
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_DATA
value|0x1A
end_define

begin_define
define|#
directive|define
name|INT_MDIO_RD_STAT
value|0x1B
end_define

begin_define
define|#
directive|define
name|INT_MDIO_LINK_STAT
value|0x1C
end_define

begin_define
define|#
directive|define
name|EXT_G0_MDIO_CTRL
value|0x1D
end_define

begin_define
define|#
directive|define
name|EXT_G1_MDIO_CTRL
value|0x21
end_define

begin_define
define|#
directive|define
name|EXT_G0_MDIO_CTRL_DATA
value|0x1E
end_define

begin_define
define|#
directive|define
name|EXT_G1_MDIO_CTRL_DATA
value|0x22
end_define

begin_define
define|#
directive|define
name|EXT_G0_MDIO_LINK_STAT
value|0x20
end_define

begin_define
define|#
directive|define
name|EXT_G1_MDIO_LINK_STAT
value|0x24
end_define

begin_define
define|#
directive|define
name|EXT_G0_MDIO_RD_STAT
value|0x1F
end_define

begin_define
define|#
directive|define
name|EXT_G1_MDIO_RD_STAT
value|0x23
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_ST_POS
value|0
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_OP_POS
value|2
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_PHYADDR_POS
value|4
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_DEVTYPE_POS
value|9
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_TA_POS
value|14
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_MIIM_POS
value|16
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_LOAD_POS
value|19
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_XDIV_POS
value|21
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_MCDIV_POS
value|28
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_RST
value|0x40000000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_SMP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_CTRL_CMD_LOAD
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_RD_STAT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INT_MDIO_STAT_LFV
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_STAT_SC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_STAT_SM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_STAT_MIILFS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INT_MDIO_STAT_MBSY
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CLOCK_DIV_4
value|0
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CLOCK_DIV_2
value|1
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CLOCK_DIV_1
value|2
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_REGADDR_POS
value|5
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_PHYADDR_POS
value|10
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CMD_SP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CMD_PSIA
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CMD_LCD
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CMD_RDS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_CMD_SC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_MMRST
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_DIV
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_DIV_WITH_HW_DIV64
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_RD_STAT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_STAT_LFV
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_STAT_SC
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_STAT_SM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_STAT_MIILFS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EXT_G_MDIO_STAT_MBSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_CMD_READ
value|0x10
end_define

begin_define
define|#
directive|define
name|MDIO_OP_CMD_WRITE
value|0x01
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_function_decl
name|int
name|nlm_int_gmac_mdio_read
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_int_gmac_mdio_write
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_int_gmac_mdio_reset
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_gmac_mdio_read
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_gmac_mdio_write
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_gmac_mdio_reset
parameter_list|(
name|uint64_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nlm_mdio_reset_all
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(LOCORE)&& !(__ASSEMBLY__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

