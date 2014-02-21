begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- R600Defines.h - R600 Helper Macros ----------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|R600DEFINES_H_
end_ifndef

begin_define
define|#
directive|define
name|R600DEFINES_H_
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_comment
comment|// Operand Flags
end_comment

begin_define
define|#
directive|define
name|MO_FLAG_CLAMP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_NEG
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_ABS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_MASK
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_PUSH
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_NOT_LAST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MO_FLAG_LAST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|NUM_MO_FLAGS
value|7
end_define

begin_comment
comment|/// \brief Helper for getting the operand index for the instruction flags
end_comment

begin_comment
comment|/// operand.
end_comment

begin_define
define|#
directive|define
name|GET_FLAG_OPERAND_IDX
parameter_list|(
name|Flags
parameter_list|)
value|(((Flags)>> 7)& 0x3)
end_define

begin_decl_stmt
name|namespace
name|R600_InstFlag
block|{
enum|enum
name|TIF
block|{
name|TRANS_ONLY
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|TEX
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|REDUCTION
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|FC
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|TRIG
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|OP3
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|VECTOR
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|//FlagOperand bits 7, 8
name|NATIVE_OPERANDS
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|OP1
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|OP2
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|VTX_INST
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|TEX_INST
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|ALU_INST
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|LDS_1A
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|LDS_1A1D
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
name|IS_EXPORT
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
block|,
name|LDS_1A2D
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
block|}
enum|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|HAS_NATIVE_OPERANDS
parameter_list|(
name|Flags
parameter_list|)
value|((Flags)& R600_InstFlag::NATIVE_OPERANDS)
end_define

begin_comment
comment|/// \brief Defines for extracting register infomation from register encoding
end_comment

begin_define
define|#
directive|define
name|HW_REG_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|HW_CHAN_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|GET_REG_CHAN
parameter_list|(
name|reg
parameter_list|)
value|((reg)>> HW_CHAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|GET_REG_INDEX
parameter_list|(
name|reg
parameter_list|)
value|((reg)& HW_REG_MASK)
end_define

begin_define
define|#
directive|define
name|IS_VTX
parameter_list|(
name|desc
parameter_list|)
value|((desc).TSFlags& R600_InstFlag::VTX_INST)
end_define

begin_define
define|#
directive|define
name|IS_TEX
parameter_list|(
name|desc
parameter_list|)
value|((desc).TSFlags& R600_InstFlag::TEX_INST)
end_define

begin_decl_stmt
name|namespace
name|OpName
block|{
enum|enum
name|VecOps
block|{
name|UPDATE_EXEC_MASK_X
block|,
name|UPDATE_PREDICATE_X
block|,
name|WRITE_X
block|,
name|OMOD_X
block|,
name|DST_REL_X
block|,
name|CLAMP_X
block|,
name|SRC0_X
block|,
name|SRC0_NEG_X
block|,
name|SRC0_REL_X
block|,
name|SRC0_ABS_X
block|,
name|SRC0_SEL_X
block|,
name|SRC1_X
block|,
name|SRC1_NEG_X
block|,
name|SRC1_REL_X
block|,
name|SRC1_ABS_X
block|,
name|SRC1_SEL_X
block|,
name|PRED_SEL_X
block|,
name|UPDATE_EXEC_MASK_Y
block|,
name|UPDATE_PREDICATE_Y
block|,
name|WRITE_Y
block|,
name|OMOD_Y
block|,
name|DST_REL_Y
block|,
name|CLAMP_Y
block|,
name|SRC0_Y
block|,
name|SRC0_NEG_Y
block|,
name|SRC0_REL_Y
block|,
name|SRC0_ABS_Y
block|,
name|SRC0_SEL_Y
block|,
name|SRC1_Y
block|,
name|SRC1_NEG_Y
block|,
name|SRC1_REL_Y
block|,
name|SRC1_ABS_Y
block|,
name|SRC1_SEL_Y
block|,
name|PRED_SEL_Y
block|,
name|UPDATE_EXEC_MASK_Z
block|,
name|UPDATE_PREDICATE_Z
block|,
name|WRITE_Z
block|,
name|OMOD_Z
block|,
name|DST_REL_Z
block|,
name|CLAMP_Z
block|,
name|SRC0_Z
block|,
name|SRC0_NEG_Z
block|,
name|SRC0_REL_Z
block|,
name|SRC0_ABS_Z
block|,
name|SRC0_SEL_Z
block|,
name|SRC1_Z
block|,
name|SRC1_NEG_Z
block|,
name|SRC1_REL_Z
block|,
name|SRC1_ABS_Z
block|,
name|SRC1_SEL_Z
block|,
name|PRED_SEL_Z
block|,
name|UPDATE_EXEC_MASK_W
block|,
name|UPDATE_PREDICATE_W
block|,
name|WRITE_W
block|,
name|OMOD_W
block|,
name|DST_REL_W
block|,
name|CLAMP_W
block|,
name|SRC0_W
block|,
name|SRC0_NEG_W
block|,
name|SRC0_REL_W
block|,
name|SRC0_ABS_W
block|,
name|SRC0_SEL_W
block|,
name|SRC1_W
block|,
name|SRC1_NEG_W
block|,
name|SRC1_REL_W
block|,
name|SRC1_ABS_W
block|,
name|SRC1_SEL_W
block|,
name|PRED_SEL_W
block|,
name|IMM_0
block|,
name|IMM_1
block|,
name|VEC_COUNT
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Config register definitions
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|R_02880C_DB_SHADER_CONTROL
value|0x02880C
end_define

begin_define
define|#
directive|define
name|S_02880C_KILL_ENABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_comment
comment|// These fields are the same for all shader types and families.
end_comment

begin_define
define|#
directive|define
name|S_NUM_GPRS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|S_STACK_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
end_define

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// R600, R700 Registers
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|R_028850_SQ_PGM_RESOURCES_PS
value|0x028850
end_define

begin_define
define|#
directive|define
name|R_028868_SQ_PGM_RESOURCES_VS
value|0x028868
end_define

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Evergreen, Northern Islands Registers
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|R_028844_SQ_PGM_RESOURCES_PS
value|0x028844
end_define

begin_define
define|#
directive|define
name|R_028860_SQ_PGM_RESOURCES_VS
value|0x028860
end_define

begin_define
define|#
directive|define
name|R_028878_SQ_PGM_RESOURCES_GS
value|0x028878
end_define

begin_define
define|#
directive|define
name|R_0288D4_SQ_PGM_RESOURCES_LS
value|0x0288d4
end_define

begin_define
define|#
directive|define
name|R_0288E8_SQ_LDS_ALLOC
value|0x0288E8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// R600DEFINES_H_
end_comment

end_unit

