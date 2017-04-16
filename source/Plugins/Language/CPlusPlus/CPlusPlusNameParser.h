begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CPlusPlusNameParser.h -----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_CPlusPlusNameParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CPlusPlusNameParser_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"clang/Lex/Lexer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// Helps to validate and obtain various parts of C++ definitions.
name|class
name|CPlusPlusNameParser
block|{
name|public
label|:
name|CPlusPlusNameParser
argument_list|(
argument|llvm::StringRef text
argument_list|)
block|:
name|m_text
argument_list|(
argument|text
argument_list|)
block|{
name|ExtractTokens
argument_list|()
expr_stmt|;
block|}
struct|struct
name|ParsedName
block|{
name|llvm
operator|::
name|StringRef
name|basename
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|context
expr_stmt|;
block|}
struct|;
struct|struct
name|ParsedFunction
block|{
name|ParsedName
name|name
decl_stmt|;
name|llvm
operator|::
name|StringRef
name|arguments
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|qualifiers
expr_stmt|;
block|}
struct|;
comment|// Treats given text as a function definition and parses it.
comment|// Function definition might or might not have a return type and this should
comment|// change parsing result.
comment|// Examples:
comment|//    main(int, chat const*)
comment|//    T fun(int, bool)
comment|//    std::vector<int>::push_back(int)
comment|//    int& map<int, pair<short, int>>::operator[](short) const
comment|//    int (*get_function(const chat *))()
name|llvm
operator|::
name|Optional
operator|<
name|ParsedFunction
operator|>
name|ParseAsFunctionDefinition
argument_list|()
expr_stmt|;
comment|// Treats given text as a potentially nested name of C++ entity (function,
comment|// class, field) and parses it.
comment|// Examples:
comment|//    main
comment|//    fun
comment|//    std::vector<int>::push_back
comment|//    map<int, pair<short, int>>::operator[]
comment|//    func<C>(int, C&)::nested_class::method
name|llvm
operator|::
name|Optional
operator|<
name|ParsedName
operator|>
name|ParseAsFullName
argument_list|()
expr_stmt|;
name|private
label|:
comment|// A C++ definition to parse.
name|llvm
operator|::
name|StringRef
name|m_text
expr_stmt|;
comment|// Tokens extracted from m_text.
name|llvm
operator|::
name|SmallVector
operator|<
name|clang
operator|::
name|Token
operator|,
literal|30
operator|>
name|m_tokens
expr_stmt|;
comment|// Index of the next token to look at from m_tokens.
name|size_t
name|m_next_token_index
init|=
literal|0
decl_stmt|;
comment|// Range of tokens saved in m_next_token_index.
struct|struct
name|Range
block|{
name|size_t
name|begin_index
init|=
literal|0
decl_stmt|;
name|size_t
name|end_index
init|=
literal|0
decl_stmt|;
name|Range
argument_list|()
block|{}
name|Range
argument_list|(
argument|size_t begin
argument_list|,
argument|size_t end
argument_list|)
block|:
name|begin_index
argument_list|(
name|begin
argument_list|)
operator|,
name|end_index
argument_list|(
argument|end
argument_list|)
block|{
name|assert
argument_list|(
name|end
operator|>=
name|begin
argument_list|)
block|;     }
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|end_index
operator|-
name|begin_index
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
block|}
struct|;
struct|struct
name|ParsedNameRanges
block|{
name|Range
name|basename_range
decl_stmt|;
name|Range
name|context_range
decl_stmt|;
block|}
struct|;
comment|// Bookmark automatically restores parsing position (m_next_token_index)
comment|// when destructed unless it's manually removed with Remove().
name|class
name|Bookmark
block|{
name|public
label|:
name|Bookmark
argument_list|(
name|size_t
operator|&
name|position
argument_list|)
operator|:
name|m_position
argument_list|(
name|position
argument_list|)
operator|,
name|m_position_value
argument_list|(
argument|position
argument_list|)
block|{}
name|Bookmark
argument_list|(
specifier|const
name|Bookmark
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|Bookmark
argument_list|(
name|Bookmark
operator|&&
name|b
argument_list|)
operator|:
name|m_position
argument_list|(
name|b
operator|.
name|m_position
argument_list|)
operator|,
name|m_position_value
argument_list|(
name|b
operator|.
name|m_position_value
argument_list|)
operator|,
name|m_restore
argument_list|(
argument|b.m_restore
argument_list|)
block|{
name|b
operator|.
name|Remove
argument_list|()
block|;     }
name|Bookmark
operator|&
name|operator
operator|=
operator|(
name|Bookmark
operator|&&
operator|)
operator|=
name|delete
expr_stmt|;
name|Bookmark
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Bookmark
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
name|Remove
parameter_list|()
block|{
name|m_restore
operator|=
name|false
expr_stmt|;
block|}
name|size_t
name|GetSavedPosition
parameter_list|()
block|{
return|return
name|m_position_value
return|;
block|}
operator|~
name|Bookmark
argument_list|()
block|{
if|if
condition|(
name|m_restore
condition|)
block|{
name|m_position
operator|=
name|m_position_value
expr_stmt|;
block|}
block|}
name|private
operator|:
name|size_t
operator|&
name|m_position
expr_stmt|;
name|size_t
name|m_position_value
decl_stmt|;
name|bool
name|m_restore
init|=
name|true
decl_stmt|;
block|}
empty_stmt|;
name|bool
name|HasMoreTokens
parameter_list|()
function_decl|;
name|void
name|Advance
parameter_list|()
function_decl|;
name|void
name|TakeBack
parameter_list|()
function_decl|;
name|bool
name|ConsumeToken
argument_list|(
name|clang
operator|::
name|tok
operator|::
name|TokenKind
name|kind
argument_list|)
decl_stmt|;
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|ConsumeToken
argument_list|(
name|Ts
operator|...
name|kinds
argument_list|)
expr_stmt|;
name|Bookmark
name|SetBookmark
parameter_list|()
function_decl|;
name|size_t
name|GetCurrentPosition
parameter_list|()
function_decl|;
name|clang
operator|::
name|Token
operator|&
name|Peek
argument_list|()
expr_stmt|;
name|bool
name|ConsumeBrackets
argument_list|(
name|clang
operator|::
name|tok
operator|::
name|TokenKind
name|left
argument_list|,
name|clang
operator|::
name|tok
operator|::
name|TokenKind
name|right
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|ParsedFunction
operator|>
name|ParseFunctionImpl
argument_list|(
argument|bool expect_return_type
argument_list|)
expr_stmt|;
comment|// Parses functions returning function pointers 'string (*f(int x))(float y)'
name|llvm
operator|::
name|Optional
operator|<
name|ParsedFunction
operator|>
name|ParseFuncPtr
argument_list|(
argument|bool expect_return_type
argument_list|)
expr_stmt|;
comment|// Consumes function arguments enclosed within '(' ... ')'
name|bool
name|ConsumeArguments
parameter_list|()
function_decl|;
comment|// Consumes template arguments enclosed within '<' ... '>'
name|bool
name|ConsumeTemplateArgs
parameter_list|()
function_decl|;
comment|// Consumes '(anonymous namespace)'
name|bool
name|ConsumeAnonymousNamespace
parameter_list|()
function_decl|;
comment|// Consumes operator declaration like 'operator *' or 'operator delete []'
name|bool
name|ConsumeOperator
parameter_list|()
function_decl|;
comment|// Skips 'const' and 'volatile'
name|void
name|SkipTypeQualifiers
parameter_list|()
function_decl|;
comment|// Skips 'const', 'volatile', '&', '&&' in the end of the function.
name|void
name|SkipFunctionQualifiers
parameter_list|()
function_decl|;
comment|// Consumes built-in types like 'int' or 'unsigned long long int'
name|bool
name|ConsumeBuiltinType
parameter_list|()
function_decl|;
comment|// Consumes types defined via decltype keyword.
name|bool
name|ConsumeDecltype
parameter_list|()
function_decl|;
comment|// Skips 'const' and 'volatile'
name|void
name|SkipPtrsAndRefs
parameter_list|()
function_decl|;
comment|// Consumes things like 'const * const&'
name|bool
name|ConsumePtrsAndRefs
parameter_list|()
function_decl|;
comment|// Consumes full type name like 'Namespace::Class<int>::Method()::InnerClass'
name|bool
name|ConsumeTypename
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Optional
operator|<
name|ParsedNameRanges
operator|>
name|ParseFullNameImpl
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|StringRef
name|GetTextForRange
argument_list|(
specifier|const
name|Range
operator|&
name|range
argument_list|)
expr_stmt|;
comment|// Populate m_tokens by calling clang lexer on m_text.
name|void
name|ExtractTokens
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CPlusPlusNameParser_h_
end_comment

end_unit

