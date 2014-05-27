begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* include/arch/unix/apr_private.h.  Generated from apr_private.h.in by configure.  */
end_comment

begin_comment
comment|/* include/arch/unix/apr_private.h.in.  Generated from configure.in by autoheader.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_PRIVATE_H
end_define

begin_comment
comment|/* Define if building universal (internal helper macro) */
end_comment

begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
end_comment

begin_comment
comment|/* Define if apr_allocator should use mmap */
end_comment

begin_comment
comment|/* #undef APR_ALLOCATOR_USES_MMAP */
end_comment

begin_comment
comment|/* Define as function which can be used for conversion of strings to    apr_int64_t */
end_comment

begin_define
define|#
directive|define
name|APR_INT64_STRFN
value|strtol
end_define

begin_comment
comment|/* Define as function used for conversion of strings to apr_off_t */
end_comment

begin_define
define|#
directive|define
name|APR_OFF_T_STRFN
value|strtol
end_define

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to 1 if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to path of random device */
end_comment

begin_define
define|#
directive|define
name|DEV_RANDOM
value|"/dev/urandom"
end_define

begin_comment
comment|/* Define if struct dirent has an inode member */
end_comment

begin_define
define|#
directive|define
name|DIRENT_INODE
value|d_fileno
end_define

begin_comment
comment|/* Define if struct dirent has a d_type member */
end_comment

begin_define
define|#
directive|define
name|DIRENT_TYPE
value|d_type
end_define

begin_comment
comment|/* Define if DSO support uses dlfcn.h */
end_comment

begin_comment
comment|/* #undef DSO_USE_DLFCN */
end_comment

begin_comment
comment|/* Define if DSO support uses dyld.h */
end_comment

begin_comment
comment|/* #undef DSO_USE_DYLD */
end_comment

begin_comment
comment|/* Define if DSO support uses shl_load */
end_comment

begin_comment
comment|/* #undef DSO_USE_SHL */
end_comment

begin_comment
comment|/* Define to list of paths to EGD sockets */
end_comment

begin_comment
comment|/* #undef EGD_DEFAULT_SOCKET */
end_comment

begin_comment
comment|/* Define if fcntl locks affect threads within the process */
end_comment

begin_comment
comment|/* #undef FCNTL_IS_GLOBAL */
end_comment

begin_comment
comment|/* Define if fcntl returns EACCES when F_SETLK is already held */
end_comment

begin_comment
comment|/* #undef FCNTL_TRYACQUIRE_EACCES */
end_comment

begin_comment
comment|/* Define if flock locks affect threads within the process */
end_comment

begin_comment
comment|/* #undef FLOCK_IS_GLOBAL */
end_comment

begin_comment
comment|/* Define if gethostbyaddr is thread safe */
end_comment

begin_comment
comment|/* #undef GETHOSTBYADDR_IS_THREAD_SAFE */
end_comment

begin_comment
comment|/* Define if gethostbyname is thread safe */
end_comment

begin_comment
comment|/* #undef GETHOSTBYNAME_IS_THREAD_SAFE */
end_comment

begin_comment
comment|/* Define if gethostbyname_r has the glibc style */
end_comment

begin_define
define|#
directive|define
name|GETHOSTBYNAME_R_GLIBC2
value|1
end_define

begin_comment
comment|/* Define if gethostbyname_r has the hostent_data for the third argument */
end_comment

begin_comment
comment|/* #undef GETHOSTBYNAME_R_HOSTENT_DATA */
end_comment

begin_comment
comment|/* Define if getservbyname is thread safe */
end_comment

begin_comment
comment|/* #undef GETSERVBYNAME_IS_THREAD_SAFE */
end_comment

begin_comment
comment|/* Define if getservbyname_r has the glibc style */
end_comment

begin_define
define|#
directive|define
name|GETSERVBYNAME_R_GLIBC2
value|1
end_define

begin_comment
comment|/* Define if getservbyname_r has the OSF/1 style */
end_comment

begin_comment
comment|/* #undef GETSERVBYNAME_R_OSF1 */
end_comment

begin_comment
comment|/* Define if getservbyname_r has the Solaris style */
end_comment

