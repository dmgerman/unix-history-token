begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alloc.h */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|SIZE_T
typedef|;
end_typedef

begin_comment
comment|/* Like malloc and realloc, but don't return if no memory is available. */
end_comment

begin_decl_stmt
specifier|extern
name|UNIV
name|xmalloc
name|P
argument_list|(
operator|(
name|SIZE_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UNIV
name|xrealloc
name|P
argument_list|(
operator|(
name|UNIV
operator|,
name|SIZE_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

