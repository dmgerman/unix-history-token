begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    util.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|PERL_FILE_IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
define|\
value|(*(f) == '/'							\ 	 || (strchr(f,':')						\ 	     || ((*(f) == '[' || *(f) == '<')				\&& (isALNUM((f)[1]) || strchr("$-_]>",(f)[1])))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|PERL_FILE_IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
define|\
value|(*(f) == '/'							\ 	 || ((f)[0]&& (f)[1] == ':')
comment|/* drive name */
value|\ 	 || ((f)[0] == '\\'&& (f)[1] == '\\'))
end_define

begin_comment
comment|/* UNC path */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !WIN32 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DOSISH
argument_list|)
operator|||
name|defined
argument_list|(
name|EPOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_FILE_IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
define|\
value|(*(f) == '/'							\ 	 || ((f)[0]&& (f)[1] == ':'))
end_define

begin_comment
comment|/* drive name */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEITHER DOSISH NOR EPOCISH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MACOS_TRADITIONAL
end_ifdef

begin_define
define|#
directive|define
name|PERL_FILE_IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
value|(strchr(f, ':')&& *(f) != ':')
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MACOS_TRADITIONAL */
end_comment

begin_define
define|#
directive|define
name|PERL_FILE_IS_ABSOLUTE
parameter_list|(
name|f
parameter_list|)
value|(*(f) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACOS_TRADITIONAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOSISH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

end_unit

