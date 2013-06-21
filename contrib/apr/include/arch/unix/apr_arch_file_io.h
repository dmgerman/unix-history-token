begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILE_IO_H
end_ifndef

begin_define
define|#
directive|define
name|FILE_IO_H
end_define

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_tables.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_info.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_lib.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WAITIO_USES_POLL
end_ifndef

begin_include
include|#
directive|include
file|"apr_poll.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System headers the file I/O library needs */
end_comment

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
name|APR_HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_ERRNO_H
end_if

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STRINGS_H
end_if

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDIO_H
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_UIO_H
end_if

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SYS_TIME_H
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BEOS
end_ifdef

begin_include
include|#
directive|include
file|<kernel/OS.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hunting down DEV_BSIZE if not from dirent.h, sys/stat.h etc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PARAM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BEOS_BONE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|BONE7
end_ifndef

begin_comment
comment|/* prior to BONE/7 fd_set& select were defined in sys/socket.h */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Be moved the fd_set stuff and also the FIONBIO definition... */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End System headers */
end_comment

begin_define
define|#
directive|define
name|APR_FILE_DEFAULT_BUFSIZE
value|4096
end_define

begin_comment
comment|/* For backwards-compat */
end_comment

begin_define
define|#
directive|define
name|APR_FILE_BUFSIZE
value|APR_FILE_DEFAULT_BUFSIZE
end_define

begin_struct
struct|struct
name|apr_file_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|int
name|filedes
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
name|apr_int32_t
name|flags
decl_stmt|;
name|int
name|eof_hit
decl_stmt|;
name|int
name|is_pipe
decl_stmt|;
name|apr_interval_time_t
name|timeout
decl_stmt|;
name|int
name|buffered
decl_stmt|;
enum|enum
block|{
name|BLK_UNKNOWN
block|,
name|BLK_OFF
block|,
name|BLK_ON
block|}
name|blocking
enum|;
name|int
name|ungetchar
decl_stmt|;
comment|/* Last char provided by an unget op. (-1 = no char)*/
ifndef|#
directive|ifndef
name|WAITIO_USES_POLL
comment|/* if there is a timeout set, then this pollset is used */
name|apr_pollset_t
modifier|*
name|pollset
decl_stmt|;
endif|#
directive|endif
comment|/* Stuff for buffered mode */
name|char
modifier|*
name|buffer
decl_stmt|;
name|apr_size_t
name|bufpos
decl_stmt|;
comment|/* Read/Write position in buffer */
name|apr_size_t
name|bufsize
decl_stmt|;
comment|/* The size of the buffer */
name|unsigned
name|long
name|dataRead
decl_stmt|;
comment|/* amount of valid data read into buffer */
name|int
name|direction
decl_stmt|;
comment|/* buffer being used for 0 = read, 1 = write */
name|apr_off_t
name|filePtr
decl_stmt|;
comment|/* position in file of handle */
if|#
directive|if
name|APR_HAS_THREADS
name|struct
name|apr_thread_mutex_t
modifier|*
name|thlock
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_define
define|#
directive|define
name|file_lock
parameter_list|(
name|f
parameter_list|)
value|do { \                            if ((f)->thlock) \                                apr_thread_mutex_lock((f)->thlock); \                        } while (0)
end_define

begin_define
define|#
directive|define
name|file_unlock
parameter_list|(
name|f
parameter_list|)
value|do { \                            if ((f)->thlock) \                                apr_thread_mutex_unlock((f)->thlock); \                        } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|file_lock
parameter_list|(
name|f
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|file_unlock
parameter_list|(
name|f
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAS_LARGE_FILES
operator|&&
name|defined
argument_list|(
name|_LARGEFILE64_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|stat64(f,b)
end_define

begin_define
define|#
directive|define
name|lstat
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|lstat64(f,b)
end_define

begin_define
define|#
directive|define
name|fstat
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|)
value|fstat64(f,b)
end_define

begin_define
define|#
directive|define
name|lseek
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|lseek64(f,o,w)
end_define

begin_define
define|#
directive|define
name|ftruncate
parameter_list|(
name|f
parameter_list|,
name|l
parameter_list|)
value|ftruncate64(f,l)
end_define

begin_typedef
typedef|typedef
name|struct
name|stat64
name|struct_stat
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|struct
name|stat
name|struct_stat
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* readdir64_r is only used in specific cases: */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_THREADS
operator|&&
name|defined
argument_list|(
name|_POSIX_THREAD_SAFE_FUNCTIONS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|READDIR_IS_THREAD_SAFE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_READDIR64_R
argument_list|)
end_if

begin_define
define|#
directive|define
name|APR_USE_READDIR64_R
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|apr_dir_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|char
modifier|*
name|dirname
decl_stmt|;
name|DIR
modifier|*
name|dirstruct
decl_stmt|;
ifdef|#
directive|ifdef
name|APR_USE_READDIR64_R
name|struct
name|dirent64
modifier|*
name|entry
decl_stmt|;
else|#
directive|else
name|struct
name|dirent
modifier|*
name|entry
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|apr_status_t
name|apr_unix_file_cleanup
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|apr_unix_child_file_cleanup
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|apr_unix_perms2mode
parameter_list|(
name|apr_fileperms_t
name|perms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_fileperms_t
name|apr_unix_mode2perms
parameter_list|(
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|apr_file_flush_locked
parameter_list|(
name|apr_file_t
modifier|*
name|thefile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|apr_file_info_get_locked
parameter_list|(
name|apr_finfo_t
modifier|*
name|finfo
parameter_list|,
name|apr_int32_t
name|wanted
parameter_list|,
name|apr_file_t
modifier|*
name|thefile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FILE_IO_H */
end_comment

end_unit

