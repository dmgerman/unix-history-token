begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mexit - Used to exit the NTPD daemon  *   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_decl_stmt
name|HANDLE
name|hServDoneEvent
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|service_exit
parameter_list|(
name|int
name|status
parameter_list|)
block|{
specifier|extern
name|int
name|debug
decl_stmt|;
if|if
condition|(
name|debug
condition|)
comment|/* did not become a service, simply exit */
name|ExitThread
argument_list|(
operator|(
name|DWORD
operator|)
name|status
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* service mode, need to have the service_main routine 		 * register with the service control manager that the  		 * service has stopped running, before exiting 		 */
if|if
condition|(
operator|(
name|status
operator|>
literal|0
operator|)
operator|&&
operator|(
name|hServDoneEvent
operator|!=
name|NULL
operator|)
condition|)
name|SetEvent
argument_list|(
name|hServDoneEvent
argument_list|)
expr_stmt|;
name|ExitThread
argument_list|(
operator|(
name|DWORD
operator|)
name|status
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not SYS_WINNT */
end_comment

begin_decl_stmt
name|int
name|mexit_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SYS_WINNT */
end_comment

end_unit

