begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bad.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 2002 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       bad.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_BAD_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_BAD_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|FFEBAD_MSG
parameter_list|(
name|KWD
parameter_list|,
name|SEV
parameter_list|,
name|MSG
parameter_list|)
value|KWD,
include|#
directive|include
file|"bad.def"
undef|#
directive|undef
name|FFEBAD_MSG
name|FFEBAD
block|}
name|ffebad
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Order important; must be increasing severity. */
name|FFEBAD_severityINFORMATIONAL
block|,
comment|/* User notice. */
name|FFEBAD_severityTRIVIAL
block|,
comment|/* Internal notice. */
name|FFEBAD_severityWARNING
block|,
comment|/* User warning. */
name|FFEBAD_severityPECULIAR
block|,
comment|/* Internal warning. */
name|FFEBAD_severityPEDANTIC
block|,
comment|/* Pedantic, could be warning or error. */
name|FFEBAD_severityFATAL
block|,
comment|/* User error. */
name|FFEBAD_severityWEIRD
block|,
comment|/* Internal error. */
name|FFEBAD_severitySEVERE
block|,
comment|/* User error, cannot continue. */
name|FFEBAD_severityDISASTER
block|,
comment|/* Internal error, cannot continue. */
name|FFEBAD_severity
block|}
name|ffebadSeverity
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffebadIndex
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|ffebad_is_inhibited_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffebad_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebad_here
parameter_list|(
name|ffebadIndex
name|i
parameter_list|,
name|ffewhereLine
name|wl
parameter_list|,
name|ffewhereColumn
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebad_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffebad_is_fatal
parameter_list|(
name|ffebad
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebadSeverity
name|ffebad_severity
parameter_list|(
name|ffebad
name|errnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffebad_start_
parameter_list|(
name|bool
name|lex_override
parameter_list|,
name|ffebad
name|errnum
parameter_list|,
name|ffebadSeverity
name|sev
parameter_list|,
specifier|const
name|char
modifier|*
name|msgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebad_string
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffebad_inhibit
parameter_list|()
value|(ffebad_is_inhibited_)
end_define

begin_define
define|#
directive|define
name|ffebad_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_set_inhibit
parameter_list|(
name|f
parameter_list|)
value|(ffebad_is_inhibited_ = (f))
end_define

begin_define
define|#
directive|define
name|ffebad_start
parameter_list|(
name|e
parameter_list|)
value|ffebad_start_ (FALSE, (e), FFEBAD_severity, NULL)
end_define

begin_define
define|#
directive|define
name|ffebad_start_lex
parameter_list|(
name|e
parameter_list|)
value|ffebad_start_ (TRUE, (e), FFEBAD_severity, NULL)
end_define

begin_define
define|#
directive|define
name|ffebad_start_msg
parameter_list|(
name|msgid
parameter_list|,
name|s
parameter_list|)
value|ffebad_start_ (FALSE, FFEBAD, (s), (msgid))
end_define

begin_define
define|#
directive|define
name|ffebad_start_msg_lex
parameter_list|(
name|msgid
parameter_list|,
name|s
parameter_list|)
value|ffebad_start_ (TRUE, FFEBAD, (s), (msgid))
end_define

begin_define
define|#
directive|define
name|ffebad_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebad_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_BAD_H */
end_comment

end_unit

