begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)var.h	3.4 84/01/13  */
end_comment

begin_struct
struct|struct
name|var
block|{
name|struct
name|var
modifier|*
name|r_left
decl_stmt|;
name|struct
name|var
modifier|*
name|r_right
decl_stmt|;
name|char
modifier|*
name|r_name
decl_stmt|;
name|struct
name|value
name|r_val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|var
modifier|*
name|var_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|var_setstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|var_setnum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
modifier|*
name|var_lookup1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|var_walk
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|)
value|var_walk1(var_head, (f), (a))
end_define

begin_define
define|#
directive|define
name|var_lookup
parameter_list|(
name|n
parameter_list|)
value|(*var_lookup1(n))
end_define

begin_decl_stmt
name|struct
name|var
modifier|*
name|var_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* secret, shhh */
end_comment

end_unit

