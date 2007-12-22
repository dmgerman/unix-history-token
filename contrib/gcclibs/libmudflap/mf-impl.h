begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implementation header for mudflap runtime library.    Mudflap: narrow-pointer bounds-checking by tree rewriting.    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Frank Ch. Eigler<fche@redhat.com>    and Graydon Hoare<graydon@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MF_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|__MF_IMPL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MUDFLAP
end_ifdef

begin_error
error|#
directive|error
literal|"Do not compile this file with -fmudflap!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_PTHREAD_H
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_elif
elif|#
directive|elif
name|LIBMUDFLAPTH
end_elif

begin_error
error|#
directive|error
literal|"Cannot build libmudflapth without pthread.h."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__mf_uintptr_t
name|uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Private definitions related to mf-runtime.h  */
end_comment

begin_define
define|#
directive|define
name|__MF_TYPE_MAX_CEM
value|__MF_TYPE_STACK
end_define

begin_comment
comment|/* largest type# for the cemetary */
end_comment

begin_define
define|#
directive|define
name|__MF_TYPE_MAX
value|__MF_TYPE_GUESS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Address calculation macros.  */
end_comment

begin_define
define|#
directive|define
name|MINPTR
value|((uintptr_t) 0)
end_define

begin_define
define|#
directive|define
name|MAXPTR
value|(~ (uintptr_t) 0)
end_define

begin_comment
comment|/* Clamp the addition/subtraction of uintptr_t's to [MINPTR,MAXPTR] */
end_comment

begin_define
define|#
directive|define
name|CLAMPSUB
parameter_list|(
name|ptr
parameter_list|,
name|offset
parameter_list|)
value|(((uintptr_t) ptr)>= (offset) ? ((uintptr_t) ptr)-((uintptr_t) offset) : MINPTR)
end_define

begin_define
define|#
directive|define
name|CLAMPADD
parameter_list|(
name|ptr
parameter_list|,
name|offset
parameter_list|)
value|(((uintptr_t) ptr)<= MAXPTR-(offset) ? ((uintptr_t) ptr)+((uintptr_t) offset) : MAXPTR)
end_define

begin_define
define|#
directive|define
name|CLAMPSZ
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
value|((size) ? (((uintptr_t) ptr)<= MAXPTR-(size)+1 ? ((uintptr_t) ptr)+((uintptr_t) size) - 1 : MAXPTR) : ((uintptr_t) ptr))
end_define

begin_define
define|#
directive|define
name|__MF_CACHE_INDEX
parameter_list|(
name|ptr
parameter_list|)
value|((((uintptr_t) (ptr))>> __mf_lc_shift)& __mf_lc_mask)
end_define

begin_define
define|#
directive|define
name|__MF_CACHE_MISS_P
parameter_list|(
name|ptr
parameter_list|,
name|sz
parameter_list|)
value|({ \              struct __mf_cache *elem =& __mf_lookup_cache[__MF_CACHE_INDEX((ptr))]; \              ((elem->low> (uintptr_t) (ptr)) ||                  \ 	      (elem->high< (CLAMPADD((uintptr_t) (ptr), (uintptr_t) CLAMPSUB(sz,1) )))); })
end_define

begin_comment
comment|/* XXX: the above should use CLAMPSZ () */
end_comment

begin_comment
comment|/* Private functions. */
end_comment

