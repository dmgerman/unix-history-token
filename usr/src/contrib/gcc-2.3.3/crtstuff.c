begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Specialized bits of code needed to support construction and    destruction of file-scope objects in C++ code.     Written by Ron Guilmette (rfg@ncd.com) with help from Richard Stallman.  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files    compiled with GCC to produce an executable, this does not cause    the resulting executable to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* This file is a bit like libgcc1.c/libgcc2.c in that it is compiled    multiple times and yields multiple .o files.     This file is useful on target machines where the object file format    supports multiple "user-defined" sections (e.g. COFF, ELF, ROSE).  On    such systems, this file allows us to avoid running collect (or any    other such slow and painful kludge).  Additionally, if the target    system supports a .init section, this file allows us to support the    linking of C++ code with a non-C++ main program.     Note that if INIT_SECTION_ASM_OP is defined in the tm.h file, then    this file *will* make use of the .init section.  If that symbol is    not defined however, then the .init section will not be used.     Currently, only ELF and COFF are supported.  It is likely however that    ROSE could also be supported, if someone was willing to do the work to    make whatever (small?) adaptations are needed.  (Some work may be    needed on the ROSE assembler and linker also.)     This file must be compiled with gcc.  */
end_comment

begin_comment
comment|/* It is incorrect to include config.h here, because this file is being    compiled for the target, and hence definitions concerning only the host    do not apply.  */
end_comment

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CTORS_SECTION_ASM_OP
end_ifndef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"a\",@progbits"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DTORS_SECTION_ASM_OP
end_ifndef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"a\",@progbits"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ON_EXIT
end_ifndef

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_BEGIN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_ASM_OP
end_ifdef

begin_comment
comment|/* The function __do_global_ctors_aux is compiled twice (once in crtbegin.o    and once in crtend.o).  It must be declared static to avoid a link    error.  Here, we define __do_global_ctors as an externally callable    function.  It is externally callable so that __main can invoke it when    INVOKE__main is defined.  This has the additional effect of forcing cc1    to switch to the .text section.  */
end_comment

begin_function_decl
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__do_global_ctors
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|INVOKE__main
comment|/* If __main won't actually call __do_global_ctors 			then it doesn't matter what's inside the function. 			The inside of __do_global_ctors_aux is called 			automatically in that case. 			And the Alliant fx2800 linker crashes 			on this reference.  So prevent the crash.  */
name|__do_global_ctors_aux
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_asm
asm|asm (INIT_SECTION_ASM_OP);
end_asm

begin_comment
comment|/* cc1 doesn't know that we are switching! */
end_comment

begin_comment
comment|/* On some svr4 systems, the .init section preamble code provided in    crti.o may do some evil things which we have to undo before we reach    the function prologue code for __do_global_ctors (directly below).    For such systems, define the macro INIT_SECTION_PREAMBLE to    expand into the code needed to undo the actions of the crti.o file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_PREAMBLE
end_ifdef

begin_expr_stmt
name|INIT_SECTION_PREAMBLE
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A routine to invoke all of the global constructors upon entry to the    program.  We put this into the .init section (for systems that have    such a thing) so that we can properly perform the construction of    file-scope static-storage C++ objects within shared libraries.   */
end_comment

begin_function
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|()
comment|/* prologue goes in .init section */
block|{
asm|asm (TEXT_SECTION_ASM_OP);
comment|/* don't put epilogue and body in .init */
name|DO_GLOBAL_CTORS_BODY
expr_stmt|;
name|ON_EXIT
argument_list|(
name|__do_global_dtors
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(INIT_SECTION_ASM_OP) */
end_comment

begin_comment
comment|/* Force cc1 to switch to .data section.  */
end_comment

begin_decl_stmt
specifier|static
name|func_ptr
name|force_to_data
index|[
literal|0
index|]
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The -1 is a flag to __do_global_[cd]tors    indicating that this table does not start with a count of elements.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CTOR_LIST_BEGIN
end_ifdef

begin_expr_stmt
name|CTOR_LIST_BEGIN
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm (CTORS_SECTION_ASM_OP);
end_asm

begin_comment
comment|/* cc1 doesn't know that we are switching! */
end_comment

begin_decl_stmt
name|func_ptr
name|__CTOR_LIST__
index|[
literal|1
index|]
init|=
block|{
operator|(
name|func_ptr
operator|)
operator|(
operator|-
literal|1
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DTOR_LIST_BEGIN
end_ifdef

begin_expr_stmt
name|DTOR_LIST_BEGIN
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm (DTORS_SECTION_ASM_OP);
end_asm

begin_comment
comment|/* cc1 doesn't know that we are switching! */
end_comment

begin_decl_stmt
name|func_ptr
name|__DTOR_LIST__
index|[
literal|1
index|]
init|=
block|{
operator|(
name|func_ptr
operator|)
operator|(
operator|-
literal|1
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CRT_BEGIN) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_END
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_ASM_OP
end_ifdef

begin_comment
comment|/* A routine to invoke all of the global constructors upon entry to the    program.  We put this into the .init section (for systems that have    such a thing) so that we can properly perform the construction of    file-scope static-storage C++ objects within shared libraries.     This must be virtually identical to the one above so that we can    insure that the function prologue from the one above works correctly    with the epilogue from this one.  (They will both go into the .init    section as the first and last things (respectively) that the linker    will put in that section.) */
end_comment

begin_function
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|()
comment|/* prologue goes in .text section */
block|{
asm|asm (INIT_SECTION_ASM_OP);
name|DO_GLOBAL_CTORS_BODY
expr_stmt|;
name|ON_EXIT
argument_list|(
name|__do_global_dtors
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* epilogue and body go in .init section */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(INIT_SECTION_ASM_OP) */
end_comment

begin_comment
comment|/* Force cc1 to switch to .data section.  */
end_comment

begin_decl_stmt
specifier|static
name|func_ptr
name|force_to_data
index|[
literal|0
index|]
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CTOR_LIST_END
end_ifdef

begin_expr_stmt
name|CTOR_LIST_END
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm (CTORS_SECTION_ASM_OP);
end_asm

begin_comment
comment|/* cc1 doesn't know that we are switching! */
end_comment

begin_decl_stmt
name|func_ptr
name|__CTOR_END__
index|[
literal|1
index|]
init|=
block|{
operator|(
name|func_ptr
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DTOR_LIST_END
end_ifdef

begin_expr_stmt
name|DTOR_LIST_END
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm (DTORS_SECTION_ASM_OP);
end_asm

begin_comment
comment|/* cc1 doesn't know that we are switching! */
end_comment

begin_decl_stmt
name|func_ptr
name|__DTOR_END__
index|[
literal|1
index|]
init|=
block|{
operator|(
name|func_ptr
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CRT_END) */
end_comment

end_unit

