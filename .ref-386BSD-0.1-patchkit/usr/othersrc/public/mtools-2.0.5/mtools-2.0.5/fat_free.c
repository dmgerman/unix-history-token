begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"msdos.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|fat_error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_fat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Remove a string of FAT entries (delete the file).  The argument is  * the beginning of the string.  Does not consider the file length, so  * if FAT is corrupted, watch out!  */
end_comment

begin_function
name|int
name|fat_free
parameter_list|(
name|fat
parameter_list|)
name|unsigned
name|int
name|fat
decl_stmt|;
block|{
name|unsigned
name|int
name|next
decl_stmt|,
name|fat_decode
argument_list|()
decl_stmt|;
comment|/* a zero length file? */
if|if
condition|(
name|fat
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* CONSTCOND */
while|while
condition|(
literal|1
condition|)
block|{
comment|/* get next cluster number */
name|next
operator|=
name|fat_decode
argument_list|(
name|fat
argument_list|)
expr_stmt|;
comment|/* mark current cluster as empty */
if|if
condition|(
name|fat_encode
argument_list|(
name|fat
argument_list|,
literal|0
argument_list|)
operator|||
name|next
operator|==
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"fat_free: FAT problem\n"
argument_list|)
expr_stmt|;
name|fat_error
operator|++
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|next
operator|>=
name|last_fat
condition|)
break|break;
name|fat
operator|=
name|next
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

