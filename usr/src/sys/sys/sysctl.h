begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)sysctl.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Get kernel info  */
end_comment

begin_define
define|#
directive|define
name|ki_op
parameter_list|(
name|x
parameter_list|)
value|((x)&0x0000ffff)
end_define

begin_define
define|#
directive|define
name|ki_type
parameter_list|(
name|x
parameter_list|)
value|((x)&0x0000ff00)
end_define

begin_comment
comment|/*   * proc info   */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC
value|(0<<8)
end_define

begin_define
define|#
directive|define
name|KINFO_PROC_ALL
value|(KINFO_PROC|0)
end_define

begin_comment
comment|/* everything */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_PID
value|(KINFO_PROC|1)
end_define

begin_comment
comment|/* by process id */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_PGRP
value|(KINFO_PROC|2)
end_define

begin_comment
comment|/* by process group id */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_SESSION
value|(KINFO_PROC|3)
end_define

begin_comment
comment|/* by session of pid */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_TTY
value|(KINFO_PROC|4)
end_define

begin_comment
comment|/* by controlling tty */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_UID
value|(KINFO_PROC|5)
end_define

begin_comment
comment|/* by effective uid */
end_comment

begin_define
define|#
directive|define
name|KINFO_PROC_RUID
value|(KINFO_PROC|6)
end_define

begin_comment
comment|/* by real uid */
end_comment

begin_comment
comment|/*   * proc ops return arrays of augmented proc structures  */
end_comment

begin_struct
struct|struct
name|kinfo_proc
block|{
name|struct
name|proc
name|kp_proc
decl_stmt|;
comment|/* proc structure */
struct|struct
name|eproc
block|{
name|struct
name|proc
modifier|*
name|e_paddr
decl_stmt|;
comment|/* address of proc */
name|struct
name|session
modifier|*
name|e_sess
decl_stmt|;
comment|/* session pointer */
name|pid_t
name|e_pgid
decl_stmt|;
comment|/* process group id */
name|short
name|e_jobc
decl_stmt|;
comment|/* job control counter */
name|dev_t
name|e_tdev
decl_stmt|;
comment|/* controlling tty */
name|pid_t
name|e_tpgid
decl_stmt|;
comment|/* tty process group id */
name|struct
name|session
modifier|*
name|e_tsess
decl_stmt|;
comment|/* tty session pointer */
define|#
directive|define
name|WMESGLEN
value|7
name|char
name|e_wmesg
index|[
name|WMESGLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* wchan message */
name|size_t
name|e_xsize
decl_stmt|;
comment|/* text size */
name|short
name|e_xrssize
decl_stmt|;
comment|/* text rss */
name|short
name|e_xccount
decl_stmt|;
comment|/* text references */
name|short
name|e_xswrss
decl_stmt|;
name|long
name|e_spare
index|[
literal|8
index|]
decl_stmt|;
block|}
name|kp_eproc
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Routing table  */
end_comment

begin_define
define|#
directive|define
name|ki_af
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x00ff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|KINFO_RT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|KINFO_RT_DUMP
value|(KINFO_RT|1)
end_define

begin_comment
comment|/* dump; may limit to a.f. */
end_comment

begin_define
define|#
directive|define
name|KINFO_RT_FLAGS
value|(KINFO_RT|2)
end_define

begin_comment
comment|/* by flags, e.g. RESOLVING */
end_comment

begin_comment
comment|/*  * Locking and stats  */
end_comment

begin_struct
struct|struct
name|kinfo_lock
block|{
name|int
name|kl_lock
decl_stmt|;
name|int
name|kl_want
decl_stmt|;
name|int
name|kl_locked
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|kinfo_lock
name|kinfo_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

