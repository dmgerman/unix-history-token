begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjCARC.h - ObjC ARC Optimization --------------*- C++ -*-----------===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file defines common definitions/declarations used by the ObjC ARC
end_comment

begin_comment
comment|/// Optimizer. ARC stands for Automatic Reference Counting and is a system for
end_comment

begin_comment
comment|/// managing reference counts for objects in Objective C.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about certain library functions. It recognizes them
end_comment

begin_comment
comment|/// by name, and hardwires knowledge of their semantics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// WARNING: This file knows about how certain Objective-C library functions are
end_comment

begin_comment
comment|/// used. Naive LLVM IR transformations which would otherwise be
end_comment

begin_comment
comment|/// behavior-preserving may break these assumptions.
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
name|LLVM_LIB_TRANSFORMS_OBJCARC_OBJCARC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TRANSFORMS_OBJCARC_OBJCARC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ObjCARCAnalysisUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ObjCARCInstKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ValueTracking.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/ObjCARC.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/Local.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|objcarc
block|{
comment|/// \brief Erase the given instruction.
comment|///
comment|/// Many ObjC calls return their argument verbatim,
comment|/// so if it's such a call and the return value has users, replace them with the
comment|/// argument value.
comment|///
specifier|static
specifier|inline
name|void
name|EraseInstruction
parameter_list|(
name|Instruction
modifier|*
name|CI
parameter_list|)
block|{
name|Value
modifier|*
name|OldArg
init|=
name|cast
operator|<
name|CallInst
operator|>
operator|(
name|CI
operator|)
operator|->
name|getArgOperand
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|bool
name|Unused
init|=
name|CI
operator|->
name|use_empty
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|Unused
condition|)
block|{
comment|// Replace the return value with the argument.
name|assert
argument_list|(
operator|(
name|IsForwarding
argument_list|(
name|GetBasicARCInstKind
argument_list|(
name|CI
argument_list|)
argument_list|)
operator|||
operator|(
name|IsNoopOnNull
argument_list|(
name|GetBasicARCInstKind
argument_list|(
name|CI
argument_list|)
argument_list|)
operator|&&
name|isa
operator|<
name|ConstantPointerNull
operator|>
operator|(
name|OldArg
operator|)
operator|)
operator|)
operator|&&
literal|"Can't delete non-forwarding instruction with users!"
argument_list|)
expr_stmt|;
name|CI
operator|->
name|replaceAllUsesWith
argument_list|(
name|OldArg
argument_list|)
expr_stmt|;
block|}
name|CI
operator|->
name|eraseFromParent
argument_list|()
expr_stmt|;
if|if
condition|(
name|Unused
condition|)
name|RecursivelyDeleteTriviallyDeadInstructions
argument_list|(
name|OldArg
argument_list|)
expr_stmt|;
block|}
comment|/// If Inst is a ReturnRV and its operand is a call or invoke, return the
comment|/// operand. Otherwise return null.
specifier|static
specifier|inline
specifier|const
name|Instruction
modifier|*
name|getreturnRVOperand
parameter_list|(
specifier|const
name|Instruction
modifier|&
name|Inst
parameter_list|,
name|ARCInstKind
name|Class
parameter_list|)
block|{
if|if
condition|(
name|Class
operator|!=
name|ARCInstKind
operator|::
name|RetainRV
condition|)
return|return
name|nullptr
return|;
specifier|const
specifier|auto
modifier|*
name|Opnd
init|=
name|Inst
operator|.
name|getOperand
argument_list|(
literal|0
argument_list|)
operator|->
name|stripPointerCasts
argument_list|()
decl_stmt|;
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|C
init|=
name|dyn_cast
operator|<
name|CallInst
operator|>
operator|(
name|Opnd
operator|)
condition|)
return|return
name|C
return|;
return|return
name|dyn_cast
operator|<
name|InvokeInst
operator|>
operator|(
name|Opnd
operator|)
return|;
block|}
block|}
comment|// end namespace objcarc
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

