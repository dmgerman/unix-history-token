begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows NT 3.x, using a Unix style C library and tools,    as distinct from winnt.h, which is used to build GCC for use with a    windows style library and tool set and uses the Microsoft tools.    Copyright (C) 1995, 1996, 1997, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_include
include|#
directive|include
file|"dbxcoff.h"
end_include

begin_comment
comment|/* Augment TARGET_SWITCHES with the cygwin/no-cygwin options. */
end_comment

begin_define
define|#
directive|define
name|MASK_WIN32
value|0x40000000
end_define

begin_comment
comment|/* Use -lming32 interface */
end_comment

begin_define
define|#
directive|define
name|MASK_CYGWIN
value|0x20000000
end_define

begin_comment
comment|/* Use -lcygwin interface */
end_comment

begin_define
define|#
directive|define
name|MASK_WINDOWS
value|0x10000000
end_define

begin_comment
comment|/* Use windows interface */
end_comment

begin_define
define|#
directive|define
name|MASK_DLL
value|0x08000000
end_define

begin_comment
comment|/* Use dll interface    */
end_comment

begin_define
define|#
directive|define
name|MASK_NOP_FUN_DLLIMPORT
value|0x20000
end_define

begin_comment
comment|/* Ignore dllimport for functions */
end_comment

begin_define
define|#
directive|define
name|TARGET_WIN32
value|(target_flags& MASK_WIN32)
end_define

begin_define
define|#
directive|define
name|TARGET_CYGWIN
value|(target_flags& MASK_CYGWIN)
end_define

begin_define
define|#
directive|define
name|TARGET_WINDOWS
value|(target_flags& MASK_WINDOWS)
end_define

begin_define
define|#
directive|define
name|TARGET_DLL
value|(target_flags& MASK_DLL)
end_define

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
value|{ "cygwin",		  MASK_CYGWIN, "Use the Cygwin interface" },  \ { "no-cygwin",		  MASK_WIN32, "Use the Mingw32 interface" }, \ { "windows",		  MASK_WINDOWS, "Create GUI application" }, \ { "console",		  -MASK_WINDOWS, "Create console application" }, \ { "dll",		  MASK_DLL, "Generate code for a DLL" },     \ { "nop-fun-dllimport",	  MASK_NOP_FUN_DLLIMPORT, "Ignore dllimport for functions" }, \ { "no-nop-fun-dllimport", -MASK_NOP_FUN_DLLIMPORT, "" },
end_define

begin_comment
comment|/* Support the __declspec keyword by turning them into attributes.    We currently only support: dllimport and dllexport.    Note that the current way we do this may result in a collision with    predefined attributes later on.  This can be solved by using one attribute,    say __declspec__, and passing args to it.  The problem with that approach    is that args are not accumulated: each new appearance would clobber any    existing args.  */
end_comment

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
value|"-Di386 -D_WIN32 \   -DWINNT  -D_X86_=1 -D__STDC__=1\   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   -D__declspec(x)=__attribute__((x)) \   -Asystem(winnt) -Acpu(i386) -Amachine(i386)"
end_define

begin_comment
comment|/* Normally, -lgcc is not needed since everything in it is in the DLL, but we    want to allow things to be added to it when installing new versions of    GCC without making a new CYGWIN.DLL, so we leave it.  Profiling is handled    by calling the init function from the prologue. */
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
value|"%{mdll: %{mno-cygwin:dllcrt1%O%s}} \                         %{!mdll: %{!mno-cygwin:crt0%O%s} \                                  %{mno-cygwin:crt1%O%s} %{pg:gcrt0%O%s}}"
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
value|"-remap %(cpp_cpu) %{posix:-D_POSIX_SOURCE} \   %{!mno-cygwin:-D__CYGWIN32__ -D__CYGWIN__} \   %{mno-cygwin:-iwithprefixbefore \     ../../../../%(mingw_include_path)/include/mingw32 -D__MINGW32__=0.2}"
end_define

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.     Each subgrouping contains a string constant, that defines the    specification name, and a string constant that used by the GNU CC driver    program.     Do not define this macro if it does not need to do anything.  */
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

