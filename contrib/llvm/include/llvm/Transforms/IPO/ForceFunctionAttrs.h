begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ForceFunctionAttrs.h - Force function attrs for debugging ---------===//
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
comment|/// Super simple passes to force specific function attrs from the commandline
end_comment

begin_comment
comment|/// into the IR for debugging purposes.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_IPO_FORCEFUNCTIONATTRS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_IPO_FORCEFUNCTIONATTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Pass which forces specific function attributes into the IR, primarily as
comment|/// a debugging tool.
name|class
name|ForceFunctionAttrsPass
block|{
name|public
label|:
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"ForceFunctionAttrsPass"
return|;
block|}
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Create a legacy pass manager instance of a pass to force function attrs.
name|Pass
modifier|*
name|createForceFunctionAttrsLegacyPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_IPO_FORCEFUNCTIONATTRS_H
end_comment

end_unit

