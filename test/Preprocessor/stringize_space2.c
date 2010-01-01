begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 -E %s | grep 'a c'  */
end_comment

begin_define
define|#
directive|define
name|t
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_macro
name|t
argument_list|(
argument|a c
argument_list|)
end_macro

end_unit

