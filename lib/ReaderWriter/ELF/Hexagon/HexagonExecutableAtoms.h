begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/Hexagon/HexagonExecutableAtoms.h --------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_EXECUTABLE_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_EXECUTABLE_ATOM_H
end_define

begin_include
include|#
directive|include
file|"ELFFile.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
typedef|typedef
name|llvm
operator|::
name|object
operator|::
name|ELFType
operator|<
name|llvm
operator|::
name|support
operator|::
name|little
operator|,
literal|2
operator|,
name|false
operator|>
name|HexagonELFType
expr_stmt|;
name|class
name|HexagonLinkingContext
decl_stmt|;
name|template
operator|<
name|class
name|HexagonELFType
operator|>
name|class
name|HexagonRuntimeFile
operator|:
name|public
name|RuntimeFile
operator|<
name|HexagonELFType
operator|>
block|{
name|public
operator|:
name|HexagonRuntimeFile
argument_list|(
name|HexagonLinkingContext
operator|&
name|context
argument_list|)
operator|:
name|RuntimeFile
operator|<
name|HexagonELFType
operator|>
operator|(
name|context
operator|,
literal|"Hexagon runtime file"
operator|)
block|{}
block|}
expr_stmt|;
block|}
comment|// elf
block|}
end_decl_stmt

begin_comment
comment|// lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_EXECUTABLE_ATOM_H
end_comment

end_unit

