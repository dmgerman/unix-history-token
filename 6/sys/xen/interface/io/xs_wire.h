begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Details of the "wire" protocol between Xen Store Daemon and client  * library or guest kernel.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) 2005 Rusty Russell IBM Corporation  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XS_WIRE_H
end_ifndef

begin_define
define|#
directive|define
name|_XS_WIRE_H
end_define

begin_enum
enum|enum
name|xsd_sockmsg_type
block|{
name|XS_DEBUG
block|,
name|XS_DIRECTORY
block|,
name|XS_READ
block|,
name|XS_GET_PERMS
block|,
name|XS_WATCH
block|,
name|XS_UNWATCH
block|,
name|XS_TRANSACTION_START
block|,
name|XS_TRANSACTION_END
block|,
name|XS_INTRODUCE
block|,
name|XS_RELEASE
block|,
name|XS_GET_DOMAIN_PATH
block|,
name|XS_WRITE
block|,
name|XS_MKDIR
block|,
name|XS_RM
block|,
name|XS_SET_PERMS
block|,
name|XS_WATCH_EVENT
block|,
name|XS_ERROR
block|,
name|XS_IS_DOMAIN_INTRODUCED
block|,
name|XS_RESUME
block|,
name|XS_SET_TARGET
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|XS_WRITE_NONE
value|"NONE"
end_define

begin_define
define|#
directive|define
name|XS_WRITE_CREATE
value|"CREATE"
end_define

begin_define
define|#
directive|define
name|XS_WRITE_CREATE_EXCL
value|"CREATE|EXCL"
end_define

begin_comment
comment|/* We hand errors as strings, for portability. */
end_comment

begin_struct
struct|struct
name|xsd_errors
block|{
name|int
name|errnum
decl_stmt|;
specifier|const
name|char
modifier|*
name|errstring
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XSD_ERROR
parameter_list|(
name|x
parameter_list|)
value|{ x, #x }
end_define

begin_comment
comment|/* LINTED: static unused */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|xsd_errors
name|xsd_errors
index|[]
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
endif|#
directive|endif
init|=
block|{
name|XSD_ERROR
argument_list|(
name|EINVAL
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EACCES
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EEXIST
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EISDIR
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|ENOENT
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|ENOMEM
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|ENOSPC
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EIO
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|ENOTEMPTY
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|ENOSYS
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EROFS
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EBUSY
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EAGAIN
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
argument|EISCONN
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|xsd_sockmsg
block|{
name|uint32_t
name|type
decl_stmt|;
comment|/* XS_??? */
name|uint32_t
name|req_id
decl_stmt|;
comment|/* Request identifier, echoed in daemon's response.  */
name|uint32_t
name|tx_id
decl_stmt|;
comment|/* Transaction id (0 if not related to a transaction). */
name|uint32_t
name|len
decl_stmt|;
comment|/* Length of data following this. */
comment|/* Generally followed by nul-terminated string(s). */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|xs_watch_type
block|{
name|XS_WATCH_PATH
init|=
literal|0
block|,
name|XS_WATCH_TOKEN
block|}
enum|;
end_enum

begin_comment
comment|/* Inter-domain shared memory communications. */
end_comment

begin_define
define|#
directive|define
name|XENSTORE_RING_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|XENSTORE_RING_IDX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MASK_XENSTORE_IDX
parameter_list|(
name|idx
parameter_list|)
value|((idx)& (XENSTORE_RING_SIZE-1))
end_define

begin_struct
struct|struct
name|xenstore_domain_interface
block|{
name|char
name|req
index|[
name|XENSTORE_RING_SIZE
index|]
decl_stmt|;
comment|/* Requests to xenstore daemon. */
name|char
name|rsp
index|[
name|XENSTORE_RING_SIZE
index|]
decl_stmt|;
comment|/* Replies and async watch events. */
name|XENSTORE_RING_IDX
name|req_cons
decl_stmt|,
name|req_prod
decl_stmt|;
name|XENSTORE_RING_IDX
name|rsp_cons
decl_stmt|,
name|rsp_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Violating this is very bad.  See docs/misc/xenstore.txt. */
end_comment

begin_define
define|#
directive|define
name|XENSTORE_PAYLOAD_MAX
value|4096
end_define

begin_comment
comment|/* Violating these just gets you an error back */
end_comment

begin_define
define|#
directive|define
name|XENSTORE_ABS_PATH_MAX
value|3072
end_define

begin_define
define|#
directive|define
name|XENSTORE_REL_PATH_MAX
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XS_WIRE_H */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

