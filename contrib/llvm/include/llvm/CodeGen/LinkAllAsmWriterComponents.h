begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Codegen/LinkAllAsmWriterComponents.h ----------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// This header file pulls in all assembler writer related passes for tools like
end_comment

begin_comment
comment|// llc that need this functionality.
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
name|LLVM_CODEGEN_LINKALLASMWRITERCOMPONENTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LINKALLASMWRITERCOMPONENTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GCs.h"
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
struct|struct
name|ForceAsmWriterLinking
block|{
name|ForceAsmWriterLinking
argument_list|()
block|{
comment|// We must reference the plug-ins in such a way that compilers will not
comment|// delete it all as dead code, even with whole program optimization,
comment|// yet is effectively a NO-OP. As the compiler isn't smart enough
comment|// to know that getenv() never returns -1, this will do the job.
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
name|llvm
operator|::
name|linkOcamlGCPrinter
argument_list|()
expr_stmt|;
block|}
block|}
name|ForceAsmWriterLinking
struct|;
comment|// Force link by creating a global definition.
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LINKALLASMWRITERCOMPONENTS_H
end_comment

end_unit

