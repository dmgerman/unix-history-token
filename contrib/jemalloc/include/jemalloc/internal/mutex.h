begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|malloc_mutex_s
name|malloc_mutex_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|MALLOC_MUTEX_INITIALIZER
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_OSSPIN
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|MALLOC_MUTEX_INITIALIZER
value|{0}
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_MUTEX_INIT_CB
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|MALLOC_MUTEX_INITIALIZER
value|{PTHREAD_MUTEX_INITIALIZER, NULL}
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PTHREAD_MUTEX_ADAPTIVE_NP
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|MALLOC_MUTEX_TYPE
value|PTHREAD_MUTEX_ADAPTIVE_NP
end_define

begin_define
define|#
directive|define
name|MALLOC_MUTEX_INITIALIZER
value|{PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_MUTEX_TYPE
value|PTHREAD_MUTEX_DEFAULT
end_define

begin_define
define|#
directive|define
name|MALLOC_MUTEX_INITIALIZER
value|{PTHREAD_MUTEX_INITIALIZER}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_struct
struct|struct
name|malloc_mutex_s
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|CRITICAL_SECTION
name|lock
decl_stmt|;
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_OSSPIN
argument_list|)
operator|)
name|OSSpinLock
name|lock
decl_stmt|;
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_MUTEX_INIT_CB
argument_list|)
operator|)
name|pthread_mutex_t
name|lock
decl_stmt|;
name|malloc_mutex_t
modifier|*
name|postponed_next
decl_stmt|;
else|#
directive|else
name|pthread_mutex_t
name|lock
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_LAZY_LOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|bool
name|isthreaded
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|malloc_mutex_init
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_mutex_prefork
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_mutex_postfork_parent
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_mutex_postfork_child
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|malloc_mutex_first_thread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|mutex_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|void
name|malloc_mutex_lock
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_mutex_unlock
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_MUTEX_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|void
name|malloc_mutex_lock
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|isthreaded
condition|)
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|EnterCriticalSection
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_OSSPIN
argument_list|)
operator|)
name|OSSpinLockLock
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
else|#
directive|else
name|pthread_mutex_lock
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|void
name|malloc_mutex_unlock
parameter_list|(
name|malloc_mutex_t
modifier|*
name|mutex
parameter_list|)
block|{
if|if
condition|(
name|isthreaded
condition|)
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|LeaveCriticalSection
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_OSSPIN
argument_list|)
operator|)
name|OSSpinLockUnlock
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
else|#
directive|else
name|pthread_mutex_unlock
argument_list|(
operator|&
name|mutex
operator|->
name|lock
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

