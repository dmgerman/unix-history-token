begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCJIT.h - Class definition for the MCJIT ----------------*- C++ -*-===//
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
name|LLVM_LIB_EXECUTIONENGINE_MCJIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_MCJIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// FIXME: This makes all kinds of horrible assumptions for the time being,
comment|// like only having one module, not needing to worry about multi-threading,
comment|// blah blah. Purely in get-it-up-and-limping mode for now.
name|class
name|MCJIT
range|:
name|public
name|ExecutionEngine
block|{
name|MCJIT
argument_list|(
argument|Module *M
argument_list|,
argument|TargetMachine *tm
argument_list|,
argument|TargetJITInfo&tji
argument_list|,
argument|RTDyldMemoryManager *MemMgr
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool AllocateGVsWithCode
argument_list|)
block|;
name|TargetMachine
operator|*
name|TM
block|;
name|MCContext
operator|*
name|Ctx
block|;
name|RTDyldMemoryManager
operator|*
name|MemMgr
block|;
comment|// FIXME: These may need moved to a separate 'jitstate' member like the
comment|// non-MC JIT does for multithreading and such. Just keep them here for now.
name|PassManager
name|PM
block|;
name|Module
operator|*
name|M
block|;
comment|// FIXME: This really doesn't belong here.
name|SmallVector
operator|<
name|char
block|,
literal|4096
operator|>
name|Buffer
block|;
comment|// Working buffer into which we JIT.
name|raw_svector_ostream
name|OS
block|;
name|RuntimeDyld
name|Dyld
block|;
name|public
operator|:
operator|~
name|MCJIT
argument_list|()
block|;
comment|/// @name ExecutionEngine interface implementation
comment|/// @{
name|virtual
name|void
operator|*
name|getPointerToBasicBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|virtual
name|void
operator|*
name|getPointerToFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|virtual
name|void
operator|*
name|recompileAndRelinkFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|virtual
name|void
name|freeMachineCodeForFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|virtual
name|GenericValue
name|runFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|GenericValue
operator|>
operator|&
name|ArgValues
argument_list|)
block|;
comment|/// getPointerToNamedFunction - This method returns the address of the
comment|/// specified function by using the dlsym function call.  As such it is only
comment|/// useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function silently returns a null pointer. Otherwise,
comment|/// it prints a message to stderr and aborts.
comment|///
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|;
comment|/// @}
comment|/// @name (Private) Registration Interfaces
comment|/// @{
specifier|static
name|void
name|Register
argument_list|()
block|{
name|MCJITCtor
operator|=
name|createJIT
block|;   }
comment|// FIXME: This routine is scheduled for termination. Do not use it.
specifier|static
name|TargetMachine
operator|*
name|selectTarget
argument_list|(
argument|Module *M
argument_list|,
argument|StringRef MArch
argument_list|,
argument|StringRef MCPU
argument_list|,
argument|const SmallVectorImpl<std::string>& MAttrs
argument_list|,
argument|std::string *Err
argument_list|)
block|;
specifier|static
name|ExecutionEngine
operator|*
name|createJIT
argument_list|(
argument|Module *M
argument_list|,
argument|std::string *ErrorStr
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool GVsWithCode
argument_list|,
argument|CodeModel::Model CMM
argument_list|,
argument|StringRef MArch
argument_list|,
argument|StringRef MCPU
argument_list|,
argument|const SmallVectorImpl<std::string>& MAttrs
argument_list|)
block|;
comment|// @}
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

