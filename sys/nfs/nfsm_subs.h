begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.2 (Berkeley) 3/30/95  * $FreeBSD$  */
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

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|nfsm_reqh
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|u_long
name|procid
operator|,
name|int
name|hsiz
operator|,
name|caddr_t
operator|*
name|bposp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|nfsm_rpchead
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cr
operator|,
name|int
name|nmflag
operator|,
name|int
name|procid
operator|,
name|int
name|auth_type
operator|,
name|int
name|auth_len
operator|,
name|char
operator|*
name|auth_str
operator|,
name|int
name|verf_len
operator|,
name|char
operator|*
name|verf_str
operator|,
expr|struct
name|mbuf
operator|*
name|mrest
operator|,
name|int
name|mrest_len
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mbp
operator|,
name|u_int32_t
operator|*
name|xidp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|NFSMADV
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		(m)->m_data += (s); \ 	} while (0)
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

begin_define
define|#
directive|define
name|nfsm_build
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		if ((s)> M_TRAILINGSPACE(mb)) { \ 			MGET(mb2, M_WAIT, MT_DATA); \ 			if ((s)> MLEN) \ 				panic("build> MLEN"); \ 			mb->m_next = mb2; \ 			mb = mb2; \ 			mb->m_len = 0; \ 			bpos = mtod(mb, caddr_t); \ 		} \ 		(a) = (c)(bpos); \ 		mb->m_len += (s); \ 		bpos += (s); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_dissect
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			(a) = (c)(dpos); \ 			dpos += (s); \ 		} else if ((t1 = nfsm_disct(&md,&dpos, (s), t1,&cp2)) != 0){ \ 			error = t1; \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} else { \ 			(a) = (c)cp2; \ 		} \ 	} while (0)
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
value|do { \ 		if (v3) { \ 			t2 = nfsm_rndup(VTONFS(v)->n_fhsize) + NFSX_UNSIGNED; \ 			if (t2<= M_TRAILINGSPACE(mb)) { \ 				nfsm_build(tl, u_int32_t *, t2); \ 				*tl++ = txdr_unsigned(VTONFS(v)->n_fhsize); \ 				*(tl + ((t2>>2) - 2)) = 0; \ 				bcopy((caddr_t)VTONFS(v)->n_fhp,(caddr_t)tl, \ 					VTONFS(v)->n_fhsize); \ 			} else if ((t2 = nfsm_strtmbuf(&mb,&bpos, \ 				(caddr_t)VTONFS(v)->n_fhp, \ 				VTONFS(v)->n_fhsize)) != 0) { \ 				error = t2; \ 				m_freem(mreq); \ 				goto nfsmout; \ 			} \ 		} else { \ 			nfsm_build(cp, caddr_t, NFSX_V2FH); \ 			bcopy((caddr_t)VTONFS(v)->n_fhp, cp, NFSX_V2FH); \ 		} \ 	} while (0)
end_define

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
value|do { \ 		if (v3) { \ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED + NFSX_V3FH);\ 			*tl++ = txdr_unsigned(NFSX_V3FH); \ 			bcopy((caddr_t)(f), (caddr_t)tl, NFSX_V3FH); \ 		} else { \ 			nfsm_build(cp, caddr_t, NFSX_V2FH); \ 			bcopy((caddr_t)(f), cp, NFSX_V2FH); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvpostop_fh
parameter_list|(
name|f
parameter_list|)
define|\
value|do { \ 		nfsm_build(tl, u_int32_t *, 2 * NFSX_UNSIGNED + NFSX_V3FH); \ 		*tl++ = nfs_true; \ 		*tl++ = txdr_unsigned(NFSX_V3FH); \ 		bcopy((caddr_t)(f), (caddr_t)tl, NFSX_V3FH); \ 	} while (0)
end_define

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
value|do { \ 		struct nfsnode *ttnp; nfsfh_t *ttfhp; int ttfhsize; \ 		if (v3) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			(f) = fxdr_unsigned(int, *tl); \ 		} else \ 			(f) = 1; \ 		if (f) { \ 			nfsm_getfh(ttfhp, ttfhsize, (v3)); \ 			if ((t1 = nfs_nget((d)->v_mount, ttfhp, ttfhsize, \&ttnp)) != 0) { \ 				error = t1; \ 				m_freem(mrep); \ 				goto nfsmout; \ 			} \ 			(v) = NFSTOV(ttnp); \ 		} \ 		if (v3) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			if (f) \ 				(f) = fxdr_unsigned(int, *tl); \ 			else if (fxdr_unsigned(int, *tl)) \ 				nfsm_adv(NFSX_V3FATTR); \ 		} \ 		if (f) \ 			nfsm_loadattr((v), (struct vattr *)0); \ 	} while (0)
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
value|do { \ 		if (v3) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			if (((s) = fxdr_unsigned(int, *tl))<= 0 || \ 				(s)> NFSX_V3FHMAX) { \ 				m_freem(mrep); \ 				error = EBADRPC; \ 				goto nfsmout; \ 			} \ 		} else \ 			(s) = NFSX_V2FH; \ 		nfsm_dissect((f), nfsfh_t *, nfsm_rndup(s)); \ 	} while (0)
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
value|do { \ 		struct vnode *ttvp = (v); \ 		if ((t1 = nfs_loadattrcache(&ttvp,&md,&dpos, (a), 0)) != 0) { \ 			error = t1; \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 		(v) = ttvp; \ 	} while (0)
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
value|do { \ 		struct vnode *ttvp = (v); \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (((f) = fxdr_unsigned(int, *tl)) != 0) { \ 			if ((t1 = nfs_loadattrcache(&ttvp,&md,&dpos, \ 				(struct vattr *)0, 1)) != 0) { \ 				error = t1; \ 				(f) = 0; \ 				m_freem(mrep); \ 				goto nfsmout; \ 			} \ 			(v) = ttvp; \ 		} \ 	} while (0)
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
value|do { \ 		int ttattrf, ttretf = 0; \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (*tl == nfs_true) { \ 			nfsm_dissect(tl, u_int32_t *, 6 * NFSX_UNSIGNED); \ 			if (f) \ 				ttretf = (VTONFS(v)->n_mtime == \ 					fxdr_unsigned(u_int32_t, *(tl + 2))); \ 		} \ 		nfsm_postop_attr((v), ttattrf); \ 		if (f) { \ 			(f) = ttretf; \ 		} else { \ 			(f) = ttattrf; \ 		} \ 	} while (0)
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
value|do { \ 		if ((a)->va_mode != (mode_t)VNOVAL) {			\ 			nfsm_build(tl, u_int32_t *, 2 * NFSX_UNSIGNED);	\ 			*tl++ = nfs_true;				\ 			*tl = txdr_unsigned((a)->va_mode);		\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = nfs_false;				\ 		}							\ 		if ((full)&& (a)->va_uid != (uid_t)VNOVAL) {		\ 			nfsm_build(tl, u_int32_t *, 2 * NFSX_UNSIGNED);	\ 			*tl++ = nfs_true;				\ 			*tl = txdr_unsigned((a)->va_uid);		\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = nfs_false;				\ 		}							\ 		if ((full)&& (a)->va_gid != (gid_t)VNOVAL) {		\ 			nfsm_build(tl, u_int32_t *, 2 * NFSX_UNSIGNED);	\ 			*tl++ = nfs_true;				\ 			*tl = txdr_unsigned((a)->va_gid);		\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = nfs_false;				\ 		}							\ 		if ((full)&& (a)->va_size != VNOVAL) {			\ 			nfsm_build(tl, u_int32_t *, 3 * NFSX_UNSIGNED);	\ 			*tl++ = nfs_true;				\ 			txdr_hyper((a)->va_size, tl);			\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = nfs_false;				\ 		}							\ 		if ((a)->va_atime.tv_sec != VNOVAL) {			\ 			if ((a)->va_atime.tv_sec != time_second) {	\ 				nfsm_build(tl, u_int32_t *, 3 * NFSX_UNSIGNED);\ 				*tl++ = txdr_unsigned(NFSV3SATTRTIME_TOCLIENT);\ 				txdr_nfsv3time(&(a)->va_atime, tl);	\ 			} else {					\ 				nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED); \ 				*tl = txdr_unsigned(NFSV3SATTRTIME_TOSERVER); \ 			}						\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = txdr_unsigned(NFSV3SATTRTIME_DONTCHANGE);	\ 		}							\ 		if ((a)->va_mtime.tv_sec != VNOVAL) {			\ 			if ((a)->va_mtime.tv_sec != time_second) {	\ 				nfsm_build(tl, u_int32_t *, 3 * NFSX_UNSIGNED);\ 				*tl++ = txdr_unsigned(NFSV3SATTRTIME_TOCLIENT);\ 				txdr_nfsv3time(&(a)->va_mtime, tl);	\ 			} else {					\ 				nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED); \ 				*tl = txdr_unsigned(NFSV3SATTRTIME_TOSERVER); \ 			}						\ 		} else {						\ 			nfsm_build(tl, u_int32_t *, NFSX_UNSIGNED);	\ 			*tl = txdr_unsigned(NFSV3SATTRTIME_DONTCHANGE);	\ 		}							\ 	} while (0)
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
value|do { \ 		nfsm_dissect(tl,u_int32_t *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(int32_t,*tl))> (m)) { \ 			m_freem(mrep); \ 			error = EBADRPC; \ 			goto nfsmout; \ 		} \ 	} while (0)
end_define

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
value|do { \ 		nfsm_dissect(tl,u_int32_t *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(int32_t,*tl))> (m) || (s)<= 0) { \ 			error = EBADRPC; \ 			nfsm_reply(0); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvnamesiz
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 		nfsm_dissect(tl,u_int32_t *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(int32_t,*tl))> NFS_MAXNAMLEN) \ 			error = NFSERR_NAMETOL; \ 		if ((s)<= 0) \ 			error = EBADRPC; \ 		if (error) \ 			nfsm_reply(0); \ 	} while (0)
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
value|do {\ 		if ((s)> 0&& \ 		   (t1 = nfsm_mbuftouio(&md,(p),(s),&dpos)) != 0) { \ 			error = t1; \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 	} while (0)
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
value|do { \ 		if ((t1 = nfsm_uiotombuf((p),&mb,(s),&bpos)) != 0) { \ 			error = t1; \ 			m_freem(mreq); \ 			goto nfsmout; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_reqhead
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		mb = mreq = nfsm_reqh((v),(a),(s),&bpos); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_reqdone
define|\
value|do { \ 		m_freem(mrep); \ 		nfsmout: \ 	} while (0)
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
value|do { \ 		if ((error = nfs_request((v), mreq, (t), (p), \ 		   (c),&mrep,&md,&dpos)) != 0) { \ 			if (error& NFSERR_RETERR) \ 				error&= ~NFSERR_RETERR; \ 			else \ 				goto nfsmout; \ 		} \ 	} while (0)
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
value|do {\ 		if ((s)> (m)) { \ 			m_freem(mreq); \ 			error = ENAMETOOLONG; \ 			goto nfsmout; \ 		} \ 		t2 = nfsm_rndup(s)+NFSX_UNSIGNED; \ 		if (t2<= M_TRAILINGSPACE(mb)) { \ 			nfsm_build(tl,u_int32_t *,t2); \ 			*tl++ = txdr_unsigned(s); \ 			*(tl+((t2>>2)-2)) = 0; \ 			bcopy((const char *)(a), (caddr_t)tl, (s)); \ 		} else if ((t2 = nfsm_strtmbuf(&mb,&bpos, (a), (s))) != 0) { \ 			error = t2; \ 			m_freem(mreq); \ 			goto nfsmout; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvdone
define|\
value|do { \ 		nfsmout: \ 		return (error); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_reply
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 		nfsd->nd_repstat = error; \ 		if (error&& !(nfsd->nd_flag& ND_NFSV3)) \ 		   (void) nfs_rephead(0, nfsd, slp, error, cache,&frev, \ 			mrq,&mb,&bpos); \ 		else \ 		   (void) nfs_rephead((s), nfsd, slp, error, cache,&frev, \ 			mrq,&mb,&bpos); \ 		if (mrep != NULL) { \ 			m_freem(mrep); \ 			mrep = NULL; \ 		} \ 		mreq = *mrq; \ 		if (error&& (!(nfsd->nd_flag& ND_NFSV3) || \ 			error == EBADRPC)) { \ 			error = 0; \ 			goto nfsmout; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_writereply
parameter_list|(
name|s
parameter_list|,
name|v3
parameter_list|)
define|\
value|do { \ 		nfsd->nd_repstat = error; \ 		if (error&& !(v3)) \ 		   (void) nfs_rephead(0, nfsd, slp, error, cache,&frev, \&mreq,&mb,&bpos); \ 		else \ 		   (void) nfs_rephead((s), nfsd, slp, error, cache,&frev, \&mreq,&mb,&bpos); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_adv
parameter_list|(
name|s
parameter_list|)
define|\
value|do { \ 		t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			dpos += (s); \ 		} else if ((t1 = nfs_adv(&md,&dpos, (s), t1)) != 0) { \ 			error = t1; \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvmtofh
parameter_list|(
name|f
parameter_list|)
define|\
value|do { \ 		int fhlen; \ 		if (nfsd->nd_flag& ND_NFSV3) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			fhlen = fxdr_unsigned(int, *tl); \ 			if (fhlen != 0&& fhlen != NFSX_V3FH) { \ 				error = EBADRPC; \ 				nfsm_reply(0); \ 			} \ 		} else { \ 			fhlen = NFSX_V2FH; \ 		} \ 		if (fhlen != 0) { \ 			nfsm_dissect(tl, u_int32_t *, fhlen); \ 			bcopy((caddr_t)tl, (caddr_t)(f), fhlen); \ 		} else {\ 			bzero((caddr_t)(f), NFSX_V3FH); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_clget
define|\
value|do { \ 		if (bp>= be) { \ 			if (mp == mb) \ 				mp->m_len += bp-bpos; \ 			MGET(mp, M_WAIT, MT_DATA); \ 			MCLGET(mp, M_WAIT); \ 			mp->m_len = NFSMSIZ(mp); \ 			mp2->m_next = mp; \ 			mp2 = mp; \ 			bp = mtod(mp, caddr_t); \ 			be = bp+mp->m_len; \ 		} \ 		tl = (u_int32_t *)bp; \ 	} while (0)
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
value|do { \ 		nfsm_srvfattr(nfsd, (a), (f)); \ 	} while (0)
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
value|do { \ 		nfsm_srvwcc(nfsd, (br), (b), (ar), (a),&mb,&bpos); \ 	} while (0)
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
value|do { \ 		nfsm_srvpostopattr(nfsd, (r), (a),&mb,&bpos); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|nfsm_srvsattr
parameter_list|(
name|a
parameter_list|)
define|\
value|do { \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (*tl == nfs_true) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			(a)->va_mode = nfstov_mode(*tl); \ 		} \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (*tl == nfs_true) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			(a)->va_uid = fxdr_unsigned(uid_t, *tl); \ 		} \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (*tl == nfs_true) { \ 			nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 			(a)->va_gid = fxdr_unsigned(gid_t, *tl); \ 		} \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		if (*tl == nfs_true) { \ 			nfsm_dissect(tl, u_int32_t *, 2 * NFSX_UNSIGNED); \ 			(a)->va_size = fxdr_hyper(tl); \ 		} \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		switch (fxdr_unsigned(int, *tl)) { \ 		case NFSV3SATTRTIME_TOCLIENT: \ 			nfsm_dissect(tl, u_int32_t *, 2 * NFSX_UNSIGNED); \ 			fxdr_nfsv3time(tl,&(a)->va_atime); \ 			break; \ 		case NFSV3SATTRTIME_TOSERVER: \ 			getnanotime(&(a)->va_atime); \ 			break; \ 		}; \ 		nfsm_dissect(tl, u_int32_t *, NFSX_UNSIGNED); \ 		switch (fxdr_unsigned(int, *tl)) { \ 		case NFSV3SATTRTIME_TOCLIENT: \ 			nfsm_dissect(tl, u_int32_t *, 2 * NFSX_UNSIGNED); \ 			fxdr_nfsv3time(tl,&(a)->va_mtime); \ 			break; \ 		case NFSV3SATTRTIME_TOSERVER: \ 			getnanotime(&(a)->va_mtime); \ 			break; \ 		} \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

