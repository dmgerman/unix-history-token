begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: CH.h,v 2.0 85/11/21 07:22:27 jqj Exp $ */
end_comment

begin_comment
comment|/*  * $Log:	CH.h,v $  * Revision 2.0  85/11/21  07:22:27  jqj  * 4.3BSD standard release  *   * Revision 1.1  85/11/21  07:01:27  root  * Initial revision  *   */
end_comment

begin_comment
comment|/*  * definitions for routines distributed as part of the Clearinghouse  * support package.  See clearinghouse(3) for documentation.  */
end_comment

begin_comment
comment|/*  * other include files needed:  * #include<sys/types.h>  * #include<netns/ns.h>  * #include<courier/Clearinghouse2.h>  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ns_addr
modifier|*
name|CH_LookupAddr
argument_list|()
decl_stmt|,
modifier|*
name|CH_LookupAddrDN
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CourierConnection
modifier|*
name|CH_GetFirstCH
argument_list|()
decl_stmt|,
modifier|*
name|CH_GetOtherCH
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Clearinghouse2_ObjectName
name|CH_StringToName
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern CH_Enumerate(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|CH_EnumerateAliases
argument_list|()
expr_stmt|;
end_expr_stmt

end_unit

