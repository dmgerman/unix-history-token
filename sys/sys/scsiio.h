begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: scsiio.h,v 1.9 1998/02/01 04:13:13 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SCSIIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SCSIIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|SENSEBUFLEN
value|48
end_define

begin_typedef
typedef|typedef
struct|struct
name|scsireq
block|{
name|u_long
name|flags
decl_stmt|;
comment|/* info about the request status and type */
name|u_long
name|timeout
decl_stmt|;
name|u_char
name|cmd
index|[
literal|16
index|]
decl_stmt|;
comment|/* 12 is actually the max */
name|u_char
name|cmdlen
decl_stmt|;
name|caddr_t
name|databuf
decl_stmt|;
comment|/* address in user space of buffer */
name|u_long
name|datalen
decl_stmt|;
comment|/* size of user buffer (request) */
name|u_long
name|datalen_used
decl_stmt|;
comment|/* size of user buffer (used)*/
name|u_char
name|sense
index|[
name|SENSEBUFLEN
index|]
decl_stmt|;
comment|/* returned sense will be in here */
name|u_char
name|senselen
decl_stmt|;
comment|/* sensedata request size (MAX of SENSEBUFLEN)*/
name|u_char
name|senselen_used
decl_stmt|;
comment|/* return value only */
name|u_char
name|status
decl_stmt|;
comment|/* what the scsi status was from the adapter */
name|u_char
name|retsts
decl_stmt|;
comment|/* the return status for the command */
name|int
name|error
decl_stmt|;
comment|/* error bits */
block|}
name|scsireq_t
typedef|;
end_typedef

begin_comment
comment|/* bit definitions for flags */
end_comment

begin_define
define|#
directive|define
name|SCCMD_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCCMD_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCCMD_IOV
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCCMD_ESCAPE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCCMD_TARGET
value|0x00000020
end_define

begin_comment
comment|/* definitions for the return status (retsts) */
end_comment

begin_define
define|#
directive|define
name|SCCMD_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|SCCMD_TIMEOUT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCCMD_BUSY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCCMD_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCCMD_UNKNOWN
value|0x04
end_define

begin_define
define|#
directive|define
name|SCIOCCOMMAND
value|_IOWR('Q', 1, scsireq_t)
end_define

begin_define
define|#
directive|define
name|SC_DB_CMDS
value|0x00000001
end_define

begin_comment
comment|/* show all scsi cmds and errors */
end_comment

begin_define
define|#
directive|define
name|SC_DB_FLOW
value|0x00000002
end_define

begin_comment
comment|/* show routines entered	*/
end_comment

begin_define
define|#
directive|define
name|SC_DB_FLOW2
value|0x00000004
end_define

begin_comment
comment|/* show path INSIDE routines	*/
end_comment

begin_define
define|#
directive|define
name|SC_DB_DMA
value|0x00000008
end_define

begin_comment
comment|/* show DMA segments etc	*/
end_comment

begin_define
define|#
directive|define
name|SCIOCDEBUG
value|_IOW('Q', 2, int)
end_define

begin_comment
comment|/* from 0 to 15 */
end_comment

begin_struct
struct|struct
name|scsi_addr
block|{
name|int
name|scbus
decl_stmt|;
comment|/* -1 if wildcard */
name|int
name|target
decl_stmt|;
comment|/* -1 if wildcard */
name|int
name|lun
decl_stmt|;
comment|/* -1 if wildcard */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCIOCREPROBE
value|_IOW('Q', 3, struct scsi_addr)
end_define

begin_comment
comment|/* look for new devs */
end_comment

begin_define
define|#
directive|define
name|SCIOCIDENTIFY
value|_IOR('Q', 4, struct scsi_addr)
end_define

begin_comment
comment|/* where are you? */
end_comment

begin_define
define|#
directive|define
name|SCIOCDECONFIG
value|_IO('Q', 5)
end_define

begin_comment
comment|/* please disappear */
end_comment

begin_define
define|#
directive|define
name|SCIOCRECONFIG
value|_IO('Q', 6)
end_define

begin_comment
comment|/* please check again */
end_comment

begin_define
define|#
directive|define
name|SCIOCRESET
value|_IO('Q', 7)
end_define

begin_comment
comment|/* reset the device */
end_comment

begin_define
define|#
directive|define
name|SCIOCADDR
value|_IOW('Q', 8, struct scsi_addr)
end_define

begin_comment
comment|/* Change address */
end_comment

begin_define
define|#
directive|define
name|SCIOCFREEZE
value|_IO('Q', 9)
end_define

begin_comment
comment|/* Freeze SCSI */
end_comment

begin_define
define|#
directive|define
name|SCIOCTHAW
value|_IO('Q', 10)
end_define

begin_comment
comment|/* Thaw SCSI */
end_comment

begin_define
define|#
directive|define
name|SCIOCFREEZETHAW
value|_IOW('Q', 11, int)
end_define

begin_comment
comment|/* Freeze SCSI for some seconds */
end_comment

begin_define
define|#
directive|define
name|SCIOCWAITTHAW
value|_IO('Q', 12)
end_define

begin_comment
comment|/* Wait for SCSI to thaw */
end_comment

begin_struct
struct|struct
name|scsi_devinfo
block|{
name|struct
name|scsi_addr
name|addr
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
name|char
name|devname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|adname
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCIOCGETDEVINFO
value|_IOWR('Q', 13, struct scsi_devinfo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SCSIIO_H_ */
end_comment

end_unit

