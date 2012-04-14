begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CompilationDatabase.h - --------------------------------*- C++ -*-===//
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
comment|//  This file provides an interface and multiple implementations for
end_comment

begin_comment
comment|//  CompilationDatabases.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  While C++ refactoring and analysis tools are not compilers, and thus
end_comment

begin_comment
comment|//  don't run as part of the build system, they need the exact information
end_comment

begin_comment
comment|//  of a build in order to be able to correctly understand the C++ code of
end_comment

begin_comment
comment|//  the project. This information is provided via the CompilationDatabase
end_comment

begin_comment
comment|//  interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  To create a CompilationDatabase from a build directory one can call
end_comment

begin_comment
comment|//  CompilationDatabase::loadFromDirectory(), which deduces the correct
end_comment

begin_comment
comment|//  compilation database from the root of the build tree.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  See the concrete subclasses of CompilationDatabase for currently supported
end_comment

begin_comment
comment|//  formats.
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
name|LLVM_CLANG_TOOLING_COMPILATION_DATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_COMPILATION_DATABASE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// \brief Specifies the working directory and command of a compilation.
struct|struct
name|CompileCommand
block|{
name|CompileCommand
argument_list|()
block|{}
name|CompileCommand
argument_list|(
argument|StringRef Directory
argument_list|,
argument|ArrayRef<std::string> CommandLine
argument_list|)
block|:
name|Directory
argument_list|(
name|Directory
argument_list|)
operator|,
name|CommandLine
argument_list|(
argument|CommandLine
argument_list|)
block|{}
comment|/// \brief The working directory the command was executed from.
name|std
operator|::
name|string
name|Directory
expr_stmt|;
comment|/// \brief The command line that was executed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CommandLine
expr_stmt|;
block|}
struct|;
comment|/// \brief Interface for compilation databases.
comment|///
comment|/// A compilation database allows the user to retrieve all compile command lines
comment|/// that a specified file is compiled with in a project.
comment|/// The retrieved compile command lines can be used to run clang tools over
comment|/// a subset of the files in a project.
name|class
name|CompilationDatabase
block|{
name|public
label|:
name|virtual
operator|~
name|CompilationDatabase
argument_list|()
expr_stmt|;
comment|/// \brief Loads a compilation database from a build directory.
comment|///
comment|/// Looks at the specified 'BuildDirectory' and creates a compilation database
comment|/// that allows to query compile commands for source files in the
comment|/// corresponding source tree.
comment|///
comment|/// Returns NULL and sets ErrorMessage if we were not able to build up a
comment|/// compilation database for the build directory.
comment|///
comment|/// FIXME: Currently only supports JSON compilation databases, which
comment|/// are named 'compile_commands.json' in the given directory. Extend this
comment|/// for other build types (like ninja build files).
specifier|static
name|CompilationDatabase
modifier|*
name|loadFromDirectory
argument_list|(
name|StringRef
name|BuildDirectory
argument_list|,
name|std
operator|::
name|string
operator|&
name|ErrorMessage
argument_list|)
decl_stmt|;
comment|/// \brief Returns all compile commands in which the specified file was
comment|/// compiled.
comment|///
comment|/// This includes compile comamnds that span multiple source files.
comment|/// For example, consider a project with the following compilations:
comment|/// $ clang++ -o test a.cc b.cc t.cc
comment|/// $ clang++ -o production a.cc b.cc -DPRODUCTION
comment|/// A compilation database representing the project would return both command
comment|/// lines for a.cc and b.cc and only the first command line for t.cc.
name|virtual
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
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
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
name|virtual
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
argument|Database
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
comment|// Tuple (directory, commandline) where 'commandline' is a JSON escaped bash
comment|// escaped command line.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|StringRef
operator|>
name|CompileCommandRef
expr_stmt|;
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
block|>
name|IndexByFile
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Database
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
comment|// LLVM_CLANG_TOOLING_COMPILATION_DATABASE_H
end_comment

end_unit

