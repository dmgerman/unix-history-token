begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * The code in this file was written by Eivind Eklund<perhaps@yes.no>,  * who places it in the public domain without restriction.  *  *	$Id: alias_cmd.h,v 1.11 1999/05/08 11:06:01 brian Exp $  */
end_comment

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|nat_RedirectPort
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
name|nat_RedirectAddr
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
name|nat_ProxyRule
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
name|nat_Pptp
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|layer
name|natlayer
decl_stmt|;
end_decl_stmt

end_unit

