begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* vmsmath.h */
end_comment

begin_comment
comment|/* Substitute for math.h on VAX/VMS systems */
end_comment

begin_comment
comment|/*  DEC VAX/VMS C comes with a math.h file but GNU VAX/VMS C does not */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MATH
end_ifndef

begin_define
define|#
directive|define
name|__MATH
end_define

begin_if
if|#
directive|if
name|CC$gfloat
end_if

begin_define
define|#
directive|define
name|HUGE_VAL
value|8.988465674311578540726371186585e+307
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HUGE_VAL
value|1.70141183460469229e+38
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|double
name|acos
argument_list|()
decl_stmt|,
name|asin
argument_list|()
decl_stmt|,
name|atan
argument_list|()
decl_stmt|,
name|atan2
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|sin
argument_list|()
decl_stmt|,
name|tan
argument_list|()
decl_stmt|,
name|cos
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|cosh
argument_list|()
decl_stmt|,
name|sinh
argument_list|()
decl_stmt|,
name|tanh
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|exp
argument_list|()
decl_stmt|,
name|frexp
argument_list|()
decl_stmt|,
name|ldexp
argument_list|()
decl_stmt|,
name|log
argument_list|()
decl_stmt|,
name|log10
argument_list|()
decl_stmt|,
name|pow
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|modf
argument_list|()
decl_stmt|,
name|fmod
argument_list|()
decl_stmt|,
name|sqrt
argument_list|()
decl_stmt|,
name|ceil
argument_list|()
decl_stmt|,
name|floor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|fabs
argument_list|()
decl_stmt|,
name|cabs
argument_list|()
decl_stmt|,
name|hypot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

