begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/CoreLinkingContext.h ------------------------------===//
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
name|LLD_READER_WRITER_CORE_LINKER_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_CORE_LINKER_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LinkingContext.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reader.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Writer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|CoreLinkingContext
range|:
name|public
name|LinkingContext
block|{
name|public
operator|:
name|CoreLinkingContext
argument_list|()
block|;    enum
block|{
name|TEST_RELOC_CALL32
operator|=
literal|1
block|,
name|TEST_RELOC_PCREL32
operator|=
literal|2
block|,
name|TEST_RELOC_GOT_LOAD32
operator|=
literal|3
block|,
name|TEST_RELOC_GOT_USE32
operator|=
literal|4
block|,
name|TEST_RELOC_LEA32_WAS_GOT
operator|=
literal|5
block|,   }
block|;
name|bool
name|validateImpl
argument_list|(
argument|raw_ostream&diagnostics
argument_list|)
name|override
block|;
name|void
name|addPasses
argument_list|(
argument|PassManager&pm
argument_list|)
name|override
block|;
name|void
name|addPassNamed
argument_list|(
argument|StringRef name
argument_list|)
block|{
name|_passNames
operator|.
name|push_back
argument_list|(
name|name
argument_list|)
block|; }
name|protected
operator|:
name|Writer
operator|&
name|writer
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|Writer
operator|>
name|_writer
block|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|_passNames
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

