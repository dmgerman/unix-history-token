begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-android -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -x ast -ast-print %t | FileCheck %s
end_comment

begin_extern
extern|extern int a1_0[sizeof(long double
end_extern

begin_expr_stmt
unit|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
expr|]
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|a1_i
index|[
name|__alignof
argument_list|(
argument|long double
argument_list|)
operator|==
literal|16
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Verify that long double is 128 bit IEEEquad
end_comment

begin_decl_stmt
name|long
name|double
name|foo
init|=
literal|1.0E4000L
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: long double foo = 1.00000000000000000000000000000000004E+4000L;
end_comment

end_unit

