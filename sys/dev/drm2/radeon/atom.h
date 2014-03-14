begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Author: Stanislaw Skowronek  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|ATOM_H
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_define
define|#
directive|define
name|ATOM_BIOS_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|ATOM_ATI_MAGIC_PTR
value|0x30
end_define

begin_define
define|#
directive|define
name|ATOM_ATI_MAGIC
value|" 761295520"
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_TABLE_PTR
value|0x48
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_MAGIC
value|"ATOM"
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_MAGIC_PTR
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_MSG_PTR
value|0x10
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_CMD_PTR
value|0x1E
end_define

begin_define
define|#
directive|define
name|ATOM_ROM_DATA_PTR
value|0x20
end_define

begin_define
define|#
directive|define
name|ATOM_CMD_INIT
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CMD_SETSCLK
value|0x0A
end_define

begin_define
define|#
directive|define
name|ATOM_CMD_SETMCLK
value|0x0B
end_define

begin_define
define|#
directive|define
name|ATOM_CMD_SETPCLK
value|0x0C
end_define

begin_define
define|#
directive|define
name|ATOM_CMD_SPDFANCNTL
value|0x39
end_define

begin_define
define|#
directive|define
name|ATOM_DATA_FWI_PTR
value|0xC
end_define

begin_define
define|#
directive|define
name|ATOM_DATA_IIO_PTR
value|0x32
end_define

begin_define
define|#
directive|define
name|ATOM_FWI_DEFSCLK_PTR
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_FWI_DEFMCLK_PTR
value|0xC
end_define

begin_define
define|#
directive|define
name|ATOM_FWI_MAXSCLK_PTR
value|0x24
end_define

begin_define
define|#
directive|define
name|ATOM_FWI_MAXMCLK_PTR
value|0x28
end_define

begin_define
define|#
directive|define
name|ATOM_CT_SIZE_PTR
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_CT_WS_PTR
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_CT_PS_PTR
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_CT_PS_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|ATOM_CT_CODE_PTR
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_OP_CNT
value|123
end_define

begin_define
define|#
directive|define
name|ATOM_OP_EOT
value|91
end_define

begin_define
define|#
directive|define
name|ATOM_CASE_MAGIC
value|0x63
end_define

begin_define
define|#
directive|define
name|ATOM_CASE_END
value|0x5A5A
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_REG
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_PS
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_WS
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_FB
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_ID
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_IMM
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_PLL
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_ARG_MC
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_DWORD
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_WORD0
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_WORD8
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_WORD16
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_BYTE0
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_BYTE8
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_BYTE16
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_SRC_BYTE24
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_WS_QUOTIENT
value|0x40
end_define

begin_define
define|#
directive|define
name|ATOM_WS_REMAINDER
value|0x41
end_define

begin_define
define|#
directive|define
name|ATOM_WS_DATAPTR
value|0x42
end_define

begin_define
define|#
directive|define
name|ATOM_WS_SHIFT
value|0x43
end_define

begin_define
define|#
directive|define
name|ATOM_WS_OR_MASK
value|0x44
end_define

begin_define
define|#
directive|define
name|ATOM_WS_AND_MASK
value|0x45
end_define

begin_define
define|#
directive|define
name|ATOM_WS_FB_WINDOW
value|0x46
end_define

begin_define
define|#
directive|define
name|ATOM_WS_ATTRIBUTES
value|0x47
end_define

begin_define
define|#
directive|define
name|ATOM_WS_REGPTR
value|0x48
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_NOP
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_START
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_READ
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_WRITE
value|3
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_CLEAR
value|4
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_SET
value|5
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_MOVE_INDEX
value|6
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_MOVE_ATTR
value|7
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_MOVE_DATA
value|8
end_define

begin_define
define|#
directive|define
name|ATOM_IIO_END
value|9
end_define

begin_define
define|#
directive|define
name|ATOM_IO_MM
value|0
end_define

begin_define
define|#
directive|define
name|ATOM_IO_PCI
value|1
end_define

begin_define
define|#
directive|define
name|ATOM_IO_SYSIO
value|2
end_define

begin_define
define|#
directive|define
name|ATOM_IO_IIO
value|0x80
end_define

begin_struct
struct|struct
name|card_info
block|{
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|void
function_decl|(
modifier|*
name|reg_write
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|uint32_t
function_decl|(
modifier|*
name|reg_read
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|void
function_decl|(
modifier|*
name|ioreg_write
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|uint32_t
function_decl|(
modifier|*
name|ioreg_read
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|void
function_decl|(
modifier|*
name|mc_write
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|uint32_t
function_decl|(
modifier|*
name|mc_read
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|void
function_decl|(
modifier|*
name|pll_write
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
name|uint32_t
function_decl|(
modifier|*
name|pll_read
function_decl|)
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
comment|/*  filled by driver */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atom_context
block|{
name|struct
name|card_info
modifier|*
name|card
decl_stmt|;
name|struct
name|sx
name|mutex
decl_stmt|;
name|void
modifier|*
name|bios
decl_stmt|;
name|uint32_t
name|cmd_table
decl_stmt|,
name|data_table
decl_stmt|;
name|uint16_t
modifier|*
name|iio
decl_stmt|;
name|uint16_t
name|data_block
decl_stmt|;
name|uint32_t
name|fb_base
decl_stmt|;
name|uint32_t
name|divmul
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|io_attr
decl_stmt|;
name|uint16_t
name|reg_block
decl_stmt|;
name|uint8_t
name|shift
decl_stmt|;
name|int
name|cs_equal
decl_stmt|,
name|cs_above
decl_stmt|;
name|int
name|io_mode
decl_stmt|;
name|uint32_t
modifier|*
name|scratch
decl_stmt|;
name|int
name|scratch_size_bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|atom_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|atom_context
modifier|*
name|atom_parse
parameter_list|(
name|struct
name|card_info
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atom_execute_table
parameter_list|(
name|struct
name|atom_context
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atom_asic_init
parameter_list|(
name|struct
name|atom_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atom_destroy
parameter_list|(
name|struct
name|atom_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atom_parse_data_header
parameter_list|(
name|struct
name|atom_context
modifier|*
name|ctx
parameter_list|,
name|int
name|index
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|,
name|uint8_t
modifier|*
name|frev
parameter_list|,
name|uint8_t
modifier|*
name|crev
parameter_list|,
name|uint16_t
modifier|*
name|data_start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atom_parse_cmd_header
parameter_list|(
name|struct
name|atom_context
modifier|*
name|ctx
parameter_list|,
name|int
name|index
parameter_list|,
name|uint8_t
modifier|*
name|frev
parameter_list|,
name|uint8_t
modifier|*
name|crev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atom_allocate_fb_scratch
parameter_list|(
name|struct
name|atom_context
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"atom-types.h"
end_include

begin_include
include|#
directive|include
file|"atombios.h"
end_include

begin_include
include|#
directive|include
file|"ObjectID.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

