begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ***********************************************************************  ** md5.h -- header file for implementation of MD5                    **  ** RSA Data Security, Inc. MD5 Message-Digest Algorithm              **  ** Created: 2/17/90 RLR                                              **  ** Revised: 12/27/90 SRD,AJ,BSK,JT Reference C version               **  ** Revised (for MD5): RLR 4/27/91                                    **  **   -- G modified to have y&~z instead of y&z                       **  **   -- FF, GG, HH modified to add in last register done             **  **   -- Access pattern: round 2 works mod 5, round 3 works mod 3     **  **   -- distinct additive constant for each step                     **  **   -- round 4 added, working mod 7                                 **  ***********************************************************************  */
end_comment

begin_comment
comment|/*  ***********************************************************************  ** Copyright (C) 1990, RSA Data Security, Inc. All rights reserved.  **  **                                                                   **  ** License to copy and use this software is granted provided that    **  ** it is identified as the "RSA Data Security, Inc. MD5 Message-     **  ** Digest Algorithm" in all material mentioning or referencing this  **  ** software or this function.                                        **  **                                                                   **  ** License is also granted to make and use derivative works          **  ** provided that such works are identified as "derived from the RSA  **  ** Data Security, Inc. MD5 Message-Digest Algorithm" in all          **  ** material mentioning or referencing the derived work.              **  **                                                                   **  ** RSA Data Security, Inc. makes no representations concerning       **  ** either the merchantability of this software or the suitability    **  ** of this software for any particular purpose.  It is provided "as  **  ** is" without express or implied warranty of any kind.              **  **                                                                   **  ** These notices must be retained in any copies of any part of this  **  ** documentation and/or software.                                    **  ***********************************************************************  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MD5_INCLUDE__
end_ifndef

begin_comment
comment|/* typedef a 32-bit type */
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
comment|/* Data structure for MD5 (Message-Digest) computation */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT4
name|i
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of _bits_ handled mod 2^64 */
name|UINT4
name|buf
index|[
literal|4
index|]
decl_stmt|;
comment|/* scratch buffer */
name|unsigned
name|char
name|in
index|[
literal|64
index|]
decl_stmt|;
comment|/* input buffer */
name|unsigned
name|char
name|digest
index|[
literal|16
index|]
decl_stmt|;
comment|/* actual digest after MD5Final call */
block|}
name|MD5_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|MD5Init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Final
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__MD5_INCLUDE__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MD5_INCLUDE__ */
end_comment

end_unit

