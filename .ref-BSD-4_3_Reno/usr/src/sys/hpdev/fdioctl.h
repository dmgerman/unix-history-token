begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * from: Utah $Hdr: fdioctl.h 1.1 89/11/20$  *  *	@(#)fdioctl.h	7.1 (Berkeley) 5/8/90  */
end_comment

begin_comment
comment|/*  * Ioctl definitions for file (vnode) disk pseudo-device.  */
end_comment

begin_define
define|#
directive|define
name|FDISKFILE
value|"/etc/fdisks"
end_define

begin_comment
comment|/* default config file */
end_comment

begin_struct
struct|struct
name|fd_ioctl
block|{
name|char
modifier|*
name|fd_file
decl_stmt|;
comment|/* pathname of file to mount */
name|int
name|fd_size
decl_stmt|;
comment|/* (returned) size of disk */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Before you can use a unit, it must be configured with FDIOCSET.  * The configuration persists across opens and closes of the device;  * an FDIOCCLR must be used to reset a configuration.  An attempt to  * FDIOCSET an already active unit will return EBUSY.  */
end_comment

begin_define
define|#
directive|define
name|FDIOCSET
value|_IOWR('F', 0, struct fd_ioctl)
end_define

begin_comment
comment|/* enable disk */
end_comment

begin_define
define|#
directive|define
name|FDIOCCLR
value|_IOW('F', 1, struct fd_ioctl)
end_define

begin_comment
comment|/* disable disk */
end_comment

end_unit

