begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: base64.h,v 1.3 2002/02/26 16:59:59 stevesk Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_BASE64_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___B64_NTOP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_B64_NTOP
end_ifndef

begin_function_decl
name|int
name|b64_ntop
parameter_list|(
name|u_char
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|srclength
parameter_list|,
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|b64_pton
parameter_list|(
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|u_char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_B64_NTOP */
end_comment

begin_define
define|#
directive|define
name|__b64_ntop
value|b64_ntop
end_define

begin_define
define|#
directive|define
name|__b64_pton
value|b64_pton
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___B64_NTOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_BASE64_H */
end_comment

end_unit

