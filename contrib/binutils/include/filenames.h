begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macros for taking apart, interpreting and processing file names.     These are here because some non-Posix (a.k.a. DOSish) systems have    drive letter brain-damage at the beginning of an absolute file name,    use forward- and back-slash in path names interchangeably, and    some of them have case-insensitive file names.     Copyright 2000 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILENAMES_H
end_ifndef

begin_define
define|#
directive|define
name|FILENAMES_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__OS2__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DOS_BASED_FILE_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILE_SYSTEM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|c
parameter_list|)
value|((c) == '/' || (c) == '\\')
end_define

begin_comment
comment|/* Note that IS_ABSOLUTE_PATH accepts d:foo as well, although it is    only semi-absolute.  This is because the users of IS_ABSOLUTE_PATH    want to know whether to prepend the current working directory to    a file name, which should not be done with a name like d:foo.  */
end_comment

begin_define
define|#
directive|define
name|IS_ABSOLUTE_PATH
parameter_list|(
name|f
parameter_list|)
value|(IS_DIR_SEPARATOR((f)[0]) || (((f)[0])&& ((f)[1] == ':')))
end_define

begin_define
define|#
directive|define
name|FILENAME_CMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcasecmp(s1, s2)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not DOSish */
end_comment

begin_define
define|#
directive|define
name|IS_DIR_SEPARATOR
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_define
define|#
directive|define
name|IS_ABSOLUTE_PATH
parameter_list|(
name|f
parameter_list|)
value|(IS_DIR_SEPARATOR((f)[0]))
end_define

begin_define
define|#
directive|define
name|FILENAME_CMP
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|strcmp(s1, s2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DOSish */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FILENAMES_H */
end_comment

end_unit

