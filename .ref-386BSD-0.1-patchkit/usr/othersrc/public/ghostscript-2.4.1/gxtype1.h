begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxtype1.h */
end_comment

begin_comment
comment|/* Private Adobe Type 1 font definitions for GhostScript library */
end_comment

begin_include
include|#
directive|include
file|"gstype1.h"
end_include

begin_comment
comment|/* Define the charstring command set */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|c_undef0
init|=
literal|0
block|,
name|c_hstem
init|=
literal|1
block|,
name|c_undef2
init|=
literal|2
block|,
name|c_vstem
init|=
literal|3
block|,
name|c_vmoveto
init|=
literal|4
block|,
name|c_rlineto
init|=
literal|5
block|,
name|c_hlineto
init|=
literal|6
block|,
name|c_vlineto
init|=
literal|7
block|,
name|c_rrcurveto
init|=
literal|8
block|,
name|c_closepath
init|=
literal|9
block|,
name|c_callsubr
init|=
literal|10
block|,
name|c_return
init|=
literal|11
block|,
name|c_escape
init|=
literal|12
block|,
comment|/* extends the command set */
name|c_hsbw
init|=
literal|13
block|,
name|c_endchar
init|=
literal|14
block|,
name|c_undoc15
init|=
literal|15
block|,
comment|/* Undocumented by Adobe, */
comment|/* but used in some Adobe fonts. */
name|c_undef16
init|=
literal|16
block|,
name|c_undef17
init|=
literal|17
block|,
name|c_undef18
init|=
literal|18
block|,
name|c_undef19
init|=
literal|19
block|,
name|c_undef20
init|=
literal|20
block|,
name|c_rmoveto
init|=
literal|21
block|,
name|c_hmoveto
init|=
literal|22
block|,
name|c_undef23
init|=
literal|23
block|,
name|c_undef24
init|=
literal|24
block|,
name|c_undef25
init|=
literal|25
block|,
name|c_undef26
init|=
literal|26
block|,
name|c_undef27
init|=
literal|27
block|,
name|c_undef28
init|=
literal|28
block|,
name|c_undef29
init|=
literal|29
block|,
name|c_vhcurveto
init|=
literal|30
block|,
name|c_hvcurveto
init|=
literal|31
block|}
name|char_command
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* extended commands */
name|ce_dotsection
init|=
literal|0
block|,
name|ce_vstem3
init|=
literal|1
block|,
name|ce_hstem3
init|=
literal|2
block|,
name|ce_seac
init|=
literal|6
block|,
name|ce_sbw
init|=
literal|7
block|,
name|ce_div
init|=
literal|12
block|,
name|ce_undoc15
init|=
literal|15
block|,
comment|/* Undocumented by Adobe, */
comment|/* but used in some Adobe fonts. */
name|ce_callothersubr
init|=
literal|16
block|,
name|ce_pop
init|=
literal|17
block|,
name|ce_setcurrentpoint
init|=
literal|33
block|}
name|char_extended_command
typedef|;
end_typedef

begin_comment
comment|/* Define the encoding of numbers */
end_comment

begin_define
define|#
directive|define
name|c_num1
value|32
end_define

begin_define
define|#
directive|define
name|c_value_num1
parameter_list|(
name|ch
parameter_list|)
value|((int)(byte)(ch) - 139)
end_define

begin_define
define|#
directive|define
name|c_num2
value|247
end_define

begin_define
define|#
directive|define
name|c_value_num2
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
define|\
value|(((int)(byte)((c1) - c_num2)<< 8) + (int)(byte)(c2) + 108)
end_define

begin_define
define|#
directive|define
name|c_num3
value|251
end_define

begin_define
define|#
directive|define
name|c_value_num3
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
define|\
value|-(((int)(byte)((c1) - c_num3)<< 8) + (int)(byte)(c2) + 108)
end_define

begin_comment
comment|/* Otherwise, the first byte is 255, followed by a 32-bit 2's complement */
end_comment

begin_comment
comment|/* number in big-endian order. */
end_comment

begin_define
define|#
directive|define
name|c_num4
value|255
end_define

begin_comment
comment|/* Define the encryption parameters */
end_comment

begin_define
define|#
directive|define
name|crypt_c1
value|((ushort)52845)
end_define

begin_define
define|#
directive|define
name|crypt_c2
value|((ushort)22719)
end_define

begin_define
define|#
directive|define
name|encrypt_next
parameter_list|(
name|ch
parameter_list|,
name|state
parameter_list|,
name|chvar
parameter_list|)
define|\
value|chvar = ((ch) ^ (state>> 8)),\   state = (chvar + state) * crypt_c1 + crypt_c2
end_define

begin_define
define|#
directive|define
name|decrypt_this
parameter_list|(
name|ch
parameter_list|,
name|state
parameter_list|)
define|\
value|((ch) ^ (state>> 8))
end_define

begin_define
define|#
directive|define
name|decrypt_next
parameter_list|(
name|ch
parameter_list|,
name|state
parameter_list|,
name|chvar
parameter_list|)
define|\
value|chvar = decrypt_this(ch, state),\   decrypt_skip_next(ch, state)
end_define

begin_define
define|#
directive|define
name|decrypt_skip_next
parameter_list|(
name|ch
parameter_list|,
name|state
parameter_list|)
define|\
value|state = ((ch) + state) * crypt_c1 + crypt_c2
end_define

end_unit

