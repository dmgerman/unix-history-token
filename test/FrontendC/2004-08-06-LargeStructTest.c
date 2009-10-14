begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|X
parameter_list|)
value|int X;
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|X
parameter_list|)
value|A(X##0) A(X##1) A(X##2) A(X##3) A(X##4) A(X##5) A(X##6) A(X##7) \              A(X##8) A(X##9) A(X##A) A(X##B) A(X##C) A(X##D) A(X##E) A(X##F)
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
name|X
parameter_list|)
value|B(X##0) B(X##1) B(X##2) B(X##3) B(X##4) B(X##5) B(X##6) B(X##7) \              B(X##8) B(X##9) B(X##A) B(X##B) B(X##C) B(X##D) B(X##E) B(X##F)
end_define

begin_struct
struct|struct
name|foo
block|{
name|C
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// 256
name|C
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// 256
name|C
argument_list|(
name|z
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|test
parameter_list|(
name|struct
name|foo
modifier|*
name|F
parameter_list|)
block|{
return|return
name|F
operator|->
name|xA1
operator|+
name|F
operator|->
name|yFF
operator|+
name|F
operator|->
name|zC4
return|;
block|}
end_function

end_unit

