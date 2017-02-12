begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header for the getopt() we supply if the platform doesn't supply it.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt(3) external variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|,
name|opterr
decl_stmt|,
name|optopt
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|getopt
parameter_list|(
name|int
name|nargc
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|nargv
parameter_list|,
specifier|const
name|char
modifier|*
name|ostr
parameter_list|)
function_decl|;
end_function_decl

end_unit

