begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* _exit.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_expr_stmt
operator|.
name|align
literal|1
name|PSEUDO
argument_list|(
argument|_exit
argument_list|,
argument|exit
argument_list|)
end_expr_stmt

begin_empty
empty|# _exit(status)
end_empty

end_unit

