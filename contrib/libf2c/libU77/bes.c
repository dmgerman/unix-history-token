begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1995, 1996 Free Software Foundation, Inc. This file is part of GNU Fortran libU77 library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with GNU Fortran; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Don't include these unless necessary -- jcb. */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
unit|double G77_besj0_0 (const real *x) {     return j0 (*x); }  double G77_besj1_0 (const real *x) {     return j1 (*x); }  double G77_besjn_0 (const integer *n, real *x) {      return jn (*n, *x);  }  double G77_besy0_0 (const real *x) {     return y0 (*x); }  double G77_besy1_0 (const real *x) {     return y1 (*x); }  double G77_besyn_0 (const integer *n, real *x) {     return yn (*n, *x); }
endif|#
directive|endif
end_endif

end_unit

