begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* backupfile.h -- declarations for making Emacs style backup file names    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it without restriction.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/* When to make backup files. */
end_comment

begin_enum
enum|enum
name|backup_type
block|{
comment|/* Never make backups. */
name|none
block|,
comment|/* Make simple backups of every file. */
name|simple
block|,
comment|/* Make numbered backups of files that already have numbered backups,      and simple backups of the others. */
name|numbered_existing
block|,
comment|/* Make numbered backups of every file. */
name|numbered
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|backup_type
name|backup_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|simple_backup_suffix
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|char
modifier|*
name|find_backup_file_name
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|backup_type
name|get_version
parameter_list|(
name|char
modifier|*
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|find_backup_file_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|backup_type
name|get_version
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

