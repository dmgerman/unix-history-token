begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|foo
end_pragma

begin_comment
comment|// expected-error {{expected 'begin' or 'end'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|begin
name|foo
end_pragma

begin_comment
comment|// expected-warning {{extra tokens at end of #pragma directive}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|end
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|end
end_pragma

begin_comment
comment|// expected-error {{not currently inside '#pragma clang arc_cf_code_audited'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|begin
end_pragma

begin_comment
comment|// expected-note {{#pragma entered here}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|begin
end_pragma

begin_comment
comment|// expected-error {{already inside '#pragma clang arc_cf_code_audited'}} expected-note {{#pragma entered here}}
end_comment

begin_include
include|#
directive|include
file|"Inputs/pragma-arc-cf-code-audited.h"
end_include

begin_comment
comment|// expected-error {{cannot #include files inside '#pragma clang arc_cf_code_audited'}}
end_comment

begin_comment
comment|// This is actually on the #pragma line in the header.
end_comment

begin_comment
comment|// expected-error@Inputs/pragma-arc-cf-code-audited.h:16 {{'#pragma clang arc_cf_code_audited' was not ended within this file}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|arc_cf_code_audited
name|begin
end_pragma

begin_comment
comment|// expected-error {{'#pragma clang arc_cf_code_audited' was not ended within this file}}
end_comment

end_unit

