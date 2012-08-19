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
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|comments
block|{
comment|/// This class provides informaiton about commands that can be used
comment|/// in comments.
name|class
name|CommandTraits
block|{
name|public
label|:
name|CommandTraits
argument_list|()
block|{ }
comment|/// \brief Check if a given command is a verbatim-like block command.
comment|///
comment|/// A verbatim-like block command eats every character (except line starting
comment|/// decorations) until matching end command is seen or comment end is hit.
comment|///
comment|/// \param StartName name of the command that starts the verbatim block.
comment|/// \param [out] EndName name of the command that ends the verbatim block.
comment|///
comment|/// \returns true if a given command is a verbatim block command.
name|bool
name|isVerbatimBlockCommand
argument_list|(
name|StringRef
name|StartName
argument_list|,
name|StringRef
operator|&
name|EndName
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Register a new verbatim block command.
name|void
name|addVerbatimBlockCommand
parameter_list|(
name|StringRef
name|StartName
parameter_list|,
name|StringRef
name|EndName
parameter_list|)
function_decl|;
comment|/// \brief Check if a given command is a verbatim line command.
comment|///
comment|/// A verbatim-like line command eats everything until a newline is seen or
comment|/// comment end is hit.
name|bool
name|isVerbatimLineCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is a command that contains a declaration
comment|/// for the entity being documented.
comment|///
comment|/// For example:
comment|/// \code
comment|///   \fn void f(int a);
comment|/// \endcode
name|bool
name|isDeclarationCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Register a new verbatim line command.
name|void
name|addVerbatimLineCommand
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// \brief Check if a given command is a block command (of any kind).
name|bool
name|isBlockCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is introducing documentation for
comment|/// a function parameter (\\param or an alias).
name|bool
name|isParamCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is introducing documentation for
comment|/// a template parameter (\\tparam or an alias).
name|bool
name|isTParamCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is introducing a brief documentation
comment|/// paragraph (\\brief or an alias).
name|bool
name|isBriefCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is \\brief or an alias.
name|bool
name|isReturnsCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \returns the number of word-like arguments for a given block command,
comment|/// except for \\param and \\tparam commands -- these have special argument
comment|/// parsers.
name|unsigned
name|getBlockCommandNumArgs
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Check if a given command is a inline command (of any kind).
name|bool
name|isInlineCommand
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
struct|struct
name|VerbatimBlockCommand
block|{
name|StringRef
name|StartName
decl_stmt|;
name|StringRef
name|EndName
decl_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|VerbatimBlockCommand
operator|,
literal|4
operator|>
name|VerbatimBlockCommandVector
expr_stmt|;
comment|/// Registered additional verbatim-like block commands.
name|VerbatimBlockCommandVector
name|VerbatimBlockCommands
decl_stmt|;
struct|struct
name|VerbatimLineCommand
block|{
name|StringRef
name|Name
decl_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|VerbatimLineCommand
operator|,
literal|4
operator|>
name|VerbatimLineCommandVector
expr_stmt|;
comment|/// Registered verbatim-like line commands.
name|VerbatimLineCommandVector
name|VerbatimLineCommands
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isBlockCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|isBriefCommand
argument_list|(
name|Name
argument_list|)
operator|||
name|isReturnsCommand
argument_list|(
name|Name
argument_list|)
operator|||
name|isParamCommand
argument_list|(
name|Name
argument_list|)
operator|||
name|isTParamCommand
argument_list|(
name|Name
argument_list|)
operator|||
name|llvm
operator|::
name|StringSwitch
operator|<
name|bool
operator|>
operator|(
name|Name
operator|)
operator|.
name|Case
argument_list|(
literal|"author"
argument_list|,
name|true
argument_list|)
operator|.
name|Case
argument_list|(
literal|"authors"
argument_list|,
name|true
argument_list|)
operator|.
name|Case
argument_list|(
literal|"pre"
argument_list|,
name|true
argument_list|)
operator|.
name|Case
argument_list|(
literal|"post"
argument_list|,
name|true
argument_list|)
operator|.
name|Default
argument_list|(
name|false
argument_list|)
return|;
block|}
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isParamCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|Name
operator|==
literal|"param"
return|;
block|}
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isTParamCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|Name
operator|==
literal|"tparam"
operator|||
comment|// Doxygen
name|Name
operator|==
literal|"templatefield"
return|;
comment|// HeaderDoc
block|}
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isBriefCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|Name
operator|==
literal|"brief"
operator|||
name|Name
operator|==
literal|"short"
return|;
block|}
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isReturnsCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|Name
operator|==
literal|"returns"
operator|||
name|Name
operator|==
literal|"return"
operator|||
name|Name
operator|==
literal|"result"
return|;
block|}
specifier|inline
name|unsigned
name|CommandTraits
operator|::
name|getBlockCommandNumArgs
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
specifier|inline
name|bool
name|CommandTraits
operator|::
name|isInlineCommand
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|StringSwitch
operator|<
name|bool
operator|>
operator|(
name|Name
operator|)
operator|.
name|Case
argument_list|(
literal|"b"
argument_list|,
name|true
argument_list|)
operator|.
name|Cases
argument_list|(
literal|"c"
argument_list|,
literal|"p"
argument_list|,
name|true
argument_list|)
operator|.
name|Cases
argument_list|(
literal|"a"
argument_list|,
literal|"e"
argument_list|,
literal|"em"
argument_list|,
name|true
argument_list|)
operator|.
name|Default
argument_list|(
name|false
argument_list|)
return|;
block|}
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

