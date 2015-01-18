begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-win32 %s -emit-llvm -fms-compatibility -o - | FileCheck %s
end_comment

begin_decl_stmt
name|char
name|__declspec
argument_list|(
name|align
argument_list|(
literal|8192
argument_list|)
argument_list|)
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @x = global i8 0, align 8192
end_comment

begin_typedef
typedef|typedef
name|char
name|__declspec
argument_list|(
name|align
argument_list|(
literal|8192
argument_list|)
argument_list|)
name|T
typedef|;
end_typedef

begin_decl_stmt
name|T
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @y = global i8 0, align 8192
end_comment

begin_decl_stmt
name|T
name|__declspec
argument_list|(
name|align
argument_list|(
literal|8192
argument_list|)
argument_list|)
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @z = global i8 0, align 8192
end_comment

begin_decl_stmt
name|int
name|__declspec
argument_list|(
name|align
argument_list|(
literal|16
argument_list|)
argument_list|)
name|redef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__declspec
argument_list|(
name|align
argument_list|(
literal|32
argument_list|)
argument_list|)
name|redef
init|=
literal|8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @redef = global i32 8, align 32
end_comment

end_unit

