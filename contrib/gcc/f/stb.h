begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stb.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       stb.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_stb
end_ifndef

begin_define
define|#
directive|define
name|_H_f_stb
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bad.h"
end_include

begin_include
include|#
directive|include
file|"expr.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"stp.h"
end_include

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffestb_args_
block|{
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "ENTRY/FUNCTION/SUBROUTINE". */
name|bool
name|is_subr
decl_stmt|;
comment|/* TRUE if SUBROUTINE or if ENTRY within 				   SUBROUTINE. */
block|}
name|dummy
struct|;
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of 				   "BACKSPACE/ENDFILE/REWIND/UNLOCK". */
block|}
name|beru
struct|;
struct|struct
block|{
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of keyword including "END". */
name|ffestrSecond
name|second
decl_stmt|;
comment|/* Second keyword. */
block|}
name|endxyz
struct|;
struct|struct
block|{
name|ffestrSecond
name|second
decl_stmt|;
comment|/* Second keyword. */
block|}
name|elsexyz
struct|;
struct|struct
block|{
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "STOP/PAUSE". */
block|}
name|halt
struct|;
if|#
directive|if
name|FFESTR_F90
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "ALLOCATE/DEALLOCATE". */
name|ffeexprContext
name|ctx
decl_stmt|;
comment|/* Either ALLOCATE or DEALLOCATE. */
block|}
name|heap
struct|;
endif|#
directive|endif
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of 				   "EXTERNAL/INTENT/INTRINSIC/OPTIONAL/PUBLIC/ 				   PRIVATE". */
block|}
name|varlist
struct|;
if|#
directive|if
name|FFESTR_VXT
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "ENCODE/DECODE". */
block|}
name|vxtcode
struct|;
endif|#
directive|endif
if|#
directive|if
name|FFESTR_F90
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "ALLOCATABLE/POINTER/TARGET". */
block|}
name|dimlist
struct|;
endif|#
directive|endif
struct|struct
block|{
specifier|const
name|char
modifier|*
name|badname
decl_stmt|;
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of "DIMENSION/VIRTUAL". */
block|}
name|R524
struct|;
struct|struct
block|{
name|ffeTokenLength
name|len
decl_stmt|;
comment|/* Length of first keyword. */
name|ffestpType
name|type
decl_stmt|;
comment|/* Type of declaration. */
block|}
name|decl
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_ffestb_args_
name|ffestb_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|ffelexHandler
name|ffestb_beru
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_block
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_blockdata
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_decl_chartype
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_construct
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_decl_dbltype
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_decl_double
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_dimlist
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_do
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_dowhile
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_dummy
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_else
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_elsexyz
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_end
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_endxyz
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_decl_gentype
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_goto
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_halt
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_heap
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_if
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_let
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_module
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_decl_recursive
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_type
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_decl_typetype
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_varlist
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_vxtcode
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_where
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HARD_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_R423B
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_R522
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R524
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R528
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R537
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_decl_R539
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R542
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R544
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R547
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_R624
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_R809
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R810
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R834
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R835
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R838
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R840
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R841
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R904
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R907
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R909
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R910
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R911
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R923
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R1001
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R1102
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_R1107
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_R1202
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_R1212
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_R1227
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_F90
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_R1228
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_R1229
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_S3P4
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_V003
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V009
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V012
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_V014
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_V016
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V018
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V019
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_V020
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFESTR_VXT
end_if

begin_function_decl
name|ffelexHandler
name|ffestb_V021
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V025
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffestb_V026
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffelexHandler
name|ffestb_V027
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestb_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestb_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

