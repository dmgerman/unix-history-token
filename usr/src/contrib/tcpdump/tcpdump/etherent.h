begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: etherent.h,v 1.2 90/09/20 23:16:17 mccanne Exp $ (LBL)  */
end_comment

begin_comment
comment|/* File name of ethernet address data base. */
end_comment

begin_define
define|#
directive|define
name|ETHERS_FILE
value|"/etc/ethers"
end_define

begin_struct
struct|struct
name|etherent
block|{
name|u_char
name|addr
index|[
literal|6
index|]
decl_stmt|;
name|char
name|name
index|[
literal|122
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|etherent
modifier|*
name|next_etherent
parameter_list|()
function_decl|;
end_function_decl

end_unit

