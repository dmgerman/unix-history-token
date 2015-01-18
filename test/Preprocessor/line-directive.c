begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fsyntax-only -verify -pedantic %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -E %s 2>&1 | grep 'blonk.c:92:2: error: ABC'
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -E %s 2>&1 | grep 'blonk.c:93:2: error: DEF'
end_comment

begin_line
line|#
directive|line
end_line

begin_file
file|'a'
end_file

begin_comment
comment|// expected-error {{#line directive requires a positive integer argument}}
end_comment

begin_line
line|#
directive|line
number|0
end_line

begin_comment
comment|// expected-warning {{#line directive with zero argument is a GNU extension}}
end_comment

begin_line
line|#
directive|line
number|00
end_line

begin_comment
comment|// expected-warning {{#line directive with zero argument is a GNU extension}}
end_comment

begin_line
line|#
directive|line
number|2147483648
end_line

begin_comment
comment|// expected-warning {{C requires #line number to be less than 2147483648, allowed as extension}}
end_comment

begin_line
line|#
directive|line
number|42
end_line

begin_comment
comment|// ok
end_comment

begin_line
line|#
directive|line
number|42
file|'a'
end_line

begin_comment
comment|// expected-error {{invalid filename for #line directive}}
end_comment

begin_line
line|#
directive|line
number|42
file|"foo/bar/baz.h"
end_line

begin_comment
comment|// ok
end_comment

begin_comment
comment|// #line directives expand macros.
end_comment

begin_define
define|#
directive|define
name|A
value|42 "foo"
end_define

begin_line
line|#
directive|line
line|A
end_line

begin_empty
empty|# 42
end_empty

begin_empty
empty|# 42 "foo"
end_empty

begin_empty
empty|# 42 "foo" 2
end_empty

begin_comment
comment|// expected-error {{invalid line marker flag '2': cannot pop empty include stack}}
end_comment

begin_empty
empty|# 42 "foo" 1 3
end_empty

begin_comment
comment|// enter
end_comment

begin_empty
empty|# 42 "foo" 2 3
end_empty

begin_comment
comment|// exit
end_comment

begin_empty
empty|# 42 "foo" 2 3 4
end_empty

begin_comment
comment|// expected-error {{invalid line marker flag '2': cannot pop empty include stack}}
end_comment

begin_empty
empty|# 42 "foo" 3 4
end_empty

begin_empty
empty|# 'a'
end_empty

begin_comment
comment|// expected-error {{invalid preprocessing directive}}
end_comment

begin_empty
empty|# 42 'f'
end_empty

begin_comment
comment|// expected-error {{invalid filename for line marker directive}}
end_comment

begin_empty
empty|# 42 1 3
end_empty

begin_comment
comment|// expected-error {{invalid filename for line marker directive}}
end_comment

begin_empty
empty|# 42 "foo" 3 1
end_empty

begin_comment
comment|// expected-error {{invalid flag line marker directive}}
end_comment

begin_empty
empty|# 42 "foo" 42
end_empty

begin_comment
comment|// expected-error {{invalid flag line marker directive}}
end_comment

begin_empty
empty|# 42 "foo" 1 2
end_empty

begin_comment
comment|// expected-error {{invalid flag line marker directive}}
end_comment

begin_empty
empty|# 42a33
end_empty

begin_comment
comment|// expected-error {{GNU line marker directive requires a simple digit sequence}}
end_comment

begin_comment
comment|// These are checked by the RUN line.
end_comment

begin_line
line|#
directive|line
number|92
file|"blonk.c"
end_line

begin_error
error|#
directive|error
error|ABC
end_error

begin_error
error|#
directive|error
error|DEF
end_error

begin_comment
comment|// expected-error@-2 {{ABC}}
end_comment

begin_line
line|#
directive|line
number|150
end_line

begin_comment
comment|// expected-error@-3 {{DEF}}
end_comment

begin_comment
comment|// Verify that linemarker diddling of the system header flag works.
end_comment

begin_empty
empty|# 192 "glomp.h"
end_empty

begin_comment
comment|// not a system header.
end_comment

