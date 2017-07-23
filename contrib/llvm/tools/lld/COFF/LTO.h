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
comment|// This file provides a way to combine bitcode files into one COFF
end_comment

begin_comment
comment|// file by compiling them using LLVM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If LTO is in use, your input files are not in regular COFF files
end_comment

begin_comment
comment|// but instead LLVM bitcode files. In that case, the linker has to
end_comment

begin_comment
comment|// convert bitcode files into the native format so that we can create
end_comment

begin_comment
comment|// a COFF file that contains native code. This file provides that
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
name|LLD_COFF_LTO_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_COFF_LTO_H
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|lto
block|{
name|class
name|LTO
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|coff
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
operator|~
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
name|StringRef
operator|>
name|compile
argument_list|()
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|lto
operator|::
name|LTO
operator|>
name|LTOObj
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SmallString
operator|<
literal|0
operator|>>
name|Buff
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

