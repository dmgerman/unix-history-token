begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC98 series]  *  Copyright (c) 1996 NetBSD/pc98 porting staff.  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Naofumi HONDA.  All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_DVCFG_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_DVCFG_H_
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|dvcfg_hw_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dvcfg_hwsel
block|{
name|int
name|cfg_max
decl_stmt|;
name|dvcfg_hw_t
modifier|*
name|cfg_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DVCFG_MAJOR
parameter_list|(
name|dvcfg
parameter_list|)
value|(((u_int)(dvcfg))>> 16)
end_define

begin_define
define|#
directive|define
name|DVCFG_MINOR
parameter_list|(
name|dvcfg
parameter_list|)
value|(((u_int)(dvcfg))& 0xffff)
end_define

begin_define
define|#
directive|define
name|DVCFG_MKCFG
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|((((u_int)(major))<< 16) | ((minor)& 0xffff))
end_define

begin_define
define|#
directive|define
name|DVCFG_HWSEL_SZ
parameter_list|(
name|array
parameter_list|)
value|(sizeof(array) / sizeof(dvcfg_hw_t))
end_define

begin_decl_stmt
specifier|static
name|__inline
name|dvcfg_hw_t
name|dvcfg_hw
name|__P
argument_list|(
operator|(
expr|struct
name|dvcfg_hwsel
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|dvcfg_hw_t
name|dvcfg_hw
parameter_list|(
name|selp
parameter_list|,
name|num
parameter_list|)
name|struct
name|dvcfg_hwsel
modifier|*
name|selp
decl_stmt|;
name|u_int
name|num
decl_stmt|;
block|{
return|return
operator|(
operator|(
name|num
operator|>=
name|selp
operator|->
name|cfg_max
operator|)
condition|?
literal|0
else|:
name|selp
operator|->
name|cfg_sel
index|[
name|num
index|]
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DVCFG_HW
parameter_list|(
name|SELP
parameter_list|,
name|NUM
parameter_list|)
value|dvcfg_hw((SELP), (NUM))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_DVCFG_H_ */
end_comment

end_unit

