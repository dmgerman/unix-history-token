begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)sysctl.h	7.1 (Berkeley) %G%  */
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
comment|/* proc ops return arrays of these */
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
name|struct
name|proc
modifier|*
name|kp_paddr
decl_stmt|;
comment|/* address of proc */
name|struct
name|session
modifier|*
name|kp_sess
decl_stmt|;
comment|/* session pointer */
name|pid_t
name|kp_pgid
decl_stmt|;
comment|/* process group id */
name|short
name|kp_jobc
decl_stmt|;
comment|/* job control counter */
name|dev_t
name|kp_tdev
decl_stmt|;
comment|/* controlling tty */
name|pid_t
name|kp_tpgid
decl_stmt|;
comment|/* foreground process group id */
name|struct
name|session
modifier|*
name|kp_tsess
decl_stmt|;
comment|/* terminal session pointer */
block|}
struct|;
end_struct

end_unit

