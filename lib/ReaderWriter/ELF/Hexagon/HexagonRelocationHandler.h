begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/ELF/Hexagon/HexagonRelocationHandler.h -----------===//
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
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_RELOCATION_HANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_HEXAGON_HEXAGON_RELOCATION_HANDLER_H
end_define

begin_include
include|#
directive|include
file|"lld/ReaderWriter/ELFLinkingContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|HexagonTargetHandler
decl_stmt|;
name|class
name|HexagonTargetLayout
decl_stmt|;
name|class
name|HexagonTargetRelocationHandler
name|final
range|:
name|public
name|TargetRelocationHandler
block|{
name|public
operator|:
name|HexagonTargetRelocationHandler
argument_list|(
name|HexagonTargetLayout
operator|&
name|layout
argument_list|)
operator|:
name|_targetLayout
argument_list|(
argument|layout
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|applyRelocation
argument_list|(
argument|ELFWriter&
argument_list|,
argument|llvm::FileOutputBuffer&
argument_list|,
argument|const AtomLayout&
argument_list|,
argument|const Reference&
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|HexagonTargetLayout
operator|&
name|_targetLayout
block|; }
decl_stmt|;
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

end_unit

