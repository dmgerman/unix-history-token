begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copryight 1997 Sean Eric Fagan  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Sean Eric Fagan  * 4. Neither the name of the author may be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  * procfs ioctl definitions.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PIOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PIOCTL_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|procfs_status
block|{
name|int
name|state
decl_stmt|;
comment|/* Running, stopped, something else? */
name|int
name|flags
decl_stmt|;
comment|/* Any flags */
name|unsigned
name|long
name|events
decl_stmt|;
comment|/* Events to stop on */
name|int
name|why
decl_stmt|;
comment|/* What event, if any, proc stopped on */
name|unsigned
name|long
name|val
decl_stmt|;
comment|/* Any extra data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PIOCBIS
value|_IOWINT('p', 1)
end_define

begin_comment
comment|/* Set event flag */
end_comment

begin_define
define|#
directive|define
name|PIOCBIC
value|_IOWINT('p', 2)
end_define

begin_comment
comment|/* Clear event flag */
end_comment

begin_define
define|#
directive|define
name|PIOCSFL
value|_IOWINT('p', 3)
end_define

begin_comment
comment|/* Set flags */
end_comment

begin_comment
comment|/* wait for proc to stop */
end_comment

begin_define
define|#
directive|define
name|PIOCWAIT
value|_IOR('p', 4, struct procfs_status)
end_define

begin_define
define|#
directive|define
name|PIOCCONT
value|_IOWINT('p', 5)
end_define

begin_comment
comment|/* Continue a process */
end_comment

begin_comment
comment|/* Get proc status */
end_comment

begin_define
define|#
directive|define
name|PIOCSTATUS
value|_IOR('p', 6, struct procfs_status)
end_define

begin_define
define|#
directive|define
name|PIOCGFL
value|_IOR('p', 7, unsigned int)
end_define

begin_comment
comment|/* Get flags */
end_comment

begin_define
define|#
directive|define
name|S_EXEC
value|0x00000001
end_define

begin_comment
comment|/* stop-on-exec */
end_comment

begin_define
define|#
directive|define
name|S_SIG
value|0x00000002
end_define

begin_comment
comment|/* stop-on-signal */
end_comment

begin_define
define|#
directive|define
name|S_SCE
value|0x00000004
end_define

begin_comment
comment|/* stop on syscall entry */
end_comment

begin_define
define|#
directive|define
name|S_SCX
value|0x00000008
end_define

begin_comment
comment|/* stop on syscall exit */
end_comment

begin_define
define|#
directive|define
name|S_CORE
value|0x00000010
end_define

begin_comment
comment|/* stop on coredump */
end_comment

begin_define
define|#
directive|define
name|S_EXIT
value|0x00000020
end_define

begin_comment
comment|/* stop on exit */
end_comment

begin_define
define|#
directive|define
name|S_ALLSTOPS
value|0x003f
end_define

begin_comment
comment|/* stop on all events */
end_comment

begin_comment
comment|/*  * If PF_LINGER is set in procp->p_pfsflags, then the last close  * of a /proc/<pid>/mem file will not clear out the stops and continue  * the process.  */
end_comment

begin_define
define|#
directive|define
name|PF_LINGER
value|0x01
end_define

begin_comment
comment|/* Keep stops around after last close */
end_comment

begin_define
define|#
directive|define
name|PF_ISUGID
value|0x02
end_define

begin_comment
comment|/* Ignore UID/GID changes */
end_comment

begin_define
define|#
directive|define
name|PF_FORK
value|0x04
end_define

begin_comment
comment|/* Retain settings on fork() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

