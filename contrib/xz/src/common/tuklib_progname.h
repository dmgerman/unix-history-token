begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_progname.h
end_comment

begin_comment
comment|/// \brief      Program name to be displayed in messages
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_PROGNAME_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_PROGNAME_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
name|TUKLIB_DECLS_BEGIN
if|#
directive|if
name|HAVE_DECL_PROGRAM_INVOCATION_NAME
define|#
directive|define
name|progname
value|program_invocation_name
else|#
directive|else
define|#
directive|define
name|progname
value|TUKLIB_SYMBOL(tuklib_progname)
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tuklib_progname_init
value|TUKLIB_SYMBOL(tuklib_progname_init)
end_define

begin_function_decl
specifier|extern
name|void
name|tuklib_progname_init
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|TUKLIB_DECLS_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

