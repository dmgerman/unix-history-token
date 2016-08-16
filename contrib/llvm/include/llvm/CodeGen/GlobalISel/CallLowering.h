begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/GlobalISel/CallLowering.h - Call lowering --*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This file describes how to lower LLVM calls to machine code calls.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_CALLLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_CALLLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|MachineIRBuilder
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallLowering
block|{
specifier|const
name|TargetLowering
modifier|*
name|TLI
decl_stmt|;
name|protected
label|:
comment|/// Getter for generic TargetLowering class.
specifier|const
name|TargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
comment|/// Getter for target specific TargetLowering class.
name|template
operator|<
name|class
name|XXXTargetLowering
operator|>
specifier|const
name|XXXTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|XXXTargetLowering
operator|*
operator|>
operator|(
name|TLI
operator|)
return|;
block|}
name|public
label|:
name|CallLowering
argument_list|(
specifier|const
name|TargetLowering
operator|*
name|TLI
argument_list|)
operator|:
name|TLI
argument_list|(
argument|TLI
argument_list|)
block|{}
name|virtual
operator|~
name|CallLowering
argument_list|()
block|{}
comment|/// This hook must be implemented to lower outgoing return values, described
comment|/// by \p Val, into the specified virtual register \p VReg.
comment|/// This hook is used by GlobalISel.
comment|///
comment|/// \return True if the lowering succeeds, false otherwise.
name|virtual
name|bool
name|lowerReturn
argument_list|(
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|const Value *Val
argument_list|,
argument|unsigned VReg
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// This hook must be implemented to lower the incoming (formal)
comment|/// arguments, described by \p Args, for GlobalISel. Each argument
comment|/// must end up in the related virtual register described by VRegs.
comment|/// In other words, the first argument should end up in VRegs[0],
comment|/// the second in VRegs[1], and so on.
comment|/// \p MIRBuilder is set to the proper insertion for the argument
comment|/// lowering.
comment|///
comment|/// \return True if the lowering succeeded, false otherwise.
name|virtual
name|bool
name|lowerFormalArguments
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
specifier|const
name|Function
operator|::
name|ArgumentListType
operator|&
name|Args
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|VRegs
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

