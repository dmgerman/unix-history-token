begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	usage.c  *  * Show usage message.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_macro
name|usage
argument_list|(
argument|char *myname
argument_list|)
end_macro

begin_block
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|name_p
decl_stmt|;
name|name_p
operator|=
name|myname
expr_stmt|;
if|if
condition|(
name|p
operator|=
name|strrchr
argument_list|(
name|myname
argument_list|,
literal|'/'
argument_list|)
condition|)
name|name_p
operator|=
name|p
operator|+
literal|1
expr_stmt|;
comment|/* point after final '/' */
ifdef|#
directive|ifdef
name|MSDOS
if|if
condition|(
name|p
operator|=
name|strrchr
argument_list|(
name|name_p
argument_list|,
literal|'\\'
argument_list|)
condition|)
name|name_p
operator|=
name|p
operator|+
literal|1
expr_stmt|;
comment|/* point after final '\\' */
if|if
condition|(
name|p
operator|=
name|strrchr
argument_list|(
name|name_p
argument_list|,
literal|':'
argument_list|)
condition|)
name|name_p
operator|=
name|p
operator|+
literal|1
expr_stmt|;
comment|/* point after final ':' */
name|printf
argument_list|(
literal|"\nUsage: %s [-acdnpsSvw] [-Dnumber] [-i[extension]] [-Idirectory]"
else|#
directive|else
argument|printf(
literal|"\nUsage: %s [-acdnpPsSuUvw] [-Dnumber] [-i[extension]] [-Idirectory]"
endif|#
directive|endif
literal|"\n            [-e \"command\"] [-x[directory]] [filename] [arguments]\n"
argument|, name_p);    printf(
literal|"\n  -a  autosplit mode with -n or -p"
literal|"\n  -c  syntaxcheck only"
literal|"\n  -d  run scripts under debugger"
literal|"\n  -n  assume 'while (<>) { ...script... }' loop arround your script"
literal|"\n  -p  assume loop like -n but print line also like sed"
ifndef|#
directive|ifndef
name|MSDOS
literal|"\n  -P  run script through C preprocessor befor compilation"
endif|#
directive|endif
literal|"\n  -s  enable some switch parsing for switches after script name"
literal|"\n  -S  look for the script using PATH environment variable"
argument|);
ifndef|#
directive|ifndef
name|MSDOS
argument|printf(
literal|"\n  -u  dump core after compiling the script"
literal|"\n  -U  allow unsafe operations"
argument|);
endif|#
directive|endif
argument|printf(
literal|"\n  -v  print version number and patchlevel of perl"
literal|"\n  -w  turn warnings on for compilation of your script\n"
literal|"\n  -Dnumber        set debugging flags"
literal|"\n  -i[extension]   edit<> files in place (make backup if extension supplied)"
literal|"\n  -Idirectory     specify include directory in conjunction with -P"
literal|"\n  -e command      one line of script, multiple -e options are allowed"
literal|"\n                  [filename] can be ommitted, when -e is used"
literal|"\n  -x[directory]   strip off text before #!perl line and perhaps cd to directory\n"
argument|); }
end_block

end_unit

