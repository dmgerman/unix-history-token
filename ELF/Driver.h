begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Driver.h -------------------------------------------------*- C++ -*-===//
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
name|LLD_ELF_DRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_DRIVER_H
end_define

begin_include
include|#
directive|include
file|"SymbolTable.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/ArgList.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf2
block|{
specifier|extern
name|class
name|LinkerDriver
modifier|*
name|Driver
decl_stmt|;
comment|// Entry point of the ELF linker.
name|void
name|link
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
name|class
name|LinkerDriver
block|{
name|public
label|:
name|void
decl|main
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
name|void
name|createFiles
argument_list|(
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|&
name|Args
argument_list|)
decl_stmt|;
name|template
operator|<
name|class
name|ELFT
operator|>
name|void
name|link
argument_list|(
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|&
name|Args
argument_list|)
expr_stmt|;
name|void
name|addFile
parameter_list|(
name|StringRef
name|Path
parameter_list|)
function_decl|;
name|private
label|:
name|template
operator|<
name|template
operator|<
name|class
operator|>
name|class
name|T
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
name|createELFInputFile
argument_list|(
argument|MemoryBufferRef MB
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
expr_stmt|;
name|bool
name|WholeArchive
init|=
name|false
decl_stmt|;
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
name|Files
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|OwningMBs
expr_stmt|;
block|}
empty_stmt|;
comment|// Parses command line options.
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
name|parseArgs
argument_list|(
name|llvm
operator|::
name|BumpPtrAllocator
operator|*
name|A
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|)
expr_stmt|;
comment|// Create enum with OPT_xxx values for each option in Options.td
enum|enum
block|{
name|OPT_INVALID
init|=
literal|0
block|,
define|#
directive|define
name|OPTION
parameter_list|(
name|_1
parameter_list|,
name|_2
parameter_list|,
name|ID
parameter_list|,
name|_4
parameter_list|,
name|_5
parameter_list|,
name|_6
parameter_list|,
name|_7
parameter_list|,
name|_8
parameter_list|,
name|_9
parameter_list|,
name|_10
parameter_list|,
name|_11
parameter_list|)
value|OPT_##ID,
include|#
directive|include
file|"Options.inc"
undef|#
directive|undef
name|OPTION
block|}
enum|;
comment|// Parses a linker script. Calling this function updates the Symtab and Config.
name|void
name|readLinkerScript
argument_list|(
name|llvm
operator|::
name|BumpPtrAllocator
operator|*
name|A
argument_list|,
name|MemoryBufferRef
name|MB
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|findFromSearchPaths
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|searchLibrary
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|buildSysrootedPath
argument_list|(
argument|llvm::StringRef Dir
argument_list|,
argument|llvm::StringRef File
argument_list|)
expr_stmt|;
block|}
comment|// namespace elf2
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

