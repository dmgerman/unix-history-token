begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of routines shared between local and client/server    "update" code.  */
end_comment

begin_comment
comment|/* List of files that we have either processed or are willing to    ignore.  Any file not on this list gets a question mark printed.  */
end_comment

begin_decl_stmt
specifier|extern
name|List
modifier|*
name|ignlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|update_filesdone_proc
name|PROTO
argument_list|(
operator|(
name|int
name|err
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

