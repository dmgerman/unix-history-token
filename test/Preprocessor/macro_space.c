begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck --strict-whitespace %s
end_comment

begin_define
define|#
directive|define
name|FOO1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|FOO2
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|FOO3
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|FOO4
parameter_list|(
name|x
parameter_list|)
value|x x
end_define

begin_define
define|#
directive|define
name|FOO5
parameter_list|(
name|x
parameter_list|)
value|x x
end_define

begin_define
define|#
directive|define
name|FOO6
parameter_list|(
name|x
parameter_list|)
value|[x]
end_define

begin_define
define|#
directive|define
name|FOO7
parameter_list|(
name|x
parameter_list|)
value|[ x]
end_define

begin_define
define|#
directive|define
name|FOO8
parameter_list|(
name|x
parameter_list|)
value|[x ]
end_define

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|FOO
parameter_list|,
name|x
parameter_list|)
value|FOO<FOO()>< FOO()><FOO ()><FOO( )><FOO()><FOO()x><FOO() x>< FOO()x>
end_define

begin_macro
name|TEST
argument_list|(
argument|FOO1
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO1<><><><><><><><>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO2
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO2<><><><><><><><>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO3
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO3<><><><><><><><>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO4
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO4<><><><><><><><>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO5
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO5<><><><><><><><>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO6
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO6<[]>< []><[]><[]><[]><[]><[]>< []>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO7
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO7<[ ]>< [ ]><[ ]><[ ]><[ ]><[ ]><[ ]>< [ ]>
end_comment

begin_macro
name|TEST
argument_list|(
argument|FOO8
argument_list|,)
end_macro

begin_comment
comment|// CHECK: FOO8<[ ]>< [ ]><[ ]><[ ]><[ ]><[ ]><[ ]>< [ ]>
end_comment

end_unit

