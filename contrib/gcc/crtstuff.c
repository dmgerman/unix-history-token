begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Specialized bits of code needed to support construction and    destruction of file-scope objects in C++ code.    Copyright (C) 1991, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is a bit like libgcc2.c in that it is compiled    multiple times and yields multiple .o files.     This file is useful on target machines where the object file format    supports multiple "user-defined" sections (e.g. COFF, ELF, ROSE).  On    such systems, this file allows us to avoid running collect (or any    other such slow and painful kludge).  Additionally, if the target    system supports a .init section, this file allows us to support the    linking of C++ code with a non-C++ main program.     Note that if INIT_SECTION_ASM_OP is defined in the tm.h file, then    this file *will* make use of the .init section.  If that symbol is    not defined however, then the .init section will not be used.     Currently, only ELF and COFF are supported.  It is likely however that    ROSE could also be supported, if someone was willing to do the work to    make whatever (small?) adaptations are needed.  (Some work may be    needed on the ROSE assembler and linker also.)     This file must be compiled with gcc.  */
end_comment

begin_comment
comment|/* It is incorrect to include config.h here, because this file is being    compiled for the target, and hence definitions concerning only the host    do not apply.  */
end_comment

begin_comment
comment|/* We include auto-host.h here to get HAVE_GAS_HIDDEN.  This is    supposedly valid even though this is a "target" file.  */
end_comment

begin_include
include|#
directive|include
file|"auto-host.h"
end_include

begin_include
include|#
directive|include
file|"tconfig.h"
end_include

begin_include
include|#
directive|include
file|"tsystem.h"
end_include

begin_include
include|#
directive|include
file|"unwind-dw2-fde.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FORCE_CODE_SECTION_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|FORCE_CODE_SECTION_ALIGN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CRT_CALL_STATIC_FUNCTION
end_ifndef

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|static void __attribute__((__used__))			\ call_ ## FUNC (void)					\ {							\   asm (SECTION_OP);					\   FUNC ();						\   FORCE_CODE_SECTION_ALIGN				\   asm (TEXT_SECTION_ASM_OP);				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJECT_FORMAT_ELF
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LD_EH_FRAME_HDR
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|inhibit_libc
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CRTSTUFFT_O
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
name|__GLIBC__
operator|>=
literal|2
end_if

begin_include
include|#
directive|include
file|<link.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__GLIBC__
operator|>
literal|2
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|>
literal|2
operator|)
expr|\
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
operator|&&
name|__GLIBC_MINOR__
operator|==
literal|2
operator|&&
name|defined
argument_list|(
name|DT_CONFIG
argument_list|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|USE_PT_GNU_EH_FRAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EH_FRAME_SECTION_NAME
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_PT_GNU_EH_FRAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_EH_FRAME_REGISTRY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We do not want to add the weak attribute to the declarations of these    routines in unwind-dw2-fde.h because that will cause the definition of    these symbols to be weak as well.     This exposes a core issue, how to handle creating weak references vs    how to create weak definitions.  Either we have to have the definition    of TARGET_WEAK_ATTRIBUTE be conditional in the shared header files or    have a second declaration if we want a function's references to be weak,    but not its definition.     Making TARGET_WEAK_ATTRIBUTE conditional seems like a good solution until    one thinks about scaling to larger problems -- ie, the condition under    which TARGET_WEAK_ATTRIBUTE is active will eventually get far too    complicated.     So, we take an approach similar to #pragma weak -- we have a second    declaration for functions that we want to have weak references.     Neither way is particularly good.  */
end_comment

begin_comment
comment|/* References to __register_frame_info and __deregister_frame_info should    be weak in this file if at all possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__register_frame_info
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|object
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__register_frame_info_bases
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|object
operator|*
argument_list|,
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|__deregister_frame_info
argument_list|(
name|void
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|__deregister_frame_info_bases
argument_list|(
name|void
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise for _Jv_RegisterClasses.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_Jv_RegisterClasses
argument_list|(
name|void
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OBJECT_FORMAT_MACHO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OBJECT_FORMAT_ELF
end_ifdef

begin_comment
comment|/*  Declare a pointer to void function type.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|func_ptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_include
include|#
directive|include
file|"gbl-ctors.h"
end_include

begin_define
define|#
directive|define
name|STATIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_BEGIN
end_ifdef

begin_comment
comment|/* NOTE:  In order to be able to support SVR4 shared libraries, we arrange    to have one set of symbols { __CTOR_LIST__, __DTOR_LIST__, __CTOR_END__,    __DTOR_END__ } per root executable and also one set of these symbols    per shared library.  So in any given whole process image, we may have    multiple definitions of each of these symbols.  In order to prevent    these definitions from conflicting with one another, and in order to    ensure that the proper lists are used for the initialization/finalization    of each individual shared library (respectively), we give these symbols    only internal (i.e. `static') linkage, and we also make it a point to    refer to only the __CTOR_END__ symbol in crtend.o and the __DTOR_LIST__    symbol in crtbegin.o, where they are defined.  */
end_comment

begin_comment
comment|/* The -1 is a flag to __do_global_[cd]tors indicating that this table    does not start with a count of elements.  */
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CTORS_SECTION_ASM_OP
argument_list|)
end_elif

