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
value|8
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

begin_comment
comment|/*  * TLS/TSD-agnostic macro-based implementation of thread-specific data.  There  * are four macros that support (at least) three use cases: file-private,  * library-private, and library-private inlined.  Following is an example  * library-private tsd variable:  *  * In example.h:  *   typedef struct {  *           int x;  *           int y;  *   } example_t;  *   #define EX_INITIALIZER JEMALLOC_CONCAT({0, 0})  *   malloc_tsd_protos(, example, example_t *)  *   malloc_tsd_externs(example, example_t *)  * In example.c:  *   malloc_tsd_data(, example, example_t *, EX_INITIALIZER)  *   malloc_tsd_funcs(, example, example_t *, EX_INITIALIZER,  *       example_tsd_cleanup)  *  * The result is a set of generated functions, e.g.:  *  *   bool example_tsd_boot(void) {...}  *   example_t **example_tsd_get() {...}  *   void example_tsd_set(example_t **val) {...}  *  * Note that all of the functions deal in terms of (a_type *) rather than  * (a_type)  so that it is possible to support non-pointer types (unlike  * pthreads TSD).  example_tsd_cleanup() is passed an (a_type *) pointer that is  * cast to (void *).  This means that the cleanup function needs to cast *and*  * dereference the function argument, e.g.:  *  *   void  *   example_tsd_cleanup(void *arg)  *   {  *           example_t *example = *(example_t **)arg;  *  *           [...]  *           if ([want the cleanup function to be called again]) {  *                   example_tsd_set(&example);  *           }  *   }  *  * If example_tsd_set() is called within example_tsd_cleanup(), it will be  * called again.  This is similar to how pthreads TSD destruction works, except  * that pthreads only calls the cleanup function again if the value was set to  * non-NULL.  */
end_comment

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
value|a_attr bool								\ a_name##_tsd_boot(void);						\ a_attr a_type *								\ a_name##_tsd_get(void);							\ a_attr void								\ a_name##_tsd_set(a_type *val);
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
value|extern __thread a_type	a_name##_tls;					\ extern __thread bool	a_name##_initialized;				\ extern bool		a_name##_booted;
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
value|extern __thread a_type	a_name##_tls;					\ extern pthread_key_t	a_name##_tsd;					\ extern bool		a_name##_booted;
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
value|extern DWORD		a_name##_tsd;					\ extern bool		a_name##_booted;
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
value|extern pthread_key_t	a_name##_tsd;					\ extern tsd_init_head_t	a_name##_tsd_init_head;				\ extern bool		a_name##_booted;
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
value|a_attr __thread a_type JEMALLOC_TLS_MODEL				\     a_name##_tls = a_initializer;					\ a_attr __thread bool JEMALLOC_TLS_MODEL					\     a_name##_initialized = false;					\ a_attr bool		a_name##_booted = false;
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
value|a_attr __thread a_type JEMALLOC_TLS_MODEL				\     a_name##_tls = a_initializer;					\ a_attr pthread_key_t	a_name##_tsd;					\ a_attr bool		a_name##_booted = false;
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
value|a_attr DWORD		a_name##_tsd;					\ a_attr bool		a_name##_booted = false;
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
value|a_attr pthread_key_t	a_name##_tsd;					\ a_attr tsd_init_head_t	a_name##_tsd_init_head = {			\ 	ql_head_initializer(blocks),					\ 	MALLOC_MUTEX_INITIALIZER					\ };									\ a_attr bool		a_name##_booted = false;
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
value|a_attr bool								\ a_name##_tsd_cleanup_wrapper(void)					\ {									\ 									\ 	if (a_name##_initialized) {					\ 		a_name##_initialized = false;				\ 		a_cleanup(&a_name##_tls);				\ 	}								\ 	return (a_name##_initialized);					\ }									\ a_attr bool								\ a_name##_tsd_boot(void)							\ {									\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		malloc_tsd_cleanup_register(				\&a_name##_tsd_cleanup_wrapper);			\ 	}								\ 	a_name##_booted = true;						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##_tsd_get(void)							\ {									\ 									\ 	assert(a_name##_booted);					\ 	return (&a_name##_tls);						\ }									\ a_attr void								\ a_name##_tsd_set(a_type *val)						\ {									\ 									\ 	assert(a_name##_booted);					\ 	a_name##_tls = (*val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		a_name##_initialized = true;				\ }
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
value|a_attr bool								\ a_name##_tsd_boot(void)							\ {									\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		if (pthread_key_create(&a_name##_tsd, a_cleanup) != 0)	\ 			return (true);					\ 	}								\ 	a_name##_booted = true;						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_type *								\ a_name##_tsd_get(void)							\ {									\ 									\ 	assert(a_name##_booted);					\ 	return (&a_name##_tls);						\ }									\ a_attr void								\ a_name##_tsd_set(a_type *val)						\ {									\ 									\ 	assert(a_name##_booted);					\ 	a_name##_tls = (*val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		if (pthread_setspecific(a_name##_tsd,			\ 		    (void *)(&a_name##_tls))) {				\ 			malloc_write("<jemalloc>: Error"		\ 			    " setting TSD for "#a_name"\n");		\ 			if (opt_abort)					\ 				abort();				\ 		}							\ 	}								\ }
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
comment|/* Data structure. */
define|\
value|typedef struct {							\ 	bool	initialized;						\ 	a_type	val;							\ } a_name##_tsd_wrapper_t;						\
comment|/* Initialization/cleanup. */
value|\ a_attr bool								\ a_name##_tsd_cleanup_wrapper(void)					\ {									\ 	a_name##_tsd_wrapper_t *wrapper;				\ 									\ 	wrapper = (a_name##_tsd_wrapper_t *) TlsGetValue(a_name##_tsd);	\ 	if (wrapper == NULL)						\ 		return (false);						\ 	if (a_cleanup != malloc_tsd_no_cleanup&&			\ 	    wrapper->initialized) {					\ 		a_type val = wrapper->val;				\ 		a_type tsd_static_data = a_initializer;			\ 		wrapper->initialized = false;				\ 		wrapper->val = tsd_static_data;				\ 		a_cleanup(&val);					\ 		if (wrapper->initialized) {				\
comment|/* Trigger another cleanup round. */
value|\ 			return (true);					\ 		}							\ 	}								\ 	malloc_tsd_dalloc(wrapper);					\ 	return (false);							\ }									\ a_attr bool								\ a_name##_tsd_boot(void)							\ {									\ 									\ 	a_name##_tsd = TlsAlloc();					\ 	if (a_name##_tsd == TLS_OUT_OF_INDEXES)				\ 		return (true);						\ 	if (a_cleanup != malloc_tsd_no_cleanup) {			\ 		malloc_tsd_cleanup_register(				\&a_name##_tsd_cleanup_wrapper);			\ 	}								\ 	a_name##_booted = true;						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_name##_tsd_wrapper_t *						\ a_name##_tsd_get_wrapper(void)						\ {									\ 	a_name##_tsd_wrapper_t *wrapper = (a_name##_tsd_wrapper_t *)	\ 	    TlsGetValue(a_name##_tsd);					\ 									\ 	if (wrapper == NULL) {						\ 		wrapper = (a_name##_tsd_wrapper_t *)			\ 		    malloc_tsd_malloc(sizeof(a_name##_tsd_wrapper_t));	\ 		if (wrapper == NULL) {					\ 			malloc_write("<jemalloc>: Error allocating"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		} else {						\ 			static a_type tsd_static_data = a_initializer;	\ 			wrapper->initialized = false;			\ 			wrapper->val = tsd_static_data;			\ 		}							\ 		if (!TlsSetValue(a_name##_tsd, (void *)wrapper)) {	\ 			malloc_write("<jemalloc>: Error setting"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		}							\ 	}								\ 	return (wrapper);						\ }									\ a_attr a_type *								\ a_name##_tsd_get(void)							\ {									\ 	a_name##_tsd_wrapper_t *wrapper;				\ 									\ 	assert(a_name##_booted);					\ 	wrapper = a_name##_tsd_get_wrapper();				\ 	return (&wrapper->val);						\ }									\ a_attr void								\ a_name##_tsd_set(a_type *val)						\ {									\ 	a_name##_tsd_wrapper_t *wrapper;				\ 									\ 	assert(a_name##_booted);					\ 	wrapper = a_name##_tsd_get_wrapper();				\ 	wrapper->val = *(val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		wrapper->initialized = true;				\ }
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
comment|/* Data structure. */
define|\
value|typedef struct {							\ 	bool	initialized;						\ 	a_type	val;							\ } a_name##_tsd_wrapper_t;						\
comment|/* Initialization/cleanup. */
value|\ a_attr void								\ a_name##_tsd_cleanup_wrapper(void *arg)					\ {									\ 	a_name##_tsd_wrapper_t *wrapper = (a_name##_tsd_wrapper_t *)arg;\ 									\ 	if (a_cleanup != malloc_tsd_no_cleanup&&			\ 	    wrapper->initialized) {					\ 		wrapper->initialized = false;				\ 		a_cleanup(&wrapper->val);				\ 		if (wrapper->initialized) {				\
comment|/* Trigger another cleanup round. */
value|\ 			if (pthread_setspecific(a_name##_tsd,		\ 			    (void *)wrapper)) {				\ 				malloc_write("<jemalloc>: Error"	\ 				    " setting TSD for "#a_name"\n");	\ 				if (opt_abort)				\ 					abort();			\ 			}						\ 			return;						\ 		}							\ 	}								\ 	malloc_tsd_dalloc(wrapper);					\ }									\ a_attr bool								\ a_name##_tsd_boot(void)							\ {									\ 									\ 	if (pthread_key_create(&a_name##_tsd,				\ 	    a_name##_tsd_cleanup_wrapper) != 0)				\ 		return (true);						\ 	a_name##_booted = true;						\ 	return (false);							\ }									\
comment|/* Get/set. */
value|\ a_attr a_name##_tsd_wrapper_t *						\ a_name##_tsd_get_wrapper(void)						\ {									\ 	a_name##_tsd_wrapper_t *wrapper = (a_name##_tsd_wrapper_t *)	\ 	    pthread_getspecific(a_name##_tsd);				\ 									\ 	if (wrapper == NULL) {						\ 		tsd_init_block_t block;					\ 		wrapper = tsd_init_check_recursion(			\&a_name##_tsd_init_head,&block);			\ 		if (wrapper)						\ 		    return (wrapper);					\ 		wrapper = (a_name##_tsd_wrapper_t *)			\ 		    malloc_tsd_malloc(sizeof(a_name##_tsd_wrapper_t));	\ 		block.data = wrapper;					\ 		if (wrapper == NULL) {					\ 			malloc_write("<jemalloc>: Error allocating"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		} else {						\ 			static a_type tsd_static_data = a_initializer;	\ 			wrapper->initialized = false;			\ 			wrapper->val = tsd_static_data;			\ 		}							\ 		if (pthread_setspecific(a_name##_tsd,			\ 		    (void *)wrapper)) {					\ 			malloc_write("<jemalloc>: Error setting"	\ 			    " TSD for "#a_name"\n");			\ 			abort();					\ 		}							\ 		tsd_init_finish(&a_name##_tsd_init_head,&block);	\ 	}								\ 	return (wrapper);						\ }									\ a_attr a_type *								\ a_name##_tsd_get(void)							\ {									\ 	a_name##_tsd_wrapper_t *wrapper;				\ 									\ 	assert(a_name##_booted);					\ 	wrapper = a_name##_tsd_get_wrapper();				\ 	return (&wrapper->val);						\ }									\ a_attr void								\ a_name##_tsd_set(a_type *val)						\ {									\ 	a_name##_tsd_wrapper_t *wrapper;				\ 									\ 	assert(a_name##_booted);					\ 	wrapper = a_name##_tsd_get_wrapper();				\ 	wrapper->val = *(val);						\ 	if (a_cleanup != malloc_tsd_no_cleanup)				\ 		wrapper->initialized = true;				\ }
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
name|void
name|malloc_tsd_boot
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

