begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i386-linux-gnu -o %t %s
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// PR10392
end_comment

begin_define
define|#
directive|define
name|push
parameter_list|(
name|foo
parameter_list|)
value|push(default)
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|hidden
name|)
end_pragma

begin_decl_stmt
name|int
name|v1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @v1 = common hidden global i32 0, align 4
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_decl_stmt
name|int
name|v2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @v2 = common global i32 0, align 4
end_comment

begin_expr_stmt
name|_Pragma
argument_list|(
literal|"GCC visibility push(hidden)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|v3
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @v3 = common hidden global i32 0, align 4
end_comment

end_unit

