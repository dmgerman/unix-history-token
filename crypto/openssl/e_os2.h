begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* e_os2.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_E_OS2_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_E_OS2_H
end_define

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_comment
comment|/* OPENSSL_UNISTD */
end_comment

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
ifdef|#
directive|ifdef
name|MSDOS
define|#
directive|define
name|OPENSSL_UNISTD_IO
value|<io.h>
define|#
directive|define
name|OPENSSL_DECLARE_EXIT
value|extern void exit(int);
else|#
directive|else
define|#
directive|define
name|OPENSSL_UNISTD_IO
value|OPENSSL_UNISTD
define|#
directive|define
name|OPENSSL_DECLARE_EXIT
comment|/* declared in unistd.h */
endif|#
directive|endif
comment|/* Definitions of OPENSSL_GLOBAL and OPENSSL_EXTERN,    to define and declare certain global    symbols that, with some compilers under VMS, have to be defined and    declared explicitely with globaldef and globalref.  On other OS:es,    these macros are defined with something sensible. */
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__DECC
argument_list|)
define|#
directive|define
name|OPENSSL_EXTERN
value|globalref
define|#
directive|define
name|OPENSSL_GLOBAL
value|globaldef
else|#
directive|else
define|#
directive|define
name|OPENSSL_EXTERN
value|extern
define|#
directive|define
name|OPENSSL_GLOBAL
endif|#
directive|endif
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

