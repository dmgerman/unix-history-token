begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* bnum.h */
end_comment

begin_comment
comment|/* Interface to Level 2 number readers */
end_comment

begin_comment
comment|/* Requires stream.h */
end_comment

begin_comment
comment|/* Homogenous number array formats. */
end_comment

begin_comment
comment|/* The default for numbers is big-endian. */
end_comment

begin_define
define|#
directive|define
name|num_int32
value|0
end_define

begin_comment
comment|/* [0..31] */
end_comment

begin_define
define|#
directive|define
name|num_int16
value|32
end_define

begin_comment
comment|/* [32..47] */
end_comment

begin_define
define|#
directive|define
name|num_float
value|48
end_define

begin_define
define|#
directive|define
name|num_float_IEEE
value|num_float
end_define

begin_define
define|#
directive|define
name|num_float_native
value|(num_float + 1)
end_define

begin_define
define|#
directive|define
name|num_msb
value|0
end_define

begin_define
define|#
directive|define
name|num_lsb
value|128
end_define

begin_define
define|#
directive|define
name|num_is_lsb
parameter_list|(
name|format
parameter_list|)
value|((format)>= num_lsb)
end_define

begin_define
define|#
directive|define
name|num_is_valid
parameter_list|(
name|format
parameter_list|)
value|(((format)& 127)<= 49)
end_define

begin_comment
comment|/* Special "format" for reading from an array */
end_comment

begin_define
define|#
directive|define
name|num_array
value|256
end_define

begin_comment
comment|/* Test the byte ordering of numbers on a stream */
end_comment

begin_define
define|#
directive|define
name|s_is_lsb
parameter_list|(
name|s
parameter_list|)
value|num_is_lsb(s->num_format)
end_define

begin_define
define|#
directive|define
name|s_is_msb
parameter_list|(
name|s
parameter_list|)
value|!s_is_lsb(s)
end_define

begin_comment
comment|/* Read from an array or encoded number array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sread_num_array
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|ref
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint
name|scount_num_stream
argument_list|(
name|P1
argument_list|(
name|stream
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sget_encoded_number
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|ref
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get/put a number with appropriate byte swapping */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sgetshort
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|short
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sputshort
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|short
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sgetlong
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|long
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sputlong
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|long
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sgetfloat
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|float
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sputfloat
argument_list|(
name|P2
argument_list|(
name|stream
operator|*
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

