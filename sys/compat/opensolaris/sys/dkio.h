begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_DKIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_DKIO_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Disk io control commands  * Warning: some other ioctls with the DIOC prefix exist elsewhere.  * The Generic DKIOC numbers are from	0   -  50.  *	The Floppy Driver uses		51  - 100.  *	The Hard Disk (except SCSI)	101 - 106.	(these are obsolete)  *	The CDROM Driver		151 - 200.  *	The USCSI ioctl			201 - 250.  */
define|#
directive|define
name|DKIOC
value|(0x04<< 8)
comment|/*  * The following ioctls are generic in nature and need to be  * suported as appropriate by all disk drivers  */
define|#
directive|define
name|DKIOCGGEOM
value|(DKIOC|1)
comment|/* Get geometry */
define|#
directive|define
name|DKIOCINFO
value|(DKIOC|3)
comment|/* Get info */
define|#
directive|define
name|DKIOCEJECT
value|(DKIOC|6)
comment|/* Generic 'eject' */
define|#
directive|define
name|DKIOCGVTOC
value|(DKIOC|11)
comment|/* Get VTOC */
define|#
directive|define
name|DKIOCSVTOC
value|(DKIOC|12)
comment|/* Set VTOC& Write to Disk */
comment|/*  * Disk Cache Controls.  These ioctls should be supported by  * all disk drivers.  *  * DKIOCFLUSHWRITECACHE when used from user-mode ignores the ioctl  * argument, but it should be passed as NULL to allow for future  * reinterpretation.  From user-mode, this ioctl request is synchronous.  *  * When invoked from within the kernel, the arg can be NULL to indicate  * a synchronous request or can be the address of a struct dk_callback  * to request an asynchronous callback when the flush request is complete.  * In this case, the flag to the ioctl must include FKIOCTL and the  * dkc_callback field of the pointed to struct must be non-null or the  * request is made synchronously.  *  * In the callback case: if the ioctl returns 0, a callback WILL be performed.  * If the ioctl returns non-zero, a callback will NOT be performed.  * NOTE: In some cases, the callback may be done BEFORE the ioctl call  * returns.  The caller's locking strategy should be prepared for this case.  */
define|#
directive|define
name|DKIOCFLUSHWRITECACHE
value|(DKIOC|34)
comment|/* flush cache to phys medium */
struct|struct
name|dk_callback
block|{
name|void
function_decl|(
modifier|*
name|dkc_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|dkc_cookie
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
name|void
modifier|*
name|dkc_cookie
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSOLARIS_SYS_DKIO_H_ */
end_comment

end_unit

