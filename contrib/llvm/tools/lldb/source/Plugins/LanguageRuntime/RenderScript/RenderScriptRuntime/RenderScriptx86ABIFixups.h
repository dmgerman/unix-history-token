begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RenderScriptx86ABIFixups.h ------------------------------*- C++ -*-===//
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
name|LLDB_RENDERSCRIPT_X86_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_RENDERSCRIPT_X86_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|lldb_renderscript
block|{
name|bool
name|fixupX86FunctionCalls
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|module
argument_list|)
decl_stmt|;
name|bool
name|fixupX86_64FunctionCalls
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|module
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

