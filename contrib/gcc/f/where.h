begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* where.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       where.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_WHERE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_WHERE_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_define
define|#
directive|define
name|FFEWHERE_columnMAX
value|UCHAR_MAX
end_define

begin_define
define|#
directive|define
name|FFEWHERE_columnUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|FFEWHERE_indexMAX
value|36
end_define

begin_define
define|#
directive|define
name|FFEWHERE_indexUNKNOWN
value|UCHAR_MAX
end_define

begin_define
define|#
directive|define
name|FFEWHERE_lineMAX
value|ULONG_MAX
end_define

begin_define
define|#
directive|define
name|FFEWHERE_lineUNKNOWN
value|(&ffewhere_unknown_line_)
end_define

begin_define
define|#
directive|define
name|FFEWHERE_filenameUNKNOWN
value|("(input file)")
end_define

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffewhereColumnNumber
typedef|;
end_typedef

begin_comment
comment|/* Change FFEWHERE_columnMAX 						   too. */
end_comment

begin_define
define|#
directive|define
name|ffewhereColumnNumber_f
value|""
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffewhereColumn
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffewhere_file_
modifier|*
name|ffewhereFile
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ffewhereLength_
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffewhereLength_f_
value|""
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ffewhereLineNumber
typedef|;
end_typedef

begin_comment
comment|/* Change FFEWHERE_lineMAX 						   too. */
end_comment

begin_define
define|#
directive|define
name|ffewhereLineNumber_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|struct
name|_ffewhere_line_
modifier|*
name|ffewhereLine
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffewhereIndex
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffewhereIndex_f
value|""
end_define

begin_typedef
typedef|typedef
name|ffewhereIndex
name|ffewhereTrack
index|[
name|FFEWHERE_indexMAX
operator|*
literal|2
operator|-
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ffewhereUses_
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffewhereUses_f_
value|""
end_define

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"glimits.h"
end_include

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffewhere_file_
block|{
name|size_t
name|length
decl_stmt|;
name|char
name|text
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffewhere_line_
block|{
name|ffewhereLine
name|next
decl_stmt|;
name|ffewhereLine
name|previous
decl_stmt|;
name|ffewhereLineNumber
name|line_num
decl_stmt|;
name|ffewhereUses_
name|uses
decl_stmt|;
name|ffewhereLength_
name|length
decl_stmt|;
name|char
name|content
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_ffewhere_line_
name|ffewhere_unknown_line_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffewhere_file_kill
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereFile
name|ffewhere_file_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_file_set
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|,
name|bool
name|have_num
parameter_list|,
name|ffewhereLineNumber
name|ln
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ffewhere_line_content
parameter_list|(
name|ffewhereLine
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereFile
name|ffewhere_line_file
parameter_list|(
name|ffewhereLine
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereLineNumber
name|ffewhere_line_filelinenum
parameter_list|(
name|ffewhereLine
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_line_kill
parameter_list|(
name|ffewhereLine
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereLine
name|ffewhere_line_new
parameter_list|(
name|ffewhereLineNumber
name|ln
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereLine
name|ffewhere_line_use
parameter_list|(
name|ffewhereLine
name|wl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_set_from_track
parameter_list|(
name|ffewhereLine
modifier|*
name|wol
parameter_list|,
name|ffewhereColumn
modifier|*
name|woc
parameter_list|,
name|ffewhereLine
name|wrl
parameter_list|,
name|ffewhereColumn
name|wrc
parameter_list|,
name|ffewhereTrack
name|wt
parameter_list|,
name|ffewhereIndex
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_track
parameter_list|(
name|ffewhereLine
modifier|*
name|wl
parameter_list|,
name|ffewhereColumn
modifier|*
name|wc
parameter_list|,
name|ffewhereTrack
name|wt
parameter_list|,
name|ffewhereIndex
name|i
parameter_list|,
name|ffewhereLineNumber
name|ln
parameter_list|,
name|ffewhereColumnNumber
name|cn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_track_clear
parameter_list|(
name|ffewhereTrack
name|wt
parameter_list|,
name|ffewhereIndex
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_track_copy
parameter_list|(
name|ffewhereTrack
name|dwt
parameter_list|,
name|ffewhereTrack
name|swt
parameter_list|,
name|ffewhereIndex
name|start
parameter_list|,
name|ffewhereIndex
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffewhere_track_kill
parameter_list|(
name|ffewhereLine
name|wrl
parameter_list|,
name|ffewhereColumn
name|wrc
parameter_list|,
name|ffewhereTrack
name|wt
parameter_list|,
name|ffewhereIndex
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffewhere_column_is_unknown
parameter_list|(
name|c
parameter_list|)
value|(c == FFEWHERE_columnUNKNOWN)
end_define

begin_define
define|#
directive|define
name|ffewhere_column_kill
parameter_list|(
name|c
parameter_list|)
value|((void) 0)
end_define

begin_define
define|#
directive|define
name|ffewhere_column_new
parameter_list|(
name|cn
parameter_list|)
value|(cn)
end_define

begin_define
define|#
directive|define
name|ffewhere_column_number
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|ffewhere_column_unknown
parameter_list|()
value|(FFEWHERE_columnUNKNOWN)
end_define

begin_define
define|#
directive|define
name|ffewhere_column_use
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|ffewhere_file_name
parameter_list|(
name|f
parameter_list|)
value|((f)->text)
end_define

begin_define
define|#
directive|define
name|ffewhere_file_namelen
parameter_list|(
name|f
parameter_list|)
value|((f)->length)
end_define

begin_define
define|#
directive|define
name|ffewhere_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_line_filename
parameter_list|(
name|l
parameter_list|)
value|(ffewhere_line_file(l)->text)
end_define

begin_define
define|#
directive|define
name|ffewhere_line_is_unknown
parameter_list|(
name|l
parameter_list|)
value|(l == FFEWHERE_lineUNKNOWN)
end_define

begin_define
define|#
directive|define
name|ffewhere_line_number
parameter_list|(
name|l
parameter_list|)
value|((l)->line_num)
end_define

begin_define
define|#
directive|define
name|ffewhere_line_unknown
parameter_list|()
value|(FFEWHERE_lineUNKNOWN)
end_define

begin_define
define|#
directive|define
name|ffewhere_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffewhere_terminate_4
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
comment|/* ! GCC_F_EHERE_H */
end_comment

end_unit

