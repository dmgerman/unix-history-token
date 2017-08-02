begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFINIBAND_ARCH_H
end_ifndef

begin_define
define|#
directive|define
name|INFINIBAND_ARCH_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/endian.h>
end_include

begin_warning
warning|#
directive|warning
literal|"This header is obsolete."
end_warning

begin_ifndef
ifndef|#
directive|ifndef
name|ntohll
end_ifndef

begin_undef
undef|#
directive|undef
name|htonll
end_undef

begin_undef
undef|#
directive|undef
name|ntohll
end_undef

begin_comment
comment|/* Users should use the glibc functions directly, not these wrappers */
end_comment

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(deprecated)
argument_list|)
name|uint64_t
name|htonll
argument_list|(
argument|uint64_t x
argument_list|)
block|{
return|return
name|htobe64
argument_list|(
name|x
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(deprecated)
argument_list|)
name|uint64_t
name|ntohll
argument_list|(
argument|uint64_t x
argument_list|)
block|{
return|return
name|be64toh
argument_list|(
name|x
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|htonll
value|htonll
end_define

begin_define
define|#
directive|define
name|ntohll
value|ntohll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Barrier macros are no longer provided by libibverbs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INFINIBAND_ARCH_H */
end_comment

end_unit

