begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Emacs VMS directory definition file.    Copyright (C) 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Files-11 Ver. 2 directory structure (VMS V4.x - long names)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIR$K_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|DIR$C_FID
value|0
end_define

begin_define
define|#
directive|define
name|DIR$C_LINKNAME
value|1
end_define

begin_define
define|#
directive|define
name|DIR$K_LENGTH
value|6
end_define

begin_define
define|#
directive|define
name|DIR$C_LENGTH
value|6
end_define

begin_define
define|#
directive|define
name|DIR$S_DIRDEF
value|6
end_define

begin_define
define|#
directive|define
name|DIR$W_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|DIR$W_VERLIMIT
value|2
end_define

begin_define
define|#
directive|define
name|DIR$B_FLAGS
value|4
end_define

begin_define
define|#
directive|define
name|DIR$S_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|DIR$V_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|DIR$V_NEXTREC
value|6
end_define

begin_define
define|#
directive|define
name|DIR$V_PREVREC
value|7
end_define

begin_define
define|#
directive|define
name|DIR$B_NAMECOUNT
value|5
end_define

begin_define
define|#
directive|define
name|DIR$S_NAME
value|80
end_define

begin_define
define|#
directive|define
name|DIR$T_NAME
value|6
end_define

begin_define
define|#
directive|define
name|DIR$K_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|DIR$C_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|DIR$S_DIRDEF1
value|8
end_define

begin_define
define|#
directive|define
name|DIR$W_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|DIR$S_FID
value|6
end_define

begin_define
define|#
directive|define
name|DIR$W_FID
value|2
end_define

begin_define
define|#
directive|define
name|DIR$W_FID_NUM
value|2
end_define

begin_define
define|#
directive|define
name|DIR$W_FID_SEQ
value|4
end_define

begin_define
define|#
directive|define
name|DIR$W_FID_RVN
value|6
end_define

begin_define
define|#
directive|define
name|DIR$B_FID_RVN
value|6
end_define

begin_define
define|#
directive|define
name|DIR$B_FID_NMX
value|7
end_define

begin_define
define|#
directive|define
name|DIR$S_DIRDEF2
value|1
end_define

begin_define
define|#
directive|define
name|DIR$T_LINKNAME
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|dir$_name
block|{
comment|/*  short dir$w_size;		/* if you read with RMS, it eats this... */
name|short
name|dir$w_verlimit
decl_stmt|;
comment|/* maximum number of versions */
union|union
block|{
name|unsigned
name|char
name|dir_b_flags
decl_stmt|;
define|#
directive|define
name|dir$b_flags
value|dir__b_flags.dir_b_flags
struct|struct
block|{
name|unsigned
name|char
name|dir_v_type
range|:
name|DIR$S_TYPE
decl_stmt|;
define|#
directive|define
name|dir$v_type
value|dir__b_flags.dir___b_flags.dir_v_type
name|unsigned
name|char
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|dir_v_nextrec
range|:
literal|1
decl_stmt|;
define|#
directive|define
name|dir$v_nextrec
value|dir__b_flags.dir___b_flags.dir_v_nextrec
name|unsigned
name|char
name|dir_v_prevrec
range|:
literal|1
decl_stmt|;
define|#
directive|define
name|dir$v_prevrec
value|dir__b_flags.dir___b_flags.dir_v_prevrec
block|}
name|dir___b_flags
struct|;
block|}
name|dir__b_flags
union|;
name|unsigned
name|char
name|dir$b_namecount
decl_stmt|;
name|char
name|dir$t_name
index|[]
decl_stmt|;
block|}
name|dir$_dirdef
typedef|;
end_typedef

begin_comment
comment|/* only the fixed first part */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dir$_version
block|{
name|short
name|dir$w_version
decl_stmt|;
name|short
name|dir$w_fid_num
decl_stmt|;
name|short
name|dir$w_fid_seq
decl_stmt|;
union|union
block|{
name|short
name|dir_w_fid_rvn
decl_stmt|;
define|#
directive|define
name|dir$w_fid_rvn
value|dir__w_fid_rvn.dir_w_fid_rvn
struct|struct
block|{
name|char
name|dir_b_fid_rvn
decl_stmt|;
define|#
directive|define
name|dir$b_fid_rvn
value|dir__w_fid_rvn.dir___w_fid_rvn.dir_b_fid_rvn
name|char
name|dir_b_fid_nmx
decl_stmt|;
define|#
directive|define
name|dir$b_fid_nmx
value|dir__w_fid_rvn.dir___w_fid_rvn.dir_b_fid_nmx
block|}
name|dir___w_fid_rvn
struct|;
block|}
name|dir__w_fid_rvn
union|;
block|}
name|dir$_dirdef1
typedef|;
end_typedef

begin_comment
comment|/* one for each version of the file */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dir$_linkname
block|{
name|char
name|dir$t_linkname
index|[]
decl_stmt|;
block|}
name|dir$_dirdef2
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

