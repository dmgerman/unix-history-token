begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file common.h  *  * Common definitions for LDNS  */
end_comment

begin_comment
comment|/**  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2004-2006  *  * See the file LICENSE for the license  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_COMMON_H
end_define

begin_comment
comment|/*  * The build configuration that is used in the distributed headers,  * as detected and determined by the auto configure script.  */
end_comment

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_SSL
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_INTTYPES_H
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_ATTR_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_ATTR_UNUSED
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_SOCKLEN_T
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_USE_DANE
value|1
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_B32_PTON
value|0
end_define

begin_define
define|#
directive|define
name|LDNS_BUILD_CONFIG_HAVE_B32_NTOP
value|0
end_define

begin_comment
comment|/*  * HAVE_STDBOOL_H is not available when distributed as a library, but no build   * configuration variables may be used (like those above) because the header  * is sometimes only available when using special compiler flags to enable the  * c99 environment. Because we cannot force the usage of this flag, we have to  * provide a default type. Below what is suggested by the autoconf manual.  */
end_comment

begin_comment
comment|/*@ignore@*/
end_comment

begin_comment
comment|/* splint barfs on this construct */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDBOOL_H
end_ifdef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE__BOOL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_typedef
typedef|typedef
name|bool
name|_Bool
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Bool
value|signed char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*@end@*/
end_comment

begin_if
if|#
directive|if
name|LDNS_BUILD_CONFIG_HAVE_ATTR_FORMAT
end_if

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|archetype
parameter_list|,
name|string_index
parameter_list|,
name|first_to_check
parameter_list|)
define|\
value|__attribute__ ((format (archetype, string_index, first_to_check)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LDNS_BUILD_CONFIG_HAVE_ATTR_FORMAT */
end_comment

begin_define
define|#
directive|define
name|ATTR_FORMAT
parameter_list|(
name|archetype
parameter_list|,
name|string_index
parameter_list|,
name|first_to_check
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LDNS_BUILD_CONFIG_HAVE_ATTR_FORMAT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
name|LDNS_BUILD_CONFIG_HAVE_ATTR_UNUSED
end_elif

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
value|x __attribute__((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LDNS_BUILD_CONFIG_HAVE_ATTR_UNUSED */
end_comment

begin_define
define|#
directive|define
name|ATTR_UNUSED
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LDNS_BUILD_CONFIG_HAVE_ATTR_UNUSED */
end_comment

begin_if
if|#
directive|if
operator|!
name|LDNS_BUILD_CONFIG_HAVE_SOCKLEN_T
end_if

begin_typedef
typedef|typedef
name|int
name|socklen_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_COMMON_H */
end_comment

end_unit

