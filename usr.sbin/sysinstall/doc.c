begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id$  *  * Jordan Hubbard  *  * My contributions are in the public domain.  *  * Parts of this file are also blatently stolen from Poul-Henning Kamp's  * previous version of sysinstall, and as such fall under his "BEERWARE license"  * so buy him a beer if you like it!  Buy him a beer for me, too!  * Heck, get him completely drunk and send me pictures! :-)  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_comment
comment|/*  * This is called from the main menu.  Try to find a copy of Lynx from somewhere  * and fire it up on the first copy of the handbook we can find.  */
end_comment

begin_function
name|int
name|docBrowser
parameter_list|(
name|char
modifier|*
name|junk
parameter_list|)
block|{
name|char
modifier|*
name|browser
init|=
name|variable_get
argument_list|(
name|BROWSER_PACKAGE
argument_list|)
decl_stmt|;
comment|/* Make sure we were started at a reasonable time */
if|if
condition|(
operator|!
name|variable_get
argument_list|(
name|SYSTEM_INSTALLED
argument_list|)
condition|)
block|{
name|msgConfirm
argument_list|(
literal|"Sorry, it's not possible to invoke the browser until the system\n"
literal|"is installed completely enough to support a copy of %s."
argument_list|,
name|browser
argument_list|)
expr_stmt|;
return|return
name|RET_FAIL
return|;
block|}
if|if
condition|(
operator|!
name|mediaVerify
argument_list|()
condition|)
return|return
name|RET_FAIL
return|;
comment|/* First, make sure we have whatever browser we've chosen is here */
if|if
condition|(
name|package_extract
argument_list|(
name|mediaDevice
argument_list|,
name|browser
argument_list|)
operator|!=
name|RET_SUCCESS
condition|)
block|{
name|msgConfirm
argument_list|(
literal|"Unable to install the %s HTML browser package.  You may\n"
literal|"wish to verify that your media is configured correctly and\n"
literal|"try again."
argument_list|,
name|browser
argument_list|)
expr_stmt|;
return|return
name|RET_FAIL
return|;
block|}
if|if
condition|(
operator|!
name|file_executable
argument_list|(
name|variable_get
argument_list|(
name|BROWSER_BINARY
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|msgYesNo
argument_list|(
literal|"Hmmm.  The %s package claims to have installed, but I can't\n"
literal|"find its binary in %s!  You may wish to try a different\n"
literal|"location to load the package from (go to Media menu) and see if that\n"
literal|"makes a difference.\n\n"
literal|"I suggest that we remove the version that was extracted since it does\n"
literal|"not appear to be correct.   Would you like me to do that now?"
argument_list|)
condition|)
name|vsystem
argument_list|(
literal|"pkg_delete %s %s"
argument_list|,
operator|!
name|strcmp
argument_list|(
name|variable_get
argument_list|(
name|CPIO_VERBOSITY_LEVEL
argument_list|)
argument_list|,
literal|"high"
argument_list|)
condition|?
literal|"-v"
else|:
literal|""
argument_list|,
name|browser
argument_list|)
expr_stmt|;
return|return
name|RET_FAIL
return|;
block|}
comment|/* Run browser on the appropriate doc */
name|dmenuOpenSimple
argument_list|(
operator|&
name|MenuHTMLDoc
argument_list|)
expr_stmt|;
return|return
name|RET_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* Try to show one of the documents requested from the HTML doc menu */
end_comment

begin_function
name|int
name|docShowDocument
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|browser
init|=
name|variable_get
argument_list|(
name|BROWSER_BINARY
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file_executable
argument_list|(
name|browser
argument_list|)
condition|)
block|{
name|msgConfirm
argument_list|(
literal|"Can't find the browser in %s!  Please ensure that it's\n"
literal|"properly set in the Options editor."
argument_list|,
name|browser
argument_list|)
expr_stmt|;
return|return
name|RET_FAIL
return|;
block|}
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|str
argument_list|,
literal|"Home"
argument_list|)
condition|)
name|vsystem
argument_list|(
literal|"%s http://www.freebsd.org"
argument_list|,
name|browser
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|str
argument_list|,
literal|"Other"
argument_list|)
condition|)
block|{     }
else|else
block|{
name|char
name|target
index|[
literal|512
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|target
argument_list|,
literal|"/usr/share/doc/%s/%s.html"
argument_list|,
name|str
argument_list|,
name|str
argument_list|)
expr_stmt|;
if|if
condition|(
name|file_readable
argument_list|(
name|target
argument_list|)
condition|)
name|vsystem
argument_list|(
literal|"%s file:%s"
argument_list|,
name|browser
argument_list|,
name|target
argument_list|)
expr_stmt|;
else|else
name|vsystem
argument_list|(
literal|"%s http://www.freebsd.org/%s"
argument_list|)
expr_stmt|;
block|}
return|return
name|RET_SUCCESS
return|;
block|}
end_function

end_unit

