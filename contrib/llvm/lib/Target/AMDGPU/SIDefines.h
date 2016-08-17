begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SIDefines.h - SI Helper Macros ----------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_SIDEFINES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_SIDEFINES_H
end_define

begin_decl_stmt
name|namespace
name|SIInstrFlags
block|{
comment|// This needs to be kept in sync with the field bits in InstSI.
enum|enum
block|{
name|SALU
init|=
literal|1
operator|<<
literal|3
block|,
name|VALU
init|=
literal|1
operator|<<
literal|4
block|,
name|SOP1
init|=
literal|1
operator|<<
literal|5
block|,
name|SOP2
init|=
literal|1
operator|<<
literal|6
block|,
name|SOPC
init|=
literal|1
operator|<<
literal|7
block|,
name|SOPK
init|=
literal|1
operator|<<
literal|8
block|,
name|SOPP
init|=
literal|1
operator|<<
literal|9
block|,
name|VOP1
init|=
literal|1
operator|<<
literal|10
block|,
name|VOP2
init|=
literal|1
operator|<<
literal|11
block|,
name|VOP3
init|=
literal|1
operator|<<
literal|12
block|,
name|VOPC
init|=
literal|1
operator|<<
literal|13
block|,
name|SDWA
init|=
literal|1
operator|<<
literal|14
block|,
name|DPP
init|=
literal|1
operator|<<
literal|15
block|,
name|MUBUF
init|=
literal|1
operator|<<
literal|16
block|,
name|MTBUF
init|=
literal|1
operator|<<
literal|17
block|,
name|SMRD
init|=
literal|1
operator|<<
literal|18
block|,
name|DS
init|=
literal|1
operator|<<
literal|19
block|,
name|MIMG
init|=
literal|1
operator|<<
literal|20
block|,
name|FLAT
init|=
literal|1
operator|<<
literal|21
block|,
name|WQM
init|=
literal|1
operator|<<
literal|22
block|,
name|VGPRSpill
init|=
literal|1
operator|<<
literal|23
block|,
name|VOPAsmPrefer32Bit
init|=
literal|1
operator|<<
literal|24
block|,
name|Gather4
init|=
literal|1
operator|<<
literal|25
block|,
name|DisableWQM
init|=
literal|1
operator|<<
literal|26
block|}
enum|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AMDGPU
block|{
enum|enum
name|OperandType
block|{
comment|/// Operand with register or 32-bit immediate
name|OPERAND_REG_IMM32
init|=
name|MCOI
operator|::
name|OPERAND_FIRST_TARGET
block|,
comment|/// Operand with register or inline constant
name|OPERAND_REG_INLINE_C
block|,
comment|/// Operand with 32-bit immediate that uses the constant bus. The standard
comment|/// OPERAND_IMMEDIATE should be used for special immediates such as source
comment|/// modifiers.
name|OPERAND_KIMM32
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|SIInstrFlags
block|{
enum|enum
name|Flags
block|{
comment|// First 4 bits are the instruction encoding
name|VM_CNT
init|=
literal|1
operator|<<
literal|0
block|,
name|EXP_CNT
init|=
literal|1
operator|<<
literal|1
block|,
name|LGKM_CNT
init|=
literal|1
operator|<<
literal|2
block|}
enum|;
comment|// v_cmp_class_* etc. use a 10-bit mask for what operation is checked.
comment|// The result is true if any of these tests are true.
enum|enum
name|ClassFlags
block|{
name|S_NAN
init|=
literal|1
operator|<<
literal|0
block|,
comment|// Signaling NaN
name|Q_NAN
init|=
literal|1
operator|<<
literal|1
block|,
comment|// Quiet NaN
name|N_INFINITY
init|=
literal|1
operator|<<
literal|2
block|,
comment|// Negative infinity
name|N_NORMAL
init|=
literal|1
operator|<<
literal|3
block|,
comment|// Negative normal
name|N_SUBNORMAL
init|=
literal|1
operator|<<
literal|4
block|,
comment|// Negative subnormal
name|N_ZERO
init|=
literal|1
operator|<<
literal|5
block|,
comment|// Negative zero
name|P_ZERO
init|=
literal|1
operator|<<
literal|6
block|,
comment|// Positive zero
name|P_SUBNORMAL
init|=
literal|1
operator|<<
literal|7
block|,
comment|// Positive subnormal
name|P_NORMAL
init|=
literal|1
operator|<<
literal|8
block|,
comment|// Positive normal
name|P_INFINITY
init|=
literal|1
operator|<<
literal|9
comment|// Positive infinity
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// Input operand modifiers bit-masks
end_comment

begin_comment
comment|// NEG and SEXT share same bit-mask because they can't be set simultaneously.
end_comment

begin_decl_stmt
name|namespace
name|SISrcMods
block|{
enum|enum
block|{
name|NEG
init|=
literal|1
operator|<<
literal|0
block|,
comment|// Floating-point negate modifier
name|ABS
init|=
literal|1
operator|<<
literal|1
block|,
comment|// Floating-point absolute modifier
name|SEXT
init|=
literal|1
operator|<<
literal|0
comment|// Integer sign-extend modifier
block|}
enum|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|SIOutMods
block|{
enum|enum
block|{
name|NONE
init|=
literal|0
block|,
name|MUL2
init|=
literal|1
block|,
name|MUL4
init|=
literal|2
block|,
name|DIV2
init|=
literal|3
block|}
enum|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AMDGPU
block|{
name|namespace
name|EncValues
block|{
comment|// Encoding values of enum9/8/7 operands
enum|enum
block|{
name|SGPR_MIN
init|=
literal|0
block|,
name|SGPR_MAX
init|=
literal|101
block|,
name|TTMP_MIN
init|=
literal|112
block|,
name|TTMP_MAX
init|=
literal|123
block|,
name|INLINE_INTEGER_C_MIN
init|=
literal|128
block|,
name|INLINE_INTEGER_C_POSITIVE_MAX
init|=
literal|192
block|,
comment|// 64
name|INLINE_INTEGER_C_MAX
init|=
literal|208
block|,
name|INLINE_FLOATING_C_MIN
init|=
literal|240
block|,
name|INLINE_FLOATING_C_MAX
init|=
literal|248
block|,
name|LITERAL_CONST
init|=
literal|255
block|,
name|VGPR_MIN
init|=
literal|256
block|,
name|VGPR_MAX
init|=
literal|511
block|}
enum|;
block|}
comment|// namespace EncValues
block|}
comment|// namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|AMDGPU
block|{
name|namespace
name|SendMsg
block|{
comment|// Encoding of SIMM16 used in s_sendmsg* insns.
enum|enum
name|Id
block|{
comment|// Message ID, width(4) [3:0].
name|ID_UNKNOWN_
init|=
operator|-
literal|1
block|,
name|ID_INTERRUPT
init|=
literal|1
block|,
name|ID_GS
block|,
name|ID_GS_DONE
block|,
name|ID_SYSMSG
init|=
literal|15
block|,
name|ID_GAPS_LAST_
block|,
comment|// Indicate that sequence has gaps.
name|ID_GAPS_FIRST_
init|=
name|ID_INTERRUPT
block|,
name|ID_SHIFT_
init|=
literal|0
block|,
name|ID_WIDTH_
init|=
literal|4
block|,
name|ID_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|ID_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|ID_SHIFT_
operator|)
block|}
enum|;
enum|enum
name|Op
block|{
comment|// Both GS and SYS operation IDs.
name|OP_UNKNOWN_
init|=
operator|-
literal|1
block|,
name|OP_SHIFT_
init|=
literal|4
block|,
comment|// width(2) [5:4]
name|OP_GS_NOP
init|=
literal|0
block|,
name|OP_GS_CUT
block|,
name|OP_GS_EMIT
block|,
name|OP_GS_EMIT_CUT
block|,
name|OP_GS_LAST_
block|,
name|OP_GS_FIRST_
init|=
name|OP_GS_NOP
block|,
name|OP_GS_WIDTH_
init|=
literal|2
block|,
name|OP_GS_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|OP_GS_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|OP_SHIFT_
operator|)
block|,
comment|// width(3) [6:4]
name|OP_SYS_ECC_ERR_INTERRUPT
init|=
literal|1
block|,
name|OP_SYS_REG_RD
block|,
name|OP_SYS_HOST_TRAP_ACK
block|,
name|OP_SYS_TTRACE_PC
block|,
name|OP_SYS_LAST_
block|,
name|OP_SYS_FIRST_
init|=
name|OP_SYS_ECC_ERR_INTERRUPT
block|,
name|OP_SYS_WIDTH_
init|=
literal|3
block|,
name|OP_SYS_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|OP_SYS_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|OP_SHIFT_
operator|)
block|}
enum|;
enum|enum
name|StreamId
block|{
comment|// Stream ID, (2) [9:8].
name|STREAM_ID_DEFAULT_
init|=
literal|0
block|,
name|STREAM_ID_LAST_
init|=
literal|4
block|,
name|STREAM_ID_FIRST_
init|=
name|STREAM_ID_DEFAULT_
block|,
name|STREAM_ID_SHIFT_
init|=
literal|8
block|,
name|STREAM_ID_WIDTH_
init|=
literal|2
block|,
name|STREAM_ID_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|STREAM_ID_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|STREAM_ID_SHIFT_
operator|)
block|}
enum|;
block|}
comment|// namespace SendMsg
name|namespace
name|Hwreg
block|{
comment|// Encoding of SIMM16 used in s_setreg/getreg* insns.
enum|enum
name|Id
block|{
comment|// HwRegCode, (6) [5:0]
name|ID_UNKNOWN_
init|=
operator|-
literal|1
block|,
name|ID_SYMBOLIC_FIRST_
init|=
literal|1
block|,
comment|// There are corresponding symbolic names defined.
name|ID_SYMBOLIC_LAST_
init|=
literal|8
block|,
name|ID_SHIFT_
init|=
literal|0
block|,
name|ID_WIDTH_
init|=
literal|6
block|,
name|ID_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|ID_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|ID_SHIFT_
operator|)
block|}
enum|;
enum|enum
name|Offset
block|{
comment|// Offset, (5) [10:6]
name|OFFSET_DEFAULT_
init|=
literal|0
block|,
name|OFFSET_SHIFT_
init|=
literal|6
block|,
name|OFFSET_WIDTH_
init|=
literal|5
block|,
name|OFFSET_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|OFFSET_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|OFFSET_SHIFT_
operator|)
block|}
enum|;
enum|enum
name|WidthMinusOne
block|{
comment|// WidthMinusOne, (5) [15:11]
name|WIDTH_M1_DEFAULT_
init|=
literal|31
block|,
name|WIDTH_M1_SHIFT_
init|=
literal|11
block|,
name|WIDTH_M1_WIDTH_
init|=
literal|5
block|,
name|WIDTH_M1_MASK_
init|=
operator|(
operator|(
operator|(
literal|1
operator|<<
name|WIDTH_M1_WIDTH_
operator|)
operator|-
literal|1
operator|)
operator|<<
name|WIDTH_M1_SHIFT_
operator|)
block|}
enum|;
block|}
comment|// namespace Hwreg
block|}
comment|// namespace AMDGPU
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_define
define|#
directive|define
name|R_00B028_SPI_SHADER_PGM_RSRC1_PS
value|0x00B028
end_define

begin_define
define|#
directive|define
name|R_00B02C_SPI_SHADER_PGM_RSRC2_PS
value|0x00B02C
end_define

begin_define
define|#
directive|define
name|S_00B02C_EXTRA_LDS_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
end_define

begin_define
define|#
directive|define
name|R_00B128_SPI_SHADER_PGM_RSRC1_VS
value|0x00B128
end_define

begin_define
define|#
directive|define
name|R_00B228_SPI_SHADER_PGM_RSRC1_GS
value|0x00B228
end_define

begin_define
define|#
directive|define
name|R_00B848_COMPUTE_PGM_RSRC1
value|0x00B848
end_define

begin_define
define|#
directive|define
name|S_00B028_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|S_00B028_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F)<< 6)
end_define

