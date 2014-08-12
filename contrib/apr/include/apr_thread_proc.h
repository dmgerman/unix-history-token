begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_THREAD_PROC_H
end_ifndef

begin_define
define|#
directive|define
name|APR_THREAD_PROC_H
end_define

begin_comment
comment|/**  * @file apr_thread_proc.h  * @brief APR Thread and Process Library  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_STRUCT_RLIMIT
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
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
comment|/**  * @defgroup apr_thread_proc Threads and Process Functions  * @ingroup APR   * @{  */
typedef|typedef
enum|enum
block|{
name|APR_SHELLCMD
block|,
comment|/**< use the shell to invoke the program */
name|APR_PROGRAM
block|,
comment|/**< invoke the program directly, no copied env */
name|APR_PROGRAM_ENV
block|,
comment|/**< invoke the program, replicating our environment */
name|APR_PROGRAM_PATH
block|,
comment|/**< find program on PATH, use our environment */
name|APR_SHELLCMD_ENV
comment|/**< use the shell to invoke the program,                              *   replicating our environment                              */
block|}
name|apr_cmdtype_e
typedef|;
typedef|typedef
enum|enum
block|{
name|APR_WAIT
block|,
comment|/**< wait for the specified process to finish */
name|APR_NOWAIT
comment|/**< do not wait -- just see if it has finished */
block|}
name|apr_wait_how_e
typedef|;
comment|/* I am specifically calling out the values so that the macros below make  * more sense.  Yes, I know I don't need to, but I am hoping this makes what  * I am doing more clear.  If you want to add more reasons to exit, continue  * to use bitmasks.  */
typedef|typedef
enum|enum
block|{
name|APR_PROC_EXIT
init|=
literal|1
block|,
comment|/**< process exited normally */
name|APR_PROC_SIGNAL
init|=
literal|2
block|,
comment|/**< process exited due to a signal */
name|APR_PROC_SIGNAL_CORE
init|=
literal|4
comment|/**< process exited and dumped a core file */
block|}
name|apr_exit_why_e
typedef|;
comment|/** did we exit the process */
define|#
directive|define
name|APR_PROC_CHECK_EXIT
parameter_list|(
name|x
parameter_list|)
value|(x& APR_PROC_EXIT)
comment|/** did we get a signal */
define|#
directive|define
name|APR_PROC_CHECK_SIGNALED
parameter_list|(
name|x
parameter_list|)
value|(x& APR_PROC_SIGNAL)
comment|/** did we get core */
define|#
directive|define
name|APR_PROC_CHECK_CORE_DUMP
parameter_list|(
name|x
parameter_list|)
value|(x& APR_PROC_SIGNAL_CORE)
comment|/** @see apr_procattr_io_set */
define|#
directive|define
name|APR_NO_PIPE
value|0
comment|/** @see apr_procattr_io_set and apr_file_pipe_create_ex */
define|#
directive|define
name|APR_FULL_BLOCK
value|1
comment|/** @see apr_procattr_io_set and apr_file_pipe_create_ex */
define|#
directive|define
name|APR_FULL_NONBLOCK
value|2
comment|/** @see apr_procattr_io_set */
define|#
directive|define
name|APR_PARENT_BLOCK
value|3
comment|/** @see apr_procattr_io_set */
define|#
directive|define
name|APR_CHILD_BLOCK
value|4
comment|/** @see apr_procattr_io_set */
define|#
directive|define
name|APR_NO_FILE
value|8
comment|/** @see apr_file_pipe_create_ex */
define|#
directive|define
name|APR_READ_BLOCK
value|3
comment|/** @see apr_file_pipe_create_ex */
define|#
directive|define
name|APR_WRITE_BLOCK
value|4
comment|/** @see apr_procattr_io_set   * @note Win32 only effective with version 1.2.12, portably introduced in 1.3.0  */
define|#
directive|define
name|APR_NO_FILE
value|8
comment|/** @see apr_procattr_limit_set */
define|#
directive|define
name|APR_LIMIT_CPU
value|0
comment|/** @see apr_procattr_limit_set */
define|#
directive|define
name|APR_LIMIT_MEM
value|1
comment|/** @see apr_procattr_limit_set */
define|#
directive|define
name|APR_LIMIT_NPROC
value|2
comment|/** @see apr_procattr_limit_set */
define|#
directive|define
name|APR_LIMIT_NOFILE
value|3
comment|/**  * @defgroup APR_OC Other Child Flags  * @{  */
define|#
directive|define
name|APR_OC_REASON_DEATH
value|0
comment|/**< child has died, caller must call                                            * unregister still */
define|#
directive|define
name|APR_OC_REASON_UNWRITABLE
value|1
comment|/**< write_fd is unwritable */
define|#
directive|define
name|APR_OC_REASON_RESTART
value|2
comment|/**< a restart is occurring, perform                                            * any necessary cleanup (including                                            * sending a special signal to child)                                            */
define|#
directive|define
name|APR_OC_REASON_UNREGISTER
value|3
comment|/**< unregister has been called, do                                            * whatever is necessary (including                                            * kill the child) */
define|#
directive|define
name|APR_OC_REASON_LOST
value|4
comment|/**< somehow the child exited without                                            * us knowing ... buggy os? */
define|#
directive|define
name|APR_OC_REASON_RUNNING
value|5
comment|/**< a health check is occurring,                                             * for most maintainence functions                                            * this is a no-op.                                            */
comment|/** @} */
comment|/** The APR process type */
typedef|typedef
struct|struct
name|apr_proc_t
block|{
comment|/** The process ID */
name|pid_t
name|pid
decl_stmt|;
comment|/** Parent's side of pipe to child's stdin */
name|apr_file_t
modifier|*
name|in
decl_stmt|;
comment|/** Parent's side of pipe to child's stdout */
name|apr_file_t
modifier|*
name|out
decl_stmt|;
comment|/** Parent's side of pipe to child's stdouterr */
name|apr_file_t
modifier|*
name|err
decl_stmt|;
if|#
directive|if
name|APR_HAS_PROC_INVOKED
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/** Diagnositics/debugging string of the command invoked for       *  this process [only present if APR_HAS_PROC_INVOKED is true]      * @remark Only enabled on Win32 by default.      * @bug This should either always or never be present in release      * builds - since it breaks binary compatibility.  We may enable      * it always in APR 1.0 yet leave it undefined in most cases.      */
name|char
modifier|*
name|invoked
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/** (Win32 only) Creator's handle granting access to the process      * @remark This handle is closed and reset to NULL in every case      * corresponding to a waitpid() on Unix which returns the exit status.      * Therefore Win32 correspond's to Unix's zombie reaping characteristics      * and avoids potential handle leaks.      */
name|HANDLE
name|hproc
decl_stmt|;
endif|#
directive|endif
block|}
name|apr_proc_t
typedef|;
comment|/**  * The prototype for APR child errfn functions.  (See the description  * of apr_procattr_child_errfn_set() for more information.)  * It is passed the following parameters:  * @param pool Pool associated with the apr_proc_t.  If your child  *             error function needs user data, associate it with this  *             pool.  * @param err APR error code describing the error  * @param description Text description of type of processing which failed  */
typedef|typedef
name|void
function_decl|(
name|apr_child_errfn_t
function_decl|)
parameter_list|(
name|apr_pool_t
modifier|*
name|proc
parameter_list|,
name|apr_status_t
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|)
function_decl|;
comment|/** Opaque Thread structure. */
typedef|typedef
name|struct
name|apr_thread_t
name|apr_thread_t
typedef|;
comment|/** Opaque Thread attributes structure. */
typedef|typedef
name|struct
name|apr_threadattr_t
name|apr_threadattr_t
typedef|;
comment|/** Opaque Process attributes structure. */
typedef|typedef
name|struct
name|apr_procattr_t
name|apr_procattr_t
typedef|;
comment|/** Opaque control variable for one-time atomic variables.  */
typedef|typedef
name|struct
name|apr_thread_once_t
name|apr_thread_once_t
typedef|;
comment|/** Opaque thread private address space. */
typedef|typedef
name|struct
name|apr_threadkey_t
name|apr_threadkey_t
typedef|;
comment|/** Opaque record of child process. */
typedef|typedef
name|struct
name|apr_other_child_rec_t
name|apr_other_child_rec_t
typedef|;
comment|/**  * The prototype for any APR thread worker functions.  */
typedef|typedef
name|void
modifier|*
function_decl|(
name|APR_THREAD_FUNC
modifier|*
name|apr_thread_start_t
function_decl|)
parameter_list|(
name|apr_thread_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
enum|enum
block|{
name|APR_KILL_NEVER
block|,
comment|/**< process is never killed (i.e., never sent                                  * any signals), but it will be reaped if it exits                                  * before the pool is cleaned up */
name|APR_KILL_ALWAYS
block|,
comment|/**< process is sent SIGKILL on apr_pool_t cleanup */
name|APR_KILL_AFTER_TIMEOUT
block|,
comment|/**< SIGTERM, wait 3 seconds, SIGKILL */
name|APR_JUST_WAIT
block|,
comment|/**< wait forever for the process to complete */
name|APR_KILL_ONLY_ONCE
comment|/**< send SIGTERM and then wait */
block|}
name|apr_kill_conditions_e
typedef|;
comment|/* Thread Function definitions */
if|#
directive|if
name|APR_HAS_THREADS
comment|/**  * Create and initialize a new threadattr variable  * @param new_attr The newly created threadattr.  * @param cont The pool to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadattr_create
argument_list|(
name|apr_threadattr_t
operator|*
operator|*
name|new_attr
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Set if newly created threads should be created in detached state.  * @param attr The threadattr to affect   * @param on Non-zero if detached threads should be created.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadattr_detach_set
argument_list|(
argument|apr_threadattr_t *attr
argument_list|,
argument|apr_int32_t on
argument_list|)
empty_stmt|;
comment|/**  * Get the detach state for this threadattr.  * @param attr The threadattr to reference  * @return APR_DETACH if threads are to be detached, or APR_NOTDETACH  * if threads are to be joinable.   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadattr_detach_get
argument_list|(
name|apr_threadattr_t
operator|*
name|attr
argument_list|)
expr_stmt|;
comment|/**  * Set the stack size of newly created threads.  * @param attr The threadattr to affect   * @param stacksize The stack size in bytes  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadattr_stacksize_set
argument_list|(
argument|apr_threadattr_t *attr
argument_list|,
argument|apr_size_t stacksize
argument_list|)
empty_stmt|;
comment|/**  * Set the stack guard area size of newly created threads.  * @param attr The threadattr to affect   * @param guardsize The stack guard area size in bytes  * @note Thread library implementations commonly use a "guard area"  * after each thread's stack which is not readable or writable such that  * stack overflows cause a segfault; this consumes e.g. 4K of memory  * and increases memory management overhead.  Setting the guard area  * size to zero hence trades off reliable behaviour on stack overflow  * for performance. */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadattr_guardsize_set
argument_list|(
argument|apr_threadattr_t *attr
argument_list|,
argument|apr_size_t guardsize
argument_list|)
empty_stmt|;
comment|/**  * Create a new thread of execution  * @param new_thread The newly created thread handle.  * @param attr The threadattr to use to determine how to create the thread  * @param func The function to start the new thread in  * @param data Any data to be passed to the starting function  * @param cont The pool to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_create
argument_list|(
argument|apr_thread_t **new_thread
argument_list|,
argument|apr_threadattr_t *attr
argument_list|,
argument|apr_thread_start_t func
argument_list|,
argument|void *data
argument_list|,
argument|apr_pool_t *cont
argument_list|)
empty_stmt|;
comment|/**  * stop the current thread  * @param thd The thread to stop  * @param retval The return value to pass back to any thread that cares  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_exit
argument_list|(
argument|apr_thread_t *thd
argument_list|,
argument|apr_status_t retval
argument_list|)
empty_stmt|;
comment|/**  * block until the desired thread stops executing.  * @param retval The return value from the dead thread.  * @param thd The thread to join  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_join
argument_list|(
name|apr_status_t
operator|*
name|retval
argument_list|,
name|apr_thread_t
operator|*
name|thd
argument_list|)
expr_stmt|;
comment|/**  * force the current thread to yield the processor  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_thread_yield
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Initialize the control variable for apr_thread_once.  If this isn't  * called, apr_initialize won't work.  * @param control The control variable to initialize  * @param p The pool to allocate data from.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_once_init
argument_list|(
name|apr_thread_once_t
operator|*
operator|*
name|control
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Run the specified function one time, regardless of how many threads  * call it.  * @param control The control variable.  The same variable should  *                be passed in each time the function is tried to be  *                called.  This is how the underlying functions determine  *                if the function has ever been called before.  * @param func The function to call.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_once
argument_list|(
name|apr_thread_once_t
operator|*
name|control
argument_list|,
name|void
argument_list|(
operator|*
name|func
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
expr_stmt|;
comment|/**  * detach a thread  * @param thd The thread to detach   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_detach
argument_list|(
name|apr_thread_t
operator|*
name|thd
argument_list|)
expr_stmt|;
comment|/**  * Return user data associated with the current thread.  * @param data The user data associated with the thread.  * @param key The key to associate with the data  * @param thread The currently open thread.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_data_get
argument_list|(
name|void
operator|*
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_thread_t
operator|*
name|thread
argument_list|)
expr_stmt|;
comment|/**  * Set user data associated with the current thread.  * @param data The user data to associate with the thread.  * @param key The key to use for associating the data with the thread  * @param cleanup The cleanup routine to use when the thread is destroyed.  * @param thread The currently open thread.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_data_set
argument_list|(
name|void
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_status_t
argument_list|(
operator|*
name|cleanup
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|apr_thread_t
operator|*
name|thread
argument_list|)
expr_stmt|;
comment|/**  * Create and initialize a new thread private address space  * @param key The thread private handle.  * @param dest The destructor to use when freeing the private memory.  * @param cont The pool to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_private_create
argument_list|(
name|apr_threadkey_t
operator|*
operator|*
name|key
argument_list|,
name|void
argument_list|(
operator|*
name|dest
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Get a pointer to the thread private memory  * @param new_mem The data stored in private memory   * @param key The handle for the desired thread private memory   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_private_get
argument_list|(
name|void
operator|*
operator|*
name|new_mem
argument_list|,
name|apr_threadkey_t
operator|*
name|key
argument_list|)
expr_stmt|;
comment|/**  * Set the data to be stored in thread private memory  * @param priv The data to be stored in private memory   * @param key The handle for the desired thread private memory   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_private_set
argument_list|(
name|void
operator|*
name|priv
argument_list|,
name|apr_threadkey_t
operator|*
name|key
argument_list|)
expr_stmt|;
comment|/**  * Free the thread private memory  * @param key The handle for the desired thread private memory   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_private_delete
argument_list|(
name|apr_threadkey_t
operator|*
name|key
argument_list|)
expr_stmt|;
comment|/**  * Return the pool associated with the current threadkey.  * @param data The user data associated with the threadkey.  * @param key The key associated with the data  * @param threadkey The currently open threadkey.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_data_get
argument_list|(
name|void
operator|*
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_threadkey_t
operator|*
name|threadkey
argument_list|)
expr_stmt|;
comment|/**  * Return the pool associated with the current threadkey.  * @param data The data to set.  * @param key The key to associate with the data.  * @param cleanup The cleanup routine to use when the file is destroyed.  * @param threadkey The currently open threadkey.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_threadkey_data_set
argument_list|(
name|void
operator|*
name|data
argument_list|,
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_status_t
argument_list|(
operator|*
name|cleanup
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|apr_threadkey_t
operator|*
name|threadkey
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/**  * Create and initialize a new procattr variable  * @param new_attr The newly created procattr.   * @param cont The pool to use  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_create
argument_list|(
name|apr_procattr_t
operator|*
operator|*
name|new_attr
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
comment|/**  * Determine if any of stdin, stdout, or stderr should be linked to pipes   * when starting a child process.  * @param attr The procattr we care about.   * @param in Should stdin be a pipe back to the parent?  * @param out Should stdout be a pipe back to the parent?  * @param err Should stderr be a pipe back to the parent?  * @note If APR_NO_PIPE, there will be no special channel, the child  * inherits the parent's corresponding stdio stream.  If APR_NO_FILE is   * specified, that corresponding stream is closed in the child (and will  * be INVALID_HANDLE_VALUE when inspected on Win32). This can have ugly   * side effects, as the next file opened in the child on Unix will fall  * into the stdio stream fd slot!  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_io_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_int32_t in
argument_list|,
argument|apr_int32_t out
argument_list|,
argument|apr_int32_t err
argument_list|)
empty_stmt|;
comment|/**  * Set the child_in and/or parent_in values to existing apr_file_t values.  * @param attr The procattr we care about.   * @param child_in apr_file_t value to use as child_in. Must be a valid file.  * @param parent_in apr_file_t value to use as parent_in. Must be a valid file.  * @remark  This is NOT a required initializer function. This is  *          useful if you have already opened a pipe (or multiple files)  *          that you wish to use, perhaps persistently across multiple  *          process invocations - such as a log file. You can save some   *          extra function calls by not creating your own pipe since this  *          creates one in the process space for you.  * @bug Note that calling this function with two NULL files on some platforms  * creates an APR_FULL_BLOCK pipe, but this behavior is neither portable nor  * is it supported.  @see apr_procattr_io_set instead for simple pipes.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_child_in_set
argument_list|(
expr|struct
name|apr_procattr_t
operator|*
name|attr
argument_list|,
name|apr_file_t
operator|*
name|child_in
argument_list|,
name|apr_file_t
operator|*
name|parent_in
argument_list|)
expr_stmt|;
comment|/**  * Set the child_out and parent_out values to existing apr_file_t values.  * @param attr The procattr we care about.   * @param child_out apr_file_t value to use as child_out. Must be a valid file.  * @param parent_out apr_file_t value to use as parent_out. Must be a valid file.  * @remark This is NOT a required initializer function. This is  *         useful if you have already opened a pipe (or multiple files)  *         that you wish to use, perhaps persistently across multiple  *         process invocations - such as a log file.   * @bug Note that calling this function with two NULL files on some platforms  * creates an APR_FULL_BLOCK pipe, but this behavior is neither portable nor  * is it supported.  @see apr_procattr_io_set instead for simple pipes.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_child_out_set
argument_list|(
expr|struct
name|apr_procattr_t
operator|*
name|attr
argument_list|,
name|apr_file_t
operator|*
name|child_out
argument_list|,
name|apr_file_t
operator|*
name|parent_out
argument_list|)
expr_stmt|;
comment|/**  * Set the child_err and parent_err values to existing apr_file_t values.  * @param attr The procattr we care about.   * @param child_err apr_file_t value to use as child_err. Must be a valid file.  * @param parent_err apr_file_t value to use as parent_err. Must be a valid file.  * @remark This is NOT a required initializer function. This is  *         useful if you have already opened a pipe (or multiple files)  *         that you wish to use, perhaps persistently across multiple  *         process invocations - such as a log file.   * @bug Note that calling this function with two NULL files on some platforms  * creates an APR_FULL_BLOCK pipe, but this behavior is neither portable nor  * is it supported.  @see apr_procattr_io_set instead for simple pipes.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_child_err_set
argument_list|(
expr|struct
name|apr_procattr_t
operator|*
name|attr
argument_list|,
name|apr_file_t
operator|*
name|child_err
argument_list|,
name|apr_file_t
operator|*
name|parent_err
argument_list|)
expr_stmt|;
comment|/**  * Set which directory the child process should start executing in.  * @param attr The procattr we care about.   * @param dir Which dir to start in.  By default, this is the same dir as  *            the parent currently resides in, when the createprocess call  *            is made.   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_dir_set
argument_list|(
name|apr_procattr_t
operator|*
name|attr
argument_list|,
specifier|const
name|char
operator|*
name|dir
argument_list|)
expr_stmt|;
comment|/**  * Set what type of command the child process will call.  * @param attr The procattr we care about.   * @param cmd The type of command.  One of:  *<PRE>  *            APR_SHELLCMD     --  Anything that the shell can handle  *            APR_PROGRAM      --  Executable program   (default)   *            APR_PROGRAM_ENV  --  Executable program, copy environment  *            APR_PROGRAM_PATH --  Executable program on PATH, copy env  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_cmdtype_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_cmdtype_e cmd
argument_list|)
empty_stmt|;
comment|/**  * Determine if the child should start in detached state.  * @param attr The procattr we care about.   * @param detach Should the child start in detached state?  Default is no.   */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_detach_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_int32_t detach
argument_list|)
empty_stmt|;
if|#
directive|if
name|APR_HAVE_STRUCT_RLIMIT
comment|/**  * Set the Resource Utilization limits when starting a new process.  * @param attr The procattr we care about.   * @param what Which limit to set, one of:  *<PRE>  *                 APR_LIMIT_CPU  *                 APR_LIMIT_MEM  *                 APR_LIMIT_NPROC  *                 APR_LIMIT_NOFILE  *</PRE>  * @param limit Value to set the limit to.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_limit_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_int32_t what
argument_list|,
argument|struct rlimit *limit
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/**  * Specify an error function to be called in the child process if APR  * encounters an error in the child prior to running the specified program.  * @param attr The procattr describing the child process to be created.  * @param errfn The function to call in the child process.  * @remark At the present time, it will only be called from apr_proc_create()  *         on platforms where fork() is used.  It will never be called on other  *         platforms, on those platforms apr_proc_create() will return the error  *         in the parent process rather than invoke the callback in the now-forked  *         child process.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_child_errfn_set
argument_list|(
name|apr_procattr_t
operator|*
name|attr
argument_list|,
name|apr_child_errfn_t
operator|*
name|errfn
argument_list|)
expr_stmt|;
comment|/**  * Specify that apr_proc_create() should do whatever it can to report  * failures to the caller of apr_proc_create(), rather than find out in  * the child.  * @param attr The procattr describing the child process to be created.  * @param chk Flag to indicate whether or not extra work should be done  *            to try to report failures to the caller.  * @remark This flag only affects apr_proc_create() on platforms where  *         fork() is used.  This leads to extra overhead in the calling  *         process, but that may help the application handle such  *         errors more gracefully.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_error_check_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_int32_t chk
argument_list|)
empty_stmt|;
comment|/**  * Determine if the child should start in its own address space or using the   * current one from its parent  * @param attr The procattr we care about.   * @param addrspace Should the child start in its own address space?  Default  *                  is no on NetWare and yes on other platforms.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_addrspace_set
argument_list|(
argument|apr_procattr_t *attr
argument_list|,
argument|apr_int32_t addrspace
argument_list|)
empty_stmt|;
comment|/**  * Set the username used for running process  * @param attr The procattr we care about.   * @param username The username used  * @param password User password if needed. Password is needed on WIN32  *                 or any other platform having  *                 APR_PROCATTR_USER_SET_REQUIRES_PASSWORD set.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_user_set
argument_list|(
name|apr_procattr_t
operator|*
name|attr
argument_list|,
specifier|const
name|char
operator|*
name|username
argument_list|,
specifier|const
name|char
operator|*
name|password
argument_list|)
expr_stmt|;
comment|/**  * Set the group used for running process  * @param attr The procattr we care about.   * @param groupname The group name  used  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_procattr_group_set
argument_list|(
name|apr_procattr_t
operator|*
name|attr
argument_list|,
specifier|const
name|char
operator|*
name|groupname
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_FORK
comment|/**  * This is currently the only non-portable call in APR.  This executes   * a standard unix fork.  * @param proc The resulting process handle.   * @param cont The pool to use.   * @remark returns APR_INCHILD for the child, and APR_INPARENT for the parent  * or an error.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_fork
argument_list|(
name|apr_proc_t
operator|*
name|proc
argument_list|,
name|apr_pool_t
operator|*
name|cont
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/**  * Create a new process and execute a new program within that process.  * @param new_proc The resulting process handle.  * @param progname The program to run   * @param args the arguments to pass to the new program.  The first   *             one should be the program name.  * @param env The new environment table for the new process.  This   *            should be a list of NULL-terminated strings. This argument  *            is ignored for APR_PROGRAM_ENV, APR_PROGRAM_PATH, and  *            APR_SHELLCMD_ENV types of commands.  * @param attr the procattr we should use to determine how to create the new  *         process  * @param pool The pool to use.  * @note This function returns without waiting for the new process to terminate;  * use apr_proc_wait for that.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_create
argument_list|(
name|apr_proc_t
operator|*
name|new_proc
argument_list|,
specifier|const
name|char
operator|*
name|progname
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|args
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|env
argument_list|,
name|apr_procattr_t
operator|*
name|attr
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Wait for a child process to die  * @param proc The process handle that corresponds to the desired child process   * @param exitcode The returned exit status of the child, if a child process   *                 dies, or the signal that caused the child to die.  *                 On platforms that don't support obtaining this information,   *                 the status parameter will be returned as APR_ENOTIMPL.  * @param exitwhy Why the child died, the bitwise or of:  *<PRE>  *            APR_PROC_EXIT         -- process terminated normally  *            APR_PROC_SIGNAL       -- process was killed by a signal  *            APR_PROC_SIGNAL_CORE  -- process was killed by a signal, and  *                                     generated a core dump.  *</PRE>  * @param waithow How should we wait.  One of:  *<PRE>  *            APR_WAIT   -- block until the child process dies.  *            APR_NOWAIT -- return immediately regardless of if the   *                          child is dead or not.  *</PRE>  * @remark The child's status is in the return code to this process.  It is one of:  *<PRE>  *            APR_CHILD_DONE     -- child is no longer running.  *            APR_CHILD_NOTDONE  -- child is still running.  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_wait
argument_list|(
argument|apr_proc_t *proc
argument_list|,
argument|int *exitcode
argument_list|,
argument|apr_exit_why_e *exitwhy
argument_list|,
argument|apr_wait_how_e waithow
argument_list|)
empty_stmt|;
comment|/**  * Wait for any current child process to die and return information   * about that child.  * @param proc Pointer to NULL on entry, will be filled out with child's   *             information   * @param exitcode The returned exit status of the child, if a child process   *                 dies, or the signal that caused the child to die.  *                 On platforms that don't support obtaining this information,   *                 the status parameter will be returned as APR_ENOTIMPL.  * @param exitwhy Why the child died, the bitwise or of:  *<PRE>  *            APR_PROC_EXIT         -- process terminated normally  *            APR_PROC_SIGNAL       -- process was killed by a signal  *            APR_PROC_SIGNAL_CORE  -- process was killed by a signal, and  *                                     generated a core dump.  *</PRE>  * @param waithow How should we wait.  One of:  *<PRE>  *            APR_WAIT   -- block until the child process dies.  *            APR_NOWAIT -- return immediately regardless of if the   *                          child is dead or not.  *</PRE>  * @param p Pool to allocate child information out of.  * @bug Passing proc as a *proc rather than **proc was an odd choice  * for some platforms... this should be revisited in 1.0  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_wait_all_procs
argument_list|(
argument|apr_proc_t *proc
argument_list|,
argument|int *exitcode
argument_list|,
argument|apr_exit_why_e *exitwhy
argument_list|,
argument|apr_wait_how_e waithow
argument_list|,
argument|apr_pool_t *p
argument_list|)
empty_stmt|;
define|#
directive|define
name|APR_PROC_DETACH_FOREGROUND
value|0
comment|/**< Do not detach */
define|#
directive|define
name|APR_PROC_DETACH_DAEMONIZE
value|1
comment|/**< Detach */
comment|/**  * Detach the process from the controlling terminal.  * @param daemonize set to non-zero if the process should daemonize  *                  and become a background process, else it will  *                  stay in the foreground.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_detach
argument_list|(
argument|int daemonize
argument_list|)
empty_stmt|;
comment|/**  * Register an other_child -- a child associated to its registered   * maintence callback.  This callback is invoked when the process  * dies, is disconnected or disappears.  * @param proc The child process to register.  * @param maintenance maintenance is a function that is invoked with a   *                    reason and the data pointer passed here.  * @param data Opaque context data passed to the maintenance function.  * @param write_fd An fd that is probed for writing.  If it is ever unwritable  *                 then the maintenance is invoked with reason   *                 OC_REASON_UNWRITABLE.  * @param p The pool to use for allocating memory.  * @bug write_fd duplicates the proc->out stream, it's really redundant  * and should be replaced in the APR 1.0 API with a bitflag of which  * proc->in/out/err handles should be health checked.  * @bug no platform currently tests the pipes health.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_proc_other_child_register
argument_list|(
name|apr_proc_t
operator|*
name|proc
argument_list|,
name|void
argument_list|(
argument|*maintenance
argument_list|)
operator|(
name|int
name|reason
operator|,
name|void
operator|*
operator|,
name|int
name|status
operator|)
argument_list|,
name|void
operator|*
name|data
argument_list|,
name|apr_file_t
operator|*
name|write_fd
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Stop watching the specified other child.    * @param data The data to pass to the maintenance function.  This is  *             used to find the process to unregister.  * @warning Since this can be called by a maintenance function while we're  *          scanning the other_children list, all scanners should protect   *          themself by loading ocr->next before calling any maintenance   *          function.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_proc_other_child_unregister
argument_list|(
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Notify the maintenance callback of a registered other child process  * that application has detected an event, such as death.  * @param proc The process to check  * @param reason The reason code to pass to the maintenance function  * @param status The status to pass to the maintenance function  * @remark An example of code using this behavior;  *<pre>  * rv = apr_proc_wait_all_procs(&proc,&exitcode,&status, APR_WAIT, p);  * if (APR_STATUS_IS_CHILD_DONE(rv)) {  * \#if APR_HAS_OTHER_CHILD  *     if (apr_proc_other_child_alert(&proc, APR_OC_REASON_DEATH, status)  *             == APR_SUCCESS) {  *         ;  (already handled)  *     }  *     else  * \#endif  *         [... handling non-otherchild processes death ...]  *</pre>  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_other_child_alert
argument_list|(
argument|apr_proc_t *proc
argument_list|,
argument|int reason
argument_list|,
argument|int status
argument_list|)
empty_stmt|;
comment|/**  * Test one specific other child processes and invoke the maintenance callback   * with the appropriate reason code, if still running, or the appropriate reason   * code if the process is no longer healthy.  * @param ocr The registered other child  * @param reason The reason code (e.g. APR_OC_REASON_RESTART) if still running  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_proc_other_child_refresh
argument_list|(
argument|apr_other_child_rec_t *ocr
argument_list|,
argument|int reason
argument_list|)
empty_stmt|;
comment|/**  * Test all registered other child processes and invoke the maintenance callback   * with the appropriate reason code, if still running, or the appropriate reason   * code if the process is no longer healthy.  * @param reason The reason code (e.g. APR_OC_REASON_RESTART) to running processes  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_proc_other_child_refresh_all
argument_list|(
argument|int reason
argument_list|)
empty_stmt|;
comment|/**   * Terminate a process.  * @param proc The process to terminate.  * @param sig How to kill the process.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_proc_kill
argument_list|(
argument|apr_proc_t *proc
argument_list|,
argument|int sig
argument_list|)
empty_stmt|;
comment|/**  * Register a process to be killed when a pool dies.  * @param a The pool to use to define the processes lifetime   * @param proc The process to register  * @param how How to kill the process, one of:  *<PRE>  *         APR_KILL_NEVER         -- process is never sent any signals  *         APR_KILL_ALWAYS        -- process is sent SIGKILL on apr_pool_t cleanup  *         APR_KILL_AFTER_TIMEOUT -- SIGTERM, wait 3 seconds, SIGKILL  *         APR_JUST_WAIT          -- wait forever for the process to complete  *         APR_KILL_ONLY_ONCE     -- send SIGTERM and then wait  *</PRE>  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_pool_note_subprocess
argument_list|(
argument|apr_pool_t *a
argument_list|,
argument|apr_proc_t *proc
argument_list|,
argument|apr_kill_conditions_e how
argument_list|)
empty_stmt|;
if|#
directive|if
name|APR_HAS_THREADS
if|#
directive|if
operator|(
name|APR_HAVE_SIGWAIT
operator|||
name|APR_HAVE_SIGSUSPEND
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
comment|/**  * Setup the process for a single thread to be used for all signal handling.  * @warning This must be called before any threads are created  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_setup_signal_thread
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Make the current thread listen for signals.  This thread will loop  * forever, calling a provided function whenever it receives a signal.  That  * functions should return 1 if the signal has been handled, 0 otherwise.  * @param signal_handler The function to call when a signal is received  * apr_status_t apr_signal_thread((int)(*signal_handler)(int signum))  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_signal_thread
argument_list|(
name|int
argument_list|(
argument|*signal_handler
argument_list|)
operator|(
name|int
name|signum
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* (APR_HAVE_SIGWAIT || APR_HAVE_SIGSUSPEND)&& !defined(OS2) */
comment|/**  * Get the child-pool used by the thread from the thread info.  * @return apr_pool_t the pool  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|thread
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_THREADS */
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
comment|/* ! APR_THREAD_PROC_H */
end_comment

end_unit

