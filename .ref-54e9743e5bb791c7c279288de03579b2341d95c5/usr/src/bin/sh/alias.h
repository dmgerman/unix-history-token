begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)alias.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|ALIASINUSE
value|1
end_define

begin_struct
struct|struct
name|alias
block|{
name|struct
name|alias
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|val
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|alias
modifier|*
name|lookupalias
parameter_list|()
function_decl|;
end_function_decl

end_unit

