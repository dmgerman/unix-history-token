begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== mutex.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : mutex header.  *  *  1.00 93/07/20 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_comment
comment|/*  * New mutex structures  */
end_comment

begin_enum
enum|enum
name|pthread_mutex_type
block|{
name|MUTEX_TYPE_FAST
block|,
name|MUTEX_TYPE_STATIC_FAST
block|,
name|MUTEX_TYPE_RECURSIVE
block|,
name|MUTEX_TYPE_METERED
block|,
name|MUTEX_TYPE_DEBUG
block|,
comment|/* Debug mutexes will have lots of options */
name|MUTEX_TYPE_MAX
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
name|pthread_mutex
block|{
name|enum
name|pthread_mutex_type
name|m_type
decl_stmt|;
name|struct
name|pthread_queue
name|m_queue
decl_stmt|;
name|struct
name|pthread
modifier|*
name|m_owner
decl_stmt|;
name|semaphore
name|m_lock
decl_stmt|;
name|void
modifier|*
name|m_data
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
block|}
name|pthread_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pthread_mutex_attr
block|{
name|enum
name|pthread_mutex_type
name|m_type
decl_stmt|;
name|long
name|m_flags
decl_stmt|;
block|}
name|pthread_mutexattr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Flags for mutexes.  */
end_comment

begin_define
define|#
directive|define
name|MUTEX_FLAGS_PRIVATE
value|0x01
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_INITED
value|0x02
end_define

begin_define
define|#
directive|define
name|MUTEX_FLAGS_BUSY
value|0x04
end_define

begin_comment
comment|/*  * Static mutex initialization values.  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_MUTEX_INITIALIZER
define|\
value|{ MUTEX_TYPE_STATIC_FAST, PTHREAD_QUEUE_INITIALIZER, \ 	 NULL, SEMAPHORE_CLEAR, NULL, MUTEX_FLAGS_INITED }
end_define

begin_comment
comment|/*  * New functions  */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|pthread_mutex_init
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|,
name|pthread_mutexattr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_lock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_unlock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_trylock
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pthread_mutex_destroy
name|__P
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

end_unit

