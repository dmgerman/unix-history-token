begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== globals.c ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : Global variables.  *  *  1.00 93/07/26 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_include
include|#
directive|include
file|"pthread.h"
end_include

begin_comment
comment|/*  * Initial thread, running thread, and top of link list  * of all threads.  */
end_comment

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_run
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_initial
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_link_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * default thread attributes  */
end_comment

begin_decl_stmt
name|pthread_attr_t
name|pthread_default_attr
init|=
block|{
name|SCHED_RR
block|,
name|NULL
block|,
name|PTHREAD_STACK_DEFAULT
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Queue for all threads elidgeable to run this scheduling round.  */
end_comment

begin_decl_stmt
name|struct
name|pthread_queue
name|pthread_current_queue
init|=
name|PTHREAD_QUEUE_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * File table information  */
end_comment

begin_decl_stmt
name|struct
name|fd_table_entry
modifier|*
name|fd_table
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

end_unit

