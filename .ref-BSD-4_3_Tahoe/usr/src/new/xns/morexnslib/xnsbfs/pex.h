begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: pex.h,v 1.1 86/06/27 13:14:37 jqj Exp $ */
end_comment

begin_comment
comment|/* $Log:	pex.h,v $  * Revision 1.1  86/06/27  13:14:37  jqj  * Initial revision  *   */
end_comment

begin_comment
comment|/*	pex.h	1.1	85/01/26	*/
end_comment

begin_comment
comment|/*  * Packet Exchange protocol header.  * See XSIS 028112, December 1981  */
end_comment

begin_struct
struct|struct
name|pex
block|{
name|u_short
name|ph_idh
decl_stmt|,
name|ph_idl
decl_stmt|;
comment|/* `unique' transaction identifier */
name|u_short
name|ph_client
decl_stmt|;
comment|/* client type field */
block|}
struct|;
end_struct

end_unit

