begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_open_stdxxx.h
end_comment

begin_comment
comment|/// \brief      Make sure that file descriptors 0, 1, and 2 are open
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
name|TUKLIB_OPEN_STDXXX_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_OPEN_STDXXX_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_function_decl
name|TUKLIB_DECLS_BEGIN
define|#
directive|define
name|tuklib_open_stdxx
value|TUKLIB_SYMBOL(tuklib_open_stdxxx)
specifier|extern
name|void
name|tuklib_open_stdxxx
parameter_list|(
name|int
name|err_status
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

