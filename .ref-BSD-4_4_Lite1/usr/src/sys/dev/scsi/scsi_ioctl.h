begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)scsi_ioctl.h	8.1 (Berkeley) 6/10/93  *  * from: $Header: scsi_ioctl.h,v 1.3 92/12/02 03:54:19 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI ioctls (`format' mode).  *  * Format mode allows a privileged process to issue direct SCSI commands  * to a drive (it is intended primarily to allow on-line formatting).  * SDIOCSFORMAT sets format mode (nonzero arg => on, zero arg => off).  * When in format mode, only the process that issued the SDIOCSFORMAT  * can read or write the drive.  *  * In format mode, the process is expected to  *	- do SDIOCSCSICOMMAND to supply cdb for next SCSI op  *	- do read or write as appropriate for cdb  *	- if I/O error, optionally do SDIOCSENSE to get completion  *	  status and sense data from last SCSI operation.  */
end_comment

begin_struct
struct|struct
name|scsi_fmt_sense
block|{
name|u_int
name|status
decl_stmt|;
comment|/* completion status of last op */
name|u_char
name|sense
index|[
literal|28
index|]
decl_stmt|;
comment|/* sense data (if any) from last op */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDIOCSFORMAT
value|_IOW('S', 1, int)
end_define

begin_define
define|#
directive|define
name|SDIOCGFORMAT
value|_IOR('S', 2, int)
end_define

begin_define
define|#
directive|define
name|SDIOCSCSICOMMAND
value|_IOW('S', 3, struct scsi_cdb)
end_define

begin_define
define|#
directive|define
name|SDIOCSENSE
value|_IOR('S', 4, struct scsi_fmt_sense)
end_define

end_unit

