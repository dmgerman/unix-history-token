begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vms-conf.h.  Generated manually from conf.in,    and used by config-gas.com when constructing config.h.  */
end_comment

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_undef
undef|#
directive|undef
name|C_ALLOCA
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|C_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|CRAY_STACKSEG_END
end_undef

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA_H
end_undef

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_define
define|#
directive|define
name|STACK_DIRECTION
value|(-1)
end_define

begin_comment
comment|/* Define if lex declares yytext as a char * by default, not a char[].  */
end_comment

begin_undef
undef|#
directive|undef
name|YYTEXT_POINTER
end_undef

begin_comment
comment|/* Name of package.  */
end_comment

begin_undef
undef|#
directive|undef
name|PACKAGE
end_undef

begin_comment
comment|/* Version of package.  */
end_comment

begin_comment
comment|/* Define in by config-gas.com */
end_comment

begin_comment
comment|/* #undef VERSION */
end_comment

begin_comment
comment|/* Should gas use high-level BFD interfaces?  */
end_comment

begin_undef
undef|#
directive|undef
name|BFD_ASSEMBLER
end_undef

begin_comment
comment|/* Some assert/preprocessor combinations are incapable of handling    certain kinds of constructs in the argument of assert.  For example,    quoted strings (if requoting isn't done right) or newlines.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_undef
undef|#
directive|undef
name|BROKEN_ASSERT
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BROKEN_ASSERT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we aren't doing cross-assembling, some operations can be optimized,    since byte orders and value sizes don't need to be adjusted.  */
end_comment

begin_undef
undef|#
directive|undef
name|CROSS_COMPILE
end_undef

begin_comment
comment|/* Some gas code wants to know these parameters.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ALIAS
value|"vms"
end_define

begin_define
define|#
directive|define
name|TARGET_CPU
value|"vax"
end_define

begin_define
define|#
directive|define
name|TARGET_CANONICAL
value|"vax-dec-vms"
end_define

begin_define
define|#
directive|define
name|TARGET_OS
value|"vms"
end_define

begin_define
define|#
directive|define
name|TARGET_VENDOR
value|"dec"
end_define

begin_comment
comment|/* Sometimes the system header files don't declare strstr.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_STRSTR
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare malloc and realloc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_MALLOC
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare free.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_FREE
end_undef

begin_comment
comment|/* Sometimes the system header files don't declare sbrk.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_SBRK
end_undef

begin_comment
comment|/* Sometimes errno.h doesn't declare errno itself.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_DECLARATION_ERRNO
end_undef

begin_undef
undef|#
directive|undef
name|MANY_SEGMENTS
end_undef

begin_comment
comment|/* The configure script defines this for some targets based on the    target name used.  It is not always defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_BYTES_BIG_ENDIAN
end_undef

begin_comment
comment|/* Needed only for some configurations that can produce multiple output    formats.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_EMULATION
end_undef

begin_undef
undef|#
directive|undef
name|EMULATIONS
end_undef

begin_undef
undef|#
directive|undef
name|USE_EMULATIONS
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_AOUT
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_BOUT
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_COFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_ECOFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_ELF
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_GENERIC
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_HP300
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_IEEE
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_SOM
end_undef

begin_undef
undef|#
directive|undef
name|OBJ_MAYBE_VMS
end_undef

begin_comment
comment|/* Used for some of the COFF configurations, when the COFF code needs    to select something based on the CPU type before it knows it...  */
end_comment

begin_undef
undef|#
directive|undef
name|I386COFF
end_undef

begin_undef
undef|#
directive|undef
name|M68KCOFF
end_undef

begin_undef
undef|#
directive|undef
name|M88KCOFF
end_undef

begin_comment
comment|/* Using cgen code?  */
end_comment

begin_undef
undef|#
directive|undef
name|USING_CGEN
end_undef

begin_comment
comment|/* Needed only for sparc configuration.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_ARCH
end_undef

begin_comment
comment|/* Needed only for PowerPC Solaris.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SOLARIS_COMMENT
end_undef

begin_comment
comment|/* Needed only for SCO 5.  */
end_comment

begin_undef
undef|#
directive|undef
name|SCO_ELF
end_undef

begin_comment
comment|/* Define if you have the remove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REMOVE
end_define

begin_comment
comment|/* Define if you have the sbrk function.  */
end_comment

begin_comment
comment|/* sbrk() is available, but we don't want gas to use it.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SBRK
end_undef

begin_comment
comment|/* Define if you have the unlink function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UNLINK
end_undef

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
end_define

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MEMORY_H
end_undef

begin_comment
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRINGS_H
end_undef

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_SYS_TYPES_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
end_define

begin_comment
comment|/* config-gas.com will make one if necessary */
end_comment

begin_comment
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_VARARGS_H
end_undef

begin_comment
comment|/* VMS-specific:  we need to set up EXIT_xxx here because the default    values in as.h are inappropriate for VMS, but we also want to prevent    as.h's inclusion of<stdlib.h> from triggering redefinition warnings.<stdlib.h> guards itself against multiple inclusion, so including it    here turns as.h's later #include into a no-op.  (We can't simply use    #ifndef HAVE_STDLIB_H here, because the<stdlib.h> in several older    gcc-vms distributions neglects to define these two required macros.)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_undef
undef|#
directive|undef
name|EXIT_SUCCESS
end_undef

begin_undef
undef|#
directive|undef
name|EXIT_FAILURE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|1
end_define

begin_comment
comment|/* SS$_NORMAL, STS$K_SUCCESS */
end_comment

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|0x10000002
end_define

begin_comment
comment|/* (STS$K_ERROR | STS$M_INHIB_MSG) */
end_comment

end_unit

