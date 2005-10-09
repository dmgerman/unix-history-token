begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MD5.H - header file for MD5C.C  */
end_comment

begin_comment
comment|/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All    rights reserved.     License to copy and use this software is granted provided that it    is identified as the "RSA Data Security, Inc. MD5 Message-Digest    Algorithm" in all material mentioning or referencing this software    or this function.     License is also granted to make and use derivative works provided    that such works are identified as "derived from the RSA Data    Security, Inc. MD5 Message-Digest Algorithm" in all material    mentioning or referencing the derived work.                                                                           RSA Data Security, Inc. makes no representations concerning either    the merchantability of this software or the suitability of this    software for any particular purpose. It is provided "as is"    without express or implied warranty of any kind.                                                                           These notices must be retained in any copies of any part of this    documentation and/or software.    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD5_H_
end_ifndef

begin_define
define|#
directive|define
name|_MD5_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*#include "global.h"	*/
comment|/* MD5 context. */
typedef|typedef
struct|struct
block|{
name|UINT4
name|state
index|[
literal|4
index|]
decl_stmt|;
comment|/* state (ABCD) */
name|UINT4
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of bits, modulo 2^64 (lsb first) */
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
comment|/* input buffer */
block|}
name|MD5_CTX
typedef|;
name|void
name|MD5Init
name|PROTO_LIST
argument_list|(
operator|(
name|MD5_CTX
operator|*
operator|)
argument_list|)
decl_stmt|;
name|void
name|MD5Update
name|PROTO_LIST
argument_list|(
operator|(
name|MD5_CTX
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
name|void
name|MD5Final
name|PROTO_LIST
argument_list|(
operator|(
name|unsigned
name|char
index|[
literal|16
index|]
operator|,
name|MD5_CTX
operator|*
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

