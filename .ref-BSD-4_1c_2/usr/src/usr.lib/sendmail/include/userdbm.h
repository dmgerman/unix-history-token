begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  USERDBM.H -- user-level definitions for the DBM library ** **	Version: **		@(#)userdbm.h	3.1		10/13/82 */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|DATUM
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|DATUM
name|fetch
parameter_list|()
function_decl|;
end_function_decl

end_unit

