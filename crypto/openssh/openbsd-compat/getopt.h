begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: getopt.h,v 1.4 2001/09/18 05:05:21 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSDGETOPT_H
end_ifndef

begin_define
define|#
directive|define
name|_BSDGETOPT_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GETOPT
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_GETOPT_OPTRESET
argument_list|)
end_if

begin_function_decl
name|int
name|BSDgetopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSDGETOPT_H */
end_comment

end_unit

