begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: rule.c,v 1.2 85/05/16 12:49:56 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|"Mkmf.h"
end_include

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"rule.h"
end_include

begin_include
include|#
directive|include
file|"slist.h"
end_include

begin_include
include|#
directive|include
file|"suffix.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_decl_stmt
specifier|static
name|RULEBLK
modifier|*
name|Ruletab
index|[
name|RULETABSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rules table */
end_comment

begin_decl_stmt
specifier|static
name|SLIST
modifier|*
name|Rulelist
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* transformation rule list */
end_comment

begin_comment
comment|/*  * buildruletable() converts a list of transformation rules into a hash table  * for fast lookup. Returns YES if successful, otherwise NO.  */
end_comment

begin_macro
name|buildruletable
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|char
modifier|*
name|DEFRULE
index|[]
decl_stmt|;
comment|/* default preprocessor rules */
name|int
name|i
decl_stmt|;
comment|/* default rule list counter */
name|int
name|instalrule
parameter_list|()
function_decl|;
comment|/* instale rule in hash table */
name|SLBLK
modifier|*
name|rblk
decl_stmt|;
comment|/* singly-linked rulename block */
comment|/* process default rules */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|DEFRULE
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|instalrule
argument_list|(
name|DEFRULE
index|[
name|i
index|]
argument_list|)
operator|==
name|NO
condition|)
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
comment|/* process rules found in makefile */
if|if
condition|(
name|Rulelist
operator|!=
name|NULL
condition|)
block|{
for|for
control|(
name|rblk
operator|=
name|Rulelist
operator|->
name|head
init|;
name|rblk
operator|!=
name|NULL
condition|;
name|rblk
operator|=
name|rblk
operator|->
name|next
control|)
block|{
if|if
condition|(
name|instalrule
argument_list|(
name|rblk
operator|->
name|key
argument_list|)
operator|==
name|NO
condition|)
block|{
name|warn
argument_list|(
literal|"out of memory"
argument_list|)
expr_stmt|;
return|return
operator|(
name|NO
operator|)
return|;
block|}
block|}
block|}
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * findrule() searchs a line for a transformation rule. Returns the  * name of the transformation rule, or NULL if not found.  */
end_comment

