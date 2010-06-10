begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_cpucores.h
end_comment

begin_comment
comment|/// \brief      Get the number of CPU cores online
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
name|TUKLIB_CPUCORES_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_CPUCORES_H
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
name|tuklib_cpucores
value|TUKLIB_SYMBOL(tuklib_cpucores)
specifier|extern
name|uint32_t
name|tuklib_cpucores
parameter_list|(
name|void
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

