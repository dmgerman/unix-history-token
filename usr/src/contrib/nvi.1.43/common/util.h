begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)util.h	9.4 (Berkeley) 12/3/94  */
end_comment

begin_comment
comment|/*  * XXX  * MIN/MAX have traditionally been in<sys/param.h>.  Don't  * try to get them from there, it's just not worth the effort.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_b):(_a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
value|((_a)<(_b)?(_a):(_b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Number handling defines and protoypes.  *  * NNFITS:	test for addition of two negative numbers under a limit  * NPFITS:	test for addition of two positive numbers under a limit  * NADD_SLONG:	test for addition of two signed longs  * NADD_USLONG:	test for addition of two unsigned longs  */
end_comment

begin_enum
enum|enum
name|nresult
block|{
name|NUM_ERR
block|,
name|NUM_OK
block|,
name|NUM_OVER
block|,
name|NUM_UNDER
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NNFITS
parameter_list|(
name|min
parameter_list|,
name|cur
parameter_list|,
name|add
parameter_list|)
define|\
value|(((long)(min)) - (cur)<= (add))
end_define

begin_define
define|#
directive|define
name|NPFITS
parameter_list|(
name|max
parameter_list|,
name|cur
parameter_list|,
name|add
parameter_list|)
define|\
value|(((unsigned long)(max)) - (cur)>= (add))
end_define

begin_define
define|#
directive|define
name|NADD_SLONG
parameter_list|(
name|sp
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|((v1)< 0 ?							\ 	    ((v2)< 0&&						\ 	    NNFITS(LONG_MIN, (v1), (v2))) ? NUM_UNDER : NUM_OK :	\ 	 (v1)> 0 ?							\ 	    (v2)> 0&&							\ 	    NPFITS(LONG_MAX, (v1), (v2)) ? NUM_OK : NUM_OVER :		\ 	 NUM_OK)
end_define

begin_define
define|#
directive|define
name|NADD_USLONG
parameter_list|(
name|sp
parameter_list|,
name|v1
parameter_list|,
name|v2
parameter_list|)
define|\
value|(NPFITS(ULONG_MAX, (v1), (v2)) ? NUM_OK : NUM_OVER)
end_define

begin_decl_stmt
name|enum
name|nresult
name|nget_slong
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|long
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|nresult
name|nget_uslong
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_long
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Digraphs (not currently real). */
end_comment

begin_decl_stmt
name|int
name|digraph
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|digraph_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|digraph_save
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function prototypes that don't seem to belong anywhere else. */
end_comment

begin_decl_stmt
name|int
name|nonblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|recno_t
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_alt_name
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tail
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
name|CHAR_T
modifier|*
name|v_strdup
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
specifier|const
name|CHAR_T
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|vi_putchar
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|TRACE
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

