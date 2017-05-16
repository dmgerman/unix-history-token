begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Writer.h -------------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_WRITER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|InputFile
decl_stmt|;
name|class
name|OutputSection
decl_stmt|;
name|class
name|InputSectionBase
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|ObjectFile
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|SymbolTable
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|writeResult
argument_list|()
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|markLive
argument_list|()
expr_stmt|;
name|bool
name|isRelroSection
parameter_list|(
specifier|const
name|OutputSection
modifier|*
name|Sec
parameter_list|)
function_decl|;
comment|// This describes a program header entry.
comment|// Each contains type, access flags and range of output sections that will be
comment|// placed in it.
struct|struct
name|PhdrEntry
block|{
name|PhdrEntry
argument_list|(
argument|unsigned Type
argument_list|,
argument|unsigned Flags
argument_list|)
empty_stmt|;
name|void
name|add
parameter_list|(
name|OutputSection
modifier|*
name|Sec
parameter_list|)
function_decl|;
name|uint64_t
name|p_paddr
init|=
literal|0
decl_stmt|;
name|uint64_t
name|p_vaddr
init|=
literal|0
decl_stmt|;
name|uint64_t
name|p_memsz
init|=
literal|0
decl_stmt|;
name|uint64_t
name|p_filesz
init|=
literal|0
decl_stmt|;
name|uint64_t
name|p_offset
init|=
literal|0
decl_stmt|;
name|uint32_t
name|p_align
init|=
literal|0
decl_stmt|;
name|uint32_t
name|p_type
init|=
literal|0
decl_stmt|;
name|uint32_t
name|p_flags
init|=
literal|0
decl_stmt|;
name|OutputSection
modifier|*
name|First
init|=
name|nullptr
decl_stmt|;
name|OutputSection
modifier|*
name|Last
init|=
name|nullptr
decl_stmt|;
name|bool
name|HasLMA
init|=
name|false
decl_stmt|;
block|}
struct|;
name|llvm
operator|::
name|StringRef
name|getOutputSectionName
argument_list|(
argument|llvm::StringRef Name
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|uint32_t
name|getMipsEFlags
argument_list|()
expr_stmt|;
name|uint8_t
name|getMipsFpAbiFlag
argument_list|(
name|uint8_t
name|OldFlag
argument_list|,
name|uint8_t
name|NewFlag
argument_list|,
name|llvm
operator|::
name|StringRef
name|FileName
argument_list|)
decl_stmt|;
name|bool
name|isMipsN32Abi
parameter_list|(
specifier|const
name|InputFile
modifier|*
name|F
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

