begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* info.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       info.c     Modifications:       30-Aug-90	 JCB  2.0 	 Extensive rewrite for new cleaner approach. */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_INFO_H
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
name|FFEINFO_BASICTYPE
parameter_list|(
name|KWD
parameter_list|,
name|LNAM
parameter_list|,
name|SNAM
parameter_list|)
value|KWD,
include|#
directive|include
file|"info-b.def"
undef|#
directive|undef
name|FFEINFO_BASICTYPE
name|FFEINFO_basictype
block|}
name|ffeinfoBasictype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* If these kindtypes aren't in size order, 				   change _kindtype_max. */
name|FFEINFO_kindtypeNONE
block|,
name|FFEINFO_kindtypeINTEGER1
block|,
name|FFEINFO_kindtypeINTEGER2
block|,
name|FFEINFO_kindtypeINTEGER3
block|,
name|FFEINFO_kindtypeINTEGER4
block|,
name|FFEINFO_kindtypeINTEGER5
block|,
name|FFEINFO_kindtypeINTEGER6
block|,
name|FFEINFO_kindtypeINTEGER7
block|,
name|FFEINFO_kindtypeINTEGER8
block|,
name|FFEINFO_kindtypeLOGICAL1
init|=
literal|1
block|,
comment|/* Ok to omit, but ok to overlap. */
name|FFEINFO_kindtypeLOGICAL2
block|,
name|FFEINFO_kindtypeLOGICAL3
block|,
name|FFEINFO_kindtypeLOGICAL4
block|,
name|FFEINFO_kindtypeLOGICAL5
block|,
name|FFEINFO_kindtypeLOGICAL6
block|,
name|FFEINFO_kindtypeLOGICAL7
block|,
name|FFEINFO_kindtypeLOGICAL8
block|,
name|FFEINFO_kindtypeREAL1
init|=
literal|1
block|,
comment|/* Ok to omit, but ok to overlap. */
name|FFEINFO_kindtypeREAL2
block|,
name|FFEINFO_kindtypeREAL3
block|,
name|FFEINFO_kindtypeREAL4
block|,
name|FFEINFO_kindtypeREAL5
block|,
name|FFEINFO_kindtypeREAL6
block|,
name|FFEINFO_kindtypeREAL7
block|,
name|FFEINFO_kindtypeREAL8
block|,
name|FFEINFO_kindtypeCHARACTER1
init|=
literal|1
block|,
comment|/* Ok to omit, but ok to overlap. */
name|FFEINFO_kindtypeCHARACTER2
block|,
name|FFEINFO_kindtypeCHARACTER3
block|,
name|FFEINFO_kindtypeCHARACTER4
block|,
name|FFEINFO_kindtypeCHARACTER5
block|,
name|FFEINFO_kindtypeCHARACTER6
block|,
name|FFEINFO_kindtypeCHARACTER7
block|,
name|FFEINFO_kindtypeCHARACTER8
block|,
name|FFEINFO_kindtypeANY
block|,
name|FFEINFO_kindtype
block|}
name|ffeinfoKindtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|FFEINFO_KIND
parameter_list|(
name|KWD
parameter_list|,
name|LNAM
parameter_list|,
name|SNAM
parameter_list|)
value|KWD,
include|#
directive|include
file|"info-k.def"
undef|#
directive|undef
name|FFEINFO_KIND
name|FFEINFO_kind
block|}
name|ffeinfoKind
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|FFEINFO_WHERE
parameter_list|(
name|KWD
parameter_list|,
name|LNAM
parameter_list|,
name|SNAM
parameter_list|)
value|KWD,
include|#
directive|include
file|"info-w.def"
undef|#
directive|undef
name|FFEINFO_WHERE
name|FFEINFO_where
block|}
name|ffeinfoWhere
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffeinfo_
name|ffeinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|ffeinfoRank
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"type.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffeinfo_
block|{
name|ffeinfoBasictype
name|basictype
decl_stmt|;
name|ffeinfoKindtype
name|kindtype
decl_stmt|;
name|ffeinfoRank
name|rank
decl_stmt|;
name|ffeinfoKind
name|kind
decl_stmt|;
name|ffeinfoWhere
name|where
decl_stmt|;
name|ffetargetCharacterSize
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|ffeinfoBasictype
name|ffeinfo_basictype_combine
parameter_list|(
name|ffeinfoBasictype
name|l
parameter_list|,
name|ffeinfoBasictype
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffeinfo_basictype_string
parameter_list|(
name|ffeinfoBasictype
name|basictype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeinfo_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffeinfo_kind_message
parameter_list|(
name|ffeinfoKind
name|kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffeinfo_kind_string
parameter_list|(
name|ffeinfoKind
name|kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfoKindtype
name|ffeinfo_kindtype_max
parameter_list|(
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|k1
parameter_list|,
name|ffeinfoKindtype
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffeinfo_kindtype_string
parameter_list|(
name|ffeinfoKindtype
name|kind_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffeinfo_where_string
parameter_list|(
name|ffeinfoWhere
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfo
name|ffeinfo_new
parameter_list|(
name|ffeinfoBasictype
name|basictype
parameter_list|,
name|ffeinfoKindtype
name|kindtype
parameter_list|,
name|ffeinfoRank
name|rank
parameter_list|,
name|ffeinfoKind
name|kind
parameter_list|,
name|ffeinfoWhere
name|where
parameter_list|,
name|ffetargetCharacterSize
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeinfo_set_type
parameter_list|(
name|ffeinfoBasictype
name|basictype
parameter_list|,
name|ffeinfoKindtype
name|kindtype
parameter_list|,
name|ffetype
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffetype
name|ffeinfo_type
parameter_list|(
name|ffeinfoBasictype
name|basictype
parameter_list|,
name|ffeinfoKindtype
name|kindtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffeinfo_basictype
parameter_list|(
name|i
parameter_list|)
value|(i.basictype)
end_define

begin_define
define|#
directive|define
name|ffeinfo_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_kind
parameter_list|(
name|i
parameter_list|)
value|(i.kind)
end_define

begin_define
define|#
directive|define
name|ffeinfo_kindtype
parameter_list|(
name|i
parameter_list|)
value|(i.kindtype)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ffeinfo_new
parameter_list|(
name|bt
parameter_list|,
name|kt
parameter_list|,
name|r
parameter_list|,
name|k
parameter_list|,
name|w
parameter_list|,
name|sz
parameter_list|)
define|\
value|((ffeinfo) {(bt), (kt), (r), (k), (w), (sz)})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffeinfo_new_any
parameter_list|()
define|\
value|ffeinfo_new (FFEINFO_basictypeANY, FFEINFO_kindtypeANY, 0,		      \ 	       FFEINFO_kindANY, FFEINFO_whereANY,			      \ 	       FFETARGET_charactersizeNONE)
end_define

begin_define
define|#
directive|define
name|ffeinfo_new_null
parameter_list|()
define|\
value|ffeinfo_new (FFEINFO_basictypeNONE, FFEINFO_kindtypeNONE, 0,		      \ 	       FFEINFO_kindNONE, FFEINFO_whereNONE,			      \ 	       FFETARGET_charactersizeNONE)
end_define

begin_define
define|#
directive|define
name|ffeinfo_rank
parameter_list|(
name|i
parameter_list|)
value|(i.rank)
end_define

begin_define
define|#
directive|define
name|ffeinfo_size
parameter_list|(
name|i
parameter_list|)
value|(i.size)
end_define

begin_define
define|#
directive|define
name|ffeinfo_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeinfo_use
parameter_list|(
name|i
parameter_list|)
value|i
end_define

begin_define
define|#
directive|define
name|ffeinfo_where
parameter_list|(
name|i
parameter_list|)
value|(i.where)
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeINTEGERDEFAULT
value|FFEINFO_kindtypeINTEGER1
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeLOGICALDEFAULT
value|FFEINFO_kindtypeLOGICAL1
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeREALDEFAULT
value|FFEINFO_kindtypeREAL1
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeREALDOUBLE
value|FFEINFO_kindtypeREAL2
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeREALQUAD
value|FFEINFO_kindtypeREAL3
end_define

begin_define
define|#
directive|define
name|FFEINFO_kindtypeCHARACTERDEFAULT
value|FFEINFO_kindtypeCHARACTER1
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_INFO_H */
end_comment

end_unit

