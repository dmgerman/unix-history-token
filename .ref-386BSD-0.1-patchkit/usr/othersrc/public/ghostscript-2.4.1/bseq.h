begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* bseq.h */
end_comment

begin_comment
comment|/* Definitions for Level 2 binary object sequences */
end_comment

begin_comment
comment|/* Binary object sequence element types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|bs_null
init|=
literal|0
block|,
name|bs_integer
init|=
literal|1
block|,
name|bs_real
init|=
literal|2
block|,
name|bs_name
init|=
literal|3
block|,
name|bs_boolean
init|=
literal|4
block|,
name|bs_string
init|=
literal|5
block|,
name|bs_eval_name
init|=
literal|6
block|,
name|bs_array
init|=
literal|9
block|,
name|bs_mark
init|=
literal|10
block|}
name|bin_seq_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|bs_executable
value|128
end_define

begin_comment
comment|/* Definition of an object in a binary object sequence */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|byte
name|tx
decl_stmt|;
comment|/* type and executable flag */
name|byte
name|unused
decl_stmt|;
union|union
block|{
name|ushort
name|w
decl_stmt|;
name|byte
name|b
index|[
literal|2
index|]
decl_stmt|;
block|}
name|size
union|;
union|union
block|{
name|long
name|w
decl_stmt|;
name|float
name|f
decl_stmt|;
name|byte
name|b
index|[
literal|4
index|]
decl_stmt|;
block|}
name|value
union|;
block|}
name|bin_seq_obj
typedef|;
end_typedef

end_unit

