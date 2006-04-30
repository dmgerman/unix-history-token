begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * SKI fully-qualified device descriptor  */
end_comment

begin_struct
struct|struct
name|ski_devdesc
block|{
name|struct
name|devsw
modifier|*
name|d_dev
decl_stmt|;
name|int
name|d_type
decl_stmt|;
define|#
directive|define
name|DEVT_NONE
value|0
define|#
directive|define
name|DEVT_DISK
value|1
define|#
directive|define
name|DEVT_NET
value|2
union|union
block|{
struct|struct
block|{
name|int
name|unit
decl_stmt|;
name|int
name|slice
decl_stmt|;
name|int
name|partition
decl_stmt|;
block|}
name|skidisk
struct|;
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* XXX net layer lives over these? */
block|}
name|netif
struct|;
block|}
name|d_kind
union|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ski_getdev
parameter_list|(
name|void
modifier|*
modifier|*
name|vdev
parameter_list|,
specifier|const
name|char
modifier|*
name|devspec
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ski_fmtdev
parameter_list|(
name|void
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ski_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAXDEV
value|31
end_define

begin_comment
comment|/* maximum number of distinct devices */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|physaddr_t
typedef|;
end_typedef

begin_comment
comment|/* exported devices XXX rename? */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|skifs_dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|ski_disk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|ski_net
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Wrapper over SKI filesystems. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|ski_fsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is in startup code */
end_comment

begin_function_decl
specifier|extern
name|void
name|delay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reboot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|ski_copyin
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|ski_copyout
parameter_list|(
specifier|const
name|vm_offset_t
name|src
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|ski_readin
parameter_list|(
name|int
name|fd
parameter_list|,
name|vm_offset_t
name|dest
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ski_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|bootinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|preloaded_file
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|bi_load
parameter_list|(
name|struct
name|bootinfo
modifier|*
parameter_list|,
name|struct
name|preloaded_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SSC_CONSOLE_INIT
value|20
end_define

begin_define
define|#
directive|define
name|SSC_GETCHAR
value|21
end_define

begin_define
define|#
directive|define
name|SSC_PUTCHAR
value|31
end_define

begin_define
define|#
directive|define
name|SSC_OPEN
value|50
end_define

begin_define
define|#
directive|define
name|SSC_CLOSE
value|51
end_define

begin_define
define|#
directive|define
name|SSC_READ
value|52
end_define

begin_define
define|#
directive|define
name|SSC_WRITE
value|53
end_define

begin_define
define|#
directive|define
name|SSC_GET_COMPLETION
value|54
end_define

begin_define
define|#
directive|define
name|SSC_WAIT_COMPLETION
value|55
end_define

begin_define
define|#
directive|define
name|SSC_GET_RTC
value|65
end_define

begin_define
define|#
directive|define
name|SSC_EXIT
value|66
end_define

begin_define
define|#
directive|define
name|SSC_LOAD_SYMBOLS
value|69
end_define

begin_define
define|#
directive|define
name|SSC_SAL_SET_VECTORS
value|120
end_define

begin_function_decl
name|u_int64_t
name|ssc
parameter_list|(
name|u_int64_t
name|in0
parameter_list|,
name|u_int64_t
name|in1
parameter_list|,
name|u_int64_t
name|in2
parameter_list|,
name|u_int64_t
name|in3
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

end_unit