begin_function_decl
specifier|extern
name|void
name|__mf_violation
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|uintptr_t
name|pc
parameter_list|,
specifier|const
name|char
modifier|*
name|location
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__mf_backtrace
parameter_list|(
name|char
modifier|*
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__mf_heuristic_check
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Type definitions. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* The mf_state type codes describe recursion and initialization order.     reentrant means we are inside a mf-runtime support routine, such as    __mf_register, and thus there should be no calls to any wrapped functions,    such as the wrapped malloc.  This indicates a bug if it occurs.    in_malloc means we are inside a real malloc call inside a wrapped malloc    call, and thus there should be no calls to any wrapped functions like the    wrapped mmap.  This happens on some systems due to how the system libraries    are constructed.  */
end_comment

begin_enum
enum|enum
name|__mf_state_enum
block|{
name|active
block|,
name|reentrant
block|,
name|in_malloc
block|}
enum|;
end_enum

begin_comment
comment|/* The __mf_options structure records optional or tunable aspects of the  mudflap library's behavior. There is a single global instance of this  structure which is populated from user input (in an environment variable)  when the library initializes. */
end_comment

begin_struct
struct|struct
name|__mf_options
block|{
comment|/* Emit a trace message for each call. */
name|unsigned
name|trace_mf_calls
decl_stmt|;
comment|/* Collect and emit statistics. */
name|unsigned
name|collect_stats
decl_stmt|;
comment|/* Set up a SIGUSR1 -> __mf_report handler. */
name|unsigned
name|sigusr1_report
decl_stmt|;
comment|/* Execute internal checking code. */
name|unsigned
name|internal_checking
decl_stmt|;
comment|/* Age object liveness periodically. */
name|unsigned
name|tree_aging
decl_stmt|;
comment|/* Adapt the lookup cache to working set. */
name|unsigned
name|adapt_cache
decl_stmt|;
comment|/* Print list of leaked heap objects on shutdown. */
name|unsigned
name|print_leaks
decl_stmt|;
comment|/* Detect reads of uninitialized objects. */
name|unsigned
name|check_initialization
decl_stmt|;
comment|/* Print verbose description of violations. */
name|unsigned
name|verbose_violations
decl_stmt|;
comment|/* Abbreviate duplicate object descriptions.  */
name|unsigned
name|abbreviate
decl_stmt|;
comment|/* Emit internal tracing message. */
name|unsigned
name|verbose_trace
decl_stmt|;
comment|/* Wipe stack/heap objects upon unwind.  */
name|unsigned
name|wipe_stack
decl_stmt|;
name|unsigned
name|wipe_heap
decl_stmt|;
comment|/* Maintain a queue of this many deferred free()s,      to trap use of freed memory. */
name|unsigned
name|free_queue_length
decl_stmt|;
comment|/* Maintain a history of this many past unregistered objects. */
name|unsigned
name|persistent_count
decl_stmt|;
comment|/* Pad allocated extents by this many bytes on either side. */
name|unsigned
name|crumple_zone
decl_stmt|;
comment|/* Maintain this many stack frames for contexts. */
name|unsigned
name|backtrace
decl_stmt|;
comment|/* Ignore read operations even if mode_check is in effect.  */
name|unsigned
name|ignore_reads
decl_stmt|;
comment|/* Collect register/unregister timestamps.  */
name|unsigned
name|timestamps
decl_stmt|;
ifdef|#
directive|ifdef
name|LIBMUDFLAPTH
comment|/* Thread stack size.  */
name|unsigned
name|thread_stack
decl_stmt|;
endif|#
directive|endif
comment|/* Major operation mode */
define|#
directive|define
name|mode_nop
value|0
comment|/* Do nothing.  */
define|#
directive|define
name|mode_populate
value|1
comment|/* Populate tree but do not check for violations.  */
define|#
directive|define
name|mode_check
value|2
comment|/* Populate and check for violations (normal).  */
define|#
directive|define
name|mode_violate
value|3
comment|/* Trigger a violation on every call (diagnostic).  */
name|unsigned
name|mudflap_mode
decl_stmt|;
comment|/* How to handle a violation. */
define|#
directive|define
name|viol_nop
value|0
comment|/* Return control to application. */
define|#
directive|define
name|viol_segv
value|1
comment|/* Signal self with segv. */
define|#
directive|define
name|viol_abort
value|2
comment|/* Call abort (). */
define|#
directive|define
name|viol_gdb
value|3
comment|/* Fork a debugger on self */
name|unsigned
name|violation_mode
decl_stmt|;
comment|/* Violation heuristics selection. */
name|unsigned
name|heur_stack_bound
decl_stmt|;
comment|/* allow current stack region */
name|unsigned
name|heur_proc_map
decl_stmt|;
comment|/* allow& cache /proc/self/map regions.  */
name|unsigned
name|heur_start_end
decl_stmt|;
comment|/* allow _start .. _end */
name|unsigned
name|heur_std_data
decl_stmt|;
comment|/* allow& cache stdlib data */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_comment
comment|/* This is a table of dynamically resolved function pointers. */
end_comment

begin_struct
struct|struct
name|__mf_dynamic_entry
block|{
name|void
modifier|*
name|pointer
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The definition of the array (mf-runtime.c) must match the enums!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|__mf_dynamic_entry
name|__mf_dynamic
index|[]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|__mf_dynamic_index
block|{
name|dyn_calloc
block|,
name|dyn_free
block|,
name|dyn_malloc
block|,
name|dyn_mmap
block|,
name|dyn_munmap
block|,
name|dyn_realloc
block|,
name|dyn_INITRESOLVE
block|,
comment|/* Marker for last init-time resolution. */
ifdef|#
directive|ifdef
name|LIBMUDFLAPTH
name|dyn_pthread_create
endif|#
directive|endif
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PIC */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Private global variables. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LIBMUDFLAPTH
end_ifdef

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|__mf_biglock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LOCKTH
parameter_list|()
value|do { extern unsigned long __mf_lock_contention; \                       int rc = pthread_mutex_trylock (& __mf_biglock); \                       if (rc) { __mf_lock_contention ++; \                                 rc = pthread_mutex_lock (& __mf_biglock); } \                       assert (rc==0); } while (0)
end_define

begin_define
define|#
directive|define
name|UNLOCKTH
parameter_list|()
value|do { int rc = pthread_mutex_unlock (& __mf_biglock); \                         assert (rc==0); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCKTH
parameter_list|()
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|UNLOCKTH
parameter_list|()
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBMUDFLAPTH
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TLS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|enum
name|__mf_state_enum
name|__mf_get_state
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__mf_set_state
parameter_list|(
name|enum
name|__mf_state_enum
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|LIBMUDFLAPTH
end_ifdef

begin_decl_stmt
specifier|extern
name|__thread
name|enum
name|__mf_state_enum
name|__mf_state_1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|enum
name|__mf_state_enum
name|__mf_state_1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|enum
name|__mf_state_enum
name|__mf_get_state
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__mf_state_1
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__mf_set_state
parameter_list|(
name|enum
name|__mf_state_enum
name|s
parameter_list|)
block|{
name|__mf_state_1
operator|=
name|s
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|__mf_starting_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|__mf_options
name|__mf_opts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* Utility macros. */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_define
define|#
directive|define
name|UNLIKELY
parameter_list|(
name|e
parameter_list|)
value|(__builtin_expect (!!(e), 0))
end_define

begin_define
define|#
directive|define
name|LIKELY
parameter_list|(
name|e
parameter_list|)
value|(__builtin_expect (!!(e), 1))
end_define

begin_define
define|#
directive|define
name|STRINGIFY2
parameter_list|(
name|e
parameter_list|)
value|#e
end_define

begin_define
define|#
directive|define
name|STRINGIFY
parameter_list|(
name|e
parameter_list|)
value|STRINGIFY2(e)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LIBMUDFLAPTH
end_ifdef

begin_define
define|#
directive|define
name|VERBOSE_TRACE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|do { if (UNLIKELY (__mf_opts.verbose_trace)) {  \       fprintf (stderr, "mf(%u): ", (unsigned) pthread_self ()); \       fprintf (stderr, __VA_ARGS__); \     } } while (0)
end_define

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|do { if (UNLIKELY (__mf_opts.trace_mf_calls)) { \       fprintf (stderr, "mf(%u): ", (unsigned) pthread_self ()); \       fprintf (stderr, __VA_ARGS__); \     } } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VERBOSE_TRACE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|do { if (UNLIKELY (__mf_opts.verbose_trace)) {  \       fprintf (stderr, "mf: "); \       fprintf (stderr, __VA_ARGS__); \     } } while (0)
end_define

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
modifier|...
parameter_list|)
define|\
value|do { if (UNLIKELY (__mf_opts.trace_mf_calls)) { \       fprintf (stderr, "mf: "); \       fprintf (stderr, __VA_ARGS__); \     } } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__MF_PERSIST_MAX
value|256
end_define

begin_define
define|#
directive|define
name|__MF_FREEQ_MAX
value|256
end_define

begin_comment
comment|/*    Wrapping and redirection:     Mudflap redirects a number of libc functions into itself, for "cheap"    verification (eg. strcpy, bzero, memcpy) and also to register /    unregister regions of memory as they are manipulated by the program    (eg. malloc/free, mmap/munmap).     There are two methods of wrapping.     (1) The static method involves a list of -wrap=foo flags being passed to    the linker, which then links references to "foo" to the symbol    "__wrap_foo", and links references to "__real_foo" to the symbol "foo".    When compiled without -DPIC, libmudflap.a contains such __wrap_foo    functions which delegate to __real_foo functions in libc to get their    work done.     (2) The dynamic method involves providing a definition of symbol foo in    libmudflap.so and linking it earlier in the compiler command line,    before libc.so. The function "foo" in libmudflap must then call    dlsym(RTLD_NEXT, "foo") to acquire a pointer to the "real" libc foo, or    at least the "next" foo in the dynamic link resolution order.     We switch between these two techniques by the presence of the -DPIC    #define passed in by libtool when building libmudflap. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_function_decl
specifier|extern
name|void
name|__mf_resolve_single_dynamic
parameter_list|(
name|struct
name|__mf_dynamic_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_define
define|#
directive|define
name|WRAPPER
parameter_list|(
name|ret
parameter_list|,
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ret __wrap_ ## fname (__VA_ARGS__)                    \     __attribute__ (( alias  (#fname)  ));             \ ret __real_ ## fname (__VA_ARGS__)                    \     __attribute__ (( alias  (#fname)  ));             \ ret fname (__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|ty
parameter_list|,
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|typedef ty (*__mf_fn_ ## fname) (__VA_ARGS__);       \  extern ty __mf_0fn_ ## fname (__VA_ARGS__);
end_define

begin_define
define|#
directive|define
name|CALL_REAL
parameter_list|(
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|({__mf_starting_p \      ? __mf_0fn_ ## fname (__VA_ARGS__) \     : (__mf_resolve_single_dynamic (& __mf_dynamic[dyn_ ## fname]), \        (((__mf_fn_ ## fname)(__mf_dynamic[dyn_ ## fname].pointer)) (__VA_ARGS__)));})
end_define

begin_define
define|#
directive|define
name|CALL_BACKUP
parameter_list|(
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__mf_0fn_ ## fname(__VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not PIC --> static library */
end_comment

begin_define
define|#
directive|define
name|WRAPPER
parameter_list|(
name|ret
parameter_list|,
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ret __wrap_ ## fname (__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|ty
parameter_list|,
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|extern ty __real_ ## fname (__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CALL_REAL
parameter_list|(
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__real_ ## fname (__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|CALL_BACKUP
parameter_list|(
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|__real_ ## fname(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PIC */
end_comment

begin_comment
comment|/* WRAPPER2 is for functions intercepted via macros at compile time. */
end_comment

begin_define
define|#
directive|define
name|WRAPPER2
parameter_list|(
name|ret
parameter_list|,
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|ret __mfwrap_ ## fname (__VA_ARGS__)
end_define

begin_comment
comment|/* Utility macros for mf-hooks*.c */
end_comment

begin_define
define|#
directive|define
name|MF_VALIDATE_EXTENT
parameter_list|(
name|value
parameter_list|,
name|size
parameter_list|,
name|acc
parameter_list|,
name|context
parameter_list|)
define|\
value|do { \   if (UNLIKELY (size> 0&& __MF_CACHE_MISS_P (value, size))) \     if (acc == __MF_CHECK_WRITE || ! __mf_opts.ignore_reads) \     __mf_check ((void *) (value), (size), acc, "(" context ")"); \  } while (0)
end_define

begin_define
define|#
directive|define
name|BEGIN_PROTECT
parameter_list|(
name|fname
parameter_list|,
modifier|...
parameter_list|)
define|\
value|if (UNLIKELY (__mf_starting_p)) \   {                                         \     return CALL_BACKUP(fname, __VA_ARGS__); \   }                                         \   else if (UNLIKELY (__mf_get_state () == reentrant))   \   {                                         \     extern unsigned long __mf_reentrancy;   \     __mf_reentrancy ++; \     return CALL_REAL(fname, __VA_ARGS__);   \   }                                         \   else if (UNLIKELY (__mf_get_state () == in_malloc))   \   {                                         \     return CALL_REAL(fname, __VA_ARGS__);   \   }                                         \   else                                      \   {                                         \     TRACE ("%s\n", __PRETTY_FUNCTION__); \   }
end_define

begin_comment
comment|/* There is an assumption here that these will only be called in routines    that call BEGIN_PROTECT at the start, and hence the state must always    be active when BEGIN_MALLOC_PROTECT is called.  */
end_comment

begin_define
define|#
directive|define
name|BEGIN_MALLOC_PROTECT
parameter_list|()
define|\
value|__mf_set_state (in_malloc)
end_define

begin_define
define|#
directive|define
name|END_MALLOC_PROTECT
parameter_list|()
define|\
value|__mf_set_state (active)
end_define

begin_comment
comment|/* Unlocked variants of main entry points from mf-runtime.h.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__mfu_check
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|location
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__mfu_register
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__mfu_unregister
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__mfu_report
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__mfu_set_options
parameter_list|(
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MF_IMPL_H */
end_comment

end_unit

