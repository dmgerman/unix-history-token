begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Adrian Chadd<adrian@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_BWN_UTIL_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_BWN_UTIL_H__
end_define

begin_comment
comment|/* Hamming weight; used in the PHY routines */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bwn_hweight32
parameter_list|(
name|uint32_t
name|val
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|r
init|=
literal|0
decl_stmt|;
comment|/* yes, could do it without a loop.. */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|32
condition|;
name|i
operator|++
control|)
block|{
name|r
operator|=
name|r
operator|+
operator|(
name|val
operator|&
literal|1
operator|)
expr_stmt|;
name|val
operator|=
name|val
operator|>>
literal|1
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|/* Clamp value; PHY code */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bwn_clamp_val
parameter_list|(
name|int
name|val
parameter_list|,
name|int
name|lo
parameter_list|,
name|int
name|hi
parameter_list|)
block|{
if|if
condition|(
name|val
operator|<
name|lo
condition|)
return|return
name|lo
return|;
if|if
condition|(
name|val
operator|>
name|hi
condition|)
return|return
name|hi
return|;
return|return
name|val
return|;
block|}
end_function

begin_comment
comment|/* Q52 format - used in PHY routines */
end_comment

begin_define
define|#
directive|define
name|INT_TO_Q52
parameter_list|(
name|i
parameter_list|)
value|((i)<< 2)
end_define

begin_define
define|#
directive|define
name|Q52_TO_INT
parameter_list|(
name|q52
parameter_list|)
value|((q52)>> 2)
end_define

begin_define
define|#
directive|define
name|Q52_FMT
value|"%u.%u"
end_define

begin_define
define|#
directive|define
name|Q52_ARG
parameter_list|(
name|q52
parameter_list|)
value|Q52_TO_INT(q52), ((((q52)& 0x3) * 100) / 4)
end_define

begin_function_decl
specifier|extern
name|unsigned
name|int
name|bwn_sqrt
parameter_list|(
name|struct
name|bwn_mac
modifier|*
name|mac
parameter_list|,
name|unsigned
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_BWN_UTIL_H__ */
end_comment

end_unit

