begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly -verify -pedantic %s
end_comment

begin_comment
comment|// pasting ""x"" and ""+"" does not give a valid preprocessing token
end_comment

begin_define
define|#
directive|define
name|XYZ
value|x ## +
end_define

begin_decl_stmt
name|XYZ
comment|// expected-error {{pasting formed 'x+', an invalid preprocessing token}}
define|#
directive|define
name|XXYZ
value|. ## test
name|XXYZ
comment|// expected-error {{pasting formed '.test', an invalid preprocessing token}}
comment|// GCC PR 20077
define|#
directive|define
name|a
value|a ## ##
comment|// expected-error {{'##' cannot appear at end of macro expansion}}
define|#
directive|define
name|b
parameter_list|()
value|b ## ##
comment|// expected-error {{'##' cannot appear at end of macro expansion}}
define|#
directive|define
name|c
value|c ##
comment|// expected-error {{'##' cannot appear at end of macro expansion}}
define|#
directive|define
name|d
parameter_list|()
value|d ##
comment|// expected-error {{'##' cannot appear at end of macro expansion}}
define|#
directive|define
name|e
value|## ## e
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
define|#
directive|define
name|f
parameter_list|()
value|## ## f
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
define|#
directive|define
name|g
value|## g
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
define|#
directive|define
name|h
parameter_list|()
value|## h
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
define|#
directive|define
name|i
value|##
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
define|#
directive|define
name|j
parameter_list|()
value|##
comment|// expected-error {{'##' cannot appear at start of macro expansion}}
comment|// Invalid token pasting.
comment|// PR3918
comment|// When pasting creates poisoned identifiers, we error.
pragma|#
directive|pragma
name|GCC
name|poison
name|BLARG
name|BLARG
comment|// expected-error {{attempt to use a poisoned identifier}}
define|#
directive|define
name|XX
value|BL ## ARG
name|XX
comment|// expected-error {{attempt to use a poisoned identifier}}
define|#
directive|define
name|VA
value|__VA_ ## ARGS__
name|int
name|VA
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{__VA_ARGS__ can only appear in the expansion of a C99 variadic macro}}
end_comment

end_unit

