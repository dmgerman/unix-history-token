begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * datakit status  */
end_comment

begin_struct
struct|struct
name|dkstat
block|{
name|long
name|input
decl_stmt|;
name|long
name|output
decl_stmt|;
name|int
name|markflt
decl_stmt|;
comment|/* mark byte expected */
name|int
name|markparity
decl_stmt|;
comment|/* parity error on mark byte */
name|int
name|closepack
decl_stmt|;
comment|/* packet on closed channel */
name|int
name|pack0
decl_stmt|;
comment|/* packet on channel 0 */
name|int
name|packstrange
decl_stmt|;
comment|/* packet on strange channel */
name|int
name|shortpack
decl_stmt|;
comment|/* short packet */
name|int
name|parity
decl_stmt|;
comment|/* parity error */
name|int
name|chgstrange
decl_stmt|;
comment|/* T_CHG on strange channel */
name|int
name|notclosed
decl_stmt|;
comment|/* packets on hung-up chans */
name|int
name|isclosed
decl_stmt|;
comment|/* "isclosed" packet on open chan */
name|int
name|dkprxmit
decl_stmt|;
comment|/* retransmit rejected dkp msg */
name|int
name|dkprjtrs
decl_stmt|;
comment|/* reject, trailer size */
name|int
name|dkprjpks
decl_stmt|;
comment|/* reject, packet size */
name|int
name|dkprjseq
decl_stmt|;
comment|/* reject, sequence number */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|crc
value|shortpack
end_define

begin_define
define|#
directive|define
name|oflow
value|parity
end_define

end_unit

