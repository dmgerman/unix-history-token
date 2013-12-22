begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-unknown-nacl | FileCheck %s
end_comment

begin_decl_stmt
name|long
name|double
name|x
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|checksize
index|[
sizeof|sizeof
argument_list|(
name|x
argument_list|)
operator|==
literal|8
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define void @s1(double %a)
end_comment

begin_function
name|void
name|s1
parameter_list|(
name|long
name|double
name|a
parameter_list|)
block|{}
end_function

end_unit

