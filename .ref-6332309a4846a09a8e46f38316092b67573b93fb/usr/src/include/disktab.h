begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)disktab.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Disk description table, see disktab(5)  */
end_comment

begin_define
define|#
directive|define
name|DISKTAB
value|"/etc/disktab"
end_define

begin_struct
struct|struct
name|disktab
block|{
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* drive name */
name|char
modifier|*
name|d_type
decl_stmt|;
comment|/* drive type */
name|int
name|d_secsize
decl_stmt|;
comment|/* sector size in bytes */
name|int
name|d_ntracks
decl_stmt|;
comment|/* # tracks/cylinder */
name|int
name|d_nsectors
decl_stmt|;
comment|/* # sectors/track */
name|int
name|d_ncylinders
decl_stmt|;
comment|/* # cylinders */
name|int
name|d_rpm
decl_stmt|;
comment|/* revolutions/minute */
name|int
name|d_badsectforw
decl_stmt|;
comment|/* supports DEC bad144 std */
name|int
name|d_sectoffset
decl_stmt|;
comment|/* use sect rather than cyl offsets */
struct|struct
name|partition
block|{
name|int
name|p_size
decl_stmt|;
comment|/* #sectors in partition */
name|short
name|p_bsize
decl_stmt|;
comment|/* block size in bytes */
name|short
name|p_fsize
decl_stmt|;
comment|/* frag size in bytes */
block|}
name|d_partitions
index|[
literal|8
index|]
struct|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|disktab
modifier|*
name|getdiskbyname
parameter_list|()
function_decl|;
end_function_decl

end_unit

