begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: db_trace.c,v 1.1 1997/09/06 02:00:50 thorpej Exp $ */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* RCS ID& Copyright macro defns */
end_comment

begin_comment
comment|/* __KERNEL_RCSID(0, "$NetBSD: db_trace.c,v 1.1 1997/09/06 02:00:50 thorpej Exp $"); */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_sym.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_access.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_variables.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_output.h>
end_include

begin_function
name|void
name|db_stack_trace_cmd
parameter_list|(
name|addr
parameter_list|,
name|have_addr
parameter_list|,
name|count
parameter_list|,
name|modif
parameter_list|)
name|db_expr_t
name|addr
decl_stmt|;
name|boolean_t
name|have_addr
decl_stmt|;
name|db_expr_t
name|count
decl_stmt|;
name|char
modifier|*
name|modif
decl_stmt|;
block|{
comment|/* nothing, yet. */
block|}
end_function

end_unit

