begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IEEE floating point support declarations, for GDB, the GNU Debugger.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IEEE_FLOAT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|IEEE_FLOAT_H
value|1
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* Parameters for extended float format:  */
end_comment

begin_struct
struct|struct
name|ext_format
block|{
name|unsigned
name|totalsize
decl_stmt|;
comment|/* Total size of extended number */
name|unsigned
name|signbyte
decl_stmt|;
comment|/* Byte number of sign bit */
name|unsigned
name|char
name|signmask
decl_stmt|;
comment|/* Mask for sign bit */
name|unsigned
name|expbyte_h
decl_stmt|;
comment|/* High byte of exponent */
name|unsigned
name|expbyte_l
decl_stmt|;
comment|/* Low  byte of exponent */
name|unsigned
name|manbyte_h
decl_stmt|;
comment|/* High byte of mantissa */
name|unsigned
name|manbyte_l
decl_stmt|;
comment|/* Low  byte of mantissa */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TOTALSIZE
value|ext_format->totalsize
end_define

begin_define
define|#
directive|define
name|SIGNBYTE
value|ext_format->signbyte
end_define

begin_define
define|#
directive|define
name|SIGNMASK
value|ext_format->signmask
end_define

begin_define
define|#
directive|define
name|EXPBYTE_H
value|ext_format->expbyte_h
end_define

begin_define
define|#
directive|define
name|EXPBYTE_L
value|ext_format->expbyte_l
end_define

begin_define
define|#
directive|define
name|MANBYTE_H
value|ext_format->manbyte_h
end_define

begin_define
define|#
directive|define
name|MANBYTE_L
value|ext_format->manbyte_l
end_define

begin_comment
comment|/* Actual ext_format structs for various machines are in the *-tdep.c file    for each machine.  */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP_NAN
value|0x7FFF
end_define

begin_comment
comment|/* Exponent value that indicates NaN */
end_comment

begin_define
define|#
directive|define
name|EXT_EXP_BIAS
value|0x3FFF
end_define

begin_comment
comment|/* Amount added to "true" exponent for ext */
end_comment

begin_define
define|#
directive|define
name|DBL_EXP_BIAS
value|0x3FF
end_define

begin_comment
comment|/* Ditto, for doubles */
end_comment

begin_comment
comment|/* Convert an IEEE extended float to a double.    FROM is the address of the extended float.    Store the double in *TO.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ieee_extended_to_double
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|ext_format
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
comment|/* The converse: convert the double *FROM to an extended float    and store where TO points.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|double_to_ieee_extended
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|ext_format
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
comment|/* defined (IEEE_FLOAT_H) */
end_comment

end_unit

