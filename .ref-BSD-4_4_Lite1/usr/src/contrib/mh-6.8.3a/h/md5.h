begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)$Id: md5.h,v 1.2 1992/10/26 16:38:50 jromine Exp $ */
end_comment

begin_comment
comment|/* taken from RFC-1321/Appendices A.1/A.2 */
end_comment

begin_comment
comment|/* GLOBAL.H - RSAREF types and constants  */
end_comment

begin_comment
comment|/* PROTOTYPES should be set to one if and only if the compiler supports   function argument prototyping. The following makes PROTOTYPES default to 0 if it has not already   been defined with C compiler flags.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|PROTOTYPES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POINTER defines a generic pointer type */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|POINTER
typedef|;
end_typedef

begin_comment
comment|/* UINT2 defines a two byte word */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|UINT2
typedef|;
end_typedef

begin_comment
comment|/* UINT4 defines a four byte word */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|UINT4
typedef|;
end_typedef

begin_comment
comment|/* PROTO_LIST is defined depending on how PROTOTYPES is defined above. If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it   returns an empty list.  */
end_comment

begin_if
if|#
directive|if
name|PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PROTO_LIST
parameter_list|(
name|list
parameter_list|)
value|list
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO_LIST
parameter_list|(
name|list
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD5.H - header file for MD5C.C  */
end_comment

begin_comment
comment|/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All rights reserved.  License to copy and use this software is granted provided that it is identified as the "RSA Data Security, Inc. MD5 Message-Digest Algorithm" in all material mentioning or referencing this software or this function.  License is also granted to make and use derivative works provided that such works are identified as "derived from the RSA Data Security, Inc. MD5 Message-Digest Algorithm" in all material mentioning or referencing the derived work.  RSA Data Security, Inc. makes no representations concerning either the merchantability of this software or the suitability of this software for any particular purpose. It is provided "as is" without express or implied warranty of any kind.  These notices must be retained in any copies of any part of this documentation and/or software.  */
end_comment

begin_comment
comment|/* MD5 context. */
end_comment

begin_typedef
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
end_typedef

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

end_unit

