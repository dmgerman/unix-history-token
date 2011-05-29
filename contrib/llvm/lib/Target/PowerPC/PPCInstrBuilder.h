begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCInstrBuilder.h - Aides for building PPC insts --------*- C++ -*-===//
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
comment|// This file exposes functions that may be used with BuildMI from the
end_comment

begin_comment
comment|// MachineInstrBuilder.h file to simplify generating frame and constant pool
end_comment

begin_comment
comment|// references.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For reference, the order of operands for memory references is:
end_comment

begin_comment
comment|// (Operand), Dest Reg, Base Reg, and either Reg Index or Immediate
end_comment

begin_comment
comment|// Displacement.
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
name|POWERPC_INSTRBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC_INSTRBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// addFrameReference - This function is used to add a reference to the base of
comment|/// an abstract object on the stack frame of the current function.  This
comment|/// reference has base register as the FrameIndex offset until it is resolved.
comment|/// This allows a constant offset to be specified as well...
comment|///
specifier|static
specifier|inline
specifier|const
name|MachineInstrBuilder
modifier|&
name|addFrameReference
parameter_list|(
specifier|const
name|MachineInstrBuilder
modifier|&
name|MIB
parameter_list|,
name|int
name|FI
parameter_list|,
name|int
name|Offset
init|=
literal|0
parameter_list|,
name|bool
name|mem
init|=
name|true
parameter_list|)
block|{
if|if
condition|(
name|mem
condition|)
return|return
name|MIB
operator|.
name|addImm
argument_list|(
name|Offset
argument_list|)
operator|.
name|addFrameIndex
argument_list|(
name|FI
argument_list|)
return|;
else|else
return|return
name|MIB
operator|.
name|addFrameIndex
argument_list|(
name|FI
argument_list|)
operator|.
name|addImm
argument_list|(
name|Offset
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

