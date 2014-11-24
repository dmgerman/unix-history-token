begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple %itanium_abi_triple -fsyntax-only -verify -Wc++-compat
end_comment

begin_comment
comment|// Note: Empty C structs are 4 bytes in the Microsoft ABI.
end_comment

begin_struct
struct|struct
name|emp_1
block|{
comment|// expected-warning {{empty struct has size 0 in C, size 1 in C++}}
block|}
struct|;
end_struct

begin_union
union|union
name|emp_2
block|{
comment|// expected-warning {{empty union has size 0 in C, size 1 in C++}}
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_3
block|{
comment|// expected-warning {{struct has size 0 in C, size 1 in C++}}
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|emp_4
block|{
comment|// expected-warning {{union has size 0 in C, size 1 in C++}}
name|int
label|:
literal|0
expr_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_5
block|{
comment|// expected-warning {{struct has size 0 in C, size 1 in C++}}
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|emp_6
block|{
comment|// expected-warning {{union has size 0 in C, size 1 in C++}}
name|int
label|:
literal|0
expr_stmt|;
name|int
label|:
literal|0
expr_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_7
block|{
comment|// expected-warning {{struct has size 0 in C, size 1 in C++}}
name|struct
name|emp_1
name|f1
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|emp_8
block|{
comment|// expected-warning {{union has size 0 in C, size 1 in C++}}
name|struct
name|emp_1
name|f1
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|emp_9
block|{
comment|// expected-warning {{struct has size 0 in C, non-zero size in C++}}
name|struct
name|emp_1
name|f1
decl_stmt|;
name|union
name|emp_2
name|f2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Checks for pointer subtraction (PR15683)
end_comment

begin_function
name|struct
name|emp_1
modifier|*
name|func_1p
parameter_list|(
name|struct
name|emp_1
modifier|*
name|x
parameter_list|)
block|{
return|return
name|x
operator|-
literal|5
return|;
block|}
end_function

begin_function
name|int
name|func_1
parameter_list|()
block|{
name|struct
name|emp_1
name|v
index|[
literal|1
index|]
decl_stmt|;
return|return
name|v
operator|-
name|v
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1' of zero size has undefined behavior}}
block|}
end_function

begin_function
name|int
name|func_2
parameter_list|(
name|struct
name|emp_1
modifier|*
name|x
parameter_list|)
block|{
return|return
literal|1
operator|+
name|x
operator|-
name|x
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1' of zero size has undefined behavior}}
block|}
end_function

begin_function
name|int
name|func_3
parameter_list|(
name|struct
name|emp_1
modifier|*
name|x
parameter_list|,
name|struct
name|emp_1
modifier|*
name|y
parameter_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1' of zero size has undefined behavior}}
block|}
end_function

begin_function
name|int
name|func_4
parameter_list|(
name|struct
name|emp_1
modifier|*
name|x
parameter_list|,
specifier|const
name|struct
name|emp_1
modifier|*
name|y
parameter_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1' of zero size has undefined behavior}}
block|}
end_function

begin_function
name|int
name|func_5
parameter_list|(
specifier|volatile
name|struct
name|emp_1
modifier|*
name|x
parameter_list|,
specifier|const
name|struct
name|emp_1
modifier|*
name|y
parameter_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1' of zero size has undefined behavior}}
block|}
end_function

begin_function
name|int
name|func_6
parameter_list|()
block|{
name|union
name|emp_2
name|v
index|[
literal|1
index|]
decl_stmt|;
return|return
name|v
operator|-
name|v
return|;
comment|// expected-warning {{subtraction of pointers to type 'union emp_2' of zero size has undefined behavior}}
block|}
end_function

begin_struct_decl
struct_decl|struct
name|A
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note {{forward declaration of 'struct A'}}
end_comment

begin_function
name|int
name|func_7
parameter_list|(
name|struct
name|A
modifier|*
name|x
parameter_list|,
name|struct
name|A
modifier|*
name|y
parameter_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-error {{arithmetic on a pointer to an incomplete type 'struct A'}}
block|}
end_function

begin_decl_stmt
name|int
name|func_8
argument_list|(
expr|struct
name|emp_1
argument_list|(
operator|*
name|x
argument_list|)
index|[
literal|10
index|]
argument_list|,
expr|struct
name|emp_1
argument_list|(
operator|*
name|y
argument_list|)
index|[
literal|10
index|]
argument_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-warning {{subtraction of pointers to type 'struct emp_1 [10]' of zero size has undefined behavior}}
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|func_9
argument_list|(
expr|struct
name|emp_1
argument_list|(
operator|*
name|x
argument_list|)
index|[]
argument_list|,
expr|struct
name|emp_1
argument_list|(
operator|*
name|y
argument_list|)
index|[]
argument_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-error {{arithmetic on a pointer to an incomplete type 'struct emp_1 []'}}
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|func_10
argument_list|(
name|int
argument_list|(
operator|*
name|x
argument_list|)
index|[
literal|0
index|]
argument_list|,
name|int
argument_list|(
operator|*
name|y
argument_list|)
index|[
literal|0
index|]
argument_list|)
block|{
return|return
name|x
operator|-
name|y
return|;
comment|// expected-warning {{subtraction of pointers to type 'int [0]' of zero size has undefined behavior}}
block|}
end_decl_stmt

end_unit

