begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: hilioctl.h 1.9 89/01/18$  *  *	@(#)hilioctl.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|_hilbell
block|{
name|u_char
name|duration
decl_stmt|;
name|u_char
name|frequency
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_hilbuf16
block|{
name|u_char
name|string
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_hilbuf11
block|{
name|u_char
name|string
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_hilbuf5
block|{
name|u_char
name|string
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_hilbuf4
block|{
name|u_char
name|string
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_hilbuf2
block|{
name|u_char
name|string
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hilqinfo
block|{
name|int
name|qid
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * HPUX ioctls (here for the benefit of the HIL driver).  * Named as they are under HPUX.  * The first set are loop device ioctls.  * The second set are ioctls for the 8042.  * Note that some are not defined as in HPUX  * due to the difference in the definitions of IOC_VOID.  */
end_comment

begin_define
define|#
directive|define
name|_IOHpux
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(IOC_IN|((x)<<8)|y)
end_define

begin_comment
comment|/* IOC_IN is IOC_VOID */
end_comment

begin_define
define|#
directive|define
name|HILID
value|_IOR('h',0x03, struct _hilbuf11)
end_define

begin_comment
comment|/* Identify& describe */
end_comment

begin_define
define|#
directive|define
name|HILSC
value|_IOR('h',0x33, struct _hilbuf16)
end_define

begin_comment
comment|/* Security code */
end_comment

begin_define
define|#
directive|define
name|HILRN
value|_IOR('h',0x30, struct _hilbuf16)
end_define

begin_comment
comment|/* Report name */
end_comment

begin_define
define|#
directive|define
name|HILRS
value|_IOR('h',0x31, struct _hilbuf16)
end_define

begin_comment
comment|/* Report status */
end_comment

begin_define
define|#
directive|define
name|HILED
value|_IOR('h',0x32, struct _hilbuf16)
end_define

begin_comment
comment|/* Extended describe*/
end_comment

begin_define
define|#
directive|define
name|HILDKR
value|_IOHpux('h',0x3D)
end_define

begin_comment
comment|/* Disable autorepeat */
end_comment

begin_define
define|#
directive|define
name|HILER1
value|_IOHpux('h',0x3E)
end_define

begin_comment
comment|/* Autorepeat 1/30 */
end_comment

begin_define
define|#
directive|define
name|HILER2
value|_IOHpux('h',0x3F)
end_define

begin_comment
comment|/* Autorepeat 1/60 */
end_comment

begin_define
define|#
directive|define
name|HILP1
value|_IOHpux('h',0x40)
end_define

begin_comment
comment|/* Prompt 1 */
end_comment

begin_define
define|#
directive|define
name|HILP2
value|_IOHpux('h',0x41)
end_define

begin_comment
comment|/* Prompt 2 */
end_comment

begin_define
define|#
directive|define
name|HILP3
value|_IOHpux('h',0x42)
end_define

begin_comment
comment|/* Prompt 3 */
end_comment

begin_define
define|#
directive|define
name|HILP4
value|_IOHpux('h',0x43)
end_define

begin_comment
comment|/* Prompt 4 */
end_comment

begin_define
define|#
directive|define
name|HILP5
value|_IOHpux('h',0x44)
end_define

begin_comment
comment|/* Prompt 5 */
end_comment

begin_define
define|#
directive|define
name|HILP6
value|_IOHpux('h',0x45)
end_define

begin_comment
comment|/* Prompt 6 */
end_comment

begin_define
define|#
directive|define
name|HILP7
value|_IOHpux('h',0x46)
end_define

begin_comment
comment|/* Prompt 7 */
end_comment

begin_define
define|#
directive|define
name|HILP
value|_IOHpux('h',0x47)
end_define

begin_comment
comment|/* Prompt */
end_comment

begin_define
define|#
directive|define
name|HILA1
value|_IOHpux('h',0x48)
end_define

begin_comment
comment|/* Acknowledge 1 */
end_comment

begin_define
define|#
directive|define
name|HILA2
value|_IOHpux('h',0x49)
end_define

begin_comment
comment|/* Acknowledge 2 */
end_comment

begin_define
define|#
directive|define
name|HILA3
value|_IOHpux('h',0x4A)
end_define

begin_comment
comment|/* Acknowledge 3 */
end_comment

begin_define
define|#
directive|define
name|HILA4
value|_IOHpux('h',0x4B)
end_define

begin_comment
comment|/* Acknowledge 4 */
end_comment

begin_define
define|#
directive|define
name|HILA5
value|_IOHpux('h',0x4C)
end_define

begin_comment
comment|/* Acknowledge 5 */
end_comment

begin_define
define|#
directive|define
name|HILA6
value|_IOHpux('h',0x4D)
end_define

begin_comment
comment|/* Acknowledge 6 */
end_comment

begin_define
define|#
directive|define
name|HILA7
value|_IOHpux('h',0x4E)
end_define

begin_comment
comment|/* Acknowledge 7 */
end_comment

begin_define
define|#
directive|define
name|HILA
value|_IOHpux('h',0x4F)
end_define

begin_comment
comment|/* Acknowledge */
end_comment

begin_define
define|#
directive|define
name|EFTSRD
value|_IOW('H',0xa0,char)
end_define

begin_comment
comment|/* Set the repeat delay. */
end_comment

begin_define
define|#
directive|define
name|EFTSRR
value|_IOW('H',0xa2,char)
end_define

begin_comment
comment|/* Set the repeat rate. */
end_comment

begin_define
define|#
directive|define
name|EFTSRPG
value|_IOW('H',0xa6,char)
end_define

begin_comment
comment|/* Set RPG interrupt rate. */
end_comment

begin_define
define|#
directive|define
name|EFTSBP
value|_IOW('H',0xc4,struct _hilbuf4)
end_define

begin_comment
comment|/* Send data to the beeper. */
end_comment

begin_define
define|#
directive|define
name|EFTRLC
value|_IOR('H',0x12,char)
end_define

begin_comment
comment|/* Read the language code. */
end_comment

begin_define
define|#
directive|define
name|EFTRCC
value|_IOR('H',0x11,char)
end_define

begin_comment
comment|/* Read configuration code. */
end_comment

begin_define
define|#
directive|define
name|EFTRRT
value|_IOR('H',0x31,struct _hilbuf5)
end_define

begin_comment
comment|/* Read the real time. */
end_comment

begin_define
define|#
directive|define
name|EFTRT
value|_IOR('H',0xf4,struct _hilbuf4)
end_define

begin_comment
comment|/* Read the timers for the 	                                              four voices. */
end_comment

begin_define
define|#
directive|define
name|EFTSBI
value|_IOW('H',0xa3,struct _hilbuf2)
end_define

begin_comment
comment|/* Set the bell information. */
end_comment

begin_comment
comment|/*  * BSD ioctls.  * Mostly the same as the HPUX versions except for shared-queue ioctls.  */
end_comment

begin_define
define|#
directive|define
name|HILIOCID
value|_IOR('h',0x03, struct _hilbuf11)
end_define

begin_define
define|#
directive|define
name|HILIOCSC
value|_IOR('h',0x33, struct _hilbuf16)
end_define

begin_define
define|#
directive|define
name|HILIOCRN
value|_IOR('h',0x30, struct _hilbuf16)
end_define

begin_define
define|#
directive|define
name|HILIOCRS
value|_IOR('h',0x31, struct _hilbuf16)
end_define

begin_define
define|#
directive|define
name|HILIOCED
value|_IOR('h',0x32, struct _hilbuf16)
end_define

begin_define
define|#
directive|define
name|HILIOCAROFF
value|_IO('h',0x3D)
end_define

begin_define
define|#
directive|define
name|HILIOCAR1
value|_IO('h',0x3E)
end_define

begin_define
define|#
directive|define
name|HILIOCAR2
value|_IO('h',0x3F)
end_define

begin_define
define|#
directive|define
name|HILIOCSBP
value|_IOW('H',0xc4,struct _hilbuf4)
end_define

begin_define
define|#
directive|define
name|HILIOCRRT
value|_IOR('H',0x31,struct _hilbuf5)
end_define

begin_define
define|#
directive|define
name|HILIOCRT
value|_IOR('H',0xf4,struct _hilbuf4)
end_define

begin_define
define|#
directive|define
name|HILIOCBEEP
value|_IOW('H',0xA3,struct _hilbell)
end_define

begin_define
define|#
directive|define
name|BELLDUR
value|80
end_define

begin_comment
comment|/* tone duration in msec (10 - 2560) */
end_comment

begin_define
define|#
directive|define
name|BELLFREQ
value|8
end_define

begin_comment
comment|/* tone frequency (0 - 63) */
end_comment

begin_define
define|#
directive|define
name|HILIOCALLOCQ
value|_IOWR('H',0x72, struct hilqinfo)
end_define

begin_comment
comment|/* allocate queue */
end_comment

begin_define
define|#
directive|define
name|HILIOCFREEQ
value|_IOW('H',0x73, struct hilqinfo)
end_define

begin_comment
comment|/* deallocate queue */
end_comment

begin_define
define|#
directive|define
name|HILIOCMAPQ
value|_IOW('H',0x74, int)
end_define

begin_comment
comment|/* map device to queue */
end_comment

begin_define
define|#
directive|define
name|HILIOCUNMAPQ
value|_IOW('H',0x75, int)
end_define

begin_comment
comment|/* unmap device from dev */
end_comment

begin_define
define|#
directive|define
name|HILIOCTEST
value|_IOW('H',0x76, int)
end_define

begin_comment
comment|/* Toggle debugging mode */
end_comment

begin_define
define|#
directive|define
name|HILIOCHPUX
value|_IO('H',0x77)
end_define

begin_comment
comment|/* use HPUX (read) semantics */
end_comment

begin_define
define|#
directive|define
name|HILIOCRESET
value|_IO('H',0x78)
end_define

begin_comment
comment|/* Reset the HIL loop. */
end_comment

begin_comment
comment|/*  * HIL input queue.  * This is the circular queue (allocated by HILIOCALLOC) shared by kernel  * and user.  It consists of a sixteen byte header followed by space for  * 255 input data packets (a total of 4096 bytes).  The kernel adds packets  * at tail.  The user is expected to remove packets from head.  This is the  * only field in the header that the user should modify.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hil_packet
block|{
name|u_char
name|size
decl_stmt|;
comment|/* total packet size */
name|u_char
name|dev
decl_stmt|;
comment|/* loop device packet was generated by */
name|long
name|tstamp
decl_stmt|;
comment|/* time stamp */
name|u_char
name|data
index|[
literal|10
index|]
decl_stmt|;
comment|/* device data */
block|}
name|hil_packet
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hil_eventqueue
block|{
name|int
name|size
decl_stmt|;
name|int
name|head
decl_stmt|;
name|int
name|tail
decl_stmt|;
name|int
name|pad
decl_stmt|;
block|}
name|hil_eventqueue
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|hilqueue
block|{
name|char
name|hqu_size
index|[
literal|0x1000
index|]
decl_stmt|;
struct|struct
name|q_data
block|{
name|hil_eventqueue
name|h_eventqueue
decl_stmt|;
name|hil_packet
name|h_event
index|[
literal|1
index|]
decl_stmt|;
block|}
name|q_data
struct|;
define|#
directive|define
name|hil_evqueue
value|q_data.h_eventqueue
define|#
directive|define
name|hil_event
value|q_data.h_event
block|}
name|HILQ
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HEVQSIZE
define|\
value|((sizeof(HILQ) - sizeof(struct q_data)) / sizeof(hil_packet) + 1)
end_define

end_unit

