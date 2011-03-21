begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006-2007 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<linux/pci.h>
end_include

begin_include
include|#
directive|include
file|"wc.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_function
name|pgprot_t
name|pgprot_wc
parameter_list|(
name|pgprot_t
name|_prot
parameter_list|)
block|{
return|return
name|pgprot_writecombine
argument_list|(
name|_prot
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|mlx4_wc_enabled
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CONFIG_PPC64
argument_list|)
end_elif

begin_function
name|pgprot_t
name|pgprot_wc
parameter_list|(
name|pgprot_t
name|_prot
parameter_list|)
block|{
return|return
name|__pgprot
argument_list|(
operator|(
name|pgprot_val
argument_list|(
name|_prot
argument_list|)
operator||
name|_PAGE_NO_CACHE
operator|)
operator|&
operator|~
operator|(
name|pgprot_t
operator|)
name|_PAGE_GUARDED
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|mlx4_wc_enabled
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(defined(__i386__) || defined(__x86_64__)) */
end_comment

begin_function
name|pgprot_t
name|pgprot_wc
parameter_list|(
name|pgprot_t
name|_prot
parameter_list|)
block|{
return|return
name|pgprot_noncached
argument_list|(
name|_prot
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|mlx4_wc_enabled
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

