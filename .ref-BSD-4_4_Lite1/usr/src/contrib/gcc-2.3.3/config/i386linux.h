begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Linux  * Copyright (C) 1992 Free Software Foundation, Inc.  *  * Written by H.J. Lu (hlu@eecs.wsu.edu)  *  * Linux is a POSIX.1 compatible UNIX clone for i386, which uses GNU  * stuffs as the native stuffs.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* The FSF has fixed the known bugs. But ....... */
end_comment

begin_comment
comment|/* Linux has a hacked gas 1.38.1, which can handle repz, repnz  * and fildll.  */
end_comment

begin_define
define|#
directive|define
name|GOOD_GAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is tested by i386gas.h.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386gstabs.h"
end_include

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -Dlinux"
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Linux uses ctype from glibc.a. I am not sure how complete it is.  * For now, we play safe. It may change later.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_undef
undef|#
directive|undef
name|MULTIBYTE_CHARS
end_undef

begin_define
define|#
directive|define
name|MULTIBYTE_CHARS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g*:-lg} %{!g*:%{!p:%{!pg:-lc}}%{p:-lgmon -lc_p}%{pg:-lgmon -lc_p}}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_comment
comment|/*  * For cross-compile, we just need to search `$(tooldir)/lib'  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{g*:crt0.o%s -static} %{!g*:%{pg:gcrt0.o%s -static} %{!pg:%{p:gcrt0.o%s -static} %{!p:crt0.o%s %{!static:%{nojump:-nojump}} %{static:-static}}}} -L"TOOLDIR"/lib"
end_define

begin_comment
comment|/*  *The cross-compile uses this.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|TOOLDIR"/g++-include"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{g*:crt0.o%s -static} %{!g*:%{pg:gcrt0.o%s -static} %{!pg:%{p:gcrt0.o%s -static} %{!p:crt0.o%s %{!static:%{nojump:-nojump}} %{static:-static}}}}"
end_define

begin_comment
comment|/*  *The native Linux system uses this.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/g++-include"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

