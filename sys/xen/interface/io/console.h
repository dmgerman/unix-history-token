begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * console.h  *   * Console I/O interface for Xen guest OSes.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Keir Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_CONSOLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_CONSOLE_H__
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|XENCONS_RING_IDX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MASK_XENCONS_IDX
parameter_list|(
name|idx
parameter_list|,
name|ring
parameter_list|)
value|((idx)& (sizeof(ring)-1))
end_define

begin_struct
struct|struct
name|xencons_interface
block|{
name|char
name|in
index|[
literal|1024
index|]
decl_stmt|;
name|char
name|out
index|[
literal|2048
index|]
decl_stmt|;
name|XENCONS_RING_IDX
name|in_cons
decl_stmt|,
name|in_prod
decl_stmt|;
name|XENCONS_RING_IDX
name|out_cons
decl_stmt|,
name|out_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IO_CONSOLE_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

