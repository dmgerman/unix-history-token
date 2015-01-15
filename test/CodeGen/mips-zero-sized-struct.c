begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mips-unknown-linux-gnu -S -emit-llvm -o - %s | FileCheck -check-prefix=O32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux-gnu -S -emit-llvm -o - %s | FileCheck -check-prefix=O32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -S -emit-llvm -o - %s -mabi=n32 | FileCheck -check-prefix=N32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux-gnu -S -emit-llvm -o - %s -mabi=n32 | FileCheck -check-prefix=N32 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -S -emit-llvm -o - %s | FileCheck -check-prefix=N64 %s
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux-gnu -S -emit-llvm -o - %s | FileCheck -check-prefix=N64 %s
end_comment

begin_comment
comment|// O32: define void @fn28(%struct.T2* noalias sret %agg.result, i8 signext %arg0)
end_comment

begin_comment
comment|// N32: define void @fn28(i8 signext %arg0)
end_comment

begin_comment
comment|// N64: define void @fn28(i8 signext %arg0)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|T2
block|{  }
name|T2
typedef|;
end_typedef

begin_decl_stmt
name|T2
name|T2_retval
decl_stmt|;
end_decl_stmt

begin_function
name|T2
name|fn28
parameter_list|(
name|char
name|arg0
parameter_list|)
block|{
return|return
name|T2_retval
return|;
block|}
end_function

end_unit

