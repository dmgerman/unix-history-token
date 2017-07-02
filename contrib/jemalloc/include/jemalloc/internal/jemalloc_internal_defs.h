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
comment|/*  * Define overrides for non-standard allocator-related functions if they are  * present on the system.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_CALLOC */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_FREE */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_MALLOC */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_MEMALIGN */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_REALLOC */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OVERRIDE___LIBC_VALLOC */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_OVERRIDE___POSIX_MEMALIGN
end_define

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
comment|/*  * Number of significant bits in virtual addresses.  This may be less than the  * total number of bits in a pointer, e.g. on x64, for which the uppermost 16  * bits are the same as bit 47.  */
end_comment

begin_define
define|#
directive|define
name|LG_VADDR
value|48
end_define

begin_comment
comment|/* Defined if C11 atomics are available. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_C11_ATOMICS */
end_comment

begin_comment
comment|/* Defined if GCC __atomic atomics are available. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_GCC_ATOMIC_ATOMICS */
end_comment

begin_comment
comment|/* Defined if GCC __sync atomics are available. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_GCC_SYNC_ATOMICS
value|1
end_define

begin_comment
comment|/*  * Defined if __sync_add_and_fetch(uint32_t *, uint32_t) and  * __sync_sub_and_fetch(uint32_t *, uint32_t) are available, despite  * __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 not being defined (which means the  * functions are defined in libgcc instead of being inlines).  */
end_comment

begin_define
define|#
directive|define
name|JE_FORCE_SYNC_COMPARE_AND_SWAP_4
end_define

begin_comment
comment|/*  * Defined if __sync_add_and_fetch(uint64_t *, uint64_t) and  * __sync_sub_and_fetch(uint64_t *, uint64_t) are available, despite  * __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 not being defined (which means the  * functions are defined in libgcc instead of being inlines).  */
end_comment

begin_define
define|#
directive|define
name|JE_FORCE_SYNC_COMPARE_AND_SWAP_8
end_define

begin_comment
comment|/*  * Defined if __builtin_clz() and __builtin_clzl() are available.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_BUILTIN_CLZ
end_define

begin_comment
comment|/*  * Defined if os_unfair_lock_*() functions are available, as provided by Darwin.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OS_UNFAIR_LOCK */
end_comment

begin_comment
comment|/*  * Defined if OSSpin*() functions are available, as provided by Darwin, and  * documented in the spinlock(3) manual page.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_OSSPIN */
end_comment

begin_comment
comment|/* Defined if syscall(2) is usable. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_USE_SYSCALL
end_define

begin_comment
comment|/*  * Defined if secure_getenv(3) is available.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAVE_SECURE_GETENV */
end_comment

begin_comment
comment|/*  * Defined if issetugid(2) is available.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_ISSETUGID
end_define

begin_comment
comment|/* Defined if pthread_atfork(3) is available. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_PTHREAD_ATFORK
end_define

begin_comment
comment|/*  * Defined if clock_gettime(CLOCK_MONOTONIC_COARSE, ...) is available.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAVE_CLOCK_MONOTONIC_COARSE */
end_comment

begin_comment
comment|/*  * Defined if clock_gettime(CLOCK_MONOTONIC, ...) is available.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_CLOCK_MONOTONIC
value|1
end_define

begin_comment
comment|/*  * Defined if mach_absolute_time() is available.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAVE_MACH_ABSOLUTE_TIME */
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
comment|/* Non-empty if the tls_model attribute is supported. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_TLS_MODEL
value|__attribute__((tls_model("initial-exec")))
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
comment|/*  * JEMALLOC_DSS enables use of sbrk(2) to allocate extents from the data storage  * segment (DSS).  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_DSS
end_define

begin_comment
comment|/* Support memory filling (junk/zero). */
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
comment|/*  * Minimum allocation alignment is 2^LG_QUANTUM bytes (ignoring tiny size  * classes).  */
end_comment

begin_comment
comment|/* #undef LG_QUANTUM */
end_comment

begin_comment
comment|/* One page is 2^LG_PAGE bytes. */
end_comment

begin_define
define|#
directive|define
name|LG_PAGE
value|12
end_define

begin_comment
comment|/*  * One huge page is 2^LG_HUGEPAGE bytes.  Note that this is defined even if the  * system does not explicitly support huge pages; system calls that require  * explicit huge page support are separately configured.  */
end_comment

begin_define
define|#
directive|define
name|LG_HUGEPAGE
value|21
end_define

