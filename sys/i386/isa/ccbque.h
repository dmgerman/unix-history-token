begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC98 series]  *  Copyright (c) 1994, 1995, 1996 NetBSD/pc98 porting staff.  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Common command control queue funcs.  * Written by N. Honda.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CCBQUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CCBQUE_H_
end_define

begin_define
define|#
directive|define
name|CCB_MWANTED
value|0x01
end_define

begin_comment
comment|/* (I)  structure and prototype */
end_comment

begin_define
define|#
directive|define
name|GENERIC_CCB_ASSERT
parameter_list|(
name|DEV
parameter_list|,
name|CCBTYPE
parameter_list|)
define|\
value|TAILQ_HEAD(CCBTYPE##tab, CCBTYPE);					\ struct CCBTYPE##que {							\ 	struct CCBTYPE##tab CCBTYPE##tab;				\ 	int count;							\ 	int maxccb;							\ 	u_int flags;							\ };									\ 									\ void DEV##_init_ccbque(int);					\ struct CCBTYPE *DEV##_get_ccb(void);				\ void DEV##_free_ccb(register struct CCBTYPE *);
end_define

begin_comment
comment|/* (II)  static allocated memory */
end_comment

begin_define
define|#
directive|define
name|GENERIC_CCB_STATIC_ALLOC
parameter_list|(
name|DEV
parameter_list|,
name|CCBTYPE
parameter_list|)
define|\
value|static struct CCBTYPE##que CCBTYPE##que;
end_define

begin_comment
comment|/* (III)  functions */
end_comment

begin_define
define|#
directive|define
name|GENERIC_CCB
parameter_list|(
name|DEV
parameter_list|,
name|CCBTYPE
parameter_list|,
name|CHAIN
parameter_list|)
define|\ 									\
value|void									\ DEV##_init_ccbque(count)						\ 	int count;							\ {									\ 	if (CCBTYPE##que.maxccb == 0)					\ 		TAILQ_INIT(&CCBTYPE##que.CCBTYPE##tab);			\ 	CCBTYPE##que.maxccb += count;					\ }									\ 									\ struct CCBTYPE *							\ DEV##_get_ccb()								\ {									\ 	register struct CCBTYPE *cb;					\ 	int s = splcam();						\ 									\ 	if (CCBTYPE##que.count< CCBTYPE##que.maxccb)			\ 	{								\ 		CCBTYPE##que.count ++;					\ 		cb = TAILQ_FIRST(&(CCBTYPE##que.CCBTYPE##tab));		\ 		if (cb != NULL)						\ 		{							\ 			TAILQ_REMOVE(&CCBTYPE##que.CCBTYPE##tab, cb, CHAIN);\ 			goto out;					\ 		}							\ 		else							\ 		{							\ 			cb = malloc(sizeof(*cb), M_DEVBUF, M_NOWAIT);	\ 			if (cb != NULL)					\ 			{						\ 				bzero(cb, sizeof(*cb));			\ 				goto out;				\ 			}						\ 		}							\ 		CCBTYPE##que.count --;					\ 	}								\ 									\ 	cb = NULL;							\ 									\ out:									\ 	splx(s);							\ 	return cb;							\ }									\ 									\ void									\ DEV##_free_ccb(cb)							\ 	register struct CCBTYPE *cb;					\ {									\ 	int s = splcam();						\ 									\ 	TAILQ_INSERT_TAIL(&CCBTYPE##que.CCBTYPE##tab, cb, CHAIN);	\ 	CCBTYPE##que.count --;						\ 									\ 	if (CCBTYPE##que.flags& CCB_MWANTED)				\ 	{								\ 		CCBTYPE##que.flags&= ~CCB_MWANTED;			\ 		wakeup ((caddr_t)&CCBTYPE##que.count);			\ 	}								\ 	splx(s);							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CCBQUE_H_ */
end_comment

end_unit

