begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/ELF/MipsELFFlagsMerger.h --------------------------===//
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
name|LLD_READER_WRITER_ELF_MIPS_MIPS_ELF_FLAGS_MERGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_ELF_MIPS_MIPS_ELF_FLAGS_MERGER_H
end_define

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|MipsELFFlagsMerger
block|{
name|public
label|:
name|MipsELFFlagsMerger
argument_list|(
argument|bool is64Bits
argument_list|)
empty_stmt|;
name|uint32_t
name|getMergedELFFlags
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Merge saved ELF header flags and the new set of flags.
name|std
operator|::
name|error_code
name|merge
argument_list|(
argument|uint8_t newClass
argument_list|,
argument|uint32_t newFlags
argument_list|)
expr_stmt|;
name|private
label|:
specifier|const
name|bool
name|_is64Bit
decl_stmt|;
name|std
operator|::
name|mutex
name|_mutex
expr_stmt|;
name|uint32_t
name|_flags
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

