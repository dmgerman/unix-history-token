begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSM_SUBS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSM_SUBS_H_
end_define

begin_include
include|#
directive|include
file|<nfs/nfs_common.h>
end_include

begin_define
define|#
directive|define
name|nfsv2tov_type
parameter_list|(
name|a
parameter_list|)
value|nv2tov_type[fxdr_unsigned(u_int32_t,(a))&0x7]
end_define

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * These macros do strange and peculiar things to mbuf chains for  * the assistance of the nfs code. To attempt to use them for any  * other purpose will be dangerous. (they make weird assumptions)  */
end_comment

begin_comment
comment|/*  * First define what the actual subs. return  */
end_comment

begin_function_decl
name|struct
name|mbuf
modifier|*
name|nfsm_reqhead
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_long
name|procid
parameter_list|,
name|int
name|hsiz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|nfsm_rpchead
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|int
name|nmflag
parameter_list|,
name|int
name|procid
parameter_list|,
name|int
name|auth_type
parameter_list|,
name|int
name|auth_len
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mrest
parameter_list|,
name|int
name|mrest_len
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mbp
parameter_list|,
name|u_int32_t
modifier|*
name|xidp
parameter_list|)
function_decl|;
end_function_decl

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
value|do { \ 		if (M_HASCL(m)) \ 			(m)->m_data = (m)->m_ext.ext_buf; \ 		else if ((m)->m_flags& M_PKTHDR) \ 			(m)->m_data = (m)->m_pktdat; \ 		else \ 			(m)->m_data = (m)->m_dat; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NFSMSIZ
parameter_list|(
name|m
parameter_list|)
value|((M_HASCL(m))?MCLBYTES: \ 				(((m)->m_flags& M_PKTHDR)?MHLEN:MLEN))
end_define

begin_comment
comment|/*  * Now for the macros that do the simple stuff and call the functions  * for the hard stuff.  * These macros use several vars. declared in nfsm_reqhead and these  * vars. must not be used elsewhere unless you are careful not to corrupt  * them. The vars. starting with pN and tN (N=1,2,3,..) are temporaries  * that may be used so long as the value is not expected to retained  * after a macro.  * I know, this is kind of dorkey, but it makes the actual op functions  * fairly clean and deals with the mess caused by the xdr discriminating  * unions.  */
end_comment

begin_comment
comment|/* *********************************** */
end_comment

begin_comment
comment|/* Request generation phase macros */
end_comment

begin_function_decl
name|int
name|nfsm_fhtom_xx
parameter_list|(
name|struct
name|vnode
modifier|*
name|v
parameter_list|,
name|int
name|v3
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

begin_function_decl
name|void
name|nfsm_v3attrbuild_xx
parameter_list|(
name|struct
name|vattr
modifier|*
name|va
parameter_list|,
name|int
name|full
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

begin_function_decl
name|int
name|nfsm_strtom_xx
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|m
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
name|nfsm_bcheck
parameter_list|(
name|t1
parameter_list|,
name|mreq
parameter_list|)
define|\
value|do { \ 	if (t1) { \ 		error = t1; \ 		m_freem(mreq); \ 		goto nfsmout; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_fhtom
parameter_list|(
name|v
parameter_list|,
name|v3
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_fhtom_xx((v), (v3),&mb,&bpos); \ 	nfsm_bcheck(t1, mreq); \ } while (0)
end_define

begin_comment
comment|/* If full is true, set all fields, otherwise just set mode and time fields */
end_comment

begin_define
define|#
directive|define
name|nfsm_v3attrbuild
parameter_list|(
name|a
parameter_list|,
name|full
parameter_list|)
define|\
value|nfsm_v3attrbuild_xx(a, full,&mb,&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_uiotom
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_uiotombuf((p),&mb, (s),&bpos); \ 	nfsm_bcheck(t1, mreq); \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_strtom
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_strtom_xx((a), (s), (m),&mb,&bpos); \ 	nfsm_bcheck(t1, mreq); \ } while (0)
end_define

begin_comment
comment|/* *********************************** */
end_comment

begin_comment
comment|/* Send the request */
end_comment

begin_define
define|#
directive|define
name|nfsm_request
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
define|\
value|do { \ 	error = nfs_request((v), mreq, (t), (p), (c),&mrep,&md,&dpos); \ 	if (error != 0) { \ 		if (error& NFSERR_RETERR) \ 			error&= ~NFSERR_RETERR; \ 		else \ 			goto nfsmout; \ 	} \ } while (0)
end_define

begin_comment
comment|/* *********************************** */
end_comment

begin_comment
comment|/* Reply interpretation phase macros */
end_comment

begin_function_decl
name|int
name|nfsm_mtofh_xx
parameter_list|(
name|struct
name|vnode
modifier|*
name|d
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
name|v
parameter_list|,
name|int
name|v3
parameter_list|,
name|int
modifier|*
name|f
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
name|nfsm_getfh_xx
parameter_list|(
name|nfsfh_t
modifier|*
modifier|*
name|f
parameter_list|,
name|int
modifier|*
name|s
parameter_list|,
name|int
name|v3
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
name|nfsm_loadattr_xx
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|v
parameter_list|,
name|struct
name|vattr
modifier|*
name|va
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
name|nfsm_postop_attr_xx
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|v
parameter_list|,
name|int
modifier|*
name|f
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
name|nfsm_wcc_data_xx
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
name|v
parameter_list|,
name|int
modifier|*
name|f
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

begin_define
define|#
directive|define
name|nfsm_mtofh
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|,
name|v3
parameter_list|,
name|f
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_mtofh_xx((d),&(v), (v3),&(f),&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_getfh
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|v3
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_getfh_xx(&(f),&(s), (v3),&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_loadattr
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_loadattr_xx(&v, a,&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_postop_attr
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_postop_attr_xx(&v,&f,&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_comment
comment|/* Used as (f) for nfsm_wcc_data() */
end_comment

begin_define
define|#
directive|define
name|NFSV3_WCCRATTR
value|0
end_define

begin_define
define|#
directive|define
name|NFSV3_WCCCHK
value|1
end_define

begin_define
define|#
directive|define
name|nfsm_wcc_data
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
define|\
value|do { \ 	int32_t t1; \ 	t1 = nfsm_wcc_data_xx(&v,&f,&md,&dpos); \ 	nfsm_dcheck(t1, mrep); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

