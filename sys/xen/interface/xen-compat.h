begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen-compat.h  *   * Guest OS interface to Xen.  Compatibility layer.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2006, Christian Limpach  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_XEN_COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_XEN_COMPAT_H__
end_define

begin_define
define|#
directive|define
name|__XEN_LATEST_INTERFACE_VERSION__
value|0x00030209
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__XEN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__XEN_TOOLS__
argument_list|)
end_if

begin_comment
comment|/* Xen is built with matching headers and implements the latest interface. */
end_comment

begin_define
define|#
directive|define
name|__XEN_INTERFACE_VERSION__
value|__XEN_LATEST_INTERFACE_VERSION__
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__XEN_INTERFACE_VERSION__
argument_list|)
end_elif

begin_comment
comment|/* Guests which do not specify a version get the legacy interface. */
end_comment

begin_define
define|#
directive|define
name|__XEN_INTERFACE_VERSION__
value|0x00000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>
name|__XEN_LATEST_INTERFACE_VERSION__
end_if

begin_error
error|#
directive|error
literal|"These header files do not support the requested interface version."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_XEN_COMPAT_H__ */
end_comment

end_unit

