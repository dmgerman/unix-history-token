begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)isctype.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_define
define|#
directive|define
name|_ANSI_LIBRARY
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_undef
undef|#
directive|undef
name|isalnum
end_undef

begin_macro
name|isalnum
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
operator|(
name|_U
operator||
name|_L
operator||
name|_N
operator|)
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isalpha
end_undef

begin_macro
name|isalpha
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
operator|(
name|_U
operator||
name|_L
operator|)
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|iscntrl
end_undef

begin_macro
name|iscntrl
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_C
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_macro
name|isdigit
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_N
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isgraph
end_undef

begin_macro
name|isgraph
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
operator|(
name|_P
operator||
name|_U
operator||
name|_L
operator||
name|_N
operator|)
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|islower
end_undef

begin_macro
name|islower
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_L
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isprint
end_undef

begin_macro
name|isprint
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
operator|(
name|_P
operator||
name|_U
operator||
name|_L
operator||
name|_N
operator||
name|_B
operator|)
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|ispunct
end_undef

begin_macro
name|ispunct
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_P
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_macro
name|isspace
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_S
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isupper
end_undef

begin_macro
name|isupper
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
name|_U
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|isxdigit
end_undef

begin_macro
name|isxdigit
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|_ctype_
operator|+
literal|1
operator|)
index|[
name|c
index|]
operator|&
operator|(
name|_N
operator||
name|_X
operator|)
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|tolower
end_undef

begin_macro
name|tolower
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|c
operator|)
operator|-
literal|'A'
operator|+
literal|'a'
operator|)
return|;
block|}
end_block

begin_undef
undef|#
directive|undef
name|toupper
end_undef

begin_macro
name|toupper
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
operator|(
name|c
operator|)
operator|-
literal|'a'
operator|+
literal|'A'
operator|)
return|;
block|}
end_block

end_unit

