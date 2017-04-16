begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -S -emit-llvm -o - -O0 %s | FileCheck %s -check-prefix=CHECK-O0
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -S -emit-llvm -o - -O0 \
end_comment

begin_comment
comment|// RUN:     -fsanitize=address -fsanitize-address-use-after-scope %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck %s -check-prefix=CHECK-ASAN-USE-AFTER-SCOPE
end_comment

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|(
name|char
modifier|*
name|A
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-O0-NOT: @llvm.lifetime.start
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
condition|)
block|{
comment|// CHECK-ASAN-USE-AFTER-SCOPE: @llvm.lifetime.start.p0i8(i64 10, i8* {{.*}})
name|char
name|A
index|[
literal|10
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK-ASAN-USE-AFTER-SCOPE: @llvm.lifetime.end.p0i8(i64 10, i8* {{.*}})
block|}
else|else
block|{
comment|// CHECK-ASAN-USE-AFTER-SCOPE: @llvm.lifetime.start.p0i8(i64 20, i8* {{.*}})
name|char
name|A
index|[
literal|20
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK-ASAN-USE-AFTER-SCOPE: @llvm.lifetime.end.p0i8(i64 20, i8* {{.*}})
block|}
block|}
end_function

end_unit

