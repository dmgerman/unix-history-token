begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* filesys.h -- external declarations for filesys.c.    $Id: filesys.h,v 1.5 1998/07/21 22:25:44 karl Exp $     Copyright (C) 1993, 97, 98 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFO_FILESYS_H
end_ifndef

begin_define
define|#
directive|define
name|INFO_FILESYS_H
end_define

begin_comment
comment|/* The path on which we look for info files.  You can initialize this    from the environment variable INFOPATH if there is one, or you can    call info_add_path () to add paths to the beginning or end of it. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|infopath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make INFOPATH have absolutely nothing in it. */
end_comment

begin_function_decl
specifier|extern
name|void
name|zap_infopath
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Add PATH to the list of paths found in INFOPATH.  2nd argument says    whether to put PATH at the front or end of INFOPATH. */
end_comment

begin_function_decl
specifier|extern
name|void
name|info_add_path
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defines that are passed along with the pathname to info_add_path (). */
end_comment

begin_define
define|#
directive|define
name|INFOPATH_PREPEND
value|0
end_define

begin_define
define|#
directive|define
name|INFOPATH_APPEND
value|1
end_define

begin_comment
comment|/* Expand the filename in PARTIAL to make a real name for this operating    system.  This looks in INFO_PATHS in order to find the correct file.    If it can't find the file, it returns NULL. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|info_find_fullpath
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Given a chunk of text and its length, convert all CRLF pairs at the    EOLs into a single Newline character.  Return the length of produced    text.  */
end_comment

begin_function_decl
name|long
name|convert_eols
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read the contents of PATHNAME, returning a buffer with the contents of    that file in it, and returning the size of that buffer in FILESIZE.    FINFO is a stat struct which has already been filled in by the caller.    If the file cannot be read, return a NULL pointer. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|filesys_read_info_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|filesys_read_compressed
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the command string that would be used to decompress FILENAME. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|filesys_decompressor_for_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|compressed_filename_p
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A function which returns a pointer to a static buffer containing    an error message for FILENAME and ERROR_NUM. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|filesys_error_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The number of the most recent file system error. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|filesys_error_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a string containing units of information separated by colons,    return the next one pointed to by IDX, or NULL if there are no more.    Advance IDX to the character after the colon. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|extract_colon_unit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return true if FILENAME is `dir', with a possible compression suffix.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_dir_name
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The default value of INFOPATH. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEFAULT_INFOPATH
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_INFOPATH
value|"/usr/local/info:/usr/info:/usr/local/lib/info:/usr/lib/info:/usr/local/gnu/info:/usr/local/gnu/lib/info:/usr/gnu/info:/usr/gnu/lib/info:/opt/gnu/info:/usr/share/info:/usr/share/lib/info:/usr/local/share/info:/usr/local/share/lib/info:/usr/gnu/lib/emacs/info:/usr/local/gnu/lib/emacs/info:/usr/local/lib/emacs/info:/usr/local/emacs/info:."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DEFAULT_INFOPATH */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_ISREG&& S_IFREG */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !S_ISDIR&& S_IFDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not INFO_FILESYS_H */
end_comment

end_unit

