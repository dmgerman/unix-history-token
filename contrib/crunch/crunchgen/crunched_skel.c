begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* File created via mkskel.sh */
end_comment

begin_decl_stmt
name|char
modifier|*
name|crunched_skel
index|[]
init|=
block|{
literal|"/*"
block|,
literal|" * Copyright (c) 1994 University of Maryland"
block|,
literal|" * All Rights Reserved."
block|,
literal|" *"
block|,
literal|" * Permission to use, copy, modify, distribute, and sell this software and its"
block|,
literal|" * documentation for any purpose is hereby granted without fee, provided that"
block|,
literal|" * the above copyright notice appear in all copies and that both that"
block|,
literal|" * copyright notice and this permission notice appear in supporting"
block|,
literal|" * documentation, and that the name of U.M. not be used in advertising or"
block|,
literal|" * publicity pertaining to distribution of the software without specific,"
block|,
literal|" * written prior permission.  U.M. makes no representations about the"
block|,
literal|" * suitability of this software for any purpose.  It is provided \"as is\""
block|,
literal|" * without express or implied warranty."
block|,
literal|" *"
block|,
literal|" * U.M. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL"
block|,
literal|" * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL U.M."
block|,
literal|" * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES"
block|,
literal|" * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION"
block|,
literal|" * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN"
block|,
literal|" * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE."
block|,
literal|" *"
block|,
literal|" * Author: James da Silva, Systems Design and Analysis Group"
block|,
literal|" *			   Computer Science Department"
block|,
literal|" *			   University of Maryland at College Park"
block|,
literal|" */"
block|,
literal|"/*"
block|,
literal|" * crunched_main.c - main program for crunched binaries, it branches to a "
block|,
literal|" * 	particular subprogram based on the value of argv[0].  Also included"
block|,
literal|" *	is a little program invoked when the crunched binary is called via"
block|,
literal|" *	its EXECNAME.  This one prints out the list of compiled-in binaries,"
block|,
literal|" *	or calls one of them based on argv[1].   This allows the testing of"
block|,
literal|" *	the crunched binary without creating all the links."
block|,
literal|" */"
block|,
literal|"#include<stdio.h>"
block|,
literal|"#include<string.h>"
block|,
literal|""
block|,
literal|"struct stub {"
block|,
literal|"    char *name;"
block|,
literal|"    int (*f)();"
block|,
literal|"};"
block|,
literal|""
block|,
literal|"extern struct stub entry_points[];"
block|,
literal|""
block|,
literal|"int main(int argc, char **argv)"
block|,
literal|"{"
block|,
literal|"    char *slash, *basename;"
block|,
literal|"    struct stub *ep;"
block|,
literal|""
block|,
literal|"    if(argv[0] == NULL || *argv[0] == '\\0')"
block|,
literal|"	crunched_usage();"
block|,
literal|""
block|,
literal|"    slash = strrchr(argv[0], '/');"
block|,
literal|"    basename = slash? slash+1 : argv[0];"
block|,
literal|""
block|,
literal|"    for(ep=entry_points; ep->name != NULL; ep++)"
block|,
literal|"	if(!strcmp(basename, ep->name)) break;"
block|,
literal|""
block|,
literal|"    if(ep->name)"
block|,
literal|"	return ep->f(argc, argv);"
block|,
literal|"    else {"
block|,
literal|"	fprintf(stderr, \"%s: %s not compiled in\\n\", EXECNAME, basename);"
block|,
literal|"	crunched_usage();"
block|,
literal|"    }"
block|,
literal|"}"
block|,
literal|""
block|,
literal|""
block|,
literal|"int crunched_main(int argc, char **argv)"
block|,
literal|"{"
block|,
literal|"    struct stub *ep;"
block|,
literal|"    int columns, len;"
block|,
literal|""
block|,
literal|"    if(argc<= 1) "
block|,
literal|"	crunched_usage();"
block|,
literal|""
block|,
literal|"    return main(--argc, ++argv);"
block|,
literal|"}"
block|,
literal|""
block|,
literal|""
block|,
literal|"int crunched_usage()"
block|,
literal|"{"
block|,
literal|"    int columns, len;"
block|,
literal|"    struct stub *ep;"
block|,
literal|""
block|,
literal|"    fprintf(stderr, \"Usage: %s<prog><args> ..., where<prog> is one of:\\n\","
block|,
literal|"	    EXECNAME);"
block|,
literal|"    columns = 0;"
block|,
literal|"    for(ep=entry_points; ep->name != NULL; ep++) {"
block|,
literal|"	len = strlen(ep->name) + 1;"
block|,
literal|"	if(columns+len< 80)"
block|,
literal|"	    columns += len;"
block|,
literal|"	else {"
block|,
literal|"	    fprintf(stderr, \"\\n\");"
block|,
literal|"	    columns = len;"
block|,
literal|"	}"
block|,
literal|"	fprintf(stderr, \" %s\", ep->name);"
block|,
literal|"    }"
block|,
literal|"    fprintf(stderr, \"\\n\");"
block|,
literal|"    exit(1);"
block|,
literal|"}"
block|,
literal|""
block|,
literal|"/* end of crunched_main.c */"
block|,
literal|""
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

end_unit

