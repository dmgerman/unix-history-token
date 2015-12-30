begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- XCoreTargetTransformInfo.h - XCore specific TTI ---------*- C++ -*-===//
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
comment|/// This file a TargetTransformInfo::Concept conforming object specific to the
end_comment

begin_comment
comment|/// XCore target machine. It uses the target's detailed information to
end_comment

begin_comment
comment|/// provide more precise answers to certain TTI queries, while letting the
end_comment

begin_comment
comment|/// target independent and default TTI implementations handle the rest.
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
name|LLVM_LIB_TARGET_XCORE_XCORETARGETTRANSFORMINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_XCORE_XCORETARGETTRANSFORMINFO_H
end_define

begin_include
include|#
directive|include
file|"XCore.h"
end_include

begin_include
include|#
directive|include
file|"XCoreTargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/TargetTransformInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/BasicTTIImpl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|XCoreTTIImpl
range|:
name|public
name|BasicTTIImplBase
operator|<
name|XCoreTTIImpl
operator|>
block|{
typedef|typedef
name|BasicTTIImplBase
operator|<
name|XCoreTTIImpl
operator|>
name|BaseT
expr_stmt|;
typedef|typedef
name|TargetTransformInfo
name|TTI
typedef|;
name|friend
name|BaseT
decl_stmt|;
specifier|const
name|XCoreSubtarget
modifier|*
name|ST
decl_stmt|;
specifier|const
name|XCoreTargetLowering
modifier|*
name|TLI
decl_stmt|;
specifier|const
name|XCoreSubtarget
operator|*
name|getST
argument_list|()
specifier|const
block|{
return|return
name|ST
return|;
block|}
specifier|const
name|XCoreTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
name|public
label|:
name|explicit
name|XCoreTTIImpl
argument_list|(
specifier|const
name|XCoreTargetMachine
operator|*
name|TM
argument_list|,
specifier|const
name|Function
operator|&
name|F
argument_list|)
operator|:
name|BaseT
argument_list|(
name|TM
argument_list|,
name|F
operator|.
name|getParent
argument_list|()
operator|->
name|getDataLayout
argument_list|()
argument_list|)
operator|,
name|ST
argument_list|(
name|TM
operator|->
name|getSubtargetImpl
argument_list|()
argument_list|)
operator|,
name|TLI
argument_list|(
argument|ST->getTargetLowering()
argument_list|)
block|{}
comment|// Provide value semantics. MSVC requires that we spell all of these out.
name|XCoreTTIImpl
argument_list|(
specifier|const
name|XCoreTTIImpl
operator|&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|static_cast
operator|<
specifier|const
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
operator|,
name|ST
argument_list|(
name|Arg
operator|.
name|ST
argument_list|)
operator|,
name|TLI
argument_list|(
argument|Arg.TLI
argument_list|)
block|{}
name|XCoreTTIImpl
argument_list|(
name|XCoreTTIImpl
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|Arg
operator|)
argument_list|)
argument_list|)
operator|,
name|ST
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|ST
argument_list|)
argument_list|)
operator|,
name|TLI
argument_list|(
argument|std::move(Arg.TLI)
argument_list|)
block|{}
name|unsigned
name|getNumberOfRegisters
argument_list|(
argument|bool Vector
argument_list|)
block|{
if|if
condition|(
name|Vector
condition|)
block|{
return|return
literal|0
return|;
block|}
return|return
literal|12
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