begin_typedef
typedef|typedef
name|int
name|x
typedef|;
end_typedef

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_typedef
typedef|typedef
name|int
name|x
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{redefinition of typedef 'x' is a C11 feature}}
end_comment

begin_empty
empty|# 192 "glomp.h" 3
end_empty

begin_comment
comment|// System header.
end_comment

begin_typedef
typedef|typedef
name|int
name|y
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_typedef
typedef|typedef
name|int
name|y
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_typedef
typedef|typedef
name|int
name|q
typedef|;
end_typedef

begin_comment
comment|// q is in system header.
end_comment

begin_line
line|#
directive|line
number|42
file|"blonk.h"
end_line

begin_comment
comment|// doesn't change system headerness.
end_comment

begin_typedef
typedef|typedef
name|int
name|z
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_typedef
typedef|typedef
name|int
name|z
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_empty
empty|# 97
end_empty

begin_comment
comment|// doesn't change system headerness.
end_comment

begin_typedef
typedef|typedef
name|int
name|z1
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_typedef
typedef|typedef
name|int
name|z1
typedef|;
end_typedef

begin_comment
comment|// ok
end_comment

begin_empty
empty|# 42 "blonk.h"
end_empty

begin_comment
comment|// DOES change system headerness.
end_comment

begin_typedef
typedef|typedef
name|int
name|w
typedef|;
end_typedef

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_typedef
typedef|typedef
name|int
name|w
typedef|;
end_typedef

begin_comment
comment|// expected-warning {{redefinition of typedef 'w' is a C11 feature}}
end_comment

begin_typedef
typedef|typedef
name|int
name|q
typedef|;
end_typedef

begin_comment
comment|// original definition in system header, should not diagnose.
end_comment

begin_comment
comment|// This should not produce an "extra tokens at end of #line directive" warning,
end_comment

begin_comment
comment|// because #line is allowed to contain expanded tokens.
end_comment

begin_define
define|#
directive|define
name|EMPTY
parameter_list|()
end_define

begin_line
line|#
directive|line
number|2
file|"foo.c"
line|EMPTY( )
end_line

begin_line
line|#
directive|line
number|2
file|"foo.c"
line|NONEMPTY( )
end_line

begin_comment
comment|// expected-warning{{extra tokens at end of #line directive}}
end_comment

begin_comment
comment|// PR3940
end_comment

begin_line
line|#
directive|line
number|0xf
end_line

begin_comment
comment|// expected-error {{#line directive requires a simple digit sequence}}
end_comment

begin_line
line|#
directive|line
number|42U
end_line

begin_comment
comment|// expected-error {{#line directive requires a simple digit sequence}}
end_comment

begin_comment
comment|// Line markers are digit strings interpreted as decimal numbers, this is
end_comment

begin_comment
comment|// 10, not 8.
end_comment

begin_line
line|#
directive|line
number|010
end_line

begin_comment
comment|// expected-warning {{#line directive interprets number as decimal, not octal}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|array
index|[
name|__LINE__
operator|==
literal|10
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_empty
empty|# 020
end_empty

begin_comment
comment|// expected-warning {{GNU line marker directive interprets number as decimal, not octal}}
end_comment

begin_decl_stmt
specifier|extern
name|int
name|array_gnuline
index|[
name|__LINE__
operator|==
literal|20
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PR3917 */
end_comment

begin_line
line|#
directive|line
number|41
end_line

begin_decl_stmt
specifier|extern
name|char
name|array2
index|[\
name|_
expr|\
name|_LINE__
operator|==
literal|42
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line marker is location of first _ */
end_comment

begin_empty
empty|# 51
end_empty

begin_decl_stmt
specifier|extern
name|char
name|array2_gnuline
index|[\
name|_
expr|\
name|_LINE__
operator|==
literal|52
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line marker is location of first _ */
end_comment

begin_comment
comment|// rdar://11550996
end_comment

begin_line
line|#
directive|line
number|0
file|"line-directive.c"
end_line

begin_comment
comment|// expected-warning {{#line directive with zero argument is a GNU extension}}
end_comment

begin_decl_stmt
name|undefined
name|t
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{unknown type name 'undefined'}}
end_comment

end_unit

