begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This header is used during the build process to find the size and     alignment of the public OpenMP locks, so that we can export data    structures without polluting the namespace.     In this default POSIX implementation, we map the two locks to the    same PTHREADS primitive.  */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|omp_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pthread_mutex_t
name|lock
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|omp_nest_lock_t
typedef|;
end_typedef

end_unit

