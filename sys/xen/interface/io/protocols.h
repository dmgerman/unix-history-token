begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * protocols.h  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PROTOCOLS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PROTOCOLS_H__
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_X86_32
value|"x86_32-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_X86_64
value|"x86_64-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_IA64
value|"ia64-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_ARM
value|"arm-abi"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_X86_32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_X86_64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_IA64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_ARM
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|arch fixup needed here
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

