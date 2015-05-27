begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"a.h"
end_include

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_decl_stmt
name|int
name|k
init|=
name|pthread_mutex_t
argument_list|()
operator|.
name|lock
decl_stmt|;
end_decl_stmt

end_unit

