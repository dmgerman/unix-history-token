begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XSlock_h__
end_ifndef

begin_define
define|#
directive|define
name|__XSlock_h__
end_define

begin_decl_stmt
name|class
name|XSLockManager
block|{
name|public
label|:
name|XSLockManager
argument_list|()
block|{
name|InitializeCriticalSection
argument_list|(
operator|&
name|cs
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
operator|~
name|XSLockManager
argument_list|()
block|{
name|DeleteCriticalSection
argument_list|(
operator|&
name|cs
argument_list|)
block|; }
expr_stmt|;
name|void
name|Enter
parameter_list|(
name|void
parameter_list|)
block|{
name|EnterCriticalSection
argument_list|(
operator|&
name|cs
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|void
name|Leave
parameter_list|(
name|void
parameter_list|)
block|{
name|LeaveCriticalSection
argument_list|(
operator|&
name|cs
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|protected
label|:
name|CRITICAL_SECTION
name|cs
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|XSLockManager
name|g_XSLock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CPerlObj
modifier|*
name|pPerl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|XSLock
block|{
name|public
label|:
name|XSLock
argument_list|(
argument|CPerlObj *p
argument_list|)
block|{
name|g_XSLock
operator|.
name|Enter
argument_list|()
expr_stmt|;
operator|::
name|pPerl
operator|=
name|p
expr_stmt|;
block|}
empty_stmt|;
operator|~
name|XSLock
argument_list|()
block|{
name|g_XSLock
operator|.
name|Leave
argument_list|()
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* PERL_CAPI does its own locking in xs_handler() */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_CAPI
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|dXSARGS
end_undef

begin_define
define|#
directive|define
name|dXSARGS
define|\
value|XSLock localLock(pPerl);			\ 	dSP; dMARK;					\ 	I32 ax = mark - PL_stack_base + 1;		\ 	I32 items = sp - mark
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT&& !PERL_CAPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

