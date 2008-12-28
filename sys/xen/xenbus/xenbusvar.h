begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xenbus.h  *  * Talks to Xen Store to figure out what devices we have.  *  * Copyright (C) 2005 Rusty Russell, IBM Corporation  * Copyright (C) 2005 XenSource Ltd.  *   * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  */
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
file|<machine/xen/xen-os.h>
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
file|"xenbus_if.h"
end_include

begin_enum
enum|enum
block|{
comment|/* 	 * Path of this device node. 	 */
name|XENBUS_IVAR_NODE
block|,
comment|/* 	 * The device type (e.g. vif, vbd). 	 */
name|XENBUS_IVAR_TYPE
block|,
comment|/* 	 * The state of this device (not the otherend's state). 	 */
name|XENBUS_IVAR_STATE
block|,
comment|/* 	 * Domain ID of the other end device. 	 */
name|XENBUS_IVAR_OTHEREND_ID
block|,
comment|/* 	 * Path of the other end device. 	 */
name|XENBUS_IVAR_OTHEREND_PATH
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for xenbus devices  */
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
comment|/* Register callback to watch this node. */
end_comment

begin_struct
struct|struct
name|xenbus_watch
block|{
name|LIST_ENTRY
argument_list|(
argument|xenbus_watch
argument_list|)
name|list
expr_stmt|;
comment|/* Path being watched. */
name|char
modifier|*
name|node
decl_stmt|;
comment|/* Callback (executed in a process context with no locks held). */
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|xenbus_watch
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|vec
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xenstore_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|xenbus_transaction
block|{
name|uint32_t
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XBT_NIL
value|((struct xenbus_transaction) { 0 })
end_define

begin_function_decl
name|int
name|xenbus_directory
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|,
name|unsigned
name|int
modifier|*
name|num
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_read
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|,
name|unsigned
name|int
modifier|*
name|len
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_write
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_mkdir
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_exists
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_rm
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_transaction_start
parameter_list|(
name|struct
name|xenbus_transaction
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_transaction_end
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
name|int
name|abort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Single read and scanf: returns errno or zero. If scancountp is  * non-null, then number of items scanned is returned in *scanncountp.  */
end_comment

begin_function_decl
name|int
name|xenbus_scanf
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
parameter_list|,
name|int
modifier|*
name|scancountp
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
name|scanf
parameter_list|,
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Single printf and write: returns errno or 0. */
end_comment

begin_function_decl
name|int
name|xenbus_printf
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
specifier|const
name|char
modifier|*
name|node
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
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Generic read function: NULL-terminated triples of name,  * sprintf-style type string, and pointer. Returns 0 or errno.  */
end_comment

begin_function_decl
name|int
name|xenbus_gather
parameter_list|(
name|struct
name|xenbus_transaction
name|t
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* notifer routines for when the xenstore comes up */
end_comment

begin_function_decl
name|int
name|register_xenstore_notifier
parameter_list|(
name|xenstore_event_handler_t
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void unregister_xenstore_notifier();
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|register_xenbus_watch
parameter_list|(
name|struct
name|xenbus_watch
modifier|*
name|watch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unregister_xenbus_watch
parameter_list|(
name|struct
name|xenbus_watch
modifier|*
name|watch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xs_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xs_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used by xenbus_dev to borrow kernel's store connection. */
end_comment

begin_function_decl
name|int
name|xenbus_dev_request_and_reply
parameter_list|(
name|struct
name|xsd_sockmsg
modifier|*
name|msg
parameter_list|,
name|void
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|XENBUS_IS_ERR_READ
parameter_list|(
name|str
parameter_list|)
value|({			\ 	if (!IS_ERR(str)&& strlen(str) == 0) {		\ 		free(str, M_DEVBUF);				\ 		str = ERR_PTR(-ERANGE);			\ 	}						\ 	IS_ERR(str);					\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XENBUS_EXIST_ERR
parameter_list|(
name|err
parameter_list|)
value|((err) == ENOENT || (err) == ERANGE)
end_define

begin_comment
comment|/**  * Register a watch on the given path, using the given xenbus_watch structure  * for storage, and the given callback function as the callback.  Return 0 on  * success, or errno on error.  On success, the given path will be saved as  * watch->node, and remains the caller's to free.  On error, watch->node will  * be NULL, the device will switch to XenbusStateClosing, and the error will  * be saved in the store.  */
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
name|xenbus_watch
modifier|*
name|watch
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|xenbus_watch
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Register a watch on the given path/path2, using the given xenbus_watch  * structure for storage, and the given callback function as the callback.  * Return 0 on success, or errno on error.  On success, the watched path  * (path/path2) will be saved as watch->node, and becomes the caller's to  * kfree().  On error, watch->node will be NULL, so the caller has nothing to  * free, the device will switch to XenbusStateClosing, and the error will be  * saved in the store.  */
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
name|xenbus_watch
modifier|*
name|watch
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|xenbus_watch
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Advertise in the store a change of the given driver to the given new_state.  * which case this is performed inside its own transaction.  Return 0 on  * success, or errno on error.  On error, the device will switch to  * XenbusStateClosing, and the error will be saved in the store.  */
end_comment

begin_function_decl
name|int
name|xenbus_switch_state
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|XenbusState
name|new_state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Grant access to the given ring_mfn to the peer of the given device.  * Return 0 on success, or errno on error.  On error, the device will  * switch to XenbusStateClosing, and the error will be saved in the  * store. The grant ring reference is returned in *refp.  */
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
name|int
modifier|*
name|refp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate an event channel for the given xenbus_device, assigning the newly  * created local port to *port.  Return 0 on success, or errno on error.  On  * error, the device will switch to XenbusStateClosing, and the error will be  * saved in the store.  */
end_comment

begin_function_decl
name|int
name|xenbus_alloc_evtchn
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free an existing event channel. Returns 0 on success or errno on error.  */
end_comment

begin_function_decl
name|int
name|xenbus_free_evtchn
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the state of the driver rooted at the given store path, or  * XenbusStateClosed if no state can be read.  */
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
comment|/***  * Report the given negative errno into the store, along with the given  * formatted message.  */
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
function_decl|;
end_function_decl

begin_comment
comment|/***  * Equivalent to xenbus_dev_error(dev, err, fmt, args), followed by  * xenbus_switch_state(dev, NULL, XenbusStateClosing) to schedule an orderly  * closedown of this driver and its peer.  */
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
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_dev_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|xenbus_dev_is_online
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xenbus_frontend_closed
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENBUS_XENBUSVAR_H */
end_comment

end_unit

