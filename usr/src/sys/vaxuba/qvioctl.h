begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * 		@(#)qvioctl.h	1.4  Berkeley  6/3/88  *   *	derived from: @(#)qvioctl.h	1.7 (ULTRIX) 6/11/85  */
end_comment

begin_comment
comment|/*  * Ioctl definitions for the qvss.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"qvreg.h"
end_include

begin_include
include|#
directive|include
file|"qevent.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<vaxuba/qvreg.h>
end_include

begin_include
include|#
directive|include
file|<vaxuba/qevent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|qv_kpcmd
block|{
name|char
name|nbytes
decl_stmt|;
comment|/* number of bytes in parameter */
name|unsigned
name|char
name|cmd
decl_stmt|;
comment|/* command to be sent, peripheral bit will */
comment|/* be forced by driver */
name|unsigned
name|char
name|par
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes of parameters to be sent */
block|}
struct|;
end_struct

begin_comment
comment|/*  * qvss information block  */
end_comment

begin_struct
struct|struct
name|qv_info
block|{
name|short
name|mswitches
decl_stmt|;
comment|/* current value of mouse buttons */
name|vsCursor
name|tablet
decl_stmt|;
comment|/* current tablet position	*/
name|short
name|tswitches
decl_stmt|;
comment|/* current tablet buttons NI!	*/
name|vsCursor
name|cursor
decl_stmt|;
comment|/* current cursor position	*/
name|short
name|row
decl_stmt|;
comment|/* screen row			*/
name|short
name|col
decl_stmt|;
comment|/* screen col			*/
name|short
name|max_row
decl_stmt|;
comment|/* max character row		*/
name|short
name|max_col
decl_stmt|;
comment|/* max character col		*/
name|short
name|max_x
decl_stmt|;
comment|/* max x position		*/
name|short
name|max_y
decl_stmt|;
comment|/* max y position		*/
name|short
name|max_cur_x
decl_stmt|;
comment|/* max cursor y position 	*/
name|short
name|max_cur_y
decl_stmt|;
comment|/* max cursor y position	*/
name|char
modifier|*
name|bitmap
decl_stmt|;
comment|/* bit map position		*/
name|short
modifier|*
name|scanmap
decl_stmt|;
comment|/* scanline map position	*/
name|short
modifier|*
name|cursorbits
decl_stmt|;
comment|/* cursor bit position		*/
name|struct
name|qvdevice
modifier|*
name|qvaddr
decl_stmt|;
comment|/* virtual address of the csr	*/
name|vsEvent
modifier|*
name|ibuff
decl_stmt|;
comment|/* pointer to event queue	*/
name|int
name|iqsize
decl_stmt|;
comment|/* may assume power of two 	*/
name|int
name|ihead
decl_stmt|;
comment|/* atomic write			*/
name|int
name|itail
decl_stmt|;
comment|/* atomic read			*/
name|vsCursor
name|mouse
decl_stmt|;
comment|/* atomic read/write		*/
name|vsBox
name|mbox
decl_stmt|;
comment|/* atomic read/write		*/
name|short
name|mthreshold
decl_stmt|;
comment|/* mouse motion parameter	*/
name|short
name|mscale
decl_stmt|;
comment|/* mouse scale factor (if  					   negative, then do square).	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qv_info
name|vsIoAddr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QIOCGINFO
value|_IOR('q', 1, struct qv_info)
end_define

begin_comment
comment|/* get the info	 */
end_comment

begin_define
define|#
directive|define
name|QIOCSMSTATE
value|_IOW('q', 2, vsCursor)
end_define

begin_comment
comment|/* set mouse pos */
end_comment

begin_define
define|#
directive|define
name|QIOCINIT
value|_IO('q', 4)
end_define

begin_comment
comment|/* init screen   */
end_comment

begin_define
define|#
directive|define
name|QIOCKPCMD
value|_IOW('q', 5, struct qv_kpcmd)
end_define

begin_comment
comment|/* keybd. per. cmd */
end_comment

begin_define
define|#
directive|define
name|QIOCADDR
value|_IOR('q', 6, struct qv_info *)
end_define

begin_comment
comment|/* get address */
end_comment

end_unit

