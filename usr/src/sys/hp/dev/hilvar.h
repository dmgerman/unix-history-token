begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: hilvar.h 1.3 92/01/21$  *  *	@(#)hilvar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NHILD
value|8
end_define

begin_comment
comment|/* 7 actual + loop pseudo (dev 0) */
end_comment

begin_define
define|#
directive|define
name|NHILQ
value|8
end_define

begin_comment
comment|/* must be<= sizeof(int) */
end_comment

begin_define
define|#
directive|define
name|HILBUFSIZE
value|40
end_define

begin_comment
comment|/* size of interrupt poll buffer */
end_comment

begin_define
define|#
directive|define
name|HILMAXCLIST
value|1024
end_define

begin_comment
comment|/* max chars in clists for HPUX io */
end_comment

begin_define
define|#
directive|define
name|HILLOOPDEV
value|0
end_define

begin_comment
comment|/* loop device index */
end_comment

begin_comment
comment|/*  * Minor device numbers.  * HP-UX uses 12 bits of the form:  *	LLLLDDDD0000  * where L is 4 bits of loop number, D 4 bits of device and 4 bits of 0.  * BSD uses 8 bits:  *	LLLLDDDD  * Device files are in BSD format, we map device numbers to HP-UX format  * on stat calls.  */
end_comment

begin_define
define|#
directive|define
name|HILUNIT
parameter_list|(
name|d
parameter_list|)
value|((d)& 0xF)
end_define

begin_define
define|#
directive|define
name|HILLOOP
parameter_list|(
name|d
parameter_list|)
value|(((d)>>4)& 0xF)
end_define

begin_define
define|#
directive|define
name|hildevmask
parameter_list|(
name|d
parameter_list|)
value|(1<< (d))
end_define

begin_define
define|#
directive|define
name|hilqmask
parameter_list|(
name|q
parameter_list|)
value|(1<< (q))
end_define

begin_struct
struct|struct
name|hiliqueue
block|{
name|HILQ
modifier|*
name|hq_eventqueue
decl_stmt|;
comment|/* input queue shared with user */
name|struct
name|proc
modifier|*
name|hq_procp
decl_stmt|;
comment|/* process this queue belongs to */
name|char
name|hq_devmask
decl_stmt|;
comment|/* devices mapped to this queue */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hilloopdev
block|{
name|int
name|hd_flags
decl_stmt|;
comment|/* device state */
name|int
name|hd_qmask
decl_stmt|;
comment|/* queues this device is mapped to */
name|struct
name|clist
name|hd_queue
decl_stmt|;
comment|/* event queue for HPUX-style input */
name|struct
name|selinfo
name|hd_selr
decl_stmt|;
comment|/* process read selecting */
name|uid_t
name|hd_uid
decl_stmt|;
comment|/* uid of mapping process */
block|}
struct|;
end_struct

begin_comment
comment|/* hd_flags */
end_comment

begin_define
define|#
directive|define
name|HIL_ALIVE
value|0x01
end_define

begin_comment
comment|/* device is present */
end_comment

begin_define
define|#
directive|define
name|HIL_PSEUDO
value|0x02
end_define

begin_comment
comment|/* device is virtual */
end_comment

begin_define
define|#
directive|define
name|HIL_READIN
value|0x04
end_define

begin_comment
comment|/* device using read() input interface */
end_comment

begin_define
define|#
directive|define
name|HIL_QUEUEIN
value|0x08
end_define

begin_comment
comment|/* device using shared Q input interface */
end_comment

begin_define
define|#
directive|define
name|HIL_NOBLOCK
value|0x20
end_define

begin_comment
comment|/* device is in non-blocking read mode */
end_comment

begin_define
define|#
directive|define
name|HIL_ASLEEP
value|0x40
end_define

begin_comment
comment|/* process awaiting input on device */
end_comment

begin_define
define|#
directive|define
name|HIL_DERROR
value|0x80
end_define

begin_comment
comment|/* loop has reconfigured, reality altered */
end_comment

begin_struct
struct|struct
name|hilloop
block|{
name|struct
name|hil_dev
modifier|*
name|hl_addr
decl_stmt|;
comment|/* base of hardware registers */
name|u_char
name|hl_cmddone
decl_stmt|;
comment|/* */
name|u_char
name|hl_cmdending
decl_stmt|;
comment|/* */
name|u_char
name|hl_actdev
decl_stmt|;
comment|/* current input device */
name|u_char
name|hl_cmddev
decl_stmt|;
comment|/* device to perform command on */
name|u_char
name|hl_pollbuf
index|[
name|HILBUFSIZE
index|]
decl_stmt|;
comment|/* interrupt time input buffer */
name|u_char
name|hl_cmdbuf
index|[
name|HILBUFSIZE
index|]
decl_stmt|;
comment|/* */
name|u_char
modifier|*
name|hl_pollbp
decl_stmt|;
comment|/* pointer into hl_pollbuf */
name|u_char
modifier|*
name|hl_cmdbp
decl_stmt|;
comment|/* pointer into hl_cmdbuf */
name|struct
name|hiliqueue
name|hl_queue
index|[
name|NHILQ
index|]
decl_stmt|;
comment|/* input queues */
name|struct
name|hilloopdev
name|hl_device
index|[
name|NHILD
index|]
decl_stmt|;
comment|/* device data */
name|u_char
name|hl_maxdev
decl_stmt|;
comment|/* number of devices on loop */
name|u_char
name|hl_kbddev
decl_stmt|;
comment|/* keyboard device on loop */
name|u_char
name|hl_kbdlang
decl_stmt|;
comment|/* keyboard language */
name|u_char
name|hl_kbdflags
decl_stmt|;
comment|/* keyboard state */
block|}
struct|;
end_struct

begin_comment
comment|/* hl_kbdflags */
end_comment

begin_define
define|#
directive|define
name|KBD_RAW
value|0x01
end_define

begin_comment
comment|/* keyboard is raw */
end_comment

begin_define
define|#
directive|define
name|KBD_AR1
value|0x02
end_define

begin_comment
comment|/* keyboard auto-repeat rate 1 */
end_comment

begin_define
define|#
directive|define
name|KBD_AR2
value|0x04
end_define

begin_comment
comment|/* keyboard auto-repeat rate 2 */
end_comment

end_unit

