begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stv.h -- Private #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       stv.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STV_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STV_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFESTV_accessstateNONE
block|,
comment|/* Haven't seen PUBLIC or PRIVATE yet. */
name|FFESTV_accessstatePUBLIC
block|,
comment|/* Seen PUBLIC stmt w/o args. */
name|FFESTV_accessstatePRIVATE
block|,
comment|/* Seen PRIVATE stmt w/o args. */
name|FFESTV_accessstateANY
block|,
comment|/* Conflict seen and reported, so stop 				   whining. */
name|FFESTV_accessstate
block|}
name|ffestvAccessstate
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Format specifier in an I/O statement. */
name|FFESTV_formatNONE
block|,
comment|/* None. */
name|FFESTV_formatLABEL
block|,
comment|/* Label (normal format). */
name|FFESTV_formatCHAREXPR
block|,
comment|/* Character expression (normal format). */
name|FFESTV_formatASTERISK
block|,
comment|/* Asterisk (list-directed). */
name|FFESTV_formatINTEXPR
block|,
comment|/* Integer expression (assigned label). */
name|FFESTV_formatNAMELIST
block|,
comment|/* Namelist (namelist-directed). */
name|FFESTV_format
block|}
name|ffestvFormat
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFESTV_savestateNONE
block|,
comment|/* Haven't seen SAVE stmt or attribute yet. */
name|FFESTV_savestateSPECIFIC
block|,
comment|/* Seen SAVE stmt w/args or SAVE attr. */
name|FFESTV_savestateALL
block|,
comment|/* Seen SAVE stmt w/o args. */
name|FFESTV_savestateANY
block|,
comment|/* Conflict seen and reported, so stop 				   whining. */
name|FFESTV_savestate
block|}
name|ffestvSavestate
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFESTV_stateNIL
block|,
comment|/* Initial state, and after end of outer prog 				   unit. */
name|FFESTV_statePROGRAM0
block|,
comment|/* After PROGRAM. */
name|FFESTV_statePROGRAM1
block|,
comment|/* Before first non-USE statement. */
name|FFESTV_statePROGRAM2
block|,
comment|/* After IMPLICIT NONE. */
name|FFESTV_statePROGRAM3
block|,
comment|/* After IMPLICIT, PARAMETER, FORMAT. */
name|FFESTV_statePROGRAM4
block|,
comment|/* Before executable stmt or CONTAINS. */
name|FFESTV_statePROGRAM5
block|,
comment|/* After CONTAINS. */
name|FFESTV_stateSUBROUTINE0
block|,
comment|/* After SUBROUTINE. */
name|FFESTV_stateSUBROUTINE1
block|,
comment|/* Before first non-USE statement. */
name|FFESTV_stateSUBROUTINE2
block|,
comment|/* After IMPLICIT NONE. */
name|FFESTV_stateSUBROUTINE3
block|,
comment|/* After IMPLICIT, PARAMETER, FORMAT, ENTRY. */
name|FFESTV_stateSUBROUTINE4
block|,
comment|/* Before executable stmt or CONTAINS. */
name|FFESTV_stateSUBROUTINE5
block|,
comment|/* After CONTAINS. */
name|FFESTV_stateFUNCTION0
block|,
comment|/* After FUNCTION. */
name|FFESTV_stateFUNCTION1
block|,
comment|/* Before first non-USE statement. */
name|FFESTV_stateFUNCTION2
block|,
comment|/* After IMPLICIT NONE. */
name|FFESTV_stateFUNCTION3
block|,
comment|/* After IMPLICIT, PARAMETER, FORMAT, ENTRY. */
name|FFESTV_stateFUNCTION4
block|,
comment|/* Before executable stmt or CONTAINS. */
name|FFESTV_stateFUNCTION5
block|,
comment|/* After CONTAINS. */
name|FFESTV_stateMODULE0
block|,
comment|/* After MODULE. */
name|FFESTV_stateMODULE1
block|,
comment|/* Before first non-USE statement. */
name|FFESTV_stateMODULE2
block|,
comment|/* After IMPLICIT NONE. */
name|FFESTV_stateMODULE3
block|,
comment|/* After IMPLICIT, PARAMETER, FORMAT, ENTRY. */
name|FFESTV_stateMODULE4
block|,
comment|/* Before executable stmt or CONTAINS. */
name|FFESTV_stateMODULE5
block|,
comment|/* After CONTAINS. */
name|FFESTV_stateBLOCKDATA0
block|,
comment|/* After BLOCKDATA. */
name|FFESTV_stateBLOCKDATA1
block|,
comment|/* Before first non-USE statement. */
name|FFESTV_stateBLOCKDATA2
block|,
comment|/* After IMPLICIT NONE. */
name|FFESTV_stateBLOCKDATA3
block|,
comment|/* After IMPLICIT, PARAMETER, FORMAT, ENTRY. */
name|FFESTV_stateBLOCKDATA4
block|,
comment|/* Before executable stmt or CONTAINS. */
name|FFESTV_stateBLOCKDATA5
block|,
comment|/* After CONTAINS. */
name|FFESTV_stateUSE
block|,
comment|/* Before first USE thru last USE. */
name|FFESTV_stateTYPE
block|,
comment|/* After TYPE thru END TYPE. */
name|FFESTV_stateINTERFACE0
block|,
comment|/* After INTERFACE thru MODULE PROCEDURE. */
name|FFESTV_stateINTERFACE1
block|,
comment|/* After MODULE PROCEDURE thru END INTERFACE. */
name|FFESTV_stateSTRUCTURE
block|,
comment|/* After STRUCTURE thru END STRUCTURE. */
name|FFESTV_stateUNION
block|,
comment|/* After UNION thru END UNION. */
name|FFESTV_stateMAP
block|,
comment|/* After MAP thru END MAP. */
name|FFESTV_stateWHERETHEN
block|,
comment|/* After WHERE-construct thru END WHERE. */
name|FFESTV_stateWHERE
block|,
comment|/* After WHERE-stmt thru next stmt. */
name|FFESTV_stateIFTHEN
block|,
comment|/* After IF THEN thru END IF. */
name|FFESTV_stateIF
block|,
comment|/* After IF thru next stmt. */
name|FFESTV_stateDO
block|,
comment|/* After DO thru END DO or terminating label. */
name|FFESTV_stateSELECT0
block|,
comment|/* After SELECT to before first CASE. */
name|FFESTV_stateSELECT1
block|,
comment|/* First CASE in SELECT thru END SELECT. */
name|FFESTV_state
block|}
name|ffestvState
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Unit specifier. */
name|FFESTV_unitNONE
block|,
comment|/* None. */
name|FFESTV_unitINTEXPR
block|,
comment|/* Integer expression (external file unit). */
name|FFESTV_unitASTERISK
block|,
comment|/* Default unit. */
name|FFESTV_unitCHAREXPR
block|,
comment|/* Character expression (internal file unit). */
name|FFESTV_unit
block|}
name|ffestvUnit
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"lab.h"
end_include

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
name|ffestvSavestate
name|ffestv_save_state_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffewhereLine
name|ffestv_save_line_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffewhereColumn
name|ffestv_save_col_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffestvAccessstate
name|ffestv_access_state_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffewhereLine
name|ffestv_access_line_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffewhereColumn
name|ffestv_access_col_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffelabNumber
name|ffestv_num_label_defines_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestv_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestv_terminate_4
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
comment|/* ! GCC_F_STV_H */
end_comment

end_unit

