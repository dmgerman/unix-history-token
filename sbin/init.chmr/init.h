begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christoph Robitschko.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Defaults  */
end_comment

begin_define
define|#
directive|define
name|RETRYTIME
value|5*60
end_define

begin_define
define|#
directive|define
name|INIT_M2S_TERMTO
value|10
end_define

begin_define
define|#
directive|define
name|INIT_M2S_KILLTO
value|30
end_define

begin_define
define|#
directive|define
name|DEF_CHECKTIME
value|5
end_define

begin_define
define|#
directive|define
name|DEF_CHECKSTATUS
value|1
end_define

begin_define
define|#
directive|define
name|ALLOC_ARGV
value|4
end_define

begin_define
define|#
directive|define
name|CALLOUT_MINFREE
value|5
end_define

begin_define
define|#
directive|define
name|CALLOUT_CHUNK
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TESTRUN
end_ifndef

begin_define
define|#
directive|define
name|DEBUG_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|INIT_CONFIG
value|"/etc/init.conf"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TESTRUN */
end_comment

begin_define
define|#
directive|define
name|DEBUG_LEVEL
value|5
end_define

begin_define
define|#
directive|define
name|INIT_CONFIG
value|"./init.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TESTRUN */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retrytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|ienviron
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sigset_t
name|block_set
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|blocksig
parameter_list|()
value|sigprocmask(SIG_BLOCK,&block_set, 0)
end_define

begin_define
define|#
directive|define
name|unblocksig
parameter_list|()
value|sigprocmask(SIG_UNBLOCK,&block_set, 0)
end_define

begin_comment
comment|/* internal representation of getty table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ttytab
block|{
name|struct
name|ttytab
modifier|*
name|next
decl_stmt|;
name|struct
name|ttytab
modifier|*
name|prev
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* argv for execve() */
name|char
modifier|*
name|type
decl_stmt|;
comment|/* terminal type */
name|int
name|intflags
decl_stmt|;
comment|/* internal flags, see below */
name|pid_t
name|pid
decl_stmt|;
comment|/* PID of spawned process */
name|int
name|failcount
decl_stmt|;
comment|/* how often getty exited with error */
name|time_t
name|starttime
decl_stmt|;
comment|/* when it was started */
block|}
name|ttytab_t
typedef|;
end_typedef

begin_comment
comment|/* Values for intflags: */
end_comment

begin_define
define|#
directive|define
name|INIT_SEEN
value|0x001
end_define

begin_define
define|#
directive|define
name|INIT_CHANGED
value|0x002
end_define

begin_define
define|#
directive|define
name|INIT_NEW
value|0x004
end_define

begin_define
define|#
directive|define
name|INIT_FAILED
value|0x008
end_define

begin_comment
comment|/* process exited with error code last time */
end_comment

begin_define
define|#
directive|define
name|INIT_OPEN
value|0x010
end_define

begin_comment
comment|/* Init has to do the open() */
end_comment

begin_define
define|#
directive|define
name|INIT_NODEV
value|0x020
end_define

begin_comment
comment|/* do not append device to argv */
end_comment

begin_define
define|#
directive|define
name|INIT_DONTSPAWN
value|0x040
end_define

begin_comment
comment|/* do not respawn a process on this line */
end_comment

begin_define
define|#
directive|define
name|INIT_ARG0
value|0x080
end_define

begin_comment
comment|/* don't pass command as argv[0] */
end_comment

begin_define
define|#
directive|define
name|INIT_FAILSLEEP
value|0x100
end_define

begin_comment
comment|/* getty is asleep before it is retried */
end_comment

begin_comment
comment|/* type field for callout table */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CO_ENT2TAB
block|,
comment|/* retry multiuser() */
name|CO_FORK
block|,
comment|/* retry do_getty(tt) */
name|CO_GETTY
block|,
comment|/* retry do_getty(tt) */
name|CO_MUL2SIN
block|,
comment|/* timeout in multi2single */
block|}
name|retr_t
typedef|;
end_typedef

begin_comment
comment|/* format of callout table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|callout
block|{
name|struct
name|callout
modifier|*
name|next
decl_stmt|;
name|unsigned
name|int
name|sleept
decl_stmt|;
name|retr_t
name|what
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
name|callout_t
typedef|;
end_typedef

end_unit

