begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declare getopt() and associated variables. */
end_comment

begin_comment
comment|/* Don't use prototypes in case some system header file has a conflicting definition.  Systems differ on how they declare the second parameter. */
end_comment

begin_function_decl
specifier|extern
name|int
name|getopt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

end_unit

