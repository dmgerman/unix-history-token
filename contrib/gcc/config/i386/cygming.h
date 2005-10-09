begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using a Unix style C library and tools.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
value|1
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_define
define|#
directive|define
name|TARGET_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_define
define|#
directive|define
name|TARGET_IS_PE_COFF
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Masks for subtarget switches used by other files.  */
end_comment

begin_define
define|#
directive|define
name|MASK_NOP_FUN_DLLIMPORT
value|0x08000000
end_define

begin_comment
comment|/* Ignore dllimport for functions */
end_comment

begin_comment
comment|/* Used in winnt.c.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NOP_FUN_DLLIMPORT
value|(target_flags& MASK_NOP_FUN_DLLIMPORT)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "cygwin",		  0, N_("Use the Cygwin interface") },	\ { "no-cygwin",		  0, N_("Use the Mingw32 interface") },	\ { "windows",		  0, N_("Create GUI application") },	\ { "no-win32",		  0, N_("Don't set Windows defines") },	\ { "win32",		  0, N_("Set Windows defines") },	\ { "console",		  0, N_("Create console application") },\ { "dll",		  0, N_("Generate code for a DLL") },	\ { "nop-fun-dllimport",	  MASK_NOP_FUN_DLLIMPORT,		\   N_("Ignore dllimport for functions") },			\ { "no-nop-fun-dllimport", -MASK_NOP_FUN_DLLIMPORT, "" },	\ { "threads",		  0, N_("Use Mingw-specific thread support") },
end_define

begin_define
define|#
directive|define
name|MAYBE_UWIN_CPP_BUILTINS
parameter_list|()
end_define

begin_comment
comment|/* Nothing.  */
end_comment

