begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|KERNEL_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|"lomac.h"
end_include

begin_comment
comment|/*  * We do not yet implement any categories.  We use lattr_t's flags  * field to implement the "LOMAC_ATTR_LOWWRITE" exception.  When  * this bit is set on a file, lowest-level processes can write to  * the file, regardless of the file's level.  *  * There is also the LOMAC_ATTR_LOWNOOPEN flag, which prevents the  * opening of a given object to subjects with a lower level than its  * own.  *  * LOMAC_ATTR_NONETDEMOTE is set on subjects to prevent demotion on  * network reads; LOMAC_ATTR_NODEMOTE is set on subjects to prevent  * all demotion.  Both of these will effectively set a high-level  * subject as very trusted (and must be used sparingly).  */
end_comment

begin_define
define|#
directive|define
name|LOMAC_ATTR_LOWWRITE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LOMAC_ATTR_LOWNOOPEN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LOMAC_ATTR_NONETDEMOTE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|LOMAC_ATTR_NODEMOTE
value|0x00080000
end_define

begin_typedef
typedef|typedef
name|struct
name|proc
name|lomac_subject_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|lomac_object
block|{
enum|enum
name|lomac_object_type
block|{
name|LO_TYPE_LVNODE
block|,
comment|/* LOMAC vnode */
name|LO_TYPE_UVNODE
block|,
comment|/* underlying vnode */
name|LO_TYPE_VM_OBJECT
block|,
comment|/* VM object, not OBJT_VNODE */
name|LO_TYPE_PIPE
block|,
comment|/* pipe */
name|LO_TYPE_SOCKETPAIR
comment|/* local-domain socket in socketpair */
block|}
name|lo_type
enum|;
union|union
block|{
name|struct
name|vnode
modifier|*
name|vnode
decl_stmt|;
name|vm_object_t
name|vm_object
decl_stmt|;
name|struct
name|pipe
modifier|*
name|pipe
decl_stmt|;
name|struct
name|socket
modifier|*
name|socket
decl_stmt|;
block|}
name|lo_object
union|;
block|}
name|lomac_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sbuf
name|lomac_log_t
typedef|;
end_typedef

begin_function_decl
name|void
name|init_subject_lattr
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|,
name|lattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_subject_lattr
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|,
name|lattr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_subject_lattr
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|,
name|lattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_object_lattr
parameter_list|(
name|lomac_object_t
modifier|*
parameter_list|,
name|lattr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_object_lattr
parameter_list|(
specifier|const
name|lomac_object_t
modifier|*
parameter_list|,
name|lattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|subject_do_not_demote
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void subject_propogate_lattr(lomac_subject_t *);
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|kernel_vm_drop_perms
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|lattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_INTERFACE_H */
end_comment

end_unit

