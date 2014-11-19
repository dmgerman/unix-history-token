begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_PAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_PAGE_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_define
define|#
directive|define
name|page
value|vm_page
end_define

begin_define
define|#
directive|define
name|virt_to_page
parameter_list|(
name|x
parameter_list|)
value|PHYS_TO_VM_PAGE(vtophys((x)))
end_define

begin_define
define|#
directive|define
name|clear_page
parameter_list|(
name|page
parameter_list|)
value|memset((page), 0, PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|pgprot_noncached
parameter_list|(
name|prot
parameter_list|)
value|VM_MEMATTR_UNCACHEABLE
end_define

begin_define
define|#
directive|define
name|pgprot_writecombine
parameter_list|(
name|prot
parameter_list|)
value|VM_MEMATTR_WRITE_COMBINING
end_define

begin_undef
undef|#
directive|undef
name|PAGE_MASK
end_undef

begin_define
define|#
directive|define
name|PAGE_MASK
value|(~(PAGE_SIZE-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_PAGE_H_ */
end_comment

end_unit

