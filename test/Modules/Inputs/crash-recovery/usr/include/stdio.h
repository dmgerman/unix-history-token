begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|id
decl_stmt|;
block|}
name|FILE
typedef|;
end_typedef

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stderrp
decl_stmt|;
end_decl_stmt

end_unit

