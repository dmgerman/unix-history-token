begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/kinfo_proc.h>
end_include

begin_macro
name|md_core
argument_list|(
argument|kd
argument_list|,
argument|fd
argument_list|,
argument|ki
argument_list|)
end_macro

begin_decl_stmt
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|kinfo_proc
modifier|*
name|ki
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Don't need to fix anything for this architecture. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

