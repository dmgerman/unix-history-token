begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)linetab.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * definition of line number information table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|LINENO
name|line
decl_stmt|;
name|ADDRESS
name|addr
decl_stmt|;
block|}
name|LINETAB
typedef|;
end_typedef

begin_decl_stmt
name|LINETAB
modifier|*
name|linetab
decl_stmt|;
end_decl_stmt

end_unit

