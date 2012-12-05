begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSM_SUBS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSM_SUBS_H_
end_define

begin_comment
comment|/*  * These macros do strange and peculiar things to mbuf chains for  * the assistance of the nfs code. To attempt to use them for any  * other purpose will be dangerous. (they make weird assumptions)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APPLE
end_ifndef

begin_comment
comment|/*  * First define what the actual subs. return  */
end_comment

begin_define
define|#
directive|define
name|M_HASCL
parameter_list|(
name|m
parameter_list|)
value|((m)->m_flags& M_EXT)
end_define

begin_define
define|#
directive|define
name|NFSMINOFF
parameter_list|(
name|m
parameter_list|)
define|\
value|if (M_HASCL(m)) 					\ 			(m)->m_data = (m)->m_ext.ext_buf; 		\ 		else if ((m)->m_flags& M_PKTHDR) 			\ 			(m)->m_data = (m)->m_pktdat; 			\ 				else 					\ 			(m)->m_data = (m)->m_dat
end_define

begin_define
define|#
directive|define
name|NFSMSIZ
parameter_list|(
name|m
parameter_list|)
value|((M_HASCL(m))?MCLBYTES: 			\ 				(((m)->m_flags& M_PKTHDR)?MHLEN:MLEN))
end_define

begin_define
define|#
directive|define
name|NFSM_DATAP
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
value|(m)->m_data += (s)
end_define

begin_comment
comment|/*  * Now for the macros that do the simple stuff and call the functions  * for the hard stuff.  * They use fields in struct nfsrv_descript to handle the mbuf queues.  * Replace most of the macro with an inline function, to minimize  * the machine code. The inline functions in lower case can be called  * directly, bypassing the macro.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|nfsm_build
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nd
parameter_list|,
name|int
name|siz
parameter_list|)
block|{
name|void
modifier|*
name|retp
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb2
decl_stmt|;
if|if
condition|(
name|siz
operator|>
name|M_TRAILINGSPACE
argument_list|(
name|nd
operator|->
name|nd_mb
argument_list|)
condition|)
block|{
name|NFSMCLGET
argument_list|(
name|mb2
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|siz
operator|>
name|MLEN
condition|)
name|panic
argument_list|(
literal|"build> MLEN"
argument_list|)
expr_stmt|;
name|mbuf_setlen
argument_list|(
name|mb2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|nd
operator|->
name|nd_bpos
operator|=
name|NFSMTOD
argument_list|(
name|mb2
argument_list|,
name|caddr_t
argument_list|)
expr_stmt|;
name|nd
operator|->
name|nd_mb
operator|->
name|m_next
operator|=
name|mb2
expr_stmt|;
name|nd
operator|->
name|nd_mb
operator|=
name|mb2
expr_stmt|;
block|}
name|retp
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|nd
operator|->
name|nd_bpos
operator|)
expr_stmt|;
name|nd
operator|->
name|nd_mb
operator|->
name|m_len
operator|+=
name|siz
expr_stmt|;
name|nd
operator|->
name|nd_bpos
operator|+=
name|siz
expr_stmt|;
return|return
operator|(
name|retp
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NFSM_BUILD
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
value|((a) = (c)nfsm_build(nd, (s)))
end_define

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|nfsm_dissect
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nd
parameter_list|,
name|int
name|siz
parameter_list|)
block|{
name|int
name|tt1
decl_stmt|;
name|void
modifier|*
name|retp
decl_stmt|;
name|tt1
operator|=
name|NFSMTOD
argument_list|(
name|nd
operator|->
name|nd_md
argument_list|,
name|caddr_t
argument_list|)
operator|+
name|nd
operator|->
name|nd_md
operator|->
name|m_len
operator|-
name|nd
operator|->
name|nd_dpos
expr_stmt|;
if|if
condition|(
name|tt1
operator|>=
name|siz
condition|)
block|{
name|retp
operator|=
operator|(
name|void
operator|*
operator|)
name|nd
operator|->
name|nd_dpos
expr_stmt|;
name|nd
operator|->
name|nd_dpos
operator|+=
name|siz
expr_stmt|;
block|}
else|else
block|{
name|retp
operator|=
name|nfsm_dissct
argument_list|(
name|nd
argument_list|,
name|siz
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|retp
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NFSM_DISSECT
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|do {								\ 		(a) = (c)nfsm_dissect(nd, (s));	 			\ 		if ((a) == NULL) { 					\ 			error = EBADRPC; 				\ 			goto nfsmout; 					\ 		}							\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APPLE */
end_comment

begin_define
define|#
directive|define
name|NFSM_STRSIZ
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		tl = (u_int32_t *)nfsm_dissect(nd, NFSX_UNSIGNED);	\ 		if (!tl || ((s) = fxdr_unsigned(int32_t, *tl))> (m)) { \ 			error = EBADRPC; 				\ 			goto nfsmout; 					\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSM_RNDUP
parameter_list|(
name|a
parameter_list|)
value|(((a)+3)&(~0x3))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSM_SUBS_H_ */
end_comment

end_unit

