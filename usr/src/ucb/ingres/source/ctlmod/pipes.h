begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  PIPES.H -- definitions for pipe blocks. ** **	Version: **		@(#)pipes.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PB_DBSIZE
end_ifndef

begin_comment
comment|/* **  The 'pb_t' (pipe block type) should be arranged so that the **  size of the structure excluding pb_xptr is some nice power **  of two. */
end_comment

begin_define
define|#
directive|define
name|PB_DBSIZE
value|116
end_define

begin_define
define|#
directive|define
name|PB_IOSIZE
value|128
end_define

begin_typedef
typedef|typedef
struct|struct
name|_pb_t
block|{
name|char
name|pb_st
decl_stmt|;
comment|/* the state to enter */
name|char
name|pb_proc
decl_stmt|;
comment|/* the proc to enter */
name|char
name|pb_resp
decl_stmt|;
comment|/* the proc to respond to */
name|char
name|pb_padxx
decl_stmt|;
comment|/* --- unused at this time --- */
name|char
name|pb_from
decl_stmt|;
comment|/* the immediate writer of this block */
name|char
name|pb_type
decl_stmt|;
comment|/* the block type, see below */
name|short
name|pb_stat
decl_stmt|;
comment|/* a status word, see below */
name|short
name|pb_nused
decl_stmt|;
comment|/* the number of bytes used in this block */
name|short
name|pb_nleft
decl_stmt|;
comment|/* the number of bytes left in this block */
name|char
name|pb_data
index|[
name|PB_DBSIZE
index|]
decl_stmt|;
comment|/* the data area */
name|char
modifier|*
name|pb_xptr
decl_stmt|;
comment|/* the data pointer (not written) */
block|}
name|pb_t
typedef|;
end_typedef

begin_comment
comment|/* possible values for pb_type */
end_comment

begin_define
define|#
directive|define
name|PB_NOTYPE
value|0
end_define

begin_comment
comment|/* unknown type */
end_comment

begin_define
define|#
directive|define
name|PB_REG
value|1
end_define

begin_comment
comment|/* regular block */
end_comment

begin_define
define|#
directive|define
name|PB_RESP
value|2
end_define

begin_comment
comment|/* response block */
end_comment

begin_define
define|#
directive|define
name|PB_ERR
value|3
end_define

begin_comment
comment|/* error message */
end_comment

begin_define
define|#
directive|define
name|PB_SYNC
value|4
end_define

begin_comment
comment|/* interrupt sync */
end_comment

begin_define
define|#
directive|define
name|PB_RESET
value|5
end_define

begin_comment
comment|/* system reset */
end_comment

begin_define
define|#
directive|define
name|PB_TRACE
value|6
end_define

begin_comment
comment|/* set new trace flags */
end_comment

begin_comment
comment|/* more meta definitions go before this line */
end_comment

begin_comment
comment|/* definitions for pb_stat */
end_comment

begin_define
define|#
directive|define
name|PB_EOF
value|00001
end_define

begin_comment
comment|/* end of file block */
end_comment

begin_define
define|#
directive|define
name|PB_FRFR
value|00002
end_define

begin_comment
comment|/* originated from front end */
end_comment

begin_define
define|#
directive|define
name|PB_INFO
value|00004
end_define

begin_comment
comment|/* info purposes only, no response */
end_comment

begin_comment
comment|/* definitions for pb_proc */
end_comment

begin_define
define|#
directive|define
name|PB_WILD
value|-2
end_define

begin_comment
comment|/* all processes */
end_comment

begin_define
define|#
directive|define
name|PB_UNKNOWN
value|-1
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|PB_FRONT
value|0
end_define

begin_comment
comment|/* front end */
end_comment

begin_comment
comment|/* other processes are given numbers from 2 */
end_comment

begin_comment
comment|/* definitions for pb_st */
end_comment

begin_comment
comment|/* define	PB_UNKNOWN	-1	*/
end_comment

begin_define
define|#
directive|define
name|PB_NONE
value|0
end_define

begin_comment
comment|/* response block */
end_comment

begin_endif
endif|#
directive|endif
endif|PB_DBSIZE
end_endif

end_unit

