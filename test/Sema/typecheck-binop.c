begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -fsyntax-only -pedantic -verify  */
end_comment

begin_struct_decl
struct_decl|struct
name|incomplete
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note{{forward declaration of 'struct incomplete'}}
end_comment

begin_function
name|int
name|sub1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|double
modifier|*
name|b
parameter_list|)
block|{
return|return
name|a
operator|-
name|b
return|;
comment|/* expected-error{{not pointers to compatible types}} */
block|}
end_function

begin_function
name|void
modifier|*
name|sub2
parameter_list|(
name|struct
name|incomplete
modifier|*
name|P
parameter_list|)
block|{
return|return
name|P
operator|-
literal|4
return|;
comment|/* expected-error{{subtraction of pointer 'struct incomplete *' requires pointee to be a complete object type}} */
block|}
end_function

begin_function
name|void
modifier|*
name|sub3
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
block|{
return|return
name|P
operator|-
literal|4
return|;
comment|/* expected-warning{{GNU void* extension}} */
block|}
end_function

begin_function
name|int
name|sub4
parameter_list|(
name|void
modifier|*
name|P
parameter_list|,
name|void
modifier|*
name|Q
parameter_list|)
block|{
return|return
name|P
operator|-
name|Q
return|;
comment|/* expected-warning{{GNU void* extension}} */
block|}
end_function

begin_function
name|int
name|sub5
parameter_list|(
name|void
modifier|*
name|P
parameter_list|,
name|int
modifier|*
name|Q
parameter_list|)
block|{
return|return
name|P
operator|-
name|Q
return|;
comment|/* expected-error{{not pointers to compatible types}} */
block|}
end_function

begin_function
name|int
name|logicaland1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
operator|&&
operator|(
name|void
operator|)
name|a
return|;
comment|/* expected-error{{invalid operands}} */
block|}
end_function

end_unit

