begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -rewrite-macros -o %t
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_comment
comment|// Any CHECK line comments are included in the output, so we use some extra
end_comment

begin_comment
comment|// regex brackets to make sure we don't match the CHECK lines themselves.
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_comment
comment|// CHECK: {{^}} 12 /*A*/ /*(1,2)*/{{$}}
end_comment

begin_macro
name|A
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|// CHECK: {{^}} /*_Pragma("mark")*/{{$}}
end_comment

begin_macro
name|_Pragma
argument_list|(
literal|"mark"
argument_list|)
end_macro

begin_comment
comment|// CHECK: /*#warning eek*/{{$}}
end_comment

begin_comment
comment|/* expected-warning {{eek}} */
end_comment

begin_warning
warning|#
directive|warning
warning|eek
end_warning

begin_comment
comment|// CHECK: {{^}}//#pragma mark mark{{$}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|mark
name|mark
end_pragma

end_unit

