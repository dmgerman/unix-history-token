begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Binutils emulation layer.    Copyright (C) 2002 Free Software Foundation, Inc.    Written by Tom Rix, Redhat.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|void
name|ar_emul_usage
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ar_emul_default_usage
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_append
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_default_append
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_replace
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_default_replace
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_create
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_default_create
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_parse_arg
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ar_emul_default_parse_arg
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|do { if ((abfd) == (bfd *) NULL) bfd_fatal (file_name); } while (0)
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
argument_list|(
argument|* ar_usage
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|fp
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|* ar_append
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|* ar_replace
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|boolean
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|* ar_create
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|boolean
argument_list|(
argument|* ar_parse_arg
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
name|bin_emulation_xfer_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

