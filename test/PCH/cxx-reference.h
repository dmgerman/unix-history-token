begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-reference.cpp
end_comment

begin_typedef
typedef|typedef
name|char
argument_list|(
operator|&
name|LR
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|char
argument_list|(
operator|&&
name|RR
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|&
name|lr
init|=
name|c
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|char
operator|&&
name|rr
operator|=
literal|'c'
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LR
modifier|&
name|lrlr
init|=
name|c
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|LR
operator|&&
name|rrlr
operator|=
name|c
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|RR
modifier|&
name|lrrr
init|=
name|c
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RR
operator|&&
name|rrrr
operator|=
literal|'c'
expr_stmt|;
end_expr_stmt

end_unit

