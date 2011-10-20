begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__v2di
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|__v4si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function_decl
name|__v2di
name|bar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|int
name|X
parameter_list|,
name|__v4si
modifier|*
name|P
parameter_list|)
block|{
operator|*
name|P
operator|=
name|X
operator|==
literal|2
condition|?
name|bar
argument_list|()
else|:
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

