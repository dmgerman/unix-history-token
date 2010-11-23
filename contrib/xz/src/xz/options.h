begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       options.h
end_comment

begin_comment
comment|/// \brief      Parser for filter-specific options
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

begin_comment
comment|/// \brief      Parser for Delta options
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Pointer to allocated options structure.
end_comment

begin_comment
comment|///             Doesn't return on error.
end_comment

begin_function_decl
specifier|extern
name|lzma_options_delta
modifier|*
name|options_delta
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Parser for BCJ options
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Pointer to allocated options structure.
end_comment

begin_comment
comment|///             Doesn't return on error.
end_comment

begin_function_decl
specifier|extern
name|lzma_options_bcj
modifier|*
name|options_bcj
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Parser for LZMA options
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Pointer to allocated options structure.
end_comment

begin_comment
comment|///             Doesn't return on error.
end_comment

begin_function_decl
specifier|extern
name|lzma_options_lzma
modifier|*
name|options_lzma
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

end_unit

