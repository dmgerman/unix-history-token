begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/include/nfs_common.c  *  */
end_comment

begin_struct
struct|struct
name|nfs_common_args
block|{
name|u_long
name|flags
decl_stmt|;
name|u_long
name|acdirmin
decl_stmt|;
name|u_long
name|acdirmax
decl_stmt|;
name|u_long
name|acregmin
decl_stmt|;
name|u_long
name|acregmax
decl_stmt|;
name|u_long
name|timeo
decl_stmt|;
name|u_long
name|retrans
decl_stmt|;
name|u_long
name|rsize
decl_stmt|;
name|u_long
name|wsize
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_ARGS_T_ACREGMIN
end_ifdef

begin_define
define|#
directive|define
name|GET_ACREGMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|nap->acregmin = a.acregmin;
end_define

begin_define
define|#
directive|define
name|PUT_ACREGMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|a.acregmin = nap->acregmin;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_ACREGMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_ACREGMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_ARGS_T_ACREGMAX
end_ifdef

begin_define
define|#
directive|define
name|GET_ACREGMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|nap->acregmax = a.acregmax;
end_define

begin_define
define|#
directive|define
name|PUT_ACREGMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|a.acregmax = nap->acregmax;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_ACREGMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_ACREGMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_ARGS_T_ACDIRMIN
end_ifdef

begin_define
define|#
directive|define
name|GET_ACDIRMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|nap->acdirmin = a.acdirmin;
end_define

begin_define
define|#
directive|define
name|PUT_ACDIRMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|a.acdirmin = nap->acdirmin;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_ACDIRMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_ACDIRMIN
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NFS_ARGS_T_ACDIRMAX
end_ifdef

begin_define
define|#
directive|define
name|GET_ACDIRMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|nap->acdirmax = a.acdirmax;
end_define

begin_define
define|#
directive|define
name|PUT_ACDIRMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
value|a.acdirmax = nap->acdirmax;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_ACDIRMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_ACDIRMAX
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|get_nfs_common_args
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
define|\
value|do { \     nap->flags = a.flags; \     GET_ACREGMIN(nap, a) \     GET_ACREGMAX(nap, a) \     GET_ACDIRMIN(nap, a) \     GET_ACDIRMAX(nap, a) \     nap->timeo = a.timeo; \     nap->retrans = a.retrans; \     nap->rsize = a.rsize; \     nap->wsize = a.wsize; \   } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|put_nfs_common_args
parameter_list|(
name|nap
parameter_list|,
name|a
parameter_list|)
define|\
value|do { \     a.flags = nap->flags; \     PUT_ACREGMIN(nap, a) \     PUT_ACREGMAX(nap, a) \     PUT_ACDIRMIN(nap, a) \     PUT_ACDIRMAX(nap, a) \     a.timeo = nap->timeo; \     a.retrans = nap->retrans; \     a.rsize = nap->rsize; \     a.wsize = nap->wsize; \   } while (
comment|/*CONSTCOND*/
value|0)
end_define

end_unit

