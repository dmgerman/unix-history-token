begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vmparam.h	7.2 (Berkeley) 5/14/88  */
end_comment

begin_comment
comment|/*  * Machine dependent constants  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|STANDALONE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"../machine/vmparam.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_decl_stmt
name|int
name|klseql
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|klsdist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|klin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kltxt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|klout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

