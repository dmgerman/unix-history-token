begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b - mbuf handling support routines  *	------------------------------------  *  *	$Id: i4b_mbuf.c,v 1.15 2000/05/29 15:41:42 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Mon May 29 16:55:18 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_mbuf.h>
end_include

begin_include
include|#
directive|include
file|<i4b/include/i4b_global.h>
end_include

begin_define
define|#
directive|define
name|I4B_MBUF_DEBUG
end_define

begin_undef
undef|#
directive|undef
name|I4B_MBUF_TYPE_DEBUG
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|I4B_MBUF_TYPE_DEBUG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|MT_DCHAN
value|42
end_define

begin_define
define|#
directive|define
name|MT_BCHAN
value|43
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NetBSD */
end_comment

begin_define
define|#
directive|define
name|MT_DCHAN
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|MT_BCHAN
value|MT_DATA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MT_I4B_D
value|MT_DCHAN
end_define

begin_define
define|#
directive|define
name|MT_I4B_B
value|MT_BCHAN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! I4B_MBUF_TYPE_DEBUG */
end_comment

begin_define
define|#
directive|define
name|MT_I4B_D
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|MT_I4B_B
value|MT_DATA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_MBUF_TYPE_DEBUG */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	allocate D-channel mbuf space  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|struct
name|mbuf
modifier|*
name|i4b_Dgetmbuf
parameter_list|(
name|int
name|len
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
if|if
condition|(
name|len
operator|>
name|MCLBYTES
condition|)
comment|/* if length> max extension size */
block|{
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getmbuf: error - len(%d)> MCLBYTES(%d)\n"
argument_list|,
name|len
argument_list|,
name|MCLBYTES
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|MGETHDR
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_I4B_D
argument_list|)
expr_stmt|;
comment|/* get mbuf with pkthdr */
comment|/* did we actually get the mbuf ? */
if|if
condition|(
operator|!
name|m
condition|)
block|{
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getbuf: error - MGETHDR failed!\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|len
operator|>=
name|MHLEN
condition|)
block|{
name|MCLGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
operator|)
condition|)
block|{
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getbuf: error - MCLGET failed, len(%d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
block|}
name|m
operator|->
name|m_len
operator|=
name|len
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	free a D-channel mbuf  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_Dfreembuf
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|m
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	clear a D-channel ifqueue from data  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_Dcleanifq
parameter_list|(
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|x
init|=
name|splimp
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|IF_QEMPTY
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|i4b_Dfreembuf
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	allocate B-channel mbuf space  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|struct
name|mbuf
modifier|*
name|i4b_Bgetmbuf
parameter_list|(
name|int
name|len
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
if|if
condition|(
name|len
operator|>
name|MCLBYTES
condition|)
comment|/* if length> max extension size */
block|{
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getmbuf: error - len(%d)> MCLBYTES(%d)\n"
argument_list|,
name|len
argument_list|,
name|MCLBYTES
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|MGETHDR
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_I4B_B
argument_list|)
expr_stmt|;
comment|/* get mbuf with pkthdr */
comment|/* did we actually get the mbuf ? */
if|if
condition|(
operator|!
name|m
condition|)
block|{
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getbuf: error - MGETHDR failed!\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|len
operator|>=
name|MHLEN
condition|)
block|{
name|MCLGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|m
operator|->
name|m_flags
operator|&
name|M_EXT
operator|)
condition|)
block|{
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|I4B_MBUF_DEBUG
name|printf
argument_list|(
literal|"i4b_getbuf: error - MCLGET failed, len(%d)\n"
argument_list|,
name|len
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|NULL
operator|)
return|;
block|}
block|}
name|m
operator|->
name|m_len
operator|=
name|len
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	free a B-channel mbuf  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_Bfreembuf
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
if|if
condition|(
name|m
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------------------------*  *	clear a B-channel ifqueue from data  *---------------------------------------------------------------------------*/
end_comment

begin_function
name|void
name|i4b_Bcleanifq
parameter_list|(
name|struct
name|ifqueue
modifier|*
name|ifq
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|x
init|=
name|splimp
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|IF_QEMPTY
argument_list|(
name|ifq
argument_list|)
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
name|ifq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|i4b_Bfreembuf
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
name|splx
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* EOF */
end_comment

end_unit

