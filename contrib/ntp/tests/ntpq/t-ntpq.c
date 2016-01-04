begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_comment
comment|//#include "ntp_stdlib.h"
end_comment

begin_comment
comment|//#include "ntp_calendar.h"
end_comment

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_include
include|#
directive|include
file|"ntpq.h"
end_include

begin_comment
comment|//very tricky to test static functions. It might be a good idea to use cmock here
end_comment

begin_comment
comment|//#define HAVE_NTPQ
end_comment

begin_comment
comment|//#include "ntpq.c"
end_comment

begin_comment
comment|//extern int main(int argc, char *argv[]);
end_comment

begin_function_decl
name|void
name|testPrimary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|testPrimary
parameter_list|(
name|void
parameter_list|)
block|{
comment|//main(NULL,NULL);
comment|/* 	char ** tokens; 	int * num = 0; 	tokenize("a bc de1 234",tokens, num); */
block|}
end_function

begin_define
define|#
directive|define
name|HAVE_NTP_SIGND
end_define

end_unit

