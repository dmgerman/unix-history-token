begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/jemalloc/jemalloc_defs.h.  Generated from jemalloc_defs.h.in by configure.  */
end_comment

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
comment|/*  * Name mangling for public symbols is controlled by --with-mangling and  * --with-jemalloc-prefix.  With default settings the je_ prefix is stripped by  * these macro definitions.  */
end_comment

begin_define
define|#
directive|define
name|je_malloc_conf
value|malloc_conf
end_define

begin_define
define|#
directive|define
name|je_malloc_message
value|malloc_message
end_define

begin_define
define|#
directive|define
name|je_malloc
value|malloc
end_define

begin_define
define|#
directive|define
name|je_calloc
value|calloc
end_define

begin_define
define|#
directive|define
name|je_posix_memalign
value|posix_memalign
end_define

begin_define
define|#
directive|define
name|je_aligned_alloc
value|aligned_alloc
end_define

begin_define
define|#
directive|define
name|je_realloc
value|realloc
end_define

begin_define
define|#
directive|define
name|je_free
value|free
end_define

begin_define
define|#
directive|define
name|je_malloc_usable_size
value|malloc_usable_size
end_define

begin_define
define|#
directive|define
name|je_malloc_stats_print
value|malloc_stats_print
end_define

begin_define
define|#
directive|define
name|je_mallctl
value|mallctl
end_define

begin_define
define|#
directive|define
name|je_mallctlnametomib
value|mallctlnametomib
end_define

begin_define
define|#
directive|define
name|je_mallctlbymib
value|mallctlbymib
end_define

begin_comment
comment|/* #undef je_memalign */
end_comment

begin_define
define|#
directive|define
name|je_valloc
value|valloc
end_define

begin_define
define|#
directive|define
name|je_allocm
value|allocm
end_define

begin_define
define|#
directive|define
name|je_rallocm
value|rallocm
end_define

begin_define
define|#
directive|define
name|je_sallocm
value|sallocm
end_define

begin_define
define|#
directive|define
name|je_dallocm
value|dallocm
end_define

begin_define
define|#
directive|define
name|je_nallocm
value|nallocm
end_define

begin_comment
comment|/*  * JEMALLOC_PRIVATE_NAMESPACE is used as a prefix for all library-private APIs.  * For shared libraries, symbol visibility mechanisms prevent these symbols  * from being exported, but for static libraries, naming collisions are a real  * possibility.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_PRIVATE_NAMESPACE
value|"__jemalloc_"
end_define

begin_define
define|#
directive|define
name|JEMALLOC_N
parameter_list|(
name|string_that_no_one_should_want_to_use_as_a_jemalloc_private_namespace_prefix
parameter_list|)
value|__jemalloc_##string_that_no_one_should_want_to_use_as_a_jemalloc_private_namespace_prefix
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
comment|/* Defined if __attribute__((...)) syntax is supported. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_ATTR
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_HAVE_ATTR
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_ATTR
parameter_list|(
name|s
parameter_list|)
value|__attribute__((s))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_EXPORT
value|JEMALLOC_ATTR(visibility("default"))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_ALIGNED
parameter_list|(
name|s
parameter_list|)
value|JEMALLOC_ATTR(aligned(s))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_SECTION
parameter_list|(
name|s
parameter_list|)
value|JEMALLOC_ATTR(section(s))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_NOINLINE
value|JEMALLOC_ATTR(noinline)
end_define

begin_elif
elif|#
directive|elif
name|_MSC_VER
end_elif

begin_define
define|#
directive|define
name|JEMALLOC_ATTR
parameter_list|(
name|s
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DLLEXPORT
end_ifdef

begin_define
define|#
directive|define
name|JEMALLOC_EXPORT
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_EXPORT
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JEMALLOC_ALIGNED
parameter_list|(
name|s
parameter_list|)
value|__declspec(align(s))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_SECTION
parameter_list|(
name|s
parameter_list|)
value|__declspec(allocate(s))
end_define

begin_define
define|#
directive|define
name|JEMALLOC_NOINLINE
value|__declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JEMALLOC_ATTR
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_EXPORT
end_define

begin_define
define|#
directive|define
name|JEMALLOC_ALIGNED
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_SECTION
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|JEMALLOC_NOINLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Support the experimental API. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_EXPERIMENTAL
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
comment|/*  * Define overrides for non-standard allocator-related functions if they  * are present on the system.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE_MEMALIGN */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_OVERRIDE_VALLOC
end_define

begin_comment
comment|/*  * At least Linux omits the "const" in:  *  *   size_t malloc_usable_size(const void *ptr);  *  * Match the operating system's prototype.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_USABLE_SIZE_CONST
value|const
end_define

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
comment|/* sizeof(void *) == 2^LG_SIZEOF_PTR. */
end_comment

begin_define
define|#
directive|define
name|LG_SIZEOF_PTR
value|3
end_define

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

end_unit

