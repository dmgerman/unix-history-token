begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ERRNO_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ERRNO_H
end_define

begin_comment
comment|/**  * @file apr_errno.h  * @brief APR Error Codes  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

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
comment|/**  * @defgroup apr_errno Error Codes  * @ingroup APR  * @{  */
comment|/**  * Type for specifying an error or status code.  */
typedef|typedef
name|int
name|apr_status_t
typedef|;
comment|/**  * Return a human readable string describing the specified error.  * @param statcode The error code to get a string for.  * @param buf A buffer to hold the error string.  * @param bufsize Size of the buffer to hold the string.  */
name|APR_DECLARE
argument_list|(
argument|char *
argument_list|)
name|apr_strerror
argument_list|(
argument|apr_status_t statcode
argument_list|,
argument|char *buf
argument_list|,
argument|apr_size_t bufsize
argument_list|)
empty_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * @def APR_FROM_OS_ERROR(os_err_type syserr)  * Fold a platform specific error into an apr_status_t code.  * @return apr_status_t  * @param e The platform os error code.  * @warning  macro implementation; the syserr argument may be evaluated  *      multiple times.  */
define|#
directive|define
name|APR_FROM_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e + APR_OS_START_SYSERR)
comment|/**  * @def APR_TO_OS_ERROR(apr_status_t statcode)  * @return os_err_type  * Fold an apr_status_t code back to the native platform defined error.  * @param e The apr_status_t folded platform os error code.  * @warning  macro implementation; the statcode argument may be evaluated  *      multiple times.  If the statcode was not created by apr_get_os_error  *      or APR_FROM_OS_ERROR, the results are undefined.  */
define|#
directive|define
name|APR_TO_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e - APR_OS_START_SYSERR)
comment|/** @def apr_get_os_error()  * @return apr_status_t the last platform error, folded into apr_status_t, on most platforms  * @remark This retrieves errno, or calls a GetLastError() style function, and  *      folds it with APR_FROM_OS_ERROR.  Some platforms (such as OS2) have no  *      such mechanism, so this call may be unsupported.  Do NOT use this  *      call for socket errors from socket, send, recv etc!  */
comment|/** @def apr_set_os_error(e)  * Reset the last platform error, unfolded from an apr_status_t, on some platforms  * @param e The OS error folded in a prior call to APR_FROM_OS_ERROR()  * @warning This is a macro implementation; the statcode argument may be evaluated  *      multiple times.  If the statcode was not created by apr_get_os_error  *      or APR_FROM_OS_ERROR, the results are undefined.  This macro sets  *      errno, or calls a SetLastError() style function, unfolding statcode  *      with APR_TO_OS_ERROR.  Some platforms (such as OS2) have no such  *      mechanism, so this call may be unsupported.  */
comment|/** @def apr_get_netos_error()  * Return the last socket error, folded into apr_status_t, on all platforms  * @remark This retrieves errno or calls a GetLastSocketError() style function,  *      and folds it with APR_FROM_OS_ERROR.  */
comment|/** @def apr_set_netos_error(e)  * Reset the last socket error, unfolded from an apr_status_t  * @param e The socket error folded in a prior call to APR_FROM_OS_ERROR()  * @warning This is a macro implementation; the statcode argument may be evaluated  *      multiple times.  If the statcode was not created by apr_get_os_error  *      or APR_FROM_OS_ERROR, the results are undefined.  This macro sets  *      errno, or calls a WSASetLastError() style function, unfolding  *      socketcode with APR_TO_OS_ERROR.  */
endif|#
directive|endif
comment|/* defined(DOXYGEN) */
comment|/**  * APR_OS_START_ERROR is where the APR specific error values start.  */
define|#
directive|define
name|APR_OS_START_ERROR
value|20000
comment|/**  * APR_OS_ERRSPACE_SIZE is the maximum number of errors you can fit  *    into one of the error/status ranges below -- except for  *    APR_OS_START_USERERR, which see.  */
define|#
directive|define
name|APR_OS_ERRSPACE_SIZE
value|50000
comment|/**  * APR_UTIL_ERRSPACE_SIZE is the size of the space that is reserved for  * use within apr-util. This space is reserved above that used by APR  * internally.  * @note This number MUST be smaller than APR_OS_ERRSPACE_SIZE by a  *       large enough amount that APR has sufficient room for its  *       codes.  */
define|#
directive|define
name|APR_UTIL_ERRSPACE_SIZE
value|20000
comment|/**  * APR_OS_START_STATUS is where the APR specific status codes start.  */
define|#
directive|define
name|APR_OS_START_STATUS
value|(APR_OS_START_ERROR + APR_OS_ERRSPACE_SIZE)
comment|/**  * APR_UTIL_START_STATUS is where APR-Util starts defining its  * status codes.  */
define|#
directive|define
name|APR_UTIL_START_STATUS
value|(APR_OS_START_STATUS + \                            (APR_OS_ERRSPACE_SIZE - APR_UTIL_ERRSPACE_SIZE))
comment|/**  * APR_OS_START_USERERR are reserved for applications that use APR that  *     layer their own error codes along with APR's.  Note that the  *     error immediately following this one is set ten times farther  *     away than usual, so that users of apr have a lot of room in  *     which to declare custom error codes.  *  * In general applications should try and create unique error codes. To try  * and assist in finding suitable ranges of numbers to use, the following  * ranges are known to be used by the listed applications. If your  * application defines error codes please advise the range of numbers it  * uses to dev@apr.apache.org for inclusion in this list.  *  * Ranges shown are in relation to APR_OS_START_USERERR  *  * Subversion - Defined ranges, of less than 100, at intervals of 5000  *              starting at an offset of 5000, e.g.  *               +5000 to 5100,  +10000 to 10100  *  * Apache HTTPD - +2000 to 2999  */
define|#
directive|define
name|APR_OS_START_USERERR
value|(APR_OS_START_STATUS + APR_OS_ERRSPACE_SIZE)
comment|/**  * APR_OS_START_USEERR is obsolete, defined for compatibility only.  * Use APR_OS_START_USERERR instead.  */
define|#
directive|define
name|APR_OS_START_USEERR
value|APR_OS_START_USERERR
comment|/**  * APR_OS_START_CANONERR is where APR versions of errno values are defined  *     on systems which don't have the corresponding errno.  */
define|#
directive|define
name|APR_OS_START_CANONERR
value|(APR_OS_START_USERERR \                                  + (APR_OS_ERRSPACE_SIZE * 10))
comment|/**  * APR_OS_START_EAIERR folds EAI_ error codes from getaddrinfo() into  *     apr_status_t values.  */
define|#
directive|define
name|APR_OS_START_EAIERR
value|(APR_OS_START_CANONERR + APR_OS_ERRSPACE_SIZE)
comment|/**  * APR_OS_START_SYSERR folds platform-specific system error values into  *     apr_status_t values.  */
define|#
directive|define
name|APR_OS_START_SYSERR
value|(APR_OS_START_EAIERR + APR_OS_ERRSPACE_SIZE)
comment|/**  * @defgroup APR_ERROR_map APR Error Space  *<PRE>  * The following attempts to show the relation of the various constants  * used for mapping APR Status codes.  *  *       0  *  *  20,000     APR_OS_START_ERROR  *  *         + APR_OS_ERRSPACE_SIZE (50,000)  *  *  70,000      APR_OS_START_STATUS  *  *         + APR_OS_ERRSPACE_SIZE - APR_UTIL_ERRSPACE_SIZE (30,000)  *  * 100,000      APR_UTIL_START_STATUS  *  *         + APR_UTIL_ERRSPACE_SIZE (20,000)  *  * 120,000      APR_OS_START_USERERR  *  *         + 10 x APR_OS_ERRSPACE_SIZE (50,000 * 10)  *  * 620,000      APR_OS_START_CANONERR  *  *         + APR_OS_ERRSPACE_SIZE (50,000)  *  * 670,000      APR_OS_START_EAIERR  *  *         + APR_OS_ERRSPACE_SIZE (50,000)  *  * 720,000      APR_OS_START_SYSERR  *  *</PRE>  */
comment|/** no error. */
define|#
directive|define
name|APR_SUCCESS
value|0
comment|/**  * @defgroup APR_Error APR Error Values  *<PRE>  *<b>APR ERROR VALUES</b>  * APR_ENOSTAT      APR was unable to perform a stat on the file  * APR_ENOPOOL      APR was not provided a pool with which to allocate memory  * APR_EBADDATE     APR was given an invalid date  * APR_EINVALSOCK   APR was given an invalid socket  * APR_ENOPROC      APR was not given a process structure  * APR_ENOTIME      APR was not given a time structure  * APR_ENODIR       APR was not given a directory structure  * APR_ENOLOCK      APR was not given a lock structure  * APR_ENOPOLL      APR was not given a poll structure  * APR_ENOSOCKET    APR was not given a socket  * APR_ENOTHREAD    APR was not given a thread structure  * APR_ENOTHDKEY    APR was not given a thread key structure  * APR_ENOSHMAVAIL  There is no more shared memory available  * APR_EDSOOPEN     APR was unable to open the dso object.  For more  *                  information call apr_dso_error().  * APR_EGENERAL     General failure (specific information not available)  * APR_EBADIP       The specified IP address is invalid  * APR_EBADMASK     The specified netmask is invalid  * APR_ESYMNOTFOUND Could not find the requested symbol  * APR_ENOTENOUGHENTROPY Not enough entropy to continue  *</PRE>  *  *<PRE>  *<b>APR STATUS VALUES</b>  * APR_INCHILD        Program is currently executing in the child  * APR_INPARENT       Program is currently executing in the parent  * APR_DETACH         The thread is detached  * APR_NOTDETACH      The thread is not detached  * APR_CHILD_DONE     The child has finished executing  * APR_CHILD_NOTDONE  The child has not finished executing  * APR_TIMEUP         The operation did not finish before the timeout  * APR_INCOMPLETE     The operation was incomplete although some processing  *                    was performed and the results are partially valid  * APR_BADCH          Getopt found an option not in the option string  * APR_BADARG         Getopt found an option that is missing an argument  *                    and an argument was specified in the option string  * APR_EOF            APR has encountered the end of the file  * APR_NOTFOUND       APR was unable to find the socket in the poll structure  * APR_ANONYMOUS      APR is using anonymous shared memory  * APR_FILEBASED      APR is using a file name as the key to the shared memory  * APR_KEYBASED       APR is using a shared key as the key to the shared memory  * APR_EINIT          Ininitalizer value.  If no option has been found, but  *                    the status variable requires a value, this should be used  * APR_ENOTIMPL       The APR function has not been implemented on this  *                    platform, either because nobody has gotten to it yet,  *                    or the function is impossible on this platform.  * APR_EMISMATCH      Two passwords do not match.  * APR_EABSOLUTE      The given path was absolute.  * APR_ERELATIVE      The given path was relative.  * APR_EINCOMPLETE    The given path was neither relative nor absolute.  * APR_EABOVEROOT     The given path was above the root path.  * APR_EBUSY          The given lock was busy.  * APR_EPROC_UNKNOWN  The given process wasn't recognized by APR  *</PRE>  * @{  */
comment|/** @see APR_STATUS_IS_ENOSTAT */
define|#
directive|define
name|APR_ENOSTAT
value|(APR_OS_START_ERROR + 1)
comment|/** @see APR_STATUS_IS_ENOPOOL */
define|#
directive|define
name|APR_ENOPOOL
value|(APR_OS_START_ERROR + 2)
comment|/* empty slot: +3 */
comment|/** @see APR_STATUS_IS_EBADDATE */
define|#
directive|define
name|APR_EBADDATE
value|(APR_OS_START_ERROR + 4)
comment|/** @see APR_STATUS_IS_EINVALSOCK */
define|#
directive|define
name|APR_EINVALSOCK
value|(APR_OS_START_ERROR + 5)
comment|/** @see APR_STATUS_IS_ENOPROC */
define|#
directive|define
name|APR_ENOPROC
value|(APR_OS_START_ERROR + 6)
comment|/** @see APR_STATUS_IS_ENOTIME */
define|#
directive|define
name|APR_ENOTIME
value|(APR_OS_START_ERROR + 7)
comment|/** @see APR_STATUS_IS_ENODIR */
define|#
directive|define
name|APR_ENODIR
value|(APR_OS_START_ERROR + 8)
comment|/** @see APR_STATUS_IS_ENOLOCK */
define|#
directive|define
name|APR_ENOLOCK
value|(APR_OS_START_ERROR + 9)
comment|/** @see APR_STATUS_IS_ENOPOLL */
define|#
directive|define
name|APR_ENOPOLL
value|(APR_OS_START_ERROR + 10)
comment|/** @see APR_STATUS_IS_ENOSOCKET */
define|#
directive|define
name|APR_ENOSOCKET
value|(APR_OS_START_ERROR + 11)
comment|/** @see APR_STATUS_IS_ENOTHREAD */
define|#
directive|define
name|APR_ENOTHREAD
value|(APR_OS_START_ERROR + 12)
comment|/** @see APR_STATUS_IS_ENOTHDKEY */
define|#
directive|define
name|APR_ENOTHDKEY
value|(APR_OS_START_ERROR + 13)
comment|/** @see APR_STATUS_IS_EGENERAL */
define|#
directive|define
name|APR_EGENERAL
value|(APR_OS_START_ERROR + 14)
comment|/** @see APR_STATUS_IS_ENOSHMAVAIL */
define|#
directive|define
name|APR_ENOSHMAVAIL
value|(APR_OS_START_ERROR + 15)
comment|/** @see APR_STATUS_IS_EBADIP */
define|#
directive|define
name|APR_EBADIP
value|(APR_OS_START_ERROR + 16)
comment|/** @see APR_STATUS_IS_EBADMASK */
define|#
directive|define
name|APR_EBADMASK
value|(APR_OS_START_ERROR + 17)
comment|/* empty slot: +18 */
comment|/** @see APR_STATUS_IS_EDSOPEN */
define|#
directive|define
name|APR_EDSOOPEN
value|(APR_OS_START_ERROR + 19)
comment|/** @see APR_STATUS_IS_EABSOLUTE */
define|#
directive|define
name|APR_EABSOLUTE
value|(APR_OS_START_ERROR + 20)
comment|/** @see APR_STATUS_IS_ERELATIVE */
define|#
directive|define
name|APR_ERELATIVE
value|(APR_OS_START_ERROR + 21)
comment|/** @see APR_STATUS_IS_EINCOMPLETE */
define|#
directive|define
name|APR_EINCOMPLETE
value|(APR_OS_START_ERROR + 22)
comment|/** @see APR_STATUS_IS_EABOVEROOT */
define|#
directive|define
name|APR_EABOVEROOT
value|(APR_OS_START_ERROR + 23)
comment|/** @see APR_STATUS_IS_EBADPATH */
define|#
directive|define
name|APR_EBADPATH
value|(APR_OS_START_ERROR + 24)
comment|/** @see APR_STATUS_IS_EPATHWILD */
define|#
directive|define
name|APR_EPATHWILD
value|(APR_OS_START_ERROR + 25)
comment|/** @see APR_STATUS_IS_ESYMNOTFOUND */
define|#
directive|define
name|APR_ESYMNOTFOUND
value|(APR_OS_START_ERROR + 26)
comment|/** @see APR_STATUS_IS_EPROC_UNKNOWN */
define|#
directive|define
name|APR_EPROC_UNKNOWN
value|(APR_OS_START_ERROR + 27)
comment|/** @see APR_STATUS_IS_ENOTENOUGHENTROPY */
define|#
directive|define
name|APR_ENOTENOUGHENTROPY
value|(APR_OS_START_ERROR + 28)
comment|/** @} */
comment|/**  * @defgroup APR_STATUS_IS Status Value Tests  * @warning For any particular error condition, more than one of these tests  *      may match. This is because platform-specific error codes may not  *      always match the semantics of the POSIX codes these tests (and the  *      corresponding APR error codes) are named after. A notable example  *      are the APR_STATUS_IS_ENOENT and APR_STATUS_IS_ENOTDIR tests on  *      Win32 platforms. The programmer should always be aware of this and  *      adjust the order of the tests accordingly.  * @{  */
comment|/**  * APR was unable to perform a stat on the file  * @warning always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_ENOSTAT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSTAT)
comment|/**  * APR was not provided a pool with which to allocate memory  * @warning always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_ENOPOOL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOPOOL)
comment|/** APR was given an invalid date  */
define|#
directive|define
name|APR_STATUS_IS_EBADDATE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADDATE)
comment|/** APR was given an invalid socket */
define|#
directive|define
name|APR_STATUS_IS_EINVALSOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINVALSOCK)
comment|/** APR was not given a process structure */
define|#
directive|define
name|APR_STATUS_IS_ENOPROC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOPROC)
comment|/** APR was not given a time structure */
define|#
directive|define
name|APR_STATUS_IS_ENOTIME
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTIME)
comment|/** APR was not given a directory structure */
define|#
directive|define
name|APR_STATUS_IS_ENODIR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENODIR)
comment|/** APR was not given a lock structure */
define|#
directive|define
name|APR_STATUS_IS_ENOLOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOLOCK)
comment|/** APR was not given a poll structure */
define|#
directive|define
name|APR_STATUS_IS_ENOPOLL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOPOLL)
comment|/** APR was not given a socket */
define|#
directive|define
name|APR_STATUS_IS_ENOSOCKET
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSOCKET)
comment|/** APR was not given a thread structure */
define|#
directive|define
name|APR_STATUS_IS_ENOTHREAD
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTHREAD)
comment|/** APR was not given a thread key structure */
define|#
directive|define
name|APR_STATUS_IS_ENOTHDKEY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTHDKEY)
comment|/** Generic Error which can not be put into another spot */
define|#
directive|define
name|APR_STATUS_IS_EGENERAL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EGENERAL)
comment|/** There is no more shared memory available */
define|#
directive|define
name|APR_STATUS_IS_ENOSHMAVAIL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSHMAVAIL)
comment|/** The specified IP address is invalid */
define|#
directive|define
name|APR_STATUS_IS_EBADIP
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADIP)
comment|/** The specified netmask is invalid */
define|#
directive|define
name|APR_STATUS_IS_EBADMASK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADMASK)
comment|/* empty slot: +18 */
comment|/**  * APR was unable to open the dso object.  * For more information call apr_dso_error().  */
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
define|#
directive|define
name|APR_STATUS_IS_EDSOOPEN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EDSOOPEN \                        || APR_TO_OS_ERROR(s) == ERROR_MOD_NOT_FOUND)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_EDSOOPEN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EDSOOPEN)
endif|#
directive|endif
comment|/** The given path was absolute. */
define|#
directive|define
name|APR_STATUS_IS_EABSOLUTE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EABSOLUTE)
comment|/** The given path was relative. */
define|#
directive|define
name|APR_STATUS_IS_ERELATIVE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ERELATIVE)
comment|/** The given path was neither relative nor absolute. */
define|#
directive|define
name|APR_STATUS_IS_EINCOMPLETE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINCOMPLETE)
comment|/** The given path was above the root path. */
define|#
directive|define
name|APR_STATUS_IS_EABOVEROOT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EABOVEROOT)
comment|/** The given path was bad. */
define|#
directive|define
name|APR_STATUS_IS_EBADPATH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADPATH)
comment|/** The given path contained wildcards. */
define|#
directive|define
name|APR_STATUS_IS_EPATHWILD
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPATHWILD)
comment|/** Could not find the requested symbol.  * For more information call apr_dso_error().  */
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
define|#
directive|define
name|APR_STATUS_IS_ESYMNOTFOUND
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESYMNOTFOUND \                        || APR_TO_OS_ERROR(s) == ERROR_PROC_NOT_FOUND)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_ESYMNOTFOUND
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESYMNOTFOUND)
endif|#
directive|endif
comment|/** The given process was not recognized by APR. */
define|#
directive|define
name|APR_STATUS_IS_EPROC_UNKNOWN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPROC_UNKNOWN)
comment|/** APR could not gather enough entropy to continue. */
define|#
directive|define
name|APR_STATUS_IS_ENOTENOUGHENTROPY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTENOUGHENTROPY)
comment|/** @} */
comment|/**  * @addtogroup APR_Error  * @{  */
comment|/** @see APR_STATUS_IS_INCHILD */
define|#
directive|define
name|APR_INCHILD
value|(APR_OS_START_STATUS + 1)
comment|/** @see APR_STATUS_IS_INPARENT */
define|#
directive|define
name|APR_INPARENT
value|(APR_OS_START_STATUS + 2)
comment|/** @see APR_STATUS_IS_DETACH */
define|#
directive|define
name|APR_DETACH
value|(APR_OS_START_STATUS + 3)
comment|/** @see APR_STATUS_IS_NOTDETACH */
define|#
directive|define
name|APR_NOTDETACH
value|(APR_OS_START_STATUS + 4)
comment|/** @see APR_STATUS_IS_CHILD_DONE */
define|#
directive|define
name|APR_CHILD_DONE
value|(APR_OS_START_STATUS + 5)
comment|/** @see APR_STATUS_IS_CHILD_NOTDONE */
define|#
directive|define
name|APR_CHILD_NOTDONE
value|(APR_OS_START_STATUS + 6)
comment|/** @see APR_STATUS_IS_TIMEUP */
define|#
directive|define
name|APR_TIMEUP
value|(APR_OS_START_STATUS + 7)
comment|/** @see APR_STATUS_IS_INCOMPLETE */
define|#
directive|define
name|APR_INCOMPLETE
value|(APR_OS_START_STATUS + 8)
comment|/* empty slot: +9 */
comment|/* empty slot: +10 */
comment|/* empty slot: +11 */
comment|/** @see APR_STATUS_IS_BADCH */
define|#
directive|define
name|APR_BADCH
value|(APR_OS_START_STATUS + 12)
comment|/** @see APR_STATUS_IS_BADARG */
define|#
directive|define
name|APR_BADARG
value|(APR_OS_START_STATUS + 13)
comment|/** @see APR_STATUS_IS_EOF */
define|#
directive|define
name|APR_EOF
value|(APR_OS_START_STATUS + 14)
comment|/** @see APR_STATUS_IS_NOTFOUND */
define|#
directive|define
name|APR_NOTFOUND
value|(APR_OS_START_STATUS + 15)
comment|/* empty slot: +16 */
comment|/* empty slot: +17 */
comment|/* empty slot: +18 */
comment|/** @see APR_STATUS_IS_ANONYMOUS */
define|#
directive|define
name|APR_ANONYMOUS
value|(APR_OS_START_STATUS + 19)
comment|/** @see APR_STATUS_IS_FILEBASED */
define|#
directive|define
name|APR_FILEBASED
value|(APR_OS_START_STATUS + 20)
comment|/** @see APR_STATUS_IS_KEYBASED */
define|#
directive|define
name|APR_KEYBASED
value|(APR_OS_START_STATUS + 21)
comment|/** @see APR_STATUS_IS_EINIT */
define|#
directive|define
name|APR_EINIT
value|(APR_OS_START_STATUS + 22)
comment|/** @see APR_STATUS_IS_ENOTIMPL */
define|#
directive|define
name|APR_ENOTIMPL
value|(APR_OS_START_STATUS + 23)
comment|/** @see APR_STATUS_IS_EMISMATCH */
define|#
directive|define
name|APR_EMISMATCH
value|(APR_OS_START_STATUS + 24)
comment|/** @see APR_STATUS_IS_EBUSY */
define|#
directive|define
name|APR_EBUSY
value|(APR_OS_START_STATUS + 25)
comment|/** @} */
comment|/**  * @addtogroup APR_STATUS_IS  * @{  */
comment|/**  * Program is currently executing in the child  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code */
define|#
directive|define
name|APR_STATUS_IS_INCHILD
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_INCHILD)
comment|/**  * Program is currently executing in the parent  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_INPARENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_INPARENT)
comment|/**  * The thread is detached  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_DETACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_DETACH)
comment|/**  * The thread is not detached  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_NOTDETACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_NOTDETACH)
comment|/**  * The child has finished executing  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_CHILD_DONE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_CHILD_DONE)
comment|/**  * The child has not finished executing  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_CHILD_NOTDONE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_CHILD_NOTDONE)
comment|/**  * The operation did not finish before the timeout  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_TIMEUP
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_TIMEUP)
comment|/**  * The operation was incomplete although some processing was performed  * and the results are partially valid.  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_INCOMPLETE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_INCOMPLETE)
comment|/* empty slot: +9 */
comment|/* empty slot: +10 */
comment|/* empty slot: +11 */
comment|/**  * Getopt found an option not in the option string  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_BADCH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_BADCH)
comment|/**  * Getopt found an option not in the option string and an argument was  * specified in the option string  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_BADARG
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_BADARG)
comment|/**  * APR has encountered the end of the file  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_EOF
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EOF)
comment|/**  * APR was unable to find the socket in the poll structure  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_NOTFOUND
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_NOTFOUND)
comment|/* empty slot: +16 */
comment|/* empty slot: +17 */
comment|/* empty slot: +18 */
comment|/**  * APR is using anonymous shared memory  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_ANONYMOUS
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ANONYMOUS)
comment|/**  * APR is using a file name as the key to the shared memory  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_FILEBASED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_FILEBASED)
comment|/**  * APR is using a shared key as the key to the shared memory  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_KEYBASED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_KEYBASED)
comment|/**  * Ininitalizer value.  If no option has been found, but  * the status variable requires a value, this should be used  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_EINIT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINIT)
comment|/**  * The APR function has not been implemented on this  * platform, either because nobody has gotten to it yet,  * or the function is impossible on this platform.  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_ENOTIMPL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTIMPL)
comment|/**  * Two passwords do not match.  * @warning  * always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_EMISMATCH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EMISMATCH)
comment|/**  * The given lock was busy  * @warning always use this test, as platform-specific variances may meet this  * more than one error code  */
define|#
directive|define
name|APR_STATUS_IS_EBUSY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBUSY)
comment|/** @} */
comment|/**  * @addtogroup APR_Error APR Error Values  * @{  */
comment|/* APR CANONICAL ERROR VALUES */
comment|/** @see APR_STATUS_IS_EACCES */
ifdef|#
directive|ifdef
name|EACCES
define|#
directive|define
name|APR_EACCES
value|EACCES
else|#
directive|else
define|#
directive|define
name|APR_EACCES
value|(APR_OS_START_CANONERR + 1)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EEXIST */
ifdef|#
directive|ifdef
name|EEXIST
define|#
directive|define
name|APR_EEXIST
value|EEXIST
else|#
directive|else
define|#
directive|define
name|APR_EEXIST
value|(APR_OS_START_CANONERR + 2)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENAMETOOLONG */
ifdef|#
directive|ifdef
name|ENAMETOOLONG
define|#
directive|define
name|APR_ENAMETOOLONG
value|ENAMETOOLONG
else|#
directive|else
define|#
directive|define
name|APR_ENAMETOOLONG
value|(APR_OS_START_CANONERR + 3)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOENT */
ifdef|#
directive|ifdef
name|ENOENT
define|#
directive|define
name|APR_ENOENT
value|ENOENT
else|#
directive|else
define|#
directive|define
name|APR_ENOENT
value|(APR_OS_START_CANONERR + 4)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOTDIR */
ifdef|#
directive|ifdef
name|ENOTDIR
define|#
directive|define
name|APR_ENOTDIR
value|ENOTDIR
else|#
directive|else
define|#
directive|define
name|APR_ENOTDIR
value|(APR_OS_START_CANONERR + 5)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOSPC */
ifdef|#
directive|ifdef
name|ENOSPC
define|#
directive|define
name|APR_ENOSPC
value|ENOSPC
else|#
directive|else
define|#
directive|define
name|APR_ENOSPC
value|(APR_OS_START_CANONERR + 6)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOMEM */
ifdef|#
directive|ifdef
name|ENOMEM
define|#
directive|define
name|APR_ENOMEM
value|ENOMEM
else|#
directive|else
define|#
directive|define
name|APR_ENOMEM
value|(APR_OS_START_CANONERR + 7)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EMFILE */
ifdef|#
directive|ifdef
name|EMFILE
define|#
directive|define
name|APR_EMFILE
value|EMFILE
else|#
directive|else
define|#
directive|define
name|APR_EMFILE
value|(APR_OS_START_CANONERR + 8)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENFILE */
ifdef|#
directive|ifdef
name|ENFILE
define|#
directive|define
name|APR_ENFILE
value|ENFILE
else|#
directive|else
define|#
directive|define
name|APR_ENFILE
value|(APR_OS_START_CANONERR + 9)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EBADF */
ifdef|#
directive|ifdef
name|EBADF
define|#
directive|define
name|APR_EBADF
value|EBADF
else|#
directive|else
define|#
directive|define
name|APR_EBADF
value|(APR_OS_START_CANONERR + 10)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EINVAL */
ifdef|#
directive|ifdef
name|EINVAL
define|#
directive|define
name|APR_EINVAL
value|EINVAL
else|#
directive|else
define|#
directive|define
name|APR_EINVAL
value|(APR_OS_START_CANONERR + 11)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ESPIPE */
ifdef|#
directive|ifdef
name|ESPIPE
define|#
directive|define
name|APR_ESPIPE
value|ESPIPE
else|#
directive|else
define|#
directive|define
name|APR_ESPIPE
value|(APR_OS_START_CANONERR + 12)
endif|#
directive|endif
comment|/**  * @see APR_STATUS_IS_EAGAIN  * @warning use APR_STATUS_IS_EAGAIN instead of just testing this value  */
ifdef|#
directive|ifdef
name|EAGAIN
define|#
directive|define
name|APR_EAGAIN
value|EAGAIN
elif|#
directive|elif
name|defined
argument_list|(
name|EWOULDBLOCK
argument_list|)
define|#
directive|define
name|APR_EAGAIN
value|EWOULDBLOCK
else|#
directive|else
define|#
directive|define
name|APR_EAGAIN
value|(APR_OS_START_CANONERR + 13)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EINTR */
ifdef|#
directive|ifdef
name|EINTR
define|#
directive|define
name|APR_EINTR
value|EINTR
else|#
directive|else
define|#
directive|define
name|APR_EINTR
value|(APR_OS_START_CANONERR + 14)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOTSOCK */
ifdef|#
directive|ifdef
name|ENOTSOCK
define|#
directive|define
name|APR_ENOTSOCK
value|ENOTSOCK
else|#
directive|else
define|#
directive|define
name|APR_ENOTSOCK
value|(APR_OS_START_CANONERR + 15)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ECONNREFUSED */
ifdef|#
directive|ifdef
name|ECONNREFUSED
define|#
directive|define
name|APR_ECONNREFUSED
value|ECONNREFUSED
else|#
directive|else
define|#
directive|define
name|APR_ECONNREFUSED
value|(APR_OS_START_CANONERR + 16)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EINPROGRESS */
ifdef|#
directive|ifdef
name|EINPROGRESS
define|#
directive|define
name|APR_EINPROGRESS
value|EINPROGRESS
else|#
directive|else
define|#
directive|define
name|APR_EINPROGRESS
value|(APR_OS_START_CANONERR + 17)
endif|#
directive|endif
comment|/**  * @see APR_STATUS_IS_ECONNABORTED  * @warning use APR_STATUS_IS_ECONNABORTED instead of just testing this value  */
ifdef|#
directive|ifdef
name|ECONNABORTED
define|#
directive|define
name|APR_ECONNABORTED
value|ECONNABORTED
else|#
directive|else
define|#
directive|define
name|APR_ECONNABORTED
value|(APR_OS_START_CANONERR + 18)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ECONNRESET */
ifdef|#
directive|ifdef
name|ECONNRESET
define|#
directive|define
name|APR_ECONNRESET
value|ECONNRESET
else|#
directive|else
define|#
directive|define
name|APR_ECONNRESET
value|(APR_OS_START_CANONERR + 19)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ETIMEDOUT  *  @deprecated */
ifdef|#
directive|ifdef
name|ETIMEDOUT
define|#
directive|define
name|APR_ETIMEDOUT
value|ETIMEDOUT
else|#
directive|else
define|#
directive|define
name|APR_ETIMEDOUT
value|(APR_OS_START_CANONERR + 20)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EHOSTUNREACH */
ifdef|#
directive|ifdef
name|EHOSTUNREACH
define|#
directive|define
name|APR_EHOSTUNREACH
value|EHOSTUNREACH
else|#
directive|else
define|#
directive|define
name|APR_EHOSTUNREACH
value|(APR_OS_START_CANONERR + 21)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENETUNREACH */
ifdef|#
directive|ifdef
name|ENETUNREACH
define|#
directive|define
name|APR_ENETUNREACH
value|ENETUNREACH
else|#
directive|else
define|#
directive|define
name|APR_ENETUNREACH
value|(APR_OS_START_CANONERR + 22)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EFTYPE */
ifdef|#
directive|ifdef
name|EFTYPE
define|#
directive|define
name|APR_EFTYPE
value|EFTYPE
else|#
directive|else
define|#
directive|define
name|APR_EFTYPE
value|(APR_OS_START_CANONERR + 23)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EPIPE */
ifdef|#
directive|ifdef
name|EPIPE
define|#
directive|define
name|APR_EPIPE
value|EPIPE
else|#
directive|else
define|#
directive|define
name|APR_EPIPE
value|(APR_OS_START_CANONERR + 24)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EXDEV */
ifdef|#
directive|ifdef
name|EXDEV
define|#
directive|define
name|APR_EXDEV
value|EXDEV
else|#
directive|else
define|#
directive|define
name|APR_EXDEV
value|(APR_OS_START_CANONERR + 25)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_ENOTEMPTY */
ifdef|#
directive|ifdef
name|ENOTEMPTY
define|#
directive|define
name|APR_ENOTEMPTY
value|ENOTEMPTY
else|#
directive|else
define|#
directive|define
name|APR_ENOTEMPTY
value|(APR_OS_START_CANONERR + 26)
endif|#
directive|endif
comment|/** @see APR_STATUS_IS_EAFNOSUPPORT */
ifdef|#
directive|ifdef
name|EAFNOSUPPORT
define|#
directive|define
name|APR_EAFNOSUPPORT
value|EAFNOSUPPORT
else|#
directive|else
define|#
directive|define
name|APR_EAFNOSUPPORT
value|(APR_OS_START_CANONERR + 27)
endif|#
directive|endif
comment|/** @} */
if|#
directive|if
name|defined
argument_list|(
name|OS2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
define|#
directive|define
name|APR_FROM_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e + APR_OS_START_SYSERR)
define|#
directive|define
name|APR_TO_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e - APR_OS_START_SYSERR)
define|#
directive|define
name|INCL_DOSERRORS
define|#
directive|define
name|INCL_DOS
comment|/* Leave these undefined.  * OS2 doesn't rely on the errno concept.  * The API calls always return a result codes which  * should be filtered through APR_FROM_OS_ERROR().  *  * #define apr_get_os_error()   (APR_FROM_OS_ERROR(GetLastError()))  * #define apr_set_os_error(e)  (SetLastError(APR_TO_OS_ERROR(e)))  */
comment|/* A special case, only socket calls require this;  */
define|#
directive|define
name|apr_get_netos_error
parameter_list|()
value|(APR_FROM_OS_ERROR(errno))
define|#
directive|define
name|apr_set_netos_error
parameter_list|(
name|e
parameter_list|)
value|(errno = APR_TO_OS_ERROR(e))
comment|/* And this needs to be greped away for good:  */
define|#
directive|define
name|APR_OS2_STATUS
parameter_list|(
name|e
parameter_list|)
value|(APR_FROM_OS_ERROR(e))
comment|/* These can't sit in a private header, so in spite of the extra size,  * they need to be made available here.  */
define|#
directive|define
name|SOCBASEERR
value|10000
define|#
directive|define
name|SOCEPERM
value|(SOCBASEERR+1)
comment|/* Not owner */
define|#
directive|define
name|SOCESRCH
value|(SOCBASEERR+3)
comment|/* No such process */
define|#
directive|define
name|SOCEINTR
value|(SOCBASEERR+4)
comment|/* Interrupted system call */
define|#
directive|define
name|SOCENXIO
value|(SOCBASEERR+6)
comment|/* No such device or address */
define|#
directive|define
name|SOCEBADF
value|(SOCBASEERR+9)
comment|/* Bad file number */
define|#
directive|define
name|SOCEACCES
value|(SOCBASEERR+13)
comment|/* Permission denied */
define|#
directive|define
name|SOCEFAULT
value|(SOCBASEERR+14)
comment|/* Bad address */
define|#
directive|define
name|SOCEINVAL
value|(SOCBASEERR+22)
comment|/* Invalid argument */
define|#
directive|define
name|SOCEMFILE
value|(SOCBASEERR+24)
comment|/* Too many open files */
define|#
directive|define
name|SOCEPIPE
value|(SOCBASEERR+32)
comment|/* Broken pipe */
define|#
directive|define
name|SOCEOS2ERR
value|(SOCBASEERR+100)
comment|/* OS/2 Error */
define|#
directive|define
name|SOCEWOULDBLOCK
value|(SOCBASEERR+35)
comment|/* Operation would block */
define|#
directive|define
name|SOCEINPROGRESS
value|(SOCBASEERR+36)
comment|/* Operation now in progress */
define|#
directive|define
name|SOCEALREADY
value|(SOCBASEERR+37)
comment|/* Operation already in progress */
define|#
directive|define
name|SOCENOTSOCK
value|(SOCBASEERR+38)
comment|/* Socket operation on non-socket */
define|#
directive|define
name|SOCEDESTADDRREQ
value|(SOCBASEERR+39)
comment|/* Destination address required */
define|#
directive|define
name|SOCEMSGSIZE
value|(SOCBASEERR+40)
comment|/* Message too long */
define|#
directive|define
name|SOCEPROTOTYPE
value|(SOCBASEERR+41)
comment|/* Protocol wrong type for socket */
define|#
directive|define
name|SOCENOPROTOOPT
value|(SOCBASEERR+42)
comment|/* Protocol not available */
define|#
directive|define
name|SOCEPROTONOSUPPORT
value|(SOCBASEERR+43)
comment|/* Protocol not supported */
define|#
directive|define
name|SOCESOCKTNOSUPPORT
value|(SOCBASEERR+44)
comment|/* Socket type not supported */
define|#
directive|define
name|SOCEOPNOTSUPP
value|(SOCBASEERR+45)
comment|/* Operation not supported on socket */
define|#
directive|define
name|SOCEPFNOSUPPORT
value|(SOCBASEERR+46)
comment|/* Protocol family not supported */
define|#
directive|define
name|SOCEAFNOSUPPORT
value|(SOCBASEERR+47)
comment|/* Address family not supported by protocol family */
define|#
directive|define
name|SOCEADDRINUSE
value|(SOCBASEERR+48)
comment|/* Address already in use */
define|#
directive|define
name|SOCEADDRNOTAVAIL
value|(SOCBASEERR+49)
comment|/* Can't assign requested address */
define|#
directive|define
name|SOCENETDOWN
value|(SOCBASEERR+50)
comment|/* Network is down */
define|#
directive|define
name|SOCENETUNREACH
value|(SOCBASEERR+51)
comment|/* Network is unreachable */
define|#
directive|define
name|SOCENETRESET
value|(SOCBASEERR+52)
comment|/* Network dropped connection on reset */
define|#
directive|define
name|SOCECONNABORTED
value|(SOCBASEERR+53)
comment|/* Software caused connection abort */
define|#
directive|define
name|SOCECONNRESET
value|(SOCBASEERR+54)
comment|/* Connection reset by peer */
define|#
directive|define
name|SOCENOBUFS
value|(SOCBASEERR+55)
comment|/* No buffer space available */
define|#
directive|define
name|SOCEISCONN
value|(SOCBASEERR+56)
comment|/* Socket is already connected */
define|#
directive|define
name|SOCENOTCONN
value|(SOCBASEERR+57)
comment|/* Socket is not connected */
define|#
directive|define
name|SOCESHUTDOWN
value|(SOCBASEERR+58)
comment|/* Can't send after socket shutdown */
define|#
directive|define
name|SOCETOOMANYREFS
value|(SOCBASEERR+59)
comment|/* Too many references: can't splice */
define|#
directive|define
name|SOCETIMEDOUT
value|(SOCBASEERR+60)
comment|/* Connection timed out */
define|#
directive|define
name|SOCECONNREFUSED
value|(SOCBASEERR+61)
comment|/* Connection refused */
define|#
directive|define
name|SOCELOOP
value|(SOCBASEERR+62)
comment|/* Too many levels of symbolic links */
define|#
directive|define
name|SOCENAMETOOLONG
value|(SOCBASEERR+63)
comment|/* File name too long */
define|#
directive|define
name|SOCEHOSTDOWN
value|(SOCBASEERR+64)
comment|/* Host is down */
define|#
directive|define
name|SOCEHOSTUNREACH
value|(SOCBASEERR+65)
comment|/* No route to host */
define|#
directive|define
name|SOCENOTEMPTY
value|(SOCBASEERR+66)
comment|/* Directory not empty */
comment|/* APR CANONICAL ERROR TESTS */
define|#
directive|define
name|APR_STATUS_IS_EACCES
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EACCES \                 || (s) == APR_OS_START_SYSERR + ERROR_ACCESS_DENIED \                 || (s) == APR_OS_START_SYSERR + ERROR_SHARING_VIOLATION)
define|#
directive|define
name|APR_STATUS_IS_EEXIST
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EEXIST \                 || (s) == APR_OS_START_SYSERR + ERROR_OPEN_FAILED \                 || (s) == APR_OS_START_SYSERR + ERROR_FILE_EXISTS \                 || (s) == APR_OS_START_SYSERR + ERROR_ALREADY_EXISTS \                 || (s) == APR_OS_START_SYSERR + ERROR_ACCESS_DENIED)
define|#
directive|define
name|APR_STATUS_IS_ENAMETOOLONG
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENAMETOOLONG \                 || (s) == APR_OS_START_SYSERR + ERROR_FILENAME_EXCED_RANGE \                 || (s) == APR_OS_START_SYSERR + SOCENAMETOOLONG)
define|#
directive|define
name|APR_STATUS_IS_ENOENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENT \                 || (s) == APR_OS_START_SYSERR + ERROR_FILE_NOT_FOUND \                 || (s) == APR_OS_START_SYSERR + ERROR_PATH_NOT_FOUND \                 || (s) == APR_OS_START_SYSERR + ERROR_NO_MORE_FILES \                 || (s) == APR_OS_START_SYSERR + ERROR_OPEN_FAILED)
define|#
directive|define
name|APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTDIR)
define|#
directive|define
name|APR_STATUS_IS_ENOSPC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPC \                 || (s) == APR_OS_START_SYSERR + ERROR_DISK_FULL)
define|#
directive|define
name|APR_STATUS_IS_ENOMEM
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOMEM)
define|#
directive|define
name|APR_STATUS_IS_EMFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EMFILE \                 || (s) == APR_OS_START_SYSERR + ERROR_TOO_MANY_OPEN_FILES)
define|#
directive|define
name|APR_STATUS_IS_ENFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENFILE)
define|#
directive|define
name|APR_STATUS_IS_EBADF
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADF \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_HANDLE)
define|#
directive|define
name|APR_STATUS_IS_EINVAL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINVAL \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_PARAMETER \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_FUNCTION)
define|#
directive|define
name|APR_STATUS_IS_ESPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESPIPE \                 || (s) == APR_OS_START_SYSERR + ERROR_NEGATIVE_SEEK)
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN \                 || (s) == APR_OS_START_SYSERR + ERROR_NO_DATA \                 || (s) == APR_OS_START_SYSERR + SOCEWOULDBLOCK \                 || (s) == APR_OS_START_SYSERR + ERROR_LOCK_VIOLATION)
define|#
directive|define
name|APR_STATUS_IS_EINTR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINTR \                 || (s) == APR_OS_START_SYSERR + SOCEINTR)
define|#
directive|define
name|APR_STATUS_IS_ENOTSOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTSOCK \                 || (s) == APR_OS_START_SYSERR + SOCENOTSOCK)
define|#
directive|define
name|APR_STATUS_IS_ECONNREFUSED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNREFUSED \                 || (s) == APR_OS_START_SYSERR + SOCECONNREFUSED)
define|#
directive|define
name|APR_STATUS_IS_EINPROGRESS
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINPROGRESS \                 || (s) == APR_OS_START_SYSERR + SOCEINPROGRESS)
define|#
directive|define
name|APR_STATUS_IS_ECONNABORTED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNABORTED \                 || (s) == APR_OS_START_SYSERR + SOCECONNABORTED)
define|#
directive|define
name|APR_STATUS_IS_ECONNRESET
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNRESET \                 || (s) == APR_OS_START_SYSERR + SOCECONNRESET)
comment|/* XXX deprecated */
define|#
directive|define
name|APR_STATUS_IS_ETIMEDOUT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + SOCETIMEDOUT)
undef|#
directive|undef
name|APR_STATUS_IS_TIMEUP
define|#
directive|define
name|APR_STATUS_IS_TIMEUP
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_TIMEUP \                 || (s) == APR_OS_START_SYSERR + SOCETIMEDOUT)
define|#
directive|define
name|APR_STATUS_IS_EHOSTUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EHOSTUNREACH \                 || (s) == APR_OS_START_SYSERR + SOCEHOSTUNREACH)
define|#
directive|define
name|APR_STATUS_IS_ENETUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENETUNREACH \                 || (s) == APR_OS_START_SYSERR + SOCENETUNREACH)
define|#
directive|define
name|APR_STATUS_IS_EFTYPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EFTYPE)
define|#
directive|define
name|APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPIPE \                 || (s) == APR_OS_START_SYSERR + ERROR_BROKEN_PIPE \                 || (s) == APR_OS_START_SYSERR + SOCEPIPE)
define|#
directive|define
name|APR_STATUS_IS_EXDEV
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EXDEV \                 || (s) == APR_OS_START_SYSERR + ERROR_NOT_SAME_DEVICE)
define|#
directive|define
name|APR_STATUS_IS_ENOTEMPTY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTEMPTY \                 || (s) == APR_OS_START_SYSERR + ERROR_DIR_NOT_EMPTY \                 || (s) == APR_OS_START_SYSERR + ERROR_ACCESS_DENIED)
define|#
directive|define
name|APR_STATUS_IS_EAFNOSUPPORT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_AFNOSUPPORT \                 || (s) == APR_OS_START_SYSERR + SOCEAFNOSUPPORT)
comment|/*     Sorry, too tired to wrap this up for OS2... feel free to     fit the following into their best matches.      { ERROR_NO_SIGNAL_SENT,     ESRCH           },     { SOCEALREADY,              EALREADY        },     { SOCEDESTADDRREQ,          EDESTADDRREQ    },     { SOCEMSGSIZE,              EMSGSIZE        },     { SOCEPROTOTYPE,            EPROTOTYPE      },     { SOCENOPROTOOPT,           ENOPROTOOPT     },     { SOCEPROTONOSUPPORT,       EPROTONOSUPPORT },     { SOCESOCKTNOSUPPORT,       ESOCKTNOSUPPORT },     { SOCEOPNOTSUPP,            EOPNOTSUPP      },     { SOCEPFNOSUPPORT,          EPFNOSUPPORT    },     { SOCEADDRINUSE,            EADDRINUSE      },     { SOCEADDRNOTAVAIL,         EADDRNOTAVAIL   },     { SOCENETDOWN,              ENETDOWN        },     { SOCENETRESET,             ENETRESET       },     { SOCENOBUFS,               ENOBUFS         },     { SOCEISCONN,               EISCONN         },     { SOCENOTCONN,              ENOTCONN        },     { SOCESHUTDOWN,             ESHUTDOWN       },     { SOCETOOMANYREFS,          ETOOMANYREFS    },     { SOCELOOP,                 ELOOP           },     { SOCEHOSTDOWN,             EHOSTDOWN       },     { SOCENOTEMPTY,             ENOTEMPTY       },     { SOCEPIPE,                 EPIPE           } */
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/* !defined(OS2) */
define|#
directive|define
name|APR_FROM_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e + APR_OS_START_SYSERR)
define|#
directive|define
name|APR_TO_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e - APR_OS_START_SYSERR)
define|#
directive|define
name|apr_get_os_error
parameter_list|()
value|(APR_FROM_OS_ERROR(GetLastError()))
define|#
directive|define
name|apr_set_os_error
parameter_list|(
name|e
parameter_list|)
value|(SetLastError(APR_TO_OS_ERROR(e)))
comment|/* A special case, only socket calls require this:  */
define|#
directive|define
name|apr_get_netos_error
parameter_list|()
value|(APR_FROM_OS_ERROR(WSAGetLastError()))
define|#
directive|define
name|apr_set_netos_error
parameter_list|(
name|e
parameter_list|)
value|(WSASetLastError(APR_TO_OS_ERROR(e)))
comment|/* APR CANONICAL ERROR TESTS */
define|#
directive|define
name|APR_STATUS_IS_EACCES
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EACCES \                 || (s) == APR_OS_START_SYSERR + ERROR_ACCESS_DENIED \                 || (s) == APR_OS_START_SYSERR + ERROR_CANNOT_MAKE \                 || (s) == APR_OS_START_SYSERR + ERROR_CURRENT_DIRECTORY \                 || (s) == APR_OS_START_SYSERR + ERROR_DRIVE_LOCKED \                 || (s) == APR_OS_START_SYSERR + ERROR_FAIL_I24 \                 || (s) == APR_OS_START_SYSERR + ERROR_LOCK_VIOLATION \                 || (s) == APR_OS_START_SYSERR + ERROR_LOCK_FAILED \                 || (s) == APR_OS_START_SYSERR + ERROR_NOT_LOCKED \                 || (s) == APR_OS_START_SYSERR + ERROR_NETWORK_ACCESS_DENIED \                 || (s) == APR_OS_START_SYSERR + ERROR_SHARING_VIOLATION)
define|#
directive|define
name|APR_STATUS_IS_EEXIST
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EEXIST \                 || (s) == APR_OS_START_SYSERR + ERROR_FILE_EXISTS \                 || (s) == APR_OS_START_SYSERR + ERROR_ALREADY_EXISTS)
define|#
directive|define
name|APR_STATUS_IS_ENAMETOOLONG
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENAMETOOLONG \                 || (s) == APR_OS_START_SYSERR + ERROR_FILENAME_EXCED_RANGE \                 || (s) == APR_OS_START_SYSERR + WSAENAMETOOLONG)
define|#
directive|define
name|APR_STATUS_IS_ENOENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENT \                 || (s) == APR_OS_START_SYSERR + ERROR_FILE_NOT_FOUND \                 || (s) == APR_OS_START_SYSERR + ERROR_PATH_NOT_FOUND \                 || (s) == APR_OS_START_SYSERR + ERROR_OPEN_FAILED \                 || (s) == APR_OS_START_SYSERR + ERROR_NO_MORE_FILES)
define|#
directive|define
name|APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTDIR \                 || (s) == APR_OS_START_SYSERR + ERROR_PATH_NOT_FOUND \                 || (s) == APR_OS_START_SYSERR + ERROR_BAD_NETPATH \                 || (s) == APR_OS_START_SYSERR + ERROR_BAD_NET_NAME \                 || (s) == APR_OS_START_SYSERR + ERROR_BAD_PATHNAME \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_DRIVE \                 || (s) == APR_OS_START_SYSERR + ERROR_DIRECTORY)
define|#
directive|define
name|APR_STATUS_IS_ENOSPC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPC \                 || (s) == APR_OS_START_SYSERR + ERROR_DISK_FULL)
define|#
directive|define
name|APR_STATUS_IS_ENOMEM
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOMEM \                 || (s) == APR_OS_START_SYSERR + ERROR_ARENA_TRASHED \                 || (s) == APR_OS_START_SYSERR + ERROR_NOT_ENOUGH_MEMORY \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_BLOCK \                 || (s) == APR_OS_START_SYSERR + ERROR_NOT_ENOUGH_QUOTA \                 || (s) == APR_OS_START_SYSERR + ERROR_OUTOFMEMORY)
define|#
directive|define
name|APR_STATUS_IS_EMFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EMFILE \                 || (s) == APR_OS_START_SYSERR + ERROR_TOO_MANY_OPEN_FILES)
define|#
directive|define
name|APR_STATUS_IS_ENFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENFILE)
define|#
directive|define
name|APR_STATUS_IS_EBADF
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADF \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_HANDLE \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_TARGET_HANDLE)
define|#
directive|define
name|APR_STATUS_IS_EINVAL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINVAL \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_ACCESS \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_DATA \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_FUNCTION \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_HANDLE \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_PARAMETER \                 || (s) == APR_OS_START_SYSERR + ERROR_NEGATIVE_SEEK)
define|#
directive|define
name|APR_STATUS_IS_ESPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESPIPE \                 || (s) == APR_OS_START_SYSERR + ERROR_SEEK_ON_DEVICE \                 || (s) == APR_OS_START_SYSERR + ERROR_NEGATIVE_SEEK)
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN \                 || (s) == APR_OS_START_SYSERR + ERROR_NO_DATA \                 || (s) == APR_OS_START_SYSERR + ERROR_NO_PROC_SLOTS \                 || (s) == APR_OS_START_SYSERR + ERROR_NESTING_NOT_ALLOWED \                 || (s) == APR_OS_START_SYSERR + ERROR_MAX_THRDS_REACHED \                 || (s) == APR_OS_START_SYSERR + ERROR_LOCK_VIOLATION \                 || (s) == APR_OS_START_SYSERR + WSAEWOULDBLOCK)
define|#
directive|define
name|APR_STATUS_IS_EINTR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINTR \                 || (s) == APR_OS_START_SYSERR + WSAEINTR)
define|#
directive|define
name|APR_STATUS_IS_ENOTSOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTSOCK \                 || (s) == APR_OS_START_SYSERR + WSAENOTSOCK)
define|#
directive|define
name|APR_STATUS_IS_ECONNREFUSED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNREFUSED \                 || (s) == APR_OS_START_SYSERR + WSAECONNREFUSED)
define|#
directive|define
name|APR_STATUS_IS_EINPROGRESS
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINPROGRESS \                 || (s) == APR_OS_START_SYSERR + WSAEINPROGRESS)
define|#
directive|define
name|APR_STATUS_IS_ECONNABORTED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNABORTED \                 || (s) == APR_OS_START_SYSERR + WSAECONNABORTED)
define|#
directive|define
name|APR_STATUS_IS_ECONNRESET
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNRESET \                 || (s) == APR_OS_START_SYSERR + ERROR_NETNAME_DELETED \                 || (s) == APR_OS_START_SYSERR + WSAECONNRESET)
comment|/* XXX deprecated */
define|#
directive|define
name|APR_STATUS_IS_ETIMEDOUT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WSAETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WAIT_TIMEOUT)
undef|#
directive|undef
name|APR_STATUS_IS_TIMEUP
define|#
directive|define
name|APR_STATUS_IS_TIMEUP
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_TIMEUP \                 || (s) == APR_OS_START_SYSERR + WSAETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WAIT_TIMEOUT)
define|#
directive|define
name|APR_STATUS_IS_EHOSTUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EHOSTUNREACH \                 || (s) == APR_OS_START_SYSERR + WSAEHOSTUNREACH)
define|#
directive|define
name|APR_STATUS_IS_ENETUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENETUNREACH \                 || (s) == APR_OS_START_SYSERR + WSAENETUNREACH)
define|#
directive|define
name|APR_STATUS_IS_EFTYPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EFTYPE \                 || (s) == APR_OS_START_SYSERR + ERROR_EXE_MACHINE_TYPE_MISMATCH \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_DLL \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_MODULETYPE \                 || (s) == APR_OS_START_SYSERR + ERROR_BAD_EXE_FORMAT \                 || (s) == APR_OS_START_SYSERR + ERROR_INVALID_EXE_SIGNATURE \                 || (s) == APR_OS_START_SYSERR + ERROR_FILE_CORRUPT \                 || (s) == APR_OS_START_SYSERR + ERROR_BAD_FORMAT)
define|#
directive|define
name|APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPIPE \                 || (s) == APR_OS_START_SYSERR + ERROR_BROKEN_PIPE)
define|#
directive|define
name|APR_STATUS_IS_EXDEV
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EXDEV \                 || (s) == APR_OS_START_SYSERR + ERROR_NOT_SAME_DEVICE)
define|#
directive|define
name|APR_STATUS_IS_ENOTEMPTY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTEMPTY \                 || (s) == APR_OS_START_SYSERR + ERROR_DIR_NOT_EMPTY)
define|#
directive|define
name|APR_STATUS_IS_EAFNOSUPPORT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAFNOSUPPORT \                 || (s) == APR_OS_START_SYSERR + WSAEAFNOSUPPORT)
elif|#
directive|elif
name|defined
argument_list|(
name|NETWARE
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_WINSOCK
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/* !defined(OS2)&& !defined(WIN32) */
define|#
directive|define
name|APR_FROM_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e + APR_OS_START_SYSERR)
define|#
directive|define
name|APR_TO_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e == 0 ? APR_SUCCESS : e - APR_OS_START_SYSERR)
define|#
directive|define
name|apr_get_os_error
parameter_list|()
value|(errno)
define|#
directive|define
name|apr_set_os_error
parameter_list|(
name|e
parameter_list|)
value|(errno = (e))
comment|/* A special case, only socket calls require this: */
define|#
directive|define
name|apr_get_netos_error
parameter_list|()
value|(APR_FROM_OS_ERROR(WSAGetLastError()))
define|#
directive|define
name|apr_set_netos_error
parameter_list|(
name|e
parameter_list|)
value|(WSASetLastError(APR_TO_OS_ERROR(e)))
comment|/* APR CANONICAL ERROR TESTS */
define|#
directive|define
name|APR_STATUS_IS_EACCES
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EACCES)
define|#
directive|define
name|APR_STATUS_IS_EEXIST
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EEXIST)
define|#
directive|define
name|APR_STATUS_IS_ENAMETOOLONG
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENAMETOOLONG)
define|#
directive|define
name|APR_STATUS_IS_ENOENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENT)
define|#
directive|define
name|APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTDIR)
define|#
directive|define
name|APR_STATUS_IS_ENOSPC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPC)
define|#
directive|define
name|APR_STATUS_IS_ENOMEM
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOMEM)
define|#
directive|define
name|APR_STATUS_IS_EMFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EMFILE)
define|#
directive|define
name|APR_STATUS_IS_ENFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENFILE)
define|#
directive|define
name|APR_STATUS_IS_EBADF
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADF)
define|#
directive|define
name|APR_STATUS_IS_EINVAL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINVAL)
define|#
directive|define
name|APR_STATUS_IS_ESPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESPIPE)
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN \                 || (s) ==                       EWOULDBLOCK \                 || (s) == APR_OS_START_SYSERR + WSAEWOULDBLOCK)
define|#
directive|define
name|APR_STATUS_IS_EINTR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINTR \                 || (s) == APR_OS_START_SYSERR + WSAEINTR)
define|#
directive|define
name|APR_STATUS_IS_ENOTSOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTSOCK \                 || (s) == APR_OS_START_SYSERR + WSAENOTSOCK)
define|#
directive|define
name|APR_STATUS_IS_ECONNREFUSED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNREFUSED \                 || (s) == APR_OS_START_SYSERR + WSAECONNREFUSED)
define|#
directive|define
name|APR_STATUS_IS_EINPROGRESS
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINPROGRESS \                 || (s) == APR_OS_START_SYSERR + WSAEINPROGRESS)
define|#
directive|define
name|APR_STATUS_IS_ECONNABORTED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNABORTED \                 || (s) == APR_OS_START_SYSERR + WSAECONNABORTED)
define|#
directive|define
name|APR_STATUS_IS_ECONNRESET
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNRESET \                 || (s) == APR_OS_START_SYSERR + WSAECONNRESET)
comment|/* XXX deprecated */
define|#
directive|define
name|APR_STATUS_IS_ETIMEDOUT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WSAETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WAIT_TIMEOUT)
undef|#
directive|undef
name|APR_STATUS_IS_TIMEUP
define|#
directive|define
name|APR_STATUS_IS_TIMEUP
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_TIMEUP \                 || (s) == APR_OS_START_SYSERR + WSAETIMEDOUT \                 || (s) == APR_OS_START_SYSERR + WAIT_TIMEOUT)
define|#
directive|define
name|APR_STATUS_IS_EHOSTUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EHOSTUNREACH \                 || (s) == APR_OS_START_SYSERR + WSAEHOSTUNREACH)
define|#
directive|define
name|APR_STATUS_IS_ENETUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENETUNREACH \                 || (s) == APR_OS_START_SYSERR + WSAENETUNREACH)
define|#
directive|define
name|APR_STATUS_IS_ENETDOWN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_OS_START_SYSERR + WSAENETDOWN)
define|#
directive|define
name|APR_STATUS_IS_EFTYPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EFTYPE)
define|#
directive|define
name|APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPIPE)
define|#
directive|define
name|APR_STATUS_IS_EXDEV
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EXDEV)
define|#
directive|define
name|APR_STATUS_IS_ENOTEMPTY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTEMPTY)
define|#
directive|define
name|APR_STATUS_IS_EAFNOSUPPORT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAFNOSUPPORT \                 || (s) == APR_OS_START_SYSERR + WSAEAFNOSUPPORT)
else|#
directive|else
comment|/* !defined(NETWARE)&& !defined(OS2)&& !defined(WIN32) */
comment|/*  *  os error codes are clib error codes  */
define|#
directive|define
name|APR_FROM_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e)
define|#
directive|define
name|APR_TO_OS_ERROR
parameter_list|(
name|e
parameter_list|)
value|(e)
define|#
directive|define
name|apr_get_os_error
parameter_list|()
value|(errno)
define|#
directive|define
name|apr_set_os_error
parameter_list|(
name|e
parameter_list|)
value|(errno = (e))
comment|/* A special case, only socket calls require this:  */
define|#
directive|define
name|apr_get_netos_error
parameter_list|()
value|(errno)
define|#
directive|define
name|apr_set_netos_error
parameter_list|(
name|e
parameter_list|)
value|(errno = (e))
comment|/**  * @addtogroup APR_STATUS_IS  * @{  */
comment|/** permission denied */
define|#
directive|define
name|APR_STATUS_IS_EACCES
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EACCES)
comment|/** file exists */
define|#
directive|define
name|APR_STATUS_IS_EEXIST
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EEXIST)
comment|/** path name is too long */
define|#
directive|define
name|APR_STATUS_IS_ENAMETOOLONG
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENAMETOOLONG)
comment|/**  * no such file or directory  * @remark  * EMVSCATLG can be returned by the automounter on z/OS for  * paths which do not exist.  */
ifdef|#
directive|ifdef
name|EMVSCATLG
define|#
directive|define
name|APR_STATUS_IS_ENOENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENT \                                       || (s) == EMVSCATLG)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_ENOENT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOENT)
endif|#
directive|endif
comment|/** not a directory */
define|#
directive|define
name|APR_STATUS_IS_ENOTDIR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTDIR)
comment|/** no space left on device */
ifdef|#
directive|ifdef
name|EDQUOT
define|#
directive|define
name|APR_STATUS_IS_ENOSPC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPC \                                       || (s) == EDQUOT)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_ENOSPC
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOSPC)
endif|#
directive|endif
comment|/** not enough memory */
define|#
directive|define
name|APR_STATUS_IS_ENOMEM
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOMEM)
comment|/** too many open files */
define|#
directive|define
name|APR_STATUS_IS_EMFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EMFILE)
comment|/** file table overflow */
define|#
directive|define
name|APR_STATUS_IS_ENFILE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENFILE)
comment|/** bad file # */
define|#
directive|define
name|APR_STATUS_IS_EBADF
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EBADF)
comment|/** invalid argument */
define|#
directive|define
name|APR_STATUS_IS_EINVAL
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINVAL)
comment|/** illegal seek */
define|#
directive|define
name|APR_STATUS_IS_ESPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ESPIPE)
comment|/** operation would block */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EWOULDBLOCK
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|EAGAIN
argument_list|)
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN)
elif|#
directive|elif
operator|(
name|EWOULDBLOCK
operator|==
name|EAGAIN
operator|)
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_EAGAIN
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAGAIN \                                       || (s) == EWOULDBLOCK)
endif|#
directive|endif
comment|/** interrupted system call */
define|#
directive|define
name|APR_STATUS_IS_EINTR
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINTR)
comment|/** socket operation on a non-socket */
define|#
directive|define
name|APR_STATUS_IS_ENOTSOCK
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTSOCK)
comment|/** Connection Refused */
define|#
directive|define
name|APR_STATUS_IS_ECONNREFUSED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNREFUSED)
comment|/** operation now in progress */
define|#
directive|define
name|APR_STATUS_IS_EINPROGRESS
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EINPROGRESS)
comment|/**  * Software caused connection abort  * @remark  * EPROTO on certain older kernels really means ECONNABORTED, so we need to  * ignore it for them.  See discussion in new-httpd archives nh.9701& nh.9603  *  * There is potentially a bug in Solaris 2.x x<6, and other boxes that  * implement tcp sockets in userland (i.e. on top of STREAMS).  On these  * systems, EPROTO can actually result in a fatal loop.  See PR#981 for  * example.  It's hard to handle both uses of EPROTO.  */
ifdef|#
directive|ifdef
name|EPROTO
define|#
directive|define
name|APR_STATUS_IS_ECONNABORTED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNABORTED \                                        || (s) == EPROTO)
else|#
directive|else
define|#
directive|define
name|APR_STATUS_IS_ECONNABORTED
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNABORTED)
endif|#
directive|endif
comment|/** Connection Reset by peer */
define|#
directive|define
name|APR_STATUS_IS_ECONNRESET
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ECONNRESET)
comment|/** Operation timed out  *  @deprecated */
define|#
directive|define
name|APR_STATUS_IS_ETIMEDOUT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ETIMEDOUT)
comment|/** no route to host */
define|#
directive|define
name|APR_STATUS_IS_EHOSTUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EHOSTUNREACH)
comment|/** network is unreachable */
define|#
directive|define
name|APR_STATUS_IS_ENETUNREACH
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENETUNREACH)
comment|/** inappropiate file type or format */
define|#
directive|define
name|APR_STATUS_IS_EFTYPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EFTYPE)
comment|/** broken pipe */
define|#
directive|define
name|APR_STATUS_IS_EPIPE
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EPIPE)
comment|/** cross device link */
define|#
directive|define
name|APR_STATUS_IS_EXDEV
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EXDEV)
comment|/** Directory Not Empty */
define|#
directive|define
name|APR_STATUS_IS_ENOTEMPTY
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_ENOTEMPTY || \                                           (s) == APR_EEXIST)
comment|/** Address Family not supported */
define|#
directive|define
name|APR_STATUS_IS_EAFNOSUPPORT
parameter_list|(
name|s
parameter_list|)
value|((s) == APR_EAFNOSUPPORT)
comment|/** @} */
endif|#
directive|endif
comment|/* !defined(NETWARE)&& !defined(OS2)&& !defined(WIN32) */
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
comment|/* ! APR_ERRNO_H */
end_comment

end_unit

