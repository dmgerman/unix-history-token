begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: vsioctl.h,v 10.3 86/02/01 15:48:03 tony Rel $ */
end_comment

begin_comment
comment|/* $Header: vsioctl.h,v 10.3 86/02/01 15:48:03 tony Rel $ */
end_comment

begin_comment
comment|/*   * vsio.h - VS100 I/O command definitions  *   * Author:	Christopher A. Kent  *		Digital Equipment Corporation  *		Western Research Lab  * Date:	Tue Jun 21 1983  */
end_comment

begin_comment
comment|/* $Log:	vsioctl.h,v $  * Revision 10.3  86/02/01  15:48:03  tony  * X Version 10.0 Release 3.0  *   * Revision 10.2  85/11/24  15:12:05  jg  * add RCS id and mark it released...  *   * Revision 10.1  85/11/08  17:38:41  newman  * X Version 10.0 release  *   * Revision 9.1  85/09/04  13:27:15  tony  * X Version 9.0 release.  *   * Revision 1.1  85/06/30  12:01:32  jg  * Initial revision  *  */
end_comment

begin_comment
comment|/*   * Possible ioctl calls  */
end_comment

begin_define
define|#
directive|define
name|VSIOINIT
value|_IO(V, 0)
end_define

begin_comment
comment|/* init the device */
end_comment

begin_define
define|#
directive|define
name|VSIOSTART
value|_IOW(V, 1, int)
end_define

begin_comment
comment|/* start microcode */
end_comment

begin_define
define|#
directive|define
name|VSIOABORT
value|_IO(V, 2)
end_define

begin_comment
comment|/* abort a command chain */
end_comment

begin_define
define|#
directive|define
name|VSIOPWRUP
value|_IO(V, 3)
end_define

begin_comment
comment|/* power-up reset */
end_comment

begin_define
define|#
directive|define
name|VSIOGETVER
value|_IOR(V, 4, int)
end_define

begin_comment
comment|/* get rom version */
end_comment

begin_define
define|#
directive|define
name|VSIOSYNC
value|_IO(V, 6)
end_define

begin_comment
comment|/* synch with device */
end_comment

begin_define
define|#
directive|define
name|VSIOBBACTL
value|_IOW(V, 8, int)
end_define

begin_comment
comment|/* control the BBA */
end_comment

begin_define
define|#
directive|define
name|VSIOFIBCTL
value|_IOW(V, 9, int)
end_define

begin_comment
comment|/* lamp on/off */
end_comment

begin_define
define|#
directive|define
name|VSIOFIBRETRY
value|_IOW(V,10, int)
end_define

begin_comment
comment|/* fiber retries */
end_comment

begin_define
define|#
directive|define
name|VSIOGETSTATS
value|_IOR(V,11, vsStats)
end_define

begin_comment
comment|/* get statistics */
end_comment

begin_define
define|#
directive|define
name|VSIOGETIOA
value|_IOR(V,13, vsIoAddrAddr)
end_define

begin_comment
comment|/* get ioreg address */
end_comment

begin_define
define|#
directive|define
name|VSIOUSERWAIT
value|_IO(V, 15)
end_define

begin_comment
comment|/* wait for user I/O completion */
end_comment

begin_define
define|#
directive|define
name|VSIOWAITGO
value|_IOW(V, 16, caddr_t)
end_define

begin_comment
comment|/* wait then go */
end_comment

begin_define
define|#
directive|define
name|VSIO_OFF
value|0
end_define

begin_comment
comment|/* option off */
end_comment

begin_define
define|#
directive|define
name|VSIO_ON
value|1
end_define

begin_comment
comment|/* option on */
end_comment

begin_define
define|#
directive|define
name|VS_FIB_FINITE
value|1
end_define

begin_comment
comment|/* finite retries */
end_comment

begin_define
define|#
directive|define
name|VS_FIB_INFINITE
value|2
end_define

begin_comment
comment|/* infinite retries */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vsStats
block|{
name|int
name|errors
decl_stmt|;
comment|/* count errors */
name|int
name|unsolIntr
decl_stmt|;
comment|/* count unsolicited interrupts */
name|int
name|overruns
decl_stmt|;
comment|/* event queue overruns */
name|int
name|flashes
decl_stmt|;
comment|/* flashes on fiber link */
name|int
name|ignites
decl_stmt|;
comment|/* times turned on */
name|int
name|douses
decl_stmt|;
comment|/* times turned off */
name|int
name|linkErrors
decl_stmt|;
comment|/* link errors */
block|}
name|vsStats
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_vsIoAddr
block|{
name|short
modifier|*
name|ioreg
decl_stmt|;
name|short
name|status
decl_stmt|;
name|caddr_t
name|obuff
decl_stmt|;
name|int
name|obufflen
decl_stmt|;
name|int
name|reloc
decl_stmt|;
name|vsEvent
modifier|*
name|ibuff
decl_stmt|;
name|int
name|iqsize
decl_stmt|;
comment|/* may assume power of 2 */
name|int
name|ihead
decl_stmt|;
comment|/* atomic write */
name|int
name|itail
decl_stmt|;
comment|/* atomic read */
name|vsCursor
name|mouse
decl_stmt|;
comment|/* atomic read/write */
name|vsBox
name|mbox
decl_stmt|;
comment|/* atomic read/write */
block|}
name|vsIoAddr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vsIoAddr
modifier|*
name|vsIoAddrAddr
typedef|;
end_typedef

end_unit