begin_comment
comment|/* We have to dynamic link to get to the system DLLs.  All of libc, libm and    the Unix stuff is in cygwin.dll.  The import library is called    'libcygwin.a'.  For Windows applications, include more libraries, but    always include kernel32.  We'd like to specific subsystem windows to    ld, but that doesn't work just yet.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-lgmon} \                   %{!mno-cygwin:-lcygwin} \                   %{mno-cygwin:-lmingw32 -lmoldname -lcrtdll} \                   %{mwindows:-lgdi32 -lcomdlg32} \ 		  -luser32 -lkernel32 -ladvapi32 -lshell32"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{mwindows:--subsystem windows} \                    %{mconsole:--subsystem console} \                    %{mdll:--dll -e _DllMainCRTStartup@12}"
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
name|WCHAR_UNSIGNED
value|1
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

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
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

begin_comment
comment|/* A C expression whose value is nonzero if IDENTIFIER with arguments ARGS    is a valid machine specific attribute for DECL.    The attributes in ATTRIBUTES have previously been assigned to DECL.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|i386_pe_valid_decl_attribute_p
parameter_list|()
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|VALID_MACHINE_DECL_ATTRIBUTE
end_undef

begin_define
define|#
directive|define
name|VALID_MACHINE_DECL_ATTRIBUTE
parameter_list|(
name|DECL
parameter_list|,
name|ATTRIBUTES
parameter_list|,
name|IDENTIFIER
parameter_list|,
name|ARGS
parameter_list|)
define|\
value|i386_pe_valid_decl_attribute_p (DECL, ATTRIBUTES, IDENTIFIER, ARGS)
end_define

begin_comment
comment|/* A C expression whose value is nonzero if IDENTIFIER with arguments ARGS    is a valid machine specific attribute for TYPE.    The attributes in ATTRIBUTES have previously been assigned to TYPE.  */
end_comment

begin_undef
undef|#
directive|undef
name|VALID_MACHINE_TYPE_ATTRIBUTE
end_undef

begin_define
define|#
directive|define
name|VALID_MACHINE_TYPE_ATTRIBUTE
parameter_list|(
name|TYPE
parameter_list|,
name|ATTRIBUTES
parameter_list|,
name|IDENTIFIER
parameter_list|,
name|ARGS
parameter_list|)
define|\
value|i386_pe_valid_type_attribute_p (TYPE, ATTRIBUTES, IDENTIFIER, ARGS)
end_define

begin_function_decl
specifier|extern
name|int
name|i386_pe_valid_type_attribute_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|union
name|tree_node
modifier|*
name|i386_pe_merge_decl_attributes
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MERGE_MACHINE_DECL_ATTRIBUTES
parameter_list|(
name|OLD
parameter_list|,
name|NEW
parameter_list|)
define|\
value|i386_pe_merge_decl_attributes ((OLD), (NEW))
end_define

