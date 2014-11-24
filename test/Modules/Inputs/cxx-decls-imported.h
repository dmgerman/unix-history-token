begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|class
name|HasFriends
block|{
name|friend
name|void
name|friend_1
parameter_list|(
name|HasFriends
parameter_list|)
function_decl|;
name|friend
name|void
name|friend_2
parameter_list|(
name|HasFriends
parameter_list|)
function_decl|;
name|void
name|private_thing
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|HasNontrivialDefaultConstructor
block|{
name|HasNontrivialDefaultConstructor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|HasNontrivialDefaultConstructor
argument_list|(
argument|int n =
literal|0
argument_list|)
empty_stmt|;
comment|// Ensure this class is not POD but is still trivially-copyable.
comment|// This is necessary to exercise the second static_assert below,
comment|// because GCC's spec for __has_trivial_constructor is absurd.
name|int
name|m
decl_stmt|;
name|private
label|:
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|static_assert
argument_list|(
operator|!
name|__is_trivial
argument_list|(
name|HasNontrivialDefaultConstructor
argument_list|)
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
operator|!
name|__has_trivial_constructor
argument_list|(
name|HasNontrivialDefaultConstructor
argument_list|)
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
modifier|*
name|operator
name|new
function_decl|[]
parameter_list|(
name|__SIZE_TYPE__
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|mergeUsedFlag
decl_stmt|;
end_decl_stmt

begin_function
specifier|inline
name|int
name|getMergeUsedFlag
parameter_list|()
block|{
return|return
name|mergeUsedFlag
return|;
block|}
end_function

end_unit

