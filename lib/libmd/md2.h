begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MD2.H - header file for MD2C.C  * $Id: md2.h,v 1.5 1997/02/22 15:07:12 peter Exp $  */
end_comment

begin_comment
comment|/* Copyright (C) 1990-2, RSA Data Security, Inc. Created 1990. All    rights reserved.     License to copy and use this software is granted for    non-commercial Internet Privacy-Enhanced Mail provided that it is    identified as the "RSA Data Security, Inc. MD2 Message Digest    Algorithm" in all material mentioning or referencing this software    or this function.     RSA Data Security, Inc. makes no representations concerning either    the merchantability of this software or the suitability of this    software for any particular purpose. It is provided "as is"    without express or implied warranty of any kind.     These notices must be retained in any copies of any part of this    documentation and/or software.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD2_H_
end_ifndef

begin_define
define|#
directive|define
name|_MD2_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|MD2Context
block|{
name|unsigned
name|char
name|state
index|[
literal|16
index|]
decl_stmt|;
comment|/* state */
name|unsigned
name|char
name|checksum
index|[
literal|16
index|]
decl_stmt|;
comment|/* checksum */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* number of bytes, modulo 16 */
name|unsigned
name|char
name|buffer
index|[
literal|16
index|]
decl_stmt|;
comment|/* input buffer */
block|}
name|MD2_CTX
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|void
name|MD2Init
parameter_list|(
name|MD2_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD2Update
parameter_list|(
name|MD2_CTX
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
name|MD2Final
parameter_list|(
name|unsigned
name|char
index|[
literal|16
index|]
parameter_list|,
name|MD2_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|MD2End
parameter_list|(
name|MD2_CTX
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
name|MD2File
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
name|MD2Data
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

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MD2_H_ */
end_comment

end_unit

