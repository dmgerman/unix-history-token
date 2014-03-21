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
comment|/// Invariant opcodes: All instruction sets have these as their low opcodes.
comment|///
comment|/// Every instruction defined here must also appear in Target.td and the order
comment|/// must be the same as in CodeGenTarget.cpp.
comment|///
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
name|PROLOG_LABEL
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
comment|/// INSERT_SUBREG - This instruction takes three operands: a register that
comment|/// has subregisters, a register providing an insert value, and a
comment|/// subregister index. It returns the value of the first register with the
comment|/// value of the second register inserted. The first register is often
comment|/// defined by an IMPLICIT_DEF, because it is commonly used to implement
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
comment|/// SUBREG_TO_REG - This instruction is similar to INSERT_SUBREG except that
comment|/// the first operand is an immediate integer constant. This constant is
comment|/// often zero, because it is commonly used to assert that the instruction
comment|/// defining the register implicitly clears the high bits.
name|SUBREG_TO_REG
init|=
literal|9
block|,
comment|/// COPY_TO_REGCLASS - This instruction is a placeholder for a plain
comment|/// register-to-register copy into a specific register class. This is only
comment|/// used between instruction selection and MachineInstr creation, before
comment|/// virtual registers have been created for all the instructions, and it's
comment|/// only needed in cases where the register classes implied by the
comment|/// instructions are insufficient. It is emitted as a COPY MachineInstr.
name|COPY_TO_REGCLASS
init|=
literal|10
block|,
comment|/// DBG_VALUE - a mapping of the llvm.dbg.value intrinsic
name|DBG_VALUE
init|=
literal|11
block|,
comment|/// REG_SEQUENCE - This variadic instruction is used to form a register that
comment|/// represents a consecutive sequence of sub-registers. It's used as a
comment|/// register coalescing / allocation aid and must be eliminated before code
comment|/// emission.
comment|// In SDNode form, the first operand encodes the register class created by
comment|// the REG_SEQUENCE, while each subsequent pair names a vreg + subreg index
comment|// pair.  Once it has been lowered to a MachineInstr, the regclass operand
comment|// is no longer present.
comment|/// e.g. v1027 = REG_SEQUENCE v1024, 3, v1025, 4, v1026, 5
comment|/// After register coalescing references of v1024 should be replace with
comment|/// v1027:3, v1025 with v1027:4, etc.
name|REG_SEQUENCE
init|=
literal|12
block|,
comment|/// COPY - Target-independent register copy. This instruction can also be
comment|/// used to copy between subregisters of virtual registers.
name|COPY
init|=
literal|13
block|,
comment|/// BUNDLE - This instruction represents an instruction bundle. Instructions
comment|/// which immediately follow a BUNDLE instruction which are marked with
comment|/// 'InsideBundle' flag are inside the bundle.
name|BUNDLE
init|=
literal|14
block|,
comment|/// Lifetime markers.
name|LIFETIME_START
init|=
literal|15
block|,
name|LIFETIME_END
init|=
literal|16
block|,
comment|/// A Stackmap instruction captures the location of live variables at its
comment|/// position in the instruction stream. It is followed by a shadow of bytes
comment|/// that must lie within the function and not contain another stackmap.
name|STACKMAP
init|=
literal|17
block|,
comment|/// Patchable call instruction - this instruction represents a call to a
comment|/// constant address, followed by a series of NOPs. It is intended to
comment|/// support optimizations for dynamic languages (such as javascript) that
comment|/// rewrite calls to runtimes with more efficient code sequences.
comment|/// This also implies a stack map.
name|PATCHPOINT
init|=
literal|18
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

