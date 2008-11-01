begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) IBM Corp. 2006  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_XENCOMM_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_XENCOMM_H_
end_define

begin_comment
comment|/* A xencomm descriptor is a scatter/gather list containing physical  * addresses corresponding to a virtually contiguous memory area. The  * hypervisor translates these physical addresses to machine addresses to copy  * to and from the virtually contiguous area.  */
end_comment

begin_define
define|#
directive|define
name|XENCOMM_MAGIC
value|0x58434F4D
end_define

begin_comment
comment|/* 'XCOM' */
end_comment

begin_define
define|#
directive|define
name|XENCOMM_INVALID
value|(~0UL)
end_define

begin_struct
struct|struct
name|xencomm_desc
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|nr_addrs
decl_stmt|;
comment|/* the number of entries in address[] */
name|uint64_t
name|address
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_XENCOMM_H_ */
end_comment

end_unit

