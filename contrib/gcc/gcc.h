begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for modules that link with gcc.c    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GCC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GCC_H
end_define

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* The mapping of a spec function name to the C function that    implements it.  */
end_comment

begin_struct
struct|struct
name|spec_function
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
operator|*
operator|(
operator|*
name|func
operator|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This defines which switch letters take arguments.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|((CHAR) == 'D' || (CHAR) == 'U' || (CHAR) == 'o' \    || (CHAR) == 'e' || (CHAR) == 'T' || (CHAR) == 'u' \    || (CHAR) == 'I' || (CHAR) == 'm' || (CHAR) == 'x' \    || (CHAR) == 'L' || (CHAR) == 'A' || (CHAR) == 'V' \    || (CHAR) == 'B' || (CHAR) == 'b')
end_define

begin_comment
comment|/* This defines which multi-letter switches take arguments.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(!strcmp (STR, "Tdata") || !strcmp (STR, "Ttext")	\   || !strcmp (STR, "Tbss") || !strcmp (STR, "include")	\   || !strcmp (STR, "imacros") || !strcmp (STR, "aux-info") \   || !strcmp (STR, "idirafter") || !strcmp (STR, "iprefix") \   || !strcmp (STR, "iwithprefix") || !strcmp (STR, "iwithprefixbefore") \   || !strcmp (STR, "isystem") || !strcmp (STR, "-param") \   || !strcmp (STR, "specs") \   || !strcmp (STR, "MF") || !strcmp (STR, "MT") || !strcmp (STR, "MQ"))
end_define

begin_comment
comment|/* These are exported by gcc.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|do_spec
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_temp_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fancy_abort
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|input_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|input_filename_length
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fatal
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_1
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|error
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pfatal_with_name
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_input
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Spec files linked with gcc.c must provide definitions for these.  */
end_comment

begin_comment
comment|/* Called before processing to change/add/remove arguments.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|lang_specific_driver
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called before linking.  Returns 0 on success and -1 on failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lang_specific_pre_link
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_infiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of extra output files that lang_specific_pre_link may generate.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lang_specific_extra_outfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table of language-specific spec functions.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|spec_function
name|lang_specific_spec_functions
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A vector of corresponding output files is made up later.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|outfiles
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GCC_H */
end_comment

end_unit

