begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* taken from ldns 1.6.1 */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_comment
comment|/** the lock for ctime buffer */
end_comment

begin_decl_stmt
specifier|static
name|lock_basic_t
name|ctime_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** has it been inited */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ctime_r_init
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** cleanup ctime_r on exit */
end_comment

begin_function
specifier|static
name|void
name|ctime_r_cleanup
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ctime_r_init
condition|)
block|{
name|ctime_r_init
operator|=
literal|0
expr_stmt|;
name|lock_basic_destroy
argument_list|(
operator|&
name|ctime_lock
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|char
modifier|*
name|ctime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|timep
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
block|{
name|char
modifier|*
name|result
decl_stmt|;
if|if
condition|(
operator|!
name|ctime_r_init
condition|)
block|{
comment|/* still small race where this init can be done twice, 		 * which is mostly harmless */
name|ctime_r_init
operator|=
literal|1
expr_stmt|;
name|lock_basic_init
argument_list|(
operator|&
name|ctime_lock
argument_list|)
expr_stmt|;
name|atexit
argument_list|(
operator|&
name|ctime_r_cleanup
argument_list|)
expr_stmt|;
block|}
name|lock_basic_lock
argument_list|(
operator|&
name|ctime_lock
argument_list|)
expr_stmt|;
name|result
operator|=
name|ctime
argument_list|(
name|timep
argument_list|)
expr_stmt|;
if|if
condition|(
name|buf
operator|&&
name|result
condition|)
block|{
if|if
condition|(
name|strlen
argument_list|(
name|result
argument_list|)
operator|>
literal|10
operator|&&
name|result
index|[
literal|7
index|]
operator|==
literal|' '
operator|&&
name|result
index|[
literal|8
index|]
operator|==
literal|'0'
condition|)
name|result
index|[
literal|8
index|]
operator|=
literal|' '
expr_stmt|;
comment|/* fix error in windows ctime */
name|strcpy
argument_list|(
name|buf
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
name|lock_basic_unlock
argument_list|(
operator|&
name|ctime_lock
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

