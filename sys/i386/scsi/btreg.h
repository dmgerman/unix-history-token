begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organizations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BTREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BTREG_H_
end_define

begin_include
include|#
directive|include
file|"bt.h"
end_include

begin_comment
comment|/*  * Mail box defs  etc.  * these could be bigger but we need the bt_data to fit on a single page..  */
end_comment

begin_define
define|#
directive|define
name|BT_MBX_SIZE
value|32
end_define

begin_comment
comment|/* mail box size  (MAX 255 MBxs) */
end_comment

begin_comment
comment|/* don't need that many really */
end_comment

begin_define
define|#
directive|define
name|BT_CCB_MAX
value|32
end_define

begin_comment
comment|/* store up to 32CCBs at any one time */
end_comment

begin_comment
comment|/* in bt742a H/W ( Not MAX ? ) */
end_comment

begin_define
define|#
directive|define
name|CCB_HASH_SIZE
value|32
end_define

begin_comment
comment|/* when we have a physical addr. for */
end_comment

begin_comment
comment|/* a ccb and need to find the ccb in */
end_comment

begin_comment
comment|/* space, look it up in the hash table */
end_comment

begin_define
define|#
directive|define
name|BT_NSEG
value|33
end_define

begin_comment
comment|/*  				 * Number of SG segments per command 				 * Max of 2048??? 				 */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|physaddr
typedef|;
end_typedef