begin_define
define|#
directive|define
name|R_00B84C_COMPUTE_PGM_RSRC2
value|0x00B84C
end_define

begin_define
define|#
directive|define
name|S_00B84C_SCRATCH_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00B84C_SCRATCH_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B84C_SCRATCH_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_00B84C_USER_SGPR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1F)<< 1)
end_define

begin_define
define|#
directive|define
name|G_00B84C_USER_SGPR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1F)
end_define

begin_define
define|#
directive|define
name|C_00B84C_USER_SGPR
value|0xFFFFFFC1
end_define

begin_define
define|#
directive|define
name|S_00B84C_TGID_X_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_00B84C_TGID_X_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B84C_TGID_X_EN
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_00B84C_TGID_Y_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_00B84C_TGID_Y_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B84C_TGID_Y_EN
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_00B84C_TGID_Z_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_00B84C_TGID_Z_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B84C_TGID_Z_EN
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_00B84C_TG_SIZE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_00B84C_TG_SIZE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B84C_TG_SIZE_EN
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_00B84C_TIDIG_COMP_CNT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 11)
end_define

begin_define
define|#
directive|define
name|G_00B84C_TIDIG_COMP_CNT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x03)
end_define

begin_define
define|#
directive|define
name|C_00B84C_TIDIG_COMP_CNT
value|0xFFFFE7FF
end_define

