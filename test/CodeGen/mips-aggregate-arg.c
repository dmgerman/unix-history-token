begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-unknown-linux-gnu -S -emit-llvm -o - %s | FileCheck -check-prefix=O32 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-unknown-linux-gnu -S -emit-llvm -o - %s  -target-abi n32 | FileCheck -check-prefix=N32-N64 %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-unknown-linux-gnu -S -emit-llvm -o - %s  -target-abi n64 | FileCheck -check-prefix=N32-N64 %s
end_comment

begin_struct
struct|struct
name|t1
block|{
name|char
name|t1
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t2
block|{
name|char
name|t2
index|[
literal|20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t3
block|{
name|char
name|t3
index|[
literal|65
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|t1
name|g1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|t2
name|g2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|t3
name|g3
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|f1
parameter_list|(
name|struct
name|t1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f2
parameter_list|(
name|struct
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|f3
parameter_list|(
name|struct
name|t3
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f
parameter_list|()
block|{
comment|// O32:  call void @f1(i32 inreg %{{[0-9]+}}, i32 inreg %{{[0-9]+}}, i16 inreg %{{[0-9]+}})
comment|// O32:  call void @f2(%struct.t2* byval align 4 %{{.*}})
comment|// O32:  call void @f3(%struct.t3* byval align 4 %{{.*}})
comment|// N32-N64:  call void @f1(i64 inreg %{{[0-9]+}}, i16 inreg %{{[0-9]+}})
comment|// N32-N64:  call void @f2(i64 inreg %{{[0-9]+}}, i64 inreg %{{[0-9]+}}, i32 inreg %{{[0-9]+}})
comment|// N32-N64:  call void @f3(%struct.t3* byval align 8 %{{.*}})
name|f1
argument_list|(
name|g1
argument_list|)
expr_stmt|;
name|f2
argument_list|(
name|g2
argument_list|)
expr_stmt|;
name|f3
argument_list|(
name|g3
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

