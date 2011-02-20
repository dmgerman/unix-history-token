begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Test pragma pop_macro and push_macro directives from    http://msdn.microsoft.com/en-us/library/hsttss76.aspx */
end_comment

begin_comment
comment|// pop_macro: Sets the value of the macro_name macro to the value on the top of
end_comment

begin_comment
comment|// the stack for this macro.
end_comment

begin_comment
comment|// #pragma pop_macro("macro_name")
end_comment

begin_comment
comment|// push_macro: Saves the value of the macro_name macro on the top of the stack
end_comment

begin_comment
comment|// for this macro.
end_comment

begin_comment
comment|// #pragma push_macro("macro_name")
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -E %s -o - | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|X
value|1
end_define

begin_define
define|#
directive|define
name|Y
value|2
end_define

begin_decl_stmt
name|int
name|pmx0
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pmy0
init|=
name|Y
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|Y
value|3
end_define

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"Y"
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"X"
name|)
end_pragma

begin_decl_stmt
name|int
name|pmx1
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|X
value|2
end_define

begin_decl_stmt
name|int
name|pmx2
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"X"
name|)
end_pragma

begin_decl_stmt
name|int
name|pmx3
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|pop_macro
name|(
literal|"Y"
name|)
end_pragma

begin_decl_stmt
name|int
name|pmy1
init|=
name|Y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Have a stray 'push' to show we don't crash when having inbalanced
end_comment

begin_comment
comment|// push/pop
end_comment

begin_pragma
pragma|#
directive|pragma
name|push_macro
name|(
literal|"Y"
name|)
end_pragma

begin_define
define|#
directive|define
name|Y
value|4
end_define

begin_decl_stmt
name|int
name|pmy2
init|=
name|Y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: int pmx0 = 1
end_comment

begin_comment
comment|// CHECK: int pmy0 = 2
end_comment

begin_comment
comment|// CHECK: int pmx1 = 1
end_comment

begin_comment
comment|// CHECK: int pmx2 = 2
end_comment

begin_comment
comment|// CHECK: int pmx3 = 1
end_comment

begin_comment
comment|// CHECK: int pmy1 = 3
end_comment

begin_comment
comment|// CHECK: int pmy2 = 4
end_comment

end_unit

