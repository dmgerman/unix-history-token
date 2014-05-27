begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_POLL_H
end_ifndef

begin_define
define|#
directive|define
name|APR_POLL_H
end_define

begin_comment
comment|/**  * @file apr_poll.h  * @brief APR Poll interface  */
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
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_inherit.h"
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

begin_if
if|#
directive|if
name|APR_HAVE_NETINET_IN_H
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
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
comment|/**  * @defgroup apr_poll Poll Routines  * @ingroup APR   * @{  */
comment|/**  * @defgroup pollopts Poll options  * @ingroup apr_poll  * @{  */
define|#
directive|define
name|APR_POLLIN
value|0x001
comment|/**< Can read without blocking */
define|#
directive|define
name|APR_POLLPRI
value|0x002
comment|/**< Priority data available */
define|#
directive|define
name|APR_POLLOUT
value|0x004
comment|/**< Can write without blocking */
define|#
directive|define
name|APR_POLLERR
value|0x010
comment|/**< Pending error */
define|#
directive|define
name|APR_POLLHUP
value|0x020
comment|/**< Hangup occurred */
define|#
directive|define
name|APR_POLLNVAL
value|0x040
comment|/**< Descriptor invalid */
comment|/** @} */
comment|/**  * @defgroup pollflags Pollset Flags  * @ingroup apr_poll  * @{  */
define|#
directive|define
name|APR_POLLSET_THREADSAFE
value|0x001
comment|/**< Adding or removing a descriptor is                                       * thread-safe                                       */
define|#
directive|define
name|APR_POLLSET_NOCOPY
value|0x002
comment|/**< Descriptors passed to apr_pollset_add()                                       * are not copied                                       */
define|#
directive|define
name|APR_POLLSET_WAKEABLE
value|0x004
comment|/**< Poll operations are interruptable by                                       * apr_pollset_wakeup()                                       */
define|#
directive|define
name|APR_POLLSET_NODEFAULT
value|0x010
comment|/**< Do not try to use the default method if                                       * the specified non-default method cannot be                                       * used                                       */
comment|/** @} */
comment|/**  * Pollset Methods  */
typedef|typedef
enum|enum
block|{
name|APR_POLLSET_DEFAULT
block|,
comment|/**< Platform default poll method */
name|APR_POLLSET_SELECT
block|,
comment|/**< Poll uses select method */
name|APR_POLLSET_KQUEUE
block|,
comment|/**< Poll uses kqueue method */
name|APR_POLLSET_PORT
block|,
comment|/**< Poll uses Solaris event port method */
name|APR_POLLSET_EPOLL
block|,
comment|/**< Poll uses epoll method */
name|APR_POLLSET_POLL
block|,
comment|/**< Poll uses poll method */
name|APR_POLLSET_AIO_MSGQ
comment|/**< Poll uses z/OS asio method */
block|}
name|apr_pollset_method_e
typedef|;
comment|/** Used in apr_pollfd_t to determine what the apr_descriptor is */
typedef|typedef
enum|enum
block|{
name|APR_NO_DESC
block|,
comment|/**< nothing here */
name|APR_POLL_SOCKET
block|,
comment|/**< descriptor refers to a socket */
name|APR_POLL_FILE
block|,
comment|/**< descriptor refers to a file */
name|APR_POLL_LASTDESC
comment|/**< @deprecated descriptor is the last one in the list */
block|}
name|apr_datatype_e
typedef|;
comment|/** Union of either an APR file or socket. */
typedef|typedef
union|union
block|{
name|apr_file_t
modifier|*
name|f
decl_stmt|;
comment|/**< file */
name|apr_socket_t
modifier|*
name|s
decl_stmt|;
comment|/**< socket */
block|}
name|apr_descriptor
typedef|;
comment|/** @see apr_pollfd_t */
typedef|typedef
name|struct
name|apr_pollfd_t
name|apr_pollfd_t
typedef|;
comment|/** Poll descriptor set. */
struct|struct
name|apr_pollfd_t
block|{
name|apr_pool_t
modifier|*
name|p
decl_stmt|;
comment|/**< associated pool */
name|apr_datatype_e
name|desc_type
decl_stmt|;
comment|/**< descriptor type */
name|apr_int16_t
name|reqevents
decl_stmt|;
comment|/**< requested events */
name|apr_int16_t
name|rtnevents
decl_stmt|;
comment|/**< returned events */
name|apr_descriptor
name|desc
decl_stmt|;
comment|/**< @see apr_descriptor */
name|void
modifier|*
name|client_data
decl_stmt|;
comment|/**< allows app to associate context */
block|}
struct|;
comment|/* General-purpose poll API for arbitrarily large numbers of  * file descriptors  */
comment|/** Opaque structure used for pollset API */
typedef|typedef
name|struct
name|apr_pollset_t
name|apr_pollset_t
typedef|;
comment|/**  * Set up a pollset object  * @param pollset  The pointer in which to return the newly created object   * @param size The maximum number of descriptors that this pollset can hold  * @param p The pool from which to allocate the pollset  * @param flags Optional flags to modify the operation of the pollset.  *  * @remark If flags contains APR_POLLSET_THREADSAFE, then a pollset is  *         created on which it is safe to make concurrent calls to  *         apr_pollset_add(), apr_pollset_remove() and apr_pollset_poll()  *         from separate threads.  This feature is only supported on some  *         platforms; the apr_pollset_create() call will fail with  *         APR_ENOTIMPL on platforms where it is not supported.  * @remark If flags contains APR_POLLSET_WAKEABLE, then a pollset is  *         created with an additional internal pipe object used for the  *         apr_pollset_wakeup() call. The actual size of pollset is  *         in that case @a size + 1. This feature is only supported on some  *         platforms; the apr_pollset_create() call will fail with  *         APR_ENOTIMPL on platforms where it is not supported.  * @remark If flags contains APR_POLLSET_NOCOPY, then the apr_pollfd_t  *         structures passed to apr_pollset_add() are not copied and  *         must have a lifetime at least as long as the pollset.  * @remark Some poll methods (including APR_POLLSET_KQUEUE,  *         APR_POLLSET_PORT, and APR_POLLSET_EPOLL) do not have a  *         fixed limit on the size of the pollset. For these methods,  *         the size parameter controls the maximum number of  *         descriptors that will be returned by a single call to  *         apr_pollset_poll().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_create
argument_list|(
argument|apr_pollset_t **pollset
argument_list|,
argument|apr_uint32_t size
argument_list|,
argument|apr_pool_t *p
argument_list|,
argument|apr_uint32_t flags
argument_list|)
empty_stmt|;
comment|/**  * Set up a pollset object  * @param pollset  The pointer in which to return the newly created object   * @param size The maximum number of descriptors that this pollset can hold  * @param p The pool from which to allocate the pollset  * @param flags Optional flags to modify the operation of the pollset.  * @param method Poll method to use. See #apr_pollset_method_e.  If this  *         method cannot be used, the default method will be used unless the  *         APR_POLLSET_NODEFAULT flag has been specified.  *  * @remark If flags contains APR_POLLSET_THREADSAFE, then a pollset is  *         created on which it is safe to make concurrent calls to  *         apr_pollset_add(), apr_pollset_remove() and apr_pollset_poll()  *         from separate threads.  This feature is only supported on some  *         platforms; the apr_pollset_create_ex() call will fail with  *         APR_ENOTIMPL on platforms where it is not supported.  * @remark If flags contains APR_POLLSET_WAKEABLE, then a pollset is  *         created with additional internal pipe object used for the  *         apr_pollset_wakeup() call. The actual size of pollset is  *         in that case size + 1. This feature is only supported on some  *         platforms; the apr_pollset_create_ex() call will fail with  *         APR_ENOTIMPL on platforms where it is not supported.  * @remark If flags contains APR_POLLSET_NOCOPY, then the apr_pollfd_t  *         structures passed to apr_pollset_add() are not copied and  *         must have a lifetime at least as long as the pollset.  * @remark Some poll methods (including APR_POLLSET_KQUEUE,  *         APR_POLLSET_PORT, and APR_POLLSET_EPOLL) do not have a  *         fixed limit on the size of the pollset. For these methods,  *         the size parameter controls the maximum number of  *         descriptors that will be returned by a single call to  *         apr_pollset_poll().  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_create_ex
argument_list|(
argument|apr_pollset_t **pollset
argument_list|,
argument|apr_uint32_t size
argument_list|,
argument|apr_pool_t *p
argument_list|,
argument|apr_uint32_t flags
argument_list|,
argument|apr_pollset_method_e method
argument_list|)
empty_stmt|;
comment|/**  * Destroy a pollset object  * @param pollset The pollset to destroy  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_destroy
argument_list|(
name|apr_pollset_t
operator|*
name|pollset
argument_list|)
expr_stmt|;
comment|/**  * Add a socket or file descriptor to a pollset  * @param pollset The pollset to which to add the descriptor  * @param descriptor The descriptor to add  * @remark If you set client_data in the descriptor, that value  *         will be returned in the client_data field whenever this  *         descriptor is signalled in apr_pollset_poll().  * @remark If the pollset has been created with APR_POLLSET_THREADSAFE  *         and thread T1 is blocked in a call to apr_pollset_poll() for  *         this same pollset that is being modified via apr_pollset_add()  *         in thread T2, the currently executing apr_pollset_poll() call in  *         T1 will either: (1) automatically include the newly added descriptor  *         in the set of descriptors it is watching or (2) return immediately  *         with APR_EINTR.  Option (1) is recommended, but option (2) is  *         allowed for implementations where option (1) is impossible  *         or impractical.  * @remark If the pollset has been created with APR_POLLSET_NOCOPY, the   *         apr_pollfd_t structure referenced by descriptor will not be copied  *         and must have a lifetime at least as long as the pollset.  * @remark Do not add the same socket or file descriptor to the same pollset  *         multiple times, even if the requested events differ for the   *         different calls to apr_pollset_add().  If the events of interest  *         for a descriptor change, you must first remove the descriptor   *         from the pollset with apr_pollset_remove(), then add it again   *         specifying all requested events.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_add
argument_list|(
name|apr_pollset_t
operator|*
name|pollset
argument_list|,
specifier|const
name|apr_pollfd_t
operator|*
name|descriptor
argument_list|)
expr_stmt|;
comment|/**  * Remove a descriptor from a pollset  * @param pollset The pollset from which to remove the descriptor  * @param descriptor The descriptor to remove  * @remark If the descriptor is not found, APR_NOTFOUND is returned.  * @remark If the pollset has been created with APR_POLLSET_THREADSAFE  *         and thread T1 is blocked in a call to apr_pollset_poll() for  *         this same pollset that is being modified via apr_pollset_remove()  *         in thread T2, the currently executing apr_pollset_poll() call in  *         T1 will either: (1) automatically exclude the newly added descriptor  *         in the set of descriptors it is watching or (2) return immediately  *         with APR_EINTR.  Option (1) is recommended, but option (2) is  *         allowed for implementations where option (1) is impossible  *         or impractical.  * @remark apr_pollset_remove() cannot be used to remove a subset of requested  *         events for a descriptor.  The reqevents field in the apr_pollfd_t  *         parameter must contain the same value when removing as when adding.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_remove
argument_list|(
name|apr_pollset_t
operator|*
name|pollset
argument_list|,
specifier|const
name|apr_pollfd_t
operator|*
name|descriptor
argument_list|)
expr_stmt|;
comment|/**  * Block for activity on the descriptor(s) in a pollset  * @param pollset The pollset to use  * @param timeout The amount of time in microseconds to wait.  This is a  *                maximum, not a minimum.  If a descriptor is signalled, the  *                function will return before this time.  If timeout is  *                negative, the function will block until a descriptor is  *                signalled or until apr_pollset_wakeup() has been called.  * @param num Number of signalled descriptors (output parameter)  * @param descriptors Array of signalled descriptors (output parameter)  * @remark APR_EINTR will be returned if the pollset has been created with  *         APR_POLLSET_WAKEABLE, apr_pollset_wakeup() has been called while  *         waiting for activity, and there were no signalled descriptors at the  *         time of the wakeup call.  * @remark Multiple signalled conditions for the same descriptor may be reported  *         in one or more returned apr_pollfd_t structures, depending on the  *         implementation.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_poll
argument_list|(
argument|apr_pollset_t *pollset
argument_list|,
argument|apr_interval_time_t timeout
argument_list|,
argument|apr_int32_t *num
argument_list|,
argument|const apr_pollfd_t **descriptors
argument_list|)
empty_stmt|;
comment|/**  * Interrupt the blocked apr_pollset_poll() call.  * @param pollset The pollset to use  * @remark If the pollset was not created with APR_POLLSET_WAKEABLE the  *         return value is APR_EINIT.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollset_wakeup
argument_list|(
name|apr_pollset_t
operator|*
name|pollset
argument_list|)
expr_stmt|;
comment|/**  * Poll the descriptors in the poll structure  * @param aprset The poll structure we will be using.   * @param numsock The number of descriptors we are polling  * @param nsds The number of descriptors signalled (output parameter)  * @param timeout The amount of time in microseconds to wait.  This is a  *                maximum, not a minimum.  If a descriptor is signalled, the  *                function will return before this time.  If timeout is  *                negative, the function will block until a descriptor is  *                signalled or until apr_pollset_wakeup() has been called.  * @remark The number of descriptors signalled is returned in the third argument.   *         This is a blocking call, and it will not return until either a   *         descriptor has been signalled or the timeout has expired.   * @remark The rtnevents field in the apr_pollfd_t array will only be filled-  *         in if the return value is APR_SUCCESS.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_poll
argument_list|(
argument|apr_pollfd_t *aprset
argument_list|,
argument|apr_int32_t numsock
argument_list|,
argument|apr_int32_t *nsds
argument_list|,
argument|apr_interval_time_t timeout
argument_list|)
empty_stmt|;
comment|/**  * Return a printable representation of the pollset method.  * @param pollset The pollset to use  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_pollset_method_name
argument_list|(
name|apr_pollset_t
operator|*
name|pollset
argument_list|)
expr_stmt|;
comment|/**  * Return a printable representation of the default pollset method  * (APR_POLLSET_DEFAULT).  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_poll_method_defname
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/** Opaque structure used for pollcb API */
typedef|typedef
name|struct
name|apr_pollcb_t
name|apr_pollcb_t
typedef|;
comment|/**  * Set up a pollcb object  * @param pollcb  The pointer in which to return the newly created object   * @param size The maximum number of descriptors that a single _poll can return.  * @param p The pool from which to allocate the pollcb  * @param flags Optional flags to modify the operation of the pollcb.  *  * @remark Pollcb is only supported on some platforms; the apr_pollcb_create()  * call will fail with APR_ENOTIMPL on platforms where it is not supported.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollcb_create
argument_list|(
argument|apr_pollcb_t **pollcb
argument_list|,
argument|apr_uint32_t size
argument_list|,
argument|apr_pool_t *p
argument_list|,
argument|apr_uint32_t flags
argument_list|)
empty_stmt|;
comment|/**  * Set up a pollcb object  * @param pollcb  The pointer in which to return the newly created object   * @param size The maximum number of descriptors that a single _poll can return.  * @param p The pool from which to allocate the pollcb  * @param flags Optional flags to modify the operation of the pollcb.  * @param method Poll method to use. See #apr_pollset_method_e.  If this  *         method cannot be used, the default method will be used unless the  *         APR_POLLSET_NODEFAULT flag has been specified.  *  * @remark Pollcb is only supported on some platforms; the apr_pollcb_create_ex()  * call will fail with APR_ENOTIMPL on platforms where it is not supported.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollcb_create_ex
argument_list|(
argument|apr_pollcb_t **pollcb
argument_list|,
argument|apr_uint32_t size
argument_list|,
argument|apr_pool_t *p
argument_list|,
argument|apr_uint32_t flags
argument_list|,
argument|apr_pollset_method_e method
argument_list|)
empty_stmt|;
comment|/**  * Add a socket or file descriptor to a pollcb  * @param pollcb The pollcb to which to add the descriptor  * @param descriptor The descriptor to add  * @remark If you set client_data in the descriptor, that value will be  *         returned in the client_data field whenever this descriptor is  *         signalled in apr_pollcb_poll().  * @remark Unlike the apr_pollset API, the descriptor is not copied, and users   *         must retain the memory used by descriptor, as the same pointer will  *         be returned to them from apr_pollcb_poll.  * @remark Do not add the same socket or file descriptor to the same pollcb  *         multiple times, even if the requested events differ for the   *         different calls to apr_pollcb_add().  If the events of interest  *         for a descriptor change, you must first remove the descriptor   *         from the pollcb with apr_pollcb_remove(), then add it again   *         specifying all requested events.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollcb_add
argument_list|(
name|apr_pollcb_t
operator|*
name|pollcb
argument_list|,
name|apr_pollfd_t
operator|*
name|descriptor
argument_list|)
expr_stmt|;
comment|/**  * Remove a descriptor from a pollcb  * @param pollcb The pollcb from which to remove the descriptor  * @param descriptor The descriptor to remove  * @remark apr_pollcb_remove() cannot be used to remove a subset of requested  *         events for a descriptor.  The reqevents field in the apr_pollfd_t  *         parameter must contain the same value when removing as when adding.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollcb_remove
argument_list|(
name|apr_pollcb_t
operator|*
name|pollcb
argument_list|,
name|apr_pollfd_t
operator|*
name|descriptor
argument_list|)
expr_stmt|;
comment|/** Function prototype for pollcb handlers   * @param baton Opaque baton passed into apr_pollcb_poll()  * @param descriptor Contains the notification for an active descriptor,   *                   the rtnevents member contains what events were triggered  *                   for this descriptor.  */
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|apr_pollcb_cb_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pollfd_t
modifier|*
name|descriptor
parameter_list|)
function_decl|;
comment|/**  * Block for activity on the descriptor(s) in a pollcb  * @param pollcb The pollcb to use  * @param timeout The amount of time in microseconds to wait.  This is a  *                maximum, not a minimum.  If a descriptor is signalled, the  *                function will return before this time.  If timeout is  *                negative, the function will block until a descriptor is  *                signalled.  * @param func Callback function to call for each active descriptor.  * @param baton Opaque baton passed to the callback function.  * @remark Multiple signalled conditions for the same descriptor may be reported  *         in one or more calls to the callback function, depending on the  *         implementation.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_pollcb_poll
argument_list|(
argument|apr_pollcb_t *pollcb
argument_list|,
argument|apr_interval_time_t timeout
argument_list|,
argument|apr_pollcb_cb_t func
argument_list|,
argument|void *baton
argument_list|)
empty_stmt|;
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
comment|/* ! APR_POLL_H */
end_comment

end_unit

