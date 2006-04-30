begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/* $Id: md5crypt.h,v 1.4 2003/05/18 14:46:46 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD5CRYPT_H
end_ifndef

begin_define
define|#
directive|define
name|_MD5CRYPT_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MD5_PASSWORDS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_MD5_CRYPT
argument_list|)
end_if

begin_function_decl
name|int
name|is_md5_salt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|md5_crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
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
comment|/* defined(HAVE_MD5_PASSWORDS)&& !defined(HAVE_MD5_CRYPT) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD5CRYPT_H */
end_comment

end_unit

