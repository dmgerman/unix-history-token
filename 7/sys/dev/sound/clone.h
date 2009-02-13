begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SND_CLONE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SND_CLONE_H_
end_define

begin_struct_decl
struct_decl|struct
name|snd_clone_entry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|snd_clone
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * 750 milisecond default deadline. Short enough to not cause excessive  * garbage collection, long enough to indicate stalled VFS.  */
end_comment

begin_define
define|#
directive|define
name|SND_CLONE_DEADLINE_DEFAULT
value|750
end_define

begin_comment
comment|/*  * Fit within 24bit MAXMINOR.  */
end_comment

begin_define
define|#
directive|define
name|SND_CLONE_MAXUNIT
value|0xffffff
end_define

begin_comment
comment|/*  * Creation flags, mostly related to the behaviour of garbage collector.  *  * SND_CLONE_ENABLE     - Enable clone allocation.  * SND_CLONE_GC_ENABLE  - Enable garbage collector operation, automatically  *                        or if explicitly called upon.  * SND_CLONE_GC_UNREF   - Garbage collect during unref operation.  * SND_CLONE_GC_LASTREF - Garbage collect during last reference  *                        (refcount = 0)  * SND_CLONE_GC_EXPIRED - Don't garbage collect unless the global clone  *                        handler has been expired.  * SND_CLONE_GC_REVOKE  - Revoke clone invocation status which has been  *                        expired instead of removing and freeing it.  * SND_CLONE_WAITOK     - malloc() is allowed to sleep while allocating  *                        clone entry.  */
end_comment

begin_define
define|#
directive|define
name|SND_CLONE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_UNREF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_LASTREF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_EXPIRED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_REVOKE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SND_CLONE_WAITOK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SND_CLONE_GC_MASK
value|(SND_CLONE_GC_ENABLE  |			\ 				 SND_CLONE_GC_UNREF   |			\ 				 SND_CLONE_GC_LASTREF |			\ 				 SND_CLONE_GC_EXPIRED |			\ 				 SND_CLONE_GC_REVOKE)
end_define

begin_define
define|#
directive|define
name|SND_CLONE_MASK
value|(SND_CLONE_ENABLE | SND_CLONE_GC_MASK |	\ 				 SND_CLONE_WAITOK)
end_define

begin_comment
comment|/*  * Runtime clone device flags  *  * These are mostly private to the clone manager operation:  *  * SND_CLONE_NEW    - New clone allocation in progress.  * SND_CLONE_INVOKE - Cloning being invoked, waiting for next VFS operation.  * SND_CLONE_BUSY   - In progress, being referenced by living thread/proc.  */
end_comment

begin_define
define|#
directive|define
name|SND_CLONE_NEW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SND_CLONE_INVOKE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SND_CLONE_BUSY
value|0x00000004
end_define

begin_comment
comment|/*  * Nothing important, just for convenience.  */
end_comment

begin_define
define|#
directive|define
name|SND_CLONE_ALLOC
value|(SND_CLONE_NEW | SND_CLONE_INVOKE |	\ 				 SND_CLONE_BUSY)
end_define

begin_define
define|#
directive|define
name|SND_CLONE_DEVMASK
value|SND_CLONE_ALLOC
end_define

begin_function_decl
name|void
name|snd_timestamp
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|snd_clone
modifier|*
name|snd_clone_create
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_busy
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_enable
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_disable
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_getsize
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_getmaxunit
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_setmaxunit
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_getdeadline
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_setdeadline
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_gettime
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_clone_getflags
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_clone_setflags
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_getdevtime
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_clone_getdevflags
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|snd_clone_setdevflags
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_gc
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_clone_destroy
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_acquire
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_release
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_ref
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_clone_unref
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_clone_register
parameter_list|(
name|struct
name|snd_clone_entry
modifier|*
parameter_list|,
name|struct
name|cdev
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|snd_clone_entry
modifier|*
name|snd_clone_alloc
parameter_list|(
name|struct
name|snd_clone
modifier|*
parameter_list|,
name|struct
name|cdev
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|snd_clone_enabled
parameter_list|(
name|x
parameter_list|)
value|((x) != NULL&& 			\ 				(snd_clone_getflags(x)& SND_CLONE_ENABLE))
end_define

begin_define
define|#
directive|define
name|snd_clone_disabled
parameter_list|(
name|x
parameter_list|)
value|(!snd_clone_enabled(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SND_CLONE_H */
end_comment

end_unit

