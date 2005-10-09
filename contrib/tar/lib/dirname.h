begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1998, 2001 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2, or (at your option)     any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; if not, write to the Free Software Foundation,     Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRNAME_H_
end_ifndef

begin_define
define|#
directive|define
name|DIRNAME_H_
value|1
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|DIRECTORY_SEPARATOR
end_ifndef

begin_define
define|#
directive|define
name|DIRECTORY_SEPARATOR
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISSLASH
end_ifndef

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|C
parameter_list|)
value|((C) == DIRECTORY_SEPARATOR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYSTEM_PREFIX_LEN
end_ifndef

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|Filename
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|base_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dir_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|base_len
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|dir_len
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strip_trailing_slashes
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DIRNAME_H_ */
end_comment

end_unit

