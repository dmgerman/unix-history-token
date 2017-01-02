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
name|vfs
block|{
name|class
name|FileSystem
decl_stmt|;
block|}
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
name|noexcept
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
comment|/// \brief The ``FormatStyle`` is used to configure the formatting to follow
comment|/// specific guidelines.
struct|struct
name|FormatStyle
block|{
comment|/// \brief The extra indent or outdent of access modifiers, e.g. ``public:``.
name|int
name|AccessModifierOffset
decl_stmt|;
comment|/// \brief Different styles for aligning after open brackets.
enum|enum
name|BracketAlignmentStyle
block|{
comment|/// \brief Align parameters on the open bracket, e.g.:
comment|/// \code
comment|///   someLongFunction(argument1,
comment|///                    argument2);
comment|/// \endcode
name|BAS_Align
block|,
comment|/// \brief Don't align, instead use ``ContinuationIndentWidth``, e.g.:
comment|/// \code
comment|///   someLongFunction(argument1,
comment|///       argument2);
comment|/// \endcode
name|BAS_DontAlign
block|,
comment|/// \brief Always break after an open bracket, if the parameters don't fit
comment|/// on a single line, e.g.:
comment|/// \code
comment|///   someLongFunction(
comment|///       argument1, argument2);
comment|/// \endcode
name|BAS_AlwaysBreak
block|,   }
enum|;
comment|/// \brief If ``true``, horizontally aligns arguments after an open bracket.
comment|///
comment|/// This applies to round brackets (parentheses), angle brackets and square
comment|/// brackets.
name|BracketAlignmentStyle
name|AlignAfterOpenBracket
decl_stmt|;
comment|/// \brief If ``true``, aligns consecutive assignments.
comment|///
comment|/// This will align the assignment operators of consecutive lines. This
comment|/// will result in formattings like
comment|/// \code
comment|///   int aaaa = 12;
comment|///   int b    = 23;
comment|///   int ccc  = 23;
comment|/// \endcode
name|bool
name|AlignConsecutiveAssignments
decl_stmt|;
comment|/// \brief If ``true``, aligns consecutive declarations.
comment|///
comment|/// This will align the declaration names of consecutive lines. This
comment|/// will result in formattings like
comment|/// \code
comment|///   int         aaaa = 12;
comment|///   float       b = 23;
comment|///   std::string ccc = 23;
comment|/// \endcode
name|bool
name|AlignConsecutiveDeclarations
decl_stmt|;
comment|/// \brief If ``true``, aligns escaped newlines as far left as possible.
comment|/// Otherwise puts them into the right-most column.
name|bool
name|AlignEscapedNewlinesLeft
decl_stmt|;
comment|/// \brief If ``true``, horizontally align operands of binary and ternary
comment|/// expressions.
comment|///
comment|/// Specifically, this aligns operands of a single expression that needs to be
comment|/// split over multiple lines, e.g.:
comment|/// \code
comment|///   int aaa = bbbbbbbbbbbbbbb +
comment|///             ccccccccccccccc;
comment|/// \endcode
name|bool
name|AlignOperands
decl_stmt|;
comment|/// \brief If ``true``, aligns trailing comments.
name|bool
name|AlignTrailingComments
decl_stmt|;
comment|/// \brief Allow putting all parameters of a function declaration onto
comment|/// the next line even if ``BinPackParameters`` is ``false``.
name|bool
name|AllowAllParametersOfDeclarationOnNextLine
decl_stmt|;
comment|/// \brief Allows contracting simple braced statements to a single line.
comment|///
comment|/// E.g., this allows ``if (a) { return; }`` to be put on a single line.
name|bool
name|AllowShortBlocksOnASingleLine
decl_stmt|;
comment|/// \brief If ``true``, short case labels will be contracted to a single line.
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
comment|/// \brief Only merge empty functions.
name|SFS_Empty
block|,
comment|/// \brief Only merge functions defined inside a class. Implies "empty".
name|SFS_Inline
block|,
comment|/// \brief Merge all functions fitting on a single line.
name|SFS_All
block|,   }
enum|;
comment|/// \brief Dependent on the value, ``int f() { return 0; }`` can be put on a
comment|/// single line.
name|ShortFunctionStyle
name|AllowShortFunctionsOnASingleLine
decl_stmt|;
comment|/// \brief If ``true``, ``if (a) return;`` can be put on a single line.
name|bool
name|AllowShortIfStatementsOnASingleLine
decl_stmt|;
comment|/// \brief If ``true``, ``while (true) continue;`` can be put on a single
comment|/// line.
name|bool
name|AllowShortLoopsOnASingleLine
decl_stmt|;
comment|/// \brief Different ways to break after the function definition return type.
enum|enum
name|DefinitionReturnTypeBreakingStyle
block|{
comment|/// Break after return type automatically.
comment|/// ``PenaltyReturnTypeOnItsOwnLine`` is taken into account.
name|DRTBS_None
block|,
comment|/// Always break after the return type.
name|DRTBS_All
block|,
comment|/// Always break after the return types of top-level functions.
name|DRTBS_TopLevel
block|,   }
enum|;
comment|/// \brief Different ways to break after the function definition or
comment|/// declaration return type.
enum|enum
name|ReturnTypeBreakingStyle
block|{
comment|/// Break after return type automatically.
comment|/// ``PenaltyReturnTypeOnItsOwnLine`` is taken into account.
name|RTBS_None
block|,
comment|/// Always break after the return type.
name|RTBS_All
block|,
comment|/// Always break after the return types of top-level functions.
name|RTBS_TopLevel
block|,
comment|/// Always break after the return type of function definitions.
name|RTBS_AllDefinitions
block|,
comment|/// Always break after the return type of top-level definitions.
name|RTBS_TopLevelDefinitions
block|,   }
enum|;
comment|/// \brief The function definition return type breaking style to use.  This
comment|/// option is deprecated and is retained for backwards compatibility.
name|DefinitionReturnTypeBreakingStyle
name|AlwaysBreakAfterDefinitionReturnType
decl_stmt|;
comment|/// \brief The function declaration return type breaking style to use.
name|ReturnTypeBreakingStyle
name|AlwaysBreakAfterReturnType
decl_stmt|;
comment|/// \brief If ``true``, always break before multiline string literals.
comment|///
comment|/// This flag is mean to make cases where there are multiple multiline strings
comment|/// in a file look more consistent. Thus, it will only take effect if wrapping
comment|/// the string at that point leads to it being indented
comment|/// ``ContinuationIndentWidth`` spaces from the start of the line.
name|bool
name|AlwaysBreakBeforeMultilineStrings
decl_stmt|;
comment|/// \brief If ``true``, always break after the ``template<...>`` of a template
comment|/// declaration.
name|bool
name|AlwaysBreakTemplateDeclarations
decl_stmt|;
comment|/// \brief If ``false``, a function call's arguments will either be all on the
comment|/// same line or will have one line each.
name|bool
name|BinPackArguments
decl_stmt|;
comment|/// \brief If ``false``, a function declaration's or function definition's
comment|/// parameters will either all be on the same line or will have one line each.
name|bool
name|BinPackParameters
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
comment|/// \brief Different ways to attach braces to their surrounding context.
enum|enum
name|BraceBreakingStyle
block|{
comment|/// Always attach braces to surrounding context.
name|BS_Attach
block|,
comment|/// Like ``Attach``, but break before braces on function, namespace and
comment|/// class definitions.
name|BS_Linux
block|,
comment|/// Like ``Attach``, but break before braces on enum, function, and record
comment|/// definitions.
name|BS_Mozilla
block|,
comment|/// Like ``Attach``, but break before function definitions, ``catch``, and
comment|/// ``else``.
name|BS_Stroustrup
block|,
comment|/// Always break before braces.
name|BS_Allman
block|,
comment|/// Always break before braces and add an extra level of indentation to
comment|/// braces of control statements, not to those of class, function
comment|/// or other definitions.
name|BS_GNU
block|,
comment|/// Like ``Attach``, but break before functions.
name|BS_WebKit
block|,
comment|/// Configure each individual brace in `BraceWrapping`.
name|BS_Custom
block|}
enum|;
comment|/// \brief The brace breaking style to use.
name|BraceBreakingStyle
name|BreakBeforeBraces
decl_stmt|;
comment|/// \brief Precise control over the wrapping of braces.
struct|struct
name|BraceWrappingFlags
block|{
comment|/// \brief Wrap class definitions.
name|bool
name|AfterClass
decl_stmt|;
comment|/// \brief Wrap control statements (``if``/``for``/``while``/``switch``/..).
name|bool
name|AfterControlStatement
decl_stmt|;
comment|/// \brief Wrap enum definitions.
name|bool
name|AfterEnum
decl_stmt|;
comment|/// \brief Wrap function definitions.
name|bool
name|AfterFunction
decl_stmt|;
comment|/// \brief Wrap namespace definitions.
name|bool
name|AfterNamespace
decl_stmt|;
comment|/// \brief Wrap ObjC definitions (``@autoreleasepool``, interfaces, ..).
name|bool
name|AfterObjCDeclaration
decl_stmt|;
comment|/// \brief Wrap struct definitions.
name|bool
name|AfterStruct
decl_stmt|;
comment|/// \brief Wrap union definitions.
name|bool
name|AfterUnion
decl_stmt|;
comment|/// \brief Wrap before ``catch``.
name|bool
name|BeforeCatch
decl_stmt|;
comment|/// \brief Wrap before ``else``.
name|bool
name|BeforeElse
decl_stmt|;
comment|/// \brief Indent the wrapped braces themselves.
name|bool
name|IndentBraces
decl_stmt|;
block|}
struct|;
comment|/// \brief Control of individual brace wrapping cases.
comment|///
comment|/// If ``BreakBeforeBraces`` is set to ``BS_Custom``, use this to specify how
comment|/// each individual brace case should be handled. Otherwise, this is ignored.
name|BraceWrappingFlags
name|BraceWrapping
decl_stmt|;
comment|/// \brief If ``true``, ternary operators will be placed after line breaks.
name|bool
name|BreakBeforeTernaryOperators
decl_stmt|;
comment|/// \brief Always break constructor initializers before commas and align
comment|/// the commas with the colon.
name|bool
name|BreakConstructorInitializersBeforeComma
decl_stmt|;
comment|/// \brief Break after each annotation on a field in Java files.
name|bool
name|BreakAfterJavaFieldAnnotations
decl_stmt|;
comment|/// \brief Allow breaking string literals when formatting.
name|bool
name|BreakStringLiterals
decl_stmt|;
comment|/// \brief The column limit.
comment|///
comment|/// A column limit of ``0`` means that there is no column limit. In this case,
comment|/// clang-format will respect the input's line breaking decisions within
comment|/// statements unless they contradict other rules.
name|unsigned
name|ColumnLimit
decl_stmt|;
comment|/// \brief A regular expression that describes comments with special meaning,
comment|/// which should not be split into lines or otherwise changed.
name|std
operator|::
name|string
name|CommentPragmas
expr_stmt|;
comment|/// \brief If the constructor initializers don't fit on a line, put each
comment|/// initializer on its own line.
name|bool
name|ConstructorInitializerAllOnOneLineOrOnePerLine
decl_stmt|;
comment|/// \brief The number of characters to use for indentation of constructor
comment|/// initializer lists.
name|unsigned
name|ConstructorInitializerIndentWidth
decl_stmt|;
comment|/// \brief Indent width for line continuations.
name|unsigned
name|ContinuationIndentWidth
decl_stmt|;
comment|/// \brief If ``true``, format braced lists as best suited for C++11 braced
comment|/// lists.
comment|///
comment|/// Important differences:
comment|/// - No spaces inside the braced list.
comment|/// - No line break before the closing brace.
comment|/// - Indentation with the continuation indent, not with the block indent.
comment|///
comment|/// Fundamentally, C++11 braced lists are formatted exactly like function
comment|/// calls would be formatted in their place. If the braced list follows a name
comment|/// (e.g. a type or variable name), clang-format formats as if the ``{}`` were
comment|/// the parentheses of a function call with that name. If there is no name,
comment|/// a zero-length name is assumed.
name|bool
name|Cpp11BracedListStyle
decl_stmt|;
comment|/// \brief If ``true``, analyze the formatted file for the most common
comment|/// alignment of ``&`` and ``*``. ``PointerAlignment`` is then used only as
comment|/// fallback.
name|bool
name|DerivePointerAlignment
decl_stmt|;
comment|/// \brief Disables formatting completely.
name|bool
name|DisableFormat
decl_stmt|;
comment|/// \brief If ``true``, clang-format detects whether function calls and
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
comment|/// \brief A vector of macros that should be interpreted as foreach loops
comment|/// instead of as function calls.
comment|///
comment|/// These are expected to be macros of the form:
comment|/// \code
comment|///   FOREACH(<variable-declaration>, ...)
comment|///<loop-body>
comment|/// \endcode
comment|///
comment|/// In the .clang-format configuration file, this can be configured like:
comment|/// \code{.yaml}
comment|///   ForEachMacros: ['RANGES_FOR', 'FOREACH']
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
comment|/// \brief See documentation of ``IncludeCategories``.
struct|struct
name|IncludeCategory
block|{
comment|/// \brief The regular expression that this category matches.
name|std
operator|::
name|string
name|Regex
expr_stmt|;
comment|/// \brief The priority to assign to this category.
name|int
name|Priority
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IncludeCategory
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Regex
operator|==
name|Other
operator|.
name|Regex
operator|&&
name|Priority
operator|==
name|Other
operator|.
name|Priority
return|;
block|}
block|}
struct|;
comment|/// \brief Regular expressions denoting the different ``#include`` categories
comment|/// used for ordering ``#includes``.
comment|///
comment|/// These regular expressions are matched against the filename of an include
comment|/// (including the<> or "") in order. The value belonging to the first
comment|/// matching regular expression is assigned and ``#includes`` are sorted first
comment|/// according to increasing category number and then alphabetically within
comment|/// each category.
comment|///
comment|/// If none of the regular expressions match, INT_MAX is assigned as
comment|/// category. The main header for a source file automatically gets category 0.
comment|/// so that it is generally kept at the beginning of the ``#includes``
comment|/// (http://llvm.org/docs/CodingStandards.html#include-style). However, you
comment|/// can also assign negative priorities if you have certain headers that
comment|/// always need to be first.
comment|///
comment|/// To configure this in the .clang-format file, use:
comment|/// \code{.yaml}
comment|///   IncludeCategories:
comment|///     - Regex:           '^"(llvm|llvm-c|clang|clang-c)/'
comment|///       Priority:        2
comment|///     - Regex:           '^(<|"(gtest|isl|json)/)'
comment|///       Priority:        3
comment|///     - Regex:           '.*'
comment|///       Priority:        1
comment|/// \endcode
name|std
operator|::
name|vector
operator|<
name|IncludeCategory
operator|>
name|IncludeCategories
expr_stmt|;
comment|/// \brief Specify a regular expression of suffixes that are allowed in the
comment|/// file-to-main-include mapping.
comment|///
comment|/// When guessing whether a #include is the "main" include (to assign
comment|/// category 0, see above), use this regex of allowed suffixes to the header
comment|/// stem. A partial match is done, so that:
comment|/// - "" means "arbitrary suffix"
comment|/// - "$" means "no suffix"
comment|///
comment|/// For example, if configured to "(_test)?$", then a header a.h would be seen
comment|/// as the "main" include in both a.cc and a_test.cc.
name|std
operator|::
name|string
name|IncludeIsMainRegex
expr_stmt|;
comment|/// \brief Indent case labels one level from the switch statement.
comment|///
comment|/// When ``false``, use the same indentation level as for the switch statement.
comment|/// Switch statement body is always indented one level more than case labels.
name|bool
name|IndentCaseLabels
decl_stmt|;
comment|/// \brief The number of columns to use for indentation.
name|unsigned
name|IndentWidth
decl_stmt|;
comment|/// \brief Indent if a function definition or declaration is wrapped after the
comment|/// type.
name|bool
name|IndentWrappedFunctionNames
decl_stmt|;
comment|/// \brief Quotation styles for JavaScript strings. Does not affect template
comment|/// strings.
enum|enum
name|JavaScriptQuoteStyle
block|{
comment|/// Leave string quotes as they are.
name|JSQS_Leave
block|,
comment|/// Always use single quotes.
name|JSQS_Single
block|,
comment|/// Always use double quotes.
name|JSQS_Double
block|}
enum|;
comment|/// \brief The JavaScriptQuoteStyle to use for JavaScript strings.
name|JavaScriptQuoteStyle
name|JavaScriptQuotes
decl_stmt|;
comment|/// \brief Whether to wrap JavaScript import/export statements.
name|bool
name|JavaScriptWrapImports
decl_stmt|;
comment|/// \brief If true, empty lines at the start of blocks are kept.
name|bool
name|KeepEmptyLinesAtTheStartOfBlocks
decl_stmt|;
comment|/// \brief Supported languages.
comment|///
comment|/// When stored in a configuration file, specifies the language, that the
comment|/// configuration targets. When passed to the ``reformat()`` function, enables
comment|/// syntax features specific to the language.
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
comment|/// Should be used for ObjC code.
name|LK_ObjC
block|,
comment|/// Should be used for Protocol Buffers
comment|/// (https://developers.google.com/protocol-buffers/).
name|LK_Proto
block|,
comment|/// Should be used for TableGen code.
name|LK_TableGen
block|}
enum|;
comment|/// \brief Language, this format style is targeted at.
name|LanguageKind
name|Language
decl_stmt|;
comment|/// \brief A regular expression matching macros that start a block.
name|std
operator|::
name|string
name|MacroBlockBegin
expr_stmt|;
comment|/// \brief A regular expression matching macros that end a block.
name|std
operator|::
name|string
name|MacroBlockEnd
expr_stmt|;
comment|/// \brief The maximum number of consecutive empty lines to keep.
name|unsigned
name|MaxEmptyLinesToKeep
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
comment|/// \brief The number of characters to use for indentation of ObjC blocks.
name|unsigned
name|ObjCBlockIndentWidth
decl_stmt|;
comment|/// \brief Add a space after ``@property`` in Objective-C, i.e. use
comment|/// ``@property (readonly)`` instead of ``@property(readonly)``.
name|bool
name|ObjCSpaceAfterProperty
decl_stmt|;
comment|/// \brief Add a space in front of an Objective-C protocol list, i.e. use
comment|/// ``Foo<Protocol>`` instead of ``Foo<Protocol>``.
name|bool
name|ObjCSpaceBeforeProtocolList
decl_stmt|;
comment|/// \brief The penalty for breaking a function call after ``call(``.
name|unsigned
name|PenaltyBreakBeforeFirstCallParameter
decl_stmt|;
comment|/// \brief The penalty for each line break introduced inside a comment.
name|unsigned
name|PenaltyBreakComment
decl_stmt|;
comment|/// \brief The penalty for breaking before the first ``<<``.
name|unsigned
name|PenaltyBreakFirstLessLess
decl_stmt|;
comment|/// \brief The penalty for each line break introduced inside a string literal.
name|unsigned
name|PenaltyBreakString
decl_stmt|;
comment|/// \brief The penalty for each character outside of the column limit.
name|unsigned
name|PenaltyExcessCharacter
decl_stmt|;
comment|/// \brief Penalty for putting the return type of a function onto its own
comment|/// line.
name|unsigned
name|PenaltyReturnTypeOnItsOwnLine
decl_stmt|;
comment|/// \brief The ``&`` and ``*`` alignment style.
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
comment|/// \brief Pointer and reference alignment style.
name|PointerAlignmentStyle
name|PointerAlignment
decl_stmt|;
comment|/// \brief If ``true``, clang-format will attempt to re-flow comments.
name|bool
name|ReflowComments
decl_stmt|;
comment|/// \brief If ``true``, clang-format will sort ``#includes``.
name|bool
name|SortIncludes
decl_stmt|;
comment|/// \brief If ``true``, a space may be inserted after C style casts.
name|bool
name|SpaceAfterCStyleCast
decl_stmt|;
comment|/// \brief If \c true, a space will be inserted after the 'template' keyword.
name|bool
name|SpaceAfterTemplateKeyword
decl_stmt|;
comment|/// \brief If ``false``, spaces will be removed before assignment operators.
name|bool
name|SpaceBeforeAssignmentOperators
decl_stmt|;
comment|/// \brief Different ways to put a space before opening parentheses.
enum|enum
name|SpaceBeforeParensOptions
block|{
comment|/// Never put a space before opening parentheses.
name|SBPO_Never
block|,
comment|/// Put a space before opening parentheses only after control statement
comment|/// keywords (``for/if/while...``).
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
comment|/// \brief If ``true``, spaces may be inserted into ``()``.
name|bool
name|SpaceInEmptyParentheses
decl_stmt|;
comment|/// \brief The number of spaces before trailing line comments
comment|/// (``//`` - comments).
comment|///
comment|/// This does not affect trailing block comments (``/*`` - comments) as
comment|/// those commonly have different usage patterns and a number of special
comment|/// cases.
name|unsigned
name|SpacesBeforeTrailingComments
decl_stmt|;
comment|/// \brief If ``true``, spaces will be inserted after ``<`` and before ``>``
comment|/// in template argument lists.
name|bool
name|SpacesInAngles
decl_stmt|;
comment|/// \brief If ``true``, spaces are inserted inside container literals (e.g.
comment|/// ObjC and Javascript array and dict literals).
name|bool
name|SpacesInContainerLiterals
decl_stmt|;
comment|/// \brief If ``true``, spaces may be inserted into C style casts.
name|bool
name|SpacesInCStyleCastParentheses
decl_stmt|;
comment|/// \brief If ``true``, spaces will be inserted after ``(`` and before ``)``.
name|bool
name|SpacesInParentheses
decl_stmt|;
comment|/// \brief If ``true``, spaces will be inserted after ``[`` and before ``]``.
name|bool
name|SpacesInSquareBrackets
decl_stmt|;
comment|/// \brief Supported language standards.
enum|enum
name|LanguageStandard
block|{
comment|/// Use C++03-compatible syntax.
name|LS_Cpp03
block|,
comment|/// Use features of C++11 (e.g. ``A<A<int>>`` instead of ``A<A<int>>``).
name|LS_Cpp11
block|,
comment|/// Automatic detection based on the input.
name|LS_Auto
block|}
enum|;
comment|/// \brief Format compatible with this standard, e.g. use ``A<A<int>>``
comment|/// instead of ``A<A<int>>`` for ``LS_Cpp03``.
name|LanguageStandard
name|Standard
decl_stmt|;
comment|/// \brief The number of columns used for tab stops.
name|unsigned
name|TabWidth
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
comment|/// Use tabs only for line continuation and indentation.
name|UT_ForContinuationAndIndentation
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
name|AlignConsecutiveAssignments
operator|==
name|R
operator|.
name|AlignConsecutiveAssignments
operator|&&
name|AlignConsecutiveDeclarations
operator|==
name|R
operator|.
name|AlignConsecutiveDeclarations
operator|&&
name|AlignEscapedNewlinesLeft
operator|==
name|R
operator|.
name|AlignEscapedNewlinesLeft
operator|&&
name|AlignOperands
operator|==
name|R
operator|.
name|AlignOperands
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
name|AllowShortBlocksOnASingleLine
operator|==
name|R
operator|.
name|AllowShortBlocksOnASingleLine
operator|&&
name|AllowShortCaseLabelsOnASingleLine
operator|==
name|R
operator|.
name|AllowShortCaseLabelsOnASingleLine
operator|&&
name|AllowShortFunctionsOnASingleLine
operator|==
name|R
operator|.
name|AllowShortFunctionsOnASingleLine
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
name|AlwaysBreakAfterReturnType
operator|==
name|R
operator|.
name|AlwaysBreakAfterReturnType
operator|&&
name|AlwaysBreakBeforeMultilineStrings
operator|==
name|R
operator|.
name|AlwaysBreakBeforeMultilineStrings
operator|&&
name|AlwaysBreakTemplateDeclarations
operator|==
name|R
operator|.
name|AlwaysBreakTemplateDeclarations
operator|&&
name|BinPackArguments
operator|==
name|R
operator|.
name|BinPackArguments
operator|&&
name|BinPackParameters
operator|==
name|R
operator|.
name|BinPackParameters
operator|&&
name|BreakBeforeBinaryOperators
operator|==
name|R
operator|.
name|BreakBeforeBinaryOperators
operator|&&
name|BreakBeforeBraces
operator|==
name|R
operator|.
name|BreakBeforeBraces
operator|&&
name|BreakBeforeTernaryOperators
operator|==
name|R
operator|.
name|BreakBeforeTernaryOperators
operator|&&
name|BreakConstructorInitializersBeforeComma
operator|==
name|R
operator|.
name|BreakConstructorInitializersBeforeComma
operator|&&
name|BreakAfterJavaFieldAnnotations
operator|==
name|R
operator|.
name|BreakAfterJavaFieldAnnotations
operator|&&
name|BreakStringLiterals
operator|==
name|R
operator|.
name|BreakStringLiterals
operator|&&
name|ColumnLimit
operator|==
name|R
operator|.
name|ColumnLimit
operator|&&
name|CommentPragmas
operator|==
name|R
operator|.
name|CommentPragmas
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
name|ContinuationIndentWidth
operator|==
name|R
operator|.
name|ContinuationIndentWidth
operator|&&
name|Cpp11BracedListStyle
operator|==
name|R
operator|.
name|Cpp11BracedListStyle
operator|&&
name|DerivePointerAlignment
operator|==
name|R
operator|.
name|DerivePointerAlignment
operator|&&
name|DisableFormat
operator|==
name|R
operator|.
name|DisableFormat
operator|&&
name|ExperimentalAutoDetectBinPacking
operator|==
name|R
operator|.
name|ExperimentalAutoDetectBinPacking
operator|&&
name|ForEachMacros
operator|==
name|R
operator|.
name|ForEachMacros
operator|&&
name|IncludeCategories
operator|==
name|R
operator|.
name|IncludeCategories
operator|&&
name|IndentCaseLabels
operator|==
name|R
operator|.
name|IndentCaseLabels
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
name|IndentWrappedFunctionNames
operator|==
name|R
operator|.
name|IndentWrappedFunctionNames
operator|&&
name|JavaScriptQuotes
operator|==
name|R
operator|.
name|JavaScriptQuotes
operator|&&
name|JavaScriptWrapImports
operator|==
name|R
operator|.
name|JavaScriptWrapImports
operator|&&
name|KeepEmptyLinesAtTheStartOfBlocks
operator|==
name|R
operator|.
name|KeepEmptyLinesAtTheStartOfBlocks
operator|&&
name|MacroBlockBegin
operator|==
name|R
operator|.
name|MacroBlockBegin
operator|&&
name|MacroBlockEnd
operator|==
name|R
operator|.
name|MacroBlockEnd
operator|&&
name|MaxEmptyLinesToKeep
operator|==
name|R
operator|.
name|MaxEmptyLinesToKeep
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
name|PenaltyBreakBeforeFirstCallParameter
operator|==
name|R
operator|.
name|PenaltyBreakBeforeFirstCallParameter
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
name|SpaceAfterCStyleCast
operator|==
name|R
operator|.
name|SpaceAfterCStyleCast
operator|&&
name|SpaceAfterTemplateKeyword
operator|==
name|R
operator|.
name|SpaceAfterTemplateKeyword
operator|&&
name|SpaceBeforeAssignmentOperators
operator|==
name|R
operator|.
name|SpaceBeforeAssignmentOperators
operator|&&
name|SpaceBeforeParens
operator|==
name|R
operator|.
name|SpaceBeforeParens
operator|&&
name|SpaceInEmptyParentheses
operator|==
name|R
operator|.
name|SpaceInEmptyParentheses
operator|&&
name|SpacesBeforeTrailingComments
operator|==
name|R
operator|.
name|SpacesBeforeTrailingComments
operator|&&
name|SpacesInAngles
operator|==
name|R
operator|.
name|SpacesInAngles
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
comment|/// Returns ``true`` if the Style has been set.
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
comment|/// Style->Language is used to get the base style, if the ``BasedOnStyle``
comment|/// option is present.
comment|///
comment|/// When ``BasedOnStyle`` is not present, options not present in the YAML
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
comment|/// \brief Returns the replacements necessary to sort all ``#include`` blocks
comment|/// that are affected by ``Ranges``.
name|tooling
operator|::
name|Replacements
name|sortIncludes
argument_list|(
argument|const FormatStyle&Style
argument_list|,
argument|StringRef Code
argument_list|,
argument|ArrayRef<tooling::Range> Ranges
argument_list|,
argument|StringRef FileName
argument_list|,
argument|unsigned *Cursor = nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Returns the replacements corresponding to applying and formatting
comment|/// \p Replaces on success; otheriwse, return an llvm::Error carrying
comment|/// llvm::StringError.
name|llvm
operator|::
name|Expected
operator|<
name|tooling
operator|::
name|Replacements
operator|>
name|formatReplacements
argument_list|(
argument|StringRef Code
argument_list|,
argument|const tooling::Replacements&Replaces
argument_list|,
argument|const FormatStyle&Style
argument_list|)
expr_stmt|;
comment|/// \brief Returns the replacements corresponding to applying \p Replaces and
comment|/// cleaning up the code after that on success; otherwise, return an llvm::Error
comment|/// carrying llvm::StringError.
comment|/// This also supports inserting/deleting C++ #include directives:
comment|/// - If a replacement has offset UINT_MAX, length 0, and a replacement text
comment|///   that is an #include directive, this will insert the #include into the
comment|///   correct block in the \p Code. When searching for points to insert new
comment|///   header, this ignores #include's after the #include block(s) in the
comment|///   beginning of a file to avoid inserting headers into code sections where
comment|///   new #include's should not be added by default. These code sections
comment|///   include:
comment|///     - raw string literals (containing #include).
comment|///     - #if blocks.
comment|///     - Special #include's among declarations (e.g. functions).
comment|/// - If a replacement has offset UINT_MAX, length 1, and a replacement text
comment|///   that is the name of the header to be removed, the header will be removed
comment|///   from \p Code if it exists.
name|llvm
operator|::
name|Expected
operator|<
name|tooling
operator|::
name|Replacements
operator|>
name|cleanupAroundReplacements
argument_list|(
argument|StringRef Code
argument_list|,
argument|const tooling::Replacements&Replaces
argument_list|,
argument|const FormatStyle&Style
argument_list|)
expr_stmt|;
comment|/// \brief Reformats the given \p Ranges in \p Code.
comment|///
comment|/// Each range is extended on either end to its next bigger logic unit, i.e.
comment|/// everything that might influence its formatting or might be influenced by its
comment|/// formatting.
comment|///
comment|/// Returns the ``Replacements`` necessary to make all \p Ranges comply with
comment|/// \p Style.
comment|///
comment|/// If ``IncompleteFormat`` is non-null, its value will be set to true if any
comment|/// of the affected ranges were not formatted due to a non-recoverable syntax
comment|/// error.
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
argument_list|,
argument|bool *IncompleteFormat = nullptr
argument_list|)
expr_stmt|;
comment|/// \brief Clean up any erroneous/redundant code in the given \p Ranges in \p
comment|/// Code.
comment|///
comment|/// Returns the ``Replacements`` that clean up all \p Ranges in \p Code.
name|tooling
operator|::
name|Replacements
name|cleanup
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
comment|/// \brief Returns the ``LangOpts`` that the formatter expects you to set.
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
comment|/// \brief Description to be used for help text for a ``llvm::cl`` option for
comment|/// specifying format style. The description is closely related to the operation
comment|/// of ``getStyle()``.
specifier|extern
specifier|const
name|char
modifier|*
name|StyleOptionHelpDescription
decl_stmt|;
comment|/// \brief Construct a FormatStyle based on ``StyleName``.
comment|///
comment|/// ``StyleName`` can take several forms:
comment|/// * "{<key>:<value>, ...}" - Set specic style parameters.
comment|/// * "<style name>" - One of the style names supported by
comment|/// getPredefinedStyle().
comment|/// * "file" - Load style configuration from a file called ``.clang-format``
comment|/// located in one of the parent directories of ``FileName`` or the current
comment|/// directory if ``FileName`` is empty.
comment|///
comment|/// \param[in] StyleName Style name to interpret according to the description
comment|/// above.
comment|/// \param[in] FileName Path to start search for .clang-format if ``StyleName``
comment|/// == "file".
comment|/// \param[in] FallbackStyle The name of a predefined style used to fallback to
comment|/// in case the style can't be determined from \p StyleName.
comment|/// \param[in] Code The actual code to be formatted. Used to determine the
comment|/// language if the filename isn't sufficient.
comment|/// \param[in] FS The underlying file system, in which the file resides. By
comment|/// default, the file system is the real file system.
comment|///
comment|/// \returns FormatStyle as specified by ``StyleName``. If no style could be
comment|/// determined, the default is LLVM Style (see ``getLLVMStyle()``).
name|FormatStyle
name|getStyle
argument_list|(
name|StringRef
name|StyleName
argument_list|,
name|StringRef
name|FileName
argument_list|,
name|StringRef
name|FallbackStyle
argument_list|,
name|StringRef
name|Code
operator|=
literal|""
argument_list|,
name|vfs
operator|::
name|FileSystem
operator|*
name|FS
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|// \brief Returns a string representation of ``Language``.
specifier|inline
name|StringRef
name|getLanguageName
argument_list|(
name|FormatStyle
operator|::
name|LanguageKind
name|Language
argument_list|)
block|{
switch|switch
condition|(
name|Language
condition|)
block|{
case|case
name|FormatStyle
operator|::
name|LK_Cpp
case|:
return|return
literal|"C++"
return|;
case|case
name|FormatStyle
operator|::
name|LK_Java
case|:
return|return
literal|"Java"
return|;
case|case
name|FormatStyle
operator|::
name|LK_JavaScript
case|:
return|return
literal|"JavaScript"
return|;
case|case
name|FormatStyle
operator|::
name|LK_Proto
case|:
return|return
literal|"Proto"
return|;
default|default:
return|return
literal|"Unknown"
return|;
block|}
block|}
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

