begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nfsm_subs.h	7.3 (Berkeley) %G%  */
end_comment

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
name|nfsm_reqh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnode
modifier|*
name|nfs_fhtovp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * To try and deal with different variants of mbuf.h, I have used the  * following defs. If M_HASCL is not defined in an older the 4.4bsd mbuf.h,  * you will have to use a different ifdef  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_HASCL
end_ifdef

begin_define
define|#
directive|define
name|NFSMCLGET
parameter_list|(
name|m
parameter_list|,
name|w
parameter_list|)
value|MCLGET(m)
end_define

begin_define
define|#
directive|define
name|NFSMGETHDR
parameter_list|(
name|m
parameter_list|)
value|MGET(m, M_WAIT, MT_DATA)
end_define

begin_define
define|#
directive|define
name|MHLEN
value|MLEN
end_define

begin_define
define|#
directive|define
name|NFSMINOFF
parameter_list|(
name|m
parameter_list|)
define|\
value|if (M_HASCL(m)) \ 			(m)->m_off = ((int)MTOCL(m))-(int)(m); \ 		else \ 			(m)->m_off = MMINOFF
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
value|(m)->m_off += (s)
end_define

begin_define
define|#
directive|define
name|NFSMSIZ
parameter_list|(
name|m
parameter_list|)
value|((M_HASCL(m))?MCLBYTES:MLEN)
end_define

begin_define
define|#
directive|define
name|m_nextpkt
value|m_act
end_define

begin_define
define|#
directive|define
name|NFSMCOPY
parameter_list|(
name|m
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|w
parameter_list|)
value|m_copy((m), (o), (l))
end_define

begin_else
else|#
directive|else
end_else

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
name|NFSMCLGET
value|MCLGET
end_define

begin_define
define|#
directive|define
name|NFSMGETHDR
parameter_list|(
name|m
parameter_list|)
define|\
value|MGETHDR(m, M_WAIT, MT_DATA); \ 		(m)->m_pkthdr.len = 0; \ 		(m)->m_pkthdr.rcvif = (struct ifnet *)0
end_define

begin_define
define|#
directive|define
name|NFSMINOFF
parameter_list|(
name|m
parameter_list|)
define|\
value|if (M_HASCL(m)) \ 			(m)->m_data = (m)->m_ext.ext_buf; \ 		else \ 			(m)->m_data = (m)->m_dat
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

begin_define
define|#
directive|define
name|NFSMCOPY
value|m_copym
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MCLBYTES
end_ifndef

begin_define
define|#
directive|define
name|MCLBYTES
value|CLBYTES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MT_CONTROL
end_ifndef

begin_define
define|#
directive|define
name|MT_CONTROL
value|MT_RIGHTS
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|t1 = NFSMSIZ(mb); \ 		if ((s)> (t1-mb->m_len)) { \ 			MGET(mb2, M_WAIT, MT_DATA); \ 			if ((s)> MLEN) \ 				panic("build> MLEN"); \ 			mb->m_next = mb2; \ 			mb = mb2; \ 			mb->m_len = 0; \ 			bpos = mtod(mb, caddr_t); \ 		} \ 		(a) = (c)(bpos); \ 		mb->m_len += (s); \ 		bpos += (s)
end_define