begin_comment
comment|/* Used to implement dllexport overriding dllimport semantics.  It's also used    to handle vtables - the first pass won't do anything because    DECL_CONTEXT (DECL) will be 0 so i386_pe_dll{ex,im}port_p will return 0.    It's also used to handle dllimport override semantics.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|REDO_SECTION_INFO_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|((DECL_MACHINE_ATTRIBUTES (DECL) != NULL_TREE) \    || (TREE_CODE (DECL) == VAR_DECL&& DECL_VIRTUAL_P (DECL)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REDO_SECTION_INFO_P
parameter_list|(
name|DECL
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|in_ctor, in_dtor, in_drectve
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
value|CTOR_SECTION_FUNCTION						\   DTOR_SECTION_FUNCTION						\   DRECTVE_SECTION_FUNCTION					\   SWITCH_TO_SECTION_FUNCTION
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
name|DRECTVE_SECTION_FUNCTION
define|\
value|void									\ drectve_section ()							\ {									\   if (in_section != in_drectve)						\     {									\       fprintf (asm_out_file, "%s\n", "\t.section .drectve\n");		\       in_section = in_drectve;						\     }									\ }
end_define

begin_comment
comment|/* Switch to SECTION (an `enum in_section').     ??? This facility should be provided by GCC proper.    The problem is that we want to temporarily switch sections in    ASM_DECLARE_OBJECT_NAME and then switch back to the original section    afterwards.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TO_SECTION_FUNCTION
define|\
value|void 								\ switch_to_section (section, decl) 				\      enum in_section section; 					\      tree decl; 						\ { 								\   switch (section) 						\     { 								\       case in_text: text_section (); break; 			\       case in_data: data_section (); break; 			\       case in_named: named_section (decl, NULL, 0); break; 	\       case in_ctor: ctor_section (); break; 			\       case in_dtor: dtor_section (); break; 			\       case in_drectve: drectve_section (); break; 		\       default: abort (); break; 				\     } 								\ }
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
value|do {						\     dtor_section ();                   		\     fprintf (FILE, "%s\t", ASM_LONG);		\     assemble_name (FILE, NAME);			\     fprintf (FILE, "\n");			\   } while (0)
end_define

begin_comment
comment|/* Don't allow flag_pic to propagate since gas may produce invalid code    otherwise. */
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
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     On i386 running Windows NT, modify the assembler name with a suffix     consisting of an atsign (@) followed by string of digits that represents    the number of bytes of arguments passed to the function, if it has the     attribute STDCALL.     In addition, we must mark dll symbols specially. Definitions of     dllexport'd objects install some info in the .drectve section.      References to dllimport'd objects are fetched indirectly via    _imp__.  If both are declared, dllexport overrides.  This is also     needed to implement one-only vtables: they go into their own    section and we need to set DECL_SECTION_NAME so we do that here.    Note that we can be called twice on the same decl.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i386_pe_encode_section_info
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENCODE_SECTION_INFO
end_ifdef

begin_undef
undef|#
directive|undef
name|ENCODE_SECTION_INFO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
value|i386_pe_encode_section_info (DECL)
end_define

begin_comment
comment|/* Utility used only in this file.  */
end_comment

begin_define
define|#
directive|define
name|I386_PE_STRIP_ENCODING
parameter_list|(
name|SYM_NAME
parameter_list|)
define|\
value|((SYM_NAME) + ((SYM_NAME)[0] == '@' ? 3 : 0))
end_define

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    trailing @[NUM] encoded by ENCODE_SECTION_INFO.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|do {									\   char *_p;								\   char *_name = I386_PE_STRIP_ENCODING (SYMBOL_NAME);			\   for (_p = _name; *_p&& *_p != '@'; ++_p)				\     ;									\   if (*_p == '@')							\     {									\       int _len = _p - _name;						\       (VAR) = (char *) alloca (_len + 1);				\       strncpy ((VAR), _name, _len);					\       (VAR)[_len] = '\0';						\     }									\   else									\     (VAR) = _name;							\ } while (0)
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
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (STREAM, "%s%s", USER_LABEL_PREFIX, 		\            I386_PE_STRIP_ENCODING (NAME))
end_define

begin_comment
unit|\
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
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME);		\   if (! i386_pe_dllimport_name_p (NAME))		\     {							\       fprintf ((STREAM), "\t.comm\t"); 			\       assemble_name ((STREAM), (NAME));			\       fprintf ((STREAM), ", %d\t%s %d\n",		\ 	       (ROUNDED), ASM_COMMENT_START, (SIZE));	\     }							\ } while (0)
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
value|do {							\   if (i386_pe_dllexport_name_p (NAME))			\     i386_pe_record_exported_symbol (NAME);		\   ASM_OUTPUT_LABEL ((STREAM), (NAME));			\ } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Emit code to check the stack when allocating more that 4000    bytes in one go. */
end_comment

begin_define
define|#
directive|define
name|CHECK_STACK_LIMIT
value|4000
end_define

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387 and needs stack probes */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_STACK_PROBE)
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

