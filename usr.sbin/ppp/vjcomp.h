begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: vjcomp.h,v 1.2 1997/10/26 12:42:13 brian Exp $  */
end_comment

begin_function_decl
specifier|extern
name|void
name|VjInit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SendPppFrame
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|VjCompInput
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|vj2asc
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

end_unit

