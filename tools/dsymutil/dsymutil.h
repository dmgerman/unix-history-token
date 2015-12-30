begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- tools/dsymutil/dsymutil.h - dsymutil high-level functionality ------===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file contains the class declaration for the code that parses STABS
end_comment

begin_comment
comment|/// debug maps that are embedded in the binaries symbol tables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_define

begin_include
include|#
directive|include
file|"DebugMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dsymutil
block|{
struct|struct
name|LinkOptions
block|{
name|bool
name|Verbose
decl_stmt|;
comment|///< Verbosity
name|bool
name|NoOutput
decl_stmt|;
comment|///< Skip emitting output
name|bool
name|NoODR
decl_stmt|;
comment|///< Do not unique types according to ODR
name|std
operator|::
name|string
name|PrependPath
expr_stmt|;
comment|///< -oso-prepend-path
name|LinkOptions
argument_list|()
operator|:
name|Verbose
argument_list|(
name|false
argument_list|)
operator|,
name|NoOutput
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Extract the DebugMaps from the given file.
comment|/// The file has to be a MachO object file. Multiple debug maps can be
comment|/// returned when the file is universal (aka fat) binary.
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|DebugMap
operator|>>>
name|parseDebugMap
argument_list|(
argument|StringRef InputFile
argument_list|,
argument|ArrayRef<std::string> Archs
argument_list|,
argument|StringRef PrependPath
argument_list|,
argument|bool Verbose
argument_list|,
argument|bool InputIsYAML
argument_list|)
expr_stmt|;
comment|/// \brief Dump the symbol table
name|bool
name|dumpStab
argument_list|(
name|StringRef
name|InputFile
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|Archs
argument_list|,
name|StringRef
name|PrependPath
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// \brief Link the Dwarf debuginfo as directed by the passed DebugMap
comment|/// \p DM into a DwarfFile named \p OutputFilename.
comment|/// \returns false if the link failed.
name|bool
name|linkDwarf
parameter_list|(
name|StringRef
name|OutputFilename
parameter_list|,
specifier|const
name|DebugMap
modifier|&
name|DM
parameter_list|,
specifier|const
name|LinkOptions
modifier|&
name|Options
parameter_list|)
function_decl|;
comment|/// \brief Exit the dsymutil process, cleaning up every temporary
comment|/// files that we created.
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|exitDsymutil
parameter_list|(
name|int
name|ExitStatus
parameter_list|)
function_decl|;
name|void
name|warn
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Warning
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Context
parameter_list|)
function_decl|;
name|bool
name|error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Error
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Context
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_DSYMUTIL_DSYMUTIL_H
end_comment

end_unit

