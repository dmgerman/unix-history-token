begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*	putenv(3)						*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*		Change or add an environment entry		*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/*   origination        1987-Oct-7               T. Holm	*/
end_comment

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/* Path: hoptoad!pacbell!ames!ll-xn!mit-eddie!uw-beaver!ssc-vax!uvicctr!tholm From: tholm@uvicctr.UUCP (Terrence W. Holm) Newsgroups: comp.os.minix Subject: putenv(3) Message-ID:<395@uvicctr.UUCP> Date: 5 May 88 06:40:52 GMT Organization: University of Victoria, Victoria B.C. Canada  EFTH Minix report #2  - May 1988 -  putenv(3)  This is an implementation of putenv(3) that we wrote for Minix. Please consider this a public domain program. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|PSIZE
value|sizeof(char *)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*      int							*/
end_comment

begin_comment
comment|/*	putenv( entry )						*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*		The "entry" should follow the form 		*/
end_comment

begin_comment
comment|/*		"NAME=VALUE". This routine will search the 	*/
end_comment

begin_comment
comment|/*		user environment for "NAME" and replace its 	*/
end_comment

begin_comment
comment|/*		value with "VALUE".				*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*		Note that "entry" is not copied, it is used 	*/
end_comment

begin_comment
comment|/*		as the environment entry. This means that it 	*/
end_comment

begin_comment
comment|/*		must not be unallocated or otherwise modifed 	*/
end_comment

begin_comment
comment|/*		by the caller, unless it is replaced by a 	*/
end_comment

begin_comment
comment|/*		subsequent putenv().				*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*		If the name is not found in the environment, 	*/
end_comment

begin_comment
comment|/*		then a new vector of pointers is allocated, 	*/
end_comment

begin_comment
comment|/*		"entry" is put at the end and the global 	*/
end_comment

begin_comment
comment|/*		variable "environ" is updated.			*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/*		This function normally returns NULL, but -1	*/
end_comment

begin_comment
comment|/*		is returned if it can not allocate enough 	*/
end_comment

begin_comment
comment|/*		space using malloc(3), or "entry" does not	*/
end_comment

begin_comment
comment|/*		contain a '='.					*/
end_comment

begin_comment
comment|/*								*/
end_comment

begin_comment
comment|/****************************************************************/
end_comment

begin_function
name|int
name|putenv
parameter_list|(
name|entry
parameter_list|)
name|char
modifier|*
name|entry
decl_stmt|;
block|{
name|unsigned
name|length
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
name|char
modifier|*
name|temp
decl_stmt|;
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
modifier|*
name|new_environ
decl_stmt|;
comment|/*  Find the length of the "NAME="  */
name|temp
operator|=
name|strchr
argument_list|(
name|entry
argument_list|,
literal|'='
argument_list|)
expr_stmt|;
if|if
condition|(
name|temp
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|length
operator|=
call|(
name|unsigned
call|)
argument_list|(
name|temp
operator|-
name|entry
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/*  Scan through the environment looking for "NAME="  */
for|for
control|(
name|p
operator|=
name|environ
init|;
operator|*
name|p
operator|!=
literal|0
condition|;
name|p
operator|++
control|)
if|if
condition|(
name|strncmp
argument_list|(
name|entry
argument_list|,
operator|*
name|p
argument_list|,
name|length
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|*
name|p
operator|=
name|entry
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/*  The name was not found, build a bigger environment  */
name|size
operator|=
name|p
operator|-
name|environ
expr_stmt|;
name|new_environ
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|size
operator|+
literal|2
operator|)
operator|*
name|PSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|new_environ
operator|==
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|new_environ
argument_list|,
operator|(
name|char
operator|*
operator|)
name|environ
argument_list|,
name|size
operator|*
name|PSIZE
argument_list|)
expr_stmt|;
name|new_environ
index|[
name|size
index|]
operator|=
name|entry
expr_stmt|;
name|new_environ
index|[
name|size
operator|+
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
name|environ
operator|=
name|new_environ
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

