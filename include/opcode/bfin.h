begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bfin.h -- Header file for ADI Blackfin opcode table    Copyright 2005 Free Software Foundation, Inc.  This file is part of GDB, GAS, and the GNU binutils.  GDB, GAS, and the GNU binutils are free software; you can redistribute them and/or modify them under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB, GAS, and the GNU binutils are distributed in the hope that they will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this file; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Common to all DSP32 instructions.  */
end_comment

begin_define
define|#
directive|define
name|BIT_MULTI_INS
value|0x0800
end_define

begin_comment
comment|/* This just sets the multi instruction bit of a DSP32 instruction.  */
end_comment

begin_define
define|#
directive|define
name|SET_MULTI_INSTRUCTION_BIT
parameter_list|(
name|x
parameter_list|)
value|x->value |=  BIT_MULTI_INS;
end_define

begin_comment
comment|/* DSP instructions (32 bit) */
end_comment

begin_comment
comment|/*   dsp32mac +----+----+---+---|---+----+----+---|---+---+---+---|---+---+---+---+ | 1  | 1  | 0 | 0 |.M.| 0  | 0  |.mmod..........|.MM|.P.|.w1|.op1...| |.h01|.h11|.w0|.op0...|.h00|.h10|.dst.......|.src0......|.src1......| +----+----+---+---|---+----+----+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_src1
decl_stmt|;
name|int
name|mask_src1
decl_stmt|;
name|int
name|bits_src0
decl_stmt|;
name|int
name|mask_src0
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_h10
decl_stmt|;
name|int
name|mask_h10
decl_stmt|;
name|int
name|bits_h00
decl_stmt|;
name|int
name|mask_h00
decl_stmt|;
name|int
name|bits_op0
decl_stmt|;
name|int
name|mask_op0
decl_stmt|;
name|int
name|bits_w0
decl_stmt|;
name|int
name|mask_w0
decl_stmt|;
name|int
name|bits_h11
decl_stmt|;
name|int
name|mask_h11
decl_stmt|;
name|int
name|bits_h01
decl_stmt|;
name|int
name|mask_h01
decl_stmt|;
name|int
name|bits_op1
decl_stmt|;
name|int
name|mask_op1
decl_stmt|;
name|int
name|bits_w1
decl_stmt|;
name|int
name|mask_w1
decl_stmt|;
name|int
name|bits_P
decl_stmt|;
name|int
name|mask_P
decl_stmt|;
name|int
name|bits_MM
decl_stmt|;
name|int
name|mask_MM
decl_stmt|;
name|int
name|bits_mmod
decl_stmt|;
name|int
name|mask_mmod
decl_stmt|;
name|int
name|bits_code2
decl_stmt|;
name|int
name|mask_code2
decl_stmt|;
name|int
name|bits_M
decl_stmt|;
name|int
name|mask_M
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DSP32Mac
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSP32Mac_opcode
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|DSP32Mac_src1_bits
value|0
end_define

begin_define
define|#
directive|define
name|DSP32Mac_src1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Mac_src0_bits
value|3
end_define

begin_define
define|#
directive|define
name|DSP32Mac_src0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Mac_dst_bits
value|6
end_define

begin_define
define|#
directive|define
name|DSP32Mac_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h10_bits
value|9
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h10_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h00_bits
value|10
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h00_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_op0_bits
value|11
end_define

begin_define
define|#
directive|define
name|DSP32Mac_op0_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Mac_w0_bits
value|13
end_define

begin_define
define|#
directive|define
name|DSP32Mac_w0_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h11_bits
value|14
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h11_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h01_bits
value|15
end_define

begin_define
define|#
directive|define
name|DSP32Mac_h01_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_op1_bits
value|16
end_define

begin_define
define|#
directive|define
name|DSP32Mac_op1_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Mac_w1_bits
value|18
end_define

begin_define
define|#
directive|define
name|DSP32Mac_w1_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_p_bits
value|19
end_define

begin_define
define|#
directive|define
name|DSP32Mac_p_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_MM_bits
value|20
end_define

begin_define
define|#
directive|define
name|DSP32Mac_MM_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_mmod_bits
value|21
end_define

begin_define
define|#
directive|define
name|DSP32Mac_mmod_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|DSP32Mac_code2_bits
value|25
end_define

begin_define
define|#
directive|define
name|DSP32Mac_code2_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Mac_M_bits
value|27
end_define

begin_define
define|#
directive|define
name|DSP32Mac_M_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Mac_code_bits
value|28
end_define

begin_define
define|#
directive|define
name|DSP32Mac_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_DSP32Mac
define|\
value|{						\   DSP32Mac_opcode,				\   DSP32Mac_src1_bits,	DSP32Mac_src1_mask,	\   DSP32Mac_src0_bits,	DSP32Mac_src0_mask,	\   DSP32Mac_dst_bits,	DSP32Mac_dst_mask,	\   DSP32Mac_h10_bits,	DSP32Mac_h10_mask,	\   DSP32Mac_h00_bits,	DSP32Mac_h00_mask,	\   DSP32Mac_op0_bits,	DSP32Mac_op0_mask,	\   DSP32Mac_w0_bits,	DSP32Mac_w0_mask,	\   DSP32Mac_h11_bits,	DSP32Mac_h11_mask,	\   DSP32Mac_h01_bits,	DSP32Mac_h01_mask,	\   DSP32Mac_op1_bits,	DSP32Mac_op1_mask,	\   DSP32Mac_w1_bits,	DSP32Mac_w1_mask,	\   DSP32Mac_p_bits,	DSP32Mac_p_mask,	\   DSP32Mac_MM_bits,	DSP32Mac_MM_mask,	\   DSP32Mac_mmod_bits,	DSP32Mac_mmod_mask,	\   DSP32Mac_code2_bits,	DSP32Mac_code2_mask,	\   DSP32Mac_M_bits,	DSP32Mac_M_mask,	\   DSP32Mac_code_bits,	DSP32Mac_code_mask	\ };
end_define

begin_comment
comment|/*  dsp32mult +----+----+---+---|---+----+----+---|---+---+---+---|---+---+---+---+ | 1  | 1  | 0 | 0 |.M.| 0  | 1  |.mmod..........|.MM|.P.|.w1|.op1...| |.h01|.h11|.w0|.op0...|.h00|.h10|.dst.......|.src0......|.src1......| +----+----+---+---|---+----+----+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
name|DSP32Mac
name|DSP32Mult
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSP32Mult_opcode
value|0xc2000000
end_define

begin_define
define|#
directive|define
name|init_DSP32Mult
define|\
value|{						\   DSP32Mult_opcode,				\   DSP32Mac_src1_bits,	DSP32Mac_src1_mask,	\   DSP32Mac_src0_bits,	DSP32Mac_src0_mask,	\   DSP32Mac_dst_bits,	DSP32Mac_dst_mask,	\   DSP32Mac_h10_bits,	DSP32Mac_h10_mask,	\   DSP32Mac_h00_bits,	DSP32Mac_h00_mask,	\   DSP32Mac_op0_bits,	DSP32Mac_op0_mask,	\   DSP32Mac_w0_bits,	DSP32Mac_w0_mask,	\   DSP32Mac_h11_bits,	DSP32Mac_h11_mask,	\   DSP32Mac_h01_bits,	DSP32Mac_h01_mask,	\   DSP32Mac_op1_bits,	DSP32Mac_op1_mask,	\   DSP32Mac_w1_bits,	DSP32Mac_w1_mask,	\   DSP32Mac_p_bits,	DSP32Mac_p_mask,	\   DSP32Mac_MM_bits,	DSP32Mac_MM_mask,	\   DSP32Mac_mmod_bits,	DSP32Mac_mmod_mask,	\   DSP32Mac_code2_bits,	DSP32Mac_code2_mask,	\   DSP32Mac_M_bits,	DSP32Mac_M_mask,	\   DSP32Mac_code_bits,	DSP32Mac_code_mask	\ };
end_define

begin_comment
comment|/*  dsp32alu +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 0 | 0 |.M.| 1 | 0 | - | - | - |.HL|.aopcde............| |.aop...|.s.|.x.|.dst0......|.dst1......|.src0......|.src1......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_src1
decl_stmt|;
name|int
name|mask_src1
decl_stmt|;
name|int
name|bits_src0
decl_stmt|;
name|int
name|mask_src0
decl_stmt|;
name|int
name|bits_dst1
decl_stmt|;
name|int
name|mask_dst1
decl_stmt|;
name|int
name|bits_dst0
decl_stmt|;
name|int
name|mask_dst0
decl_stmt|;
name|int
name|bits_x
decl_stmt|;
name|int
name|mask_x
decl_stmt|;
name|int
name|bits_s
decl_stmt|;
name|int
name|mask_s
decl_stmt|;
name|int
name|bits_aop
decl_stmt|;
name|int
name|mask_aop
decl_stmt|;
name|int
name|bits_aopcde
decl_stmt|;
name|int
name|mask_aopcde
decl_stmt|;
name|int
name|bits_HL
decl_stmt|;
name|int
name|mask_HL
decl_stmt|;
name|int
name|bits_dontcare
decl_stmt|;
name|int
name|mask_dontcare
decl_stmt|;
name|int
name|bits_code2
decl_stmt|;
name|int
name|mask_code2
decl_stmt|;
name|int
name|bits_M
decl_stmt|;
name|int
name|mask_M
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DSP32Alu
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSP32Alu_opcode
value|0xc4000000
end_define

begin_define
define|#
directive|define
name|DSP32Alu_src1_bits
value|0
end_define

begin_define
define|#
directive|define
name|DSP32Alu_src1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Alu_src0_bits
value|3
end_define

begin_define
define|#
directive|define
name|DSP32Alu_src0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dst1_bits
value|6
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dst1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dst0_bits
value|9
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dst0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Alu_x_bits
value|12
end_define

begin_define
define|#
directive|define
name|DSP32Alu_x_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Alu_s_bits
value|13
end_define

begin_define
define|#
directive|define
name|DSP32Alu_s_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Alu_aop_bits
value|14
end_define

begin_define
define|#
directive|define
name|DSP32Alu_aop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Alu_aopcde_bits
value|16
end_define

begin_define
define|#
directive|define
name|DSP32Alu_aopcde_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|DSP32Alu_HL_bits
value|21
end_define

begin_define
define|#
directive|define
name|DSP32Alu_HL_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dontcare_bits
value|22
end_define

begin_define
define|#
directive|define
name|DSP32Alu_dontcare_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Alu_code2_bits
value|25
end_define

begin_define
define|#
directive|define
name|DSP32Alu_code2_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Alu_M_bits
value|27
end_define

begin_define
define|#
directive|define
name|DSP32Alu_M_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Alu_code_bits
value|28
end_define

begin_define
define|#
directive|define
name|DSP32Alu_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_DSP32Alu
define|\
value|{							\   DSP32Alu_opcode,					\   DSP32Alu_src1_bits,		DSP32Alu_src1_mask,	\   DSP32Alu_src0_bits,		DSP32Alu_src0_mask,	\   DSP32Alu_dst1_bits,		DSP32Alu_dst1_mask,	\   DSP32Alu_dst0_bits,		DSP32Alu_dst0_mask,	\   DSP32Alu_x_bits,		DSP32Alu_x_mask,	\   DSP32Alu_s_bits,		DSP32Alu_s_mask,	\   DSP32Alu_aop_bits,		DSP32Alu_aop_mask,	\   DSP32Alu_aopcde_bits,		DSP32Alu_aopcde_mask,	\   DSP32Alu_HL_bits,		DSP32Alu_HL_mask,	\   DSP32Alu_dontcare_bits,	DSP32Alu_dontcare_mask,	\   DSP32Alu_code2_bits,		DSP32Alu_code2_mask,	\   DSP32Alu_M_bits,		DSP32Alu_M_mask,	\   DSP32Alu_code_bits,		DSP32Alu_code_mask 	\ };
end_define

begin_comment
comment|/*  dsp32shift +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 0 | 0 |.M.| 1 | 1 | 0 | 0 | - | - |.sopcde............| |.sop...|.HLs...|.dst0......| - | - | - |.src0......|.src1......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_src1
decl_stmt|;
name|int
name|mask_src1
decl_stmt|;
name|int
name|bits_src0
decl_stmt|;
name|int
name|mask_src0
decl_stmt|;
name|int
name|bits_dst1
decl_stmt|;
name|int
name|mask_dst1
decl_stmt|;
name|int
name|bits_dst0
decl_stmt|;
name|int
name|mask_dst0
decl_stmt|;
name|int
name|bits_HLs
decl_stmt|;
name|int
name|mask_HLs
decl_stmt|;
name|int
name|bits_sop
decl_stmt|;
name|int
name|mask_sop
decl_stmt|;
name|int
name|bits_sopcde
decl_stmt|;
name|int
name|mask_sopcde
decl_stmt|;
name|int
name|bits_dontcare
decl_stmt|;
name|int
name|mask_dontcare
decl_stmt|;
name|int
name|bits_code2
decl_stmt|;
name|int
name|mask_code2
decl_stmt|;
name|int
name|bits_M
decl_stmt|;
name|int
name|mask_M
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DSP32Shift
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSP32Shift_opcode
value|0xc6000000
end_define

begin_define
define|#
directive|define
name|DSP32Shift_src1_bits
value|0
end_define

begin_define
define|#
directive|define
name|DSP32Shift_src1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Shift_src0_bits
value|3
end_define

begin_define
define|#
directive|define
name|DSP32Shift_src0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dst1_bits
value|6
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dst1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dst0_bits
value|9
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dst0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32Shift_HLs_bits
value|12
end_define

begin_define
define|#
directive|define
name|DSP32Shift_HLs_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Shift_sop_bits
value|14
end_define

begin_define
define|#
directive|define
name|DSP32Shift_sop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Shift_sopcde_bits
value|16
end_define

begin_define
define|#
directive|define
name|DSP32Shift_sopcde_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dontcare_bits
value|21
end_define

begin_define
define|#
directive|define
name|DSP32Shift_dontcare_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32Shift_code2_bits
value|23
end_define

begin_define
define|#
directive|define
name|DSP32Shift_code2_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|DSP32Shift_M_bits
value|27
end_define

begin_define
define|#
directive|define
name|DSP32Shift_M_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32Shift_code_bits
value|28
end_define

begin_define
define|#
directive|define
name|DSP32Shift_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_DSP32Shift
define|\
value|{								\   DSP32Shift_opcode,						\   DSP32Shift_src1_bits,		DSP32Shift_src1_mask,		\   DSP32Shift_src0_bits,		DSP32Shift_src0_mask,		\   DSP32Shift_dst1_bits,		DSP32Shift_dst1_mask,		\   DSP32Shift_dst0_bits,		DSP32Shift_dst0_mask,		\   DSP32Shift_HLs_bits,		DSP32Shift_HLs_mask,		\   DSP32Shift_sop_bits,		DSP32Shift_sop_mask,		\   DSP32Shift_sopcde_bits,	DSP32Shift_sopcde_mask,		\   DSP32Shift_dontcare_bits,	DSP32Shift_dontcare_mask,	\   DSP32Shift_code2_bits,	DSP32Shift_code2_mask,		\   DSP32Shift_M_bits,		DSP32Shift_M_mask,		\   DSP32Shift_code_bits,		DSP32Shift_code_mask		\ };
end_define

begin_comment
comment|/*  dsp32shiftimm +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 0 | 0 |.M.| 1 | 1 | 0 | 1 | - | - |.sopcde............| |.sop...|.HLs...|.dst0......|.immag.................|.src1......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_src1
decl_stmt|;
name|int
name|mask_src1
decl_stmt|;
name|int
name|bits_immag
decl_stmt|;
name|int
name|mask_immag
decl_stmt|;
name|int
name|bits_dst0
decl_stmt|;
name|int
name|mask_dst0
decl_stmt|;
name|int
name|bits_HLs
decl_stmt|;
name|int
name|mask_HLs
decl_stmt|;
name|int
name|bits_sop
decl_stmt|;
name|int
name|mask_sop
decl_stmt|;
name|int
name|bits_sopcde
decl_stmt|;
name|int
name|mask_sopcde
decl_stmt|;
name|int
name|bits_dontcare
decl_stmt|;
name|int
name|mask_dontcare
decl_stmt|;
name|int
name|bits_code2
decl_stmt|;
name|int
name|mask_code2
decl_stmt|;
name|int
name|bits_M
decl_stmt|;
name|int
name|mask_M
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DSP32ShiftImm
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DSP32ShiftImm_opcode
value|0xc6800000
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_src1_bits
value|0
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_src1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_immag_bits
value|3
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_immag_mask
value|0x3f
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_dst0_bits
value|9
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_dst0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_HLs_bits
value|12
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_HLs_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_sop_bits
value|14
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_sop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_sopcde_bits
value|16
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_sopcde_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_dontcare_bits
value|21
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_dontcare_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_code2_bits
value|23
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_code2_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_M_bits
value|27
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_M_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_code_bits
value|28
end_define

begin_define
define|#
directive|define
name|DSP32ShiftImm_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_DSP32ShiftImm
define|\
value|{								\   DSP32ShiftImm_opcode,						\   DSP32ShiftImm_src1_bits,	DSP32ShiftImm_src1_mask,	\   DSP32ShiftImm_immag_bits,	DSP32ShiftImm_immag_mask,	\   DSP32ShiftImm_dst0_bits,	DSP32ShiftImm_dst0_mask,	\   DSP32ShiftImm_HLs_bits,	DSP32ShiftImm_HLs_mask,		\   DSP32ShiftImm_sop_bits,	DSP32ShiftImm_sop_mask,		\   DSP32ShiftImm_sopcde_bits,	DSP32ShiftImm_sopcde_mask,	\   DSP32ShiftImm_dontcare_bits,	DSP32ShiftImm_dontcare_mask,	\   DSP32ShiftImm_code2_bits,	DSP32ShiftImm_code2_mask,	\   DSP32ShiftImm_M_bits,		DSP32ShiftImm_M_mask,		\   DSP32ShiftImm_code_bits,	DSP32ShiftImm_code_mask		\ };
end_define

begin_comment
comment|/* LOAD / STORE  */
end_comment

