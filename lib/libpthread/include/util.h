begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== util.h ============================================================  * Copyright (c) 1991, 1992, 1993 by Chris Provenzano, proven@mit.edu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  This product includes software developed by Chris Provenzano.  * 4. The name of Chris Provenzano may not be used to endorse or promote   *	  products derived from this software without specific prior written  *	  permission.  *  * THIS SOFTWARE IS PROVIDED BY CHRIS PROVENZANO ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL CHRIS PROVENZANO BE LIABLE FOR ANY   * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR   * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.  *  * Description : Header file for generic utility functions.  *  * 91/08/31 proven - Added exchange.  * Exchange any two objects of any size in any table.  *  * 91/10/06 proven - Cleaned out all the old junk.   *  * 91/03/06 proven - Added getint.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTHREAD_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_PTHREAD_UTIL_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Stuff only pthread internals really uses */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_typedef
typedef|typedef
enum|enum
name|Boolean
block|{
name|FALSE
block|,
name|TRUE
block|, }
name|Boolean
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NUL
value|'\0'
end_define

begin_define
define|#
directive|define
name|NOTOK
value|-1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|min
argument_list|)
end_if

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Alingn the size to the next multiple of 4 bytes */
end_comment

begin_define
define|#
directive|define
name|ALIGN4
parameter_list|(
name|size
parameter_list|)
value|((size + 3)& ~3)
end_define

begin_define
define|#
directive|define
name|ALIGN8
parameter_list|(
name|size
parameter_list|)
value|((size + 7)& ~7)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUG0
parameter_list|(
name|s
parameter_list|)
value|printf(s)
end_define

begin_define
define|#
directive|define
name|DEBUG1
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|printf(s,a)
end_define

begin_define
define|#
directive|define
name|DEBUG2
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|printf(s,a,b)
end_define

begin_define
define|#
directive|define
name|DEBUG3
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|printf(s,a,b,c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG0
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG1
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG2
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG3
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

