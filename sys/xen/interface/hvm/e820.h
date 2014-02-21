begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_E820_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_E820_H__
end_define

begin_comment
comment|/* E820 location in HVM virtual address space. */
end_comment

begin_define
define|#
directive|define
name|HVM_E820_PAGE
value|0x00090000
end_define

begin_define
define|#
directive|define
name|HVM_E820_NR_OFFSET
value|0x000001E8
end_define

begin_define
define|#
directive|define
name|HVM_E820_OFFSET
value|0x000002D0
end_define

begin_define
define|#
directive|define
name|HVM_BELOW_4G_RAM_END
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|HVM_BELOW_4G_MMIO_START
value|HVM_BELOW_4G_RAM_END
end_define

begin_define
define|#
directive|define
name|HVM_BELOW_4G_MMIO_LENGTH
value|((1ULL<< 32) - HVM_BELOW_4G_MMIO_START)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_E820_H__ */
end_comment

end_unit

