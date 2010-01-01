begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep -- '-"" , - "" , -"" , - ""'
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|b
parameter_list|)
value|-#b  ,  - #b  ,  -# b  ,  - # b
end_define

begin_macro
name|A
argument_list|()
end_macro

end_unit

