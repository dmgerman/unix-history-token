begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IEEE floating point support declarations, for GDB, the GNU Debugger.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FLOATFORMAT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|FLOATFORMAT_H
value|1
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* A floatformat consists of a sign bit, an exponent and a mantissa.  Once the    bytes are concatenated according to the byteorder flag, then each of those    fields is contiguous.  We number the bits with 0 being the most significant    (i.e. BITS_BIG_ENDIAN type numbering), and specify which bits each field    contains with the *_start and *_len fields.  */
end_comment

begin_enum
enum|enum
name|floatformat_byteorders
block|{
name|floatformat_little
block|,
name|floatformat_big
block|}
enum|;
end_enum

begin_enum
enum|enum
name|floatformat_intbit
block|{
name|floatformat_intbit_yes
block|,
name|floatformat_intbit_no
block|}
enum|;
end_enum

begin_struct
struct|struct
name|floatformat
block|{
name|enum
name|floatformat_byteorders
name|byteorder
decl_stmt|;
name|unsigned
name|int
name|totalsize
decl_stmt|;
comment|/* Total size of number in bits */
comment|/* Sign bit is always one bit long.  1 means negative, 0 means positive.  */
name|unsigned
name|int
name|sign_start
decl_stmt|;
name|unsigned
name|int
name|exp_start
decl_stmt|;
name|unsigned
name|int
name|exp_len
decl_stmt|;
comment|/* Amount added to "true" exponent.  0x3fff for many IEEE extendeds.  */
name|unsigned
name|int
name|exp_bias
decl_stmt|;
comment|/* Exponent value which indicates NaN.  This is the actual value stored in      the float, not adjusted by the exp_bias.  This usually consists of all      one bits.  */
name|unsigned
name|int
name|exp_nan
decl_stmt|;
name|unsigned
name|int
name|man_start
decl_stmt|;
name|unsigned
name|int
name|man_len
decl_stmt|;
comment|/* Is the integer bit explicit or implicit?  */
name|enum
name|floatformat_intbit
name|intbit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* floatformats for IEEE single and double, big and little endian.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_ieee_single_big
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_ieee_single_little
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_ieee_double_big
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_ieee_double_little
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* floatformats for various extendeds.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_i387_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_m68881_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_i960_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_m88110_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|floatformat
name|floatformat_arm_ext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert from FMT to a double.    FROM is the address of the extended float.    Store the double in *TO.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|floatformat_to_double
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|floatformat
operator|*
operator|,
name|char
operator|*
operator|,
name|double
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The converse: convert the double *FROM to FMT    and store where TO points.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|floatformat_from_double
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|floatformat
operator|*
operator|,
name|double
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (FLOATFORMAT_H) */
end_comment

end_unit

