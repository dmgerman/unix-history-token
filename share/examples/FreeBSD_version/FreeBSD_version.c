begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__FreeBSD__
operator|==
literal|0
end_if

begin_comment
comment|/* 1.0 did not define __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|__FreeBSD_version
value|199401
end_define

begin_elif
elif|#
directive|elif
name|__FreeBSD__
operator|==
literal|1
end_elif

begin_comment
comment|/* 1.1 defined it to be 1 */
end_comment

begin_define
define|#
directive|define
name|__FreeBSD_version
value|199405
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 2.0 and higher define it to be 2 */
end_comment

begin_include
include|#
directive|include
file|<osreldate.h>
end_include

begin_comment
comment|/* and this works */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|int
name|getosreldate
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"Compilation release date: %d\n"
argument_list|,
name|__FreeBSD_version
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|199408
name|printf
argument_list|(
literal|"Execution environment release date: %d\n"
argument_list|,
name|getosreldate
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"Execution environment release date: can't tell\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

