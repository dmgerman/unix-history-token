begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* XXX: Depend on our system headers protecting against multiple includes. */
end_comment

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_undef
undef|#
directive|undef
name|_PATH_FTPUSERS
end_undef

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_define
define|#
directive|define
name|_DIAGASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|long
name|strsuftollx
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * IEEE Std 1003.1c-95, adopted in X/Open CAE Specification Issue 5 Version 2  */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
operator|||
name|__XSI_VISIBLE
operator|>=
literal|500
end_if

begin_define
define|#
directive|define
name|LOGIN_NAME_MAX
value|MAXLOGNAME
end_define

begin_comment
comment|/* max login name length (incl. NUL) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

