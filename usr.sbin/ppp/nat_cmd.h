begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: alias_cmd.h,v 1.3 1997/10/26 01:02:01 brian Exp $  */
end_comment

begin_function_decl
specifier|extern
name|int
name|AliasRedirectPort
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|AliasRedirectAddr
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

