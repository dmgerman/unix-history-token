begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    EXTERN.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/*  * EXT  designates a global var which is defined in perl.h  * dEXT designates a global var which is defined in another  *      file, so we can't count on finding it in perl.h  *      (this practice should be avoided).  */
end_comment

begin_undef
undef|#
directive|undef
name|EXT
end_undef

begin_undef
undef|#
directive|undef
name|dEXT
end_undef

begin_undef
undef|#
directive|undef
name|EXTCONST
end_undef

begin_undef
undef|#
directive|undef
name|dEXTCONST
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|/* Suppress portability warnings from DECC for VMS-specific extensions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__DECC
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|message
name|disable
name|(
name|GLOBALEXT
name|,
name|NOSHAREEXT
name|,
name|READONLYEXT
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXT
value|globalref
end_define

begin_define
define|#
directive|define
name|dEXT
value|globaldef {"$GLOBAL_RW_VARS"} noshare
end_define

begin_define
define|#
directive|define
name|EXTCONST
value|globalref
end_define

begin_define
define|#
directive|define
name|dEXTCONST
value|globaldef {"$GLOBAL_RO_VARS"} readonly
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_STATIC_SYMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PERLDLL
end_ifdef

begin_define
define|#
directive|define
name|EXT
value|extern __declspec(dllexport)
end_define

begin_define
define|#
directive|define
name|dEXT
end_define

begin_define
define|#
directive|define
name|EXTCONST
value|extern __declspec(dllexport) const
end_define

begin_define
define|#
directive|define
name|dEXTCONST
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT
value|extern __declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|dEXT
end_define

begin_define
define|#
directive|define
name|EXTCONST
value|extern __declspec(dllimport) const
end_define

begin_define
define|#
directive|define
name|dEXTCONST
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
name|defined
argument_list|(
name|USEIMPORTLIB
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT
value|extern __declspec(dllimport)
end_define

begin_define
define|#
directive|define
name|dEXT
end_define

begin_define
define|#
directive|define
name|EXTCONST
value|extern __declspec(dllimport) const
end_define

begin_define
define|#
directive|define
name|dEXTCONST
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT
value|extern
end_define

begin_define
define|#
directive|define
name|dEXT
end_define

begin_define
define|#
directive|define
name|EXTCONST
value|extern const
end_define

begin_define
define|#
directive|define
name|dEXTCONST
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|INIT
end_undef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|DOINIT
end_undef

end_unit

