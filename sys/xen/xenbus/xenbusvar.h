begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * Copyright (C) 2005 Rusty Russell, IBM Corporation  * Copyright (C) 2005 XenSource Ltd.  *   * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file xenbusvar.h  *  * \brief Datastructures and function declarations for usedby device  *        drivers operating on the XenBus.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENBUS_XENBUSVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENBUS_XENBUSVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/grant_table.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/io/xenbus.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/io/xs_wire.h>
end_include

begin_include
include|#
directive|include
file|<xen/xenstore/xenstorevar.h>
end_include

begin_comment
comment|/* XenBus allocations including XenStore data returned to clients. */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_XENBUS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
comment|/** 	 * Path of this device node. 	 */
name|XENBUS_IVAR_NODE
block|,
comment|/** 	 * The device type (e.g. vif, vbd). 	 */
name|XENBUS_IVAR_TYPE
block|,
comment|/** 	 * The state of this device (not the otherend's state). 	 */
name|XENBUS_IVAR_STATE
block|,
comment|/** 	 * Domain ID of the other end device. 	 */
name|XENBUS_IVAR_OTHEREND_ID
block|,
comment|/** 	 * Path of the other end device. 	 */
name|XENBUS_IVAR_OTHEREND_PATH
block|}
enum|;
end_enum

begin_comment
comment|/**  * Simplified accessors for xenbus devices  */
end_comment

begin_define
define|#
directive|define
name|XENBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(xenbus, var, XENBUS, ivar, type)
end_define

