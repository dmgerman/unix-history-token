begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strtok.c	1.1 (Berkeley/CCI) 7/5/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*	@(#)strtok.c	1.2	*/
end_comment

begin_comment
comment|/*	3.0 SID #	1.2	*/
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  * uses strpbrk and strspn to break string into tokens on  * sequentially subsequent calls.  returns NULL when no  * non-separator characters remain.  * `subsequent' calls are calls with first argument NULL.  */
end_comment

begin_define
define|#
directive|define
name|NULL
value|(char*)0
end_define

begin_function_decl
specifier|extern
name|int
name|strspn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strpbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|strtok
parameter_list|(
name|string
parameter_list|,
name|sepset
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|,
decl|*
name|sepset
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|,
modifier|*
name|r
decl_stmt|;
specifier|static
name|char
modifier|*
name|savept
decl_stmt|;
comment|/*first or subsequent call*/
name|p
operator|=
operator|(
name|string
operator|==
name|NULL
operator|)
condition|?
name|savept
else|:
name|string
expr_stmt|;
if|if
condition|(
name|p
operator|==
literal|0
condition|)
comment|/* return if no tokens remaining */
return|return
operator|(
name|NULL
operator|)
return|;
name|q
operator|=
name|p
operator|+
name|strspn
argument_list|(
name|p
argument_list|,
name|sepset
argument_list|)
expr_stmt|;
comment|/* skip leading separators */
if|if
condition|(
operator|*
name|q
operator|==
literal|'\0'
condition|)
comment|/* return if no tokens remaining */
return|return
operator|(
name|NULL
operator|)
return|;
if|if
condition|(
operator|(
name|r
operator|=
name|strpbrk
argument_list|(
name|q
argument_list|,
name|sepset
argument_list|)
operator|)
operator|==
name|NULL
condition|)
comment|/* move past token */
name|savept
operator|=
literal|0
expr_stmt|;
comment|/* indicate this is last token */
else|else
block|{
operator|*
name|r
operator|=
literal|'\0'
expr_stmt|;
name|savept
operator|=
operator|++
name|r
expr_stmt|;
block|}
return|return
operator|(
name|q
operator|)
return|;
block|}
end_block

end_unit

