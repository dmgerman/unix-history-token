begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: disks.c,v 1.31.2.33 1995/11/08 07:09:17 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_comment
comment|/* Where we start displaying chunk information on the screen */
end_comment

begin_define
define|#
directive|define
name|CHUNK_START_ROW
value|5
end_define

begin_comment
comment|/* Where we keep track of MBR chunks */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|chunk
modifier|*
name|chunk_info
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|current_chunk
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|record_chunks
parameter_list|(
name|Disk
modifier|*
name|d
parameter_list|)
block|{
name|struct
name|chunk
modifier|*
name|c1
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
name|int
name|last_free
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|chunks
condition|)
name|msgFatal
argument_list|(
literal|"No chunk list found for %s!"
argument_list|,
name|d
operator|->
name|name
argument_list|)
expr_stmt|;
name|current_chunk
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|c1
operator|=
name|d
operator|->
name|chunks
operator|->
name|part
init|;
name|c1
condition|;
name|c1
operator|=
name|c1
operator|->
name|next
control|)
block|{
if|if
condition|(
name|c1
operator|->
name|type
operator|==
name|unused
operator|&&
name|c1
operator|->
name|size
operator|>
name|last_free
condition|)
block|{
name|last_free
operator|=
name|c1
operator|->
name|size
expr_stmt|;
name|current_chunk
operator|=
name|i
expr_stmt|;
block|}
name|chunk_info
index|[
name|i
operator|++
index|]
operator|=
name|c1
expr_stmt|;
block|}
name|chunk_info
index|[
name|i
index|]
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_chunks
parameter_list|(
name|Disk
modifier|*
name|d
parameter_list|)
block|{
name|int
name|row
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|(
operator|!
name|d
operator|->
name|bios_cyl
operator|||
name|d
operator|->
name|bios_cyl
operator|>
literal|65536
operator|)
operator|||
operator|(
operator|!
name|d
operator|->
name|bios_hd
operator|||
name|d
operator|->
name|bios_hd
operator|>
literal|256
operator|)
operator|||
operator|(
operator|!
name|d
operator|->
name|bios_sect
operator|||
name|d
operator|->
name|bios_sect
operator|>=
literal|64
operator|)
condition|)
block|{
name|int
name|sz
decl_stmt|;
name|dialog_clear
argument_list|()
expr_stmt|;
name|msgConfirm
argument_list|(
literal|"WARNING:  The current geometry for %s is incorrect.  Using\n"
literal|"a default geometry of 64 heads and 32 sectors.  If this geometry\n"
literal|"is incorrect or you are unsure as to whether or not it's correct,\n"
literal|"please consult the Hardware Guide in the Documentation submenu\n"
literal|"or use the (G)eometry command to change it now."
argument_list|,
name|d
operator|->
name|name
argument_list|)
expr_stmt|;
name|d
operator|->
name|bios_hd
operator|=
literal|64
expr_stmt|;
name|d
operator|->
name|bios_sect
operator|=
literal|32
expr_stmt|;
name|sz
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|chunk_info
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
name|sz
operator|+=
name|chunk_info
index|[
name|i
index|]
operator|->
name|size
expr_stmt|;
if|if
condition|(
name|sz
condition|)
name|d
operator|->
name|bios_cyl
operator|=
name|sz
operator|/
name|ONE_MEG
expr_stmt|;
else|else
name|msgConfirm
argument_list|(
literal|"     }     attrset(A_NORMAL);     mvaddstr(0, 0, "
argument|Disk name:\t
literal|");     clrtobot();     attrset(A_REVERSE); addstr(d->name); attrset(A_NORMAL);     attrset(A_REVERSE); mvaddstr(0, 55, "
argument|FDISK Partition Editor
literal|"); attrset(A_NORMAL);     mvprintw(1, 0, 	     "
argument|DISK Geometry:\t%lu cyls/%lu heads/%lu sectors
literal|", 	     d->bios_cyl, d->bios_hd, d->bios_sect);     mvprintw(3, 1, "
argument|%
literal|10s
argument|%
literal|10s
argument|%
literal|10s
argument|%
literal|8s
argument|%
literal|8s
argument|%
literal|8s
argument|%
literal|8s
argument|%
literal|8s
literal|", 	     "
argument|Offset
literal|", "
argument|Size
literal|", "
argument|End
literal|", "
argument|Name
literal|", "
argument|PType
literal|", "
argument|Desc
literal|", 	     "
argument|Subtype
literal|", "
argument|Flags
literal|");     for (i = 0, row = CHUNK_START_ROW; chunk_info[i]; i++, row++) { 	if (i == current_chunk) 	    attrset(A_REVERSE); 	mvprintw(row, 2, "
argument|%
literal|10ld
argument|%
literal|10lu
argument|%
literal|10lu
argument|%
literal|8s
argument|%
literal|8d
argument|%
literal|8s
argument|%
literal|8d
argument|\t%-
literal|6s
literal|", 		 chunk_info[i]->offset, chunk_info[i]->size, 		 chunk_info[i]->end, chunk_info[i]->name, 		 chunk_info[i]->type, chunk_n[chunk_info[i]->type], 		 chunk_info[i]->subtype, ShowChunkFlags(chunk_info[i])); 	if (i == current_chunk) 	    attrset(A_NORMAL);     } }  static void print_command_summary() {     mvprintw(14, 0, "
argument|The following commands are supported (in upper or lower case):
literal|");     mvprintw(16, 0, "
argument|A = Use Entire Disk    B = Bad Block Scan     C = Create Partition
literal|");     mvprintw(17, 0, "
argument|D = Delete Partition   G = Set Drive Geometry S = Set Bootable
literal|");     mvprintw(18, 0, "
argument|U = Undo All Changes   Q = Finish             W = Write Changes
literal|");     mvprintw(20, 0, "
argument|The currently selected partition is displayed in
literal|");     attrset(A_REVERSE); addstr("
argument|reverse
literal|"); attrset(A_NORMAL); addstr("
argument|video.
literal|");     mvprintw(21, 0, "
argument|Use F1 or ? to get more help
argument_list|,
argument|arrow keys to move.
literal|");     move(0, 0); }  /* Partition a disk based wholly on which variables are set */ static void scriptPartition(Device *dev, Disk *d) {     char *cp;     int i, sz;      record_chunks(d);     cp = variable_get(VAR_GEOMETRY);     if (cp) { 	msgDebug("
argument|Setting geometry from script to: %s\n
literal|", cp); 	d->bios_cyl = strtol(cp,&cp, 0); 	d->bios_hd = strtol(cp + 1,&cp, 0); 	d->bios_sect = strtol(cp + 1, 0, 0);     }      cp = variable_get(VAR_DISKSPACE);     if (cp) { 	if (!strcmp(cp, "
argument|free
literal|")) { 	    /* Do free disk space case */ 	    for (i = 0; chunk_info[i]; i++) { 		/* If a chunk is at least 10MB in size, use it. */ 		if (chunk_info[i]->type == unused&& chunk_info[i]->size> (10 * ONE_MEG)) { 		    Create_Chunk(d, chunk_info[i]->offset, chunk_info[i]->size, freebsd, 3, 				 (chunk_info[i]->flags& CHUNK_ALIGN)); 		    variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		    break; 		} 	    } 	    if (!chunk_info[i]) { 		dialog_clear(); 		msgConfirm("
argument|Unable to find any free space on this disk!
literal|"); 		return; 	    } 	} 	else if (!strcmp(cp, "
argument|all
literal|")) { 	    /* Do all disk space case */ 	    msgDebug("
argument|Warning:  Devoting all of disk %s to FreeBSD.\n
literal|", d->name);  	    All_FreeBSD(d, FALSE); 	} 	else if (!strcmp(cp, "
argument|exclusive
literal|")) { 	    /* Do really-all-the-disk-space case */ 	    msgDebug("
argument|Warning:  Devoting all of disk %s to FreeBSD.\n
literal|", d->name);  	    All_FreeBSD(d, TRUE); 	} 	else if ((sz = strtol(cp,&cp, 0))) { 	    /* Look for sz bytes free */ 	    if (*cp&& toupper(*cp) == 'M') 		sz *= ONE_MEG; 	    for (i = 0; chunk_info[i]; i++) { 		/* If a chunk is at least sz MB, use it. */ 		if (chunk_info[i]->type == unused&& chunk_info[i]->size>= sz) { 		    Create_Chunk(d, chunk_info[i]->offset, sz, freebsd, 3, (chunk_info[i]->flags& CHUNK_ALIGN)); 		    variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		    break; 		} 	    } 	    if (!chunk_info[i]) { 		dialog_clear(); 		msgConfirm("
argument|Unable to find %d free blocks on this disk!
literal|", sz); 		return; 	    } 	} 	else if (!strcmp(cp, "
argument|existing
literal|")) { 	    /* Do existing FreeBSD case */ 	    for (i = 0; chunk_info[i]; i++) { 		if (chunk_info[i]->type == freebsd) 		    break; 	    } 	    if (!chunk_info[i]) { 		dialog_clear(); 		msgConfirm("
argument|Unable to find any existing FreeBSD partitions on this disk!
literal|"); 		return; 	    } 	} 	else { 	    dialog_clear(); 	    msgConfirm("
argument|`%s
literal|' is an invalid value for %s - is config file valid?", cp, VAR_DISKSPACE); 	    return; 	} 	variable_set2(DISK_PARTITIONED, "yes");     } }  static u_char * getBootMgr(char *dname) {     extern u_char mbr[], bteasy17[];     char str[80];     char *cp;     int i = 0;      cp = variable_get(VAR_BOOTMGR);     if (!cp) { 	/* Figure out what kind of MBR the user wants */ 	sprintf(str, "Install Boot Manager for drive %s?", dname); 	MenuMBRType.title = str; 	dialog_clear(); 	i = dmenuOpenSimple(&MenuMBRType);     }     else { 	if (!strncmp(cp, "boot", 4)) 	    BootMgr = 0; 	else if (!strcmp(cp, "standard")) 	    BootMgr = 1; 	else 	    BootMgr = 2;     }     if (cp || i) { 	switch (BootMgr) { 	case 0: 	    return bteasy17;  	case 1: 	    return mbr;  	case 2: 	default: 	    break; 	}     }     return NULL; }  void diskPartition(Device *dev, Disk *d) {     char *p;     int key = 0;     Boolean chunking;     char *msg = NULL;     u_char *mbrContents;      chunking = TRUE;     keypad(stdscr, TRUE);      clear();     record_chunks(d);     while (chunking) { 	print_chunks(d); 	print_command_summary(); 	if (msg) { 	    standout(); mvprintw(23, 0, msg); standend(); 	    beep(); 	    msg = NULL; 	}  	key = toupper(getch()); 	switch (key) {  	case '
argument|\
literal|014
literal|':	/* ^L */ 	    clear(); 	    print_command_summary(); 	    continue;  	case KEY_UP: 	case '
argument|-
literal|': 	    if (current_chunk != 0) 		--current_chunk; 	    break;  	case KEY_DOWN: 	case '
argument|+
literal|': 	case '
argument|\r
literal|': 	case '
argument|\n
literal|': 	    if (chunk_info[current_chunk + 1]) 		++current_chunk; 	    break;  	case KEY_HOME: 	    current_chunk = 0; 	    break;  	case KEY_END: 	    while (chunk_info[current_chunk + 1]) 		++current_chunk; 	    break;  	case KEY_F(1): 	case '
argument|?
literal|': 	    systemDisplayHelp("slice"); 	    break;  	case '
argument|A
literal|': { 	    int rv;  	    rv = msgYesNo("Do you want to do this with a true partition entry\n" 			  "so as to remain cooperative with any future possible\n" 			  "operating systems on the drive(s)?"); 	    if (rv) { 		rv = !msgYesNo("This is dangerous in that it will make the drive totally\n" 			       "uncooperative with other potential operating systems on the\n" 			       "same disk.  It will lead instead to a totally dedicated disk,\n" 			       "starting at the very first sector, bypassing all BIOS geometry\n" 			       "considerations.\n" 			       "You will run into serious trouble with ST-506 and ESDI drives\n" 			       "and possibly some IDE drives (e.g. drives running under the\n" 			       "control of sort of disk manager).  SCSI drives are considerably\n" 			       "less at risk.\n\n" 			       "Do you insist on dedicating the entire disk this way?"); 	    } 	    All_FreeBSD(d, rv); 	    if (rv) 		d->bios_hd = d->bios_sect = d->bios_cyl = 1; 	    variable_set2(DISK_PARTITIONED, "yes"); 	    record_chunks(d); 	} 	    break;  	case '
argument|B
literal|': 	    if (chunk_info[current_chunk]->type != freebsd) 		msg = "Can only scan for bad blocks in FreeBSD partition."; 	    else if (strncmp(d->name, "sd", 2) || 		     !msgYesNo("This typically makes sense only for ESDI, IDE or MFM drives.\n" 			       "Are you sure you want to do this on a SCSI disk?")) { 		if (chunk_info[current_chunk]->flags& CHUNK_BAD144) 		    chunk_info[current_chunk]->flags&= ~CHUNK_BAD144; 		else 		    chunk_info[current_chunk]->flags |= CHUNK_BAD144; 	    } 	    break;  	case '
argument|C
literal|': 	    if (chunk_info[current_chunk]->type != unused) 		msg = "Partition in use, delete it first or move to an unused one."; 	    else { 		char *val, tmp[20], *cp; 		int size;  		snprintf(tmp, 20, "%d", chunk_info[current_chunk]->size); 		val = msgGetInput(tmp, "Please specify the size for new FreeBSD partition in blocks, or append\n" 				  "a trailing `M'
argument|for megabytes (e.g.
literal|20M
argument|).
literal|"); 		if (val&& (size = strtol(val,&cp, 0))> 0) { 		    if (*cp&& toupper(*cp) == 'M') 			size *= ONE_MEG; 		    Create_Chunk(d, chunk_info[current_chunk]->offset, size, freebsd, 3, 				 (chunk_info[current_chunk]->flags& CHUNK_ALIGN)); 		    variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		    record_chunks(d); 		} 	    } 	    break;  	case 'D': 	    if (chunk_info[current_chunk]->type == unused) 		msg = "
argument|Partition is already unused!
literal|"; 	    else { 		Delete_Chunk(d, chunk_info[current_chunk]); 		variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		record_chunks(d); 	    } 	    break;  	case 'G': { 	    char *val, geometry[80];  	    snprintf(geometry, 80, "
argument|%lu/%lu/%lu
literal|", d->bios_cyl, d->bios_hd, d->bios_sect); 	    val = msgGetInput(geometry, "
argument|Please specify the new geometry in cyl/hd/sect format.\n
literal|" 			      "
argument|Don
literal|'t forget to use the two slash (/) separator characters!\n" 			      "It'
argument|s not possible to parse the field without them.
literal|"); 	    if (val) { 		d->bios_cyl = strtol(val,&val, 0); 		d->bios_hd = strtol(val + 1,&val, 0); 		d->bios_sect = strtol(val + 1, 0, 0); 	    } 	} 	break;      case 'S': 	/* Set Bootable */ 	chunk_info[current_chunk]->flags |= CHUNK_ACTIVE; 	break; 	     case 'U': 	    clear(); 	    if (msgYesNo("
argument|Are you SURE you want to Undo everything?
literal|")) 		break; 	    d = Open_Disk(d->name); 	    if (!d) { 		dialog_clear(); 		msgConfirm("
argument|Can
literal|'t reopen disk %s! Internal state is probably corrupted", d->name); 		return; 	    } 	    Free_Disk(dev->private); 	    dev->private = d; 	    variable_unset(DISK_PARTITIONED); 	    record_chunks(d); 	    break;  	case '
argument|W
literal|': 	    if (!msgYesNo("Are you SURE you want to write this now?  You do also\n" 			  "have the option of not modifying the disk until *all*\n" 			  "configuration information has been entered, at which\n" 			  "point you can do it all at once.  If you'
argument|re unsure
argument_list|,
argument|then\n
literal|" 			  "
argument|PLEASE CHOOSE NO at this dialog!  This option is DANGEROUS\n
literal|" 			  "
argument|if you do not know EXACTLY what you are doing!
literal|")) { 		variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		clear();  		/* Don't trash the MBR if the first (and therefore only) chunk is marked for a truly dedicated 		 * disk (i.e., the disklabel starts at sector 0), even in cases where the user has requested 		 * booteasy or a "
argument|standard
literal|" MBR -- both would be fatal in this case. 		 */ 		if ((d->chunks->part->flags& CHUNK_FORCE_ALL) != CHUNK_FORCE_ALL&& (mbrContents = getBootMgr(d->name)) != NULL) 		    Set_Boot_Mgr(d, mbrContents);  		if (diskPartitionWrite(NULL) != RET_SUCCESS) { 		    dialog_clear(); 		    msgConfirm("
argument|Disk partition write returned an error status!
literal|"); 		} 		else { 		    msgConfirm("
argument|Wrote FDISK partition information out successfully.
literal|"); 		} 	    } 	    break;  	case '|': 	    if (!msgYesNo("
argument|Are you SURE you want to go into Wizard mode?\n
literal|" 			  "
argument|No seat belts whatsoever are provided!
literal|")) { 		dialog_clear(); 		end_dialog(); 		DialogActive = FALSE; 		slice_wizard(d); 		variable_set2(DISK_PARTITIONED, "
argument|yes
literal|"); 		dialog_clear(); 		DialogActive = TRUE; 		record_chunks(d); 	    } 	    else 		msg = "
argument|Wise choice!
literal|"; 	    break;  	case 'Q': 	    chunking = FALSE; 	    clear(); 	    /* Don't trash the MBR if the first (and therefore only) chunk is marked for a truly dedicated 	     * disk (i.e., the disklabel starts at sector 0), even in cases where the user has requested 	     * booteasy or a "
argument|standard
literal|" MBR -- both would be fatal in this case. 	     */ 	    if ((d->chunks->part->flags& CHUNK_FORCE_ALL) != CHUNK_FORCE_ALL&& (mbrContents = getBootMgr(d->name)) != NULL) 		Set_Boot_Mgr(d, mbrContents); 	    break;  	default: 	    beep(); 	    msg = "
argument|Type F1 or ? for help
literal|"; 	    break; 	}     }     p = CheckRules(d);     if (p) { 	dialog_clear(); 	msgConfirm(p); 	free(p);     }     dialog_clear(); }  static int partitionHook(char *str) {     Device **devs = NULL;      /* Clip garbage off the ends */     string_prune(str);     str = string_skipwhite(str);     /* Try and open all the disks */     while (str) { 	char *cp;  	cp = index(str, '\n'); 	if (cp) 	   *cp++ = 0; 	if (!*str) { 	    beep(); 	    return 0; 	} 	devs = deviceFind(str, DEVICE_TYPE_DISK); 	if (!devs) { 	    dialog_clear(); 	    msgConfirm("
argument|Unable to find disk %s!
literal|", str); 	    return 0; 	} 	else if (devs[1]) { 	    dialog_clear(); 	    msgConfirm("
argument|Bizarre multiple match for %s!
literal|", str); 	} 	devs[0]->enabled = TRUE; 	diskPartition(devs[0], (Disk *)devs[0]->private); 	str = cp;     }     return devs ? 1 : 0; }  int diskPartitionEditor(char *str) {     DMenu *menu;     Device **devs;     int i, cnt;     char *cp;      cp = variable_get(VAR_DISK);     devs = deviceFind(cp, DEVICE_TYPE_DISK);     cnt = deviceCount(devs);     if (!cnt) { 	dialog_clear(); 	msgConfirm("
argument|No disks found!  Please verify that your disk controller is being\n
literal|" 		   "
argument|properly probed at boot time.  See the Hardware Guide on the\n
literal|" 		   "
argument|Documentation menu for clues on diagnosing this type of problem.
literal|"); 	i = RET_FAIL;     }     else if (cnt == 1) { 	devs[0]->enabled = TRUE; 	if (str&& !strcmp(str, "
argument|script
literal|")) 	    scriptPartition(devs[0], (Disk *)devs[0]->private); 	else 	    diskPartition(devs[0], (Disk *)devs[0]->private); 	i = RET_SUCCESS; 	variable_set2(DISK_SELECTED, "
argument|yes
literal|");     }     else { 	menu = deviceCreateMenu(&MenuDiskDevices, DEVICE_TYPE_DISK, partitionHook); 	if (!menu) { 	    dialog_clear(); 	    msgConfirm("
argument|No devices suitable for installation found!\n\n
literal|" 		       "
argument|Please verify that your disk controller (and attached drives)\n
literal|" 		       "
argument|were detected properly.  This can be done by pressing the\n
literal|" 		       "
argument|[Scroll Lock] key and using the Arrow keys to move back to\n
literal|" 		       "
argument|the boot messages.  Press [Scroll Lock] again to return.
literal|"); 	    i = RET_FAIL; 	} 	else { 	    if (!dmenuOpenSimple(menu)) 		i = RET_FAIL; 	    else  { 		i = RET_SUCCESS; 		variable_set2(DISK_SELECTED, "
argument|yes
literal|"); 	    } 	    free(menu); 	}     }     return i; }  int diskPartitionWrite(char *str) {     extern u_char boot1[], boot2[];     Device **devs;     char *cp;     int i;      if ((cp = variable_get(DISK_PARTITIONED))&& strcmp(cp, "
argument|yes
literal|")) 	return RET_SUCCESS;     else if (!cp) { 	dialog_clear(); 	msgConfirm("
argument|You must partition the disk(s) before this option can be used.
literal|"); 	return RET_FAIL;     }      devs = deviceFind(NULL, DEVICE_TYPE_DISK);     if (!devs) { 	dialog_clear(); 	msgConfirm("
argument|Unable to find any disks to write to??
literal|"); 	return RET_FAIL;     }      for (i = 0; devs[i]; i++) { 	Chunk *c1; 	Disk *d = (Disk *)devs[i]->private;  	if (!devs[i]->enabled) 	    continue;  	Set_Boot_Blocks(d, boot1, boot2); 	msgNotify("
argument|Writing partition information to drive %s
literal|", d->name); 	if (Write_Disk(d)) { 	    dialog_clear(); 	    msgConfirm("
argument|ERROR: Unable to write data to disk %s!
literal|", d->name); 	    return RET_FAIL; 	} 	/* Now scan for bad blocks, if necessary */ 	for (c1 = d->chunks->part; c1; c1 = c1->next) { 	    if (c1->flags& CHUNK_BAD144) { 		int ret;  		msgNotify("
argument|Running bad block scan on partition %s
literal|", c1->name); 		ret = vsystem("
argument|bad144 -v /dev/r%s
literal|1234
literal|", c1->name); 		if (ret) { 		    dialog_clear(); 		    msgConfirm("
argument|Bad144 init on %s returned status of %d!
literal|", c1->name, ret); 		} 		ret = vsystem("
argument|bad144 -v -s /dev/r%s
literal|", c1->name); 		if (ret) { 		    dialog_clear(); 		    msgConfirm("
argument|Bad144 scan on %s returned status of %d!
literal|", c1->name, ret); 		} 	    } 	}     }     /* Now it's not "
argument|yes
literal|", but "
argument|written
literal|" */     variable_set2(DISK_PARTITIONED, "
argument|written
literal|"
end_function

unit|);     return RET_SUCCESS; }
end_unit

