begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Analysis/ObjectUtils.h - analysis utils for object files -*- C++ -*-===//
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
name|LLVM_ANALYSIS_OBJECT_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_OBJECT_UTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// True if GV can be left out of the object symbol table. This is the case
comment|/// for linkonce_odr values whose address is not significant. While legal, it is
comment|/// not normally profitable to omit them from the .o symbol table. Using this
comment|/// analysis makes sense when the information can be passed down to the linker
comment|/// or we are in LTO.
specifier|inline
name|bool
name|canBeOmittedFromSymbolTable
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
block|{
if|if
condition|(
operator|!
name|GV
operator|->
name|hasLinkOnceODRLinkage
argument_list|()
condition|)
return|return
name|false
return|;
comment|// We assume that anyone who sets global unnamed_addr on a non-constant knows
comment|// what they're doing.
if|if
condition|(
name|GV
operator|->
name|hasGlobalUnnamedAddr
argument_list|()
condition|)
return|return
name|true
return|;
comment|// If it is a non constant variable, it needs to be uniqued across shared
comment|// objects.
if|if
condition|(
name|auto
operator|*
name|Var
operator|=
name|dyn_cast
operator|<
name|GlobalVariable
operator|>
operator|(
name|GV
operator|)
condition|)
if|if
condition|(
operator|!
name|Var
operator|->
name|isConstant
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|GV
operator|->
name|hasAtLeastLocalUnnamedAddr
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

