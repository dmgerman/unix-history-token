begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file gets read by makestatetext to create text files  * with the names of the states, so don't change the file  * format  */
end_comment

begin_enum
enum|enum
name|volumestate
block|{
name|volume_unallocated
block|,
comment|/* present but unused.  Must be 0 */
name|volume_uninit
block|,
comment|/* mentioned elsewhere but not known to the configuration */
name|volume_down
block|,
comment|/* The volume is up and functional, but not all plexes may be available */
name|volume_up
block|,
name|volume_laststate
init|=
name|volume_up
comment|/* last value, for table dimensions */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|plexstate
block|{
comment|/* An empty entry, not a plex at all.   */
name|plex_unallocated
block|,
comment|/* The plex has been referenced by a volume */
name|plex_referenced
block|,
comment|/*      * The plex has been allocated, but there configuration      * is not complete      */
name|plex_init
block|,
comment|/*      * A plex which has gone completely down because of      * I/O errors.      */
name|plex_faulty
block|,
comment|/*      * A plex which has been taken down by the      * administrator.      */
name|plex_down
block|,
comment|/* A plex which is being initialized */
name|plex_initializing
block|,
comment|/*      * *** The remaining states represent plexes which are      * at least partially up.  Keep these separate so that      * they can be checked more easily.      */
comment|/*      * A plex entry which is at least partially up.  Not      * all subdisks are available, and an inconsistency      * has occurred.  If no other plex is uncorrupted,      * the volume is no longer consistent.      */
name|plex_corrupt
block|,
name|plex_firstup
init|=
name|plex_corrupt
block|,
comment|/* first "up" state */
comment|/*      * A RAID-5 plex entry which is accessible, but one      * subdisk is down, requiring recovery for many      * I/O requests.      */
name|plex_degraded
block|,
comment|/*      * A plex which is really up, but which has a reborn      * subdisk which we don't completely trust, and      * which we don't want to read if we can avoid it      */
name|plex_flaky
block|,
comment|/*      * A plex entry which is completely up.  All subdisks      * are up.      */
name|plex_up
block|,
name|plex_laststate
init|=
name|plex_up
comment|/* last value, for table dimensions */
block|}
enum|;
end_enum

begin_comment
comment|/* subdisk states */
end_comment

begin_enum
enum|enum
name|sdstate
block|{
comment|/* An empty entry, not a subdisk at all. */
name|sd_unallocated
block|,
comment|/*      * A subdisk entry which has not been created      * completely.  Some fields may be empty.      */
name|sd_uninit
block|,
comment|/* The subdisk has been referenced by a plex */
name|sd_referenced
block|,
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, but the disk hasn't      * been updated.      */
name|sd_init
block|,
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, and the disk has been      * updated, but there is no data on the disk.      */
name|sd_empty
block|,
comment|/*      * A subdisk entry which has been created completely and      * which is currently being initialized      */
name|sd_initializing
block|,
comment|/*      * A subdisk entry which has been initialized,      * but which can't come up because it would      * cause inconsistencies.      */
name|sd_initialized
block|,
comment|/* *** The following states represent invalid data */
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, the config on disk has been      * updated, and the data was valid, but since then the      * drive has been taken down, and as a result updates      * have been missed.      */
name|sd_obsolete
block|,
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, the disk has been updated,      * and the data was valid, but since then the drive      * has been crashed and updates have been lost.      */
name|sd_stale
block|,
comment|/* *** The following states represent valid, inaccessible data */
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, the disk has been updated,      * and the data was valid, but since then the drive      * has gone down.   No attempt has been made to write      * to the subdisk since the crash, so the data is valid.      */
name|sd_crashed
block|,
comment|/*      * A subdisk entry which was up, which contained      * valid data, and which was taken down by the      * administrator.  The data is valid.      */
name|sd_down
block|,
comment|/*      * *** This is invalid data (the subdisk previously had      * a numerically lower state), but it is currently in the      * process of being revived.  We can write but not read.      */
name|sd_reviving
block|,
comment|/*      * *** The following states represent accessible subdisks      * with valid data      */
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, the disk has been updated,      * and the data was valid, but since then the drive      * has gone down and up again.  No updates were lost,      * but it is possible that the subdisk has been      * damaged.  We won't read from this subdisk if we      * have a choice.  If this is the only subdisk which      * covers this address space in the plex, we set its      * state to sd_up under these circumstances, so this      * status implies that there is another subdisk to      * fulfil the request.      */
name|sd_reborn
block|,
comment|/*      * A subdisk entry which has been created completely.      * All fields are correct, the disk has been updated,      * and the data is valid.      */
name|sd_up
block|,
name|sd_laststate
init|=
name|sd_up
comment|/* last value, for table dimensions */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|drivestate
block|{
name|drive_unallocated
block|,
comment|/* present but unused.  Must be 0 */
name|drive_referenced
block|,
comment|/* just mentioned in some other config entry */
name|drive_down
block|,
comment|/* not accessible */
name|drive_up
block|,
comment|/* up and running */
name|drive_laststate
init|=
name|drive_up
comment|/* last value, for table dimensions */
block|}
enum|;
end_enum

begin_comment
comment|/* Local Variables: */
end_comment

begin_comment
comment|/* fill-column: 50 */
end_comment

begin_comment
comment|/* End: */
end_comment

end_unit