begin_comment
comment|/* Support the __declspec keyword by turning them into attributes.    We currently only support: dllimport and dllexport.    Note that the current way we do this may result in a collision with    predefined attributes later on.  This can be solved by using one attribute,    say __declspec__, and passing args to it.  The problem with that approach    is that args are not accumulated: each new appearance would clobber any    existing args.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do									\     {									\ 	builtin_define ("_X86_=1");					\ 	builtin_assert ("system=winnt");				\ 	builtin_define ("__stdcall=__attribute__((__stdcall__))");	\ 	builtin_define ("__fastcall=__attribute__((__fastcall__))");	\ 	builtin_define ("__cdecl=__attribute__((__cdecl__))");		\ 	builtin_define ("__declspec(x)=__attribute__((x))");		\ 	if (!flag_iso)							\ 	  {								\ 	    builtin_define ("_stdcall=__attribute__((__stdcall__))");	\ 	    builtin_define ("_fastcall=__attribute__((__fastcall__))");	\ 	    builtin_define ("_cdecl=__attribute__((__cdecl__))");	\ 	  }								\ 	MAYBE_UWIN_CPP_BUILTINS ();					\ 	EXTRA_OS_CPP_BUILTINS ();					\   }									\   while (0)
end_define

begin_comment
comment|/* Get tree.c to declare a target-specific specialization of    merge_decl_attributes.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GCC driver    program.     Do not define this macro if it does not need to do anything.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "mingw_include_path", DEFAULT_TARGET_MACHINE }
end_define

begin_undef
undef|#
directive|undef
name|MATH_LIBRARY
end_undef

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_escape
end_escape

begin_comment
comment|/* Enable parsing of #pragma pack(push,<n>) and #pragma pack(pop).  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_PRAGMA_PACK_PUSH_POP
value|1
end_define

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_define
define|#
directive|define
name|TREE
value|union tree_node *
end_define

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_drectve
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
value|DRECTVE_SECTION_FUNCTION					\   SWITCH_TO_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|DRECTVE_SECTION_FUNCTION
define|\
value|void									\ drectve_section (void)							\ {									\   if (in_section != in_drectve)						\     {									\       fprintf (asm_out_file, "%s\n", "\t.section .drectve\n");		\       in_section = in_drectve;						\     }									\ }
end_define

begin_function_decl
name|void
name|drectve_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Older versions of gas don't handle 'r' as data.    Explicitly set data flag with 'd'.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.section .rdata,\"dr\""
end_define

begin_comment
comment|/* Switch to SECTION (an `enum in_section').     ??? This facility should be provided by GCC proper.    The problem is that we want to temporarily switch sections in    ASM_DECLARE_OBJECT_NAME and then switch back to the original section    afterwards.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TO_SECTION_FUNCTION
define|\
value|void switch_to_section (enum in_section, tree);			\ void								\ switch_to_section (enum in_section section, tree decl)		\ {								\   switch (section)						\     {								\       case in_text: text_section (); break;			\       case in_data: data_section (); break;			\       case in_readonly_data: readonly_data_section (); break;	\       case in_named: named_section (decl, NULL, 0); break;	\       case in_drectve: drectve_section (); break;		\       default: abort (); break;				\     }								\ }
end_define

begin_comment
comment|/* Don't allow flag_pic to propagate since gas may produce invalid code    otherwise.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|do {									\   if (flag_pic)								\     {									\       warning ("-f%s ignored for target (all code is position independent)",\ 	       (flag_pic> 1) ? "PIC" : "pic");				\       flag_pic = 0;							\     }									\ } while (0)
end_define

begin_comment
unit|\
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386 running Windows NT, modify the assembler name with a suffix    consisting of an atsign (@) followed by string of digits that represents    the number of bytes of arguments passed to the function, if it has the    attribute STDCALL.     In addition, we must mark dll symbols specially. Definitions of    dllexport'd objects install some info in the .drectve section.    References to dllimport'd objects are fetched indirectly via    _imp__.  If both are declared, dllexport overrides.  This is also    needed to implement one-only vtables: they go into their own    section and we need to set DECL_SECTION_NAME so we do that here.    Note that we can be called twice on the same decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|TARGET_ENCODE_SECTION_INFO
value|i386_pe_encode_section_info
end_define

begin_undef
undef|#
directive|undef
name|TARGET_STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|TARGET_STRIP_NAME_ENCODING
value|i386_pe_strip_name_encoding_full
end_define

begin_escape
end_escape

begin_comment
comment|/* Output a reference to a label.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
value|i386_pe_output_labelref
end_define

begin_comment
comment|/* Output a common block.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME, 1);		\   if (! i386_pe_dllimport_name_p (NAME))		\     {							\       fprintf ((STREAM), "\t.comm\t");			\       assemble_name ((STREAM), (NAME));			\       fprintf ((STREAM), ", %d\t%s %d\n",		\ 	       (int)(ROUNDED), ASM_COMMENT_START, (int)(SIZE));	\     }							\ } while (0)
end_define

begin_comment
comment|/* Output the label for an initialized variable.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME, 1);		\   ASM_OUTPUT_LABEL ((STREAM), (NAME));			\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Emit code to check the stack when allocating more that 4000    bytes in one go.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_STACK_LIMIT
value|4000
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    returns float values in the 387 and needs stack probes.    We also align doubles to 64-bits for MSVC default compatibility.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_STACK_PROBE \     | MASK_ALIGN_DOUBLE)
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", 1<<(LOG))
end_define

begin_comment
comment|/* Define this macro if in some cases global symbols from one translation    unit may not be bound to undefined symbols in another translation unit    without user intervention.  For instance, under Microsoft Windows    symbols must be explicitly imported from shared libraries (DLLs).  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
end_define

begin_function_decl
specifier|extern
name|void
name|i386_pe_unique_section
parameter_list|(
name|TREE
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_ASM_UNIQUE_SECTION
value|i386_pe_unique_section
end_define

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|i386_pe_asm_named_section
end_define

begin_comment
comment|/* Select attributes for named sections.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SECTION_TYPE_FLAGS
value|i386_pe_section_type_flags
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare a function    properly.  If we are generating SDB debugging information, this    will happen automatically, so we only need to handle other cases.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_FUNCTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do									\     {									\       if (i386_pe_dllexport_name_p (NAME))				\ 	i386_pe_record_exported_symbol (NAME, 0);			\       if (write_symbols != SDB_DEBUG)					\ 	i386_pe_declare_function_type (FILE, NAME, TREE_PUBLIC (DECL));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\     }									\   while (0)
end_define

begin_comment
comment|/* Add an external function to the list of functions to be declared at    the end of the file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do									\     {									\       if (TREE_CODE (DECL) == FUNCTION_DECL)				\ 	i386_pe_record_external_function (NAME);			\     }									\   while (0)
end_define

begin_comment
comment|/* Declare the type properly for any external libcall.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|i386_pe_declare_function_type (FILE, XSTR (FUN, 0), 1)
end_define

begin_comment
comment|/* This says out to put a global symbol in the BSS section.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss ((FILE), (DECL), (NAME), (SIZE), (ALIGN))
end_define

begin_comment
comment|/* Output function declarations at the end of the file.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|i386_pe_file_end
end_define

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_comment
comment|/* DWARF2 Unwinding doesn't work with exception handling yet.  To make    it work, we need to build a libgcc_s.dll, and dcrt0.o should be    changed to call __register_frame_info/__deregister_frame_info.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_undef
undef|#
directive|undef
name|PROFILE_HOOK
end_undef

begin_define
define|#
directive|define
name|PROFILE_HOOK
parameter_list|(
name|LABEL
parameter_list|)
define|\
value|if (MAIN_NAME_P (DECL_NAME (current_function_decl)))			\     {									\       emit_call_insn (gen_rtx (CALL, VOIDmode,				\ 	gen_rtx_MEM (FUNCTION_MODE,					\ 		     gen_rtx_SYMBOL_REF (Pmode, "_monstartup")),	\ 	const0_rtx));							\     }
end_define

begin_comment
comment|/* Java Native Interface (JNI) methods on Win32 are invoked using the    stdcall calling convention.  */
end_comment

