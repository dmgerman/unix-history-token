begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Binutils emulation layer.    Copyright 2002, 2003 Free Software Foundation, Inc.    Written by Tom Rix, Red Hat Inc.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BINEMUL_H
end_ifndef

begin_define
define|#
directive|define
name|BINEMUL_H
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bucomm.h"
end_include

begin_function_decl
specifier|extern
name|void
name|ar_emul_usage
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar_emul_default_usage
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_append
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_default_append
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_replace
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_default_replace
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_parse_arg
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ar_emul_default_parse_arg
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macros for common output.  */
end_comment

begin_define
define|#
directive|define
name|AR_EMUL_USAGE_PRINT_OPTION_HEADER
parameter_list|(
name|fp
parameter_list|)
define|\
comment|/* xgettext:c-format */
define|\
value|fprintf (fp, _(" emulation options: \n"))
end_define

begin_define
define|#
directive|define
name|AR_EMUL_ELEMENT_CHECK
parameter_list|(
name|abfd
parameter_list|,
name|file_name
parameter_list|)
define|\
value|do { if ((abfd) == NULL) bfd_fatal (file_name); } while (0)
end_define

begin_define
define|#
directive|define
name|AR_EMUL_APPEND_PRINT_VERBOSE
parameter_list|(
name|verbose
parameter_list|,
name|file_name
parameter_list|)
define|\
value|do { if (verbose) printf ("a - %s\n", file_name); } while (0)
end_define

begin_define
define|#
directive|define
name|AR_EMUL_REPLACE_PRINT_VERBOSE
parameter_list|(
name|verbose
parameter_list|,
name|file_name
parameter_list|)
define|\
value|do { if (verbose) printf ("r - %s\n", file_name); } while (0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|bin_emulation_xfer_struct
block|{
comment|/* Print out the extra options.  */
name|void
function_decl|(
modifier|*
name|ar_usage
function_decl|)
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
name|bfd_boolean
function_decl|(
modifier|*
name|ar_append
function_decl|)
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
name|bfd_boolean
function_decl|(
modifier|*
name|ar_replace
function_decl|)
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
name|bfd_boolean
function_decl|(
modifier|*
name|ar_parse_arg
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
block|}
name|bin_emulation_xfer_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

