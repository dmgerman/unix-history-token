begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/jemalloc/internal/jemalloc_internal_defs.h.  Generated from jemalloc_internal_defs.h.in by configure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_DEFS_H_
end_define

begin_comment
comment|/*  * If JEMALLOC_PREFIX is defined via --with-jemalloc-prefix, it will cause all  * public APIs to be prefixed.  This makes it possible, with some care, to use  * multiple allocators simultaneously.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PREFIX */
end_comment

begin_comment
comment|/* #undef JEMALLOC_CPREFIX */
end_comment

begin_comment
comment|/*  * JEMALLOC_PRIVATE_NAMESPACE is used as a prefix for all library-private APIs.  * For shared libraries, symbol visibility mechanisms prevent these symbols  * from being exported, but for static libraries, naming collisions are a real  * possibility.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_PRIVATE_NAMESPACE
value|__je_
end_define

begin_comment
comment|/*  * Hyper-threaded CPUs may need a special instruction inside spin loops in  * order to yield to another virtual CPU.  */
end_comment

begin_define
define|#
directive|define
name|CPU_SPINWAIT
value|__asm__ volatile("pause")
end_define

begin_comment
comment|/* Defined if the equivalent of FreeBSD's atomic(9) functions are available. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_ATOMIC9
value|1
end_define

begin_comment
comment|/*  * Defined if OSAtomic*() functions are available, as provided by Darwin, and  * documented in the atomic(3) manual page.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OSATOMIC */
end_comment

begin_comment
comment|/*  * Defined if __sync_add_and_fetch(uint32_t *, uint32_t) and  * __sync_sub_and_fetch(uint32_t *, uint32_t) are available, despite  * __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 not being defined (which means the  * functions are defined in libgcc instead of being inlines)  */
end_comment

begin_comment
comment|/* #undef JE_FORCE_SYNC_COMPARE_AND_SWAP_4 */
end_comment

begin_comment
comment|/*  * Defined if __sync_add_and_fetch(uint64_t *, uint64_t) and  * __sync_sub_and_fetch(uint64_t *, uint64_t) are available, despite  * __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 not being defined (which means the  * functions are defined in libgcc instead of being inlines)  */
end_comment

begin_comment
comment|/* #undef JE_FORCE_SYNC_COMPARE_AND_SWAP_8 */
end_comment

begin_comment
comment|/*  * Defined if OSSpin*() functions are available, as provided by Darwin, and  * documented in the spinlock(3) manual page.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OSSPIN */
end_comment

begin_comment
comment|/*  * Defined if _malloc_thread_cleanup() exists.  At least in the case of  * FreeBSD, pthread_key_create() allocates, which if used during malloc  * bootstrapping will cause recursion into the pthreads library.  Therefore, if  * _malloc_thread_cleanup() exists, use it as the basis for thread cleanup in  * malloc_tsd.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_MALLOC_THREAD_CLEANUP
end_define

begin_comment
comment|/*  * Defined if threaded initialization is known to be safe on this platform.  * Among other things, it must be possible to initialize a mutex without  * triggering allocation in order for threaded allocation to be safe.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_THREADED_INIT */
end_comment

begin_comment
comment|/*  * Defined if the pthreads implementation defines  * _pthread_mutex_init_calloc_cb(), in which case the function is used in order  * to avoid recursive allocation during mutex initialization.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_MUTEX_INIT_CB
value|1
end_define

begin_comment
comment|/* Defined if sbrk() is supported. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_SBRK
end_define

begin_comment
comment|/* Non-empty if the tls_model attribute is supported. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
value|__attribute__((tls_model("initial-exec")))
end_define

begin_comment
comment|/* JEMALLOC_CC_SILENCE enables code that silences unuseful compiler warnings. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_CC_SILENCE
end_define

begin_comment
comment|/* JEMALLOC_CODE_COVERAGE enables test code coverage analysis. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_CODE_COVERAGE */
end_comment

begin_comment
comment|/*  * JEMALLOC_DEBUG enables assertions and other sanity checks, and disables  * inline functions.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_DEBUG */
end_comment