begin_undef
undef|#
directive|undef
name|MODIFY_JNI_METHOD_CALL
end_undef

begin_define
define|#
directive|define
name|MODIFY_JNI_METHOD_CALL
parameter_list|(
name|MDECL
parameter_list|)
define|\
value|build_type_attribute_variant ((MDECL),				      \ 			       build_tree_list (get_identifier ("stdcall"),   \ 						NULL))
end_define

begin_comment
comment|/* External function declarations.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_pe_record_external_function
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i386_pe_declare_function_type
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i386_pe_record_exported_symbol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|i386_pe_file_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_pe_dllexport_name_p
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|i386_pe_dllimport_name_p
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For Win32 ABI compatibility */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* MSVC returns aggregate types of up to 8 bytes via registers.    See i386.c:ix86_return_in_memory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MS_AGGREGATE_RETURN
end_undef

begin_define
define|#
directive|define
name|MS_AGGREGATE_RETURN
value|1
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|128
end_define

begin_comment
comment|/* Native complier aligns internal doubles in structures on dword boundaries.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_FIELD_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|64
end_define

begin_comment
comment|/* A bit-field declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_define
define|#
directive|define
name|GROUP_BITFIELDS_BY_ALIGN
value|TYPE_NATIVE(rec)
end_define

begin_comment
comment|/* Enable alias attribute support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_ASM_OP
end_ifndef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|"\t.set\t"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This implements the `alias' attribute, keeping any stdcall or    fastcall decoration.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DEF_FROM_DECLS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF_FROM_DECLS
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|TARGET
parameter_list|)
define|\
value|do									\     {									\       const char *alias;						\       rtx rtlname = XEXP (DECL_RTL (DECL), 0);				\       if (GET_CODE (rtlname) == SYMBOL_REF)				\ 	alias = XSTR (rtlname, 0);					\       else								\ 	abort ();							\       if (TREE_CODE (DECL) == FUNCTION_DECL)				\ 	i386_pe_declare_function_type (STREAM, alias,			\ 				       TREE_PUBLIC (DECL));		\       ASM_OUTPUT_DEF (STREAM, alias, IDENTIFIER_POINTER (TARGET));	\     } while (0)
end_define

begin_undef
undef|#
directive|undef
name|TREE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_undef
undef|#
directive|undef
name|FILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

