begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)kinfo.h	7.4 (Berkeley) 6/28/90  */
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
comment|/*  * vnodes  */
end_comment

begin_define
define|#
directive|define
name|KINFO_VNODE
value|(2<<8)
end_define

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

