begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmparam.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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

