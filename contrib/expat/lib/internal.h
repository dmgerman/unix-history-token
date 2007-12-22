begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* internal.h     Internal definitions used by Expat.  This is not needed to compile    client code.     The following definitions are made:     FASTCALL -- Used for most internal functions to specify that the                fastest possible calling convention be used.     inline   -- Used for selected internal functions for which inlining                may improve performance on some platforms. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|/* Last minute instability reported with egcs on a RedHat Linux 7.3    box; argh! */
end_comment

begin_comment
comment|/* #define FASTCALL __attribute__((stdcall, regparm(3))) */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
end_elif

begin_comment
comment|/* XXX This seems to have an unexpected negative effect on Windows so    we'll disable it for now on that platform.  It may be reconsidered    for a future release if it can be made more effective. */
end_comment

begin_comment
comment|/* #define FASTCALL __fastcall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FASTCALL
end_ifndef

begin_define
define|#
directive|define
name|FASTCALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XML_MIN_SIZE
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|inline
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XML_MIN_SIZE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|inline
value|inline
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