begin_comment
comment|/*  * If defined, adjacent virtual memory mappings with identical attributes  * automatically coalesce, and they fragment when changes are made to subranges.  * This is the normal order of things for mmap()/munmap(), but on Windows  * VirtualAlloc()/VirtualFree() operations must be precisely matched, i.e.  * mappings do *not* coalesce/fragment.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_MAPS_COALESCE
end_define

begin_comment
comment|/*  * If defined, retain memory for later reuse by default rather than using e.g.  * munmap() to unmap freed extents.  This is enabled on 64-bit Linux because  * common sequences of mmap()/munmap() calls will cause virtual memory map  * holes.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_RETAIN */
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
comment|/*  * Used to mark unreachable code to quiet "end of non-void" compiler warnings.  * Don't use this directly; instead use unreachable() from util.h  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_UNREACHABLE
value|abort
end_define

begin_comment
comment|/*  * ffs*() functions to use for bitmapping.  Don't use these directly; instead,  * use ffs_*() from util.h.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_FFSLL
value|__builtin_ffsll
end_define

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_FFSL
value|__builtin_ffsl
end_define

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_FFS
value|__builtin_ffs
end_define

begin_comment
comment|/*  * If defined, explicitly attempt to more uniformly distribute large allocation  * pointer alignments across all cache indices.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_CACHE_OBLIVIOUS
end_define

begin_comment
comment|/*  * Darwin (OS X) uses zones to work around Mach-O symbol override shortcomings.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_ZONE */
end_comment

begin_comment
comment|/*  * Methods for determining whether the OS overcommits.  * JEMALLOC_PROC_SYS_VM_OVERCOMMIT_MEMORY: Linux's  *                                         /proc/sys/vm.overcommit_memory file.  * JEMALLOC_SYSCTL_VM_OVERCOMMIT: FreeBSD's vm.overcommit sysctl.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_SYSCTL_VM_OVERCOMMIT
end_define

begin_comment
comment|/* #undef JEMALLOC_PROC_SYS_VM_OVERCOMMIT_MEMORY */
end_comment

begin_comment
comment|/* Defined if madvise(2) is available. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_MADVISE
end_define

begin_comment
comment|/*  * Methods for purging unused pages differ between operating systems.  *  *   madvise(..., MADV_FREE) : This marks pages as being unused, such that they  *                             will be discarded rather than swapped out.  *   madvise(..., MADV_DONTNEED) : If JEMALLOC_PURGE_MADVISE_DONTNEED_ZEROS is  *                                 defined, this immediately discards pages,  *                                 such that new pages will be demand-zeroed if  *                                 the address region is later touched;  *                                 otherwise this behaves similarly to  *                                 MADV_FREE, though typically with higher  *                                 system overhead.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_PURGE_MADVISE_FREE
end_define

begin_define
define|#
directive|define
name|JEMALLOC_PURGE_MADVISE_DONTNEED
end_define

begin_comment
comment|/* #undef JEMALLOC_PURGE_MADVISE_DONTNEED_ZEROS */
end_comment

begin_comment
comment|/*  * Defined if transparent huge pages (THPs) are supported via the  * MADV_[NO]HUGEPAGE arguments to madvise(2), and THP support is enabled.  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_THP */
end_comment

begin_comment
comment|/* Define if operating system has alloca.h header. */
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
comment|/* sizeof(long long) == 2^LG_SIZEOF_LONG_LONG. */
end_comment

begin_define
define|#
directive|define
name|LG_SIZEOF_LONG_LONG
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

begin_comment
comment|/* glibc malloc hooks (__malloc_hook, __realloc_hook, __free_hook). */
end_comment

begin_comment
comment|/* #undef JEMALLOC_GLIBC_MALLOC_HOOK */
end_comment

begin_comment
comment|/* glibc memalign hook. */
end_comment

begin_comment
comment|/* #undef JEMALLOC_GLIBC_MEMALIGN_HOOK */
end_comment

begin_comment
comment|/* pthread support */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_PTHREAD
end_define

begin_comment
comment|/* dlsym() support */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_DLSYM
end_define

begin_comment
comment|/* Adaptive mutex support in pthreads. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_HAVE_PTHREAD_MUTEX_ADAPTIVE_NP
end_define

begin_comment
comment|/* GNU specific sched_getcpu support */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAVE_SCHED_GETCPU */
end_comment

begin_comment
comment|/* GNU specific sched_setaffinity support */
end_comment

begin_comment
comment|/* #undef JEMALLOC_HAVE_SCHED_SETAFFINITY */
end_comment

begin_comment
comment|/*  * If defined, all the features necessary for background threads are present.  */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_BACKGROUND_THREAD
value|1
end_define

begin_comment
comment|/*  * If defined, jemalloc symbols are not exported (doesn't work when  * JEMALLOC_PREFIX is not defined).  */
end_comment

begin_comment
comment|/* #undef JEMALLOC_EXPORT */
end_comment

begin_comment
comment|/* config.malloc_conf options string. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_CONFIG_MALLOC_CONF
value|"abort_conf:false"
end_define

begin_comment
comment|/* If defined, jemalloc takes the malloc/free/etc. symbol names. */
end_comment

begin_define
define|#
directive|define
name|JEMALLOC_IS_MALLOC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_DEFS_H_ */
end_comment

end_unit

