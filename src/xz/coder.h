begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       coder.h
end_comment

begin_comment
comment|/// \brief      Compresses or uncompresses a file
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

begin_enum
enum|enum
name|operation_mode
block|{
name|MODE_COMPRESS
block|,
name|MODE_DECOMPRESS
block|,
name|MODE_TEST
block|,
name|MODE_LIST
block|, }
enum|;
end_enum

begin_comment
comment|// NOTE: The order of these is significant in suffix.c.
end_comment

begin_enum
enum|enum
name|format_type
block|{
name|FORMAT_AUTO
block|,
name|FORMAT_XZ
block|,
name|FORMAT_LZMA
block|,
comment|// HEADER_GZIP,
name|FORMAT_RAW
block|, }
enum|;
end_enum

begin_comment
comment|/// Operation mode of the command line tool. This is set in args.c and read
end_comment

begin_comment
comment|/// in several files.
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|operation_mode
name|opt_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// File format to use when encoding or what format(s) to accept when
end_comment

begin_comment
comment|/// decoding. This is a global because it's needed also in suffix.c.
end_comment

begin_comment
comment|/// This is set in args.c.
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|format_type
name|opt_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If true, the compression settings are automatically adjusted down if
end_comment

begin_comment
comment|/// they exceed the memory usage limit.
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_auto_adjust
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set the integrity check type used when compressing
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_set_check
parameter_list|(
name|lzma_check
name|check
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set preset number
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_set_preset
parameter_list|(
name|uint32_t
name|new_preset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Enable extreme mode
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_set_extreme
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Add a filter to the custom filter chain
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_add_filter
parameter_list|(
name|lzma_vli
name|id
parameter_list|,
name|void
modifier|*
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_set_compression_settings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Compress or decompress the given file
end_comment

begin_function_decl
specifier|extern
name|void
name|coder_run
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

end_unit

