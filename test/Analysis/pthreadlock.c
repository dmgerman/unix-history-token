begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=experimental.unix.PthreadLock -verify %s
end_comment

begin_comment
comment|// Tests performing normal locking patterns and wrong locking orders
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|foo
decl_stmt|;
block|}
name|pthread_mutex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|lck_mtx_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|pthread_mutex_lock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pthread_mutex_unlock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pthread_mutex_trylock
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lck_mtx_lock
parameter_list|(
name|lck_mtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lck_mtx_unlock
parameter_list|(
name|lck_mtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lck_mtx_try_lock
parameter_list|(
name|lck_mtx_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|pthread_mutex_t
name|mtx1
decl_stmt|,
name|mtx2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|lck_mtx_t
name|lck1
decl_stmt|,
name|lck2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ok1
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok2
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok3
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok4
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok5
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_trylock
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|==
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok6
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok7
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|lck_mtx_try_lock
argument_list|(
operator|&
name|lck1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|bad1
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been acquired}}
block|}
end_function

begin_function
name|void
name|bad2
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been acquired}}
block|}
end_function

begin_function
name|void
name|bad3
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This was not the most recently acquired lock}}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bad4
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_trylock
argument_list|(
operator|&
name|mtx1
argument_list|)
condition|)
comment|// no-warning
return|return;
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This was not the most recently acquired lock}}
block|}
end_function

begin_function
name|void
name|bad5
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been acquired}}
block|}
end_function

begin_function
name|void
name|bad6
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been acquired}}
block|}
end_function

begin_function
name|void
name|bad7
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_lock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_lock
argument_list|(
operator|&
name|lck2
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This was not the most recently acquired lock}}
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bad8
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|lck_mtx_try_lock
argument_list|(
operator|&
name|lck1
argument_list|)
operator|==
literal|0
condition|)
comment|// no-warning
return|return;
name|lck_mtx_lock
argument_list|(
operator|&
name|lck2
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This was not the most recently acquired lock}}
block|}
end_function

end_unit

