begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86JITInfo.h - X86 implementation of the JIT interface  --*- C++ -*-===//
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
comment|// This file contains the X86 implementation of the TargetJITInfo class.
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
name|X86JITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86JITINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/JITCodeEmitter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetJITInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|X86TargetMachine
decl_stmt|;
name|class
name|X86Subtarget
decl_stmt|;
name|class
name|X86JITInfo
range|:
name|public
name|TargetJITInfo
block|{
name|X86TargetMachine
operator|&
name|TM
block|;
specifier|const
name|X86Subtarget
operator|*
name|Subtarget
block|;
name|uintptr_t
name|PICBase
block|;
name|char
operator|*
name|TLSOffset
block|;
name|public
operator|:
name|explicit
name|X86JITInfo
argument_list|(
name|X86TargetMachine
operator|&
name|tm
argument_list|)
block|;
comment|/// replaceMachineCodeForFunction - Make it so that calling the function
comment|/// whose machine code is at OLD turns into a call to NEW, perhaps by
comment|/// overwriting OLD with a branch to NEW.  This is used for self-modifying
comment|/// code.
comment|///
name|virtual
name|void
name|replaceMachineCodeForFunction
argument_list|(
name|void
operator|*
name|Old
argument_list|,
name|void
operator|*
name|New
argument_list|)
block|;
comment|/// emitGlobalValueIndirectSym - Use the specified JITCodeEmitter object
comment|/// to emit an indirect symbol which contains the address of the specified
comment|/// ptr.
name|virtual
name|void
operator|*
name|emitGlobalValueIndirectSym
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|void
operator|*
name|ptr
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|;
comment|/// emitFunctionStub - Use the specified JITCodeEmitter object to emit a
comment|/// small native function that simply calls the function at the specified
comment|/// address.
name|virtual
name|void
operator|*
name|emitFunctionStub
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|void
operator|*
name|Fn
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|;
comment|/// emitFunctionStubAtAddr - Use the specified JITCodeEmitter object to
comment|/// emit a small native function that simply calls Fn. Emit the stub into
comment|/// the supplied buffer.
name|virtual
name|void
name|emitFunctionStubAtAddr
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|void
operator|*
name|Fn
argument_list|,
name|void
operator|*
name|Buffer
argument_list|,
name|JITCodeEmitter
operator|&
name|JCE
argument_list|)
block|;
comment|/// getPICJumpTableEntry - Returns the value of the jumptable entry for the
comment|/// specific basic block.
name|virtual
name|uintptr_t
name|getPICJumpTableEntry
argument_list|(
argument|uintptr_t BB
argument_list|,
argument|uintptr_t JTBase
argument_list|)
block|;
comment|/// getLazyResolverFunction - Expose the lazy resolver to the JIT.
name|virtual
name|LazyResolverFn
name|getLazyResolverFunction
argument_list|(
name|JITCompilerFn
argument_list|)
block|;
comment|/// relocate - Before the JIT can run a block of code that has been emitted,
comment|/// it must rewrite the code to contain the actual addresses of any
comment|/// referenced global symbols.
name|virtual
name|void
name|relocate
argument_list|(
argument|void *Function
argument_list|,
argument|MachineRelocation *MR
argument_list|,
argument|unsigned NumRelocs
argument_list|,
argument|unsigned char* GOTBase
argument_list|)
block|;
comment|/// allocateThreadLocalMemory - Each target has its own way of
comment|/// handling thread local variables. This method returns a value only
comment|/// meaningful to the target.
name|virtual
name|char
operator|*
name|allocateThreadLocalMemory
argument_list|(
argument|size_t size
argument_list|)
block|;
comment|/// setPICBase / getPICBase - Getter / setter of PICBase, used to compute
comment|/// PIC jumptable entry.
name|void
name|setPICBase
argument_list|(
argument|uintptr_t Base
argument_list|)
block|{
name|PICBase
operator|=
name|Base
block|; }
name|uintptr_t
name|getPICBase
argument_list|()
specifier|const
block|{
return|return
name|PICBase
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