begin_struct
struct|struct
name|bt_scat_gath
block|{
name|unsigned
name|long
name|seg_len
decl_stmt|;
name|physaddr
name|seg_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|bt_mbx_out
block|{
name|physaddr
name|ccb_addr
decl_stmt|;
name|unsigned
name|char
name|dummy
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|cmd
decl_stmt|;
block|}
name|BT_MBO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bt_mbx_in
block|{
name|physaddr
name|ccb_addr
decl_stmt|;
name|unsigned
name|char
name|btstat
decl_stmt|;
name|unsigned
name|char
name|sdstat
decl_stmt|;
name|unsigned
name|char
name|dummy
decl_stmt|;
name|unsigned
name|char
name|stat
decl_stmt|;
block|}
name|BT_MBI
typedef|;
end_typedef

begin_struct
struct|struct
name|bt_mbx
block|{
name|BT_MBO
name|mbo
index|[
name|BT_MBX_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|BT_MBO_FREE
value|0x0
comment|/* MBO intry is free */
define|#
directive|define
name|BT_MBO_START
value|0x1
comment|/* MBO activate entry */
define|#
directive|define
name|BT_MBO_ABORT
value|0x2
comment|/* MBO abort entry */
name|BT_MBI
name|mbi
index|[
name|BT_MBX_SIZE
index|]
decl_stmt|;
define|#
directive|define
name|BT_MBI_FREE
value|0x0
comment|/* MBI entry is free */
define|#
directive|define
name|BT_MBI_OK
value|0x1
comment|/* completed without error */
define|#
directive|define
name|BT_MBI_ABORT
value|0x2
comment|/* aborted ccb */
define|#
directive|define
name|BT_MBI_UNKNOWN
value|0x3
comment|/* Tried to abort invalid CCB */
define|#
directive|define
name|BT_MBI_ERROR
value|0x4
comment|/* Completed with error */
name|BT_MBO
modifier|*
name|tmbo
decl_stmt|;
comment|/* Target Mail Box out */
name|BT_MBI
modifier|*
name|tmbi
decl_stmt|;
comment|/* Target Mail Box in */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bt_ccb
block|{
name|unsigned
name|char
name|opcode
decl_stmt|;
define|#
directive|define
name|BT_INITIATOR_CCB
value|0x00
comment|/* SCSI Initiator CCB */
define|#
directive|define
name|BT_TARGET_CCB
value|0x01
comment|/* SCSI Target CCB */
define|#
directive|define
name|BT_INIT_SCAT_GATH_CCB
value|0x02
comment|/* SCSI Initiator w/sg */
define|#
directive|define
name|BT_RESET_CCB
value|0x81
comment|/* SCSI Bus reset */
name|unsigned
name|char
range|:
literal|3
decl_stmt|,
name|data_in
range|:
literal|1
decl_stmt|,
name|data_out
range|:
literal|1
decl_stmt|,
range|:
literal|3
decl_stmt|;
name|unsigned
name|char
name|scsi_cmd_length
decl_stmt|;
name|unsigned
name|char
name|req_sense_length
decl_stmt|;
name|unsigned
name|long
name|data_length
decl_stmt|;
name|physaddr
name|data_addr
decl_stmt|;
name|unsigned
name|char
name|dummy
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|host_stat
decl_stmt|;
define|#
directive|define
name|BT_OK
value|0x00
comment|/* cmd ok */
define|#
directive|define
name|BT_LINK_OK
value|0x0a
comment|/* Link cmd ok */
define|#
directive|define
name|BT_LINK_IT
value|0x0b
comment|/* Link cmd ok + int */
define|#
directive|define
name|BT_SEL_TIMEOUT
value|0x11
comment|/* Selection time out */
define|#
directive|define
name|BT_OVER_UNDER
value|0x12
comment|/* Data over/under run */
define|#
directive|define
name|BT_BUS_FREE
value|0x13
comment|/* Bus dropped at unexpected time */
define|#
directive|define
name|BT_INV_BUS
value|0x14
comment|/* Invalid bus phase/sequence */
define|#
directive|define
name|BT_BAD_MBO
value|0x15
comment|/* Incorrect MBO cmd */
define|#
directive|define
name|BT_BAD_CCB
value|0x16
comment|/* Incorrect ccb opcode */
define|#
directive|define
name|BT_BAD_LINK
value|0x17
comment|/* Not same values of LUN for links */
define|#
directive|define
name|BT_INV_TARGET
value|0x18
comment|/* Invalid target direction */
define|#
directive|define
name|BT_CCB_DUP
value|0x19
comment|/* Duplicate CCB received */
define|#
directive|define
name|BT_INV_CCB
value|0x1a
comment|/* Invalid CCB or segment list */
define|#
directive|define
name|BT_ABORTED
value|42
comment|/* pseudo value from driver */
name|unsigned
name|char
name|target_stat
decl_stmt|;
name|unsigned
name|char
name|target
decl_stmt|;
name|unsigned
name|char
name|lun
decl_stmt|;
name|unsigned
name|char
name|scsi_cmd
index|[
literal|12
index|]
decl_stmt|;
comment|/* 12 bytes (bytes only) */
name|unsigned
name|char
name|dummy2
index|[
literal|1
index|]
decl_stmt|;
name|unsigned
name|char
name|link_id
decl_stmt|;
name|physaddr
name|link_addr
decl_stmt|;
name|physaddr
name|sense_ptr
decl_stmt|;
name|struct
name|scsi_sense_data
name|scsi_sense
decl_stmt|;
name|struct
name|bt_scat_gath
name|scat_gath
index|[
name|BT_NSEG
index|]
decl_stmt|;
name|struct
name|bt_ccb
modifier|*
name|next
decl_stmt|;
name|struct
name|scsi_xfer
modifier|*
name|xfer
decl_stmt|;
comment|/* the scsi_xfer for this cmd */
name|struct
name|bt_mbx_out
modifier|*
name|mbx
decl_stmt|;
comment|/* pointer to mail box */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|CCB_FREE
value|0
define|#
directive|define
name|CCB_ACTIVE
value|1
define|#
directive|define
name|CCB_ABORTED
value|2
name|struct
name|bt_ccb
modifier|*
name|nexthash
decl_stmt|;
comment|/* if two hash the same */
name|physaddr
name|hashkey
decl_stmt|;
comment|/*physaddr of this ccb */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bt_data
block|{
name|int
name|bt_base
decl_stmt|;
comment|/* base port for each board */
name|struct
name|bt_mbx
name|bt_mbx
decl_stmt|;
comment|/* all our mailboxes */
name|struct
name|bt_ccb
modifier|*
name|bt_ccb_free
decl_stmt|;
comment|/* list of free CCBs */
name|struct
name|bt_ccb
modifier|*
name|ccbhash
index|[
name|CCB_HASH_SIZE
index|]
decl_stmt|;
comment|/* phys to kv hash */
name|int
name|bt_int
decl_stmt|;
comment|/* int. read off board */
name|int
name|bt_dma
decl_stmt|;
comment|/* DMA channel read of board */
name|int
name|bt_scsi_dev
decl_stmt|;
comment|/* adapters scsi id */
name|int
name|numccbs
decl_stmt|;
comment|/* how many we have malloc'd */
name|int
name|bt_bounce
decl_stmt|;
comment|/* should we bounce? */
name|int
name|unit
decl_stmt|;
comment|/* The zero in bt0 */
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
comment|/* prototype for devs */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bt_data
modifier|*
name|btdata
index|[
name|NBT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|bt_unit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|bt_data
modifier|*
name|bt_alloc
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_long
name|iobase
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bt_free
name|__P
argument_list|(
operator|(
expr|struct
name|bt_data
operator|*
name|bt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bt_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bt_init
name|__P
argument_list|(
operator|(
expr|struct
name|bt_data
operator|*
name|bt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bt_attach
name|__P
argument_list|(
operator|(
expr|struct
name|bt_data
operator|*
name|bt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BT_H_ */
end_comment

end_unit

