begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * setup.c - set up all files for Phantasia  */
end_comment

begin_include
include|#
directive|include
file|"include.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: main() / / FUNCTION: setup files for Phantasia 3.3.2 / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: none / / RETURN VALUE: none / / MODULES CALLED: time(), exit(), stat(), Error(), creat(), close(), fopen(),  /	fgets(), floor(), srandom(), umask(), drandom(), strcpy(), getuid(),  /	unlink(), fwrite(), fclose(), sscanf(), printf(), strlen(), fprintf() / / GLOBAL INPUTS: Peoplefile[], Curmonster, _iob[], Databuf[], *Monstfp,  /	Lastdead[], Goldfile[], Voidfile[], Motdfile[], Messfile[], Scorefile[],  /	Enemyfile[], Monstfile[], Enrgyvoid / / GLOBAL OUTPUTS: Curmonster, Databuf[], *Monstfp, Enrgyvoid / / DESCRIPTION:  / /	This program tries to verify the parameters specified in /	the Makefile. / /	Create all necessary files.  Note that nothing needs to be /	put in these files. /	Also, the monster binary data base is created here. / /************************************************************************/
end_comment

begin_function
name|main
parameter_list|()
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* for opening files */
name|struct
name|stat
name|fbuf
decl_stmt|;
comment|/* for getting files statistics */
specifier|register
name|char
modifier|*
modifier|*
name|filename
decl_stmt|;
comment|/* for pointing to file names */
specifier|register
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
specifier|static
name|char
modifier|*
name|files
index|[]
init|=
comment|/* all files to create */
block|{
name|Monstfile
block|,
name|Peoplefile
block|,
name|Messfile
block|,
name|Lastdead
block|,
name|Motdfile
block|,
name|Goldfile
block|,
name|Voidfile
block|,
name|Scorefile
block|,
ifdef|#
directive|ifdef
name|ENEMY
name|Enemyfile
block|,
endif|#
directive|endif
operator|(
name|char
operator|*
operator|)
name|NULL
block|}
decl_stmt|;
name|srandom
argument_list|(
operator|(
name|unsigned
operator|)
name|time
argument_list|(
operator|(
name|long
operator|*
operator|)
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
comment|/* prime random numbers */
name|umask
argument_list|(
literal|0117
argument_list|)
expr_stmt|;
comment|/* only owner can read/write created files */
if|if
condition|(
name|getuid
argument_list|()
operator|!=
name|UID
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Warning: UID (%d) is not equal to current uid.\n"
argument_list|,
name|UID
argument_list|)
expr_stmt|;
comment|/* check Phantasia destination directory */
if|if
condition|(
name|stat
argument_list|(
argument|DEST
literal|",&fbuf)< 0) 	/* not found */ 	{ 	Error("
argument|Cannot stat %s.\n
literal|", DEST"
argument_list|)
empty_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_if
if|if
condition|(
operator|(
name|fbuf
operator|.
name|st_mode
operator|&
name|S_IFDIR
operator|)
operator|==
literal|0
condition|)
comment|/* not a directory */
name|Error
argument_list|(
literal|"%s is not a directory.\n"
argument_list|,
argument|DEST
literal|"); 	/*NOTREACHED*/      /* try to create data files */     filename =&files[0];     while (*filename != NULL) 	/* create each file */ 	{ 	if (stat(*filename,&fbuf) == 0) 	    /* file exists; remove it */ 	    { 	    if (*filename == Peoplefile) 		/* do not reset character file if it already exists */ 		{ 		++filename; 		continue; 		}  	    if (unlink(*filename)< 0) 		Error("
argument|Cannot unlink %s.\n
literal|", *filename); 		/*NOTREACHED*/ 	    }  	if ((fd = creat(*filename, 0660))< 0) 	    Error("
argument|Cannot create %s.\n
literal|", *filename); 	    /*NOTREACHED*/  	close(fd);			/* close newly created file */  	++filename;			/* process next file */ 	}      /* put holy grail info into energy void file */     Enrgyvoid.ev_active = TRUE;     Enrgyvoid.ev_x = ROLL(-1.0e6, 2.0e6);     Enrgyvoid.ev_y = ROLL(-1.0e6, 2.0e6);     if ((fp = fopen(Voidfile, "
argument|w
literal|")) == NULL) 	Error("
argument|Cannot update %s.\n
literal|", Voidfile);     else 	{ 	fwrite(&Enrgyvoid, SZ_VOIDSTRUCT, 1, fp); 	fclose(fp); 	}      /* create binary monster data base */     if ((Monstfp = fopen(Monstfile, "
argument|w
literal|")) == NULL) 	Error("
argument|Cannot update %s.\n
literal|", Monstfile);     else 	{ 	if ((fp = fopen("
argument|monsters.asc
literal|", "
argument|r
literal|")) == NULL) 	    { 	    fclose(Monstfp); 	    Error("
argument|cannot open %s to create monster database.\n
literal|", "
argument|monsters.asc
literal|"); 	    } 	else 	    { 	    Curmonster.m_o_strength = 	    Curmonster.m_o_speed = 	    Curmonster.m_maxspeed = 	    Curmonster.m_o_energy = 	    Curmonster.m_melee = 	    Curmonster.m_skirmish = 0.0;  	    while (fgets(Databuf, SZ_DATABUF, fp) != NULL) 		/* read in text file, convert to binary */ 		{ 		sscanf(&Databuf[24], "
argument|%lf%lf%lf%lf%lf%d%d%lf
literal|",&Curmonster.m_strength,&Curmonster.m_brains,&Curmonster.m_speed,&Curmonster.m_energy,&Curmonster.m_experience,&Curmonster.m_treasuretype,&Curmonster.m_type,&Curmonster.m_flock); 		Databuf[24] = '\0'; 		strcpy(Curmonster.m_name, Databuf); 		fwrite((char *)&Curmonster, SZ_MONSTERSTRUCT, 1, Monstfp); 		} 	    fclose(fp); 	    fclose(Monstfp); 	    } 	}  #ifdef MAKE_INSTALLS_THIS_AND_DOESNT_ANSWER_QUESTIONS     /* write to motd file */     printf("
argument|One line
literal|'motd'
argument|?
literal|");     if (fgets(Databuf, SZ_DATABUF, stdin) == NULL) 	Databuf[0] = '\0';     if ((fp = fopen(Motdfile, "
argument|w
literal|")) == NULL) 	Error("
argument|Cannot update %s.\n
literal|", Motdfile);     else 	{ 	fwrite(Databuf, sizeof(char), strlen(Databuf), fp); 	fclose(fp); 	} #endif      /* report compile-time options */     printf("
argument|Compiled options:\n\n
literal|");     printf("
argument|Phantasia destination directory:  %s\n
literal|", DEST"
argument_list|)
empty_stmt|;
end_if

begin_expr_stmt
name|printf
argument_list|(
literal|"Wizard:  %s   UID:  %d\n"
argument_list|,
name|WIZARD
argument_list|,
name|UID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OK_TO_PLAY
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Restricted playing enabled.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|printf
argument_list|(
literal|"Playing unrestricted.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENEMY
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Enemy list enabled.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|printf
argument_list|(
literal|"Enemy list disabled.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHELL
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Shell escapes enabled.  Default shell:  %s\n"
argument_list|,
name|SHELL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|printf
argument_list|(
literal|"Shell escapes disabled.\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Compiled for BSD 4.1\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD42
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Compiled for BSD 4.2\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS3
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Compiled for System III\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5
end_ifdef

begin_expr_stmt
name|printf
argument_list|(
literal|"Compiled for System V\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*NOTREACHED*/
end_comment

begin_comment
unit|}
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: Error() / / FUNCTION: print an error message, and exit / / AUTHOR: E. A. Estes, 12/4/85 / / ARGUMENTS: /	char *str - format string for printf() /	char *file - file which caused error / / RETURN VALUE: none / / MODULES CALLED: exit(), perror(), fprintf() / / GLOBAL INPUTS: _iob[] / / GLOBAL OUTPUTS: none / / DESCRIPTION: /	Print an error message, then exit. / /************************************************************************/
end_comment

begin_expr_stmt
unit|Error
operator|(
name|str
operator|,
name|file
operator|)
name|char
operator|*
name|str
operator|,
operator|*
name|file
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Error: "
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|str
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_block

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/************************************************************************ / / FUNCTION NAME: drandom() / / FUNCTION: return a random number / / AUTHOR: E. A. Estes, 2/7/86 / / ARGUMENTS: none / / RETURN VALUE: none / / MODULES CALLED: random() / / GLOBAL INPUTS: none / / GLOBAL OUTPUTS: none / / DESCRIPTION:  / /************************************************************************/
end_comment

begin_function
name|double
name|drandom
parameter_list|()
block|{
if|if
condition|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|!=
literal|2
condition|)
return|return
operator|(
call|(
name|double
call|)
argument_list|(
name|random
argument_list|()
operator|&
literal|0x7fff
argument_list|)
operator|/
literal|32768.0
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|double
operator|)
name|random
argument_list|()
operator|/
literal|32768.0
operator|)
return|;
block|}
end_function

end_unit

