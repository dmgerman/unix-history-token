begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)setlocale.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|C
index|[]
init|=
literal|"C"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The setlocale function.  *  * Sorry, for now we only accept the C locale.  */
end_comment

begin_function
name|char
modifier|*
name|setlocale
parameter_list|(
name|category
parameter_list|,
name|locale
parameter_list|)
name|int
name|category
decl_stmt|;
specifier|const
name|char
modifier|*
name|locale
decl_stmt|;
block|{
if|if
condition|(
operator|(
name|unsigned
name|int
operator|)
name|category
operator|>=
name|_LC_LAST
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
if|if
condition|(
name|locale
operator|==
name|NULL
condition|)
return|return
operator|(
name|C
operator|)
return|;
return|return
operator|(
name|strcmp
argument_list|(
name|locale
argument_list|,
name|C
argument_list|)
condition|?
name|NULL
else|:
name|C
operator|)
return|;
block|}
end_function

end_unit

