begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Frv initialization file linked before all user modules    Copyright (C) 1999, 2000 Free Software Foundation, Inc.     Contributed by Red Hat, Inc.       This file is part of GNU CC.       GNU CC is free software ; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation * either version 2, or (at your option)    any later version.       GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY ; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.       You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.     This file was originally taken from the file crtstuff.c in the    main compiler directory, and simplified. */
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

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_comment
comment|/*  Declare a pointer to void function type.  */
end_comment

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

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
name|INIT_SECTION_NEG_ONE
parameter_list|(
name|SECTION
parameter_list|,
name|FLAGS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|__asm__ (".section " SECTION "," FLAGS "\n\t"				\ 	 ".globl   " UNDERSCORE NAME "\n\t"				\ 	 ".type    " UNDERSCORE NAME ",@object\n\t"			\ 	 ".p2align  2\n"						\ 	 UNDERSCORE NAME ":\n\t"					\ 	 ".word     -1\n\t"						\ 	 ".previous")
end_define

begin_define
define|#
directive|define
name|INIT_SECTION
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
comment|/* Beginning of .ctor/.dtor sections that provides a list of constructors and    destructors to run.  */
end_comment

begin_expr_stmt
name|INIT_SECTION_NEG_ONE
argument_list|(
literal|".ctors"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__CTOR_LIST__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|INIT_SECTION_NEG_ONE
argument_list|(
literal|".dtors"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__DTOR_LIST__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Beginning of .eh_frame section that provides all of the exception handling    tables.  */
end_comment

begin_expr_stmt
name|INIT_SECTION
argument_list|(
literal|".eh_frame"
argument_list|,
literal|"\"aw\""
argument_list|,
literal|"__EH_FRAME_BEGIN__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Beginning of .rofixup section that provides a list of pointers that we    need to adjust.  */
end_comment

begin_expr_stmt
name|INIT_SECTION
argument_list|(
literal|".rofixup"
argument_list|,
literal|"\"a\""
argument_list|,
literal|"__ROFIXUP_LIST__"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|void
name|__frv_register_eh
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__constructor__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|__frv_deregister_eh
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__destructor__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|func_ptr
name|__EH_FRAME_BEGIN__
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register the exeception handling table as the first constructor */
end_comment

begin_function
name|void
name|__frv_register_eh
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|struct
name|object
name|object
decl_stmt|;
if|if
condition|(
name|__register_frame_info
condition|)
name|__register_frame_info
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|,
operator|&
name|object
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Note, do not declare __{,de}register_frame_info weak as it seems    to interfere with the pic support.  */
end_comment

begin_comment
comment|/* Unregister the exeception handling table as a deconstructor */
end_comment

begin_function
name|void
name|__frv_deregister_eh
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|completed
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|completed
condition|)
return|return;
if|if
condition|(
name|__deregister_frame_info
condition|)
name|__deregister_frame_info
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|)
expr_stmt|;
name|completed
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Run the global destructors */
end_comment

begin_function
name|void
name|__do_global_dtors
parameter_list|()
block|{
specifier|static
name|func_ptr
modifier|*
name|p
init|=
name|__DTOR_LIST__
operator|+
literal|1
decl_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
block|{
name|p
operator|++
expr_stmt|;
operator|(
operator|*
operator|(
name|p
operator|-
literal|1
operator|)
operator|)
operator|(
operator|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* Run the global constructors */
end_comment

begin_function
name|void
name|__do_global_ctors
parameter_list|()
block|{
name|unsigned
name|long
name|nptrs
init|=
operator|(
name|unsigned
name|long
operator|)
name|__CTOR_LIST__
index|[
literal|0
index|]
decl_stmt|;
name|unsigned
name|i
decl_stmt|;
if|if
condition|(
name|nptrs
operator|==
operator|(
name|unsigned
name|long
operator|)
operator|-
literal|1
condition|)
for|for
control|(
name|nptrs
operator|=
literal|0
init|;
name|__CTOR_LIST__
index|[
name|nptrs
operator|+
literal|1
index|]
operator|!=
literal|0
condition|;
name|nptrs
operator|++
control|)
empty_stmt|;
for|for
control|(
name|i
operator|=
name|nptrs
init|;
name|i
operator|>=
literal|1
condition|;
name|i
operator|--
control|)
name|__CTOR_LIST__
index|[
name|i
index|]
operator|(
operator|)
expr_stmt|;
name|atexit
argument_list|(
name|__do_global_dtors
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Subroutine called automatically by `main'.    Compiling a global function named `main'    produces an automatic call to this function at the beginning.     For many systems, this routine calls __do_global_ctors.    For systems which support a .init section we use the .init section    to run __do_global_ctors, so we need not do anything here.  */
end_comment

begin_function
name|void
name|__main
parameter_list|()
block|{
comment|/* Support recursive calls to `main': run initializers just once.  */
specifier|static
name|int
name|initialized
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|__do_global_ctors
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

