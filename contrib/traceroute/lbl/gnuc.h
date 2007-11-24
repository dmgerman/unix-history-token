begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: gnuc.h,v 1.3 95/10/09 02:47:01 leres Exp $ (LBL) */
end_comment

begin_comment
comment|/* Define __P() macro, if necessary */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
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
comment|/* inline foo */
end_comment

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Handle new and old "dead" routine prototypes  *  * For example:  *  *	__dead void foo(void) __attribute__((volatile));  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__dead
end_ifndef

begin_define
define|#
directive|define
name|__dead
value|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__dead
end_ifndef

begin_define
define|#
directive|define
name|__dead
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|args
parameter_list|)
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

