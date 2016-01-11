begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|//#include "log.h"
end_comment

begin_include
include|#
directive|include
file|"log.c"
end_include

begin_function_decl
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testChangePrognameInMysyslog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testOpenLogfileTest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|testWriteInCustomLogfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
block|{
name|init_lib
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|//in var/log/syslog (may differ depending on your OS), logged name of the program will be "TEST_PROGNAME".
end_comment

begin_function
name|void
name|testChangePrognameInMysyslog
parameter_list|(
name|void
parameter_list|)
block|{
name|sntp_init_logging
argument_list|(
literal|"TEST_PROGNAME"
argument_list|)
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"TESTING sntp_init_logging()"
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|//writes log files in your own file instead of syslog! (MAY BE USEFUL TO SUPPRESS ERROR MESSAGES!)
end_comment

begin_function
name|void
name|testOpenLogfileTest
parameter_list|(
name|void
parameter_list|)
block|{
name|sntp_init_logging
argument_list|(
literal|"TEST_PROGNAME2"
argument_list|)
expr_stmt|;
comment|//this name is consistent through the entire program unless changed
name|open_logfile
argument_list|(
literal|"testLogfile.log"
argument_list|)
expr_stmt|;
comment|//open_logfile("/var/log/syslog"); //this gives me "Permission Denied" when i do %m
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Cannot open log file %s"
argument_list|,
literal|"abcXX"
argument_list|)
expr_stmt|;
comment|//cleanup_log(); //unnecessary  after log.c fix!
return|return;
block|}
end_function

begin_comment
comment|//multiple cleanup_log() causes segfault. Probably the reason it's static. Opening multiple open_logfile(name) will cause segfault x.x I'm guessing it's not intended to be changed. Cleanup after unity test doesn't fix it, looks like. Calling in tearDown() also causes issues.
end_comment

begin_function
name|void
name|testWriteInCustomLogfile
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|testString
index|[
literal|256
index|]
init|=
literal|"12345 ABC"
decl_stmt|;
name|char
name|testName
index|[
literal|256
index|]
init|=
literal|"TEST_PROGNAME3"
decl_stmt|;
operator|(
name|void
operator|)
name|remove
argument_list|(
literal|"testLogfile2.log"
argument_list|)
expr_stmt|;
name|sntp_init_logging
argument_list|(
name|testName
argument_list|)
expr_stmt|;
name|open_logfile
argument_list|(
literal|"testLogfile2.log"
argument_list|)
expr_stmt|;
comment|// ./ causing issues
comment|//sntp_init_logging(testName);
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s"
argument_list|,
name|testString
argument_list|)
expr_stmt|;
name|FILE
modifier|*
name|f
init|=
name|fopen
argument_list|(
literal|"testLogfile2.log"
argument_list|,
literal|"r"
argument_list|)
decl_stmt|;
name|char
name|line
index|[
literal|256
index|]
decl_stmt|;
name|TEST_ASSERT_TRUE
argument_list|(
name|f
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//should be only 1 line
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|line
argument_list|)
argument_list|,
name|f
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s"
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
name|char
modifier|*
name|x
init|=
name|strstr
argument_list|(
name|line
argument_list|,
name|testName
argument_list|)
decl_stmt|;
name|TEST_ASSERT_TRUE
argument_list|(
name|x
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|x
operator|=
name|strstr
argument_list|(
name|line
argument_list|,
name|testString
argument_list|)
expr_stmt|;
name|TEST_ASSERT_TRUE
argument_list|(
name|x
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|//cleanup_log();
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
comment|//using this will also cause segfault, because at the end, log.c will  call (using atexit(func) function) cleanup_log(void)-> fclose(syslog_file);
comment|//After the 1st fclose, syslog_file = NULL, and is never reset -> hopefully fixed by editing log.c
comment|//TEST_ASSERT_EQUAL_STRING(testString,line); //doesn't work, line is dynamic because the process name is random.
return|return;
block|}
end_function

end_unit