begin_define
define|#
directive|define
name|UNIQUE_SECTION_P
parameter_list|(
name|DECL
parameter_list|)
value|DECL_ONE_ONLY (DECL)
end_define

begin_function_decl
specifier|extern
name|void
name|i386_pe_unique_section
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
value|i386_pe_unique_section (DECL, RELOC)
end_define

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_comment
comment|/* A C statement to output something to the assembler file to switch to section    NAME for object DECL which is either a FUNCTION_DECL, a VAR_DECL or    NULL_TREE.  Some target formats do not support arbitrary sections.  Do not    define this macro in such cases.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SECTION_NAME
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do {									\   static struct section_info						\     {									\       struct section_info *next;					\       char *name;							\       enum sect_enum {SECT_RW, SECT_RO, SECT_EXEC} type;		\     } *sections;							\   struct section_info *s;						\   char *mode;								\   enum sect_enum type;							\ 									\   for (s = sections; s; s = s->next)					\     if (!strcmp (NAME, s->name))					\       break;								\ 									\   if (DECL&& TREE_CODE (DECL) == FUNCTION_DECL)			\     type = SECT_EXEC, mode = "x";					\   else if (DECL&& DECL_READONLY_SECTION (DECL, RELOC))			\     type = SECT_RO, mode = "";						\   else									\     type = SECT_RW, mode = "w";						\ 									\   if (s == 0)								\     {									\       s = (struct section_info *) xmalloc (sizeof (struct section_info)); \       s->name = xmalloc ((strlen (NAME) + 1) * sizeof (*NAME));		\       strcpy (s->name, NAME);						\       s->type = type;							\       s->next = sections;						\       sections = s;							\       fprintf (STREAM, ".section\t%s,\"%s\"\n", NAME, mode);		\
comment|/* Functions may have been compiled at various levels of		\          optimization so we can't use `same_size' here.  Instead,	\          have the linker pick one.  */
value|\       if ((DECL)&& DECL_ONE_ONLY (DECL))				\         fprintf (STREAM, "\t.linkonce %s\n",				\ 	         TREE_CODE (DECL) == FUNCTION_DECL			\ 	         ? "discard" : "same_size");				\     }									\   else									\     {									\       fprintf (STREAM, ".section\t%s,\"%s\"\n", NAME, mode);		\     }									\ } while (0)
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
value|do									\     {									\       if (i386_pe_dllexport_name_p (NAME))				\ 	i386_pe_record_exported_symbol (NAME);				\       if (write_symbols != SDB_DEBUG)					\ 	i386_pe_declare_function_type (FILE, NAME, TREE_PUBLIC (DECL));	\       ASM_OUTPUT_LABEL (FILE, NAME);					\     }									\   while (0)
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
comment|/* Output function declarations at the end of the file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|i386_pe_asm_file_end (FILE)
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
comment|/* DWARF2 Unwinding doesn't work with exception handling yet. */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

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
name|SUBTARGET_PROLOGUE
define|\
value|if (profile_flag 							\&& strcmp (IDENTIFIER_POINTER (DECL_NAME (current_function_decl)),\ 		 "main") == 0)						\      {									\       rtx xops[1];							\       xops[0] = gen_rtx_MEM (FUNCTION_MODE,				\ 			 gen_rtx (SYMBOL_REF, Pmode, "_monstartup"));	\       if (do_rtl)							\ 	emit_call_insn (gen_rtx (CALL, VOIDmode, xops[0], const0_rtx));	\       else								\ 	output_asm_insn (AS1 (call,%P1), xops);			\      }
end_define

begin_comment
comment|/* External function declarations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_comment
comment|/* stdio.h has been included, ok to use FILE * */
end_comment

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|PROTO(ARGS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_record_external_function
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_declare_function_type
name|STDIO_PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_record_exported_symbol
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|i386_pe_asm_file_end
name|STDIO_PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* A bitfield declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELDS_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELDS_TYPE_MATTERS
value|0
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
value|"\t.set"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