begin_comment
comment|/* #undef GETSERVBYNAME_R_SOLARIS */
end_comment

begin_comment
comment|/* Define if accept4 function is supported */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACCEPT4
value|1
end_define

begin_comment
comment|/* Define if async i/o supports message q's */
end_comment

begin_comment
comment|/* #undef HAVE_AIO_MSGQ */
end_comment

begin_comment
comment|/* Define to 1 if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<alloca.h> and it should be used (not on Ultrix).    */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<arpa/inet.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_INET_H
value|1
end_define

begin_comment
comment|/* Define if compiler provides atomic builtins */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arm__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ATOMIC_BUILTINS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if BONE_VERSION is defined in sys/socket.h */
end_comment

begin_comment
comment|/* #undef HAVE_BONE_VERSION */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ByteOrder.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BYTEORDER_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `calloc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<conio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CONIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `create_area' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CREATE_AREA */
end_comment

begin_comment
comment|/* Define to 1 if you have the `create_sem' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CREATE_SEM */
end_comment

begin_comment
comment|/* Define to 1 if you have the<crypt.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CRYPT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<ctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `sys_siglist', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_SYS_SIGLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dir.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_DL_H */
end_comment

begin_comment
comment|/* Define if dup3 function is supported */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP3
value|1
end_define

begin_comment
comment|/* Define if EGD is supported */
end_comment

begin_comment
comment|/* #undef HAVE_EGD */
end_comment

begin_comment
comment|/* Define if the epoll interface is supported */
end_comment

begin_comment
comment|/* #undef HAVE_EPOLL */
end_comment

begin_comment
comment|/* Define if epoll_create1 function is supported */
end_comment

begin_comment
comment|/* #undef HAVE_EPOLL_CREATE1 */
end_comment

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fdatasync' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FDATASYNC */
end_comment

begin_comment
comment|/* Define to 1 if you have the `flock' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define if F_SETLK is defined in fcntl.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_F_SETLK
value|1
end_define

begin_comment
comment|/* Define if getaddrinfo accepts the AI_ADDRCONFIG flag */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAI_ADDRCONFIG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gai_strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GAI_STRERROR
value|1
end_define

begin_comment
comment|/* Define if getaddrinfo exists and works well enough for APR */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETADDRINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getgrgid_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGRGID_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getgrnam_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGRNAM_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyaddr_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYADDR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gethostbyname_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTBYNAME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getifaddrs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_comment
comment|/* Define if getnameinfo exists */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETNAMEINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpass' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPASS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpassphrase' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPASSPHRASE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getpwnam_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPWNAM_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpwuid_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPWUID_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getservbyname_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETSERVBYNAME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `gmtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GMTIME_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<grp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GRP_H
value|1
end_define

begin_comment
comment|/* Define if hstrerror is present */
end_comment

begin_comment
comment|/* #undef HAVE_HSTRERROR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `isinf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISINF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isnan' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISNAN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<kernel/OS.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_KERNEL_OS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `kqueue' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KQUEUE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<langinfo.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `bsd' library (-lbsd). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBBSD */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sendfile' library (-lsendfile). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSENDFILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `truerand' library (-ltruerand). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBTRUERAND */
end_comment

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `localtime_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALTIME_R
value|1
end_define

begin_comment
comment|/* Define if LOCK_EX is defined in sys/file.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCK_EX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<mach-o/dyld.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_O_DYLD_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if MAP_ANON is defined in sys/mman.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_MAP_ANON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkstemp64' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MKSTEMP64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `mmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mmap64' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MMAP64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `munmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/sctp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_SCTP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/sctp_uio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_SCTP_UIO_H
value|1
end_define

begin_comment
comment|/* Defined if netinet/tcp.h is present */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_TCP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<net/errno.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_ERRNO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `nl_langinfo' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_LANGINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<os2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_OS2_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<osreldate.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OSRELDATE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<OS.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_OS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `poll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
value|1
end_define

