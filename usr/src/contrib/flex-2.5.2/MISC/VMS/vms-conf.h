begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h manually constructed for VMS */
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
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_MALLOC_H
end_undef

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_undef
undef|#
directive|undef
name|HAVE_SYS_TYPES_H
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA_H
end_undef

begin_comment
comment|/* Extra platform-specific command line handling.  */
end_comment

begin_define
define|#
directive|define
name|NEED_ARGV_FIXUP
end_define

begin_comment
comment|/* Override default exit behavior.  */
end_comment

begin_define
define|#
directive|define
name|exit
value|vms_exit
end_define

end_unit

