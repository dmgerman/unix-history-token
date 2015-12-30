begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompileUtils.h - Utilities for compiling IR in the JIT --*- C++ -*-===//
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
comment|// Contains utilities for compiling IR to object files.
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
name|LLVM_EXECUTIONENGINE_ORC_COMPILEUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_COMPILEUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectMemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LegacyPassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Simple compile functor: Takes a single IR module and returns an
comment|///        ObjectFile.
name|class
name|SimpleCompiler
block|{
name|public
label|:
comment|/// @brief Construct a simple compile functor with the given target.
name|SimpleCompiler
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|)
operator|:
name|TM
argument_list|(
argument|TM
argument_list|)
block|{}
comment|/// @brief Compile a Module to an ObjectFile.
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|operator
argument_list|()
operator|(
name|Module
operator|&
name|M
operator|)
specifier|const
block|{
name|SmallVector
operator|<
name|char
block|,
literal|0
operator|>
name|ObjBufferSV
block|;
name|raw_svector_ostream
name|ObjStream
argument_list|(
name|ObjBufferSV
argument_list|)
block|;
name|legacy
operator|::
name|PassManager
name|PM
block|;
name|MCContext
operator|*
name|Ctx
block|;
if|if
condition|(
name|TM
operator|.
name|addPassesToEmitMC
argument_list|(
name|PM
argument_list|,
name|Ctx
argument_list|,
name|ObjStream
argument_list|)
condition|)
name|llvm_unreachable
argument_list|(
literal|"Target does not support MC emission."
argument_list|)
expr_stmt|;
name|PM
operator|.
name|run
argument_list|(
name|M
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|ObjBuffer
argument_list|(
argument|new ObjectMemoryBuffer(std::move(ObjBufferSV))
argument_list|)
expr_stmt|;
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>>
name|Obj
operator|=
name|object
operator|::
name|ObjectFile
operator|::
name|createObjectFile
argument_list|(
name|ObjBuffer
operator|->
name|getMemBufferRef
argument_list|()
argument_list|)
expr_stmt|;
comment|// TODO: Actually report errors helpfully.
typedef|typedef
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|OwningObj
expr_stmt|;
if|if
condition|(
name|Obj
condition|)
return|return
name|OwningObj
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|Obj
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|ObjBuffer
argument_list|)
argument_list|)
return|;
return|return
name|OwningObj
argument_list|(
name|nullptr
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
name|private
label|:
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace orc.
end_comment

begin_comment
unit|}
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_COMPILEUTILS_H
end_comment

end_unit