begin_comment
comment|/* Define if POLLIN is defined */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLLIN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `port_create' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PORT_CREATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<process.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PROCESS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pthread_attr_setguardsize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_ATTR_SETGUARDSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_key_delete' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_KEY_DELETE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_mutexattr_setpshared' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_MUTEXATTR_SETPSHARED
value|1
end_define

begin_comment
comment|/* Define if recursive pthread mutexes are available */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_MUTEX_RECURSIVE
value|1
end_define

begin_comment
comment|/* Define if cross-process robust mutexes are available */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_MUTEX_ROBUST */
end_comment

begin_comment
comment|/* Define if PTHREAD_PROCESS_SHARED is defined in pthread.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_PROCESS_SHARED
value|1
end_define

begin_comment
comment|/* Define if pthread rwlocks are available */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_RWLOCKS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_rwlock_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_RWLOCK_INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_yield' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_YIELD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `putenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pwd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readdir64_r' function. */
end_comment

begin_comment
comment|/* #undef HAVE_READDIR64_R */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sched.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SCHED_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sched_yield' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SCHED_YIELD */
end_comment

begin_comment
comment|/* Define to 1 if you have the<semaphore.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEMAPHORE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `semctl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEMCTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `semget' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEMGET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sem_close' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_CLOSE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sem_post' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_POST
value|1
end_define

begin_comment
comment|/* Define if SEM_UNDO is defined in sys/sem.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_UNDO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sem_unlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_UNLINK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sem_wait' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_WAIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sendfile' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SENDFILE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sendfile64' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SENDFILE64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sendfilev' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SENDFILEV */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sendfilev64' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SENDFILEV64 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `send_file' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SEND_FILE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setsid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `set_h_errno' function. */
end_comment

begin_comment
comment|/* #undef HAVE_SET_H_ERRNO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `shmat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHMAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shmctl' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHMCTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shmdt' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHMDT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shmget' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHMGET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shm_open' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHM_OPEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `shm_unlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHM_UNLINK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigaction' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigsuspend' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSUSPEND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigwait' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGWAIT
value|1
end_define

begin_comment
comment|/* Whether you have socklen_t */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKLEN_T
value|1
end_define

begin_comment
comment|/* Define if the SOCK_CLOEXEC flag is supported */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCK_CLOEXEC
value|1
end_define

begin_comment
comment|/* Define if SO_ACCEPTFILTER is defined in sys/socket.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_SO_ACCEPTFILTER
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdarg.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `stricmp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRICMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strnicmp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STRNICMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define if struct impreq was found */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_IPMREQ
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_atimensec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_ATIMENSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_atime_n' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_ATIME_N */
end_comment

begin_comment
comment|/* Define to 1 if `st_atim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_blocks' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_BLOCKS
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_ctimensec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_CTIMENSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_ctime_n' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_CTIME_N */
end_comment

begin_comment
comment|/* Define to 1 if `st_ctim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_CTIM_TV_NSEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `st_mtimensec' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIMENSEC */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtime_n' is a member of `struct stat'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_STAT_ST_MTIME_N */
end_comment

begin_comment
comment|/* Define to 1 if `st_mtim.tv_nsec' is a member of `struct stat'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
value|1
end_define

begin_comment
comment|/* Define to 1 if `tm_gmtoff' is a member of `struct tm'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TM_TM_GMTOFF
value|1
end_define

begin_comment
comment|/* Define to 1 if `__tm_gmtoff' is a member of `struct tm'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_TM___TM_GMTOFF */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sysapi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYSAPI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sysgtime.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYSGTIME_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/file.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ipc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IPC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mutex.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MUTEX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/resource.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sem.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SEM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sendfile.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SENDFILE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/shm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SHM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sockio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/syslimits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSLIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/uio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/uuid.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_UUID_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if TCP_CORK is defined in netinet/tcp.h */
end_comment

begin_comment
comment|/* #undef HAVE_TCP_CORK */
end_comment

begin_comment
comment|/* Define if TCP_NODELAY and TCP_CORK can be enabled at the same time */
end_comment

begin_comment
comment|/* #undef HAVE_TCP_NODELAY_WITH_CORK */
end_comment

begin_comment
comment|/* Define if TCP_NOPUSH is defined in netinet/tcp.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCP_NOPUSH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<tpfeq.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TPFEQ_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<tpfio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TPFIO_H */
end_comment

