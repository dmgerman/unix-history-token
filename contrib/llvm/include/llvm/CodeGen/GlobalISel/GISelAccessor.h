begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GISelAccessor.h - GISel Accessor ------------------------*- C++ -*-===//
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
comment|/// This file declares the API to access the various APIs related
end_comment

begin_comment
comment|/// to GlobalISel.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_GISELACCESSOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_GISELACCESSOR_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallLowering
decl_stmt|;
name|class
name|InstructionSelector
decl_stmt|;
name|class
name|LegalizerInfo
decl_stmt|;
name|class
name|RegisterBankInfo
decl_stmt|;
comment|/// The goal of this helper class is to gather the accessor to all
comment|/// the APIs related to GlobalISel.
comment|/// It should be derived to feature an actual accessor to the GISel APIs.
comment|/// The reason why this is not simply done into the subtarget is to avoid
comment|/// spreading ifdefs around.
struct|struct
name|GISelAccessor
block|{
name|virtual
operator|~
name|GISelAccessor
argument_list|()
block|{}
name|virtual
specifier|const
name|CallLowering
operator|*
name|getCallLowering
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|InstructionSelector
operator|*
name|getInstructionSelector
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|LegalizerInfo
operator|*
name|getLegalizerInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|RegisterBankInfo
operator|*
name|getRegBankInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

