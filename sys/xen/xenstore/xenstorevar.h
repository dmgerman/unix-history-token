begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xenstorevar.h  *  * Method declarations and structures for accessing the XenStore.h  *  * Copyright (C) 2005 Rusty Russell, IBM Corporation  * Copyright (C) 2005 XenSource Ltd.  * Copyright (C) 2009,2010 Spectra Logic Corporation  *   * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENSTORE_XENSTOREVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENSTORE_XENSTOREVAR_H
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
file|"xenbus_if.h"
end_include

begin_comment
comment|/* XenStore allocations including XenStore data returned to clients. */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_XENSTORE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|xenstore_domain_interface
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xs_watch
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|xenstore_domain_interface
modifier|*
name|xen_store
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
name|xs_watch_cb_t
function_decl|)
parameter_list|(
name|struct
name|xs_watch
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
end_typedef

begin_comment
comment|/* Register callback to watch subtree (node) in the XenStore. */
end_comment

begin_struct
struct|struct
name|xs_watch
block|{
name|LIST_ENTRY
argument_list|(
argument|xs_watch
argument_list|)
name|list
expr_stmt|;
comment|/* Path being watched. */
name|char
modifier|*
name|node
decl_stmt|;
comment|/* Callback (executed in a process context with no locks held). */
name|xs_watch_cb_t
modifier|*
name|callback
decl_stmt|;
comment|/* Callback client data untouched by the XenStore watch mechanism. */
name|uintptr_t
name|callback_data
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|xs_watch_list
argument_list|,
name|xs_watch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xs_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|xs_transaction
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
name|XST_NIL
value|((struct xs_transaction) { 0 })
end_define

begin_comment
comment|/**  * Fetch the contents of a directory in the XenStore.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the path to read.  * \param node    The basename of the path to read.  * \param num     The returned number of directory entries.  * \param result  An array of directory entry strings.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * \note The results buffer is malloced and should be free'd by the  *       caller with 'free(*result, M_XENSTORE)'.  */
end_comment

begin_function_decl
name|int
name|xs_directory
parameter_list|(
name|struct
name|xs_transaction
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
specifier|const
name|char
modifier|*
modifier|*
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if a path exists in the XenStore.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the path to read.  * \param node    The basename of the path to read.  *  * \retval 1  The path exists.  * \retval 0  The path does not exist or an error occurred attempting  *            to make that determination.  */
end_comment

begin_function_decl
name|int
name|xs_exists
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Get the contents of a single "file".  Returns the contents in  * *result which should be freed with free(*result, M_XENSTORE) after  * use.  The length of the value in bytes is returned in *len.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the file to read.  * \param node    The basename of the file to read.  * \param len     The amount of data read.  * \param result  The returned contents from this file.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  *  * \note The results buffer is malloced and should be free'd by the  *       caller with 'free(*result, M_XENSTORE)'.  */
end_comment

begin_function_decl
name|int
name|xs_read
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Write to a single file.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the file to write.  * \param node    The basename of the file to write.  * \param string  The NUL terminated string of data to write.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_write
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Create a new directory.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the directory to create.  * \param node    The basename of the directory to create.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_mkdir
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Remove a file or directory (directories must be empty).  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the directory to remove.  * \param node    The basename of the directory to remove.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_rm
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Destroy a tree of files rooted at dir/node.  *  * \param t       The XenStore transaction covering this request.  * \param dir     The dirname of the directory to remove.  * \param node    The basename of the directory to remove.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_rm_tree
parameter_list|(
name|struct
name|xs_transaction
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

begin_comment
comment|/**  * Start a transaction.  *  * Changes by others will not be seen during the lifetime of this  * transaction, and changes will not be visible to others until it  * is committed (xs_transaction_end).  *  * \param t  The returned transaction.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_transaction_start
parameter_list|(
name|struct
name|xs_transaction
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * End a transaction.  *  * \param t      The transaction to end/commit.  * \param abort  If non-zero, the transaction is discarded  * 		 instead of committed.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_transaction_end
parameter_list|(
name|struct
name|xs_transaction
name|t
parameter_list|,
name|int
name|abort
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Single file read and scanf parsing of the result.  *  * \param t           The XenStore transaction covering this request.  * \param dir         The dirname of the path to read.  * \param node        The basename of the path to read.  * \param scancountp  The number of input values assigned (i.e. the result  *      	      of scanf).  * \param fmt         Scanf format string followed by a variable number of  *                    scanf input arguments.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function_decl
name|int
name|xs_scanf
parameter_list|(
name|struct
name|xs_transaction
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
comment|/**  * Printf formatted write to a XenStore file.  *  * \param t     The XenStore transaction covering this request.  * \param dir   The dirname of the path to read.  * \param node  The basename of the path to read.  * \param fmt   Printf format string followed by a variable number of  *              printf arguments.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of write failure.  */
end_comment

begin_function_decl
name|int
name|xs_printf
parameter_list|(
name|struct
name|xs_transaction
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
comment|/**  * va_list version of xenbus_printf().  *  * \param t     The XenStore transaction covering this request.  * \param dir   The dirname of the path to read.  * \param node  The basename of the path to read.  * \param fmt   Printf format string.  * \param ap    Va_list of printf arguments.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of write failure.  */
end_comment

begin_function_decl
name|int
name|xs_vprintf
parameter_list|(
name|struct
name|xs_transaction
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
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Multi-file read within a single directory and scanf parsing of  * the results.  *  * \param t    The XenStore transaction covering this request.  * \param dir  The dirname of the paths to read.  * \param ...  A variable number of argument triples specifying  *             the file name, scanf-style format string, and  *             output variable (pointer to storage of the results).  *             The last triple in the call must be terminated  *             will a final NULL argument.  A NULL format string  *             will cause the entire contents of the given file  *             to be assigned as a NUL terminated, M_XENSTORE heap  *             backed, string to the output parameter of that tuple.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of read failure.  *  * Example:  *         char protocol_abi[64];  *         uint32_t ring_ref;  *         char *dev_type;  *         int error;  *  *         error = xenbus_gather(XBT_NIL, xenbus_get_node(dev),  *             "ring-ref", "%" PRIu32,&ring_ref,  *             "protocol", "%63s", protocol_abi,  *             "device-type", NULL,&dev_type,  *             NULL);  *  *         ...  *  *         free(dev_type, M_XENSTORE);  */
end_comment

begin_function_decl
name|int
name|xs_gather
parameter_list|(
name|struct
name|xs_transaction
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
comment|/**  * Register a XenStore watch.  *  * XenStore watches allow a client to be notified via a callback (embedded  * within the watch object) of changes to an object in the XenStore.  *  * \param watch  An xs_watch struct with it's node and callback fields  *               properly initialized.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of write failure.  EEXIST errors from the XenStore  *          are supressed, allowing multiple, physically different,  *          xenbus_watch objects, to watch the same path in the XenStore.  */
end_comment

begin_function_decl
name|int
name|xs_register_watch
parameter_list|(
name|struct
name|xs_watch
modifier|*
name|watch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unregister a XenStore watch.  *  * \param watch  An xs_watch object previously used in a successful call  *		 to xs_register_watch().  *  * The xs_watch object's node field is not altered by this call.  * It is the caller's responsibility to properly dispose of both the  * watch object and the data pointed to by watch->node.  */
end_comment

begin_function_decl
name|void
name|xs_unregister_watch
parameter_list|(
name|struct
name|xs_watch
modifier|*
name|watch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate and return an sbuf containing the XenStore path string  *<dir>/<name>.  If name is the NUL string, the returned sbuf contains  * the path string<dir>.  *  * \param dir	The NUL terminated directory prefix for new path.  * \param name  The NUL terminated basename for the new path.  *  * \return  A buffer containing the joined path.  */
end_comment

begin_function_decl
name|struct
name|sbuf
modifier|*
name|xs_join
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENSTORE_XENSTOREVAR_H */
end_comment

end_unit

