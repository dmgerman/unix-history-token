begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: suffix.c,v 1.2 85/03/21 10:19:36 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"Mkmf.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_include
include|#
directive|include
file|"macro.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"suffix.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|SFX1
index|[
name|SFXTABSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* single character suffixes */
end_comment

begin_decl_stmt
specifier|static
name|int
name|INC1
index|[
name|SFXTABSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* include file types for 1 char sfx */
end_comment

begin_decl_stmt
specifier|static
name|SFXBLK
modifier|*
name|SFX2
index|[
name|SFXTABSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2+ character suffixes */
end_comment

begin_comment
comment|/*  * buildsfxtable() converts a suffix list into a hash table for fast lookup.  * Returns YES if successful, otherwise NO.  */
end_comment

begin_macro
name|buildsfxtable
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|HASH
modifier|*
name|MDEFTABLE
decl_stmt|;
comment|/* macro definition table */
specifier|extern
name|SUFFIX
name|DEFSFX
index|[]
decl_stmt|;
comment|/* default suffix list */
name|HASHBLK
modifier|*
name|htb
decl_stmt|;
comment|/* hash table block */
name|HASHBLK
modifier|*
name|htlookup
parameter_list|()
function_decl|;
comment|/* find hash table entry */
name|int
name|i
decl_stmt|;
comment|/* suffix list counter */
name|int
name|installsfx
parameter_list|()
function_decl|;
comment|/* install suffix in hash table */
name|int
name|sfxbuftotable
parameter_list|()
function_decl|;
comment|/* feed suffixes to installsfx() */
comment|/* default suffix list */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|DEFSFX
index|[
name|i
index|]
operator|.
name|suffix
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|installsfx
argument_list|(
name|DEFSFX
index|[
name|i
index|]
operator|.
name|suffix
argument_list|,
name|DEFSFX
index|[
name|i
index|]
operator|.
name|sfxtyp
argument_list|,
name|DEFSFX
index|[
name|i
index|]
operator|.
name|inctyp
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
comment|/* supplementary suffix definitions */
if|if
condition|(
operator|(
name|htb
operator|=
name|htlookup
argument_list|(
name|MSUFFIX
argument_list|,
name|MDEFTABLE
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|sfxbuftotable
argument_list|(
name|htb
operator|->
name|h_def
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * installsfx() installs a suffix in one of two suffix tables: SFX1 for  * one character suffixes, and SFX2 for two or more character suffixes.  * For a suffix that already exists, only its type and corresponding  * included file type is updated. Returns integer YES if successful,  * otherwise NO.  */
end_comment

begin_macro
name|installsfx
argument_list|(
argument|suffix
argument_list|,
argument|sfxtyp
argument_list|,
argument|inctyp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|suffix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suffix string */
end_comment

begin_decl_stmt
name|int
name|sfxtyp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suffix type */
end_comment

begin_decl_stmt
name|int
name|inctyp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* include file type */
end_comment

begin_block
block|{
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string somewhere */
name|int
name|sfxindex
decl_stmt|;
comment|/* index into suffix tables */
name|SFXBLK
modifier|*
name|sfxblk
decl_stmt|;
comment|/* suffix list block */
if|if
condition|(
operator|*
name|suffix
operator|==
literal|'.'
condition|)
name|suffix
operator|++
expr_stmt|;
name|sfxindex
operator|=
name|suffix
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|suffix
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|suffix
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
name|SFX1
index|[
name|sfxindex
index|]
operator|=
name|sfxtyp
expr_stmt|;
comment|/* 0 or 1 character suffix */
name|INC1
index|[
name|sfxindex
index|]
operator|=
name|inctyp
expr_stmt|;
block|}
else|else
block|{
comment|/* 2+ character suffix */
if|if
condition|(
operator|(
name|sfxblk
operator|=
operator|(
name|SFXBLK
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|SFXBLK
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
if|if
condition|(
operator|(
name|sfxblk
operator|->
name|sfx
operator|.
name|suffix
operator|=
name|strsav
argument_list|(
name|suffix
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
name|sfxblk
operator|->
name|sfx
operator|.
name|sfxtyp
operator|=
name|sfxtyp
expr_stmt|;
name|sfxblk
operator|->
name|sfx
operator|.
name|inctyp
operator|=
name|inctyp
expr_stmt|;
name|sfxblk
operator|->
name|next
operator|=
name|SFX2
index|[
name|sfxindex
index|]
expr_stmt|;
name|SFX2
index|[
name|sfxindex
index|]
operator|=
name|sfxblk
expr_stmt|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * lookuptypeofinclude() returns the include file type for suffix, or 0 if  * unknown suffix.  */
end_comment

begin_macro
name|lookuptypeofinclude
argument_list|(
argument|suffix
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|suffix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suffix string */
end_comment

begin_block
block|{
name|SFXBLK
modifier|*
name|sfxblk
decl_stmt|;
comment|/* suffix block pointer */
if|if
condition|(
name|suffix
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|suffix
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
return|return
operator|(
name|INC1
index|[
operator|*
name|suffix
index|]
operator|)
return|;
comment|/* 0 or 1 char suffix */
comment|/* 2+ character suffix */
for|for
control|(
name|sfxblk
operator|=
name|SFX2
index|[
operator|*
name|suffix
index|]
init|;
name|sfxblk
operator|!=
name|NULL
condition|;
name|sfxblk
operator|=
name|sfxblk
operator|->
name|next
control|)
if|if
condition|(
name|EQUAL
argument_list|(
name|suffix
argument_list|,
name|sfxblk
operator|->
name|sfx
operator|.
name|suffix
argument_list|)
condition|)
return|return
operator|(
name|sfxblk
operator|->
name|sfx
operator|.
name|inctyp
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * lookupsfx() returns the suffix type, or 0 if unknown suffix.  */
end_comment

begin_macro
name|lookupsfx
argument_list|(
argument|suffix
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|suffix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* suffix string */
end_comment

begin_block
block|{
name|SFXBLK
modifier|*
name|sfxblk
decl_stmt|;
comment|/* suffix block pointer */
if|if
condition|(
name|suffix
index|[
literal|0
index|]
operator|==
literal|'\0'
operator|||
name|suffix
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
return|return
operator|(
name|SFX1
index|[
operator|*
name|suffix
index|]
operator|)
return|;
comment|/* 0 or 1 char suffix */
comment|/* 2+ character suffix */
for|for
control|(
name|sfxblk
operator|=
name|SFX2
index|[
operator|*
name|suffix
index|]
init|;
name|sfxblk
operator|!=
name|NULL
condition|;
name|sfxblk
operator|=
name|sfxblk
operator|->
name|next
control|)
if|if
condition|(
name|EQUAL
argument_list|(
name|suffix
argument_list|,
name|sfxblk
operator|->
name|sfx
operator|.
name|suffix
argument_list|)
condition|)
return|return
operator|(
name|sfxblk
operator|->
name|sfx
operator|.
name|sfxtyp
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * sfxbuftotable() parses a buffer containing suffixes and presents them  * to installsfx() for installation into the appropriate hash table.  * The suffix type may be altered by attaching a modifier :suffixtype.  *	:h	--> header file type  *	:o	--> object file type  *	:s	--> source file type (default)  *	:x	--> executable file type  *	:	--> unknown file type  * The include file type may be altered by attaching an additional  * modifier includetype.  *	C	--> C source code  *	F	--> Fortran, Ratfor, Efl source code  *	P	--> Pascal source code  * If the suffix is object file type, the OBJSFX default object suffix  * is modified accordingly. Returns YES if successful, otherwise NO.  */
end_comment

begin_macro
name|sfxbuftotable
argument_list|(
argument|sfxbuf
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|sfxbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer conatining suffixes */
end_comment

begin_block
block|{
specifier|extern
name|char
name|OBJSFX
index|[]
decl_stmt|;
comment|/* object file name suffix */
name|char
modifier|*
name|gettoken
parameter_list|()
function_decl|;
comment|/* get next token */
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
comment|/* find last occurrence of character */
name|char
modifier|*
name|sfxtyp
decl_stmt|;
comment|/* suffix type */
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|char
name|suffix
index|[
name|SUFFIXSIZE
operator|+
literal|2
index|]
decl_stmt|;
comment|/* suffix + modifier */
name|int
name|installsfx
parameter_list|()
function_decl|;
comment|/* install suffix in hash table */
while|while
condition|(
operator|(
name|sfxbuf
operator|=
name|gettoken
argument_list|(
name|suffix
argument_list|,
name|sfxbuf
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
if|if
condition|(
operator|(
name|sfxtyp
operator|=
name|rindex
argument_list|(
name|suffix
argument_list|,
literal|':'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|installsfx
argument_list|(
name|suffix
argument_list|,
name|SFXSRC
argument_list|,
name|INCLUDE_NONE
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
block|}
else|else
block|{
operator|*
name|sfxtyp
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|installsfx
argument_list|(
name|suffix
argument_list|,
name|sfxtyp
index|[
literal|1
index|]
argument_list|,
name|sfxtyp
index|[
literal|2
index|]
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
if|if
condition|(
name|sfxtyp
index|[
literal|1
index|]
operator|==
name|SFXOBJ
condition|)
name|strcpy
argument_list|(
name|OBJSFX
argument_list|,
name|suffix
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

