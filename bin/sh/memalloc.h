begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)memalloc.h	8.2 (Berkeley) 5/4/95  *	$Id: memalloc.h,v 1.5 1997/02/22 13:58:35 peter Exp $  */
end_comment

begin_struct
struct|struct
name|stackmark
block|{
name|struct
name|stack_block
modifier|*
name|stackp
decl_stmt|;
name|char
modifier|*
name|stacknxt
decl_stmt|;
name|int
name|stacknleft
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|stacknxt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stacknleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sstrnleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|herefd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pointer
name|ckmalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pointer
name|ckrealloc
name|__P
argument_list|(
operator|(
name|pointer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|savestr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pointer
name|stalloc
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stunalloc
name|__P
argument_list|(
operator|(
name|pointer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setstackmark
name|__P
argument_list|(
operator|(
expr|struct
name|stackmark
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|popstackmark
name|__P
argument_list|(
operator|(
expr|struct
name|stackmark
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|growstackblock
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|grabstackblock
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|growstackstr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|makestrspace
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ungrabstackstr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|stackblock
parameter_list|()
value|stacknxt
end_define

begin_define
define|#
directive|define
name|stackblocksize
parameter_list|()
value|stacknleft
end_define

begin_define
define|#
directive|define
name|STARTSTACKSTR
parameter_list|(
name|p
parameter_list|)
value|p = stackblock(), sstrnleft = stackblocksize()
end_define

begin_define
define|#
directive|define
name|STPUTC
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|(--sstrnleft>= 0? (*p++ = (c)) : (p = growstackstr(), *p++ = (c)))
end_define

begin_define
define|#
directive|define
name|CHECKSTRSPACE
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|{ if (sstrnleft< n) p = makestrspace(); }
end_define

begin_define
define|#
directive|define
name|USTPUTC
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|(--sstrnleft, *p++ = (c))
end_define

begin_define
define|#
directive|define
name|STACKSTRNUL
parameter_list|(
name|p
parameter_list|)
value|(sstrnleft == 0? (p = growstackstr(), *p = '\0') : (*p = '\0'))
end_define

begin_define
define|#
directive|define
name|STUNPUTC
parameter_list|(
name|p
parameter_list|)
value|(++sstrnleft, --p)
end_define

begin_define
define|#
directive|define
name|STTOPC
parameter_list|(
name|p
parameter_list|)
value|p[-1]
end_define

begin_define
define|#
directive|define
name|STADJUST
parameter_list|(
name|amount
parameter_list|,
name|p
parameter_list|)
value|(p += (amount), sstrnleft -= (amount))
end_define

begin_define
define|#
directive|define
name|grabstackstr
parameter_list|(
name|p
parameter_list|)
value|stalloc(stackblocksize() - sstrnleft)
end_define

begin_define
define|#
directive|define
name|ckfree
parameter_list|(
name|p
parameter_list|)
value|free((pointer)(p))
end_define

end_unit

