begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AlphaJITInfo.h - Alpha impl. of the JIT interface ----*- C++ -*-===//
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
comment|// This file contains the Alpha implementation of the TargetJITInfo class.
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
name|ALPHA_JITINFO_H
end_ifndef

begin_define
define|#
directive|define
name|ALPHA_JITINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetJITInfo.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetMachine
decl_stmt|;
name|class
name|AlphaJITInfo
range|:
name|public
name|TargetJITInfo
block|{
name|protected
operator|:
name|TargetMachine
operator|&
name|TM
block|;
comment|//because gpdist are paired and relative to the pc of the first inst,
comment|//we need to have some state
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
block|,
name|int
operator|>
block|,
name|void
operator|*
operator|>
name|gpdistmap
block|;
name|public
operator|:
name|explicit
name|AlphaJITInfo
argument_list|(
name|TargetMachine
operator|&
name|tm
argument_list|)
operator|:
name|TM
argument_list|(
argument|tm
argument_list|)
block|{
name|useGOT
operator|=
name|true
block|; }
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
block|;
name|private
operator|:
specifier|static
specifier|const
name|unsigned
name|GOToffset
operator|=
literal|4096
block|;    }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

