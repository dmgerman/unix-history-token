begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 		      Library for ftpd clients.(libftp) 			Copyright by Oleg Orel 			 All rights reserved. 			 This  library is desined  for  free,  non-commercial  software  creation.  It is changeable and can be improved. The author would greatly appreciate  any  advises, new  components  and  patches  of  the  existing  programs. Commercial  usage is  also  possible  with  participation of it's author.    */
end_comment

begin_include
include|#
directive|include
file|"FtpLibrary.h"
end_include

begin_function
name|int
name|FtpNumber
parameter_list|(
name|char
modifier|*
name|Message
parameter_list|)
block|{
return|return
operator|(
name|Message
index|[
literal|0
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|100
operator|+
operator|(
name|Message
index|[
literal|1
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|10
operator|+
operator|(
name|Message
index|[
literal|2
index|]
operator|-
literal|'0'
operator|)
return|;
block|}
end_function

end_unit

