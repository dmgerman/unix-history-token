begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Simple prototyle Xen Store Daemon providing simple tree-like database.  * Copyright (C) 2005 Rusty Russell IBM Corporation  *  * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XENSTORED_H
end_ifndef

begin_define
define|#
directive|define
name|_XENSTORED_H
end_define

begin_enum
enum|enum
name|xsd_sockmsg_type
block|{
name|XS_DEBUG
block|,
name|XS_SHUTDOWN
block|,
name|XS_DIRECTORY
block|,
name|XS_READ
block|,
name|XS_GET_PERMS
block|,
name|XS_WATCH
block|,
name|XS_WATCH_ACK
block|,
name|XS_UNWATCH
block|,
name|XS_TRANSACTION_START
block|,
name|XS_TRANSACTION_END
block|,
name|XS_OP_READ_ONLY
init|=
name|XS_TRANSACTION_END
block|,
name|XS_INTRODUCE
block|,
name|XS_RELEASE
block|,
name|XS_GETDOMAINPATH
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
block|, }
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

begin_decl_stmt
specifier|static
name|struct
name|xsd_errors
name|xsd_errors
index|[]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
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
name|ETIMEDOUT
argument_list|)
block|,
name|XSD_ERROR
argument_list|(
name|EISCONN
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|xsd_sockmsg
block|{
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
comment|/* Length of data following this. */
comment|/* Generally followed by nul-terminated string(s). */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XENSTORED_H */
end_comment

end_unit

