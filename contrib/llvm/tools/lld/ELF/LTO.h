begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LTO.h ----------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|// This file provides a way to combine bitcode files into one ELF
end_comment

begin_comment
comment|// file by compiling them using LLVM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If LTO is in use, your input files are not in regular ELF files
end_comment

begin_comment
comment|// but instead LLVM bitcode files. In that case, the linker has to
end_comment

begin_comment
comment|// convert bitcode files into the native format so that we can create
end_comment

begin_comment
comment|// an ELF file that contains native code. This file provides that
end_comment

begin_comment
comment|// functionality.
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
name|LLD_ELF_LTO_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_LTO_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Linker/IRMover.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|BitcodeFile
decl_stmt|;
name|class
name|InputFile
decl_stmt|;
name|class
name|BitcodeCompiler
block|{
name|public
label|:
name|BitcodeCompiler
argument_list|()
expr_stmt|;
name|void
name|add
parameter_list|(
name|BitcodeFile
modifier|&
name|F
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>>
name|compile
argument_list|()
expr_stmt|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>>
name|runSplitCodegen
argument_list|(
specifier|const
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|TargetMachine
operator|>
operator|(
operator|)
operator|>
operator|&
name|TMFactory
argument_list|)
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Module
operator|>
name|Combined
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SmallString
operator|<
literal|0
operator|>>
name|OwningData
expr_stmt|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|InternalizedSyms
expr_stmt|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|AsmUndefinedRefs
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

