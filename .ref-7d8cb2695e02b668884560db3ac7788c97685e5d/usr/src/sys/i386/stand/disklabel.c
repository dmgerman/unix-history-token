begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)disklabel.c	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STANDALONE
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|stderr
value|0
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<disktab.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|"disk.h"
end_include

begin_define
define|#
directive|define
name|BOOTSIZE
value|(8*1024)
end_define

begin_comment
comment|/* size of boot "block" */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STANDALONE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TP
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|standdisk
init|=
literal|"cst2d:"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|st506boot
init|=
literal|"cst2e:"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ST506 boot block */
end_comment

begin_decl_stmt
name|char
modifier|*
name|scsiboot
init|=
literal|"cst2f:"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCSI boot block */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|standdisk
init|=
literal|"/etc/disktab"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|st506boot
init|=
literal|"/stand/bootwd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ST506 boot block */
end_comment

begin_decl_stmt
name|char
modifier|*
name|scsiboot
init|=
literal|"/stand/bootswd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCSI boot block */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|st506boot
init|=
literal|"/stand/bootwd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ST506 boot block */
end_comment

begin_decl_stmt
name|char
modifier|*
name|scsiboot
init|=
literal|"/stand/bootswd"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SCSI boot block */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|name
index|[
name|BOOTSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_union
union|union
block|{
name|char
name|bootstrap
index|[
name|BOOTSIZE
index|]
decl_stmt|;
struct|struct
block|{
name|char
name|pad
index|[
name|LABELOFFSET
index|]
decl_stmt|;
name|struct
name|disklabel
name|lab
decl_stmt|;
block|}
name|b
struct|;
block|}
name|block0
union|;
end_union

begin_define
define|#
directive|define
name|MAXTYPES
value|4
end_define

begin_decl_stmt
name|char
modifier|*
name|tnames
index|[
name|MAXTYPES
index|]
init|=
block|{
literal|"type 0"
block|,
literal|"ST506"
block|,
literal|"floppy"
block|,
literal|"SCSI"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|struct
name|disklabel
modifier|*
name|lp
init|=
operator|&
name|block0
operator|.
name|b
operator|.
name|lab
decl_stmt|;
specifier|register
name|struct
name|disktab
modifier|*
name|dp
decl_stmt|;
specifier|register
name|i
expr_stmt|;
name|int
name|f
decl_stmt|,
name|b
decl_stmt|;
name|char
modifier|*
name|boot
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
ifndef|#
directive|ifndef
name|STANDALONE
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
if|if
condition|(
name|argc
operator|<
literal|2
operator|||
name|argc
operator|>
literal|5
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: disklabel disk    (to read label)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"or disklabel disk type [ packid ] [ bootblock ]    (to write label)\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|!=
literal|'/'
condition|)
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"/dev/r%sc"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
else|else
name|strcpy
argument_list|(
name|name
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|argc
operator|==
literal|2
condition|)
block|{
name|f
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|<
literal|0
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|!=
literal|'/'
condition|)
block|{
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"/dev/r%s"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|f
operator|=
name|open
argument_list|(
name|name
argument_list|,
name|O_RDONLY
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|f
operator|<
literal|0
condition|)
name|Perror
argument_list|(
name|name
argument_list|)
expr_stmt|;
else|#
directive|else
name|char
name|buf
index|[
literal|80
index|]
decl_stmt|,
name|c
decl_stmt|;
name|new_file
label|:
name|f
operator|=
name|getdev
argument_list|(
literal|"File"
argument_list|,
name|name
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|printf
argument_list|(
literal|"R)ead, W)rite, F)ilename,  or E)xit [RWFE] ? "
argument_list|)
expr_stmt|;
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'E'
condition|)
break|break ;
if|if
condition|(
name|c
operator|==
literal|'W'
condition|)
goto|goto
name|wr_lab
goto|;
if|if
condition|(
name|c
operator|==
literal|'F'
condition|)
block|{
name|close
argument_list|(
name|f
argument_list|)
expr_stmt|;
goto|goto
name|new_file
goto|;
block|}
if|if
condition|(
name|c
operator|!=
literal|'R'
condition|)
continue|continue ;
endif|#
directive|endif
if|if
condition|(
name|read
argument_list|(
name|f
argument_list|,
operator|&
name|block0
argument_list|,
name|BOOTSIZE
argument_list|)
operator|<
name|BOOTSIZE
condition|)
name|Perror
argument_list|(
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|lp
operator|->
name|dk_magic
operator|!=
name|DISKMAGIC
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Bad pack magic number (pack is unlabeled)\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|STANDALONE
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
continue|continue ;
endif|#
directive|endif
block|}
ifndef|#
directive|ifndef
name|STANDALONE
name|printf
argument_list|(
literal|"%s (%.*s):\n"
argument_list|,
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|lp
operator|->
name|dk_name
argument_list|)
argument_list|,
name|lp
operator|->
name|dk_name
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"%s (%s):\n"
argument_list|,
name|name
argument_list|,
name|lp
operator|->
name|dk_name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"%s, "
argument_list|,
operator|(
name|unsigned
operator|)
name|lp
operator|->
name|dk_type
operator|<
name|MAXTYPES
condition|?
name|tnames
index|[
name|lp
operator|->
name|dk_type
index|]
else|:
literal|"unknown type"
argument_list|)
expr_stmt|;
if|if
condition|(
name|lp
operator|->
name|dk_type
operator|==
name|DTYPE_SCSI
condition|)
block|{
name|printf
argument_list|(
literal|"%d bytes/sector, %d sectors/drive, "
argument_list|,
name|lp
operator|->
name|dk_secsize
argument_list|,
name|lp
operator|->
name|dk_secperunit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d sectors/track,\n %d tracks/cylinder, "
argument_list|,
name|lp
operator|->
name|dk_secpercyl
operator|/
name|lp
operator|->
name|dk_ntracks
argument_list|,
name|lp
operator|->
name|dk_ntracks
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d sectors/cylinder, "
argument_list|,
name|lp
operator|->
name|dk_secpercyl
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s i/o mode\n"
argument_list|,
name|lp
operator|->
name|dk_blind
condition|?
literal|"blind"
else|:
literal|"slow"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"%d bytes/sector, %d sectors/track, "
argument_list|,
name|lp
operator|->
name|dk_secsize
argument_list|,
name|lp
operator|->
name|dk_nsectors
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d tracks/cylinder, %d cylinders\n"
argument_list|,
name|lp
operator|->
name|dk_ntracks
argument_list|,
name|lp
operator|->
name|dk_ncylinders
argument_list|)
expr_stmt|;
if|if
condition|(
name|lp
operator|->
name|dk_secpercyl
operator|!=
name|lp
operator|->
name|dk_nsectors
operator|*
name|lp
operator|->
name|dk_ntracks
condition|)
name|printf
argument_list|(
literal|"WARNING: sectors/cylinder field is wrong (%d instead of %d)\n"
argument_list|,
name|lp
operator|->
name|dk_secpercyl
argument_list|,
name|lp
operator|->
name|dk_nsectors
operator|*
name|lp
operator|->
name|dk_ntracks
argument_list|)
expr_stmt|;
if|if
condition|(
name|lp
operator|->
name|dk_secperunit
operator|!=
name|lp
operator|->
name|dk_nsectors
operator|*
name|lp
operator|->
name|dk_ntracks
operator|*
name|lp
operator|->
name|dk_ncylinders
condition|)
name|printf
argument_list|(
literal|"WARNING: sectors/unit field is wrong (%d instead of %d)\n"
argument_list|,
name|lp
operator|->
name|dk_secperunit
argument_list|,
name|lp
operator|->
name|dk_nsectors
operator|*
name|lp
operator|->
name|dk_ntracks
operator|*
name|lp
operator|->
name|dk_ncylinders
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|STANDALONE
name|printf
argument_list|(
literal|"partitions:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t       size    offset\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"partition table:\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
ifndef|#
directive|ifndef
name|STANDALONE
name|printf
argument_list|(
literal|"\t%c: %8d %8d"
argument_list|,
literal|'a'
argument|+ i
argument_list|,
else|#
directive|else
argument|printf(
literal|"partition %c, size %d sectors, offset %d cylinders."
argument|,
literal|'a'
argument|+ i,
endif|#
directive|endif
argument|lp->dk_partition[i].nblocks, lp->dk_partition[i].cyloff); 		    if (lp->dk_partition[i].nblocks){ 				if (lp->dk_type != DTYPE_SCSI) {
ifndef|#
directive|ifndef
name|STANDALONE
argument|printf(
literal|"\t(Cyl. %d - %d"
argument|,
else|#
directive|else
argument|printf(
literal|" (from cyl %d to %d"
argument|,
endif|#
directive|endif
argument|lp->dk_partition[i].cyloff, 			    lp->dk_partition[i].cyloff +  			    (lp->dk_partition[i].nblocks + lp->dk_secpercyl 			        -
literal|1
argument|) / lp->dk_secpercyl -
literal|1
argument|); 			if (lp->dk_partition[i].nblocks % lp->dk_secpercyl) 			    putchar(
literal|'*'
argument|); 			putchar(
literal|')'
argument|); 		    		} else { 				} 			} 		    printf(
literal|"\n"
argument|); 		}
ifdef|#
directive|ifdef
name|STANDALONE
argument|continue ; wr_lab: 	printf(
literal|"Type (e.g. miniscribe85...): "
argument|) ; 	gets(buf) ; 	dp = getdiskbyname(buf); 	if (dp == NULL) { 		printf(
literal|"%s: unknown disk type\n"
argument|, buf);
ifndef|#
directive|ifndef
name|STANDALONE
argument|exit(
literal|1
argument|);
else|#
directive|else
argument|continue ;
endif|#
directive|endif
argument|}
else|#
directive|else
argument|exit(
literal|0
argument|); 	} 	dp = getdiskbyname(argv[
literal|2
argument|]); 	if (dp == NULL) { 		fprintf(stderr,
literal|"%s: unknown disk type\n"
argument|, argv[
literal|2
argument|]); 		exit(
literal|1
argument|); 	} 	f = open(name, O_WRONLY); 	if (f<
literal|0
argument|) 		Perror(name);
endif|#
directive|endif
argument|if (strcmp(dp->d_type,
literal|"scsi"
argument|) ==
literal|0
argument||| strcmp(dp->d_type,
literal|"SCSI"
argument|) ==
literal|0
argument|) 		boot = scsiboot ; else boot = st506boot ;
ifndef|#
directive|ifndef
name|STANDALONE
argument|if (argc>
literal|4
argument|) 		boot = argv[
literal|4
argument|];
endif|#
directive|endif
argument|b = open(boot, O_RDONLY); 	if (b<
literal|0
argument|) 		Perror(boot); 	if (read(b,&block0, BOOTSIZE)<
literal|0
argument|) 		Perror(boot); 	close(b) ; 	for (p = (char *)lp; p< (char *)lp + sizeof(struct disklabel); p++) 		if (*p) { 			fprintf(stderr,
literal|"Bootstrap doesn't leave room for disk label\n"
argument|); 			exit(
literal|2
argument|); 		} 	lp->dk_magic = DISKMAGIC; 	if (strcmp(dp->d_type,
literal|"st506"
argument|) ==
literal|0
argument||| 	    strcmp(dp->d_type,
literal|"ST506"
argument|) ==
literal|0
argument|) { 		lp->dk_type = DTYPE_ST506; 		lp->dk_precompcyl = dp->d_precomp; 	} 	if (strcmp(dp->d_type,
literal|"floppy"
argument|) ==
literal|0
argument|) 		lp->dk_type = DTYPE_FLOPPY; 	if (strcmp(dp->d_type,
literal|"scsi"
argument|) ==
literal|0
argument|) 		lp->dk_type = DTYPE_SCSI;  	if (strcmp(dp->d_type,
literal|"SCSI"
argument|) ==
literal|0
argument|) 		lp->dk_type = DTYPE_SCSI; 	lp->dk_secsize = dp->d_secsize; 	lp->dk_nsectors = dp->d_nsectors; 	lp->dk_ntracks = dp->d_ntracks; 	lp->dk_ncylinders = dp->d_ncylinders; 	if (lp->dk_type == DTYPE_SCSI) { 		lp->dk_secpercyl = dp->d_secpercyl ; 		lp->dk_secperunit = dp->d_nsectors ; 		lp->dk_blind = dp->d_blind ; 	} else { 		lp->dk_secpercyl = dp->d_nsectors * dp->d_ntracks; 		lp->dk_secperunit = dp->d_nsectors * dp->d_ntracks 					* dp->d_ncylinders; 	} 	for (i =
literal|0
argument|; i<
literal|8
argument|; i++) { 		lp->dk_partition[i].nblocks = dp->d_partitions[i].p_size; 		if (lp->dk_partition[i].nblocks == -
literal|1
argument|) 			lp->dk_partition[i].nblocks =
literal|0
argument|; 		lp->dk_partition[i].cyloff = dp->d_partitions[i].p_offset; 		if (lp->dk_partition[i].cyloff == -
literal|1
argument|) 			lp->dk_partition[i].cyloff =
literal|0
argument|; 	}
ifndef|#
directive|ifndef
name|STANDALONE
argument|if (argc>
literal|3
argument|) 		strncpy(lp->dk_name, argv[
literal|3
argument|], sizeof(lp->dk_name)); 	else
endif|#
directive|endif
argument|strncpy(lp->dk_name, dp->d_name, sizeof(lp->dk_name)); 	if (write(f,&block0, BOOTSIZE)< BOOTSIZE) 		Perror(
literal|"write"
argument|);
ifdef|#
directive|ifdef
name|STANDALONE
argument|}
endif|#
directive|endif
argument|exit(
literal|0
argument|); }  Perror(op) 	char *op; {  	fprintf(stderr,
literal|"disklabel: "
argument|);
comment|/*perror(op);*/
argument|exit(
literal|4
argument|); }
ifdef|#
directive|ifdef
name|STANDALONE
argument|getdev(prompt, buf) char *buf ; { 	register int i;  	do { 		printf(
literal|"%s: "
argument|, prompt); 		gets(buf); 		i = open(buf,
literal|2
argument|); 	} while (i<=
literal|0
argument|); 	return (i); }  fprintf(a,b,c,d,e,f,g,h) { 	printf(b,c,d,e,f,g,h) ; }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