begin_comment
comment|/* CIK */
end_comment

begin_define
define|#
directive|define
name|S_00B84C_EXCP_EN_MSB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 13)
end_define

begin_define
define|#
directive|define
name|G_00B84C_EXCP_EN_MSB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x03)
end_define

begin_define
define|#
directive|define
name|C_00B84C_EXCP_EN_MSB
value|0xFFFF9FFF
end_define

begin_comment
comment|/*     */
end_comment

begin_define
define|#
directive|define
name|S_00B84C_LDS_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FF)<< 15)
end_define

begin_define
define|#
directive|define
name|G_00B84C_LDS_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1FF)
end_define

begin_define
define|#
directive|define
name|C_00B84C_LDS_SIZE
value|0xFF007FFF
end_define

begin_define
define|#
directive|define
name|S_00B84C_EXCP_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 24)
end_define

begin_define
define|#
directive|define
name|G_00B84C_EXCP_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_00B84C_EXCP_EN
end_define

begin_define
define|#
directive|define
name|R_0286CC_SPI_PS_INPUT_ENA
value|0x0286CC
end_define

begin_define
define|#
directive|define
name|R_0286D0_SPI_PS_INPUT_ADDR
value|0x0286D0
end_define

begin_define
define|#
directive|define
name|R_00B848_COMPUTE_PGM_RSRC1
value|0x00B848
end_define

