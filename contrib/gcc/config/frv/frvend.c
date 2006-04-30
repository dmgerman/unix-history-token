begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Frv initialization file linked after all user modules    Copyright (C) 1999, 2000, 2003, 2004 Free Software Foundation, Inc.     Contributed by Red Hat, Inc.       This file is part of GCC.       GCC is free software ; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation * either version 2, or (at your option)    any later version.       GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY ; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.       You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_include
include|#
directive|include
file|"defaults.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"unwind-dw2-fde.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FRV_UNDERSCORE__
end_ifdef

begin_define
define|#
directive|define
name|UNDERSCORE
value|"_"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNDERSCORE
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FINI_SECTION_ZERO
parameter_list|(
name|SECTION
parameter_list|,
name|FLAGS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|__asm__ (".section " SECTION "," FLAGS "\n\t"				\ 	 ".globl   " UNDERSCORE NAME "\n\t"				\ 	 ".type    " UNDERSCORE NAME ",@object\n\t"			\ 	 ".p2align  2\n"						\ 	 UNDERSCORE NAME ":\n\t"					\ 	 ".word     0\n\t"						\ 	 ".previous")
end_define

begin_define
define|#
directive|define
name|FINI_SECTION
parameter_list|(
name|SECTION
parameter_list|,
name|FLAGS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|__asm__ (".section " SECTION "," FLAGS "\n\t"				\ 	 ".globl   " UNDERSCORE NAME "\n\t"				\ 	 ".type    " UNDERSCORE NAME ",@object\n\t"			\ 	 ".p2align  2\n"						\ 	 UNDERSCORE NAME ":\n\t"					\ 	 ".previous")
end_define

begin_comment
comment|/* End of .ctor/.dtor sections that provides a list of constructors and    destructors to run.  */
end_comment

begin_expr_stmt
name|FINI_SECTION_ZERO
argument_list|(
literal|".ctors"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__CTOR_END__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FINI_SECTION_ZERO
argument_list|(
literal|".dtors"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__DTOR_END__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* End of .eh_frame section that provides all of the exception handling    tables.  */
end_comment

begin_expr_stmt
name|FINI_SECTION_ZERO
argument_list|(
literal|".eh_frame"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__FRAME_END__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* End of .rofixup section that provides a list of pointers that we    need to adjust.  */
end_comment

begin_expr_stmt
name|FINI_SECTION
argument_list|(
literal|".rofixup"
argument_list|,
literal|"\"a\""
argument_list|,
literal|"__ROFIXUP_END__"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

