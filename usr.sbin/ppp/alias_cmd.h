begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * The code in this file was written by Eivind Eklund<perhaps@yes.no>,  * who places it in the public domain without restriction.  *  *	$Id: alias_cmd.h,v 1.7.2.2 1998/05/01 19:23:44 brian Exp $  */
end_comment

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|alias_RedirectPort
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
name|alias_RedirectAddr
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

