begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)cp.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * Tahoe console processor interface  */
end_comment

begin_comment
comment|/*  * Reduced DCB layout for byte communication.  */
end_comment

begin_define
define|#
directive|define
name|CPBUFLEN
value|200
end_define

begin_comment
comment|/* Output buffer length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|cphdr
block|{
name|char
name|cp_unit
decl_stmt|;
comment|/* Done bit& unit # */
name|char
name|cp_comm
decl_stmt|;
comment|/* Command */
name|short
name|cp_count
decl_stmt|;
comment|/* Counter (when relevant) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpdcb_o
block|{
comment|/* Output structure */
name|struct
name|cphdr
name|cp_hdr
decl_stmt|;
name|char
name|cp_buf
index|[
name|CPBUFLEN
index|]
decl_stmt|;
comment|/* Buffer for output or 'stty' */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpdcb_i
block|{
comment|/* Structure for input */
name|struct
name|cphdr
name|cp_hdr
decl_stmt|;
name|char
name|cpi_buf
index|[
literal|4
index|]
decl_stmt|;
comment|/* Buffer for input */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPDONE
value|0x80
end_define

begin_comment
comment|/* 'Done' bit in cp_unit */
end_comment

begin_define
define|#
directive|define
name|CPTAKE
value|0x40
end_define

begin_comment
comment|/* CP 'ack' to this cpdcb */
end_comment

begin_comment
comment|/* unit values */
end_comment

begin_define
define|#
directive|define
name|CPUNIT
value|0
end_define

begin_comment
comment|/* the CP itself */
end_comment

begin_define
define|#
directive|define
name|CPCONS
value|1
end_define

begin_comment
comment|/* console line */
end_comment

begin_define
define|#
directive|define
name|CPREMOT
value|2
end_define

begin_comment
comment|/* remote line */
end_comment

begin_define
define|#
directive|define
name|CPCLOCK
value|4
end_define

begin_comment
comment|/* realtime clock */
end_comment

begin_comment
comment|/* commands */
end_comment

begin_define
define|#
directive|define
name|CPRESET
value|0
end_define

begin_define
define|#
directive|define
name|CPWRITE
value|1
end_define

begin_comment
comment|/* write device or register */
end_comment

begin_define
define|#
directive|define
name|CPREAD
value|2
end_define

begin_comment
comment|/* read device or register */
end_comment

begin_define
define|#
directive|define
name|CPSTTY
value|3
end_define

begin_comment
comment|/* set terminal configuration */
end_comment

begin_define
define|#
directive|define
name|CPBOOT
value|4
end_define

begin_comment
comment|/* reboot system */
end_comment

begin_comment
comment|/*  *	CP specific locations  */
end_comment

begin_define
define|#
directive|define
name|CPBFLG
value|0xc0000500
end_define

begin_comment
comment|/* System bootflag flags */
end_comment

begin_define
define|#
directive|define
name|CPYFLG
value|0xc0000504
end_define

begin_comment
comment|/* Copy of the Y flag */
end_comment

begin_define
define|#
directive|define
name|CPOPTS
value|0xc0000508
end_define

begin_comment
comment|/* copy of CP options */
end_comment

begin_define
define|#
directive|define
name|CPRSRV
value|0xc000050c
end_define

begin_comment
comment|/* reserved for CP usage */
end_comment

begin_define
define|#
directive|define
name|CPBDEV
value|0xc0000510
end_define

begin_comment
comment|/* Bootstrap device, saved on boot */
end_comment

begin_define
define|#
directive|define
name|CPEDEV
value|0xc000052f
end_define

begin_comment
comment|/* End of device name */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_decl_stmt
name|struct
name|cphdr
modifier|*
name|cnlast
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last command sent to cp */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

