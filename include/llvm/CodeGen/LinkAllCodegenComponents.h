begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Codegen/LinkAllCodegenComponents.h ------------------*- C++ -*-===//
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
comment|// This header file pulls in all codegen related passes for tools like lli and
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
name|LLVM_CODEGEN_LINKALLCODEGENCOMPONENTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LINKALLCODEGENCOMPONENTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SchedulerRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GCs.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
struct|struct
name|ForceCodegenLinking
block|{
name|ForceCodegenLinking
argument_list|()
block|{
comment|// We must reference the passes in such a way that compilers will not
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
operator|(
name|void
operator|)
name|llvm
operator|::
name|createDeadMachineInstructionElimPass
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createLocalRegisterAllocator
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createLinearScanRegisterAllocator
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createPBQPRegisterAllocator
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createSimpleRegisterCoalescer
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|linkOcamlGC
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|linkShadowStackGC
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createBURRListDAGScheduler
argument_list|(
name|NULL
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Default
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createTDRRListDAGScheduler
argument_list|(
name|NULL
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Default
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createTDListDAGScheduler
argument_list|(
name|NULL
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Default
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createFastDAGScheduler
argument_list|(
name|NULL
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Default
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|llvm
operator|::
name|createDefaultScheduler
argument_list|(
name|NULL
argument_list|,
name|llvm
operator|::
name|CodeGenOpt
operator|::
name|Default
argument_list|)
expr_stmt|;
block|}
block|}
name|ForceCodegenLinking
struct|;
comment|// Force link by creating a global definition.
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

