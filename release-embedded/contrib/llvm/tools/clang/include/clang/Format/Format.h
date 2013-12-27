begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Format.h - Format C++ code -----------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// Various functions to configurably format source code.
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
name|LLVM_CLANG_FORMAT_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FORMAT_FORMAT_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Refactoring.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Lexer
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|DiagnosticConsumer
decl_stmt|;
name|namespace
name|format
block|{
comment|/// \brief The \c FormatStyle is used to configure the formatting to follow
comment|/// specific guidelines.
struct|struct
name|FormatStyle
block|{
comment|/// \brief The column limit.
name|unsigned
name|ColumnLimit
decl_stmt|;
comment|/// \brief The penalty for each character outside of the column limit.
name|unsigned
name|PenaltyExcessCharacter
decl_stmt|;
comment|/// \brief The maximum number of consecutive empty lines to keep.
name|unsigned
name|MaxEmptyLinesToKeep
decl_stmt|;
comment|/// \brief Set whether& and * bind to the type as opposed to the variable.
name|bool
name|PointerBindsToType
decl_stmt|;
comment|/// \brief If \c true, analyze the formatted file for the most common binding.
name|bool
name|DerivePointerBinding
decl_stmt|;
comment|/// \brief The extra indent or outdent of access modifiers (e.g.: public:).
name|int
name|AccessModifierOffset
decl_stmt|;
enum|enum
name|LanguageStandard
block|{
name|LS_Cpp03
block|,
name|LS_Cpp11
block|,
name|LS_Auto
block|}
enum|;
comment|/// \brief Format compatible with this standard, e.g. use \c A<A<int>>
comment|/// instead of \c A<A<int>> for LS_Cpp03.
name|LanguageStandard
name|Standard
decl_stmt|;
comment|/// \brief Indent case labels one level from the switch statement.
comment|///
comment|/// When false, use the same indentation level as for the switch statement.
comment|/// Switch statement body is always indented one level more than case labels.
name|bool
name|IndentCaseLabels
decl_stmt|;
comment|/// \brief The number of spaces to before trailing line comments.
name|unsigned
name|SpacesBeforeTrailingComments
decl_stmt|;
comment|/// \brief If false, a function call's or function definition's parameters
comment|/// will either all be on the same line or will have one line each.
name|bool
name|BinPackParameters
decl_stmt|;
comment|/// \brief Allow putting all parameters of a function declaration onto
comment|/// the next line even if \c BinPackParameters is \c false.
name|bool
name|AllowAllParametersOfDeclarationOnNextLine
decl_stmt|;
comment|/// \brief Penalty for putting the return type of a function onto its own
comment|/// line.
name|unsigned
name|PenaltyReturnTypeOnItsOwnLine
decl_stmt|;
comment|/// \brief If the constructor initializers don't fit on a line, put each
comment|/// initializer on its own line.
name|bool
name|ConstructorInitializerAllOnOneLineOrOnePerLine
decl_stmt|;
comment|/// \brief If true, "if (a) return;" can be put on a single line.
name|bool
name|AllowShortIfStatementsOnASingleLine
decl_stmt|;
comment|/// \brief Add a space in front of an Objective-C protocol list, i.e. use
comment|/// Foo<Protocol> instead of Foo<Protocol>.
name|bool
name|ObjCSpaceBeforeProtocolList
decl_stmt|;
comment|/// \brief If \c true, aligns escaped newlines as far left as possible.
comment|/// Otherwise puts them into the right-most column.
name|bool
name|AlignEscapedNewlinesLeft
decl_stmt|;
block|}
struct|;
comment|/// \brief Returns a format style complying with the LLVM coding standards:
comment|/// http://llvm.org/docs/CodingStandards.html.
name|FormatStyle
name|getLLVMStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with Google's C++ style guide:
comment|/// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml.
name|FormatStyle
name|getGoogleStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with Chromium's style guide:
comment|/// http://www.chromium.org/developers/coding-style.
name|FormatStyle
name|getChromiumStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with Mozilla's style guide:
comment|/// https://developer.mozilla.org/en-US/docs/Developer_Guide/Coding_Style.
name|FormatStyle
name|getMozillaStyle
parameter_list|()
function_decl|;
comment|/// \brief Reformats the given \p Ranges in the token stream coming out of
comment|/// \c Lex.
comment|///
comment|/// Each range is extended on either end to its next bigger logic unit, i.e.
comment|/// everything that might influence its formatting or might be influenced by its
comment|/// formatting.
comment|///
comment|/// \param DiagClient A custom DiagnosticConsumer. Can be 0, in this case
comment|/// diagnostic is output to llvm::errs().
comment|///
comment|/// Returns the \c Replacements necessary to make all \p Ranges comply with
comment|/// \p Style.
name|tooling
operator|::
name|Replacements
name|reformat
argument_list|(
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|,
name|Lexer
operator|&
name|Lex
argument_list|,
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|std
operator|::
name|vector
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|,
name|DiagnosticConsumer
operator|*
name|DiagClient
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// \brief Returns the \c LangOpts that the formatter expects you to set.
name|LangOptions
name|getFormattingLangOpts
parameter_list|()
function_decl|;
block|}
comment|// end namespace format
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
comment|// LLVM_CLANG_FORMAT_FORMAT_H
end_comment

end_unit

