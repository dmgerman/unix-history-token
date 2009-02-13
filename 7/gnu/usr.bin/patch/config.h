begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* Portability variables.  -*- C -*- */
end_comment

begin_comment
comment|/* Define if the system does not support the `const' keyword.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define if the system supports file names longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
end_define

begin_comment
comment|/* Define if the system has pathconf().  */
end_comment

begin_comment
comment|/* #undef HAVE_PATHCONF */
end_comment

begin_comment
comment|/* Define if the system has strerror().  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if the system has ANSI C header files and library functions.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
end_define

begin_comment
comment|/* Define if the system uses strchr instead of index    and strrchr instead of rindex.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if the system has unistd.h.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if the system has fcntl.h.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define as either int or void -- the type that signal handlers return.  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  Which directory library header to use.  */
end_comment

begin_define
define|#
directive|define
name|DIRENT
value|1
end_define

begin_comment
comment|/* dirent.h */
end_comment

begin_comment
comment|/* #undef SYSNDIR */
end_comment

begin_comment
comment|/* sys/ndir.h */
end_comment

begin_comment
comment|/* #undef SYSDIR */
end_comment

begin_comment
comment|/* sys/dir.h */
end_comment

begin_comment
comment|/* #undef NDIR */
end_comment

begin_comment
comment|/* ndir.h */
end_comment

begin_comment
comment|/* #undef NODIR */
end_comment

begin_comment
comment|/* none -- don't make numbered backup files */
end_comment

begin_comment
comment|/* Define if the system lets you pass fewer arguments to a function    than the function actually accepts (in the absence of a prototype).    Defining it makes I/O calls slightly more efficient.    You need not bother defining it unless your C preprocessor chokes on    multi-line arguments to macros.  */
end_comment

begin_comment
comment|/* #undef CANVARARG */
end_comment

begin_comment
comment|/* Define Reg* as either `register' or nothing, depending on whether    the C compiler pays attention to this many register declarations.    The intent is that you don't have to order your register declarations    in the order of importance, so you can freely declare register variables    in sub-blocks of code and as function parameters.    Do not use Reg<n> more than once per routine.     These don't really matter a lot, since most modern C compilers ignore    register declarations and often do a better job of allocating    registers than people do.  */
end_comment

begin_define
define|#
directive|define
name|Reg1
value|register
end_define

begin_define
define|#
directive|define
name|Reg2
value|register
end_define

begin_define
define|#
directive|define
name|Reg3
value|register
end_define

begin_define
define|#
directive|define
name|Reg4
value|register
end_define

begin_define
define|#
directive|define
name|Reg5
value|register
end_define

begin_define
define|#
directive|define
name|Reg6
value|register
end_define

begin_define
define|#
directive|define
name|Reg7
end_define

begin_define
define|#
directive|define
name|Reg8
end_define

begin_define
define|#
directive|define
name|Reg9
end_define

begin_define
define|#
directive|define
name|Reg10
end_define

begin_define
define|#
directive|define
name|Reg11
end_define

begin_define
define|#
directive|define
name|Reg12
end_define

begin_define
define|#
directive|define
name|Reg13
end_define

begin_define
define|#
directive|define
name|Reg14
end_define

begin_define
define|#
directive|define
name|Reg15
end_define

begin_define
define|#
directive|define
name|Reg16
end_define

end_unit

