begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_LIBINTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBINTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|domain
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|gettext
parameter_list|(
modifier|...
parameter_list|)
value|(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|domain
parameter_list|,
modifier|...
parameter_list|)
value|(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SOLARIS_H_ */
end_comment

end_unit

