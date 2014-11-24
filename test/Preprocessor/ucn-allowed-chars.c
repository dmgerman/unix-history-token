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
comment|// Identifier characters
end_comment

begin_extern
extern|extern char a\u01F6;
end_extern

begin_comment
comment|// C11, C++11
end_comment

begin_extern
extern|extern char a\u00AA;
end_extern

begin_comment
comment|// C99, C11, C++11
end_comment

begin_extern
extern|extern char a\u0384;
end_extern

begin_comment
comment|// C++03, C11, C++11
end_comment

begin_extern
extern|extern char a\u0E50;
end_extern

begin_comment
comment|// C99, C++03, C11, C++11
end_comment

begin_extern
extern|extern char a\uFFFF;
end_extern

begin_comment
comment|// none
end_comment

begin_comment
comment|// Identifier initial characters
end_comment

begin_extern
extern|extern char \u0E50;
end_extern

begin_comment
comment|// C++03, C11, C++11
end_comment

begin_extern
extern|extern char \u0300;
end_extern

begin_comment
comment|// disallowed initially in C11/C++11, always in C99/C++03
end_comment

begin_extern
extern|extern char \u0D61;
end_extern

begin_comment
comment|// C99, C11, C++03, C++11
end_comment

begin_comment
comment|// Disallowed everywhere
end_comment

begin_define
define|#
directive|define
name|A
value|\u0000
end_define

begin_comment
comment|// expected-error{{control character}}
end_comment

begin_define
define|#
directive|define
name|B
value|\u001F
end_define

begin_comment
comment|// expected-error{{control character}}
end_comment

begin_define
define|#
directive|define
name|C
value|\u007F
end_define

begin_comment
comment|// expected-error{{control character}}
end_comment

begin_define
define|#
directive|define
name|D
value|\u009F
end_define

begin_comment
comment|// expected-error{{control character}}
end_comment

begin_define
define|#
directive|define
name|E
value|\uD800
end_define

begin_comment
comment|// C++03 allows UCNs representing surrogate characters!
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
comment|// expected-warning@7 {{using this character in an identifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-warning@8 {{using this character in an identifier is incompatible with C++98}}
end_comment

begin_comment
comment|// expected-error@11 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@19 {{expected unqualified-id}}
end_comment

begin_comment
comment|// expected-error@33 {{invalid universal character}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// C++03
end_comment

begin_comment
comment|// expected-error@7 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@8 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@11 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@19 {{expected unqualified-id}}
end_comment

begin_comment
comment|// expected-warning@33 {{universal character name refers to a surrogate character}}
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
comment|// expected-warning@7 {{using this character in an identifier is incompatible with C99}}
end_comment

begin_comment
comment|// expected-warning@9 {{using this character in an identifier is incompatible with C99}}
end_comment

begin_comment
comment|// expected-error@11 {{expected ';'}}
end_comment

begin_comment
comment|// expected-warning@18 {{starting an identifier with this character is incompatible with C99}}
end_comment

begin_comment
comment|// expected-error@19 {{expected identifier}}
end_comment

begin_comment
comment|// expected-error@33 {{invalid universal character}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// C99
end_comment

begin_comment
comment|// expected-error@7 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@9 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@11 {{expected ';'}}
end_comment

begin_comment
comment|// expected-error@18 {{expected identifier}}
end_comment

begin_comment
comment|// expected-error@19 {{expected identifier}}
end_comment

begin_comment
comment|// expected-error@33 {{invalid universal character}}
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

