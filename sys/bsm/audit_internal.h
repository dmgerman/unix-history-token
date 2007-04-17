begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Apple Computer, Inc.  * Copyright (c) 2005 SPARTA, Inc.  * All rights reserved.  *  * This code was developed in part by Robert N. M. Watson, Senior Principal  * Scientist, SPARTA, Inc.  *  * @APPLE_BSD_LICENSE_HEADER_START@  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * @APPLE_BSD_LICENSE_HEADER_END@  *  * P4: //depot/projects/trustedbsd/audit3/sys/bsm/audit_internal.h#16  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AUDIT_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_AUDIT_INTERNAL_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__unused
argument_list|)
end_if

begin_define
define|#
directive|define
name|__unused
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * audit_internal.h contains private interfaces that are shared by user space  * and the kernel for the purposes of assembling audit records.  Applications  * should not include this file or use the APIs found within, or it may be  * broken with future releases of OpenBSM, which may delete, modify, or  * otherwise break these interfaces or the assumptions they rely on.  */
end_comment

begin_struct
struct|struct
name|au_token
block|{
name|u_char
modifier|*
name|t_data
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|au_token
argument_list|)
name|tokens
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|au_record
block|{
name|char
name|used
decl_stmt|;
comment|/* Record currently in use? */
name|int
name|desc
decl_stmt|;
comment|/* Descriptor for record. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|au_token
argument_list|)
name|token_q
expr_stmt|;
comment|/* Queue of BSM tokens. */
name|u_char
modifier|*
name|data
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|au_record
argument_list|)
name|au_rec_q
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|au_record
name|au_record_t
typedef|;
end_typedef

begin_comment
comment|/*  * We could determined the header and trailer sizes by defining appropriate  * structures.  We hold off that approach until we have a consistent way of  * using structures for all tokens.  This is not straightforward since these  * token structures may contain pointers of whose contents we do not know the  * size (e.g text tokens).  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_HEADER_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|AUDIT_TRAILER_SIZE
value|7
end_define

begin_comment
comment|/*  * BSM token streams store fields in big endian byte order, so as to be  * portable; when encoding and decoding, we must convert byte orders for  * typed values.  */
end_comment

begin_define
define|#
directive|define
name|ADD_U_CHAR
parameter_list|(
name|loc
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		*(loc) = (val);						\ 		(loc) += sizeof(u_char);				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ADD_U_INT16
parameter_list|(
name|loc
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		be16enc((loc), (val));					\ 		(loc) += sizeof(u_int16_t);				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ADD_U_INT32
parameter_list|(
name|loc
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		be32enc((loc), (val));					\ 		(loc) += sizeof(u_int32_t);				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ADD_U_INT64
parameter_list|(
name|loc
parameter_list|,
name|val
parameter_list|)
define|\
value|do {								\ 		be64enc((loc), (val));					\ 		(loc) += sizeof(u_int64_t); 				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ADD_MEM
parameter_list|(
name|loc
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
define|\
value|do {								\ 		memcpy((loc), (data), (size));				\ 		(loc) += size;						\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ADD_STRING
parameter_list|(
name|loc
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
value|ADD_MEM(loc, data, size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_AUDIT_INTERNAL_H_ */
end_comment

end_unit