begin_define
define|#
directive|define
name|nfsm_disect
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			(a) = (c)(dpos); \ 			dpos += (s); \ 		} else if (error = nfsm_disct(&md,&dpos, (s), t1, TRUE,&cp2)) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} else { \ 			(a) = (c)cp2; \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_disecton
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			(a) = (c)(dpos); \ 			dpos += (s); \ 		} else if (error = nfsm_disct(&md,&dpos, (s), t1, FALSE,&cp2)) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} else { \ 			(a) = (c)cp2; \ 		}
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
value|{ struct nfsnode *np; nfsv2fh_t *fhp; \ 		nfsm_disect(fhp,nfsv2fh_t *,NFSX_FH); \ 		if (error = nfs_nget((d)->v_mount, fhp,&np)) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		} \ 		(v) = NFSTOV(np); \ 		nfsm_loadattr(v, (struct vattr *)0); \ 		(v)->v_type = np->n_vattr.va_type; \ 		}
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
value|if (error = nfs_loadattrcache((v),&md,&dpos, (a))) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		}
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
value|nfsm_disect(p,u_long *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(long,*p))> (m)) { \ 			m_freem(mrep); \ 			error = EBADRPC; \ 			goto nfsmout; \ 		}
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
value|nfsm_disect(p,u_long *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(long,*p))> (m) || (s)<= 0) { \ 			error = EBADRPC; \ 			nfsm_reply(0); \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srvstrsizon
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
define|\
value|nfsm_disecton(p,u_long *,NFSX_UNSIGNED); \ 		if (((s) = fxdr_unsigned(long,*p))> (m)) { \ 			error = EBADRPC; \ 			nfsm_reply(0); \ 		}
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
value|if (error = nfsm_uiotombuf((p),&mb,(s),&bpos)) { \ 			m_freem(mreq); \ 			goto nfsmout; \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_reqhead
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|if ((mreq = nfsm_reqh(nfs_prog,nfs_vers,(a),(c),(s),&bpos,&mb,&xid)) == NULL) { \ 			error = ENOBUFS; \ 			goto nfsmout; \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_vars
define|\
value|register u_long *p; \ 		register caddr_t cp; \ 		register long t1, t2; \ 		caddr_t bpos, dpos, cp2; \ 		u_long xid; \ 		int error = 0; \ 		long offs = 0; \ 		struct mbuf *mreq, *mrep, *md, *mb, *mb2
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
parameter_list|)
define|\
value|if (error = nfs_request((v), mreq, xid, \ 		   (v)->v_mount,&mrep,&md,&dpos)) \ 			goto nfsmout
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
value|if ((s)> (m)) { \ 			m_freem(mreq); \ 			error = ENAMETOOLONG; \ 			goto nfsmout; \ 		} \ 		t2 = nfsm_rndup(s)+NFSX_UNSIGNED; \ 		if(t2<=(NFSMSIZ(mb)-mb->m_len)){ \ 			nfsm_build(p,u_long *,t2); \ 			*p++ = txdr_unsigned(s); \ 			*(p+((t2>>2)-2)) = 0; \ 			bcopy((caddr_t)(a), (caddr_t)p, (s)); \ 		} else if (error = nfsm_strtmbuf(&mb,&bpos, (a), (s))) { \ 			m_freem(mreq); \ 			goto nfsmout; \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srverr
define|\
value|{ \ 			m_freem(mrep); \ 			return(ENOBUFS); \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srvars
define|\
value|register caddr_t cp; \ 		register u_long *p; \ 		register long t1, t2; \ 		caddr_t bpos; \ 		long offs = 0; \ 		int error = 0; \ 		char *cp2; \ 		struct mbuf *mb, *mb2, *mreq
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
value|{ \ 		if (error) \ 			nfs_rephead(0, xid, error, mrq,&mb,&bpos); \ 		else \ 			nfs_rephead((s), xid, error, mrq,&mb,&bpos); \ 		m_freem(mrep); \ 		mreq = *mrq; \ 		if (error) \ 			return(0); \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_adv
parameter_list|(
name|s
parameter_list|)
define|\
value|t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			dpos += (s); \ 		} else if (error = nfs_adv(&md,&dpos, (s), t1)) { \ 			m_freem(mrep); \ 			goto nfsmout; \ 		}
end_define

begin_define
define|#
directive|define
name|nfsm_srvmtofh
parameter_list|(
name|f
parameter_list|)
define|\
value|nfsm_disecton(p, u_long *, NFSX_FH); \ 		bcopy((caddr_t)p, (caddr_t)f, NFSX_FH)
end_define

begin_define
define|#
directive|define
name|nfsm_clget
define|\
value|if (bp>= be) { \ 			MGET(mp, M_WAIT, MT_DATA); \ 			NFSMCLGET(mp, M_WAIT); \ 			mp->m_len = NFSMSIZ(mp); \ 			if (mp3 == NULL) \ 				mp3 = mp2 = mp; \ 			else { \ 				mp2->m_next = mp; \ 				mp2 = mp; \ 			} \ 			bp = mtod(mp, caddr_t); \ 			be = bp+mp->m_len; \ 		} \ 		p = (u_long *)bp
end_define

end_unit

