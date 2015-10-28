begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- OrcMCJITReplacement.h - Orc-based MCJIT replacement ---*- C++ -*-===//
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
comment|// This file forces OrcMCJITReplacement to link in on certain operating systems.
end_comment

begin_comment
comment|// (Windows).
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
name|LLVM_EXECUTIONENGINE_ORCMCJITREPLACEMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORCMCJITREPLACEMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_extern
extern|extern
literal|"C"
name|void
name|LLVMLinkInOrcMCJITReplacement
parameter_list|()
function_decl|;
end_extern

begin_macro
name|namespace
end_macro

begin_block
block|{
struct|struct
name|ForceOrcMCJITReplacementLinking
block|{
name|ForceOrcMCJITReplacementLinking
argument_list|()
block|{
comment|// We must reference OrcMCJITReplacement in such a way that compilers will
comment|// not delete it all as dead code, even with whole program optimization,
comment|// yet is effectively a NO-OP. As the compiler isn't smart enough to know
comment|// that getenv() never returns -1, this will do the job.
if|if
condition|(
name|std
operator|::
name|getenv
argument_list|(
literal|"bar"
argument_list|)
operator|!=
operator|(
name|char
operator|*
operator|)
operator|-
literal|1
condition|)
return|return;
name|LLVMLinkInOrcMCJITReplacement
argument_list|()
expr_stmt|;
block|}
block|}
name|ForceOrcMCJITReplacementLinking
struct|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

