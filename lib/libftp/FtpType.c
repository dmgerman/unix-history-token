begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 		      Library for ftpd clients.(libftp) 			Copyright by Oleg Orel 			 All rights reserved.  This  library is desined  for  free,  non-commercial  software  creation. It is changeable and can be improved. The author would greatly appreciate any  advises, new  components  and  patches  of  the  existing  programs. Commercial  usage is  also  possible  with  participation of it's author.    */
end_comment

begin_include
include|#
directive|include
file|"FtpLibrary.h"
end_include

begin_function
name|STATUS
name|FtpType
parameter_list|(
name|FTP
modifier|*
name|ftp
parameter_list|,
name|char
name|type
parameter_list|)
block|{
name|STATUS
name|p
decl_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|FtpCommand
argument_list|(
name|ftp
argument_list|,
literal|"TYPE %c"
argument_list|,
name|type
argument_list|,
literal|200
argument_list|,
name|EOF
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|ftp
operator|->
name|mode
operator|=
operator|(
name|int
operator|)
name|type
expr_stmt|;
return|return
name|p
return|;
block|}
end_function

end_unit

