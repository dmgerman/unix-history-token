begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LinkAllVMCore.h - Reference All VMCore Code --------------*- C++ -*-===//
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
name|LLVM_LINKALLVMCORE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKALLVMCORE_H
end_define

begin_include
include|#
directive|include
file|"llvm/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IntrinsicInst.h"
end_include

begin_include
include|#
directive|include
file|"llvm/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Verifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Alarm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DynamicLibrary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Memory.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Process.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Program.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Signals.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Mangler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SlowOperationInformer.h"
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
name|Module
operator|*
name|M
operator|=
name|new
name|llvm
operator|::
name|Module
argument_list|(
literal|""
argument_list|,
name|llvm
operator|::
name|getGlobalContext
argument_list|()
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
name|llvm
operator|::
name|getGlobalContext
argument_list|()
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
operator|(
name|void
operator|)
name|new
name|llvm
operator|::
name|Mangler
argument_list|(
operator|*
name|M
argument_list|,
literal|""
argument_list|)
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