begin_comment
comment|/* Hack: force cc1 to switch to .data section early, so that assembling    __CTOR_LIST__ does not undo our behind-the-back change to .ctors.  */
end_comment

begin_decl_stmt
specifier|static
name|func_ptr
name|force_to_data
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (CTORS_SECTION_ASM_OP);
end_asm

begin_decl_stmt
name|STATIC
name|func_ptr
name|__CTOR_LIST__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|STATIC
name|func_ptr
name|__CTOR_LIST__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|,
name|section
argument_list|(
literal|".ctors"
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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

begin_comment
comment|/* __CTOR_LIST__ alternatives */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DTOR_LIST_BEGIN
end_ifdef

begin_expr_stmt
name|DTOR_LIST_BEGIN
expr_stmt|;
end_expr_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DTORS_SECTION_ASM_OP
argument_list|)
end_elif

begin_asm
asm|asm (DTORS_SECTION_ASM_OP);
end_asm

begin_decl_stmt
name|STATIC
name|func_ptr
name|__DTOR_LIST__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|STATIC
name|func_ptr
name|__DTOR_LIST__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".dtors"
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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

begin_comment
comment|/* __DTOR_LIST__ alternatives */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EH_FRAME_SECTION_NAME
end_ifdef

begin_comment
comment|/* Stick a label at the beginning of the frame unwind info so we can register    and deregister it with the exception handling library code.  */
end_comment

begin_decl_stmt
name|STATIC
name|char
name|__EH_FRAME_BEGIN__
index|[]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
name|EH_FRAME_SECTION_NAME
argument_list|)
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EH_FRAME_SECTION_NAME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JCR_SECTION_NAME
end_ifdef

begin_comment
comment|/* Stick a label at the beginning of the java class registration info    so we can register them properly.  */
end_comment

begin_decl_stmt
name|STATIC
name|void
modifier|*
name|__JCR_LIST__
index|[]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|section
argument_list|(
name|JCR_SECTION_NAME
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
operator|)
argument_list|)
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JCR_SECTION_NAME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_ASM_OP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OBJECT_FORMAT_ELF
end_ifdef

begin_comment
comment|/* Declare the __dso_handle variable.  It should have a unique value    in every shared-object; in a main program its value is zero.  The    object should in any case be protected.  This means the instance    in one DSO or the main program is not used in another object.  The    dynamic linker takes care of this.  */
end_comment

begin_comment
comment|/* XXX Ideally the following should be implemented using        __attribute__ ((__visibility__ ("hidden")))    but the __attribute__ support is not yet there.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_HIDDEN
end_ifdef

begin_asm
asm|asm (".hidden\t__dso_handle");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CRTSTUFFS_O
end_ifdef

begin_decl_stmt
name|void
modifier|*
name|__dso_handle
init|=
operator|&
name|__dso_handle
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
modifier|*
name|__dso_handle
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __cxa_finalize function may not be available so we use only a    weak declaration.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__cxa_finalize
argument_list|(
name|void
operator|*
argument_list|)
name|TARGET_ATTRIBUTE_WEAK
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run all the global destructors on exit from the program.  */
end_comment

