begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips64-linux-gnu -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Transparent unions are passed according to the calling convention rules of
end_comment

begin_comment
comment|// the first member. In this case, it is as if it were a void pointer so we
end_comment

begin_comment
comment|// do not have the inreg attribute we would normally have for unions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This comes up in glibc's wait() function and matters for the big-endian N32
end_comment

begin_comment
comment|// case where pointers are promoted to i64 and a non-transparent union would be
end_comment

begin_comment
comment|// passed in the upper 32-bits of an i64.
end_comment

begin_union
union|union
name|either_pointer
block|{
name|void
modifier|*
name|void_ptr
decl_stmt|;
name|int
modifier|*
name|int_ptr
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|transparent_union
operator|)
argument_list|)
union|;
end_union

begin_function_decl
specifier|extern
name|void
name|foo
parameter_list|(
name|union
name|either_pointer
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|foo
argument_list|(
operator|&
name|data
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @bar()
end_comment

begin_comment
comment|// CHECK:         call void @foo(i8* %{{[0-9]+}})
end_comment

begin_comment
comment|// CHECK: declare void @foo(i8*)
end_comment

end_unit

