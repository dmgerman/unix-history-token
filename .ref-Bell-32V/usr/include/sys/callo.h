begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The callout structure is for  * a routine arranging  * to be called by the clock interrupt  * (clock.c) with a specified argument,  * in a specified amount of time.  * Used, for example, to time tab  * delays on typewriters.  */
end_comment

begin_struct
struct|struct
name|callo
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|caddr_t
name|c_arg
decl_stmt|;
comment|/* argument to routine */
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|callo
name|callout
index|[
name|NCALL
index|]
decl_stmt|;
end_decl_stmt

end_unit

