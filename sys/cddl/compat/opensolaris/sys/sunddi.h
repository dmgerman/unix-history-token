begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_SUNDDI_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_SUNDDI_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysevent.h>
end_include

begin_define
define|#
directive|define
name|ddi_driver_major
parameter_list|(
name|zfs_dip
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|ddi_copyin
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|,
name|flag
parameter_list|)
define|\
value|(copyin((from), (to), (size)), 0)
end_define

begin_define
define|#
directive|define
name|ddi_copyout
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|size
parameter_list|,
name|flag
parameter_list|)
define|\
value|(copyout((from), (to), (size)), 0)
end_define

begin_function_decl
name|int
name|ddi_strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|nptr
parameter_list|,
name|int
name|base
parameter_list|,
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddi_strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|nptr
parameter_list|,
name|int
name|base
parameter_list|,
name|unsigned
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddi_strtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
modifier|*
name|nptr
parameter_list|,
name|int
name|base
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DDI_SUCCESS
value|(0)
end_define

begin_define
define|#
directive|define
name|DDI_FAILURE
value|(-1)
end_define

begin_define
define|#
directive|define
name|DDI_SLEEP
value|0x666
end_define

begin_function_decl
name|int
name|ddi_soft_state_init
parameter_list|(
name|void
modifier|*
modifier|*
name|statep
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|nitems
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ddi_soft_state_fini
parameter_list|(
name|void
modifier|*
modifier|*
name|statep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ddi_get_soft_state
parameter_list|(
name|void
modifier|*
name|state
parameter_list|,
name|int
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddi_soft_state_zalloc
parameter_list|(
name|void
modifier|*
name|state
parameter_list|,
name|int
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ddi_soft_state_free
parameter_list|(
name|void
modifier|*
name|state
parameter_list|,
name|int
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_ddi_log_sysevent
parameter_list|(
name|char
modifier|*
name|vendor
parameter_list|,
name|char
modifier|*
name|class_name
parameter_list|,
name|char
modifier|*
name|subclass_name
parameter_list|,
name|nvlist_t
modifier|*
name|attr_list
parameter_list|,
name|sysevent_id_t
modifier|*
name|eidp
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ddi_log_sysevent
parameter_list|(
name|dip
parameter_list|,
name|vendor
parameter_list|,
name|class_name
parameter_list|,
name|subclass_name
parameter_list|,	\
name|attr_list
parameter_list|,
name|eidp
parameter_list|,
name|flag
parameter_list|)
define|\
value|_ddi_log_sysevent((vendor), (class_name), (subclass_name),	\ 	    (attr_list), (eidp), (flag))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_SUNDDI_H_ */
end_comment

end_unit

