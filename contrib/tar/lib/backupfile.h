begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* backupfile.h -- declarations for making Emacs style backup file names    Copyright (C) 1990-1992, 1997-1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BACKUPFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|BACKUPFILE_H_
end_define

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

begin_define
define|#
directive|define
name|VALID_BACKUP_TYPE
parameter_list|(
name|Type
parameter_list|)
define|\
value|((Type) == none			\    || (Type) == simple			\    || (Type) == numbered_existing	\    || (Type) == numbered)
end_define

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|simple_backup_suffix
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|find_backup_file_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|enum
name|backup_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|backup_type
name|get_version
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|context
operator|,
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|backup_type
name|xget_version
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|context
operator|,
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|addext
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BACKUPFILE_H_ */
end_comment

end_unit

