begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for AMD Am29000 CPU, Unix.    Copyright (C) 1991 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is mostly the same as a29k.h, except that we define unix instead of    EPI and define unix-style machine names.  */
end_comment

begin_include
include|#
directive|include
file|"a29k.h"
end_include

begin_comment
comment|/* Set our default target to be the 29050; that is the more interesting chip    for Unix systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(1+2+8+64)
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dam29k -Da29k -Dam29000"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!m29000:-Dam29050 -D__am29050__}"
end_define

begin_comment
comment|/* Use a default linker configuration file.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-T default.gld%s"
end_define

begin_comment
comment|/* For some systems, it is best if double-word objects are aligned on a     doubleword boundary.  We want to maintain compatibility with MetaWare in    a29k.h, but do not feel constrained to do so here.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Add shared data as a kludge for now.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{ char *p, *after_dir = main_input_filename;			\   if (TARGET_29050)						\     fprintf (FILE, "\t.cputype 29050\n");			\   for (p = main_input_filename; *p; p++)			\     if (*p == '/')						\       after_dir = p + 1;					\   fprintf (FILE, "\t.file \"%s\"\n", after_dir);		\   if (flag_shared_data)						\     fprintf (FILE, "\t.sect .shdata,data\n");			\   fprintf (FILE, "\t.sect .lit,lit\n");  }
end_define

begin_comment
comment|/* Output before shared  data.  */
end_comment

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|"\t.use .shdata"
end_define

begin_comment
comment|/* If we want shared data, we have to turn off commons.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|if (flag_shared_data) flag_no_common = 1;
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This would be needed except that the 29k doesn't have strict 	 alignment requirements.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(((TYPE) != 0)							\ 	? ((TYPE_ALIGN(TYPE)<= PARM_BOUNDARY)				\ 		? PARM_BOUNDARY						\ 		: TYPE_ALIGN(TYPE))					\ 	: ((GET_MODE_ALIGNMENT(MODE)<= PARM_BOUNDARY)			\ 		? PARM_BOUNDARY						\ 		: GET_MODE_ALIGNMENT(MODE)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

