begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Table of command-line options  *  * The first column specifies the short name, if any, or 0 if none.  * The second column specifies the long name.  * The third column specifies whether it takes a parameter.  * The fourth column is the documentation.  *  * N.B. The long options' order must correspond to the code in file.c,  * and OPTSTRING must be kept up-to-date with the short options.  * Pay particular attention to the numbers of long-only options in the  * switch statement!  */
end_comment

begin_macro
name|OPT_LONGONLY
argument_list|(
literal|"help"
argument_list|,
literal|0
argument_list|,
literal|"                 display this help and exit\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'v'
argument_list|,
literal|"version"
argument_list|,
literal|0
argument_list|,
literal|"              output version information and exit\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'m'
argument_list|,
literal|"magic-file"
argument_list|,
literal|1
argument_list|,
literal|" LIST      use LIST as a colon-separated list of magic\n"
literal|"                               number files\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'z'
argument_list|,
literal|"uncompress"
argument_list|,
literal|0
argument_list|,
literal|"           try to look inside compressed files\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'b'
argument_list|,
literal|"brief"
argument_list|,
literal|0
argument_list|,
literal|"                do not prepend filenames to output lines\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'c'
argument_list|,
literal|"checking-printout"
argument_list|,
literal|0
argument_list|,
literal|"    print the parsed form of the magic file, use in\n"
literal|"                               conjunction with -m to debug a new magic file\n"
literal|"                               before installing it\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'e'
argument_list|,
literal|"exclude"
argument_list|,
literal|1
argument_list|,
literal|" TEST         exclude TEST from the list of test to be\n"
literal|"                               performed for file. Valid tests are:\n"
literal|"                               %o\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'f'
argument_list|,
literal|"files-from"
argument_list|,
literal|1
argument_list|,
literal|" FILE      read the filenames to be examined from FILE\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'F'
argument_list|,
literal|"separator"
argument_list|,
literal|1
argument_list|,
literal|" STRING     use string as separator instead of `:'\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'i'
argument_list|,
literal|"mime"
argument_list|,
literal|0
argument_list|,
literal|"                 output MIME type strings (--mime-type and\n"
literal|"                               --mime-encoding)\n"
argument_list|)
end_macro

begin_macro
name|OPT_LONGONLY
argument_list|(
literal|"apple"
argument_list|,
literal|0
argument_list|,
literal|"                output the Apple CREATOR/TYPE\n"
argument_list|)
end_macro

begin_macro
name|OPT_LONGONLY
argument_list|(
literal|"mime-type"
argument_list|,
literal|0
argument_list|,
literal|"            output the MIME type\n"
argument_list|)
end_macro

begin_macro
name|OPT_LONGONLY
argument_list|(
literal|"mime-encoding"
argument_list|,
literal|0
argument_list|,
literal|"        output the MIME encoding\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'k'
argument_list|,
literal|"keep-going"
argument_list|,
literal|0
argument_list|,
literal|"           don't stop at the first match\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'l'
argument_list|,
literal|"list"
argument_list|,
literal|0
argument_list|,
literal|"                 list magic strength\n"
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_macro
name|OPT
argument_list|(
literal|'L'
argument_list|,
literal|"dereference"
argument_list|,
literal|0
argument_list|,
literal|"          follow symlinks (default)\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'h'
argument_list|,
literal|"no-dereference"
argument_list|,
literal|0
argument_list|,
literal|"       don't follow symlinks\n"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|OPT
argument_list|(
literal|'n'
argument_list|,
literal|"no-buffer"
argument_list|,
literal|0
argument_list|,
literal|"            do not buffer output\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'N'
argument_list|,
literal|"no-pad"
argument_list|,
literal|0
argument_list|,
literal|"               do not pad output\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'0'
argument_list|,
literal|"print0"
argument_list|,
literal|0
argument_list|,
literal|"               terminate filenames with ASCII NUL\n"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UTIME
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_UTIMES
argument_list|)
end_if

begin_macro
name|OPT
argument_list|(
literal|'p'
argument_list|,
literal|"preserve-date"
argument_list|,
literal|0
argument_list|,
literal|"        preserve access times on files\n"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|OPT
argument_list|(
literal|'r'
argument_list|,
literal|"raw"
argument_list|,
literal|0
argument_list|,
literal|"                  don't translate unprintable chars to \\ooo\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'s'
argument_list|,
literal|"special-files"
argument_list|,
literal|0
argument_list|,
literal|"        treat special (block/char devices) files as\n"
literal|"                             ordinary ones\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'C'
argument_list|,
literal|"compile"
argument_list|,
literal|0
argument_list|,
literal|"              compile file specified by -m\n"
argument_list|)
end_macro

begin_macro
name|OPT
argument_list|(
literal|'d'
argument_list|,
literal|"debug"
argument_list|,
literal|0
argument_list|,
literal|"                print debugging messages\n"
argument_list|)
end_macro

end_unit

