begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gzht.h */
end_comment

begin_comment
comment|/* Private halftone representation for GhostScript */
end_comment

begin_comment
comment|/* Halftone parameter structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|halftone_params_s
block|{
name|float
name|frequency
decl_stmt|;
name|float
name|angle
decl_stmt|;
comment|/* Computed values */
name|int
name|width
decl_stmt|;
name|int
name|height
decl_stmt|;
name|struct
name|ht_bit_s
modifier|*
name|order
decl_stmt|;
comment|/* whitening order */
name|int
name|order_size
decl_stmt|;
block|}
name|halftone_params
typedef|;
end_typedef

begin_comment
comment|/*  * The whitening order is represented by an array stored in row order.  * The pixel represented by order[0] is whitened first.  * During sampling, order[i].mask is a normalized sample value.  * After sampling and sorting,  * order[i].offset is the byte index of the pixel in the rendering cache;  * order[i].mask is the mask to be or'ed into this byte and the  * following one.  (This is arranged so it will work properly on  * either big- or little-endian machines.)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ht_bit_s
block|{
name|ushort
name|offset
decl_stmt|;
name|ushort
name|mask
decl_stmt|;
block|}
name|ht_bit
typedef|;
end_typedef

end_unit

