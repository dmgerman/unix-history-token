begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
operator|(
operator|*
name|Copyright
argument_list|(
name|c
argument_list|)
literal|1979
name|Regents
name|of
name|the
name|University
name|of
name|California
operator|*
operator|)
specifier|const
name|sccsid
operator|=
literal|'@(#)unixio.h 1.1 6/17/81'
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|type
name|fileptr
init|=
name|record
name|cnt
operator|:
name|integer
name|end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|function
name|TELL
argument_list|(
name|var
name|fptr
operator|:
name|text
argument_list|)
block|{
name|returns
block|}
end_decl_stmt

begin_expr_stmt
unit|:
name|fileptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|external
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|procedure
name|SEEK
argument_list|(
name|var
name|fptr
operator|:
name|text
argument_list|;
name|var
name|cnt
operator|:
name|fileptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|external
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|procedure
name|APPEND
argument_list|(
name|var
name|fptr
operator|:
name|text
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|external
expr_stmt|;
end_expr_stmt

end_unit

