begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * generic krb5-types.h for cross compiling, assume system is posix/sus  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__krb5_types_h__
end_ifndef

begin_define
define|#
directive|define
name|__krb5_types_h__
end_define

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_typedef
typedef|typedef
name|socklen_t
name|krb5_socklen_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_typedef
typedef|typedef
name|ssize_t
name|krb5_ssize_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_extension
argument_list|)
end_if

begin_define
define|#
directive|define
name|__has_extension
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KRB5TYPES_REQUIRE_GNUC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|(((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + __GNUC_PATCHLEVEL__)>= \      (((m) * 10000) + ((n) * 100) + (p)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_DEPRECATED
end_ifndef

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|deprecated
argument_list|)
operator|||
name|KRB5TYPES_REQUIRE_GNUC
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|HEIMDAL_DEPRECATED
value|__attribute__((deprecated))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>
literal|1200
operator|)
end_elif

begin_define
define|#
directive|define
name|HEIMDAL_DEPRECATED
value|__declspec(deprecated)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEIMDAL_DEPRECATED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_PRINTF_ATTRIBUTE
end_ifndef

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|format
argument_list|)
operator|||
name|KRB5TYPES_REQUIRE_GNUC
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|HEIMDAL_PRINTF_ATTRIBUTE
parameter_list|(
name|x
parameter_list|)
value|__attribute__((format x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEIMDAL_PRINTF_ATTRIBUTE
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_NORETURN_ATTRIBUTE
end_ifndef

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|noreturn
argument_list|)
operator|||
name|KRB5TYPES_REQUIRE_GNUC
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|HEIMDAL_NORETURN_ATTRIBUTE
value|__attribute__((noreturn))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEIMDAL_NORETURN_ATTRIBUTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_UNUSED_ATTRIBUTE
end_ifndef

begin_if
if|#
directive|if
name|__has_extension
argument_list|(
name|unused
argument_list|)
operator|||
name|KRB5TYPES_REQUIRE_GNUC
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|HEIMDAL_UNUSED_ATTRIBUTE
value|__attribute__((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HEIMDAL_UNUSED_ATTRIBUTE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|krb5_socket_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __krb5_types_h__ */
end_comment

end_unit

