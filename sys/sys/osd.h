begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_OSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_OSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * Lock key:  *   (c) container lock (e.g. jail's pr_mtx) and/or osd_object_lock  *   (l) osd_list_lock  */
end_comment

begin_struct
struct|struct
name|osd
block|{
name|u_int
name|osd_nslots
decl_stmt|;
comment|/* (c) */
name|void
modifier|*
modifier|*
name|osd_slots
decl_stmt|;
comment|/* (c) */
name|LIST_ENTRY
argument_list|(
argument|osd
argument_list|)
name|osd_next
expr_stmt|;
comment|/* (l) */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|OSD_THREAD
value|0
end_define

begin_define
define|#
directive|define
name|OSD_JAIL
value|1
end_define

begin_define
define|#
directive|define
name|OSD_KHELP
value|2
end_define

begin_define
define|#
directive|define
name|OSD_FIRST
value|OSD_THREAD
end_define

begin_define
define|#
directive|define
name|OSD_LAST
value|OSD_KHELP
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osd_destructor_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|osd_method_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|obj
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|osd_register
parameter_list|(
name|u_int
name|type
parameter_list|,
name|osd_destructor_t
name|destructor
parameter_list|,
name|osd_method_t
modifier|*
name|methods
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osd_deregister
parameter_list|(
name|u_int
name|type
parameter_list|,
name|u_int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osd_set
parameter_list|(
name|u_int
name|type
parameter_list|,
name|struct
name|osd
modifier|*
name|osd
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|osd_reserve
parameter_list|(
name|u_int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osd_set_reserved
parameter_list|(
name|u_int
name|type
parameter_list|,
name|struct
name|osd
modifier|*
name|osd
parameter_list|,
name|u_int
name|slot
parameter_list|,
name|void
modifier|*
name|rsv
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osd_free_reserved
parameter_list|(
name|void
modifier|*
name|rsv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|osd_get
parameter_list|(
name|u_int
name|type
parameter_list|,
name|struct
name|osd
modifier|*
name|osd
parameter_list|,
name|u_int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osd_del
parameter_list|(
name|u_int
name|type
parameter_list|,
name|struct
name|osd
modifier|*
name|osd
parameter_list|,
name|u_int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osd_call
parameter_list|(
name|u_int
name|type
parameter_list|,
name|u_int
name|method
parameter_list|,
name|void
modifier|*
name|obj
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osd_exit
parameter_list|(
name|u_int
name|type
parameter_list|,
name|struct
name|osd
modifier|*
name|osd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|osd_thread_register
parameter_list|(
name|destructor
parameter_list|)
define|\
value|osd_register(OSD_THREAD, (destructor), NULL)
end_define

begin_define
define|#
directive|define
name|osd_thread_deregister
parameter_list|(
name|slot
parameter_list|)
define|\
value|osd_deregister(OSD_THREAD, (slot))
end_define

begin_define
define|#
directive|define
name|osd_thread_set
parameter_list|(
name|td
parameter_list|,
name|slot
parameter_list|,
name|value
parameter_list|)
define|\
value|osd_set(OSD_THREAD,&(td)->td_osd, (slot), (value))
end_define

begin_define
define|#
directive|define
name|osd_thread_set_reserved
parameter_list|(
name|td
parameter_list|,
name|slot
parameter_list|,
name|rsv
parameter_list|,
name|value
parameter_list|)
define|\
value|osd_set_reserved(OSD_THREAD,&(td)->td_osd, (slot), (rsv), (value))
end_define

begin_define
define|#
directive|define
name|osd_thread_get
parameter_list|(
name|td
parameter_list|,
name|slot
parameter_list|)
define|\
value|osd_get(OSD_THREAD,&(td)->td_osd, (slot))
end_define

begin_define
define|#
directive|define
name|osd_thread_del
parameter_list|(
name|td
parameter_list|,
name|slot
parameter_list|)
value|do {				\ 	KASSERT((td) == curthread, ("Not curthread."));			\ 	osd_del(OSD_THREAD,&(td)->td_osd, (slot));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|osd_thread_call
parameter_list|(
name|td
parameter_list|,
name|method
parameter_list|,
name|data
parameter_list|)
define|\
value|osd_call(OSD_THREAD, (method), (td), (data))
end_define

begin_define
define|#
directive|define
name|osd_thread_exit
parameter_list|(
name|td
parameter_list|)
define|\
value|osd_exit(OSD_THREAD,&(td)->td_osd)
end_define

begin_define
define|#
directive|define
name|osd_jail_register
parameter_list|(
name|destructor
parameter_list|,
name|methods
parameter_list|)
define|\
value|osd_register(OSD_JAIL, (destructor), (methods))
end_define

begin_define
define|#
directive|define
name|osd_jail_deregister
parameter_list|(
name|slot
parameter_list|)
define|\
value|osd_deregister(OSD_JAIL, (slot))
end_define

begin_define
define|#
directive|define
name|osd_jail_set
parameter_list|(
name|pr
parameter_list|,
name|slot
parameter_list|,
name|value
parameter_list|)
define|\
value|osd_set(OSD_JAIL,&(pr)->pr_osd, (slot), (value))
end_define

begin_define
define|#
directive|define
name|osd_jail_set_reserved
parameter_list|(
name|pr
parameter_list|,
name|slot
parameter_list|,
name|rsv
parameter_list|,
name|value
parameter_list|)
define|\
value|osd_set_reserved(OSD_JAIL,&(pr)->pr_osd, (slot), (rsv), (value))
end_define

begin_define
define|#
directive|define
name|osd_jail_get
parameter_list|(
name|pr
parameter_list|,
name|slot
parameter_list|)
define|\
value|osd_get(OSD_JAIL,&(pr)->pr_osd, (slot))
end_define

begin_define
define|#
directive|define
name|osd_jail_del
parameter_list|(
name|pr
parameter_list|,
name|slot
parameter_list|)
define|\
value|osd_del(OSD_JAIL,&(pr)->pr_osd, (slot))
end_define

begin_define
define|#
directive|define
name|osd_jail_call
parameter_list|(
name|pr
parameter_list|,
name|method
parameter_list|,
name|data
parameter_list|)
define|\
value|osd_call(OSD_JAIL, (method), (pr), (data))
end_define

begin_define
define|#
directive|define
name|osd_jail_exit
parameter_list|(
name|pr
parameter_list|)
define|\
value|osd_exit(OSD_JAIL,&(pr)->pr_osd)
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
comment|/* !_SYS_OSD_H_ */
end_comment

end_unit

