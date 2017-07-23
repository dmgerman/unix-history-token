begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmCond.h - Assembly file conditional assembly  ----------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCPARSER_ASMCOND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCPARSER_ASMCOND_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// AsmCond - Class to support conditional assembly
comment|///
comment|/// The conditional assembly feature (.if, .else, .elseif and .endif) is
comment|/// implemented with AsmCond that tells us what we are in the middle of
comment|/// processing.  Ignore can be either true or false.  When true we are ignoring
comment|/// the block of code in the middle of a conditional.
name|class
name|AsmCond
block|{
name|public
label|:
enum|enum
name|ConditionalAssemblyType
block|{
name|NoCond
block|,
comment|// no conditional is being processed
name|IfCond
block|,
comment|// inside if conditional
name|ElseIfCond
block|,
comment|// inside elseif conditional
name|ElseCond
comment|// inside else conditional
block|}
enum|;
name|ConditionalAssemblyType
name|TheCond
init|=
name|NoCond
decl_stmt|;
name|bool
name|CondMet
init|=
name|false
decl_stmt|;
name|bool
name|Ignore
init|=
name|false
decl_stmt|;
name|AsmCond
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCPARSER_ASMCOND_H
end_comment

end_unit

