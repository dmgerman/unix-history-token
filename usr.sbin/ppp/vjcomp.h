begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: vjcomp.h,v 1.1 1997/10/26 01:04:02 brian Exp $  */
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

end_unit

