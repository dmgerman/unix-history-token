begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fno-builtin
end_comment

begin_define
define|#
directive|define
name|_diagnose_if
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__((diagnose_if(__VA_ARGS__)))
end_define

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{exactly 3 arguments}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{exactly 3 arguments}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{exactly 3 arguments}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
operator|,
function_decl|"error"
operator|,
function_decl|1
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{exactly 3 arguments}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|0
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{requires a string}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
operator|,
function_decl|"invalid"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{invalid diagnostic type for 'diagnose_if'; use "error" or "warning" instead}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
operator|,
function_decl|"ERROR"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{invalid diagnostic type}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
name|a
parameter_list|,
function_decl|""
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{invalid diagnostic type}}
end_comment

begin_function_decl
name|void
name|failure
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
name|a
parameter_list|,
function_decl|""
operator|,
function_decl|""
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{undeclared identifier 'a'}}
end_comment

begin_decl_stmt
name|int
name|globalVar
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|never_constant
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
name|globalVar
parameter_list|,
function_decl|""
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'diagnose_if' attribute expression never produces a constant expression}} expected-note{{subexpression not valid}}
end_comment

begin_function_decl
name|void
name|never_constant
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
name|globalVar
parameter_list|,
function_decl|""
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'diagnose_if' attribute expression never produces a constant expression}} expected-note{{subexpression not valid}}
end_comment