begin_macro
name|XENBUS_ACCESSOR
argument_list|(
argument|node
argument_list|,
argument|NODE
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|XENBUS_ACCESSOR
argument_list|(
argument|type
argument_list|,
argument|TYPE
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|XENBUS_ACCESSOR
argument_list|(
argument|state
argument_list|,
argument|STATE
argument_list|,
argument|enum xenbus_state
argument_list|)
end_macro

begin_macro
name|XENBUS_ACCESSOR
argument_list|(
argument|otherend_id
argument_list|,
argument|OTHEREND_ID
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|XENBUS_ACCESSOR
argument_list|(
argument|otherend_path
argument_list|,
argument|OTHEREND_PATH
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_comment
comment|/**  * Return the state of a XenBus device.  *  * \param path  The root XenStore path for the device.  *  * \return  The current state of the device or XenbusStateClosed if no  *	    state can be read.  */
end_comment

begin_function_decl
name|XenbusState
name|xenbus_read_driver_state
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the state of the "other end" (peer) of a XenBus device.  *  * \param dev   The XenBus device whose peer to query.  *  * \return  The current state of the peer device or XenbusStateClosed if no  *          state can be read.  */
end_comment

begin_function
specifier|static
specifier|inline
name|XenbusState
name|xenbus_get_otherend_state
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|xenbus_read_driver_state
argument_list|(
name|xenbus_get_otherend_path
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Initialize and register a watch on the given path (client suplied storage).  *  * \param dev       The XenBus device requesting the watch service.  * \param path      The XenStore path of the object to be watched.  The  *                  storage for this string must be stable for the lifetime  *                  of the watch.  * \param watch     The watch object to use for this request.  This object  *                  must be stable for the lifetime of the watch.  * \param callback  The function to call when XenStore objects at or below  *                  path are modified.  * \param cb_data   Client data that can be retrieved from the watch object  *                  during the callback.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * \note  On error, the device 'dev' will be switched to the XenbusStateClosing  *        state and the returned error is saved in the per-device error node  *        for dev in the XenStore.  */
end_comment

begin_function_decl
name|int
name|xenbus_watch_path
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|xs_watch
modifier|*
name|watch
parameter_list|,
name|xs_watch_cb_t
modifier|*
name|callback
parameter_list|,
name|uintptr_t
name|cb_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize and register a watch at path/path2 in the XenStore.  *  * \param dev       The XenBus device requesting the watch service.  * \param path      The base XenStore path of the object to be watched.  * \param path2     The tail XenStore path of the object to be watched.  * \param watch     The watch object to use for this request.  This object  *                  must be stable for the lifetime of the watch.  * \param callback  The function to call when XenStore objects at or below  *                  path are modified.  * \param cb_data   Client data that can be retrieved from the watch object  *                  during the callback.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * \note  On error, \a dev will be switched to the XenbusStateClosing  *        state and the returned error is saved in the per-device error node  *        for \a dev in the XenStore.  *  * Similar to xenbus_watch_path, however the storage for the path to the  * watched object is allocated from the heap and filled with "path '/' path2".  * Should a call to this function succeed, it is the callers responsibility  * to free watch->node using the M_XENBUS malloc type.  */
end_comment

begin_function_decl
name|int
name|xenbus_watch_path2
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|path2
parameter_list|,
name|struct
name|xs_watch
modifier|*
name|watch
parameter_list|,
name|xs_watch_cb_t
modifier|*
name|callback
parameter_list|,
name|uintptr_t
name|cb_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Grant access to the given ring_mfn to the peer of the given device.  *  * \param dev        The device granting access to the ring page.  * \param ring_mfn   The guest machine page number of the page to grant  *                   peer access rights.  * \param refp[out]  The grant reference for the page.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * A successful call to xenbus_grant_ring should be paired with a call  * to gnttab_end_foreign_access() when foregn access to this page is no  * longer requried.  *   * \note  On error, \a dev will be switched to the XenbusStateClosing  *        state and the returned error is saved in the per-device error node  *        for \a dev in the XenStore.  */
end_comment

begin_function_decl
name|int
name|xenbus_grant_ring
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|unsigned
name|long
name|ring_mfn
parameter_list|,
name|grant_ref_t
modifier|*
name|refp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Record the given errno, along with the given, printf-style, formatted  * message in dev's device specific error node in the XenStore.  *  * \param dev  The device which encountered the error.  * \param err  The errno value corresponding to the error.  * \param fmt  Printf format string followed by a variable number of  *             printf arguments.  */
end_comment

begin_function_decl
name|void
name|xenbus_dev_error
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * va_list version of xenbus_dev_error().  *  * \param dev  The device which encountered the error.  * \param err  The errno value corresponding to the error.  * \param fmt  Printf format string.  * \param ap   Va_list of printf arguments.  */
end_comment

begin_function_decl
name|void
name|xenbus_dev_verror
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Equivalent to xenbus_dev_error(), followed by  * xenbus_set_state(dev, XenbusStateClosing).  *  * \param dev  The device which encountered the error.  * \param err  The errno value corresponding to the error.  * \param fmt  Printf format string followed by a variable number of  *             printf arguments.  */
end_comment

begin_function_decl
name|void
name|xenbus_dev_fatal
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * va_list version of xenbus_dev_fatal().  *  * \param dev  The device which encountered the error.  * \param err  The errno value corresponding to the error.  * \param fmt  Printf format string.  * \param ap   Va_list of printf arguments.  */
end_comment

begin_function_decl
name|void
name|xenbus_dev_vfatal
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Convert a member of the xenbus_state enum into an ASCII string.  *  * /param state  The XenBus state to lookup.  *  * /return  A string representing state or, for unrecognized states,  *	    the string "Unknown".  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|xenbus_strstate
parameter_list|(
name|enum
name|xenbus_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the value of a XenBus device's "online" node within the XenStore.  *  * \param dev  The XenBus device to query.  *  * \return  The value of the "online" node for the device.  If the node  *          does not exist, 0 (offline) is returned.  */
end_comment

begin_function_decl
name|int
name|xenbus_dev_is_online
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Default callback invoked when a change to the local XenStore sub-tree  * for a device is modified.  *   * \param dev   The XenBus device whose tree was modified.  * \param path  The tree relative sub-path to the modified node.  The empty  *              string indicates the root of the tree was destroyed.  */
end_comment

begin_function_decl
name|void
name|xenbus_localend_changed
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"xenbus_if.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENBUS_XENBUSVAR_H */
end_comment

end_unit

