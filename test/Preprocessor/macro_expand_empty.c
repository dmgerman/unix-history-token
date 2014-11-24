begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_comment
comment|// Check that this doesn't crash
end_comment

begin_define
define|#
directive|define
name|IDENTITY1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|IDENTITY2
parameter_list|(
name|x
parameter_list|)
value|IDENTITY1(x) IDENTITY1(x) IDENTITY1(x) IDENTITY1(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY3
parameter_list|(
name|x
parameter_list|)
value|IDENTITY2(x) IDENTITY2(x) IDENTITY2(x) IDENTITY2(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY4
parameter_list|(
name|x
parameter_list|)
value|IDENTITY3(x) IDENTITY3(x) IDENTITY3(x) IDENTITY3(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY5
parameter_list|(
name|x
parameter_list|)
value|IDENTITY4(x) IDENTITY4(x) IDENTITY4(x) IDENTITY4(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY6
parameter_list|(
name|x
parameter_list|)
value|IDENTITY5(x) IDENTITY5(x) IDENTITY5(x) IDENTITY5(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY7
parameter_list|(
name|x
parameter_list|)
value|IDENTITY6(x) IDENTITY6(x) IDENTITY6(x) IDENTITY6(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY8
parameter_list|(
name|x
parameter_list|)
value|IDENTITY7(x) IDENTITY7(x) IDENTITY7(x) IDENTITY7(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY9
parameter_list|(
name|x
parameter_list|)
value|IDENTITY8(x) IDENTITY8(x) IDENTITY8(x) IDENTITY8(x)
end_define

begin_define
define|#
directive|define
name|IDENTITY0
parameter_list|(
name|x
parameter_list|)
value|IDENTITY9(x) IDENTITY9(x) IDENTITY9(x) IDENTITY9(x)
end_define

begin_macro
name|IDENTITY0
argument_list|()
end_macro

begin_define
define|#
directive|define
name|FOO
parameter_list|()
value|BAR() second
end_define

begin_define
define|#
directive|define
name|BAR
parameter_list|()
end_define

begin_expr_stmt
name|first
comment|// CHECK: {{^}}first{{$}}
name|FOO
argument_list|()
comment|// CHECK: {{^}} second{{$}}
name|third
end_expr_stmt

begin_comment
comment|// CHECK: {{^}}third{{$}}
end_comment

end_unit