begin_comment
comment|/* Define if truerand is supported */
end_comment

begin_comment
comment|/* #undef HAVE_TRUERAND */
end_comment

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unix.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UNIX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `unsetenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `utimes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `uuid_create' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UUID_CREATE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `uuid_generate' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UUID_GENERATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<uuid.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UUID_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<uuid/uuid.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UUID_UUID_H */
end_comment

begin_comment
comment|/* Define if C compiler supports VLA */
end_comment

begin_define
define|#
directive|define
name|HAVE_VLA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `waitpid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<windows.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WINDOWS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<winsock2.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_WINSOCK2_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `writev' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WRITEV
value|1
end_define

begin_comment
comment|/* Define for z/OS pthread API nuances */
end_comment

begin_comment
comment|/* #undef HAVE_ZOS_PTHREADS */
end_comment

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Define if EAI_ error codes from getaddrinfo are negative */
end_comment

begin_comment
comment|/* #undef NEGATIVE_EAI */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|""
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|""
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|""
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|""
end_define

begin_comment
comment|/* Define if POSIX semaphores affect threads within the process */
end_comment

begin_comment
comment|/* #undef POSIXSEM_IS_GLOBAL */
end_comment

begin_comment
comment|/* Define on PowerPC 405 where errata 77 applies */
end_comment

begin_comment
comment|/* #undef PPC405_ERRATA */
end_comment

begin_comment
comment|/* Define if pthread_attr_getdetachstate() has one arg */
end_comment

begin_comment
comment|/* #undef PTHREAD_ATTR_GETDETACHSTATE_TAKES_ONE_ARG */
end_comment

begin_comment
comment|/* Define if pthread_getspecific() has two args */
end_comment

begin_comment
comment|/* #undef PTHREAD_GETSPECIFIC_TAKES_TWO_ARGS */
end_comment

begin_comment
comment|/* Define if readdir is thread safe */
end_comment

begin_comment
comment|/* #undef READDIR_IS_THREAD_SAFE */
end_comment

begin_comment
comment|/* Define to 1 if the `setpgrp' function takes no argument. */
end_comment

begin_comment
comment|/* #undef SETPGRP_VOID */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef SIGWAIT_TAKES_ONE_ARG */
end_comment

begin_comment
comment|/* The size of `char', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_CHAR
value|1
end_define

begin_comment
comment|/* The size of ino_t */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INO_T
value|4
end_define

begin_comment
comment|/* The size of `int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The size of `long', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_comment
comment|/* The size of `long long', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
end_define

begin_comment
comment|/* The size of off_t */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_OFF_T
value|8
end_define

begin_comment
comment|/* The size of pid_t */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_PID_T
value|4
end_define

begin_comment
comment|/* The size of `short', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_comment
comment|/* The size of size_t */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
value|8
end_define

begin_comment
comment|/* The size of ssize_t */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SSIZE_T
value|8
end_define

begin_comment
comment|/* The size of struct iovec */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_IOVEC
value|16
end_define

begin_comment
comment|/* The size of `void*', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_VOIDP
value|8
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at runtime. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if strerror returns int */
end_comment

begin_define
define|#
directive|define
name|STRERROR_R_RC_INT
value|1
end_define

begin_comment
comment|/* Define if SysV semaphores affect threads within the process */
end_comment

begin_comment
comment|/* #undef SYSVSEM_IS_GLOBAL */
end_comment

begin_comment
comment|/* Define if use of generic atomics is requested */
end_comment

begin_comment
comment|/* #undef USE_ATOMICS_GENERIC */
end_comment

begin_comment
comment|/* Define if BeOS Semaphores will be used */
end_comment

begin_comment
comment|/* #undef USE_BEOSSEM */
end_comment

begin_comment
comment|/* Define if SVR4-style fcntl() will be used */
end_comment

begin_comment
comment|/* #undef USE_FCNTL_SERIALIZE */
end_comment

begin_comment
comment|/* Define if 4.2BSD-style flock() will be used */
end_comment

begin_define
define|#
directive|define
name|USE_FLOCK_SERIALIZE
value|1
end_define

