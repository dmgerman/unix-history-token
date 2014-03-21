begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SparcJITInfo.h - Sparc Implementation of the JIT Interface -*- C++ -*-==//
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
comment|// This file contains the declaration of the SparcJITInfo class.
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
name|SPARCJITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SPARCJITINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineConstantPool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
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
name|SparcTargetMachine
decl_stmt|;
name|class
name|SparcJITInfo
range|:
name|public
name|TargetJITInfo
block|{
name|bool
name|IsPIC
block|;
name|public
operator|:
name|explicit
name|SparcJITInfo
argument_list|()
operator|:
name|IsPIC
argument_list|(
argument|false
argument_list|)
block|{}
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
comment|// getStubLayout - Returns the size and alignment of the largest call stub
comment|// on Sparc.
name|virtual
name|StubLayout
name|getStubLayout
argument_list|()
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
argument|unsigned char *GOTBase
argument_list|)
block|;
comment|/// Initialize - Initialize internal stage for the function being JITted.
name|void
name|Initialize
argument_list|(
argument|const MachineFunction&MF
argument_list|,
argument|bool isPIC
argument_list|)
block|{
name|IsPIC
operator|=
name|isPIC
block|;   }
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

