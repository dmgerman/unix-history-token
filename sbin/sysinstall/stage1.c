begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* #define DEBUG  * Copyright (c) 1994, Paul Richards.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|device_list
index|[]
init|=
block|{
literal|"wd"
block|,
literal|"sd"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|query_disks
parameter_list|()
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|char
name|disk
index|[
literal|15
index|]
decl_stmt|;
name|char
name|diskname
index|[
literal|5
index|]
decl_stmt|;
name|struct
name|stat
name|st
decl_stmt|;
name|struct
name|disklabel
name|dl
decl_stmt|;
name|int
name|fd
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_NO_DISKS
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|Dname
index|[
name|i
index|]
condition|)
block|{
name|close
argument_list|(
name|Dfd
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|Dfd
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|Dlbl
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|Dlbl
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|free
argument_list|(
name|Dname
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|Dname
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|Ndisk
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|device_list
index|[
name|j
index|]
condition|;
name|j
operator|++
control|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
name|sprintf
argument_list|(
name|diskname
argument_list|,
literal|"%s%d"
argument_list|,
name|device_list
index|[
name|j
index|]
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|disk
argument_list|,
literal|"/dev/r%sd"
argument_list|,
name|diskname
argument_list|)
expr_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|disk
argument_list|,
operator|&
name|st
argument_list|)
operator|||
operator|!
operator|(
name|st
operator|.
name|st_mode
operator|&
name|S_IFCHR
operator|)
condition|)
continue|continue;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|disk
argument_list|,
name|O_RDWR
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
continue|continue;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|DIOCGDINFO
argument_list|,
operator|&
name|dl
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|Dlbl
index|[
name|Ndisk
index|]
operator|=
name|Malloc
argument_list|(
sizeof|sizeof
name|dl
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|Dlbl
index|[
name|Ndisk
index|]
argument_list|,
operator|&
name|dl
argument_list|,
sizeof|sizeof
name|dl
argument_list|)
expr_stmt|;
name|Dname
index|[
name|Ndisk
index|]
operator|=
name|StrAlloc
argument_list|(
name|diskname
argument_list|)
expr_stmt|;
name|Dfd
index|[
name|Ndisk
index|]
operator|=
name|fd
expr_stmt|;
name|Ndisk
operator|++
expr_stmt|;
if|if
condition|(
name|Ndisk
operator|==
name|MAX_NO_DISKS
condition|)
return|return;
block|}
block|}
block|}
end_function

