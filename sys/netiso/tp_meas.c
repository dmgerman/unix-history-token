begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_meas.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_meas.c,v $  *  * tp_meas.c : create a performance measurement event  * in the circular buffer tp_Meas[]  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netiso/argo_debug.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_meas.h>
end_include

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
end_ifdef

begin_decl_stmt
name|int
name|tp_Measn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tp_Meas
name|tp_Meas
index|[
name|TPMEASN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * NAME:	 tpmeas()  *  * CALLED FROM: tp_emit(), tp_soisdisconecting(), tp_soisdisconnected()  *	tp0_stash(), tp_stash(), tp_send(), tp_goodack(), tp_usrreq()  *  * FUNCTION and ARGUMENTS:  *  stashes a performance-measurement event for the given reference (ref)  *  (kind) tells which kind of event, timev is the time to be stored  *  with this event, (seq), (win), and (size) are integers that usually  *  refer to the sequence number, window number (on send) and  *  size of tpdu or window.  *  * RETURNS:		Nada  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_function
name|void
name|Tpmeas
parameter_list|(
name|ref
parameter_list|,
name|kind
parameter_list|,
name|timev
parameter_list|,
name|seq
parameter_list|,
name|win
parameter_list|,
name|size
parameter_list|)
name|u_int
name|ref
decl_stmt|;
name|u_int
name|kind
decl_stmt|;
name|struct
name|timeval
modifier|*
name|timev
decl_stmt|;
name|u_int
name|seq
decl_stmt|,
name|win
decl_stmt|,
name|size
decl_stmt|;
block|{
specifier|register
name|struct
name|tp_Meas
modifier|*
name|tpm
decl_stmt|;
specifier|static
name|int
name|mseq
decl_stmt|;
name|tpm
operator|=
operator|&
name|tp_Meas
index|[
name|tp_Measn
operator|++
index|]
expr_stmt|;
name|tp_Measn
operator|%=
name|TPMEASN
expr_stmt|;
name|tpm
operator|->
name|tpm_kind
operator|=
name|kind
expr_stmt|;
name|tpm
operator|->
name|tpm_tseq
operator|=
name|mseq
operator|++
expr_stmt|;
name|tpm
operator|->
name|tpm_ref
operator|=
name|ref
expr_stmt|;
if|if
condition|(
name|kind
operator|==
name|TPtime_from_ll
condition|)
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|timev
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|tpm
operator|->
name|tpm_time
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|time
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|tpm
operator|->
name|tpm_time
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
expr_stmt|;
name|tpm
operator|->
name|tpm_seq
operator|=
name|seq
expr_stmt|;
name|tpm
operator|->
name|tpm_window
operator|=
name|win
expr_stmt|;
name|tpm
operator|->
name|tpm_size
operator|=
name|size
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP_PERF_MEAS */
end_comment

end_unit

