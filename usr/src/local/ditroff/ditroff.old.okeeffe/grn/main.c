begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	main.c	1.8	(Berkeley) 83/09/23  *  *	This file contains the main and file system dependent routines  * for processing gremlin files into troff input.  The program watches  * input go by to standard output, only interpretting things between .GS  * and .GE lines.  Default values may be overridden, as in gprint, on the  * command line and are further overridden by commands in the input.  A  * description of the command-line options are listed below.  A space is  * NOT required for the operand of an option.  *  *	command options are:  *  *	-r ss	sets gremlin's roman font to troff font ss.  Also for -i,  *		-b and -s for italics, bold, and special fonts.  This does  *		NOT affect font changes imbedded into strings.  A \fI, for  *		instance, will get the italics font regardless of what -i  *		is set to.  *  *	-1 #	sets point size 1 to #.  also for -2, -3, -4.  Defaults  *		are 12, 16, 24, 36.  *  *	-n #	set narrow line thickness to # pixels.  Also for -m (medium)  *		and -t (thick).  Defaults are 1, 3, and 5 pixels.  *  *	-x #	scale the picture by x (integer or decimal).  *  *	-T dev	Prepare output for "dev" printer.  Default is for the varian  *		and versatec printers.  Devices acceptable are:  ver, var, ip.  *  *	-p	prompt user for fonts, sizes and thicknesses.  *  *  *		Inside the GS and GE, there are commands similar to command-  *	    line options listed above.  At most one command may reside on each  *	    line, and each command is followed by a parameter separated by white  *	    space.  The commands are as follows, and may be abbreviated down to  *	    one character (with exception of "scale" down to "sc") and may be  *	    upper or lower case.  *  *			   1, 2, 3, 4  -  set size 1, 2, 3, or 4 (followed  *	roman, italics, bold, special  -  set gremlin's fonts to any other  *					  troff font (one or two characters)  *			     scale, x  -  scale is IN ADDITION to the global  *					  scale factor from the -x option.  *		narrow, medium, thick  -  set pixel widths of lines.  *				 file  -  set the file name to read the  *					  gremlin picture from.  *			width, height  -  these two commands override any  *					  scaling factor that is in effect,  *					  and forces the picture to fit into  *					  either the height or width specified,  *					  whichever makes the picture smaller.  *					  The operand for these two commands is  *					  a floating-point number in units of  *					  inches  *  *	Troff number registers used:  g1 through g9.  g1 is the width of the  *	picture, and g2 is the height.  g2-g6 save information, g8 and g9 are  *	used for text processing and g7 is reserved.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"gprint.h"
end_include

begin_include
include|#
directive|include
file|"dev.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* database imports */
end_comment

