begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MD5.H - header file for MD5C.C  * $Id: md5.h,v 1.6 1996/12/22 10:31:34 phk Exp $  */
end_comment

begin_comment
comment|/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All rights reserved.  License to copy and use this software is granted provided that it is identified as the "RSA Data Security, Inc. MD5 Message-Digest Algorithm" in all material mentioning or referencing this software or this function.  License is also granted to make and use derivative works provided that such works are identified as "derived from the RSA Data Security, Inc. MD5 Message-Digest Algorithm" in all material mentioning or referencing the derived work.  RSA Data Security, Inc. makes no representations concerning either the merchantability of this software or the suitability of this software for any particular purpose. It is provided "as is" without express or implied warranty of any kind.  These notices must be retained in any copies of any part of this documentation and/or software.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MD5_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MD5_H_
end_define

begin_comment
comment|/* MD5 context. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|MD5Context
block|{
name|u_int32_t
name|state
index|[
literal|4
index|]
decl_stmt|;
comment|/* state (ABCD) */
name|u_int32_t
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

begin_function_decl
name|void
name|MD5Init
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Update
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Final
parameter_list|(
name|unsigned
name|char
index|[
literal|16
index|]
parameter_list|,
name|MD5_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MD5End
parameter_list|(
name|MD5_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MD5File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MD5Data
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MD5_H_ */
end_comment

end_unit

