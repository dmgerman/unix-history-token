begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* You may need to adjust the definition of signal1 to supply a */
end_comment

begin_comment
comment|/* cast to the correct argument type.  This detail is system- and */
end_comment

begin_comment
comment|/* compiler-dependent.   The #define below assumes signal.h declares */
end_comment

begin_comment
comment|/* type SIG_PF for the signal function's second argument. */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|Sigret_t
end_ifndef

begin_define
define|#
directive|define
name|Sigret_t
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Sigarg_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_define
define|#
directive|define
name|Sigarg_t
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Sigarg_t
value|int
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
comment|/*Sigarg_t*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SIG_PF
end_ifdef

begin_comment
comment|/* compile with -DUSE_SIG_PF under IRIX */
end_comment

begin_define
define|#
directive|define
name|sig_pf
value|SIG_PF
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|Sigret_t
function_decl|(
modifier|*
name|sig_pf
function_decl|)
parameter_list|(
name|Sigarg_t
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|signal1
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|signal(a,(sig_pf)b)
end_define

end_unit