begin_extern
extern|extern HGPrintElt(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|extern
name|ELT
modifier|*
name|DBInit
argument_list|()
decl_stmt|,
modifier|*
name|DBRead
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|POINT
modifier|*
name|PTInit
argument_list|()
decl_stmt|,
modifier|*
name|PTMakePoint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GREMLIB
value|"/usr/local/gremlib/"
end_define

begin_define
define|#
directive|define
name|DEVDIR
value|"/usr/lib/font/dev"
end_define

begin_define
define|#
directive|define
name|DEFAULTDEV
value|"var"
end_define

begin_define
define|#
directive|define
name|MAXINLINE
value|100
end_define

begin_comment
comment|/* input line length */
end_comment

begin_define
define|#
directive|define
name|DEFTHICK
value|3
end_define

begin_comment
comment|/* default thicknes */
end_comment

begin_define
define|#
directive|define
name|DEFSTYLE
value|SOLID
end_define

begin_comment
comment|/* default line style */
end_comment

begin_define
define|#
directive|define
name|SCREENtoINCH
value|0.02
end_define

begin_comment
comment|/* scaling factor, screen to inches */
end_comment

begin_define
define|#
directive|define
name|BIG
value|100000000000.0
end_define

begin_comment
comment|/* unweildly large floating number */
end_comment

begin_define
define|#
directive|define
name|JLEFT
value|-1
end_define

begin_comment
comment|/* justification constants - for the */
end_comment

begin_define
define|#
directive|define
name|JCENTER
value|0
end_define

begin_comment
comment|/*    whole picture - where it will */
end_comment

begin_define
define|#
directive|define
name|JRIGHT
value|1
end_define

begin_comment
comment|/*    get placed within the line */
end_comment

begin_decl_stmt
name|char
name|SccsId
index|[]
init|=
literal|"main.c	1.8	83/09/23"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|printer
init|=
name|DEFAULTDEV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device to look up resolution of */
end_comment

begin_decl_stmt
name|double
name|res
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* that printer's resolution goes here */
end_comment

begin_decl_stmt
name|int
name|linethickness
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* brush styles */
end_comment

begin_decl_stmt
name|int
name|linmod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* point registers for printing elements */
end_comment

begin_decl_stmt
name|int
name|lasty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lastyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a line's vertical position is NOT the same */
end_comment

begin_comment
comment|/* after that line is over, so for a line of */
end_comment

begin_comment
comment|/* drawing commands, vertical spacing is kept */
end_comment

begin_comment
comment|/* in lastyline */
end_comment

begin_decl_stmt
name|double
name|scale
init|=
name|SCREENtoINCH
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default scale to map gremlin screen to inches 				   (modified by -x command-line option) */
end_comment

begin_comment
comment|/* list of prompts for asking user to set default values */
end_comment

begin_decl_stmt
name|char
modifier|*
name|prompt
index|[]
init|=
block|{
comment|/* used only for -p option */
literal|"Roman font name? (%s): "
block|,
literal|"Italic font name? (%s): "
block|,
literal|"Bold font name? (%s): "
block|,
literal|"Special font name? (%s): "
block|,
literal|"font size 1? (%s): "
block|,
literal|"font size 2? (%s): "
block|,
literal|"font size 3? (%s): "
block|,
literal|"font size 4? (%s): "
block|, 	}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these are the default fonts, sizes, */
end_comment

begin_comment
comment|/*   line styles, and thicknesses.  These */
end_comment

begin_comment
comment|/*   can be modified from command-line */
end_comment

begin_comment
comment|/*   options, and are reset each time the */
end_comment

begin_comment
comment|/*   start of a picture (.GS) is found. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|defstring
index|[]
init|=
block|{
literal|"R\0         "
block|,
literal|"I\0         "
block|,
literal|"B\0         "
block|,
literal|"S\0         "
block|,
literal|"10\0        "
block|,
literal|"16\0        "
block|,
literal|"24\0        "
block|,
literal|"36\0        "
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|defthick
index|[
name|STYLES
index|]
init|=
block|{
literal|1
block|,
literal|1
block|,
literal|5
block|,
literal|1
block|,
literal|1
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defaults... */
end_comment

begin_decl_stmt
name|int
name|style
index|[
name|STYLES
index|]
init|=
block|{
name|DOTTED
block|,
name|DOTDASHED
block|,
name|SOLID
block|,
name|DASHED
block|,
name|SOLID
block|,
name|SOLID
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|thick
index|[
name|STYLES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* thicknesses set by defaults, then by commands */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tfont
index|[
name|FONTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fonts originally set to defstring values, then */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tsize
index|[
name|SIZES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*    optionally changed by commands inside grn */
end_comment

begin_decl_stmt
name|double
name|xscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scaling factor from individual pictures */
end_comment

begin_decl_stmt
name|double
name|troffscale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scaling factor at output time */
end_comment

begin_decl_stmt
name|double
name|width
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user-request maximum width for picture (in inches) */
end_comment

begin_decl_stmt
name|double
name|height
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user-request height */
end_comment

begin_decl_stmt
name|double
name|toppoint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remember the picture */
end_comment

begin_decl_stmt
name|double
name|bottompoint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bounds in these variables */
end_comment

begin_decl_stmt
name|double
name|leftpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|rightpoint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ytop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these are integer versions of the above */
end_comment

begin_decl_stmt
name|int
name|ybottom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so not to convert each time they're used */
end_comment

begin_decl_stmt
name|int
name|xleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|xright
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linenum
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number of input file */
end_comment

begin_decl_stmt
name|char
name|inputline
index|[
name|MAXINLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* spot to filter through the file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|c1
init|=
name|inputline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* c1, c2, and c3 will be used to */
end_comment

begin_decl_stmt
name|char
modifier|*
name|c2
init|=
name|inputline
operator|+
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hunt for lines that begin with */
end_comment

begin_decl_stmt
name|char
modifier|*
name|c3
init|=
name|inputline
operator|+
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ".GS" by looking individually */
end_comment

begin_decl_stmt
name|char
name|GScommand
index|[
name|MAXINLINE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* put user's ".GS" command line here */
end_comment

begin_decl_stmt
name|char
name|gremlinfile
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename to use for a picture */
end_comment

begin_function_decl
name|char
modifier|*
name|doinput
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	main (argument_count, argument_pointer)  |  | Results:	parses the command line, accumulating input file names, then  |		reads the inputs, passing it directly to output until a ".GS"  |		line is read.  Main then passes control to "conv" to do the  |		gremlin file conversions.  |  | Bugs:	a -p option ALWAYS reads standard input.  Even if the input  |		file is coming in that way.  *----------------------------------------------------------------------------*/
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|FILE
modifier|*
name|fp
init|=
name|stdin
decl_stmt|;
specifier|register
name|int
name|k
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
name|char
modifier|*
name|file
index|[
literal|50
index|]
decl_stmt|,
name|string
index|[
literal|50
index|]
decl_stmt|;
name|float
name|mult
decl_stmt|;
name|int
name|brsh
decl_stmt|,
name|gfil
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|operand
parameter_list|()
function_decl|;
while|while
condition|(
operator|--
name|argc
condition|)
block|{
if|if
condition|(
operator|*
operator|*
operator|++
name|argv
operator|!=
literal|'-'
condition|)
name|file
index|[
name|gfil
operator|++
index|]
operator|=
operator|*
name|argv
expr_stmt|;
else|else
switch|switch
condition|(
name|c
operator|=
operator|(
operator|*
name|argv
operator|)
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'1'
case|:
comment|/* select sizes */
case|case
literal|'2'
case|:
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
name|strcpy
argument_list|(
name|defstring
index|[
name|c
operator|+
name|FONTS
operator|-
literal|'1'
index|]
argument_list|,
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* select Roman font */
name|strcpy
argument_list|(
name|defstring
index|[
literal|0
index|]
argument_list|,
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* select italics font */
name|strcpy
argument_list|(
name|defstring
index|[
literal|1
index|]
argument_list|,
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
comment|/* select bold font */
name|strcpy
argument_list|(
name|defstring
index|[
literal|2
index|]
argument_list|,
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* select special font */
name|strcpy
argument_list|(
name|defstring
index|[
literal|3
index|]
argument_list|,
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
comment|/* select narrow brush width */
operator|(
name|void
operator|)
name|sscanf
argument_list|(
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|0
index|]
operator|=
name|defthick
index|[
literal|1
index|]
operator|=
name|defthick
index|[
literal|3
index|]
operator|=
name|defthick
index|[
literal|4
index|]
operator|=
name|brsh
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* select thick brush width */
operator|(
name|void
operator|)
name|sscanf
argument_list|(
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|2
index|]
operator|=
name|brsh
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* select medium brush width */
operator|(
name|void
operator|)
name|sscanf
argument_list|(
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|5
index|]
operator|=
name|brsh
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
comment|/* select scale */
name|sscanf
argument_list|(
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
argument_list|,
literal|"%f"
argument_list|,
operator|&
name|mult
argument_list|)
expr_stmt|;
name|scale
operator|*=
name|mult
expr_stmt|;
break|break;
case|case
literal|'T'
case|:
comment|/* final output typesetter name */
name|printer
operator|=
name|operand
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
comment|/* prompt for font and size parameters */
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
literal|8
condition|;
name|k
operator|++
control|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|prompt
index|[
name|k
index|]
argument_list|,
name|defstring
index|[
name|k
index|]
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
condition|)
name|strcpy
argument_list|(
name|defstring
index|[
name|k
index|]
argument_list|,
name|string
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"narrow brush size? (%d): "
argument_list|,
name|defthick
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
condition|)
block|{
name|sscanf
argument_list|(
name|string
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|0
index|]
operator|=
name|defthick
index|[
literal|1
index|]
operator|=
name|defthick
index|[
literal|3
index|]
operator|=
name|defthick
index|[
literal|4
index|]
operator|=
name|brsh
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"medium brush size? (%d): "
argument_list|,
name|defthick
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
condition|)
block|{
name|sscanf
argument_list|(
name|string
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|5
index|]
operator|=
name|brsh
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"thick brush size? (%d): "
argument_list|,
name|defthick
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|gets
argument_list|(
name|string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|string
operator|!=
literal|'\0'
condition|)
block|{
name|sscanf
argument_list|(
name|string
argument_list|,
literal|"%d"
argument_list|,
operator|&
name|brsh
argument_list|)
expr_stmt|;
name|defthick
index|[
literal|2
index|]
operator|=
name|brsh
expr_stmt|;
block|}
break|break;
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"unknown switch: %c\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* set the resolution for an output device */
name|getres
argument_list|(
name|printer
argument_list|)
expr_stmt|;
comment|/* named in "printer" */
if|if
condition|(
name|gfil
operator|==
literal|0
condition|)
block|{
comment|/* no filename, use standard input */
name|file
index|[
literal|0
index|]
operator|=
name|NULL
expr_stmt|;
name|gfil
operator|++
expr_stmt|;
block|}
for|for
control|(
name|k
operator|=
literal|0
init|;
name|k
operator|<
name|gfil
condition|;
name|k
operator|++
control|)
block|{
if|if
condition|(
name|file
index|[
name|k
index|]
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|file
index|[
name|k
index|]
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"grn: can't open %s\n"
argument_list|,
name|file
index|[
name|k
index|]
argument_list|)
expr_stmt|;
continue|continue;
block|}
block|}
else|else
block|{
name|fp
operator|=
name|stdin
expr_stmt|;
block|}
while|while
condition|(
name|doinput
argument_list|(
name|fp
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|*
name|c1
operator|==
literal|'.'
operator|&&
operator|*
name|c2
operator|==
literal|'G'
operator|&&
operator|*
name|c3
operator|==
literal|'S'
condition|)
block|{
name|conv
argument_list|(
name|fp
argument_list|,
name|linenum
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|fputs
argument_list|(
name|inputline
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	char  * operand (& argc,& argv)  |  | Results:	returns address of the operand given with a command-line  |		option.  It uses either "-Xoperand" or "-X operand", whichever  |		is present.  The program is terminated if no option is present.  |  | Side Efct:	argc and argv are updated as necessary.  *----------------------------------------------------------------------------*/
end_comment

begin_function
name|char
modifier|*
name|operand
parameter_list|(
name|argcp
parameter_list|,
name|argvp
parameter_list|)
name|int
modifier|*
name|argcp
decl_stmt|;
name|char
modifier|*
modifier|*
modifier|*
name|argvp
decl_stmt|;
block|{
if|if
condition|(
operator|(
operator|*
operator|*
name|argvp
operator|)
index|[
literal|2
index|]
condition|)
return|return
operator|(
operator|*
operator|*
name|argvp
operator|+
literal|2
operator|)
return|;
comment|/* operand immediately follows */
if|if
condition|(
operator|(
operator|--
operator|*
name|argcp
operator|)
operator|<=
literal|0
condition|)
block|{
comment|/* no operand */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"command-line option operand missing.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|*
operator|(
operator|++
operator|(
operator|*
name|argvp
operator|)
operator|)
operator|)
return|;
comment|/* operand is next word */
block|}
end_function

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	getres (device_name)  |  | Results:	sets "res" to the resolution of the output device specified  |		by the string dev.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|getres
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|fin
decl_stmt|;
name|struct
name|dev
name|device
decl_stmt|;
name|char
name|temp
index|[
literal|60
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"%s%s/DESC.out"
argument_list|,
name|DEVDIR
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fin
operator|=
name|open
argument_list|(
name|temp
argument_list|,
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't open tables for %s\n"
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|read
argument_list|(
name|fin
argument_list|,
operator|&
name|device
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|res
operator|=
operator|(
name|double
operator|)
name|device
operator|.
name|res
expr_stmt|;
name|close
argument_list|(
name|fin
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	char  * doinput (file_pointer)  |  | Results:	a line of input is read into "inputline".  |  | Side Efct:	"linenum" is incremented.  |  | Bugs:	lines longer than MAXINLINE are NOT checked, except for   |		updating "linenum"  *----------------------------------------------------------------------------*/
end_comment

begin_function
name|char
modifier|*
name|doinput
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|k
decl_stmt|;
if|if
condition|(
operator|(
name|k
operator|=
name|fgets
argument_list|(
name|inputline
argument_list|,
name|MAXINLINE
argument_list|,
name|fp
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|k
return|;
if|if
condition|(
name|index
argument_list|(
name|inputline
argument_list|,
literal|'\n'
argument_list|)
condition|)
comment|/* ++ only if it's a complete line */
name|linenum
operator|++
expr_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
operator|!
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	initpic ( )  |  | Results:	sets all parameters to the normal defaults, possibly overridden  |		by the command line flags.  Initilaize the picture variables,  |		and output the startup commands to troff to begin the picture.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|initpic
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|STYLES
condition|;
name|i
operator|++
control|)
block|{
comment|/* line thickness defaults */
name|thick
index|[
name|i
index|]
operator|=
name|defthick
index|[
name|i
index|]
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|FONTS
condition|;
name|i
operator|++
control|)
block|{
comment|/* font name defaults */
name|tfont
index|[
name|i
index|]
operator|=
name|defstring
index|[
name|i
index|]
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SIZES
condition|;
name|i
operator|++
control|)
block|{
comment|/* font size defaults */
name|tsize
index|[
name|i
index|]
operator|=
name|defstring
index|[
name|FONTS
operator|+
name|i
index|]
expr_stmt|;
block|}
name|gremlinfile
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
comment|/* filename is "null" */
name|toppoint
operator|=
name|BIG
expr_stmt|;
comment|/* set the picture bounds out */
name|bottompoint
operator|=
literal|0.0
expr_stmt|;
comment|/* of range so they'll be set */
name|leftpoint
operator|=
name|BIG
expr_stmt|;
comment|/* by "savebounds" on input */
name|rightpoint
operator|=
literal|0.0
expr_stmt|;
name|xscale
operator|=
name|scale
expr_stmt|;
comment|/* default scale of individual pictures */
name|width
operator|=
literal|0.0
expr_stmt|;
comment|/* size specifications input by user */
name|height
operator|=
literal|0.0
expr_stmt|;
name|linethickness
operator|=
name|DEFTHICK
expr_stmt|;
comment|/* brush styles */
name|linmod
operator|=
name|DEFSTYLE
expr_stmt|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	conv (file_pointer, starting_line)  |  | Results:	at this point, we just passed a ".GS" line in the input file.  |		conv reads the input and calls "interpret" to process commands,  |		gathering up information until a ".GE" line is found.  It then  |		calls "HGPrint" to do the translation of the gremlin file to  |		troff commands.  *----------------------------------------------------------------------------*/
end_comment

begin_expr_stmt
name|conv
argument_list|(
name|fp
argument_list|,
name|baseline
argument_list|)
specifier|register
name|FILE
operator|*
name|fp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|baseline
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|FILE
modifier|*
name|gfp
init|=
name|NULL
decl_stmt|;
specifier|register
name|int
name|done
init|=
literal|0
decl_stmt|;
specifier|register
name|ELT
modifier|*
name|e
decl_stmt|;
name|ELT
modifier|*
name|PICTURE
decl_stmt|;
name|double
name|temp
decl_stmt|;
name|POINT
name|ptr
decl_stmt|;
name|initpic
argument_list|()
expr_stmt|;
comment|/* set defaults, ranges, etc. */
name|strcpy
argument_list|(
name|GScommand
argument_list|,
name|inputline
argument_list|)
expr_stmt|;
comment|/* save ".GS" line for later */
do|do
block|{
name|done
operator|=
operator|(
name|doinput
argument_list|(
name|fp
argument_list|)
operator|==
name|NULL
operator|)
expr_stmt|;
comment|/* test for EOF */
name|done
operator||=
operator|(
operator|*
name|c1
operator|==
literal|'.'
operator|&&
operator|*
name|c2
operator|==
literal|'G'
operator|&&
operator|*
name|c3
operator|==
literal|'E'
operator|)
expr_stmt|;
comment|/*  and .GE */
if|if
condition|(
name|done
condition|)
block|{
if|if
condition|(
operator|!
name|gremlinfile
index|[
literal|0
index|]
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"grn: at line %d: no picture filename.\n"
argument_list|,
name|baseline
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|gfp
operator|=
name|fopen
argument_list|(
name|gremlinfile
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|char
name|name
index|[
literal|100
index|]
decl_stmt|;
comment|/* if the file isn't in the current */
comment|/* directory, try the gremlin library */
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"%s%s"
argument_list|,
name|GREMLIB
argument_list|,
name|gremlinfile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|gfp
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"grn: can't open %s\n"
argument_list|,
name|gremlinfile
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|PICTURE
operator|=
name|DBRead
argument_list|(
name|gfp
argument_list|)
expr_stmt|;
comment|/* read picture file */
name|fclose
argument_list|(
name|gfp
argument_list|)
expr_stmt|;
if|if
condition|(
name|DBNullelt
argument_list|(
name|PICTURE
argument_list|)
condition|)
return|return;
comment|/* if a request is made to make the */
comment|/* picture fit into a specific area, */
comment|/* set the scale to do that. */
if|if
condition|(
operator|(
name|temp
operator|=
name|bottompoint
operator|-
name|toppoint
operator|)
operator|<
literal|0.1
condition|)
name|temp
operator|=
literal|0.1
expr_stmt|;
name|temp
operator|=
operator|(
name|height
operator|!=
literal|0.0
operator|)
condition|?
name|height
operator|/
name|temp
else|:
name|BIG
expr_stmt|;
if|if
condition|(
operator|(
name|troffscale
operator|=
name|rightpoint
operator|-
name|leftpoint
operator|)
operator|<
literal|0.1
condition|)
name|troffscale
operator|=
literal|0.1
expr_stmt|;
name|troffscale
operator|=
operator|(
name|width
operator|!=
literal|0.0
operator|)
condition|?
name|width
operator|/
name|troffscale
else|:
name|BIG
expr_stmt|;
if|if
condition|(
name|temp
operator|==
name|BIG
operator|&&
name|troffscale
operator|==
name|BIG
condition|)
block|{
name|troffscale
operator|=
name|xscale
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|temp
operator|<
name|troffscale
condition|)
name|troffscale
operator|=
name|temp
expr_stmt|;
block|}
name|troffscale
operator|*=
name|res
expr_stmt|;
comment|/* change to device units from inches */
name|ytop
operator|=
name|toppoint
operator|*
name|troffscale
expr_stmt|;
comment|/* calculate integer */
name|ybottom
operator|=
name|bottompoint
operator|*
name|troffscale
expr_stmt|;
comment|/* versions of the */
name|xleft
operator|=
name|leftpoint
operator|*
name|troffscale
expr_stmt|;
comment|/* picture limits */
name|xright
operator|=
name|rightpoint
operator|*
name|troffscale
expr_stmt|;
comment|/* save stuff in number registers, */
comment|/*   register g1 = picture width and */
comment|/*   register g2 = picture height, */
comment|/*   set vertical spacing, no fill, */
comment|/*   and break (to make sure picture */
comment|/*   starts on left), and put out the */
comment|/*   user's ".GS" line. */
name|printf
argument_list|(
literal|".nr g1 %d\n.nr g2 %d\n"
argument_list|,
name|xright
operator|-
name|xleft
argument_list|,
name|ybottom
operator|-
name|ytop
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".br\n%s"
argument_list|,
name|GScommand
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr g3 \\n(.f\n.nr g4 \\n(.s\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".nr g5 \\n(.v\n.nr g6 \\n(.u\n.nf\n.vs 0"
argument_list|)
expr_stmt|;
name|lastx
operator|=
name|xleft
expr_stmt|;
comment|/* note where we are, (upper left */
name|lastyline
operator|=
name|lasty
operator|=
name|ytop
expr_stmt|;
comment|/* corner of the picture) */
name|e
operator|=
name|PICTURE
expr_stmt|;
while|while
condition|(
operator|!
name|DBNullelt
argument_list|(
name|e
argument_list|)
condition|)
block|{
name|HGPrintElt
argument_list|(
name|e
argument_list|)
expr_stmt|;
comment|/* traverse picture;  print elements */
name|e
operator|=
name|DBNextElt
argument_list|(
name|e
argument_list|)
expr_stmt|;
block|}
comment|/* end picture at lower left */
name|ptr
operator|.
name|x
operator|=
name|leftpoint
expr_stmt|;
name|ptr
operator|.
name|y
operator|=
name|bottompoint
expr_stmt|;
name|tmove
argument_list|(
operator|&
name|ptr
argument_list|)
expr_stmt|;
comment|/* restore default line parameters, */
comment|/* put out the ".GE" line from user */
comment|/* then restore everything to the way */
comment|/* it was before the .GS */
name|printf
argument_list|(
literal|"\\D't %du'\\D's %du'\n"
argument_list|,
name|DEFTHICK
argument_list|,
name|DEFSTYLE
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".ft \\n(g3\n.ps \\n(g4\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|".vs \\n(g5u\n.if \\n(g6 .fi\n%s"
argument_list|,
name|inputline
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|interpret
argument_list|(
name|inputline
argument_list|)
expr_stmt|;
comment|/* take commands from the input file */
block|}
block|}
do|while
condition|(
operator|!
name|done
condition|)
do|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	savebounds (x_coordinate, y_coordinate)  |  | Results:	keeps track of the maximum and minimum extent of a picture  |		in the global variables:  left-, right-, top- and bottompoint.  |		"savebounds" assumes that the points have been oriented to  |		the correct direction.  No scaling has taken place, though.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|savebounds
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|float
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|y
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|x
operator|<
name|leftpoint
condition|)
name|leftpoint
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|x
operator|>
name|rightpoint
condition|)
name|rightpoint
operator|=
name|x
expr_stmt|;
if|if
condition|(
name|y
operator|<
name|toppoint
condition|)
name|toppoint
operator|=
name|y
expr_stmt|;
if|if
condition|(
name|y
operator|>
name|bottompoint
condition|)
name|bottompoint
operator|=
name|y
expr_stmt|;
block|}
end_block

begin_comment
comment|/*----------------------------------------------------------------------------*  | Routine:	interpret (character_string)  |  | Results:	commands are taken from the input string and performed.  |		Commands are separated by the endofline, and are of the  |		format:  |			string1 string2  |  |		where string1 is the command and string2 is the argument.  |  | Side Efct:	font and size strings, plus the gremlin file name and the  |		width and height variables are set by this routine.  *----------------------------------------------------------------------------*/
end_comment

begin_macro
name|interpret
argument_list|(
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|str1
index|[
name|MAXINLINE
index|]
decl_stmt|;
name|char
name|str2
index|[
name|MAXINLINE
index|]
decl_stmt|;
specifier|register
name|char
modifier|*
name|chr
decl_stmt|;
name|sscanf
argument_list|(
name|line
argument_list|,
literal|"%80s%80s"
argument_list|,
operator|&
name|str1
index|[
literal|0
index|]
argument_list|,
operator|&
name|str2
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|chr
operator|=
operator|&
name|str1
index|[
literal|0
index|]
init|;
operator|*
name|chr
condition|;
name|chr
operator|++
control|)
comment|/* convert command to */
if|if
condition|(
name|isupper
argument_list|(
operator|*
name|chr
argument_list|)
condition|)
operator|*
name|chr
operator|=
name|tolower
argument_list|(
operator|*
name|chr
argument_list|)
expr_stmt|;
comment|/* lower case */
switch|switch
condition|(
name|str1
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'1'
case|:
case|case
literal|'2'
case|:
comment|/* font sizes */
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
name|tsize
index|[
name|str1
index|[
literal|0
index|]
operator|-
literal|'1'
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|tsize
index|[
name|str1
index|[
literal|0
index|]
operator|-
literal|'1'
index|]
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* roman */
name|tfont
index|[
literal|0
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|tfont
index|[
literal|0
index|]
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|/* italics */
name|tfont
index|[
literal|1
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|tfont
index|[
literal|1
index|]
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
comment|/* bold */
name|tfont
index|[
literal|2
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|tfont
index|[
literal|2
index|]
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
comment|/* special */
if|if
condition|(
name|str1
index|[
literal|1
index|]
operator|==
literal|'c'
condition|)
goto|goto
name|scalecommand
goto|;
name|tfont
index|[
literal|3
index|]
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|str2
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|tfont
index|[
literal|3
index|]
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
comment|/* thick */
name|thick
index|[
literal|2
index|]
operator|=
name|atoi
argument_list|(
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
comment|/* medium */
name|thick
index|[
literal|5
index|]
operator|=
name|atoi
argument_list|(
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
comment|/* narrow */
name|thick
index|[
literal|0
index|]
operator|=
name|thick
index|[
literal|1
index|]
operator|=
name|thick
index|[
literal|3
index|]
operator|=
name|thick
index|[
literal|4
index|]
operator|=
name|atoi
argument_list|(
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
comment|/* x */
name|scalecommand
label|:
comment|/* scale */
name|xscale
operator|*=
name|atof
argument_list|(
name|str2
argument_list|)
expr_stmt|;
if|if
condition|(
name|xscale
operator|<
literal|0.0
condition|)
name|xscale
operator|=
operator|-
name|xscale
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|/* file */
name|strcpy
argument_list|(
name|gremlinfile
argument_list|,
name|str2
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
comment|/* width */
name|width
operator|=
name|atof
argument_list|(
name|str2
argument_list|)
expr_stmt|;
if|if
condition|(
name|width
operator|<
literal|0.0
condition|)
name|width
operator|=
operator|-
name|width
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
comment|/* height */
name|height
operator|=
name|atof
argument_list|(
name|str2
argument_list|)
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|0.0
condition|)
name|height
operator|=
operator|-
name|height
expr_stmt|;
break|break;
default|default:
break|break;
block|}
empty_stmt|;
block|}
end_block

end_unit

