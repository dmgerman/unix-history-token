begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is part of GNU paxutils     Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2003,    2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_paxlib_h_
end_ifndef

begin_define
define|#
directive|define
name|_paxlib_h_
end_define

begin_include
include|#
directive|include
file|<hash.h>
end_include

begin_include
include|#
directive|include
file|<inttostr.h>
end_include

begin_comment
comment|/* Error reporting functions and definitions */
end_comment

begin_comment
comment|/* Exit status for paxutils app.  Let's try to keep this list as simple as    possible. tar -d option strongly invites a status different for unequal    comparison and other errors.  */
end_comment

begin_define
define|#
directive|define
name|PAXEXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|PAXEXIT_DIFFERS
value|1
end_define

begin_define
define|#
directive|define
name|PAXEXIT_FAILURE
value|2
end_define

begin_comment
comment|/* Both WARN and ERROR write a message on stderr and continue processing,    however ERROR manages so tar will exit unsuccessfully.  FATAL_ERROR    writes a message on stderr and aborts immediately, with another message    line telling so.  USAGE_ERROR works like FATAL_ERROR except that the    other message line suggests trying --help.  All four macros accept a    single argument of the form ((0, errno, _("FORMAT"), Args...)).  errno    is zero when the error is not being detected by the system.  */
end_comment

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|Args
parameter_list|)
define|\
value|error Args
end_define

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, exit_status = PAXEXIT_FAILURE)
end_define

begin_define
define|#
directive|define
name|FATAL_ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, fatal_exit ())
end_define

begin_define
define|#
directive|define
name|USAGE_ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, usage (PAXEXIT_FAILURE))
end_define

begin_decl_stmt
specifier|extern
name|int
name|exit_status
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pax_decode_mode
parameter_list|(
name|mode_t
name|mode
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|call_arg_error
parameter_list|(
name|char
specifier|const
modifier|*
name|call
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|call_arg_fatal
parameter_list|(
name|char
specifier|const
modifier|*
name|call
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|call_arg_warn
parameter_list|(
name|char
specifier|const
modifier|*
name|call
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chmod_error_details
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chown_error_details
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_mode
parameter_list|(
name|mode_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chdir_fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|chmod_error_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chown_error_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exec_fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|link_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mkdir_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mkfifo_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mknod_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|open_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_error_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|read_fatal_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|read_warn_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|readlink_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|readlink_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmdir_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savedir_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savedir_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seek_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seek_error_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seek_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|seek_warn_details
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_fatal
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|symlink_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|truncate_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|truncate_warn
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unlink_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utime_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|waitpid_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_error
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pax_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal_exit
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|STRINGIFY_BIGINT
parameter_list|(
name|i
parameter_list|,
name|b
parameter_list|)
value|umaxtostr (i, b)
end_define

begin_escape
end_escape

begin_comment
comment|/* Name-related functions */
end_comment

begin_function_decl
name|bool
name|hash_string_insert
parameter_list|(
name|Hash_table
modifier|*
modifier|*
name|table
parameter_list|,
name|char
specifier|const
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hash_string_lookup
parameter_list|(
name|Hash_table
specifier|const
modifier|*
name|table
parameter_list|,
name|char
specifier|const
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|removed_prefixes_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safer_name_suffix
parameter_list|(
name|char
specifier|const
modifier|*
name|file_name
parameter_list|,
name|bool
name|link_target
parameter_list|,
name|bool
name|absolute_names
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

