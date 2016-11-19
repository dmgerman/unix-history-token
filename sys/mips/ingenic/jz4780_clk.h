begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2015 Alexander Kabaev<kan@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_INGENIC_JZ4780_CLK_H
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_INGENIC_JZ4780_CLK_H
end_define

begin_include
include|#
directive|include
file|<dev/extres/clk/clk.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_gate.h>
end_include

begin_comment
comment|/* Convenience bitfiled manipulation macros */
end_comment

begin_define
define|#
directive|define
name|REG_MSK
parameter_list|(
name|field
parameter_list|)
value|(((1u<< field ## _WIDTH) - 1)<< field ##_SHIFT)
end_define

begin_define
define|#
directive|define
name|REG_VAL
parameter_list|(
name|field
parameter_list|,
name|val
parameter_list|)
value|((val)<< field ##_SHIFT)
end_define

begin_define
define|#
directive|define
name|REG_CLR
parameter_list|(
name|reg
parameter_list|,
name|field
parameter_list|)
value|((reg)& ~REG_MSK(field))
end_define

begin_define
define|#
directive|define
name|REG_GET
parameter_list|(
name|reg
parameter_list|,
name|field
parameter_list|)
value|(((reg)& REG_MSK(field))>> field ##_SHIFT)
end_define

begin_define
define|#
directive|define
name|REG_SET
parameter_list|(
name|reg
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|(REG_CLR(reg, field) | REG_VAL(field, val))
end_define

begin_comment
comment|/* Common clock macros */
end_comment

begin_define
define|#
directive|define
name|CLK_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock((_sc)->clk_mtx)
end_define

begin_define
define|#
directive|define
name|CLK_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock((_sc)->clk_mtx)
end_define

begin_define
define|#
directive|define
name|CLK_WR_4
parameter_list|(
name|_sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((_sc)->clk_res, (off), (val))
end_define

begin_define
define|#
directive|define
name|CLK_RD_4
parameter_list|(
name|_sc
parameter_list|,
name|off
parameter_list|)
value|bus_read_4((_sc)->clk_res, (off))
end_define

begin_struct
struct|struct
name|jz4780_clk_mux_descr
block|{
name|uint16_t
name|mux_reg
decl_stmt|;
name|uint16_t
name|mux_shift
range|:
literal|5
decl_stmt|;
name|uint16_t
name|mux_bits
range|:
literal|5
decl_stmt|;
name|uint16_t
name|mux_map
range|:
literal|4
decl_stmt|;
comment|/* Map into mux space */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jz4780_clk_div_descr
block|{
name|uint16_t
name|div_reg
decl_stmt|;
name|uint16_t
name|div_shift
range|:
literal|5
decl_stmt|;
name|uint16_t
name|div_bits
range|:
literal|5
decl_stmt|;
name|uint16_t
name|div_lg
range|:
literal|5
decl_stmt|;
name|int
name|div_ce_bit
range|:
literal|6
decl_stmt|;
comment|/* -1, if CE bit is not present */
name|int
name|div_st_bit
range|:
literal|6
decl_stmt|;
comment|/* Can be negative */
name|int
name|div_busy_bit
range|:
literal|6
decl_stmt|;
comment|/* Can be negative */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jz4780_clk_descr
block|{
name|uint16_t
name|clk_id
range|:
literal|6
decl_stmt|;
name|uint16_t
name|clk_type
range|:
literal|3
decl_stmt|;
name|int
name|clk_gate_bit
range|:
literal|7
decl_stmt|;
comment|/* Can be negative */
name|struct
name|jz4780_clk_mux_descr
name|clk_mux
decl_stmt|;
name|struct
name|jz4780_clk_div_descr
name|clk_div
decl_stmt|;
specifier|const
name|char
modifier|*
name|clk_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|clk_pnames
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* clk_type bits */
end_comment

begin_define
define|#
directive|define
name|CLK_MASK_GATE
value|0x01
end_define

begin_define
define|#
directive|define
name|CLK_MASK_DIV
value|0x02
end_define

begin_define
define|#
directive|define
name|CLK_MASK_MUX
value|0x04
end_define

begin_function_decl
specifier|extern
name|int
name|jz4780_clk_gen_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
specifier|const
name|struct
name|jz4780_clk_descr
modifier|*
name|descr
parameter_list|,
name|struct
name|mtx
modifier|*
name|dev_mtx
parameter_list|,
name|struct
name|resource
modifier|*
name|mem_res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|jz4780_clk_pll_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|struct
name|clknode_init_def
modifier|*
name|clkdef
parameter_list|,
name|struct
name|mtx
modifier|*
name|dev_mtx
parameter_list|,
name|struct
name|resource
modifier|*
name|mem_res
parameter_list|,
name|uint32_t
name|mem_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|jz4780_clk_otg_register
parameter_list|(
name|struct
name|clkdom
modifier|*
name|clkdom
parameter_list|,
name|struct
name|clknode_init_def
modifier|*
name|clkdef
parameter_list|,
name|struct
name|mtx
modifier|*
name|dev_mtx
parameter_list|,
name|struct
name|resource
modifier|*
name|mem_res
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_INGENIC_JZ4780_CLK_PLL_H */
end_comment

end_unit

