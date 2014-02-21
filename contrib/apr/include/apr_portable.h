begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* This header file is where you should put ANY platform specific information.  * This should be the only header file that programs need to include that   * actually has platform dependent code which refers to the .  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_PORTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_PORTABLE_H
end_define

begin_comment
comment|/**  * @file apr_portable.h  * @brief APR Portability Routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_proc.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_global_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_proc_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_time.h"
end_include

begin_include
include|#
directive|include
file|"apr_dso.h"
end_include

begin_include
include|#
directive|include
file|"apr_shm.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_DIRENT_H
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_PTHREAD_H
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/**  * @defgroup apr_portabile Portability Routines  * @ingroup APR   * @{  */
ifdef|#
directive|ifdef
name|WIN32
comment|/* The primitives for Windows types */
typedef|typedef
name|HANDLE
name|apr_os_file_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_dir_t
typedef|;
typedef|typedef
name|SOCKET
name|apr_os_sock_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_proc_mutex_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_thread_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_proc_t
typedef|;
typedef|typedef
name|DWORD
name|apr_os_threadkey_t
typedef|;
typedef|typedef
name|FILETIME
name|apr_os_imp_time_t
typedef|;
typedef|typedef
name|SYSTEMTIME
name|apr_os_exp_time_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_dso_handle_t
typedef|;
typedef|typedef
name|HANDLE
name|apr_os_shm_t
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|OS2
argument_list|)
typedef|typedef
name|HFILE
name|apr_os_file_t
typedef|;
typedef|typedef
name|HDIR
name|apr_os_dir_t
typedef|;
typedef|typedef
name|int
name|apr_os_sock_t
typedef|;
typedef|typedef
name|HMTX
name|apr_os_proc_mutex_t
typedef|;
typedef|typedef
name|TID
name|apr_os_thread_t
typedef|;
typedef|typedef
name|PID
name|apr_os_proc_t
typedef|;
typedef|typedef
name|PULONG
name|apr_os_threadkey_t
typedef|;
typedef|typedef
name|struct
name|timeval
name|apr_os_imp_time_t
typedef|;
typedef|typedef
name|struct
name|tm
name|apr_os_exp_time_t
typedef|;
typedef|typedef
name|HMODULE
name|apr_os_dso_handle_t
typedef|;
typedef|typedef
name|void
modifier|*
name|apr_os_shm_t
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|__BEOS__
argument_list|)
include|#
directive|include
file|<kernel/OS.h>
include|#
directive|include
file|<kernel/image.h>
struct|struct
name|apr_os_proc_mutex_t
block|{
name|sem_id
name|sem
decl_stmt|;
name|int32
name|ben
decl_stmt|;
block|}
struct|;
typedef|typedef
name|int
name|apr_os_file_t
typedef|;
typedef|typedef
name|DIR
name|apr_os_dir_t
typedef|;
typedef|typedef
name|int
name|apr_os_sock_t
typedef|;
typedef|typedef
name|struct
name|apr_os_proc_mutex_t
name|apr_os_proc_mutex_t
typedef|;
typedef|typedef
name|thread_id
name|apr_os_thread_t
typedef|;
typedef|typedef
name|thread_id
name|apr_os_proc_t
typedef|;
typedef|typedef
name|int
name|apr_os_threadkey_t
typedef|;
typedef|typedef
name|struct
name|timeval
name|apr_os_imp_time_t
typedef|;
typedef|typedef
name|struct
name|tm
name|apr_os_exp_time_t
typedef|;
typedef|typedef
name|image_id
name|apr_os_dso_handle_t
typedef|;
typedef|typedef
name|void
modifier|*
name|apr_os_shm_t
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|NETWARE
argument_list|)
typedef|typedef
name|int
name|apr_os_file_t
typedef|;
typedef|typedef
name|DIR
name|apr_os_dir_t
typedef|;
typedef|typedef
name|int
name|apr_os_sock_t
typedef|;
typedef|typedef
name|NXMutex_t
name|apr_os_proc_mutex_t
typedef|;
typedef|typedef
name|NXThreadId_t
name|apr_os_thread_t
typedef|;
typedef|typedef
name|long
name|apr_os_proc_t
typedef|;
typedef|typedef
name|NXKey_t
name|apr_os_threadkey_t
typedef|;
typedef|typedef
name|struct
name|timeval
name|apr_os_imp_time_t
typedef|;
typedef|typedef
name|struct
name|tm
name|apr_os_exp_time_t
typedef|;
typedef|typedef
name|void
modifier|*
name|apr_os_dso_handle_t
typedef|;
typedef|typedef
name|void
modifier|*
name|apr_os_shm_t
typedef|;
else|#
directive|else
comment|/* Any other OS should go above this one.  This is the lowest common  * denominator typedefs for  all UNIX-like systems.  :)  */
comment|/** Basic OS process mutex structure. */
struct|struct
name|apr_os_proc_mutex_t
block|{
if|#
directive|if
name|APR_HAS_SYSVSEM_SERIALIZE
operator|||
name|APR_HAS_FCNTL_SERIALIZE
operator|||
name|APR_HAS_FLOCK_SERIALIZE
comment|/** Value used for SYS V Semaphore, FCNTL and FLOCK serialization */
name|int
name|crossproc
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAS_PROC_PTHREAD_SERIALIZE
comment|/** Value used for PTHREAD serialization */
name|pthread_mutex_t
modifier|*
name|pthread_interproc
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAS_THREADS
comment|/* If no threads, no need for thread locks */
if|#
directive|if
name|APR_USE_PTHREAD_SERIALIZE
comment|/** This value is currently unused within APR and Apache */
name|pthread_mutex_t
modifier|*
name|intraproc
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
struct|;
typedef|typedef
name|int
name|apr_os_file_t
typedef|;
comment|/**< native file */
typedef|typedef
name|DIR
name|apr_os_dir_t
typedef|;
comment|/**< native dir */
typedef|typedef
name|int
name|apr_os_sock_t
typedef|;
comment|/**< native dir */
typedef|typedef
name|struct
name|apr_os_proc_mutex_t
name|apr_os_proc_mutex_t
typedef|;
comment|/**< native process                                                           *   mutex                                                           */
if|#
directive|if
name|APR_HAS_THREADS
operator|&&
name|APR_HAVE_PTHREAD_H
typedef|typedef
name|pthread_t
name|apr_os_thread_t
typedef|;
comment|/**< native thread */
typedef|typedef
name|pthread_key_t
name|apr_os_threadkey_t
typedef|;
comment|/**< native thread address                                                      *   space */
endif|#
directive|endif
typedef|typedef
name|pid_t
name|apr_os_proc_t
typedef|;
comment|/**< native pid */
typedef|typedef
name|struct
name|timeval
name|apr_os_imp_time_t
typedef|;
comment|/**< native timeval */
typedef|typedef
name|struct
name|tm
name|apr_os_exp_time_t
typedef|;
comment|/**< native tm */
comment|/** @var apr_os_dso_handle_t  * native dso types  */
if|#
directive|if
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|||
name|defined
argument_list|(
name|HPUX10
argument_list|)
operator|||
name|defined
argument_list|(
name|HPUX11
argument_list|)
include|#
directive|include
file|<dl.h>
typedef|typedef
name|shl_t
name|apr_os_dso_handle_t
typedef|;
elif|#
directive|elif
name|defined
argument_list|(
name|DARWIN
argument_list|)
include|#
directive|include
file|<mach-o/dyld.h>
typedef|typedef
name|NSModule
name|apr_os_dso_handle_t
typedef|;
else|#
directive|else
typedef|typedef
name|void
modifier|*
name|apr_os_dso_handle_t
typedef|;
endif|#
directive|endif
typedef|typedef
name|void
modifier|*
name|apr_os_shm_t
typedef|;
comment|/**< native SHM */
endif|#
directive|endif
comment|/**  * @typedef apr_os_sock_info_t  * @brief alias for local OS socket  */
comment|/**  * everything APR needs to know about an active socket to construct  * an APR socket from it; currently, this is platform-independent  */
struct|struct
name|apr_os_sock_info_t
block|{
name|apr_os_sock_t
modifier|*
name|os_sock
decl_stmt|;
comment|/**< always required */
name|struct
name|sockaddr
modifier|*
name|local
decl_stmt|;
comment|/**< NULL if not yet bound */
name|struct
name|sockaddr
modifier|*
name|remote
decl_stmt|;
comment|/**< NULL if not connected */
name|int
name|family
decl_stmt|;
comment|/**< always required (APR_INET, APR_INET6, etc.) */
name|int
name|type
decl_stmt|;
comment|/**< always required (SOCK_STREAM, SOCK_DGRAM, etc.) */
name|int
name|protocol
decl_stmt|;
comment|/**< 0 or actual protocol (APR_PROTO_SCTP, APR_PROTO_TCP, etc.) */
block|}
struct|;
typedef|typedef
name|struct
name|apr_os_sock_info_t
name|apr_os_sock_info_t
typedef|;
if|#
directive|if
name|APR_PROC_MUTEX_IS_GLOBAL
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/** Opaque global mutex type */
define|#
directive|define
name|apr_os_global_mutex_t
value|apr_os_proc_mutex_t
comment|/** @return apr_os_global_mutex */
define|#
directive|define
name|apr_os_global_mutex_get
value|apr_os_proc_mutex_get
else|#
directive|else
comment|/** Thread and process mutex for those platforms where process mutexes      *  are not held in threads.      */
struct|struct
name|apr_os_global_mutex_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_proc_mutex_t
modifier|*
name|proc_mutex
decl_stmt|;
if|#
directive|if
name|APR_HAS_THREADS
name|apr_thread_mutex_t
modifier|*
name|thread_mutex
decl_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_THREADS */
block|}
struct|;
typedef|typedef
name|struct
name|apr_os_global_mutex_t
name|apr_os_global_mutex_t
typedef|;
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_global_mutex_get
argument_list|(
name|apr_os_global_mutex_t
operator|*
name|ospmutex
argument_list|,
name|apr_global_mutex_t
operator|*
name|pmutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/**  * convert the file from apr type to os specific type.  * @param thefile The os specific file we are converting to  * @param file The apr file to convert.  * @remark On Unix, it is only possible to get a file descriptor from   *         an apr file type.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_file_get
argument_list|(
name|apr_os_file_t
operator|*
name|thefile
argument_list|,
name|apr_file_t
operator|*
name|file
argument_list|)
expr_stmt|;
comment|/**  * convert the dir from apr type to os specific type.  * @param thedir The os specific dir we are converting to  * @param dir The apr dir to convert.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_dir_get
argument_list|(
name|apr_os_dir_t
operator|*
operator|*
name|thedir
argument_list|,
name|apr_dir_t
operator|*
name|dir
argument_list|)
expr_stmt|;
comment|/**  * Convert the socket from an apr type to an OS specific socket  * @param thesock The socket to convert.  * @param sock The os specific equivalent of the apr socket..  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_sock_get
argument_list|(
name|apr_os_sock_t
operator|*
name|thesock
argument_list|,
name|apr_socket_t
operator|*
name|sock
argument_list|)
expr_stmt|;
comment|/**  * Convert the proc mutex from os specific type to apr type  * @param ospmutex The os specific proc mutex we are converting to.  * @param pmutex The apr proc mutex to convert.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_proc_mutex_get
argument_list|(
name|apr_os_proc_mutex_t
operator|*
name|ospmutex
argument_list|,
name|apr_proc_mutex_t
operator|*
name|pmutex
argument_list|)
expr_stmt|;
comment|/**  * Get the exploded time in the platforms native format.  * @param ostime the native time format  * @param aprtime the time to convert  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_exp_time_get
argument_list|(
name|apr_os_exp_time_t
operator|*
operator|*
name|ostime
argument_list|,
name|apr_time_exp_t
operator|*
name|aprtime
argument_list|)
expr_stmt|;
comment|/**  * Get the imploded time in the platforms native format.  * @param ostime  the native time format  * @param aprtime the time to convert  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_imp_time_get
argument_list|(
name|apr_os_imp_time_t
operator|*
operator|*
name|ostime
argument_list|,
name|apr_time_t
operator|*
name|aprtime
argument_list|)
expr_stmt|;
comment|/**  * convert the shm from apr type to os specific type.  * @param osshm The os specific shm representation  * @param shm The apr shm to convert.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_shm_get
argument_list|(
name|apr_os_shm_t
operator|*
name|osshm
argument_list|,
name|apr_shm_t
operator|*
name|shm
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_THREADS
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**   * @defgroup apr_os_thread Thread portability Routines  * @{   */
comment|/**  * convert the thread to os specific type from apr type.  * @param thethd The apr thread to convert  * @param thd The os specific thread we are converting to  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_thread_get
argument_list|(
name|apr_os_thread_t
operator|*
operator|*
name|thethd
argument_list|,
name|apr_thread_t
operator|*
name|thd
argument_list|)
expr_stmt|;
comment|/**  * convert the thread private memory key to os specific type from an apr type.  * @param thekey The apr handle we are converting from.  * @param key The os specific handle we are converting to.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_threadkey_get
argument_list|(
name|apr_os_threadkey_t
operator|*
name|thekey
argument_list|,
name|apr_threadkey_t
operator|*
name|key
argument_list|)
expr_stmt|;
comment|/**  * convert the thread from os specific type to apr type.  * @param thd The apr thread we are converting to.  * @param thethd The os specific thread to convert  * @param cont The pool to use if it is needed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_thread_put
argument_list|(
name|apr_thread_t
operator|*
operator|*
name|thd
argument_list|,
name|apr_os_thread_t
operator|*
name|thethd
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * convert the thread private memory key from os specific type to apr type.  * @param key The apr handle we are converting to.  * @param thekey The os specific handle to convert  * @param cont The pool to use if it is needed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_threadkey_put
argument_list|(
name|apr_threadkey_t
operator|*
operator|*
name|key
argument_list|,
name|apr_os_threadkey_t
operator|*
name|thekey
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Get the thread ID  */
name|APR_DECLARE
argument_list|(
argument|apr_os_thread_t
argument_list|)
name|apr_os_thread_current
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Compare two thread id's  * @param tid1 1st Thread ID to compare  * @param tid2 2nd Thread ID to compare  * @return non-zero if the two threads are equal, zero otherwise  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_os_thread_equal
argument_list|(
argument|apr_os_thread_t tid1
argument_list|,
argument|apr_os_thread_t tid2
argument_list|)
empty_stmt|;
comment|/** @} */
endif|#
directive|endif
comment|/* APR_HAS_THREADS */
comment|/**  * convert the file from os specific type to apr type.  * @param file The apr file we are converting to.  * @param thefile The os specific file to convert  * @param flags The flags that were used to open this file.  * @param cont The pool to use if it is needed.  * @remark On Unix, it is only possible to put a file descriptor into  *         an apr file type.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_file_put
argument_list|(
argument|apr_file_t **file
argument_list|,
argument|apr_os_file_t *thefile
argument_list|,
argument|apr_int32_t flags
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * convert the file from os specific type to apr type.  * @param file The apr file we are converting to.  * @param thefile The os specific pipe to convert  * @param cont The pool to use if it is needed.  * @remark On Unix, it is only possible to put a file descriptor into  *         an apr file type.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_pipe_put
argument_list|(
name|apr_file_t
operator|*
operator|*
name|file
argument_list|,
name|apr_os_file_t
operator|*
name|thefile
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * convert the file from os specific type to apr type.  * @param file The apr file we are converting to.  * @param thefile The os specific pipe to convert  * @param register_cleanup A cleanup will be registered on the apr_file_t  *   to issue apr_file_close().  * @param cont The pool to use if it is needed.  * @remark On Unix, it is only possible to put a file descriptor into  *         an apr file type.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_pipe_put_ex
argument_list|(
argument|apr_file_t **file
argument_list|,
argument|apr_os_file_t *thefile
argument_list|,
argument|int register_cleanup
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * convert the dir from os specific type to apr type.  * @param dir The apr dir we are converting to.  * @param thedir The os specific dir to convert  * @param cont The pool to use when creating to apr directory.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_dir_put
argument_list|(
name|apr_dir_t
operator|*
operator|*
name|dir
argument_list|,
name|apr_os_dir_t
operator|*
name|thedir
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Convert a socket from the os specific type to the apr type  * @param sock The pool to use.  * @param thesock The socket to convert to.  * @param cont The socket we are converting to an apr type.  * @remark If it is a true socket, it is best to call apr_os_sock_make()  *         and provide APR with more information about the socket.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_sock_put
argument_list|(
name|apr_socket_t
operator|*
operator|*
name|sock
argument_list|,
name|apr_os_sock_t
operator|*
name|thesock
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Create a socket from an existing descriptor and local and remote  * socket addresses.  * @param apr_sock The new socket that has been set up  * @param os_sock_info The os representation of the socket handle and  *        other characteristics of the socket  * @param cont The pool to use  * @remark If you only know the descriptor/handle or if it isn't really  *         a true socket, use apr_os_sock_put() instead.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_sock_make
argument_list|(
name|apr_socket_t
operator|*
operator|*
name|apr_sock
argument_list|,
name|apr_os_sock_info_t
operator|*
name|os_sock_info
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Convert the proc mutex from os specific type to apr type  * @param pmutex The apr proc mutex we are converting to.  * @param ospmutex The os specific proc mutex to convert.  * @param cont The pool to use if it is needed.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_proc_mutex_put
argument_list|(
name|apr_proc_mutex_t
operator|*
operator|*
name|pmutex
argument_list|,
name|apr_os_proc_mutex_t
operator|*
name|ospmutex
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Put the imploded time in the APR format.  * @param aprtime the APR time format  * @param ostime the time to convert  * @param cont the pool to use if necessary  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_imp_time_put
argument_list|(
name|apr_time_t
operator|*
name|aprtime
argument_list|,
name|apr_os_imp_time_t
operator|*
operator|*
name|ostime
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Put the exploded time in the APR format.  * @param aprtime the APR time format  * @param ostime the time to convert  * @param cont the pool to use if necessary  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_exp_time_put
argument_list|(
name|apr_time_exp_t
operator|*
name|aprtime
argument_list|,
name|apr_os_exp_time_t
operator|*
operator|*
name|ostime
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * convert the shared memory from os specific type to apr type.  * @param shm The apr shm representation of osshm  * @param osshm The os specific shm identity  * @param cont The pool to use if it is needed.  * @remark On fork()ed architectures, this is typically nothing more than  * the memory block mapped.  On non-fork architectures, this is typically  * some internal handle to pass the mapping from process to process.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_shm_put
argument_list|(
name|apr_shm_t
operator|*
operator|*
name|shm
argument_list|,
name|apr_os_shm_t
operator|*
name|osshm
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_DSO
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**   * @defgroup apr_os_dso DSO (Dynamic Loading) Portability Routines  * @{  */
comment|/**  * convert the dso handle from os specific to apr  * @param dso The apr handle we are converting to  * @param thedso the os specific handle to convert  * @param pool the pool to use if it is needed  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_dso_handle_put
argument_list|(
argument|apr_dso_handle_t **dso
argument_list|,
argument|apr_os_dso_handle_t thedso
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * convert the apr dso handle into an os specific one  * @param aprdso The apr dso handle to convert  * @param dso The os specific dso to return  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_dso_handle_get
argument_list|(
name|apr_os_dso_handle_t
operator|*
name|dso
argument_list|,
name|apr_dso_handle_t
operator|*
name|aprdso
argument_list|)
expr_stmt|;
comment|/** @} */
endif|#
directive|endif
comment|/* APR_HAS_DSO */
if|#
directive|if
name|APR_HAS_OS_UUID
comment|/**  * Private: apr-util's apr_uuid module when supported by the platform  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_os_uuid_get
argument_list|(
argument|unsigned char *uuid_data
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/**  * Get the name of the system default character set.  * @param pool the pool to allocate the name from, if needed  */
name|APR_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_os_default_encoding
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Get the name of the current locale character set.  * @param pool the pool to allocate the name from, if needed  * @remark Defers to apr_os_default_encoding if the current locale's  * data can't be retrieved on this system.  */
name|APR_DECLARE
argument_list|(
argument|const char*
argument_list|)
name|apr_os_locale_encoding
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_PORTABLE_H */
end_comment

end_unit

