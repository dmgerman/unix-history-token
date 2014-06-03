begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommentCommandTraits.h - Comment command properties ----*- C++ -*-===//
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
comment|//  This file defines the class that provides information about comment
end_comment

begin_comment
comment|//  commands.
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
name|LLVM_CLANG_AST_COMMENT_COMMAND_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_COMMENT_COMMAND_TRAITS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/CommentOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|comments
block|{
comment|/// \brief Information about a single command.
comment|///
comment|/// When reordering, adding or removing members please update the corresponding
comment|/// TableGen backend.
struct|struct
name|CommandInfo
block|{
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// Name of the command that ends the verbatim block.
specifier|const
name|char
modifier|*
name|EndCommandName
decl_stmt|;
name|unsigned
name|ID
range|:
literal|8
decl_stmt|;
comment|/// Number of word-like arguments for a given block command, except for
comment|/// \\param and \\tparam commands -- these have special argument parsers.
name|unsigned
name|NumArgs
range|:
literal|4
decl_stmt|;
comment|/// True if this command is a inline command (of any kind).
name|unsigned
name|IsInlineCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is a block command (of any kind).
name|unsigned
name|IsBlockCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is introducing a brief documentation
comment|/// paragraph (\\brief or an alias).
name|unsigned
name|IsBriefCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is \\returns or an alias.
name|unsigned
name|IsReturnsCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is introducing documentation for a function
comment|/// parameter (\\param or an alias).
name|unsigned
name|IsParamCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is introducing documentation for
comment|/// a template parameter (\\tparam or an alias).
name|unsigned
name|IsTParamCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is \\throws or an alias.
name|unsigned
name|IsThrowsCommand
range|:
literal|1
decl_stmt|;
comment|/// True if this command is \\deprecated or an alias.
name|unsigned
name|IsDeprecatedCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this is a \\headerfile-like command.
name|unsigned
name|IsHeaderfileCommand
range|:
literal|1
decl_stmt|;
comment|/// True if we don't want to warn about this command being passed an empty
comment|/// paragraph.  Meaningful only for block commands.
name|unsigned
name|IsEmptyParagraphAllowed
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this command is a verbatim-like block command.
comment|///
comment|/// A verbatim-like block command eats every character (except line starting
comment|/// decorations) until matching end command is seen or comment end is hit.
name|unsigned
name|IsVerbatimBlockCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this command is an end command for a verbatim-like block.
name|unsigned
name|IsVerbatimBlockEndCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this command is a verbatim line command.
comment|///
comment|/// A verbatim-like line command eats everything until a newline is seen or
comment|/// comment end is hit.
name|unsigned
name|IsVerbatimLineCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this command contains a declaration for the entity being
comment|/// documented.
comment|///
comment|/// For example:
comment|/// \code
comment|///   \fn void f(int a);
comment|/// \endcode
name|unsigned
name|IsDeclarationCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if verbatim-like line command is a function declaration.
name|unsigned
name|IsFunctionDeclarationCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if block command is further describing a container API; such
comment|/// as \@coclass, \@classdesign, etc.
name|unsigned
name|IsRecordLikeDetailCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if block command is a container API; such as \@interface.
name|unsigned
name|IsRecordLikeDeclarationCommand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this command is unknown.  This \c CommandInfo object was
comment|/// created during parsing.
name|unsigned
name|IsUnknownCommand
range|:
literal|1
decl_stmt|;
block|}
struct|;
comment|/// This class provides information about commands that can be used
comment|/// in comments.
name|class
name|CommandTraits
block|{
name|public
label|:
enum|enum
name|KnownCommandIDs
block|{
define|#
directive|define
name|COMMENT_COMMAND
parameter_list|(
name|NAME
parameter_list|)
value|KCI_##NAME,
include|#
directive|include
file|"clang/AST/CommentCommandList.inc"
undef|#
directive|undef
name|COMMENT_COMMAND
name|KCI_Last
block|}
enum|;
name|CommandTraits
argument_list|(
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Allocator
argument_list|,
specifier|const
name|CommentOptions
operator|&
name|CommentOptions
argument_list|)
expr_stmt|;
name|void
name|registerCommentOptions
parameter_list|(
specifier|const
name|CommentOptions
modifier|&
name|CommentOptions
parameter_list|)
function_decl|;
comment|/// \returns a CommandInfo object for a given command name or
comment|/// NULL if no CommandInfo object exists for this command.
specifier|const
name|CommandInfo
modifier|*
name|getCommandInfoOrNULL
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CommandInfo
modifier|*
name|getCommandInfo
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|CommandInfo
modifier|*
name|Info
init|=
name|getCommandInfoOrNULL
argument_list|(
name|Name
argument_list|)
condition|)
return|return
name|Info
return|;
name|llvm_unreachable
argument_list|(
literal|"the command should be known"
argument_list|)
expr_stmt|;
block|}
specifier|const
name|CommandInfo
modifier|*
name|getTypoCorrectCommandInfo
argument_list|(
name|StringRef
name|Typo
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CommandInfo
modifier|*
name|getCommandInfo
argument_list|(
name|unsigned
name|CommandID
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CommandInfo
modifier|*
name|registerUnknownCommand
parameter_list|(
name|StringRef
name|CommandName
parameter_list|)
function_decl|;
specifier|const
name|CommandInfo
modifier|*
name|registerBlockCommand
parameter_list|(
name|StringRef
name|CommandName
parameter_list|)
function_decl|;
comment|/// \returns a CommandInfo object for a given command name or
comment|/// NULL if \c Name is not a builtin command.
specifier|static
specifier|const
name|CommandInfo
modifier|*
name|getBuiltinCommandInfo
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \returns a CommandInfo object for a given command ID or
comment|/// NULL if \c CommandID is not a builtin command.
specifier|static
specifier|const
name|CommandInfo
modifier|*
name|getBuiltinCommandInfo
parameter_list|(
name|unsigned
name|CommandID
parameter_list|)
function_decl|;
name|private
label|:
name|CommandTraits
argument_list|(
argument|const CommandTraits&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CommandTraits
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
specifier|const
name|CommandInfo
modifier|*
name|getRegisteredCommandInfo
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CommandInfo
modifier|*
name|getRegisteredCommandInfo
argument_list|(
name|unsigned
name|CommandID
argument_list|)
decl|const
decl_stmt|;
name|CommandInfo
modifier|*
name|createCommandInfoWithName
parameter_list|(
name|StringRef
name|CommandName
parameter_list|)
function_decl|;
name|unsigned
name|NextID
decl_stmt|;
comment|/// Allocator for CommandInfo objects.
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Allocator
expr_stmt|;
name|SmallVector
operator|<
name|CommandInfo
operator|*
operator|,
literal|4
operator|>
name|RegisteredCommands
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace comments
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

