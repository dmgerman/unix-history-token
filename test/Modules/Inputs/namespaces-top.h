begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|namespace
name|N1
block|{
name|int
modifier|&
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|N2
block|{
name|int
modifier|&
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|N3
block|{
name|int
modifier|&
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|N12
block|{ }
end_decl_stmt

begin_decl_stmt
name|namespace
name|N13
block|{
name|void
name|f
parameter_list|()
function_decl|;
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|()
init|=
operator|&
name|f
function_decl|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|AddAndReexportBeforeImport
block|{
name|int
name|S
decl_stmt|;
block|}
end_decl_stmt

end_unit

