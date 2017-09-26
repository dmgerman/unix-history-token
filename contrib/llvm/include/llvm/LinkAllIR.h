begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- LinkAllIR.h - Reference All VMCore Code --------------*- C++ -*-===//
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
comment|// This header file pulls in all the object modules of the VMCore library so
end_comment

begin_comment
comment|// that tools like llc, opt, and lli can ensure they are linked with all symbols
end_comment

begin_comment
comment|// from libVMCore.a It should only be used from a tool's main program.
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
name|LLVM_LINKALLIR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKALLIR_H
end_define

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Verifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DynamicLibrary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Process.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Program.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Signals.h"
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
name|ForceVMCoreLinking
block|{
name|ForceVMCoreLinking
argument_list|()
block|{
comment|// We must reference VMCore in such a way that compilers will not
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
name|LLVMContext
name|Context
expr_stmt|;
operator|(
name|void
operator|)
name|new
name|llvm
operator|::
name|Module
argument_list|(
literal|""
argument_list|,
name|Context
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|new
name|llvm
operator|::
name|UnreachableInst
argument_list|(
name|Context
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createVerifierPass
argument_list|()
expr_stmt|;
block|}
block|}
name|ForceVMCoreLinking
struct|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

