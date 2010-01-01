begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -O1 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'ret i32 4' %t
end_comment

begin_enum
enum|enum
name|e0
block|{
name|E0
block|}
enum|;
end_enum

begin_struct
struct|struct
name|s0
block|{
name|enum
name|e0
name|a
range|:
literal|31
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s0
name|t1_tmp
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f0
parameter_list|()
block|{
return|return
name|__alignof__
argument_list|(
name|t1_tmp
argument_list|)
return|;
block|}
end_function

end_unit