begin_function_decl
name|int
name|alwaysok
parameter_list|(
name|int
name|q
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|neverok
parameter_list|(
name|int
name|q
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"oh no"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 5{{from 'diagnose_if' attribute on 'neverok'}}
end_comment

begin_function_decl
name|int
name|alwayswarn
parameter_list|(
name|int
name|q
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"oh no"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 5{{from 'diagnose_if' attribute}}
end_comment

begin_function_decl
name|int
name|neverwarn
parameter_list|(
name|int
name|q
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|0
operator|,
function_decl|""
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|runConstant
parameter_list|()
block|{
name|int
name|m
decl_stmt|;
name|alwaysok
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|alwaysok
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|alwaysok
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|{
name|int
function_decl|(
modifier|*
name|pok
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|alwaysok
function_decl|;
name|pok
operator|=
operator|&
name|alwaysok
expr_stmt|;
block|}
name|neverok
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
name|neverok
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
name|neverok
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
block|{
name|int
function_decl|(
modifier|*
name|pok
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|neverok
function_decl|;
comment|// expected-error{{oh no}}
name|pok
operator|=
operator|&
name|neverok
expr_stmt|;
comment|// expected-error{{oh no}}
block|}
name|alwayswarn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{oh no}}
name|alwayswarn
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{oh no}}
name|alwayswarn
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|// expected-warning{{oh no}}
block|{
name|int
function_decl|(
modifier|*
name|pok
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|alwayswarn
function_decl|;
comment|// expected-warning{{oh no}}
name|pok
operator|=
operator|&
name|alwayswarn
expr_stmt|;
comment|// expected-warning{{oh no}}
block|}
name|neverwarn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|neverwarn
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|neverwarn
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|{
name|int
function_decl|(
modifier|*
name|pok
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|neverwarn
function_decl|;
name|pok
operator|=
operator|&
name|neverwarn
expr_stmt|;
block|}
block|}
end_function

begin_function_decl
name|int
name|abs
parameter_list|(
name|int
name|q
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|q>= 0
operator|,
function_decl|"redundant abs call"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-note{{from 'diagnose_if'}}
end_comment

begin_function
name|void
name|runVariable
parameter_list|()
block|{
name|int
name|m
decl_stmt|;
name|abs
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|abs
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{redundant abs call}}
name|abs
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|*
name|pabs
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|abs
function_decl|;
name|pabs
operator|=
operator|&
name|abs
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|_overloadable
value|__attribute__((overloadable))
end_define

begin_decl_stmt
name|int
name|ovl1
argument_list|(
specifier|const
name|char
operator|*
name|n
argument_list|)
name|_overloadable
name|_diagnose_if
argument_list|(
name|n
argument_list|,
literal|"oh no"
argument_list|,
literal|"error"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_decl_stmt
name|int
name|ovl1
argument_list|(
name|void
operator|*
name|m
argument_list|)
name|_overloadable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ovl2
argument_list|(
specifier|const
name|char
operator|*
name|n
argument_list|)
name|_overloadable
name|_diagnose_if
argument_list|(
name|n
argument_list|,
literal|"oh no"
argument_list|,
literal|"error"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_decl_stmt
name|int
name|ovl2
argument_list|(
name|char
operator|*
name|m
argument_list|)
name|_overloadable
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{candidate function}}
end_comment

begin_function
name|void
name|overloadsYay
parameter_list|()
block|{
name|ovl1
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|ovl1
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
name|ovl2
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{ambiguous}}
block|}
end_function

begin_function_decl
name|void
name|errorWarnDiagnose1
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"oh no"
operator|,
function_decl|"error"
end_function_decl

begin_comment
unit|)
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_expr_stmt
name|_diagnose_if
argument_list|(
literal|1
argument_list|,
literal|"nop"
argument_list|,
literal|"warning"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|errorWarnDiagnose2
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"oh no"
operator|,
function_decl|"error"
end_function_decl

begin_comment
unit|)
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_expr_stmt
name|_diagnose_if
argument_list|(
literal|1
argument_list|,
literal|"nop"
argument_list|,
literal|"error"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|errorWarnDiagnose3
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"nop"
operator|,
function_decl|"warning"
end_function_decl

begin_expr_stmt
unit|)
name|_diagnose_if
argument_list|(
literal|1
argument_list|,
literal|"oh no"
argument_list|,
literal|"error"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|errorWarnDiagnoseArg1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a == 1
operator|,
function_decl|"oh no"
operator|,
function_decl|"error"
end_function_decl

begin_comment
unit|)
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_expr_stmt
name|_diagnose_if
argument_list|(
name|a
operator|==
literal|1
argument_list|,
literal|"nop"
argument_list|,
literal|"warning"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|errorWarnDiagnoseArg2
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a == 1
operator|,
function_decl|"oh no"
operator|,
function_decl|"error"
end_function_decl

begin_comment
unit|)
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_expr_stmt
name|_diagnose_if
argument_list|(
name|a
operator|==
literal|1
argument_list|,
literal|"nop"
argument_list|,
literal|"error"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|errorWarnDiagnoseArg3
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a == 1
operator|,
function_decl|"nop"
operator|,
function_decl|"warning"
end_function_decl

begin_expr_stmt
unit|)
name|_diagnose_if
argument_list|(
name|a
operator|==
literal|1
argument_list|,
literal|"oh no"
argument_list|,
literal|"error"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function
name|void
name|runErrorWarnDiagnose
parameter_list|()
block|{
name|errorWarnDiagnose1
argument_list|()
expr_stmt|;
comment|// expected-error{{oh no}}
name|errorWarnDiagnose2
argument_list|()
expr_stmt|;
comment|// expected-error{{oh no}}
name|errorWarnDiagnose3
argument_list|()
expr_stmt|;
comment|// expected-error{{oh no}}
name|errorWarnDiagnoseArg1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
name|errorWarnDiagnoseArg2
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
name|errorWarnDiagnoseArg3
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{oh no}}
block|}
end_function

begin_function_decl
name|void
name|warnWarnDiagnose
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"oh no!"
operator|,
function_decl|"warning"
end_function_decl

begin_expr_stmt
unit|)
name|_diagnose_if
argument_list|(
literal|1
argument_list|,
literal|"foo"
argument_list|,
literal|"warning"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-note 2{{from 'diagnose_if'}}
end_comment

begin_function
name|void
name|runWarnWarnDiagnose
parameter_list|()
block|{
name|warnWarnDiagnose
argument_list|()
expr_stmt|;
comment|// expected-warning{{oh no!}} expected-warning{{foo}}
block|}
end_function

begin_function_decl
name|void
name|declsStackErr1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a& 1
operator|,
function_decl|"decl1"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackErr1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a& 2
operator|,
function_decl|"decl2"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackErr2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|declsStackErr2
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"complaint"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackErr3
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"complaint"
operator|,
function_decl|"error"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackErr3
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|runDeclsStackErr
parameter_list|()
block|{
name|declsStackErr1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|declsStackErr1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-error{{decl1}}
name|declsStackErr1
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error{{decl2}}
name|declsStackErr1
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// expected-error{{decl1}}
name|declsStackErr2
argument_list|()
expr_stmt|;
comment|// expected-error{{complaint}}
name|declsStackErr3
argument_list|()
expr_stmt|;
comment|// expected-error{{complaint}}
block|}
end_function

begin_function_decl
name|void
name|declsStackWarn1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a& 1
operator|,
function_decl|"decl1"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackWarn1
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|a& 2
operator|,
function_decl|"decl2"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackWarn2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|declsStackWarn2
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"complaint"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackWarn3
parameter_list|()
function_decl|_diagnose_if
parameter_list|(
function_decl|1
operator|,
function_decl|"complaint"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function_decl
name|void
name|declsStackWarn3
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|runDeclsStackWarn
parameter_list|()
block|{
name|declsStackWarn1
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|declsStackWarn1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{decl1}}
name|declsStackWarn1
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|// expected-warning{{decl2}}
name|declsStackWarn1
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|// expected-warning{{decl1}} expected-warning{{decl2}}
name|declsStackWarn2
argument_list|()
expr_stmt|;
comment|// expected-warning{{complaint}}
name|declsStackWarn3
argument_list|()
expr_stmt|;
comment|// expected-warning{{complaint}}
block|}
end_function

begin_function_decl
name|void
name|noMsg
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
name|n
parameter_list|,
function_decl|""
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function
name|void
name|runNoMsg
parameter_list|()
block|{
name|noMsg
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{<no message provided>}}
block|}
end_function

begin_function_decl
name|void
name|alwaysWarnWithArg
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|_diagnose_if
parameter_list|(
function_decl|1 || a
operator|,
function_decl|"alwaysWarn"
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note{{from 'diagnose_if'}}
end_comment

begin_function
name|void
name|runAlwaysWarnWithArg
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|alwaysWarnWithArg
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning{{alwaysWarn}}
block|}
end_function

begin_comment
comment|// Test that diagnose_if warnings generated in system headers are not ignored.
end_comment

begin_include
include|#
directive|include
file|"Inputs/diagnose-if-warn-system-header.h"
end_include

begin_comment
comment|// Bug: we would complain about `a` being undeclared if this was spelled
end_comment

begin_comment
comment|// __diagnose_if__.
end_comment

begin_function_decl
name|void
name|underbarName
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__diagnose_if__
parameter_list|(
name|a
parameter_list|,
function_decl|""
operator|,
function_decl|"warning"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

end_unit

