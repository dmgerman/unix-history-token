begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  FUNC.H -- declarations for function headers. ** **	Version: **		@(#)func.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* the function definition struct */
end_comment

begin_struct
struct|struct
name|fn_def
block|{
name|char
modifier|*
name|fn_name
decl_stmt|;
comment|/* the name of the function */
name|int
function_decl|(
modifier|*
name|fn_fn
function_decl|)
parameter_list|()
function_decl|;
comment|/* a pointer to the actual function */
name|int
function_decl|(
modifier|*
name|fn_initfn
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialization function */
name|int
function_decl|(
modifier|*
name|fn_cleanup
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt cleanup function */
name|char
modifier|*
name|fn_gptr
decl_stmt|;
comment|/* pointer to global space */
name|unsigned
name|fn_gsize
decl_stmt|;
comment|/* size of global space */
name|short
modifier|*
name|fn_tvect
decl_stmt|;
comment|/* the trace vector itself */
name|short
name|fn_tsize
decl_stmt|;
comment|/* size of trace vector */
name|char
name|fn_tflag
decl_stmt|;
comment|/* the trace flag letter */
name|char
name|fn_active
decl_stmt|;
comment|/*> 0 if active */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fn_def
modifier|*
name|FuncVect
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|NumFunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the number of functions */
end_comment

end_unit