begin_comment
comment|/*  LDSTidxI +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 0 | 0 | 1 |.W.|.Z.|.sz....|.ptr.......|.reg.......| |.offset........................................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_offset
decl_stmt|;
name|int
name|mask_offset
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_ptr
decl_stmt|;
name|int
name|mask_ptr
decl_stmt|;
name|int
name|bits_sz
decl_stmt|;
name|int
name|mask_sz
decl_stmt|;
name|int
name|bits_Z
decl_stmt|;
name|int
name|mask_Z
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDSTidxI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDSTidxI_opcode
value|0xe4000000
end_define

begin_define
define|#
directive|define
name|LDSTidxI_offset_bits
value|0
end_define

begin_define
define|#
directive|define
name|LDSTidxI_offset_mask
value|0xffff
end_define

begin_define
define|#
directive|define
name|LDSTidxI_reg_bits
value|16
end_define

begin_define
define|#
directive|define
name|LDSTidxI_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTidxI_ptr_bits
value|19
end_define

begin_define
define|#
directive|define
name|LDSTidxI_ptr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTidxI_sz_bits
value|22
end_define

begin_define
define|#
directive|define
name|LDSTidxI_sz_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDSTidxI_Z_bits
value|24
end_define

begin_define
define|#
directive|define
name|LDSTidxI_Z_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDSTidxI_W_bits
value|25
end_define

begin_define
define|#
directive|define
name|LDSTidxI_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDSTidxI_code_bits
value|26
end_define

begin_define
define|#
directive|define
name|LDSTidxI_code_mask
value|0x3f
end_define

begin_define
define|#
directive|define
name|init_LDSTidxI
define|\
value|{						\   LDSTidxI_opcode,				\   LDSTidxI_offset_bits, LDSTidxI_offset_mask,	\   LDSTidxI_reg_bits, LDSTidxI_reg_mask,		\   LDSTidxI_ptr_bits, LDSTidxI_ptr_mask,		\   LDSTidxI_sz_bits, LDSTidxI_sz_mask,		\   LDSTidxI_Z_bits, LDSTidxI_Z_mask,		\   LDSTidxI_W_bits, LDSTidxI_W_mask,		\   LDSTidxI_code_bits, LDSTidxI_code_mask	\ };
end_define

begin_comment
comment|/*  LDST +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 0 | 1 |.sz....|.W.|.aop...|.Z.|.ptr.......|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_ptr
decl_stmt|;
name|int
name|mask_ptr
decl_stmt|;
name|int
name|bits_Z
decl_stmt|;
name|int
name|mask_Z
decl_stmt|;
name|int
name|bits_aop
decl_stmt|;
name|int
name|mask_aop
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_sz
decl_stmt|;
name|int
name|mask_sz
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDST_opcode
value|0x9000
end_define

begin_define
define|#
directive|define
name|LDST_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|LDST_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDST_ptr_bits
value|3
end_define

begin_define
define|#
directive|define
name|LDST_ptr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDST_Z_bits
value|6
end_define

begin_define
define|#
directive|define
name|LDST_Z_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDST_aop_bits
value|7
end_define

begin_define
define|#
directive|define
name|LDST_aop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDST_W_bits
value|9
end_define

begin_define
define|#
directive|define
name|LDST_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDST_sz_bits
value|10
end_define

begin_define
define|#
directive|define
name|LDST_sz_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDST_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|LDST_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_LDST
define|\
value|{					\   LDST_opcode,				\   LDST_reg_bits,	LDST_reg_mask,	\   LDST_ptr_bits,	LDST_ptr_mask,	\   LDST_Z_bits,		LDST_Z_mask,	\   LDST_aop_bits,	LDST_aop_mask,	\   LDST_W_bits,		LDST_W_mask,	\   LDST_sz_bits,		LDST_sz_mask,	\   LDST_code_bits,	LDST_code_mask	\ };
end_define

begin_comment
comment|/*  LDSTii +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 1 |.W.|.op....|.offset........|.ptr.......|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_ptr
decl_stmt|;
name|int
name|mask_ptr
decl_stmt|;
name|int
name|bits_offset
decl_stmt|;
name|int
name|mask_offset
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDSTii
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDSTii_opcode
value|0xa000
end_define

begin_define
define|#
directive|define
name|LDSTii_reg_bit
value|0
end_define

begin_define
define|#
directive|define
name|LDSTii_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTii_ptr_bit
value|3
end_define

begin_define
define|#
directive|define
name|LDSTii_ptr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTii_offset_bit
value|6
end_define

begin_define
define|#
directive|define
name|LDSTii_offset_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|LDSTii_op_bit
value|10
end_define

begin_define
define|#
directive|define
name|LDSTii_op_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDSTii_W_bit
value|12
end_define

begin_define
define|#
directive|define
name|LDSTii_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDSTii_code_bit
value|13
end_define

begin_define
define|#
directive|define
name|LDSTii_code_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|init_LDSTii
define|\
value|{						\   LDSTii_opcode,				\   LDSTii_reg_bit,	LDSTii_reg_mask,	\   LDSTii_ptr_bit,	LDSTii_ptr_mask,	\   LDSTii_offset_bit,    LDSTii_offset_mask, 	\   LDSTii_op_bit,        LDSTii_op_mask,		\   LDSTii_W_bit,		LDSTii_W_mask,		\   LDSTii_code_bit,	LDSTii_code_mask	\ };
end_define

begin_comment
comment|/*  LDSTiiFP +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 1 | 1 | 1 | 0 |.W.|.offset............|.reg...........| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_offset
decl_stmt|;
name|int
name|mask_offset
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDSTiiFP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDSTiiFP_opcode
value|0xb800
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_reg_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_offset_bits
value|4
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_offset_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_W_bits
value|9
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_code_bits
value|10
end_define

begin_define
define|#
directive|define
name|LDSTiiFP_code_mask
value|0x3f
end_define

begin_define
define|#
directive|define
name|init_LDSTiiFP
define|\
value|{						\   LDSTiiFP_opcode,				\   LDSTiiFP_reg_bits,	LDSTiiFP_reg_mask,	\   LDSTiiFP_offset_bits, LDSTiiFP_offset_mask,	\   LDSTiiFP_W_bits,	LDSTiiFP_W_mask,	\   LDSTiiFP_code_bits,	LDSTiiFP_code_mask	\ };
end_define

begin_comment
comment|/*  dspLDST +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 0 | 1 | 1 | 1 |.W.|.aop...|.m.....|.i.....|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_i
decl_stmt|;
name|int
name|mask_i
decl_stmt|;
name|int
name|bits_m
decl_stmt|;
name|int
name|mask_m
decl_stmt|;
name|int
name|bits_aop
decl_stmt|;
name|int
name|mask_aop
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DspLDST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DspLDST_opcode
value|0x9c00
end_define

begin_define
define|#
directive|define
name|DspLDST_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|DspLDST_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|DspLDST_i_bits
value|3
end_define

begin_define
define|#
directive|define
name|DspLDST_i_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DspLDST_m_bits
value|5
end_define

begin_define
define|#
directive|define
name|DspLDST_m_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DspLDST_aop_bits
value|7
end_define

begin_define
define|#
directive|define
name|DspLDST_aop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DspLDST_W_bits
value|9
end_define

begin_define
define|#
directive|define
name|DspLDST_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DspLDST_code_bits
value|10
end_define

begin_define
define|#
directive|define
name|DspLDST_code_mask
value|0x3f
end_define

begin_define
define|#
directive|define
name|init_DspLDST
define|\
value|{						\   DspLDST_opcode,				\   DspLDST_reg_bits,	DspLDST_reg_mask,	\   DspLDST_i_bits,	DspLDST_i_mask,		\   DspLDST_m_bits,	DspLDST_m_mask,		\   DspLDST_aop_bits,	DspLDST_aop_mask,	\   DspLDST_W_bits,	DspLDST_W_mask,		\   DspLDST_code_bits,	DspLDST_code_mask	\ };
end_define

begin_comment
comment|/*  LDSTpmod +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 0 | 0 |.W.|.aop...|.reg.......|.idx.......|.ptr.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_ptr
decl_stmt|;
name|int
name|mask_ptr
decl_stmt|;
name|int
name|bits_idx
decl_stmt|;
name|int
name|mask_idx
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_aop
decl_stmt|;
name|int
name|mask_aop
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDSTpmod
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDSTpmod_opcode
value|0x8000
end_define

begin_define
define|#
directive|define
name|LDSTpmod_ptr_bits
value|0
end_define

begin_define
define|#
directive|define
name|LDSTpmod_ptr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTpmod_idx_bits
value|3
end_define

begin_define
define|#
directive|define
name|LDSTpmod_idx_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTpmod_reg_bits
value|6
end_define

begin_define
define|#
directive|define
name|LDSTpmod_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDSTpmod_aop_bits
value|9
end_define

begin_define
define|#
directive|define
name|LDSTpmod_aop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDSTpmod_W_bits
value|11
end_define

begin_define
define|#
directive|define
name|LDSTpmod_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDSTpmod_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|LDSTpmod_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_LDSTpmod
define|\
value|{						\   LDSTpmod_opcode,				\   LDSTpmod_ptr_bits, 	LDSTpmod_ptr_mask,	\   LDSTpmod_idx_bits,	LDSTpmod_idx_mask,	\   LDSTpmod_reg_bits,	LDSTpmod_reg_mask,	\   LDSTpmod_aop_bits,	LDSTpmod_aop_mask,	\   LDSTpmod_W_bits,	LDSTpmod_W_mask,	\   LDSTpmod_code_bits,	LDSTpmod_code_mask	\ };
end_define

begin_comment
comment|/*  LOGI2op +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 0 | 0 | 1 |.opc.......|.src...............|.dst.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_opc
decl_stmt|;
name|int
name|mask_opc
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LOGI2op
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOGI2op_opcode
value|0x4800
end_define

begin_define
define|#
directive|define
name|LOGI2op_dst_bits
value|0
end_define

begin_define
define|#
directive|define
name|LOGI2op_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LOGI2op_src_bits
value|3
end_define

begin_define
define|#
directive|define
name|LOGI2op_src_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|LOGI2op_opc_bits
value|8
end_define

begin_define
define|#
directive|define
name|LOGI2op_opc_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LOGI2op_code_bits
value|11
end_define

begin_define
define|#
directive|define
name|LOGI2op_code_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|init_LOGI2op
define|\
value|{						\   LOGI2op_opcode,				\   LOGI2op_dst_bits, 	LOGI2op_dst_mask,	\   LOGI2op_src_bits,	LOGI2op_src_mask,	\   LOGI2op_opc_bits,	LOGI2op_opc_mask,	\   LOGI2op_code_bits,	LOGI2op_code_mask	\ };
end_define

begin_comment
comment|/*  ALU2op +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 0 | 0 | 0 | 0 |.opc...........|.src.......|.dst.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_opc
decl_stmt|;
name|int
name|mask_opc
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|ALU2op
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ALU2op_opcode
value|0x4000
end_define

begin_define
define|#
directive|define
name|ALU2op_dst_bits
value|0
end_define

begin_define
define|#
directive|define
name|ALU2op_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|ALU2op_src_bits
value|3
end_define

begin_define
define|#
directive|define
name|ALU2op_src_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|ALU2op_opc_bits
value|6
end_define

begin_define
define|#
directive|define
name|ALU2op_opc_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|ALU2op_code_bits
value|10
end_define

begin_define
define|#
directive|define
name|ALU2op_code_mask
value|0x3f
end_define

begin_define
define|#
directive|define
name|init_ALU2op
define|\
value|{						\   ALU2op_opcode,				\   ALU2op_dst_bits,	ALU2op_dst_mask,	\   ALU2op_src_bits,	ALU2op_src_mask,	\   ALU2op_opc_bits,	ALU2op_opc_mask,	\   ALU2op_code_bits,	ALU2op_code_mask	\ };
end_define

begin_comment
comment|/*  BRCC +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 1 |.T.|.B.|.offset................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_offset
decl_stmt|;
name|int
name|mask_offset
decl_stmt|;
name|int
name|bits_B
decl_stmt|;
name|int
name|mask_B
decl_stmt|;
name|int
name|bits_T
decl_stmt|;
name|int
name|mask_T
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|BRCC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BRCC_opcode
value|0x1000
end_define

begin_define
define|#
directive|define
name|BRCC_offset_bits
value|0
end_define

begin_define
define|#
directive|define
name|BRCC_offset_mask
value|0x3ff
end_define

begin_define
define|#
directive|define
name|BRCC_B_bits
value|10
end_define

begin_define
define|#
directive|define
name|BRCC_B_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|BRCC_T_bits
value|11
end_define

begin_define
define|#
directive|define
name|BRCC_T_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|BRCC_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|BRCC_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_BRCC
define|\
value|{						\   BRCC_opcode,					\   BRCC_offset_bits,	BRCC_offset_mask,	\   BRCC_B_bits,		BRCC_B_mask,		\   BRCC_T_bits,		BRCC_T_mask,		\   BRCC_code_bits,	BRCC_code_mask		\ };
end_define

begin_comment
comment|/*  UJUMP +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 1 | 0 |.offset........................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_offset
decl_stmt|;
name|int
name|mask_offset
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|UJump
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UJump_opcode
value|0x2000
end_define

begin_define
define|#
directive|define
name|UJump_offset_bits
value|0
end_define

begin_define
define|#
directive|define
name|UJump_offset_mask
value|0xfff
end_define

begin_define
define|#
directive|define
name|UJump_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|UJump_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_UJump
define|\
value|{						\   UJump_opcode,					\   UJump_offset_bits,	UJump_offset_mask,	\   UJump_code_bits,	UJump_code_mask		\ };
end_define

begin_comment
comment|/*  ProgCtrl +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |.prgfunc.......|.poprnd........| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_poprnd
decl_stmt|;
name|int
name|mask_poprnd
decl_stmt|;
name|int
name|bits_prgfunc
decl_stmt|;
name|int
name|mask_prgfunc
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|ProgCtrl
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ProgCtrl_opcode
value|0x0000
end_define

begin_define
define|#
directive|define
name|ProgCtrl_poprnd_bits
value|0
end_define

begin_define
define|#
directive|define
name|ProgCtrl_poprnd_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|ProgCtrl_prgfunc_bits
value|4
end_define

begin_define
define|#
directive|define
name|ProgCtrl_prgfunc_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|ProgCtrl_code_bits
value|8
end_define

begin_define
define|#
directive|define
name|ProgCtrl_code_mask
value|0xff
end_define

begin_define
define|#
directive|define
name|init_ProgCtrl
define|\
value|{							\   ProgCtrl_opcode,					\   ProgCtrl_poprnd_bits,		ProgCtrl_poprnd_mask,	\   ProgCtrl_prgfunc_bits,	ProgCtrl_prgfunc_mask,	\   ProgCtrl_code_bits,		ProgCtrl_code_mask	\ };
end_define

begin_comment
comment|/*  CALLa +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 0 | 0 | 0 | 1 |.S.|.msw...........................| |.lsw...........................................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_addr
decl_stmt|;
name|int
name|mask_addr
decl_stmt|;
name|int
name|bits_S
decl_stmt|;
name|int
name|mask_S
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CALLa
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CALLa_opcode
value|0xe2000000
end_define

begin_define
define|#
directive|define
name|CALLa_addr_bits
value|0
end_define

begin_define
define|#
directive|define
name|CALLa_addr_mask
value|0xffffff
end_define

begin_define
define|#
directive|define
name|CALLa_S_bits
value|24
end_define

begin_define
define|#
directive|define
name|CALLa_S_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CALLa_code_bits
value|25
end_define

begin_define
define|#
directive|define
name|CALLa_code_mask
value|0x7f
end_define

begin_define
define|#
directive|define
name|init_CALLa
define|\
value|{						\   CALLa_opcode,					\   CALLa_addr_bits,	CALLa_addr_mask,	\   CALLa_S_bits,		CALLa_S_mask,		\   CALLa_code_bits,	CALLa_code_mask		\ };
end_define

begin_comment
comment|/*  pseudoDEBUG +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |.fn....|.grp.......|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_grp
decl_stmt|;
name|int
name|mask_grp
decl_stmt|;
name|int
name|bits_fn
decl_stmt|;
name|int
name|mask_fn
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|PseudoDbg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PseudoDbg_opcode
value|0xf800
end_define

begin_define
define|#
directive|define
name|PseudoDbg_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|PseudoDbg_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PseudoDbg_grp_bits
value|3
end_define

begin_define
define|#
directive|define
name|PseudoDbg_grp_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PseudoDbg_fn_bits
value|6
end_define

begin_define
define|#
directive|define
name|PseudoDbg_fn_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|PseudoDbg_code_bits
value|8
end_define

begin_define
define|#
directive|define
name|PseudoDbg_code_mask
value|0xff
end_define

begin_define
define|#
directive|define
name|init_PseudoDbg
define|\
value|{						\   PseudoDbg_opcode,				\   PseudoDbg_reg_bits,	PseudoDbg_reg_mask,	\   PseudoDbg_grp_bits,	PseudoDbg_grp_mask,	\   PseudoDbg_fn_bits,	PseudoDbg_fn_mask,	\   PseudoDbg_code_bits,	PseudoDbg_code_mask	\ };
end_define

begin_comment
comment|/*  PseudoDbg_assert +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 1 | 0 | - | - | - | - | - |.dbgop.....|.regtest...| |.expected......................................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_expected
decl_stmt|;
name|int
name|mask_expected
decl_stmt|;
name|int
name|bits_regtest
decl_stmt|;
name|int
name|mask_regtest
decl_stmt|;
name|int
name|bits_dbgop
decl_stmt|;
name|int
name|mask_dbgop
decl_stmt|;
name|int
name|bits_dontcare
decl_stmt|;
name|int
name|mask_dontcare
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|PseudoDbg_Assert
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PseudoDbg_Assert_opcode
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_expected_bits
value|0
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_expected_mask
value|0xffff
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_regtest_bits
value|16
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_regtest_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_dbgop_bits
value|19
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_dbgop_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_dontcare_bits
value|22
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_dontcare_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_code_bits
value|27
end_define

begin_define
define|#
directive|define
name|PseudoDbg_Assert_code_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|init_PseudoDbg_Assert
define|\
value|{									\   PseudoDbg_Assert_opcode,						\   PseudoDbg_Assert_expected_bits, 	PseudoDbg_Assert_expected_mask,	\   PseudoDbg_Assert_regtest_bits, 	PseudoDbg_Assert_regtest_mask,	\   PseudoDbg_Assert_dbgop_bits, 		PseudoDbg_Assert_dbgop_mask,	\   PseudoDbg_Assert_dontcare_bits, 	PseudoDbg_Assert_dontcare_mask,	\   PseudoDbg_Assert_code_bits,	 	PseudoDbg_Assert_code_mask	\ };
end_define

begin_comment
comment|/*  CaCTRL +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 |.a.|.op....|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_a
decl_stmt|;
name|int
name|mask_a
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CaCTRL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CaCTRL_opcode
value|0x0240
end_define

begin_define
define|#
directive|define
name|CaCTRL_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|CaCTRL_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CaCTRL_op_bits
value|3
end_define

begin_define
define|#
directive|define
name|CaCTRL_op_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|CaCTRL_a_bits
value|5
end_define

begin_define
define|#
directive|define
name|CaCTRL_a_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CaCTRL_code_bits
value|6
end_define

begin_define
define|#
directive|define
name|CaCTRL_code_mask
value|0x3fff
end_define

begin_define
define|#
directive|define
name|init_CaCTRL
define|\
value|{						\   CaCTRL_opcode,				\   CaCTRL_reg_bits,	CaCTRL_reg_mask,	\   CaCTRL_op_bits,	CaCTRL_op_mask,		\   CaCTRL_a_bits,	CaCTRL_a_mask,		\   CaCTRL_code_bits,	CaCTRL_code_mask	\ };
end_define

begin_comment
comment|/*  PushPopMultiple +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 1 | 0 |.d.|.p.|.W.|.dr........|.pr........| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_pr
decl_stmt|;
name|int
name|mask_pr
decl_stmt|;
name|int
name|bits_dr
decl_stmt|;
name|int
name|mask_dr
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_p
decl_stmt|;
name|int
name|mask_p
decl_stmt|;
name|int
name|bits_d
decl_stmt|;
name|int
name|mask_d
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|PushPopMultiple
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PushPopMultiple_opcode
value|0x0400
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_pr_bits
value|0
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_pr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_dr_bits
value|3
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_dr_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_W_bits
value|6
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_p_bits
value|7
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_p_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_d_bits
value|8
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_d_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_code_bits
value|8
end_define

begin_define
define|#
directive|define
name|PushPopMultiple_code_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|init_PushPopMultiple
define|\
value|{								\   PushPopMultiple_opcode,					\   PushPopMultiple_pr_bits,	PushPopMultiple_pr_mask,	\   PushPopMultiple_dr_bits,	PushPopMultiple_dr_mask,	\   PushPopMultiple_W_bits,	PushPopMultiple_W_mask,		\   PushPopMultiple_p_bits,	PushPopMultiple_p_mask,		\   PushPopMultiple_d_bits,	PushPopMultiple_d_mask,		\   PushPopMultiple_code_bits,	PushPopMultiple_code_mask	\ };
end_define

begin_comment
comment|/*  PushPopReg +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |.W.|.grp.......|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_grp
decl_stmt|;
name|int
name|mask_grp
decl_stmt|;
name|int
name|bits_W
decl_stmt|;
name|int
name|mask_W
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|PushPopReg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PushPopReg_opcode
value|0x0100
end_define

begin_define
define|#
directive|define
name|PushPopReg_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|PushPopReg_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PushPopReg_grp_bits
value|3
end_define

begin_define
define|#
directive|define
name|PushPopReg_grp_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PushPopReg_W_bits
value|6
end_define

begin_define
define|#
directive|define
name|PushPopReg_W_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|PushPopReg_code_bits
value|7
end_define

begin_define
define|#
directive|define
name|PushPopReg_code_mask
value|0x1ff
end_define

begin_define
define|#
directive|define
name|init_PushPopReg
define|\
value|{						\   PushPopReg_opcode,				\   PushPopReg_reg_bits,	PushPopReg_reg_mask,	\   PushPopReg_grp_bits,	PushPopReg_grp_mask,	\   PushPopReg_W_bits,	PushPopReg_W_mask,	\   PushPopReg_code_bits,	PushPopReg_code_mask,	\ };
end_define

begin_comment
comment|/*  linkage +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |.R.| |.framesize.....................................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_framesize
decl_stmt|;
name|int
name|mask_framesize
decl_stmt|;
name|int
name|bits_R
decl_stmt|;
name|int
name|mask_R
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|Linkage
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Linkage_opcode
value|0xe8000000
end_define

begin_define
define|#
directive|define
name|Linkage_framesize_bits
value|0
end_define

begin_define
define|#
directive|define
name|Linkage_framesize_mask
value|0xffff
end_define

begin_define
define|#
directive|define
name|Linkage_R_bits
value|16
end_define

begin_define
define|#
directive|define
name|Linkage_R_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|Linkage_code_bits
value|17
end_define

begin_define
define|#
directive|define
name|Linkage_code_mask
value|0x7fff
end_define

begin_define
define|#
directive|define
name|init_Linkage
define|\
value|{							\   Linkage_opcode,					\   Linkage_framesize_bits,	Linkage_framesize_mask,	\   Linkage_R_bits,		Linkage_R_mask,		\   Linkage_code_bits,		Linkage_code_mask	\ };
end_define

begin_comment
comment|/*  LoopSetup +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |.rop...|.c.|.soffset.......| |.reg...........| - | - |.eoffset...............................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_eoffset
decl_stmt|;
name|int
name|mask_eoffset
decl_stmt|;
name|int
name|bits_dontcare
decl_stmt|;
name|int
name|mask_dontcare
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_soffset
decl_stmt|;
name|int
name|mask_soffset
decl_stmt|;
name|int
name|bits_c
decl_stmt|;
name|int
name|mask_c
decl_stmt|;
name|int
name|bits_rop
decl_stmt|;
name|int
name|mask_rop
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LoopSetup
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LoopSetup_opcode
value|0xe0800000
end_define

begin_define
define|#
directive|define
name|LoopSetup_eoffset_bits
value|0
end_define

begin_define
define|#
directive|define
name|LoopSetup_eoffset_mask
value|0x3ff
end_define

begin_define
define|#
directive|define
name|LoopSetup_dontcare_bits
value|10
end_define

begin_define
define|#
directive|define
name|LoopSetup_dontcare_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LoopSetup_reg_bits
value|12
end_define

begin_define
define|#
directive|define
name|LoopSetup_reg_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|LoopSetup_soffset_bits
value|16
end_define

begin_define
define|#
directive|define
name|LoopSetup_soffset_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|LoopSetup_c_bits
value|20
end_define

begin_define
define|#
directive|define
name|LoopSetup_c_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LoopSetup_rop_bits
value|21
end_define

begin_define
define|#
directive|define
name|LoopSetup_rop_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LoopSetup_code_bits
value|23
end_define

begin_define
define|#
directive|define
name|LoopSetup_code_mask
value|0x1ff
end_define

begin_define
define|#
directive|define
name|init_LoopSetup
define|\
value|{								\   LoopSetup_opcode,						\   LoopSetup_eoffset_bits,	LoopSetup_eoffset_mask,		\   LoopSetup_dontcare_bits,	LoopSetup_dontcare_mask,	\   LoopSetup_reg_bits,		LoopSetup_reg_mask,		\   LoopSetup_soffset_bits,	LoopSetup_soffset_mask,		\   LoopSetup_c_bits,		LoopSetup_c_mask,		\   LoopSetup_rop_bits,		LoopSetup_rop_mask,		\   LoopSetup_code_bits,		LoopSetup_code_mask		\ };
end_define

begin_comment
comment|/*  LDIMMhalf +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 1 |.Z.|.H.|.S.|.grp...|.reg.......| |.hword.........................................................| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|opcode
decl_stmt|;
name|int
name|bits_hword
decl_stmt|;
name|int
name|mask_hword
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_grp
decl_stmt|;
name|int
name|mask_grp
decl_stmt|;
name|int
name|bits_S
decl_stmt|;
name|int
name|mask_S
decl_stmt|;
name|int
name|bits_H
decl_stmt|;
name|int
name|mask_H
decl_stmt|;
name|int
name|bits_Z
decl_stmt|;
name|int
name|mask_Z
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|LDIMMhalf
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LDIMMhalf_opcode
value|0xe1000000
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_hword_bits
value|0
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_hword_mask
value|0xffff
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_reg_bits
value|16
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_grp_bits
value|19
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_grp_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_S_bits
value|21
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_S_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_H_bits
value|22
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_H_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_Z_bits
value|23
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_Z_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_code_bits
value|24
end_define

begin_define
define|#
directive|define
name|LDIMMhalf_code_mask
value|0xff
end_define

begin_define
define|#
directive|define
name|init_LDIMMhalf
define|\
value|{						\   LDIMMhalf_opcode,				\   LDIMMhalf_hword_bits,	LDIMMhalf_hword_mask,	\   LDIMMhalf_reg_bits,	LDIMMhalf_reg_mask,	\   LDIMMhalf_grp_bits,	LDIMMhalf_grp_mask,	\   LDIMMhalf_S_bits,	LDIMMhalf_S_mask,	\   LDIMMhalf_H_bits,	LDIMMhalf_H_mask,	\   LDIMMhalf_Z_bits,	LDIMMhalf_Z_mask,	\   LDIMMhalf_code_bits,	LDIMMhalf_code_mask	\ };
end_define

begin_comment
comment|/*  CC2dreg +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |.op....|.reg.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_reg
decl_stmt|;
name|int
name|mask_reg
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CC2dreg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CC2dreg_opcode
value|0x0200
end_define

begin_define
define|#
directive|define
name|CC2dreg_reg_bits
value|0
end_define

begin_define
define|#
directive|define
name|CC2dreg_reg_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CC2dreg_op_bits
value|3
end_define

begin_define
define|#
directive|define
name|CC2dreg_op_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|CC2dreg_code_bits
value|5
end_define

begin_define
define|#
directive|define
name|CC2dreg_code_mask
value|0x7fff
end_define

begin_define
define|#
directive|define
name|init_CC2dreg
define|\
value|{						\   CC2dreg_opcode,				\   CC2dreg_reg_bits,	CC2dreg_reg_mask,	\   CC2dreg_op_bits,	CC2dreg_op_mask,	\   CC2dreg_code_bits,	CC2dreg_code_mask	\ };
end_define

begin_comment
comment|/*  PTR2op +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 0 | 0 | 0 | 1 | 0 |.opc.......|.src.......|.dst.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_opc
decl_stmt|;
name|int
name|mask_opc
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|PTR2op
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PTR2op_opcode
value|0x4400
end_define

begin_define
define|#
directive|define
name|PTR2op_dst_bits
value|0
end_define

begin_define
define|#
directive|define
name|PTR2op_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PTR2op_src_bits
value|3
end_define

begin_define
define|#
directive|define
name|PTR2op_src_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PTR2op_opc_bits
value|6
end_define

begin_define
define|#
directive|define
name|PTR2op_opc_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|PTR2op_code_bits
value|9
end_define

begin_define
define|#
directive|define
name|PTR2op_code_mask
value|0x7f
end_define

begin_define
define|#
directive|define
name|init_PTR2op
define|\
value|{						\   PTR2op_opcode,				\   PTR2op_dst_bits,	PTR2op_dst_mask,	\   PTR2op_src_bits,	PTR2op_src_mask,	\   PTR2op_opc_bits,	PTR2op_opc_mask,	\   PTR2op_code_bits,	PTR2op_code_mask	\ };
end_define

begin_comment
comment|/*  COMP3op +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 0 | 1 |.opc.......|.dst.......|.src1......|.src0......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_src0
decl_stmt|;
name|int
name|mask_src0
decl_stmt|;
name|int
name|bits_src1
decl_stmt|;
name|int
name|mask_src1
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_opc
decl_stmt|;
name|int
name|mask_opc
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|COMP3op
typedef|;
end_typedef

begin_define
define|#
directive|define
name|COMP3op_opcode
value|0x5000
end_define

begin_define
define|#
directive|define
name|COMP3op_src0_bits
value|0
end_define

begin_define
define|#
directive|define
name|COMP3op_src0_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMP3op_src1_bits
value|3
end_define

begin_define
define|#
directive|define
name|COMP3op_src1_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMP3op_dst_bits
value|6
end_define

begin_define
define|#
directive|define
name|COMP3op_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMP3op_opc_bits
value|9
end_define

begin_define
define|#
directive|define
name|COMP3op_opc_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMP3op_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|COMP3op_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_COMP3op
define|\
value|{						\   COMP3op_opcode,				\   COMP3op_src0_bits,	COMP3op_src0_mask,	\   COMP3op_src1_bits,	COMP3op_src1_mask,	\   COMP3op_dst_bits,	COMP3op_dst_mask,	\   COMP3op_opc_bits,	COMP3op_opc_mask,	\   COMP3op_code_bits,	COMP3op_code_mask	\ };
end_define

begin_comment
comment|/*  ccMV +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 1 | 1 |.T.|.d.|.s.|.dst.......|.src.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_s
decl_stmt|;
name|int
name|mask_s
decl_stmt|;
name|int
name|bits_d
decl_stmt|;
name|int
name|mask_d
decl_stmt|;
name|int
name|bits_T
decl_stmt|;
name|int
name|mask_T
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CCmv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CCmv_opcode
value|0x0600
end_define

begin_define
define|#
directive|define
name|CCmv_src_bits
value|0
end_define

begin_define
define|#
directive|define
name|CCmv_src_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CCmv_dst_bits
value|3
end_define

begin_define
define|#
directive|define
name|CCmv_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CCmv_s_bits
value|6
end_define

begin_define
define|#
directive|define
name|CCmv_s_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CCmv_d_bits
value|7
end_define

begin_define
define|#
directive|define
name|CCmv_d_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CCmv_T_bits
value|8
end_define

begin_define
define|#
directive|define
name|CCmv_T_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CCmv_code_bits
value|9
end_define

begin_define
define|#
directive|define
name|CCmv_code_mask
value|0x7f
end_define

begin_define
define|#
directive|define
name|init_CCmv
define|\
value|{					\   CCmv_opcode,				\   CCmv_src_bits,	CCmv_src_mask,	\   CCmv_dst_bits,	CCmv_dst_mask,	\   CCmv_s_bits,		CCmv_s_mask,	\   CCmv_d_bits,		CCmv_d_mask,	\   CCmv_T_bits,		CCmv_T_mask,	\   CCmv_code_bits,	CCmv_code_mask	\ };
end_define

begin_comment
comment|/*  CCflag +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 1 |.I.|.opc.......|.G.|.y.........|.x.........| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_x
decl_stmt|;
name|int
name|mask_x
decl_stmt|;
name|int
name|bits_y
decl_stmt|;
name|int
name|mask_y
decl_stmt|;
name|int
name|bits_G
decl_stmt|;
name|int
name|mask_G
decl_stmt|;
name|int
name|bits_opc
decl_stmt|;
name|int
name|mask_opc
decl_stmt|;
name|int
name|bits_I
decl_stmt|;
name|int
name|mask_I
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CCflag
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CCflag_opcode
value|0x0800
end_define

begin_define
define|#
directive|define
name|CCflag_x_bits
value|0
end_define

begin_define
define|#
directive|define
name|CCflag_x_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CCflag_y_bits
value|3
end_define

begin_define
define|#
directive|define
name|CCflag_y_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CCflag_G_bits
value|6
end_define

begin_define
define|#
directive|define
name|CCflag_G_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CCflag_opc_bits
value|7
end_define

begin_define
define|#
directive|define
name|CCflag_opc_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|CCflag_I_bits
value|10
end_define

begin_define
define|#
directive|define
name|CCflag_I_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CCflag_code_bits
value|11
end_define

begin_define
define|#
directive|define
name|CCflag_code_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|init_CCflag
define|\
value|{						\   CCflag_opcode,				\   CCflag_x_bits,	CCflag_x_mask,		\   CCflag_y_bits,	CCflag_y_mask,		\   CCflag_G_bits,	CCflag_G_mask,		\   CCflag_opc_bits,	CCflag_opc_mask,	\   CCflag_I_bits,	CCflag_I_mask,		\   CCflag_code_bits,	CCflag_code_mask,	\ };
end_define

begin_comment
comment|/*  CC2stat +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |.D.|.op....|.cbit..............| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_cbit
decl_stmt|;
name|int
name|mask_cbit
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_D
decl_stmt|;
name|int
name|mask_D
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|CC2stat
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CC2stat_opcode
value|0x0300
end_define

begin_define
define|#
directive|define
name|CC2stat_cbit_bits
value|0
end_define

begin_define
define|#
directive|define
name|CC2stat_cbit_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|CC2stat_op_bits
value|5
end_define

begin_define
define|#
directive|define
name|CC2stat_op_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|CC2stat_D_bits
value|7
end_define

begin_define
define|#
directive|define
name|CC2stat_D_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|CC2stat_code_bits
value|8
end_define

begin_define
define|#
directive|define
name|CC2stat_code_mask
value|0xff
end_define

begin_define
define|#
directive|define
name|init_CC2stat
define|\
value|{						\   CC2stat_opcode,				\   CC2stat_cbit_bits,	CC2stat_cbit_mask,	\   CC2stat_op_bits,	CC2stat_op_mask,	\   CC2stat_D_bits,	CC2stat_D_mask,		\   CC2stat_code_bits,	CC2stat_code_mask	\ };
end_define

begin_comment
comment|/*  REGMV +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 0 | 1 | 1 |.gd........|.gs........|.dst.......|.src.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_gs
decl_stmt|;
name|int
name|mask_gs
decl_stmt|;
name|int
name|bits_gd
decl_stmt|;
name|int
name|mask_gd
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|RegMv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RegMv_opcode
value|0x3000
end_define

begin_define
define|#
directive|define
name|RegMv_src_bits
value|0
end_define

begin_define
define|#
directive|define
name|RegMv_src_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|RegMv_dst_bits
value|3
end_define

begin_define
define|#
directive|define
name|RegMv_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|RegMv_gs_bits
value|6
end_define

begin_define
define|#
directive|define
name|RegMv_gs_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|RegMv_gd_bits
value|9
end_define

begin_define
define|#
directive|define
name|RegMv_gd_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|RegMv_code_bits
value|12
end_define

begin_define
define|#
directive|define
name|RegMv_code_mask
value|0xf
end_define

begin_define
define|#
directive|define
name|init_RegMv
define|\
value|{					\   RegMv_opcode,				\   RegMv_src_bits,	RegMv_src_mask,	\   RegMv_dst_bits,	RegMv_dst_mask,	\   RegMv_gs_bits,	RegMv_gs_mask,	\   RegMv_gd_bits,	RegMv_gd_mask,	\   RegMv_code_bits,	RegMv_code_mask	\ };
end_define

begin_comment
comment|/*  COMPI2opD +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 1 | 0 | 0 |.op|.isrc......................|.dst.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_dst
decl_stmt|;
name|int
name|mask_dst
decl_stmt|;
name|int
name|bits_src
decl_stmt|;
name|int
name|mask_src
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|COMPI2opD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|COMPI2opD_opcode
value|0x6000
end_define

begin_define
define|#
directive|define
name|COMPI2opD_dst_bits
value|0
end_define

begin_define
define|#
directive|define
name|COMPI2opD_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMPI2opD_src_bits
value|3
end_define

begin_define
define|#
directive|define
name|COMPI2opD_src_mask
value|0x7f
end_define

begin_define
define|#
directive|define
name|COMPI2opD_op_bits
value|10
end_define

begin_define
define|#
directive|define
name|COMPI2opD_op_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|COMPI2opD_code_bits
value|11
end_define

begin_define
define|#
directive|define
name|COMPI2opD_code_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|init_COMPI2opD
define|\
value|{						\   COMPI2opD_opcode,				\   COMPI2opD_dst_bits,	COMPI2opD_dst_mask,	\   COMPI2opD_src_bits,	COMPI2opD_src_mask,	\   COMPI2opD_op_bits,	COMPI2opD_op_mask,	\   COMPI2opD_code_bits,	COMPI2opD_code_mask	\ };
end_define

begin_comment
comment|/*  COMPI2opP +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 0 | 1 | 1 | 0 | 1 |.op|.src.......................|.dst.......| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
name|COMPI2opD
name|COMPI2opP
typedef|;
end_typedef

begin_define
define|#
directive|define
name|COMPI2opP_opcode
value|0x6800
end_define

begin_define
define|#
directive|define
name|COMPI2opP_dst_bits
value|0
end_define

begin_define
define|#
directive|define
name|COMPI2opP_dst_mask
value|0x7
end_define

begin_define
define|#
directive|define
name|COMPI2opP_src_bits
value|3
end_define

begin_define
define|#
directive|define
name|COMPI2opP_src_mask
value|0x7f
end_define

begin_define
define|#
directive|define
name|COMPI2opP_op_bits
value|10
end_define

begin_define
define|#
directive|define
name|COMPI2opP_op_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|COMPI2opP_code_bits
value|11
end_define

begin_define
define|#
directive|define
name|COMPI2opP_code_mask
value|0x1f
end_define

begin_define
define|#
directive|define
name|init_COMPI2opP
define|\
value|{						\   COMPI2opP_opcode,				\   COMPI2opP_dst_bits,	COMPI2opP_dst_mask,	\   COMPI2opP_src_bits,	COMPI2opP_src_mask,	\   COMPI2opP_op_bits,	COMPI2opP_op_mask,	\   COMPI2opP_code_bits,	COMPI2opP_code_mask	\ };
end_define

begin_comment
comment|/*  dagMODim +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 0 |.br| 1 | 1 |.op|.m.....|.i.....| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_i
decl_stmt|;
name|int
name|mask_i
decl_stmt|;
name|int
name|bits_m
decl_stmt|;
name|int
name|mask_m
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_code2
decl_stmt|;
name|int
name|mask_code2
decl_stmt|;
name|int
name|bits_br
decl_stmt|;
name|int
name|mask_br
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DagMODim
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DagMODim_opcode
value|0x9e60
end_define

begin_define
define|#
directive|define
name|DagMODim_i_bits
value|0
end_define

begin_define
define|#
directive|define
name|DagMODim_i_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DagMODim_m_bits
value|2
end_define

begin_define
define|#
directive|define
name|DagMODim_m_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DagMODim_op_bits
value|4
end_define

begin_define
define|#
directive|define
name|DagMODim_op_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DagMODim_code2_bits
value|5
end_define

begin_define
define|#
directive|define
name|DagMODim_code2_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DagMODim_br_bits
value|7
end_define

begin_define
define|#
directive|define
name|DagMODim_br_mask
value|0x1
end_define

begin_define
define|#
directive|define
name|DagMODim_code_bits
value|8
end_define

begin_define
define|#
directive|define
name|DagMODim_code_mask
value|0xff
end_define

begin_define
define|#
directive|define
name|init_DagMODim
define|\
value|{						\   DagMODim_opcode,				\   DagMODim_i_bits,	DagMODim_i_mask,	\   DagMODim_m_bits,	DagMODim_m_mask,	\   DagMODim_op_bits,	DagMODim_op_mask,	\   DagMODim_code2_bits,	DagMODim_code2_mask,	\   DagMODim_br_bits,	DagMODim_br_mask,	\   DagMODim_code_bits,	DagMODim_code_mask	\ };
end_define

begin_comment
comment|/*  dagMODik +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 1 | 1 | 0 |.op....|.i.....| +---+---+---+---|---+---+---+---|---+---+---+---|---+---+---+---+ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|opcode
decl_stmt|;
name|int
name|bits_i
decl_stmt|;
name|int
name|mask_i
decl_stmt|;
name|int
name|bits_op
decl_stmt|;
name|int
name|mask_op
decl_stmt|;
name|int
name|bits_code
decl_stmt|;
name|int
name|mask_code
decl_stmt|;
block|}
name|DagMODik
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DagMODik_opcode
value|0x9f60
end_define

begin_define
define|#
directive|define
name|DagMODik_i_bits
value|0
end_define

begin_define
define|#
directive|define
name|DagMODik_i_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DagMODik_op_bits
value|2
end_define

begin_define
define|#
directive|define
name|DagMODik_op_mask
value|0x3
end_define

begin_define
define|#
directive|define
name|DagMODik_code_bits
value|3
end_define

begin_define
define|#
directive|define
name|DagMODik_code_mask
value|0xfff
end_define

begin_define
define|#
directive|define
name|init_DagMODik
define|\
value|{						\   DagMODik_opcode,				\   DagMODik_i_bits,	DagMODik_i_mask,	\   DagMODik_op_bits,	DagMODik_op_mask,	\   DagMODik_code_bits,	DagMODik_code_mask	\ };
end_define

end_unit

