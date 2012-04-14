begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -Wdisabled-macro-expansion -verify
end_comment

begin_define
define|#
directive|define
name|p
value|p
end_define

begin_define
define|#
directive|define
name|a
value|b
end_define

begin_define
define|#
directive|define
name|b
value|a
end_define

begin_define
define|#
directive|define
name|f
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|g
parameter_list|(
name|b
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|h
parameter_list|(
name|x
parameter_list|)
value|i(x)
end_define

begin_define
define|#
directive|define
name|i
parameter_list|(
name|y
parameter_list|)
value|i(y)
end_define

begin_define
define|#
directive|define
name|c
parameter_list|(
name|x
parameter_list|)
value|x(0)
end_define

begin_decl_stmt
name|p
comment|// expected-warning {{recursive macro}}
name|a
comment|// expected-warning {{recursive macro}}
name|f
argument_list|(
literal|2
argument_list|)
name|g
argument_list|(
literal|3
argument_list|)
comment|// expected-warning {{recursive macro}}
name|h
argument_list|(
literal|0
argument_list|)
comment|// expected-warning {{recursive macro}}
name|c
argument_list|(
name|c
argument_list|)
end_decl_stmt

begin_comment
comment|// expected-warning {{recursive macro}}
end_comment

end_unit

