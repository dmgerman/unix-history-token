begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dev.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<stand/stand.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|nodev
argument_list|(
argument|io
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|noioctl
argument_list|(
argument|io
argument_list|,
argument|cmd
argument_list|,
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iob
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_block

end_unit