begin_comment
comment|/* Some systems place the number of pointers in the first word of the    table.  On SVR4 however, that word is -1.  In all cases, the table is    null-terminated.  On SVR4, we start from the beginning of the list and    invoke each per-compilation-unit destructor routine in order    until we find that null.     Note that this function MUST be static.  There will be one of these    functions in each root executable and one in each shared library, but    although they all have the same code, each one is unique in that it    refers to one particular associated `__DTOR_LIST__' which belongs to the    same particular root executable or shared library file.     On some systems, this routine is run more than once from the .fini,    when exit is called recursively, so we arrange to remember where in    the list we left off processing, and we resume at that point,    should we be re-invoked.  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|__do_global_dtors_aux
argument_list|(
name|void
argument_list|)
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
specifier|static
name|_Bool
name|completed
decl_stmt|;
name|func_ptr
name|f
decl_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|completed
argument_list|,
literal|0
argument_list|)
condition|)
return|return;
ifdef|#
directive|ifdef
name|CRTSTUFFS_O
if|if
condition|(
name|__cxa_finalize
condition|)
name|__cxa_finalize
argument_list|(
name|__dso_handle
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
operator|(
name|f
operator|=
operator|*
name|p
operator|)
condition|)
block|{
name|p
operator|++
expr_stmt|;
name|f
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|USE_EH_FRAME_REGISTRY
if|#
directive|if
name|defined
argument_list|(
name|CRT_GET_RFIB_TEXT
argument_list|)
operator|||
name|defined
argument_list|(
name|CRT_GET_RFIB_DATA
argument_list|)
comment|/* If we used the new __register_frame_info_bases interface,      make sure that we deregister from the same place.  */
if|if
condition|(
name|__deregister_frame_info_bases
condition|)
name|__deregister_frame_info_bases
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|__deregister_frame_info
condition|)
name|__deregister_frame_info
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|completed
operator|=
literal|1
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/* Stick a call to __do_global_dtors_aux into the .fini section.  */
end_comment

begin_macro
name|CRT_CALL_STATIC_FUNCTION
argument_list|(
argument|FINI_SECTION_ASM_OP
argument_list|,
argument|__do_global_dtors_aux
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_EH_FRAME_REGISTRY
argument_list|)
operator|||
name|defined
argument_list|(
name|JCR_SECTION_NAME
argument_list|)
end_if

begin_comment
comment|/* Stick a call to __register_frame_info into the .init section.  For some    reason calls with no arguments work more reliably in .init, so stick the    call in another function.  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|frame_dummy
argument_list|(
name|void
argument_list|)
block|{
ifdef|#
directive|ifdef
name|USE_EH_FRAME_REGISTRY
specifier|static
name|struct
name|object
name|object
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|CRT_GET_RFIB_TEXT
argument_list|)
operator|||
name|defined
argument_list|(
name|CRT_GET_RFIB_DATA
argument_list|)
name|void
modifier|*
name|tbase
decl_stmt|,
modifier|*
name|dbase
decl_stmt|;
ifdef|#
directive|ifdef
name|CRT_GET_RFIB_TEXT
name|CRT_GET_RFIB_TEXT
argument_list|(
name|tbase
argument_list|)
expr_stmt|;
else|#
directive|else
name|tbase
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CRT_GET_RFIB_DATA
name|CRT_GET_RFIB_DATA
argument_list|(
name|dbase
argument_list|)
expr_stmt|;
else|#
directive|else
name|dbase
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|__register_frame_info_bases
condition|)
name|__register_frame_info_bases
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|,
operator|&
name|object
argument_list|,
name|tbase
argument_list|,
name|dbase
argument_list|)
expr_stmt|;
else|#
directive|else
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
endif|#
directive|endif
endif|#
directive|endif
comment|/* EH_FRAME_SECTION_NAME */
ifdef|#
directive|ifdef
name|JCR_SECTION_NAME
if|if
condition|(
name|__JCR_LIST__
index|[
literal|0
index|]
operator|&&
name|_Jv_RegisterClasses
condition|)
name|_Jv_RegisterClasses
argument_list|(
name|__JCR_LIST__
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* JCR_SECTION_NAME */
block|}
end_decl_stmt

