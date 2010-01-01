begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep '^ # define X 3$'
end_comment

begin_define
define|#
directive|define
name|H
value|#
end_define

begin_define
define|#
directive|define
name|D
value|define
end_define

begin_define
define|#
directive|define
name|DEFINE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|H D a b
end_define

begin_macro
name|DEFINE
argument_list|(
argument|X
argument_list|,
literal|3
argument_list|)
end_macro

end_unit

