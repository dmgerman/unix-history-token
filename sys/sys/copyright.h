begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1992-2006 The FreeBSD Project. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Copyrights macros  */
end_comment

begin_comment
comment|/* FreeBSD */
end_comment

begin_define
define|#
directive|define
name|COPYRIGHT_FreeBSD
define|\
value|"Copyright (c) 1992-2006 The FreeBSD Project.\n"
end_define

begin_comment
comment|/* Berkeley */
end_comment

begin_define
define|#
directive|define
name|COPYRIGHT_UCB
define|\
value|"Copyright (c) 1979, 1980, 1983, 1986, 1988, 1989, 1991, 1992, 1993, 1994\n\tThe Regents of the University of California. All rights reserved.\n"
end_define

begin_comment
comment|/* a port of FreeBSD to the NEC PC98, Japan */
end_comment

begin_define
define|#
directive|define
name|COPYRIGHT_PC98
define|\
value|"Copyright (c) 1994-2003 FreeBSD(98) porting team.\nCopyright (c) 1992  A.Kojima F.Ukai M.Ishii (KMC).\n"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PC98
argument_list|)
end_if

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
name|COPYRIGHT_FreeBSD
comment|/**/
name|COPYRIGHT_PC98
comment|/**/
name|COPYRIGHT_UCB
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
name|COPYRIGHT_FreeBSD
comment|/**/
name|COPYRIGHT_UCB
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

