begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)parser.h	3.2 84/01/13  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"context.h"
end_include

begin_include
include|#
directive|include
file|"token.h"
end_include

begin_include
include|#
directive|include
file|"string.h"
end_include

begin_define
define|#
directive|define
name|p_erred
parameter_list|()
value|(cx.x_erred)
end_define

begin_define
define|#
directive|define
name|p_synerred
parameter_list|()
value|(cx.x_synerred)
end_define

begin_define
define|#
directive|define
name|p_clearerr
parameter_list|()
value|(cx.x_erred = cx.x_synerred = 0)
end_define

begin_define
define|#
directive|define
name|p_abort
parameter_list|()
value|(cx.x_abort)
end_define

end_unit

