begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ***********************************************************************  ** md5.h -- header file for implementation of MD5                    **  ** RSA Data Security, Inc. MD5 Message-Digest Algorithm              **  ** Created: 2/17/90 RLR                                              **  ** Revised: 12/27/90 SRD,AJ,BSK,JT Reference C version               **  ** Revised (for MD5): RLR 4/27/91                                    **  ***********************************************************************  */
end_comment

begin_comment
comment|/*  ***********************************************************************  ** Copyright (C) 1990, RSA Data Security, Inc. All rights reserved.  **  **                                                                   **  ** License to copy and use this software is granted provided that    **  ** it is identified as the "RSA Data Security, Inc. MD5 Message-     **  ** Digest Algorithm" in all material mentioning or referencing this  **  ** software or this function.                                        **  **                                                                   **  ** License is also granted to make and use derivative works          **  ** provided that such works are identified as "derived from the RSA  **  ** Data Security, Inc. MD5 Message-Digest Algorithm" in all          **  ** material mentioning or referencing the derived work.              **  **                                                                   **  ** RSA Data Security, Inc. makes no representations concerning       **  ** either the merchantability of this software or the suitability    **  ** of this software for any particular purpose.  It is provided "as  **  ** is" without express or implied warranty of any kind.              **  **                                                                   **  ** These notices must be retained in any copies of any part of this  **  ** documentation and/or software.                                    **  ***********************************************************************  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/* typedef a 32-bit type */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|LONG
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

begin_comment
comment|/*  ***********************************************************************  ** End of md5.h                                                      **  ******************************** (cut) ********************************  */
end_comment

end_unit

