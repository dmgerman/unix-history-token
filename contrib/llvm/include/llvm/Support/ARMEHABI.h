begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ARMEHABI.h - ARM Exception Handling ABI ----------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines the constants for the ARM unwind opcodes and exception
end_comment

begin_comment
comment|// handling table entry kinds.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The enumerations and constants in this file reflect the ARM EHABI
end_comment

begin_comment
comment|// Specification as published by ARM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Exception Handling ABI for the ARM Architecture r2.09 - November 30, 2012
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// http://infocenter.arm.com/help/topic/com.arm.doc.ihi0038a/IHI0038A_ehabi.pdf
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_ARMEHABI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ARMEHABI_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|ARM
block|{
name|namespace
name|EHABI
block|{
comment|/// ARM exception handling table entry kinds
enum|enum
name|EHTEntryKind
block|{
name|EHT_GENERIC
init|=
literal|0x00
block|,
name|EHT_COMPACT
init|=
literal|0x80
block|}
enum|;
enum|enum
block|{
comment|/// Special entry for the function never unwind
name|EXIDX_CANTUNWIND
init|=
literal|0x1
block|}
enum|;
comment|/// ARM-defined frame unwinding opcodes
enum|enum
name|UnwindOpcodes
block|{
comment|// Format: 00xxxxxx
comment|// Purpose: vsp = vsp + ((x<< 2) + 4)
name|UNWIND_OPCODE_INC_VSP
init|=
literal|0x00
block|,
comment|// Format: 01xxxxxx
comment|// Purpose: vsp = vsp - ((x<< 2) + 4)
name|UNWIND_OPCODE_DEC_VSP
init|=
literal|0x40
block|,
comment|// Format: 10000000 00000000
comment|// Purpose: refuse to unwind
name|UNWIND_OPCODE_REFUSE
init|=
literal|0x8000
block|,
comment|// Format: 1000xxxx xxxxxxxx
comment|// Purpose: pop r[15:12], r[11:4]
comment|// Constraint: x != 0
name|UNWIND_OPCODE_POP_REG_MASK_R4
init|=
literal|0x8000
block|,
comment|// Format: 1001xxxx
comment|// Purpose: vsp = r[x]
comment|// Constraint: x != 13&& x != 15
name|UNWIND_OPCODE_SET_VSP
init|=
literal|0x90
block|,
comment|// Format: 10100xxx
comment|// Purpose: pop r[(4+x):4]
name|UNWIND_OPCODE_POP_REG_RANGE_R4
init|=
literal|0xa0
block|,
comment|// Format: 10101xxx
comment|// Purpose: pop r14, r[(4+x):4]
name|UNWIND_OPCODE_POP_REG_RANGE_R4_R14
init|=
literal|0xa8
block|,
comment|// Format: 10110000
comment|// Purpose: finish
name|UNWIND_OPCODE_FINISH
init|=
literal|0xb0
block|,
comment|// Format: 10110001 0000xxxx
comment|// Purpose: pop r[3:0]
comment|// Constraint: x != 0
name|UNWIND_OPCODE_POP_REG_MASK
init|=
literal|0xb100
block|,
comment|// Format: 10110010 x(uleb128)
comment|// Purpose: vsp = vsp + ((x<< 2) + 0x204)
name|UNWIND_OPCODE_INC_VSP_ULEB128
init|=
literal|0xb2
block|,
comment|// Format: 10110011 xxxxyyyy
comment|// Purpose: pop d[(x+y):x]
name|UNWIND_OPCODE_POP_VFP_REG_RANGE_FSTMFDX
init|=
literal|0xb300
block|,
comment|// Format: 10111xxx
comment|// Purpose: pop d[(8+x):8]
name|UNWIND_OPCODE_POP_VFP_REG_RANGE_FSTMFDX_D8
init|=
literal|0xb8
block|,
comment|// Format: 11000xxx
comment|// Purpose: pop wR[(10+x):10]
name|UNWIND_OPCODE_POP_WIRELESS_MMX_REG_RANGE_WR10
init|=
literal|0xc0
block|,
comment|// Format: 11000110 xxxxyyyy
comment|// Purpose: pop wR[(x+y):x]
name|UNWIND_OPCODE_POP_WIRELESS_MMX_REG_RANGE
init|=
literal|0xc600
block|,
comment|// Format: 11000111 0000xxxx
comment|// Purpose: pop wCGR[3:0]
comment|// Constraint: x != 0
name|UNWIND_OPCODE_POP_WIRELESS_MMX_REG_MASK
init|=
literal|0xc700
block|,
comment|// Format: 11001000 xxxxyyyy
comment|// Purpose: pop d[(16+x+y):(16+x)]
name|UNWIND_OPCODE_POP_VFP_REG_RANGE_FSTMFDD_D16
init|=
literal|0xc800
block|,
comment|// Format: 11001001 xxxxyyyy
comment|// Purpose: pop d[(x+y):x]
name|UNWIND_OPCODE_POP_VFP_REG_RANGE_FSTMFDD
init|=
literal|0xc900
block|,
comment|// Format: 11010xxx
comment|// Purpose: pop d[(8+x):8]
name|UNWIND_OPCODE_POP_VFP_REG_RANGE_FSTMFDD_D8
init|=
literal|0xd0
block|}
enum|;
comment|/// ARM-defined Personality Routine Index
enum|enum
name|PersonalityRoutineIndex
block|{
comment|// To make the exception handling table become more compact, ARM defined
comment|// several personality routines in EHABI.  There are 3 different
comment|// personality routines in ARM EHABI currently.  It is possible to have 16
comment|// pre-defined personality routines at most.
name|AEABI_UNWIND_CPP_PR0
init|=
literal|0
block|,
name|AEABI_UNWIND_CPP_PR1
init|=
literal|1
block|,
name|AEABI_UNWIND_CPP_PR2
init|=
literal|2
block|,
name|NUM_PERSONALITY_INDEX
block|}
enum|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

