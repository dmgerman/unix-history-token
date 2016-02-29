begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_comment
comment|/* Maximum number of malloc_tsd users with cleanup functions. */
end_comment

begin_define
define|#
directive|define
name|MALLOC_TSD_CLEANUPS_MAX
value|2
end_define

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|malloc_tsd_cleanup_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|JEMALLOC_MALLOC_THREAD_CLEANUP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|struct
name|tsd_init_block_s
name|tsd_init_block_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tsd_init_head_s
name|tsd_init_head_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|tsd_s
name|tsd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|tsd_state_uninitialized
block|,
name|tsd_state_nominal
block|,
name|tsd_state_purgatory
block|,
name|tsd_state_reincarnated
block|}
name|tsd_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * TLS/TSD-agnostic macro-based implementation of thread-specific data.  There  * are five macros that support (at least) three use cases: file-private,  * library-private, and library-private inlined.  Following is an example  * library-private tsd variable:  *  * In example.h:  *   typedef struct {  *           int x;  *           int y;  *   } example_t;  *   #define EX_INITIALIZER JEMALLOC_CONCAT({0, 0})  *   malloc_tsd_types(example_, example_t)  *   malloc_tsd_protos(, example_, example_t)  *   malloc_tsd_externs(example_, example_t)  * In example.c:  *   malloc_tsd_data(, example_, example_t, EX_INITIALIZER)  *   malloc_tsd_funcs(, example_, example_t, EX_INITIALIZER,  *       example_tsd_cleanup)  *  * The result is a set of generated functions, e.g.:  *  *   bool example_tsd_boot(void) {...}  *   example_t *example_tsd_get() {...}  *   void example_tsd_set(example_t *val) {...}  *  * Note that all of the functions deal in terms of (a_type *) rather than  * (a_type) so that it is possible to support non-pointer types (unlike  * pthreads TSD).  example_tsd_cleanup() is passed an (a_type *) pointer that is  * cast to (void *).  This means that the cleanup function needs to cast the  * function argument to (a_type *), then dereference the resulting pointer to  * access fields, e.g.  *  *   void  *   example_tsd_cleanup(void *arg)  *   {  *           example_t *example = (example_t *)arg;  *  *           example->x = 42;  *           [...]  *           if ([want the cleanup function to be called again])  *                   example_tsd_set(example);  *   }  *  * If example_tsd_set() is called within example_tsd_cleanup(), it will be  * called again.  This is similar to how pthreads TSD destruction works, except  * that pthreads only calls the cleanup function again if the value was set to  * non-NULL.  */
end_comment

begin_comment
comment|/* malloc_tsd_types(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_ifdef

begin_define
define|#
directive|define
name|malloc_tsd_types
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_types
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_types
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|typedef struct {							\ 	bool	initialized;						\ 	a_type	val;							\ } a_name##tsd_wrapper_t;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|malloc_tsd_types
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|typedef struct {							\ 	bool	initialized;						\ 	a_type	val;							\ } a_name##tsd_wrapper_t;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc_tsd_protos(). */
end_comment

begin_define
define|#
directive|define
name|malloc_tsd_protos
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|a_attr bool								\ a_name##tsd_boot0(void);						\ a_attr void								\ a_name##tsd_boot1(void);						\ a_attr bool								\ a_name##tsd_boot(void);							\ a_attr a_type *								\ a_name##tsd_get(void);							\ a_attr void								\ a_name##tsd_set(a_type *val);
end_define

