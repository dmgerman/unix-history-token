begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley Software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dir.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure for entries in directory stack.  */
end_comment

begin_struct
struct|struct
name|directory
block|{
name|struct
name|directory
modifier|*
name|di_next
decl_stmt|;
comment|/* next in loop */
name|struct
name|directory
modifier|*
name|di_prev
decl_stmt|;
comment|/* prev in loop */
name|unsigned
name|short
modifier|*
name|di_count
decl_stmt|;
comment|/* refcount of processes */
name|char
modifier|*
name|di_name
decl_stmt|;
comment|/* actual name */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|directory
modifier|*
name|dcwd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the one we are in now */
end_comment

end_unit

