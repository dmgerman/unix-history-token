begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* ccfont.h */
end_comment

begin_comment
comment|/* Header for fonts compiled into C. */
end_comment

begin_comment
comment|/* Define type-specific refs for initializing arrays. */
end_comment

begin_define
define|#
directive|define
name|ref_
parameter_list|(
name|t
parameter_list|)
value|struct { struct tas_s tas; t value; }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|len
decl_stmt|;
name|char
name|_ds
modifier|*
name|str
decl_stmt|;
block|}
name|charray
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|byte
name|encx
decl_stmt|,
name|charx
decl_stmt|;
block|}
name|charindex
typedef|;
end_typedef

begin_define
define|#
directive|define
name|array_v
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|,
name|ea
parameter_list|)
define|\
value|{ {(t_array<<r_type_shift)+(ea), n}, (ref *)(p) }
end_define

begin_define
define|#
directive|define
name|boolean_v
parameter_list|(
name|b
parameter_list|)
value|{ {t_boolean<<r_type_shift}, (ushort)(b) }
end_define

begin_define
define|#
directive|define
name|name_v
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
define|\
value|{ {t_name<<r_type_shift, n}, s }
end_define

begin_define
define|#
directive|define
name|null_v
parameter_list|()
value|{ {t_null<<r_type_shift} }
end_define

begin_define
define|#
directive|define
name|real_v
parameter_list|(
name|v
parameter_list|)
value|{ {t_real<<r_type_shift}, (float)(v) }
end_define

begin_define
define|#
directive|define
name|integer_v
parameter_list|(
name|i
parameter_list|)
value|{ {t_integer<<r_type_shift}, (long)(i) }
end_define

begin_define
define|#
directive|define
name|string_v
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
define|\
value|{ {(t_string<<r_type_shift)+a_read+a_execute, n}, s }
end_define

begin_comment
comment|/* Define the combined access masks */
end_comment

begin_define
define|#
directive|define
name|a_readonly
value|(a_read + a_execute)
end_define

begin_comment
comment|/* Support routines in iccfont.c */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|charindex
name|_ds
modifier|*
name|enc_keys
decl_stmt|;
comment|/* keys from encoding vectors */
name|uint
name|num_enc_keys
decl_stmt|;
specifier|const
name|char
name|_ds
modifier|*
name|_ds
modifier|*
name|str_keys
decl_stmt|;
comment|/* string keys */
name|uint
name|num_str_keys
decl_stmt|;
name|uint
name|extra_slots
decl_stmt|;
comment|/* (need 1 extra for fonts) */
name|uint
name|dict_attrs
decl_stmt|;
comment|/* protection for dictionary */
name|uint
name|value_attrs
decl_stmt|;
comment|/* protection for values */
comment|/* (only used for string dicts) */
block|}
name|cfont_dict_keys
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|cfont_ref_dict_create
argument_list|(
name|P3
argument_list|(
argument|ref *
argument_list|,
argument|const cfont_dict_keys _ds *
argument_list|,
argument|const ref _ds * _ds *
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfont_string_dict_create
argument_list|(
name|P3
argument_list|(
argument|ref *
argument_list|,
argument|const cfont_dict_keys _ds *
argument_list|,
argument|const charray _ds *
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfont_num_dict_create
argument_list|(
name|P3
argument_list|(
argument|ref *
argument_list|,
argument|const cfont_dict_keys _ds *
argument_list|,
argument|const float _ds *
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cfont_name_array_create
argument_list|(
name|P3
argument_list|(
argument|ref *
argument_list|,
argument|const char _ds * _ds *
argument_list|,
argument|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

