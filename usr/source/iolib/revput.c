begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|bufflen
value|100
end_define

begin_macro
name|IEH3revp
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* reversed line IEH3outputter */
specifier|extern
name|char
modifier|*
name|IEH3outp
decl_stmt|,
modifier|*
name|IEH3outlim
decl_stmt|;
operator|*
name|IEH3outp
operator|++
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|IEH3outp
operator|>
name|IEH3outlim
operator|+
literal|100
condition|)
name|IEH3err
argument_list|(
literal|"unprint producing too many chars"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

