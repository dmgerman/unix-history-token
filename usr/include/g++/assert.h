begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1988 Free Software Foundation  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.   */
end_comment

begin_comment
comment|/* Allow this file to be included multiple times    with different settings of NDEBUG.  */
end_comment

begin_undef
undef|#
directive|undef
name|assert
end_undef

begin_undef
undef|#
directive|undef
name|assertval
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ignore
parameter_list|)
end_define

begin_define
define|#
directive|define
name|assertval
parameter_list|(
name|ex
parameter_list|)
value|(ex)
end_define

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern
literal|"C"
name|void
name|__eprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|/* Defined in gnulib */
end_comment

begin_extern
extern|extern
literal|"C"
specifier|volatile
name|void
name|abort
parameter_list|()
function_decl|;
end_extern

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex) ? 1 : \               (__eprintf("Failed assertion " #ex " at line %d of `%s'.\n", \                __LINE__, __FILE__), abort (), 0))
end_define

begin_define
define|#
directive|define
name|assertval
parameter_list|(
name|ex
parameter_list|)
define|\
value|((ex) ? 1 : \               (__eprintf("Failed assertion " #ex " at line %d of `%s'.\n", \                __LINE__, __FILE__), abort (), 0))
end_define

begin_endif
endif|#
directive|endif
endif|NDEBUG
end_endif

end_unit

