begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple x86_64-linux %s
end_comment

begin_define
define|#
directive|define
name|EVAL_EXPR
parameter_list|(
name|testno
parameter_list|,
name|expr
parameter_list|)
value|int test##testno = sizeof(struct{char qq[expr];});
end_define

begin_comment
comment|//<rdar://problem/10962435>
end_comment

begin_macro
name|EVAL_EXPR
argument_list|(
literal|1
argument_list|,
argument|((char*)-
literal|1LL
argument|) +
literal|1
argument|==
literal|0
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

begin_macro
name|EVAL_EXPR
argument_list|(
literal|2
argument_list|,
argument|((char*)-
literal|1LL
argument|) +
literal|1
argument|< (char*) -
literal|1
argument|?
literal|1
argument|: -
literal|1
argument_list|)
end_macro

end_unit