begin_comment
comment|/* JEMALLOC_STATS enables statistics calculation. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_STATS
end_define

begin_comment
comment|/* JEMALLOC_PROF enables allocation profiling. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PROF */
end_comment

begin_comment
comment|/* Use libunwind for profile backtracing if defined. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PROF_LIBUNWIND */
end_comment

begin_comment
comment|/* Use libgcc for profile backtracing if defined. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PROF_LIBGCC */
end_comment

begin_comment
comment|/* Use gcc intrinsics for profile backtracing if defined. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PROF_GCC */
end_comment

begin_comment
comment|/*  * JEMALLOC_TCACHE enables a thread-specific caching layer for small objects.  * This makes it possible to allocate/deallocate objects without any locking  * when the cache is in the steady state.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_TCACHE
end_define

begin_comment
comment|/*  * JEMALLOC_DSS enables use of sbrk(2) to allocate chunks from the data storage  * segment (DSS).  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_DSS
end_define

begin_comment
comment|/* Support memory filling (junk/zero/quarantine/redzone). */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_FILL
end_define

begin_comment
comment|/* Support utrace(2)-based tracing. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_UTRACE
end_define

begin_comment
comment|/* Support Valgrind. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_VALGRIND */
end_comment

begin_comment
comment|/* Support optional abort() on OOM. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_XMALLOC
end_define

begin_comment
comment|/* Support lazy locking (avoid locking unless a second thread is launched). */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_LAZY_LOCK
end_define

begin_comment
comment|/* One page is 2^STATIC_PAGE_SHIFT bytes. */
end_comment

begin_define
define|#
directive|define
name|STATIC_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/*  * If defined, use munmap() to unmap freed chunks, rather than storing them for  * later reuse.  This is disabled by default on Linux because common sequences  * of mmap()/munmap() calls will cause virtual memory map holes.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_MUNMAP
end_define

begin_comment
comment|/*  * If defined, use mremap(...MREMAP_FIXED...) for huge realloc().  This is  * disabled by default because it is Linux-specific and it will cause virtual  * memory map holes, much like munmap(2) does.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_MREMAP */
end_comment

begin_comment
comment|/* TLS is used to map arenas and magazine caches to threads. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_TLS
end_define

begin_comment
comment|/*  * JEMALLOC_IVSALLOC enables ivsalloc(), which verifies that pointers reside  * within jemalloc-owned chunks before dereferencing them.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_IVSALLOC */
end_comment

begin_comment
comment|/*  * Darwin (OS X) uses zones to work around Mach-O symbol override shortcomings.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_ZONE */
end_comment

begin_comment
comment|/* #undef JEMALLOC_ZONE_VERSION */
end_comment

begin_comment
comment|/*  * Methods for purging unused pages differ between operating systems.  *  *   madvise(..., MADV_DONTNEED) : On Linux, this immediately discards pages,  *                                 such that new pages will be demand-zeroed if  *                                 the address region is later touched.  *   madvise(..., MADV_FREE) : On FreeBSD and Darwin, this marks pages as being  *                             unused, such that they will be discarded rather  *                             than swapped out.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_PURGE_MADVISE_DONTNEED */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_PURGE_MADVISE_FREE
end_define

begin_comment
comment|/*  * Define if operating system has alloca.h header.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAS_ALLOCA_H */
end_comment

begin_comment
comment|/* C99 restrict keyword supported. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAS_RESTRICT
value|1
end_define

begin_comment
comment|/* For use by hash code. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_BIG_ENDIAN */
end_comment

begin_comment
comment|/* sizeof(int) == 2^LG_SIZEOF_INT. */
end_comment

begin_define
define|#
directive|define
name|LG_SIZEOF_INT
value|2
end_define

begin_comment
comment|/* sizeof(long) == 2^LG_SIZEOF_LONG. */
end_comment

begin_define
define|#
directive|define
name|LG_SIZEOF_LONG
value|3
end_define

begin_comment
comment|/* sizeof(intmax_t) == 2^LG_SIZEOF_INTMAX_T. */
end_comment

begin_define
define|#
directive|define
name|LG_SIZEOF_INTMAX_T
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_DEFS_H_ */
end_comment

end_unit

