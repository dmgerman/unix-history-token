begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PPCJITInfo.h - PowerPC impl. of the JIT interface --------*- C++ -*-===//
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
comment|// This file contains the PowerPC implementation of the TargetJITInfo class.
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
name|POWERPC_JITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC_JITINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetJITInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/JITCodeEmitter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCTargetMachine
decl_stmt|;
name|class
name|PPCJITInfo
range|:
name|public
name|TargetJITInfo
block|{
name|protected
operator|:
name|PPCTargetMachine
operator|&
name|TM
block|;
name|bool
name|is64Bit
block|;
name|public
operator|:
name|PPCJITInfo
argument_list|(
argument|PPCTargetMachine&tm
argument_list|,
argument|bool tmIs64Bit
argument_list|)
operator|:
name|TM
argument_list|(
argument|tm
argument_list|)
block|{
name|useGOT
operator|=
literal|0
block|;
name|is64Bit
operator|=
name|tmIs64Bit
block|;     }
name|virtual
name|StubLayout
name|getStubLayout
argument_list|()
block|;
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
name|virtual
name|LazyResolverFn
name|getLazyResolverFunction
argument_list|(
name|JITCompilerFn
argument_list|)
block|;
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
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

