begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_exit.h
end_comment

begin_comment
comment|/// \brief      Close stdout and stderr, and exit
end_comment

begin_comment
comment|/// \note       Requires tuklib_progname and tuklib_gettext modules
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
name|TUKLIB_EXIT_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_EXIT_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_decl_stmt
name|TUKLIB_DECLS_BEGIN
define|#
directive|define
name|tuklib_exit
value|TUKLIB_SYMBOL(tuklib_exit)
specifier|extern
name|void
name|tuklib_exit
argument_list|(
name|int
name|status
argument_list|,
name|int
name|err_status
argument_list|,
name|int
name|show_error
argument_list|)
name|tuklib_attr_noreturn
decl_stmt|;
end_decl_stmt

begin_macro
name|TUKLIB_DECLS_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

