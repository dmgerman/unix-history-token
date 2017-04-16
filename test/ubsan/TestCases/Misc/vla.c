begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsanitize=vla-bound %s -O3 -o %t
end_comment

begin_comment
comment|// RUN: %run %t 2>&1 | FileCheck %s --check-prefix=CHECK-MINUS-ONE
end_comment

begin_comment
comment|// RUN: %run %t a 2>&1 | FileCheck %s --check-prefix=CHECK-ZERO
end_comment

begin_comment
comment|// RUN: %run %t a b
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CHECK-MINUS-ONE: vla.c:[[@LINE+2]]:11: runtime error: variable length array bound evaluates to non-positive value -1
comment|// CHECK-ZERO: vla.c:[[@LINE+1]]:11: runtime error: variable length array bound evaluates to non-positive value 0
name|int
name|arr
index|[
name|argc
operator|-
literal|2
index|]
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

