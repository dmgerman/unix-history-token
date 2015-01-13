begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- JSONCompilationDatabase.h - ----------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
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
comment|//  The JSONCompilationDatabase finds compilation databases supplied as a file
end_comment

begin_comment
comment|//  'compile_commands.json'.
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
name|LLVM_CLANG_TOOLING_JSON_COMPILATION_DATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_JSON_COMPILATION_DATABASE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/CompilationDatabase.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/FileMatchTrie.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLParser.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// \brief A JSON based compilation database.
comment|///
comment|/// JSON compilation database files must contain a list of JSON objects which
comment|/// provide the command lines in the attributes 'directory', 'command' and
comment|/// 'file':
comment|/// [
comment|///   { "directory": "<working directory of the compile>",
comment|///     "command": "<compile command line>",
comment|///     "file": "<path to source file>"
comment|///   },
comment|///   ...
comment|/// ]
comment|/// Each object entry defines one compile action. The specified file is
comment|/// considered to be the main source file for the translation unit.
comment|///
comment|/// JSON compilation databases can for example be generated in CMake projects
comment|/// by setting the flag -DCMAKE_EXPORT_COMPILE_COMMANDS.
name|class
name|JSONCompilationDatabase
range|:
name|public
name|CompilationDatabase
block|{
name|public
operator|:
comment|/// \brief Loads a JSON compilation database from the specified file.
comment|///
comment|/// Returns NULL and sets ErrorMessage if the database could not be
comment|/// loaded from the given file.
specifier|static
name|JSONCompilationDatabase
operator|*
name|loadFromFile
argument_list|(
argument|StringRef FilePath
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
block|;
comment|/// \brief Loads a JSON compilation database from a data buffer.
comment|///
comment|/// Returns NULL and sets ErrorMessage if the database could not be loaded.
specifier|static
name|JSONCompilationDatabase
operator|*
name|loadFromBuffer
argument_list|(
argument|StringRef DatabaseString
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
block|;
comment|/// \brief Returns all compile comamnds in which the specified file was
comment|/// compiled.
comment|///
comment|/// FIXME: Currently FilePath must be an absolute path inside the
comment|/// source directory which does not have symlinks resolved.
name|std
operator|::
name|vector
operator|<
name|CompileCommand
operator|>
name|getCompileCommands
argument_list|(
argument|StringRef FilePath
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Returns the list of all files available in the compilation database.
comment|///
comment|/// These are the 'file' entries of the JSON objects.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getAllFiles
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Returns all compile commands for all the files in the compilation
comment|/// database.
name|std
operator|::
name|vector
operator|<
name|CompileCommand
operator|>
name|getAllCompileCommands
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
comment|/// \brief Constructs a JSON compilation database on a memory buffer.
name|JSONCompilationDatabase
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Database
argument_list|)
operator|:
name|Database
argument_list|(
name|Database
argument_list|)
block|,
name|YAMLStream
argument_list|(
argument|Database->getBuffer()
argument_list|,
argument|SM
argument_list|)
block|{}
comment|/// \brief Parses the database file and creates the index.
comment|///
comment|/// Returns whether parsing succeeded. Sets ErrorMessage if parsing
comment|/// failed.
name|bool
name|parse
argument_list|(
name|std
operator|::
name|string
operator|&
name|ErrorMessage
argument_list|)
block|;
comment|// Tuple (directory, commandline) where 'commandline' pointing to the
comment|// corresponding nodes in the YAML stream.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|yaml
operator|::
name|ScalarNode
operator|*
operator|,
name|llvm
operator|::
name|yaml
operator|::
name|ScalarNode
operator|*
operator|>
name|CompileCommandRef
expr_stmt|;
comment|/// \brief Converts the given array of CompileCommandRefs to CompileCommands.
name|void
name|getCommands
argument_list|(
argument|ArrayRef<CompileCommandRef> CommandsRef
argument_list|,
argument|std::vector<CompileCommand>&Commands
argument_list|)
specifier|const
decl_stmt|;
comment|// Maps file paths to the compile command lines for that file.
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|vector
operator|<
name|CompileCommandRef
operator|>
expr|>
name|IndexByFile
expr_stmt|;
name|FileMatchTrie
name|MatchTrie
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Database
expr_stmt|;
name|llvm
operator|::
name|SourceMgr
name|SM
expr_stmt|;
name|llvm
operator|::
name|yaml
operator|::
name|Stream
name|YAMLStream
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace tooling
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_JSON_COMPILATION_DATABASE_H
end_comment

end_unit

