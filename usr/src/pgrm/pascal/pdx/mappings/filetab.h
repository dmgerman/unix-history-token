begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)filetab.h	5.1 (Berkeley) 6/6/85  */
end_comment

begin_comment
comment|/*  * definition of file table  */
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
name|char
modifier|*
name|filename
decl_stmt|;
name|LINENO
name|lineindex
decl_stmt|;
block|}
name|FILETAB
typedef|;
end_typedef

begin_decl_stmt
name|FILETAB
modifier|*
name|filetab
decl_stmt|;
end_decl_stmt

end_unit

