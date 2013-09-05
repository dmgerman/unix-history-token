begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CAPRIGHTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CAPRIGHTS_H_
end_define

begin_comment
comment|/*  * The top two bits in the first element of the cr_rights[] array contain  * total number of elements in the array - 2. This means if those two bits are  * equal to 0, we have 2 array elements.  * The top two bits in all remaining array elements should be 0.  * The next five bits contain array index. Only one bit is used and bit position  * in this five-bits range defines array index. This means there can be at most  * five array elements.  */
end_comment

begin_define
define|#
directive|define
name|CAP_RIGHTS_VERSION_00
value|0
end_define

begin_comment
comment|/* #define	CAP_RIGHTS_VERSION_01	1 #define	CAP_RIGHTS_VERSION_02	2 #define	CAP_RIGHTS_VERSION_03	3 */
end_comment

begin_define
define|#
directive|define
name|CAP_RIGHTS_VERSION
value|CAP_RIGHTS_VERSION_00
end_define

begin_struct
struct|struct
name|cap_rights
block|{
name|uint64_t
name|cr_rights
index|[
name|CAP_RIGHTS_VERSION
operator|+
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_CAP_RIGHTS_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_CAP_RIGHTS_T_DECLARED
end_define

begin_typedef
typedef|typedef
name|struct
name|cap_rights
name|cap_rights_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CAPRIGHTS_H_ */
end_comment

end_unit

