begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       args.h
end_comment

begin_comment
comment|/// \brief      Argument parsing
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

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/// Filenames from command line
name|char
modifier|*
modifier|*
name|arg_names
decl_stmt|;
comment|/// Number of filenames from command line
name|size_t
name|arg_count
decl_stmt|;
comment|/// Name of the file from which to read filenames. This is NULL
comment|/// if --files or --files0 was not used.
name|char
modifier|*
name|files_name
decl_stmt|;
comment|/// File opened for reading from which filenames are read. This is
comment|/// non-NULL only if files_name is non-NULL.
name|FILE
modifier|*
name|files_file
decl_stmt|;
comment|/// Delimiter for filenames read from files_file
name|char
name|files_delim
decl_stmt|;
block|}
name|args_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|bool
name|opt_stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_force
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_keep_original
decl_stmt|;
end_decl_stmt

begin_comment
comment|// extern bool opt_recursive;
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_robot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_ignore_check
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|stdin_filename
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|args_parse
parameter_list|(
name|args_info
modifier|*
name|args
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|args_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

