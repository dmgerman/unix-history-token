begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=alpha.unix.PthreadLock -verify %s
end_comment

begin_comment
comment|// Tests performing normal locking patterns and wrong locking orders
end_comment

begin_include
include|#
directive|include
file|"Inputs/system-header-simulator-for-pthread-lock.h"
end_include

begin_decl_stmt
name|pthread_mutex_t
name|mtx1
decl_stmt|,
name|mtx2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_mutex_t
modifier|*
name|pmtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|lck_mtx_t
name|lck1
decl_stmt|,
name|lck2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|lck_grp_t
name|grp1
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NULL
value|0
end_define

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
name|ok8
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
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok9
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
name|ok10
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
operator|!=
literal|0
condition|)
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
name|ok11
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
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
name|ok12
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_destroy
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
name|ok13
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
name|pthread_mutex_destroy
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
name|ok14
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
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
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
name|pthread_mutex_destroy
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
name|ok15
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
name|pthread_mutex_destroy
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
name|ok16
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok17
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok18
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok19
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx2
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok20
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
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok21
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok22
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
name|pmtx
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok23
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_destroy
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
name|ok24
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
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
name|ok25
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
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
name|ok26
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
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
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
name|ok27
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
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
else|else
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|ok28
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
block|{
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
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
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

begin_function
name|void
name|bad9
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_unlock
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
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad10
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
name|lck_mtx_unlock
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
specifier|static
name|void
name|bad11_sub
parameter_list|(
name|pthread_mutex_t
modifier|*
name|lock
parameter_list|)
block|{
name|lck_mtx_unlock
argument_list|(
name|lock
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad11
parameter_list|(
name|int
name|i
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
if|if
condition|(
name|i
operator|<
literal|5
condition|)
name|bad11_sub
argument_list|(
operator|&
name|lck1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bad12
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
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad13
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
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad14
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
comment|// no-warning
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx2
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad15
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
name|mtx2
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been unlocked}}
block|}
end_function

begin_function
name|void
name|bad16
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
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
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad17
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
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
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad18
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad19
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
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock is still locked}}
block|}
end_function

begin_function
name|void
name|bad20
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_destroy
argument_list|(
operator|&
name|mtx1
argument_list|,
operator|&
name|grp1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad21
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_destroy
argument_list|(
operator|&
name|mtx1
argument_list|,
operator|&
name|grp1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad22
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_destroy
argument_list|(
operator|&
name|mtx1
argument_list|,
operator|&
name|grp1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_destroy
argument_list|(
operator|&
name|mtx1
argument_list|,
operator|&
name|grp1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad23
parameter_list|(
name|void
parameter_list|)
block|{
name|lck_mtx_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
name|lck_mtx_destroy
argument_list|(
operator|&
name|mtx1
argument_list|,
operator|&
name|grp1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock is still locked}}
block|}
end_function

begin_function
name|void
name|bad24
parameter_list|(
name|void
parameter_list|)
block|{
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been initialized}}
block|}
end_function

begin_function
name|void
name|bad25
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
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock is still being held}}
block|}
end_function

begin_function
name|void
name|bad26
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
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been initialized}}
block|}
end_function

begin_function
name|void
name|bad27
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
name|int
name|ret
init|=
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
else|else
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad28
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
name|int
name|ret
init|=
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
decl_stmt|;
comment|// no-warning
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// no-warning
else|else
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad29
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
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been initialized}}
else|else
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|bad30
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
if|if
condition|(
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
operator|!=
literal|0
condition|)
comment|// no-warning
name|pthread_mutex_init
argument_list|(
operator|&
name|mtx1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been initialized}}
else|else
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
block|}
end_function

begin_function
name|void
name|bad31
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|ret
init|=
name|pthread_mutex_destroy
argument_list|(
operator|&
name|mtx1
argument_list|)
decl_stmt|;
comment|// no-warning
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
comment|// expected-warning{{This lock has already been destroyed}}
if|if
condition|(
name|ret
operator|!=
literal|0
condition|)
name|pthread_mutex_lock
argument_list|(
operator|&
name|mtx1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

