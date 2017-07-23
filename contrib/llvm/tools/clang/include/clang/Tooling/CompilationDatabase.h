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
name|LLVM_CLANG_TOOLING_COMPILATIONDATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_COMPILATIONDATABASE_H
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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
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
comment|/// \brief Specifies the working directory and command of a compilation.
struct|struct
name|CompileCommand
block|{
name|CompileCommand
argument_list|()
block|{}
name|CompileCommand
argument_list|(
argument|Twine Directory
argument_list|,
argument|Twine Filename
argument_list|,
argument|std::vector<std::string> CommandLine
argument_list|,
argument|Twine Output
argument_list|)
block|:
name|Directory
argument_list|(
name|Directory
operator|.
name|str
argument_list|()
argument_list|)
operator|,
name|Filename
argument_list|(
name|Filename
operator|.
name|str
argument_list|()
argument_list|)
operator|,
name|CommandLine
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|CommandLine
argument_list|)
argument_list|)
operator|,
name|Output
argument_list|(
argument|Output.str()
argument_list|)
block|{}
comment|/// \brief The working directory the command was executed from.
name|std
operator|::
name|string
name|Directory
expr_stmt|;
comment|/// The source file associated with the command.
name|std
operator|::
name|string
name|Filename
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
comment|/// The output file associated with the command.
name|std
operator|::
name|string
name|Output
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
name|std
operator|::
name|unique_ptr
operator|<
name|CompilationDatabase
operator|>
name|loadFromDirectory
argument_list|(
argument|StringRef BuildDirectory
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
expr_stmt|;
comment|/// \brief Tries to detect a compilation database location and load it.
comment|///
comment|/// Looks for a compilation database in all parent paths of file 'SourceFile'
comment|/// by calling loadFromDirectory.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|CompilationDatabase
operator|>
name|autoDetectFromSource
argument_list|(
argument|StringRef SourceFile
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
expr_stmt|;
comment|/// \brief Tries to detect a compilation database location and load it.
comment|///
comment|/// Looks for a compilation database in directory 'SourceDir' and all
comment|/// its parent paths by calling loadFromDirectory.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|CompilationDatabase
operator|>
name|autoDetectFromDirectory
argument_list|(
argument|StringRef SourceDir
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
expr_stmt|;
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
comment|/// \brief Returns the list of all files available in the compilation database.
name|virtual
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
operator|=
literal|0
expr_stmt|;
comment|/// \brief Returns all compile commands for all the files in the compilation
comment|/// database.
comment|///
comment|/// FIXME: Add a layer in Tooling that provides an interface to run a tool
comment|/// over all files in a compilation database. Not all build systems have the
comment|/// ability to provide a feasible implementation for \c getAllCompileCommands.
name|virtual
name|std
operator|::
name|vector
operator|<
name|CompileCommand
operator|>
name|getAllCompileCommands
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Interface for compilation database plugins.
comment|///
comment|/// A compilation database plugin allows the user to register custom compilation
comment|/// databases that are picked up as compilation database if the corresponding
comment|/// library is linked in. To register a plugin, declare a static variable like:
comment|///
comment|/// \code
comment|/// static CompilationDatabasePluginRegistry::Add<MyDatabasePlugin>
comment|/// X("my-compilation-database", "Reads my own compilation database");
comment|/// \endcode
name|class
name|CompilationDatabasePlugin
block|{
name|public
label|:
name|virtual
operator|~
name|CompilationDatabasePlugin
argument_list|()
expr_stmt|;
comment|/// \brief Loads a compilation database from a build directory.
comment|///
comment|/// \see CompilationDatabase::loadFromDirectory().
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|CompilationDatabase
operator|>
name|loadFromDirectory
argument_list|(
argument|StringRef Directory
argument_list|,
argument|std::string&ErrorMessage
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief A compilation database that returns a single compile command line.
comment|///
comment|/// Useful when we want a tool to behave more like a compiler invocation.
name|class
name|FixedCompilationDatabase
range|:
name|public
name|CompilationDatabase
block|{
name|public
operator|:
comment|/// \brief Creates a FixedCompilationDatabase from the arguments after "--".
comment|///
comment|/// Parses the given command line for "--". If "--" is found, the rest of
comment|/// the arguments will make up the command line in the returned
comment|/// FixedCompilationDatabase.
comment|/// The arguments after "--" must not include positional parameters or the
comment|/// argv[0] of the tool. Those will be added by the FixedCompilationDatabase
comment|/// when a CompileCommand is requested. The argv[0] of the returned command
comment|/// line will be "clang-tool".
comment|///
comment|/// Returns NULL in case "--" is not found.
comment|///
comment|/// The argument list is meant to be compatible with normal llvm command line
comment|/// parsing in main methods.
comment|/// int main(int argc, char **argv) {
comment|///   std::unique_ptr<FixedCompilationDatabase> Compilations(
comment|///     FixedCompilationDatabase::loadFromCommandLine(argc, argv));
comment|///   cl::ParseCommandLineOptions(argc, argv);
comment|///   ...
comment|/// }
comment|///
comment|/// \param Argc The number of command line arguments - will be changed to
comment|/// the number of arguments before "--", if "--" was found in the argument
comment|/// list.
comment|/// \param Argv Points to the command line arguments.
comment|/// \param ErrorMsg Contains error text if the function returns null pointer.
comment|/// \param Directory The base directory used in the FixedCompilationDatabase.
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|FixedCompilationDatabase
operator|>
name|loadFromCommandLine
argument_list|(
argument|int&Argc
argument_list|,
argument|const char *const *Argv
argument_list|,
argument|std::string&ErrorMsg
argument_list|,
argument|Twine Directory =
literal|"."
argument_list|)
block|;
comment|/// \brief Constructs a compilation data base from a specified directory
comment|/// and command line.
name|FixedCompilationDatabase
argument_list|(
argument|Twine Directory
argument_list|,
argument|ArrayRef<std::string> CommandLine
argument_list|)
block|;
comment|/// \brief Returns the given compile command.
comment|///
comment|/// Will always return a vector with one entry that contains the directory
comment|/// and command line specified at construction with "clang-tool" as argv[0]
comment|/// and 'FilePath' as positional argument.
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
comment|/// Note: This is always an empty list for the fixed compilation database.
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
comment|///
comment|/// Note: This is always an empty list for the fixed compilation database.
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
comment|/// This is built up to contain a single entry vector to be returned from
comment|/// getCompileCommands after adding the positional argument.
name|std
operator|::
name|vector
operator|<
name|CompileCommand
operator|>
name|CompileCommands
block|; }
decl_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

