begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Like the compiler, the static analyzer treats some functions differently if
end_comment

begin_comment
comment|// they come from a system header -- for example, pthread_mutex* functions
end_comment

begin_comment
comment|// should not invalidate regions of their arguments.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

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
struct|struct
block|{
name|void
modifier|*
name|foo
decl_stmt|;
block|}
name|pthread_mutexattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|foo
decl_stmt|;
block|}
name|lck_grp_t
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
name|pthread_mutex_destroy
parameter_list|(
name|pthread_mutex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pthread_mutex_init
parameter_list|(
name|pthread_mutex_t
modifier|*
name|mutex
parameter_list|,
specifier|const
name|pthread_mutexattr_t
modifier|*
name|mutexattr
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

begin_function_decl
specifier|extern
name|void
name|lck_mtx_destroy
parameter_list|(
name|lck_mtx_t
modifier|*
name|lck
parameter_list|,
name|lck_grp_t
modifier|*
name|grp
parameter_list|)
function_decl|;
end_function_decl

end_unit

