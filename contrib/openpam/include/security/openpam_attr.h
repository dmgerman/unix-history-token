begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $OpenPAM: openpam_attr.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SECURITY_OPENPAM_ATTR_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SECURITY_OPENPAM_ATTR_H_INCLUDED
end_define

begin_comment
comment|/* GCC attributes */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC_MINOR__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPENPAM_GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
define|\
value|((__GNUC__<< 16) + __GNUC_MINOR__>= ((maj)<< 16) + (min))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPENPAM_GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENPAM_GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|5
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPENPAM_FORMAT
parameter_list|(
name|params
parameter_list|)
value|__attribute__((__format__ params))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPENPAM_FORMAT
parameter_list|(
name|params
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENPAM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|3
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPENPAM_NONNULL
parameter_list|(
name|params
parameter_list|)
value|__attribute__((__nonnull__ params))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPENPAM_NONNULL
parameter_list|(
name|params
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENPAM_GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPENPAM_UNUSED
parameter_list|(
name|var
parameter_list|)
value|var __attribute__((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPENPAM_UNUSED
parameter_list|(
name|var
parameter_list|)
value|var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SECURITY_OPENPAM_ATTR_H_INCLUDED */
end_comment

end_unit

