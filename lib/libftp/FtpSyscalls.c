begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 		      Library for ftpd clients.(libftp) 			Copyright by Oleg Orel 			 All rights reserved.  This  library is desined  for  free,  non-commercial  software  creation. It is changeable and can be improved. The author would greatly appreciate any  advises, new  components  and  patches  of  the  existing  programs. Commercial  usage is  also  possible  with  participation of it's author.    */
end_comment

begin_include
include|#
directive|include
file|"FtpLibrary.h"
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|DEF
parameter_list|(
name|syscal
parameter_list|,
name|name
parameter_list|)
value|int name(void *a, void *b, void *c) \ {\    register int status;\    while (((status=syscal(a,b,c))==-1)&& (errno==EINTR));\    return status;\ }
end_define

begin_macro
name|DEF
argument_list|(
argument|open
argument_list|,
argument|nointr_open
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|close
argument_list|,
argument|nointr_close
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|select
argument_list|,
argument|nointr_select
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|read
argument_list|,
argument|nointr_read
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|write
argument_list|,
argument|nointr_write
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|dup
argument_list|,
argument|nointr_dup
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|wait
argument_list|,
argument|nointr_wait
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|connect
argument_list|,
argument|nointr_connect
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|listen
argument_list|,
argument|nointr_listen
argument_list|)
end_macro

begin_macro
name|DEF
argument_list|(
argument|accept
argument_list|,
argument|nointr_accept
argument_list|)
end_macro

end_unit

