begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: ncurses_dll.h,v 1.2 2001/12/09 01:36:34 tom Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_DLL_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_DLL_H_incl
value|1
end_define

begin_undef
undef|#
directive|undef
name|NCURSES_DLL
end_undef

begin_comment
comment|/* cygwin dll not implemented */
end_comment

begin_define
define|#
directive|define
name|NCURSES_STATIC
end_define

begin_comment
comment|/* cygwin dll not implemented */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_DLL
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_STATIC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NCURSES_STATIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NCURSES_IMPEXP
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_API
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_EXPORT
name|(
name|type
name|)
end_undef

begin_undef
undef|#
directive|undef
name|NCURSES_EXPORT_VAR
name|(
name|type
name|)
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NCURSES_DLL
argument_list|)
end_if

begin_comment
comment|/* building a DLL */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
value|__declspec(dllexport)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|NCURSES_STATIC
argument_list|)
end_elif

begin_comment
comment|/* building or linking to a static library */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
end_define

begin_comment
comment|/* nothing */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* linking to the DLL */
end_comment

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCURSES_API
value|__cdecl
end_define

begin_define
define|#
directive|define
name|NCURSES_EXPORT
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type NCURSES_API
end_define

begin_define
define|#
directive|define
name|NCURSES_EXPORT_VAR
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Take care of non-cygwin platforms */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_IMPEXP
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_IMPEXP
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_API
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_API
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_EXPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_EXPORT
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type NCURSES_API
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NCURSES_EXPORT_VAR
argument_list|)
end_if

begin_define
define|#
directive|define
name|NCURSES_EXPORT_VAR
parameter_list|(
name|type
parameter_list|)
value|NCURSES_IMPEXP type
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCURSES_DLL_H_incl */
end_comment

end_unit