begin_comment
comment|/* Define if BeOS areas will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_BEOS */
end_comment

begin_comment
comment|/* Define if BeOS areas will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_BEOS_ANON */
end_comment

begin_comment
comment|/* Define if 4.4BSD-style mmap() via MAP_ANON will be used */
end_comment

begin_define
define|#
directive|define
name|USE_SHMEM_MMAP_ANON
value|1
end_define

begin_comment
comment|/* Define if mmap() via POSIX.1 shm_open() on temporary file will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_MMAP_SHM */
end_comment

begin_comment
comment|/* Define if Classical mmap() on temporary file will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_MMAP_TMP */
end_comment

begin_comment
comment|/* Define if SVR4-style mmap() on /dev/zero will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_MMAP_ZERO */
end_comment

begin_comment
comment|/* Define if OS/2 DosAllocSharedMem() will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_OS2 */
end_comment

begin_comment
comment|/* Define if OS/2 DosAllocSharedMem() will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_OS2_ANON */
end_comment

begin_comment
comment|/* Define if SysV IPC shmget() will be used */
end_comment

begin_define
define|#
directive|define
name|USE_SHMEM_SHMGET
value|1
end_define

begin_comment
comment|/* Define if SysV IPC shmget() will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_SHMGET_ANON */
end_comment

begin_comment
comment|/* Define if Windows shared memory will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_WIN32 */
end_comment

begin_comment
comment|/* Define if Windows CreateFileMapping() will be used */
end_comment

begin_comment
comment|/* #undef USE_SHMEM_WIN32_ANON */
end_comment

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if SysV IPC semget() will be used */
end_comment

begin_comment
comment|/* #undef USE_SYSVSEM_SERIALIZE */
end_comment

begin_comment
comment|/* Define if apr_wait_for_io_or_timeout() uses poll(2) */
end_comment

begin_define
define|#
directive|define
name|WAITIO_USES_POLL
value|1
end_define

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
name|AC_APPLE_UNIVERSAL_BUILD
end_if

begin_if
if|#
directive|if
name|defined
name|__BIG_ENDIAN__
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|WORDS_BIGENDIAN
end_ifndef

begin_comment
comment|/* #  undef WORDS_BIGENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* switch this on if we have a BeOS version below BONE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BEOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BONE_VERSION
argument_list|)
end_if

begin_define
define|#
directive|define
name|BEOS_R5
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BEOS_BONE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Darwin 10's default compiler (gcc42) builds for both 64 and  * 32 bit architectures unless specifically told not to.  * In those cases, we need to override types depending on how  * we're being built at compile time.  * NOTE: This is an ugly work-around for Darwin's  * concept of universal binaries, a single package  * (executable, lib, etc...) which contains both 32  * and 64 bit versions. The issue is that if APR is  * built universally, if something else is compiled  * against it, some bit sizes will depend on whether  * it is 32 or 64 bit. This is determined by the __LP64__  * flag. Since we need to support both, we have to  * handle OS X unqiuely.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DARWIN_10
end_ifdef

begin_define
define|#
directive|define
name|APR_OFF_T_STRFN
value|strtol
end_define

begin_define
define|#
directive|define
name|APR_INT64_STRFN
value|strtol
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SSIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_VOIDP
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_IOVEC
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|APR_INT64_STRFN
value|strtol
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SSIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_VOIDP
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_IOVEC
value|16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APR_INT64_STRFN
value|strtol
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_SSIZE_T
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_VOIDP
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_STRUCT_IOVEC
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|APR_OFF_T_STRFN
value|strtol
end_define

begin_define
define|#
directive|define
name|APR_OFF_T_STRFN
value|strtol
end_define

begin_comment
comment|/* #undef SETPGRP_VOID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DARWIN_UNIX03
end_ifdef

begin_define
define|#
directive|define
name|SETPGRP_VOID
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* #undef SETPGRP_VOID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DARWIN_10 */
end_comment

begin_comment
comment|/*  * Include common private declarations.  */
end_comment

begin_include
include|#
directive|include
file|"../apr_private_common.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_PRIVATE_H */
end_comment

end_unit

