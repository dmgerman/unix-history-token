begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -std=c89 -Eonly -verify -pedantic-errors   */
end_comment

begin_comment
comment|/* PR3919 */
end_comment

begin_define
define|#
directive|define
name|foo
value|`bar
end_define

begin_comment
comment|/* expected-error {{whitespace required after macro name}} */
end_comment

begin_define
define|#
directive|define
name|foo2
value|!bar
end_define

begin_comment
comment|/* expected-warning {{whitespace recommended after macro name}} */
end_comment

begin_define
define|#
directive|define
name|foo3$bar
end_define

begin_comment
comment|/* expected-error {{'$' in identifier}} */
end_comment

end_unit