begin_macro
name|CRT_CALL_STATIC_FUNCTION
argument_list|(
argument|INIT_SECTION_ASM_OP
argument_list|,
argument|frame_dummy
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EH_FRAME_SECTION_NAME || JCR_SECTION_NAME */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_comment
comment|/* The function __do_global_ctors_aux is compiled twice (once in crtbegin.o    and once in crtend.o).  It must be declared static to avoid a link    error.  Here, we define __do_global_ctors as an externally callable    function.  It is externally callable so that __main can invoke it when    INVOKE__main is defined.  This has the additional effect of forcing cc1    to switch to the .text section.  */
end_comment

begin_function_decl
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__do_global_ctors
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|INVOKE__main
comment|/* If __main won't actually call __do_global_ctors then it doesn't matter      what's inside the function.  The inside of __do_global_ctors_aux is      called automatically in that case.  And the Alliant fx2800 linker      crashes on this reference.  So prevent the crash.  */
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
comment|/* On some svr4 systems, the initial .init section preamble code provided in    crti.o may do something, such as bump the stack, which we have to     undo before we reach the function prologue code for __do_global_ctors     (directly below).  For such systems, define the macro INIT_SECTION_PREAMBLE    to expand into the code needed to undo the actions of the crti.o file.  */
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
comment|/* A routine to invoke all of the global constructors upon entry to the    program.  We put this into the .init section (for systems that have    such a thing) so that we can properly perform the construction of    file-scope static-storage C++ objects within shared libraries.  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|__do_global_ctors_aux
argument_list|(
name|void
argument_list|)
comment|/* prologue goes in .init section */
block|{
name|FORCE_CODE_SECTION_ALIGN
comment|/* explicit align before switch to .text */
name|asm
parameter_list|(
name|TEXT_SECTION_ASM_OP
parameter_list|)
function_decl|;
comment|/* don't put epilogue and body in .init */
name|DO_GLOBAL_CTORS_BODY
expr_stmt|;
name|atexit
argument_list|(
name|__do_global_dtors
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAS_INIT_SECTION
argument_list|)
end_elif

begin_comment
comment|/* ! INIT_SECTION_ASM_OP */
end_comment

begin_comment
comment|/* This case is used by the Irix 6 port, which supports named sections but    not an SVR4-style .fini section.  __do_global_dtors can be non-static    in this case because we protect it with -hidden_symbol.  */
end_comment

begin_function
name|void
name|__do_global_dtors
parameter_list|(
name|void
parameter_list|)
block|{
name|func_ptr
modifier|*
name|p
decl_stmt|,
name|f
decl_stmt|;
for|for
control|(
name|p
operator|=
name|__DTOR_LIST__
operator|+
literal|1
init|;
operator|(
name|f
operator|=
operator|*
name|p
operator|)
condition|;
name|p
operator|++
control|)
name|f
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|USE_EH_FRAME_REGISTRY
if|if
condition|(
name|__deregister_frame_info
condition|)
name|__deregister_frame_info
argument_list|(
name|__EH_FRAME_BEGIN__
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_EH_FRAME_REGISTRY
argument_list|)
operator|||
name|defined
argument_list|(
name|JCR_SECTION_NAME
argument_list|)
end_if

begin_comment
comment|/* A helper function for __do_global_ctors, which is in crtend.o.  Here    in crtbegin.o, we can reference a couple of symbols not visible there.    Plus, since we're before libgcc.a, we have no problems referencing    functions from there.  */
end_comment

begin_function
name|void
name|__do_global_ctors_1
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_EH_FRAME_REGISTRY
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|JCR_SECTION_NAME
if|if
condition|(
name|__JCR_LIST__
index|[
literal|0
index|]
operator|&&
name|_Jv_RegisterClasses
condition|)
name|_Jv_RegisterClasses
argument_list|(
name|__JCR_LIST__
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EH_FRAME_SECTION_NAME || JCR_SECTION_NAME */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! INIT_SECTION_ASM_OP&& ! HAS_INIT_SECTION */
end_comment

begin_error
error|#
directive|error
literal|"What are you doing with crtstuff.c, then?"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CRT_END
argument_list|)
end_elif

begin_comment
comment|/* ! CRT_BEGIN */
end_comment

begin_comment
comment|/* Put a word containing zero at the end of each of our two lists of function    addresses.  Note that the words defined here go into the .ctors and .dtors    sections of the crtend.o file, and since that file is always linked in    last, these words naturally end up at the very ends of the two lists    contained in these two sections.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CTOR_LIST_END
end_ifdef

begin_expr_stmt
name|CTOR_LIST_END
expr_stmt|;
end_expr_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CTORS_SECTION_ASM_OP
argument_list|)
end_elif

begin_comment
comment|/* Hack: force cc1 to switch to .data section early, so that assembling    __CTOR_LIST__ does not undo our behind-the-back change to .ctors.  */
end_comment

begin_decl_stmt
specifier|static
name|func_ptr
name|force_to_data
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
init|=
block|{ }
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (CTORS_SECTION_ASM_OP);
end_asm

begin_decl_stmt
name|STATIC
name|func_ptr
name|__CTOR_END__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
init|=
block|{
operator|(
name|func_ptr
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|STATIC
name|func_ptr
name|__CTOR_END__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".ctors"
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DTORS_SECTION_ASM_OP
argument_list|)
end_elif

begin_asm
asm|asm (DTORS_SECTION_ASM_OP);
end_asm

begin_decl_stmt
name|STATIC
name|func_ptr
name|__DTOR_END__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
init|=
block|{
operator|(
name|func_ptr
operator|)
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|STATIC
name|func_ptr
name|__DTOR_END__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|section
argument_list|(
literal|".dtors"
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|func_ptr
argument_list|)
argument_list|)
operator|)
argument_list|)
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
name|EH_FRAME_SECTION_NAME
end_ifdef

begin_comment
comment|/* Terminate the frame unwind info section with a 4byte 0 as a sentinel;    this would be the 'length' field in a real FDE.  */
end_comment

begin_decl_stmt
name|STATIC
name|int
name|__FRAME_END__
index|[]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|mode
argument_list|(
name|SI
argument_list|)
operator|,
name|section
argument_list|(
name|EH_FRAME_SECTION_NAME
argument_list|)
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EH_FRAME_SECTION_NAME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JCR_SECTION_NAME
end_ifdef

begin_comment
comment|/* Null terminate the .jcr section array.  */
end_comment

begin_decl_stmt
name|STATIC
name|void
modifier|*
name|__JCR_END__
index|[
literal|1
index|]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|section
argument_list|(
name|JCR_SECTION_NAME
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JCR_SECTION_NAME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_ASM_OP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OBJECT_FORMAT_ELF
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|used
operator|)
argument_list|)
name|__do_global_ctors_aux
argument_list|(
name|void
argument_list|)
block|{
name|func_ptr
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|__CTOR_END__
operator|-
literal|1
init|;
operator|*
name|p
operator|!=
operator|(
name|func_ptr
operator|)
operator|-
literal|1
condition|;
name|p
operator|--
control|)
call|(
modifier|*
name|p
call|)
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/* Stick a call to __do_global_ctors_aux into the .init section.  */
end_comment

begin_macro
name|CRT_CALL_STATIC_FUNCTION
argument_list|(
argument|INIT_SECTION_ASM_OP
argument_list|,
argument|__do_global_ctors_aux
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_comment
comment|/* Stick the real initialization code, followed by a normal sort of    function epilogue at the very end of the .init section for this    entire root executable file or for this entire shared library file.     Note that we use some tricks here to get *just* the body and just    a function epilogue (but no function prologue) into the .init    section of the crtend.o file.  Specifically, we switch to the .text    section, start to define a function, and then we switch to the .init    section just before the body code.     Earlier on, we put the corresponding function prologue into the .init    section of the crtbegin.o file (which will be linked in first).     Note that we want to invoke all constructors for C++ file-scope static-    storage objects AFTER any other possible initialization actions which    may be performed by the code in the .init section contributions made by    other libraries, etc.  That's because those other initializations may    include setup operations for very primitive things (e.g. initializing    the state of the floating-point coprocessor, etc.) which should be done    before we start to execute any of the user's code.  */
end_comment

begin_function
specifier|static
name|void
name|__do_global_ctors_aux
parameter_list|(
name|void
parameter_list|)
comment|/* prologue goes in .text section */
block|{
asm|asm (INIT_SECTION_ASM_OP);
name|DO_GLOBAL_CTORS_BODY
expr_stmt|;
name|atexit
argument_list|(
name|__do_global_dtors
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* epilogue and body go in .init section */
end_comment

begin_function_decl
name|FORCE_CODE_SECTION_ALIGN
name|asm
parameter_list|(
name|TEXT_SECTION_ASM_OP
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJECT_FORMAT_ELF */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAS_INIT_SECTION
argument_list|)
end_elif

begin_comment
comment|/* ! INIT_SECTION_ASM_OP */
end_comment

begin_comment
comment|/* This case is used by the Irix 6 port, which supports named sections but    not an SVR4-style .init section.  __do_global_ctors can be non-static    in this case because we protect it with -hidden_symbol.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__do_global_ctors_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__do_global_ctors
parameter_list|(
name|void
parameter_list|)
block|{
name|func_ptr
modifier|*
name|p
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|USE_EH_FRAME_REGISTRY
argument_list|)
operator|||
name|defined
argument_list|(
name|JCR_SECTION_NAME
argument_list|)
name|__do_global_ctors_1
argument_list|()
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|p
operator|=
name|__CTOR_END__
operator|-
literal|1
init|;
operator|*
name|p
operator|!=
operator|(
name|func_ptr
operator|)
operator|-
literal|1
condition|;
name|p
operator|--
control|)
call|(
modifier|*
name|p
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! INIT_SECTION_ASM_OP&& ! HAS_INIT_SECTION */
end_comment

begin_error
error|#
directive|error
literal|"What are you doing with crtstuff.c, then?"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! CRT_BEGIN&& ! CRT_END */
end_comment

begin_error
error|#
directive|error
literal|"One of CRT_BEGIN or CRT_END must be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OBJECT_FORMAT_MACHO */
end_comment

begin_comment
comment|/* For Mach-O format executables, we assume that the system's runtime is    smart enough to handle constructors and destructors, but doesn't have    an init section (if it can't even handle constructors/destructors    you should be using INVOKE__main, not crtstuff). All we need to do    is install/deinstall the frame information for exceptions. We do this    by putting a constructor in crtbegin.o and a destructor in crtend.o.     crtend.o also puts in the terminating zero in the frame information    segment.  */
end_comment

begin_comment
comment|/* The crtstuff for other object formats use the symbol __EH_FRAME_BEGIN__    to figure out the start of the exception frame, but here we use    getsectbynamefromheader to find this value. Either method would work,    but this method avoids creating any global symbols, which seems    cleaner.  */
end_comment

begin_include
include|#
directive|include
file|<mach-o/ldsyms.h>
end_include

begin_function_decl
specifier|extern
specifier|const
name|struct
name|section
modifier|*
name|getsectbynamefromheader
parameter_list|(
specifier|const
name|struct
name|mach_header
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_BEGIN
end_ifdef

begin_function_decl
specifier|static
name|void
name|__reg_frame_ctor
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(constructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|void
name|__reg_frame_ctor
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|struct
name|object
name|object
decl_stmt|;
specifier|const
name|struct
name|section
modifier|*
name|eh_frame
decl_stmt|;
name|eh_frame
operator|=
name|getsectbynamefromheader
argument_list|(
operator|&
name|_mh_execute_header
argument_list|,
literal|"__TEXT"
argument_list|,
literal|"__eh_frame"
argument_list|)
expr_stmt|;
name|__register_frame_info
argument_list|(
operator|(
name|void
operator|*
operator|)
name|eh_frame
operator|->
name|addr
argument_list|,
operator|&
name|object
argument_list|)
expr_stmt|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CRT_END
argument_list|)
end_elif

begin_function_decl
specifier|static
name|void
name|__dereg_frame_dtor
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(destructor
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|void
name|__dereg_frame_dtor
parameter_list|(
name|void
parameter_list|)
block|{
specifier|const
name|struct
name|section
modifier|*
name|eh_frame
decl_stmt|;
name|eh_frame
operator|=
name|getsectbynamefromheader
argument_list|(
operator|&
name|_mh_execute_header
argument_list|,
literal|"__TEXT"
argument_list|,
literal|"__eh_frame"
argument_list|)
expr_stmt|;
name|__deregister_frame_info
argument_list|(
operator|(
name|void
operator|*
operator|)
name|eh_frame
operator|->
name|addr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Terminate the frame section with a final zero.  */
end_comment

begin_decl_stmt
name|STATIC
name|int
name|__FRAME_END__
index|[]
name|__attribute__
argument_list|(
operator|(
name|unused
operator|,
name|mode
argument_list|(
name|SI
argument_list|)
operator|,
name|section
argument_list|(
name|EH_FRAME_SECTION_NAME
argument_list|)
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! CRT_BEGIN&& ! CRT_END */
end_comment

begin_error
error|#
directive|error
literal|"One of CRT_BEGIN or CRT_END must be defined."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJECT_FORMAT_MACHO */
end_comment

end_unit

