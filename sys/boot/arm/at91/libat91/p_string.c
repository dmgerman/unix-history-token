begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: p_string.c  *  * Instantiation of basic string operations to prevent inclusion of full  * string library.  These are simple implementations not necessarily optimized  * for speed, but rather to show intent.  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  * 12JAN2005	kb_admin	minor updates  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/*  * .KB_C_FN_DEFINITION_START  * void p_memset(char *buffer, char value, int size)  *  This global function sets memory at the pointer for the specified  * number of bytes to value.  * .KB_C_FN_DEFINITION_END  */
end_comment

begin_function
name|void
name|p_memset
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|char
name|value
parameter_list|,
name|int
name|size
parameter_list|)
block|{
while|while
condition|(
name|size
operator|--
condition|)
operator|*
name|buffer
operator|++
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * .KB_C_FN_DEFINITION_START  * int p_memcmp(char *to, char *from, unsigned size)  *  This global function compares data at to against data at from for  * size bytes.  Returns 0 if the locations are equal.  size must be  * greater than 0.  * .KB_C_FN_DEFINITION_END  */
end_comment

begin_function
name|int
name|p_memcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|to
parameter_list|,
specifier|const
name|char
modifier|*
name|from
parameter_list|,
name|unsigned
name|size
parameter_list|)
block|{
while|while
condition|(
operator|(
operator|--
name|size
operator|)
operator|&&
operator|(
operator|*
name|to
operator|++
operator|==
operator|*
name|from
operator|++
operator|)
condition|)
continue|continue;
return|return
operator|(
operator|*
name|to
operator|!=
operator|*
name|from
operator|)
return|;
block|}
end_function

end_unit

