begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== queue.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : mutex header.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_comment
comment|/*  * New queue structures  */
end_comment

begin_struct
struct|struct
name|pthread_queue
block|{
name|struct
name|pthread
modifier|*
name|q_next
decl_stmt|;
name|struct
name|pthread
modifier|*
name|q_last
decl_stmt|;
name|void
modifier|*
name|q_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Static queue initialization values.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_QUEUE_INITIALIZER
value|{ NULL, NULL, NULL }
end_define

begin_comment
comment|/*  * New functions  * Should make pthread_queue_get a macro  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|pthread_queue_init
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_queue_enq
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|,
expr|struct
name|pthread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pthread_queue_remove
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|,
expr|struct
name|pthread
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_queue_get
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pthread
modifier|*
name|pthread_queue_deq
name|__P
argument_list|(
operator|(
expr|struct
name|pthread_queue
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

