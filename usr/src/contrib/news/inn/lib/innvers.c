begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_comment
comment|/* Length of string plus trailing space. */
end_comment

begin_define
define|#
directive|define
name|S
parameter_list|(
name|x
parameter_list|)
value|sizeof(x)
end_define

begin_comment
comment|/* Buffer size. */
end_comment

begin_define
define|#
directive|define
name|SIZE
value|S("INN") + S(RELEASE) + 1 + S(PATCHLEVEL) \ 		+ S(DATE) + 1 + S(LOCAL_STRING) + 1
end_define

begin_comment
comment|/* **  Return the version string. */
end_comment

begin_function
name|char
modifier|*
name|INNVersion
parameter_list|()
block|{
specifier|static
name|char
name|buff
index|[
name|SIZE
operator|+
literal|1
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|STRING
name|q
decl_stmt|;
if|if
condition|(
name|buff
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
name|p
operator|=
name|buff
expr_stmt|;
name|p
operator|+=
name|strlen
argument_list|(
name|strcpy
argument_list|(
name|p
argument_list|,
literal|"INN"
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|' '
expr_stmt|;
name|p
operator|+=
name|strlen
argument_list|(
name|strcpy
argument_list|(
name|p
argument_list|,
name|RELEASE
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|'.'
expr_stmt|;
name|p
operator|+=
name|strlen
argument_list|(
name|strcpy
argument_list|(
name|p
argument_list|,
name|PATCHLEVEL
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|' '
expr_stmt|;
name|p
operator|+=
name|strlen
argument_list|(
name|strcpy
argument_list|(
name|p
argument_list|,
name|DATE
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|=
name|LOCAL_STRING
expr_stmt|;
if|if
condition|(
operator|*
name|q
condition|)
block|{
operator|*
name|p
operator|++
operator|=
literal|' '
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|'('
expr_stmt|;
name|p
operator|+=
name|strlen
argument_list|(
name|strcpy
argument_list|(
name|p
argument_list|,
name|q
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
literal|')'
expr_stmt|;
block|}
block|}
return|return
name|buff
return|;
block|}
end_function

end_unit

