begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * The code in this file was written by Eivind Eklund<perhaps@yes.no>,  * who places it in the public domain without restriction.  *  *	$Id: alias_cmd.h,v 1.6 1997/12/21 14:28:24 brian Exp $  */
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

