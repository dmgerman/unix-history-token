begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sequent DYNIX/ptx 1.x (SVr3) */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv3.h"
end_include

begin_comment
comment|/* Sequent Symmetry SVr3 doesn't have crtn.o; crt1.o doesn't work    but crt0.o does.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}\  %{!pg:%{posix:%{p:mcrtp0.o%s}%{!p:crtp0.o%s}}\        %{!posix:%{p:mcrt0.o%s}%{!p:crt0.o%s}}} crtbegin.o%s\  %{p:-L/usr/lib/libp}%{pg:-L/usr/lib/libp}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{posix:-lcposix}\  %{shlib:-lc_s}\  %{fshared-data:-lpps -lseq} -lc crtend.o%s"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE} -D_SEQUENT_=1"
end_define

begin_comment
comment|/* Although the .init section is used, it is not automatically invoked.    This because the _start() function in /lib/crt0.o never calls anything    from the .init section */
end_comment

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_comment
comment|/* Assembler pseudo-op for initialized shared variables (.shdata).  */
end_comment

begin_undef
undef|#
directive|undef
name|SHARED_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SHARED_SECTION_ASM_OP
value|"\t.section .shdata, \"ws\""
end_define

begin_comment
comment|/* Assembler pseudo-op for uninitialized shared global variables (.shbss).  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SHARED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHARED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( fputs(".comm ", (FILE)),			\   assemble_name((FILE), (NAME)),		\    fprintf((FILE), ",%u,-3\n", (SIZE)))
end_define

begin_comment
comment|/* Assembler pseudo-op for uninitialized shared local variables (.shbss).  */
end_comment

begin_undef
undef|#
directive|undef
name|SHARED_BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SHARED_BSS_SECTION_ASM_OP
value|"\t.section .shbss, \"bs\""
end_define

begin_comment
comment|/* seq2-sysv3.h used to define HAVE_ATEXIT, so I assume ptx1 needs this...  */
end_comment

begin_define
define|#
directive|define
name|NEED_ATEXIT
end_define

end_unit

