begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* btoken.h */
end_comment

begin_comment
comment|/* Definitions for Level 2 binary tokens */
end_comment

begin_comment
comment|/* Binary token types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|bt_seq
init|=
literal|128
block|,
name|bt_seq_IEEE_msb
init|=
literal|128
block|,
comment|/* binary object sequence, */
comment|/* IEEE floats, big-endian */
name|bt_seq_IEEE_lsb
init|=
literal|129
block|,
comment|/* ditto, little-endian */
name|bt_seq_native_msb
init|=
literal|130
block|,
comment|/* ditto, native floats, big-endian */
name|bt_seq_native_lsb
init|=
literal|131
block|,
comment|/* ditto, little-endian */
name|bt_int32_msb
init|=
literal|132
block|,
name|bt_int32_lsb
init|=
literal|133
block|,
name|bt_int16_msb
init|=
literal|134
block|,
name|bt_int16_lsb
init|=
literal|135
block|,
name|bt_int8
init|=
literal|136
block|,
name|bt_fixed
init|=
literal|137
block|,
name|bt_float_IEEE_msb
init|=
literal|138
block|,
name|bt_float_IEEE_lsb
init|=
literal|139
block|,
name|bt_float_native
init|=
literal|140
block|,
name|bt_boolean
init|=
literal|141
block|,
name|bt_string_256
init|=
literal|142
block|,
name|bt_string_64k_msb
init|=
literal|143
block|,
name|bt_string_64k_lsb
init|=
literal|144
block|,
name|bt_litname_system
init|=
literal|145
block|,
name|bt_execname_system
init|=
literal|146
block|,
name|bt_litname_user
init|=
literal|147
block|,
name|bt_execname_user
init|=
literal|148
block|,
name|bt_num_array
init|=
literal|149
block|}
name|bt_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bt_type_min
value|128
end_define

begin_define
define|#
directive|define
name|bt_type_max
value|159
end_define

end_unit

