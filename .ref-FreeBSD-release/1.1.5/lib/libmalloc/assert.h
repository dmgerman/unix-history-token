begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: assert.h,v 1.7 1993/05/23 03:38:27 moraes Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSERT_H__
end_ifndef

begin_define
define|#
directive|define
name|__ASSERT_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|((void) (!(p) ? __m_botch(s, __FILE__, __LINE__) : 0))
end_define

begin_decl_stmt
specifier|extern
name|int
name|__m_botch
name|proto
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|p
parameter_list|,
name|s
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

begin_comment
comment|/* __ASSERT_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

