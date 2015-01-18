begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wthread-safety -Wthread-safety-beta %s
end_comment

begin_define
define|#
directive|define
name|LOCKABLE
value|__attribute__ ((lockable))
end_define

begin_define
define|#
directive|define
name|SCOPED_LOCKABLE
value|__attribute__ ((scoped_lockable))
end_define

begin_define
define|#
directive|define
name|GUARDED_BY
parameter_list|(
name|x
parameter_list|)
value|__attribute__ ((guarded_by(x)))
end_define

begin_define
define|#
directive|define
name|GUARDED_VAR
value|__attribute__ ((guarded_var))
end_define

begin_define
define|#
directive|define
name|PT_GUARDED_BY
parameter_list|(
name|x
parameter_list|)
value|__attribute__ ((pt_guarded_by(x)))
end_define

begin_define
define|#
directive|define
name|PT_GUARDED_VAR
value|__attribute__ ((pt_guarded_var))
end_define

begin_define
define|#
directive|define
name|ACQUIRED_AFTER
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((acquired_after(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|ACQUIRED_BEFORE
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((acquired_before(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|EXCLUSIVE_LOCK_FUNCTION
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((exclusive_lock_function(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|SHARED_LOCK_FUNCTION
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((shared_lock_function(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|ASSERT_EXCLUSIVE_LOCK
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((assert_exclusive_lock(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|ASSERT_SHARED_LOCK
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((assert_shared_lock(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|EXCLUSIVE_TRYLOCK_FUNCTION
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((exclusive_trylock_function(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|SHARED_TRYLOCK_FUNCTION
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((shared_trylock_function(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|UNLOCK_FUNCTION
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((unlock_function(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|LOCK_RETURNED
parameter_list|(
name|x
parameter_list|)
value|__attribute__ ((lock_returned(x)))
end_define

begin_define
define|#
directive|define
name|LOCKS_EXCLUDED
parameter_list|(
modifier|...
parameter_list|)
value|__attribute__ ((locks_excluded(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|EXCLUSIVE_LOCKS_REQUIRED
parameter_list|(
modifier|...
parameter_list|)
define|\
value|__attribute__ ((exclusive_locks_required(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|SHARED_LOCKS_REQUIRED
parameter_list|(
modifier|...
parameter_list|)
define|\
value|__attribute__ ((shared_locks_required(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|NO_THREAD_SAFETY_ANALYSIS
value|__attribute__ ((no_thread_safety_analysis))
end_define

begin_comment
comment|// Define the mutex struct.
end_comment

begin_comment
comment|// Simplified only for test purpose.
end_comment

begin_struct
struct|struct
name|LOCKABLE
name|Mutex
block|{}
struct|;
end_struct

begin_struct
struct|struct
name|Foo
block|{
name|struct
name|Mutex
modifier|*
name|mu_
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// Declare mutex lock/unlock functions.
end_comment

begin_function_decl
name|void
name|mutex_exclusive_lock
parameter_list|(
name|struct
name|Mutex
modifier|*
name|mu
parameter_list|)
function_decl|EXCLUSIVE_LOCK_FUNCTION
parameter_list|(
name|mu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mutex_shared_lock
parameter_list|(
name|struct
name|Mutex
modifier|*
name|mu
parameter_list|)
function_decl|SHARED_LOCK_FUNCTION
parameter_list|(
name|mu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mutex_unlock
parameter_list|(
name|struct
name|Mutex
modifier|*
name|mu
parameter_list|)
function_decl|UNLOCK_FUNCTION
parameter_list|(
name|mu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mutex_shared_unlock
parameter_list|(
name|struct
name|Mutex
modifier|*
name|mu
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(release_shared_capability
parameter_list|(
name|mu
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|mutex_exclusive_unlock
parameter_list|(
name|struct
name|Mutex
modifier|*
name|mu
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(release_capability
parameter_list|(
name|mu
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Define global variables.
end_comment

begin_decl_stmt
name|struct
name|Mutex
name|mu1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|Mutex
name|mu2
name|ACQUIRED_AFTER
parameter_list|(
name|mu1
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|Foo
name|foo_
init|=
block|{
operator|&
name|mu1
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|a_
name|GUARDED_BY
parameter_list|(
name|foo_
operator|.
name|mu_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
modifier|*
name|b_
name|PT_GUARDED_BY
parameter_list|(
name|foo_
operator|.
name|mu_
parameter_list|)
init|=
operator|&
name|a_
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|c_
name|GUARDED_VAR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|d_
name|PT_GUARDED_VAR
init|=
operator|&
name|c_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Define test functions.
end_comment

begin_function
name|int
name|Foo_fun1
parameter_list|(
name|int
name|i
parameter_list|)
function|SHARED_LOCKS_REQUIRED
parameter_list|(
name|mu2
parameter_list|)
function|EXCLUSIVE_LOCKS_REQUIRED
parameter_list|(
name|mu1
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_function
name|int
name|Foo_fun2
parameter_list|(
name|int
name|i
parameter_list|)
function|EXCLUSIVE_LOCKS_REQUIRED
parameter_list|(
name|mu2
parameter_list|)
function|SHARED_LOCKS_REQUIRED
parameter_list|(
name|mu1
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_function
name|int
name|Foo_func3
parameter_list|(
name|int
name|i
parameter_list|)
function|LOCKS_EXCLUDED
parameter_list|(
name|mu1
parameter_list|,
name|mu2
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|Bar_fun1
parameter_list|(
name|int
name|i
parameter_list|)
function|EXCLUSIVE_LOCKS_REQUIRED
parameter_list|(
name|mu1
parameter_list|)
block|{
return|return
name|i
return|;
block|}
end_function

begin_function
name|void
name|set_value
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
name|value
parameter_list|)
function|EXCLUSIVE_LOCKS_REQUIRED
parameter_list|(
name|foo_
operator|.
name|mu_
parameter_list|)
block|{
operator|*
name|a
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_function
name|int
name|get_value
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
function|SHARED_LOCKS_REQUIRED
parameter_list|(
name|foo_
operator|.
name|mu_
parameter_list|)
block|{
return|return
operator|*
name|p
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|Foo_fun1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// expected-warning{{calling function 'Foo_fun1' requires holding mutex 'mu2'}} \
name|expected
operator|-
name|warning
block|{
block|{
name|calling
name|function
literal|'Foo_fun1'
name|requires
name|holding
name|mutex
literal|'mu1'
name|exclusively
block|}
block|}
name|mutex_exclusive_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_shared_lock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|Foo_fun1
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|mutex_shared_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// expected-warning{{acquiring mutex 'mu1' that is already held}}
name|mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|mutex_shared_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_exclusive_lock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|Foo_fun2
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
operator|&
name|mu2
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_exclusive_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|Bar_fun1
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_exclusive_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|Foo_func3
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|// expected-warning{{cannot call function 'Foo_func3' while mutex 'mu1' is held}}
name|mutex_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|Foo_func3
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|set_value
argument_list|(
operator|&
name|a_
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{calling function 'set_value' requires holding mutex 'foo_.mu_' exclusively}}
name|get_value
argument_list|(
name|b_
argument_list|)
expr_stmt|;
comment|// expected-warning{{calling function 'get_value' requires holding mutex 'foo_.mu_'}}
name|mutex_exclusive_lock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
name|set_value
argument_list|(
operator|&
name|a_
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
name|mutex_shared_lock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
call|(
name|void
call|)
argument_list|(
name|get_value
argument_list|(
name|b_
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
name|c_
operator|=
literal|0
expr_stmt|;
comment|// expected-warning{{writing variable 'c_' requires holding any mutex exclusively}}
call|(
name|void
call|)
argument_list|(
operator|*
name|d_
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{reading the value pointed to by 'd_' requires holding any mutex}}
name|mutex_exclusive_lock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
name|c_
operator|=
literal|1
expr_stmt|;
call|(
name|void
call|)
argument_list|(
operator|*
name|d_
operator|==
literal|1
argument_list|)
expr_stmt|;
name|mutex_unlock
argument_list|(
name|foo_
operator|.
name|mu_
argument_list|)
expr_stmt|;
name|mutex_exclusive_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_shared_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// expected-warning {{releasing mutex 'mu1' using shared access, expected exclusive access}}
name|mutex_exclusive_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// expected-warning {{releasing mutex 'mu1' that was not held}}
name|mutex_shared_lock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
name|mutex_exclusive_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// expected-warning {{releasing mutex 'mu1' using exclusive access, expected shared access}}
name|mutex_shared_unlock
argument_list|(
operator|&
name|mu1
argument_list|)
expr_stmt|;
comment|// expected-warning {{releasing mutex 'mu1' that was not held}}
return|return
literal|0
return|;
block|}
end_function

end_unit

