begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)uwait.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc68k
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68000
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|||
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s300
argument_list|)
operator|||
name|defined
argument_list|(
name|hp9000s800
argument_list|)
end_if

begin_define
define|#
directive|define
name|BITS_BIGENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_define
define|#
directive|define
name|BITS_LITTLENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|BITS_BIGENDIAN
operator|&&
operator|!
name|defined
name|BITS_LITTLENDIAN
end_if

begin_error
error|#
directive|error
error|Do not know my byte ordering
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure of the information in the first word returned by both  * wait and wait3.  If w_stopval==WSTOPPED, then the second structure  * describes the information returned, else the first.  See WUNTRACED below.  */
end_comment

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
comment|/* used in syscall */
comment|/* 	 * Terminated process status. 	 */
struct|struct
block|{
ifdef|#
directive|ifdef
name|BITS_LITTLENDIAN
name|unsigned
name|short
name|w_Termsig
range|:
literal|7
decl_stmt|;
comment|/* termination signal */
name|unsigned
name|short
name|w_Coredump
range|:
literal|1
decl_stmt|;
comment|/* core dump indicator */
name|unsigned
name|short
name|w_Retcode
range|:
literal|8
decl_stmt|;
comment|/* exit code if w_termsig==0 */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BITS_BIGENDIAN
name|unsigned
name|short
name|w_Fill1
range|:
literal|16
decl_stmt|;
comment|/* high 16 bits unused */
name|unsigned
name|short
name|w_Retcode
range|:
literal|8
decl_stmt|;
comment|/* exit code if w_termsig==0 */
name|unsigned
name|short
name|w_Coredump
range|:
literal|1
decl_stmt|;
comment|/* core dump indicator */
name|unsigned
name|short
name|w_Termsig
range|:
literal|7
decl_stmt|;
comment|/* termination signal */
endif|#
directive|endif
block|}
name|w_U
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|w_termsig
value|w_U.w_Termsig
end_define

begin_define
define|#
directive|define
name|w_coredump
value|w_U.w_Coredump
end_define

begin_define
define|#
directive|define
name|w_retcode
value|w_U.w_Retcode
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|x
parameter_list|)
value|((x).w_termsig != 0)
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|x
parameter_list|)
value|((x).w_termsig == 0)
end_define

end_unit

