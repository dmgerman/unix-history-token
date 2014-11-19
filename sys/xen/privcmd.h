begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * privcmd.h  *   * Interface to /proc/xen/privcmd.  *   * Copyright (c) 2003-2005, K A Fraser  *   * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License version 2  * as published by the Free Software Foundation; or, when distributed  * separately from the Linux kernel or incorporated into other  * software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PRIVCMD_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PRIVCMD_H__
end_define

begin_struct
struct|struct
name|ioctl_privcmd_hypercall
block|{
name|unsigned
name|long
name|op
decl_stmt|;
comment|/* hypercall number */
name|unsigned
name|long
name|arg
index|[
literal|5
index|]
decl_stmt|;
comment|/* arguments */
name|long
name|retval
decl_stmt|;
comment|/* return value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ioctl_privcmd_mmapbatch
block|{
name|int
name|num
decl_stmt|;
comment|/* number of pages to populate */
name|domid_t
name|dom
decl_stmt|;
comment|/* target domain */
name|unsigned
name|long
name|addr
decl_stmt|;
comment|/* virtual address */
specifier|const
name|xen_pfn_t
modifier|*
name|arr
decl_stmt|;
comment|/* array of mfns */
name|int
modifier|*
name|err
decl_stmt|;
comment|/* array of error codes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_PRIVCMD_HYPERCALL
define|\
value|_IOWR('E', 0, struct ioctl_privcmd_hypercall)
end_define

begin_define
define|#
directive|define
name|IOCTL_PRIVCMD_MMAPBATCH
define|\
value|_IOWR('E', 1, struct ioctl_privcmd_mmapbatch)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__XEN_PRIVCMD_H__ */
end_comment

end_unit

