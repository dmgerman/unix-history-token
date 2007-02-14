begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSSERVER_NFSM_SUBS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSSERVER_NFSM_SUBS_H_
end_define

begin_include
include|#
directive|include
file|<nfs/nfs_common.h>
end_include

begin_define
define|#
directive|define
name|nfstov_mode
parameter_list|(
name|a
parameter_list|)
value|(fxdr_unsigned(u_int32_t, (a))& ALLPERMS)
end_define

begin_comment
comment|/*  * These macros do strange and peculiar things to mbuf chains for  * the assistance of the nfs code. To attempt to use them for any  * other purpose will be dangerous. (they make weird assumptions)  */
end_comment

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
comment|/* ************************************* */
end_comment

begin_comment
comment|/* Dissection phase macros */
end_comment

begin_function_decl
name|int
name|nfsm_srvstrsiz_xx
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
name|nfsm_srvnamesiz_xx
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
name|nfsm_srvnamesiz0_xx
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
name|nfsm_srvmtofh_xx
parameter_list|(
name|fhandle_t
modifier|*
name|f
parameter_list|,
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
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
name|nfsm_srvsattr_xx
parameter_list|(
name|struct
name|vattr
modifier|*
name|a
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
name|nfsm_srvstrsiz
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_srvstrsiz_xx(&(s), (m),&md,&dpos); \ 	if (t1) { \ 		error = t1; \ 		nfsm_reply(0); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvnamesiz
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_srvnamesiz_xx(&(s), NFS_MAXNAMLEN,&md,&dpos); \ 	if (t1) { \ 		error = t1; \ 		nfsm_reply(0); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvpathsiz
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_srvnamesiz0_xx(&(s), NFS_MAXPATHLEN,&md,&dpos); \ 	if (t1) { \ 		error = t1; \ 		nfsm_reply(0); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvmtofh
parameter_list|(
name|f
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_srvmtofh_xx((f), nfsd,&md,&dpos); \ 	if (t1) { \ 		error = t1; \ 		nfsm_reply(0); \ 	} \ } while (0)
end_define

begin_comment
comment|/* XXX why is this different? */
end_comment

begin_define
define|#
directive|define
name|nfsm_srvsattr
parameter_list|(
name|a
parameter_list|)
define|\
value|do { \ 	int t1; \ 	t1 = nfsm_srvsattr_xx((a),&md,&dpos); \ 	if (t1) { \ 		error = t1; \ 		m_freem(mrep); \ 		mrep = NULL; \ 		goto nfsmout; \ 	} \ } while (0)
end_define

begin_comment
comment|/* ************************************* */
end_comment

begin_comment
comment|/* Prepare the reply */
end_comment

begin_define
define|#
directive|define
name|nfsm_reply
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 	if (mrep != NULL) { \ 		m_freem(mrep); \ 		mrep = NULL; \ 	} \ 	mreq = nfs_rephead((s), nfsd, error,&mb,&bpos); \ 	*mrq = mreq; \ 	if (error == EBADRPC) { \ 		error = 0; \ 		goto nfsmout; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_writereply
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 	mreq = nfs_rephead((s), nfsd, error,&mb,&bpos); \ } while(0)
end_define

begin_comment
comment|/* ************************************* */
end_comment

begin_comment
comment|/* Reply phase macros - add additional reply info */
end_comment

begin_function_decl
name|void
name|nfsm_srvfhtom_xx
parameter_list|(
name|fhandle_t
modifier|*
name|f
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
name|nfsm_srvpostop_fh_xx
parameter_list|(
name|fhandle_t
modifier|*
name|f
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
name|nfsm_clget_xx
parameter_list|(
name|u_int32_t
modifier|*
modifier|*
name|tl
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mb
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|char
modifier|*
modifier|*
name|bp
parameter_list|,
name|char
modifier|*
modifier|*
name|be
parameter_list|,
name|caddr_t
name|bpos
parameter_list|,
name|int
name|droplock
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|nfsm_srvfhtom
parameter_list|(
name|f
parameter_list|,
name|v3
parameter_list|)
define|\
value|nfsm_srvfhtom_xx((f), (v3),&mb,&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_srvpostop_fh
parameter_list|(
name|f
parameter_list|)
define|\
value|nfsm_srvpostop_fh_xx((f),&mb,&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_srvwcc_data
parameter_list|(
name|br
parameter_list|,
name|b
parameter_list|,
name|ar
parameter_list|,
name|a
parameter_list|)
define|\
value|nfsm_srvwcc(nfsd, (br), (b), (ar), (a),&mb,&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_srvpostop_attr
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
define|\
value|nfsm_srvpostopattr(nfsd, (r), (a),&mb,&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_srvfillattr
parameter_list|(
name|a
parameter_list|,
name|f
parameter_list|)
define|\
value|nfsm_srvfattr(nfsd, (a), (f))
end_define

begin_define
define|#
directive|define
name|nfsm_clget
define|\
value|nfsm_clget_xx(&tl, mb,&mp,&bp,&be, bpos, 1)
end_define

begin_define
define|#
directive|define
name|nfsm_clget_nolock
define|\
value|nfsm_clget_xx(&tl, mb,&mp,&bp,&be, bpos, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

