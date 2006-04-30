begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for the data structures and codes used in VMS debugging.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_VMSDBG_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_VMSDBG_H
value|1
end_define

begin_comment
comment|/*  We define types and constants used in VMS Debug output.  Note that the     structs only approximate the output that is written.  We write the output     explicitly, field by field.  This output would only agree with the     structs in this file if no padding were done.  The sizes after each     struct are the size actually written, which is usually smaller than the     size of the struct.  */
end_comment

begin_comment
comment|/* Header type codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_DST_TYPE
block|{
name|DST_K_SOURCE
init|=
literal|155
block|,
name|DST_K_PROLOG
init|=
literal|162
block|,
name|DST_K_BLKBEG
init|=
literal|176
block|,
name|DST_K_BLKEND
init|=
literal|177
block|,
name|DST_K_LINE_NUM
init|=
literal|185
block|,
name|DST_K_MODBEG
init|=
literal|188
block|,
name|DST_K_MODEND
init|=
literal|189
block|,
name|DST_K_RTNBEG
init|=
literal|190
block|,
name|DST_K_RTNEND
init|=
literal|191
block|}
name|DST_DTYPE
typedef|;
end_typedef

begin_comment
comment|/* Header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_HEADER
block|{
union|union
block|{
name|unsigned
name|short
name|int
name|dst_w_length
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_x_length
decl_stmt|;
block|}
name|dst__header_length
union|;
union|union
block|{
name|ENUM_BITFIELD
argument_list|(
argument|_DST_TYPE
argument_list|)
name|dst_w_type
label|:
literal|16
expr_stmt|;
name|ENUM_BITFIELD
argument_list|(
argument|_DST_TYPE
argument_list|)
name|dst_x_type
label|:
literal|16
expr_stmt|;
block|}
name|dst__header_type
union|;
block|}
name|DST_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_DST_HEADER_SIZE
value|sizeof 4
end_define

begin_comment
comment|/* Language type codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_DST_LANGUAGE
block|{
name|DST_K_FORTRAN
init|=
literal|1
block|,
name|DST_K_C
init|=
literal|7
block|,
name|DST_K_ADA
init|=
literal|9
block|,
name|DST_K_UNKNOWN
init|=
literal|10
block|,
name|DST_K_CXX
init|=
literal|15
block|}
name|DST_LANGUAGE
typedef|;
end_typedef

begin_comment
comment|/* Module header (a module is the result of a single compilation).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_MODULE_BEGIN
block|{
name|DST_HEADER
name|dst_a_modbeg_header
decl_stmt|;
struct|struct
block|{
name|unsigned
name|dst_v_modbeg_hide
range|:
literal|1
decl_stmt|;
name|unsigned
name|dst_v_modbeg_version
range|:
literal|1
decl_stmt|;
name|unsigned
name|dst_v_modbeg_unused
range|:
literal|6
decl_stmt|;
block|}
name|dst_b_modbeg_flags
struct|;
name|unsigned
name|char
name|dst_b_modbeg_unused
decl_stmt|;
name|DST_LANGUAGE
name|dst_l_modbeg_language
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_version_major
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_version_minor
decl_stmt|;
name|unsigned
name|char
name|dst_b_modbeg_name
decl_stmt|;
block|}
name|DST_MODULE_BEGIN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_MODBEG_SIZE
value|15
end_define

begin_comment
comment|/* Module trailer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_MB_TRLR
block|{
name|unsigned
name|char
name|dst_b_compiler
decl_stmt|;
block|}
name|DST_MB_TRLR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_MB_TRLR_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_VERSION_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_VERSION_MINOR
value|13
end_define

begin_typedef
typedef|typedef
struct|struct
name|_DST_MODULE_END
block|{
name|DST_HEADER
name|dst_a_modend_header
decl_stmt|;
block|}
name|DST_MODULE_END
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_MODEND_SIZE
value|sizeof 4
end_define

begin_comment
comment|/* Routine header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_ROUTINE_BEGIN
block|{
name|DST_HEADER
name|dst_a_rtnbeg_header
decl_stmt|;
struct|struct
block|{
name|unsigned
name|dst_v_rtnbeg_unused
range|:
literal|4
decl_stmt|;
name|unsigned
name|dst_v_rtnbeg_unalloc
range|:
literal|1
decl_stmt|;
name|unsigned
name|dst_v_rtnbeg_prototype
range|:
literal|1
decl_stmt|;
name|unsigned
name|dst_v_rtnbeg_inlined
range|:
literal|1
decl_stmt|;
name|unsigned
name|dst_v_rtnbeg_no_call
range|:
literal|1
decl_stmt|;
block|}
name|dst_b_rtnbeg_flags
struct|;
name|int
modifier|*
name|dst_l_rtnbeg_address
decl_stmt|;
name|int
modifier|*
name|dst_l_rtnbeg_pd_address
decl_stmt|;
name|unsigned
name|char
name|dst_b_rtnbeg_name
decl_stmt|;
block|}
name|DST_ROUTINE_BEGIN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_RTNBEG_SIZE
value|14
end_define

begin_comment
comment|/* Routine trailer */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_ROUTINE_END
block|{
name|DST_HEADER
name|dst_a_rtnend_header
decl_stmt|;
name|char
name|dst_b_rtnend_unused
decl_stmt|;
name|unsigned
name|int
name|dst_l_rtnend_size
decl_stmt|;
block|}
name|DST_ROUTINE_END
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_RTNEND_SIZE
value|9
end_define

