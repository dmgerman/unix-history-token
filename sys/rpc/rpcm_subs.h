begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: nfsm_subs.h,v 1.11 2000/01/05 20:50:52 millert Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: nfsm_subs.h,v 1.10 1996/03/20 21:59:56 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * copyright (c) 2003  * the regents of the university of michigan  * all rights reserved  *   * permission is granted to use, copy, create derivative works and redistribute  * this software and such derivative works for any purpose, so long as the name  * of the university of michigan is not used in any advertising or publicity  * pertaining to the use or distribution of this software without specific,  * written prior authorization.  if the above copyright notice or any other  * identification of the university of michigan is included in any copy of any  * portion of this software, then the disclaimer below must also be included.  *   * this software is provided as is, without representation from the university  * of michigan as to its fitness for any purpose, and without warranty by the  * university of michigan of any kind, either express or implied, including  * without limitation the implied warranties of merchantability and fitness for  * a particular purpose. the regents of the university of michigan shall not be  * liable for any damages, including special, indirect, incidental, or  * consequential damages, with respect to any claim arising out of or in  * connection with the use of the software, even if it has been or is hereafter  * advised of the possibility of such damages.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsm_subs.h	8.2 (Berkeley) 3/30/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RPC_RPCM_SUBS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RPC_RPCM_SUBS_H_
end_define

begin_comment
comment|/*  * Now for the macros that do the simple stuff and call the functions  * for the hard stuff.  * These macros use several vars. declared in rpcm_reqhead and these  * vars. must not be used elsewhere unless you are careful not to corrupt  * them. The vars. starting with pN and tN (N=1,2,3,..) are temporaries  * that may be used so long as the value is not expected to retained  * after a macro.  * I know, this is kind of dorkey, but it makes the actual op functions  * fairly clean and deals with the mess caused by the xdr discriminating  * unions.  */
end_comment

begin_define
define|#
directive|define
name|rpcm_build
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
name|rpcm_dissect
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|s
parameter_list|)
define|\
value|{ t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			(a) = (c)(dpos); \ 			dpos += (s); \ 		} else if ((t1 = rpcm_disct(&md,&dpos, (s), t1,&cp2)) != 0){ \ 			error = t1; \ 			goto rpcmout; \ 		} else { \ 			(a) = (c)cp2; \ 		} }
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|rpcm_mtouio
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|if ((s)> 0&& \ 		   (t1 = rpcm_mbuftouio(&md,(p),(s),&dpos)) != 0) { \ 			error = t1; \ 			goto rpcmout; \ 		}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rpcm_rndup
parameter_list|(
name|a
parameter_list|)
value|(((a)+3)&(~0x3))
end_define

begin_define
define|#
directive|define
name|rpcm_adv
parameter_list|(
name|s
parameter_list|)
define|\
value|{ t1 = mtod(md, caddr_t)+md->m_len-dpos; \ 		if (t1>= (s)) { \ 			dpos += (s); \ 		} else if ((t1 = rpc_adv(&md,&dpos, (s), t1)) != 0) { \ 			error = t1; \ 			goto rpcmout; \ 		} }
end_define

begin_define
define|#
directive|define
name|RPCMADV
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
value|(m)->m_data += (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RPC_RPCM_SUBS_H_ */
end_comment

end_unit

