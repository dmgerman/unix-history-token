begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxlum.h */
end_comment

begin_comment
comment|/* Luminance computation parameters for Ghostscript */
end_comment

begin_comment
comment|/* Color weights used for computing luminance. */
end_comment

begin_define
define|#
directive|define
name|lum_red_weight
value|299
end_define

begin_define
define|#
directive|define
name|lum_green_weight
value|587
end_define

begin_define
define|#
directive|define
name|lum_blue_weight
value|114
end_define

begin_define
define|#
directive|define
name|lum_all_weights
value|(lum_red_weight + lum_green_weight + lum_blue_weight)
end_define

end_unit

