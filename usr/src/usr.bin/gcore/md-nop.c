begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)md-nop.c	5.5 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

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
file|"extern.h"
end_include

begin_function
name|void
name|md_core
parameter_list|(
name|kd
parameter_list|,
name|fd
parameter_list|,
name|ki
parameter_list|)
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|struct
name|kinfo_proc
modifier|*
name|ki
decl_stmt|;
block|{
comment|/* Don't need to fix anything for this architecture. */
return|return;
block|}
end_function

end_unit

