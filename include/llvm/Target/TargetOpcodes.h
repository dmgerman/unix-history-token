begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetOpcodes.h - Target Indep Opcodes ------*- C++ -*-===//
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
comment|// This file defines the target independent instruction opcodes.
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
name|LLVM_TARGET_TARGETOPCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETOPCODES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Invariant opcodes: All instruction sets have these as their low opcodes.
name|namespace
name|TargetOpcode
block|{
enum|enum
block|{
name|PHI
init|=
literal|0
block|,
name|INLINEASM
init|=
literal|1
block|,
name|DBG_LABEL
init|=
literal|2
block|,
name|EH_LABEL
init|=
literal|3
block|,
name|GC_LABEL
init|=
literal|4
block|,
comment|/// KILL - This instruction is a noop that is used only to adjust the
comment|/// liveness of registers. This can be useful when dealing with
comment|/// sub-registers.
name|KILL
init|=
literal|5
block|,
comment|/// EXTRACT_SUBREG - This instruction takes two operands: a register
comment|/// that has subregisters, and a subregister index. It returns the
comment|/// extracted subregister value. This is commonly used to implement
comment|/// truncation operations on target architectures which support it.
name|EXTRACT_SUBREG
init|=
literal|6
block|,
comment|/// INSERT_SUBREG - This instruction takes three operands: a register
comment|/// that has subregisters, a register providing an insert value, and a
comment|/// subregister index. It returns the value of the first register with
comment|/// the value of the second register inserted. The first register is
comment|/// often defined by an IMPLICIT_DEF, as is commonly used to implement
comment|/// anyext operations on target architectures which support it.
name|INSERT_SUBREG
init|=
literal|7
block|,
comment|/// IMPLICIT_DEF - This is the MachineInstr-level equivalent of undef.
name|IMPLICIT_DEF
init|=
literal|8
block|,
comment|/// SUBREG_TO_REG - This instruction is similar to INSERT_SUBREG except
comment|/// that the first operand is an immediate integer constant. This constant
comment|/// is often zero, as is commonly used to implement zext operations on
comment|/// target architectures which support it, such as with x86-64 (with
comment|/// zext from i32 to i64 via implicit zero-extension).
name|SUBREG_TO_REG
init|=
literal|9
block|,
comment|/// COPY_TO_REGCLASS - This instruction is a placeholder for a plain
comment|/// register-to-register copy into a specific register class. This is only
comment|/// used between instruction selection and MachineInstr creation, before
comment|/// virtual registers have been created for all the instructions, and it's
comment|/// only needed in cases where the register classes implied by the
comment|/// instructions are insufficient. The actual MachineInstrs to perform
comment|/// the copy are emitted with the TargetInstrInfo::copyRegToReg hook.
name|COPY_TO_REGCLASS
init|=
literal|10
block|,
comment|// DBG_VALUE - a mapping of the llvm.dbg.value intrinsic
name|DBG_VALUE
init|=
literal|11
block|}
enum|;
block|}
comment|// end namespace TargetOpcode
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

