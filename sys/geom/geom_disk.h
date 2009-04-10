begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Poul-Henning Kamp  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Poul-Henning Kamp  * and NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_GEOM_DISK_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_GEOM_DISK_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_struct_decl
struct_decl|struct
name|disk
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|disk_open_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|disk_close_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|disk_strategy_t
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|disk_ioctl_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* NB: disk_ioctl_t SHALL be cast'able to d_ioctl_t */
end_comment

begin_struct_decl
struct_decl|struct
name|g_geom
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devstat
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|disk
block|{
comment|/* Fields which are private to geom_disk */
name|struct
name|g_geom
modifier|*
name|d_geom
decl_stmt|;
name|struct
name|devstat
modifier|*
name|d_devstat
decl_stmt|;
name|int
name|d_destroyed
decl_stmt|;
comment|/* Shared fields */
name|u_int
name|d_flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
name|u_int
name|d_unit
decl_stmt|;
name|struct
name|bio_queue_head
modifier|*
name|d_queue
decl_stmt|;
name|struct
name|mtx
modifier|*
name|d_lock
decl_stmt|;
comment|/* Disk methods  */
name|disk_open_t
modifier|*
name|d_open
decl_stmt|;
name|disk_close_t
modifier|*
name|d_close
decl_stmt|;
name|disk_strategy_t
modifier|*
name|d_strategy
decl_stmt|;
name|disk_ioctl_t
modifier|*
name|d_ioctl
decl_stmt|;
name|dumper_t
modifier|*
name|d_dump
decl_stmt|;
comment|/* Info fields from driver to geom_disk.c. Valid when open */
name|u_int
name|d_sectorsize
decl_stmt|;
name|off_t
name|d_mediasize
decl_stmt|;
name|u_int
name|d_fwsectors
decl_stmt|;
name|u_int
name|d_fwheads
decl_stmt|;
name|u_int
name|d_maxsize
decl_stmt|;
name|u_int
name|d_stripeoffset
decl_stmt|;
name|u_int
name|d_stripesize
decl_stmt|;
name|char
name|d_ident
index|[
name|DISK_IDENT_SIZE
index|]
decl_stmt|;
comment|/* Fields private to the driver */
name|void
modifier|*
name|d_drv1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DISKFLAG_NEEDSGIANT
value|0x1
end_define

begin_define
define|#
directive|define
name|DISKFLAG_OPEN
value|0x2
end_define

begin_define
define|#
directive|define
name|DISKFLAG_CANDELETE
value|0x4
end_define

begin_define
define|#
directive|define
name|DISKFLAG_CANFLUSHCACHE
value|0x8
end_define

begin_function_decl
name|struct
name|disk
modifier|*
name|disk_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_create
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|int
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_destroy
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_gone
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DISK_VERSION_00
value|0x58561059
end_define

begin_define
define|#
directive|define
name|DISK_VERSION_01
value|0x5856105a
end_define

begin_define
define|#
directive|define
name|DISK_VERSION
value|DISK_VERSION_01
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
comment|/* _GEOM_GEOM_DISK_H_ */
end_comment

end_unit

