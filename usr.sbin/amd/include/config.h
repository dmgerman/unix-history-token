begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Get this in now so that OS_HDR can use it  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|P_void
value|void
end_define

begin_define
define|#
directive|define
name|Const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|P_void
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_define
define|#
directive|define
name|Const
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|INLINE
end_define

begin_comment
comment|/* __inline */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/*  * Pick up target dependent definitions  */
end_comment

begin_include
include|#
directive|include
file|"os-defaults.h"
end_include

begin_include
include|#
directive|include
include|OS_HDR
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VOIDP
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|voidp
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|voidp
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VOIDP */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|clocktime
parameter_list|()
value|(clock_valid ? clock_valid : time(&clock_valid))
end_define

begin_decl_stmt
specifier|extern
name|time_t
name|time
name|P
argument_list|(
operator|(
name|time_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|clock_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clock needs recalculating */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "amd"|"mmd" */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "kiska" */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mypid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current process id */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SYSLOG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|syslogging
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Really using syslog */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_SYSLOG */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|logfp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Log file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xlog_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logging level */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xlog_level_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|orig_umask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* umask() on startup */
end_comment

begin_define
define|#
directive|define
name|XLOG_FATAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|XLOG_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|XLOG_USER
value|0x0004
end_define

begin_define
define|#
directive|define
name|XLOG_WARNING
value|0x0008
end_define

begin_define
define|#
directive|define
name|XLOG_INFO
value|0x0010
end_define

begin_define
define|#
directive|define
name|XLOG_DEBUG
value|0x0020
end_define

begin_define
define|#
directive|define
name|XLOG_MAP
value|0x0040
end_define

begin_define
define|#
directive|define
name|XLOG_STATS
value|0x0080
end_define

begin_define
define|#
directive|define
name|XLOG_DEFSTR
value|"all,nomap,nostats"
end_define

begin_comment
comment|/* Default log options */
end_comment

begin_define
define|#
directive|define
name|XLOG_ALL
value|(XLOG_FATAL|XLOG_ERROR|XLOG_USER|XLOG_WARNING|XLOG_INFO|XLOG_MAP|XLOG_STATS)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|D_ALL
value|(~0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEM
end_ifdef

begin_define
define|#
directive|define
name|free
parameter_list|(
name|x
parameter_list|)
value|xfree(__FILE__,__LINE__,x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG_MEM */
end_comment

begin_define
define|#
directive|define
name|Debug
parameter_list|(
name|x
parameter_list|)
value|if (!(debug_flags& (x))) ; else
end_define

begin_define
define|#
directive|define
name|dlog
value|Debug(D_FULL) dplog
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*  * Option tables  */
end_comment

begin_struct
struct|struct
name|opt_tab
block|{
name|char
modifier|*
name|opt
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|opt_tab
name|xlog_opt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cmdoption
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|opt_tab
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|going_down
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dplog
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*extern void dplog P((char*, ...));*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_function_decl
specifier|extern
name|void
name|plog
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*extern void plog P((int, char*, ...));*/
end_comment

begin_decl_stmt
specifier|extern
name|void
name|show_opts
name|P
argument_list|(
operator|(
name|int
name|ch
operator|,
expr|struct
name|opt_tab
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|voidp
name|xmalloc
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|voidp
name|xrealloc
name|P
argument_list|(
operator|(
name|voidp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