begin_define
define|#
directive|define
name|S_00B848_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00B848_VGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_00B848_VGPRS
value|0xFFFFFFC0
end_define

begin_define
define|#
directive|define
name|S_00B848_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F)<< 6)
end_define

begin_define
define|#
directive|define
name|G_00B848_SGPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x0F)
end_define

begin_define
define|#
directive|define
name|C_00B848_SGPRS
value|0xFFFFFC3F
end_define

begin_define
define|#
directive|define
name|S_00B848_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x03)<< 10)
end_define

begin_define
define|#
directive|define
name|G_00B848_PRIORITY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x03)
end_define

begin_define
define|#
directive|define
name|C_00B848_PRIORITY
value|0xFFFFF3FF
end_define

begin_define
define|#
directive|define
name|S_00B848_FLOAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 12)
end_define

begin_define
define|#
directive|define
name|G_00B848_FLOAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_00B848_FLOAT_MODE
value|0xFFF00FFF
end_define

begin_define
define|#
directive|define
name|S_00B848_PRIV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00B848_PRIV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_PRIV
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_DX10_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_00B848_DX10_CLAMP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_DX10_CLAMP
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_DEBUG_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_00B848_DEBUG_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_DEBUG_MODE
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_00B848_IEEE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_00B848_IEEE_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00B848_IEEE_MODE
value|0xFF7FFFFF
end_define

begin_comment
comment|// Helpers for setting FLOAT_MODE
end_comment

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_NEAREST
value|0
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_INF
value|1
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_NEGINF
value|2
end_define

begin_define
define|#
directive|define
name|FP_ROUND_ROUND_TO_ZERO
value|3
end_define

begin_comment
comment|// Bits 3:0 control rounding mode. 1:0 control single precision, 3:2 double
end_comment

begin_comment
comment|// precision.
end_comment

begin_define
define|#
directive|define
name|FP_ROUND_MODE_SP
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_define
define|#
directive|define
name|FP_ROUND_MODE_DP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_IN_FLUSH_OUT
value|0
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_OUT
value|1
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_IN
value|2
end_define

begin_define
define|#
directive|define
name|FP_DENORM_FLUSH_NONE
value|3
end_define

begin_comment
comment|// Bits 7:4 control denormal handling. 5:4 control single precision, 6:7 double
end_comment

begin_comment
comment|// precision.
end_comment

begin_define
define|#
directive|define
name|FP_DENORM_MODE_SP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|FP_DENORM_MODE_DP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|R_00B860_COMPUTE_TMPRING_SIZE
value|0x00B860
end_define

begin_define
define|#
directive|define
name|S_00B860_WAVESIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 12)
end_define

begin_define
define|#
directive|define
name|R_0286E8_SPI_TMPRING_SIZE
value|0x0286E8
end_define

begin_define
define|#
directive|define
name|S_0286E8_WAVESIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1FFF)<< 12)
end_define

begin_define
define|#
directive|define
name|R_SPILLED_SGPRS
value|0x4
end_define

begin_define
define|#
directive|define
name|R_SPILLED_VGPRS
value|0x8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

