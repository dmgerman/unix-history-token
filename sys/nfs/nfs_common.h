begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFS_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFS_COMMON_H_
end_define

begin_decl_stmt
specifier|extern
name|enum
name|vtype
name|nv3tov_type
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|nfstype
name|nfsv3_type
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|vtonfsv2_mode
parameter_list|(
name|t
parameter_list|,
name|m
parameter_list|)
define|\
value|txdr_unsigned(((t) == VFIFO) ? MAKEIMODE(VCHR, (m)) : MAKEIMODE((t), (m)))
end_define

begin_define
define|#
directive|define
name|nfsv3tov_type
parameter_list|(
name|a
parameter_list|)
value|nv3tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
end_define

begin_define
define|#
directive|define
name|vtonfsv3_type
parameter_list|(
name|a
parameter_list|)
value|txdr_unsigned(nfsv3_type[((int32_t)(a))])
end_define

begin_function_decl
name|int
name|nfs_adv
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_quad_t
name|nfs_curusec
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|nfsm_disct
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ****************************** */
end_comment

begin_comment
comment|/* Build request/reply phase macros */
end_comment

begin_function_decl
name|void
modifier|*
name|nfsm_build_xx
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mb
parameter_list|,
name|caddr_t
modifier|*
name|bpos
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nfsm_build
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|(c)nfsm_build_xx((s),&mb,&bpos)
end_define

begin_comment
comment|/* ****************************** */
end_comment

begin_comment
comment|/* Interpretation phase macros */
end_comment

begin_function_decl
name|void
modifier|*
name|nfsm_dissect_xx
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|md
parameter_list|,
name|caddr_t
modifier|*
name|dpos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_strsiz_xx
parameter_list|(
name|int
modifier|*
name|s
parameter_list|,
name|int
name|m
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|md
parameter_list|,
name|caddr_t
modifier|*
name|dpos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_adv_xx
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|md
parameter_list|,
name|caddr_t
modifier|*
name|dpos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error check helpers */
end_comment

begin_define
define|#
directive|define
name|nfsm_dcheck
parameter_list|(
name|t1
parameter_list|,
name|mrep
parameter_list|)
define|\
value|do { \ 	if (t1 != 0) { \ 		error = t1; \ 		m_freem((mrep)); \ 		(mrep) = NULL; \ 		goto nfsmout; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_dcheckp
parameter_list|(
name|retp
parameter_list|,
name|mrep
parameter_list|)
define|\
value|do { \ 	if (retp == NULL) { \ 		error = EBADRPC; \ 		m_freem((mrep)); \ 		(mrep) = NULL; \ 		goto nfsmout; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_dissect
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|({ \ 	void *ret; \ 	ret = nfsm_dissect_xx((s),&md,&dpos); \ 	nfsm_dcheckp(ret, mrep); \ 	(c)ret; \ })
end_define

begin_define
define|#
directive|define
name|nfsm_strsiz
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_strsiz_xx(&(s), (m),&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while(0)
end_define

begin_define
define|#
directive|define
name|nfsm_mtouio
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|do {\ 	int32_t t1 = 0; \ 	if ((s)> 0) \ 		t1 = nfsm_mbuftouio(&md, (p), (s),&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_rndup
parameter_list|(
name|a
parameter_list|)
value|(((a)+3)&(~0x3))
end_define

begin_define
define|#
directive|define
name|nfsm_adv
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_adv_xx((s),&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

