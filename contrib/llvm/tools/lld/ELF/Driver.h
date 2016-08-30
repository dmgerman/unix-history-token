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
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/ArgList.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
specifier|extern
name|class
name|LinkerDriver
modifier|*
name|Driver
decl_stmt|;
name|class
name|CpioFile
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
name|addFile
parameter_list|(
name|StringRef
name|Path
parameter_list|)
function_decl|;
name|void
name|addLibrary
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|llvm
operator|::
name|LLVMContext
name|Context
expr_stmt|;
comment|// to parse bitcode ifles
name|std
operator|::
name|unique_ptr
operator|<
name|CpioFile
operator|>
name|Cpio
expr_stmt|;
comment|// for reproduce
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|MemoryBufferRef
operator|>
name|getArchiveMembers
argument_list|(
argument|MemoryBufferRef MB
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|MemoryBufferRef
operator|>
name|readFile
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
name|void
name|readConfigs
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
comment|// True if we are in --whole-archive and --no-whole-archive.
name|bool
name|WholeArchive
init|=
name|false
decl_stmt|;
comment|// True if we are in --start-lib and --end-lib.
name|bool
name|InLib
init|=
name|false
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
expr_stmt|;
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
name|class
name|ELFOptTable
range|:
name|public
name|llvm
operator|::
name|opt
operator|::
name|OptTable
block|{
name|public
operator|:
name|ELFOptTable
argument_list|()
block|;
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
name|parse
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Argv
argument_list|)
block|;
name|private
operator|:
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
block|; }
decl_stmt|;
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
file|"ELF/Options.inc"
undef|#
directive|undef
name|OPTION
block|}
enum|;
comment|// This is the class to create a .cpio file for --reproduce.
comment|//
comment|// If "--reproduce foo" is given, we create a file "foo.cpio" and
comment|// copy all input files to the archive, along with a response file
comment|// to re-run the same command with the same inputs.
comment|// It is useful for reporting issues to LLD developers.
comment|//
comment|// Cpio as a file format is a deliberate choice. It's standardized in
comment|// POSIX and very easy to create. cpio command is available virtually
comment|// on all Unix systems. See
comment|// http://pubs.opengroup.org/onlinepubs/9699919799/utilities/pax.html#tag_20_92_13_07
comment|// for the format details.
name|class
name|CpioFile
block|{
name|public
label|:
specifier|static
name|CpioFile
modifier|*
name|create
parameter_list|(
name|StringRef
name|OutputPath
parameter_list|)
function_decl|;
name|void
name|append
parameter_list|(
name|StringRef
name|Path
parameter_list|,
name|StringRef
name|Data
parameter_list|)
function_decl|;
name|private
label|:
name|CpioFile
argument_list|(
argument|std::unique_ptr<llvm::raw_fd_ostream> OS
argument_list|,
argument|StringRef Basename
argument_list|)
empty_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|raw_fd_ostream
operator|>
name|OS
expr_stmt|;
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|Seen
expr_stmt|;
name|std
operator|::
name|string
name|Basename
expr_stmt|;
block|}
empty_stmt|;
name|void
name|printHelp
parameter_list|(
specifier|const
name|char
modifier|*
name|Argv0
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|getVersionString
argument_list|()
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|parseHexstring
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|createResponseFile
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|InputArgList
operator|&
name|Args
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|relativeToRoot
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
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

