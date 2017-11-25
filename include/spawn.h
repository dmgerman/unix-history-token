begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2008 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPAWN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPAWN_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sigset.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGSET_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SIGSET_T_DECLARED
end_define

begin_typedef
typedef|typedef
name|__sigset_t
name|sigset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|sched_param
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|__posix_spawnattr
modifier|*
name|posix_spawnattr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|__posix_spawn_file_actions
modifier|*
name|posix_spawn_file_actions_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|POSIX_SPAWN_RESETIDS
value|0x01
end_define

begin_define
define|#
directive|define
name|POSIX_SPAWN_SETPGROUP
value|0x02
end_define

begin_define
define|#
directive|define
name|POSIX_SPAWN_SETSCHEDPARAM
value|0x04
end_define

begin_define
define|#
directive|define
name|POSIX_SPAWN_SETSCHEDULER
value|0x08
end_define

begin_define
define|#
directive|define
name|POSIX_SPAWN_SETSIGDEF
value|0x10
end_define

begin_define
define|#
directive|define
name|POSIX_SPAWN_SETSIGMASK
value|0x20
end_define

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Spawn routines  *  * XXX both arrays should be __restrict, but this does not work when GCC  * is invoked with -std=c99.  */
name|int
name|posix_spawn
parameter_list|(
name|pid_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|posix_spawn_file_actions_t
modifier|*
parameter_list|,
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnp
parameter_list|(
name|pid_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|posix_spawn_file_actions_t
modifier|*
parameter_list|,
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * File descriptor actions  */
end_comment

begin_function_decl
name|int
name|posix_spawn_file_actions_init
parameter_list|(
name|posix_spawn_file_actions_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawn_file_actions_destroy
parameter_list|(
name|posix_spawn_file_actions_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawn_file_actions_addopen
parameter_list|(
name|posix_spawn_file_actions_t
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawn_file_actions_adddup2
parameter_list|(
name|posix_spawn_file_actions_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawn_file_actions_addclose
parameter_list|(
name|posix_spawn_file_actions_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Spawn attributes  */
end_comment

begin_function_decl
name|int
name|posix_spawnattr_init
parameter_list|(
name|posix_spawnattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_destroy
parameter_list|(
name|posix_spawnattr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getflags
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|short
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getpgroup
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|pid_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getschedparam
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|struct
name|sched_param
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getschedpolicy
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|int
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getsigdefault
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|sigset_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_getsigmask
parameter_list|(
specifier|const
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
name|sigset_t
modifier|*
name|__restrict
name|sigmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setflags
parameter_list|(
name|posix_spawnattr_t
modifier|*
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setpgroup
parameter_list|(
name|posix_spawnattr_t
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setschedparam
parameter_list|(
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|struct
name|sched_param
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setschedpolicy
parameter_list|(
name|posix_spawnattr_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setsigdefault
parameter_list|(
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_spawnattr_setsigmask
parameter_list|(
name|posix_spawnattr_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPAWN_H_ */
end_comment

end_unit