begin_comment
comment|/* Block header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_BLOCK_BEGIN
block|{
name|DST_HEADER
name|dst_a_blkbeg_header
decl_stmt|;
name|unsigned
name|char
name|dst_b_blkbeg_unused
decl_stmt|;
name|int
modifier|*
name|dst_l_blkbeg_address
decl_stmt|;
name|unsigned
name|char
name|dst_b_blkbeg_name
decl_stmt|;
block|}
name|DST_BLOCK_BEGIN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_BLKBEG_SIZE
value|10
end_define

begin_comment
comment|/* Block trailer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_BLOCK_END
block|{
name|DST_HEADER
name|dst_a_blkend_header
decl_stmt|;
name|unsigned
name|char
name|dst_b_blkend_unused
decl_stmt|;
name|unsigned
name|int
name|dst_l_blkend_size
decl_stmt|;
block|}
name|DST_BLOCK_END
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_BLKEND_SIZE
value|9
end_define

begin_comment
comment|/* Line number header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_LINE_NUM_HEADER
block|{
name|DST_HEADER
name|dst_a_line_num_header
decl_stmt|;
block|}
name|DST_LINE_NUM_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_LINE_NUM_HEADER_SIZE
value|4
end_define

begin_comment
comment|/* PC to Line number correlation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_PCLINE_COMMANDS
block|{
name|char
name|dst_b_pcline_command
decl_stmt|;
union|union
block|{
name|unsigned
name|int
name|dst_l_pcline_unslong
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_pcline_unsword
decl_stmt|;
name|unsigned
name|char
name|dst_b_pcline_unsbyte
decl_stmt|;
block|}
name|dst_a_pcline_access_fields
union|;
block|}
name|DST_PCLINE_COMMANDS
typedef|;
end_typedef

begin_comment
comment|/* PC and Line number correlation codes.  */
end_comment

begin_define
define|#
directive|define
name|DST_K_PCLINE_COMMANDS_SIZE
value|5
end_define

begin_define
define|#
directive|define
name|DST_K_PCLINE_COMMANDS_SIZE_MIN
value|2
end_define

begin_define
define|#
directive|define
name|DST_K_PCLINE_COMMANDS_SIZE_MAX
value|5
end_define

