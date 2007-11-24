begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996  *	Matthias Drochner.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project  *	by Matthias Drochner.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * ARC fully-qualified device descriptor  */
end_comment

begin_struct
struct|struct
name|arc_devdesc
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
name|arcdisk
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
name|arc_getdev
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
name|arc_fmtdev
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
name|arc_setcurrdev
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
name|arcdisk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|netif_driver
name|arcnet
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
name|int
name|arc_copyin
parameter_list|(
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
name|int
name|arc_copyout
parameter_list|(
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
name|int
name|arc_readin
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
name|arc_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arc_autoload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

