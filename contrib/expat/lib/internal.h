begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* internal.h     Internal definitions used by Expat.  This is not needed to compile    client code.     The following calling convention macros are defined for frequently    called functions:     FASTCALL    - Used for those internal functions that have a simple                  body and a low number of arguments and local variables.     PTRCALL     - Used for functions called though function pointers.     PTRFASTCALL - Like PTRCALL, but for low number of arguments.     inline      - Used for selected internal functions for which inlining                  may improve performance on some platforms.     Note: Use of these macros is based on judgement, not hard rules,          and therefore subject to change. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_comment
comment|/* We'll use this version by default only where we know it helps.     regparm() generates warnings on Solaris boxes.   See SF bug #692878.     Instability reported with egcs on a RedHat Linux 7.3.    Let's comment out:    #define FASTCALL __attribute__((stdcall, regparm(3)))    and let's try this: */
end_comment

begin_define
define|#
directive|define
name|FASTCALL
value|__attribute__((regparm(3)))
end_define

begin_define
define|#
directive|define
name|PTRFASTCALL
value|__attribute__((regparm(3)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Using __fastcall seems to have an unexpected negative effect under    MS VC++, especially for function pointers, so we won't use it for    now on that platform. It may be reconsidered for a future release    if it can be made more effective.    Likely reason: __fastcall on Windows is like stdcall, therefore    the compiler cannot perform stack optimizations for call clusters. */
end_comment

begin_comment
comment|/* Make sure all of these are defined if they aren't already. */
end_comment

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
name|PTRCALL
end_ifndef

begin_define
define|#
directive|define
name|PTRCALL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRFASTCALL
end_ifndef

begin_define
define|#
directive|define
name|PTRFASTCALL
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

