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
file|"lld/Core/Reproduce.h"
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
argument_list|,
name|bool
name|CanExitEarly
argument_list|)
decl_stmt|;
name|void
name|addFile
parameter_list|(
name|StringRef
name|Path
parameter_list|,
name|bool
name|WithLOption
parameter_list|)
function_decl|;
name|void
name|addLibrary
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
name|private
label|:
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
name|void
name|inferMachineType
parameter_list|()
function_decl|;
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
name|InWholeArchive
init|=
name|false
decl_stmt|;
comment|// True if we are in --start-lib and --end-lib.
name|bool
name|InLib
init|=
name|false
decl_stmt|;
comment|// True if we are in -format=binary and -format=elf.
name|bool
name|InBinary
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|InputFile
operator|*
operator|>
name|Files
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
parameter_list|,
name|_12
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
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|findFromSearchPaths
argument_list|(
argument|StringRef Path
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|searchLibrary
argument_list|(
argument|StringRef Path
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

