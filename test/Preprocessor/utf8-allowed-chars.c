begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -std=c99 -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -std=c11 -Wc99-compat -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -x c++ -std=c++03 -Wc++11-compat -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -x c++ -std=c++11 -Wc++98-compat -verify
end_comment

begin_comment
comment|// Note: This file contains Unicode characters; please do not remove them!
end_comment

begin_comment
comment|// Identifier characters
end_comment

begin_decl_stmt
specifier|extern
name|char
name|aÇ¶
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C11, C++11
end_comment

begin_decl_stmt
specifier|extern
name|char
name|aÂª
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C99, C11, C++11
end_comment

begin_decl_stmt
specifier|extern
name|char
name|aÎ
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C++03, C11, C++11
end_comment

begin_decl_stmt
specifier|extern
name|char
name|aà¹
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C99, C++03, C11, C++11
end_comment

begin_decl_stmt
specifier|extern
name|char
name|aï¹
decl_stmt|;
end_decl_stmt

begin_comment
comment|// none
end_comment

begin_decl_stmt
specifier|extern
name|char
name|xÌ
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C11, C++11. Note that this does not have a composed form.
end_comment

begin_comment
comment|// Identifier initial characters
end_comment

begin_decl_stmt
specifier|extern
name|char
name|à¹
decl_stmt|;
end_decl_stmt

begin_comment
comment|// C++03, C11, C++11
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Ì
decl_stmt|;
end_decl_stmt

begin_comment
comment|// disallowed initially in C11/C++11, always in C99/C++03
end_comment

begin_if
if|#
directive|if
name|__cplusplus
end_if

begin_if
if|#
directive|if
name|__cplusplus
operator|>=
literal|201103L
end_if

begin_comment
comment|// C++11
end_comment

begin_comment
comment|// expected-warning@9 {{using this character in an identifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-warning@10 {{using this character in an identifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-error@13 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-warning@14 {{using this character in an identifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-error@21 {{expected unqualified-id}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// C++03
end_comment

begin_comment
comment|// expected-error@9 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@10 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@13 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@14 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@21 {{non-ASCII characters are not allowed outside of literals and identifiers}} expected-warning@21 {{declaration does not declare anything}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|>=
literal|201112L
end_if

begin_comment
comment|// C11
end_comment

begin_comment
comment|// expected-warning@9 {{using this character in an identifier is incompatible with C99}}
end_comment

begin_comment
comment|// expected-warning@11 {{using this character in an identifier is incompatible with C99}}
end_comment

begin_comment
comment|// expected-error@13 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-warning@14 {{using this character in an identifier is incompatible with C99}}
end_comment

begin_comment
comment|// expected-warning@20 {{starting an identifier with this character is incompatible with C99}}
end_comment

begin_comment
comment|// expected-error@21 {{expected identifier}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// C99
end_comment

begin_comment
comment|// expected-error@9 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@11 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@13 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@14 {{non-ASCII characters are not allowed outside of literals and identifiers}}
end_comment

begin_comment
comment|// expected-error@20 {{expected identifier}}
end_comment

begin_comment
comment|// expected-error@21 {{non-ASCII characters are not allowed outside of literals and identifiers}} expected-warning@21 {{declaration does not declare anything}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

