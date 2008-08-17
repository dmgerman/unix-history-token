begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|btfp_time
comment|/* Structure for reading 5 time words   */
comment|/* in one ioctl(2) operation.           */
block|{
name|unsigned
name|short
name|btfp_time
index|[
literal|5
index|]
decl_stmt|;
comment|/* Time words 0,1,2,3, and 4. (16bit)*/
block|}
struct|;
end_struct

begin_comment
comment|/***** Simple ioctl commands *****/
end_comment

begin_define
define|#
directive|define
name|RUNLOCK
value|_IO('X',19)
end_define

begin_comment
comment|/* Release Capture Lockout */
end_comment

begin_define
define|#
directive|define
name|RCR0
value|_IOR('X',22,unsigned int)
end_define

begin_comment
comment|/* Read control register */
end_comment

begin_define
define|#
directive|define
name|WCR0
value|_IOW('X',23,unsigned int)
end_define

begin_comment
comment|/* Write control register */
end_comment

begin_comment
comment|/***** Compound ioctl commands *****/
end_comment

begin_comment
comment|/* Read all 5 time words in one call.   */
end_comment

begin_define
define|#
directive|define
name|READTIME
value|_IOR('X',32,struct btfp_time)
end_define

begin_define
define|#
directive|define
name|VMEFD
value|"/dev/btfp0"
end_define

begin_struct
struct|struct
name|vmedate
block|{
comment|/* structure returned by get_vmetime.c */
name|unsigned
name|short
name|year
decl_stmt|;
name|unsigned
name|short
name|doy
decl_stmt|;
name|unsigned
name|short
name|hr
decl_stmt|;
name|unsigned
name|short
name|mn
decl_stmt|;
name|unsigned
name|short
name|sec
decl_stmt|;
name|unsigned
name|long
name|frac
decl_stmt|;
name|unsigned
name|short
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PRIO
value|120
end_define

begin_comment
comment|/* set the realtime priority */
end_comment

begin_define
define|#
directive|define
name|NREGS
value|7
end_define

begin_comment
comment|/* number of registers we will use */
end_comment

end_unit

