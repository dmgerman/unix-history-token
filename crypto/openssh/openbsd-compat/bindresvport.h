begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bindresvport.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_BINDRESVPORT_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_BINDRESVPORT_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BINDRESVPORT_SA
end_ifndef

begin_function_decl
name|int
name|bindresvport_sa
parameter_list|(
name|int
name|sd
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_BINDRESVPORT_SA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_BINDRESVPORT_H */
end_comment

end_unit

