begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxarith.h */
end_comment

begin_comment
comment|/* Arithmetic macros for GhostScript library */
end_comment

begin_comment
comment|/* Define an in-line abs function, good for any signed numeric type. */
end_comment

begin_define
define|#
directive|define
name|any_abs
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_comment
comment|/* Find the high-order bit of a positive or unsigned long variable. */
end_comment

begin_define
define|#
directive|define
name|num_bits
parameter_list|(
name|x
parameter_list|)
define|\
value|("\000\001\002\002\003\003\003\003\004\004\004\004\004\004\004\004"\    [(x>= 0x10000L ?\      (uint)(x>> (x>= 0x1000000L ?\                   (x>= 0x10000000L ? 28 : 24) :\                   (x>= 0x100000L ? 20 : 16))) :\      (uint)x>> ((uint)x>= 0x100 ?\                   ((uint)x>= 0x1000 ? 12 : 8) :\                   ((uint)x>= 0x10 ? 4 : 0)))\& 15])
end_define

begin_comment
comment|/* Test floating point values against zero. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/* not IEEE format! */
end_comment

begin_define
define|#
directive|define
name|is_fzero
parameter_list|(
name|f
parameter_list|)
value|((f) == 0)
end_define

begin_define
define|#
directive|define
name|is_fzero2
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|((f1) == 0&& (f2) == 0)
end_define

begin_define
define|#
directive|define
name|is_fneg
parameter_list|(
name|f
parameter_list|)
value|((f)< 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_f_as_l
parameter_list|(
name|f
parameter_list|)
value|*(long *)(&(f))
end_define

begin_define
define|#
directive|define
name|is_fzero
parameter_list|(
name|f
parameter_list|)
value|((_f_as_l(f)<< 1) == 0)
end_define

begin_comment
comment|/* +0 or -0 */
end_comment

begin_define
define|#
directive|define
name|is_fzero2
parameter_list|(
name|f1
parameter_list|,
name|f2
parameter_list|)
value|(((_f_as_l(f1) | _f_as_l(f2))<< 1) == 0)
end_define

begin_define
define|#
directive|define
name|is_fneg
parameter_list|(
name|f
parameter_list|)
value|((_f_as_l(f))< 0)
end_define

begin_comment
comment|/* -0 is negative, oh well */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

