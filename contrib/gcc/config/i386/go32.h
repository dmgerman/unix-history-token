begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running MS-DOS with djgpp/go32.  */
end_comment

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_PREDEFINES
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -DGO32 -DMSDOS \   -Asystem(unix) -Asystem(msdos) -Acpu(i386) -Amachine(i386)"
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_ctor, in_dtor
end_define

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CTOR_SECTION_FUNCTION						\   DTOR_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|CTOR_SECTION_FUNCTION
define|\
value|void								\ ctor_section ()							\ {								\   if (in_section != in_ctor)					\     {								\       fprintf (asm_out_file, "\t.section .ctor\n");		\       in_section = in_ctor;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|DTOR_SECTION_FUNCTION
define|\
value|void								\ dtor_section ()							\ {								\   if (in_section != in_dtor)					\     {								\       fprintf (asm_out_file, "\t.section .dtor\n");		\       in_section = in_dtor;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\     ctor_section ();				\     fprintf (FILE, "%s\t", ASM_LONG);		\     assemble_name (FILE, NAME);			\     fprintf (FILE, "\n");			\   } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\     dtor_section ();                   		\     fprintf (FILE, "%s\t", ASM_LONG);		\     assemble_name (FILE, NAME);              	\     fprintf (FILE, "\n");			\   } while (0)
end_define

end_unit

