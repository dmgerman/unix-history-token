begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: auth2-pam.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PAM
end_ifdef

begin_function_decl
name|int
name|auth2_pam
parameter_list|(
name|Authctxt
modifier|*
name|authctxt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_PAM */
end_comment

end_unit

