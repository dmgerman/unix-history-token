begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)bivar.h	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * Software status per BI node.  */
end_comment

begin_struct
struct|struct
name|binode_status
block|{
comment|/*	int	bh_type;		/* type of adapter */
name|struct
name|biiregs
modifier|*
name|bh_bi
decl_stmt|;
comment|/* virt addr of registers */
name|struct
name|biiregs
modifier|*
name|bh_physbi
decl_stmt|;
comment|/* phys addr of registers */
name|int
name|bh_errcnt
decl_stmt|;
comment|/* number of errors */
name|int
name|bh_ivec
decl_stmt|;
comment|/* interrupt vector */
name|int
name|bh_arb
decl_stmt|;
comment|/* arbitration */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ... per BI  */
end_comment

begin_struct
struct|struct
name|bi_hd
block|{
name|short
name|bh_nodes
decl_stmt|;
comment|/* which nodes are present */
name|struct
name|binode_status
name|bh_nodes
index|[
literal|16
index|]
decl_stmt|;
comment|/* info about those nodes */
block|}
struct|;
end_struct

end_unit

