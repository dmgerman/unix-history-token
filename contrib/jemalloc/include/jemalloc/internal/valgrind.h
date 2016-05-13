begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_VALGRIND
end_ifdef

begin_include
include|#
directive|include
file|<valgrind/valgrind.h>
end_include

begin_comment
comment|/*  * The size that is reported to Valgrind must be consistent through a chain of  * malloc..realloc..realloc calls.  Request size isn't recorded anywhere in  * jemalloc, so it is critical that all callers of these macros provide usize  * rather than request size.  As a result, buffer overflow detection is  * technically weakened for the standard API, though it is generally accepted  * practice to consider any extra bytes reported by malloc_usable_size() as  * usable space.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_NOACCESS
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {		\ 	if (unlikely(in_valgrind))					\ 		valgrind_make_mem_noaccess(ptr, usize);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_UNDEFINED
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {		\ 	if (unlikely(in_valgrind))					\ 		valgrind_make_mem_undefined(ptr, usize);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {		\ 	if (unlikely(in_valgrind))					\ 		valgrind_make_mem_defined(ptr, usize);			\ } while (0)
end_define

begin_comment
comment|/*  * The VALGRIND_MALLOCLIKE_BLOCK() and VALGRIND_RESIZEINPLACE_BLOCK() macro  * calls must be embedded in macros rather than in functions so that when  * Valgrind reports errors, there are no extra stack frames in the backtraces.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MALLOC
parameter_list|(
name|cond
parameter_list|,
name|tsdn
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|zero
parameter_list|)
value|do {	\ 	if (unlikely(in_valgrind&& cond)) {				\ 		VALGRIND_MALLOCLIKE_BLOCK(ptr, usize, p2rz(tsdn, ptr),	\ 		    zero);						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_REALLOC
parameter_list|(
name|maybe_moved
parameter_list|,
name|tsdn
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,	\
name|ptr_maybe_null
parameter_list|,
name|old_ptr
parameter_list|,
name|old_usize
parameter_list|,
name|old_rzsize
parameter_list|,
name|old_ptr_maybe_null
parameter_list|,	\
name|zero
parameter_list|)
value|do {								\ 	if (unlikely(in_valgrind)) {					\ 		size_t rzsize = p2rz(tsdn, ptr);			\ 									\ 		if (!maybe_moved || ptr == old_ptr) {			\ 			VALGRIND_RESIZEINPLACE_BLOCK(ptr, old_usize,	\ 			    usize, rzsize);				\ 			if (zero&& old_usize< usize) {		\ 				valgrind_make_mem_defined(		\ 				    (void *)((uintptr_t)ptr +		\ 				    old_usize), usize - old_usize);	\ 			}						\ 		} else {						\ 			if (!old_ptr_maybe_null || old_ptr != NULL) {	\ 				valgrind_freelike_block(old_ptr,	\ 				    old_rzsize);			\ 			}						\ 			if (!ptr_maybe_null || ptr != NULL) {		\ 				size_t copy_size = (old_usize< usize)	\ 				    ?  old_usize : usize;		\ 				size_t tail_size = usize - copy_size;	\ 				VALGRIND_MALLOCLIKE_BLOCK(ptr, usize,	\ 				    rzsize, false);			\ 				if (copy_size> 0) {			\ 					valgrind_make_mem_defined(ptr,	\ 					copy_size);			\ 				}					\ 				if (zero&& tail_size> 0) {		\ 					valgrind_make_mem_defined(	\ 					    (void *)((uintptr_t)ptr +	\ 					    copy_size), tail_size);	\ 				}					\ 			}						\ 		}							\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_FREE
parameter_list|(
name|ptr
parameter_list|,
name|rzsize
parameter_list|)
value|do {			\ 	if (unlikely(in_valgrind))					\ 		valgrind_freelike_block(ptr, rzsize);			\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RUNNING_ON_VALGRIND
value|((unsigned)0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_NOACCESS
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_UNDEFINED
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
name|ptr
parameter_list|,
name|usize
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_MALLOC
parameter_list|(
name|cond
parameter_list|,
name|tsdn
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,
name|zero
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_REALLOC
parameter_list|(
name|maybe_moved
parameter_list|,
name|tsdn
parameter_list|,
name|ptr
parameter_list|,
name|usize
parameter_list|,	\
name|ptr_maybe_null
parameter_list|,
name|old_ptr
parameter_list|,
name|old_usize
parameter_list|,
name|old_rzsize
parameter_list|,
name|old_ptr_maybe_null
parameter_list|,	\
name|zero
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_VALGRIND_FREE
parameter_list|(
name|ptr
parameter_list|,
name|rzsize
parameter_list|)
value|do {} while (0)
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
name|JEMALLOC_VALGRIND
end_ifdef

begin_function_decl
name|void
name|valgrind_make_mem_noaccess
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|usize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|valgrind_make_mem_undefined
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|usize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|valgrind_make_mem_defined
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|usize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|valgrind_freelike_block
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|usize
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