begin_function
name|char
modifier|*
name|findrule
parameter_list|(
name|rulename
parameter_list|,
name|bp
parameter_list|)
name|char
modifier|*
name|rulename
decl_stmt|;
comment|/* transformation rule buffer */
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* I/O buffer pointer */
block|{
specifier|register
name|char
modifier|*
name|rp
decl_stmt|;
comment|/* rule name pointer */
name|int
name|dotcount
init|=
literal|0
decl_stmt|;
comment|/* number of '.'s in rule */
for|for
control|(
name|rp
operator|=
name|rulename
init|;
operator|*
name|bp
operator|!=
literal|':'
operator|&&
operator|*
name|bp
operator|!=
literal|' '
operator|&&
operator|*
name|bp
operator|!=
literal|'\t'
condition|;
name|rp
operator|++
operator|,
name|bp
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|rp
operator|=
operator|*
name|bp
operator|)
operator|==
literal|'.'
condition|)
name|dotcount
operator|++
expr_stmt|;
block|}
operator|*
name|rp
operator|=
literal|'\0'
expr_stmt|;
comment|/* eat up white space between rule and ':' */
if|if
condition|(
operator|*
name|bp
operator|!=
literal|':'
condition|)
block|{
while|while
condition|(
operator|*
name|bp
operator|==
literal|' '
operator|||
operator|*
name|bp
operator|==
literal|'\t'
condition|)
name|bp
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|bp
operator|!=
literal|':'
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
block|}
return|return
operator|(
operator|(
name|dotcount
operator|==
literal|2
operator|)
condition|?
name|rulename
else|:
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * instalrule() installs a source transformation rule in the rule lookup  * table. The rule table consists of a set of singly-linked lists, indexed  * by the first character of the suffix of the target file. The index of  * the target file is used by lookuprule() to find out the name of the file  * from which it was derived. Returns YES if successful, otherwise NO.  */
end_comment

begin_macro
name|instalrule
argument_list|(
argument|rule
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|rule
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rule to be installed in Rule table */
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
name|rindex
parameter_list|()
function_decl|;
comment|/* find last occurrence of character */
name|char
modifier|*
name|strsav
parameter_list|()
function_decl|;
comment|/* save a string somewhere */
name|char
modifier|*
name|target
decl_stmt|;
comment|/* target suffix */
name|int
name|lookupsfx
parameter_list|()
function_decl|;
comment|/* get suffix type */
name|int
name|ruleindex
decl_stmt|;
comment|/* index into rule table */
name|RULEBLK
modifier|*
name|rblk
decl_stmt|;
comment|/* rule list block */
name|target
operator|=
name|rindex
argument_list|(
name|rule
argument_list|,
literal|'.'
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|lookupsfx
argument_list|(
name|target
argument_list|)
operator|==
name|SFXSRC
condition|)
block|{
name|ruleindex
operator|=
name|target
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|rblk
operator|=
operator|(
name|RULEBLK
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|RULEBLK
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
name|rblk
operator|->
name|r_rule
operator|=
name|strsav
argument_list|(
name|rule
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
name|rblk
operator|->
name|r_next
operator|=
name|Ruletab
index|[
name|ruleindex
index|]
expr_stmt|;
name|Ruletab
index|[
name|ruleindex
index|]
operator|=
name|rblk
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
comment|/*  * lookuprule() applies successive transformation rules to filename, and  * checks to see if the file exists. Returns YES if filename exists,  * otherwise NO.  */
end_comment

begin_macro
name|lookuprule
argument_list|(
argument|target
argument_list|,
argument|source
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|target
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of (transformed) file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|source
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of source file */
end_comment

begin_block
block|{
specifier|register
name|char
modifier|*
name|r
decl_stmt|;
comment|/* rule pointer */
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
comment|/* source buffer pointer */
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
comment|/* find last occurrence of character */
name|char
modifier|*
name|sourcesuffix
decl_stmt|;
comment|/* source file suffix */
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|char
modifier|*
name|rulesuffix
decl_stmt|;
comment|/* target suffix in each rule */
name|char
modifier|*
name|targetsuffix
decl_stmt|;
comment|/* transformed file suffix string */
name|int
name|ruleindex
decl_stmt|;
comment|/* index into rule table */
name|int
name|strcmp
parameter_list|()
function_decl|;
comment|/* string comparison */
name|RULEBLK
modifier|*
name|rblk
decl_stmt|;
comment|/* rule list block */
if|if
condition|(
operator|(
name|targetsuffix
operator|=
name|rindex
argument_list|(
name|target
argument_list|,
literal|'.'
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
name|ruleindex
operator|=
name|targetsuffix
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|Ruletab
index|[
name|ruleindex
index|]
operator|!=
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|source
argument_list|,
name|target
argument_list|)
expr_stmt|;
name|sourcesuffix
operator|=
name|rindex
argument_list|(
name|source
argument_list|,
literal|'.'
argument_list|)
expr_stmt|;
for|for
control|(
name|rblk
operator|=
name|Ruletab
index|[
name|ruleindex
index|]
init|;
name|rblk
operator|!=
name|NULL
condition|;
name|rblk
operator|=
name|rblk
operator|->
name|r_next
control|)
block|{
name|rulesuffix
operator|=
name|rindex
argument_list|(
name|rblk
operator|->
name|r_rule
argument_list|,
literal|'.'
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|rulesuffix
argument_list|,
name|targetsuffix
argument_list|)
operator|==
literal|0
condition|)
block|{
name|r
operator|=
name|rblk
operator|->
name|r_rule
expr_stmt|;
name|s
operator|=
name|sourcesuffix
expr_stmt|;
while|while
condition|(
operator|*
operator|++
name|s
operator|=
operator|*
operator|++
name|r
condition|)
if|if
condition|(
operator|*
name|s
operator|==
literal|'.'
condition|)
block|{
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|FILEXIST
argument_list|(
name|source
argument_list|)
condition|)
return|return
operator|(
name|YES
operator|)
return|;
block|}
block|}
block|}
return|return
operator|(
name|NO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * storerule() appends a transformation rule to the end of a singly-linked  * list. Returns integer NO if out of memory, otherwise YES.  */
end_comment

begin_macro
name|storerule
argument_list|(
argument|rulename
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|rulename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* transformation rule name */
end_comment

begin_block
block|{
name|char
modifier|*
name|slappend
parameter_list|()
function_decl|;
comment|/* append rule to list */
name|SLIST
modifier|*
name|slinit
parameter_list|()
function_decl|;
comment|/* initialize transformation list */
if|if
condition|(
name|Rulelist
operator|==
name|NULL
condition|)
name|Rulelist
operator|=
name|slinit
argument_list|()
expr_stmt|;
if|if
condition|(
name|slappend
argument_list|(
name|rulename
argument_list|,
name|Rulelist
argument_list|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NO
operator|)
return|;
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

