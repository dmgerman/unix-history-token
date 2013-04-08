begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
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

begin_comment
comment|// CHECK: {{^}}-"" , - "" , -"" , - ""{{$}}
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

begin_comment
comment|// CHECK: {{^}}"a c"{{$}}
end_comment

end_unit

