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
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Core/Replacement.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
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
name|enum
name|class
name|ParseError
block|{
name|Success
operator|=
literal|0
operator|,
name|Error
operator|,
name|Unsuitable
block|}
empty_stmt|;
name|class
name|ParseErrorCategory
name|final
range|:
name|public
name|std
operator|::
name|error_category
block|{
name|public
operator|:
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
name|LLVM_NOEXCEPT
name|override
block|;
name|std
operator|::
name|string
name|message
argument_list|(
argument|int EV
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
specifier|const
name|std
operator|::
name|error_category
operator|&
name|getParseCategory
argument_list|()
expr_stmt|;
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|ParseError e
argument_list|)
expr_stmt|;
comment|/// \brief The \c FormatStyle is used to configure the formatting to follow
comment|/// specific guidelines.
struct|struct
name|FormatStyle
block|{
comment|/// \brief Supported languages. When stored in a configuration file, specifies
comment|/// the language, that the configuration targets. When passed to the
comment|/// reformat() function, enables syntax features specific to the language.
enum|enum
name|LanguageKind
block|{
comment|/// Do not use.
name|LK_None
block|,
comment|/// Should be used for C, C++, ObjectiveC, ObjectiveC++.
name|LK_Cpp
block|,
comment|/// Should be used for Java.
name|LK_Java
block|,
comment|/// Should be used for JavaScript.
name|LK_JavaScript
block|,
comment|/// Should be used for Protocol Buffers
comment|/// (https://developers.google.com/protocol-buffers/).
name|LK_Proto
block|}
enum|;
comment|/// \brief Language, this format style is targeted at.
name|LanguageKind
name|Language
decl_stmt|;
comment|/// \brief The column limit.
comment|///
comment|/// A column limit of \c 0 means that there is no column limit. In this case,
comment|/// clang-format will respect the input's line breaking decisions within
comment|/// statements unless they contradict other rules.
name|unsigned
name|ColumnLimit
decl_stmt|;
comment|/// \brief The maximum number of consecutive empty lines to keep.
name|unsigned
name|MaxEmptyLinesToKeep
decl_stmt|;
comment|/// \brief If true, empty lines at the start of blocks are kept.
name|bool
name|KeepEmptyLinesAtTheStartOfBlocks
decl_stmt|;
comment|/// \brief The penalty for each line break introduced inside a comment.
name|unsigned
name|PenaltyBreakComment
decl_stmt|;
comment|/// \brief The penalty for each line break introduced inside a string literal.
name|unsigned
name|PenaltyBreakString
decl_stmt|;
comment|/// \brief The penalty for each character outside of the column limit.
name|unsigned
name|PenaltyExcessCharacter
decl_stmt|;
comment|/// \brief The penalty for breaking before the first \c<<.
name|unsigned
name|PenaltyBreakFirstLessLess
decl_stmt|;
comment|/// \brief The penalty for breaking a function call after "call(".
name|unsigned
name|PenaltyBreakBeforeFirstCallParameter
decl_stmt|;
comment|/// \brief The& and * alignment style.
enum|enum
name|PointerAlignmentStyle
block|{
comment|/// Align pointer to the left.
name|PAS_Left
block|,
comment|/// Align pointer to the right.
name|PAS_Right
block|,
comment|/// Align pointer in the middle.
name|PAS_Middle
block|}
enum|;
comment|/// Pointer and reference alignment style.
name|PointerAlignmentStyle
name|PointerAlignment
decl_stmt|;
comment|/// \brief If \c true, analyze the formatted file for the most common
comment|/// alignment of& and *. \c PointerAlignment is then used only as fallback.
name|bool
name|DerivePointerAlignment
decl_stmt|;
comment|/// \brief The extra indent or outdent of access modifiers, e.g. \c public:.
name|int
name|AccessModifierOffset
decl_stmt|;
comment|/// \brief Supported language standards.
enum|enum
name|LanguageStandard
block|{
comment|/// Use C++03-compatible syntax.
name|LS_Cpp03
block|,
comment|/// Use features of C++11 (e.g. \c A<A<int>> instead of
comment|///<tt>A<A<int>></tt>).
name|LS_Cpp11
block|,
comment|/// Automatic detection based on the input.
name|LS_Auto
block|}
enum|;
comment|/// \brief Format compatible with this standard, e.g. use
comment|///<tt>A<A<int>></tt> instead of \c A<A<int>> for LS_Cpp03.
name|LanguageStandard
name|Standard
decl_stmt|;
comment|/// \brief Indent case labels one level from the switch statement.
comment|///
comment|/// When \c false, use the same indentation level as for the switch statement.
comment|/// Switch statement body is always indented one level more than case labels.
name|bool
name|IndentCaseLabels
decl_stmt|;
comment|/// \brief Indent if a function definition or declaration is wrapped after the
comment|/// type.
name|bool
name|IndentWrappedFunctionNames
decl_stmt|;
comment|/// \brief Different ways to indent namespace contents.
enum|enum
name|NamespaceIndentationKind
block|{
comment|/// Don't indent in namespaces.
name|NI_None
block|,
comment|/// Indent only in inner namespaces (nested in other namespaces).
name|NI_Inner
block|,
comment|/// Indent in all namespaces.
name|NI_All
block|}
enum|;
comment|/// \brief The indentation used for namespaces.
name|NamespaceIndentationKind
name|NamespaceIndentation
decl_stmt|;
comment|/// \brief The number of spaces before trailing line comments
comment|/// (\c // - comments).
comment|///
comment|/// This does not affect trailing block comments (\c /**/ - comments) as those
comment|/// commonly have different usage patterns and a number of special cases.
name|unsigned
name|SpacesBeforeTrailingComments
decl_stmt|;
comment|/// \brief If \c false, a function declaration's or function definition's
comment|/// parameters will either all be on the same line or will have one line each.
name|bool
name|BinPackParameters
decl_stmt|;
comment|/// \brief If \c false, a function call's arguments will either be all on the
comment|/// same line or will have one line each.
name|bool
name|BinPackArguments
decl_stmt|;
comment|/// \brief If \c true, clang-format detects whether function calls and
comment|/// definitions are formatted with one parameter per line.
comment|///
comment|/// Each call can be bin-packed, one-per-line or inconclusive. If it is
comment|/// inconclusive, e.g. completely on one line, but a decision needs to be
comment|/// made, clang-format analyzes whether there are other bin-packed cases in
comment|/// the input file and act accordingly.
comment|///
comment|/// NOTE: This is an experimental flag, that might go away or be renamed. Do
comment|/// not use this in config files, etc. Use at your own risk.
name|bool
name|ExperimentalAutoDetectBinPacking
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
comment|/// \brief Always break constructor initializers before commas and align
comment|/// the commas with the colon.
name|bool
name|BreakConstructorInitializersBeforeComma
decl_stmt|;
comment|/// \brief Allows contracting simple braced statements to a single line.
comment|///
comment|/// E.g., this allows<tt>if (a) { return; }</tt> to be put on a single line.
name|bool
name|AllowShortBlocksOnASingleLine
decl_stmt|;
comment|/// \brief If \c true,<tt>if (a) return;</tt> can be put on a single
comment|/// line.
name|bool
name|AllowShortIfStatementsOnASingleLine
decl_stmt|;
comment|/// \brief If \c true,<tt>while (true) continue;</tt> can be put on a
comment|/// single line.
name|bool
name|AllowShortLoopsOnASingleLine
decl_stmt|;
comment|/// \brief If \c true, short case labels will be contracted to a single line.
name|bool
name|AllowShortCaseLabelsOnASingleLine
decl_stmt|;
comment|/// \brief Different styles for merging short functions containing at most one
comment|/// statement.
enum|enum
name|ShortFunctionStyle
block|{
comment|/// \brief Never merge functions into a single line.
name|SFS_None
block|,
comment|/// \brief Only merge functions defined inside a class.
name|SFS_Inline
block|,
comment|/// \brief Only merge empty functions.
name|SFS_Empty
block|,
comment|/// \brief Merge all functions fitting on a single line.
name|SFS_All
block|,   }
enum|;
comment|/// \brief Dependent on the value,<tt>int f() { return 0; }</tt> can be put
comment|/// on a single line.
name|ShortFunctionStyle
name|AllowShortFunctionsOnASingleLine
decl_stmt|;
comment|/// \brief Add a space after \c @property in Objective-C, i.e. use
comment|///<tt>\@property (readonly)</tt> instead of<tt>\@property(readonly)</tt>.
name|bool
name|ObjCSpaceAfterProperty
decl_stmt|;
comment|/// \brief Add a space in front of an Objective-C protocol list, i.e. use
comment|///<tt>Foo<Protocol></tt> instead of \c Foo<Protocol>.
name|bool
name|ObjCSpaceBeforeProtocolList
decl_stmt|;
comment|/// \brief If \c true, horizontally aligns arguments after an open bracket.
comment|///
comment|/// This applies to round brackets (parentheses), angle brackets and square
comment|/// brackets. This will result in formattings like
comment|/// \code
comment|/// someLongFunction(argument1,
comment|///                  argument2);
comment|/// \endcode
name|bool
name|AlignAfterOpenBracket
decl_stmt|;
comment|/// \brief If \c true, horizontally align operands of binary and ternary
comment|/// expressions.
name|bool
name|AlignOperands
decl_stmt|;
comment|/// \brief If \c true, aligns trailing comments.
name|bool
name|AlignTrailingComments
decl_stmt|;
comment|/// \brief If \c true, aligns escaped newlines as far left as possible.
comment|/// Otherwise puts them into the right-most column.
name|bool
name|AlignEscapedNewlinesLeft
decl_stmt|;
comment|/// \brief The number of columns to use for indentation.
name|unsigned
name|IndentWidth
decl_stmt|;
comment|/// \brief The number of columns used for tab stops.
name|unsigned
name|TabWidth
decl_stmt|;
comment|/// \brief The number of characters to use for indentation of constructor
comment|/// initializer lists.
name|unsigned
name|ConstructorInitializerIndentWidth
decl_stmt|;
comment|/// \brief The number of characters to use for indentation of ObjC blocks.
name|unsigned
name|ObjCBlockIndentWidth
decl_stmt|;
comment|/// \brief If \c true, always break after function definition return types.
comment|///
comment|/// More truthfully called 'break before the identifier following the type
comment|/// in a function definition'. PenaltyReturnTypeOnItsOwnLine becomes
comment|/// irrelevant.
name|bool
name|AlwaysBreakAfterDefinitionReturnType
decl_stmt|;
comment|/// \brief If \c true, always break after the<tt>template<...></tt> of a
comment|/// template declaration.
name|bool
name|AlwaysBreakTemplateDeclarations
decl_stmt|;
comment|/// \brief If \c true, always break before multiline string literals.
name|bool
name|AlwaysBreakBeforeMultilineStrings
decl_stmt|;
comment|/// \brief Different ways to use tab in formatting.
enum|enum
name|UseTabStyle
block|{
comment|/// Never use tab.
name|UT_Never
block|,
comment|/// Use tabs only for indentation.
name|UT_ForIndentation
block|,
comment|/// Use tabs whenever we need to fill whitespace that spans at least from
comment|/// one tab stop to the next one.
name|UT_Always
block|}
enum|;
comment|/// \brief The way to use tab characters in the resulting file.
name|UseTabStyle
name|UseTab
decl_stmt|;
comment|/// \brief The style of breaking before or after binary operators.
enum|enum
name|BinaryOperatorStyle
block|{
comment|/// Break after operators.
name|BOS_None
block|,
comment|/// Break before operators that aren't assignments.
name|BOS_NonAssignment
block|,
comment|/// Break before operators.
name|BOS_All
block|,   }
enum|;
comment|/// \brief The way to wrap binary operators.
name|BinaryOperatorStyle
name|BreakBeforeBinaryOperators
decl_stmt|;
comment|/// \brief If \c true, ternary operators will be placed after line breaks.
name|bool
name|BreakBeforeTernaryOperators
decl_stmt|;
comment|/// \brief Different ways to attach braces to their surrounding context.
enum|enum
name|BraceBreakingStyle
block|{
comment|/// Always attach braces to surrounding context.
name|BS_Attach
block|,
comment|/// Like \c Attach, but break before braces on function, namespace and
comment|/// class definitions.
name|BS_Linux
block|,
comment|/// Like \c Attach, but break before function definitions, and 'else'.
name|BS_Stroustrup
block|,
comment|/// Always break before braces.
name|BS_Allman
block|,
comment|/// Always break before braces and add an extra level of indentation to
comment|/// braces of control statements, not to those of class, function
comment|/// or other definitions.
name|BS_GNU
block|}
enum|;
comment|/// \brief The brace breaking style to use.
name|BraceBreakingStyle
name|BreakBeforeBraces
decl_stmt|;
comment|/// \brief If \c true, format braced lists as best suited for C++11 braced
comment|/// lists.
comment|///
comment|/// Important differences:
comment|/// - No spaces inside the braced list.
comment|/// - No line break before the closing brace.
comment|/// - Indentation with the continuation indent, not with the block indent.
comment|///
comment|/// Fundamentally, C++11 braced lists are formatted exactly like function
comment|/// calls would be formatted in their place. If the braced list follows a name
comment|/// (e.g. a type or variable name), clang-format formats as if the \c {} were
comment|/// the parentheses of a function call with that name. If there is no name,
comment|/// a zero-length name is assumed.
name|bool
name|Cpp11BracedListStyle
decl_stmt|;
comment|/// \brief If \c true, spaces will be inserted after '(' and before ')'.
name|bool
name|SpacesInParentheses
decl_stmt|;
comment|/// \brief If \c true, spaces will be inserted after '<' and before '>' in
comment|/// template argument lists
name|bool
name|SpacesInAngles
decl_stmt|;
comment|/// \brief If \c true, spaces will be inserted after '[' and before ']'.
name|bool
name|SpacesInSquareBrackets
decl_stmt|;
comment|/// \brief If \c true, spaces may be inserted into '()'.
name|bool
name|SpaceInEmptyParentheses
decl_stmt|;
comment|/// \brief If \c true, spaces are inserted inside container literals (e.g.
comment|/// ObjC and Javascript array and dict literals).
name|bool
name|SpacesInContainerLiterals
decl_stmt|;
comment|/// \brief If \c true, spaces may be inserted into C style casts.
name|bool
name|SpacesInCStyleCastParentheses
decl_stmt|;
comment|/// \brief If \c true, a space may be inserted after C style casts.
name|bool
name|SpaceAfterCStyleCast
decl_stmt|;
comment|/// \brief Different ways to put a space before opening parentheses.
enum|enum
name|SpaceBeforeParensOptions
block|{
comment|/// Never put a space before opening parentheses.
name|SBPO_Never
block|,
comment|/// Put a space before opening parentheses only after control statement
comment|/// keywords (<tt>for/if/while...</tt>).
name|SBPO_ControlStatements
block|,
comment|/// Always put a space before opening parentheses, except when it's
comment|/// prohibited by the syntax rules (in function-like macro definitions) or
comment|/// when determined by other style rules (after unary operators, opening
comment|/// parentheses, etc.)
name|SBPO_Always
block|}
enum|;
comment|/// \brief Defines in which cases to put a space before opening parentheses.
name|SpaceBeforeParensOptions
name|SpaceBeforeParens
decl_stmt|;
comment|/// \brief If \c false, spaces will be removed before assignment operators.
name|bool
name|SpaceBeforeAssignmentOperators
decl_stmt|;
comment|/// \brief Indent width for line continuations.
name|unsigned
name|ContinuationIndentWidth
decl_stmt|;
comment|/// \brief A regular expression that describes comments with special meaning,
comment|/// which should not be split into lines or otherwise changed.
name|std
operator|::
name|string
name|CommentPragmas
expr_stmt|;
comment|/// \brief Disables formatting at all.
name|bool
name|DisableFormat
decl_stmt|;
comment|/// \brief A vector of macros that should be interpreted as foreach loops
comment|/// instead of as function calls.
comment|///
comment|/// These are expected to be macros of the form:
comment|/// \code
comment|/// FOREACH(<variable-declaration>, ...)
comment|///<loop-body>
comment|/// \endcode
comment|///
comment|/// For example: BOOST_FOREACH.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ForEachMacros
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FormatStyle
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|AccessModifierOffset
operator|==
name|R
operator|.
name|AccessModifierOffset
operator|&&
name|AlignAfterOpenBracket
operator|==
name|R
operator|.
name|AlignAfterOpenBracket
operator|&&
name|AlignOperands
operator|==
name|R
operator|.
name|AlignOperands
operator|&&
name|AlignEscapedNewlinesLeft
operator|==
name|R
operator|.
name|AlignEscapedNewlinesLeft
operator|&&
name|AlignTrailingComments
operator|==
name|R
operator|.
name|AlignTrailingComments
operator|&&
name|AllowAllParametersOfDeclarationOnNextLine
operator|==
name|R
operator|.
name|AllowAllParametersOfDeclarationOnNextLine
operator|&&
name|AllowShortFunctionsOnASingleLine
operator|==
name|R
operator|.
name|AllowShortFunctionsOnASingleLine
operator|&&
name|AllowShortBlocksOnASingleLine
operator|==
name|R
operator|.
name|AllowShortBlocksOnASingleLine
operator|&&
name|AllowShortIfStatementsOnASingleLine
operator|==
name|R
operator|.
name|AllowShortIfStatementsOnASingleLine
operator|&&
name|AllowShortLoopsOnASingleLine
operator|==
name|R
operator|.
name|AllowShortLoopsOnASingleLine
operator|&&
name|AlwaysBreakAfterDefinitionReturnType
operator|==
name|R
operator|.
name|AlwaysBreakAfterDefinitionReturnType
operator|&&
name|AlwaysBreakTemplateDeclarations
operator|==
name|R
operator|.
name|AlwaysBreakTemplateDeclarations
operator|&&
name|AlwaysBreakBeforeMultilineStrings
operator|==
name|R
operator|.
name|AlwaysBreakBeforeMultilineStrings
operator|&&
name|BinPackParameters
operator|==
name|R
operator|.
name|BinPackParameters
operator|&&
name|BinPackArguments
operator|==
name|R
operator|.
name|BinPackArguments
operator|&&
name|BreakBeforeBinaryOperators
operator|==
name|R
operator|.
name|BreakBeforeBinaryOperators
operator|&&
name|BreakBeforeTernaryOperators
operator|==
name|R
operator|.
name|BreakBeforeTernaryOperators
operator|&&
name|BreakBeforeBraces
operator|==
name|R
operator|.
name|BreakBeforeBraces
operator|&&
name|BreakConstructorInitializersBeforeComma
operator|==
name|R
operator|.
name|BreakConstructorInitializersBeforeComma
operator|&&
name|ColumnLimit
operator|==
name|R
operator|.
name|ColumnLimit
operator|&&
name|ConstructorInitializerAllOnOneLineOrOnePerLine
operator|==
name|R
operator|.
name|ConstructorInitializerAllOnOneLineOrOnePerLine
operator|&&
name|ConstructorInitializerIndentWidth
operator|==
name|R
operator|.
name|ConstructorInitializerIndentWidth
operator|&&
name|DerivePointerAlignment
operator|==
name|R
operator|.
name|DerivePointerAlignment
operator|&&
name|ExperimentalAutoDetectBinPacking
operator|==
name|R
operator|.
name|ExperimentalAutoDetectBinPacking
operator|&&
name|IndentCaseLabels
operator|==
name|R
operator|.
name|IndentCaseLabels
operator|&&
name|IndentWrappedFunctionNames
operator|==
name|R
operator|.
name|IndentWrappedFunctionNames
operator|&&
name|IndentWidth
operator|==
name|R
operator|.
name|IndentWidth
operator|&&
name|Language
operator|==
name|R
operator|.
name|Language
operator|&&
name|MaxEmptyLinesToKeep
operator|==
name|R
operator|.
name|MaxEmptyLinesToKeep
operator|&&
name|KeepEmptyLinesAtTheStartOfBlocks
operator|==
name|R
operator|.
name|KeepEmptyLinesAtTheStartOfBlocks
operator|&&
name|NamespaceIndentation
operator|==
name|R
operator|.
name|NamespaceIndentation
operator|&&
name|ObjCBlockIndentWidth
operator|==
name|R
operator|.
name|ObjCBlockIndentWidth
operator|&&
name|ObjCSpaceAfterProperty
operator|==
name|R
operator|.
name|ObjCSpaceAfterProperty
operator|&&
name|ObjCSpaceBeforeProtocolList
operator|==
name|R
operator|.
name|ObjCSpaceBeforeProtocolList
operator|&&
name|PenaltyBreakComment
operator|==
name|R
operator|.
name|PenaltyBreakComment
operator|&&
name|PenaltyBreakFirstLessLess
operator|==
name|R
operator|.
name|PenaltyBreakFirstLessLess
operator|&&
name|PenaltyBreakString
operator|==
name|R
operator|.
name|PenaltyBreakString
operator|&&
name|PenaltyExcessCharacter
operator|==
name|R
operator|.
name|PenaltyExcessCharacter
operator|&&
name|PenaltyReturnTypeOnItsOwnLine
operator|==
name|R
operator|.
name|PenaltyReturnTypeOnItsOwnLine
operator|&&
name|PointerAlignment
operator|==
name|R
operator|.
name|PointerAlignment
operator|&&
name|SpacesBeforeTrailingComments
operator|==
name|R
operator|.
name|SpacesBeforeTrailingComments
operator|&&
name|Cpp11BracedListStyle
operator|==
name|R
operator|.
name|Cpp11BracedListStyle
operator|&&
name|Standard
operator|==
name|R
operator|.
name|Standard
operator|&&
name|TabWidth
operator|==
name|R
operator|.
name|TabWidth
operator|&&
name|UseTab
operator|==
name|R
operator|.
name|UseTab
operator|&&
name|SpacesInParentheses
operator|==
name|R
operator|.
name|SpacesInParentheses
operator|&&
name|SpacesInSquareBrackets
operator|==
name|R
operator|.
name|SpacesInSquareBrackets
operator|&&
name|SpacesInAngles
operator|==
name|R
operator|.
name|SpacesInAngles
operator|&&
name|SpaceInEmptyParentheses
operator|==
name|R
operator|.
name|SpaceInEmptyParentheses
operator|&&
name|SpacesInContainerLiterals
operator|==
name|R
operator|.
name|SpacesInContainerLiterals
operator|&&
name|SpacesInCStyleCastParentheses
operator|==
name|R
operator|.
name|SpacesInCStyleCastParentheses
operator|&&
name|SpaceAfterCStyleCast
operator|==
name|R
operator|.
name|SpaceAfterCStyleCast
operator|&&
name|SpaceBeforeParens
operator|==
name|R
operator|.
name|SpaceBeforeParens
operator|&&
name|SpaceBeforeAssignmentOperators
operator|==
name|R
operator|.
name|SpaceBeforeAssignmentOperators
operator|&&
name|ContinuationIndentWidth
operator|==
name|R
operator|.
name|ContinuationIndentWidth
operator|&&
name|CommentPragmas
operator|==
name|R
operator|.
name|CommentPragmas
operator|&&
name|ForEachMacros
operator|==
name|R
operator|.
name|ForEachMacros
return|;
block|}
block|}
struct|;
comment|/// \brief Returns a format style complying with the LLVM coding standards:
comment|/// http://llvm.org/docs/CodingStandards.html.
name|FormatStyle
name|getLLVMStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with one of Google's style guides:
comment|/// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml.
comment|/// http://google-styleguide.googlecode.com/svn/trunk/javascriptguide.xml.
comment|/// https://developers.google.com/protocol-buffers/docs/style.
name|FormatStyle
name|getGoogleStyle
argument_list|(
name|FormatStyle
operator|::
name|LanguageKind
name|Language
argument_list|)
decl_stmt|;
comment|/// \brief Returns a format style complying with Chromium's style guide:
comment|/// http://www.chromium.org/developers/coding-style.
name|FormatStyle
name|getChromiumStyle
argument_list|(
name|FormatStyle
operator|::
name|LanguageKind
name|Language
argument_list|)
decl_stmt|;
comment|/// \brief Returns a format style complying with Mozilla's style guide:
comment|/// https://developer.mozilla.org/en-US/docs/Developer_Guide/Coding_Style.
name|FormatStyle
name|getMozillaStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with Webkit's style guide:
comment|/// http://www.webkit.org/coding/coding-style.html
name|FormatStyle
name|getWebKitStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns a format style complying with GNU Coding Standards:
comment|/// http://www.gnu.org/prep/standards/standards.html
name|FormatStyle
name|getGNUStyle
parameter_list|()
function_decl|;
comment|/// \brief Returns style indicating formatting should be not applied at all.
name|FormatStyle
name|getNoStyle
parameter_list|()
function_decl|;
comment|/// \brief Gets a predefined style for the specified language by name.
comment|///
comment|/// Currently supported names: LLVM, Google, Chromium, Mozilla. Names are
comment|/// compared case-insensitively.
comment|///
comment|/// Returns \c true if the Style has been set.
name|bool
name|getPredefinedStyle
argument_list|(
name|StringRef
name|Name
argument_list|,
name|FormatStyle
operator|::
name|LanguageKind
name|Language
argument_list|,
name|FormatStyle
operator|*
name|Style
argument_list|)
decl_stmt|;
comment|/// \brief Parse configuration from YAML-formatted text.
comment|///
comment|/// Style->Language is used to get the base style, if the \c BasedOnStyle
comment|/// option is present.
comment|///
comment|/// When \c BasedOnStyle is not present, options not present in the YAML
comment|/// document, are retained in \p Style.
name|std
operator|::
name|error_code
name|parseConfiguration
argument_list|(
argument|StringRef Text
argument_list|,
argument|FormatStyle *Style
argument_list|)
expr_stmt|;
comment|/// \brief Gets configuration in a YAML string.
name|std
operator|::
name|string
name|configurationAsText
argument_list|(
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|)
expr_stmt|;
comment|/// \brief Reformats the given \p Ranges in the token stream coming out of
comment|/// \c Lex.
comment|///
comment|/// DEPRECATED: Do not use.
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
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|)
expr_stmt|;
comment|/// \brief Reformats the given \p Ranges in the file \p ID.
comment|///
comment|/// Each range is extended on either end to its next bigger logic unit, i.e.
comment|/// everything that might influence its formatting or might be influenced by its
comment|/// formatting.
comment|///
comment|/// Returns the \c Replacements necessary to make all \p Ranges comply with
comment|/// \p Style.
name|tooling
operator|::
name|Replacements
name|reformat
argument_list|(
argument|const FormatStyle&Style
argument_list|,
argument|SourceManager&SourceMgr
argument_list|,
argument|FileID ID
argument_list|,
argument|ArrayRef<CharSourceRange> Ranges
argument_list|)
expr_stmt|;
comment|/// \brief Reformats the given \p Ranges in \p Code.
comment|///
comment|/// Otherwise identical to the reformat() function consuming a \c Lexer.
name|tooling
operator|::
name|Replacements
name|reformat
argument_list|(
argument|const FormatStyle&Style
argument_list|,
argument|StringRef Code
argument_list|,
argument|ArrayRef<tooling::Range> Ranges
argument_list|,
argument|StringRef FileName =
literal|"<stdin>"
argument_list|)
expr_stmt|;
comment|/// \brief Returns the \c LangOpts that the formatter expects you to set.
comment|///
comment|/// \param Style determines specific settings for lexing mode.
name|LangOptions
name|getFormattingLangOpts
parameter_list|(
specifier|const
name|FormatStyle
modifier|&
name|Style
init|=
name|getLLVMStyle
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Description to be used for help text for a llvm::cl option for
comment|/// specifying format style. The description is closely related to the operation
comment|/// of getStyle().
specifier|extern
specifier|const
name|char
modifier|*
name|StyleOptionHelpDescription
decl_stmt|;
comment|/// \brief Construct a FormatStyle based on \c StyleName.
comment|///
comment|/// \c StyleName can take several forms:
comment|/// \li "{<key>:<value>, ...}" - Set specic style parameters.
comment|/// \li "<style name>" - One of the style names supported by
comment|/// getPredefinedStyle().
comment|/// \li "file" - Load style configuration from a file called '.clang-format'
comment|/// located in one of the parent directories of \c FileName or the current
comment|/// directory if \c FileName is empty.
comment|///
comment|/// \param[in] StyleName Style name to interpret according to the description
comment|/// above.
comment|/// \param[in] FileName Path to start search for .clang-format if \c StyleName
comment|/// == "file".
comment|/// \param[in] FallbackStyle The name of a predefined style used to fallback to
comment|/// in case the style can't be determined from \p StyleName.
comment|///
comment|/// \returns FormatStyle as specified by \c StyleName. If no style could be
comment|/// determined, the default is LLVM Style (see getLLVMStyle()).
name|FormatStyle
name|getStyle
parameter_list|(
name|StringRef
name|StyleName
parameter_list|,
name|StringRef
name|FileName
parameter_list|,
name|StringRef
name|FallbackStyle
parameter_list|)
function_decl|;
block|}
comment|// end namespace format
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|clang
operator|::
name|format
operator|::
name|ParseError
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_FORMAT_FORMAT_H
end_comment

end_unit

