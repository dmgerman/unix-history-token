begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	callout.h	4.3	81/02/27	*/
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|callo
modifier|*
name|callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ncallo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

