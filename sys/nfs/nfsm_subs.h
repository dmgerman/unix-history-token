begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.1 (Berkeley) 6/16/93  * $FreeBSD$  */
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

begin_comment
comment|/*  * First define what the actual subs. return  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|nfsm_reqh
parameter_list|()
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
value|if (M_HASCL(m)) \ 			(m)->m_data = (m)->m_ext.ext_buf; \ 		else if ((m)->m_flags& M_PKTHDR) \ 			(m)->m_data = (m)->m_pktdat; \ 		else \ 			(m)->m_data = (m)->m_dat
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
value|(m)->m_data += (s)
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
value|{ if ((s)> M_TRAILINGSPACE(mb)) { \ 			MGET(mb2, M_WAIT, MT_DATA); \ 			if ((s)> MLEN) \ 				panic("build> MLEN"); \ 			mb->m_next = mb2; \ 			mb = mb2; \ 			mb->m_len = 0; \ 			bpos = mtod(mb, caddr_t); \ 		} \ 		(a) = (c)(bpos); \ 		mb->m_len += (s); \ 		bpos += (s); }
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
value|{ t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			(a) = (c)(dpos); \ 			dpos += (s); \ 		} else { \ 			error = nfsm_disct(&md,&dpos, (s), t1,&cp2); \ 			if (error) { \ 				m_freem(mrep); \ 				goto nfsmout; \ 			} else { \ 				(a) = (c)cp2; \ 			} \ 		} }
end_define

begin_define
define|#
directive|define
name|nfsm_fhtom
parameter_list|(
name|v
parameter_list|)
define|\
value|nfsm_build(cp,caddr_t,NFSX_FH); \ 		bcopy((caddr_t)&(VTONFS(v)->n_fh), cp, NFSX_FH)
end_define

begin_define
define|#
directive|define
name|nfsm_srvfhtom
parameter_list|(
name|f
parameter_list|)
define|\
value|nfsm_build(cp,caddr_t,NFSX_FH); \ 		bcopy((caddr_t)(f), cp, NFSX_FH)
end_define

begin_define
define|#
directive|define
name|nfsm_mtofh
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
define|\
value|{ struct nfsnode *np; nfsv2fh_t *fhp; \ 		nfsm_dissect(fhp,nfsv2fh_t *,NFSX_FH); \ 		error = nfs_nget((d)->v_mount, fhp,&np); \ 		if (error) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 		(v) = NFSTOV(np); \ 		nfsm_loadattr(v, (struct vattr *)0); \ 		}
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
value|{ struct vnode *tvp = (v); \ 		error = nfs_loadattrcache(&tvp,&md,&dpos, (a)); \ 		if (error) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 		(v) = tvp; }
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
value|{ nfsm_dissect(tl,u_long *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(long,*tl))> (m)) { \ 			m_freem(mrep); \ 			error = EBADRPC; \ 			goto nfsmout; \ 		} }
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
value|{ nfsm_dissect(tl,u_long *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(long,*tl))> (m) || (s)<= 0) { \ 			error = EBADRPC; \ 			nfsm_reply(0); \ 		} }
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
value|if ((s)> 0&& \ 		   (error = nfsm_mbuftouio(&md,(p),(s),&dpos))) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		}
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
value|error = nfsm_uiotombuf((p),&mb,(s),&bpos); \ 		if (error) { \ 			m_freem(mreq); \ 			goto nfsmout; \ 		}
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
value|mb = mreq = nfsm_reqh((v),(a),(s),&bpos)
end_define

begin_define
define|#
directive|define
name|nfsm_reqdone
value|m_freem(mrep); \ 		nfsmout:
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
value|error = nfs_request((v), mreq, (t), (p), \ 		   (c),&mrep,&md,&dpos); \ 		if (error) \ 			goto nfsmout
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
value|if ((s)> (m)) { \ 			m_freem(mreq); \ 			error = ENAMETOOLONG; \ 			goto nfsmout; \ 		} \ 		t2 = nfsm_rndup(s)+NFSX_UNSIGNED; \ 		if (t2<= M_TRAILINGSPACE(mb)) { \ 			nfsm_build(tl,u_long *,t2); \ 			*tl++ = txdr_unsigned(s); \ 			*(tl+((t2>>2)-2)) = 0; \ 			bcopy((caddr_t)(a), (caddr_t)tl, (s)); \ 		} else { \ 			error = nfsm_strtmbuf(&mb,&bpos, (a), (s)); \ 			if (error) { \ 				m_freem(mreq); \ 				goto nfsmout; \ 			} \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srvdone
define|\
value|nfsmout: \ 		return(error)
end_define

begin_define
define|#
directive|define
name|nfsm_reply
parameter_list|(
name|s
parameter_list|)
define|\
value|{ \ 		nfsd->nd_repstat = error; \ 		if (error) \ 		   (void) nfs_rephead(0, nfsd, error, cache,&frev, \ 			mrq,&mb,&bpos); \ 		else \ 		   (void) nfs_rephead((s), nfsd, error, cache,&frev, \ 			mrq,&mb,&bpos); \ 		m_freem(mrep); \ 		mreq = *mrq; \ 		if (error) \ 			return(0); \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_adv
parameter_list|(
name|s
parameter_list|)
define|\
value|t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			dpos += (s); \ 		} else { \ 			error = nfs_adv(&md,&dpos, (s), t1); \ 			if (error) { \ 				m_freem(mrep); \ 				goto nfsmout; \ 			} \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srvmtofh
parameter_list|(
name|f
parameter_list|)
define|\
value|nfsm_dissect(tl, u_long *, NFSX_FH); \ 		bcopy((caddr_t)tl, (caddr_t)f, NFSX_FH)
end_define

begin_define
define|#
directive|define
name|nfsm_clget
define|\
value|if (bp>= be) { \ 			if (mp == mb) \ 				mp->m_len += bp-bpos; \ 			MGET(mp, M_WAIT, MT_DATA); \ 			MCLGET(mp, M_WAIT); \ 			mp->m_len = NFSMSIZ(mp); \ 			mp2->m_next = mp; \ 			mp2 = mp; \ 			bp = mtod(mp, caddr_t); \ 			be = bp+mp->m_len; \ 		} \ 		tl = (u_long *)bp
end_define

begin_define
define|#
directive|define
name|nfsm_srvfillattr
define|\
value|fp->fa_type = vtonfs_type(vap->va_type); \ 	fp->fa_mode = vtonfs_mode(vap->va_type, vap->va_mode); \ 	fp->fa_nlink = txdr_unsigned(vap->va_nlink); \ 	fp->fa_uid = txdr_unsigned(vap->va_uid); \ 	fp->fa_gid = txdr_unsigned(vap->va_gid); \ 	if (nfsd->nd_nqlflag == NQL_NOVAL) { \ 		fp->fa_nfsblocksize = txdr_unsigned(vap->va_blocksize); \ 		if (vap->va_type == VFIFO) \ 			fp->fa_nfsrdev = 0xffffffff; \ 		else \ 			fp->fa_nfsrdev = txdr_unsigned(vap->va_rdev); \ 		fp->fa_nfsfsid = txdr_unsigned(vap->va_fsid); \ 		fp->fa_nfsfileid = txdr_unsigned(vap->va_fileid); \ 		fp->fa_nfssize = txdr_unsigned(vap->va_size); \ 		fp->fa_nfsblocks = txdr_unsigned(vap->va_bytes / NFS_FABLKSIZE); \ 		txdr_nfstime(&vap->va_atime,&fp->fa_nfsatime); \ 		txdr_nfstime(&vap->va_mtime,&fp->fa_nfsmtime); \ 		txdr_nfstime(&vap->va_ctime,&fp->fa_nfsctime); \ 	} else { \ 		fp->fa_nqblocksize = txdr_unsigned(vap->va_blocksize); \ 		if (vap->va_type == VFIFO) \ 			fp->fa_nqrdev = 0xffffffff; \ 		else \ 			fp->fa_nqrdev = txdr_unsigned(vap->va_rdev); \ 		fp->fa_nqfsid = txdr_unsigned(vap->va_fsid); \ 		fp->fa_nqfileid = txdr_unsigned(vap->va_fileid); \ 		txdr_hyper(&vap->va_size,&fp->fa_nqsize); \ 		txdr_hyper(&vap->va_bytes,&fp->fa_nqbytes); \ 		txdr_nqtime(&vap->va_atime,&fp->fa_nqatime); \ 		txdr_nqtime(&vap->va_mtime,&fp->fa_nqmtime); \ 		txdr_nqtime(&vap->va_ctime,&fp->fa_nqctime); \ 		fp->fa_nqflags = txdr_unsigned(vap->va_flags); \ 		fp->fa_nqgen = txdr_unsigned(vap->va_gen); \ 		txdr_hyper(&vap->va_filerev,&fp->fa_nqfilerev); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

