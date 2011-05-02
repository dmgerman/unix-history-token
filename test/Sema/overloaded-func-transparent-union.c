begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// rdar:// 9129552
end_comment

begin_comment
comment|// PR9406
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|char
modifier|*
name|str2
decl_stmt|;
block|}
name|Class
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Class
modifier|*
name|object
decl_stmt|;
block|}
name|Instance
name|__attribute__
typedef|((
name|transparent_union
typedef|));
end_typedef

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function
name|void
name|Class_Init
parameter_list|(
name|Instance
name|this
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|void
modifier|*
name|str2
parameter_list|)
block|{
name|this
operator|.
name|object
operator|->
name|str
operator|=
name|str
expr_stmt|;
name|this
operator|.
name|object
operator|->
name|str2
operator|=
name|str2
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function
name|void
name|Class_Init
parameter_list|(
name|Instance
name|this
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
block|{
name|this
operator|.
name|object
operator|->
name|str
operator|=
name|str
expr_stmt|;
name|this
operator|.
name|object
operator|->
name|str2
operator|=
name|str
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|Class
name|obj
decl_stmt|;
name|Class_Init
argument_list|(
operator|&
name|obj
argument_list|,
literal|"Hello "
argument_list|,
literal|" World"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

