begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  RESP.H -- response blocks ** **	Version: **		@(#)resp.h	7.1	2/5/81 */
end_comment

begin_struct
struct|struct
name|resp
block|{
name|short
name|resp_resp
decl_stmt|;
comment|/* the function value */
name|char
name|resp_active
decl_stmt|;
comment|/*> 0 if in use */
name|long
name|resp_time
decl_stmt|;
comment|/* elapsed time */
name|long
name|resp_tups
decl_stmt|;
comment|/* count of tuples touched */
name|long
name|resp_pread
decl_stmt|;
comment|/* pages read */
name|long
name|resp_pwrit
decl_stmt|;
comment|/* pages written */
comment|/* PARM	resp_rval;	/* the module return value */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|resp
name|Resp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the current response */
end_comment

end_unit

