begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Macros for processing command arguments.  *  * Conforms closely to the command option requirements of intro(1) in System V  * and intro(C) in Xenix.  *  * A command consists of: cmdname [ options ] [ cmdarguments ]  *  * Options consist of a leading dash '-' and a flag letter.  An argument may  * follow optionally preceded by white space.  * Options without arguments may be grouped behind a single dash.  * A dash on its own is interpreted as the end of the options and is retained  * as a command argument.  * A double dash '--' is interpreted as the end of the options and is discarded.  *  * For example:  *	zap -xz -f flame -q34 -- -x  *  * where zap.c contains the following in main():  *  *	OPTIONS("[-xz] [-q queue-id] [-f dump-file] user")  *	    FLAG('x', xecute)  *	    FLAG('z', zot)  *	    STRING('f', file)  *		fp = fopen(file, "w");  *	    NUMBER('q', queue)  *	    ENDOPTS  *  * Results in:  *	xecute = 1  *	zot = 1  *	file = "flame"  *	fp = fopen("flame", "w")  *	queue = 34  *	argc = 2  *	argv[0] = "zap"  *	argv[1] = "-x"  *  * Should the user enter unknown flags or leave out required arguments,  * the message:  *  *	Usage: zap [-xz] [-q queue-id] [-f dump-file] user  *  * will be printed.  This message can be printed by calling pusage(), or  * usage().  usage() will also cause program termination with exit code 1.  *  * Author: Stephen McKay, February 1991  *  * Based on recollection of the original options.h produced at the University  * of Queensland by Ross Patterson (and possibly others).  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|O_usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|O_name
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|pusage
parameter_list|()
block|{
comment|/*      * Avoid gratuitously loading stdio.      */
name|write
argument_list|(
literal|2
argument_list|,
literal|"Usage: "
argument_list|,
literal|7
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|O_name
argument_list|,
name|strlen
argument_list|(
name|O_name
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|" "
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|O_usage
argument_list|,
name|strlen
argument_list|(
name|O_usage
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|usage
parameter_list|()
value|(pusage(), exit(1))
end_define

begin_define
define|#
directive|define
name|OPTIONS
parameter_list|(
name|usage_msg
parameter_list|)
define|\
value|{					\     char O_cont;			\     O_usage = (usage_msg);		\     O_name = argv[0];			\     while (*++argv&& **argv == '-')	\ 	{				\ 	if ((*argv)[1] == '\0')		\ 	    break;			\ 	argc--;				\ 	if ((*argv)[1] == '-'&& (*argv)[2] == '\0') \ 	    {				\ 	    argv++;			\ 	    break;			\ 	    }				\ 	O_cont = 1;			\ 	while (O_cont)			\ 	    switch (*++*argv)		\ 		{			\ 		default:		\ 		case '-':		\ 		    usage();		\ 		case '\0':		\ 		    O_cont = 0;
end_define

begin_define
define|#
directive|define
name|FLAG
parameter_list|(
name|x
parameter_list|,
name|flag
parameter_list|)
define|\
value|break;		\ 		case (x):		\ 		    (flag) = 1;
end_define

begin_define
define|#
directive|define
name|CHAR
parameter_list|(
name|x
parameter_list|,
name|ch
parameter_list|)
define|\
value|break;		\ 		case (x):		\ 		    O_cont = 0;		\ 		    if (*++*argv == '\0'&& (--argc, *++argv == 0)) \ 			usage();	\ 		    (ch) = **argv;
end_define

begin_define
define|#
directive|define
name|NUMBER
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
define|\
value|break;		\ 		case (x):		\ 		    O_cont = 0;		\ 		    if (*++*argv == '\0'&& (--argc, *++argv == 0)) \ 			usage();	\ 		    (n) = atol(*argv);
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|x
parameter_list|,
name|str
parameter_list|)
define|\
value|break;		\ 		case (x):		\ 		    O_cont = 0;		\ 		    if (*++*argv == '\0'&& (--argc, *++argv == 0)) \ 			usage();	\ 		    (str) = *argv;
end_define

begin_define
define|#
directive|define
name|SUFFIX
parameter_list|(
name|x
parameter_list|,
name|str
parameter_list|)
define|\
value|break;		\ 		case (x):		\ 		    (str) = ++*argv;	\ 		    O_cont = 0;
end_define

begin_define
define|#
directive|define
name|ENDOPTS
define|\
value|break;		\ 		}			\ 	}				\     *--argv = O_name;			\     }
end_define

end_unit

