begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- JsonCompileCommandLineDatabase - Simple JSON database --*- C++ -*-===//
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
comment|//  This file implements reading a compile command line database, as written
end_comment

begin_comment
comment|//  out for example by CMake. It only supports the subset of the JSON standard
end_comment

begin_comment
comment|//  that is needed to parse the CMake output.
end_comment

begin_comment
comment|//  See http://www.json.org/ for the full standard.
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
name|LLVM_CLANG_TOOLING_JSON_COMPILE_COMMAND_LINE_DATABASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_JSON_COMPILE_COMMAND_LINE_DATABASE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
comment|/// \brief Converts a JSON escaped command line to a vector of arguments.
comment|///
comment|/// \param JsonEscapedCommandLine The escaped command line as a string. This
comment|/// is assumed to be escaped as a JSON string (e.g. " and \ are escaped).
comment|/// In addition, any arguments containing spaces are assumed to be \-escaped
comment|///
comment|/// For example, the input (|| denoting non C-escaped strings):
comment|///   |./call  a  \"b \\\" c \\\\ \"  d|
comment|/// would yield:
comment|///   [ |./call|, |a|, |b " c \ |, |d| ].
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|UnescapeJsonCommandLine
argument_list|(
argument|llvm::StringRef JsonEscapedCommandLine
argument_list|)
expr_stmt|;
comment|/// \brief Interface for users of the JsonCompileCommandLineParser.
name|class
name|CompileCommandHandler
block|{
name|public
label|:
name|virtual
operator|~
name|CompileCommandHandler
argument_list|()
block|{}
comment|/// \brief Called after all translation units are parsed.
name|virtual
name|void
name|EndTranslationUnits
argument_list|()
block|{}
comment|/// \brief Called at the end of a single translation unit.
name|virtual
name|void
name|EndTranslationUnit
argument_list|()
block|{}
comment|/// \brief Called for every (Key, Value) pair in a translation unit
comment|/// description.
name|virtual
name|void
name|HandleKeyValue
argument_list|(
argument|llvm::StringRef Key
argument_list|,
argument|llvm::StringRef Value
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief A JSON parser that supports the subset of JSON needed to parse
comment|/// JSON compile command line databases as written out by CMake.
comment|///
comment|/// The supported subset describes a list of compile command lines for
comment|/// each processed translation unit. The translation units are stored in a
comment|/// JSON array, where each translation unit is described by a JSON object
comment|/// containing (Key, Value) pairs for the working directory the compile command
comment|/// line was executed from, the main C/C++ input file of the translation unit
comment|/// and the actual compile command line, for example:
comment|/// [
comment|///   {
comment|///     "file":"/file.cpp",
comment|///     "directory":"/",
comment|///     "command":"/cc /file.cpp"
comment|///   }
comment|/// ]
name|class
name|JsonCompileCommandLineParser
block|{
name|public
label|:
comment|/// \brief Create a parser on 'Input', calling 'CommandHandler' to handle the
comment|/// parsed constructs. 'CommandHandler' may be NULL in order to just check
comment|/// the validity of 'Input'.
name|JsonCompileCommandLineParser
argument_list|(
argument|const llvm::StringRef Input
argument_list|,
argument|CompileCommandHandler *CommandHandler
argument_list|)
empty_stmt|;
comment|/// \brief Parses the specified input. Returns true if no parsing errors were
comment|/// foudn.
name|bool
name|Parse
parameter_list|()
function_decl|;
comment|/// \brief Returns an error message if Parse() returned false previously.
name|std
operator|::
name|string
name|GetErrorMessage
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|bool
name|ParseTranslationUnits
parameter_list|()
function_decl|;
name|bool
name|ParseTranslationUnit
parameter_list|(
name|bool
name|First
parameter_list|)
function_decl|;
name|bool
name|ParseObjectKeyValuePairs
parameter_list|()
function_decl|;
name|bool
name|ParseString
argument_list|(
name|llvm
operator|::
name|StringRef
operator|&
name|String
argument_list|)
decl_stmt|;
name|bool
name|Consume
parameter_list|(
name|char
name|C
parameter_list|)
function_decl|;
name|bool
name|ConsumeOrError
argument_list|(
name|char
name|C
argument_list|,
name|llvm
operator|::
name|StringRef
name|Message
argument_list|)
decl_stmt|;
name|void
name|NextNonWhitespace
parameter_list|()
function_decl|;
name|bool
name|IsWhitespace
parameter_list|()
function_decl|;
name|void
name|SetExpectError
argument_list|(
name|char
name|C
argument_list|,
name|llvm
operator|::
name|StringRef
name|Message
argument_list|)
decl_stmt|;
specifier|const
name|llvm
operator|::
name|StringRef
name|Input
expr_stmt|;
name|llvm
operator|::
name|StringRef
operator|::
name|iterator
name|Position
expr_stmt|;
name|std
operator|::
name|string
name|ErrorMessage
expr_stmt|;
name|CompileCommandHandler
modifier|*
specifier|const
name|CommandHandler
decl_stmt|;
block|}
empty_stmt|;
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

begin_comment
comment|// LLVM_CLANG_TOOLING_JSON_COMPILE_COMMAND_LINE_DATABASE_H
end_comment

end_unit