begin_comment
comment|/* malloc_tsd_externs(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_ifdef

begin_define
define|#
directive|define
name|malloc_tsd_externs
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|extern __thread a_type	a_name##tsd_tls;				\ extern __thread bool	a_name##tsd_initialized;			\ extern bool		a_name##tsd_booted;
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_externs
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|extern __thread a_type	a_name##tsd_tls;				\ extern pthread_key_t	a_name##tsd_tsd;				\ extern bool		a_name##tsd_booted;
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_externs
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|extern DWORD		a_name##tsd_tsd;				\ extern a_name##tsd_wrapper_t	a_name##tsd_boot_wrapper;		\ extern bool		a_name##tsd_booted;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|malloc_tsd_externs
parameter_list|(
name|a_name
parameter_list|,
name|a_type
parameter_list|)
define|\
value|extern pthread_key_t	a_name##tsd_tsd;				\ extern tsd_init_head_t	a_name##tsd_init_head;				\ extern a_name##tsd_wrapper_t	a_name##tsd_boot_wrapper;		\ extern bool		a_name##tsd_booted;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc_tsd_data(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_ifdef

begin_define
define|#
directive|define
name|malloc_tsd_data
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|)
define|\
value|a_attr __thread a_type JEMALLOC_TLS_MODEL				\     a_name##tsd_tls = a_initializer;					\ a_attr __thread bool JEMALLOC_TLS_MODEL					\     a_name##tsd_initialized = false;					\ a_attr bool		a_name##tsd_booted = false;
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_data
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|)
define|\
value|a_attr __thread a_type JEMALLOC_TLS_MODEL				\     a_name##tsd_tls = a_initializer;					\ a_attr pthread_key_t	a_name##tsd_tsd;				\ a_attr bool		a_name##tsd_booted = false;
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_data
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|)
define|\
value|a_attr DWORD		a_name##tsd_tsd;				\ a_attr a_name##tsd_wrapper_t a_name##tsd_boot_wrapper = {		\ 	false,								\ 	a_initializer							\ };									\ a_attr bool		a_name##tsd_booted = false;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|malloc_tsd_data
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|)
define|\
value|a_attr pthread_key_t	a_name##tsd_tsd;				\ a_attr tsd_init_head_t	a_name##tsd_init_head = {			\ 	ql_head_initializer(blocks),					\ 	MALLOC_MUTEX_INITIALIZER					\ };									\ a_attr a_name##tsd_wrapper_t a_name##tsd_boot_wrapper = {		\ 	false,								\ 	a_initializer							\ };									\ a_attr bool		a_name##tsd_booted = false;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc_tsd_funcs(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_ifdef

begin_define
define|#
directive|define
name|malloc_tsd_funcs
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|,		\
name|a_cleanup
parameter_list|)
define|\
comment|/* Initialization/cleanup. */
define|\
value|a_attr bool								\ a_name##tsd_cleanup_wrapper(void)					\ {									\ 									\ 	if (a_name##tsd_initialized) {					\ 		a_name##tsd_initialized = false;			\ 		a_cleanup(&a_name##tsd_tls);				\ 	}								\ 	return (a_name##tsd_initialized);				\ }									\ a_attr bool								\ a_name##tsd_boot0(void)							\ {									\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		malloc_tsd_cleanup_register(				\&a_name##tsd_cleanup_wrapper);			\ 	}								\ 	a_name##tsd_booted = true;					\ 	return (false);							\ }									\ a_attr void								\ a_name##tsd_boot1(void)							\ {									\ 									\
comment|/* Do nothing. */
value|\ }									\ a_attr bool								\ a_name##tsd_boot(void)							\ {									\ 									\ 	return (a_name##tsd_boot0());					\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##tsd_get(void)							\ {									\ 									\ 	assert(a_name##tsd_booted);					\ 	return (&a_name##tsd_tls);					\ }									\ a_attr void								\ a_name##tsd_set(a_type *val)						\ {									\ 									\ 	assert(a_name##tsd_booted);					\ 	a_name##tsd_tls = (*val);					\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		a_name##tsd_initialized = true;				\ }
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_funcs
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|,		\
name|a_cleanup
parameter_list|)
define|\
comment|/* Initialization/cleanup. */
define|\
value|a_attr bool								\ a_name##tsd_boot0(void)							\ {									\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		if (pthread_key_create(&a_name##tsd_tsd, a_cleanup) !=	\ 		    0)							\ 			return (true);					\ 	}								\ 	a_name##tsd_booted = true;					\ 	return (false);							\ }									\ a_attr void								\ a_name##tsd_boot1(void)							\ {									\ 									\
comment|/* Do nothing. */
value|\ }									\ a_attr bool								\ a_name##tsd_boot(void)							\ {									\ 									\ 	return (a_name##tsd_boot0());					\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##tsd_get(void)							\ {									\ 									\ 	assert(a_name##tsd_booted);					\ 	return (&a_name##tsd_tls);					\ }									\ a_attr void								\ a_name##tsd_set(a_type *val)						\ {									\ 									\ 	assert(a_name##tsd_booted);					\ 	a_name##tsd_tls = (*val);					\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		if (pthread_setspecific(a_name##tsd_tsd,		\ 		    (void *)(&a_name##tsd_tls))) {			\ 			malloc_write("<jemalloc>: Error"		\ 			    " setting TSD for "#a_name"\n");		\ 			if (opt_abort)					\ 				abort();				\ 		}							\ 	}								\ }
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|malloc_tsd_funcs
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|,		\
name|a_cleanup
parameter_list|)
define|\
comment|/* Initialization/cleanup. */
define|\
value|a_attr bool								\ a_name##tsd_cleanup_wrapper(void)					\ {									\ 	DWORD error = GetLastError();					\ 	a_name##tsd_wrapper_t *wrapper = (a_name##tsd_wrapper_t *)	\ 	    TlsGetValue(a_name##tsd_tsd);				\ 	SetLastError(error);						\ 									\ 	if (wrapper == NULL)						\ 		return (false);						\ 	if (a_cleanup != malloc_tsd_no_cleanup&&			\ 	    wrapper->initialized) {					\ 		wrapper->initialized = false;				\ 		a_cleanup(&wrapper->val);				\ 		if (wrapper->initialized) {				\
comment|/* Trigger another cleanup round. */
value|\ 			return (true);					\ 		}							\ 	}								\ 	malloc_tsd_dalloc(wrapper);					\ 	return (false);							\ }									\ a_attr void								\ a_name##tsd_wrapper_set(a_name##tsd_wrapper_t *wrapper)			\ {									\ 									\ 	if (!TlsSetValue(a_name##tsd_tsd, (void *)wrapper)) {		\ 		malloc_write("<jemalloc>: Error setting"		\ 		    " TSD for "#a_name"\n");				\ 		abort();						\ 	}								\ }									\ a_attr a_name##tsd_wrapper_t *						\ a_name##tsd_wrapper_get(void)						\ {									\ 	DWORD error = GetLastError();					\ 	a_name##tsd_wrapper_t *wrapper = (a_name##tsd_wrapper_t *)	\ 	    TlsGetValue(a_name##tsd_tsd);				\ 	SetLastError(error);						\ 									\ 	if (unlikely(wrapper == NULL)) {				\ 		wrapper = (a_name##tsd_wrapper_t *)			\ 		    malloc_tsd_malloc(sizeof(a_name##tsd_wrapper_t));	\ 		if (wrapper == NULL) {					\ 			malloc_write("<jemalloc>: Error allocating"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		} else {						\ 			wrapper->initialized = false;			\ 			wrapper->val = a_initializer;			\ 		}							\ 		a_name##tsd_wrapper_set(wrapper);			\ 	}								\ 	return (wrapper);						\ }									\ a_attr bool								\ a_name##tsd_boot0(void)							\ {									\ 									\ 	a_name##tsd_tsd = TlsAlloc();					\ 	if (a_name##tsd_tsd == TLS_OUT_OF_INDEXES)			\ 		return (true);						\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		malloc_tsd_cleanup_register(				\&a_name##tsd_cleanup_wrapper);			\ 	}								\ 	a_name##tsd_wrapper_set(&a_name##tsd_boot_wrapper);		\ 	a_name##tsd_booted = true;					\ 	return (false);							\ }									\ a_attr void								\ a_name##tsd_boot1(void)							\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 	wrapper = (a_name##tsd_wrapper_t *)				\ 	    malloc_tsd_malloc(sizeof(a_name##tsd_wrapper_t));		\ 	if (wrapper == NULL) {						\ 		malloc_write("<jemalloc>: Error allocating"		\ 		    " TSD for "#a_name"\n");				\ 		abort();						\ 	}								\ 	memcpy(wrapper,&a_name##tsd_boot_wrapper,			\ 	    sizeof(a_name##tsd_wrapper_t));				\ 	a_name##tsd_wrapper_set(wrapper);				\ }									\ a_attr bool								\ a_name##tsd_boot(void)							\ {									\ 									\ 	if (a_name##tsd_boot0())					\ 		return (true);						\ 	a_name##tsd_boot1();						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##tsd_get(void)							\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 									\ 	assert(a_name##tsd_booted);					\ 	wrapper = a_name##tsd_wrapper_get();				\ 	return (&wrapper->val);						\ }									\ a_attr void								\ a_name##tsd_set(a_type *val)						\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 									\ 	assert(a_name##tsd_booted);					\ 	wrapper = a_name##tsd_wrapper_get();				\ 	wrapper->val = *(val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		wrapper->initialized = true;				\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|malloc_tsd_funcs
parameter_list|(
name|a_attr
parameter_list|,
name|a_name
parameter_list|,
name|a_type
parameter_list|,
name|a_initializer
parameter_list|,		\
name|a_cleanup
parameter_list|)
define|\
comment|/* Initialization/cleanup. */
define|\
value|a_attr void								\ a_name##tsd_cleanup_wrapper(void *arg)					\ {									\ 	a_name##tsd_wrapper_t *wrapper = (a_name##tsd_wrapper_t *)arg;	\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup&&			\ 	    wrapper->initialized) {					\ 		wrapper->initialized = false;				\ 		a_cleanup(&wrapper->val);				\ 		if (wrapper->initialized) {				\
comment|/* Trigger another cleanup round. */
value|\ 			if (pthread_setspecific(a_name##tsd_tsd,	\ 			    (void *)wrapper)) {				\ 				malloc_write("<jemalloc>: Error"	\ 				    " setting TSD for "#a_name"\n");	\ 				if (opt_abort)				\ 					abort();			\ 			}						\ 			return;						\ 		}							\ 	}								\ 	malloc_tsd_dalloc(wrapper);					\ }									\ a_attr void								\ a_name##tsd_wrapper_set(a_name##tsd_wrapper_t *wrapper)			\ {									\ 									\ 	if (pthread_setspecific(a_name##tsd_tsd,			\ 	    (void *)wrapper)) {						\ 		malloc_write("<jemalloc>: Error setting"		\ 		    " TSD for "#a_name"\n");				\ 		abort();						\ 	}								\ }									\ a_attr a_name##tsd_wrapper_t *						\ a_name##tsd_wrapper_get(void)						\ {									\ 	a_name##tsd_wrapper_t *wrapper = (a_name##tsd_wrapper_t *)	\ 	    pthread_getspecific(a_name##tsd_tsd);			\ 									\ 	if (unlikely(wrapper == NULL)) {				\ 		tsd_init_block_t block;					\ 		wrapper = tsd_init_check_recursion(			\&a_name##tsd_init_head,&block);			\ 		if (wrapper)						\ 		    return (wrapper);					\ 		wrapper = (a_name##tsd_wrapper_t *)			\ 		    malloc_tsd_malloc(sizeof(a_name##tsd_wrapper_t));	\ 		block.data = wrapper;					\ 		if (wrapper == NULL) {					\ 			malloc_write("<jemalloc>: Error allocating"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		} else {						\ 			wrapper->initialized = false;			\ 			wrapper->val = a_initializer;			\ 		}							\ 		a_name##tsd_wrapper_set(wrapper);			\ 		tsd_init_finish(&a_name##tsd_init_head,&block);	\ 	}								\ 	return (wrapper);						\ }									\ a_attr bool								\ a_name##tsd_boot0(void)							\ {									\ 									\ 	if (pthread_key_create(&a_name##tsd_tsd,			\ 	    a_name##tsd_cleanup_wrapper) != 0)				\ 		return (true);						\ 	a_name##tsd_wrapper_set(&a_name##tsd_boot_wrapper);		\ 	a_name##tsd_booted = true;					\ 	return (false);							\ }									\ a_attr void								\ a_name##tsd_boot1(void)							\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 	wrapper = (a_name##tsd_wrapper_t *)				\ 	    malloc_tsd_malloc(sizeof(a_name##tsd_wrapper_t));		\ 	if (wrapper == NULL) {						\ 		malloc_write("<jemalloc>: Error allocating"		\ 		    " TSD for "#a_name"\n");				\ 		abort();						\ 	}								\ 	memcpy(wrapper,&a_name##tsd_boot_wrapper,			\ 	    sizeof(a_name##tsd_wrapper_t));				\ 	a_name##tsd_wrapper_set(wrapper);				\ }									\ a_attr bool								\ a_name##tsd_boot(void)							\ {									\ 									\ 	if (a_name##tsd_boot0())					\ 		return (true);						\ 	a_name##tsd_boot1();						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##tsd_get(void)							\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 									\ 	assert(a_name##tsd_booted);					\ 	wrapper = a_name##tsd_wrapper_get();				\ 	return (&wrapper->val);						\ }									\ a_attr void								\ a_name##tsd_set(a_type *val)						\ {									\ 	a_name##tsd_wrapper_t *wrapper;					\ 									\ 	assert(a_name##tsd_booted);					\ 	wrapper = a_name##tsd_wrapper_get();				\ 	wrapper->val = *(val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		wrapper->initialized = true;				\ }
end_define

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

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|JEMALLOC_MALLOC_THREAD_CLEANUP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_if

begin_struct
struct|struct
name|tsd_init_block_s
block|{
name|ql_elm
argument_list|(
argument|tsd_init_block_t
argument_list|)
name|link
expr_stmt|;
name|pthread_t
name|thread
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tsd_init_head_s
block|{
name|ql_head
argument_list|(
argument|tsd_init_block_t
argument_list|)
name|blocks
expr_stmt|;
name|malloc_mutex_t
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MALLOC_TSD
define|\
comment|/*  O(name,			type) */
define|\
value|O(tcache,			tcache_t *)				\     O(thread_allocated,		uint64_t)				\     O(thread_deallocated,	uint64_t)				\     O(prof_tdata,		prof_tdata_t *)				\     O(arena,			arena_t *)				\     O(arenas_tdata,		arena_tdata_t *)			\     O(narenas_tdata,		unsigned)				\     O(arenas_tdata_bypass,	bool)					\     O(tcache_enabled,		tcache_enabled_t)			\     O(quarantine,		quarantine_t *)				\  #define	TSD_INITIALIZER {						\     tsd_state_uninitialized,						\     NULL,								\     0,									\     0,									\     NULL,								\     NULL,								\     NULL,								\     0,									\     false,								\     tcache_enabled_default,						\     NULL								\ }
end_define

begin_struct
struct|struct
name|tsd_s
block|{
name|tsd_state_t
name|state
decl_stmt|;
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|t		n;
name|MALLOC_TSD
undef|#
directive|undef
name|O
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|tsd_t
name|tsd_initializer
init|=
name|TSD_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_macro
name|malloc_tsd_types
argument_list|(
argument_list|,
argument|tsd_t
argument_list|)
end_macro

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

begin_function_decl
name|void
modifier|*
name|malloc_tsd_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_dalloc
parameter_list|(
name|void
modifier|*
name|wrapper
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_no_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_cleanup_register
parameter_list|(
name|bool
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|malloc_tsd_boot0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|malloc_tsd_boot1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|JEMALLOC_MALLOC_THREAD_CLEANUP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|JEMALLOC_TLS
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|)
end_if

begin_function_decl
name|void
modifier|*
name|tsd_init_check_recursion
parameter_list|(
name|tsd_init_head_t
modifier|*
name|head
parameter_list|,
name|tsd_init_block_t
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tsd_init_finish
parameter_list|(
name|tsd_init_head_t
modifier|*
name|head
parameter_list|,
name|tsd_init_block_t
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|tsd_cleanup
parameter_list|(
name|void
modifier|*
name|arg
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

begin_macro
name|malloc_tsd_protos
argument_list|(
argument|JEMALLOC_ATTR(unused)
argument_list|,
argument_list|,
argument|tsd_t
argument_list|)
end_macro

begin_function_decl
name|tsd_t
modifier|*
name|tsd_fetch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tsd_nominal
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|t	*tsd_##n##p_get(tsd_t *tsd);					\ t	tsd_##n##_get(tsd_t *tsd);					\ void	tsd_##n##_set(tsd_t *tsd, t n);
end_define

begin_decl_stmt
name|MALLOC_TSD
undef|#
directive|undef
name|O
endif|#
directive|endif
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
name|JEMALLOC_TSD_C_
argument_list|)
operator|)
name|malloc_tsd_externs
argument_list|(,
name|tsd_t
argument_list|)
name|malloc_tsd_funcs
argument_list|(
name|JEMALLOC_ALWAYS_INLINE
argument_list|, ,
name|tsd_t
argument_list|,
name|tsd_initializer
argument_list|,
name|tsd_cleanup
argument_list|)
name|JEMALLOC_ALWAYS_INLINE
name|tsd_t
modifier|*
name|tsd_fetch
argument_list|(
name|void
argument_list|)
block|{
name|tsd_t
modifier|*
name|tsd
init|=
name|tsd_get
argument_list|()
decl_stmt|;
if|if
condition|(
name|unlikely
argument_list|(
name|tsd
operator|->
name|state
operator|!=
name|tsd_state_nominal
argument_list|)
condition|)
block|{
if|if
condition|(
name|tsd
operator|->
name|state
operator|==
name|tsd_state_uninitialized
condition|)
block|{
name|tsd
operator|->
name|state
operator|=
name|tsd_state_nominal
expr_stmt|;
comment|/* Trigger cleanup handler registration. */
name|tsd_set
argument_list|(
name|tsd
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tsd
operator|->
name|state
operator|==
name|tsd_state_purgatory
condition|)
block|{
name|tsd
operator|->
name|state
operator|=
name|tsd_state_reincarnated
expr_stmt|;
name|tsd_set
argument_list|(
name|tsd
argument_list|)
expr_stmt|;
block|}
else|else
name|assert
argument_list|(
name|tsd
operator|->
name|state
operator|==
name|tsd_state_reincarnated
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|tsd
operator|)
return|;
block|}
end_decl_stmt

begin_function
name|JEMALLOC_INLINE
name|bool
name|tsd_nominal
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
block|{
return|return
operator|(
name|tsd
operator|->
name|state
operator|==
name|tsd_state_nominal
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|O
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|JEMALLOC_ALWAYS_INLINE t *						\ tsd_##n##p_get(tsd_t *tsd)						\ {									\ 									\ 	return (&tsd->n);						\ }									\ 									\ JEMALLOC_ALWAYS_INLINE t						\ tsd_##n##_get(tsd_t *tsd)						\ {									\ 									\ 	return (*tsd_##n##p_get(tsd));					\ }									\ 									\ JEMALLOC_ALWAYS_INLINE void						\ tsd_##n##_set(tsd_t *tsd, t n)						\ {									\ 									\ 	assert(tsd->state == tsd_state_nominal);			\ 	tsd->n = n;							\ }
end_define

begin_macro
name|MALLOC_TSD
end_macro

begin_undef
undef|#
directive|undef
name|O
end_undef

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

