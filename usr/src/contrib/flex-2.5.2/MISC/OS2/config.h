begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ------------------------------------------------ */
end_comment

begin_comment
comment|/* version of config.h for OS/2                     */
end_comment

begin_comment
comment|/* ------------------------------------------------ */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_undef
undef|#
directive|undef
name|size_t
end_undef

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLOC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA_H
end_define

begin_comment
comment|/* Define if platform-specific command line handling is necessary.  */
end_comment

begin_define
define|#
directive|define
name|NEED_ARGV_FIXUP
end_define

begin_define
define|#
directive|define
name|argv_fixup
parameter_list|(
name|ac
parameter_list|,
name|av
parameter_list|)
value|{ _response(ac,av); _wildcard(ac,av);}
end_define

end_unit

