begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)lcmd.h	3.2 84/03/23  */
end_comment

begin_define
define|#
directive|define
name|LCMD_NARG
value|20
end_define

begin_comment
comment|/* maximum number of arguments */
end_comment

begin_struct
struct|struct
name|lcmd_tab
block|{
name|char
modifier|*
name|lc_name
decl_stmt|;
name|int
name|lc_minlen
decl_stmt|;
name|int
function_decl|(
modifier|*
name|lc_func
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|lcmd_arg
modifier|*
name|lc_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lcmd_arg
block|{
name|char
modifier|*
name|arg_name
decl_stmt|;
name|int
name|arg_minlen
decl_stmt|;
name|char
name|arg_type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARG_ANY
value|0
end_define

begin_define
define|#
directive|define
name|ARG_NUM
value|1
end_define

begin_define
define|#
directive|define
name|ARG_STR
value|2
end_define

begin_function_decl
name|struct
name|lcmd_tab
modifier|*
name|lcmd_lookup
parameter_list|()
function_decl|;
end_function_decl

end_unit

