begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -std=c99 -pedantic -verify -Wundef
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -x c++ -pedantic -verify -Wundef
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -fsyntax-only -std=c99 -pedantic -Wundef 2>&1 | FileCheck -strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|\
value|u00FC
end_define

begin_define
define|#
directive|define
name|a
value|\u00FD() 0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|\
name|u00FC
end_ifndef

begin_error
error|#
directive|error
literal|"This should never happen"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|a
operator|\
name|u00FD
argument_list|()
end_if

begin_error
error|#
directive|error
literal|"This should never happen"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|a
operator|\
name|U000000FD
argument_list|()
end_if

begin_error
error|#
directive|error
literal|"This should never happen"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|\
name|uarecool
end_if

begin_comment
comment|// expected-warning{{incomplete universal character name; treating as '\' followed by identifier}} expected-error {{invalid token at start of a preprocessor expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|\
name|uwerecool
end_if

begin_comment
comment|// expected-warning{{\u used with no following hex digits; treating as '\' followed by identifier}} expected-error {{invalid token at start of a preprocessor expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|\
name|U0001000
end_if

begin_comment
comment|// expected-warning{{incomplete universal character name; treating as '\' followed by identifier}} expected-error {{invalid token at start of a preprocessor expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Make sure we reject disallowed UCNs
end_comment

begin_define
define|#
directive|define
name|\
value|ufffe
end_define

begin_comment
comment|// expected-error {{macro name must be an identifier}}
end_comment

begin_define
define|#
directive|define
name|\
value|U10000000
end_define

begin_comment
comment|// expected-error {{macro name must be an identifier}}
end_comment

begin_define
define|#
directive|define
name|\
value|u0061
end_define

begin_comment
comment|// expected-error {{character 'a' cannot be specified by a universal character name}} expected-error {{macro name must be an identifier}}
end_comment

begin_comment
comment|// FIXME: Not clear what our behavior should be here; \u0024 is "$".
end_comment

begin_define
define|#
directive|define
name|a
value|\u0024
end_define

begin_comment
comment|// expected-warning {{whitespace}}
end_comment

begin_if
if|#
directive|if
operator|\
name|u0110
end_if

begin_comment
comment|// expected-warning {{is not defined, evaluates to 0}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|\
value|u0110 1 / 0
end_define

begin_if
if|#
directive|if
operator|\
name|u0110
end_if

begin_comment
comment|// expected-error {{division by zero in preprocessor expression}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRINGIZE
parameter_list|(
name|X
parameter_list|)
value|# X
end_define

begin_decl_stmt
specifier|extern
name|int
name|check_size
index|[
sizeof|sizeof
argument_list|(
name|STRINGIZE
argument_list|(
operator|\
name|u0112
argument_list|)
argument_list|)
operator|==
literal|3
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check that we still diagnose disallowed UCNs in #if 0 blocks.
end_comment

begin_comment
comment|// C99 5.1.1.2p1 and C++11 [lex.phases]p1 dictate that preprocessor tokens are
end_comment

begin_comment
comment|// formed before directives are parsed.
end_comment

begin_comment
comment|// expected-error@+4 {{character 'a' cannot be specified by a universal character name}}
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|\
value|ufffe
end_define

begin_comment
comment|// okay
end_comment

begin_define
define|#
directive|define
name|\
value|U10000000
end_define

begin_comment
comment|// okay
end_comment

begin_define
define|#
directive|define
name|\
value|u0061
end_define

begin_comment
comment|// error, but -verify only looks at comments outside #if 0
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A UCN formed by token pasting is undefined in both C99 and C++.
end_comment

begin_comment
comment|// Right now we don't do anything special, which causes us to coincidentally
end_comment

begin_comment
comment|// accept the first case below but reject the second two.
end_comment

begin_define
define|#
directive|define
name|PASTE
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|A ## B
end_define

begin_decl_stmt
specifier|extern
name|int
name|PASTE
argument_list|(
operator|\
argument_list|,
name|u00FD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PASTE
argument_list|(
operator|\
name|u
argument_list|,
literal|00FD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{\u used with no following hex digits}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|PASTE
argument_list|(
operator|\
name|u0
argument_list|,
literal|0FD
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{incomplete universal character name}}
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// expected-error@-3 {{expected unqualified-id}}
end_comment

begin_comment
comment|// expected-error@-3 {{expected unqualified-id}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-error@-6 {{expected identifier}}
end_comment

begin_comment
comment|// expected-error@-6 {{expected identifier}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// A UCN produced by line splicing is valid in C99 but undefined in C++.
end_comment

begin_comment
comment|// Since undefined behavior can do anything including working as intended,
end_comment

begin_comment
comment|// we just accept it in C++ as well.;
end_comment

begin_define
define|#
directive|define
name|newline_1_
value|\u00F\ C 1
end_define

begin_define
define|#
directive|define
name|newline_2_
value|\u00\ F\ C 1
end_define

begin_define
define|#
directive|define
name|newline_3_
value|\u\ 00\ FC 1
end_define

begin_define
define|#
directive|define
name|newline_4_
value|\\ u00FC 1
end_define

begin_define
define|#
directive|define
name|newline_5_
value|\\ u\ \ 0\ 0\ F\ C 1
end_define

begin_if
if|#
directive|if
operator|(
name|newline_1_
operator|\
name|u00FC
operator|&&
name|newline_2_
operator|\
name|u00FC
operator|&&
name|newline_3_
operator|\
name|u00FC
operator|&&
expr|\
name|newline_4_
operator|\
name|u00FC
operator|&&
name|newline_5_
operator|\
name|u00FC
operator|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Line splicing failed to produce UCNs"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|capital_u_
value|\U00FC
end_define

begin_comment
comment|// expected-warning@-1 {{incomplete universal character name}} expected-note@-1 {{did you mean to use '\u'?}} expected-warning@-1 {{whitespace}}
end_comment

begin_comment
comment|// CHECK: note: did you mean to use '\u'?
end_comment

begin_comment
comment|// CHECK-NEXT:   #define capital_u_\U00FC
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                   \^}}
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                   u}}
end_comment

end_unit