begin_function
name|int
name|stage1
parameter_list|()
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|int
name|ret
init|=
literal|1
decl_stmt|;
name|int
name|ready
init|=
literal|0
decl_stmt|;
name|int
name|foundroot
init|=
literal|0
decl_stmt|,
name|foundusr
init|=
literal|0
decl_stmt|,
name|foundswap
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|complaint
init|=
literal|0
decl_stmt|;
name|query_disks
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|ready
condition|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|standend
argument_list|()
expr_stmt|;
name|j
operator|=
literal|2
expr_stmt|;
if|if
condition|(
name|fixit
condition|)
block|{
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|Suggested course of action:"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|(F)disk, (W)rite"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|possibly (F)disk, (B)oot"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|(D)isklabel, (A)ssign<root>"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|(A)ssign swap"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|(P)roceed"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|Reboot"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|Load cpio floppy"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|Choose stand-alone shell"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|Your old kernel, /etc/fstab"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
name|j
operator|++
argument_list|,
literal|50
argument_list|,
literal|"|and /sbin/init files are"
argument_list|)
expr_stmt|;
name|mvprintw
argument_list|(
argument|j++
argument_list|,
literal|50
argument_list|,
literal|"|renamed since the kernel and); 	    mvprintw(j++, 50, "
argument||/etc/fstab are replaced from
literal|"); 	    mvprintw(j++, 50, "
argument||this floppy.
literal|"); 	} else { 	    mvprintw(j++, 50, "
argument||You should now assign some
literal|"); 	    mvprintw(j++, 50, "
argument||space to root
argument_list|,
argument|swap
argument_list|,
argument|and
literal|"); 	    mvprintw(j++, 50, "
argument||(optionally) /usr partitions
literal|");  	    mvprintw(j++, 50, "
argument||Root (/) should be a minimum
literal|"); 	    mvprintw(j++, 50, "
argument||of
literal|18MB
argument|with a
literal|30MB
argument|/usr
literal|"); 	    mvprintw(j++, 50, "
argument||or
literal|50MB
argument|without a /usr.
literal|");  	    mvprintw(j++, 50, "
argument||Swap space should be a
literal|"); 	    mvprintw(j++, 50, "
argument||minimum of
literal|12MB
argument|or RAM *
literal|2
literal|"); 	    mvprintw(j++, 50, "
argument||Be sure to also (A)ssign a
literal|"); 	    mvprintw(j++, 50, "
argument||mount point to each one or
literal|"); 	    mvprintw(j++, 50, "
argument||it will NOT be enabled.
literal|");  	    mvprintw(j++, 50, "
argument||
literal|"); 	    mvprintw(j++, 50, "
argument||We suggest that you invoke
literal|"); 	    mvprintw(j++, 50, "
argument||(F)disk then (D)isklabel
literal|"); 	    mvprintw(j++, 50, "
argument||in setting up your disk.
literal|"); 	    mvprintw(j++, 50, "
argument||If installing on a drive
literal|"); 	    mvprintw(j++, 50, "
argument||other than
literal|0
argument_list|,
argument|read the
literal|"); 	    mvprintw(j++, 50, "
argument||TROUBLESHOOTING doc first
literal|"); 	}  	j = 0; 	mvprintw(j++, 0, "
argument|%s -- Diskspace editor
literal|", TITLE); 	j++; 	mvprintw(j++, 0, "
argument|Disks         Total   FreeBSD
literal|"); 	j++; 	for(i = 0; i< MAX_NO_DISKS&& Dname[i]; i++) { 	    mvprintw(j++, 0, "
argument|%
literal|2d
argument|: %-
literal|6s
argument|%
literal|5lu
argument|MB  %
literal|5lu
argument|MB
literal|", 		     i, 		     Dname[i], 		     PartMb(Dlbl[i],RAWPART), 		     PartMb(Dlbl[i],OURPART)); 	} 	j++; 	mvprintw(j++, 0, "
argument|Filesystems  Type        Size  Action Mountpoint
literal|"); 	j++; 	for(i = 0; i< MAX_NO_FS; i++) { 	    if(!Fname[i]) 		continue; 	    if(!strcmp(Ftype[i],"
argument|swap
literal|")) { 		mvprintw(j++, 0, "
argument|%
literal|2d
argument|: %-
literal|5s
argument|%-
literal|5s
argument|%
literal|5lu
argument|MB  %-
literal|6s
argument|%-s
literal|", 		     i, Fname[i], Ftype[i], Fsize[i], "
argument|swap
literal|", Fmount[i]); 	    } else { 		mvprintw(j++, 0, "
argument|%
literal|2d
argument|: %-
literal|5s
argument|%-
literal|5s
argument|%
literal|5lu
argument|MB  %-
literal|6s
argument|%-s
literal|", 		     i, Fname[i], Ftype[i], Fsize[i],  			     Faction[i] ? "
argument|newfs
literal|" : "
argument|mount
literal|", Fmount[i]); 	    } 	}  	mvprintw(20, 0, "
argument|Commands available:
literal|"); 	mvprintw(21, 0, "
argument|(H)elp  (T)utorial  (F)disk  (D)isklabel  (P)roceed  (Q)uit
literal|"); 	if(complaint) { 		standout(); 		mvprintw(22, 0, complaint); 		standend(); 		complaint = 0; 	} 	mvprintw(23, 0, "
argument|Enter Command>
literal|"); 	i = getch(); 	switch(i) { 	case 'h': case 'H': 	    clear(); 	    mvprintw(0, 0,  "
argument|%s -- Diskspace editor -- Command Help  (T)utorial	- Read a more detailed tutorial on how disklabels
argument_list|,
argument|MBRs
argument_list|,
argument|etc. work. (P)roceed	- Proceed with system installation. (Q)uit		- Don
literal|'t install anything. (F)disk		- Enter the FDISK (MBR) editor. (D)isklabel	- Enter the disklabel editor.  Press any key to return to Diskspace editor...", TITLE); 	    getch(); 	    break; 	case '
argument|t
literal|': case '
argument|T
literal|':             ShowFile(HELPME_FILE,"Help file for disklayout"); 	    break; 	case '
argument|p
literal|': case '
argument|P
literal|': 	    foundroot=0,foundusr=0,foundswap=0; 	    for (i = 1; Fmount[i]; i++) { 		if(!strcmp(Fmount[i],"/")) foundroot=i; 		if(!strcmp(Fmount[i],"swap")) foundswap=i; 		if(!strcmp(Fmount[i],"/usr")) foundusr=i; 	    } 	    if (!foundroot) { 		complaint = "Please assign mountpoint for '
argument|/
literal|'"; 		break; 	    } 	    if (!foundswap) { 		complaint = "Please assign mountpoint for swap"; 		break; 	    } 	    if (!fixit&& !foundusr&& Fsize[foundroot]< 60) { 		complaint = "Please assign mountpoint for /usr"; 		break; 	    } 	    if (dialog_yesno("Last Chance!", 		"Are you sure you want to proceed with the installation?\nLast chance before wiping your hard disk!", -1, -1)) 		break; 	    ret = 0; 	    goto leave; 	case '
argument|q
literal|': case '
argument|Q
literal|': 	    ret = 1; 	    goto leave; 	case '
argument|f
literal|': case '
argument|F
literal|': 	    Fdisk(); 	    query_disks(); 	    break; 	case '
argument|d
literal|': case '
argument|D
literal|'
end_function

unit|: 	    DiskLabel(); 	    break; 	default: 	    beep(); 	}     } leave:     clear();     for (i = 0; Dname[i]; i++) 	close(Dfd[i]);     return ret; }
end_unit