begin_define
define|#
directive|define
name|DST_K_DELTA_PC_LOW
value|-128
end_define

begin_define
define|#
directive|define
name|DST_K_DELTA_PC_HIGH
value|0
end_define

begin_define
define|#
directive|define
name|DST_K_DELTA_PC_W
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_INCR_LINUM
value|2
end_define

begin_define
define|#
directive|define
name|DST_K_INCR_LINUM_W
value|3
end_define

begin_define
define|#
directive|define
name|DST_K_SET_LINUM
value|9
end_define

begin_define
define|#
directive|define
name|DST_K_SET_ABS_PC
value|16
end_define

begin_define
define|#
directive|define
name|DST_K_DELTA_PC_L
value|17
end_define

begin_define
define|#
directive|define
name|DST_K_INCR_LINUM_L
value|18
end_define

begin_define
define|#
directive|define
name|DST_K_SET_LINUM_B
value|19
end_define

begin_define
define|#
directive|define
name|DST_K_SET_LINUM_L
value|20
end_define

begin_comment
comment|/* Source file correlation header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_SOURCE_CORR
block|{
name|DST_HEADER
name|dst_a_source_corr_header
decl_stmt|;
block|}
name|DST_SOURCE_CORR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_SOURCE_CORR_HEADER_SIZE
value|4
end_define

begin_comment
comment|/* Source file correlation codes.  */
end_comment

begin_define
define|#
directive|define
name|DST_K_SRC_DECLFILE
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_SETFILE
value|2
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_SETREC_L
value|3
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_SETREC_W
value|4
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_SETLNUM_L
value|5
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_SETLNUM_W
value|6
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_INCRLNUM_B
value|7
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_DEFLINES_W
value|10
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_DEFLINES_B
value|11
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_FORMFEED
value|16
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_MIN_CMD
value|1
end_define

begin_define
define|#
directive|define
name|DST_K_SRC_MAX_CMD
value|16
end_define

begin_comment
comment|/* Source file header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_SRC_COMMAND
block|{
name|unsigned
name|char
name|dst_b_src_command
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|dst_b_src_df_length
decl_stmt|;
name|unsigned
name|char
name|dst_b_src_df_flags
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_src_df_fileid
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_LONG_LONG
name|long
name|long
name|dst_q_src_df_rms_cdt
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HAVE___INT64
name|__int64
name|dst_q_src_df_rms_cdt
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|unsigned
name|int
name|dst_l_src_df_rms_ebk
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_src_df_rms_ffb
decl_stmt|;
name|unsigned
name|char
name|dst_b_src_df_rms_rfo
decl_stmt|;
name|unsigned
name|char
name|dst_b_src_df_filename
decl_stmt|;
block|}
name|dst_a_src_decl_src
struct|;
name|unsigned
name|int
name|dst_l_src_unslong
decl_stmt|;
name|unsigned
name|short
name|int
name|dst_w_src_unsword
decl_stmt|;
name|unsigned
name|char
name|dst_b_src_unsbyte
decl_stmt|;
block|}
name|dst_a_src_cmd_fields
union|;
block|}
name|DST_SRC_COMMAND
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_SRC_COMMAND_SIZE
value|21
end_define

begin_comment
comment|/* Source file trailer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_SRC_CMDTRLR
block|{
name|unsigned
name|char
name|dst_b_src_df_libmodname
decl_stmt|;
block|}
name|DST_SRC_CMDTRLR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_SRC_CMDTRLR_SIZE
value|1
end_define

begin_comment
comment|/* Prolog header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_DST_PROLOG
block|{
name|DST_HEADER
name|dst_a_prolog_header
decl_stmt|;
name|unsigned
name|int
name|dst_l_prolog_bkpt_addr
decl_stmt|;
block|}
name|DST_PROLOG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DST_K_PROLOG_SIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_VMSDBG_H */
end_comment

end_unit

