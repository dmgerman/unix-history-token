begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)pk.h	5.6	(Berkeley)	4/5/88	*/
end_comment

begin_struct
struct|struct
name|header
block|{
name|char
name|sync
decl_stmt|;
name|char
name|ksize
decl_stmt|;
name|unsigned
name|short
name|sum
decl_stmt|;
name|char
name|cntl
decl_stmt|;
name|char
name|ccntl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HDRSIZ
value|6
end_define

begin_comment
comment|/* Packet header size */
end_comment

begin_define
define|#
directive|define
name|PACKSIZE
value|64
end_define

begin_comment
comment|/* Standard packet size */
end_comment

begin_define
define|#
directive|define
name|WINDOWS
value|7
end_define

begin_comment
comment|/* number of outstanding un-ack'd packets */
end_comment

begin_struct
struct|struct
name|pack
block|{
name|short
name|p_state
decl_stmt|;
comment|/* line state */
name|short
name|p_bits
decl_stmt|;
comment|/* mask for getepack */
name|short
name|p_rsize
decl_stmt|;
comment|/* input packet size */
name|short
name|p_xsize
decl_stmt|;
comment|/* output packet size */
name|struct
name|header
name|p_ihbuf
decl_stmt|;
comment|/* input header */
name|struct
name|header
name|p_ohbuf
decl_stmt|;
comment|/* output header */
name|char
modifier|*
name|p_rptr
decl_stmt|;
name|char
modifier|*
modifier|*
name|p_ipool
decl_stmt|;
name|char
name|p_xcount
decl_stmt|;
comment|/* # active output buffers */
name|char
name|p_rcount
decl_stmt|;
name|char
name|p_lpsize
decl_stmt|;
comment|/* log(psize/32) */
name|char
name|p_obusy
decl_stmt|;
comment|/* output busy? for reentrant pkoutput() */
name|char
name|p_srxmit
decl_stmt|;
name|char
name|p_rwindow
decl_stmt|;
comment|/* window size */
name|char
name|p_swindow
decl_stmt|;
name|char
name|p_msg
decl_stmt|;
comment|/* control msg */
name|char
name|p_rmsg
decl_stmt|;
comment|/* repeated control msg */
name|char
name|p_ps
decl_stmt|,
name|p_pr
decl_stmt|;
comment|/* last packet sent, recv'd */
name|char
name|p_rpr
decl_stmt|;
name|char
name|p_nxtps
decl_stmt|;
comment|/* next output seq number */
name|char
name|p_imap
decl_stmt|;
comment|/* bit map of input buffers */
name|char
name|p_pscopy
decl_stmt|;
comment|/* newest output packet */
name|char
modifier|*
name|p_ob
index|[
literal|8
index|]
decl_stmt|;
comment|/* output buffers */
name|char
modifier|*
name|p_ib
index|[
literal|8
index|]
decl_stmt|;
comment|/* input buffers */
name|char
name|p_os
index|[
literal|8
index|]
decl_stmt|;
comment|/* output buffer status */
name|char
name|p_is
index|[
literal|8
index|]
decl_stmt|;
comment|/* input buffer status */
name|short
name|p_osum
index|[
literal|8
index|]
decl_stmt|;
comment|/* output checksums */
name|short
name|p_isum
index|[
literal|8
index|]
decl_stmt|;
comment|/* input checksums */
name|int
name|p_ifn
decl_stmt|,
name|p_ofn
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHECK
value|0125252
end_define

begin_define
define|#
directive|define
name|SYN
value|020
end_define

begin_define
define|#
directive|define
name|MOD8
value|7
end_define

begin_define
define|#
directive|define
name|ISCNTL
parameter_list|(
name|a
parameter_list|)
value|((a& 0300)==0)
end_define

begin_comment
comment|/* MIN may have been defined in<sys/param.h> */
end_comment

begin_undef
undef|#
directive|undef
name|MIN
end_undef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a<b)? a:b)
end_define

begin_decl_stmt
specifier|extern
name|char
name|next
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mask
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * driver state  */
end_comment

begin_define
define|#
directive|define
name|DEAD
value|0
end_define

begin_define
define|#
directive|define
name|INITa
value|1
end_define

begin_define
define|#
directive|define
name|INITb
value|2
end_define

begin_define
define|#
directive|define
name|INITab
value|3
end_define

begin_define
define|#
directive|define
name|LIVE
value|010
end_define

begin_define
define|#
directive|define
name|RXMIT
value|020
end_define

begin_define
define|#
directive|define
name|RREJ
value|040
end_define

begin_define
define|#
directive|define
name|PDEBUG
value|0200
end_define

begin_define
define|#
directive|define
name|DRAINO
value|0400
end_define

begin_define
define|#
directive|define
name|WAITO
value|01000
end_define

begin_define
define|#
directive|define
name|DOWN
value|02000
end_define

begin_define
define|#
directive|define
name|RCLOSE
value|04000
end_define

begin_define
define|#
directive|define
name|BADFRAME
value|020000
end_define

begin_comment
comment|/*  * io buffer states  */
end_comment

begin_define
define|#
directive|define
name|B_NULL
value|0
end_define

begin_define
define|#
directive|define
name|B_READY
value|1
end_define

begin_define
define|#
directive|define
name|B_SENT
value|2
end_define

begin_define
define|#
directive|define
name|B_RESID
value|010
end_define

begin_define
define|#
directive|define
name|B_COPY
value|020
end_define

begin_define
define|#
directive|define
name|B_MARK
value|040
end_define

begin_define
define|#
directive|define
name|B_SHORT
value|0100
end_define

begin_comment
comment|/* read or write */
end_comment

begin_define
define|#
directive|define
name|B_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|B_READ
value|1
end_define

begin_comment
comment|/*  * control messages  */
end_comment

begin_define
define|#
directive|define
name|CLOSE
value|1
end_define

begin_define
define|#
directive|define
name|RJ
value|2
end_define

begin_define
define|#
directive|define
name|SRJ
value|3
end_define

begin_define
define|#
directive|define
name|RR
value|4
end_define

begin_define
define|#
directive|define
name|INITC
value|5
end_define

begin_define
define|#
directive|define
name|INITB
value|6
end_define

begin_define
define|#
directive|define
name|INITA
value|7
end_define

begin_define
define|#
directive|define
name|M_CLOSE
value|002
end_define

begin_define
define|#
directive|define
name|M_RJ
value|004
end_define

begin_define
define|#
directive|define
name|M_SRJ
value|010
end_define

begin_define
define|#
directive|define
name|M_RR
value|020
end_define

begin_define
define|#
directive|define
name|M_INITC
value|040
end_define

begin_define
define|#
directive|define
name|M_INITA
value|0200
end_define

begin_define
define|#
directive|define
name|M_INITB
value|0100
end_define

begin_define
define|#
directive|define
name|NPLINES
value|2
end_define

begin_decl_stmt
specifier|extern
name|int
name|pksizes
index|[]
decl_stmt|;
end_decl_stmt

end_unit

