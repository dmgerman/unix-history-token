begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Machine-independent glue to integrate David Gay's gdtoa  * package into libc.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"spinlock.h"
end_include

begin_decl_stmt
name|spinlock_t
name|__gdtoa_locks
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

end_unit

